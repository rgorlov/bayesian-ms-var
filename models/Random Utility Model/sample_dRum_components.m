function r = sample_dRum_components(W,lambda,rands)

w = [0.0184  ;  0.1727  ;  0.3739  ;  0.3170  ;  0.1089  ;  0.0091];
s = [0.8256  ;  1.1144  ;  1.4963  ;  2.0180  ;  2.7271  ;  3.7111];

inner = (W-lambda)./s;
prob = (w./s).*exp(-0.5.*(inner.*inner));

prob = prob./sum(prob);
cprob = cumsum(prob);
r = find(cprob > rands,1);

if ~isempty(r)
    return
end

r = find(cumsum(w) > rands,1);

end

