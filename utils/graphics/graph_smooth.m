function graph_smooth(Y,smooth,dates,doPrint)
% check if dates are passed, otherwise use numeric X-axis
if ~exist('dates', 'var') ||isempty(dates)
    dates = 1:length(Y);
else
    dates = datetime(dates, 'ConvertFrom', 'datenum');
end

red = [1 0 0];
blue = [0 0 1];

% prepare figure for publication
setLatexFig(12, 4); % width, height in inches
set(gcf,'defaultAxesColorOrder',[blue; red]);

% plot title SP500 Total Excess Return
yyaxis left
plot(dates, Y, '-b', 'LineWidth', 1.5);
ylabel('Total Excess Return')
ylim([min(Y), max(Y)]);
ytickformat('%.0f%%');

yyaxis right
plot(dates, smooth(:,1) * 100, ':r', 'LineWidth', 1.5);
ylabel('$$P(S_{t+1} = 1)$$', 'interpreter', 'latex')
ytickformat('%.0f%%');

% take care of ticks
xtickformat('QQQ-yyyy');
xticks(gca, linspace(dates(1), dates(end), 12));
xtickangle(45);

% make axes prettier
apply_prettier(gca);

if doPrint
    print -depsc ../thesis/resources/eps/smoothed_regimes.eps
end

end
