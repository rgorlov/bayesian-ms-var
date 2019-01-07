function [beta, Dd, D]  = sample_matric_beta(state,omega_inv,prior,Y,X)
[~, nvar] = size(Y);
[~, nreg] = size(X);
nstate = prior.nstate;
D = zeros(nreg*nvar,nreg*nvar,nstate);
Dd = zeros(nreg*nvar,nstate);
beta = zeros(nreg*nvar,nstate);
for s = 1:nstate
    
    % Count observation in state s
    mask = (state == s);
    Ts = sum(mask);
    Ys = Y(mask,:);
    Xs = X(mask,:);
    
    % A faster method is to cholesky decompose Sigma,
    % and use it to standardize SUR data, then apply Lindley Smith
    P = chol(omega_inv(:,:,s));
    Y_mat_sd = P * Ys';
    Y_SUR_sd = Y_mat_sd(:);
    kt     = nreg*Ts;
    X_SUR_sd = zeros(nreg*Ts,nreg);
    for n = 1:nvar
        for k = 1:n
            X_SUR_sd(k:nreg:kt, (n-1)*nreg+1 : n*nreg) = P(k,n) .* Xs;
        end
    end
    
    % Sample posterior conditional draws from (Mu,Delta)|. ~ N(Dd,D)
    Beta_prec = X_SUR_sd' * X_SUR_sd + inv(prior.B(:,:,s)); D(:,:,s) = Beta_prec\eye(nreg*nvar);
    Beta_mean = Beta_prec \ (X_SUR_sd'*Y_SUR_sd + prior.B(:,:,s) \ prior.b(:,s));
    beta_use = Beta_mean + chol(Beta_prec) \ randn(nvar*nreg,1); Dd(:,s) = Beta_mean(:);
    beta(:,s) = beta_use(:);
    
%     if any(isempty(beta)) || any(any(isnan(beta))) || any(isempty(Xs)) || any(any(isnan(Xs))) || length(unique(state))~=nstate
%         OK = false(1)
%     end
end

end