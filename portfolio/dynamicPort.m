function w = dynamicPort(sim_r,sim_x,sim_state,gamma)
%% Optimal Dynamic portfolio
[M,N] = size(sim_r);
log_rf = 0;
alpha = 0.01:0.01:1;
U_fut  = ones(M,1);      %Initial Future Utility set to 1 as optimization stops at period 14.
%backward recursoin starting in period N - 1 = 14.
g = 1/(1-gamma);
g_inv = 1/g;
sim_r = exp(sim_r);
nPorts = length(alpha);
nstate = length(unique(sim_state(:,1)));
U_cond = zeros(M,nPorts);
for period = N-1:-1:1;
    %Grid point based on 1 % steps
    returns  = repmat(sim_r(:,period+1),[ 1 nPorts ] );
    weights = repmat(alpha, [ M 1 ]);
    states = repmat(sim_state(:,period+1),[ 1 nPorts]);
    inner = weights.*returns + (1-weights).*exp(log_rf);
    U_futmat = repmat(U_fut, [ 1 nPorts ]);
    
    root = (inner.^g_inv);
    
    U = g.*(root.*U_futmat);
    
    for s = 1 : nstate
        mask = (sim_state(:,period+1) == s);
        m = sum(mask);
        X = [ones(m,1) sim_x(mask,period)];
        
        beta = (X'*X)\(X'*U(mask,:));
        U_cond(mask,:) = X*beta;
    end
    
    [~,I] = max(U_cond,[],2);
    W_opt = alpha(I)';
    
    % update vectors
    U_fut = ((W_opt.*sim_r(:,period+1) + (1-W_opt).*exp(log_rf)).^g_inv).*U_fut;
end

% solve for first period.
returns  = repmat(sim_r(:,1),[ 1 nPorts ] );
weights = repmat(alpha, [ M 1 ]);
inner = weights.*returns + (1-weights).*exp(log_rf);
U_futmat = repmat(U_fut, [ 1 nPorts ]);

root = inner.^g_inv;
U = g.*(root.*U_futmat);
for s = 1 : nstate
    mask = (sim_state(:,1) == s);
    m = sum(mask);
    X = [ones(m,1)];
    
    beta = (X'*X)\(X'*U(mask,:));
    U_cond(mask,:) = X*beta;
end

[~,I] = max(U_cond,[],2);
W_opt = alpha(I)';

w = W_opt(1);


end
