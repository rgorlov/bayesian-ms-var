function state_vector = sample_state_kim(beta,omega,markov,unc_prob,Y,X)
%%codegen
coder.inline('never')
[T,nvar] = size(Y);
[~,nreg] = size(Y);
[nstate,~] = size(markov);
beta = reshape(beta,[nvar,nreg,nstate]);

% Compute likelihood at each point in time for each state
norm_pdf  = zeros(T,nstate);
for s = 1:nstate
    R = chol(omega(:,:,s));
    xRinv = (Y - X*beta(:,:,s)) / R;
    logSqrtDetSigma = sum(log(diag(R)));
    quadform = sum(xRinv.^2, 2);
    norm_pdf(:,s) = exp(-0.5*quadform - logSqrtDetSigma - nvar*log(2*pi)/2);
end
norm_pdf = norm_pdf';

%% hamilton filter
% Initialize hamilton filter
markov_T = markov';
chain = zeros(nstate,T);
forward_use = norm_pdf(:,1).*(markov_T*unc_prob);
chain(:,1) = forward_use / sum(forward_use);
for t = 2 : T
    forward_use = norm_pdf(:,t).*(markov_T*chain(:,t-1));
    chain(:,t) = forward_use / sum(forward_use);
end

%% Kim smoothing algorithm
% Initialize vectors draw
state_draws = zeros(nstate,T);
prob = chain(:,T);

%initialize first draw
RandDraw = rand(T,1);
draw = find(cumsum(prob)>RandDraw(T,1), 1);
state_draws(draw,T) = 1;
filtered = markov_T*chain;
for t = T-1:-1:1
    first = markov*(state_draws(:,t+1)./filtered(:,t));
    prob = first.*chain(:,t);
    draw = find(cumsum(prob)>RandDraw(t,1), 1);
    state_draws(draw,t) = 1;
end

% generate state vector
state_vector = sum(repmat((1:nstate)',[1,T]).*state_draws,1)';


end

