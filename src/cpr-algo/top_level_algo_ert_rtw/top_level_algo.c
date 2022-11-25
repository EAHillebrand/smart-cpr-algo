/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo.c
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 1.70
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Fri Nov 25 11:53:29 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "top_level_algo.h"
#include "top_level_algo_private.h"

/* Block signals (default storage) */
B_top_level_algo_T top_level_algo_B;

/* Block states (default storage) */
DW_top_level_algo_T top_level_algo_DW;

/* Real-time model */
static RT_MODEL_top_level_algo_T top_level_algo_M_;
RT_MODEL_top_level_algo_T *const top_level_algo_M = &top_level_algo_M_;

/* Model step function */
void top_level_algo_step(void)
{
  codertarget_arduinobase_inter_T *obj;
  int_T i;

  /* MATLABSystem: '<Root>/Analog Input1' */
  if (top_level_algo_DW.obj.SampleTime !=
      top_level_algo_P.AnalogInput1_SampleTime) {
    top_level_algo_DW.obj.SampleTime = top_level_algo_P.AnalogInput1_SampleTime;
  }

  obj = &top_level_algo_DW.obj;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(18UL);

  /* MATLABSystem: '<Root>/Analog Input1' */
  MW_AnalogInSingle_ReadResult
    (top_level_algo_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &top_level_algo_B.AnalogInput1, 3);

  /* Update for S-Function (sfix_udelay): '<S2>/Tapped Delay' */
  for (i = 0; i < 19; i++) {
    top_level_algo_DW.TappedDelay_X[i] = top_level_algo_DW.TappedDelay_X[i + 1];
  }

  top_level_algo_DW.TappedDelay_X[19] = top_level_algo_B.AnalogInput1;

  /* End of Update for S-Function (sfix_udelay): '<S2>/Tapped Delay' */
}

/* Model initialize function */
void top_level_algo_initialize(void)
{
  {
    codertarget_arduinobase_inter_T *obj;
    int16_T i;

    /* InitializeConditions for S-Function (sfix_udelay): '<S2>/Tapped Delay' */
    for (i = 0; i < 20; i++) {
      top_level_algo_DW.TappedDelay_X[i] = top_level_algo_P.TappedDelay_vinit;
    }

    /* End of InitializeConditions for S-Function (sfix_udelay): '<S2>/Tapped Delay' */

    /* Start for MATLABSystem: '<Root>/Analog Input1' */
    top_level_algo_DW.obj.matlabCodegenIsDeleted = true;
    top_level_algo_DW.obj.isInitialized = 0L;
    top_level_algo_DW.obj.SampleTime = -1.0;
    top_level_algo_DW.obj.matlabCodegenIsDeleted = false;
    top_level_algo_DW.obj.SampleTime = top_level_algo_P.AnalogInput1_SampleTime;
    obj = &top_level_algo_DW.obj;
    top_level_algo_DW.obj.isSetupComplete = false;
    top_level_algo_DW.obj.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(18UL);
    top_level_algo_DW.obj.isSetupComplete = true;
  }
}

/* Model terminate function */
void top_level_algo_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  obj = &top_level_algo_DW.obj;
  if (!top_level_algo_DW.obj.matlabCodegenIsDeleted) {
    top_level_algo_DW.obj.matlabCodegenIsDeleted = true;
    if ((top_level_algo_DW.obj.isInitialized == 1L) &&
        top_level_algo_DW.obj.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(18UL);
      MW_AnalogIn_Close
        (top_level_algo_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
