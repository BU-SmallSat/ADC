/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ADC_capi.c
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

#include <stddef.h>
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "ADC_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "ADC.h"
#include "ADC_capi.h"
#include "ADC_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               (NULL)
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 16, TARGET_STRING("ADC/lla2eci"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 1, 0, TARGET_STRING("ADC/Estimator/Math Function1"),
    TARGET_STRING(""), 0, 0, 1, 0, 1 },

  { 2, 3, TARGET_STRING("ADC/Controller/Detumble /saturator and power monitor"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 3, 0, TARGET_STRING("ADC/Estimator/Kalman Filter/X0"),
    TARGET_STRING(""), 0, 0, 2, 0, 1 },

  { 4, 11, TARGET_STRING(
    "ADC/Estimator/Kalman Filter/Observer/MeasurementUpdate"),
    TARGET_STRING(""), 0, 0, 3, 0, 0 },

  { 5, 0, TARGET_STRING("ADC/Estimator/Kalman Filter/Observer/Add"),
    TARGET_STRING(""), 0, 0, 3, 0, 0 },

  { 6, 11, TARGET_STRING(
    "ADC/Estimator/Kalman Filter/Observer/MeasurementUpdate/Product3"),
    TARGET_STRING(""), 0, 0, 3, 0, 0 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 7, TARGET_STRING("ADC/Controller/Memory"),
    TARGET_STRING("X0"), 0, 4, 0 },

  { 8, TARGET_STRING("ADC/Estimator/Memory"),
    TARGET_STRING("X0"), 0, 4, 0 },

  { 9, TARGET_STRING("ADC/Estimator/Memory1"),
    TARGET_STRING("X0"), 0, 4, 0 },

  { 10, TARGET_STRING("ADC/Estimator/Normalization"),
    TARGET_STRING("Bias"), 0, 4, 0 },

  { 11, TARGET_STRING("ADC/Controller/Detumble /Discrete Derivative"),
    TARGET_STRING("ICPrevScaledInput"), 0, 4, 0 },

  { 12, TARGET_STRING("ADC/Controller/Detumble /voltage"),
    TARGET_STRING("Value"), 0, 4, 0 },

  { 13, TARGET_STRING("ADC/Controller/Detumble /Gain"),
    TARGET_STRING("Gain"), 0, 4, 0 },

  { 14, TARGET_STRING("ADC/Controller/Pointing/voltage"),
    TARGET_STRING("Value"), 0, 4, 0 },

  { 15, TARGET_STRING("ADC/Controller/Pointing/Switch"),
    TARGET_STRING("Threshold"), 0, 4, 0 },

  { 16, TARGET_STRING("ADC/Controller/Pointing/Switch2"),
    TARGET_STRING("Threshold"), 0, 4, 0 },

  { 17, TARGET_STRING("ADC/Estimator/Kalman Filter/A"),
    TARGET_STRING("Value"), 0, 5, 0 },

  { 18, TARGET_STRING("ADC/Estimator/Kalman Filter/B"),
    TARGET_STRING("Value"), 0, 6, 0 },

  { 19, TARGET_STRING("ADC/Estimator/Kalman Filter/C"),
    TARGET_STRING("Value"), 0, 5, 0 },

  { 20, TARGET_STRING("ADC/Estimator/Kalman Filter/D"),
    TARGET_STRING("Value"), 0, 6, 0 },

  { 21, TARGET_STRING("ADC/Estimator/Kalman Filter/Enable"),
    TARGET_STRING("Value"), 1, 4, 0 },

  { 22, TARGET_STRING("ADC/Estimator/Kalman Filter/X0"),
    TARGET_STRING("Value"), 0, 3, 0 },

  { 23, TARGET_STRING("ADC/Controller/Detumble /Discrete Derivative/TSamp"),
    TARGET_STRING("WtEt"), 0, 4, 0 },

  { 24, TARGET_STRING("ADC/Estimator/Kalman Filter/CalculatePL/KalmanGainL"),
    TARGET_STRING("Value"), 0, 5, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Block states information */
static const rtwCAPI_States rtBlockStates[] = {
  /* addrMapIndex, contStateStartIndex, blockPath,
   * stateName, pathAlias, dWorkIndex, dataTypeIndex, dimIndex,
   * fixPtIdx, sTimeIndex, isContinuous, hierInfoIdx, flatElemIdx
   */
  { 25, 0, TARGET_STRING("ADC/Estimator/Kalman Filter/MemoryX"),
    TARGET_STRING(""),
    TARGET_STRING(""),
    0, 0, 3, 0, 0, 1, -1, 0 },

  { 26, -1, TARGET_STRING("ADC/Controller/Detumble\n/Discrete Derivative/UD"),
    TARGET_STRING(""), "", 0, 0, 0, 0, 1, 0, -1, 0 },

  {
    0, -1, (NULL), (NULL), (NULL), 0, 0, 0, 0, 0, 0, -1, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 0, (NULL), 0, 0, 0 }
};

#ifndef HOST_CAPI_BUILD

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &ADC_B.r_ECI[0],                     /* 0: Signal */
  &ADC_B.MathFunction1[0],             /* 1: Signal */
  &ADC_B.m[0],                         /* 2: Signal */
  &ADC_B.X0[0],                        /* 3: Signal */
  &ADC_B.Product3[0],                  /* 4: Signal */
  &ADC_B.Add[0],                       /* 5: Signal */
  &ADC_B.Product3[0],                  /* 6: Signal */
  &ADC_P.Memory_X0,                    /* 7: Block Parameter */
  &ADC_P.Memory_X0_d,                  /* 8: Block Parameter */
  &ADC_P.Memory1_X0,                   /* 9: Block Parameter */
  &ADC_P.Normalization_Bias,           /* 10: Block Parameter */
  &ADC_P.DiscreteDerivative_ICPrevScaledInput,/* 11: Mask Parameter */
  &ADC_P.voltage_Value,                /* 12: Block Parameter */
  &ADC_P.Gain_Gain,                    /* 13: Block Parameter */
  &ADC_P.voltage_Value_b,              /* 14: Block Parameter */
  &ADC_P.Switch_Threshold,             /* 15: Block Parameter */
  &ADC_P.Switch2_Threshold,            /* 16: Block Parameter */
  &ADC_P.A_Value[0],                   /* 17: Block Parameter */
  &ADC_P.B_Value[0],                   /* 18: Block Parameter */
  &ADC_P.C_Value[0],                   /* 19: Block Parameter */
  &ADC_P.D_Value[0],                   /* 20: Block Parameter */
  &ADC_P.Enable_Value,                 /* 21: Block Parameter */
  &ADC_P.X0_Value[0],                  /* 22: Block Parameter */
  &ADC_P.TSamp_WtEt,                   /* 23: Block Parameter */
  &ADC_P.KalmanGainL_Value[0],         /* 24: Block Parameter */
  &ADC_X.MemoryX_CSTATE[0],            /* 25: Continuous State */
  &ADC_DW.UD_DSTATE[0],                /* 26: Discrete State */
};

/* Declare Data Run-Time Dimension Buffer Addresses statically */
static int32_T* rtVarDimsAddrMap[] = {
  (NULL)
};

#endif

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 },

  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

