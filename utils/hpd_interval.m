function [interval] = hpd_interval(data, alpha)

% Purpose:
% Compute the HPD region using random sample (posterior MCMC draws) from some distribution
% -----------------------------------
% Algorithm:
% Follows the method proposed by Chen and Shao (1998)
% It can only find the HPD of a single-modal distribution.
% -----------------------------------
% Usage:
% data = random sample (posterior MCMC draws), a column vector
% alpha = significance level, say 0.05, (In that case, 95% HPD interval will be computed)
% -----------------------------------
% Returns:
% LB = lower bound of the HPD interval
% UB = upper bound of the HPD interval
%
% Version: 06/2012
% Written by Hang Qian, Iowa State University
% Contact me:  matlabist@gmail.com

if nargin < 2
    alpha = 0.05;
end

[rows, columns] = size(data);

if columns > rows
    nobs = columns;
    data = sort(data,2);
    cut = round(nobs * alpha);
    span = nobs - cut;
    [gap,ind] = min( data(:,span+1:nobs) - data(:,1:cut),[],2 );
    for r = 1:rows
        LB(r,1) = data(r,ind(r));
        UB(r,1) = data(r,ind(r) + span);
    end
    interval = [LB UB];
else
    nobs = rows;
    data = sort(data);
    cut = round(nobs * alpha);
    span = nobs - cut;
    [gap,ind] = min( data(span+1:nobs,:) - data(1:cut,:),[],1 );
    for c = 1:columns
        LB(c,1) = data(ind(c),c);
        UB(c,1) = data(ind(c) + span,c);
    end
    interval = [LB UB];
end

