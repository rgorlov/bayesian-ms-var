function [PI, Dd, D] = sample_PI(state_vector,Omega,prior,Y,X)
[~, J] = size(Y);
[~, K] = size(X);
nstate = prior.nstate;
D = zeros(K*J,K*J,nstate);
d = zeros(K,J,nstate);
Dd = zeros(K*J,1,nstate);
PI = zeros(K,J,nstate);

for s = 1:nstate
    %%%%%%%%%%%%%%%% BLOCK 2 : SAMPLE M|E,P,S %%%%%%%%%%%%%%%%%%%%%
    % Sample posterior conditional draws from mu|. ~ N(Dd,D)
    mask = (state_vector == s);
    Ys = Y(mask,:);
    Xs = X(mask,:);
    A = (Xs' * Xs)\(Xs' * Ys);
    Omega_s = Omega(:,:,s);
    
    E = kron(Omega_s\eye(J),Xs'*Xs);
    D(:,:,s) = (inv(prior.V) + E)\eye(J*K);
    Dd(:,:,s) = D(:,:,s) * (prior.V\prior.PI_mean(:,:,s)' + E*A(:));
    B = Dd(:,:,s) + chol(D(:,:,s))'*randn(J*K,1);
    
    PI(:,:,s) = reshape(B,[J,K]);
end
end

