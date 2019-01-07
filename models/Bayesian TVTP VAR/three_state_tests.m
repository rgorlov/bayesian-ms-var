gam1  = [0 , 0 , 0,  0 , 0,  0]; % prob to state 1
gam2  = [4 , 0 , 1, -2 , 2,  0]; % prob to state 2
gam3  = [4 , 1 , 0, -2 , 0,  2]; % prob to state 3

%increase in Z will deteriorate persisentce across all states
%decrease in Z will improve persistence across all states.

gam = [gam1 ; gam2 ; gam3]';
Z_t = [-0.3 0 0.3];
T = length(Z_t);
nstate = 3;
ind = logical(repmat(eye(nstate),[1,2]));
XX = [Z_t ; ones(1,T)];
TVTP_vec = zeros(T,nstate,nstate);

for k = 1:nstate
    H = exp(XX'*gam(ind(k,:),:));
    H = H./repmat(sum(H,2),[1,nstate]);
    TVTP_vec(:,:,k) = H;
end
% construct time varying matrices
markov_T = zeros(nstate,nstate,T);
for k = 1 : nstate
    markov_T(k,:,:) = reshape(TVTP_vec(:,:,k).', 1,nstate,T);
end
