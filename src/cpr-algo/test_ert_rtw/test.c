/*
 * test.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "test".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Tue Feb  7 12:17:20 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test.h"
#include "test_private.h"

/* Block states (default storage) */
DW_test_T test_DW;

/* Real-time model */
static RT_MODEL_test_T test_M_;
RT_MODEL_test_T *const test_M = &test_M_;

/* Model step function */
void test_step(void)
{
  GPIO_TypeDef * portNameLoc;
  real_T tmp;
  int32_T pinWriteLoc;

  /* MATLABSystem: '<S4>/Digital Port Write' */
  portNameLoc = GPIOB;

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/OFF'
   *  Constant: '<Root>/ON'
   *  Constant: '<S1>/Constant'
   *  RelationalOperator: '<S1>/Compare'
   *  Sin: '<Root>/Sine Wave'
   */
  if (sin(((real_T)test_DW.counter + test_P.SineWave_Offset) * 2.0 *
          3.1415926535897931 / test_P.SineWave_NumSamp) * test_P.SineWave_Amp +
      test_P.SineWave_Bias >= test_P.CompareToConstant_const) {
    tmp = test_P.ON_Value;
  } else {
    tmp = test_P.OFF_Value;
  }

  /* End of Switch: '<Root>/Switch' */

  /* MATLABSystem: '<S4>/Digital Port Write' */
  if (tmp != 0.0) {
    pinWriteLoc = 2;
  } else {
    pinWriteLoc = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)pinWriteLoc);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)pinWriteLoc & 2U);

  /* Update for Sin: '<Root>/Sine Wave' */
  test_DW.counter++;
  if (test_DW.counter == test_P.SineWave_NumSamp) {
    test_DW.counter = 0;
  }

  /* End of Update for Sin: '<Root>/Sine Wave' */
}

/* Model initialize function */
void test_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(test_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&test_DW, 0,
                sizeof(DW_test_T));

  /* InitializeConditions for Sin: '<Root>/Sine Wave' */
  test_DW.counter = 0;
}

/* Model terminate function */
void test_terminate(void)
{
  /* (no terminate code required) */
}
