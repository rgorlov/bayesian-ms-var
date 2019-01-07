function y = mv_gammaf(p,v)


pi_pow = 0.25.*p.*(p-1);
pi_cons = pi_pow*log(pi);

yprod = 0;
for j = 1 : p 
    b = 0.5 *( 1 - j ) + v;
    yprod = yprod + gammaln(b);
end

y = pi_cons + yprod;

end