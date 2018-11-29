% @b_k:       rudder angle control signal 
% @psi_k:     measured compass angle 
% @init_data: initialization values
% returns:
% @b_est:     estimated rudder angle
% @psi_est:   estimated compass angle
% the init_data will be kept persistent while in loop
function [psi_est, b_est] = kalman_filter(b_k, psi_k, init_data)
    peristent init_flag x_pri P_pri A_d B_d C_d E_d Q_k R_k I 
    if isempty(init_flag)
        init_flag = 1;
     
        % distribute copies of init_data
        [x_pri,P_pri,A_d,B_d,C_d,E_d,Q_k,R_k,P_k,I] = deal(data.x_pri0, data.P_pri0, ... 
            data.Ad, data.Bd, data.Ed, data.Cd, data.Qk, data.Rk, data.I)
    end
    
    % 1. compute Kalman gain:
    K_k = P_pri*C_d'*(C_d*P_pri*C_d+R_k);
    
    % 2. Update estimate with measurement (posteriori):
    x_post = x_pri+K_k*(y_k-C_d*x_pri)
    
    % 3. Compute error variance for updated estimate:
    P_k = (I-K_k*C_d)*P_pri
    
    % 4. Project ahead (priori)
    x_pri = A_d*x_post
    P_pri = A_d*P_k*A_d'+Q_k
    
    compass = x_post(3); rudder_bias = x_post(5)
end 