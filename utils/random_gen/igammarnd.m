function g = igammarnd(s, nu,m,n)
% First element is SSE, second element degrees of freedom.
% Written by Bart Diris - page 317 of BLR1999

if nargin < 3; 
    m = 1;
    n = 1;
end

if nargin < 4;
    n = 1;
end

R = chi2rnd(nu,m,n);
g = s./R;

