function [sim_r, sim_x, state] = sim_var_tvpt(beta,gamma,omega,old_markov,state_last,T,Y,regime_var)
%#codegen
% initialize params
nstate = size(omega,3);
nvar = size(omega,2);
rdraw = randn(nvar,T);
sdraw = rand(1,T);
nreg = length(beta)/nvar;
beta = reshape(beta,[nvar,nreg, nstate]);
prob = old_markov(state_last,:);
c_prob = cumsum(prob);
state = zeros(1,T);
state(1) = find(c_prob > sdraw(1,1),1);
ind = logical(repmat(eye(nstate),[1,2]));
s_T = Y(end,2:end);
nobs = length(Y);
threshold = mean(Y(:,regime_var+1),1);
% initialize starting values;
cholmega = zeros(nvar,nvar,nstate);
for s = 1 : nstate
    cholmega(:,:,s) =  chol(omega(:,:,s));
end
VAR = [1 s_T]*beta(:,:,state(1)) + rdraw(:,1)' * cholmega(:,:,state(1));
sim_r  = zeros(1,T);
sim_r(:,1) = VAR(:,1);

sim_x = zeros(nreg-1,T);
sim_x(:,1) = VAR(:,2:end);
markov = zeros(nstate,nstate);
sim_nobs = nobs + 1;
threshold = (nobs * threshold + sim_x(regime_var,1)) ./ ( sim_nobs );
XX = [sim_x(regime_var,1)' - threshold 1];
for k = 1:nstate
    H = exp(XX*gamma(ind(k,:),:));
    H = H./repmat(sum(H,2),[1,nstate]);
    markov(k,:) = H;
end

% simulate new periods while drawing net states

% try
for t = 2:T

    prob = markov(state(t-1),:);
    c_prob = cumsum(prob);
    state(t) = find(c_prob>sdraw(1,t),1);
    VAR = [1 sim_x(:,t-1)']*beta(:,:,state(t)) + rdraw(:,t)' * cholmega(:,:,state(t));
    sim_r(:,t) = VAR(:,1);
    sim_x(:,t) = VAR(:,2:end);
    threshold = (sim_nobs * threshold + sim_x(regime_var,t)) ./ ( sim_nobs + 1 );
    sim_nobs = sim_nobs + 1;
    XX = [transpose(sim_x(regime_var,t)) - threshold  1];
    for k = 1:nstate
        H = exp(XX*gamma(ind(k,:),:));
        H(~isfinite(H)) = 0;
        H = H./repmat(sum(H,2),[1,nstate]);
        markov(k,:) = H;
    end
    
end
% catch error
%     stop = true;
% end
    
end