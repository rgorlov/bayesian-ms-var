function conditional_variance_plot(posterior, posterior_, doPrint)
setLatexFig(12, 8); % width, height in inches

[N,T] = size(posterior.sim_r);
var_r = var(cumsum(posterior.sim_r,2))./(1:T);
var_r_ = var(cumsum(posterior_.sim_r,2))./(1:T);
subplot(2, 1, 1)
plot(1: 120, var_r, '-r', 1:120, var_r_, '--b', 'LineWidth', 1.5);
ylabel('$$Var_{t}(r_{t->t+K})$$')
ytickformat('%.0f%%');
xlabel('Horizon in Months')
title('Conditional Variance of Excess Stock Returns');
legend({'time-varying', 'constant'}, 'Box', 'Off')
apply_prettier(gca);


bond_r = reshape(posterior.sim_x(1,:,:),[120,20000])';
bond_r_ = reshape(posterior_.sim_x(1,:,:),[120,20000])';
var_b = var(cumsum(bond_r,2))./(1:T);
var_b_ = var(cumsum(bond_r_,2))./(1:T);
subplot(2, 1, 2)
plot(1: 120, var_b, '-r', 1:120, var_b_, '--b', 'LineWidth', 1.5);
ylabel('$$Var_{t}(corp_{t->t+K})$$')
ytickformat('%.0f%%');
xlabel('Horizon in Months')
title('Conditional Variance of Excess Bond Returns');
legend({'time-varying', 'constant'}, 'Box', 'Off')
apply_prettier(gca);
if doPrint
    print -depsc ../thesis/resources/eps/both-cond-variance.eps
end
end