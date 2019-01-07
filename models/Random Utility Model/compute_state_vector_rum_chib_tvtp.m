function state_vector = compute_state_vector_rum_chib_tvtp(beta,sigma2,markov,unc_prob,nstate,Y,X)
%%codegen
% coder.inline('never')

[nobs,~] = size(X);
% Compute likelihood at each point in time for each state
normlike_pdf = zeros(nobs,nstate);
exp_constant = -0.5./sigma2;
constant = sqrt(2*pi*sigma2);
eps = repmat(Y,[1,nstate])-X*beta;
for s = 1:nstate
    normlike_pdf(:,s) = exp(exp_constant(s).*(eps(:,s).^2))/constant(s);
end
norm_pdf = normlike_pdf';

%% forward pass hamilton filter 1989 eq(5.4)
inf_prob = zeros(nstate,nobs);
markov_t = permute(markov,[2 1 3]);
forward_use = (markov_t(:,:,1)*unc_prob).*norm_pdf(:,1);
inf_prob(:,1) = forward_use/sum(forward_use);
for t = 2:nobs;
    forward_use = (markov_t(:,:,t)*inf_prob(:,t-1)).*norm_pdf(:,t);
    inf_prob(:,t) = forward_use/sum(forward_use);
end

%% Backward pass

% Initialize state draw
prob = inf_prob(:,nobs);
state_vector = zeros(1,nobs);
RandDraw = rand(1,nobs);
draw = find(cumsum(prob)>RandDraw(1,nobs), 1);
state_vector(1,nobs) = mean(draw);

% backward pass smoother eq (5.5)
for t = nobs-1:-1:1
    s = state_vector(1,t+1);
    backward_use = markov(:,s,t).*inf_prob(:,t);
    prob = backward_use/sum(backward_use);
    draw = find(cumsum(prob) > RandDraw(1,t), 1);
    state_vector(1,t) = mean(draw);
end

end

