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
