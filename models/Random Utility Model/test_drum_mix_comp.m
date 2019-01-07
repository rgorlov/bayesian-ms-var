

fit = 0.5*ones(1,100);
est = fit + randn(1,100);

R = sample_rum_errors(est,fit);