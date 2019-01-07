function R = sample_rum_errors(S,fit)
T = length(fit);
R = zeros(1,T);
rands = rand(1,T);
for t = 1 : T
    r = sample_mixture_components(S(1,t),fit(1,t),rands(1,t));
    R(1,t) = r(1);
end
end
