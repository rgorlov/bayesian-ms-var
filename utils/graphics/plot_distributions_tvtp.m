%% PLOT Posterior distribution
function plot_distributions_tvtp(posterior,ndraws,burn_in)

d = ndraws-burn_in;
thinned = mod(1:d,1)==0;
d = sum(thinned);
% plot betas 1
figure
subplot(2,4,1)
hold all
[f,xi] = ksdensity(reshape(posterior.beta(1,1,thinned),[d,1]));
plot(xi,f,'--b','LineWidth',1.5)
[f,xi] = ksdensity(reshape(posterior.beta(1,2,thinned),[d,1]));
plot(xi,f,'-r','LineWidth',1.5)
xlabel('\beta_{1,1}');

%plot betas 2
subplot(2,4,2)
hold all
[f,xi] = ksdensity(reshape(posterior.beta(2,1,thinned),[d,1]));
plot(xi,f,'--b','LineWidth',1.5)
[f,xi] = ksdensity(reshape(posterior.beta(2,2,thinned),[d,1]));
plot(xi,f,'-r','LineWidth',1.5)
xlabel('\beta_{1,2}');

%plot betas 3
subplot(2,4,3)
hold all
[f,xi] = ksdensity(reshape(posterior.beta(3,1,thinned),[d,1]));
plot(xi,f,'--b','LineWidth',1.5)
[f,xi] = ksdensity(reshape(posterior.beta(3,2,thinned),[d,1]));
plot(xi,f,'-r','LineWidth',1.5)
xlabel('\beta_{2,1}');

%plot betas 4
subplot(2,4,4)
hold all
[f,xi] = ksdensity(reshape(posterior.beta(4,1,thinned),[d,1]));
plot(xi,f,'--b','LineWidth',1.5)
[f,xi] = ksdensity(reshape(posterior.beta(4,2,thinned),[d,1]));
plot(xi,f,'-r','LineWidth',1.5)
xlabel('\beta_{2,2}');
legend('Regime 1 Risk on','Regime 2 Risk off','Location','NorthEast')

%plot gammas
subplot(2,4,5)
hold all
[f,xi] = ksdensity(reshape(posterior.gamma(1,2,thinned),[d 1]));
plot(xi,f,'--b','LineWidth',1.5)
[f,xi] = ksdensity(reshape(posterior.gamma(2,2,thinned),[d 1]));
plot(xi,f,'-r','LineWidth',1.5)
xlabel('\gamma_{k2}^{z}');

%plot gammas
subplot(2,4,6)
hold all
[f,xi] = ksdensity(reshape(posterior.gamma(3,2,thinned),[d 1]));
plot(xi,f,'--b','LineWidth',1.5)
[f,xi] = ksdensity(reshape(posterior.gamma(4,2,thinned),[d 1]));
plot(xi,f,'-r','LineWidth',1.5)
xlabel('\gamma_{k2}');

%plot sigmas
subplot(2,4,7)
hold all
[f,xi] =ksdensity(reshape(posterior.omega(1,1,1,thinned),[d 1]));
plot(xi,f,'--b','LineWidth',1.5)
[f,xi] = ksdensity(reshape(posterior.omega(1,1,2,thinned),[d 1]));
plot(xi,f,'-r','LineWidth',1.5)
xlabel('\sigma^{2}_{k}');

%plot covariances
subplot(2,4,8)
hold all
[f,xi] =ksdensity(reshape(posterior.omega(1,2,1,thinned),[d 1]));
plot(xi,f,'--b','LineWidth',1.5)
[f,xi] = ksdensity(reshape(posterior.omega(1,2,2,thinned),[d 1]));
plot(xi,f,'-r','LineWidth',1.5);
xlabel('\sigma_{12,k}');

end
