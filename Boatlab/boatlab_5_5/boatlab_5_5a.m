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