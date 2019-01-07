
b = (X'*X)\(X'*Y);
[~,N] = size(Y);
[T,K] = size(X);
e = Y - X*b;
S = e'*e/(T-K);
V = kron(S,(X'*X)\eye(K));

[beta,Sigma,E,CovB,logL] = mvregress(X,Y, 'algorithm','cwls','covar0',S)

iwishrnd(e'*e,T-K)

priorV = 0.001*eye(N);
iwishrnd(priorV,N)

% rt * 1
% S =
%     0.0023   -0.0023
%    -0.0023    0.0024
% 10.000 increase due to scale.
% rt * 100
% S =
% 
%    22.6587  -22.5804
%   -22.5804   23.7327

%% IG parameters %%%
alpha = 4;
beta = 4;
eY = beta/(alpha-1);
vY = beta*beta/((alpha-1)*(alpha-1)*(alpha-2));
sqrt(vY)

% find gamma paramters
% alpha = eY*eY/vY
% beta = eY/vY

% find wishart parameters
R = (beta*2)\1*eye(N);
v = alpha*2

% find iwishart params
v = v + N + 1;
R = R\eye(N);
%% G parameters %%%
alpha = 0.5;
beta = 0.05;

eY = alpha/beta
vY = alpha/(beta*beta)

% find igamma parameters
alpha = eY*eY/vY + 2
beta = eY*(alpha - 1)

% find iwishart params
v = alpha*2;
R = beta*2;

%% convert brandt 2010 to priors  %% using v = 8, d = 2
cov_brandt  = 10^(-3)*[6.225 -6.044; -6.044 6.316]; %table 5.1 Brandth 2010

% S = cov*(v-d-1)
S = cov_brandt*(v-N-1)
