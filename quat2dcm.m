function DCM  = quat2dcm(q_in)
%Compute the direction cosine matrix from Euler Parameters
% [DCM] = quat2dcm(q_in)
%
% Author: Karl Ludwig Fetzer
DCM = zeros(3);
DCM(1,1) = 1 - 2 * q_in(2)^2 - 2 * q_in(3)^2;
DCM(1,2) = 2 * (q_in(1)*q_in(2) - q_in(3)*q_in(4));
DCM(1,3) = 2 * (q_in(3)*q_in(1) + q_in(2)*q_in(4));
DCM(2,1) = 2 * (q_in(1)*q_in(2) + q_in(3)*q_in(4));
DCM(2,2) = 1 - 2 * q_in(3)^2 - 2 * q_in(1)^2;
DCM(2,3) = 2 * (q_in(2)*q_in(3) - q_in(1)*q_in(4));
DCM(3,1) = 2 * (q_in(3)*q_in(1) - q_in(2)*q_in(4));
DCM(3,2) = 2 * (q_in(2)*q_in(3) + q_in(1)*q_in(4));
DCM(3,3) = 1 - 2 * q_in(1)^2 - 2 * q_in(2)^2;


%changed this code to fix error 18-JUN-2013 -- KJL
% a=q(1);
% b=q(2);
% c=q(3);
% d=q(4);
% 
% DCM = [a^2+b^2-c^2-d^2  2*b*c+2*a*d     2*b*d-2*a*c;
%        2*b*c-2*a*d      a^2-b^2+c^2-d^2 2*c*d+2*a*b;
%        2*b*d+2*a*c      2*c*d-2*a*b     a^2-b^2-c^2+d^2];    


end