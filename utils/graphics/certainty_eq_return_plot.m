function certainty_eq_return_plot(cer_tvtp, cer_var, doPrint)
setLatexFig(12, 8); % width, height in inches
gammas = [ 2 5 10 20 ];
for g = 1 : length(gammas)
    subplot(2,2, g)
    plot(1: 120, cer_tvtp(g, :) * 100, '-r', 1:120, cer_var(g, :) * 100, '--b', 'LineWidth', 1.5);
    xlabel('Horizon in months');
    ylabel('CER');
    ytickformat('%.1f%%');
    title(sprintf('$\\gamma = %d$', gammas(g)));
    legend({'time-varying', 'constant'}, 'Box', 'Off', 'Location', 'Best');
    apply_prettier(gca);
end
if doPrint
    print -depsc ../thesis/resources/eps/both-cer;
end
end
