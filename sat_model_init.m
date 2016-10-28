%% Intilization file for ANDESITE simulink model
% Modified heavily by J. Brent Parham 5/27/2016
clear all
close all
clc

%% Constants
%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
mu = 3.986004415e14;  %Earth's gravitational parameter (m^3/s^2)
Re = 6378.1363e3;   %Earth's radius (m)
ee = 0.081819221456;     %mean eccentricity of the Earth
w_earth = 7.2921158553e-5;  %Earth's spin rate (rad/s)
J = [1;
     1.08262668355e-3;
    -2.53265648533e-6;
    -1.61962159137e-6;
    -2.27296082869e-7;
     5.40681239107e-7];  %zonal harmonic constants (J1-J6)
TU = 13.44684985511 * 60; %TU (s)
SP = 4.57e-5;  %mean solar pressure (N/m^2)


%% Time parameters and variables
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
epoch = [2017 06 01 00 00 00];%UTC epoch ([yr mon day hr min sec])
t0 = 0; %initial time from epoch (s)
dt = 1/10; %time step (s)
tf = 86400;  %final time from epoch- current setting corresponds to (s)


%% Orbital elements of the spacecraft's orbit
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
a = Re + 500e3;  %semi-major axis (m)
e = 0;  %eccentricity
Omega = rand(1)*360*pi/180;  %RAAN (rad)
inc = 85*pi/180;  %inclination (rad)
% inc = 85*pi/180;
omega = 0*pi/180;  %argument of periapsis (rad)
f0 = 360*pi/180*rand(1);  %true anomaly at epoch (rad)
%other constants
p = a*(1-e^2);  %semi-latus rectum (m)
r0 = p/(1+e*cos(f0));  %initial orbit magnitude (m)
h = sqrt(mu*p);  %specific angular momentum (m^2/s)
n = sqrt(mu/a^3);  %mean motion (rad/s)
P = 2*pi/n;  %orbital period (s)

%% Initial conditions of spacecraft
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
r0 = (ROT3(omega)*ROT1(inc)*ROT3(Omega))'*[r0*cos(f0);
                                           r0*sin(f0);
                                           0];  %initial position (ECI)
v0 = (ROT3(omega)*ROT1(inc)*ROT3(Omega))'*[-mu/h*sin(f0);
                                            mu/h*(e+cos(f0));
                                            0];  %initial velocity (ECI)


% Plantery Systems Corp CSD Max Payload Rotation Rates  6U
% initial angular velocity (rad/s) of body frame relative to ECI frame
w0 = 0.2*ones(3,1)/sqrt(3);

q0 = [1;
      1;
      1;
      1]/2;  %initial unit quaternion relating body frame to ECI frame 
  
%% System parameters of spacecraft
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%Full Mule
m = 9;  %mass of spacecraft (kg)
Jx=0.06;
Jy=0.1;
Jz=0.14;

%Empty Mule
% m = 5.801;  %mass of spacecraft (kg)
% Jx=0.046;
% Jy=0.07784;
% Jz=0.10699;

J_c = [Jx  0  0;
       0  Jy 0;
       0  0  Jz];  %centroidal moment of inertia sans reaction wheel system (kg-m^2)


%% FACET model: Cube w/ 1 m sides (6 sides)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
FACET_model.num_of_faces = 6;  %number of faces
FACET_model.A = [.2*.1 .2*.1 .3*.2 .3*.2 .1*.3 .1*.3]; %area of each face (m^2) %+x,-x,+z,-z,+y,-y
FACET_model.Asolar = [0 .2*.1*.7 0 0.002728*30 0 0]; %area of each face (m^2) %+x,-x,+z,-z,+y,-y
FACET_model.Cr = 1.0*ones(1,6); %coefficient of reflectivity for each face
FACET_model.r_COM = [0;0;0]; %position of center of mass relative to geometric center (m)

%unit normal vectors: columns are unit normal vectors (pointing outward) of each face
FACET_model.n = [1  -1  0  0   0  0;
                  0  0  0  0  1  -1;
                  0  0  1  -1   0  0];
%centers of pressure: columns are vectors from geometric center of spacecraft to center 
%of pressure of each face which depends on the dimensions of the spacecraft (m)
FACET_model.r_cp = [0.15  -0.15   0       0     0     0
                    0        0    0       0     0.1  -0.1
                    0        0    0.05  -0.05   0     0];


for i = 1:FACET_model.num_of_faces
    FACET_model.cp(1:3,i) = (FACET_model.r_cp(:,i) - FACET_model.r_COM);
end   

%% Sensor Suite parameters
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Gyro parameters
sig_u = 1*pi/180*1/3600;%gyro drift variance
sig_v = (0.0066*pi/180)*2;
bias0 = 3/3600*randn(3,1)*pi/180;  %initial gyro bias (rad/s)
gyro_freq = 25;  %Sampling frequency of gyro (Hz)

%Magnetometer parameters
sig_B = 4.5e-8;   %magnetometer noise variance
mag_freq = 10;  %magnetometer sampling frequency (Hz)

%Sun Sensor parameters
sig_s = 0.1;  %Sun sensor noise variance
sun_freq = 10;  %Sun sensor sampling frequency (Hz)

%Star Tracker parameters
sig_q = .0001;  %star tracker variance
ST_freq = 2;  %star tracker sampling frequency (Hz)


%% Controller Paramters
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%pole_B = 4.48677e-5; %Threshold of magnetic field value at poles used to turn off coils (about 55 deg lat)
I_max = 1.0; %max current for torque coils (A)
N=40;

