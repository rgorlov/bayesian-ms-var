function [posterior, prior] = sample_MS_TVTP(Y,X,Z,nstate,ndraws,burn_in,thin,permute_flag)
% get dims
[nobs,nreg] = size(X);
prior.nstate = nstate;

% B_i ~ N (b, B)
prior.b = zeros(nreg,nstate);
prior.B = 0.25 * ones(nreg,nstate);

% sigma2_i ~ IG(w_i/2, W_i/2)
prior.w = 2*ones(nstate,1);
prior.W = 0.25*ones(nstate,1);

% set prior for gammas ~ N(g, G)
prior.g  = [0 0 -1 1]';
prior.G  = 6.25*eye(nstate*2);

prior.reset = 0;
% Preallocate memory for output
%Beta ~ N(D,Dd), Markov ~ Dir(nstate,nstate), Sigma ~ IG(..)
d = (ndraws - burn_in)/thin;
posterior.sigma = zeros(nstate,d);
posterior.beta = zeros(nreg,nstate,d);
posterior.gam = zeros(nstate*2, d);
posterior.Dd = zeros(nreg,nstate,d);
posterior.D = zeros(nreg,nreg,nstate,d);
posterior.state = zeros(nobs, d);
posterior.smooth = zeros(nobs, nstate);
posterior.tvtp = zeros(nstate,nstate,nobs,d);
npermute = 0;

%initial draw of beta is prior
beta = prior.b + sqrt(prior.B) .* randn(nreg,nstate);
%initial draw of sigma is prior
sigma2 = 1 ./ gamrnd(prior.w, 1./prior.W);
% Initial state probability
unc_prob = ones(nstate,1)./nstate;
% initial TVTP
tvtp = rand(nstate,nstate,nobs);
% initial gamm
gam = zeros(nstate*2,nstate);
r = 1;
d = 0;
while r < ndraws
    
    [state_vector] = compute_state_vector_rum_chib_tvtp_mex(beta,sigma2,tvtp,unc_prob,nstate,Y,X);
    
    if isempty(state_vector) || (length(unique(state_vector))<nstate)
        prior.reset = prior.reset + 1;
        continue
    end
    
    [tvtp ,gam] = sample_dRum_TVTP(state_vector,prior,Z,gam);
%     [tvtp ,gam] = sample_TVTP(state_vector, prior, Z,gam);
    [beta, Dd, D] = sample_rum_beta(state_vector,sigma2,prior,Y,X);
    
    [sigma2, a, b] = sample_rum_sigma2(state_vector,beta,prior,Y,X);
    
    % Permute parameters for desired order
    switch permute_flag
        case 1
            [~,ind] = sort(beta(1,:));
            % E[R_t]_{1} > ... > E[R_t]_{K}
        case 2
            [~,ind] = sort(unc_mean(:,1), 'descend');
            % V[R_t]_{1} >...> V[R_t]_{K}
        case 3
            [~,ind] = sort(sigma2);
            % permute random
        case 4
            ind = randperm(nstate);
        case 5
            [~,ind] = sort(unc_prob);
        otherwise
            ind = (1:nstate)';
    end
    
    if any(ind(:) ~= (1:nstate)')
        beta = beta(:,ind);
        D = D(:,:,ind);
        Dd = Dd(:,ind);
        a = a(ind);
        b  = b(ind);
        sigma2 = sigma2(ind);
        
        indx = [ind(:); ind(:)+nstate];
        gam = gam(indx,ind);
        gam = gam - repmat(gam(:,1),[1,2]);
        
        prior.g = prior.g(indx);
        
        E = accumarray({(1:nobs)' state_vector},1);
        E = E(:,ind).*repmat((1:nstate),[nobs,1]);
        state_vector = sum(E,2);
        npermute = npermute + 1;
        
    end
    r = r + 1;
    if mod(r,10)==0 
        disp(r) 
    end
    if (r > burn_in) && (mod(r,thin)==0)
        d = d + 1;
        posterior.state(:, d) = state_vector;
        posterior.beta(:,:, d) = beta;
        posterior.gam(:, d) = gam(:,2);
        posterior.Dd(:,:, d) = Dd;
        posterior.D(:,:,:, d) = D;
        posterior.sigma(:, d) = sqrt(sigma2);
        posterior.a(:,d) = a;
        posterior.b(:,d) = b;
        posterior.tvtp(:,:,:,d) = tvtp;
    end
end

posterior.beta_mean = mean(posterior.beta,3);
posterior.beta_median = median(posterior.beta,3);
posterior.beta_std = std(posterior.beta,0,3);
posterior.beta_di = hpd(posterior.beta);
posterior.gam_mean = mean(posterior.gam,2);
posterior.gam_median = median(posterior.gam,2);
posterior.gam_std = std(posterior.gam,0,2);
posterior.gam_di = hpd_interval(posterior.gam);
posterior.sigma_mean = mean(posterior.sigma,2);
posterior.sigma_median = median(posterior.sigma,2);
posterior.sigma_std = std(posterior.sigma,0,2);
posterior.sigma_di = hpd_interval(posterior.sigma);
posterior.Y = Y;
posterior.X = X;
posterior.Z = Z;
posterior.nstate = nstate;
posterior.npermute = npermute;

for m = 1:nstate
    posterior.smooth(:,m) = mean(posterior.state == m,2);
end

% result ={};
% result(1,:) = {'Coeff.','Post. mean', 'Post. median', 'Post. std', '5th perc.','95th perc.'};
% for m = 1:nstate
%     for k = 1:nreg
%         row = ['b(',num2str(k),')','s(',num2str(m),')'];
%         row = {row, posterior.beta_mean(k,m),posterior.beta_median(k,m), posterior.beta_std(k,m), posterior.beta_di(m*k,1), posterior.beta_di(m*k,2)};
%         result = [result; row];
%     end
% end
% for m = 1:nstate
%     row = ['sigma(',num2str(m),')'];
%     row = {row,posterior.sigma_mean(m),posterior.sigma_median(m),posterior.sigma_std(m), posterior.sigma_di(m,1), posterior.sigma_di(m,2)};
%     result = [result;row];
% end
% for m = 1:nstate^2
%     row = ['markov(',num2str(m),')'];
%     row = {row,posterior.markov_mean(m),posterior.markov_median(m),posterior.markov_std(m), posterior.markov_di(m,1), posterior.markov_di(m,2)};
%     result = [result;row];
% end
% for m = 1:nstate
%     row = ['unc_prob(',num2str(m),')'];
%     row = {row, posterior.unc_prob_mean(m),posterior.unc_prob_median(m),posterior.unc_prob_std(m),posterior.unc_prob_di(m,1),posterior.unc_prob_di(m,2)};
%     result = [result;row];
% end
% posterior.result = result;
% disp(' ')
% disp(result)

end