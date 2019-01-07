%% Optimal Myopic Portfolio
function [w,cer] = myopicPort_three_assets(sim_r, sim_br, gamma)

% set parameters
% log risk free rate;
log_rf = 0;
alpha = 0.01:0.01:1;
[G,~] = size(sim_r);
a = 1/(1-gamma);
% make matrices
returns = exp([sim_r sim_br]);
options = optimset('Algorithm','sqp','TolX',1e-14,'TolFun',1e-14,'MaxIter',100000,'MaxFunEvals',100000, 'Display', 'off');
lb = zeros(3,1);
ub = ones(3,1);
Aeq = ones(1,3);
beq = 1;

[w, fval, exitflag,~,~,~,Hessian] = fmincon(@(x)CondUtil(x), ones(3,1)/3, [], [], Aeq, beq, lb, ub, [], options);

    % find weight for max conditional expectation
    function cond_Exp = CondUtil(x)
        
        weights = repmat([ x(1) x(2) ],[G,1]);
        
        % compute conditional expectation given invester risk aversion
        inner = a.*((sum(weights.*returns,2) + x(3).*exp(0)).^(1-gamma));
        cond_Exp = -mean(inner,1);
    end
cer = (-fval*(1-gamma))^(a) - 1;
end