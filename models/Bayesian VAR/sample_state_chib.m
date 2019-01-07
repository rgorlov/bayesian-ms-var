function state_vector = sample_state_chib(beta,omega,markov,unc_prob,Y,X)
%%codegen
% coder.inline('never')
[T,nvar] = size(Y);
[~,nreg] = size(Y);
[nstate,~] = size(markov);
beta = reshape(beta,[nvar,nreg,nstate]);

%% Compute likelihood at each point in time for each state
norm_pdf  = zeros(T,nstate);
for s = 1:nstate
    R = chol(omega(:,:,s));
    xRinv = (Y - X*beta(:,:,s)) / R;
    logSqrtDetSigma = sum(log(diag(R)));
    quadform = sum(xRinv.^2, 2);
    norm_pdf(:,s) = exp(-0.5*quadform - logSqrtDetSigma - nvar*log(2*pi)/2);
end
norm_pdf = norm_pdf';

%% forward pass hamilton filter 1989 eq(5.4)
markov_T = markov';
inf_prob = zeros(nstate,T);
forward_use = (markov_T*unc_prob).*norm_pdf(:,1);
inf_prob(:,1) = forward_use / sum( forward_use );
for t = 2:T;
    forward_use = (markov_T*inf_prob(:,t-1)).*norm_pdf(:,t);
    inf_prob(:,t) = forward_use/sum(forward_use);
end

%% Initialize state draw
prob = inf_prob(:,T);
state_vector = zeros(T,1);
RandDraw = rand(T,1);
draw = find(cumsum(prob)>RandDraw(T,1), 1);
draw = reshape(draw,[1,1]);
state_vector(T,1) = draw;

% backward pass smoother eq (5.5)
for t = T-1:-1:1
    s = state_vector(t+1,1);
    backward_use = markov(:,s).*inf_prob(:,t);
    prob = backward_use/sum(backward_use);
    draw = find(cumsum(prob) > RandDraw(t,1), 1);
    draw = reshape(draw,[1,1]);
    state_vector(t,1) = draw;
end

end