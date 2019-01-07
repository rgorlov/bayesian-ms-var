%% get marginal of threshold.
function plot_regime_effect(posterior,ndraws,burn_in,Y,Z,doPrint)
setLatexFig(12, 6); % width, height in inches
itt  = mod(1:(ndraws-burn_in),25)==0;
d    = sum(itt);
xi11 = reshape(posterior.tvtp(1,1,:,itt),[length(Y),d]);
xi22 = reshape(posterior.tvtp(2,2,:,itt),[length(Y),d]);
plot(Z, mean(xi11,2), 'or', Z, mean(xi22,2),'ob', 'MarkerSize',1.5)
% hold
% scatter((Z),mean(xi11,2));
% scatter((Z),mean(xi22,2));
legend({'$s = 1$','$s = 2$'},'Box', 'off')
ylabel('$P(S_{t} = s | S_{t-1} = s)$');
xlabel('$ln(sv_{t+1})$');
apply_prettier(gca)
if doPrint
    print -depsc ../thesis/resources/eps/msvar-tvtp-regime-effect
end
end