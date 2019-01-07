function sample = con_state_draw(markov,current_state)
%% this function draws a state conditional on the current state and its markov chain.
% It requires a symmetric markov matrix with the individual rows summing
% to 1. The second parameter for input is an integer that must be within the bounds of the markov chain. 
% such that 1 <= current_state <= size(markov)
% USAGE :
% markov = [0.33 0.66 ; 0.15 0.85 ]
% current_state = 2;
% 2 = con_state_draw(markov, current_state);
% the function uses the common alias method to draw an integer based on its
% discrete probability distribution

[nstate,nstate2] = size(markov);

if ( nstate ~= nstate2 )
    error('markov matrix is not symmetric');
end

if ( current_state < 1 || current_state > nstate );
    error('current state parameter is invalid');
end
states = cumsum(ones(nstate,1));
prob = markov(current_state,:);
cum_prob = cumsum(prob);
index = find(cum_prob>rand,1);
sample = states(index); 
end
