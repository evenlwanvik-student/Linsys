%% Problem 5.e) measured vs estimated heading measurement

load_system('boatlab_5_e.slx')
sim('boatlab_5_e.slx') 
plot(t,psi_ref(:,1),'r--',t,psi(:,1),t,psi_est(:,1)); grid on;
title(['Measured vs estimated heading ($y=\psi+\psi_w+v$)'], 'fontsize',16, 'Interpreter','latex')
xlabel('t [sec]', 'fontsize',12, 'Interpreter','latex');
ylabel('[deg]', 'fontsize',12, 'Interpreter','latex');
legend({'$\psi_r$', '$\psi+\psi_w+v$', '$\hat{\psi}$'}, ...
    'fontsize',12, 'Interpreter','latex', 'Location','SouthEast')

%% Problem 5.e) measured vs estimated heading measurement
load_system('boatlab_5_e_plain.slx')
sim('boatlab_5_e_plain.slx')
load_system('boatlab_5_e.slx')
sim('boatlab_5_e.slx') 
plot(t,psi_ref(:,1),'r--',t,psi(:,1),t_plain,psi_plain(:,1)); grid on;
title(['Measured heading with and without Kalman filter, ($y=\psi+\psi_w+v$)'], 'fontsize',16, 'Interpreter','latex')
xlabel('t [sec]', 'fontsize',12, 'Interpreter','latex');
ylabel('[deg]', 'fontsize',12, 'Interpreter','latex');
legend({'$\psi_r$', '$\psi$ with kalman filter', '$\psi$ without kalman filter'}, ...
    'fontsize',12, 'Interpreter','latex', 'Location','SouthEast')

%% Problem 5.e) compare rudder inputs
subplot(2,1,1)
plot(t,b_est(:,1),'m', t,delta(:,1)); grid on;
title(['Compare rudder control signal $\delta$'], 'fontsize',16, 'Interpreter','latex')
xlabel('t [sec]', 'fontsize',12, 'Interpreter','latex');
ylabel('[deg]', 'fontsize',12, 'Interpreter','latex');
legend({'$\hat{b}$', '$\delta$ with both estimations', '$\delta$ without any estimations'}, ...
    'fontsize',12, 'Interpreter','latex', 'Location','NorthEast')
subplot(2,1,2)
plot(t_totally_plain, delta_totally_plain(:,1),'color',[0.9100 0.4100 0.1700]); grid on;
xlabel('t [sec]', 'fontsize',12, 'Interpreter','latex');
ylabel('[deg]', 'fontsize',12, 'Interpreter','latex');
legend({'$\delta$ without any estimations'}, 'fontsize',12, 'Interpreter','latex', 'Location','SouthEast')

%% Problem 5.e) compare actual and estimated wave influence

load_system('boatlab_5_e_waves.slx')
sim('boatlab_5_e_waves.slx')
plot(t_waves,psi_waves_est(:,1), t_waves,psi_waves(:,1)); grid on;
title(['estimated wave influence $\psi_w$ vs estimated $\hat{\psi_w}$'], 'fontsize',16, 'Interpreter','latex')
ylabel('[deg]', 'fontsize',12, 'Interpreter','latex');
xlabel('t [sec]', 'fontsize',12, 'Interpreter','latex');
legend({'$\hat{\psi_w}$', '$\psi_w$'},'fontsize',12, 'Interpreter','latex', 'Location','SouthEast')

%% Problem 5.e) north-east plot
load_system('boatlab_5_plain.slx')
sim('boatlab_5_plain.slx')
load_system('boatlab_5_e_plain.slx')
sim('boatlab_5_e_plain.slx')
load_system('boatlab_5_e.slx')
sim('boatlab_5_e.slx') 

plot(coordinates_totally_plain(:,2),coordinates_totally_plain(:,1),'r--', coordinates(:,2), ...
    coordinates(:,1), coordinates_plain(:,2),coordinates_plain(:,1)); grid on;
title(['north-east plot of autopilot'], 'fontsize',16, 'Interpreter','latex')
xlabel('y', 'fontsize',12, 'Interpreter','latex');
ylabel('x', 'fontsize',12, 'Interpreter','latex');
legend({'No disturbances (reference)', 'With Kalman filter', 'Without Kalman filter (only wave disturbance)'}, ...
    'fontsize',12, 'Interpreter','latex', 'Location','NorthWest')
ylim([0 1200])
xlim([0 350])
