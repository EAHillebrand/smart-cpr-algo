/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo.c
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 1.77
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Fri Nov 25 18:08:36 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "top_level_algo.h"
#include "top_level_algo_private.h"

/* Named constants for Chart: '<S2>/timer' */
#define top_level_algo_IN_Finished     ((uint8_T)1U)
#define top_level_algo_IN_Polling      ((uint8_T)2U)
#define top_level_algo_IN_Starting     ((uint8_T)3U)

/* Block signals (default storage) */
B_top_level_algo_T top_level_algo_B;

/* Block states (default storage) */
DW_top_level_algo_T top_level_algo_DW;

/* Real-time model */
static RT_MODEL_top_level_algo_T top_level_algo_M_;
RT_MODEL_top_level_algo_T *const top_level_algo_M = &top_level_algo_M_;
int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0L) != (denominator < 0L)) && (numerator % denominator
           != 0L) ? -1L : 0L) + numerator / denominator;
}

/* Model step function */
void top_level_algo_step(void)
{
  codertarget_arduinobase_inter_T *obj;
  int32_T str;
  int16_T Mean_AccVal;
  int16_T n;

  /* Chart: '<S2>/timer' */
  if (top_level_algo_DW.temporalCounter_i1 < 31U) {
    top_level_algo_DW.temporalCounter_i1++;
  }

  if (top_level_algo_DW.is_active_c3_top_level_algo == 0U) {
    top_level_algo_DW.is_active_c3_top_level_algo = 1U;
    top_level_algo_DW.is_c3_top_level_algo = top_level_algo_IN_Starting;
    top_level_algo_DW.counter = 0.0;
  } else {
    switch (top_level_algo_DW.is_c3_top_level_algo) {
     case top_level_algo_IN_Finished:
      break;

     case top_level_algo_IN_Polling:
      if (top_level_algo_DW.counter > 100.0) {
        top_level_algo_DW.is_c3_top_level_algo = top_level_algo_IN_Finished;
      } else if (top_level_algo_DW.temporalCounter_i1 >= 20U) {
        top_level_algo_DW.is_c3_top_level_algo = top_level_algo_IN_Polling;
        top_level_algo_DW.temporalCounter_i1 = 0U;
        top_level_algo_DW.counter++;
      }
      break;

     default:
      /* case IN_Starting: */
      top_level_algo_DW.is_c3_top_level_algo = top_level_algo_IN_Polling;
      top_level_algo_DW.temporalCounter_i1 = 0U;
      top_level_algo_DW.counter++;
      break;
    }
  }

  /* End of Chart: '<S2>/timer' */

  /* S-Function (sdspstatfcns): '<S2>/Mean' incorporates:
   *  S-Function (sfix_udelay): '<S2>/Tapped Delay'
   */
  Mean_AccVal = (int16_T)top_level_algo_DW.TappedDelay_X[0L];
  str = 1L;
  for (n = 18; n >= 0; n--) {
    Mean_AccVal += (int16_T)top_level_algo_DW.TappedDelay_X[str];
    str++;
  }

  /* Product: '<S2>/Product' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Product: '<S2>/Divide'
   *  S-Function (sdspstatfcns): '<S2>/Mean'
   */
  top_level_algo_B.Product = (real_T)(uint16_T)div_nde_s32_floor(Mean_AccVal,
    20L) / top_level_algo_P.Constant1_Value * top_level_algo_P.Constant_Value;

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
  for (n = 0; n < 19; n++) {
    /* Update for S-Function (sfix_udelay): '<S2>/Tapped Delay1' */
    top_level_algo_DW.TappedDelay1_X[n] = top_level_algo_DW.TappedDelay1_X[n + 1];

    /* Update for S-Function (sfix_udelay): '<S2>/Tapped Delay' */
    top_level_algo_DW.TappedDelay_X[n] = top_level_algo_DW.TappedDelay_X[n + 1];
  }

  /* Update for S-Function (sfix_udelay): '<S2>/Tapped Delay1' */
  top_level_algo_DW.TappedDelay1_X[19] = top_level_algo_B.Product;

  /* Update for S-Function (sfix_udelay): '<S2>/Tapped Delay' */
  top_level_algo_DW.TappedDelay_X[19] = top_level_algo_B.AnalogInput1;
}

/* Model initialize function */
void top_level_algo_initialize(void)
{
  {
    codertarget_arduinobase_inter_T *obj;
    int16_T i;
    for (i = 0; i < 20; i++) {
      /* InitializeConditions for S-Function (sfix_udelay): '<S2>/Tapped Delay1' */
      top_level_algo_DW.TappedDelay1_X[i] = top_level_algo_P.TappedDelay1_vinit;

      /* InitializeConditions for S-Function (sfix_udelay): '<S2>/Tapped Delay' */
      top_level_algo_DW.TappedDelay_X[i] = top_level_algo_P.TappedDelay_vinit;
    }

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
