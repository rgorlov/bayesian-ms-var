function sample = drchrnd(theta,ndraws)

% Purpose: 
% Generate random numbers from Dirichlet distribution
% -----------------------------------
% Density:
% f(x) = constant * prod(xi^(theta_i-1))
% -----------------------------------
% Algorithm: 
% gamma representation of Dirchlet distribution
% -----------------------------------
% Usage:
% theta = relative power parameters (a k*1 column vector)
% ndraws = number of draws
% -----------------------------------
% Returns:
% sample = random numbers from Dirichlet distribution (k*ndraws matrix)
% -----------------------------------
%
% Version: 06/2012
% Written by Hang Qian, Iowa State University
% Contact me:  matlabist@gmail.com


if nargin < 2
    ndraws = 1;
end

if ndraws == 1
    gam_draws = gamrnd(theta,1);
    sample = gam_draws ./ sum(gam_draws);
else
    theta = theta(:);
    gam_draws = gamrnd(theta(:,ones(1,ndraws)),1);
    sum_draws = sum(gam_draws);
    sample = gam_draws ./ sum_draws(ones(length(theta),1),:);
end



