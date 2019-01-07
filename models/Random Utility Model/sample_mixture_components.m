function r = sample_mixture_components(S,lambda,rands)

w = [0.00397 0.0396 0.168 0.147 0.125 0.101 0.104 0.116 0.107 0.088]';
m = [5.09 3.29 1.82 1.24 0.764 0.391 0.0431 -0.306 -0.673 -1.06]';
s = [2.1213 1.4213 1.0488 0.6496 0.4450 0.3271 0.2789 0.2768 0.3077 0.3821]';

inner = (S-lambda -m)./s;
prob = (w./s).*exp(-0.5*(inner.*inner));

prob = prob./sum(prob);
cprob = cumsum(prob);
r = find(cprob > rands,1);

if ~isempty(r)
    return
end

r = find(cumsum(w) > rands,1);

end