function timer_bar(r,ndraws,msg)

staticText = '    % finished';
lbracket = '[';
rbracket = ']';
bar = '\';
null = '.';
emptybar = repmat(null,[1,100]);
loadingbar = [lbracket, emptybar, rbracket, staticText];
pos = 106;

%each 1% point increase in loop print a [\\..] ascii loading bar;
if rem(100*r,ndraws) == 0
    pct = floor(100*r/ndraws);
    loadingbar(2:pct+1) = bar;
    if pct >= 100
        pos = 104:106;
    elseif pct >= 10
        pos = 105:106;
    end
    loadingbar(pos) = num2str(pct);
    clc
    disp(msg)
    disp(loadingbar);
end

end
