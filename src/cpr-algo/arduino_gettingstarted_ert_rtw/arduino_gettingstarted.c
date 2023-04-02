/*
 * arduino_gettingstarted.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "arduino_gettingstarted".
 *
 * Model version              : 7.0
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Tue Mar 28 17:19:39 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "arduino_gettingstarted.h"
#include "rtwtypes.h"
#include "arduino_gettingstarted_private.h"
#include <math.h>
#include <string.h>

/* Block states (default storage) */
DW_arduino_gettingstarted_T arduino_gettingstarted_DW;

/* Real-time model */
static RT_MODEL_arduino_gettingstart_T arduino_gettingstarted_M_;
RT_MODEL_arduino_gettingstart_T *const arduino_gettingstarted_M =
  &arduino_gettingstarted_M_;
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
void arduino_gettingstarted_step(void)
{
  real_T rtb_PulseGenerator;
  uint8_T tmp;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (arduino_gettingstarted_DW.clockTickCounter <
                        arduino_gettingstarted_P.PulseGenerator_Duty) &&
    (arduino_gettingstarted_DW.clockTickCounter >= 0) ?
    arduino_gettingstarted_P.PulseGenerator_Amp : 0.0;
  if (arduino_gettingstarted_DW.clockTickCounter >=
      arduino_gettingstarted_P.PulseGenerator_Period - 1.0) {
    arduino_gettingstarted_DW.clockTickCounter = 0;
  } else {
    arduino_gettingstarted_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<Root>/Digital Output' */
  rtb_PulseGenerator = rt_roundd_snf(rtb_PulseGenerator);
  if (rtb_PulseGenerator < 256.0) {
    if (rtb_PulseGenerator >= 0.0) {
      tmp = (uint8_T)rtb_PulseGenerator;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(2, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output' */
}

/* Model initialize function */
void arduino_gettingstarted_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(arduino_gettingstarted_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&arduino_gettingstarted_DW, 0,
                sizeof(DW_arduino_gettingstarted_T));

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  arduino_gettingstarted_DW.obj.matlabCodegenIsDeleted = false;
  arduino_gettingstarted_DW.obj.isInitialized = 1;
  digitalIOSetup(2, 1);
  arduino_gettingstarted_DW.obj.isSetupComplete = true;

  /* InitializeConditions for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  arduino_gettingstarted_DW.clockTickCounter = 0;
}

/* Model terminate function */
void arduino_gettingstarted_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!arduino_gettingstarted_DW.obj.matlabCodegenIsDeleted) {
    arduino_gettingstarted_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}
