/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ADC.c
 *
 * Code generated for Simulink model 'ADC'.
 *
 * Model version                  : 1.1151
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * C/C++ source code generated on : Fri Oct 28 16:14:12 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ADC.h"
#include "ADC_private.h"

/* Block signals (auto storage) */
B_ADC_T ADC_B;

/* Continuous states */
X_ADC_T ADC_X;

/* Block states (auto storage) */
DW_ADC_T ADC_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_ADC_T ADC_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_ADC_T ADC_Y;

/* Real-time model */
RT_MODEL_ADC_T ADC_M_;
RT_MODEL_ADC_T *const ADC_M = &ADC_M_;

/* Forward declaration for local functions */
static real_T ADC_norm(const real_T x[3]);
static real_T ADC_norm_f(const real_T x[3]);
static real_T ADC_norm_a(const real_T x[3]);
static real_T ADC_norm_g(const real_T x[3]);
static real_T ADC_norm_fj(const real_T x[3]);

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ADC_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  ADC_step();
  ADC_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  ADC_step();
  ADC_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  ADC_step();
  ADC_derivatives();

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
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

/* Function for MATLAB Function: '<S5>/PD Controler' */
static real_T ADC_norm_f(const real_T x[3])
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
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
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
  if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf(u1)))))
  {
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

/* Function for MATLAB Function: '<S19>/Calculator' */
static real_T ADC_norm_a(const real_T x[3])
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
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

/* Function for MATLAB Function: '<S2>/MATLAB Function1' */
static real_T ADC_norm_g(const real_T x[3])
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
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

/* Function for MATLAB Function: '<S2>/ LVLH ' */
static real_T ADC_norm_fj(const real_T x[3])
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
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

/* Model step function */
void ADC_step(void)
{
  /* local block i/o variables */
  real_T rtb_Clock;
  real_T rtb_MemoryX[6];
  boolean_T rtb_HiddenBuf_InsertedFor_MeasurementUpdate_at_inport_3;
  real_T rtb_TSamp[3];
  real_T rtb_Memory[3];
  boolean_T guard1 = false;
  real_T time_diff;
  real_T y;
  real_T scale;
  int32_T k;
  static const real_T a[9] = { 1.57407015004541E-8, 0.0, 0.0, 0.0,
    1.18055261253406E-8, 0.0, 0.0, 0.0, 1.68650373219151E-9 };

  static const real_T b[18] = { 1015.8163712302, 7.60272150440681E-14,
    453.958044168675, 8.04611892244142E-14, 1186.23970592244,
    -1.67413778929006E-14, -453.958044168676, -2.35978593865247E-13,
    600.766687834337, 384003.046505704, 1.08705332006039E-11, -20043.8129028358,
    1.44940442674718E-11, 448289.486640409, 1.35573181939759E-11,
    -187075.587093135, 9.49012273578315E-11, 795987.850800695 };

  static const real_T b_a[18] = { -1015.8163712302, -7.60272150440681E-14,
    -453.958044168675, -8.04611892244142E-14, -1186.23970592244,
    1.67413778929006E-14, 453.958044168676, 2.35978593865247E-13,
    -600.766687834337, -384003.046505704, -1.08705332006039E-11,
    20043.8129028358, -1.44940442674718E-11, -448289.486640409,
    -1.35573181939759E-11, 187075.587093135, -9.49012273578315E-11,
    -795987.850800695 };

  real_T u[3];
  static const real_T b_a_0[9] = { 0.00018667619023324857, 0.0, 0.0, 0.0,
    0.00031112698372208096, 0.0, 0.0, 0.0, 0.00043557777721091334 };

  static const real_T b_b[9] = { 0.06, 0.0, 0.0, 0.0, 0.1, 0.0, 0.0, 0.0, 0.14 };

  real_T GMST;
  real_T lambdaecliptic;
  real_T E;
  real_T y_tmp[3];
  static const int8_T b_0[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  boolean_T c[6];
  real_T rtb_B_o[3];
  real_T rtb_m[3];
  real_T rtb_B1[3];
  real_T rtb_B[3];
  real_T rtb_R_SUN[3];
  real_T rtb_x[6];
  real_T rtb_R_LVLH2b[9];
  int32_T i;
  real_T rtb_B_n[3];
  real_T rtb_B_n_0[3];
  real_T rtb_B_0[3];
  real_T rtb_B_1[3];
  real_T tmp[18];
  real_T b_a_1[3];
  real_T a_0[3];
  real_T rtb_B_n_1[3];
  real_T rtb_B_n_2[9];
  real_T rtb_B_n_3[9];
  real_T rtb_B_n_4[3];
  real_T rtb_B_n_5[9];
  real_T tmp_0[9];
  real_T rtb_Normalization_0[12];
  real_T tmp_1[12];
  real_T tmp_2[4];
  real_T tmp_3[6];
  real_T tmp_4[6];
  real_T rtb_x_0[6];
  int32_T b_data[6];
  int32_T b_sizes;
  real_T rtb_B_g;
  real_T rtb_m_c_idx_0;
  real_T rtb_m_c_idx_1;
  real_T rtb_m_c_idx_2;
  real_T z_idx_2;
  real_T z_idx_1;
  real_T z_idx_0;
  real_T rtb_Normalization_idx_1;
  real_T rtb_Switch2_idx_0;
  real_T rtb_Switch2_idx_1;
  real_T rtb_Switch2_idx_2;
  if (rtmIsMajorTimeStep(ADC_M)) {
    /* set solver stop time */
    if (!(ADC_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ADC_M->solverInfo, ((ADC_M->Timing.clockTickH0 + 1)
        * ADC_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ADC_M->solverInfo, ((ADC_M->Timing.clockTick0 + 1) *
        ADC_M->Timing.stepSize0 + ADC_M->Timing.clockTickH0 *
        ADC_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ADC_M)) {
    ADC_M->Timing.t[0] = rtsiGetT(&ADC_M->solverInfo);
  }

  /* Clock: '<S4>/Clock' */
  rtb_Clock = ADC_M->Timing.t[0];
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
  /* MATLAB Function 'Controller/Decision': '<S3>:1' */
  /* B is output to Detumbler, B1 is output to Pointing Control */
  /* '<S3>:1:3' */
  if (fabs(ADC_norm(ADC_U.w_meas)) >= 0.01) {
    /* '<S3>:1:4' */
    guard1 = true;
  } else {
    a_0[0] = ADC_U.B_meas[0] - ADC_B.Memory[0];
    a_0[1] = ADC_U.B_meas[1] - ADC_B.Memory[1];
    a_0[2] = ADC_U.B_meas[2] - ADC_B.Memory[2];
    if (ADC_norm(a_0) / ADC_norm(ADC_U.B_meas) > 0.05) {
      /* '<S3>:1:4' */
      guard1 = true;
    } else {
      /* '<S3>:1:8' */
      rtb_B_o[0] = 0.0;
      rtb_B_o[1] = 0.0;
      rtb_B_o[2] = 0.0;

      /* '<S3>:1:9' */
      rtb_B1[0] = ADC_U.B_meas[0];
      rtb_B1[1] = ADC_U.B_meas[1];
      rtb_B1[2] = ADC_U.B_meas[2];

      /* '<S3>:1:10' */
    }
  }

  if (guard1) {
    /* '<S3>:1:5' */
    rtb_B_o[0] = ADC_U.B_meas[0];
    rtb_B_o[1] = ADC_U.B_meas[1];
    rtb_B_o[2] = ADC_U.B_meas[2];

    /* '<S3>:1:6' */
    rtb_B1[0] = 0.0;
    rtb_B1[1] = 0.0;
    rtb_B1[2] = 0.0;
  }

  /* End of MATLAB Function: '<S1>/Decision' */

  /* MATLAB Function: '<S4>/MATLAB Function' */
  /* MATLAB Function 'Controller/Detumble /MATLAB Function': '<S7>:1' */
  /* '<S7>:1:5' */
  time_diff = 1.0;
  scale = 2.2250738585072014E-308;
  E = fabs(rtb_B_o[0]);
  if (E > 2.2250738585072014E-308) {
    y = 1.0;
    scale = E;
  } else {
    GMST = E / 2.2250738585072014E-308;
    y = GMST * GMST;
  }

  E = fabs(rtb_B_o[1]);
  if (E > scale) {
    GMST = scale / E;
    y = y * GMST * GMST + 1.0;
    scale = E;
  } else {
    GMST = E / scale;
    y += GMST * GMST;
  }

  E = fabs(rtb_B_o[2]);
  if (E > scale) {
    GMST = scale / E;
    y = y * GMST * GMST + 1.0;
    scale = E;
  } else {
    GMST = E / scale;
    y += GMST * GMST;
  }

  y = scale * sqrt(y);
  if (y > 0.0) {
    /* '<S7>:1:12' */
    /* '<S7>:1:13' */
    ADC_DW.times[(int32_T)ADC_DW.counter - 1] = rtb_Clock;
    if (ADC_DW.counter > 1.0) {
      /* '<S7>:1:14' */
      /* '<S7>:1:15' */
      time_diff = ADC_DW.times[(int32_T)ADC_DW.counter - 1] - ADC_DW.times
        [(int32_T)(ADC_DW.counter - 1.0) - 1];
    }

    if (time_diff >= 1.0) {
      /* '<S7>:1:17' */
      /* '<S7>:1:18' */
      time_diff = 0.0;
    } else {
      /* '<S7>:1:20' */
      time_diff = 1.0;

      /*          counter=1; */
      if (ADC_DW.counter == 1.0E+6) {
        /* '<S7>:1:23' */
        /* '<S7>:1:24' */
        ADC_DW.counter = 1.0;

        /* '<S7>:1:25' */
        memset(&ADC_DW.times[0], 0, 1000000U * sizeof(real_T));
      }
    }

    /* '<S7>:1:29' */
    ADC_DW.counter++;
  } else {
    /* '<S7>:1:31' */
    time_diff = 0.0;
  }

  /* End of MATLAB Function: '<S4>/MATLAB Function' */

  /* Product: '<S4>/Product4' */
  ADC_B.Product4[0] = time_diff * rtb_B_o[0];
  ADC_B.Product4[1] = time_diff * rtb_B_o[1];
  ADC_B.Product4[2] = time_diff * rtb_B_o[2];
  if (rtmIsMajorTimeStep(ADC_M)) {
    /* SampleTimeMath: '<S6>/TSamp'
     *
     * About '<S6>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_TSamp[0] = ADC_B.Product4[0] * ADC_P.TSamp_WtEt;
    rtb_TSamp[1] = ADC_B.Product4[1] * ADC_P.TSamp_WtEt;
    rtb_TSamp[2] = ADC_B.Product4[2] * ADC_P.TSamp_WtEt;

    /* Sum: '<S6>/Diff' incorporates:
     *  UnitDelay: '<S6>/UD'
     */
    ADC_B.Diff[0] = rtb_TSamp[0] - ADC_DW.UD_DSTATE[0];
    ADC_B.Diff[1] = rtb_TSamp[1] - ADC_DW.UD_DSTATE[1];
    ADC_B.Diff[2] = rtb_TSamp[2] - ADC_DW.UD_DSTATE[2];

    /* Gain: '<S4>/Gain' */
    rtb_B_o[0] = ADC_P.Gain_Gain * ADC_B.Diff[0];
    rtb_B_o[1] = ADC_P.Gain_Gain * ADC_B.Diff[1];
    rtb_B_o[2] = ADC_P.Gain_Gain * ADC_B.Diff[2];

    /* MATLAB Function: '<S4>/saturator and power monitor' */
    /* MATLAB Function 'Controller/Detumble /saturator and power monitor': '<S8>:1' */
    /* '<S8>:1:5' */
    /* '<S8>:1:7' */
    /* Saturator */
    if (fabs(rtb_B_o[0]) > 0.2) {
      /* '<S8>:1:11' */
      /* '<S8>:1:12' */
      if (rtb_B_o[0] < 0.0) {
        lambdaecliptic = -1.0;
      } else if (rtb_B_o[0] > 0.0) {
        lambdaecliptic = 1.0;
      } else if (rtb_B_o[0] == 0.0) {
        lambdaecliptic = 0.0;
      } else {
        lambdaecliptic = rtb_B_o[0];
      }

      ADC_B.m[0] = 0.2 * lambdaecliptic;
    } else {
      /* '<S8>:1:14' */
      ADC_B.m[0] = rtb_B_o[0];
    }

    if (fabs(rtb_B_o[1]) > 0.2) {
      /* '<S8>:1:17' */
      /* '<S8>:1:18' */
      if (rtb_B_o[1] < 0.0) {
        lambdaecliptic = -1.0;
      } else if (rtb_B_o[1] > 0.0) {
        lambdaecliptic = 1.0;
      } else if (rtb_B_o[1] == 0.0) {
        lambdaecliptic = 0.0;
      } else {
        lambdaecliptic = rtb_B_o[1];
      }

      ADC_B.m[1] = 0.2 * lambdaecliptic;
    } else {
      /* '<S8>:1:20' */
      ADC_B.m[1] = rtb_B_o[1];
    }

    if (fabs(rtb_B_o[2]) > 0.2) {
      /* '<S8>:1:23' */
      /* '<S8>:1:24' */
      if (rtb_B_o[2] < 0.0) {
        lambdaecliptic = -1.0;
      } else if (rtb_B_o[2] > 0.0) {
        lambdaecliptic = 1.0;
      } else if (rtb_B_o[2] == 0.0) {
        lambdaecliptic = 0.0;
      } else {
        lambdaecliptic = rtb_B_o[2];
      }

      ADC_B.m[2] = 0.2 * lambdaecliptic;
    } else {
      /* '<S8>:1:26' */
      ADC_B.m[2] = rtb_B_o[2];
    }

    /* End of MATLAB Function: '<S4>/saturator and power monitor' */

    /* Constant: '<S16>/X0' */
    /* Power Monitor */
    /* '<S8>:1:29' */
    /* '<S8>:1:30' */
    for (i = 0; i < 6; i++) {
      ADC_B.X0[i] = ADC_P.X0_Value[i];
    }

    /* End of Constant: '<S16>/X0' */
  }

  /* Integrator: '<S16>/MemoryX' */
  if (ADC_DW.MemoryX_IWORK.IcNeedsLoading) {
    {
      int_T i1;
      real_T *xc = &ADC_X.MemoryX_CSTATE[0];
      const real_T *u1 = &ADC_B.X0[0];
      for (i1=0; i1 < 6; i1++) {
        xc[i1] = u1[i1];
      }
    }
  }

  {
    int_T i1;
    real_T *y0 = &rtb_MemoryX[0];
    real_T *xc = &ADC_X.MemoryX_CSTATE[0];
    for (i1=0; i1 < 6; i1++) {
      y0[i1] = xc[i1];
    }
  }

  /* MATLAB Function: '<S5>/LQR Controller' */
  /* MATLAB Function 'Controller/Pointing/LQR Controller': '<S9>:1' */
  /* maximum magnetic moment */
  /* '<S9>:1:4' */
  /* '<S9>:1:5' */
  /*  Main Controller */
  /* '<S9>:1:9' */
  /* '<S9>:1:39' */
  rtb_B_n_2[0] = 0.0;
  rtb_B_n_2[3] = -rtb_B1[2];
  rtb_B_n_2[6] = rtb_B1[1];
  rtb_B_n_2[1] = rtb_B1[2];
  rtb_B_n_2[4] = 0.0;
  rtb_B_n_2[7] = -rtb_B1[0];
  rtb_B_n_2[2] = -rtb_B1[1];
  rtb_B_n_2[5] = rtb_B1[0];
  rtb_B_n_2[8] = 0.0;
  for (k = 0; k < 3; k++) {
    rtb_B_n_3[3 * k] = -rtb_B_n_2[3 * k];
    rtb_B_n_3[1 + 3 * k] = -rtb_B_n_2[3 * k + 1];
    rtb_B_n_3[2 + 3 * k] = -rtb_B_n_2[3 * k + 2];
  }

  for (k = 0; k < 3; k++) {
    for (i = 0; i < 6; i++) {
      tmp[k + 3 * i] = 0.0;
      tmp[k + 3 * i] += b[3 * i] * rtb_B_n_3[k];
      tmp[k + 3 * i] += b[3 * i + 1] * rtb_B_n_3[k + 3];
      tmp[k + 3 * i] += b[3 * i + 2] * rtb_B_n_3[k + 6];
    }
  }

  for (k = 0; k < 3; k++) {
    rtb_B_o[k] = 0.0;
    for (i = 0; i < 6; i++) {
      rtb_B_o[k] += tmp[3 * i + k] * rtb_MemoryX[i];
    }
  }

  /* '<S9>:1:10' */
  /* '<S9>:1:11' */
  /* Saturator */
  if (fabs(rtb_B_o[0]) > 0.2) {
    /* '<S9>:1:14' */
    /* '<S9>:1:15' */
    if (rtb_B_o[0] < 0.0) {
      lambdaecliptic = -1.0;
    } else if (rtb_B_o[0] > 0.0) {
      lambdaecliptic = 1.0;
    } else if (rtb_B_o[0] == 0.0) {
      lambdaecliptic = 0.0;
    } else {
      lambdaecliptic = rtb_B_o[0];
    }

    rtb_m_c_idx_0 = 0.2 * lambdaecliptic;
  } else {
    /* '<S9>:1:17' */
    rtb_m_c_idx_0 = rtb_B_o[0];
  }

  if (fabs(rtb_B_o[1]) > 0.2) {
    /* '<S9>:1:20' */
    /* '<S9>:1:21' */
    if (rtb_B_o[1] < 0.0) {
      lambdaecliptic = -1.0;
    } else if (rtb_B_o[1] > 0.0) {
      lambdaecliptic = 1.0;
    } else if (rtb_B_o[1] == 0.0) {
      lambdaecliptic = 0.0;
    } else {
      lambdaecliptic = rtb_B_o[1];
    }

    rtb_m_c_idx_1 = 0.2 * lambdaecliptic;
  } else {
    /* '<S9>:1:23' */
    rtb_m_c_idx_1 = rtb_B_o[1];
  }

  if (fabs(rtb_B_o[2]) > 0.2) {
    /* '<S9>:1:26' */
    /* '<S9>:1:27' */
    if (rtb_B_o[2] < 0.0) {
      lambdaecliptic = -1.0;
    } else if (rtb_B_o[2] > 0.0) {
      lambdaecliptic = 1.0;
    } else if (rtb_B_o[2] == 0.0) {
      lambdaecliptic = 0.0;
    } else {
      lambdaecliptic = rtb_B_o[2];
    }

    rtb_m_c_idx_2 = 0.2 * lambdaecliptic;
  } else {
    /* '<S9>:1:29' */
    rtb_m_c_idx_2 = rtb_B_o[2];
  }

  /* MATLAB Function: '<S5>/PD Controler' incorporates:
   *  Inport: '<Root>/Euler Angle Measure'
   */
  /* Power Monitor */
  /* '<S9>:1:32' */
  /* '<S9>:1:33' */
  /* MATLAB Function 'Controller/Pointing/PD Controler': '<S10>:1' */
  /* maximum magnetic moment */
  /* '<S10>:1:4' */
  /* '<S10>:1:5' */
  /* Full Mule */
  /* centroidal moment of inertia sans reaction wheel system (kg-m^2) */
  /* '<S10>:1:15' */
  rtb_B_o[0] = ADC_U.w_meas[0];
  rtb_B_o[1] = ADC_U.w_meas[1] + 0.0011;
  rtb_B_o[2] = ADC_U.w_meas[2];

  /*  Main PID Controller */
  /* '<S10>:1:18' */
  /* '<S10>:1:19' */
  /* '<S10>:1:63' */
  /*  from Wie et. al */
  /* '<S10>:1:26' */
  rtb_B_n_5[0] = 0.0;
  rtb_B_n_5[3] = -ADC_U.w_meas[2];
  rtb_B_n_5[6] = ADC_U.w_meas[1] + 0.0011;
  rtb_B_n_5[1] = ADC_U.w_meas[2];
  rtb_B_n_5[4] = 0.0;
  rtb_B_n_5[7] = -ADC_U.w_meas[0];
  rtb_B_n_5[2] = -(ADC_U.w_meas[1] + 0.0011);
  rtb_B_n_5[5] = ADC_U.w_meas[0];
  rtb_B_n_5[8] = 0.0;
  for (k = 0; k < 3; k++) {
    rtb_B_n_2[3 * k] = -rtb_B_n_5[3 * k];
    rtb_B_n_2[1 + 3 * k] = -rtb_B_n_5[3 * k + 1];
    rtb_B_n_2[2 + 3 * k] = -rtb_B_n_5[3 * k + 2];
  }

  for (k = 0; k < 3; k++) {
    for (i = 0; i < 3; i++) {
      rtb_B_n_3[k + 3 * i] = 0.0;
      rtb_B_n_3[k + 3 * i] += b_b[3 * i] * rtb_B_n_2[k];
      rtb_B_n_3[k + 3 * i] += b_b[3 * i + 1] * rtb_B_n_2[k + 3];
      rtb_B_n_3[k + 3 * i] += b_b[3 * i + 2] * rtb_B_n_2[k + 6];
    }
  }

  for (k = 0; k < 3; k++) {
    a_0[k] = rtb_B_n_3[k + 6] * rtb_B_o[2] + (rtb_B_n_3[k + 3] * rtb_B_o[1] +
      rtb_B_n_3[k] * rtb_B_o[0]);
  }

  for (k = 0; k < 3; k++) {
    b_a_1[k] = b_a_0[k + 6] * rtb_B_o[2] + (b_a_0[k + 3] * rtb_B_o[1] + b_a_0[k]
      * rtb_B_o[0]);
  }

  for (k = 0; k < 3; k++) {
    u[k] = (a_0[k] - b_a_1[k]) - ((0.0 * rtb_MemoryX[0] + 0.0 * rtb_MemoryX[1])
      + 0.0 * rtb_MemoryX[2]);
  }

  if (ADC_norm_f(rtb_B1) > 0.0) {
    /* '<S10>:1:28' */
    /* '<S10>:1:29' */
    time_diff = ADC_norm_f(rtb_B1);
    time_diff *= time_diff;
    rtb_B_o[0] = (rtb_B1[1] * u[2] - rtb_B1[2] * u[1]) / time_diff;
    rtb_B_o[1] = (rtb_B1[2] * u[0] - rtb_B1[0] * u[2]) / time_diff;
    rtb_B_o[2] = (rtb_B1[0] * u[1] - rtb_B1[1] * u[0]) / time_diff;
  } else {
    /* '<S10>:1:31' */
    rtb_B_o[0] = 0.0;
    rtb_B_o[1] = 0.0;
    rtb_B_o[2] = 0.0;
  }

  /* Saturator */
  if (fabs(rtb_B_o[0]) > 0.2) {
    /* '<S10>:1:35' */
    /* '<S10>:1:36' */
    if (rtb_B_o[0] < 0.0) {
      lambdaecliptic = -1.0;
    } else if (rtb_B_o[0] > 0.0) {
      lambdaecliptic = 1.0;
    } else if (rtb_B_o[0] == 0.0) {
      lambdaecliptic = 0.0;
    } else {
      lambdaecliptic = rtb_B_o[0];
    }

    rtb_m[0] = 0.2 * lambdaecliptic;
  } else {
    /* '<S10>:1:38' */
    rtb_m[0] = rtb_B_o[0];
  }

  if (fabs(rtb_B_o[1]) > 0.2) {
    /* '<S10>:1:41' */
    /* '<S10>:1:42' */
    if (rtb_B_o[1] < 0.0) {
      lambdaecliptic = -1.0;
    } else if (rtb_B_o[1] > 0.0) {
      lambdaecliptic = 1.0;
    } else if (rtb_B_o[1] == 0.0) {
      lambdaecliptic = 0.0;
    } else {
      lambdaecliptic = rtb_B_o[1];
    }

    rtb_m[1] = 0.2 * lambdaecliptic;
  } else {
    /* '<S10>:1:44' */
    rtb_m[1] = rtb_B_o[1];
  }

  if (fabs(rtb_B_o[2]) > 0.2) {
    /* '<S10>:1:47' */
    /* '<S10>:1:48' */
    if (rtb_B_o[2] < 0.0) {
      lambdaecliptic = -1.0;
    } else if (rtb_B_o[2] > 0.0) {
      lambdaecliptic = 1.0;
    } else if (rtb_B_o[2] == 0.0) {
      lambdaecliptic = 0.0;
    } else {
      lambdaecliptic = rtb_B_o[2];
    }

    rtb_m[2] = 0.2 * lambdaecliptic;
  } else {
    /* '<S10>:1:50' */
    rtb_m[2] = rtb_B_o[2];
  }

  /* Switch: '<S5>/Switch' incorporates:
   *  Inport: '<Root>/S_flag'
   */
  /* Power Monitor */
  /* '<S10>:1:53' */
  /* '<S10>:1:54' */
  /*  control torque */
  /* '<S10>:1:57' */
  if (!(ADC_U.S_flag > ADC_P.Switch_Threshold)) {
    rtb_m_c_idx_0 = rtb_m[0];
  }

  /* Outport: '<Root>/Magnetic Dipole Moment' incorporates:
   *  Sum: '<S1>/Sum'
   */
  ADC_Y.MagneticDipoleMoment[0] = ADC_B.m[0] + rtb_m_c_idx_0;

  /* Switch: '<S5>/Switch' incorporates:
   *  Inport: '<Root>/S_flag'
   */
  if (!(ADC_U.S_flag > ADC_P.Switch_Threshold)) {
    rtb_m_c_idx_1 = rtb_m[1];
  }

  /* Outport: '<Root>/Magnetic Dipole Moment' incorporates:
   *  Sum: '<S1>/Sum'
   */
  ADC_Y.MagneticDipoleMoment[1] = ADC_B.m[1] + rtb_m_c_idx_1;

  /* Switch: '<S5>/Switch' incorporates:
   *  Inport: '<Root>/S_flag'
   */
  if (!(ADC_U.S_flag > ADC_P.Switch_Threshold)) {
    rtb_m_c_idx_2 = rtb_m[2];
  }

  /* Outport: '<Root>/Magnetic Dipole Moment' incorporates:
   *  Sum: '<S1>/Sum'
   */
  ADC_Y.MagneticDipoleMoment[2] = ADC_B.m[2] + rtb_m_c_idx_2;

  /* MATLAB Function: '<S5>/LQR Controller' incorporates:
   *  Switch: '<S5>/Switch2'
   */
  for (k = 0; k < 3; k++) {
    b_a_1[k] = 0.0;
    for (i = 0; i < 6; i++) {
      b_a_1[k] += b_a[3 * i + k] * rtb_MemoryX[i];
    }
  }

  for (k = 0; k < 3; k++) {
    a_0[k] = a[k + 6] * b_a_1[2] + (a[k + 3] * b_a_1[1] + a[k] * b_a_1[0]);
  }

  /* Switch: '<S5>/Switch2' incorporates:
   *  Inport: '<Root>/S_flag'
   *  MATLAB Function: '<S5>/PD Controler'
   */
  if (ADC_U.S_flag > ADC_P.Switch2_Threshold) {
    rtb_Switch2_idx_0 = a_0[0];
    rtb_Switch2_idx_1 = a_0[1];
    rtb_Switch2_idx_2 = a_0[2];
  } else {
    rtb_Switch2_idx_0 = rtb_m[1] * rtb_B1[2] - rtb_m[2] * rtb_B1[1];
    rtb_Switch2_idx_1 = rtb_m[2] * rtb_B1[0] - rtb_m[0] * rtb_B1[2];
    rtb_Switch2_idx_2 = rtb_m[0] * rtb_B1[1] - rtb_m[1] * rtb_B1[0];
  }

  /* MATLAB Function: '<S19>/Calculator' incorporates:
   *  Inport: '<Root>/epoch'
   *  Inport: '<Root>/r'
   */
  /* MATLAB Function 'Estimator/Space Environment/Calculator': '<S65>:1' */
  /* Compute the Julian Date (JD) from a Gregorian Date (UT1) input */
  /* '<S65>:1:5' */
  /* (year) */
  /* '<S65>:1:6' */
  /* (month) */
  /* '<S65>:1:7' */
  /* (day) */
  /* '<S65>:1:8' */
  /* (hr) */
  /* '<S65>:1:9' */
  /* (min) */
  /* '<S65>:1:10' */
  /* (sec) */
  /* '<S65>:1:11' */
  /* (JD) */
  /* Compute the Universal Time (UT) from JD */
  /* '<S65>:1:14' */
  scale = ((((((367.0 * ADC_U.epoch[0] - floor((floor((ADC_U.epoch[1] + 9.0) /
    12.0) + ADC_U.epoch[0]) * 1.75)) + floor(275.0 * ADC_U.epoch[1] / 9.0)) +
              ADC_U.epoch[2]) + 1.7210135E+6) + ((ADC_U.epoch[5] / 60.0 +
              ADC_U.epoch[4]) / 60.0 + ADC_U.epoch[3]) / 24.0) - 2.451545E+6) /
    36525.0;

  /* Compute the Greenwich Mean Sidereal Time (GMST) from UT */
  /* '<S65>:1:17' */
  /* '<S65>:1:18' */
  time_diff = rt_remd_snf(((3.1644001848128662E+9 * scale + 67310.54841) + scale
    * scale * 0.093104) - 6.2E-6 * rt_powd_snf(scale, 3.0), 86400.0) / 240.0;
  if (time_diff < 0.0) {
    /* '<S65>:1:19' */
    /* '<S65>:1:20' */
    time_diff = -(-time_diff - 360.0);
  }

  /* truncate GMST between 0 and 2pi */
  /* '<S65>:1:23' */
  GMST = time_diff * 3.1415926535897931 / 180.0;

  /* (rad) */
  /* Compute the Direction Cosine Matrix (DCM) for converting vectors in  */
  /* Earth-Centered Inertial (ECI) frame to vectors in Earth-Centered  */
  /* Earth-Fixed (ECEF) frame */
  /* Compute the Sun vector based on the UT */
  /* '<S65>:1:31' */
  /* '<S65>:1:51' */
  /* (°) */
  /* '<S65>:1:52' */
  time_diff = (35999.05034 * scale + 357.5277233) * 3.1415926535897931 / 180.0;

  /* (rad) */
  /* '<S65>:1:53' */
  lambdaecliptic = (((36000.77005361 * scale + 280.4606184) + 1.914666471 * sin
                     (time_diff)) + sin(2.0 * time_diff) * 0.019994643) *
    3.1415926535897931 / 180.0;

  /* (rad) */
  /* '<S65>:1:54' */
  E = (23.439291 - 0.0130042 * scale) * 3.1415926535897931 / 180.0;

  /* (rad) */
  /* '<S65>:1:55' */
  scale = ((1.000140612 - 0.016708617 * cos(time_diff)) - cos(2.0 * time_diff) *
           0.000139589) * 1.49598E+8 * 1000.0;

  /* (m) */
  /* '<S65>:1:56' */
  /* (m) */
  /* Compute the Moon vector based on the UT */
  /* Compute the Earth's magnetic vector in the ECI frame */
  /* '<S65>:1:37' */
  /* 2010 IGRF constants */
  /* '<S65>:1:90' */
  /* '<S65>:1:92' */
  /* '<S65>:1:94' */
  rtb_B_o[0] = cos(GMST + 1.8811352995009261) * 0.17339393238837042;
  rtb_B_o[1] = sin(GMST + 1.8811352995009261) * 0.17339393238837042;

  /* '<S65>:1:98' */
  time_diff = ADC_norm_a(ADC_U.r);
  rtb_B[0] = ADC_U.r[0] / time_diff;
  rtb_B[1] = ADC_U.r[1] / time_diff;
  rtb_B[2] = ADC_U.r[2] / time_diff;

  /* '<S65>:1:100' */
  y = 7.771067126913751E+15 / rt_powd_snf(ADC_norm_a(ADC_U.r), 3.0);
  time_diff = ((rtb_B_o[0] * rtb_B[0] + rtb_B_o[1] * rtb_B[1]) +
               -0.98485254947677181 * rtb_B[2]) * 3.0;

  /* (T) */
  rtb_R_SUN[0] = scale * cos(lambdaecliptic);
  rtb_R_SUN[1] = cos(E) * sin(lambdaecliptic) * scale;
  rtb_R_SUN[2] = sin(E) * sin(lambdaecliptic) * scale;
  rtb_B[0] = (time_diff * rtb_B[0] - rtb_B_o[0]) * y;
  rtb_B[1] = (time_diff * rtb_B[1] - rtb_B_o[1]) * y;
  rtb_B_g = (time_diff * rtb_B[2] - -0.98485254947677181) * y;
  rtb_B[2] = (time_diff * rtb_B[2] - -0.98485254947677181) * y;

  /* End of MATLAB Function: '<S19>/Calculator' */

  /* MATLAB Function: '<S2>/MATLAB Function1' incorporates:
   *  Inport: '<Root>/Magnetic Measure'
   *  Inport: '<Root>/Sun Measure'
   */
  /* MATLAB Function 'Estimator/MATLAB Function1': '<S18>:1' */
  /* '<S18>:1:3' */
  time_diff = ADC_norm_g(ADC_U.B_meas);
  rtb_B_o[0] = ADC_U.B_meas[0] / time_diff;
  rtb_B_o[1] = ADC_U.B_meas[1] / time_diff;
  rtb_B_o[2] = ADC_U.B_meas[2] / time_diff;

  /* '<S18>:1:4' */
  time_diff = ADC_norm_g(ADC_U.S_meas);
  u[0] = ADC_U.S_meas[0] / time_diff;
  u[1] = ADC_U.S_meas[1] / time_diff;
  u[2] = ADC_U.S_meas[2] / time_diff;

  /* '<S18>:1:5' */
  time_diff = ADC_norm_g(rtb_B);
  rtb_B[0] /= time_diff;
  rtb_B[1] /= time_diff;
  rtb_B_g /= time_diff;

  /* '<S18>:1:6' */
  time_diff = ADC_norm_g(rtb_R_SUN);
  rtb_R_SUN[0] /= time_diff;
  rtb_R_SUN[1] /= time_diff;
  rtb_Normalization_idx_1 = rtb_R_SUN[2] / time_diff;

  /* '<S18>:1:9' */
  rtb_B_1[0] = rtb_B[1] * rtb_Normalization_idx_1 - rtb_B_g * rtb_R_SUN[1];
  rtb_B_1[1] = rtb_B_g * rtb_R_SUN[0] - rtb_B[0] * rtb_Normalization_idx_1;
  rtb_B_1[2] = rtb_B[0] * rtb_R_SUN[1] - rtb_B[1] * rtb_R_SUN[0];
  scale = ADC_norm_g(rtb_B_1);

  /* '<S18>:1:10' */
  rtb_m_c_idx_0 = rtb_B[1] * rtb_Normalization_idx_1 - rtb_B_g * rtb_R_SUN[1];
  rtb_m_c_idx_1 = rtb_B_g * rtb_R_SUN[0] - rtb_B[0] * rtb_Normalization_idx_1;
  rtb_m_c_idx_2 = rtb_B[0] * rtb_R_SUN[1] - rtb_B[1] * rtb_R_SUN[0];
  rtb_B_0[0] = rtb_B[1] * rtb_Normalization_idx_1 - rtb_B_g * rtb_R_SUN[1];
  rtb_B_0[1] = rtb_B_g * rtb_R_SUN[0] - rtb_B[0] * rtb_Normalization_idx_1;
  rtb_B_0[2] = rtb_B[0] * rtb_R_SUN[1] - rtb_B[1] * rtb_R_SUN[0];
  GMST = ADC_norm_g(rtb_B_0);

  /* '<S18>:1:13' */
  rtb_B_n_0[0] = rtb_B_o[1] * u[2] - rtb_B_o[2] * u[1];
  rtb_B_n_0[1] = rtb_B_o[2] * u[0] - rtb_B_o[0] * u[2];
  rtb_B_n_0[2] = rtb_B_o[0] * u[1] - rtb_B_o[1] * u[0];
  E = ADC_norm_g(rtb_B_n_0);

  /* '<S18>:1:14' */
  rtb_B1[0] = rtb_B_o[1] * u[2] - rtb_B_o[2] * u[1];
  rtb_B1[1] = rtb_B_o[2] * u[0] - rtb_B_o[0] * u[2];
  rtb_B1[2] = rtb_B_o[0] * u[1] - rtb_B_o[1] * u[0];
  rtb_B_n[0] = rtb_B_o[1] * u[2] - rtb_B_o[2] * u[1];
  rtb_B_n[1] = rtb_B_o[2] * u[0] - rtb_B_o[0] * u[2];
  rtb_B_n[2] = rtb_B_o[0] * u[1] - rtb_B_o[1] * u[0];
  y = ADC_norm_g(rtb_B_n);

  /* '<S18>:1:16' */
  if (rtmIsMajorTimeStep(ADC_M)) {
    /* Sum: '<S2>/Sum' incorporates:
     *  Inport: '<Root>/r'
     *  Memory: '<S2>/Memory1'
     */
    rtb_m[0] = ADC_U.r[0] - ADC_DW.Memory1_PreviousInput[0];
    rtb_m[1] = ADC_U.r[1] - ADC_DW.Memory1_PreviousInput[1];
    rtb_m[2] = ADC_U.r[2] - ADC_DW.Memory1_PreviousInput[2];

    /* MATLAB Function: '<S2>/ LVLH ' incorporates:
     *  Inport: '<Root>/r'
     */
    /* MATLAB Function 'Estimator/ LVLH ': '<S14>:1' */
    /* % create Local Horizontal Local Vertical Coordinates */
    /* '<S14>:1:4' */
    /* '<S14>:1:21' */
    time_diff = ADC_norm_fj(ADC_U.r);
    z_idx_0 = -(ADC_U.r[0] / time_diff);
    z_idx_1 = -(ADC_U.r[1] / time_diff);
    z_idx_2 = -(ADC_U.r[2] / time_diff);
    if (ADC_norm_fj(rtb_m) > 1.0E-8) {
      /* '<S14>:1:6' */
      /*  use this if reasonable velocity estimate from postion change */
      /* '<S14>:1:8' */
      time_diff = (rtb_m[0] * z_idx_0 + rtb_m[1] * z_idx_1) + rtb_m[2] * z_idx_2;
      rtb_m[0] -= time_diff * z_idx_0;
      rtb_m[1] -= time_diff * z_idx_1;
      lambdaecliptic = rtb_m[2] - time_diff * z_idx_2;
      rtb_m[2] -= time_diff * z_idx_2;

      /* '<S14>:1:21' */
      time_diff = ADC_norm_fj(rtb_m);
      rtb_m[0] /= time_diff;
      rtb_m[1] /= time_diff;
      lambdaecliptic /= time_diff;
      rtb_m[2] = lambdaecliptic;

      /* '<S14>:1:9' */
      y_tmp[0] = z_idx_1 * lambdaecliptic - z_idx_2 * rtb_m[1];
      y_tmp[1] = z_idx_2 * rtb_m[0] - z_idx_0 * lambdaecliptic;
      y_tmp[2] = z_idx_0 * rtb_m[1] - z_idx_1 * rtb_m[0];
    } else {
      /*  assume polar and use geometry to find velocity direction */
      /* '<S14>:1:12' */
      lambdaecliptic = 0.0 * ADC_U.r[0] + -ADC_U.r[1];
      y_tmp[0] = lambdaecliptic;
      y_tmp[1] = 0.0 * ADC_U.r[1] + ADC_U.r[0];
      y_tmp[2] = 0.0;

      /* '<S14>:1:21' */
      time_diff = ADC_norm_fj(y_tmp);
      y_tmp[0] = lambdaecliptic / time_diff;
      y_tmp[1] /= time_diff;
      y_tmp[2] = 0.0 / time_diff;

      /* '<S14>:1:13' */
      time_diff = (y_tmp[0] * z_idx_0 + y_tmp[1] * z_idx_1) + 0.0 / time_diff *
        z_idx_2;
      y_tmp[0] -= time_diff * z_idx_0;
      y_tmp[1] -= time_diff * z_idx_1;
      lambdaecliptic = y_tmp[2] - time_diff * z_idx_2;
      y_tmp[2] -= time_diff * z_idx_2;

      /* '<S14>:1:21' */
      time_diff = ADC_norm_fj(y_tmp);
      y_tmp[0] /= time_diff;
      y_tmp[1] /= time_diff;
      lambdaecliptic /= time_diff;
      y_tmp[2] = lambdaecliptic;

      /* '<S14>:1:14' */
      rtb_m[0] = y_tmp[1] * z_idx_2 - lambdaecliptic * z_idx_1;
      rtb_m[1] = lambdaecliptic * z_idx_0 - y_tmp[0] * z_idx_2;
      rtb_m[2] = y_tmp[0] * z_idx_1 - y_tmp[1] * z_idx_0;
    }

    /* Math: '<S2>/Math Function1' incorporates:
     *  MATLAB Function: '<S2>/ LVLH '
     */
    /* '<S14>:1:17' */
    ADC_B.MathFunction1[0] = rtb_m[0];
    ADC_B.MathFunction1[1] = rtb_m[1];
    ADC_B.MathFunction1[2] = rtb_m[2];
    ADC_B.MathFunction1[3] = y_tmp[0];
    ADC_B.MathFunction1[4] = y_tmp[1];
    ADC_B.MathFunction1[5] = y_tmp[2];
    ADC_B.MathFunction1[6] = z_idx_0;
    ADC_B.MathFunction1[7] = z_idx_1;
    ADC_B.MathFunction1[8] = z_idx_2;
  }

  /* MATLAB Function: '<S2>/MATLAB Function1' incorporates:
   *  Product: '<S2>/Matrix Multiply'
   */
  rtb_B_n_1[0] = (rtb_B_o[1] * u[2] - rtb_B_o[2] * u[1]) / E;
  rtb_B_n_1[1] = (rtb_B_o[2] * u[0] - rtb_B_o[0] * u[2]) / E;
  rtb_B_n_1[2] = (rtb_B_o[0] * u[1] - rtb_B_o[1] * u[0]) / E;
  z_idx_1 = (rtb_B[1] * rtb_Normalization_idx_1 - rtb_B_g * rtb_R_SUN[1]) /
    scale;
  z_idx_0 = (rtb_B_g * rtb_R_SUN[0] - rtb_B[0] * rtb_Normalization_idx_1) /
    scale;
  lambdaecliptic = (rtb_B[0] * rtb_R_SUN[1] - rtb_B[1] * rtb_R_SUN[0]) / scale;
  for (k = 0; k < 3; k++) {
    rtb_B_n_2[k] = rtb_B_o[k] * rtb_B[0];
    rtb_B_n_2[k + 3] = rtb_B_o[k] * rtb_B[1];
    rtb_B_n_2[k + 6] = rtb_B_o[k] * rtb_B_g;
  }

  for (k = 0; k < 3; k++) {
    rtb_B_n_3[k] = rtb_B_n_1[k] * z_idx_1;
    rtb_B_n_3[k + 3] = rtb_B_n_1[k] * z_idx_0;
    rtb_B_n_3[k + 6] = rtb_B_n_1[k] * lambdaecliptic;
  }

  rtb_B_n_4[0] = (rtb_B_o[1] * rtb_B1[2] - rtb_B_o[2] * rtb_B1[1]) / y;
  rtb_B_n_4[1] = (rtb_B_o[2] * rtb_B1[0] - rtb_B_o[0] * rtb_B1[2]) / y;
  rtb_B_n_4[2] = (rtb_B_o[0] * rtb_B1[1] - rtb_B_o[1] * rtb_B1[0]) / y;
  z_idx_1 = (rtb_B[1] * rtb_m_c_idx_2 - rtb_B_g * rtb_m_c_idx_1) / GMST;
  z_idx_0 = (rtb_B_g * rtb_m_c_idx_0 - rtb_B[0] * rtb_m_c_idx_2) / GMST;
  lambdaecliptic = (rtb_B[0] * rtb_m_c_idx_1 - rtb_B[1] * rtb_m_c_idx_0) / GMST;
  for (k = 0; k < 3; k++) {
    rtb_B_n_5[k] = (rtb_B_n_2[k] + rtb_B_n_3[k]) + rtb_B_n_4[k] * z_idx_1;
    rtb_B_n_5[k + 3] = (rtb_B_n_2[k + 3] + rtb_B_n_3[k + 3]) + rtb_B_n_4[k] *
      z_idx_0;
    rtb_B_n_5[k + 6] = (rtb_B_n_2[k + 6] + rtb_B_n_3[k + 6]) + rtb_B_n_4[k] *
      lambdaecliptic;
  }

  /* Product: '<S2>/Matrix Multiply' */
  for (k = 0; k < 3; k++) {
    for (i = 0; i < 3; i++) {
      rtb_R_LVLH2b[k + 3 * i] = 0.0;
      rtb_R_LVLH2b[k + 3 * i] += ADC_B.MathFunction1[3 * i] * rtb_B_n_5[k];
      rtb_R_LVLH2b[k + 3 * i] += ADC_B.MathFunction1[3 * i + 1] * rtb_B_n_5[k +
        3];
      rtb_R_LVLH2b[k + 3 * i] += ADC_B.MathFunction1[3 * i + 2] * rtb_B_n_5[k +
        6];
    }
  }

  /* MATLAB Function: '<S2>/DCM to q' */
  /* MATLAB Function 'Estimator/DCM to q': '<S15>:1' */
  /* '<S15>:1:3' */
  /* '<S15>:1:5' */
  GMST = (rtb_R_LVLH2b[0] + rtb_R_LVLH2b[4]) + rtb_R_LVLH2b[8];
  if (!(GMST >= -1.0)) {
    GMST = -1.0;
  }

  z_idx_2 = sqrt(GMST + 1.0) * 0.5;

  /* '<S15>:1:6' */
  lambdaecliptic = (rtb_R_LVLH2b[7] - rtb_R_LVLH2b[5]) / (4.0 * z_idx_2);

  /* '<S15>:1:7' */
  z_idx_0 = (rtb_R_LVLH2b[2] - rtb_R_LVLH2b[6]) / (4.0 * z_idx_2);

  /* '<S15>:1:8' */
  z_idx_1 = (rtb_R_LVLH2b[3] - rtb_R_LVLH2b[1]) / (4.0 * z_idx_2);

  /* End of MATLAB Function: '<S2>/DCM to q' */

  /* S-Function (sdsp2norm2): '<S2>/Normalization' */
  /* '<S15>:1:10' */
  time_diff = 1.0 / ((((lambdaecliptic * lambdaecliptic + z_idx_0 * z_idx_0) +
                       z_idx_1 * z_idx_1) + z_idx_2 * z_idx_2) +
                     ADC_P.Normalization_Bias);
  scale = lambdaecliptic * time_diff;
  rtb_Normalization_idx_1 = z_idx_0 * time_diff;
  E = z_idx_1 * time_diff;
  lambdaecliptic = z_idx_2 * time_diff;

  /* MATLAB Function: '<S2>/State1' incorporates:
   *  Inport: '<Root>/Euler Angle Measure'
   */
  /* MATLAB Function 'Estimator/State1': '<S20>:1' */
  /*  w_r=w+.0011*R(:,2); */
  /*  q_dot=0.5*[q(4) -q(3)  q(2) */
  /*         q(3)  q(4) -q(1) */
  /*         -q(2) q(1)  q(4)]*w_r; */
  /*  orbital rate in rad/sec = 0.0011 */
  /* '<S20>:1:9' */
  /* '<S20>:1:10' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S20>:1:21' */
  /* '<S20>:1:27' */
  /* '<S20>:1:34' */
  /* '<S20>:1:12' */
  /* '<S20>:1:13' */
  tmp_0[0] = 0.0;
  tmp_0[3] = -E;
  tmp_0[6] = rtb_Normalization_idx_1;
  tmp_0[1] = E;
  tmp_0[4] = 0.0;
  tmp_0[7] = -scale;
  tmp_0[2] = -rtb_Normalization_idx_1;
  tmp_0[5] = scale;
  tmp_0[8] = 0.0;
  for (k = 0; k < 3; k++) {
    rtb_Normalization_0[k << 2] = (real_T)b_0[3 * k] * lambdaecliptic + tmp_0[3 *
      k];
    rtb_Normalization_0[1 + (k << 2)] = (real_T)b_0[3 * k + 1] * lambdaecliptic
      + tmp_0[3 * k + 1];
    rtb_Normalization_0[2 + (k << 2)] = (real_T)b_0[3 * k + 2] * lambdaecliptic
      + tmp_0[3 * k + 2];
  }

  rtb_Normalization_0[3] = -scale;
  rtb_Normalization_0[7] = -rtb_Normalization_idx_1;
  rtb_Normalization_0[11] = -E;
  for (k = 0; k < 3; k++) {
    tmp_1[k << 2] = rtb_Normalization_0[k << 2] * 0.5;
    tmp_1[1 + (k << 2)] = rtb_Normalization_0[(k << 2) + 1] * 0.5;
    tmp_1[2 + (k << 2)] = rtb_Normalization_0[(k << 2) + 2] * 0.5;
    tmp_1[3 + (k << 2)] = rtb_Normalization_0[(k << 2) + 3] * 0.5;
  }

  lambdaecliptic = rtb_R_LVLH2b[3] * 0.0011 + ADC_U.w_meas[0];
  z_idx_0 = rtb_R_LVLH2b[4] * 0.0011 + ADC_U.w_meas[1];
  z_idx_1 = rtb_R_LVLH2b[5] * 0.0011 + ADC_U.w_meas[2];
  for (k = 0; k < 4; k++) {
    tmp_2[k] = tmp_1[k + 8] * z_idx_1 + (tmp_1[k + 4] * z_idx_0 + tmp_1[k] *
      lambdaecliptic);
  }

  rtb_x[0] = scale;
  rtb_x[1] = rtb_Normalization_idx_1;
  rtb_x[2] = E;
  rtb_x[3] = tmp_2[0];
  rtb_x[4] = tmp_2[1];
  rtb_x[5] = tmp_2[2];

  /* End of MATLAB Function: '<S2>/State1' */

  /* MATLAB Function: '<S2>/  ' */
  /* MATLAB Function 'Estimator/  ': '<S11>:1' */
  k = 0;
  for (i = 0; i < 6; i++) {
    guard1 = rtIsNaN(rtb_x[i]);
    if (guard1) {
      k++;
    }

    c[i] = guard1;
  }

  b_sizes = k;
  k = 0;
  for (i = 0; i < 6; i++) {
    if (c[i]) {
      b_data[k] = i + 1;
      k++;
    }
  }

  /* '<S11>:1:3' */
  for (k = 0; k < b_sizes; k++) {
    rtb_x[b_data[k] - 1] = 0.0;
  }

  /* End of MATLAB Function: '<S2>/  ' */

  /* SignalConversion: '<S39>/HiddenBuf_InsertedFor_MeasurementUpdate_at_inport_3' incorporates:
   *  Constant: '<S16>/Enable'
   */
  /* '<S11>:1:4' */
  /* MATLAB Function 'Estimator/  1': '<S12>:1' */
  /* '<S12>:1:3' */
  /* '<S12>:1:4' */
  /* MATLAB Function 'Estimator/  2': '<S13>:1' */
  /* '<S13>:1:4' */
  rtb_HiddenBuf_InsertedFor_MeasurementUpdate_at_inport_3 = ADC_P.Enable_Value;

  /* Outputs for Enabled SubSystem: '<S39>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S64>/Enable'
   */
  if (rtmIsMajorTimeStep(ADC_M) && rtmIsMajorTimeStep(ADC_M)) {
    if (rtb_HiddenBuf_InsertedFor_MeasurementUpdate_at_inport_3) {
      if (!ADC_DW.MeasurementUpdate_MODE) {
        ADC_DW.MeasurementUpdate_MODE = true;
      }
    } else {
      if (ADC_DW.MeasurementUpdate_MODE) {
        ADC_DW.MeasurementUpdate_MODE = false;
      }
    }
  }

  if (ADC_DW.MeasurementUpdate_MODE) {
    for (k = 0; k < 6; k++) {
      /* Product: '<S39>/C[k]*xhat[k|k-1]' incorporates:
       *  Constant: '<S16>/C'
       *  Sum: '<S39>/Add1'
       */
      tmp_3[k] = 0.0;
      for (i = 0; i < 6; i++) {
        tmp_3[k] += ADC_P.C_Value[6 * i + k] * rtb_MemoryX[i];
      }

      /* End of Product: '<S39>/C[k]*xhat[k|k-1]' */

      /* Product: '<S39>/D[k-1]*u[k-1]' incorporates:
       *  Constant: '<S16>/D'
       *  Sum: '<S39>/Add1'
       */
      tmp_4[k] = 0.0;
      tmp_4[k] += ADC_P.D_Value[k] * rtb_Switch2_idx_0;
      tmp_4[k] += ADC_P.D_Value[k + 6] * rtb_Switch2_idx_1;
      tmp_4[k] += ADC_P.D_Value[k + 12] * rtb_Switch2_idx_2;

      /* Sum: '<S64>/Sum' incorporates:
       *  Product: '<S64>/Product3'
       *  Sum: '<S39>/Add1'
       */
      rtb_x_0[k] = rtb_x[k] - (tmp_3[k] + tmp_4[k]);
    }

    /* Product: '<S64>/Product3' incorporates:
     *  Constant: '<S21>/KalmanGainL'
     */
    for (k = 0; k < 6; k++) {
      ADC_B.Product3[k] = 0.0;
      for (i = 0; i < 6; i++) {
        ADC_B.Product3[k] += ADC_P.KalmanGainL_Value[6 * i + k] * rtb_x_0[i];
      }
    }
  }

  /* End of Outputs for SubSystem: '<S39>/MeasurementUpdate' */
  for (k = 0; k < 6; k++) {
    /* Product: '<S39>/B[k]*u[k]' incorporates:
     *  Constant: '<S16>/B'
     *  Sum: '<S39>/Add'
     */
    tmp_3[k] = 0.0;
    tmp_3[k] += ADC_P.B_Value[k] * rtb_Switch2_idx_0;
    tmp_3[k] += ADC_P.B_Value[k + 6] * rtb_Switch2_idx_1;
    tmp_3[k] += ADC_P.B_Value[k + 12] * rtb_Switch2_idx_2;

    /* Product: '<S39>/A[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S16>/A'
     *  Sum: '<S39>/Add'
     */
    tmp_4[k] = 0.0;
    for (i = 0; i < 6; i++) {
      tmp_4[k] += ADC_P.A_Value[6 * i + k] * rtb_MemoryX[i];
    }

    /* End of Product: '<S39>/A[k]*xhat[k|k-1]' */

    /* Sum: '<S39>/Add' */
    ADC_B.Add[k] = (tmp_3[k] + tmp_4[k]) + ADC_B.Product3[k];
  }

  /* MATLAB Function 'Estimator/MATLAB Function': '<S17>:1' */
  /* '<S17>:1:3' */
  if (rtmIsMajorTimeStep(ADC_M)) {
    /* Memory: '<S2>/Memory' */
    rtb_Memory[0] = ADC_DW.Memory_PreviousInput_h[0];
    rtb_Memory[1] = ADC_DW.Memory_PreviousInput_h[1];
    rtb_Memory[2] = ADC_DW.Memory_PreviousInput_h[2];
  }

  if (rtmIsMajorTimeStep(ADC_M)) {
    if (rtmIsMajorTimeStep(ADC_M)) {
      /* Update for Memory: '<S1>/Memory' incorporates:
       *  Update for Inport: '<Root>/Magnetic Measure'
       */
      ADC_DW.Memory_PreviousInput[0] = ADC_U.B_meas[0];
      ADC_DW.Memory_PreviousInput[1] = ADC_U.B_meas[1];
      ADC_DW.Memory_PreviousInput[2] = ADC_U.B_meas[2];

      /* Update for UnitDelay: '<S6>/UD' */
      ADC_DW.UD_DSTATE[0] = rtb_TSamp[0];
      ADC_DW.UD_DSTATE[1] = rtb_TSamp[1];
      ADC_DW.UD_DSTATE[2] = rtb_TSamp[2];
    }

    /* Update for Integrator: '<S16>/MemoryX' */
    ADC_DW.MemoryX_IWORK.IcNeedsLoading = 0;
    if (rtmIsMajorTimeStep(ADC_M)) {
      /* Update for Memory: '<S2>/Memory1' */
      ADC_DW.Memory1_PreviousInput[0] = rtb_Memory[0];
      ADC_DW.Memory1_PreviousInput[1] = rtb_Memory[1];
      ADC_DW.Memory1_PreviousInput[2] = rtb_Memory[2];

      /* Update for Memory: '<S2>/Memory' incorporates:
       *  Update for Inport: '<Root>/r'
       */
      ADC_DW.Memory_PreviousInput_h[0] = ADC_U.r[0];
      ADC_DW.Memory_PreviousInput_h[1] = ADC_U.r[1];
      ADC_DW.Memory_PreviousInput_h[2] = ADC_U.r[2];
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(ADC_M)) {
    rt_ertODEUpdateContinuousStates(&ADC_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++ADC_M->Timing.clockTick0)) {
      ++ADC_M->Timing.clockTickH0;
    }

    ADC_M->Timing.t[0] = rtsiGetSolverStopTime(&ADC_M->solverInfo);

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
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void ADC_derivatives(void)
{
  /* Derivatives for Integrator: '<S16>/MemoryX' */
  {
    {
      int_T i1;
      const real_T *u0 = &ADC_B.Add[0];
      real_T *xdot = &((XDot_ADC_T *) ADC_M->ModelData.derivs)->MemoryX_CSTATE[0];
      for (i1=0; i1 < 6; i1++) {
        xdot[i1] = u0[i1];
      }
    }
  }
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
    rtsiSetContStatesPtr(&ADC_M->solverInfo, (real_T **)
                         &ADC_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&ADC_M->solverInfo, &ADC_M->Sizes.numContStates);
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
  ADC_M->Timing.stepSize0 = 0.1;
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
  (void) memset((void *)&ADC_DW, 0,
                sizeof(DW_ADC_T));

  /* external inputs */
  (void) memset((void *)&ADC_U, 0,
                sizeof(ExtU_ADC_T));

  /* external outputs */
  (void) memset(&ADC_Y.MagneticDipoleMoment[0], 0,
                3U*sizeof(real_T));

  {
    int32_T i;

    /* Start for Constant: '<S16>/X0' */
    for (i = 0; i < 6; i++) {
      ADC_B.X0[i] = ADC_P.X0_Value[i];
    }

    /* End of Start for Constant: '<S16>/X0' */

    /* InitializeConditions for Memory: '<S1>/Memory' */
    ADC_DW.Memory_PreviousInput[0] = ADC_P.Memory_X0;
    ADC_DW.Memory_PreviousInput[1] = ADC_P.Memory_X0;
    ADC_DW.Memory_PreviousInput[2] = ADC_P.Memory_X0;

    /* InitializeConditions for MATLAB Function: '<S4>/MATLAB Function' */
    memset(&ADC_DW.times[0], 0, 1000000U * sizeof(real_T));
    ADC_DW.counter = 1.0;

    /* InitializeConditions for UnitDelay: '<S6>/UD' */
    ADC_DW.UD_DSTATE[0] = ADC_P.DiscreteDerivative_ICPrevScaledInput;
    ADC_DW.UD_DSTATE[1] = ADC_P.DiscreteDerivative_ICPrevScaledInput;
    ADC_DW.UD_DSTATE[2] = ADC_P.DiscreteDerivative_ICPrevScaledInput;

    /* InitializeConditions for Integrator: '<S16>/MemoryX' */
    if (rtmIsFirstInitCond(ADC_M)) {
      ADC_X.MemoryX_CSTATE[0] = 0.0;
      ADC_X.MemoryX_CSTATE[1] = 0.0;
      ADC_X.MemoryX_CSTATE[2] = 0.0;
      ADC_X.MemoryX_CSTATE[3] = 0.0;
      ADC_X.MemoryX_CSTATE[4] = 0.0;
      ADC_X.MemoryX_CSTATE[5] = 0.0;
    }

    ADC_DW.MemoryX_IWORK.IcNeedsLoading = 1;

    /* InitializeConditions for Memory: '<S2>/Memory1' */
    ADC_DW.Memory1_PreviousInput[0] = ADC_P.Memory1_X0;
    ADC_DW.Memory1_PreviousInput[1] = ADC_P.Memory1_X0;
    ADC_DW.Memory1_PreviousInput[2] = ADC_P.Memory1_X0;

    /* InitializeConditions for Memory: '<S2>/Memory' */
    ADC_DW.Memory_PreviousInput_h[0] = ADC_P.Memory_X0_d;
    ADC_DW.Memory_PreviousInput_h[1] = ADC_P.Memory_X0_d;
    ADC_DW.Memory_PreviousInput_h[2] = ADC_P.Memory_X0_d;
  }

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(ADC_M)) {
    rtmSetFirstInitCond(ADC_M, 0);
  }
}

/* Model terminate function */
void ADC_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
