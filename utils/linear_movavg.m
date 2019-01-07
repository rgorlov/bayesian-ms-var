function movavg_data = linear_movavg(data, lag)
% get length
T = length(data);

% pre allocate for cumulative sum
cum_data = zeros(T, 1);

% get nan index
nan_index = ~isnan(data);

% cumsum data
cum_data(nan_index) = cumsum(data(nan_index));

% compute moving sums of days
movsumdata = cum_data - [zeros(lag, 1) ; cum_data(1 : T - lag, :)];

% compute moving average of data
movavg_data = movsumdata/lag;
end