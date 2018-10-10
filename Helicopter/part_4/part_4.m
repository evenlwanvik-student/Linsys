
Q_est = [30 0 0 0 0;
     0 30 0 0 0;
     0 0 100 0 0;
     0 0 0 20 0;
     0 0 0 0 60];
 
R_est = [1, 0;
     0, 1];

K_LQR = lqr(A,B,Q_est,R_est)

K_LQR_P = K_LQR(1:2,1:3);

P_LQR = inv(C_P*inv(B_P*K_LQR_P-A_P)*B_P)  


% Calculate poles for LQR fedback sstem
A_cl = A - B*K_LQR;
H = B*P_LQR;

%closed loop statespace
clSys = ss(A_cl, H, C, 0);


% Observer poles
clPoles = eig(clSys);
domPole = min(abs(clPoles));
fastPole = max(abs(clPoles));

T = 10;
pole_mag = T*fastPole;

phi = pi/8;
spread = -phi:(phi);


pole_phi = ((180-20):40/5:(180+20))*pi/180;
L_poles = pole_mag*exp(i*pole_phi)  %?
%L_poles = [-80 -80 -70+38i -70-38i -60+50i -60-50i];

scatter(real(L_poles),imag(L_poles))
       
%real_poles = [pole_mag-1 pole_mag-2 pole_mag-3 pole_mag-4 pole_mag-5 pole_mag-6]






% observer gain matrix L
K1 = 0.581;
K2 = 0.0935;
K3 = -0.612;
A_est = [0 1 0 0 0 0; 
         0 0 0 0 0 0; 
         0 0 0 1 0 0; 
         0 0 0 0 0 0; 
         0 0 0 0 0 1;
         K3 0 0 0 0 0];
B_est = [0,0;
         0,K1;
         0,0;
         K2,0;
         0,0;
         0,0];
C_est = [1 0 0 0 0 0; 
       0 0 1 0 0 0;
       0 0 0 0 1 0];


L_est = abs(place(A_est', C_est', real_poles)')

L_est = [0.093 0.0051 -0.013;
         2.22 0.24 -0.65;
         -0.020 0.093 0.0016;
         -0.091 2.28 0.0723;
         0.0147 -0.0020 0.0907;
         0.7043 -0.103 2.11] *10^3

% The poles of the observer is A-LC. 
%K1 = 0.582;
%K2 = 0.0935;
%K3 = 0.612;
%A_full = [0 1 0 0 0 0; 0 0 0 1 0 0; 0 0 0 0 0 0; 0 0 0 0 0 1; 0 0 0 0 0 0; K3 0 0 0 0 0];
%B_full = [0 0; 0 K1; 0 0; K2 0; 0 0; 0 0];
%C = [1 0 0 0 0 0; 0 0 1 0 0 0; 0 0 0 0 1 0];




butter_L_poles = [-5 + 18.5i 
           -5 - 18.5i
           -13.5 + 13.5i
           -13.5 - 13.5i
           -18.5 + 5i
           -18.5 - 5i];

