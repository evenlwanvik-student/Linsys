%% Problem 5.d) heading and rudder plot

% load a reference system without kalman filter
load_system('boatlab_5_d_plain.slx')
sim('boatlab_5_d_plain.slx') 

load_system('boatlab_5_d.slx')
sim('boatlab_5_d.slx') 
% plot heading
subplot(2,1,1)
plot(t,psi_ref(:,1),'r--',t,psi(:,1),t_plain,psi_plain(:,1)); grid on;
title(['Heading ref $\psi_r$ and measurement $y=\psi+v$'], 'fontsize',16, 'Interpreter','latex')
xlabel('t [sec]', 'fontsize',12, 'Interpreter','latex');
ylabel('$\psi$ [deg]', 'fontsize',12, 'Interpreter','latex');
legend({'$\psi_r$', '$\psi+v$ with $\hat{b}$', '$\psi+v$ without $\hat{b}$'}, ...
    'fontsize',12, 'Interpreter','latex', 'Location','SouthEast')
% plot rudder
subplot(2,1,2)
plot(t,b_est(:,1),'m', t,delta(:,1), t_plain,delta_plain(:,1)); grid on;
title(['Rudder bias $\hat{b}$ and control $\delta$'], 'fontsize',16, 'Interpreter','latex')
xlabel('t [sec]', 'fontsize',12, 'Interpreter','latex');
ylabel('[deg]', 'fontsize',12, 'Interpreter','latex');
legend({'$\hat{b}$', '$\delta$ with $\hat{b}$', '$\delta$ without $\hat{b}$'}, ...
    'fontsize',12, 'Interpreter','latex', 'Location','NorthEast')

%% Problem 5.d) north-east plot

plot(coordinates_totally_plain(:,2),coordinates_totally_plain(:,1),'r--', coordinates(:,2), ...
    coordinates(:,1), coordinates_plain(:,2),coordinates_plain(:,1)); grid on;
title(['north-east plot of autopilot'], 'fontsize',16, 'Interpreter','latex')
xlabel('t [sec]', 'fontsize',12, 'Interpreter','latex');
ylabel('[deg]', 'fontsize',12, 'Interpreter','latex');
legend({'No disturbances (reference)', 'with rudder bias estimation', 'without rudder bias estimation'}, ...
    'fontsize',12, 'Interpreter','latex', 'Location','SouthEast')
xlim([0 1000])