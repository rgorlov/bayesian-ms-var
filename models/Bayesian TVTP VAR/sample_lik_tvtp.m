function [m_llh] = sample_lik_tvtp(Y, X, Z, ndraws, prior, posterior)
%% load data from posterior
nstate = prior.nstate;
[nobs, nvar] = size(Y);
[ ~, nreg  ] = size(X);
beta = posterior.beta_mean;
prior.b = prior.b;
omega = posterior.omega_mean;
gamma = posterior.gamma_mean;
Dd = posterior.Dd;
D = posterior.D;
[~,N]=size(posterior.state);

if ~exist('X', 'var') || isempty(X)
    X = ones(length(Y),1);
end

% % construct time varying parameter vectors
ind = logical(repmat(eye(nstate),[1,2]));
XX = [Z' ; ones(1,nobs)]';
TVTP_vec = zeros(nobs,nstate,nstate);
for k = 1:nstate
    H = exp(XX*gamma(ind(k,:),:));
    H = H./repmat(sum(H,2),[1,nstate]);
    TVTP_vec(:,:,k) = H;
end

% construct time varying matrices
TVTP = zeros(nstate,nstate,nobs);
for k = 1 : nstate
    TVTP(k,:,:) = reshape(TVTP_vec(:,:,k)', 1,nstate,nobs);
end

% To obtain the marginal likelihood we use
% p(r) = p(r|theta*) x p(theta*) / p(theta*|r)
% with theta* = {M*, E*, P*}

%% [1] p(r|theta*) = (Pr_t=1^t=T) [f_t(r_t| I_t-1, theta*)]
% Use Hamilton Filter to compute the model likelihood f_t(r_t| I_t-1, theta*)
% =(S_k=1^k=K) [f_t(r_t| I_t-1, theta*, s_t=k) x p(s_t=k|theta*, I_t-1)]
% Compute likelihood at each point in time for each state
norm_pdf  = zeros(nobs,nstate);
beta_mvn = reshape(beta,[nreg,nvar,nstate]);
for s = 1:nstate
    R = chol(omega(:,:,s));
    xRinv = (Y - X*beta_mvn(:,:,s)) / R;
    logSqrtDetSigma = sum(log(diag(R)));
    quadform = sum(xRinv.^2, 2);
    norm_pdf(:,s) = exp(-0.5*quadform - logSqrtDetSigma - nvar*log(2*pi)/2);
end
norm_pdf = norm_pdf';

unc_prob = ones(nstate,1)./nstate;
inf_prob = zeros(nstate,nobs);
markov_T = permute(TVTP,[2 1 3]);
forward_use = norm_pdf(:,1).*(markov_T(:,:,1)*unc_prob);
inf_prob(:,1) = forward_use / sum(forward_use);
model_llh = log(sum(forward_use));
for t = 2 : nobs
    forward_use = norm_pdf(:,t).*(markov_T(:,:,t)*inf_prob(:,t-1));
    inf_prob(:,t) = forward_use / sum(forward_use);
    model_llh = log(sum(forward_use)) + model_llh;
end

%% [2] The prior likelihood p(theta*) = p(M*) x p(E*) x p(P*)
prior_beta_llh = 0;
prior_omega_llh = 0;
prior_gamma_llh = 0;
for s = 1:nstate
    prior_beta_llh = prior_beta_llh + log(mvnpdf(beta(:,s),prior.b(:,s),prior.B(:,:,s)));
    prior_omega_llh = prior_omega_llh + log(iwishart_pdf(omega(:,:,s),prior.v(s),inv(prior.O(:,:,s))));
    if s > 1
        prior_gamma_llh = prior_omega_llh + log(mvnpdf(gamma(:,s),prior.g, prior.G));
    end
end
prior_llh = prior_beta_llh+prior_gamma_llh+prior_omega_llh;

%% [3] The posterior density ordinate can be decomposed as such:
% p(M*, E*, P* | y) = p(P*|M*,E*,y) x p(E*|M*,y) x p(M*|y)

% [3.1] We use the Gibbs output to compute the posterior density ordinate
% of the mean p(M*|y) = int p(M*|E,P,S,y) x p(E,P,S|y) dEdPdS
normpdf_sum = 0;
for i = 1:N
    normpdf_prod = 1;
    for s = 1:nstate
        normpdf_prod = normpdf_prod .* mvnpdf(beta(:,s),Dd(:,s,i),D(:,:,s,i));
    end
    normpdf_sum = normpdf_sum + normpdf_prod;
end
post_beta_llh = log(normpdf_sum/N);
    
%% [3.2] We run additional 5000 sampling runs with to obtain the reduced
% conditional density ordinate of the variance [sigma2]
% p(E*|M*,y) = int p(E*|S,P,M*,y) x p(S,P|M*,y) dSdP
% beta is the sampled posterior mean here.
state = ceil(nstate*rand(nobs,1));
add_omega = zeros(nvar,nvar,nstate,ndraws);
add_df = zeros(nstate,ndraws);
msg = ('Reduced Gibbs sampler running for the reduced conditional density ordinate covariance matrix.');
for r = 1 : ndraws
    [ ~, omega_add, post_omega, df ] = sample_omega(state, beta, prior, Y, X);
    [ markov_T , gamma, ~, ~] = sample_dRum_TVTP(state, prior, Z, gamma);
    [ state ] = sample_tvtp_state_mex(beta, omega_add, markov_T, prior.nstate, Y, X);
    timer_bar(r, ndraws, msg)
    add_omega(:, :, :, r) = post_omega;
    add_df(:, r) = df;
end

sum_O = 0;
for i = 1:r
    prod_O = 1;
    for s = 1:nstate
        O = iwishart_pdf(omega(:,:,s),add_df(s,i),inv(add_omega(:,:,s,i)));
        prod_O = prod_O * O;
    end
    sum_O = sum_O + prod_O;
end
post_omega_llh = log(sum_O/r);
   
%% [3.3] We run additional 5000 sampling runs with to obtain the reduced
% conditional density ordinate of the time varying transition matrix
% p(P*|M*,E*y) = int p(P*|S,M*,E*,y) x p(S|M*,E*,y) dS
% beta and sigma the sampled posterior mean here.

smpl_G = zeros(nstate*2,nstate*2,ndraws);
smpl_g = zeros(nstate*2,ndraws);
gamma = posterior.gamma_mean;
state = ceil(nstate*rand(nobs,1));
msg = ('Reduced Gibbs sampler running for conditional density ordinate of the time varying transition matrix.');
for r = 1 : ndraws

    [ markov_T , ~, G, Gg] = sample_dRum_TVTP(state, prior, Z, gamma);
    [ state ] = sample_tvtp_state_mex(beta, omega, markov_T, prior.nstate, Y, X);

    timer_bar(r, ndraws, msg)
    smpl_G(:,:,r) = G;
    smpl_Gg(:,r) = Gg;
    
end
sum_gamma = 0;
for i = 1:r
    normpdf_prod = 1;
    for s = 2:nstate
        normpdf_prod = normpdf_prod .* mvnpdf(gamma(:,s),smpl_Gg(:,i),smpl_G(:,:,i));
    end
    sum_gamma = sum_gamma + normpdf_prod;
end
post_gamma_llh = log(sum_gamma/r);


%% combine all parts to gether to get the marginal likelihood
post_llh = post_beta_llh + post_omega_llh + post_gamma_llh;
marginal_likelihood = model_llh + prior_llh - post_llh;
m_llh.marginal = marginal_likelihood;
m_llh.model = model_llh;
m_llh.prior = prior_llh;
m_llh.pbeta = post_beta_llh;
m_llh.pomega = post_omega_llh;
m_llh.pmarkov = post_gamma_llh;
end
