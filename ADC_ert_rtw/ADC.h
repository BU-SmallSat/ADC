/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ADC.h
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

#ifndef RTW_HEADER_ADC_h_
#define RTW_HEADER_ADC_h_
#include <float.h>
#include <math.h>
#include <string.h>
#ifndef ADC_COMMON_INCLUDES_
# define ADC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* ADC_COMMON_INCLUDES_ */

#include "ADC_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Memory[3];                    /* '<S1>/Memory' */
  real_T Product4[3];                  /* '<S4>/Product4' */
  real_T Diff[3];                      /* '<S6>/Diff' */
  real_T X0[6];                        /* '<S16>/X0' */
  real_T MathFunction1[9];             /* '<S2>/Math Function1' */
  real_T Add[6];                       /* '<S39>/Add' */
  real_T Product3[6];                  /* '<S64>/Product3' */
  real_T m[3];                         /* '<S4>/saturator and power monitor' */
} B_ADC_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE[3];                 /* '<S6>/UD' */
  real_T Memory_PreviousInput[3];      /* '<S1>/Memory' */
  real_T Memory1_PreviousInput[3];     /* '<S2>/Memory1' */
  real_T Memory_PreviousInput_h[3];    /* '<S2>/Memory' */
  real_T counter;                      /* '<S4>/MATLAB Function' */
  real_T times[1000000];               /* '<S4>/MATLAB Function' */
  struct {
    int_T IcNeedsLoading;
  } MemoryX_IWORK;                     /* '<S16>/MemoryX' */

  boolean_T MeasurementUpdate_MODE;    /* '<S39>/MeasurementUpdate' */
} DW_ADC_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T MemoryX_CSTATE[6];            /* '<S16>/MemoryX' */
} X_ADC_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T MemoryX_CSTATE[6];            /* '<S16>/MemoryX' */
} XDot_ADC_T;

/* State disabled  */
typedef struct {
  boolean_T MemoryX_CSTATE[6];         /* '<S16>/MemoryX' */
} XDis_ADC_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T B_meas[3];                    /* '<Root>/Magnetic Measure' */
  real_T w_meas[3];                    /* '<Root>/Euler Angle Measure' */
  real_T S_meas[3];                    /* '<Root>/Sun Measure' */
  real_T epoch[6];                     /* '<Root>/epoch' */
  real_T r[3];                         /* '<Root>/r' */
  real_T v[3];                         /* '<Root>/v ' */
  real_T S_flag;                       /* '<Root>/S_flag' */
} ExtU_ADC_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T MagneticDipoleMoment[3];      /* '<Root>/Magnetic Dipole Moment' */
} ExtY_ADC_T;

