function [Omega, v, R] = sample_Omega(state_vector,PI,prior,Y,X)
%%%%%%%%%%%%%%%% BLOCK 3 : SAMPLE E|M,P,S %%%%%%%%%%%%%%%%%%%%%


for s = 1:nstate
    
    % Sample posterior conditional draws from Omega^{-1}|. ~ WISHART(v,R)
    mask = (state_vector == s);
    Ts = sum(mask);
    Ys = Y(mask,:);
    Xs = X(mask,:);
    resid = Ys - Xs*PI(:,:,s);
    
    R(:,:,s) = resid' * resid + prior.R;
    v(s) = Ts + prior.v;
    U = randn(v(s), K);
    a = chol(R(:,:,s));
    Omega(:,:,s) = a'*inv(U'*U)*a;
    
end
end

