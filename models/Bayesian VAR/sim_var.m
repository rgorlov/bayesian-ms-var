function [sim_r, sim_x, state] = sim_var(s_T,beta,omega,markov,state_last,T)

% initialize params
state = zeros(1,T);
state(1) = state_last;
nvar = size(omega,2);
nstate = size(markov,2);
rdraw = randn(nvar,T);
sdraw = rand(1,T);
nreg = length(beta)/nvar;
beta = reshape(beta,[nvar,nreg, nstate]);
% initialize starting values;
cholmega = zeros(nvar,nvar,nstate);
for s = 1 : nstate
    cholmega(:,:,s) = chol(omega(:,:,s));
end

VAR = [1 s_T]*beta(:,:,state(1)) + rdraw(:,1)' * cholmega(:,:,state(1));
sim_r  = zeros(1,T);
sim_r(:,1) = VAR(:,1);

sim_x = zeros(nreg-1,T);
sim_x(:,1) = VAR(:,2:end);

% simulate new periods while drawing net states
for t = 2:T
    prob = markov(state(t-1),:);
    c_prob = cumsum(prob);
    state(t) = find(c_prob>sdraw(1,t),1);
    VAR = [1 sim_x(:,t-1)']*beta(:,:,state(t)) + rdraw(:,t)' * cholmega(:,:,state(t));
    sim_r(:,t) = VAR(:,1);
    sim_x(:,t) = VAR(:,2:end);
end

end