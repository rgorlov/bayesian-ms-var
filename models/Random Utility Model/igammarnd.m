function g = igammarnd(s, nu)
% First element is SSE, second element degrees of freedom.
% Written by Bart Diris - page 317 of BLR1999
R = chi2rnd(nu);
g = s/R;

