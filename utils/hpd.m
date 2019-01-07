function [interval] = hpd(data)
% loop over every dimension
[K, S, draws] = size(data);

interval = [];
for s = 1:S
    for k = 1:K
        data_k = reshape(data(k,s,:),[1,draws]);
        interval = [ interval ; hpd_interval(data_k) ];
    end
end

end
