% test tvtp multivariate state sampler
clear,clc
J = 3;
K = 3;
T  = 1000;
nstate = 4;
omega = repmat(eye(J),[1,1,nstate]);
X = [ones(T,1) randn(T,1) randn(T,1)];
Y = randn(T, J);
markov = rand(nstate,nstate,T);
beta = repmat( randn(J*K,nstate),[1,1]);
tic
for i = 1 : 100
    state_vector = sample_tvtp_state(beta,omega,markov,nstate,Y,X);
end
toc
tic
for i = 1 : 100
    state_vector = sample_tvtp_state_mex(beta,omega,markov,nstate,Y,X);
end
toc