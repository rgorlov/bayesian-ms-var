function w_T = dynamicPortT(sim_r, sim_br, sim_x, sim_state, gamma)
%% Optimal Dynamic portfolio
[M, K]   = size(sim_r);
[F, ~,~] = size(sim_x);
log_rf   = 0;
% set up portfolio grid search
alpha    = 0:0.01:1;
U_fut    = ones(M,1);
aversion = 1/(1-gamma);
appetite = 1/aversion;
e_sim_r  = exp(sim_r);
e_sim_br = exp(sim_br);
nPorts   = length(alpha);
% doot     = zeros(M, nPorts, K);
w_T      = zeros(3,K);
weights  = repmat(alpha, [ M 1 ]);
% for t = 1 : K
%     returns = repmat(e_sim_r(:,t), [1, nPorts]);
%     wealth = weights.*returns + (1-weights).*exp(log_rf);
%     doot(:,:,t) = wealth.^appetite;
% end
options = optimset('Algorithm','sqp','TolX',1e-14,'TolFun',1e-14,'MaxIter',100000,'MaxFunEvals',100000, 'Display', 'off');
lb = zeros(3,1);
ub = ones(3,1);
Aeq = ones(1,3);
beq = 1;
for t = 1 : K
    
    N = t;
    W_opttrack = zeros(M,N);
    
    % backward recursoin starting in period N - 1
    for period = N-1:-1:1
        
%         U_futmat = repmat(U_fut, [1, nPorts]);
        returns  = [e_sim_r(:, period+1), e_sim_br(:, period+1)];
        X = [ones(M,1) squeeze(sim_x(:,period,:))'];
        
        [w, fval, exitflag,~,~,~,Hessian] = fmincon(@(x)CondUtil(x), ones(3,1)/3, [], [], Aeq, beq, lb, ub, [], options);
                        
        % update vectors
        U_fut = (([returns, ones(M,1)] * w).^appetite).*U_fut;
    end
    % solve for first period.
    returns  = [e_sim_r(:, 1), e_sim_br(:, 1)];
    X = [ones(M,1)];
    [w, fval, exitflag,~,~,~,Hessian] = fmincon(@(x)CondUtil(x), ones(3,1)/3, [], [], Aeq, beq, lb, ub, [], options);

    w_T(:,t) = w;
    U_fut  = ones(M,1);
    disp(['Done ' num2str(t) ' period.'])
end
    function cond_Exp = CondUtil(x)
        % compute conditional expectation given invester risk aversion
        inner = aversion.*((([returns, ones(M,1)] * x).^appetite) .* U_fut);
        cond_Exp = -mean(X * ((X' * X)\(X'*inner)));
    end
end