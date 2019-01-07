function pdf = iwishart_pdf(Y, v, R)

[y1,y2] = size(Y);
[r1,r2] = size(R);

if y1 ~= y2
    error('Input matrix Y is not symmetric.');
end
if r1 ~= r2
    error('Input matrix R is not symmetric.');
end
if y1 ~= r1
    error('Input matrix R & Y have different dimensions.');
end
if v <= (y1-1)
    error('not enough degrees of freedom, need size(Y) > v.');
end

inner = trace(Y\R);
num = 0.5.*v*log(det(R));
den = 0.5.*(v + y1 + 1)*log(det(Y));
a = 0.5.*v.*y1*log(2);
c = mv_gammaf(y1,v/2);
constant = num - (a + c + den);
log_pdf = constant - 0.5 * inner ;
pdf = exp(log_pdf);
end