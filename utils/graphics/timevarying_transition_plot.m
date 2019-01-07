function out = timevarying_transition_plot(posterior, posterior_, dates, doPrint)

if isfield(posterior, 'tvtp')
    [M, N, T, draws] = size(posterior.tvtp);
else
    return
end

if M ~= N
    return;
end
dates = datetime(dates, 'ConvertFrom', 'datenum');
Nsubs = M*N;

mkv = posterior_.markov_mean;
setLatexFig(12, 8); % width, height in inches

p = 1;
out = [];
for m = 1 : M
    for n = 1 : N
        pl = subplot(M,N,p);
        
        data = mean(reshape(posterior.tvtp(m,n,:,:), [ T draws ]),2) * 100;
        out = [ out , data ];
        mkvdata = mkv(m,n) * ones(size(data)) * 100;
        plot(dates, data, '-b', dates, mkvdata, ':r', 'LineWidth', 1.5);
        ytickformat('%.0f%%'); legend({'time-varying', 'constant'}, 'Box', 'Off')
        xtickformat('QQQ-yyyy');
        xticks(pl, linspace(dates(1), dates(end),12));
%         xlim([dates(1),dates(end)]); ylim([1;0]);
        xtickangle(45);
        p = p + 1;
        
        if n*m ==1
            ylabel('$$S_{t} = 1$$')
        elseif m == 2 && n == 1
            ylabel('$$S_{t} = 2$$')
            xlabel('$$S_{t+1} = 1$$')
        elseif n*m == 4
            xlabel('$$S_{t+1} = 2$$')
        end
        apply_prettier(gca);
    end
end
if doPrint
    print -depsc ../thesis/resources/eps/both-transition-probabilities.eps
end
end


