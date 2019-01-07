%% PLOT Posterior distribution
function plots = plot_distributions(posterior,ndraws,burn_in)
responseVars = posterior.responseVars;
predictorVars = posterior.predictorVars;
plots = struct();
d = ndraws-burn_in;
thinned = mod(1:d,1)==0;
d = sum(thinned);

%% Coefficients figure
[nvars, nregs, nstates] = size(posterior.beta_median);
setLatexFig(12, 8);
plots.coefs = gcf;
YX = nvars*nregs;
scolor = {'--b', '-r'};
for r = 1 : YX
    sp = subplot(nvars,nregs,r);
    hold all
    for s = 1 : nstates
        [f,xi] = ksdensity(reshape(posterior.beta(r,s,thinned),[d,1]));
        plot(xi,f,scolor{s},'LineWidth',1.5);
    end
    vars = ceil((1:YX)/nvars);
    regs = repmat(1:nregs, [ 1, nvars]);
    
%     title(sprintf('$%s_{t+1}$', responseVars{vars(r)}));
    if mod(r-1, 4) == 0
        ylabel(sprintf('$%s_{t+1}$', responseVars{vars(r)}));
    end
    if r <= 4
        title(sprintf('$%s_{t}$', predictorVars{regs(r)}));
    end
    if r == YX
        legend({'Regime 1','Regime 2'},'Location', 'Best', 'Box', 'off');
    end
    apply_prettier(gca);
