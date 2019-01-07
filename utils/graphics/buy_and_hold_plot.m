function buy_and_hold_plot(w, w_, doPrint)
ylabels = {'stocks', 'bonds', 'risk-free rate'};
[assets, sims, gammas] = size(w);
gindex = [1, 2, 3, 4];
gamma = [ 2 5 10 20 ];
setLatexFig(12, 8); % width, height in inches
plot_count = 1;
for a = 1 : assets
  for i = 1 : gammas
    subplot(assets, gammas, plot_count)
    plot(1:sims, 100 * w(a, :, gindex(i)), '-r', 1:sims, 100 * w_(a, :, gindex(i)), '--b', 'LineWidth', 1.5);
    ytickformat('%.0f%%');
    xlim([1, 120])
    legend({'time-varying', 'constant'}, 'Box', 'Off')
    
    if a == 1 
        title(sprintf('$\\gamma = %d$', gamma(gindex(i))));
    end
    if i == 1
        ylabel(sprintf('%s', ylabels{a}));
    end
    if a == assets
        xlabel('Horizon in months')
    end
    
    apply_prettier(gca);
    plot_count = plot_count + 1;
  end
end
if doPrint
    print -depsc ../thesis/resources/eps/buy-and-hold-portfolios;
end
end
