%% RUM & DRUM models generate simulations
T = 700;
n_t = sqrt(0.5)*randn(T,1);
z = zeros(T,1);
z(1) = n_t(1);
for t = 2 : T
    z(t)  = 0.8*z(t-1) + n_t(t);
end
% set time varying parameters
gam  = [4 , 1 ,-2 , 2];

gam1  = [0 , 0 , 0,  0 , 0,  0]; % prob to state 1
gam2  = [4 , 0 , 1, -2 , 2,  0]; % prob to state 2
gam3  = [4 , 1 , 0, -2 , 0,  2]; % prob to state 3

%increase in Z will deteriorate persisentce across all states
%decrease in Z will improve persistence across all states.

gam = [gam1 ; gam2 ; gam3]';

Z_m = 0.5;
nstate = 3;
ind = logical(repmat(eye(nstate),[1,2]));
XX = [(z-Z_m)' ; ones(1,T)];
TVTP_vec = zeros(T,nstate,nstate);
for k = 1:nstate
    H = exp(XX'*gam(ind(k,:),:));
    H = H./repmat(sum(H,2),[1,nstate]);
    TVTP_vec(:,:,k) = H;
end
% construct time varying matrices
markov_T = zeros(nstate,nstate,T);
for k = 1 : nstate
    markov_T(k,:,:) = reshape(TVTP_vec(:,:,k).', 1,nstate,T);
end

beta_brandt_1 = [0.2049 0.0568; -0.1694 0.9514];  %table 5.1 Brandth 2010
beta_brandt_2 = [0.001 0.01; -0.1 0.90];  
beta(:,:,1) = beta_brandt_1;
beta(:,:,2) = beta_brandt_2;

cov_brandt_1  = 10^(-3)*[6.225 -6.044; -6.044 6.316]; %table 5.1 Brandth 2010
cov_brandt_2  = 10^(-3)*[20.225 0; 0 20.316]; 
cov(:,:,1) = cov_brandt_1;
cov(:,:,2) = cov_brandt_2;

M = 1;      %Number of simulations
s_T = -3.3;      %starting point
s = ceil(nstate*rand);
state = zeros(1,T);
state(1) = s;
VAR = repmat([1 s_T]*beta(:,:,s)',[M,1]) + mvnrnd([0 0],cov(:,:,s),M);
sim_dp = zeros(M,T);
sim_dp(:,1) = VAR(:,2);
sim_r  = zeros(M,T);
sim_r(:,1) = VAR(:,1);
for t = 2:T
    state(t) = con_state_draw(markov_T(:,:,t),state(t-1));
    sim = mvnrnd([0 0],cov(:,:,state(t)),M);
    VAR = [ones(M,1) sim_dp(:,t-1)]*beta(:,:,state(t))' + sim;
    sim_r(:,t) = VAR(:,1);
    sim_dp(:,t) = VAR(:,2);
end

var_k = var(cumsum(sim_r,2))./(1:T);
plot(var_k,'LineWidth',2)
text(min((1:length(var_k))'+.25,14.95),var_k', cellstr(num2str(var_k','%.4f'))','FontWeight', 'bold');
ylabel('$\frac{1}{K}Var_{t}(r_{t->t+K})$','interpreter','latex','Fontsize', 16)
xlabel('Horizon K','FontWeight', 'bold')
title('Conditional Variance - plug-in method','FontWeight', 'bold');
axis tight;

% clearvars -except y state x1 x2 z nstate T

%% estimate simulations
ind = 2:T;
Y =  [ sim_r(1,2:end)' sim_dp(1,2:end)'];
X  = [ ones(length(Y),1) sim_dp(1,1:end-1)'];
Z  = z(1:end-1);

nstate  = 2;
ndraws = 30000;
burn_in = 10000;
thin =1;
permute_flag = 1;
Z_th = 0;
[posterior_d, prior_d] = HMM_VAR_TVTP(Y,X,Z-Z_th,nstate,ndraws,burn_in,permute_flag);
%% PLOT Posterior distribution 
graph_smooth(cumsum(Y(:,1)),posterior_tvtp.smooth,dates(2:end))

d = (ndraws-burn_in)/1;
% plot betas 1
subplot(2,4,1)
hold all
[f,xi] = ksdensity(reshape(posterior_tvtp.beta(1,1,:),[d,1]));
plot(xi,f,'--b','LineWidth',1.5)
[f,xi] = ksdensity(reshape(posterior_tvtp.beta(1,2,:),[d,1]));
plot(xi,f,'-r','LineWidth',1.5)
xlabel('\beta_{1,1}');

%plot betas 2
subplot(2,4,2)
hold all
[f,xi] = ksdensity(reshape(posterior_tvtp.beta(2,1,:),[d,1]));
plot(xi,f,'--b','LineWidth',1.5)
[f,xi] = ksdensity(reshape(posterior_tvtp.beta(2,2,:),[d,1]));
plot(xi,f,'-r','LineWidth',1.5)
xlabel('\beta_{1,2}');

%plot betas 3
subplot(2,4,3)
hold all
[f,xi] = ksdensity(reshape(posterior_tvtp.beta(3,1,:),[d,1]));
plot(xi,f,'--b','LineWidth',1.5)
[f,xi] = ksdensity(reshape(posterior_tvtp.beta(3,2,:),[d,1]));
plot(xi,f,'-r','LineWidth',1.5)
xlabel('\beta_{2,1}');

%plot betas 4
subplot(2,4,4)
hold all
[f,xi] = ksdensity(reshape(posterior_tvtp.beta(4,1,:),[d,1]));
plot(xi,f,'--b','LineWidth',1.5)
[f,xi] = ksdensity(reshape(posterior_tvtp.beta(4,2,:),[d,1]));
plot(xi,f,'-r','LineWidth',1.5)
xlabel('\beta_{2,2}');
legend('Regime 1 Risk on','Regime 2 Risk off','Location','NorthEast')

%plot gammas
subplot(2,4,5)
hold all
[f,xi] = ksdensity(reshape(posterior_tvtp.gamma(1,2,:),[d 1]));
plot(xi,f,'--b','LineWidth',1.5)
[f,xi] = ksdensity(reshape(posterior_tvtp.gamma(2,2,:),[d 1]));
plot(xi,f,'-r','LineWidth',1.5)
xlabel('\gamma_{k2}^{z}');

%plot gammas
subplot(2,4,6)
hold all
[f,xi] = ksdensity(reshape(posterior_tvtp.gamma(3,2,:),[d 1]));
plot(xi,f,'--b','LineWidth',1.5)
[f,xi] = ksdensity(reshape(posterior_tvtp.gamma(4,2,:),[d 1]));
plot(xi,f,'-r','LineWidth',1.5)
xlabel('\gamma_{k2}');

%plot sigmas
subplot(2,4,7)
hold all 
[f,xi] =ksdensity(reshape(posterior_tvtp.omega(1,1,1,:),[d 1]));
plot(xi,f,'--b','LineWidth',1.5)
[f,xi] = ksdensity(reshape(posterior_tvtp.omega(1,1,2,:),[d 1]));
plot(xi,f,'-r','LineWidth',1.5)
xlabel('\sigma^{2}_{k}');

%plot covariances
subplot(2,4,8)
hold all 
[f,xi] =ksdensity(reshape(posterior_tvtp.omega(1,2,1,:),[d 1]));
plot(xi,f,'--b','LineWidth',1.5)
[f,xi] = ksdensity(reshape(posterior_tvtp.omega(1,2,2,:),[d 1]));
plot(xi,f,'-r','LineWidth',1.5)
xlabel('\sigma_{12,k}');


%% get marginal of threshold.
itt = mod(1:(ndraws-burn_in),thin)==0;
d= sum(itt);
xi11 = reshape(posterior_tvtp.tvtp(1,1,:,itt),[length(Z),d]);
xi22 = reshape(posterior_tvtp.tvtp(2,2,:,itt),[length(Z),d]);
hold all
ab = abs(xi11-xi22)<0.00001;
c =logical(sum(ab,1));
figure
plot(Z,[xi22(:,c) xi11(:,c)],'o','MarkerSize',1)
figure
ksdensity(Z(sum(ab,2)~=0))
Z_th = mean(Z(sum(ab,2)~=0));
median(Z(sum(ab,2)~=0));
hpd_interval(Z(sum(ab,2)~=0));

