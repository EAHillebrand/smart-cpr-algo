/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test1_forNano.c
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
#include "test1_forNano_private.h"

/* Block states (default storage) */
DW_test1_forNano_T test1_forNano_DW;

/* Real-time model */
static RT_MODEL_test1_forNano_T test1_forNano_M_;
RT_MODEL_test1_forNano_T *const test1_forNano_M = &test1_forNano_M_;
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

/* Model step function */
void test1_forNano_step(void)
{
  real_T temp;
  uint8_T tmp;

  /* SignalGenerator: '<Root>/Square Wave Generator' */
  temp = test1_forNano_P.SquareWaveGenerator_Frequency *
    test1_forNano_M->Timing.t[0];
  if (temp - floor(temp) >= 0.5) {
    temp = test1_forNano_P.SquareWaveGenerator_Amplitude;
  } else {
    temp = -test1_forNano_P.SquareWaveGenerator_Amplitude;
  }

  /* End of SignalGenerator: '<Root>/Square Wave Generator' */

  /* MATLABSystem: '<Root>/Digital Output' */
  temp = rt_roundd_snf(temp);
  if (temp < 256.0) {
    if (temp >= 0.0) {
      tmp = (uint8_T)temp;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(2, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  test1_forNano_M->Timing.t[0] =
    ((time_T)(++test1_forNano_M->Timing.clockTick0)) *
    test1_forNano_M->Timing.stepSize0;
}

/* Model initialize function */
void test1_forNano_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&test1_forNano_M->solverInfo,
                          &test1_forNano_M->Timing.simTimeStep);
    rtsiSetTPtr(&test1_forNano_M->solverInfo, &rtmGetTPtr(test1_forNano_M));
    rtsiSetStepSizePtr(&test1_forNano_M->solverInfo,
                       &test1_forNano_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&test1_forNano_M->solverInfo, (&rtmGetErrorStatus
      (test1_forNano_M)));
    rtsiSetRTModelPtr(&test1_forNano_M->solverInfo, test1_forNano_M);
  }

  rtsiSetSimTimeStep(&test1_forNano_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&test1_forNano_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(test1_forNano_M, &test1_forNano_M->Timing.tArray[0]);
  test1_forNano_M->Timing.stepSize0 = 0.2;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  test1_forNano_DW.obj.matlabCodegenIsDeleted = false;
  test1_forNano_DW.obj.isInitialized = 1;
  digitalIOSetup(2, 1);
  test1_forNano_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void test1_forNano_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!test1_forNano_DW.obj.matlabCodegenIsDeleted) {
    test1_forNano_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
