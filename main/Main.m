%%%% --------------------------- MAIN WRAPPER -------------------------- %%

getData;

db;

%% ----------------------------- MODEL SETUP --------------------------- %%
responseVars = {    'r', 'corp', 'dp', 'sv'};
predictorVars ={    'const', 'corp', 'dp', 'sv'};
Y  = db{2:end, responseVars};      % Y = Observed data ( T x K )
X  = db{1:end-1, predictorVars};   % X = regressors (T x K )
Z  = db{2:end, {'sv'}};            % Z = regressor (T x 1)
%   0 = no permutation
%   1 = permute by predictor sensitivity to excess stock return
%   2 = permute by the unconditional mean of excess stock return
%   3 = permute by the variance of the covariance matrix
%   4 = permute by the covariance between the predictor and excess stock return
nstate       = 2;       % nstate = Number of latent states
ndraws       = 30000;   % ndraws = Number of draws in MCMC
burn_in      = 10000;   % burn_in = Number of burn-in draws in MCMC
thin         = 10;      % thin = grab each thinned simulated parameter
permute.flag = 3;       % permute_flag: permute current draws in desired order
permute.var  = 1;
permute.var2 = 4;
permute.reg  = 3;       % # variable after const, so 3rd here, total 4th used for forecasting
model        = false;   % false : run constant probabiliaties, true : run time varying probabilities
Z_th         = mean(Z,1);
%% ----------------------------- MODEL CALLS --------------------------- %%
%  --------------------- time varying transition probabilities  --------  %
if ~model
    rng('default');
    [posterior, prior, marginal] = HMM_VAR_TVTP(Y,X,Z-Z_th,nstate,ndraws,burn_in,permute, responseVars, predictorVars);

    % ------------- VECTOR AUTO REGRESSIVE HIDDEN MARKOV MODEL -------------  %
    rng('default');
    [posterior_, prior_, marginal_] = HMM_VAR(Y,X,nstate,ndraws,burn_in,permute, responseVars, predictorVars);
end
%% ------------------------------- RESULTS ----------------------------- %%
%% plot & print smoothed states
graph_smooth(cumsum(Y(:,1)),posterior_.smooth,datenum(db.dates(2:end)), false)
%% plot & print model coefs
plots = plot_distributions(posterior_,ndraws,burn_in);
plots = plot_distributions(posterior,ndraws,burn_in);
%% plot regime prediction effect
plot_regime_effect(posterior,ndraws,burn_in,Y,Z,true)
%% ----------------------------- PORTFOLIOS ---------------------------- %%
%% compute buy and hold portfolios
[w_, cer_]= buy_and_hold_portfolios(posterior_);
[w, cer]  = buy_and_hold_portfolios(posterior);
%% plot & print buy and hold portfolios
buy_and_hold_plot(w, w_, false);
%% plot & print certainty equivalent returns
certainty_eq_return_plot(cer, cer_, false);
%% plot & print conditional variances
conditional_variance_plot(posterior, posterior_, false)
%% tvtp & print plot
tvtp_plot = timevarying_transition_plot(posterior, posterior_, datenum(db.dates(2:end)), false);
%% state & print plot
create_state_plots(posterior, posterior_, db.dates(2:end));
%% plot sim state
plot_distributions_tvtp(posterior,ndraws,burn_in)