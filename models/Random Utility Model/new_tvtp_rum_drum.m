%% RUM & DRUM models generate simulations
T = 400;
x1 = randn(T,1);
x2 = randn(T,1);
n_t = sqrt(0.5)*randn(T,1);
z = zeros(T,1);
z(1) = n_t(1);
nstate = 2;
for t = 2 : T
    z(t)  = 0.8*z(t-1) + n_t(t);
end
% gam12^z gam22^z, gam12~, gam22~
gam  = [4 , 1 ,-2 , 2];

Z_m = 0.5;
ind = logical(repmat(eye(nstate),[1,2]));
XX = [(z-Z_m)' ; ones(1,T)];
TVTP_vec = zeros(T,nstate,nstate);
gamALL = [zeros(nstate*2,1) gam.'];
for k = 1:nstate
    H = exp(XX'*gamALL(ind(k,:),:));
    H = H./repmat(sum(H,2),[1,nstate]);
    TVTP_vec(:,:,k) = H;
end

% construct time varying matrices
markov_T = zeros(nstate,nstate,T);
for k = 1 : nstate
    markov_T(k,:,:) = reshape(TVTP_vec(:,:,k).', 1,nstate,T);
end

B1 = [ 0 0.8 ];
B2 = [ 0.2 0.2 ];
var = [0.05 0.1];
state = zeros(T,1);
state(1) = ceil(2*rand);
y(1) = x1(1)*B1(state(1)) + x2(1)*B2(state(1)) + sqrt(var(state(1)))*randn;

for t = 2 : T
    state(t) = con_state_draw(markov_T(:,:,t),state(t-1));
    y(t) = x1(t)*B1(state(t)) + x2(t)*B2(state(t)) + sqrt(var(state(t)))*randn;
end

clearvars -except y state x1 x2 z nstate T

%% estimate simulations
ind =201:T;
Y = y(ind)';
X = [ x1(ind) x2(ind) ];
Z = z(ind) - mean(z(ind));
nstate  = 2;
ndraws = 30000;
burn_in = 10000;
thin =1;
permute_flag = 1;
[posterior_d, prior_d] = sample_MS_TVTP(Y,X,Z,nstate,ndraws,burn_in,thin,permute_flag);

%% get marginal of threshold.
itt = mod(1:(ndraws-burn_in),25)==0;
d= sum(itt);
xi11 = reshape(posterior_d.tvtp(1,1,:,itt),[length(ind),d]);
xi22 = reshape(posterior_d.tvtp(2,2,:,itt),[length(ind),d]);
hold all
ab = abs(xi11-xi22)<0.0001;
c =logical(sum(ab,1));
Zz = z(ind);
plot(Zz,[xi22(:,c) xi11(:,c)],'o','MarkerSize',1)
figure
ksdensity(Zz(sum(ab,2)~=0))

%% PLOT Posterior distribution 
d = (ndraws-burn_in)/thin;
% plot betas 1
subplot(1,4,1)
hold all
[f,xi] = ksdensity(reshape(posterior_d.beta(1,1,:),[d,1]));
plot(xi,f,'--b','LineWidth',1.5)
[f,xi] = ksdensity(reshape(posterior_d.beta(1,2,:),[d,1]));
plot(xi,f,'-r','LineWidth',1.5)
xlabel('\beta_{1,k}');

%plot betas 2
subplot(1,4,2)
hold all
[f,xi] = ksdensity(reshape(posterior_d.beta(2,1,:),[d,1]));
plot(xi,f,'--b','LineWidth',1.5)
[f,xi] = ksdensity(reshape(posterior_d.beta(2,2,:),[d,1]));
plot(xi,f,'-r','LineWidth',1.5)
xlabel('\beta_{2,k}');

%plot gammas
subplot(1,4,3)
hold all
gam12 = posterior_d.gam(3,:);
gam22 = posterior_d.gam(4,:);
[f,xi] = ksdensity(gam12);
plot(xi,f,'--b','LineWidth',1.5)
[f,xi] = ksdensity(gam22);
plot(xi,f,'-r','LineWidth',1.5)
xlabel('\gamma_{k2}');

%plot sigmas
subplot(1,4,4)
hold all 
[f,xi] =ksdensity(posterior_d.sigma(1,:).^2);
plot(xi,f,'--b','LineWidth',1.5)
[f,xi] = ksdensity(posterior_d.sigma(2,:).^2);
plot(xi,f,'-r','LineWidth',1.5)
xlabel('\sigma^{2}_{k}');
legend('Regime 1','Regime 2','Location','NorthEast')

%plot smoothed probabilities
figure
plot([posterior_d.smooth(:,2) state(ind)-1],'LineWidth',1.5)
figure
graph_smooth(state(ind),posterior_d.smooth,1:length(ind))


%% in case of random permutations
[~,inda]=sort(posterior_d.beta(1,:,:));
nobs = 200;
for i = 1 : d
        indi = inda(:,:,i);
        sorted.beta(:,:,i) = posterior_d.beta(:,indi,i);
        sorted.sigma(:,i) = posterior_d.sigma(indi,i);
        indx = [indi(:); indi(:)+nstate];
        sorted.gam(:,i) = posterior_d.gam(indx,i);
        E = accumarray({(1:nobs)' posterior_d.state(:,i)},1);
        E = E(:,indi).*repmat((1:nstate),[nobs,1]);
        sorted.state(:,i) = sum(E,2);
end
for m = 1:nstate
    sorted.smooth(:,m) = mean(sorted.state == m,2);
end
d = (ndraws-burn_in)/thin;
% plot betas 1
subplot(1,4,1)
hold all
[f,xi] = ksdensity(reshape(sorted.beta(1,1,:),[d,1]));
plot(xi,f,'--b','LineWidth',1.5)
[f,xi] = ksdensity(reshape(sorted.beta(1,2,:),[d,1]));
plot(xi,f,'-r','LineWidth',1.5)
xlabel('\beta_{1,k}');

%plot betas 2
subplot(1,4,2)
hold all
[f,xi] = ksdensity(reshape(sorted.beta(2,1,:),[d,1]));
plot(xi,f,'--b','LineWidth',1.5)
[f,xi] = ksdensity(reshape(sorted.beta(2,2,:),[d,1]));
plot(xi,f,'-r','LineWidth',1.5)
xlabel('\beta_{2,k}');

%plot gammas
subplot(1,4,3)
hold all
gam12 = sorted.gam(3,:);
gam22 = sorted.gam(4,:);
[f,xi] = ksdensity(gam12);
plot(xi,f,'--b','LineWidth',1.5)
[f,xi] = ksdensity(gam22);
plot(xi,f,'-r','LineWidth',1.5)
xlabel('\gamma_{k2}');

%plot sigmas
subplot(1,4,4)
hold all 
[f,xi] =ksdensity(sorted.sigma(1,:).^2);
plot(xi,f,'--b','LineWidth',1.5)
[f,xi] = ksdensity(sorted.sigma(2,:).^2);
plot(xi,f,'-r','LineWidth',1.5)
xlabel('\sigma^{2}_{k}');
legend('Regime 1','Regime 2','Location','NorthEast')


%plot smoothed probabilities
figure
graph_smooth(state(ind),sorted.smooth,1:length(ind))