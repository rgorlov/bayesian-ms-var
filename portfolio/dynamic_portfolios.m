function [w, cer] = dynamic_portfolios(posterior)

bond_r = reshape(posterior. sim_x(1,:,:),[120,20000])'./100;
stock_r = posterior.sim_r(:,:)./100;
gammas = [ 2 5 10 20 ];
w = zeros(3, 120, 4);
cer = zeros(4, 120);
for g = 1 : length(gammas)
    [w(:,:, g), cer(g,:)] = strategicPort_three_assets(stock_r, bond_r, posterior.sim_x, gammas(g));
end

end