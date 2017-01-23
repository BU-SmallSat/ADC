/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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

#include <stdio.h>
#include <stdlib.h>
#include "ADC.h"
#include "ADC_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "rt_nonfinite.h"
#include "linuxinitialize.h"
#include "pythonInterface.c"

/* '<Root>/Magnetic Measure' */
static real_T arg_Magnetic_Measure[3] = { 0.0, 0.0, 0.0 };

/* '<Root>/Euler Angle Measure' */
static real_T arg_Euler_Angle_Measure[3] = { 0.0, 0.0, 0.0 };

/* '<Root>/Sun Measure' */
static real_T arg_Sun_Measure[3] = { 0.0, 0.0, 0.0 };

/* '<Root>/epoch' */
static real_T arg_epoch[6] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

/* '<Root>/lla' */
static real_T arg_lla[3] = { 0.0, 0.0, 0.0 };

/* '<Root>/v ' */
static real_T arg_v_[3] = { 0.0, 0.0, 0.0 };

/* '<Root>/S_flag' */
static real_T local_arg_S_flag = 0.0;
static real_T * arg_S_flag = &local_arg_S_flag;

/* '<Root>/Magnetic Dipole Moment' */
static real_T arg_Magnetic_Dipole_Moment[3];

/* '<Root>/q_est1' */
static real_T arg_q_est1[4];

/* Function prototype declaration*/
void exitTask(int sig);
void terminateTask(void *arg);
void baseRateTask(void *arg);
void subrateTask(void *arg);
volatile boolean_T runModel = true;
sem_t stopSem;
sem_t baserateTaskSem;
pthread_t schedulerThread;
pthread_t baseRateThread;
unsigned long threadJoinStatus[8];
int terminatingmodel = 0;

void baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(ADC_M) == (NULL)) && !rtmGetStopRequested(ADC_M);
  INPUT_ARGS *args = malloc(sizeof(INPUT_ARGS));
  INPUT_ARGS *result = NULL;
  while (runModel) {
    sem_wait(&baserateTaskSem);
    result = pageForValues(args);
    if (result != NULL){
      ADC_custom(args->arg_Magnetic_Measure, args->arg_Euler_Angle_Measure, args->arg_Sun_Measure,
                args->arg_epoch, args->arg_lla, arg_v_, &args->local_arg_S_flag,
                arg_Magnetic_Dipole_Moment, arg_q_est1);
      printf("%f, %f, %f, %f, %f, %f, %f\n", arg_Magnetic_Dipole_Moment[0], arg_Magnetic_Dipole_Moment[1],arg_Magnetic_Dipole_Moment[2],
      arg_q_est1[0],arg_q_est1[1],arg_q_est1[2],arg_q_est1[3]);
      
    }
    runModel = (rtmGetErrorStatus(ADC_M) == (NULL)) && !rtmGetStopRequested
      (ADC_M);
  }

  runModel = 0;
  terminateTask(arg);
  pthread_exit((void *)0);
}

void exitTask(int sig)
{
  rtmSetErrorStatus(ADC_M, "stopping the model");
}

void terminateTask(void *arg)
{
  terminatingmodel = 1;
  printf("**terminating the model**\n");
  fflush(stdout);

  {
    int ret;
    runModel = 0;
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  ADC_terminate();
  sem_post(&stopSem);
}

int main(int argc, char **argv)
{
  //printf("**starting the model**\n");

  fflush(stdout);
  rtmSetErrorStatus(ADC_M, 0);

  /* Initialize model */
  ADC_initialize();  
  /* Call RTOS Initialization funcation */
  myRTOSInit(0.1, 0);

  /* Wait for stop semaphore */
  sem_wait(&stopSem);
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
