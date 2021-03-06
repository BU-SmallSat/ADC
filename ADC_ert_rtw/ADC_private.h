/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ADC_private.h
 *
 * Code generated for Simulink model 'ADC'.
 *
 * Model version                  : 1.1171
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Wed Feb 01 13:48:56 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ADC_private_h_
#define RTW_HEADER_ADC_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetFirstInitCond
# define rtmSetFirstInitCond(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
# define rtmIsFirstInitCond(rtm)       ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T rt_roundd_snf(real_T u);
extern real_T rt_remd_snf(real_T u0, real_T u1);

/* private model entry point functions */
extern void ADC_derivatives(real_T arg_Magnetic_Measure[3], real_T
  arg_Euler_Angle_Measure[3], real_T arg_Sun_Measure[3], real_T arg_epoch[6],
  real_T arg_lla[3], real_T arg_v_[3], real_T *arg_S_flag, real_T
  arg_Magnetic_Dipole_Moment[3], real_T arg_q_est1[4]);

#endif                                 /* RTW_HEADER_ADC_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
