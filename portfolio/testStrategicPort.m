%% Test Brandt 2010 - plug in method
beta_brandt = [0.2049 0.0568; -0.1694 0.9514];  %table 5.1 Brandth 2010
cov_brandt  = 1e-03*[6.225 -6.044; -6.044 6.316]; %table 5.1 Brandth 2010

M = 200;      %Number of simulations
N = 15;       %Number of periods
s_T = -3.3;   %starting point

VAR = repmat([1 s_T]*beta_brandt',[M,1]) + mvnrnd([0 0],cov_brandt,M);
sim_dp = zeros(M,N);
sim_dp(:,1) = VAR(:,2);
sim_r  = zeros(M,N);
sim_r(:,1) = VAR(:,1);
sim_br  = zeros(M,N);
sim_br(:,1) = VAR(:,1);
for i = 2:N
    sim = mvnrnd([0 0],cov_brandt,M);
    VAR = [ones(M,1) sim_dp(:,i-1)]*beta_brandt' + sim;
    sim_r(:,i) = VAR(:,1);
    sim_br(:,i) = VAR(:,1);
    sim_dp(:,i) = VAR(:,2);
end

sim_x = [reshape(sim_dp, [1, N, M]) ; reshape(sim_dp, [1, N, M])];
w_T = strategicPort_three_assets(sim_r, sim_br, sim_x, gamma);
plot(1:N,w_T)
