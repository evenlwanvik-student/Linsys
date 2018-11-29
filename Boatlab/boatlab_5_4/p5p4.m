% Testing observability with different disturbances 

% Calculater varibles
T=70.4663;
K=0.1556;
omega_0 = 0.7823;
lambda = 0.0749;

%With no disturbance at all
A_1=[0 1; 0 -1/T];
C_1=[1 0];

%With current as the only disturbance
A_2=[0 1 0; 0 -1/T -K/T;0 0 0];
C_2=[1 0 0];

%With waves as the only disturbance
A_3=[0 1 0 0;
    -omega_0^2 -2*lambda*omega_0 0 0;
    0 0 0 1;
    0 0 0 -1/T];
C_3=[0 1 1 0 ];

%With both current and waves as disturbances
A_4=[0 1 0 0 0;
    -omega_0^2 -2*lambda*omega_0 0 0 0;
    0 0 0 1 0; 
    0 0 0 -1/T -K/T;
    0 0 0 0 0];
C_4 = [0 1 1 0 0];

fprintf('Observability-matrix without disturbances:\n')
ObsvWODist=obsv(A_1,C_1);
disp(ObsvWODist)
fprintf('Rank1=\n')
rank(obsv(A_1,C_1))

fprintf('Observability-matrix with current:\n')
ObsvWC=obsv(A_2,C_2);
disp(ObsvWC)
fprintf('Rank2=\n')
rank(obsv(A_2,C_2))

fprintf('Observability-matrix with waves:\n')
ObsvWW=obsv(A_3,C_3);
disp(ObsvWW)
fprintf('rank3=\n')
rank(obsv(A_3,C_3))


fprintf('Observability-matrix with both waves and current:\n')
ObsvWDist=obsv(A_4,C_4);
disp(ObsvWDist)
fprintf('rank=4\n')
rank(obsv(A_4,C_4))


