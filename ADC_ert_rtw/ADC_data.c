/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ADC_data.c
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

#include "ADC.h"
#include "ADC_private.h"

/* Block parameters (auto storage) */
P_ADC_T ADC_P = {
  1.0E-10,                             /* Mask Parameter: Normalization_Bias
                                        * Referenced by: '<S2>/Normalization'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevScaledInput
                                        * Referenced by: '<S7>/UD'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory'
                                        */
  10.0,                                /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S7>/TSamp'
                                        */
  -1.0E+6,                             /* Expression: -1000000
                                        * Referenced by: '<S5>/Gain'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S5>/voltage'
                                        */

  /*  Expression: pInitialization.X0
   * Referenced by: '<S17>/X0'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S6>/voltage'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Memory1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Switch2'
                                        */

  /*  Expression: pInitialization.A
   * Referenced by: '<S17>/A'
   */
  { 0.0, 0.0, 0.0, 3.26658658709613E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    2.93992792838652E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -3.49991420046014E-7, 1.0,
    0.0, 0.0, 0.0, 0.0, -0.000790559724912417, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.00184463935812897, 0.0, 0.0 },

  /*  Expression: pInitialization.B
   * Referenced by: '<S17>/B'
   */
  { 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0 },

  /*  Expression: pInitialization.C
   * Referenced by: '<S17>/C'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  /*  Expression: pInitialization.L
   * Referenced by: '<S22>/KalmanGainL'
   */
  { 1.4177154277384025, 2.5650525883962236E-16, 2.1755603981485798E-8,
    0.0090891436230066316, -3.8348070227674988E-17, -4.3096792928100906E-7,
    2.5650525883962236E-16, 1.417715425834783, 8.359210572581451E-17,
    -1.3660441867738583E-17, 0.0090891138924151932, 5.5819251421678332E-17,
    2.1755603981485798E-8, 8.359210572581451E-17, 1.4177154065222974,
    1.1083603081978727E-6, -1.1724076396088012E-16, 0.0090888140339763467,
    0.90891436230066314, -1.3660441867738583E-15, 0.00011083603081978727,
    14.141843810174159, 1.7157413398781074E-16, 0.00052701802870377273,
    -3.8348070227674986E-15, 0.90891138924151926, -1.1724076396088011E-14,
    1.7157413398781074E-16, 14.1418437321706, 1.4245465815913488E-16,
    -4.3096792928100907E-5, 5.5819251421678328E-15, 0.90888140339763468,
    0.00052701802870377273, 1.4245465815913488E-16, 14.14184350071444 },

  /*  Expression: pInitialization.D
   * Referenced by: '<S17>/D'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Memory'
                                        */
  1                                    /* Computed Parameter: Enable_Value
                                        * Referenced by: '<S17>/Enable'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
