/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ADC.h
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

#ifndef RTW_HEADER_ADC_h_
#define RTW_HEADER_ADC_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap.h"
#ifndef ADC_COMMON_INCLUDES_
# define ADC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* ADC_COMMON_INCLUDES_ */

#include "ADC_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

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
  real_T dv0[18];
  real_T rtb_Normalization_m[12];
  real_T dv1[12];
  real_T R_LVLH2b[9];                  /* '<S2>/Matrix Multiply' */
  real_T dv2[9];
  real_T u[9];
  real_T u_c[9];
  real_T u_k[9];
  real_T dv3[9];
  real_T X0[6];                        /* '<S17>/X0' */
  real_T MathFunction1[9];             /* '<S2>/Math Function1' */
  real_T Add[6];                       /* '<S40>/Add' */
  real_T x[6];                         /* '<S2>/State1' */
  real_T dv4[6];
  real_T dv5[6];
  real_T rtb_x_c[6];
  real_T dv6[4];
  int32_T b_data[6];
  real_T Memory[3];                    /* '<S1>/Memory' */
  real_T r_ECI[3];                     /* '<Root>/lla2eci' */
  real_T Product3[6];                  /* '<S65>/Product3' */
  real_T m[3];                         /* '<S5>/saturator and power monitor' */
  real_T u_b[3];
  real_T y_tmp[3];
  real_T B_e[3];                       /* '<S1>/Decision' */
  real_T m_g[3];                       /* '<S6>/LQR Controller' */
  real_T B1[3];                        /* '<S1>/Decision' */
  real_T Sum_c[3];                     /* '<S2>/Sum' */
  real_T u_p[3];
  real_T u_cv[3];
  real_T rtb_m_g_f[3];
  real_T rtb_m_g_g[3];
  real_T u_g[3];
  real_T rtb_m_g_m[3];
  real_T u_n[3];
  real_T rtb_m_g_p[3];
  real_T rtb_m_l[3];
  real_T TSamp[3];                     /* '<S7>/TSamp' */
  real_T Memory_j[3];                  /* '<S2>/Memory' */
  real_T time_diff;
  real_T scale;
  real_T G0;
  real_T f;
  real_T M;
  real_T E;
  real_T rtb_B_e_d;
  real_T a;
  real_T rtb_m_idx_0;
  real_T rtb_m_idx_1;
  real_T rtb_m_idx_2;
  real_T c_idx_0;
  real_T c_idx_1;
  real_T c_idx_2;
  real_T W2_idx_2;
  real_T W2_idx_1;
  real_T W2_idx_0;
  real_T b_c_idx_0;
  real_T b_c_idx_1;
  real_T b_c_idx_2;
  real_T z_idx_2;
  real_T z_idx_1;
} B_ADC_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE[3];                 /* '<S7>/UD' */
  real_T Memory_PreviousInput[3];      /* '<S1>/Memory' */
  real_T Memory1_PreviousInput[3];     /* '<S2>/Memory1' */
  real_T Memory_PreviousInput_h[3];    /* '<S2>/Memory' */
  real_T counter;                      /* '<S5>/MATLAB Function' */
  real_T times[1000000];               /* '<S5>/MATLAB Function' */
  int_T MemoryX_IWORK;                 /* '<S17>/MemoryX' */
  boolean_T MeasurementUpdate_MODE;    /* '<S40>/MeasurementUpdate' */
} DW_ADC_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T MemoryX_CSTATE[6];            /* '<S17>/MemoryX' */
} X_ADC_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T MemoryX_CSTATE[6];            /* '<S17>/MemoryX' */
} XDot_ADC_T;

