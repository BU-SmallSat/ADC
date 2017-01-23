/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ADC.c
 *
 * Code generated for Simulink model 'ADC'.
 *
 * Model version                  : 1.1170
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Wed Jan 18 14:57:52 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ADC_capi.h"
#include "ADC.h"
#include "ADC_private.h"

/* user code (top of source file) */
/* this is a source test comment that graham wrote


  


  


    
    

  
    
    /* Block signals (auto storage) */
                  B_ADC_T ADC_B;

      
  
      
    
    
    
    
    
    
    
    /* Continuous states */
          X_ADC_T ADC_X;

      
      /* Block states (auto storage) */
                  DW_ADC_T ADC_DW;

          

  
	/* Real-time model */
          RT_MODEL_ADC_T ADC_M_;

          RT_MODEL_ADC_T *const ADC_M = &ADC_M_;




  


  


  /* Forward declaration for local functions */
    
             static real_T ADC_norm(const real_T x[3]);
      
    
             static real_T ADC_norm_l(const real_T x[3]);
      
    
             static void ADC_sind(real_T *x);
      
    
             static void ADC_cosd(real_T *x);
      
    
             static real_T ADC_norm_j(const real_T x[3]);
      
    
             static real_T ADC_norm_lw(const real_T x[3]);
      
    
             static real_T ADC_norm_p(const real_T x[3]);
      



  


    
  
  
     

  
    
    /* 
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */

        static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si , real_T arg_Magnetic_Measure[3], real_T arg_Euler_Angle_Measure[3], real_T arg_Sun_Measure[3], real_T arg_epoch[6], real_T arg_lla[3], real_T arg_v_[3], real_T *arg_S_flag, real_T arg_Magnetic_Dipole_Moment[3], real_T arg_q_est1[4])
    {
      time_T    t     = rtsiGetT(si);
      time_T    tnew  = rtsiGetSolverStopTime(si);
      time_T    h     = rtsiGetStepSize(si);
      real_T    *x    = rtsiGetContStates(si);
      ODE4_IntgData  *id   = (ODE4_IntgData *)rtsiGetSolverData(si);
      real_T    *y    = id->y;
      real_T    *f0   = id->f[0];
      real_T    *f1   = id->f[1];
      real_T    *f2   = id->f[2];
      real_T    *f3   = id->f[3];
      real_T    temp;
      int_T     i;
      int_T     nXc   = 6;
      
      rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
      
      
      /* Save the state values at time t in y, we'll use x as ynew. */
      (void) memcpy(y, x,
(uint_T)nXc*sizeof(real_T));
      
      /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
      /* f0 = f(t,y) */
      rtsiSetdX(si, f0);    
              ADC_derivatives(arg_Magnetic_Measure, arg_Euler_Angle_Measure, arg_Sun_Measure, arg_epoch, arg_lla, arg_v_, arg_S_flag, arg_Magnetic_Dipole_Moment, arg_q_est1);

      /* f1 = f(t + (h/2), y + (h/2)*f0) */
      temp = 0.5 * h;
      for (i = 0; i < nXc; i++) {
        x[i] = y[i] + (temp*f0[i]);
      }
      rtsiSetT(si, t + temp);
      rtsiSetdX(si, f1);
      
        
    

      ADC_custom(arg_Magnetic_Measure, arg_Euler_Angle_Measure, arg_Sun_Measure, arg_epoch, arg_lla, arg_v_, arg_S_flag, arg_Magnetic_Dipole_Moment, arg_q_est1);
  

              ADC_derivatives(arg_Magnetic_Measure, arg_Euler_Angle_Measure, arg_Sun_Measure, arg_epoch, arg_lla, arg_v_, arg_S_flag, arg_Magnetic_Dipole_Moment, arg_q_est1);

      
      /* f2 = f(t + (h/2), y + (h/2)*f1) */
      for (i = 0; i < nXc; i++) {
        x[i] = y[i] + (temp*f1[i]);
      }
      rtsiSetdX(si, f2);
      
        
    

      ADC_custom(arg_Magnetic_Measure, arg_Euler_Angle_Measure, arg_Sun_Measure, arg_epoch, arg_lla, arg_v_, arg_S_flag, arg_Magnetic_Dipole_Moment, arg_q_est1);
  

              ADC_derivatives(arg_Magnetic_Measure, arg_Euler_Angle_Measure, arg_Sun_Measure, arg_epoch, arg_lla, arg_v_, arg_S_flag, arg_Magnetic_Dipole_Moment, arg_q_est1);

      
      /* f3 = f(t + h, y + h*f2) */
      for (i = 0; i < nXc; i++) {
        x[i] = y[i] + (h*f2[i]);
      }
      rtsiSetT(si, tnew);
      rtsiSetdX(si, f3);
      
        
    

      ADC_custom(arg_Magnetic_Measure, arg_Euler_Angle_Measure, arg_Sun_Measure, arg_epoch, arg_lla, arg_v_, arg_S_flag, arg_Magnetic_Dipole_Moment, arg_q_est1);
  

              ADC_derivatives(arg_Magnetic_Measure, arg_Euler_Angle_Measure, arg_Sun_Measure, arg_epoch, arg_lla, arg_v_, arg_S_flag, arg_Magnetic_Dipole_Moment, arg_q_est1);

      
      /* tnew = t + h
      ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
      temp = h / 6.0;
      for (i = 0; i < nXc; i++) {
	x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
      }
      
      

      rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
      
    }
    
  
    
  
  
        
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

  

          
              
    
        
    /* Function for MATLAB Function: '<S1>/Decision' */

    
        
    static real_T ADC_norm(const real_T x[3])
    {
          real_T y;
real_T scale;
real_T absxk;
real_T t;
scale = 2.2250738585072014E-308;
absxk = fabs(x[0]);
if (absxk > 2.2250738585072014E-308) {
    y = 1.0;
    scale = absxk;
} else {
    t = absxk / 2.2250738585072014E-308;
    y = t * t;
}
absxk = fabs(x[1]);
if (absxk > scale) {
    t = scale / absxk;
    y = 1.0 + y * t * t;
    scale = absxk;
} else {
    t = absxk / scale;
    y += t * t;
}
absxk = fabs(x[2]);
if (absxk > scale) {
    t = scale / absxk;
    y = 1.0 + y * t * t;
    scale = absxk;
} else {
    t = absxk / scale;
    y += t * t;
}
return scale * sqrt(y);


    }
    

    

        
              
    
        
    /* Function for MATLAB Function: '<S6>/PD Controler' */

    
        
    static real_T ADC_norm_l(const real_T x[3])
    {
          real_T y;
real_T scale;
real_T absxk;
real_T t;
scale = 2.2250738585072014E-308;
absxk = fabs(x[0]);
if (absxk > 2.2250738585072014E-308) {
    y = 1.0;
    scale = absxk;
} else {
    t = absxk / 2.2250738585072014E-308;
    y = t * t;
}
absxk = fabs(x[1]);
if (absxk > scale) {
    t = scale / absxk;
    y = 1.0 + y * t * t;
    scale = absxk;
} else {
    t = absxk / scale;
    y += t * t;
}
absxk = fabs(x[2]);
if (absxk > scale) {
    t = scale / absxk;
    y = 1.0 + y * t * t;
    scale = absxk;
} else {
    t = absxk / scale;
    y += t * t;
}
return scale * sqrt(y);


    }
    

    

      
        
              
    
        
        
     

    
        
     real_T rt_powd_snf(real_T u0, real_T u1)
    {
          real_T y;
real_T tmp;
real_T tmp_0;
if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
} else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
        if (tmp == 1.0) {
            y = (rtNaN);
        } else if (tmp > 1.0) {
            if (u1 > 0.0) {
                y = (rtInf);
            } else {
                y = 0.0;
            }
        } else if (u1 > 0.0) {
            y = 0.0;
        } else {
            y = (rtInf);
        }
    } else if (tmp_0 == 0.0) {
        y = 1.0;
    } else if (tmp_0 == 1.0) {
        if (u1 > 0.0) {
            y = u0;
        } else {
            y = 1.0 / u0;
        }
    } else if (u1 == 2.0) {
        y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
        y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
        y = (rtNaN);
    } else {
        y = pow(u0, u1);
    }
}
return y;


    }
    

    

      
        
              
    
        
        
     

    
        
     real_T rt_roundd_snf(real_T u)
    {
          real_T y;
if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
        y = floor(u + 0.5);
    } else if (u > -0.5) {
        y = u * 0.0;
    } else {
        y = ceil(u - 0.5);
    }
} else {
    y = u;
}
return y;


    }
    

    

      
        
              
    
        
        
     

    
        
     real_T rt_remd_snf(real_T u0, real_T u1)
    {
          real_T y;
real_T u1_0;
if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf(u1))))) {
    y = (rtNaN);
} else {
    if (u1 < 0.0) {
        u1_0 = ceil(u1);
    } else {
        u1_0 = floor(u1);
    }
    if ((u1 != 0.0) && (u1 != u1_0)) {
        u1_0 = u0 / u1;
        if (fabs(u1_0 - rt_roundd_snf(u1_0)) <= DBL_EPSILON * fabs(u1_0)) {
            y = 0.0;
        } else {
            y = fmod(u0, u1);
        }
    } else {
        y = fmod(u0, u1);
    }
}
return y;


    }
    

    

        
              
    
        
    /* Function for MATLAB Function: '<Root>/lla2eci' */

    
        
    static void ADC_sind(real_T *x)
    {
          int8_T n;
real_T c_x;
real_T absx;

if (!((!rtIsInf(*x)) && (!rtIsNaN(*x)))) {
    c_x = (rtNaN);
} else {


    c_x = rt_remd_snf(*x, 360.0);
    absx = fabs(c_x);
    if (absx > 180.0) {
        if (c_x > 0.0) {
            c_x -= 360.0;
        } else {
            c_x += 360.0;
        }
        absx = fabs(c_x);
    }
    if (absx <= 45.0) {
        c_x *= 0.017453292519943295;
        n = 0;
    } else if (absx <= 135.0) {
        if (c_x > 0.0) {
            c_x = 0.017453292519943295 * (c_x - 90.0);
            n = 1;
        } else {
            c_x = 0.017453292519943295 * (c_x + 90.0);
            n = -1;
        }
    } else if (c_x > 0.0) {
        c_x = 0.017453292519943295 * (c_x - 180.0);
        n = 2;
    } else {
        c_x = 0.017453292519943295 * (c_x + 180.0);
        n = -2;
    }
    if (n == 0) {
        c_x = sin(c_x);
    } else if (n == 1) {
        c_x = cos(c_x);
    } else if (n == -1) {
        c_x = -cos(c_x);
    } else {
        c_x = -sin(c_x);
    }
}
*x = c_x;


    }
    

    

        
              
    
        
    /* Function for MATLAB Function: '<Root>/lla2eci' */

    
        
    static void ADC_cosd(real_T *x)
    {
          int8_T n;
real_T b_x;
real_T absx;

if (!((!rtIsInf(*x)) && (!rtIsNaN(*x)))) {
    *x = (rtNaN);
} else {


    b_x = rt_remd_snf(*x, 360.0);
    absx = fabs(b_x);
    if (absx > 180.0) {
        if (b_x > 0.0) {
            b_x -= 360.0;
        } else {
            b_x += 360.0;
        }
        absx = fabs(b_x);
    }
    if (absx <= 45.0) {
        b_x *= 0.017453292519943295;
        n = 0;
    } else if (absx <= 135.0) {
        if (b_x > 0.0) {
            b_x = 0.017453292519943295 * (b_x - 90.0);
            n = 1;
        } else {
            b_x = 0.017453292519943295 * (b_x + 90.0);
            n = -1;
        }
    } else if (b_x > 0.0) {
        b_x = 0.017453292519943295 * (b_x - 180.0);
        n = 2;
    } else {
        b_x = 0.017453292519943295 * (b_x + 180.0);
        n = -2;
    }
    if (n == 0) {
        *x = cos(b_x);
    } else if (n == 1) {
        *x = -sin(b_x);
    } else if (n == -1) {
        *x = sin(b_x);
    } else {
        *x = -cos(b_x);
    }
}


    }
    

    

        
              
    
        
    /* Function for MATLAB Function: '<S20>/Calculator' */

    
        
    static real_T ADC_norm_j(const real_T x[3])
    {
          real_T y;
real_T scale;
real_T absxk;
real_T t;
scale = 2.2250738585072014E-308;
absxk = fabs(x[0]);
if (absxk > 2.2250738585072014E-308) {
    y = 1.0;
    scale = absxk;
} else {
    t = absxk / 2.2250738585072014E-308;
    y = t * t;
}
absxk = fabs(x[1]);
if (absxk > scale) {
    t = scale / absxk;
    y = 1.0 + y * t * t;
    scale = absxk;
} else {
    t = absxk / scale;
    y += t * t;
}
absxk = fabs(x[2]);
if (absxk > scale) {
    t = scale / absxk;
    y = 1.0 + y * t * t;
    scale = absxk;
} else {
    t = absxk / scale;
    y += t * t;
}
return scale * sqrt(y);


    }
    

    

        
              
    
        
    /* Function for MATLAB Function: '<S2>/MATLAB Function1' */

    
        
    static real_T ADC_norm_lw(const real_T x[3])
    {
          real_T y;
real_T scale;
real_T absxk;
real_T t;
scale = 2.2250738585072014E-308;
absxk = fabs(x[0]);
if (absxk > 2.2250738585072014E-308) {
    y = 1.0;
    scale = absxk;
} else {
    t = absxk / 2.2250738585072014E-308;
    y = t * t;
}
absxk = fabs(x[1]);
if (absxk > scale) {
    t = scale / absxk;
    y = 1.0 + y * t * t;
    scale = absxk;
} else {
    t = absxk / scale;
    y += t * t;
}
absxk = fabs(x[2]);
if (absxk > scale) {
    t = scale / absxk;
    y = 1.0 + y * t * t;
    scale = absxk;
} else {
    t = absxk / scale;
    y += t * t;
}
return scale * sqrt(y);


    }
    

    

        
              
    
        
    /* Function for MATLAB Function: '<S2>/ LVLH ' */

    
        
    static real_T ADC_norm_p(const real_T x[3])
    {
          real_T y;
real_T scale;
real_T absxk;
real_T t;
scale = 2.2250738585072014E-308;
absxk = fabs(x[0]);
if (absxk > 2.2250738585072014E-308) {
    y = 1.0;
    scale = absxk;
} else {
    t = absxk / 2.2250738585072014E-308;
    y = t * t;
}
absxk = fabs(x[1]);
if (absxk > scale) {
    t = scale / absxk;
    y = 1.0 + y * t * t;
    scale = absxk;
} else {
    t = absxk / scale;
    y += t * t;
}
absxk = fabs(x[2]);
if (absxk > scale) {
    t = scale / absxk;
    y = 1.0 + y * t * t;
    scale = absxk;
} else {
    t = absxk / scale;
    y += t * t;
}
return scale * sqrt(y);


    }
    

    


  
    
      
    
    
    /* Model step function */
            void ADC_custom(real_T arg_Magnetic_Measure[3], real_T arg_Euler_Angle_Measure[3], real_T arg_Sun_Measure[3], real_T arg_epoch[6], real_T arg_lla[3], real_T arg_v_[3], real_T *arg_S_flag, real_T arg_Magnetic_Dipole_Moment[3], real_T arg_q_est1[4])   
    {
            


      
      
      
      
            
                  /* local block i/o variables */
        	
              real_T rtb_Clock;


	


        boolean_T guard1 = false;
int32_T k;
static const real_T a[9] = { 1.57407015004541E-8, 0.0, 0.0, 0.0, 1.18055261253406E-8, 0.0, 0.0, 0.0, 1.68650373219151E-9 };
static const real_T b[18] = { 1015.8163712302, 7.60272150440681E-14, 453.958044168675, 8.04611892244142E-14, 1186.23970592244, -1.67413778929006E-14, -453.958044168676, -2.35978593865247E-13, 600.766687834337, 384003.046505704, 1.08705332006039E-11, -20043.8129028358, 1.44940442674718E-11, 448289.486640409, 1.35573181939759E-11, -187075.587093135, 9.49012273578315E-11, 795987.850800695 };
static const real_T b_a[18] = { -1015.8163712302, -7.60272150440681E-14, -453.958044168675, -8.04611892244142E-14, -1186.23970592244, 1.67413778929006E-14, 453.958044168676, 2.35978593865247E-13, -600.766687834337, -384003.046505704, -1.08705332006039E-11, 20043.8129028358, -1.44940442674718E-11, -448289.486640409, -1.35573181939759E-11, 187075.587093135, -9.49012273578315E-11, -795987.850800695 };
static const real_T b_a_0[9] = { 0.00018667619023324857, 0.0, 0.0, 0.0, 0.00031112698372208096, 0.0, 0.0, 0.0, 0.00043557777721091334 };
static const real_T b_b[9] = { 0.06, 0.0, 0.0, 0.0, 0.1, 0.0, 0.0, 0.0, 0.14 };
static const int8_T b_0[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };
boolean_T c[6];
int32_T i;
int32_T b_sizes;
real_T z_idx_0;

        
        
        
    






            UNUSED_PARAMETER(arg_v_);







      

        
  



            
         
      if (rtmIsMajorTimeStep(ADC_M)) {
        
      /* set solver stop time */
    if (!(ADC_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ADC_M->solverInfo, ((ADC_M->Timing.clockTickH0 + 1) * ADC_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ADC_M->solverInfo, ((ADC_M->Timing.clockTick0  + 1) * ADC_M->Timing.stepSize0 + ADC_M->Timing.clockTickH0 * ADC_M->Timing.stepSize0 * 4294967296.0));
    }

  
  

      } /* end MajorTimeStep */
    /* Update absolute time of base rate at minor time step */
    if (rtmIsMinorTimeStep(ADC_M)) {
      ADC_M->Timing.t[0] = rtsiGetT(&ADC_M->solverInfo);
    } 
      

    

      
      
        
  



                          
                

      
/* Clock: '<S5>/Clock' */          rtb_Clock = ADC_M->Timing.t[0];

   
        
if (rtmIsMajorTimeStep(ADC_M)) {
    /* Memory: '<S1>/Memory' */
    ADC_B.Memory[0] = ADC_DW.Memory_PreviousInput[0];
    ADC_B.Memory[1] = ADC_DW.Memory_PreviousInput[1];
    ADC_B.Memory[2] = ADC_DW.Memory_PreviousInput[2];
}
/* MATLAB Function: '<S1>/Decision' incorporates:
 *  Inport: '<Root>/Euler Angle Measure'
 *  Inport: '<Root>/Magnetic Measure'
 */
/* MATLAB Function 'Controller/Decision': '<S4>:1' */
/* B is output to Detumbler, B1 is output to Pointing Control */
/* '<S4>:1:3' */


if (fabs(ADC_norm(arg_Euler_Angle_Measure)) >= 0.01) {
    /* '<S4>:1:4' */
    guard1 = true;
} else {
    ADC_B.u_b[0] = arg_Magnetic_Measure[0] - ADC_B.Memory[0];
    ADC_B.u_b[1] = arg_Magnetic_Measure[1] - ADC_B.Memory[1];
    ADC_B.u_b[2] = arg_Magnetic_Measure[2] - ADC_B.Memory[2];


    if (ADC_norm(ADC_B.u_b) / ADC_norm(arg_Magnetic_Measure) > 0.05) {
        /* '<S4>:1:4' */
        guard1 = true;
    } else {
        /* '<S4>:1:8' */
        /* '<S4>:1:9' */
        ADC_B.B_e[0] = 0.0;
        ADC_B.B1[0] = arg_Magnetic_Measure[0];
        ADC_B.B_e[1] = 0.0;
        ADC_B.B1[1] = arg_Magnetic_Measure[1];
        ADC_B.B_e[2] = 0.0;
        ADC_B.B1[2] = arg_Magnetic_Measure[2];
        /* '<S4>:1:10' */
    }
}
if (guard1) {
    /* '<S4>:1:5' */
    /* '<S4>:1:6' */
    ADC_B.B_e[0] = arg_Magnetic_Measure[0];
    ADC_B.B1[0] = 0.0;
    ADC_B.B_e[1] = arg_Magnetic_Measure[1];
    ADC_B.B1[1] = 0.0;
    ADC_B.B_e[2] = arg_Magnetic_Measure[2];
    ADC_B.B1[2] = 0.0;
}
/* End of MATLAB Function: '<S1>/Decision' */

/* MATLAB Function: '<S5>/MATLAB Function' */
/* MATLAB Function 'Controller/Detumble /MATLAB Function': '<S8>:1' */
/* '<S8>:1:5' */
ADC_B.time_diff = 1.0;
ADC_B.scale = 2.2250738585072014E-308;
ADC_B.M = fabs(ADC_B.B_e[0]);
if (ADC_B.M > 2.2250738585072014E-308) {
    ADC_B.G0 = 1.0;
    ADC_B.scale = ADC_B.M;
} else {
    ADC_B.E = ADC_B.M / 2.2250738585072014E-308;
    ADC_B.G0 = ADC_B.E * ADC_B.E;
}
ADC_B.M = fabs(ADC_B.B_e[1]);
if (ADC_B.M > ADC_B.scale) {
    ADC_B.E = ADC_B.scale / ADC_B.M;
    ADC_B.G0 = 1.0 + ADC_B.G0 * ADC_B.E * ADC_B.E;
    ADC_B.scale = ADC_B.M;
} else {
    ADC_B.E = ADC_B.M / ADC_B.scale;
    ADC_B.G0 += ADC_B.E * ADC_B.E;
}
ADC_B.M = fabs(ADC_B.B_e[2]);
if (ADC_B.M > ADC_B.scale) {
    ADC_B.E = ADC_B.scale / ADC_B.M;
    ADC_B.G0 = 1.0 + ADC_B.G0 * ADC_B.E * ADC_B.E;
    ADC_B.scale = ADC_B.M;
} else {
    ADC_B.E = ADC_B.M / ADC_B.scale;
    ADC_B.G0 += ADC_B.E * ADC_B.E;
}
ADC_B.G0 = ADC_B.scale * sqrt(ADC_B.G0);
if (ADC_B.G0 > 0.0) {
    /* '<S8>:1:12' */
    /* '<S8>:1:13' */
    ADC_DW.times[(int32_T)ADC_DW.counter - 1] = rtb_Clock;
    if (ADC_DW.counter > 1.0) {
        /* '<S8>:1:14' */
        /* '<S8>:1:15' */
        ADC_B.time_diff = ADC_DW.times[(int32_T)ADC_DW.counter - 1] - ADC_DW.times[(int32_T)(ADC_DW.counter - 1.0) - 1];
    }
    if (ADC_B.time_diff >= 1.0) {
        /* '<S8>:1:17' */
        /* '<S8>:1:18' */
        ADC_B.time_diff = 0.0;
    } else {
        /* '<S8>:1:20' */
        ADC_B.time_diff = 1.0;
        /*          counter=1; */
        if (ADC_DW.counter == 1.0E+6) {
            /* '<S8>:1:23' */
            /* '<S8>:1:24' */
            ADC_DW.counter = 1.0;
            /* '<S8>:1:25' */
            memset(&ADC_DW.times[0], 0, 1000000U * sizeof(real_T));
        }
    }
    /* '<S8>:1:29' */
    ADC_DW.counter++;
} else {
    /* '<S8>:1:31' */
    ADC_B.time_diff = 0.0;
}
/* End of MATLAB Function: '<S5>/MATLAB Function' */
if (rtmIsMajorTimeStep(ADC_M)) {
    /* SampleTimeMath: '<S7>/TSamp' incorporates:
 *  Product: '<S5>/Product4'
 *
 * About '<S7>/TSamp':
 *  y = u * K where K = 1 / ( w * Ts )
 */
    ADC_B.TSamp[0] = ADC_B.time_diff * ADC_B.B_e[0] * ADC_P.TSamp_WtEt;
    /* Gain: '<S5>/Gain' incorporates:
 *  Sum: '<S7>/Diff'
 *  UnitDelay: '<S7>/UD'
 */
    ADC_B.B_e[0] = ADC_P.Gain_Gain * (ADC_B.TSamp[0] - ADC_DW.UD_DSTATE[0]);
    /* SampleTimeMath: '<S7>/TSamp' incorporates:
 *  Product: '<S5>/Product4'
 *
 * About '<S7>/TSamp':
 *  y = u * K where K = 1 / ( w * Ts )
 */
    ADC_B.TSamp[1] = ADC_B.time_diff * ADC_B.B_e[1] * ADC_P.TSamp_WtEt;
    /* Gain: '<S5>/Gain' incorporates:
 *  Sum: '<S7>/Diff'
 *  UnitDelay: '<S7>/UD'
 */
    ADC_B.B_e[1] = ADC_P.Gain_Gain * (ADC_B.TSamp[1] - ADC_DW.UD_DSTATE[1]);
    /* SampleTimeMath: '<S7>/TSamp' incorporates:
 *  Product: '<S5>/Product4'
 *
 * About '<S7>/TSamp':
 *  y = u * K where K = 1 / ( w * Ts )
 */
    ADC_B.TSamp[2] = ADC_B.time_diff * ADC_B.B_e[2] * ADC_P.TSamp_WtEt;
    /* Gain: '<S5>/Gain' incorporates:
 *  Sum: '<S7>/Diff'
 *  UnitDelay: '<S7>/UD'
 */
    ADC_B.rtb_B_e_d = ADC_P.Gain_Gain * (ADC_B.TSamp[2] - ADC_DW.UD_DSTATE[2]);
    ADC_B.B_e[2] = ADC_P.Gain_Gain * (ADC_B.TSamp[2] - ADC_DW.UD_DSTATE[2]);
    /* MATLAB Function: '<S5>/saturator and power monitor' */
    /* MATLAB Function 'Controller/Detumble /saturator and power monitor': '<S9>:1' */
    /* '<S9>:1:5' */
    /* '<S9>:1:4' */
    /* '<S9>:1:5' */
    /* '<S9>:1:7' */
    /* Saturator */
    if (fabs(ADC_B.B_e[0]) > 0.2) {
        /* '<S9>:1:11' */
        /* '<S9>:1:12' */
        if (ADC_B.B_e[0] < 0.0) {
            ADC_B.rtb_m_idx_0 = -1.0;
        } else if (ADC_B.B_e[0] > 0.0) {
            ADC_B.rtb_m_idx_0 = 1.0;
        } else if (ADC_B.B_e[0] == 0.0) {
            ADC_B.rtb_m_idx_0 = 0.0;
        } else {
            ADC_B.rtb_m_idx_0 = ADC_B.B_e[0];
        }
        ADC_B.m[0] = 0.2 * ADC_B.rtb_m_idx_0;
    } else {
        /* '<S9>:1:14' */
        ADC_B.m[0] = ADC_B.B_e[0];
    }
    if (fabs(ADC_B.B_e[1]) > 0.2) {
        /* '<S9>:1:17' */
        /* '<S9>:1:18' */
        if (ADC_B.B_e[1] < 0.0) {
            ADC_B.rtb_m_idx_0 = -1.0;
        } else if (ADC_B.B_e[1] > 0.0) {
            ADC_B.rtb_m_idx_0 = 1.0;
        } else if (ADC_B.B_e[1] == 0.0) {
            ADC_B.rtb_m_idx_0 = 0.0;
        } else {
            ADC_B.rtb_m_idx_0 = ADC_B.B_e[1];
        }
        ADC_B.m[1] = 0.2 * ADC_B.rtb_m_idx_0;
    } else {
        /* '<S9>:1:20' */
        ADC_B.m[1] = ADC_B.B_e[1];
    }
    if (fabs(ADC_B.rtb_B_e_d) > 0.2) {
        /* '<S9>:1:23' */
        /* '<S9>:1:24' */
        if (ADC_B.rtb_B_e_d < 0.0) {
            ADC_B.rtb_B_e_d = -1.0;
        } else if (ADC_B.rtb_B_e_d > 0.0) {
            ADC_B.rtb_B_e_d = 1.0;
        } else {
            if (ADC_B.rtb_B_e_d == 0.0) {
                ADC_B.rtb_B_e_d = 0.0;
            }
        }
        ADC_B.m[2] = 0.2 * ADC_B.rtb_B_e_d;
    } else {
        /* '<S9>:1:26' */
        ADC_B.m[2] = ADC_B.rtb_B_e_d;
    }
    /* End of MATLAB Function: '<S5>/saturator and power monitor' */

    /* Constant: '<S17>/X0' */
    /* Power Monitor */
    /* '<S9>:1:29' */
    /* '<S9>:1:30' */
    for (i = 0; i < 6; i++) {
        ADC_B.X0[i] = ADC_P.X0_Value[i];
    }
    /* End of Constant: '<S17>/X0' */
}
/* Integrator: '<S17>/MemoryX' */
if (ADC_DW.MemoryX_IWORK != 0) {
    for (i = 0; i < 6; i++) {
        ADC_X.MemoryX_CSTATE[i] = ADC_B.X0[i];
    }
}
/* MATLAB Function: '<S6>/LQR Controller' incorporates:
 *  Integrator: '<S17>/MemoryX'
 */
/* MATLAB Function 'Controller/Pointing/LQR Controller': '<S10>:1' */
/* '<S10>:1:4' */
/* '<S10>:1:3' */
/* '<S10>:1:11' */
/* '<S10>:1:10' */
/* '<S10>:1:9' */
/* maximum magnetic moment */
/* '<S10>:1:3' */
/* '<S10>:1:4' */
/* '<S10>:1:5' */
/*  Main Controller */
/* '<S10>:1:9' */
/* '<S10>:1:39' */
ADC_B.u[0] = 0.0;
ADC_B.u[3] = -ADC_B.B1[2];
ADC_B.u[6] = ADC_B.B1[1];
ADC_B.u[1] = ADC_B.B1[2];
ADC_B.u[4] = 0.0;
ADC_B.u[7] = -ADC_B.B1[0];
ADC_B.u[2] = -ADC_B.B1[1];
ADC_B.u[5] = ADC_B.B1[0];
ADC_B.u[8] = 0.0;
for (i = 0; i < 3; i++) {
    ADC_B.u_c[3 * i] = -ADC_B.u[3 * i];
    ADC_B.u_c[1 + 3 * i] = -ADC_B.u[1 + 3 * i];
    ADC_B.u_c[2 + 3 * i] = -ADC_B.u[2 + 3 * i];
}
for (i = 0; i < 3; i++) {
    for (b_sizes = 0; b_sizes < 6; b_sizes++) {
        ADC_B.dv0[i + 3 * b_sizes] = 0.0;
        ADC_B.dv0[i + 3 * b_sizes] += ADC_B.u_c[i] * b[3 * b_sizes];
        ADC_B.dv0[i + 3 * b_sizes] += ADC_B.u_c[i + 3] * b[1 + 3 * b_sizes];
        ADC_B.dv0[i + 3 * b_sizes] += ADC_B.u_c[i + 6] * b[2 + 3 * b_sizes];
    }
}
for (i = 0; i < 3; i++) {
    ADC_B.B_e[i] = 0.0;
    for (b_sizes = 0; b_sizes < 6; b_sizes++) {
        ADC_B.B_e[i] += ADC_B.dv0[i + 3 * b_sizes] * ADC_X.MemoryX_CSTATE[b_sizes];
    }
}
/* '<S10>:1:10' */
/* '<S10>:1:11' */
/* Saturator */
if (fabs(ADC_B.B_e[0]) > 0.2) {
    /* '<S10>:1:14' */
    /* '<S10>:1:15' */
    if (ADC_B.B_e[0] < 0.0) {
        ADC_B.rtb_B_e_d = -1.0;
    } else if (ADC_B.B_e[0] > 0.0) {
        ADC_B.rtb_B_e_d = 1.0;
    } else if (ADC_B.B_e[0] == 0.0) {
        ADC_B.rtb_B_e_d = 0.0;
    } else {
        ADC_B.rtb_B_e_d = ADC_B.B_e[0];
    }
    ADC_B.m_g[0] = 0.2 * ADC_B.rtb_B_e_d;
} else {
    /* '<S10>:1:17' */
    ADC_B.m_g[0] = ADC_B.B_e[0];
}
if (fabs(ADC_B.B_e[1]) > 0.2) {
    /* '<S10>:1:20' */
    /* '<S10>:1:21' */
    if (ADC_B.B_e[1] < 0.0) {
        ADC_B.rtb_B_e_d = -1.0;
    } else if (ADC_B.B_e[1] > 0.0) {
        ADC_B.rtb_B_e_d = 1.0;
    } else if (ADC_B.B_e[1] == 0.0) {
        ADC_B.rtb_B_e_d = 0.0;
    } else {
        ADC_B.rtb_B_e_d = ADC_B.B_e[1];
    }
    ADC_B.m_g[1] = 0.2 * ADC_B.rtb_B_e_d;
} else {
    /* '<S10>:1:23' */
    ADC_B.m_g[1] = ADC_B.B_e[1];
}
if (fabs(ADC_B.B_e[2]) > 0.2) {
    /* '<S10>:1:26' */
    /* '<S10>:1:27' */
    if (ADC_B.B_e[2] < 0.0) {
        ADC_B.rtb_B_e_d = -1.0;
    } else if (ADC_B.B_e[2] > 0.0) {
        ADC_B.rtb_B_e_d = 1.0;
    } else if (ADC_B.B_e[2] == 0.0) {
        ADC_B.rtb_B_e_d = 0.0;
    } else {
        ADC_B.rtb_B_e_d = ADC_B.B_e[2];
    }
    ADC_B.m_g[2] = 0.2 * ADC_B.rtb_B_e_d;
} else {
    /* '<S10>:1:29' */
    ADC_B.m_g[2] = ADC_B.B_e[2];
}
/* MATLAB Function: '<S6>/PD Controler' incorporates:
 *  Inport: '<Root>/Euler Angle Measure'
 *  Integrator: '<S17>/MemoryX'
 */
/* Power Monitor */
/* '<S10>:1:32' */
/* '<S10>:1:33' */
/* MATLAB Function 'Controller/Pointing/PD Controler': '<S11>:1' */
/* '<S11>:1:4' */
/* '<S11>:1:3' */
/* '<S11>:1:18' */
/* '<S11>:1:26' */
/* maximum magnetic moment */
/* '<S11>:1:3' */
/* '<S11>:1:4' */
/* '<S11>:1:5' */
/* Full Mule */
/* centroidal moment of inertia sans reaction wheel system (kg-m^2) */
/* '<S11>:1:15' */
ADC_B.B_e[0] = arg_Euler_Angle_Measure[0];
ADC_B.B_e[1] = arg_Euler_Angle_Measure[1] + 0.0011;
ADC_B.B_e[2] = arg_Euler_Angle_Measure[2];
/*  Main PID Controller */
/* '<S11>:1:18' */
/* '<S11>:1:19' */
/* '<S11>:1:63' */
/*  from Wie et. al */
/* '<S11>:1:26' */
ADC_B.u_k[0] = 0.0;
ADC_B.u_k[3] = -arg_Euler_Angle_Measure[2];
ADC_B.u_k[6] = arg_Euler_Angle_Measure[1] + 0.0011;
ADC_B.u_k[1] = arg_Euler_Angle_Measure[2];
ADC_B.u_k[4] = 0.0;
ADC_B.u_k[7] = -arg_Euler_Angle_Measure[0];
ADC_B.u_k[2] = -(arg_Euler_Angle_Measure[1] + 0.0011);
ADC_B.u_k[5] = arg_Euler_Angle_Measure[0];
ADC_B.u_k[8] = 0.0;
for (i = 0; i < 3; i++) {
    ADC_B.u[3 * i] = -ADC_B.u_k[3 * i];
    ADC_B.u[1 + 3 * i] = -ADC_B.u_k[1 + 3 * i];
    ADC_B.u[2 + 3 * i] = -ADC_B.u_k[2 + 3 * i];
}
for (i = 0; i < 3; i++) {
    for (b_sizes = 0; b_sizes < 3; b_sizes++) {
        ADC_B.u_c[i + 3 * b_sizes] = 0.0;
        ADC_B.u_c[i + 3 * b_sizes] += ADC_B.u[i] * b_b[3 * b_sizes];
        ADC_B.u_c[i + 3 * b_sizes] += ADC_B.u[i + 3] * b_b[1 + 3 * b_sizes];
        ADC_B.u_c[i + 3 * b_sizes] += ADC_B.u[i + 6] * b_b[2 + 3 * b_sizes];
    }
}
for (i = 0; i < 3; i++) {
    ADC_B.u_b[i] = (((ADC_B.u_c[i] * ADC_B.B_e[0] + ADC_B.u_c[i + 3] * ADC_B.B_e[1]) + ADC_B.u_c[i + 6] * ADC_B.B_e[2]) - ((b_a_0[i] * ADC_B.B_e[0] + b_a_0[i + 3] * ADC_B.B_e[1]) + b_a_0[i + 6] * ADC_B.B_e[2])) - ((0.0 * ADC_X.MemoryX_CSTATE[0] + 0.0 * ADC_X.MemoryX_CSTATE[1]) + 0.0 * ADC_X.MemoryX_CSTATE[2]);
}
if (ADC_norm_l(ADC_B.B1) > 0.0) {
    /* '<S11>:1:28' */
    /* '<S11>:1:29' */
    ADC_B.time_diff = ADC_norm_l(ADC_B.B1);
    ADC_B.time_diff *= ADC_B.time_diff;
    ADC_B.B_e[0] = (ADC_B.B1[1] * ADC_B.u_b[2] - ADC_B.B1[2] * ADC_B.u_b[1]) / ADC_B.time_diff;
    ADC_B.B_e[1] = (ADC_B.B1[2] * ADC_B.u_b[0] - ADC_B.B1[0] * ADC_B.u_b[2]) / ADC_B.time_diff;
    ADC_B.B_e[2] = (ADC_B.B1[0] * ADC_B.u_b[1] - ADC_B.B1[1] * ADC_B.u_b[0]) / ADC_B.time_diff;
} else {
    /* '<S11>:1:31' */
    ADC_B.B_e[0] = 0.0;
    ADC_B.B_e[1] = 0.0;
    ADC_B.B_e[2] = 0.0;
}
/* Saturator */
if (fabs(ADC_B.B_e[0]) > 0.2) {
    /* '<S11>:1:35' */
    /* '<S11>:1:36' */
    if (ADC_B.B_e[0] < 0.0) {
        ADC_B.rtb_B_e_d = -1.0;
    } else if (ADC_B.B_e[0] > 0.0) {
        ADC_B.rtb_B_e_d = 1.0;
    } else if (ADC_B.B_e[0] == 0.0) {
        ADC_B.rtb_B_e_d = 0.0;
    } else {
        ADC_B.rtb_B_e_d = ADC_B.B_e[0];
    }
    ADC_B.rtb_m_idx_0 = 0.2 * ADC_B.rtb_B_e_d;
} else {
    /* '<S11>:1:38' */
    ADC_B.rtb_m_idx_0 = ADC_B.B_e[0];
}
if (fabs(ADC_B.B_e[1]) > 0.2) {
    /* '<S11>:1:41' */
    /* '<S11>:1:42' */
    if (ADC_B.B_e[1] < 0.0) {
        ADC_B.rtb_B_e_d = -1.0;
    } else if (ADC_B.B_e[1] > 0.0) {
        ADC_B.rtb_B_e_d = 1.0;
    } else if (ADC_B.B_e[1] == 0.0) {
        ADC_B.rtb_B_e_d = 0.0;
    } else {
        ADC_B.rtb_B_e_d = ADC_B.B_e[1];
    }
    ADC_B.rtb_m_idx_1 = 0.2 * ADC_B.rtb_B_e_d;
} else {
    /* '<S11>:1:44' */
    ADC_B.rtb_m_idx_1 = ADC_B.B_e[1];
}
if (fabs(ADC_B.B_e[2]) > 0.2) {
    /* '<S11>:1:47' */
    /* '<S11>:1:48' */
    if (ADC_B.B_e[2] < 0.0) {
        ADC_B.rtb_B_e_d = -1.0;
    } else if (ADC_B.B_e[2] > 0.0) {
        ADC_B.rtb_B_e_d = 1.0;
    } else if (ADC_B.B_e[2] == 0.0) {
        ADC_B.rtb_B_e_d = 0.0;
    } else {
        ADC_B.rtb_B_e_d = ADC_B.B_e[2];
    }
    ADC_B.rtb_m_idx_2 = 0.2 * ADC_B.rtb_B_e_d;
} else {
    /* '<S11>:1:50' */
    ADC_B.rtb_m_idx_2 = ADC_B.B_e[2];
}
/* Switch: '<S6>/Switch' incorporates:
 *  Inport: '<Root>/S_flag'
 */
/* Power Monitor */
/* '<S11>:1:53' */
/* '<S11>:1:54' */
/*  control torque */
/* '<S11>:1:57' */
if (*arg_S_flag > ADC_P.Switch_Threshold) {
    ADC_B.time_diff = ADC_B.m_g[0];
} else {
    ADC_B.time_diff = ADC_B.rtb_m_idx_0;
}
/* Outport: '<Root>/Magnetic Dipole Moment' incorporates:
 *  Sum: '<S1>/Sum'
 */
arg_Magnetic_Dipole_Moment[0] = ADC_B.m[0] + ADC_B.time_diff;
/* Switch: '<S6>/Switch' incorporates:
 *  Inport: '<Root>/S_flag'
 */
if (*arg_S_flag > ADC_P.Switch_Threshold) {
    ADC_B.time_diff = ADC_B.m_g[1];
} else {
    ADC_B.time_diff = ADC_B.rtb_m_idx_1;
}
/* Outport: '<Root>/Magnetic Dipole Moment' incorporates:
 *  Sum: '<S1>/Sum'
 */
arg_Magnetic_Dipole_Moment[1] = ADC_B.m[1] + ADC_B.time_diff;
/* Switch: '<S6>/Switch' incorporates:
 *  Inport: '<Root>/S_flag'
 */
if (*arg_S_flag > ADC_P.Switch_Threshold) {
    ADC_B.time_diff = ADC_B.m_g[2];
} else {
    ADC_B.time_diff = ADC_B.rtb_m_idx_2;
}
/* Outport: '<Root>/Magnetic Dipole Moment' incorporates:
 *  Sum: '<S1>/Sum'
 */
arg_Magnetic_Dipole_Moment[2] = ADC_B.m[2] + ADC_B.time_diff;
/* MATLAB Function: '<Root>/lla2eci' incorporates:
 *  Inport: '<Root>/epoch'
 *  Inport: '<Root>/lla'
 */
/* MATLAB Function 'lla2eci': '<S3>:1' */
/*  lla = [lat(deg),lon(deg),alt(m)] */
/* '<S3>:1:3' */
/* '<S3>:1:4' */
/* '<S3>:1:5' */
/* Compute the Julian Date (JD) from a Gregorian Date (UT1) input */
/* '<S3>:1:9' */
/* (year) */
/* '<S3>:1:10' */
/* (month) */
/* '<S3>:1:11' */
/* (day) */
/* '<S3>:1:12' */
/* (hr) */
/* '<S3>:1:13' */
/* (min) */
/* '<S3>:1:14' */
/* (sec) */
/* '<S3>:1:15' */
/* (JD) */
/* Compute the Universal Time (UT) from JD */
/* '<S3>:1:18' */
ADC_B.time_diff = ((((((367.0 * arg_epoch[0] - floor(1.75 * (arg_epoch[0] + floor((arg_epoch[1] + 9.0) / 12.0)))) + floor(275.0 * arg_epoch[1] / 9.0)) + arg_epoch[2]) + 1.7210135E+6) + ((arg_epoch[5] / 60.0 + arg_epoch[4]) / 60.0 + arg_epoch[3]) / 24.0) - 2.451545E+6) / 36525.0;
/* Compute the Greenwich Mean Sidereal Time (GMST) from UT */
/* '<S3>:1:21' */
/* '<S3>:1:22' */
ADC_B.G0 = rt_remd_snf(((67310.54841 + 3.1644001848128662E+9 * ADC_B.time_diff) + 0.093104 * (ADC_B.time_diff * ADC_B.time_diff)) - 6.2E-6 * rt_powd_snf(ADC_B.time_diff, 3.0), 86400.0) / 240.0;
if (ADC_B.G0 < 0.0) {
    /* '<S3>:1:23' */
    /* '<S3>:1:24' */
    ADC_B.G0 = -(-ADC_B.G0 - 360.0);
}
/* truncate GMST between 0 and 2pi */
/* '<S3>:1:27' */
ADC_B.G0 = ADC_B.G0 * 3.1415926535897931 / 180.0;
/* (rad) */
/* Compute the Direction Cosine Matrix (DCM) for converting vectors in  */
/* Earth-Centered Inertial (ECI) frame to vectors in Earth-Centered  */
/* Earth-Fixed (ECEF) frame */
/* '<S3>:1:32' */
/* '<S3>:1:55' */
/* '<S3>:1:53' */
/*  WGS84 ellipsoid constants: */
/*  intermediate calculation */
/*  (prime vertical radius of curvature) */
/* '<S3>:1:40' */
ADC_B.time_diff = arg_lla[0];
ADC_sind(&ADC_B.time_diff);
ADC_B.scale = 6.378137E+6 / sqrt(1.0 - 0.0066943799901414 * (ADC_B.time_diff * ADC_B.time_diff));
/*  results: */
/* '<S3>:1:43' */
/* '<S3>:1:44' */
/* '<S3>:1:45' */
/* '<S3>:1:47' */
ADC_B.time_diff = arg_lla[0];
ADC_cosd(&ADC_B.time_diff);
ADC_B.E = arg_lla[1];
ADC_cosd(&ADC_B.E);
ADC_B.M = arg_lla[0];
ADC_cosd(&ADC_B.M);
ADC_B.f = arg_lla[1];
ADC_sind(&ADC_B.f);
ADC_B.rtb_B_e_d = arg_lla[0];
ADC_sind(&ADC_B.rtb_B_e_d);
ADC_B.time_diff = (ADC_B.scale + arg_lla[2]) * ADC_B.time_diff * ADC_B.E;
ADC_B.M = (ADC_B.scale + arg_lla[2]) * ADC_B.M * ADC_B.f;
ADC_B.scale = (0.99330562000985856 * ADC_B.scale + arg_lla[2]) * ADC_B.rtb_B_e_d;
ADC_B.dv2[0] = cos(ADC_B.G0);
ADC_B.dv2[1] = sin(ADC_B.G0);
ADC_B.dv2[2] = 0.0;
ADC_B.dv2[3] = -sin(ADC_B.G0);
ADC_B.dv2[4] = cos(ADC_B.G0);
ADC_B.dv2[5] = 0.0;
ADC_B.dv2[6] = 0.0;
ADC_B.dv2[7] = 0.0;
ADC_B.dv2[8] = 1.0;
for (i = 0; i < 3; i++) {
    ADC_B.r_ECI[i] = 0.0;
    ADC_B.r_ECI[i] += ADC_B.dv2[i] * ADC_B.time_diff;
    ADC_B.r_ECI[i] += ADC_B.dv2[i + 3] * ADC_B.M;
    ADC_B.r_ECI[i] += ADC_B.dv2[i + 6] * ADC_B.scale;
}
/* End of MATLAB Function: '<Root>/lla2eci' */

/* MATLAB Function: '<S20>/Calculator' incorporates:
 *  Inport: '<Root>/epoch'
 */
/* MATLAB Function 'Estimator/Space Environment/Calculator': '<S66>:1' */
/* Compute the Julian Date (JD) from a Gregorian Date (UT1) input */
/* '<S66>:1:5' */
/* (year) */
/* '<S66>:1:6' */
/* (month) */
/* '<S66>:1:7' */
/* (day) */
/* '<S66>:1:8' */
/* (hr) */
/* '<S66>:1:9' */
/* (min) */
/* '<S66>:1:10' */
/* (sec) */
/* '<S66>:1:11' */
/* (JD) */
/* Compute the Universal Time (UT) from JD */
/* '<S66>:1:14' */
ADC_B.time_diff = ((((((367.0 * arg_epoch[0] - floor(1.75 * (arg_epoch[0] + floor((arg_epoch[1] + 9.0) / 12.0)))) + floor(275.0 * arg_epoch[1] / 9.0)) + arg_epoch[2]) + 1.7210135E+6) + ((arg_epoch[5] / 60.0 + arg_epoch[4]) / 60.0 + arg_epoch[3]) / 24.0) - 2.451545E+6) / 36525.0;
/* Compute the Greenwich Mean Sidereal Time (GMST) from UT */
/* '<S66>:1:17' */
/* '<S66>:1:18' */
ADC_B.G0 = rt_remd_snf(((67310.54841 + 3.1644001848128662E+9 * ADC_B.time_diff) + 0.093104 * (ADC_B.time_diff * ADC_B.time_diff)) - 6.2E-6 * rt_powd_snf(ADC_B.time_diff, 3.0), 86400.0) / 240.0;
if (ADC_B.G0 < 0.0) {
    /* '<S66>:1:19' */
    /* '<S66>:1:20' */
    ADC_B.G0 = -(-ADC_B.G0 - 360.0);
}
/* truncate GMST between 0 and 2pi */
/* '<S66>:1:23' */
ADC_B.G0 = ADC_B.G0 * 3.1415926535897931 / 180.0;
/* (rad) */
/* Compute the Direction Cosine Matrix (DCM) for converting vectors in  */
/* Earth-Centered Inertial (ECI) frame to vectors in Earth-Centered  */
/* Earth-Fixed (ECEF) frame */
/* Compute the Sun vector based on the UT */
/* '<S66>:1:31' */
/* '<S66>:1:51' */
/* (°) */
/* '<S66>:1:52' */
ADC_B.M = (357.5277233 + 35999.05034 * ADC_B.time_diff) * 3.1415926535897931 / 180.0;
/* (rad) */
/* '<S66>:1:53' */
ADC_B.scale = (((280.4606184 + 36000.77005361 * ADC_B.time_diff) + 1.914666471 * sin(ADC_B.M)) + 0.019994643 * sin(2.0 * ADC_B.M)) * 3.1415926535897931 / 180.0;
/* (rad) */
/* '<S66>:1:54' */
ADC_B.E = (23.439291 - 0.0130042 * ADC_B.time_diff) * 3.1415926535897931 / 180.0;
/* (rad) */
/* '<S66>:1:55' */
ADC_B.M = ((1.000140612 - 0.016708617 * cos(ADC_B.M)) - 0.000139589 * cos(2.0 * ADC_B.M)) * 1.49598E+8 * 1000.0;
/* (m) */
/* '<S66>:1:56' */
/* (m) */
/* Compute the Moon vector based on the UT */
/* Compute the Earth's magnetic vector in the ECI frame */
/* '<S66>:1:37' */
/* 2010 IGRF constants */
/* '<S66>:1:87' */
/* '<S66>:1:90' */
/* '<S66>:1:92' */
/* '<S66>:1:94' */
ADC_B.u_b[0] = 0.17339393238837042 * cos(ADC_B.G0 + 1.8811352995009261);
ADC_B.u_b[1] = 0.17339393238837042 * sin(ADC_B.G0 + 1.8811352995009261);
/* '<S66>:1:98' */
ADC_B.time_diff = ADC_norm_j(ADC_B.r_ECI);
ADC_B.m_g[0] = ADC_B.r_ECI[0] / ADC_B.time_diff;
ADC_B.m_g[1] = ADC_B.r_ECI[1] / ADC_B.time_diff;
ADC_B.m_g[2] = ADC_B.r_ECI[2] / ADC_B.time_diff;
/* '<S66>:1:100' */
ADC_B.G0 = 7.771067126913751E+15 / rt_powd_snf(ADC_norm_j(ADC_B.r_ECI), 3.0);
ADC_B.time_diff = 3.0 * ((ADC_B.u_b[0] * ADC_B.m_g[0] + ADC_B.u_b[1] * ADC_B.m_g[1]) + -0.98485254947677181 * ADC_B.m_g[2]);
/* (T) */
ADC_B.B_e[0] = ADC_B.M * cos(ADC_B.scale);
ADC_B.B_e[1] = ADC_B.M * (cos(ADC_B.E) * sin(ADC_B.scale));
ADC_B.B_e[2] = ADC_B.M * (sin(ADC_B.E) * sin(ADC_B.scale));
ADC_B.m_g[0] = ADC_B.G0 * (ADC_B.time_diff * ADC_B.m_g[0] - ADC_B.u_b[0]);
ADC_B.m_g[1] = ADC_B.G0 * (ADC_B.time_diff * ADC_B.m_g[1] - ADC_B.u_b[1]);
ADC_B.f = ADC_B.G0 * (ADC_B.time_diff * ADC_B.m_g[2] - -0.98485254947677181);
ADC_B.m_g[2] = ADC_B.G0 * (ADC_B.time_diff * ADC_B.m_g[2] - -0.98485254947677181);
/* End of MATLAB Function: '<S20>/Calculator' */

/* MATLAB Function: '<S2>/MATLAB Function1' incorporates:
 *  Inport: '<Root>/Magnetic Measure'
 *  Inport: '<Root>/Sun Measure'
 */
/* MATLAB Function 'Estimator/MATLAB Function1': '<S19>:1' */
/* '<S19>:1:3' */


ADC_B.time_diff = ADC_norm_lw(arg_Magnetic_Measure);
ADC_B.u_b[0] = arg_Magnetic_Measure[0] / ADC_B.time_diff;
ADC_B.u_b[1] = arg_Magnetic_Measure[1] / ADC_B.time_diff;
ADC_B.u_b[2] = arg_Magnetic_Measure[2] / ADC_B.time_diff;
/* '<S19>:1:4' */


ADC_B.time_diff = ADC_norm_lw(arg_Sun_Measure);
ADC_B.W2_idx_0 = arg_Sun_Measure[0] / ADC_B.time_diff;
ADC_B.W2_idx_1 = arg_Sun_Measure[1] / ADC_B.time_diff;
ADC_B.W2_idx_2 = arg_Sun_Measure[2] / ADC_B.time_diff;
/* '<S19>:1:5' */
ADC_B.time_diff = ADC_norm_lw(ADC_B.m_g);
ADC_B.m_g[0] /= ADC_B.time_diff;
ADC_B.m_g[1] /= ADC_B.time_diff;
ADC_B.f /= ADC_B.time_diff;
/* '<S19>:1:6' */
ADC_B.time_diff = ADC_norm_lw(ADC_B.B_e);
ADC_B.B_e[0] /= ADC_B.time_diff;
ADC_B.B_e[1] /= ADC_B.time_diff;
ADC_B.rtb_B_e_d = ADC_B.B_e[2] / ADC_B.time_diff;
/* '<S19>:1:9' */
ADC_B.rtb_m_g_g[0] = ADC_B.m_g[1] * ADC_B.rtb_B_e_d - ADC_B.f * ADC_B.B_e[1];
ADC_B.rtb_m_g_g[1] = ADC_B.f * ADC_B.B_e[0] - ADC_B.m_g[0] * ADC_B.rtb_B_e_d;
ADC_B.rtb_m_g_g[2] = ADC_B.m_g[0] * ADC_B.B_e[1] - ADC_B.m_g[1] * ADC_B.B_e[0];
ADC_B.G0 = ADC_norm_lw(ADC_B.rtb_m_g_g);
/* '<S19>:1:10' */
ADC_B.c_idx_0 = ADC_B.m_g[1] * ADC_B.rtb_B_e_d - ADC_B.f * ADC_B.B_e[1];
ADC_B.c_idx_1 = ADC_B.f * ADC_B.B_e[0] - ADC_B.m_g[0] * ADC_B.rtb_B_e_d;
ADC_B.c_idx_2 = ADC_B.m_g[0] * ADC_B.B_e[1] - ADC_B.m_g[1] * ADC_B.B_e[0];
ADC_B.rtb_m_g_f[0] = ADC_B.m_g[1] * ADC_B.rtb_B_e_d - ADC_B.f * ADC_B.B_e[1];
ADC_B.rtb_m_g_f[1] = ADC_B.f * ADC_B.B_e[0] - ADC_B.m_g[0] * ADC_B.rtb_B_e_d;
ADC_B.rtb_m_g_f[2] = ADC_B.m_g[0] * ADC_B.B_e[1] - ADC_B.m_g[1] * ADC_B.B_e[0];
ADC_B.scale = ADC_norm_lw(ADC_B.rtb_m_g_f);
/* '<S19>:1:13' */
ADC_B.u_cv[0] = ADC_B.u_b[1] * ADC_B.W2_idx_2 - ADC_B.u_b[2] * ADC_B.W2_idx_1;
ADC_B.u_cv[1] = ADC_B.u_b[2] * ADC_B.W2_idx_0 - ADC_B.u_b[0] * ADC_B.W2_idx_2;
ADC_B.u_cv[2] = ADC_B.u_b[0] * ADC_B.W2_idx_1 - ADC_B.u_b[1] * ADC_B.W2_idx_0;
ADC_B.E = ADC_norm_lw(ADC_B.u_cv);
/* '<S19>:1:14' */
ADC_B.b_c_idx_0 = ADC_B.u_b[1] * ADC_B.W2_idx_2 - ADC_B.u_b[2] * ADC_B.W2_idx_1;
ADC_B.b_c_idx_1 = ADC_B.u_b[2] * ADC_B.W2_idx_0 - ADC_B.u_b[0] * ADC_B.W2_idx_2;
ADC_B.b_c_idx_2 = ADC_B.u_b[0] * ADC_B.W2_idx_1 - ADC_B.u_b[1] * ADC_B.W2_idx_0;
ADC_B.u_p[0] = ADC_B.u_b[1] * ADC_B.W2_idx_2 - ADC_B.u_b[2] * ADC_B.W2_idx_1;
ADC_B.u_p[1] = ADC_B.u_b[2] * ADC_B.W2_idx_0 - ADC_B.u_b[0] * ADC_B.W2_idx_2;
ADC_B.u_p[2] = ADC_B.u_b[0] * ADC_B.W2_idx_1 - ADC_B.u_b[1] * ADC_B.W2_idx_0;
ADC_B.M = ADC_norm_lw(ADC_B.u_p);
/* '<S19>:1:16' */
if (rtmIsMajorTimeStep(ADC_M)) {
    /* MATLAB Function: '<S2>/ LVLH ' */
    /* MATLAB Function 'Estimator/ LVLH ': '<S15>:1' */
    /* '<S15>:1:12' */
    /* % create Local Horizontal Local Vertical Coordinates */
    /* '<S15>:1:4' */
    /* '<S15>:1:21' */
    ADC_B.time_diff = ADC_norm_p(ADC_B.r_ECI);
    /* Sum: '<S2>/Sum' incorporates:
 *  Memory: '<S2>/Memory1'
 */
    ADC_B.Sum_c[0] = ADC_B.r_ECI[0] - ADC_DW.Memory1_PreviousInput[0];
    /* MATLAB Function: '<S2>/ LVLH ' */
    z_idx_0 = -(ADC_B.r_ECI[0] / ADC_B.time_diff);
    /* Sum: '<S2>/Sum' incorporates:
 *  Memory: '<S2>/Memory1'
 */
    ADC_B.Sum_c[1] = ADC_B.r_ECI[1] - ADC_DW.Memory1_PreviousInput[1];
    /* MATLAB Function: '<S2>/ LVLH ' */
    ADC_B.z_idx_1 = -(ADC_B.r_ECI[1] / ADC_B.time_diff);
    /* Sum: '<S2>/Sum' incorporates:
 *  Memory: '<S2>/Memory1'
 */
    ADC_B.Sum_c[2] = ADC_B.r_ECI[2] - ADC_DW.Memory1_PreviousInput[2];
    /* MATLAB Function: '<S2>/ LVLH ' */
    ADC_B.z_idx_2 = -(ADC_B.r_ECI[2] / ADC_B.time_diff);
    if (ADC_norm_p(ADC_B.Sum_c) > 1.0E-8) {
        /* '<S15>:1:6' */
        /*  use this if reasonable velocity estimate from postion change */
        /* '<S15>:1:8' */
        ADC_B.time_diff = (ADC_B.Sum_c[0] * z_idx_0 + ADC_B.Sum_c[1] * ADC_B.z_idx_1) + ADC_B.Sum_c[2] * ADC_B.z_idx_2;
        ADC_B.Sum_c[0] -= ADC_B.time_diff * z_idx_0;
        ADC_B.Sum_c[1] -= ADC_B.time_diff * ADC_B.z_idx_1;
        ADC_B.a = ADC_B.Sum_c[2] - ADC_B.time_diff * ADC_B.z_idx_2;
        ADC_B.Sum_c[2] -= ADC_B.time_diff * ADC_B.z_idx_2;
        /* '<S15>:1:21' */
        ADC_B.time_diff = ADC_norm_p(ADC_B.Sum_c);
        ADC_B.Sum_c[0] /= ADC_B.time_diff;
        ADC_B.Sum_c[1] /= ADC_B.time_diff;
        ADC_B.a /= ADC_B.time_diff;
        ADC_B.Sum_c[2] = ADC_B.a;
        /* '<S15>:1:9' */
        ADC_B.y_tmp[0] = ADC_B.z_idx_1 * ADC_B.a - ADC_B.z_idx_2 * ADC_B.Sum_c[1];
        ADC_B.y_tmp[1] = ADC_B.z_idx_2 * ADC_B.Sum_c[0] - z_idx_0 * ADC_B.a;
        ADC_B.y_tmp[2] = z_idx_0 * ADC_B.Sum_c[1] - ADC_B.z_idx_1 * ADC_B.Sum_c[0];
    } else {
        /*  assume polar and use geometry to find velocity direction */
        /* '<S15>:1:12' */
        ADC_B.a = 0.0 * ADC_B.r_ECI[0] + -ADC_B.r_ECI[1];
        ADC_B.y_tmp[0] = ADC_B.a;
        ADC_B.y_tmp[1] = ADC_B.r_ECI[0] + 0.0 * ADC_B.r_ECI[1];
        ADC_B.y_tmp[2] = 0.0;
        /* '<S15>:1:21' */
        ADC_B.time_diff = ADC_norm_p(ADC_B.y_tmp);
        ADC_B.y_tmp[0] = ADC_B.a / ADC_B.time_diff;
        ADC_B.y_tmp[1] /= ADC_B.time_diff;
        ADC_B.y_tmp[2] = 0.0 / ADC_B.time_diff;
        /* '<S15>:1:13' */
        ADC_B.time_diff = (ADC_B.y_tmp[0] * z_idx_0 + ADC_B.y_tmp[1] * ADC_B.z_idx_1) + 0.0 / ADC_B.time_diff * ADC_B.z_idx_2;
        ADC_B.y_tmp[0] -= ADC_B.time_diff * z_idx_0;
        ADC_B.y_tmp[1] -= ADC_B.time_diff * ADC_B.z_idx_1;
        ADC_B.a = ADC_B.y_tmp[2] - ADC_B.time_diff * ADC_B.z_idx_2;
        ADC_B.y_tmp[2] -= ADC_B.time_diff * ADC_B.z_idx_2;
        /* '<S15>:1:21' */
        ADC_B.time_diff = ADC_norm_p(ADC_B.y_tmp);
        ADC_B.y_tmp[0] /= ADC_B.time_diff;
        ADC_B.y_tmp[1] /= ADC_B.time_diff;
        ADC_B.a /= ADC_B.time_diff;
        ADC_B.y_tmp[2] = ADC_B.a;
        /* '<S15>:1:14' */
        ADC_B.Sum_c[0] = ADC_B.y_tmp[1] * ADC_B.z_idx_2 - ADC_B.a * ADC_B.z_idx_1;
        ADC_B.Sum_c[1] = ADC_B.a * z_idx_0 - ADC_B.y_tmp[0] * ADC_B.z_idx_2;
        ADC_B.Sum_c[2] = ADC_B.y_tmp[0] * ADC_B.z_idx_1 - ADC_B.y_tmp[1] * z_idx_0;
    }
    /* Math: '<S2>/Math Function1' incorporates:
 *  MATLAB Function: '<S2>/ LVLH '
 */
    /* '<S15>:1:17' */
    ADC_B.MathFunction1[0] = ADC_B.Sum_c[0];
    ADC_B.MathFunction1[3] = ADC_B.y_tmp[0];
    ADC_B.MathFunction1[6] = z_idx_0;
    ADC_B.MathFunction1[1] = ADC_B.Sum_c[1];
    ADC_B.MathFunction1[4] = ADC_B.y_tmp[1];
    ADC_B.MathFunction1[7] = ADC_B.z_idx_1;
    ADC_B.MathFunction1[2] = ADC_B.Sum_c[2];
    ADC_B.MathFunction1[5] = ADC_B.y_tmp[2];
    ADC_B.MathFunction1[8] = ADC_B.z_idx_2;
}
/* MATLAB Function: '<S2>/MATLAB Function1' incorporates:
 *  Product: '<S2>/Matrix Multiply'
 */
ADC_B.u_g[0] = ADC_B.u_b[1] * ADC_B.W2_idx_2 - ADC_B.u_b[2] * ADC_B.W2_idx_1;
ADC_B.u_g[1] = ADC_B.u_b[2] * ADC_B.W2_idx_0 - ADC_B.u_b[0] * ADC_B.W2_idx_2;
ADC_B.u_g[2] = ADC_B.u_b[0] * ADC_B.W2_idx_1 - ADC_B.u_b[1] * ADC_B.W2_idx_0;
ADC_B.rtb_m_g_m[0] = ADC_B.m_g[1] * ADC_B.rtb_B_e_d - ADC_B.f * ADC_B.B_e[1];
ADC_B.rtb_m_g_m[1] = ADC_B.f * ADC_B.B_e[0] - ADC_B.m_g[0] * ADC_B.rtb_B_e_d;
ADC_B.rtb_m_g_m[2] = ADC_B.m_g[0] * ADC_B.B_e[1] - ADC_B.m_g[1] * ADC_B.B_e[0];
for (i = 0; i < 3; i++) {
    ADC_B.u_cv[i] = ADC_B.u_g[i] / ADC_B.E;
    ADC_B.rtb_m_g_g[i] = ADC_B.rtb_m_g_m[i] / ADC_B.G0;
    ADC_B.u[i] = ADC_B.u_b[i] * ADC_B.m_g[0];
    ADC_B.u[i + 3] = ADC_B.u_b[i] * ADC_B.m_g[1];
    ADC_B.u[i + 6] = ADC_B.u_b[i] * ADC_B.f;
}
ADC_B.u_n[0] = ADC_B.u_b[1] * ADC_B.b_c_idx_2 - ADC_B.u_b[2] * ADC_B.b_c_idx_1;
ADC_B.u_n[1] = ADC_B.u_b[2] * ADC_B.b_c_idx_0 - ADC_B.u_b[0] * ADC_B.b_c_idx_2;
ADC_B.u_n[2] = ADC_B.u_b[0] * ADC_B.b_c_idx_1 - ADC_B.u_b[1] * ADC_B.b_c_idx_0;
ADC_B.rtb_m_g_p[0] = ADC_B.m_g[1] * ADC_B.c_idx_2 - ADC_B.f * ADC_B.c_idx_1;
ADC_B.rtb_m_g_p[1] = ADC_B.f * ADC_B.c_idx_0 - ADC_B.m_g[0] * ADC_B.c_idx_2;
ADC_B.rtb_m_g_p[2] = ADC_B.m_g[0] * ADC_B.c_idx_1 - ADC_B.m_g[1] * ADC_B.c_idx_0;
for (i = 0; i < 3; i++) {
    ADC_B.u_c[i] = ADC_B.u_cv[i] * ADC_B.rtb_m_g_g[0];
    ADC_B.u_c[i + 3] = ADC_B.u_cv[i] * ADC_B.rtb_m_g_g[1];
    ADC_B.u_c[i + 6] = ADC_B.u_cv[i] * ADC_B.rtb_m_g_g[2];
    ADC_B.u_b[i] = ADC_B.u_n[i] / ADC_B.M;
    ADC_B.m_g[i] = ADC_B.rtb_m_g_p[i] / ADC_B.scale;
}
for (i = 0; i < 3; i++) {
    ADC_B.u_k[i] = (ADC_B.u[i] + ADC_B.u_c[i]) + ADC_B.u_b[i] * ADC_B.m_g[0];
    ADC_B.u_k[i + 3] = (ADC_B.u[i + 3] + ADC_B.u_c[i + 3]) + ADC_B.u_b[i] * ADC_B.m_g[1];
    ADC_B.u_k[i + 6] = (ADC_B.u[i + 6] + ADC_B.u_c[i + 6]) + ADC_B.u_b[i] * ADC_B.m_g[2];
    /* Product: '<S2>/Matrix Multiply' */
    for (b_sizes = 0; b_sizes < 3; b_sizes++) {
        ADC_B.R_LVLH2b[i + 3 * b_sizes] = 0.0;
        ADC_B.R_LVLH2b[i + 3 * b_sizes] += ADC_B.u_k[i] * ADC_B.MathFunction1[3 * b_sizes];
        ADC_B.R_LVLH2b[i + 3 * b_sizes] += ADC_B.u_k[i + 3] * ADC_B.MathFunction1[1 + 3 * b_sizes];
        ADC_B.R_LVLH2b[i + 3 * b_sizes] += ADC_B.u_k[i + 6] * ADC_B.MathFunction1[2 + 3 * b_sizes];
    }
}
/* MATLAB Function: '<S2>/DCM to q' */
/* MATLAB Function 'Estimator/DCM to q': '<S16>:1' */
/* '<S16>:1:3' */
/* '<S16>:1:5' */
ADC_B.E = (ADC_B.R_LVLH2b[0] + ADC_B.R_LVLH2b[4]) + ADC_B.R_LVLH2b[8];
if (!(ADC_B.E >= -1.0)) {
    ADC_B.E = -1.0;
}
ADC_B.G0 = 0.5 * sqrt(ADC_B.E + 1.0);
/* '<S16>:1:6' */
ADC_B.scale = (ADC_B.R_LVLH2b[7] - ADC_B.R_LVLH2b[5]) / (4.0 * ADC_B.G0);
/* '<S16>:1:7' */
ADC_B.E = (ADC_B.R_LVLH2b[2] - ADC_B.R_LVLH2b[6]) / (4.0 * ADC_B.G0);
/* '<S16>:1:8' */
ADC_B.M = (ADC_B.R_LVLH2b[3] - ADC_B.R_LVLH2b[1]) / (4.0 * ADC_B.G0);
/* End of MATLAB Function: '<S2>/DCM to q' */

/* S-Function (sdsp2norm2): '<S2>/Normalization' */
/* '<S16>:1:10' */
ADC_B.time_diff = 1.0 / ((((ADC_B.scale * ADC_B.scale + ADC_B.E * ADC_B.E) + ADC_B.M * ADC_B.M) + ADC_B.G0 * ADC_B.G0) + ADC_P.Normalization_Bias);
ADC_B.scale *= ADC_B.time_diff;
ADC_B.E *= ADC_B.time_diff;
ADC_B.M *= ADC_B.time_diff;
ADC_B.time_diff *= ADC_B.G0;
/* Outport: '<Root>/q_est1' */
arg_q_est1[0] = ADC_B.scale;
arg_q_est1[1] = ADC_B.E;
arg_q_est1[2] = ADC_B.M;
arg_q_est1[3] = ADC_B.time_diff;
/* Switch: '<S6>/Switch2' incorporates:
 *  Inport: '<Root>/S_flag'
 */
guard1 = (*arg_S_flag > ADC_P.Switch2_Threshold);
/* MATLAB Function: '<S6>/LQR Controller' incorporates:
 *  Integrator: '<S17>/MemoryX'
 */
for (i = 0; i < 3; i++) {
    ADC_B.B_e[i] = 0.0;
    for (b_sizes = 0; b_sizes < 6; b_sizes++) {
        ADC_B.B_e[i] += b_a[i + 3 * b_sizes] * ADC_X.MemoryX_CSTATE[b_sizes];
    }
}
/* MATLAB Function: '<S6>/PD Controler' */
ADC_B.rtb_m_l[0] = ADC_B.rtb_m_idx_1 * ADC_B.B1[2] - ADC_B.rtb_m_idx_2 * ADC_B.B1[1];
ADC_B.rtb_m_l[1] = ADC_B.rtb_m_idx_2 * ADC_B.B1[0] - ADC_B.rtb_m_idx_0 * ADC_B.B1[2];
ADC_B.rtb_m_l[2] = ADC_B.rtb_m_idx_0 * ADC_B.B1[1] - ADC_B.rtb_m_idx_1 * ADC_B.B1[0];
/* MATLAB Function: '<S2>/State1' */
/* MATLAB Function 'Estimator/State1': '<S21>:1' */
/* '<S21>:1:9' */
/*  w_r=w+.0011*R(:,2); */
/*  q_dot=0.5*[q(4) -q(3)  q(2) */
/*         q(3)  q(4) -q(1) */
/*         -q(2) q(1)  q(4)]*w_r; */
/*  orbital rate in rad/sec = 0.0011 */
/* '<S21>:1:9' */
/* '<S21>:1:10' */
/*  This block supports an embeddable subset of the MATLAB language. */
/*  See the help menu for details.  */
/* '<S21>:1:21' */
/* '<S21>:1:27' */
/* '<S21>:1:34' */
/* '<S21>:1:12' */
/* '<S21>:1:13' */
ADC_B.dv3[0] = 0.0;
ADC_B.dv3[3] = -ADC_B.M;
ADC_B.dv3[6] = ADC_B.E;
ADC_B.dv3[1] = ADC_B.M;
ADC_B.dv3[4] = 0.0;
ADC_B.dv3[7] = -ADC_B.scale;
ADC_B.dv3[2] = -ADC_B.E;
ADC_B.dv3[5] = ADC_B.scale;
ADC_B.dv3[8] = 0.0;
for (i = 0; i < 3; i++) {
    /* MATLAB Function: '<S2>/State1' */
    ADC_B.rtb_Normalization_m[i << 2] = ADC_B.time_diff * (real_T)b_0[3 * i] + ADC_B.dv3[3 * i];
    ADC_B.rtb_Normalization_m[1 + (i << 2)] = ADC_B.time_diff * (real_T)b_0[1 + 3 * i] + ADC_B.dv3[1 + 3 * i];
    ADC_B.rtb_Normalization_m[2 + (i << 2)] = ADC_B.time_diff * (real_T)b_0[2 + 3 * i] + ADC_B.dv3[2 + 3 * i];
    /* Switch: '<S6>/Switch2' incorporates:
 *  MATLAB Function: '<S6>/LQR Controller'
 */
    if (guard1) {
        ADC_B.m_g[i] = (a[i] * ADC_B.B_e[0] + a[i + 3] * ADC_B.B_e[1]) + a[i + 6] * ADC_B.B_e[2];
    } else {
        ADC_B.m_g[i] = ADC_B.rtb_m_l[i];
    }
}
/* MATLAB Function: '<S2>/State1' incorporates:
 *  Inport: '<Root>/Euler Angle Measure'
 */
ADC_B.rtb_Normalization_m[3] = -ADC_B.scale;
ADC_B.rtb_Normalization_m[7] = -ADC_B.E;
ADC_B.rtb_Normalization_m[11] = -ADC_B.M;
for (i = 0; i < 3; i++) {
    ADC_B.dv1[i << 2] = 0.5 * ADC_B.rtb_Normalization_m[i << 2];
    ADC_B.dv1[1 + (i << 2)] = 0.5 * ADC_B.rtb_Normalization_m[1 + (i << 2)];
    ADC_B.dv1[2 + (i << 2)] = 0.5 * ADC_B.rtb_Normalization_m[2 + (i << 2)];
    ADC_B.dv1[3 + (i << 2)] = 0.5 * ADC_B.rtb_Normalization_m[3 + (i << 2)];
    ADC_B.u_b[i] = arg_Euler_Angle_Measure[i] + ADC_B.R_LVLH2b[3 + i] * 0.0011;
}
for (i = 0; i < 4; i++) {
    ADC_B.dv6[i] = (ADC_B.dv1[i] * ADC_B.u_b[0] + ADC_B.dv1[i + 4] * ADC_B.u_b[1]) + ADC_B.dv1[i + 8] * ADC_B.u_b[2];
}
ADC_B.x[0] = ADC_B.scale;
ADC_B.x[1] = ADC_B.E;
ADC_B.x[2] = ADC_B.M;
ADC_B.x[3] = ADC_B.dv6[0];
ADC_B.x[4] = ADC_B.dv6[1];
ADC_B.x[5] = ADC_B.dv6[2];
/* MATLAB Function: '<S2>/  ' */
/* MATLAB Function 'Estimator/  ': '<S12>:1' */
/* '<S12>:1:3' */
k = 0;
for (i = 0; i < 6; i++) {
    guard1 = rtIsNaN(ADC_B.x[i]);
    if (guard1) {
        k++;
    }
    c[i] = guard1;
}
b_sizes = k;
i = 0;
for (k = 0; k < 6; k++) {
    if (c[k]) {
        ADC_B.b_data[i] = k + 1;
        i++;
    }
}
/* '<S12>:1:3' */
for (i = 0; i < b_sizes; i++) {
    ADC_B.x[ADC_B.b_data[i] - 1] = 0.0;
}
/* End of MATLAB Function: '<S2>/  ' */

/* Outputs for Enabled SubSystem: '<S40>/MeasurementUpdate' incorporates:
 *  EnablePort: '<S65>/Enable'
 */
/* '<S12>:1:4' */
/* MATLAB Function 'Estimator/  1': '<S13>:1' */
/* '<S13>:1:3' */
/* '<S13>:1:4' */
/* MATLAB Function 'Estimator/  2': '<S14>:1' */
/* '<S14>:1:4' */
if (rtmIsMajorTimeStep(ADC_M) && rtmIsMajorTimeStep(ADC_M)) {
    /* Constant: '<S17>/Enable' */
    if (ADC_P.Enable_Value) {
        if (!ADC_DW.MeasurementUpdate_MODE) {
            ADC_DW.MeasurementUpdate_MODE = true;
        }
    } else {
        if (ADC_DW.MeasurementUpdate_MODE) {
            ADC_DW.MeasurementUpdate_MODE = false;
        }
    }
    /* End of Constant: '<S17>/Enable' */
}
if (ADC_DW.MeasurementUpdate_MODE) {
    for (i = 0; i < 6; i++) {
        /* Product: '<S40>/C[k]*xhat[k|k-1]' incorporates:
 *  Constant: '<S17>/C'
 *  Integrator: '<S17>/MemoryX'
 *  Sum: '<S40>/Add1'
 */
        ADC_B.dv4[i] = 0.0;
        for (b_sizes = 0; b_sizes < 6; b_sizes++) {
            ADC_B.dv4[i] += ADC_P.C_Value[i + 6 * b_sizes] * ADC_X.MemoryX_CSTATE[b_sizes];
        }
        /* End of Product: '<S40>/C[k]*xhat[k|k-1]' */

        /* Product: '<S40>/D[k-1]*u[k-1]' incorporates:
 *  Constant: '<S17>/D'
 *  Sum: '<S40>/Add1'
 */
        ADC_B.dv5[i] = 0.0;
        ADC_B.dv5[i] += ADC_P.D_Value[i] * ADC_B.m_g[0];
        ADC_B.dv5[i] += ADC_P.D_Value[i + 6] * ADC_B.m_g[1];
        ADC_B.dv5[i] += ADC_P.D_Value[i + 12] * ADC_B.m_g[2];
        /* Sum: '<S65>/Sum' incorporates:
 *  Product: '<S65>/Product3'
 *  Sum: '<S40>/Add1'
 */
        ADC_B.rtb_x_c[i] = ADC_B.x[i] - (ADC_B.dv4[i] + ADC_B.dv5[i]);
    }
    /* Product: '<S65>/Product3' incorporates:
 *  Constant: '<S22>/KalmanGainL'
 */
    for (i = 0; i < 6; i++) {
        ADC_B.Product3[i] = 0.0;
        for (b_sizes = 0; b_sizes < 6; b_sizes++) {
            ADC_B.Product3[i] += ADC_P.KalmanGainL_Value[i + 6 * b_sizes] * ADC_B.rtb_x_c[b_sizes];
        }
    }
}
/* End of Outputs for SubSystem: '<S40>/MeasurementUpdate' */
for (i = 0; i < 6; i++) {
    /* Product: '<S40>/B[k]*u[k]' incorporates:
 *  Constant: '<S17>/B'
 *  Sum: '<S40>/Add'
 */
    ADC_B.dv4[i] = 0.0;
    ADC_B.dv4[i] += ADC_P.B_Value[i] * ADC_B.m_g[0];
    ADC_B.dv4[i] += ADC_P.B_Value[i + 6] * ADC_B.m_g[1];
    ADC_B.dv4[i] += ADC_P.B_Value[i + 12] * ADC_B.m_g[2];
    /* Product: '<S40>/A[k]*xhat[k|k-1]' incorporates:
 *  Constant: '<S17>/A'
 *  Integrator: '<S17>/MemoryX'
 *  Sum: '<S40>/Add'
 */
    ADC_B.dv5[i] = 0.0;
    for (b_sizes = 0; b_sizes < 6; b_sizes++) {
        ADC_B.dv5[i] += ADC_P.A_Value[i + 6 * b_sizes] * ADC_X.MemoryX_CSTATE[b_sizes];
    }
    /* End of Product: '<S40>/A[k]*xhat[k|k-1]' */

    /* Sum: '<S40>/Add' */
    ADC_B.Add[i] = (ADC_B.dv4[i] + ADC_B.dv5[i]) + ADC_B.Product3[i];
}
/* MATLAB Function 'Estimator/MATLAB Function': '<S18>:1' */
/* '<S18>:1:3' */
if (rtmIsMajorTimeStep(ADC_M)) {
    /* Memory: '<S2>/Memory' */
    ADC_B.Memory_j[0] = ADC_DW.Memory_PreviousInput_h[0];
    ADC_B.Memory_j[1] = ADC_DW.Memory_PreviousInput_h[1];
    ADC_B.Memory_j[2] = ADC_DW.Memory_PreviousInput_h[2];
}






        
  


          
      
          if (rtmIsMajorTimeStep(ADC_M)) {
                    
  



                                  if (rtmIsMajorTimeStep(ADC_M)) {
    /* Update for Memory: '<S1>/Memory' incorporates:
 *  Update for Inport: '<Root>/Magnetic Measure'
 */
    ADC_DW.Memory_PreviousInput[0] = arg_Magnetic_Measure[0];
    /* Update for UnitDelay: '<S7>/UD' */
    ADC_DW.UD_DSTATE[0] = ADC_B.TSamp[0];
    /* Update for Memory: '<S1>/Memory' incorporates:
 *  Update for Inport: '<Root>/Magnetic Measure'
 */
    ADC_DW.Memory_PreviousInput[1] = arg_Magnetic_Measure[1];
    /* Update for UnitDelay: '<S7>/UD' */
    ADC_DW.UD_DSTATE[1] = ADC_B.TSamp[1];
    /* Update for Memory: '<S1>/Memory' incorporates:
 *  Update for Inport: '<Root>/Magnetic Measure'
 */
    ADC_DW.Memory_PreviousInput[2] = arg_Magnetic_Measure[2];
    /* Update for UnitDelay: '<S7>/UD' */
    ADC_DW.UD_DSTATE[2] = ADC_B.TSamp[2];
    /* Update for Memory: '<S2>/Memory1' */
    ADC_DW.Memory1_PreviousInput[0] = ADC_B.Memory_j[0];
    /* Update for Memory: '<S2>/Memory' */
    ADC_DW.Memory_PreviousInput_h[0] = ADC_B.r_ECI[0];
    /* Update for Memory: '<S2>/Memory1' */
    ADC_DW.Memory1_PreviousInput[1] = ADC_B.Memory_j[1];
    /* Update for Memory: '<S2>/Memory' */
    ADC_DW.Memory_PreviousInput_h[1] = ADC_B.r_ECI[1];
    /* Update for Memory: '<S2>/Memory1' */
    ADC_DW.Memory1_PreviousInput[2] = ADC_B.Memory_j[2];
    /* Update for Memory: '<S2>/Memory' */
    ADC_DW.Memory_PreviousInput_h[2] = ADC_B.r_ECI[2];
}
/* Update for Integrator: '<S17>/MemoryX' */
ADC_DW.MemoryX_IWORK = 0;




              
  



    
          } /* end MajorTimeStep */
      
          
  
    if (rtmIsMajorTimeStep(ADC_M)) {
  
    
    
        rt_ertODEUpdateContinuousStates(&ADC_M->solverInfo, arg_Magnetic_Measure, arg_Euler_Angle_Measure, arg_Sun_Measure, arg_epoch, arg_lla, arg_v_, arg_S_flag, arg_Magnetic_Dipole_Moment, arg_q_est1);

            /* Update absolute time for base rate */
            /* The "clockTick0" counts the number of times the code of this task has 
    * been executed. The absolute time is the multiplication of "clockTick0" 
    * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not 
    * overflow during the application lifespan selected.
      * Timer of this task consists of two 32 bit unsigned integers. 
      * The two integers represent the low bits Timing.clockTick0 and the high bits 
      * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment. 
    */

    if(!(++ADC_M->Timing.clockTick0)) {
 ++ADC_M->Timing.clockTickH0; 
}  ADC_M->Timing.t[0] = rtsiGetSolverStopTime(&ADC_M->solverInfo);

      
	{
           /* Update absolute timer for sample time: [0.1s, 0.0s] */
	         /* The "clockTick1" counts the number of times the code of this task has 
    * been executed. The resolution of this integer timer is 0.1, which is the step size 
    * of the task. Size of "clockTick1" ensures timer will not overflow during the 
    * application lifespan selected.
      * Timer of this task consists of two 32 bit unsigned integers. 
      * The two integers represent the low bits Timing.clockTick1 and the high bits 
      * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment. 
    */

    ADC_M->Timing.clockTick1++;
 if (!ADC_M->Timing.clockTick1) {
 ADC_M->Timing.clockTickH1++; 
}

	 }

        

    


    
    
  
     } /* end MajorTimeStep */
  

        

      
      
              
        



      
          
  

    } 
                /* Derivatives for root system: '<Root>' */
        
        
    void ADC_derivatives(real_T arg_Magnetic_Measure[3], real_T arg_Euler_Angle_Measure[3], real_T arg_Sun_Measure[3], real_T arg_epoch[6], real_T arg_lla[3], real_T arg_v_[3], real_T *arg_S_flag, real_T arg_Magnetic_Dipole_Moment[3], real_T arg_q_est1[4])
    {
  
      
      
  int32_T i;
XDot_ADC_T *_rtXdot;

    
  



              
    
    
  



                              _rtXdot = ((XDot_ADC_T *) ADC_M->ModelData.derivs);
/* Derivatives for Integrator: '<S17>/MemoryX' */
for (i = 0; i < 6; i++) {
    _rtXdot->MemoryX_CSTATE[i] = ADC_B.Add[i];
}
/* End of Derivatives for Integrator: '<S17>/MemoryX' */





    
  



      
    
        }
    
  






  







  /* Model initialize function */
    void ADC_initialize(void)
  { 
        


    
    
    
    
        
    
    
        /* Registration code */
          
  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  
  



      
          /* initialize real-time model */
          (void) memset((void *)ADC_M, 0,
sizeof(RT_MODEL_ADC_T));
          
  
    
      
        
    {
      /* Setup solver object */

        rtsiSetSimTimeStepPtr(&ADC_M->solverInfo, &ADC_M->Timing.simTimeStep);
      rtsiSetTPtr(&ADC_M->solverInfo, &rtmGetTPtr(ADC_M));
        rtsiSetStepSizePtr(&ADC_M->solverInfo, &ADC_M->Timing.stepSize0);
        rtsiSetdXPtr(&ADC_M->solverInfo, &ADC_M->ModelData.derivs);
        rtsiSetContStatesPtr(&ADC_M->solverInfo, (real_T **) &ADC_M->ModelData.contStates);
        rtsiSetNumContStatesPtr(&ADC_M->solverInfo, &ADC_M->Sizes.numContStates);
          rtsiSetNumPeriodicContStatesPtr(&ADC_M->solverInfo, &ADC_M->Sizes.numPeriodicContStates);
          rtsiSetPeriodicContStateIndicesPtr(&ADC_M->solverInfo, &ADC_M->ModelData.periodicContStateIndices);
          rtsiSetPeriodicContStateRangesPtr(&ADC_M->solverInfo, &ADC_M->ModelData.periodicContStateRanges);
      rtsiSetErrorStatusPtr(&ADC_M->solverInfo, (&rtmGetErrorStatus(ADC_M)));

      
      rtsiSetRTModelPtr(&ADC_M->solverInfo, ADC_M);
    }
      rtsiSetSimTimeStep(&ADC_M->solverInfo, MAJOR_TIME_STEP);
          ADC_M->ModelData.intgData.y = ADC_M->ModelData.odeY;
          ADC_M->ModelData.intgData.f[0] = ADC_M->ModelData.odeF[0];
          ADC_M->ModelData.intgData.f[1] = ADC_M->ModelData.odeF[1];
          ADC_M->ModelData.intgData.f[2] = ADC_M->ModelData.odeF[2];
          ADC_M->ModelData.intgData.f[3] = ADC_M->ModelData.odeF[3];
          
          ADC_M->ModelData.contStates = ((X_ADC_T *) &ADC_X);
          

          
          rtsiSetSolverData(&ADC_M->solverInfo, (void *)&ADC_M->ModelData.intgData);
    rtsiSetSolverName(&ADC_M->solverInfo,"ode4");

    
  

  
      rtmSetTPtr(ADC_M, &ADC_M->Timing.tArray[0]);

  




	    ADC_M->Timing.stepSize0  = 0.1;

      rtmSetFirstInitCond(ADC_M, 1);

      

    

        
  
  

  
  
     

  

    /* block I/O */
    
      
    
        (void) memset(((void *) &ADC_B), 0,
sizeof(B_ADC_T));
        
  
    
  
  
    
      /* states (continuous) */
      {
        
        (void) memset((void *)&ADC_X, 0,
sizeof(X_ADC_T));


      }

    /* states (dwork) */
    
        

    
        
                    
        (void) memset((void *)&ADC_DW,  0,
 sizeof(DW_ADC_T));
        
        

        
    
        
  
    

    


  

    
    /* Initialize DataMapInfo substructure containing ModelMap for C API */
      ADC_InitializeDataMapInfo(ADC_M);
      

  
      
          
    
    
        

    
      
        {
    int32_T i;

                            

    

    
 
    

    
 
/* Start for Constant: '<S17>/X0' */
for (i = 0; i < 6; i++) {
    ADC_B.X0[i] = ADC_P.X0_Value[i];
}
/* End of Start for Constant: '<S17>/X0' */
    

    
 
/* InitializeConditions for Memory: '<S1>/Memory' */
ADC_DW.Memory_PreviousInput[0] = ADC_P.Memory_X0;
/* InitializeConditions for UnitDelay: '<S7>/UD' */
ADC_DW.UD_DSTATE[0] = ADC_P.DiscreteDerivative_ICPrevScaledInput;
/* InitializeConditions for Memory: '<S1>/Memory' */
ADC_DW.Memory_PreviousInput[1] = ADC_P.Memory_X0;
/* InitializeConditions for UnitDelay: '<S7>/UD' */
ADC_DW.UD_DSTATE[1] = ADC_P.DiscreteDerivative_ICPrevScaledInput;
/* InitializeConditions for Memory: '<S1>/Memory' */
ADC_DW.Memory_PreviousInput[2] = ADC_P.Memory_X0;
/* InitializeConditions for UnitDelay: '<S7>/UD' */
ADC_DW.UD_DSTATE[2] = ADC_P.DiscreteDerivative_ICPrevScaledInput;
/* InitializeConditions for Integrator: '<S17>/MemoryX' */
if (rtmIsFirstInitCond(ADC_M)) {
    ADC_X.MemoryX_CSTATE[0] = 0.0;
    ADC_X.MemoryX_CSTATE[1] = 0.0;
    ADC_X.MemoryX_CSTATE[2] = 0.0;
    ADC_X.MemoryX_CSTATE[3] = 0.0;
    ADC_X.MemoryX_CSTATE[4] = 0.0;
    ADC_X.MemoryX_CSTATE[5] = 0.0;
}
ADC_DW.MemoryX_IWORK = 1;
/* End of InitializeConditions for Integrator: '<S17>/MemoryX' */

/* InitializeConditions for Memory: '<S2>/Memory1' */
ADC_DW.Memory1_PreviousInput[0] = ADC_P.Memory1_X0;
/* InitializeConditions for Memory: '<S2>/Memory' */
ADC_DW.Memory_PreviousInput_h[0] = ADC_P.Memory_X0_d;
/* InitializeConditions for Memory: '<S2>/Memory1' */
ADC_DW.Memory1_PreviousInput[1] = ADC_P.Memory1_X0;
/* InitializeConditions for Memory: '<S2>/Memory' */
ADC_DW.Memory_PreviousInput_h[1] = ADC_P.Memory_X0_d;
/* InitializeConditions for Memory: '<S2>/Memory1' */
ADC_DW.Memory1_PreviousInput[2] = ADC_P.Memory1_X0;
/* InitializeConditions for Memory: '<S2>/Memory' */
ADC_DW.Memory_PreviousInput_h[2] = ADC_P.Memory_X0_d;
/* SystemInitialize for MATLAB Function: '<S5>/MATLAB Function' */
memset(&ADC_DW.times[0], 0, 1000000U * sizeof(real_T));
ADC_DW.counter = 1.0;
        







  }


      
    
        
  



      
  

        /* user code (Initialize function Body) */

        /*this is a test that graham wrote
*/
int x = 5;

                
  



            /* set "at time zero" to false */
    if (rtmIsFirstInitCond(ADC_M)) {
      rtmSetFirstInitCond(ADC_M, 0);
    }
    
    
        

  


      
  


  }




        
  


  
    
    /* Model terminate function */
        void ADC_terminate(void)

    {
      

      
                                
  



          
  

        /* user code (Terminate function Body) */

        /*this is a test that graham wrote
*/
int x = 5;

                
            
  



    




          
  

    }
    
  




  
  
   




  


  


  


  


/* 
 * File trailer for generated code.
 * 
 * [EOF]
 */

