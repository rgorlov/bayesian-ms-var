% gamma = 4;
% p = 120;
% w = zeros(1,p);
% tic
% for n = 1 : p
%     w(1,n) = dynamicPort(posterior.sim_r(:,1:n),posterior.sim_x(:,1:n),posterior.sim_state(:,1:n),gamma);
%     disp(['Done ' num2str(n) ' period.'])
% end
% toc
% %%
% gamma = 4;
% p = 120;
% tic
% w2 = zeros(1,p);
% for n = 1 : p
%     w2(1,n) = dynamicPort2(posterior.sim_r(:,1:n),posterior.sim_x(:,1:n),gamma);
%     disp(['Done ' num2str(n) ' period.'])
% end
% toc
% %%
% gamma = 10;
% bond_r = reshape(posterior_.sim_x(1,:,:),[120,20000])';
% w_T = dynamicPortT(posterior_.sim_r(:,1:40)/100,bond_r(:,1:40)/100, posterior_.sim_x(:,1:40,:), posterior_.sim_state(:,1:40), gamma);
% 
% plot(1:40,w_T);legend('stocks','bonds', 'rfree');
% %%
% gamma = 4;
% w_TT = dynamicPort_mex(posterior.sim_r(1:100,:),posterior.sim_x(1:100,:), gamma);
%%
bond_r = reshape(posterior_. sim_x(1,:,:),[120,20000])'./100;
stock_r = posterior_.sim_r(:,:)./100;
gammas = [ 2 5 10 20 ];
h = 12;
w = zeros(3, h, 4);
cer = zeros(4, h);
for g = 1 : 1
    [w(:,:, g), cer(g,:)] = strategicPort_three_assets(stock_r(:,1:h), bond_r(:,1:h), posterior_.sim_x(:,1:h,:), gammas(g));
end