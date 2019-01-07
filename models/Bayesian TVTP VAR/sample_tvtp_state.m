function state_vector = sample_tvtp_state(beta,omega,markov,nstate,Y,X)
%%codegen
% coder.inline('never')
[T,nvar] = size(Y);
[~,nreg] = size(X);
beta = reshape(beta, [ nvar, nreg, nstate ]);

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
unc_prob = ones(nstate,1)./nstate;
inf_prob = zeros(nstate,T);
markov_T = permute(markov,[2 1 3]);
forward_use = norm_pdf(:,1).*(markov_T(:,:,1)*unc_prob);
inf_prob(:,1) = forward_use / sum(forward_use);
for t = 2 : T
    forward_use = norm_pdf(:,t).*(markov_T(:,:,t)*inf_prob(:,t-1));
    inf_prob(:,t) = forward_use / sum(forward_use);
end

%% chib algorithm
% Initialize vectors draw
prob = inf_prob(:,T);
state_vector = zeros(T,1);
%initialize first draw
RandDraw = rand(T,1);
draw = find(cumsum(prob)>RandDraw(T,1), 1);
if isempty(draw)
    p = rand;
    p = [p ; 1-p];
    draw = find(cumsum(p)>RandDraw(T,1), 1);
end
draw = reshape(draw,[1,1]);
state_vector(T,1) = draw;
for t = T-1:-1:1
    s = state_vector(t+1,1);
    backward_use = markov(:,s,t).*inf_prob(:,t);
    prob = backward_use/sum(backward_use);
    draw = find(cumsum(prob) > RandDraw(t,1), 1);
    if isempty(draw)
        p = rand;
        p = [p ; 1-p];
        draw = find(cumsum(p)>RandDraw(T,1), 1);
    end
    draw = reshape(draw,[1,1]);
    state_vector(t,1) = draw;    
end

end

