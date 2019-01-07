function [TVTP,gam] = sample_TVTP(state_vector, prior, z, gam)
nstate = prior.nstate;
T = length(state_vector);

w = [0.00397 0.0396 0.168 0.147 0.125 0.101 0.104 0.116 0.107 0.088]';
m = [5.09 3.29 1.82 1.24 0.764 0.391 0.0431 -0.306 -0.673 -1.06]';
s = [2.1213 1.4213 1.0488 0.6496 0.4450 0.3271 0.2789 0.2768 0.3077 0.3821]';
s2 = s.*s;
D = accumarray({(1:T)' state_vector},1);
D_lag = D(1:end-1,:);
D = D(2:end,:)';
Z = [repmat(z(2:end),[1,nstate]).*D_lag D_lag]'; 
nobs = T - 1;
p = nstate*2;
S = zeros(nstate,nobs);
R = zeros(nstate,nobs);
W = rand(1,nobs);
V = rand(nstate,nobs);
randnmix = randn(nstate,nobs);
fit = (Z'*gam).';
lambda = exp(fit);
for k = 2 : nstate
    a = -log(W)./sum(lambda,1);
    b = (-log(V(k,:))./lambda(k,:)).*(D(k,:)~=1);
    S(k,:) = -log(a+b);
    R(k,:) = sample_rum_errors(S(k,:),fit(k,:));
end
 
gam = zeros(nstate*2,nstate);
for k = 2:nstate
    V = diag(1./s2(R(k,:)));
    ZZ = (Z*V)*Z';
    a = S(k,:)-m(R(k,:)).';
    ZS = (Z*V)*(a.');
    G = (ZZ + inv(prior.G))\eye(p);
    g = (ZS + prior.G\prior.g);
    gam(:,k) = G*g + chol(G)'*randn(p,1);
end

% % construct time varying parameter vectors
ind = logical(repmat(eye(nstate),[1,2]));
XX = [(z).' ; ones(1,T)];
TVTP_vec = zeros(T,nstate,nstate);
for k = 1:nstate
    H = exp(XX'*gam(ind(k,:),:));
    H = H./repmat(sum(H,2),[1,nstate]);
    TVTP_vec(:,:,k) = H;
end

% construct time varying matrices
TVTP = zeros(nstate,nstate,T);
for k = 1 : nstate
    TVTP(k,:,:) = reshape(TVTP_vec(:,:,k).', 1,nstate,T);
end

end