end
printName = posterior.model;
print(sprintf('../thesis/resources/eps/%s-posterior-coefs.eps', printName), '-depsc ');
%% Covariance matrix figure
[nvars, ~, nstates] = size(posterior.beta_median);
setLatexFig(12, 8);
plots.covs = gcf;
parmatrix = zeros(nvars); parmatrix(:) = 1 : nvars*nvars; k = 0;
pars = tril(parmatrix'); pars = pars(:); pars(pars==0)=[]; pars = sort(pars);
for r = 1 : nvars
    for c = 1 : r
        k = k + 1;
        sp = subplot(nvars, nvars, pars(k));
        hold all
        for s = 1 : nstates
            [f,xi] = ksdensity(reshape(posterior.omega(r,c,s,thinned),[d 1]));
            plot(xi*12,f,scolor{s},'LineWidth',1.5);
        end
        if mod(pars(k)-1, 4) == 0
            ylabel(sprintf('$%s_{t+1}$', responseVars{r}));
        end
        if pars(k) > 12
            xlabel(sprintf('$%s_{t+1}$', responseVars{c}));
        end       
%         xlabel(sprintf('$%s_{t+1}, %s_{t+1}$', responseVars{r}, responseVars{c}));
        if r == nvars && c == r
            legend({'Regime 1','Regime 2'},'Location', 'Best', 'Box', 'off')
        end
        apply_prettier(gca);
    end
end
print(sprintf('../thesis/resources/eps/%s-posterior-cov.eps', printName), '-depsc ');
%% Additional figures
cols = 3;
if isfield(posterior, 'gamma')
    cols = 5;
end
%plot unconditional return
setLatexFig(12, 5);
plots.regime = gcf;
subplot(2,cols,1)
hold all
[f,xi] = ksdensity(reshape(posterior.unc_mean(1,1,thinned),[d 1]));
plot(xi,f,'--b','LineWidth',1.5);
[f,xi] = ksdensity(reshape(posterior.unc_mean(2,1,thinned),[d 1]));
plot(xi,f,'-r','LineWidth',1.5);
xlabel('$$E(r_{t+1}|s_{t+1})$$', 'interpreter', 'latex')
apply_prettier(gca);
%plot cumulative return per regime
subplot(2,cols,2)
hold all
[f,xi] = ksdensity(posterior.e_cumrets(1,thinned));
plot(xi,f,'--b','LineWidth',1.5);
[f,xi] = ksdensity(posterior.e_cumrets(2,thinned));
plot(xi,f,'-r','LineWidth',1.5);
xlabel('$$E(\sum r_{t+1}|s_{t+1})$$', 'interpreter', 'latex')
apply_prettier(gca);
%plot duration per regime
subplot(2,cols,3)
hold all
[f,xi] = ksdensity(posterior.regime_d(1,thinned));
plot(xi,f,'--b','LineWidth',1.5);
[f,xi] = ksdensity(posterior.regime_d(2,thinned));
plot(xi,f,'-r','LineWidth',1.5);
xlabel('$$E(D|s_{t+1})$$', 'interpreter', 'latex')
legend({'Regime 1','Regime 2'},'Location', 'Best', 'Box', 'off')
apply_prettier(gca);
if isfield(posterior, 'gamma')
    %plot gammas
    subplot(2,cols,4)
    hold all
    [f,xi] = ksdensity(reshape(posterior.gamma(1,2,thinned),[d 1]));
    plot(xi,f,'--b','LineWidth',1.5)
    [f,xi] = ksdensity(reshape(posterior.gamma(2,2,thinned),[d 1]));
    plot(xi,f,'-r','LineWidth',1.5)
    xlabel('$$\gamma_{k2}^{z}$$', 'interpreter', 'latex');
    apply_prettier(gca);
    %plot gammas
    subplot(2,cols,5)
    hold all
    [f,xi] = ksdensity(reshape(posterior.gamma(3,2,thinned),[d 1]));
    plot(xi,f,'--b','LineWidth',1.5)
    [f,xi] = ksdensity(reshape(posterior.gamma(4,2,thinned),[d 1]));
    plot(xi,f,'-r','LineWidth',1.5)
    xlabel('$$\gamma_{k2}$$', 'interpreter', 'latex');
    apply_prettier(gca);
    %plot unconditional bond returns
    subplot(2,cols,6)
    hold all
    [f,xi] = ksdensity(reshape(posterior.unc_mean(1,2,thinned),[d 1]));
    plot(xi,f,'--b','LineWidth',1.5);
    [f,xi] = ksdensity(reshape(posterior.unc_mean(2,2,thinned),[d 1]));
    plot(xi,f,'--r','LineWidth',1.5);
    xlabel('$$E(corp_{t+1}|s_{t+1})$$', 'interpreter', 'latex')
    apply_prettier(gca);
    %plot cumulative bond return per regime
    subplot(2,cols,7)
    hold all
    [f,xi] = ksdensity(posterior.e_cumbonds(1,thinned));
    plot(xi,f,'--b','LineWidth',1.5);
    [f,xi] = ksdensity(posterior.e_cumbonds(2,thinned));
    plot(xi,f,'-r','LineWidth',1.5);
    xlabel('$$E(\sum corp_{t+1}|s_{t+1})$$', 'interpreter', 'latex')
    apply_prettier(gca);
else
    %plot unconditional bond returns
    subplot(2,cols,4)
    hold all
    [f,xi] = ksdensity(reshape(posterior.unc_mean(1,2,thinned),[d 1]));
    plot(xi,f,'--b','LineWidth',1.5);
    [f,xi] = ksdensity(reshape(posterior.unc_mean(2,2,thinned),[d 1]));
    plot(xi,f,'-r','LineWidth',1.5);
    xlabel('$$E(corp_{t+1}|s_{t+1})$$', 'interpreter', 'latex')
    apply_prettier(gca);
    %plot cumulative bond return per regime
    subplot(2,cols,5)
    hold all
    [f,xi] = ksdensity(posterior.e_cumbonds(1,thinned));
    plot(xi,f,'--b','LineWidth',1.5);
    [f,xi] = ksdensity(posterior.e_cumbonds(2,thinned));
    plot(xi,f,'-r','LineWidth',1.5);
    xlabel('$$E(\sum corp_{t+1}|s_{t+1})$$', 'interpreter', 'latex')
    apply_prettier(gca);
end
print(sprintf('../thesis/resources/eps/%s-posterior-regime.eps', printName), '-depsc ');
end
