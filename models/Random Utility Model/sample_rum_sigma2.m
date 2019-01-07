function [sigma2, a, b] = sample_rum_sigma2(state_vector,beta,prior,Y,X)

nstate = prior.nstate;
sigma2 = zeros(nstate,1);
a = zeros(nstate,1);
b = zeros(nstate,1);

for s = 1:nstate

    %%%%%%%%%%%%%%%% BLOCK 3 : SAMPLE E|M,P,S %%%%%%%%%%%%%%%%%%%%%
    
    % Sample posterior conditional draws from sigma2|. ~ IG(a,1/b)
    mask = (state_vector == s);
    Ts = sum(mask);
    Ys = Y(mask);
    Xs = X(mask,:);
    Yhs = Xs*beta;
    resid = Ys - Yhs(:,s);
    RSS = resid' * resid;
    a(s) = 0.5*Ts + prior.w(s);
    b(s) = 0.5*RSS + prior.W(s);
    sigma2(s) = 1./gamrnd(a(s), 1./b(s));
 
end
end

