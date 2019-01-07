function W_dyn = dynPort(sim_r, sim_dp, gamma)

[M,N] = size(sim_r);
log_rf = 0;
alpha = 0:0.01:1;
U_fut  = ones(M,1);      %Initial Future Utility set to 1 as optimization stops at period 14.
U_opt  = -1*ones(M,1);   %Optimal Utility
W_opt  = zeros(M,1);     %Optimal Portfolio Weights

%backward recursoin starting in period N-1 = 14.
for period = N-1:-1:1;
    %Grid point based on 1 % steps
    for a_G = 1:length(alpha);    
        U = (1/(1-gamma))*((alpha(a_G)*exp(sim_r(:,period+1)) + (1-alpha(a_G))*exp(log_rf)).^(1-gamma).*U_fut);
        X = [ones(M,1) sim_dp(:,period)];
        beta = (X'*X)\(X'*U);
        U_cond = X*beta;
        
        i = U_cond > U_opt;
        U_opt(i) = U_cond(i);
        W_opt(i) = alpha(a_G);
    end
    % update vectors
    U_fut = ((W_opt.*exp(sim_r(:,period+1)) + (1-W_opt).*exp(log_rf)).^(1-gamma).*U_fut);
    %re intialize vectors
    U_opt  = -1*ones(M,1);   
    W_opt  = zeros(M,1);
end
        
for a_G = 1:length(alpha);   
        U = (1/(1-gamma))*((alpha(a_G)*exp(sim_r(:,1)) + (1-alpha(a_G))*exp(log_rf)).^(1-gamma).*U_fut);
        X = [ones(M,1)];
        beta = (X'*X)\(X'*U);
        U_cond = X*beta;
        
        i = U_cond > U_opt;
        U_opt(i) = U_cond(i);
        W_opt(i) = alpha(a_G);
end

W_dyn = W_opt(1);
end