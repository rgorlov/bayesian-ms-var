function [ drch_pdf_log ] = drch_pdf(D_p, D_prior, D_post)
%DRCH_PDF_LOG Summary of this function goes here
%   Detailed explanation goes here
[nstate, ~] = size(D_p);

if nstate ~=4
    restrict = nstate;
else
    restrict = nstate - 1;
end

if ~exist('D_post', 'var') || isempty(D_post)
    D_prior(D_prior==0)=[];
    Dir_alpha = zeros(nstate,restrict);
    Dir_alpha(:) = D_prior;
else
    D_post(D_post==0)=[];
    Dir_alpha = zeros(nstate,restrict);
    Dir_alpha(:) = D_post;
end

% reshape posterior markov matrix
D_p(D_p==0)=[];
Dir_mean = zeros(nstate,restrict);
Dir_mean(:) = D_p;

constant = gammaln(sum(Dir_alpha,2))-sum(gammaln(Dir_alpha(:,1:end)),2);
stochastic = sum((Dir_alpha(:,1:end)-1).*log(Dir_mean),2);
drch_pdf_log = sum(constant+stochastic);


end

