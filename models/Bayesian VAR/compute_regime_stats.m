function [e_y, ve_y, ev_y, v_y, y_md, unc_mean, regime_d, e_cumrets, e_cumbonds, unc_sharpe] = compute_regime_stats(state, beta, omega, markov, initial, Y, X)
[~, nvar] = size(Y);
[~, nreg] = size(X);
nstate = size(markov,2);
unc_mean = zeros(nstate,nvar);
unc_sharpe = zeros(nstate,nvar);
omega_diag = zeros(nstate,nvar);
for s = 1 : nstate
    beta_rs = reshape(beta(:,s),[nvar,nreg]);
    mask = (state == s);
    Xs = X(mask,:);
    Ts = sum(mask);
    m_Xs = sum(Xs,1)./Ts;
    unc_mean(s,:) = sum(Xs * beta_rs, 1)./Ts;
    unc_sharpe(s,:)  = unc_mean(s,:)./std(Xs * beta_rs, 1);
    d_Xs = Xs - repmat(m_Xs,[Ts,1]);
    cov_Xs = (d_Xs'*d_Xs)./(Ts - 1);
    Y_omega = (beta_rs' * cov_Xs) * beta_rs + omega(:,:,s);
    omega_diag(s,:) = diag(Y_omega)';
end
e_y = initial'*unc_mean;
% Var[ E[ rt | st ] | st = k ] = E[E[rt|st]^2| st = k ] - E[E[rt|st]| st = k ]^2
ve_y = initial'*unc_mean.^2 - (initial'*unc_mean).^2;
% E[ Var[ rt | st ] | st = k]
ev_y = initial'*omega_diag;

% Var[ rt | st = k ]
v_y = ev_y + ve_y;
% mean dynamics
y_md = ve_y ./ v_y;
% expected duration per regime
regime_d = 1./(1-diag(markov));
% cumulative return during regime
e_cumrets = unc_mean(:,1).*regime_d;
e_cumbonds = unc_mean(:,2).*regime_d;

end