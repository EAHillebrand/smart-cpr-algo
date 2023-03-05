/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: stm32f4discovery_gettingstarted.c
 *
 * Code generated for Simulink model 'stm32f4discovery_gettingstarted'.
 *
 * Model version                  : 10.2
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Fri Mar  3 15:09:37 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "stm32f4discovery_gettingstarted.h"
#include "stm32f4discovery_gettingstarted_private.h"

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
  real_T rtb_PulseGenerator1;
  int32_T pinWriteLoc;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator1' */
  rtb_PulseGenerator1 = (stm32f4discovery_gettingstar_DW.clockTickCounter <
    stm32f4discovery_gettingstart_P.PulseGenerator1_Duty) &&
    (stm32f4discovery_gettingstar_DW.clockTickCounter >= 0) ?
    stm32f4discovery_gettingstart_P.PulseGenerator1_Amp : 0.0;
  if (stm32f4discovery_gettingstar_DW.clockTickCounter >=
      stm32f4discovery_gettingstart_P.PulseGenerator1_Period - 1.0) {
    stm32f4discovery_gettingstar_DW.clockTickCounter = 0;
  } else {
    stm32f4discovery_gettingstar_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator1' */

  /* MATLABSystem: '<S3>/Digital Port Write' */
  portNameLoc = GPIOD;
  if (rtb_PulseGenerator1 != 0.0) {
    pinWriteLoc = 4;
  } else {
    pinWriteLoc = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)pinWriteLoc);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)pinWriteLoc & 4U);

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

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator1' */
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