/* State disabled  */
typedef struct {
  boolean_T MemoryX_CSTATE[6];         /* '<S17>/MemoryX' */
} XDis_ADC_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Parameters (auto storage) */
struct P_ADC_T_ {
  real_T Normalization_Bias;           /* Mask Parameter: Normalization_Bias
                                        * Referenced by: '<S2>/Normalization'
                                        */
  real_T DiscreteDerivative_ICPrevScaledInput;/* Mask Parameter: DiscreteDerivative_ICPrevScaledInput
                                               * Referenced by: '<S7>/UD'
                                               */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S1>/Memory'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S7>/TSamp'
                                        */
  real_T Gain_Gain;                    /* Expression: -1000000
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T voltage_Value;                /* Expression: 5
                                        * Referenced by: '<S5>/voltage'
                                        */
  real_T X0_Value[6];                  /* Expression: pInitialization.X0
                                        * Referenced by: '<S17>/X0'
                                        */
  real_T voltage_Value_b;              /* Expression: 5
                                        * Referenced by: '<S6>/voltage'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S6>/Switch'
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<S2>/Memory1'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S6>/Switch2'
                                        */
  real_T A_Value[36];                  /* Expression: pInitialization.A
                                        * Referenced by: '<S17>/A'
                                        */
  real_T B_Value[18];                  /* Expression: pInitialization.B
                                        * Referenced by: '<S17>/B'
                                        */
  real_T C_Value[36];                  /* Expression: pInitialization.C
                                        * Referenced by: '<S17>/C'
                                        */
  real_T KalmanGainL_Value[36];        /* Expression: pInitialization.L
                                        * Referenced by: '<S22>/KalmanGainL'
                                        */
  real_T D_Value[18];                  /* Expression: pInitialization.D
                                        * Referenced by: '<S17>/D'
                                        */
  real_T Memory_X0_d;                  /* Expression: 0
                                        * Referenced by: '<S2>/Memory'
                                        */
  boolean_T Enable_Value;              /* Computed Parameter: Enable_Value
                                        * Referenced by: '<S17>/Enable'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ADC_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
  } DataMapInfo;

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

/* Model entry point functions */
extern void ADC_initialize(void);
extern void ADC_terminate(void);

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  ADC_GetCAPIStaticMap(void);

/* Customized model step function */
extern void ADC_custom(real_T arg_Magnetic_Measure[3], real_T
  arg_Euler_Angle_Measure[3], real_T arg_Sun_Measure[3], real_T arg_epoch[6],
  real_T arg_lla[3], real_T arg_v_[3], real_T *arg_S_flag, real_T
  arg_Magnetic_Dipole_Moment[3], real_T arg_q_est1[4]);

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
 * '<S3>'   : 'ADC/lla2eci'
 * '<S4>'   : 'ADC/Controller/Decision'
 * '<S5>'   : 'ADC/Controller/Detumble '
 * '<S6>'   : 'ADC/Controller/Pointing'
 * '<S7>'   : 'ADC/Controller/Detumble /Discrete Derivative'
 * '<S8>'   : 'ADC/Controller/Detumble /MATLAB Function'
 * '<S9>'   : 'ADC/Controller/Detumble /saturator and power monitor'
 * '<S10>'  : 'ADC/Controller/Pointing/LQR Controller'
 * '<S11>'  : 'ADC/Controller/Pointing/PD Controler'
 * '<S12>'  : 'ADC/Estimator/  '
 * '<S13>'  : 'ADC/Estimator/  1'
 * '<S14>'  : 'ADC/Estimator/  2'
 * '<S15>'  : 'ADC/Estimator/ LVLH '
 * '<S16>'  : 'ADC/Estimator/DCM to q'
 * '<S17>'  : 'ADC/Estimator/Kalman Filter'
 * '<S18>'  : 'ADC/Estimator/MATLAB Function'
 * '<S19>'  : 'ADC/Estimator/MATLAB Function1'
 * '<S20>'  : 'ADC/Estimator/Space Environment'
 * '<S21>'  : 'ADC/Estimator/State1'
 * '<S22>'  : 'ADC/Estimator/Kalman Filter/CalculatePL'
 * '<S23>'  : 'ADC/Estimator/Kalman Filter/CalculateYhat'
 * '<S24>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionA'
 * '<S25>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionB'
 * '<S26>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionC'
 * '<S27>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionD'
 * '<S28>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionG'
 * '<S29>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionH'
 * '<S30>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionN'
 * '<S31>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionP'
 * '<S32>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionP0'
 * '<S33>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionQ'
 * '<S34>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionR'
 * '<S35>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionReset'
 * '<S36>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionX'
 * '<S37>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionX0'
 * '<S38>'  : 'ADC/Estimator/Kalman Filter/DataTypeConversionu'
 * '<S39>'  : 'ADC/Estimator/Kalman Filter/MemoryP'
 * '<S40>'  : 'ADC/Estimator/Kalman Filter/Observer'
 * '<S41>'  : 'ADC/Estimator/Kalman Filter/ReducedQRN'
 * '<S42>'  : 'ADC/Estimator/Kalman Filter/ScalarExpansionP0'
 * '<S43>'  : 'ADC/Estimator/Kalman Filter/ScalarExpansionQ'
 * '<S44>'  : 'ADC/Estimator/Kalman Filter/ScalarExpansionR'
 * '<S45>'  : 'ADC/Estimator/Kalman Filter/UseCurrentEstimator'
 * '<S46>'  : 'ADC/Estimator/Kalman Filter/checkA'
 * '<S47>'  : 'ADC/Estimator/Kalman Filter/checkB'
 * '<S48>'  : 'ADC/Estimator/Kalman Filter/checkC'
 * '<S49>'  : 'ADC/Estimator/Kalman Filter/checkD'
 * '<S50>'  : 'ADC/Estimator/Kalman Filter/checkEnable'
 * '<S51>'  : 'ADC/Estimator/Kalman Filter/checkG'
 * '<S52>'  : 'ADC/Estimator/Kalman Filter/checkH'
 * '<S53>'  : 'ADC/Estimator/Kalman Filter/checkN'
 * '<S54>'  : 'ADC/Estimator/Kalman Filter/checkP0'
 * '<S55>'  : 'ADC/Estimator/Kalman Filter/checkQ'
 * '<S56>'  : 'ADC/Estimator/Kalman Filter/checkR'
 * '<S57>'  : 'ADC/Estimator/Kalman Filter/checkReset'
 * '<S58>'  : 'ADC/Estimator/Kalman Filter/checkX0'
 * '<S59>'  : 'ADC/Estimator/Kalman Filter/checku'
 * '<S60>'  : 'ADC/Estimator/Kalman Filter/checky'
 * '<S61>'  : 'ADC/Estimator/Kalman Filter/CalculatePL/DataTypeConversionL'
 * '<S62>'  : 'ADC/Estimator/Kalman Filter/CalculatePL/DataTypeConversionM'
 * '<S63>'  : 'ADC/Estimator/Kalman Filter/CalculatePL/DataTypeConversionP'
 * '<S64>'  : 'ADC/Estimator/Kalman Filter/CalculatePL/DataTypeConversionZ'
 * '<S65>'  : 'ADC/Estimator/Kalman Filter/Observer/MeasurementUpdate'
 * '<S66>'  : 'ADC/Estimator/Space Environment/Calculator'
 */
#endif                                 /* RTW_HEADER_ADC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
