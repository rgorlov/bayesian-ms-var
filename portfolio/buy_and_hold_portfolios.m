function [w, cer] = buy_and_hold_portfolios(posterior)

bond_r = reshape(posterior.sim_x(1,:,:),[120,20000])';
gammas = [ 2 5 10 20 ];
w = zeros(3, 120, 4);
cer = zeros(4, 120);
for g = 1 : length(gammas)
    [w(:,:, g), cer(g,:)] = bhPort(posterior.sim_r./100, bond_r./100, gammas(g));
end

end