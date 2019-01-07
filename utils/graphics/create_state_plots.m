function create_state_plots(posterior, posterior_, datetimes)

setLatexFig(12, 4); % width, height in inches

plot(datetimes, posterior.smooth(:,1)*100, '-.r',...
    datetimes, posterior_.smooth(:,1)*100, ':b','LineWidth',1.5);

ytickformat('%.0f%%');
ylabel('$$P(S_{t+1} = 1)$$');
legend({'time-varying', 'constant'})
xtickformat('QQQ-yyyy');
xticks(linspace(datetimes(1), datetimes(end),12)); 
xtickangle(45);

apply_prettier(gca);
print -depsc ../thesis/resources/eps/both-state-probabilities.eps
end