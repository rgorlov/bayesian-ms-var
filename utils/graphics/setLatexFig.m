function setLatexFig(width, height)

% Width in inches, Height in inches
figure('Units', 'inches',...
    'Position', [0, 0, width, height],...
    'PaperPositionMode','auto');

% set global current figure handle properties
set(gcf,'InvertHardcopy', 'on');
set(gcf,'PaperUnits', 'inches');

% set papersize
papersize = get(gcf, 'PaperSize');
left   = (papersize(1) - width)/2;
bottom = (papersize(2) - height)/2;

%  reset paperposition using papersize
set(gcf,'PaperPosition', [left, bottom, width, height]);

end
