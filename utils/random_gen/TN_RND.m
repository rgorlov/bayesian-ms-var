function sample = TN_RND(mu,sigma,lb,ub,ndraws)

% Purpose: 
% Generate random numbers from truncated normal distribution
% TN(lb,ub) (mu, sigma)
% -----------------------------------
% Density:
% f(x) = 1/(Phi(ub)-Phi(lb)) * phi(x,mu,sigma)
% -----------------------------------
% Algorithm: 
% Inverse CDF
% -----------------------------------
% Usage:
% mu = location parameter
% sigma = scale parameter
% lb = lower bound of the random number
% ub = upper bound of the random number
% ndraws = number of draws
% -----------------------------------
% Returns:
% sample = random numbers from TN(lb,ub) (mu, sigma)
% -----------------------------------
% Notes:
% 1. If at least one of the arguments mu,sigma,lb,ub are vectors/matrix,
%    It will return a vector/matrix random numbers with conformable size.
% 2. If there is no lower/upper bound, use Inf or some large number instead
%
% Version: 06/2012
% Written by Hang Qian, Iowa State University
% Contact me:  matlabist@gmail.com

if nargin < 4; ub = 999;end
if nargin < 3; lb = -999;end
if nargin < 2; sigma = 1;end
if nargin < 1; mu = 0;end

prob_ub = normcdf(ub,mu,sigma);
prob_lb = normcdf(lb,mu,sigma);
prob_diff = prob_ub - prob_lb;

ndraws_check = numel(prob_diff);
if nargin < 5 || ndraws_check > 1
    ndraws = ndraws_check;
    U = prob_diff;
    U(:) = rand(ndraws,1);
else
    U = rand(ndraws,1);
end

U_rescale = prob_lb + U .* prob_diff;
sample = norminv(U_rescale,mu,sigma);
