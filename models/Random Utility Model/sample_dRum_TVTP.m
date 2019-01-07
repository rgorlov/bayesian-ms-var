function [TVTP,gam, G, Gg] = sample_dRum_TVTP(state_vector, prior, z, gam)
nstate = prior.nstate;
T = length(state_vector);
s2 = [0.6816    1.2419    2.2388    4.0724    7.4371   13.7720]';
D = zeros(T, nstate);
for s = 1 : nstate
    D(:,s) = double(state_vector == s);
end
D_lag = D(1:end-1,:);
D = D(2:end,:)';
Z = [repmat(z(2:end,:),[1,nstate]).*D_lag D_lag]'; 
i = nstate*2;
nobs = T - 1;
w = zeros(nstate,nobs);
R = zeros(nstate,nobs);

lambda = exp(Z'*gam)';
W = rand(nstate,nobs);
iota = ones(1,nobs);
for k = 2 : nstate
    lambda_k = sum(lambda,1) - lambda(k,:);
    fit = (Z'*gam(:,k) - log(lambda_k)')';
    pi_k = 1-(0.5 + 0.5*tanh(-0.5.*fit));
    p = D(k,:) + W(k,:).*(iota - D(k,:) - pi_k);
    logsmpl  = log(p) - log(1-p);
    w(k,:) = fit + logsmpl;
    R(k,:) = sample_errors_mex(w(k,:),fit);
    w(k,:) = w(k,:) + log(lambda_k);
end

gam = zeros(nstate*2,nstate);
for k = 2:nstate
    V = 1./s2(R(k,:));
    V = repmat(V',[nstate*2,1]);
    ZV = Z.*V;
    ZZ = ZV*Z';
    ZS = ZV*w(k,:)';
    
    G = (ZZ + inv(prior.G))\eye(i);
    g = ZS + prior.G\prior.g;
    Gg = G*g;
    gam(:,k) = Gg + chol(G)'*randn(i,1);
end

% % construct time varying parameter vectors
ind = logical(repmat(eye(nstate),[1,2]));
XX = [(z)' ; ones(1,T)]';
TVTP_vec = zeros(T,nstate,nstate);
for k = 1:nstate
    H = exp(XX*gam(ind(k,:),:));
    H = H./repmat(sum(H,2),[1,nstate]);
    TVTP_vec(:,:,k) = H;
end

% construct time varying matrices
TVTP = zeros(nstate,nstate,T);
for k = 1 : nstate
    TVTP(k,:,:) = reshape(TVTP_vec(:,:,k)', 1,nstate,T);
end

end
