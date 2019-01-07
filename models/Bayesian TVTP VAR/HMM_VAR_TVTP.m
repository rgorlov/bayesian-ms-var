function [posterior, prior, marginal] = HMM_VAR_TVTP(Y,X,Z,nstate,ndraws,burn_in,permute,responseVars, predictorVars)

[nobs, nvar] = size(Y);
[ ~, nreg  ] = size(X);
[ ~, nreg_z] = size(Z);
% --------------------------------------------------------
prior.nstate = nstate;

% include dummies for each state and dummy interaction
nreg_tvtp = nreg_z*nstate*2;

% set prior for gammas ~ N(g, G)
% prior.g  = [zeros(nreg_tvtp,1) repmat([zeros(1,nreg_tvtp) -1 1]',[1,nstate-1])];
prior.g  =  [ zeros(1, nreg_z * nstate), -1, ones(1, nstate -1)]';
prior.G  =  diag([6*ones(1, nreg_z * nstate), ones(1, nstate)]);
% beta(s) ~ N(b(s),B(s))
prior.b = zeros(nvar*nreg,nstate);
prior.B = repmat(100 * eye(nvar*nreg), [1 1 nstate]);
% omega(s) ~ IW(v(s),O(s))
prior.O = repmat(1000 * eye(nvar), [1 1 nstate]);
prior.v = (nvar + 5) .* ones(nstate,1);
permute_flag = permute.flag;
permute_var  = permute.var;
permute_var2 = permute.var2;
regime_var = permute.reg; % regressor for regime prediction
% Set variable and predictor names
posterior.model         = 'msvar-tvtp';
posterior.responseVars  = responseVars;
posterior.predictorVars = predictorVars;
% --------------------------------------------------------
% Preallocate memory
nperiods = 120;
posterior.beta = zeros(nvar*nreg,nstate,ndraws - burn_in);
posterior.Dd = zeros(nvar*nreg, nstate, ndraws - burn_in);
posterior.D = zeros(nvar*nreg, nvar*nreg, nstate, ndraws - burn_in);
posterior.post_omega = zeros(nvar, nvar, nstate, ndraws - burn_in);
posterior.df = zeros(nstate, ndraws - burn_in);
posterior.omega = zeros(nvar,nvar,nstate,ndraws - burn_in);
posterior.state = zeros(nobs, ndraws - burn_in);
posterior.gamma = zeros(nreg_tvtp,nstate, ndraws - burn_in);
posterior.tvtp = zeros(nstate, nstate, nobs, ndraws - burn_in);
posterior.sim_r = zeros(ndraws - burn_in, nperiods );
posterior.sim_x = zeros(nreg-1, nperiods, ndraws - burn_in);
posterior.sim_state = zeros(ndraws - burn_in, nperiods );
npermute = 0;
% --------------------------------------------------------
%Initial draws
gamma = zeros(nstate*2,nstate);
% Initial draws
beta = zeros(nvar*nreg,nstate);
omega_inv = zeros(nvar,nvar,nstate);
omega = zeros(nvar,nvar,nstate);
state = ceil(rand(nobs,1) * nstate);
for s = 1:nstate
    mask = (state == s);
    Xs = X(mask, :);
    Ys = Y(mask, :);
    Ts = sum(mask);
    beta_in = (Xs'*Xs)\(Xs'*Ys) + chol(inv(Xs'*Xs))*randn(nreg,nreg);
    beta(:,s) = beta_in(:);
    omega(:,:,s) = (Ys-Xs*beta_in)'*(Ys-Xs*beta_in)/(Ts-nvar);
    omega_inv(:,:,s) = omega(:,:,s)\eye(nvar);
end
% Gibbs sampler
msg = ('Gibbs sampler running.');
for r = 1:ndraws
    
    [ beta, Dd, D ]  = sample_matric_beta(state, omega_inv, prior, Y, X);
    [ omega_inv, omega, post_omega, df ] = sample_omega(state, beta, prior, Y, X);
    [ markov_T , gamma, ~, ~] = sample_dRum_TVTP(state, prior, Z, gamma);
    [ state ] = sample_tvtp_state_mex(beta, omega, markov_T, prior.nstate, Y, X);
    
    % Permute parameters for desired order
    switch permute_flag
        case 1
            [~,ind] = sort(beta(5,:), 'descend');
            % E[R_t]_{1} > ... > E[R_t]_{K}
        case 2
            [e_y, ve_y, ev_y, v_y, y_md, unc_mean, regime_d, e_cumrets, e_cumbonds] = compute_regime_stats_tvtp(state, beta, omega, markov_T, Y, X);
            [~,ind] = sort(unc_mean(:,permute_var), 'descend');
            % V[R_t]_{1} >...> V[R_t]_{K}
        case 3
            [~,ind] = sort(omega(permute_var,permute_var,:), 'descend');
            % Cov(R_t,X_t,{1}) > ... > Cov(R_t,X_t,{K})
        case 4
            [~,ind] = sort(omega(1,permute_var,:), 'descend');
            % permute on the correlation of  two variables
        case 5           
            var1 = omega(permute_var, permute_var,:);
            var2 = omega(permute_var2, permute_var2,:);
            cov  = omega(permute_var, permute_var2,:);
            cor  = cov ./ (sqrt(var1) .* sqrt(var2));
            [~,ind] = sort(cor, 'descend');
        otherwise
            % permute random
            ind = randperm(nstate);
    end
    
    if any(ind(:) ~= (1:nstate)')
        % disp(['Permutation applied to unburned draws No. :',num2str(r)])
        beta = beta(:,ind);
        Dd = Dd(:,ind);
        D = D(:,:,ind);
        
        omega_inv = omega_inv(:,:,ind);
        omega = omega(:,:,ind);
        post_omega = post_omega(:,:,ind);
        df = df(ind);
        
        indx = [ind(:); ind(:)+nstate];
        gamma = gamma(indx,ind);
        gamma = gamma - repmat(gamma(:,1),[1,nstate]);
        prior.g = prior.g(indx);
        
        E = accumarray({(1:nobs)' state},1);
        E = E(:,ind).*repmat((1:nstate),[nobs,1]);
        state = sum(E,2);
        npermute = npermute + 1;
    end
    
    
    timer_bar(r,ndraws,msg)
    % Record the draws
    if r > burn_in
        [e_y, ve_y, ev_y, v_y, y_md, unc_mean, regime_d, e_cumrets, e_cumbonds] = compute_regime_stats_tvtp(state, beta, omega, markov_T, Y, X);
        state_last = state(nobs);
        markov = markov_T(:,:,nobs);
        [sim_r, sim_x, sim_state] = sim_var_tvpt(beta,gamma,omega,markov,state_last,nperiods,Y,regime_var);
        posterior.sim_r( r - burn_in, : ) = sim_r;
        posterior.sim_x( :, :, r - burn_in ) = sim_x;
        posterior.sim_state( r - burn_in, : ) = sim_state;
        
        posterior.beta(:,:, r - burn_in) = beta;
        posterior.omega(:,:,:, r - burn_in) = omega;
        posterior.state(:, r - burn_in) = state;
        posterior.gamma(:, :, r - burn_in) = gamma;
        posterior.tvtp(:,:,:, r - burn_in) = markov_T;
        
        posterior.Dd(:, :, r - burn_in) = Dd;
        posterior.D(:, :, :, r - burn_in) = D;
        
        posterior.df(:, r - burn_in) = df;
        posterior.post_omega(:, :, :, r - burn_in) = post_omega;
        
        posterior.unc_mean(:, :, r - burn_in ) = unc_mean;
        posterior.e_y(:, r - burn_in ) = e_y';
        posterior.ve_y(:, r - burn_in ) = ve_y';
        posterior.ev_y(:, r - burn_in ) = ev_y';
        posterior.v_y(:, r - burn_in ) = v_y';
        posterior.y_md(:, r - burn_in ) = y_md';
        posterior.regime_d(:, r - burn_in ) = regime_d';
        posterior.e_cumrets(:, r - burn_in ) = e_cumrets';
        posterior.e_cumbonds(:, r - burn_in ) = e_cumbonds';
    end
    
end

posterior.beta_mean = mean(posterior.beta,3);
posterior.beta_mean_rs = reshape(posterior.beta_mean,[nreg,nvar,nstate]);
posterior.beta_median = median(posterior.beta,3);
posterior.beta_median = reshape(posterior.beta_median,[nreg,nvar,nstate]);
posterior.beta_std = std(posterior.beta,0,3);
posterior.beta_std = reshape(posterior.beta_std,[nreg,nvar,nstate]);
posterior.beta_di = hpd(posterior.beta);
posterior.beta_di = reshape(posterior.beta_di,[nreg,nvar,nstate,2]);

posterior.gamma_mean = mean(posterior.gamma,3);
posterior.gamma_median = median(posterior.gamma,3);
posterior.gamma_std = std(posterior.gamma,0,3);
posterior.gamma_di = hpd(posterior.gamma);
posterior.gamma_di = posterior.gamma_di((nstate*2)+1:end,:);

posterior.omega_mean = mean(posterior.omega,4);
posterior.omega_median = median(posterior.omega,4);
posterior.omega_std = std(posterior.omega,0,4);
posterior.omega_di = hpd(reshape(posterior.omega,[nvar*nvar,nstate,r - burn_in]));
posterior.omega_di = reshape(posterior.omega_di,[nvar,nvar,nstate,2]);

posterior.unc_mean_mean = mean(posterior.unc_mean,3);
posterior.unc_mean_median = median(posterior.unc_mean,3);
posterior.unc_mean_std = std(posterior.unc_mean,0,3);
posterior.unc_mean_di = hpd(posterior.unc_mean);

% total expectation of returns
posterior.e_y_mean = mean(posterior.e_y,2);
posterior.e_y_median = median(posterior.e_y,2);
posterior.e_y_std = std(posterior.e_y,0,2);
posterior.e_y_di = hpd_interval(posterior.e_y);
% expectation of variance of returns
posterior.ev_y_mean = mean(posterior.ev_y,2);
posterior.ev_y_median = median(posterior.ev_y,2);
posterior.ev_y_std = std(posterior.ev_y,0,2);
posterior.ev_y_di = hpd_interval(posterior.ev_y);
% variance of expectation of returns
posterior.ve_y_mean = mean(posterior.ve_y,2);
posterior.ve_y_median = median(posterior.ve_y,2);
posterior.ve_y_std = std(posterior.ve_y,0,2);
posterior.ve_y_di = hpd_interval(posterior.ve_y);
% total variance of returns
posterior.v_y_mean = mean(posterior.v_y,2);
posterior.v_y_median = median(posterior.v_y,2);
posterior.v_y_std = std(posterior.v_y,0,2);
posterior.v_y_di = hpd_interval(posterior.v_y);
% variance of expectation % of total variance
posterior.y_md_mean = mean(posterior.y_md,2);
posterior.y_md_median = median(posterior.y_md,2);
posterior.y_md_std = std(posterior.y_md,0,2);
posterior.y_md_di = hpd_interval(posterior.y_md);
% duration of regime
posterior.regime_d_mean = mean(posterior.regime_d,2);
posterior.regime_d_median = median(posterior.regime_d,2);
posterior.regime_d_std = std(posterior.regime_d,0,2);
posterior.regime_d_di = hpd_interval(posterior.regime_d);
% expected cumulative returns per regime
posterior.e_cumrets_mean = mean(posterior.e_cumrets,2);
posterior.e_cumrets_median = median(posterior.e_cumrets,2);
posterior.e_cumrets_std = std(posterior.e_cumrets,0,2);
posterior.e_cumrets_di = hpd_interval(posterior.e_cumrets);
% expected cumulative returns per regime
posterior.e_cumbonds_mean = mean(posterior.e_cumbonds,2);
posterior.e_cumbonds_median = median(posterior.e_cumbonds,2);
posterior.e_cumbonds_std = std(posterior.e_cumbonds,0,2);
posterior.e_cumbonds_di = hpd_interval(posterior.e_cumbonds);

posterior.Y = Y;
posterior.X = X;
posterior.Z = Z;
cov_reshaped = zeros(nstate,nvar);
for m = 1:nstate
    posterior.smooth(:,m) = mean(posterior.state == m,2);
    cov_reshaped(s,:) = diag(posterior.omega_mean(:,:,s))';
end
posterior.npermute = npermute;

%% compute marginal likelihood
additional_draws = ceil(ndraws/2);
[m_llh] = sample_lik_tvtp(Y, X, Z, additional_draws, prior, posterior);
posterior.likelihood = m_llh;
marginal =0;% m_llh.marginal;
%% print result
result ={};
header = {'Coeff.','Post. mean', 'Post. median', 'Post. std', '5th perc.','95th perc.'};
result = [ result ; header ];
% responseVars, predictorVars
for i = 1:nreg
    result = [ result; {'', '', sprintf('$%s_{t+1}$', responseVars{i}), '', '', ''}];
    for j = 1:nvar
        for s = 1 :nstate
            row = sprintf('$%*s_{t}|s_t=%d$', 6, predictorVars{j}, s);
            row = {row, posterior.beta_mean_rs(j,i,s),posterior.beta_median(j,i,s), posterior.beta_std(j,i,s), posterior.beta_di(j,i,s,1), posterior.beta_di(j,i,s,2)};
            result = [ result ; row ];
        end
    end
end
result = [ result ; {'', '', 'Covariance Matrix', '', '', ''}];
for i = 1:nvar
    for j = 1:i
        for s = 1:nstate
            if j == i
                row = sprintf('$Var(%s_t|s_t=%d)$', responseVars{i}, s);
            else
                row = sprintf('$Cov(%s_t,%s_t|s_t=%d)$',responseVars{i}, responseVars{j}, s);
            end
            row = {row, posterior.omega_mean(i,j,s),posterior.omega_median(i,j,s), posterior.omega_std(i,j,s), posterior.omega_di(i,j,s,1), posterior.omega_di(i,j,s,2)};
            result = [ result ; row ];
        end
    end
end

ind = logical(repmat(eye(nstate),[1,2]));
state_header = {'', '', 'Transition probabilities','', '', '',};
result = [ result ; state_header ];
row = cell(2*nstate,6);
for m = 1:nstate
    row(m * nstate - nstate + 1,1) = {['\gamma_{',num2str(m),',',num2str(2),'}^{z}']};
    row(m * nstate - nstate + 2,1) = {['\gamma_{',num2str(m),',',num2str(2),'}']};
    
    numbers = [posterior.gamma_mean(ind(m,:),2),posterior.gamma_median(ind(m,:),2),posterior.gamma_std(ind(m,:),2),posterior.gamma_di(ind(m,:),1),posterior.gamma_di(ind(m,:),2)];
    for r = 1 : 5
        row(m * nstate - nstate + 1, r+1) = {numbers(1,r)};
        row(m * nstate - nstate + 2, r+1) = {numbers(2,r)};
    end
end
result = [ result ; row ];

stats_header = {'', '', 'Regime characteristics','', '', '',};
result = [ result ; stats_header ];
for m = 1:nstate
    row = sprintf('$E(D|s_t=%d)$', m);
    row = {row, posterior.regime_d_mean(m),posterior.regime_d_median(m),posterior.regime_d_std(m),posterior.regime_d_di(m,1),posterior.regime_d_di(m,2)};
    result = [ result ; row ];
end
% cumulative return
for m = 1:nstate
    row = sprintf('$E(\\sum r_t|s_t=%d$)', m);
    row = {row, posterior.e_cumrets_mean(m),posterior.e_cumrets_median(m),posterior.e_cumrets_std(m),posterior.e_cumrets_di(m,1),posterior.e_cumrets_di(m,2)};
    result = [ result ; row ];
end

% cumulative bond return
for m = 1:nstate
    row = sprintf('$E(\\sum corp_t|s_t=%d$)', m);
    row = {row, posterior.e_cumbonds_mean(m),posterior.e_cumbonds_median(m),posterior.e_cumbonds_std(m),posterior.e_cumbonds_di(m,1),posterior.e_cumbonds_di(m,2)};
    result = [ result ; row ];
end

row = ['$E(r_{t}|s_{t})$'];
row = {row, posterior.e_y_mean(1),posterior.e_y_median(1),posterior.e_y_std(1),posterior.e_y_di(1,1),posterior.e_y_di(1,2)};
result = [ result ; row ];

row = ['$E(Var(r_t|s_t)|s_t)$'];
row = {row, posterior.ev_y_mean(1),posterior.ev_y_median(1),posterior.ev_y_std(1),posterior.ev_y_di(1,1),posterior.ev_y_di(1,2)};
result = [ result ; row ];

row = ['$Var(E(r_t|s_t)|s_t)$'];
row = {row, posterior.ve_y_mean(1),posterior.ve_y_median(1),posterior.ve_y_std(1),posterior.ve_y_di(1,1),posterior.ve_y_di(1,2)};
result = [ result ; row ];

row = ['$Var(r_t|s_t)$'];
row = {row, posterior.v_y_mean(1),posterior.v_y_median(1),posterior.v_y_std(1),posterior.v_y_di(1,1),posterior.v_y_di(1,2)};
result = [ result ; row ];

row = ['$\frac{Var(E(r_t|s_t)|s_t)}{Var(r_t|s_t)}$'];
row = {row, posterior.y_md_mean(1),posterior.y_md_median(1),posterior.y_md_std(1),posterior.y_md_di(1,1),posterior.y_md_di(1,2)};
result = [ result ; row ];

disp(result);
posterior.result = result;
disp(['Number of permutations applied: ',num2str(npermute)])
disp(' ')

end

