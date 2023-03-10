/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo.c
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 3.4
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Mar  9 17:14:06 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "top_level_algo.h"
#include "rtwtypes.h"
#include "top_level_algo_types.h"
#include "top_level_algo_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <math.h>
#include "stm_adc_ll.h"
#include <float.h>

/* Named constants for Chart: '<S9>/sample and hold' */
#define top_level_algo_IN_Holding      ((uint8_T)1U)
#define top_level_algo_IN_Init         ((uint8_T)2U)

/* Named constants for Chart: '<S11>/ClockLogic' */
#define top_level_algo_IN_HIGH         ((uint8_T)1U)
#define top_level_algo_IN_LOW          ((uint8_T)2U)
#define top_level_algo_IN_START        ((uint8_T)3U)
#define top_level_algo_IN_WAIT         ((uint8_T)4U)

/* Named constants for Chart: '<S11>/DataLogic' */
#define top_level_algo_IN_CHECK        ((uint8_T)1U)
#define top_level_algo_IN_LOAD         ((uint8_T)2U)
#define top_level_algo_IN_MASK         ((uint8_T)3U)
#define top_level_algo_IN_START_l      ((uint8_T)4U)
#define top_level_algo_IN_WAITING      ((uint8_T)5U)
#define top_level_algo_IN_Wait         ((uint8_T)6U)

/* Named constants for Chart: '<S3>/Chart' */
#define top_level_algo_IN_DETECTION    ((uint8_T)1U)
#define top_level_algo_IN_FOUR         ((uint8_T)2U)
#define top_level_algo_IN_INIT         ((uint8_T)3U)
#define top_level_algo_IN_ONE          ((uint8_T)4U)
#define top_level_algo_IN_POLLING      ((uint8_T)5U)
#define top_level_algo_IN_SHORTEN      ((uint8_T)6U)
#define top_level_algo_IN_THREE        ((uint8_T)7U)
#define top_level_algo_IN_TWO          ((uint8_T)8U)
#define top_level_algo_IN_Wait_l       ((uint8_T)9U)

/* Named constants for Chart: '<S3>/Chart1' */
#define top_level_algo_IN_Counting     ((uint8_T)1U)
#define top_level_algo_IN_First        ((uint8_T)2U)

/* Named constants for Chart: '<S7>/timer' */
#define top_level_algo_IN_Finished     ((uint8_T)1U)
#define top_level_algo_IN_Starting     ((uint8_T)2U)

/* Block signals (default storage) */
B_top_level_algo_T top_level_algo_B;

/* Block states (default storage) */
DW_top_level_algo_T top_level_algo_DW;

/* Real-time model */
static RT_MODEL_top_level_algo_T top_level_algo_M_;
RT_MODEL_top_level_algo_T *const top_level_algo_M = &top_level_algo_M_;

