%% Optimal Buy & Hold Portfolio
function [w3,cer] = bhPort(sim_sr, sim_br, gamma)

% get total number of K periods
[~,K] = size(sim_sr);

% compute the cumulative return up to k-th period.
cum_sr = cumsum(sim_sr,2); % excess stock returns
cum_br = cumsum(sim_br,2); % excess bond returns

% for each period compute the weight, since it is the myopic solution.
w  = zeros(1,K);
w3 = zeros(3,K);
cer = zeros(1,K);
for k = 1 : K
    
%     w(1,k) = myopicPort(cum_sr(:,k), gamma);
    [w3(:,k), cer(:,k)] = myopicPort_three_assets(cum_sr(:,k), cum_br(:,k), gamma);
end

disp(['Computed buy & hold portfolio for gamma: ', num2str(gamma)]);

end