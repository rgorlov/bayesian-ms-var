function var_k = plot_conditional_variance(sim_y)
[N,T] = size(sim_y);
var_k = var(cumsum(sim_y,2))./(1:T);
figure
plot(var_k,'LineWidth',2)
text(min((1:10:length(var_k))'+.25,length(var_k)-0.05),var_k(1:10:end)', cellstr(num2str(var_k(1:10:end)','%.4f'))','FontWeight', 'bold');
ylabel('$\frac{1}{K}Var_{t}(r_{t->t+K})$','interpreter','latex','Fontsize', 16)
xlabel('Horizon K','FontWeight', 'bold')
title('Conditional Variance','FontWeight', 'bold');
end