/* Forward declaration for local functions */
static void top_level_algo_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj);
static void rate_scheduler(void);
int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (top_level_algo_M->Timing.TaskCounters.TID[2])++;
  if ((top_level_algo_M->Timing.TaskCounters.TID[2]) > 99) {/* Sample time: [0.1s, 0.0s] */
    top_level_algo_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * Output and update for action system:
 *    '<S12>/If Action Subsystem'
 *    '<S12>/If Action Subsystem1'
 *    '<S12>/If Action Subsystem2'
 *    '<S12>/If Action Subsystem3'
 *    '<S12>/If Action Subsystem4'
 *    '<S12>/If Action Subsystem5'
 *    '<S12>/If Action Subsystem6'
 *    '<S12>/If Action Subsystem7'
 *    '<S12>/If Action Subsystem8'
 *    '<S12>/If Action Subsystem10'
 *    ...
 */
void top_level_alg_IfActionSubsystem(uint8_T *rty_Out1,
  P_IfActionSubsystem_top_level_T *localP)
{
  /* SignalConversion generated from: '<S15>/Out1' incorporates:
   *  Constant: '<S15>/Constant'
   */
  *rty_Out1 = localP->Constant_Value;
}

/*
 * System initialize for atomic system:
 *    '<S9>/sample and hold'
 *    '<S9>/sample and hold1'
 */
void top_level_al_sampleandhold_Init(real_T *rty_displacement)
{
  *rty_displacement = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S9>/sample and hold'
 *    '<S9>/sample and hold1'
 */
void top_level_algo_sampleandhold(real_T rtu_max, boolean_T rtu_read, real_T
  *rty_displacement, DW_sampleandhold_top_level_al_T *localDW)
{
  /* Chart: '<S9>/sample and hold' */
  if (localDW->is_active_c1_top_level_algo == 0U) {
    localDW->is_active_c1_top_level_algo = 1U;
    localDW->is_c1_top_level_algo = top_level_algo_IN_Init;
    *rty_displacement = 0.0;
  } else if (localDW->is_c1_top_level_algo == top_level_algo_IN_Holding) {
    if (rtu_read) {
      *rty_displacement = rtu_max;
    }

    /* case IN_Init: */
  } else if (rtu_read) {
    localDW->is_c1_top_level_algo = top_level_algo_IN_Holding;
    *rty_displacement = rtu_max;
  }

  /* End of Chart: '<S9>/sample and hold' */
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  boolean_T yEq;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

static void top_level_algo_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj)
{
  uint16_T module;
  uint16_T triggerType;
  uint32_T noConv;
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  adcStructLoc.dmastream = LL_DMA_STREAM_0;
  adcStructLoc.dmaPeripheralPtr = DMA2;
  adcStructLoc.InternalBufferPtr = (void*)(&obj->ADCInternalBuffer[0]);
  adcStructLoc.peripheralPtr = ADC3;
  adcStructLoc.InjectedNoOfConversion = 0U;
  adcStructLoc.InternalBufferSize = 1U;
  module = ADC_DMA_INTERRUPT_MODE;
  triggerType = ADC_TRIGGER_AND_READ;
  noConv = LL_ADC_REG_SEQ_SCAN_DISABLE;
  adcStructLoc.RegularNoOfConversion = 1U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, module, 1, triggerType, noConv);
  enableADC(obj->ADCHandle);
  startADCConversionForExternalTrigger(obj->ADCHandle, 1);
  obj->isSetupComplete = true;
}

/* Model step function */
void top_level_algo_step(void)
{
  /* local block i/o variables */
  real_T rtb_Merge;
  real_T rtb_Reset;
  boolean_T rtb_IsPos;
  boolean_T rtb_IsNeg;
  boolean_T rtb_LogicalOperator7;
  boolean_T rtb_LogicalOperator3;
  boolean_T rtb_NOT2;
  boolean_T rtb_NOT;

  {
    int32_T Mean_AccVal_f;
    int32_T i;
    int32_T str;
    int32_T str_0;
    uint32_T rtb_Add;
    uint16_T data;
    boolean_T Delay1_DSTATE_m_tmp;
    boolean_T Delay7_DSTATE_tmp;
    boolean_T rtb_AND;
    boolean_T rtb_AND1;
    boolean_T rtb_LogicalOperator_a;

    /* S-Function (sfix_udelay): '<S7>/Tapped Delay1' */
    memcpy(&top_level_algo_B.TappedDelay[0], &top_level_algo_DW.TappedDelay1_X[0],
           20U * sizeof(real_T));

    /* S-Function (sdspstatfcns): '<S7>/Mean1' */
    top_level_algo_B.Mean1_AccVal = top_level_algo_B.TappedDelay[0];
    str = 1;

    /* S-Function (sdspstatfcns): '<S7>/Mean' incorporates:
     *  S-Function (sfix_udelay): '<S7>/Tapped Delay'
     */
    Mean_AccVal_f = top_level_algo_DW.TappedDelay_X_f[0];
    str_0 = 1;
    for (i = 18; i >= 0; i--) {
      /* S-Function (sdspstatfcns): '<S7>/Mean1' */
      top_level_algo_B.Mean1_AccVal += top_level_algo_B.TappedDelay[str];
      str++;

      /* S-Function (sdspstatfcns): '<S7>/Mean' incorporates:
       *  S-Function (sfix_udelay): '<S7>/Tapped Delay'
       */
      Mean_AccVal_f += top_level_algo_DW.TappedDelay_X_f[str_0];
      str_0++;
    }

    /* S-Function (sdspstatfcns): '<S6>/Mean' incorporates:
     *  S-Function (sfix_udelay): '<S6>/Tapped Delay'
     */
    top_level_algo_B.Mean_AccVal = top_level_algo_DW.TappedDelay_X[0];
    str = 1;
    for (i = 98; i >= 0; i--) {
      top_level_algo_B.Mean_AccVal += top_level_algo_DW.TappedDelay_X[str];
      str++;
    }

    /* Gain: '<S6>/Compression  Sensitivity' incorporates:
     *  S-Function (sdspstatfcns): '<S6>/Mean'
     */
    top_level_algo_B.Mean_AccVal = top_level_algo_B.Mean_AccVal / 100.0 *
      top_level_algo_P.CompressionSensitivity_Gain;

    /* Product: '<S7>/Product' incorporates:
     *  Constant: '<S7>/Constant'
     *  Constant: '<S7>/Constant1'
     *  Product: '<S7>/Divide'
     *  S-Function (sdspstatfcns): '<S7>/Mean'
     */
    top_level_algo_B.Product = (real_T)div_nde_s32_floor(Mean_AccVal_f, 20) /
      top_level_algo_P.Constant1_Value * top_level_algo_P.Vdd;

    /* Chart: '<S7>/timer' incorporates:
     *  S-Function (sdspstatfcns): '<S7>/Mean1'
     */
    if (top_level_algo_DW.temporalCounter_i1 < 2047U) {
      top_level_algo_DW.temporalCounter_i1++;
    }

    if (top_level_algo_DW.is_active_c3_top_level_algo == 0U) {
      top_level_algo_DW.is_active_c3_top_level_algo = 1U;
      top_level_algo_DW.is_c3_top_level_algo = top_level_algo_IN_Starting;
      top_level_algo_DW.temporalCounter_i1 = 0U;
      i = 0;
    } else if (top_level_algo_DW.is_c3_top_level_algo ==
               top_level_algo_IN_Finished) {
      i = 1;
    } else {
      /* case IN_Starting: */
      i = 0;
      if (top_level_algo_DW.temporalCounter_i1 >= 2000U) {
        top_level_algo_DW.is_c3_top_level_algo = top_level_algo_IN_Finished;
        top_level_algo_B.baseline = top_level_algo_B.Mean1_AccVal / 20.0;
        i = 1;
      }
    }

    /* End of Chart: '<S7>/timer' */

    /* Switch: '<S7>/Switch' */
    if (i > top_level_algo_P.Switch_Threshold) {
      top_level_algo_B.Mean1_AccVal = top_level_algo_B.baseline;
    } else {
      top_level_algo_B.Mean1_AccVal = top_level_algo_B.Product;
    }

    /* Gain: '<S7>/Radius (mm)' incorporates:
     *  Gain: '<S7>/Gear Down'
     *  Gain: '<S7>/rad  per volt'
     *  Sum: '<S7>/Subtract'
     *  Switch: '<S7>/Switch'
     */
    rtb_Merge = 6.2831853071795862 / top_level_algo_P.Vdd *
      (top_level_algo_B.Mean1_AccVal - top_level_algo_B.Product) * (1.0 /
      top_level_algo_P.gear_ratio) * top_level_algo_P.Radiusmm_Gain;

    /* If: '<S60>/If' */
    if (rtb_Merge < 0.0) {
      /* Outputs for IfAction SubSystem: '<S60>/If Action Subsystem' incorporates:
       *  ActionPort: '<S62>/Action Port'
       */
      /* Gain: '<S7>/Radius (mm)' incorporates:
       *  Constant: '<S60>/Constant'
       *  Merge: '<S60>/Merge'
       *  SignalConversion generated from: '<S62>/In1'
       */
      rtb_Merge = top_level_algo_P.Constant_Value;

      /* End of Outputs for SubSystem: '<S60>/If Action Subsystem' */
    }

    /* End of If: '<S60>/If' */

    /* Sum: '<S6>/First Diff' incorporates:
     *  Delay: '<S6>/Delay'
     */
    top_level_algo_B.Mean1_AccVal = rtb_Merge - top_level_algo_DW.Delay_DSTATE;

    /* Sum: '<S6>/Second Diff' incorporates:
     *  Delay: '<S6>/Delay'
     *  Delay: '<S6>/Delay1'
     */
    top_level_algo_B.u = top_level_algo_DW.Delay_DSTATE -
      top_level_algo_DW.Delay1_DSTATE[0];

    /* Sum: '<S6>/Third Diff' incorporates:
     *  Delay: '<S6>/Delay1'
     *  Delay: '<S6>/Delay2'
     */
    top_level_algo_B.u_m = top_level_algo_DW.Delay1_DSTATE[0] -
      top_level_algo_DW.Delay2_DSTATE[0];

    /* Sum: '<S6>/Fourth Diff' incorporates:
     *  Delay: '<S6>/Delay2'
     *  Delay: '<S6>/Delay3'
     */
    top_level_algo_B.u_c = top_level_algo_DW.Delay2_DSTATE[0] -
      top_level_algo_DW.Delay3_DSTATE[0];

    /* Sum: '<S6>/Fifth Diff' incorporates:
     *  Delay: '<S6>/Delay3'
     *  Delay: '<S6>/Delay4'
     */
    top_level_algo_B.Clock1 = top_level_algo_DW.Delay3_DSTATE[0] -
      top_level_algo_DW.Delay4_DSTATE[0];

    /* Sum: '<S6>/5to30 Diff' incorporates:
     *  Delay: '<S6>/Delay4'
     *  Delay: '<S6>/Delay5'
     */
    top_level_algo_B.TmpMLSysMemLayoutBufferAtDi =
      top_level_algo_DW.Delay4_DSTATE[0] - top_level_algo_DW.Delay5_DSTATE[0];

    /* Signum: '<S6>/Sign' */
    if (rtIsNaN(top_level_algo_B.Mean1_AccVal)) {
      top_level_algo_B.Mean1_AccVal = (rtNaN);
    } else if (top_level_algo_B.Mean1_AccVal < 0.0) {
      top_level_algo_B.Mean1_AccVal = -1.0;
    } else {
      top_level_algo_B.Mean1_AccVal = (top_level_algo_B.Mean1_AccVal > 0.0);
    }

    /* Signum: '<S6>/Sign1' */
    if (rtIsNaN(top_level_algo_B.u)) {
      top_level_algo_B.u = (rtNaN);
    } else if (top_level_algo_B.u < 0.0) {
      top_level_algo_B.u = -1.0;
    } else {
      top_level_algo_B.u = (top_level_algo_B.u > 0.0);
    }

    /* Signum: '<S6>/Sign2' */
    if (rtIsNaN(top_level_algo_B.u_m)) {
      top_level_algo_B.u_m = (rtNaN);
    } else if (top_level_algo_B.u_m < 0.0) {
      top_level_algo_B.u_m = -1.0;
    } else {
      top_level_algo_B.u_m = (top_level_algo_B.u_m > 0.0);
    }

    /* Signum: '<S6>/Sign3' */
    if (rtIsNaN(top_level_algo_B.u_c)) {
      top_level_algo_B.u_c = (rtNaN);
    } else if (top_level_algo_B.u_c < 0.0) {
      top_level_algo_B.u_c = -1.0;
    } else {
      top_level_algo_B.u_c = (top_level_algo_B.u_c > 0.0);
    }

    /* Signum: '<S6>/Sign4' */
    if (rtIsNaN(top_level_algo_B.Clock1)) {
      top_level_algo_B.Clock1 = (rtNaN);
    } else if (top_level_algo_B.Clock1 < 0.0) {
      top_level_algo_B.Clock1 = -1.0;
    } else {
      top_level_algo_B.Clock1 = (top_level_algo_B.Clock1 > 0.0);
    }

    /* Signum: '<S6>/Sign5' */
    if (rtIsNaN(top_level_algo_B.TmpMLSysMemLayoutBufferAtDi)) {
      top_level_algo_B.TmpMLSysMemLayoutBufferAtDi = (rtNaN);
    } else if (top_level_algo_B.TmpMLSysMemLayoutBufferAtDi < 0.0) {
      top_level_algo_B.TmpMLSysMemLayoutBufferAtDi = -1.0;
    } else {
      top_level_algo_B.TmpMLSysMemLayoutBufferAtDi =
        (top_level_algo_B.TmpMLSysMemLayoutBufferAtDi > 0.0);
    }

    /* Sum: '<S6>/Add' incorporates:
     *  Gain: '<S6>/Gain'
     *  Gain: '<S6>/Gain1'
     *  Signum: '<S6>/Sign'
     *  Signum: '<S6>/Sign1'
     *  Signum: '<S6>/Sign2'
     *  Signum: '<S6>/Sign3'
     *  Signum: '<S6>/Sign4'
     *  Signum: '<S6>/Sign5'
     */
    top_level_algo_B.TmpMLSysMemLayoutBufferAtDi +=
      (((top_level_algo_P.Gain_Gain * top_level_algo_B.Mean1_AccVal +
         top_level_algo_P.Gain1_Gain * top_level_algo_B.u) +
        top_level_algo_B.u_m) + top_level_algo_B.u_c) + top_level_algo_B.Clock1;

    /* Logic: '<S6>/AND' incorporates:
     *  Constant: '<S57>/Constant'
     *  Constant: '<S59>/Constant'
     *  RelationalOperator: '<S57>/Compare'
     *  RelationalOperator: '<S59>/Compare'
     */
    rtb_IsPos = ((top_level_algo_B.TmpMLSysMemLayoutBufferAtDi >=
                  top_level_algo_P.Positive_const) &&
                 (top_level_algo_B.Mean_AccVal >=
                  top_level_algo_P.Longrangemotionup_const));

    /* Logic: '<S9>/Logical Operator4' incorporates:
     *  Logic: '<S6>/Zero'
     *  Logic: '<S9>/OR'
     */
    Delay1_DSTATE_m_tmp = !rtb_IsPos;

    /* Logic: '<S9>/Logical Operator5' incorporates:
     *  Delay: '<S9>/Delay1'
     *  Delay: '<S9>/Delay4'
     *  Logic: '<S9>/Logical Operator4'
     *  Logic: '<S9>/Logical Operator6'
     */
    top_level_algo_DW.Delay1_DSTATE_m = (Delay1_DSTATE_m_tmp &&
      (top_level_algo_DW.Delay4_DSTATE_a[0] || top_level_algo_DW.Delay1_DSTATE_m));

    /* Logic: '<S6>/AND1' incorporates:
     *  Constant: '<S56>/Constant'
     *  Constant: '<S58>/Constant'
     *  RelationalOperator: '<S56>/Compare'
     *  RelationalOperator: '<S58>/Compare'
     */
    rtb_IsNeg = ((top_level_algo_B.TmpMLSysMemLayoutBufferAtDi <=
                  top_level_algo_P.Negative_const) &&
                 (top_level_algo_B.Mean_AccVal <=
                  top_level_algo_P.Longrangemotiondown_const));

    /* Logic: '<S9>/Logical Operator7' incorporates:
     *  Delay: '<S9>/Delay1'
     *  Logic: '<S9>/NOT5'
     */
    rtb_LogicalOperator7 = (rtb_IsNeg && (!top_level_algo_DW.Delay1_DSTATE_m));

    /* Logic: '<S9>/AND1' incorporates:
     *  Delay: '<S9>/Delay3'
     *  Logic: '<S9>/NOT1'
     */
    rtb_AND1 = (rtb_LogicalOperator7 && (!top_level_algo_DW.Delay3_DSTATE_m[0]));

    /* Logic: '<S9>/Logical Operator' incorporates:
     *  Logic: '<S6>/Zero'
     *  Logic: '<S9>/OR1'
     */
    Delay7_DSTATE_tmp = !rtb_IsNeg;

    /* Logic: '<S9>/Logical Operator1' incorporates:
     *  Delay: '<S9>/Delay7'
     *  Delay: '<S9>/Delay8'
     *  Logic: '<S9>/Logical Operator'
     *  Logic: '<S9>/Logical Operator2'
     */
    top_level_algo_DW.Delay7_DSTATE = (Delay7_DSTATE_tmp &&
      (top_level_algo_DW.Delay8_DSTATE[0] || top_level_algo_DW.Delay7_DSTATE));

    /* Logic: '<S9>/Logical Operator3' incorporates:
     *  Delay: '<S9>/Delay7'
     *  Logic: '<S9>/NOT4'
     */
    rtb_LogicalOperator3 = (rtb_IsPos && (!top_level_algo_DW.Delay7_DSTATE));

    /* Logic: '<S9>/AND' incorporates:
     *  Delay: '<S9>/Delay6'
     *  Logic: '<S9>/NOT3'
     */
    rtb_AND = (rtb_LogicalOperator3 && (!top_level_algo_DW.Delay6_DSTATE[0]));

    /* Logic: '<S3>/Logical Operator' */
    rtb_LogicalOperator_a = (rtb_AND || rtb_AND1);

    /* Clock: '<S3>/Clock1' */
    top_level_algo_B.Clock1 = top_level_algo_M->Timing.t[0];

    /* Chart: '<S3>/Chart1' */
    if (top_level_algo_DW.temporalCounter_i1_o < 1023U) {
      top_level_algo_DW.temporalCounter_i1_o++;
    }

    if (top_level_algo_DW.is_active_c12_top_level_algo == 0U) {
      top_level_algo_DW.is_active_c12_top_level_algo = 1U;
      top_level_algo_DW.is_c12_top_level_algo = top_level_algo_IN_INIT;
    } else {
      switch (top_level_algo_DW.is_c12_top_level_algo) {
       case top_level_algo_IN_Counting:
        if ((top_level_algo_DW.temporalCounter_i1_o >= 10U) &&
            rtb_LogicalOperator_a) {
          top_level_algo_DW.is_c12_top_level_algo = top_level_algo_IN_Counting;
          top_level_algo_DW.temporalCounter_i1_o = 0U;
        } else if (top_level_algo_DW.temporalCounter_i1_o >= 1000U) {
          top_level_algo_DW.is_c12_top_level_algo = top_level_algo_IN_INIT;
        }
        break;

       case top_level_algo_IN_First:
        if ((top_level_algo_DW.temporalCounter_i1_o >= 10U) &&
            rtb_LogicalOperator_a) {
          top_level_algo_DW.is_c12_top_level_algo = top_level_algo_IN_Counting;
          top_level_algo_DW.temporalCounter_i1_o = 0U;
        }
        break;

       default:
        /* case IN_INIT: */
        if (rtb_LogicalOperator_a) {
          top_level_algo_DW.is_c12_top_level_algo = top_level_algo_IN_First;
          top_level_algo_DW.temporalCounter_i1_o = 0U;
        }
        break;
      }
    }

    /* End of Chart: '<S3>/Chart1' */

    /* Chart: '<S3>/Chart2' */
    if (top_level_algo_DW.temporalCounter_i1_a < 1023U) {
      top_level_algo_DW.temporalCounter_i1_a++;
    }

    if (top_level_algo_DW.is_active_c13_top_level_algo == 0U) {
      top_level_algo_DW.is_active_c13_top_level_algo = 1U;
      top_level_algo_DW.is_c13_top_level_algo = top_level_algo_IN_INIT;
      top_level_algo_DW.lastTs = 0.0;
      top_level_algo_B.paceDetect = 0.0;
    } else {
      switch (top_level_algo_DW.is_c13_top_level_algo) {
       case top_level_algo_IN_Counting:
        if ((top_level_algo_DW.temporalCounter_i1_a >= 10U) && rtb_AND) {
          top_level_algo_DW.is_c13_top_level_algo = top_level_algo_IN_Counting;
          top_level_algo_DW.temporalCounter_i1_a = 0U;
          top_level_algo_B.paceDetect = 60.0 / (top_level_algo_B.Clock1 -
            top_level_algo_DW.lastTs);
          top_level_algo_DW.lastTs = top_level_algo_B.Clock1;
        } else if (top_level_algo_DW.temporalCounter_i1_a >= 1000U) {
          top_level_algo_DW.is_c13_top_level_algo = top_level_algo_IN_INIT;
          top_level_algo_DW.lastTs = 0.0;
          top_level_algo_B.paceDetect = 0.0;
        }
        break;

       case top_level_algo_IN_First:
        if ((top_level_algo_DW.temporalCounter_i1_a >= 10U) && rtb_AND) {
          top_level_algo_DW.is_c13_top_level_algo = top_level_algo_IN_Counting;
          top_level_algo_DW.temporalCounter_i1_a = 0U;
          top_level_algo_B.paceDetect = 60.0 / (top_level_algo_B.Clock1 -
            top_level_algo_DW.lastTs);
          top_level_algo_DW.lastTs = top_level_algo_B.Clock1;
        }
        break;

       default:
        /* case IN_INIT: */
        if (rtb_AND) {
          top_level_algo_DW.is_c13_top_level_algo = top_level_algo_IN_First;
          top_level_algo_DW.temporalCounter_i1_a = 0U;
          top_level_algo_DW.lastTs = top_level_algo_B.Clock1;
        }
        break;
      }
    }

    /* End of Chart: '<S3>/Chart2' */

    /* Math: '<S10>/Mod' incorporates:
     *  Constant: '<S10>/Constant1'
     */
    top_level_algo_B.TmpMLSysMemLayoutBufferAtDi = rt_modd_snf
      (top_level_algo_B.paceDetect, top_level_algo_P.Constant1_Value_g);

    /* SwitchCase: '<S12>/Switch Case' incorporates:
     *  MATLABSystem: '<S10>/Divide by Constant and Round'
     *  Sum: '<S10>/Subtract'
     */
    top_level_algo_B.Mean1_AccVal = floor((top_level_algo_B.paceDetect -
      top_level_algo_B.TmpMLSysMemLayoutBufferAtDi) * 0.01);
    if (rtIsNaN(top_level_algo_B.Mean1_AccVal) || rtIsInf
        (top_level_algo_B.Mean1_AccVal)) {
      top_level_algo_B.Mean1_AccVal = 0.0;
    } else {
      top_level_algo_B.Mean1_AccVal = fmod(top_level_algo_B.Mean1_AccVal,
        4.294967296E+9);
    }

    switch (top_level_algo_B.Mean1_AccVal < 0.0 ? -(int32_T)(uint32_T)
            -top_level_algo_B.Mean1_AccVal : (int32_T)(uint32_T)
            top_level_algo_B.Mean1_AccVal) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem);

      /* End of Outputs for SubSystem: '<S12>/If Action Subsystem' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S16>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem1);

      /* End of Outputs for SubSystem: '<S12>/If Action Subsystem1' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S18>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem2);

      /* End of Outputs for SubSystem: '<S12>/If Action Subsystem2' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S19>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem3);

      /* End of Outputs for SubSystem: '<S12>/If Action Subsystem3' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S20>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem4);

      /* End of Outputs for SubSystem: '<S12>/If Action Subsystem4' */
      break;

     case 5:
      /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem5);

      /* End of Outputs for SubSystem: '<S12>/If Action Subsystem5' */
      break;

     case 6:
      /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem6' incorporates:
       *  ActionPort: '<S22>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem6);

      /* End of Outputs for SubSystem: '<S12>/If Action Subsystem6' */
      break;

     case 7:
      /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem7' incorporates:
       *  ActionPort: '<S23>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem7);

      /* End of Outputs for SubSystem: '<S12>/If Action Subsystem7' */
      break;

     case 8:
      /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem8' incorporates:
       *  ActionPort: '<S24>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem8);

      /* End of Outputs for SubSystem: '<S12>/If Action Subsystem8' */
      break;

     case 9:
      /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem10' incorporates:
       *  ActionPort: '<S17>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem10);

      /* End of Outputs for SubSystem: '<S12>/If Action Subsystem10' */
      break;
    }

    /* End of SwitchCase: '<S12>/Switch Case' */

    /* Math: '<S10>/Mod1' incorporates:
     *  Constant: '<S10>/Constant2'
     */
    top_level_algo_B.Mean_AccVal = rt_modd_snf
      (top_level_algo_B.TmpMLSysMemLayoutBufferAtDi,
       top_level_algo_P.Constant2_Value);

    /* SwitchCase: '<S13>/Switch Case' incorporates:
     *  MATLABSystem: '<S10>/Divide by Constant and Round1'
     *  Sum: '<S10>/Subtract1'
     */
    top_level_algo_B.Mean1_AccVal = floor
      ((top_level_algo_B.TmpMLSysMemLayoutBufferAtDi -
        top_level_algo_B.Mean_AccVal) * 0.1);
    if (rtIsNaN(top_level_algo_B.Mean1_AccVal) || rtIsInf
        (top_level_algo_B.Mean1_AccVal)) {
      top_level_algo_B.Mean1_AccVal = 0.0;
    } else {
      top_level_algo_B.Mean1_AccVal = fmod(top_level_algo_B.Mean1_AccVal,
        4.294967296E+9);
    }

    switch (top_level_algo_B.Mean1_AccVal < 0.0 ? -(int32_T)(uint32_T)
            -top_level_algo_B.Mean1_AccVal : (int32_T)(uint32_T)
            top_level_algo_B.Mean1_AccVal) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem' incorporates:
       *  ActionPort: '<S25>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
        &top_level_algo_P.IfActionSubsystem_l);

      /* End of Outputs for SubSystem: '<S13>/If Action Subsystem' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S26>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
        &top_level_algo_P.IfActionSubsystem1_d);

      /* End of Outputs for SubSystem: '<S13>/If Action Subsystem1' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S28>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
        &top_level_algo_P.IfActionSubsystem2_d);

      /* End of Outputs for SubSystem: '<S13>/If Action Subsystem2' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S29>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
        &top_level_algo_P.IfActionSubsystem3_p);

      /* End of Outputs for SubSystem: '<S13>/If Action Subsystem3' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S30>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
        &top_level_algo_P.IfActionSubsystem4_d);

      /* End of Outputs for SubSystem: '<S13>/If Action Subsystem4' */
      break;

     case 5:
      /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S31>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
        &top_level_algo_P.IfActionSubsystem5_h);

      /* End of Outputs for SubSystem: '<S13>/If Action Subsystem5' */
      break;

     case 6:
      /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem6' incorporates:
       *  ActionPort: '<S32>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
        &top_level_algo_P.IfActionSubsystem6_b);

      /* End of Outputs for SubSystem: '<S13>/If Action Subsystem6' */
      break;

     case 7:
      /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem7' incorporates:
       *  ActionPort: '<S33>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
        &top_level_algo_P.IfActionSubsystem7_h);

      /* End of Outputs for SubSystem: '<S13>/If Action Subsystem7' */
      break;

     case 8:
      /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem8' incorporates:
       *  ActionPort: '<S34>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
        &top_level_algo_P.IfActionSubsystem8_p);

      /* End of Outputs for SubSystem: '<S13>/If Action Subsystem8' */
      break;

     case 9:
      /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem10' incorporates:
       *  ActionPort: '<S27>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
        &top_level_algo_P.IfActionSubsystem10_l);

      /* End of Outputs for SubSystem: '<S13>/If Action Subsystem10' */
      break;
    }

    /* End of SwitchCase: '<S13>/Switch Case' */

    /* SwitchCase: '<S14>/Switch Case' */
    if (top_level_algo_B.Mean_AccVal < 0.0) {
      top_level_algo_B.Mean1_AccVal = ceil(top_level_algo_B.Mean_AccVal);
    } else {
      top_level_algo_B.Mean1_AccVal = floor(top_level_algo_B.Mean_AccVal);
    }

    if (rtIsNaN(top_level_algo_B.Mean1_AccVal) || rtIsInf
        (top_level_algo_B.Mean1_AccVal)) {
      top_level_algo_B.Mean1_AccVal = 0.0;
    } else {
      top_level_algo_B.Mean1_AccVal = fmod(top_level_algo_B.Mean1_AccVal,
        4.294967296E+9);
    }

    switch (top_level_algo_B.Mean1_AccVal < 0.0 ? -(int32_T)(uint32_T)
            -top_level_algo_B.Mean1_AccVal : (int32_T)(uint32_T)
            top_level_algo_B.Mean1_AccVal) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem' incorporates:
       *  ActionPort: '<S35>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
        &top_level_algo_P.IfActionSubsystem_j);

      /* End of Outputs for SubSystem: '<S14>/If Action Subsystem' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S36>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
        &top_level_algo_P.IfActionSubsystem1_a);

      /* End of Outputs for SubSystem: '<S14>/If Action Subsystem1' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S38>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
        &top_level_algo_P.IfActionSubsystem2_i);

      /* End of Outputs for SubSystem: '<S14>/If Action Subsystem2' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S39>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
        &top_level_algo_P.IfActionSubsystem3_c);

      /* End of Outputs for SubSystem: '<S14>/If Action Subsystem3' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S40>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
        &top_level_algo_P.IfActionSubsystem4_db);

      /* End of Outputs for SubSystem: '<S14>/If Action Subsystem4' */
      break;

     case 5:
      /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S41>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
        &top_level_algo_P.IfActionSubsystem5_hh);

      /* End of Outputs for SubSystem: '<S14>/If Action Subsystem5' */
      break;

     case 6:
      /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem6' incorporates:
       *  ActionPort: '<S42>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
        &top_level_algo_P.IfActionSubsystem6_c);

      /* End of Outputs for SubSystem: '<S14>/If Action Subsystem6' */
      break;

     case 7:
      /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem7' incorporates:
       *  ActionPort: '<S43>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
        &top_level_algo_P.IfActionSubsystem7_n);

      /* End of Outputs for SubSystem: '<S14>/If Action Subsystem7' */
      break;

     case 8:
      /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem8' incorporates:
       *  ActionPort: '<S44>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
        &top_level_algo_P.IfActionSubsystem8_f);

      /* End of Outputs for SubSystem: '<S14>/If Action Subsystem8' */
      break;

     case 9:
      /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem10' incorporates:
       *  ActionPort: '<S37>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
        &top_level_algo_P.IfActionSubsystem10_m);

      /* End of Outputs for SubSystem: '<S14>/If Action Subsystem10' */
      break;
    }

    /* End of SwitchCase: '<S14>/Switch Case' */

    /* Chart: '<S3>/Chart' */
    if (top_level_algo_DW.is_active_c4_top_level_algo == 0U) {
      top_level_algo_DW.is_active_c4_top_level_algo = 1U;
      top_level_algo_DW.is_c4_top_level_algo = top_level_algo_IN_INIT;
      top_level_algo_DW.comp = 0.0;
      top_level_algo_DW.first = 0.0;
      top_level_algo_DW.second = 0.0;
      top_level_algo_DW.third = 0.0;
      top_level_algo_DW.fourth = 0.0;
    } else {
      switch (top_level_algo_DW.is_c4_top_level_algo) {
       case top_level_algo_IN_DETECTION:
        if ((top_level_algo_DW.first != 0.0) && (top_level_algo_DW.second != 0.0)
            && (top_level_algo_DW.third != 0.0) && (top_level_algo_DW.fourth ==
             0.0)) {
          top_level_algo_DW.is_c4_top_level_algo = top_level_algo_IN_FOUR;
          top_level_algo_DW.fourth = top_level_algo_B.Clock1;
        } else if (top_level_algo_DW.first == 0.0) {
          top_level_algo_DW.is_c4_top_level_algo = top_level_algo_IN_ONE;
          top_level_algo_DW.first = top_level_algo_B.Clock1;
        } else if ((top_level_algo_DW.first != 0.0) && (top_level_algo_DW.second
                    == 0.0)) {
          top_level_algo_DW.is_c4_top_level_algo = top_level_algo_IN_TWO;
          top_level_algo_DW.second = top_level_algo_B.Clock1;
        } else if ((top_level_algo_DW.first != 0.0) && (top_level_algo_DW.second
                    != 0.0) && (top_level_algo_DW.third == 0.0)) {
          top_level_algo_DW.is_c4_top_level_algo = top_level_algo_IN_THREE;
          top_level_algo_DW.third = top_level_algo_B.Clock1;
        }
        break;

       case top_level_algo_IN_FOUR:
        if (!rtb_AND) {
          top_level_algo_DW.is_c4_top_level_algo = top_level_algo_IN_POLLING;
        }
        break;

       case top_level_algo_IN_INIT:
        if (rtb_AND) {
          top_level_algo_DW.is_c4_top_level_algo = top_level_algo_IN_Wait_l;
          top_level_algo_DW.last_count = top_level_algo_B.Clock1;
        }
        break;

       case top_level_algo_IN_ONE:
        if (!rtb_AND) {
          top_level_algo_DW.is_c4_top_level_algo = top_level_algo_IN_POLLING;
        }
        break;

       case top_level_algo_IN_POLLING:
        if (rtb_AND && (top_level_algo_DW.comp <= 3.0)) {
          top_level_algo_DW.is_c4_top_level_algo = top_level_algo_IN_DETECTION;
          top_level_algo_DW.comp++;
          top_level_algo_DW.last_count = top_level_algo_B.Clock1;
        } else if (top_level_algo_B.Clock1 - top_level_algo_DW.last_count > 4.0)
        {
          top_level_algo_DW.is_c4_top_level_algo = top_level_algo_IN_INIT;
          top_level_algo_DW.comp = 0.0;
          top_level_algo_DW.first = 0.0;
          top_level_algo_DW.second = 0.0;
          top_level_algo_DW.third = 0.0;
          top_level_algo_DW.fourth = 0.0;
        } else if (rtb_AND && (top_level_algo_DW.comp > 3.0)) {
          top_level_algo_DW.is_c4_top_level_algo = top_level_algo_IN_SHORTEN;
          top_level_algo_DW.last_count = top_level_algo_B.Clock1;
          top_level_algo_DW.first = top_level_algo_DW.second;
          top_level_algo_DW.second = top_level_algo_DW.third;
          top_level_algo_DW.third = top_level_algo_DW.fourth;
          top_level_algo_DW.fourth = top_level_algo_B.Clock1;
        }
        break;

       case top_level_algo_IN_SHORTEN:
        if (!rtb_AND) {
          top_level_algo_DW.is_c4_top_level_algo = top_level_algo_IN_POLLING;
        }
        break;

       case top_level_algo_IN_THREE:
        if (!rtb_AND) {
          top_level_algo_DW.is_c4_top_level_algo = top_level_algo_IN_POLLING;
        }
        break;

       case top_level_algo_IN_TWO:
        if (!rtb_AND) {
          top_level_algo_DW.is_c4_top_level_algo = top_level_algo_IN_POLLING;
        }
        break;

       default:
        /* case IN_Wait: */
        if (!rtb_AND) {
          top_level_algo_DW.is_c4_top_level_algo = top_level_algo_IN_POLLING;
        }
        break;
      }
    }

    /* End of Chart: '<S3>/Chart' */

    /* Switch: '<S90>/Reset' incorporates:
     *  Delay: '<S9>/Delay2'
     *  Memory: '<S90>/Memory'
     *  MinMax: '<S85>/MinMax'
     */
    if (top_level_algo_DW.Delay2_DSTATE_m[0U]) {
      /* Switch: '<S90>/Reset' incorporates:
       *  Constant: '<S90>/Initial Condition'
       */
      rtb_Reset = top_level_algo_P.MinBDC_vinit;
    } else if ((rtb_Merge <= top_level_algo_DW.Memory_PreviousInput) || rtIsNaN
               (top_level_algo_DW.Memory_PreviousInput)) {
      /* MinMax: '<S85>/MinMax' incorporates:
       *  Switch: '<S90>/Reset'
       */
      rtb_Reset = rtb_Merge;
    } else {
      /* Switch: '<S90>/Reset' incorporates:
       *  Memory: '<S90>/Memory'
       *  MinMax: '<S85>/MinMax'
       */
      rtb_Reset = top_level_algo_DW.Memory_PreviousInput;
    }

    /* End of Switch: '<S90>/Reset' */

    /* Chart: '<S9>/sample and hold1' */
    top_level_algo_sampleandhold(rtb_Reset, rtb_AND,
      &top_level_algo_B.Mean_AccVal, &top_level_algo_DW.sf_sampleandhold1);

    /* Switch: '<S89>/Reset' incorporates:
     *  Delay: '<S9>/Delay'
     *  Memory: '<S89>/Memory'
     *  MinMax: '<S84>/MinMax'
     */
    if (top_level_algo_DW.Delay_DSTATE_a[0U]) {
      /* Switch: '<S89>/Reset' incorporates:
       *  Constant: '<S89>/Initial Condition'
       */
      top_level_algo_B.Reset_f = top_level_algo_P.MaxBDC_vinit;
    } else if ((rtb_Merge >= top_level_algo_DW.Memory_PreviousInput_l) ||
               rtIsNaN(top_level_algo_DW.Memory_PreviousInput_l)) {
      /* MinMax: '<S84>/MinMax' incorporates:
       *  Switch: '<S89>/Reset'
       */
      top_level_algo_B.Reset_f = rtb_Merge;
    } else {
      /* Switch: '<S89>/Reset' incorporates:
       *  Memory: '<S89>/Memory'
       *  MinMax: '<S84>/MinMax'
       */
      top_level_algo_B.Reset_f = top_level_algo_DW.Memory_PreviousInput_l;
    }

    /* End of Switch: '<S89>/Reset' */

    /* Chart: '<S9>/sample and hold' */
    top_level_algo_sampleandhold(top_level_algo_B.Reset_f, rtb_AND1,
      &top_level_algo_B.Mean_AccVal, &top_level_algo_DW.sf_sampleandhold);

    /* Logic: '<S9>/OR1' incorporates:
     *  Logic: '<S6>/Zero'
     *  Logic: '<S9>/OR'
     */
    rtb_AND1 = ((!Delay1_DSTATE_m_tmp) || (!Delay7_DSTATE_tmp));

    /* Logic: '<S9>/NOT2' incorporates:
     *  Logic: '<S9>/OR1'
     */
    rtb_NOT2 = (rtb_AND1 && Delay7_DSTATE_tmp);

    /* Logic: '<S9>/NOT' incorporates:
     *  Logic: '<S9>/OR'
     */
    rtb_NOT = (Delay1_DSTATE_m_tmp && rtb_AND1);

    /* Sum: '<S6>/30 Diff' incorporates:
     *  Delay: '<S6>/Delay5'
     */
    top_level_algo_B.u0Diff = rtb_Merge - top_level_algo_DW.Delay5_DSTATE[0];

    /* MATLABSystem: '<S75>/Digital Port Write' incorporates:
     *  Constant: '<S64>/Constant'
     *  RelationalOperator: '<S64>/Compare'
     */
    top_level_algo_B.portNameLoc = GPIOE;
    if (rtb_Merge > top_level_algo_P.CompareToConstant_const) {
      i = 64;
    } else {
      i = 0;
    }

    LL_GPIO_SetOutputPin(top_level_algo_B.portNameLoc, (uint32_T)i);
    LL_GPIO_ResetOutputPin(top_level_algo_B.portNameLoc, ~(uint32_T)i & 64U);

    /* End of MATLABSystem: '<S75>/Digital Port Write' */

    /* MATLABSystem: '<S77>/Digital Port Write' incorporates:
     *  Constant: '<S65>/Constant'
     *  RelationalOperator: '<S65>/Compare'
     */
    top_level_algo_B.portNameLoc = GPIOE;
    if (rtb_Merge > top_level_algo_P.CompareToConstant1_const) {
      i = 32;
    } else {
      i = 0;
    }

    LL_GPIO_SetOutputPin(top_level_algo_B.portNameLoc, (uint32_T)i);
    LL_GPIO_ResetOutputPin(top_level_algo_B.portNameLoc, ~(uint32_T)i & 32U);

    /* End of MATLABSystem: '<S77>/Digital Port Write' */

    /* MATLABSystem: '<S79>/Digital Port Write' incorporates:
     *  Constant: '<S66>/Constant'
     *  RelationalOperator: '<S66>/Compare'
     */
    top_level_algo_B.portNameLoc = GPIOE;
    if (rtb_Merge > top_level_algo_P.CompareToConstant2_const) {
      i = 16;
    } else {
      i = 0;
    }

    LL_GPIO_SetOutputPin(top_level_algo_B.portNameLoc, (uint32_T)i);
    LL_GPIO_ResetOutputPin(top_level_algo_B.portNameLoc, ~(uint32_T)i & 16U);

    /* End of MATLABSystem: '<S79>/Digital Port Write' */

    /* MATLABSystem: '<S81>/Digital Port Write' incorporates:
     *  Constant: '<S67>/Constant'
     *  RelationalOperator: '<S67>/Compare'
     */
    top_level_algo_B.portNameLoc = GPIOE;
    if (rtb_Merge > top_level_algo_P.CompareToConstant3_const) {
      i = 8;
    } else {
      i = 0;
    }

    LL_GPIO_SetOutputPin(top_level_algo_B.portNameLoc, (uint32_T)i);
    LL_GPIO_ResetOutputPin(top_level_algo_B.portNameLoc, ~(uint32_T)i & 8U);

    /* End of MATLABSystem: '<S81>/Digital Port Write' */

    /* MATLABSystem: '<S83>/Digital Port Write' incorporates:
     *  Constant: '<S68>/Constant'
     *  RelationalOperator: '<S68>/Compare'
     */
    top_level_algo_B.portNameLoc = GPIOE;
    if (rtb_Merge > top_level_algo_P.CompareToConstant4_const) {
      i = 4;
    } else {
      i = 0;
    }

    LL_GPIO_SetOutputPin(top_level_algo_B.portNameLoc, (uint32_T)i);
    LL_GPIO_ResetOutputPin(top_level_algo_B.portNameLoc, ~(uint32_T)i & 4U);

    /* End of MATLABSystem: '<S83>/Digital Port Write' */

    /* DiscretePulseGenerator: '<S1>/Pulse Generator' */
    top_level_algo_B.Mean_AccVal = (top_level_algo_DW.clockTickCounter <
      top_level_algo_P.PulseGenerator_Duty) &&
      (top_level_algo_DW.clockTickCounter >= 0) ?
      top_level_algo_P.PulseGenerator_Amp : 0.0;
    if (top_level_algo_DW.clockTickCounter >=
        top_level_algo_P.PulseGenerator_Period - 1.0) {
      top_level_algo_DW.clockTickCounter = 0;
    } else {
      top_level_algo_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<S1>/Pulse Generator' */

    /* Chart: '<S11>/ClockLogic' */
    if (top_level_algo_DW.temporalCounter_i1_b < 15U) {
      top_level_algo_DW.temporalCounter_i1_b++;
    }

    if (top_level_algo_DW.is_active_c5_top_level_algo == 0U) {
      top_level_algo_DW.is_active_c5_top_level_algo = 1U;
      top_level_algo_DW.is_c5_top_level_algo = top_level_algo_IN_START;
      top_level_algo_DW.counter = 0.0;
      top_level_algo_B.CLK = 0.0;
    } else {
      switch (top_level_algo_DW.is_c5_top_level_algo) {
       case top_level_algo_IN_HIGH:
        if (top_level_algo_DW.temporalCounter_i1_b >= 10U) {
          top_level_algo_DW.is_c5_top_level_algo = top_level_algo_IN_LOW;
          top_level_algo_DW.temporalCounter_i1_b = 0U;
          top_level_algo_B.CLK = 0.0;
          top_level_algo_DW.counter++;
        }
        break;

       case top_level_algo_IN_LOW:
        if (top_level_algo_DW.counter == 36.0) {
          top_level_algo_DW.is_c5_top_level_algo = top_level_algo_IN_START;
          top_level_algo_DW.counter = 0.0;
          top_level_algo_B.CLK = 0.0;
        } else if (top_level_algo_DW.temporalCounter_i1_b >= 10U) {
          top_level_algo_DW.is_c5_top_level_algo = top_level_algo_IN_HIGH;
          top_level_algo_DW.temporalCounter_i1_b = 0U;
          top_level_algo_B.CLK = 1.0;
        }
        break;

       case top_level_algo_IN_START:
        if (top_level_algo_B.Mean_AccVal == 1.0) {
          top_level_algo_DW.is_c5_top_level_algo = top_level_algo_IN_WAIT;
          top_level_algo_DW.temporalCounter_i1_b = 0U;
        } else {
          top_level_algo_DW.counter = 0.0;
          top_level_algo_B.CLK = 0.0;
        }
        break;

       default:
        /* case IN_WAIT: */
        if (top_level_algo_DW.temporalCounter_i1_b >= 10U) {
          top_level_algo_DW.is_c5_top_level_algo = top_level_algo_IN_HIGH;
          top_level_algo_DW.temporalCounter_i1_b = 0U;
          top_level_algo_B.CLK = 1.0;
        }
        break;
      }
    }

    /* End of Chart: '<S11>/ClockLogic' */

    /* MATLABSystem: '<S53>/Digital Port Write' */
    top_level_algo_B.portNameLoc = GPIOE;
    if (top_level_algo_B.CLK != 0.0) {
      i = 256;
    } else {
      i = 0;
    }

    LL_GPIO_SetOutputPin(top_level_algo_B.portNameLoc, (uint32_T)i);
    LL_GPIO_ResetOutputPin(top_level_algo_B.portNameLoc, ~(uint32_T)i & 256U);

    /* End of MATLABSystem: '<S53>/Digital Port Write' */

    /* Sum: '<S10>/Add' incorporates:
     *  ArithShift: '<S10>/Shift Arithmetic1'
     *  ArithShift: '<S10>/Shift Arithmetic2'
     *  DataTypeConversion: '<S10>/Cast To Double'
     *  DataTypeConversion: '<S10>/Cast To Double1'
     *  DataTypeConversion: '<S10>/Cast To Double2'
     */
    rtb_Add = (((uint32_T)top_level_algo_B.Merge_b << 8) +
               top_level_algo_B.Merge) + ((uint32_T)top_level_algo_B.Merge_d <<
      16);

    /* Chart: '<S11>/DataLogic' */
    if (top_level_algo_DW.temporalCounter_i1_ah < 31U) {
      top_level_algo_DW.temporalCounter_i1_ah++;
    }

    if (top_level_algo_DW.is_active_c6_top_level_algo == 0U) {
      top_level_algo_DW.is_active_c6_top_level_algo = 1U;
      top_level_algo_DW.is_c6_top_level_algo = top_level_algo_IN_LOAD;
      top_level_algo_B.data = 0U;
      top_level_algo_DW.Holder = rtb_Add;
    } else {
      switch (top_level_algo_DW.is_c6_top_level_algo) {
       case top_level_algo_IN_CHECK:
        if (top_level_algo_DW.Holder == 0U) {
          top_level_algo_DW.is_c6_top_level_algo = top_level_algo_IN_WAITING;
          top_level_algo_DW.temporalCounter_i1_ah = 0U;
        } else if (top_level_algo_DW.temporalCounter_i1_ah >= 10U) {
          top_level_algo_DW.is_c6_top_level_algo = top_level_algo_IN_MASK;
          top_level_algo_DW.temporalCounter_i1_ah = 0U;
          top_level_algo_B.data = top_level_algo_DW.Holder & 1U;
        }
        break;

       case top_level_algo_IN_LOAD:
        if (top_level_algo_B.Mean_AccVal == 1.0) {
          top_level_algo_DW.is_c6_top_level_algo = top_level_algo_IN_Wait;
          top_level_algo_DW.temporalCounter_i1_ah = 0U;
        }
        break;

       case top_level_algo_IN_MASK:
        if (top_level_algo_DW.temporalCounter_i1_ah >= 10U) {
          top_level_algo_DW.is_c6_top_level_algo = top_level_algo_IN_CHECK;
          top_level_algo_DW.temporalCounter_i1_ah = 0U;
          top_level_algo_DW.Holder >>= 1;
        }
        break;

       case top_level_algo_IN_START_l:
        if (top_level_algo_DW.temporalCounter_i1_ah >= 20U) {
          top_level_algo_DW.is_c6_top_level_algo = top_level_algo_IN_MASK;
          top_level_algo_DW.temporalCounter_i1_ah = 0U;
          top_level_algo_B.data = top_level_algo_DW.Holder & 1U;
        }
        break;

       case top_level_algo_IN_WAITING:
        if (top_level_algo_DW.temporalCounter_i1_ah >= 10U) {
          top_level_algo_DW.is_c6_top_level_algo = top_level_algo_IN_LOAD;
          top_level_algo_B.data = 0U;
          top_level_algo_DW.Holder = rtb_Add;
        }
        break;

       default:
        /* case IN_Wait: */
        if (top_level_algo_DW.temporalCounter_i1_ah >= 5U) {
          top_level_algo_DW.is_c6_top_level_algo = top_level_algo_IN_START_l;
          top_level_algo_DW.temporalCounter_i1_ah = 0U;
          top_level_algo_B.data = 1U;
        }
        break;
      }
    }

    /* End of Chart: '<S11>/DataLogic' */

    /* MATLABSystem: '<S55>/Digital Port Write' */
    top_level_algo_B.portNameLoc = GPIOE;
    if (top_level_algo_B.data != 0U) {
      i = 512;
    } else {
      i = 0;
    }

    LL_GPIO_SetOutputPin(top_level_algo_B.portNameLoc, (uint32_T)i);
    LL_GPIO_ResetOutputPin(top_level_algo_B.portNameLoc, ~(uint32_T)i & 512U);

    /* End of MATLABSystem: '<S55>/Digital Port Write' */

    /* MATLABSystem: '<S48>/Analog to Digital Converter' */
    top_level_algo_B.triggerType = ADC_TRIGGER_AND_READ;
    regularReadADCDMA(top_level_algo_DW.obj.ADCHandle,
                      top_level_algo_B.triggerType, &data);

    /* DataTypeConversion: '<Root>/Cast To Double' incorporates:
     *  MATLABSystem: '<S48>/Analog to Digital Converter'
     */
    top_level_algo_B.CastToDouble = data;
  }

  {
    int_T i;
    for (i = 0; i < 19; i++) {
      /* Update for S-Function (sfix_udelay): '<S7>/Tapped Delay1' */
      top_level_algo_DW.TappedDelay1_X[i] = top_level_algo_DW.TappedDelay1_X[i +
        1];

      /* Update for S-Function (sfix_udelay): '<S7>/Tapped Delay' */
      top_level_algo_DW.TappedDelay_X_f[i] = top_level_algo_DW.TappedDelay_X_f[i
        + 1];
    }

    /* Update for S-Function (sfix_udelay): '<S7>/Tapped Delay1' */
    top_level_algo_DW.TappedDelay1_X[19] = top_level_algo_B.Product;

    /* Update for S-Function (sfix_udelay): '<S7>/Tapped Delay' */
    top_level_algo_DW.TappedDelay_X_f[19] = top_level_algo_B.CastToDouble;

    /* Update for S-Function (sfix_udelay): '<S6>/Tapped Delay' */
    for (i = 0; i < 99; i++) {
      top_level_algo_DW.TappedDelay_X[i] = top_level_algo_DW.TappedDelay_X[i + 1];
    }

    top_level_algo_DW.TappedDelay_X[99] = top_level_algo_B.u0Diff;

    /* End of Update for S-Function (sfix_udelay): '<S6>/Tapped Delay' */

    /* Update for Delay: '<S6>/Delay' */
    top_level_algo_DW.Delay_DSTATE = rtb_Merge;

    /* Update for Delay: '<S6>/Delay1' */
    top_level_algo_DW.Delay1_DSTATE[0] = top_level_algo_DW.Delay1_DSTATE[1];
    top_level_algo_DW.Delay1_DSTATE[1] = rtb_Merge;

    /* Update for Delay: '<S6>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE[0] = top_level_algo_DW.Delay2_DSTATE[1];
    top_level_algo_DW.Delay2_DSTATE[1] = top_level_algo_DW.Delay2_DSTATE[2];
    top_level_algo_DW.Delay2_DSTATE[2] = rtb_Merge;

    /* Update for Delay: '<S6>/Delay3' */
    top_level_algo_DW.Delay3_DSTATE[0] = top_level_algo_DW.Delay3_DSTATE[1];
    top_level_algo_DW.Delay3_DSTATE[1] = top_level_algo_DW.Delay3_DSTATE[2];
    top_level_algo_DW.Delay3_DSTATE[2] = top_level_algo_DW.Delay3_DSTATE[3];
    top_level_algo_DW.Delay3_DSTATE[3] = rtb_Merge;

    /* Update for Delay: '<S6>/Delay4' */
    top_level_algo_DW.Delay4_DSTATE[0] = top_level_algo_DW.Delay4_DSTATE[1];
    top_level_algo_DW.Delay4_DSTATE[1] = top_level_algo_DW.Delay4_DSTATE[2];
    top_level_algo_DW.Delay4_DSTATE[2] = top_level_algo_DW.Delay4_DSTATE[3];
    top_level_algo_DW.Delay4_DSTATE[3] = top_level_algo_DW.Delay4_DSTATE[4];
    top_level_algo_DW.Delay4_DSTATE[4] = rtb_Merge;

    /* Update for Delay: '<S6>/Delay5' */
    for (i = 0; i < 49; i++) {
      top_level_algo_DW.Delay5_DSTATE[i] = top_level_algo_DW.Delay5_DSTATE[i + 1];
    }

    top_level_algo_DW.Delay5_DSTATE[49] = rtb_Merge;

    /* End of Update for Delay: '<S6>/Delay5' */

    /* Update for Delay: '<S9>/Delay4' */
    top_level_algo_DW.Delay4_DSTATE_a[0] = top_level_algo_DW.Delay4_DSTATE_a[1];
    top_level_algo_DW.Delay4_DSTATE_a[1] = rtb_IsNeg;

    /* Update for Delay: '<S9>/Delay3' */
    top_level_algo_DW.Delay3_DSTATE_m[0] = top_level_algo_DW.Delay3_DSTATE_m[1];
    top_level_algo_DW.Delay3_DSTATE_m[1] = rtb_LogicalOperator7;

    /* Update for Delay: '<S9>/Delay8' */
    top_level_algo_DW.Delay8_DSTATE[0] = top_level_algo_DW.Delay8_DSTATE[1];
    top_level_algo_DW.Delay8_DSTATE[1] = rtb_IsPos;

    /* Update for Delay: '<S9>/Delay6' */
    top_level_algo_DW.Delay6_DSTATE[0] = top_level_algo_DW.Delay6_DSTATE[1];
    top_level_algo_DW.Delay6_DSTATE[1] = rtb_LogicalOperator3;

    /* Update for Memory: '<S90>/Memory' */
    top_level_algo_DW.Memory_PreviousInput = rtb_Reset;

    /* Update for Delay: '<S9>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE_m[0] = top_level_algo_DW.Delay2_DSTATE_m[1];

    /* Update for Delay: '<S9>/Delay' */
    top_level_algo_DW.Delay_DSTATE_a[0] = top_level_algo_DW.Delay_DSTATE_a[1];

    /* Update for Delay: '<S9>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE_m[1] = top_level_algo_DW.Delay2_DSTATE_m[2];

    /* Update for Delay: '<S9>/Delay' */
    top_level_algo_DW.Delay_DSTATE_a[1] = top_level_algo_DW.Delay_DSTATE_a[2];

    /* Update for Delay: '<S9>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE_m[2] = top_level_algo_DW.Delay2_DSTATE_m[3];

    /* Update for Delay: '<S9>/Delay' */
    top_level_algo_DW.Delay_DSTATE_a[2] = top_level_algo_DW.Delay_DSTATE_a[3];

    /* Update for Delay: '<S9>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE_m[3] = top_level_algo_DW.Delay2_DSTATE_m[4];

    /* Update for Delay: '<S9>/Delay' */
    top_level_algo_DW.Delay_DSTATE_a[3] = top_level_algo_DW.Delay_DSTATE_a[4];

    /* Update for Delay: '<S9>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE_m[4] = rtb_NOT2;

    /* Update for Delay: '<S9>/Delay' */
    top_level_algo_DW.Delay_DSTATE_a[4] = rtb_NOT;

    /* Update for Memory: '<S89>/Memory' */
    top_level_algo_DW.Memory_PreviousInput_l = top_level_algo_B.Reset_f;
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  top_level_algo_M->Timing.t[0] =
    ((time_T)(++top_level_algo_M->Timing.clockTick0)) *
    top_level_algo_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    top_level_algo_M->Timing.clockTick1++;
  }

  rate_scheduler();
}

