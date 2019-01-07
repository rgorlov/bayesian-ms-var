function [posterior, prior, marginal] = HMM_VAR(Y,X,nstate,ndraws,burn_in,permute, responseVars, predictorVars)
% --------------------------------------------------------
% get model dimensions
[nobs, nvar] = size(Y);
[ ~, nreg  ] = size(X);
% --------------------------------------------------------
% Prior distribution settings
% beta(s) ~ N(b(s),B(s))
% omega(s) ~ IW(v(s),O(s))
%  Q(s) ~ Dirichlet(a1,...,aS)
% pi(s) ~ Dirichlet(c1,...,cS)
% You may change the hyperparameters here if needed
nperiods = 120;
prior.nstate = nstate;
prior.b = zeros(nvar*nreg,nstate);
prior.B = repmat(100 * eye(nvar*nreg),[1 1 nstate]);
prior.O = repmat(1000*eye(nvar),[1 1 nstate]);
prior.v = (nvar + 5) .* ones(nstate,1);
prior.markov = ones(nstate,nstate);
prior.initital = ones(nstate,1);
permute_flag = permute.flag;
permute_var  = permute.var;
permute_var2 = permute.var2;
% Set variable and predictor names
posterior.model         = 'msvar';
posterior.responseVars  = responseVars;
posterior.predictorVars = predictorVars;
% --------------------------------------------------------
% Preallocate memory
posterior.beta = zeros(nvar*nreg, nstate, ndraws - burn_in);
posterior.Dd = zeros(nvar*nreg, nstate, ndraws - burn_in);
posterior.D = zeros(nvar*nreg, nvar*nreg, nstate, ndraws - burn_in);
posterior.omega = zeros(nvar, nvar, nstate, ndraws - burn_in);
posterior.post_omega = zeros(nvar, nvar, nstate, ndraws - burn_in);
posterior.df = zeros(nstate, ndraws - burn_in);
posterior.markov = zeros(nstate^2, ndraws - burn_in);
posterior.post_markov = zeros(nstate^2, ndraws - burn_in);
posterior.initial = zeros(nstate,ndraws - burn_in);
posterior.state = zeros(nobs, ndraws - burn_in);
posterior.unc_mean = zeros(nstate,nvar, ndraws - burn_in);
posterior.sim_r = zeros(ndraws - burn_in, nperiods );
posterior.sim_x = zeros(nreg-1, nperiods, ndraws - burn_in);
posterior.sim_state = zeros(ndraws - burn_in, nperiods );
npermute = 0;
% --------------------------------------------------------
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
    beta_in = (Xs'*Xs)\(Xs'*Ys) + chol(inv(Xs'*Xs))*randn(nreg,nvar);
    beta(:,s) = beta_in(:);
    omega(:,:,s) = (Ys-Xs*beta_in)'*(Ys-Xs*beta_in)/(Ts-nvar);
    omega_inv(:,:,s) = omega(:,:,s)\eye(nvar);
end

msg = ('Gibbs sampler running.');
% Gibbs sampler
for r = 1:ndraws
    
    try
        [ beta, Dd, D ]  = sample_matric_beta(state, omega_inv, prior, Y, X);
        [ omega_inv, omega, post_omega, df ] = sample_omega(state, beta, prior, Y, X);
        [ markov, initial, post_markov ] = sample_markov(state, prior);
        [ state ] = sample_state_chib_mex(beta, omega, markov, initial, Y, X);
    catch err
        fprintf('caught error\n');
        stop = true;
    end
    
    % Permute parameters for desired order
    switch permute_flag
        case 1
            [~,ind] = sort(beta(permute_var,:), 'descend');
            %             coefs = reshape(beta,[nvar,nreg,nstate]);
            % E[R_t]_{1} > ... > E[R_t]_{K}
        case 2
            [~, ~, ~, ~, ~, unc_mean, ~, ~, ~,unc_sharpe] = compute_regime_stats(state, beta, omega, markov, initial, Y, X);
            [~,ind] = sort(unc_mean(:,permute_var), 'descend');
            % V[R_t]_{1} >...> V[R_t]_{K}
        case 3
            [~,ind] = sort(omega(permute_var,permute_var,:), 'descend');
            % Cov(R_t,X_t,{1}) > ... > Cov(R_t,X_t,{K})
        case 4
            [~,ind] = sort(omega(1,permute_var,:), 'descend');
            % permute random
        case 5
            % permute on the correlation of  two variables
            var1 = omega(permute_var, permute_var,:);
            var2 = omega(permute_var2, permute_var2,:);
            cov  = omega(permute_var, permute_var2,:);
            cor  = cov ./ (sqrt(var1) .* sqrt(var2));
            [~,ind] = sort(cor, 'descend');
        otherwise
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
        
        markov = markov(ind,ind);
        post_markov = post_markov(ind,ind);
        initial = initial(ind);
        
        E = accumarray({(1:nobs)' state},1);
        E = E(:,ind).*repmat((1:nstate),[nobs,1]);
        state = sum(E,2);
        
        npermute = npermute + 1;
    end
    
    timer_bar(r,ndraws,msg)
        
        % Record the draws
        if r > burn_in
            [e_y, ve_y, ev_y, v_y, y_md, unc_mean, regime_d, e_cumrets, e_cumbonds, ~] = compute_regime_stats(state, beta, omega, markov, initial, Y, X);
            s_T = Y(nobs,2:end);
            state_last = state(nobs);
            %         [sim_r, sim_x, sim_state] = sim_var(s_T,beta,omega,markov,state_last,nperiods);
            [sim_r, sim_x, sim_state] = sim_var_mex(s_T,beta,omega,markov,state_last,nperiods);
            posterior.sim_r( r - burn_in, : ) = sim_r;
            posterior.sim_x( :, :, r - burn_in ) = sim_x;
            posterior.sim_state( r - burn_in, : ) = sim_state;
            
            posterior.beta(:, :, r - burn_in) = beta;
            posterior.omega(:, :, :, r - burn_in) = omega;
            posterior.markov(:, r - burn_in) = markov(:);
            posterior.initial(:, r - burn_in) = initial;
            posterior.state(:, r - burn_in) = state;
            
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
            posterior.post_markov(:, r - burn_in) = post_markov(:);
            
        end
%     end
end
posterior.beta_mean = mean(posterior.beta,3);
posterior.beta_mean_rs = reshape(posterior.beta_mean,[nreg,nvar,nstate]);
posterior.beta_median = median(posterior.beta,3);
posterior.beta_median = reshape(posterior.beta_median,[nreg,nvar,nstate]);
posterior.beta_std = std(posterior.beta,0,3);
posterior.beta_std = reshape(posterior.beta_std,[nreg,nvar,nstate]);
posterior.beta_di = hpd(posterior.beta);
posterior.beta_di = reshape(posterior.beta_di,[nreg,nvar,nstate,2]);

posterior.omega_mean = mean(posterior.omega,4);
posterior.omega_median = median(posterior.omega,4);
posterior.omega_std = std(posterior.omega,0,4);
posterior.omega_di = hpd(reshape(posterior.omega,[nvar*nvar,nstate,r - burn_in]));
posterior.omega_di = reshape(posterior.omega_di,[nvar,nvar,nstate,2]);

posterior.markov_mean = mean(reshape(posterior.markov,[nstate,nstate, r - burn_in]),3);
posterior.markov_median = median(reshape(posterior.markov,[nstate,nstate, r - burn_in]),3);
posterior.markov_std = std(reshape(posterior.markov,[nstate,nstate, r - burn_in]),0,3);
posterior.markov_di = hpd_interval(posterior.markov);
posterior.markov_di = reshape(posterior.markov_di,[nstate,nstate,2]);

posterior.initial_mean = mean(posterior.initial,2);
posterior.initial_median = median(posterior.initial,2);
posterior.initial_std = std(posterior.initial,0,2);
posterior.initial_di = hpd_interval(posterior.initial);

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
cov_reshaped = zeros(nstate,nvar);
for m = 1:nstate
    posterior.smooth(:,m) = mean(posterior.state == m,2);
    cov_reshaped(s,:) = diag(posterior.omega_mean(:,:,s))';
end
posterior.npermute = npermute;
%% compute marginal likelihood
additional_draws = ceil(ndraws/2);
[m_llh] = sample_Likelihood(Y, X, additional_draws, prior, posterior);
posterior.likelihood = m_llh;
marginal = m_llh.marginal;

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

transition_header = {'', '', 'Transition probabilities','', '', '',};
result = [ result ; transition_header ];
for i = 1 : nstate
    for j = 1 : nstate
        row = sprintf('$p_{%d,%d}$', i, j);
        row = {row,posterior.markov_mean(i,j),posterior.markov_median(i,j),posterior.markov_std(i,j), posterior.markov_di(i,j,1), posterior.markov_di(i,j,2)};
        result = [ result ; row ];
    end
end
state_header = {'', '', 'Unconditional state probabilities','', '', '',};
result = [ result ; state_header ];
for m = 1:nstate
    row = sprintf('$\\pi_{%d}$', m);
    row = {row, posterior.initial_mean(m),posterior.initial_median(m),posterior.initial_std(m),posterior.initial_di(m,1),posterior.initial_di(m,2)};
    result = [ result ; row ];
end

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
