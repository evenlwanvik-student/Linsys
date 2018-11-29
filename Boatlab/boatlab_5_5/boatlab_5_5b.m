%% problem 5.b)

sim_time_b = 5000; % simulation time
load_system('boatlab_5_b.slx')
sim('boatlab_5_b.slx')
R = var(psi_deg(:,2)) %[deg]
plot(psi_deg(:,2))