/* Model initialize function */
void top_level_algo_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&top_level_algo_M->solverInfo,
                          &top_level_algo_M->Timing.simTimeStep);
    rtsiSetTPtr(&top_level_algo_M->solverInfo, &rtmGetTPtr(top_level_algo_M));
    rtsiSetStepSizePtr(&top_level_algo_M->solverInfo,
                       &top_level_algo_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&top_level_algo_M->solverInfo, (&rtmGetErrorStatus
      (top_level_algo_M)));
    rtsiSetRTModelPtr(&top_level_algo_M->solverInfo, top_level_algo_M);
  }

  rtsiSetSimTimeStep(&top_level_algo_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&top_level_algo_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(top_level_algo_M, &top_level_algo_M->Timing.tArray[0]);
  top_level_algo_M->Timing.stepSize0 = 0.001;

  {
    real_T displacement;
    int32_T i;
    for (i = 0; i < 20; i++) {
      /* InitializeConditions for S-Function (sfix_udelay): '<S7>/Tapped Delay1' */
      top_level_algo_DW.TappedDelay1_X[i] = top_level_algo_P.TappedDelay1_vinit;

      /* InitializeConditions for S-Function (sfix_udelay): '<S7>/Tapped Delay' */
      top_level_algo_DW.TappedDelay_X_f[i] =
        top_level_algo_P.TappedDelay_vinit_l;
    }

    /* InitializeConditions for S-Function (sfix_udelay): '<S6>/Tapped Delay' */
    for (i = 0; i < 100; i++) {
      top_level_algo_DW.TappedDelay_X[i] = top_level_algo_P.TappedDelay_vinit;
    }

    /* End of InitializeConditions for S-Function (sfix_udelay): '<S6>/Tapped Delay' */

    /* InitializeConditions for Delay: '<S6>/Delay' */
    top_level_algo_DW.Delay_DSTATE = top_level_algo_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S6>/Delay1' */
    top_level_algo_DW.Delay1_DSTATE[0] =
      top_level_algo_P.Delay1_InitialCondition;
    top_level_algo_DW.Delay1_DSTATE[1] =
      top_level_algo_P.Delay1_InitialCondition;

    /* InitializeConditions for Delay: '<S6>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE[0] =
      top_level_algo_P.Delay2_InitialCondition;
    top_level_algo_DW.Delay2_DSTATE[1] =
      top_level_algo_P.Delay2_InitialCondition;
    top_level_algo_DW.Delay2_DSTATE[2] =
      top_level_algo_P.Delay2_InitialCondition;

    /* InitializeConditions for Delay: '<S6>/Delay3' */
    top_level_algo_DW.Delay3_DSTATE[0] =
      top_level_algo_P.Delay3_InitialCondition;
    top_level_algo_DW.Delay3_DSTATE[1] =
      top_level_algo_P.Delay3_InitialCondition;
    top_level_algo_DW.Delay3_DSTATE[2] =
      top_level_algo_P.Delay3_InitialCondition;
    top_level_algo_DW.Delay3_DSTATE[3] =
      top_level_algo_P.Delay3_InitialCondition;

    /* InitializeConditions for Delay: '<S6>/Delay4' */
    for (i = 0; i < 5; i++) {
      top_level_algo_DW.Delay4_DSTATE[i] =
        top_level_algo_P.Delay4_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S6>/Delay4' */

    /* InitializeConditions for Delay: '<S6>/Delay5' */
    for (i = 0; i < 50; i++) {
      top_level_algo_DW.Delay5_DSTATE[i] =
        top_level_algo_P.Delay5_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S6>/Delay5' */

    /* InitializeConditions for Delay: '<S9>/Delay1' */
    top_level_algo_DW.Delay1_DSTATE_m =
      top_level_algo_P.Delay1_InitialCondition_d;

    /* InitializeConditions for Delay: '<S9>/Delay7' */
    top_level_algo_DW.Delay7_DSTATE = top_level_algo_P.Delay7_InitialCondition;

    /* InitializeConditions for Delay: '<S9>/Delay4' */
    top_level_algo_DW.Delay4_DSTATE_a[0] =
      top_level_algo_P.Delay4_InitialCondition_f;

    /* InitializeConditions for Delay: '<S9>/Delay3' */
    top_level_algo_DW.Delay3_DSTATE_m[0] =
      top_level_algo_P.Delay3_InitialCondition_k;

    /* InitializeConditions for Delay: '<S9>/Delay8' */
    top_level_algo_DW.Delay8_DSTATE[0] =
      top_level_algo_P.Delay8_InitialCondition;

    /* InitializeConditions for Delay: '<S9>/Delay6' */
    top_level_algo_DW.Delay6_DSTATE[0] =
      top_level_algo_P.Delay6_InitialCondition;

    /* InitializeConditions for Delay: '<S9>/Delay4' */
    top_level_algo_DW.Delay4_DSTATE_a[1] =
      top_level_algo_P.Delay4_InitialCondition_f;

    /* InitializeConditions for Delay: '<S9>/Delay3' */
    top_level_algo_DW.Delay3_DSTATE_m[1] =
      top_level_algo_P.Delay3_InitialCondition_k;

    /* InitializeConditions for Delay: '<S9>/Delay8' */
    top_level_algo_DW.Delay8_DSTATE[1] =
      top_level_algo_P.Delay8_InitialCondition;

    /* InitializeConditions for Delay: '<S9>/Delay6' */
    top_level_algo_DW.Delay6_DSTATE[1] =
      top_level_algo_P.Delay6_InitialCondition;

    /* InitializeConditions for Memory: '<S90>/Memory' */
    top_level_algo_DW.Memory_PreviousInput = top_level_algo_P.MinBDC_vinit;
    for (i = 0; i < 5; i++) {
      /* InitializeConditions for Delay: '<S9>/Delay2' */
      top_level_algo_DW.Delay2_DSTATE_m[i] =
        top_level_algo_P.Delay2_InitialCondition_c;

      /* InitializeConditions for Delay: '<S9>/Delay' */
      top_level_algo_DW.Delay_DSTATE_a[i] =
        top_level_algo_P.Delay_InitialCondition_d;
    }

    /* InitializeConditions for Memory: '<S89>/Memory' */
    top_level_algo_DW.Memory_PreviousInput_l = top_level_algo_P.MaxBDC_vinit;

    /* SystemInitialize for Chart: '<S9>/sample and hold1' */
    top_level_al_sampleandhold_Init(&displacement);

    /* SystemInitialize for Chart: '<S9>/sample and hold' */
    top_level_al_sampleandhold_Init(&displacement);

    /* SystemInitialize for Merge: '<S12>/Merge' */
    top_level_algo_B.Merge = top_level_algo_P.Merge_InitialOutput;

    /* SystemInitialize for Merge: '<S13>/Merge' */
    top_level_algo_B.Merge_b = top_level_algo_P.Merge_InitialOutput_i;

    /* SystemInitialize for Merge: '<S14>/Merge' */
    top_level_algo_B.Merge_d = top_level_algo_P.Merge_InitialOutput_j;

    /* Start for MATLABSystem: '<S48>/Analog to Digital Converter' */
    top_level_algo_DW.obj.isInitialized = 0;
    top_level_algo_DW.obj.matlabCodegenIsDeleted = false;
    top_level_algo_SystemCore_setup(&top_level_algo_DW.obj);
  }
}

/* Model terminate function */
void top_level_algo_terminate(void)
{
  uint16_T mode;

  /* Terminate for MATLABSystem: '<S48>/Analog to Digital Converter' */
  if (!top_level_algo_DW.obj.matlabCodegenIsDeleted) {
    top_level_algo_DW.obj.matlabCodegenIsDeleted = true;
    if ((top_level_algo_DW.obj.isInitialized == 1) &&
        top_level_algo_DW.obj.isSetupComplete) {
      mode = ADC_DMA_INTERRUPT_MODE;
      ADC_Handle_Deinit(top_level_algo_DW.obj.ADCHandle, mode, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S48>/Analog to Digital Converter' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
