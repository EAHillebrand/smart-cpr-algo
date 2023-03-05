/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'test1_forNano'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Tue Jan 31 16:14:44 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test1_forNano.h"
#include "rtwtypes.h"

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

  test1_forNano_step();

  /* Get model outputs here */
  OverrunFlag--;
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 0.2;
  float systemClock = 0;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;

#if defined(MW_MULTI_TASKING_MODE) && (MW_MULTI_TASKING_MODE == 1)

  MW_ASM (" SVC #254");

#endif

  ;
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(test1_forNano_M, 0);
  test1_forNano_initialize();
  noInterrupts();
  configureArduinoARMTimer(modelBaseRate);
  runModel =
    rtmGetErrorStatus(test1_forNano_M) == (NULL);
  interrupts();
  while (runModel) {
    stopRequested = !(
                      rtmGetErrorStatus(test1_forNano_M) == (NULL));
    MW_Arduino_Loop();
  }

  /* Terminate model */
  test1_forNano_terminate();
  MW_Arduino_Terminate();
  noInterrupts();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
