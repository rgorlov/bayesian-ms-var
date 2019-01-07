function [markov, unc_prob, lrr, post_Markov] = sample_Markov(state_vector,prior,PI,X)

nobs = length(state_vector);
nstate = prior.nstate;
freq = zeros(nstate,nstate);
post_Markov = zeros(nstate,nstate);
markov = zeros(nstate,nstate);
rgm = [ 1 1 0 0 ; 0 0 1 1];
if nstate ~= 4;
    rgm = [1 0; 0 1];
end
%%%%%%%%%%%%%%%% BLOCK 4 : SAMPLE P|M,E,S %%%%%%%%%%%%%%%%%%%%%

for s = 1:nstate
    mask = (state_vector == s);
    %sample transition matrix
    mask_next = [false;mask(1:nobs-1)];
    State_next = state_vector(mask_next);
    for k = 1:nstate
        freq(s,k) = sum(State_next == k);
    end
    
    post_Markov(s,:) = prior.markov(s,:) + freq(s,:);
    % draw Markov transition matrix
    markov(s,:) = drchrnd(post_Markov(s,:),1);
    
end

%unconditional probabilities eq 4.7
A = [markov'-eye(nstate) ; ones(1,nstate)];
e = [zeros(nstate,1);1];
unc_prob = (A'*A)\(A'*e);
for s = 1 : nstate
    var = (mean(X)*PI(:,1,s))';
    mu(s,1) = var;
end
%calculate long-run returns of bull and bear markets eq (4.8&4.9)
lrr = rgm*(unc_prob.*mu)./(rgm*unc_prob);

end
