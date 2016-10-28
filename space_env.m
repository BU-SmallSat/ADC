function [JD,T_UT1,R_ECItoECEF,R_SUN,R_MOON,B] =space_env(epoch,r,Re)

%Compute the Julian Date (JD) from a Gregorian Date (UT1) input
yr=epoch(1);  %(year)
mo=epoch(2);  %(month)
d=epoch(3);  %(day)
h=epoch(4);  %(hr)
min=epoch(5);  %(min)
s=epoch(6);  %(sec)
JD=367*yr-floor(7/4*(yr+floor((mo+9)/12)))+floor(275*mo/9)+d+1721013.5+(((s/60+min)/60)+h)/24;  %(JD)

%Compute the Universal Time (UT) from JD
T_UT1 = (JD-2451545.0)/36525;

%Compute the Greenwich Mean Sidereal Time (GMST) from UT
GMST = 67310.54841 + (876600.0*3600.0 + 8640184.812866)*T_UT1 + 0.093104*T_UT1^2 - 6.2E-6*T_UT1^3;
G0 = rem(GMST,86400)/240;
if G0 < 0
    G0 = -(-G0-360);
end
%truncate GMST between 0 and 2pi
GMST = G0*pi/180;  %(rad)

%Compute the Direction Cosine Matrix (DCM) for converting vectors in 
%Earth-Centered Inertial (ECI) frame to vectors in Earth-Centered 
%Earth-Fixed (ECEF) frame
R_ECItoECEF = ROT3(GMST);

%Compute the Sun vector based on the UT
R_SUN = r_sun(T_UT1);

%Compute the Moon vector based on the UT
R_MOON = r_moon(T_UT1,Re);

%Compute the Earth's magnetic vector in the ECI frame
B = Dipole_model(r,GMST,Re);  %(T)

end

function A = ROT3(theta)

A = [cos(theta) sin(theta) 0;
    -sin(theta) cos(theta) 0;
     0          0          1];
 
end

function r = r_sun(T_UT1)

lambdaM = 280.4606184+36000.77005361*T_UT1;  %(°)
M = (357.5277233+35999.05034*T_UT1)*pi/180.0;  %(rad)
lambdaecliptic = (lambdaM+1.914666471*sin(M)+0.019994643*sin(2*M))*pi/180.0;  %(rad)
E = (23.439291-0.0130042*T_UT1)*pi/180.0;  %(rad)
Rs = (1.000140612-0.016708617*cos(M)-0.000139589*cos(2*M))*149598000*10^3;  %(m)
r = Rs*[cos(lambdaecliptic);
        cos(E)*sin(lambdaecliptic);
        sin(E)*sin(lambdaecliptic)];  %(m)
  
end

function r = r_moon(T_UT1,Re)

lambdaecliptic = (218.32+481267.8813*T_UT1+6.29*sin((134.9+477198.85*T_UT1)*pi/180)-...
                 1.27*sin((259.2-413335.38*T_UT1)*pi/180)+0.66*sin((235.7+890534.23*T_UT1)*pi/180)+...
                 0.21*sin((269.9+954397.70*T_UT1)*pi/180)-0.19*sin((357.5+35999.05*T_UT1)*pi/180)-...
                 0.11*sin((186.6+966404.05*T_UT1)*pi/180))*pi/180;  %(rad)
phiecliptic = (5.13*sin((93.3+483202.03*T_UT1)*pi/180)+0.28*sin((228.2+960400.87*T_UT1)*pi/180)-...
              0.28*sin((318.3+6003.18*T_UT1)*pi/180)-0.17*sin((217.6-407332.20*T_UT1)*pi/180))*pi/180;  %(rad)
P = (0.9508+0.0518*cos((134.9+477198.85*T_UT1)*pi/180)+0.0095*cos((259.2-413335.38*T_UT1)*pi/180)+...
    0.0078*cos((235.7+890534.23*T_UT1)*pi/180)+0.0028*cos((269.9+954397.70*T_UT1)*pi/180))*pi/180;  %(rad)
epsilon = (23.439291-0.0130042*T_UT1-1.64E-7*T_UT1^2+5.04E-7*T_UT1^3)*pi/180; %rad
radius = Re/sin(P);  %(m)
r = radius*[cos(phiecliptic)*cos(lambdaecliptic);
            cos(epsilon)*cos(phiecliptic)*sin(lambdaecliptic)-sin(epsilon)*sin(phiecliptic);
            sin(epsilon)*cos(phiecliptic)*sin(lambdaecliptic)+cos(epsilon)*sin(phiecliptic)];  %(m)
        
end

function B = Dipole_model(r,GMST,Re)

%2010 IGRF constants
g01 = -29496.5e-9;
g11 = -1585.9e-9;
h11 = 4945.1e-9;

H0 = sqrt(g01^2 + g11^2 + h11^2);

theta_m = acos(g01/H0);
phi_m = atan2(h11,g11);

GMST_m = GMST + phi_m;

m_hat = [sin(theta_m)*cos(GMST_m);
         sin(theta_m)*sin(GMST_m);
         cos(theta_m)];
     
r_hat = r/norm(r);
     
B = Re^3*H0/norm(r)^3*(3*dot(m_hat,r_hat)*r_hat - m_hat);

end