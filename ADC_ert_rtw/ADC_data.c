/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ADC_data.c
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

/* Block parameters (auto storage) */
P_ADC_T ADC_P = {
  1.0E-10,                             /* Mask Parameter: Normalization_Bias
                                        * Referenced by: '<S2>/Normalization'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevScaledInput
                                        * Referenced by: '<S6>/UD'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory'
                                        */
  10.0,                                /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S6>/TSamp'
                                        */
  -1.0E+6,                             /* Expression: -1000000
                                        * Referenced by: '<S4>/Gain'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S4>/voltage'
                                        */

  /*  Expression: pInitialization.X0
   * Referenced by: '<S16>/X0'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S5>/voltage'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Switch2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Memory1'
                                        */

  /*  Expression: pInitialization.A
   * Referenced by: '<S16>/A'
   */
  { 0.0, 0.0, 0.0, 3.26658658709613E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    2.93992792838652E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -3.49991420046014E-7, 1.0,
    0.0, 0.0, 0.0, 0.0, -0.000790559724912417, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.00184463935812897, 0.0, 0.0 },

  /*  Expression: pInitialization.B
   * Referenced by: '<S16>/B'
   */
  { 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0 },

  /*  Expression: pInitialization.C
   * Referenced by: '<S16>/C'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  /*  Expression: pInitialization.L
   * Referenced by: '<S21>/KalmanGainL'
   */
  { 1.4177154277384036, -1.2744079657868988E-16, 2.1755604400597929E-8,
    0.0090891436230064564, -1.0331431611546131E-16, -4.3096792905621642E-7,
    -1.2744079657868988E-16, 1.4177154258347824, 3.8858186583332767E-16,
    -2.350437548954545E-17, 0.0090891138924151082, 7.1414128292061062E-17,
    2.1755604400597929E-8, 3.8858186583332767E-16, 1.4177154065222988,
    1.1083603081543271E-6, -1.3100007537895191E-16, 0.0090888140339763727,
    0.9089143623006456, -2.3504375489545452E-15, 0.00011083603081543272,
    14.141843810174137, 4.5106869183648662E-16, 0.00052701802869632014,
    -1.0331431611546131E-14, 0.90891138924151083, -1.3100007537895191E-14,
    4.5106869183648662E-16, 14.141843732170612, 2.3996825255438177E-15,
    -4.3096792905621642E-5, 7.1414128292061059E-15, 0.90888140339763723,
    0.00052701802869632014, 2.3996825255438177E-15, 14.141843500714431 },

  /*  Expression: pInitialization.D
   * Referenced by: '<S16>/D'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Memory'
                                        */
  1                                    /* Computed Parameter: Enable_Value
                                        * Referenced by: '<S16>/Enable'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
