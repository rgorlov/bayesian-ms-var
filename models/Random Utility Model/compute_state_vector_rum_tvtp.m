function state_vector = compute_state_vector_rum_tvtp(beta,sigma2,markov,unc_prob,nstate,Y,X)
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

%% hamilton filter
% Initialize hamilton filter
I = ones(nstate,1);
chain = zeros(nstate,nobs);
F = markov;
num = norm_pdf(:,1).*(F(:,:,1)*unc_prob);
chain(:,1) = num / (I'*num);
for t = 2 : nobs
    num = norm_pdf(:,t).*(F(:,:,t)*chain(:,t-1));
    chain(:,t) = num / sum(num);
end

%% Kim smoothing algorithm
% Initialize vectors draw
state_draws = zeros(nstate,nobs);
prob = chain(:,nobs);

%initialize first draw
RandDraw = rand(nobs,1);
draw = find(cumsum(prob)>RandDraw(nobs,1), 1);
state_draws(draw,nobs) = 1;
F_t = permute(F,[2 1 3]);
for t = nobs-1:-1:1
    F_filter = F(:,:,t)*chain(:,t);
    first = F_t(:,:,t)*(state_draws(:,t+1)./F_filter);
    prob = first.*chain(:,t);
    draw = find(cumsum(prob)>RandDraw(t,1), 1);
    state_draws(draw,t) = 1;
end

% generate state vector
state_vector = sum(repmat((1:nstate)',[1,nobs]).*state_draws,1)';


end

