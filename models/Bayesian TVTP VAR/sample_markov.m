%%%%%%%%%%%%%%%% BLOCK 4 : SAMPLE P|M,E,S %%%%%%%%%%%%%%%%%%%%%
function [markov, initial, post_markov] = sample_markov(state,prior)
nstate = prior.nstate;
freq = zeros(nstate,nstate);
post_markov = zeros(nstate,nstate);
markov = zeros(nstate,nstate);
nobs = length(state);

for s = 1:nstate
    mask = (state == s);
    %sample transition matrix
    mask_next = [false;mask(1:nobs-1)];
    State_next = state(mask_next);
    for k = 1:nstate
        freq(s,k) = sum(State_next == k);
    end
    
    post_markov(s,:) = prior.markov(s,:) + freq(s,:);
    % draw Markov transition matrix
    markov(s,:) = drchrnd(post_markov(s,:),1);
    
end

A = [markov'-eye(nstate) ; ones(1,nstate)];
e = [zeros(nstate,1);1];
initial = (A'*A)\(A'*e);
end
