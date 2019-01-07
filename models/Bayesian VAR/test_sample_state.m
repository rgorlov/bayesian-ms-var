% test tvtp multivariate state sampler
clear,clc
J = 2;
K = 2;
T  = 1000;
nstate = 4;
omega = repmat(eye(J),[1,1,nstate]);
X = [ones(T,1) randn(T,1)];
Y = randn(T, J);
markov = rand(nstate,nstate);
beta = repmat( randn(J*K,1),[1,nstate]);
unc_prob = ones(nstate,1)./nstate;
for i = 1 : 100
%       state_vector = sample_state_chib(beta,omega,markov,unc_prob,Y,X);
      state_vector = sample_state_kim(beta,omega,markov,unc_prob,Y,X);
end

