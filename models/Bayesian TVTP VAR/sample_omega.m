function [omega_inv, omega, post_omega, df] = sample_omega(state, beta, prior, Y, X)
[~, nvar] = size(Y);
[~, nreg] = size(X);
nstate = prior.nstate;
df = zeros(1,nstate);
post_omega = zeros(nvar,nvar,nstate);
omega = zeros(nvar,nvar,nstate);
omega_inv = zeros(nvar,nvar,nstate);

for s = 1 : nstate
    % Sample posterior conditional draws from Omega^{-1}|. ~ WISHART(R,v)
    mask = (state == s);
    Ts = sum(mask);
    Ys = Y(mask,:);
    Xs = X(mask,:);
    
    e = Ys - Xs*reshape(beta(:,s),[nvar,nreg]);
    rss = e' * e;
    post_omega(:,:,s) = inv( inv(prior.O(:,:,s)) + rss);
    df(s) = prior.v(s) + Ts - nreg - 2;
    omega_inv(:,:,s) = WISHART_RND(post_omega(:,:,s),df(s));
    omega(:,:,s) = omega_inv(:,:,s)\eye(nvar);
end

end