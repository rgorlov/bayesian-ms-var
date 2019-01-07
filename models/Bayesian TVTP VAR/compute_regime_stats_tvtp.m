function [e_y, ve_y, ev_y, v_y, y_md, unc_mean, regime_d, e_cumrets, e_cumbonds] = compute_regime_stats_tvtp(state, beta, omega, markov, Y, X)
[nobs, nvar] = size(Y);
[~, nreg] = size(X);
nstate = size(markov,2);
unc_mean = zeros(nstate,nvar);
omega_diag = zeros(nstate,nvar);
freq = zeros(nstate,nstate);
t_prob = zeros(nstate,nstate);
for s = 1 : nstate
    beta_rs = reshape(beta(:,s),[nvar,nreg]);
    mask = (state == s);
    Xs = X(mask,:);
    Ts = sum(mask);
    m_Xs = sum(Xs,1)./Ts;
    unc_mean(s,:) = m_Xs * beta_rs;
    d_Xs = Xs - repmat(m_Xs,[Ts,1]);
    cov_Xs = (d_Xs'*d_Xs)./(Ts - 1);
    Y_omega = (beta_rs' * cov_Xs) * beta_rs + omega(:,:,s);
    omega_diag(s,:) = diag(Y_omega)';
    
    mask_next = [false;mask(1:nobs-1)];
    State_next = state(mask_next);
    for k = 1:nstate
        freq(s,k) = sum(State_next == k);
    end  
    % expected transition probability
    t_prob(s,:) = freq(s,:)./Ts;
end
A = [t_prob'-eye(nstate) ; ones(1,nstate)];
e = [zeros(nstate,1);1];
initial = (A'*A)\(A'*e);

e_y = initial'*unc_mean;
% Var[ E[ rt | st ] | st = k ] = E[E[rt|st]^2| st = k ] - E[E[rt|st]| st = k ]^2
ve_y = initial'*unc_mean.^2 - (initial'*unc_mean).^2;
% E[ Var[ rt | st ] | st = k]
ev_y = initial'*omega_diag;

% Var[ rt | st = k ]
v_y = ev_y + ve_y;
% mean dynamics
y_md = ve_y ./ v_y;
% % expected duration per regime
regime_d = 1./(1-diag(t_prob));
% cumulative return during regime
e_cumrets = unc_mean(:,1).*regime_d;
e_cumbonds = unc_mean(:,2).*regime_d;
end