
Q_est = [0.5 0 0 0 0;
         0 1 0 0 0;
         0 0 0.2 0 0;
         0 0 0 0.05 0;
         0 0 0 0 0.1];
 
R_est = [500, 0;
     0, 500];
 
K_LQR = lqr(A_PI,B_PI,Q_est,R_est);

K_LQR_P = K_LQR(1:2,1:3);

P_LQR = inv(C_P*inv(B_P*K_LQR_P-A_P)*B_P);  


% Calculate poles for LQR fedback sstem
A_cl = A_PI - B_PI*K_LQR;
H = B_PI*P_LQR;

%closed loop statespace
clSys = ss(A_cl, H, C, 0);


% Observer poles
clPoles = eig(clSys)
domPole = min(abs(clPoles));
fastPole = max(abs(clPoles));

T = 4;
pole_mag = T*fastPole;
real_poles = [pole_mag-1 pole_mag-2 pole_mag-3 pole_mag-4 pole_mag-5 pole_mag-6]
scatter(real_poles);

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
C_est = [0 0 0 0 0 0; 
         0 0 1 0 0 0;
         0 0 0 0 1 0];

L_poles'
       
L_est = abs(place(A_est', C_est', L_poles)')





