
% ENDRET LITT DIV, 
% L_est, A_est .. etc = L, A ...
%
K1 = 0.581;
K2 = 0.0935;
K3 = -0.612;

A = [0 1 0 0 0 0; 
     0 0 0 0 0 0; 
     0 0 0 1 0 0; 
     0 0 0 0 0 0; 
     0 0 0 0 0 1;
     K3 0 0 0 0 0];
     
B = [0,0;
     0,K1;
     0,0;
     K2,0;
     0,0;
     0,0];
     
C = [1 0 0 0 0 0; 
     0 0 1 0 0 0;
     0 0 0 0 1 0];

% Controller weights w/ estimator
Q_est = [30 0 0 0 0;
         0 30 0 0 0;
         0 0 100 0 0;
         0 0 0 20 0;
         0 0 0 0 60];

% Reference weights
R_est = [1, 0;
         0, 1];

K_LQR = lqr(A,B,Q_est,R_est) % State feedback gains (LQR)
K_LQR_P = K_LQR(1:2,1:3); % used for calculating the reference gain
P_LQR = inv(C_P*inv(B_P*K_LQR_P-A_P)*B_P) % Reference gain (LQR)

% Calculate poles for LQR fedback sstem
A_cl = A - B*K_LQR; % LQR Closed loop state matrix (Inner system matrix)
H = B*P_LQR; % New input matrix 

% Get the inner closed loop state-space model
clSys = ss(A_cl, H, C, 0);
% Calculate the poles of the inner closed loop
clPoles = eig(clSys);
domPole = min(abs(clPoles)); % the dominant pole (smallest real value)
fastPole = max(abs(clPoles)); % fastest pole (largest real value)

poleGain = 10; % x times quicker than the state feedback control poles
poleMag = T*fastPole; % pole magnitude
pole_phi = ((180-20):40/5:(180+20))*pi/180; % angles of the poles from -20 to 20 around pi (left plane)
p_est = pole_mag*exp(i*pole_phi)  % poles given in complex conjugated pairs
scatter(real(p_est),imag(p_est)) % scatter plot of pole placement

% Observer gain matrix L
L = place(A', C_', p)' % SLIK SKAL DET VÆRE, IKKE SOM UNDER
%L_est = abs(place(A_est', C_est', real_poles)')

%L = [0.093 0.0051 -0.013;
%         2.22 0.24 -0.65;
%         -0.020 0.093 0.0016;
%         -0.091 2.28 0.0723;
%         0.0147 -0.0020 0.0907;
%         0.7043 -0.103 2.11] *10^3

%butter_L_poles = [-5 + 18.5i 
%           -5 - 18.5i
%           -13.5 + 13.5i
%           -13.5 - 13.5i
%           -18.5 + 5i
%           -18.5 - 5i];

