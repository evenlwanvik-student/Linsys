%%%%%%%%%%% LQR w/ integrator
A_PI = [0 1 0 0 0; 0 0 0 0 0; 0 0 0 0 0; 1,0,0,0,0; 0,0,1,0,0];
A_P = [0 1 0; 0 0 0; 0 0 0]; % _P for calculating the P matrix

B_PI = [0,0;
    0,0.581;
    0.0935,0;
    0,0;
    0,0];

B_P = [0,0;
    0,0.581;
    0.0935,0];

Q = [100 0 0 0 0;
     0 50 0 0 0;
     0 0 100 0 0;
     0 0 0 20 0;
     0 0 0 0 50];
 
R = [0.1, 0;
     0, 1];
 
C = [1 0 0 0 0;
     0 0 1 0 0];
C_P = [1 0 0;
       0 0 1];
 
 
K_LQR = lqr(A_PI,B_PI,Q,R)

K_LQR_P = K_LQR(1:2,1:3);


P_LQR = inv(C_P*inv(B_P*K_LQR_P-A_P)*B_P)

% hvorfor disse verdiene på Q og P
% hvorfor integrator
% hvorfor er denne vanskeligere enn problem 2
% 






