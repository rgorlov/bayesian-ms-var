
J = 2;
K = 2;
T  = 120;
nstate = 2;
s_T = randn;
ssr = randn(T,J);
omega = ssr'* ssr;
omega = repmat(omega,[1,1,nstate]);
X = [ones(T,1) randn(T,1)];
Y = randn(T, J);
state_last = ceil(nstate*rand);
markov = rand(nstate,nstate);
markov = markov./repmat(sum(markov,2),[1 nstate]);
beta = repmat( randn(J*K,nstate),[1,1]);
gamma = [ 0, 0, 0, 0 ; 4 , 1 ,-2 , 2]';

for i = 1:10000
    [sim_r, sim_x, state] = sim_var_tvpt_mex(beta,gamma,omega,markov,state_last,T,Y);
end

