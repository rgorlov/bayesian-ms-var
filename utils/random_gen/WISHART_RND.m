function sample = WISHART_RND(Omega,df)

% Purpose: 
% Generate a random matrix from Wishart distribution
% -----------------------------------
% Density:
% f(x) = c*det(Omega)^(-df/2) * x ^((df-k-1)/2) * exp (-tr(inv(Omega)*x/2)
% where k is the dimension of the matrix, c is a constant
% E(X) = df * Omega
% -----------------------------------
% Algorithm: 
% Yi ~ MVN(0,Omega), i=1,...,df, then sum(Yi*Yi') ~ Wishart(Omega,df)
% -----------------------------------
% Usage:
% Omega = covariance matrix
% df = degree of freedom
% -----------------------------------
% Returns:
% sample = a random matrix from Wishart(Omega,df)
% -----------------------------------
%
% Version: 06/2012
% Written by Hang Qian, Iowa State University
% Contact me:  matlabist@gmail.com


dim = size(Omega,1);
P = chol(Omega);
Y = P' * randn(dim,df);
sample = Y * Y';