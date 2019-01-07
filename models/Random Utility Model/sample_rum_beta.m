function [beta, Dd, D] = sample_rum_beta(state_vector,sigma2,prior,Y,X)
[nobs, nreg] = size(X);
nstate = prior.nstate;
D = zeros(nreg,nreg,nstate);
d = zeros(nreg,nstate);
Dd = d;
beta = d;
for s = 1:nstate
    %%%%%%%%%%%%%%%% BLOCK 2 : SAMPLE M|E,P,S %%%%%%%%%%%%%%%%%%%%%
    % Sample posterior conditional draws from mu|. ~ N(Dd,D)
    mask = (state_vector == s);
    Ys = Y(mask);
    Xs = X(mask,:);
    D(:,:,s) = ( Xs' * Xs ./ sigma2(s) + diag(1./prior.B(:,s)) ) \ eye(nreg);
    d(:,s) = Xs' * Ys ./ sigma2(s) + prior.b(:,s)./prior.B(:,s);
    Dd(:,s) = D(:,:,s) * d(:,s);
    
    beta(:,s) = Dd(:,s) +  chol(D(:,:,s))'*randn(nreg,1);
end

end

