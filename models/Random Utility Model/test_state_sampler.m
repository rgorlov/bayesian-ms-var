%% test state sampler

beta = [B1 ; B2];
sigma2 = var;
unc_prob = 0.5*ones(nstate,1);
state_vector = compute_state_vector_rum_chib_tvtp(beta,sigma2,markov_T,unc_prob,nstate,Y,X)