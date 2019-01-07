%% getData
%% load data, send to datatable
clear,clc

data = load('data/gw_data.mat', '-regexp', '^(?!raw|num|csp|crsp_vwx)...');

db = struct2table(data);

%% create variables
% inflation
db.infl = log(1 + db.infl);
db.ma_infl = log(linear_movavg(exp(db.infl)-1, 12));
db.mv_infl = log(linear_movavg((exp(db.infl)-1).^2, 12));
% rfree
db.rf = db.r_free;
db.r_free = log (1 + db.r_free);
% dividend yield
db.dy = [NaN ; log(db.dividends(2:end)./db.index(1:end-1))];
% earnings price ratio
db.ep = log(db.earnings./db.index);
% dividend payout ratio
db.de = log(db.dividends./db.earnings);
% dividend to price ratio
db.dp = log(db.dividends./db.index);
% default yield spread
db.dfy = log(db.BAA - db.AAA);
db.ma_dfy = log(linear_movavg(exp(db.dfy), 12));
db.mv_dfy = log(linear_movavg(db.dfy.^2, 12));
% term spread
db.tms = db.lty - db.rf;
db.ma_tms = log(linear_movavg(db.tms, 12));
db.mv_tms = log(linear_movavg(db.tms.^2, 12));
% default return spread
db.dfr = db.corpr - db.ltr;
db.ma_dfr = log(linear_movavg(exp(db.dfr), 12));
db.mv_dfr = log(linear_movavg(db.dfr.^2, 12));
% excess bond returns
db.corp = 100 * (log(1 + db.corpr) - db.r_free);
% stock variance
db.svar = log(db.svar);
% real return on t bil
db.rrf = db.r_free - db.infl;
% log excess returns
db.r = 100 * (log(1 + db.crsp_vw) - db.r_free);
% moving avg risk
db.sv = log(linear_movavg(exp(db.svar), 12));
% momentum of excess returns
db.mom = linear_movavg(db.r, 12);
db.mv_mom = log(db.mom.^2);
%%
% time 
index = datenum('195207', 'yyyymm');
fin = datenum('201312', 'yyyymm');
index = find(db.dates==index,1);
fin = find(db.dates==fin,1);
ind = index:fin;
db = db(ind,:);
db.crsp_vw = [];
db.BAA = [];
db.AAA = [];
%db.r_free = [];
db.tbl = [];
% db.lty = [];
db.corpr = [];
% db.ltr = [];
db.index =[];
db.earnings =[];
db.dividends =[];
db.const = ones(height(db),1);
db.dates = datetime(datestr(db.dates, 'yyyy-mm'), 'InputFormat', 'yyyy-MM');