/* Parameters (auto storage) */
struct P_ADC_T_ {
  real_T Normalization_Bias;           /* Mask Parameter: Normalization_Bias
                                        * Referenced by: '<S2>/Normalization'
                                        */
  real_T DiscreteDerivative_ICPrevScaledInput;/* Mask Parameter: DiscreteDerivative_ICPrevScaledInput
                                               * Referenced by: '<S6>/UD'
                                               */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S1>/Memory'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S6>/TSamp'
                                        */
  real_T Gain_Gain;                    /* Expression: -1000000
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T voltage_Value;                /* Expression: 5
                                        * Referenced by: '<S4>/voltage'
                                        */
  real_T X0_Value[6];                  /* Expression: pInitialization.X0
                                        * Referenced by: '<S16>/X0'
                                        */
  real_T voltage_Value_b;              /* Expression: 5
                                        * Referenced by: '<S5>/voltage'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S5>/Switch'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S5>/Switch2'
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<S2>/Memory1'
                                        */
  real_T A_Value[36];                  /* Expression: pInitialization.A
                                        * Referenced by: '<S16>/A'
                                        */
  real_T B_Value[18];                  /* Expression: pInitialization.B
                                        * Referenced by: '<S16>/B'
                                        */
  real_T C_Value[36];                  /* Expression: pInitialization.C
                                        * Referenced by: '<S16>/C'
                                        */
  real_T KalmanGainL_Value[36];        /* Expression: pInitialization.L
                                        * Referenced by: '<S21>/KalmanGainL'
                                        */
  real_T D_Value[18];                  /* Expression: pInitialization.D
                                        * Referenced by: '<S16>/D'
                                        */
  real_T Memory_X0_d;                  /* Expression: 0
                                        * Referenced by: '<S2>/Memory'
                                        */
  boolean_T Enable_Value;              /* Computed Parameter: Enable_Value
                                        * Referenced by: '<S16>/Enable'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ADC_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_ADC_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[6];
    real_T odeF[4][6];
    ODE4_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    boolean_T firstInitCondFlag;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_ADC_T ADC_P;

/* Block signals (auto storage) */
extern B_ADC_T ADC_B;

/* Continuous states (auto storage) */
extern X_ADC_T ADC_X;

/* Block states (auto storage) */
extern DW_ADC_T ADC_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_ADC_T ADC_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_ADC_T ADC_Y;

/* Model entry point functions */
extern void ADC_initialize(void);
extern void ADC_step(void);
extern void ADC_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ADC_T *const ADC_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ADC'
 * '<S1>'   : 'ADC/Controller'
 * '<S2>'   : 'ADC/Estimator'
 * '<S3>'   : 'ADC/Controller/Decision'
 * '<S4>'   : 'ADC/Controller/Detumble '
 * '<S5>'   : 'ADC/Controller/Pointing'
 * '<S6>'   : 'ADC/Controller/Detumble /Discrete Derivative'
 * '<S7>'   : 'ADC/Controller/Detumble /MATLAB Function'
 * '<S8>'   : 'ADC/Controller/Detumble /saturator and power monitor'
 * '<S9>'   : 'ADC/Controller/Pointing/LQR Controller'
 * '<S10>'  : 'ADC/Controller/Pointing/PD Controler'
 * '<S11>'  : 'ADC/Estimator/  '
 * '<S12>'  : 'ADC/Estimator/  1'
 * '<S13>'  : 'ADC/Estimator/  2'
 * '<S14>'  : 'ADC/Estimator/ LVLH '
 * '<S15>'  : 'ADC/Estimator/DCM to q'
 * '<S16>'  : 'ADC/Estimator/Kalman Filter'
 * '<S17>'  : 'ADC/Estimator/MATLAB Function'
 * '<S18>'  : 'ADC/Estimator/MATLAB Function1'
 * '<S19>'  : 'ADC/Estimator/Space Environment'
 * '<S20>'  : 'ADC/Estimator/State1'
 * '<S21>'  : 'ADC/Estimator/Kalman Filter/CalculatePL'
 * '<S22>'  : 'ADC/Estimator/Kalman Filter/CalculateYhat'
 * '<S23>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionA'
 * '<S24>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionB'
 * '<S25>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionC'
 * '<S26>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionD'
 * '<S27>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionG'
 * '<S28>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionH'
 * '<S29>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionN'
 * '<S30>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionP'
 * '<S31>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionP0'
 * '<S32>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionQ'
 * '<S33>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionR'
 * '<S34>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionReset'
 * '<S35>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionX'
 * '<S36>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionX0'
 * '<S37>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionu'
 * '<S38>'  : 'ADC/Estimator/Kalman Filter/MemoryP'
 * '<S39>'  : 'ADC/Estimator/Kalman Filter/Observer'
 * '<S40>'  : 'ADC/Estimator/Kalman Filter/ReducedQRN'
 * '<S41>'  : 'ADC/Estimator/Kalman Filter/ScalarExpansionP0'
 * '<S42>'  : 'ADC/Estimator/Kalman Filter/ScalarExpansionQ'
 * '<S43>'  : 'ADC/Estimator/Kalman Filter/ScalarExpansionR'
 * '<S44>'  : 'ADC/Estimator/Kalman Filter/UseCurrentEstimator'
 * '<S45>'  : 'ADC/Estimator/Kalman Filter/checkA'
 * '<S46>'  : 'ADC/Estimator/Kalman Filter/checkB'
 * '<S47>'  : 'ADC/Estimator/Kalman Filter/checkC'
 * '<S48>'  : 'ADC/Estimator/Kalman Filter/checkD'
 * '<S49>'  : 'ADC/Estimator/Kalman Filter/checkEnable'
 * '<S50>'  : 'ADC/Estimator/Kalman Filter/checkG'
 * '<S51>'  : 'ADC/Estimator/Kalman Filter/checkH'
 * '<S52>'  : 'ADC/Estimator/Kalman Filter/checkN'
 * '<S53>'  : 'ADC/Estimator/Kalman Filter/checkP0'
 * '<S54>'  : 'ADC/Estimator/Kalman Filter/checkQ'
 * '<S55>'  : 'ADC/Estimator/Kalman Filter/checkR'
 * '<S56>'  : 'ADC/Estimator/Kalman Filter/checkReset'
 * '<S57>'  : 'ADC/Estimator/Kalman Filter/checkX0'
 * '<S58>'  : 'ADC/Estimator/Kalman Filter/checku'
 * '<S59>'  : 'ADC/Estimator/Kalman Filter/checky'
 * '<S60>'  : 'ADC/Estimator/Kalman Filter/CalculatePL/DataTypeConversionL'
 * '<S61>'  : 'ADC/Estimator/Kalman Filter/CalculatePL/DataTypeConversionM'
 * '<S62>'  : 'ADC/Estimator/Kalman Filter/CalculatePL/DataTypeConversionP'
 * '<S63>'  : 'ADC/Estimator/Kalman Filter/CalculatePL/DataTypeConversionZ'
 * '<S64>'  : 'ADC/Estimator/Kalman Filter/Observer/MeasurementUpdate'
 * '<S65>'  : 'ADC/Estimator/Space Environment/Calculator'
 */
#endif                                 /* RTW_HEADER_ADC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
