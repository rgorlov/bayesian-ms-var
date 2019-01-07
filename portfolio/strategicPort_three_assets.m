function [w_T,cer] = strategicPort_three_assets(sim_r, sim_br, sim_x, gamma)
[M, K]   = size(sim_r);
aversion = 1/(1-gamma);
appetite = 1/aversion;
e_sim_r  = exp(sim_r);
e_sim_br = exp(sim_br);
U_fut    = ones(M,1);
nports   = 101*101;
w_T      = ones(3, K);
portfolios = zeros(3, nports);
U        = ones(M, nports);
% create portfolios for grid search
w = 1;
cer = zeros(1,K);

for stock_weight = 0 : 0.01 : 1
    for bond_weight = 0 : 0.01 : 1
        weights = [stock_weight; bond_weight; 1-stock_weight-bond_weight];
        portfolios(:, w) = abs(weights)/sum(abs(weights));
        w = w + 1;
    end
end
% compute wealths for each period
% log_wealth = zeros(M, nports, K);
batchsize = 300;
% for t = 1 : K
%     returns = [e_sim_r(:, t), e_sim_br(:, t), ones(M,1)];
%     wealths = returns * portfolios;    
%     for buffer = 1 : ceil(nports/batchsize)
%         batch = batchsize * (buffer-1) + 1 : min(batchsize * buffer, nports);
%         log_wealth(:,batch,t) = exp(appetite .* log(wealths(:,batch)));
%     end
% end

for t = 1 : K
    
    N = t;
    
    for period = N-1:-1:1   
        % set up returns
        returns = [e_sim_r(:, period+1), e_sim_br(:, period+1), ones(M,1)];
        
        wealths = returns * portfolios;
        % compute wealth from portfolios
        for buffer = 1 : ceil(nports/batchsize)
            batch = batchsize * (buffer-1) + 1 : min(batchsize * buffer, nports);
            U(:,batch) = aversion * ((wealths(:,batch).^appetite) .* U_fut);
        end
        % compute utility for weight pairs
        X = [ones(M,1) squeeze(sim_x(:,period,:))'];
        beta = (X'*X)\(X'*U);
        U_cond = X*beta;
        
        % select optimal portfolio
        [~,I] = max(U_cond,[],2);
        W_opt = portfolios(:,I);
        
        % update vectors
        U_fut = (sum(returns .* W_opt', 2).^appetite) .*U_fut;
    end
    returns = [e_sim_r(:, 1), e_sim_br(:, 1), ones(M,1)];
    wealths = returns * portfolios;
    % solve for first period
    for buffer = 1 : ceil(nports/batchsize)
        batch = batchsize * (buffer-1) + 1 : min(batchsize * buffer, nports);
        U(:,batch) = aversion * ((wealths(:,batch).^appetite) .* U_fut);
    end
    % compute utility for weight pairs
    [fval,I] = max(mean(U, 1), [], 2);
    W_opt = portfolios(:,I);
    cer(:,t) = (-fval*appetite)^aversion - 1;
    w_T(:,t) = W_opt;
    U_fut  = ones(M,1);
    disp(['Done ' num2str(t) ' period.'])
end
end