/* Structure Element Map - use elemMapIndex to access this structure */
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (NULL), 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static const rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_VECTOR, 0, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 2, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 4, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 },

  { rtwCAPI_SCALAR, 6, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 8, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 10, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  3,                                   /* 0 */
  1,                                   /* 1 */
  3,                                   /* 2 */
  3,                                   /* 3 */
  6,                                   /* 4 */
  1,                                   /* 5 */
  1,                                   /* 6 */
  1,                                   /* 7 */
  6,                                   /* 8 */
  6,                                   /* 9 */
  6,                                   /* 10 */
  3                                    /* 11 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.0, 0.1
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[0],
    0, 0 },

  { (const void *) &rtcapiStoredFloats[1], (const void *) &rtcapiStoredFloats[0],
    1, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals,
   *           rootInputs, numRootInputs,
   *           rootOutputs, numRootOutputs},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 7,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 18,
    rtModelParameters, 0 },

  { rtBlockStates, 2 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 3931530435U,
    1088133387U,
    2458642832U,
    1037310115U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  ADC_GetCAPIStaticMap()
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void ADC_InitializeDataMapInfo(RT_MODEL_ADC_T *const ADC_M)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(ADC_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(ADC_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(ADC_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(ADC_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(ADC_M->DataMapInfo.mmi, rtVarDimsAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(ADC_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(ADC_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(ADC_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void ADC_host_InitializeDataMapInfo(ADC_host_DataMapInfo_T *dataMap, const
    char *path)
  {
    /* Set C-API version */
    rtwCAPI_SetVersion(dataMap->mmi, 1);

    /* Cache static C-API data into the Real-time Model Data structure */
    rtwCAPI_SetStaticMap(dataMap->mmi, &mmiStatic);

    /* host data address map is NULL */
    rtwCAPI_SetDataAddressMap(dataMap->mmi, NULL);

    /* host vardims address map is NULL */
    rtwCAPI_SetVarDimsAddressMap(dataMap->mmi, NULL);

    /* Set Instance specific path */
    rtwCAPI_SetPath(dataMap->mmi, path);
    rtwCAPI_SetFullPath(dataMap->mmi, NULL);

    /* Set reference to submodels */
    rtwCAPI_SetChildMMIArray(dataMap->mmi, (NULL));
    rtwCAPI_SetChildMMIArrayLen(dataMap->mmi, 0);
  }

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
