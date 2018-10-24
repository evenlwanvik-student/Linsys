Q_est = [35 0 0 0 0;
         0 50 0 0 0;
         0 0 100 0 0;
         0 0 0 69 0;
         0 0 0 0 60];
R_est = [1 0; 
        0 1];
      

K_LQR = lqr(A_PI,B_PI,Q_est,R_est)

K_LQR_P = K_LQR(1:2,1:3);

P_LQR = inv(C_P*inv(B_P*K_LQR_P-A_P)*B_P)  


% Calculate poles for LQR fedback sstem
A_cl = A_PI - B_PI*K_LQR
H = B_PI*P_LQR;

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
L_poles = pole_mag*exp(i*pole_phi)  


scatter(real(L_poles),imag(L_poles))
       


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

butter_L_poles = [-5 + 18.5i 
           -5 - 18.5i
           -13.5 + 13.5i
           -13.5 - 13.5i
           -18.5 + 5i
           -18.5 - 5i]

L_est = abs(place(A_est', C_est', L_poles)')

poles = [-80,-80,-70+38i,-70-38i,-60+50i,-60-50i];
L_o = place(transpose(A_est), transpose(C_est),poles).'




