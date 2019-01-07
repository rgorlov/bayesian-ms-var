%% Optimal Myopic Portfolio
function w = myopicPort(sim_r, gamma)

% set parameters
% log risk free rate;
log_rf = 0;           
alpha = 0.01:0.01:1;
nPorts = length(alpha);
[G,~] = size(sim_r);

% make matrices
returns = repmat(exp(sim_r(:,1)),[1 nPorts]);
weights = repmat(alpha,[G 1]);

% compute conditional expectation given invester risk aversion
a = 1/(1-gamma);
inner = a.*((weights.*returns + (1-weights).*exp(0)).^(1-gamma));
cond_Exp = mean(inner,1);

% find weight for max conditional expectation
[~, index] = max(cond_Exp);
w = alpha(index);

end
