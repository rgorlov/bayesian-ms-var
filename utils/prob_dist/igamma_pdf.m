function log_density=igamma_pdf(X,a,b)
log_density=a.*log(b)-gammaln(a)-(a+1).*log(X)-(b./X);
end