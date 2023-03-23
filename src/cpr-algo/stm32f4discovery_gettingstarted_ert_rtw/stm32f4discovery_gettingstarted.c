/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: stm32f4discovery_gettingstarted.c
 *
 * Code generated for Simulink model 'stm32f4discovery_gettingstarted'.
 *
 * Model version                  : 12.0
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Mar 18 09:36:49 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "stm32f4discovery_gettingstarted.h"
#include "rtwtypes.h"
#include <string.h>

/* Block states (default storage) */
DW_stm32f4discovery_gettingst_T stm32f4discovery_gettingstar_DW;

/* Real-time model */
static RT_MODEL_stm32f4discovery_get_T stm32f4discovery_gettingstar_M_;
RT_MODEL_stm32f4discovery_get_T *const stm32f4discovery_gettingstar_M =
  &stm32f4discovery_gettingstar_M_;

/* Model step function */
void stm32f4discovery_gettingstarted_step(void)
{
  GPIO_TypeDef * portNameLoc;
  real_T rtb_PulseGenerator;
  int32_T pinWriteLoc;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (stm32f4discovery_gettingstar_DW.clockTickCounter <
                        stm32f4discovery_gettingstart_P.PulseGenerator_Duty) &&
    (stm32f4discovery_gettingstar_DW.clockTickCounter >= 0) ?
    stm32f4discovery_gettingstart_P.PulseGenerator_Amp : 0.0;
  if (stm32f4discovery_gettingstar_DW.clockTickCounter >=
      stm32f4discovery_gettingstart_P.PulseGenerator_Period - 1.0) {
    stm32f4discovery_gettingstar_DW.clockTickCounter = 0;
  } else {
    stm32f4discovery_gettingstar_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<S3>/Digital Port Write' */
  portNameLoc = GPIOE;
  if (rtb_PulseGenerator != 0.0) {
    pinWriteLoc = 16;
  } else {
    pinWriteLoc = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)pinWriteLoc);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)pinWriteLoc & 16U);

  /* End of MATLABSystem: '<S3>/Digital Port Write' */
}

/* Model initialize function */
void stm32f4discovery_gettingstarted_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(stm32f4discovery_gettingstar_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&stm32f4discovery_gettingstar_DW, 0,
                sizeof(DW_stm32f4discovery_gettingst_T));

  /* InitializeConditions for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  stm32f4discovery_gettingstar_DW.clockTickCounter = 0;
}

/* Model terminate function */
void stm32f4discovery_gettingstarted_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
