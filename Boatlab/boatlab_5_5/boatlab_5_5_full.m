%%inits
sim_time = 500; % simulation time
Fs = 10;        % sampling frequency
Ts = 1/Fs;      % sample time
ref = 30;       % heading reference [deg]

% PD controller
Kpd = 0.839;    
Td = 70.47;
Tf = 8.39;
num = [Td 1]; den = [Tf 1];
PD = Kpd * tf(num,den); 

% get north-east without any noise or disturbance
load_system('boatlab_5_plain.slx')
sim('boatlab_5_plain.slx') 

%% Problem 5.a)

w_0 = 0.7823;     % resonance frequency
lambda = 0.0749;  % dampening factor
sigma = 0.0271;   % compass noise from wave stdev.
K_w = 2*lambda*w_0*sigma; % wave noise gain
T = 70.46;        % rudder->heading time constant
K = 0.1556;       % rudder->heading time gain

% Matrices from Task 5.4 a)
A = [0 1 0 0 0; -w_0^2 -2*lambda*w_0 0 0 0; 
     0 0 0 1 0; 
     0 0 0 -1/T -K/T; 
     0 0 0 0 0];
B = [0; 0; 0; K/T; 0];
C = [0 1 1 0 0];
D = 0;
E = [0 0; K_w 0; 0 0; 0 0; 0 1];


F_s = 10;      % Sample frequency
T_s = 1/F_s;   % Corresponding samples time

% Discretizing the system matrix A, input matrix B and noise matrix E
[Ad, Bd]  = c2d(A,B,T_s);   
[Ad, Ed] = c2d(A,E,T_s);
% Cd = C and Dd = D (superposition property)
Cd = C;
Dd = D;

%% problem 5.b)

sim_time_b = 5000; % simulation time
load_system('boatlab_5_b.slx')
sim('boatlab_5_b.slx')
R = var(psi_deg(:,2)) %[deg]
plot(psi_deg(:,2))

%% Problem 5.c)

% covariance matrices
Q = diag([30, 10^-6]); % 

% x and p priori initial values
x_pri0 = [0; 0; 0; 0; 0];
P_pri0 = diag([1, 0.013, pi^2, 1, 2.5*10^(-4)]);
R = (R/Ts)*(pi/180) % deg->rad / sample time
I = eye(5);

% data struct for initial values, which will be kept persistent in kalman
% function
data = struct('x_pri0', x_pri0, 'P_pri0', P_pri0,'Ad', Ad, 'Bd', ...
              Bd, 'Ed', Ed, 'Cd', Cd, 'Q', Q, 'R', R, 'I', I);

%load_system('boatlab_5_c.slx')
%sim('boatlab_5_c.slx') 

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
