/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo.c
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 1.146
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sat Mar  4 22:35:31 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "top_level_algo.h"
#include "top_level_algo_private.h"

/* Named constants for Chart: '<S8>/sample and hold' */
#define top_level_algo_IN_Holding      ((uint8_T)1U)
#define top_level_algo_IN_Init         ((uint8_T)2U)

/* Named constants for Chart: '<S2>/Chart' */
#define top_level_algo_IN_DETECTION    ((uint8_T)1U)
#define top_level_algo_IN_FOUR         ((uint8_T)2U)
#define top_level_algo_IN_INIT         ((uint8_T)3U)
#define top_level_algo_IN_ONE          ((uint8_T)4U)
#define top_level_algo_IN_POLLING      ((uint8_T)5U)
#define top_level_algo_IN_SHORTEN      ((uint8_T)6U)
#define top_level_algo_IN_THREE        ((uint8_T)7U)
#define top_level_algo_IN_TWO          ((uint8_T)8U)
#define top_level_algo_IN_Wait         ((uint8_T)9U)

/* Named constants for Chart: '<S6>/timer' */
#define top_level_algo_IN_Finished     ((uint8_T)1U)
#define top_level_algo_IN_Starting     ((uint8_T)2U)

/* Named constants for Chart: '<S49>/ClockLogic' */
#define top_level_algo_IN_HIGH         ((uint8_T)1U)
#define top_level_algo_IN_LOW          ((uint8_T)2U)
#define top_level_algo_IN_START        ((uint8_T)3U)
#define top_level_algo_IN_WAIT         ((uint8_T)4U)

/* Named constants for Chart: '<S49>/DataLogic' */
#define top_level_algo_IN_CHECK        ((uint8_T)1U)
#define top_level_algo_IN_LOAD         ((uint8_T)2U)
#define top_level_algo_IN_MASK         ((uint8_T)3U)
#define top_level_algo_IN_START_f      ((uint8_T)4U)
#define top_level_algo_IN_WAITING      ((uint8_T)5U)
#define top_level_algo_IN_Wait_j       ((uint8_T)6U)

/* Block signals (default storage) */
B_top_level_algo_T top_level_algo_B;

/* Block states (default storage) */
DW_top_level_algo_T top_level_algo_DW;

/* Real-time model */
static RT_MODEL_top_level_algo_T top_level_algo_M_;
RT_MODEL_top_level_algo_T *const top_level_algo_M = &top_level_algo_M_;

/* Forward declaration for local functions */
static void top_level_algo_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj);
int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

/*
 * System initialize for atomic system:
 *    '<S8>/sample and hold'
 *    '<S8>/sample and hold1'
 */
void top_level_al_sampleandhold_Init(real_T *rty_displacement)
{
  *rty_displacement = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S8>/sample and hold'
 *    '<S8>/sample and hold1'
 */
void top_level_algo_sampleandhold(real_T rtu_max, boolean_T rtu_read, real_T
  *rty_displacement, DW_sampleandhold_top_level_al_T *localDW)
{
  /* Chart: '<S8>/sample and hold' */
  if (localDW->is_active_c1_top_level_algo == 0U) {
    localDW->is_active_c1_top_level_algo = 1U;
    localDW->is_c1_top_level_algo = top_level_algo_IN_Init;
    *rty_displacement = 0.0;
  } else if (localDW->is_c1_top_level_algo == top_level_algo_IN_Holding) {
    if (rtu_read) {
      localDW->is_c1_top_level_algo = top_level_algo_IN_Holding;
      *rty_displacement = rtu_max;
    }

    /* case IN_Init: */
  } else if (rtu_read) {
    localDW->is_c1_top_level_algo = top_level_algo_IN_Holding;
    *rty_displacement = rtu_max;
  }

  /* End of Chart: '<S8>/sample and hold' */
}

/*
 * Output and update for action system:
 *    '<S50>/If Action Subsystem'
 *    '<S50>/If Action Subsystem1'
 *    '<S50>/If Action Subsystem2'
 *    '<S50>/If Action Subsystem3'
 *    '<S50>/If Action Subsystem4'
 *    '<S50>/If Action Subsystem5'
 *    '<S50>/If Action Subsystem6'
 *    '<S50>/If Action Subsystem7'
 *    '<S50>/If Action Subsystem8'
 *    '<S50>/If Action Subsystem10'
 *    ...
 */
void top_level_alg_IfActionSubsystem(uint8_T *rty_Out1,
  P_IfActionSubsystem_top_level_T *localP)
{
  /* SignalConversion generated from: '<S53>/Out1' incorporates:
   *  Constant: '<S53>/Constant'
   */
  *rty_Out1 = localP->Constant_Value;
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
  adcStructLoc.dmaPeripheralPtr = DMA2;
  adcStructLoc.peripheralPtr = ADC3;
  adcStructLoc.InjectedNoOfConversion = 0U;
  adcStructLoc.dmastream = 0U;
  adcStructLoc.InternalBufferSize = 1U;
  adcStructLoc.InternalBufferPtr = (void*)(&obj->ADCInternalBuffer[0]);
  module = ADC_DMA_INTERRUPT_MODE;
  triggerType = ADC_TRIGGER_AND_READ;
  noConv = LL_ADC_REG_SEQ_SCAN_DISABLE;
  adcStructLoc.RegularNoOfConversion = 1U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, module, 1, triggerType, noConv);
  obj->isSetupComplete = true;
}

/* Model step function */
void top_level_algo_step(void)
{
  /* local block i/o variables */
  real_T rtb_Merge;
  real_T rtb_Reset;
  real_T rtb_Reset_f;
  boolean_T rtb_IsPos;
  boolean_T rtb_IsNeg;
  boolean_T rtb_LogicalOperator3;
  boolean_T rtb_LogicalOperator7;
  boolean_T rtb_NOT2;
  boolean_T rtb_NOT;

  {
    int32_T Mean_AccVal_f;
    int32_T i;
    int32_T rtb_measure_period;
    int32_T str;
    uint32_T rtb_Add;
    uint16_T data;
    boolean_T Delay7_DSTATE_tmp;
    boolean_T rtb_AND;
    boolean_T rtb_NOT2_tmp;

    /* DiscretePulseGenerator: '<S9>/Pulse Generator' */
    top_level_algo_B.PulseGenerator = (top_level_algo_DW.clockTickCounter <
      top_level_algo_P.PulseGenerator_Duty) &&
      (top_level_algo_DW.clockTickCounter >= 0) ?
      top_level_algo_P.PulseGenerator_Amp : 0.0;
    if (top_level_algo_DW.clockTickCounter >=
        top_level_algo_P.PulseGenerator_Period - 1.0) {
      top_level_algo_DW.clockTickCounter = 0;
    } else {
      top_level_algo_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<S9>/Pulse Generator' */

    /* Chart: '<S49>/ClockLogic' */
    if (top_level_algo_DW.temporalCounter_i1_l < 15U) {
      top_level_algo_DW.temporalCounter_i1_l++;
    }

    if (top_level_algo_DW.is_active_c5_top_level_algo == 0U) {
      top_level_algo_DW.is_active_c5_top_level_algo = 1U;
      top_level_algo_DW.is_c5_top_level_algo = top_level_algo_IN_START;
      top_level_algo_DW.counter = 0.0;
      top_level_algo_B.CLK = 0.0;
    } else {
      switch (top_level_algo_DW.is_c5_top_level_algo) {
       case top_level_algo_IN_HIGH:
        if (top_level_algo_DW.temporalCounter_i1_l >= 10U) {
          top_level_algo_DW.is_c5_top_level_algo = top_level_algo_IN_LOW;
          top_level_algo_DW.temporalCounter_i1_l = 0U;
          top_level_algo_B.CLK = 0.0;
          top_level_algo_DW.counter++;
        }
        break;

       case top_level_algo_IN_LOW:
        if (top_level_algo_DW.counter == 36.0) {
          top_level_algo_DW.is_c5_top_level_algo = top_level_algo_IN_START;
          top_level_algo_DW.counter = 0.0;
          top_level_algo_B.CLK = 0.0;
        } else if (top_level_algo_DW.temporalCounter_i1_l >= 10U) {
          top_level_algo_DW.is_c5_top_level_algo = top_level_algo_IN_HIGH;
          top_level_algo_DW.temporalCounter_i1_l = 0U;
          top_level_algo_B.CLK = 1.0;
        }
        break;

       case top_level_algo_IN_START:
        if (top_level_algo_B.PulseGenerator == 1.0) {
          top_level_algo_DW.is_c5_top_level_algo = top_level_algo_IN_WAIT;
          top_level_algo_DW.temporalCounter_i1_l = 0U;
        } else {
          top_level_algo_DW.counter = 0.0;
          top_level_algo_B.CLK = 0.0;
        }
        break;

       default:
        /* case IN_WAIT: */
        if (top_level_algo_DW.temporalCounter_i1_l >= 10U) {
          top_level_algo_DW.is_c5_top_level_algo = top_level_algo_IN_HIGH;
          top_level_algo_DW.temporalCounter_i1_l = 0U;
          top_level_algo_B.CLK = 1.0;
        }
        break;
      }
    }

    /* End of Chart: '<S49>/ClockLogic' */

    /* S-Function (sfix_udelay): '<S6>/Tapped Delay1' */
    memcpy(&top_level_algo_B.TappedDelay[0], &top_level_algo_DW.TappedDelay1_X[0],
           20U * sizeof(real_T));

    /* S-Function (sdspstatfcns): '<S6>/Mean1' */
    top_level_algo_B.Mean1_AccVal = top_level_algo_B.TappedDelay[0];
    str = 1;
    for (i = 18; i >= 0; i--) {
      top_level_algo_B.Mean1_AccVal += top_level_algo_B.TappedDelay[str];
      str++;
    }

    /* Chart: '<S6>/timer' incorporates:
     *  S-Function (sdspstatfcns): '<S6>/Mean1'
     */
    if (top_level_algo_DW.temporalCounter_i1 < 2047U) {
      top_level_algo_DW.temporalCounter_i1++;
    }

    if (top_level_algo_DW.is_active_c3_top_level_algo == 0U) {
      top_level_algo_DW.is_active_c3_top_level_algo = 1U;
      top_level_algo_DW.is_c3_top_level_algo = top_level_algo_IN_Starting;
      top_level_algo_DW.temporalCounter_i1 = 0U;
      rtb_measure_period = 0;
    } else if (top_level_algo_DW.is_c3_top_level_algo == 1) {
      rtb_measure_period = 1;
    } else {
      /* case IN_Starting: */
      rtb_measure_period = 0;
      if (top_level_algo_DW.temporalCounter_i1 >= 2000U) {
        top_level_algo_DW.is_c3_top_level_algo = top_level_algo_IN_Finished;
        top_level_algo_B.baseline = top_level_algo_B.Mean1_AccVal / 20.0;
        rtb_measure_period = 1;
      }
    }

    /* End of Chart: '<S6>/timer' */

    /* S-Function (sdspstatfcns): '<S6>/Mean' incorporates:
     *  S-Function (sfix_udelay): '<S6>/Tapped Delay'
     */
    Mean_AccVal_f = top_level_algo_DW.TappedDelay_X_f[0];
    str = 1;
    for (i = 18; i >= 0; i--) {
      Mean_AccVal_f += top_level_algo_DW.TappedDelay_X_f[str];
      str++;
    }

    /* S-Function (sdspstatfcns): '<S5>/Mean' incorporates:
     *  S-Function (sfix_udelay): '<S5>/Tapped Delay'
     */
    top_level_algo_B.Mean_AccVal = top_level_algo_DW.TappedDelay_X[0];
    str = 1;
    for (i = 98; i >= 0; i--) {
      top_level_algo_B.Mean_AccVal += top_level_algo_DW.TappedDelay_X[str];
      str++;
    }

    /* Clock: '<S2>/Clock1' */
    top_level_algo_B.Mean1_AccVal = top_level_algo_M->Timing.t[0];

    /* Product: '<S6>/Product' incorporates:
     *  Constant: '<S6>/Constant'
     *  Constant: '<S6>/Constant1'
     *  Product: '<S6>/Divide'
     *  S-Function (sdspstatfcns): '<S6>/Mean'
     */
    top_level_algo_B.Product = (real_T)div_nde_s32_floor(Mean_AccVal_f, 20) /
      top_level_algo_P.Constant1_Value * top_level_algo_P.Vdd;

    /* Switch: '<S6>/Switch' */
    if (rtb_measure_period > top_level_algo_P.Switch_Threshold) {
      top_level_algo_B.TmpMLSysMemLayoutBufferAtDi = top_level_algo_B.baseline;
    } else {
      top_level_algo_B.TmpMLSysMemLayoutBufferAtDi = top_level_algo_B.Product;
    }

    /* End of Switch: '<S6>/Switch' */

    /* Gain: '<S6>/Radius (mm)' incorporates:
     *  Gain: '<S6>/Gear Down'
     *  Gain: '<S6>/rad  per volt'
     *  Sum: '<S6>/Subtract'
     */
    rtb_Merge = 6.2831853071795862 / top_level_algo_P.Vdd *
      (top_level_algo_B.TmpMLSysMemLayoutBufferAtDi - top_level_algo_B.Product) *
      (1.0 / top_level_algo_P.gear_ratio) * top_level_algo_P.Radiusmm_Gain;

    /* If: '<S21>/If' */
    if (rtb_Merge < 0.0) {
      /* Outputs for IfAction SubSystem: '<S21>/If Action Subsystem' incorporates:
       *  ActionPort: '<S23>/Action Port'
       */
      /* Gain: '<S6>/Radius (mm)' incorporates:
       *  Constant: '<S21>/Constant'
       *  Inport: '<S23>/In1'
       *  Merge: '<S21>/Merge'
       */
      rtb_Merge = top_level_algo_P.Constant_Value;

      /* End of Outputs for SubSystem: '<S21>/If Action Subsystem' */
    }

    /* End of If: '<S21>/If' */

    /* Sum: '<S5>/First Diff' incorporates:
     *  Delay: '<S5>/Delay'
     */
    top_level_algo_B.TmpMLSysMemLayoutBufferAtDi = rtb_Merge -
      top_level_algo_DW.Delay_DSTATE;

    /* Sum: '<S5>/Second Diff' incorporates:
     *  Delay: '<S5>/Delay'
     *  Delay: '<S5>/Delay1'
     */
    top_level_algo_B.u = top_level_algo_DW.Delay_DSTATE -
      top_level_algo_DW.Delay1_DSTATE[0];

    /* Sum: '<S5>/Third Diff' incorporates:
     *  Delay: '<S5>/Delay1'
     *  Delay: '<S5>/Delay2'
     */
    top_level_algo_B.u_m = top_level_algo_DW.Delay1_DSTATE[0] -
      top_level_algo_DW.Delay2_DSTATE[0];

    /* Sum: '<S5>/Fourth Diff' incorporates:
     *  Delay: '<S5>/Delay2'
     *  Delay: '<S5>/Delay3'
     */
    top_level_algo_B.u_c = top_level_algo_DW.Delay2_DSTATE[0] -
      top_level_algo_DW.Delay3_DSTATE[0];

    /* Sum: '<S5>/Fifth Diff' incorporates:
     *  Delay: '<S5>/Delay3'
     *  Delay: '<S5>/Delay4'
     */
    top_level_algo_B.u_k = top_level_algo_DW.Delay3_DSTATE[0] -
      top_level_algo_DW.Delay4_DSTATE[0];

    /* Sum: '<S5>/5to30 Diff' incorporates:
     *  Delay: '<S5>/Delay4'
     *  Delay: '<S5>/Delay5'
     */
    top_level_algo_B.u_cx = top_level_algo_DW.Delay4_DSTATE[0] -
      top_level_algo_DW.Delay5_DSTATE[0];

    /* Signum: '<S5>/Sign' */
    if (top_level_algo_B.TmpMLSysMemLayoutBufferAtDi < 0.0) {
      top_level_algo_B.TmpMLSysMemLayoutBufferAtDi = -1.0;
    } else if (top_level_algo_B.TmpMLSysMemLayoutBufferAtDi > 0.0) {
      top_level_algo_B.TmpMLSysMemLayoutBufferAtDi = 1.0;
    } else if (top_level_algo_B.TmpMLSysMemLayoutBufferAtDi == 0.0) {
      top_level_algo_B.TmpMLSysMemLayoutBufferAtDi = 0.0;
    } else {
      top_level_algo_B.TmpMLSysMemLayoutBufferAtDi = (rtNaN);
    }

    /* End of Signum: '<S5>/Sign' */

    /* Signum: '<S5>/Sign1' */
    if (top_level_algo_B.u < 0.0) {
      top_level_algo_B.u = -1.0;
    } else if (top_level_algo_B.u > 0.0) {
      top_level_algo_B.u = 1.0;
    } else if (top_level_algo_B.u == 0.0) {
      top_level_algo_B.u = 0.0;
    } else {
      top_level_algo_B.u = (rtNaN);
    }

    /* End of Signum: '<S5>/Sign1' */

    /* Signum: '<S5>/Sign2' */
    if (top_level_algo_B.u_m < 0.0) {
      top_level_algo_B.u_m = -1.0;
    } else if (top_level_algo_B.u_m > 0.0) {
      top_level_algo_B.u_m = 1.0;
    } else if (top_level_algo_B.u_m == 0.0) {
      top_level_algo_B.u_m = 0.0;
    } else {
      top_level_algo_B.u_m = (rtNaN);
    }

    /* End of Signum: '<S5>/Sign2' */

    /* Signum: '<S5>/Sign3' */
    if (top_level_algo_B.u_c < 0.0) {
      top_level_algo_B.u_c = -1.0;
    } else if (top_level_algo_B.u_c > 0.0) {
      top_level_algo_B.u_c = 1.0;
    } else if (top_level_algo_B.u_c == 0.0) {
      top_level_algo_B.u_c = 0.0;
    } else {
      top_level_algo_B.u_c = (rtNaN);
    }

    /* End of Signum: '<S5>/Sign3' */

    /* Signum: '<S5>/Sign4' */
    if (top_level_algo_B.u_k < 0.0) {
      top_level_algo_B.u_k = -1.0;
    } else if (top_level_algo_B.u_k > 0.0) {
      top_level_algo_B.u_k = 1.0;
    } else if (top_level_algo_B.u_k == 0.0) {
      top_level_algo_B.u_k = 0.0;
    } else {
      top_level_algo_B.u_k = (rtNaN);
    }

    /* End of Signum: '<S5>/Sign4' */

    /* Signum: '<S5>/Sign5' */
    if (top_level_algo_B.u_cx < 0.0) {
      top_level_algo_B.u_cx = -1.0;
    } else if (top_level_algo_B.u_cx > 0.0) {
      top_level_algo_B.u_cx = 1.0;
    } else if (top_level_algo_B.u_cx == 0.0) {
      top_level_algo_B.u_cx = 0.0;
    } else {
      top_level_algo_B.u_cx = (rtNaN);
    }

    /* End of Signum: '<S5>/Sign5' */

    /* Sum: '<S5>/Add' incorporates:
     *  Gain: '<S5>/Gain'
     *  Gain: '<S5>/Gain1'
     */
    top_level_algo_B.TmpMLSysMemLayoutBufferAtDi =
      ((((top_level_algo_P.Gain_Gain *
          top_level_algo_B.TmpMLSysMemLayoutBufferAtDi +
          top_level_algo_P.Gain1_Gain * top_level_algo_B.u) +
         top_level_algo_B.u_m) + top_level_algo_B.u_c) + top_level_algo_B.u_k) +
      top_level_algo_B.u_cx;

    /* Gain: '<S5>/Compression  Sensitivity' incorporates:
     *  S-Function (sdspstatfcns): '<S5>/Mean'
     */
    top_level_algo_B.Mean_AccVal = top_level_algo_B.Mean_AccVal / 100.0 *
      top_level_algo_P.CompressionSensitivity_Gain;

    /* Logic: '<S5>/AND' incorporates:
     *  Constant: '<S18>/Constant'
     *  Constant: '<S20>/Constant'
     *  RelationalOperator: '<S18>/Compare'
     *  RelationalOperator: '<S20>/Compare'
     */
    rtb_IsPos = ((top_level_algo_B.TmpMLSysMemLayoutBufferAtDi >=
                  top_level_algo_P.Positive_const) &&
                 (top_level_algo_B.Mean_AccVal >=
                  top_level_algo_P.Longrangemotionup_const));

    /* Logic: '<S5>/AND1' incorporates:
     *  Constant: '<S17>/Constant'
     *  Constant: '<S19>/Constant'
     *  RelationalOperator: '<S17>/Compare'
     *  RelationalOperator: '<S19>/Compare'
     */
    rtb_IsNeg = ((top_level_algo_B.TmpMLSysMemLayoutBufferAtDi <=
                  top_level_algo_P.Negative_const) &&
                 (top_level_algo_B.Mean_AccVal <=
                  top_level_algo_P.Longrangemotiondown_const));

    /* Logic: '<S8>/Logical Operator' incorporates:
     *  Logic: '<S5>/Zero'
     *  Logic: '<S8>/OR1'
     */
    Delay7_DSTATE_tmp = !rtb_IsNeg;

    /* Logic: '<S8>/Logical Operator1' incorporates:
     *  Delay: '<S8>/Delay7'
     *  Delay: '<S8>/Delay8'
     *  Logic: '<S8>/Logical Operator'
     *  Logic: '<S8>/Logical Operator2'
     */
    top_level_algo_DW.Delay7_DSTATE = (Delay7_DSTATE_tmp &&
      (top_level_algo_DW.Delay8_DSTATE[0] || top_level_algo_DW.Delay7_DSTATE));

    /* Logic: '<S8>/Logical Operator3' incorporates:
     *  Delay: '<S8>/Delay7'
     *  Logic: '<S8>/NOT4'
     */
    rtb_LogicalOperator3 = (rtb_IsPos && (!top_level_algo_DW.Delay7_DSTATE));

    /* Logic: '<S8>/AND' incorporates:
     *  Delay: '<S8>/Delay6'
     *  Logic: '<S8>/NOT3'
     */
    rtb_AND = (rtb_LogicalOperator3 && (!top_level_algo_DW.Delay6_DSTATE[0]));

    /* Chart: '<S2>/Chart' */
    if (top_level_algo_DW.is_active_c4_top_level_algo == 0U) {
      top_level_algo_DW.is_active_c4_top_level_algo = 1U;
      top_level_algo_DW.is_c4_top_level_algo = top_level_algo_IN_INIT;
      top_level_algo_DW.comp = 0.0;
      top_level_algo_B.rate = 0.0;
      top_level_algo_DW.zero = 0.0;
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
          top_level_algo_DW.fourth = top_level_algo_B.Mean1_AccVal;
        } else if (top_level_algo_DW.first == 0.0) {
          top_level_algo_DW.is_c4_top_level_algo = top_level_algo_IN_ONE;
          top_level_algo_DW.first = top_level_algo_B.Mean1_AccVal;
        } else if ((top_level_algo_DW.first != 0.0) && (top_level_algo_DW.second
                    == 0.0)) {
          top_level_algo_DW.is_c4_top_level_algo = top_level_algo_IN_TWO;
          top_level_algo_DW.second = top_level_algo_B.Mean1_AccVal;
        } else if ((top_level_algo_DW.first != 0.0) && (top_level_algo_DW.second
                    != 0.0) && (top_level_algo_DW.third == 0.0)) {
          top_level_algo_DW.is_c4_top_level_algo = top_level_algo_IN_THREE;
          top_level_algo_DW.third = top_level_algo_B.Mean1_AccVal;
        }
        break;

       case top_level_algo_IN_FOUR:
        if (!rtb_AND) {
          top_level_algo_DW.is_c4_top_level_algo = top_level_algo_IN_POLLING;
        }
        break;

       case top_level_algo_IN_INIT:
        if (rtb_AND) {
          top_level_algo_DW.is_c4_top_level_algo = top_level_algo_IN_Wait;
          top_level_algo_DW.zero = top_level_algo_B.Mean1_AccVal;
          top_level_algo_DW.last_count = top_level_algo_B.Mean1_AccVal;
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
          top_level_algo_DW.last_count = top_level_algo_B.Mean1_AccVal;
          top_level_algo_B.rate = top_level_algo_DW.comp * 60.0 /
            (top_level_algo_B.Mean1_AccVal - top_level_algo_DW.zero);
        } else if (top_level_algo_B.Mean1_AccVal - top_level_algo_DW.last_count >
                   4.0) {
          top_level_algo_DW.is_c4_top_level_algo = top_level_algo_IN_INIT;
          top_level_algo_DW.comp = 0.0;
          top_level_algo_B.rate = 0.0;
          top_level_algo_DW.zero = 0.0;
          top_level_algo_DW.first = 0.0;
          top_level_algo_DW.second = 0.0;
          top_level_algo_DW.third = 0.0;
          top_level_algo_DW.fourth = 0.0;
        } else if (rtb_AND && (top_level_algo_DW.comp > 3.0)) {
          top_level_algo_DW.is_c4_top_level_algo = top_level_algo_IN_SHORTEN;
          top_level_algo_B.rate = top_level_algo_DW.comp * 60.0 /
            (top_level_algo_B.Mean1_AccVal - top_level_algo_DW.zero);
          top_level_algo_DW.last_count = top_level_algo_B.Mean1_AccVal;
          top_level_algo_DW.zero = top_level_algo_DW.first;
          top_level_algo_DW.first = top_level_algo_DW.second;
          top_level_algo_DW.second = top_level_algo_DW.third;
          top_level_algo_DW.third = top_level_algo_DW.fourth;
          top_level_algo_DW.fourth = top_level_algo_B.Mean1_AccVal;
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

    /* End of Chart: '<S2>/Chart' */

    /* Math: '<S48>/Mod' incorporates:
     *  Constant: '<S48>/Constant1'
     */
    top_level_algo_B.TmpMLSysMemLayoutBufferAtDi = rt_modd_snf
      (top_level_algo_B.rate, top_level_algo_P.Constant1_Value_g);

    /* SwitchCase: '<S50>/Switch Case' incorporates:
     *  MATLABSystem: '<S48>/Divide by Constant and Round'
     *  Sum: '<S48>/Subtract'
     */
    top_level_algo_B.Mean1_AccVal = floor((top_level_algo_B.rate -
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
      /* Outputs for IfAction SubSystem: '<S50>/If Action Subsystem' incorporates:
       *  ActionPort: '<S53>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem_o);

      /* End of Outputs for SubSystem: '<S50>/If Action Subsystem' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S50>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S54>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem1_f);

      /* End of Outputs for SubSystem: '<S50>/If Action Subsystem1' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S50>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S56>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem2);

      /* End of Outputs for SubSystem: '<S50>/If Action Subsystem2' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S50>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S57>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem3);

      /* End of Outputs for SubSystem: '<S50>/If Action Subsystem3' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S50>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S58>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem4);

      /* End of Outputs for SubSystem: '<S50>/If Action Subsystem4' */
      break;

     case 5:
      /* Outputs for IfAction SubSystem: '<S50>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S59>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem5);

      /* End of Outputs for SubSystem: '<S50>/If Action Subsystem5' */
      break;

     case 6:
      /* Outputs for IfAction SubSystem: '<S50>/If Action Subsystem6' incorporates:
       *  ActionPort: '<S60>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem6);

      /* End of Outputs for SubSystem: '<S50>/If Action Subsystem6' */
      break;

     case 7:
      /* Outputs for IfAction SubSystem: '<S50>/If Action Subsystem7' incorporates:
       *  ActionPort: '<S61>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem7);

      /* End of Outputs for SubSystem: '<S50>/If Action Subsystem7' */
      break;

     case 8:
      /* Outputs for IfAction SubSystem: '<S50>/If Action Subsystem8' incorporates:
       *  ActionPort: '<S62>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem8);

      /* End of Outputs for SubSystem: '<S50>/If Action Subsystem8' */
      break;

     case 9:
      /* Outputs for IfAction SubSystem: '<S50>/If Action Subsystem10' incorporates:
       *  ActionPort: '<S55>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem10);

      /* End of Outputs for SubSystem: '<S50>/If Action Subsystem10' */
      break;
    }

    /* End of SwitchCase: '<S50>/Switch Case' */

    /* Math: '<S48>/Mod1' incorporates:
     *  Constant: '<S48>/Constant2'
     */
    top_level_algo_B.Mean_AccVal = rt_modd_snf
      (top_level_algo_B.TmpMLSysMemLayoutBufferAtDi,
       top_level_algo_P.Constant2_Value);

    /* SwitchCase: '<S51>/Switch Case' incorporates:
     *  MATLABSystem: '<S48>/Divide by Constant and Round1'
     *  Sum: '<S48>/Subtract1'
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
      /* Outputs for IfAction SubSystem: '<S51>/If Action Subsystem' incorporates:
       *  ActionPort: '<S63>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
        &top_level_algo_P.IfActionSubsystem_l);

      /* End of Outputs for SubSystem: '<S51>/If Action Subsystem' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S51>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S64>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
        &top_level_algo_P.IfActionSubsystem1_d);

      /* End of Outputs for SubSystem: '<S51>/If Action Subsystem1' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S51>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S66>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
        &top_level_algo_P.IfActionSubsystem2_d);

      /* End of Outputs for SubSystem: '<S51>/If Action Subsystem2' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S51>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S67>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
        &top_level_algo_P.IfActionSubsystem3_p);

      /* End of Outputs for SubSystem: '<S51>/If Action Subsystem3' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S51>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S68>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
        &top_level_algo_P.IfActionSubsystem4_d);

      /* End of Outputs for SubSystem: '<S51>/If Action Subsystem4' */
      break;

     case 5:
      /* Outputs for IfAction SubSystem: '<S51>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S69>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
        &top_level_algo_P.IfActionSubsystem5_h);

      /* End of Outputs for SubSystem: '<S51>/If Action Subsystem5' */
      break;

     case 6:
      /* Outputs for IfAction SubSystem: '<S51>/If Action Subsystem6' incorporates:
       *  ActionPort: '<S70>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
        &top_level_algo_P.IfActionSubsystem6_b);

      /* End of Outputs for SubSystem: '<S51>/If Action Subsystem6' */
      break;

     case 7:
      /* Outputs for IfAction SubSystem: '<S51>/If Action Subsystem7' incorporates:
       *  ActionPort: '<S71>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
        &top_level_algo_P.IfActionSubsystem7_h);

      /* End of Outputs for SubSystem: '<S51>/If Action Subsystem7' */
      break;

     case 8:
      /* Outputs for IfAction SubSystem: '<S51>/If Action Subsystem8' incorporates:
       *  ActionPort: '<S72>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
        &top_level_algo_P.IfActionSubsystem8_p);

      /* End of Outputs for SubSystem: '<S51>/If Action Subsystem8' */
      break;

     case 9:
      /* Outputs for IfAction SubSystem: '<S51>/If Action Subsystem10' incorporates:
       *  ActionPort: '<S65>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
        &top_level_algo_P.IfActionSubsystem10_l);

      /* End of Outputs for SubSystem: '<S51>/If Action Subsystem10' */
      break;
    }

    /* End of SwitchCase: '<S51>/Switch Case' */

    /* SwitchCase: '<S52>/Switch Case' */
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
      /* Outputs for IfAction SubSystem: '<S52>/If Action Subsystem' incorporates:
       *  ActionPort: '<S73>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
        &top_level_algo_P.IfActionSubsystem_j);

      /* End of Outputs for SubSystem: '<S52>/If Action Subsystem' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S52>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S74>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
        &top_level_algo_P.IfActionSubsystem1_a);

      /* End of Outputs for SubSystem: '<S52>/If Action Subsystem1' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S52>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S76>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
        &top_level_algo_P.IfActionSubsystem2_i);

      /* End of Outputs for SubSystem: '<S52>/If Action Subsystem2' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S52>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S77>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
        &top_level_algo_P.IfActionSubsystem3_c);

      /* End of Outputs for SubSystem: '<S52>/If Action Subsystem3' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S52>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S78>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
        &top_level_algo_P.IfActionSubsystem4_db);

      /* End of Outputs for SubSystem: '<S52>/If Action Subsystem4' */
      break;

     case 5:
      /* Outputs for IfAction SubSystem: '<S52>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S79>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
        &top_level_algo_P.IfActionSubsystem5_hh);

      /* End of Outputs for SubSystem: '<S52>/If Action Subsystem5' */
      break;

     case 6:
      /* Outputs for IfAction SubSystem: '<S52>/If Action Subsystem6' incorporates:
       *  ActionPort: '<S80>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
        &top_level_algo_P.IfActionSubsystem6_c);

      /* End of Outputs for SubSystem: '<S52>/If Action Subsystem6' */
      break;

     case 7:
      /* Outputs for IfAction SubSystem: '<S52>/If Action Subsystem7' incorporates:
       *  ActionPort: '<S81>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
        &top_level_algo_P.IfActionSubsystem7_n);

      /* End of Outputs for SubSystem: '<S52>/If Action Subsystem7' */
      break;

     case 8:
      /* Outputs for IfAction SubSystem: '<S52>/If Action Subsystem8' incorporates:
       *  ActionPort: '<S82>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
        &top_level_algo_P.IfActionSubsystem8_f);

      /* End of Outputs for SubSystem: '<S52>/If Action Subsystem8' */
      break;

     case 9:
      /* Outputs for IfAction SubSystem: '<S52>/If Action Subsystem10' incorporates:
       *  ActionPort: '<S75>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
        &top_level_algo_P.IfActionSubsystem10_m);

      /* End of Outputs for SubSystem: '<S52>/If Action Subsystem10' */
      break;
    }

    /* End of SwitchCase: '<S52>/Switch Case' */

    /* Sum: '<S48>/Add' incorporates:
     *  ArithShift: '<S48>/Shift Arithmetic1'
     *  ArithShift: '<S48>/Shift Arithmetic2'
     *  DataTypeConversion: '<S48>/Cast To Double'
     *  DataTypeConversion: '<S48>/Cast To Double1'
     *  DataTypeConversion: '<S48>/Cast To Double2'
     */
    rtb_Add = (((uint32_T)top_level_algo_B.Merge_b << 8) +
               top_level_algo_B.Merge) + ((uint32_T)top_level_algo_B.Merge_d <<
      16);

    /* Chart: '<S49>/DataLogic' */
    if (top_level_algo_DW.temporalCounter_i1_d < 31U) {
      top_level_algo_DW.temporalCounter_i1_d++;
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
          top_level_algo_DW.temporalCounter_i1_d = 0U;
        } else if (top_level_algo_DW.temporalCounter_i1_d >= 10U) {
          top_level_algo_DW.is_c6_top_level_algo = top_level_algo_IN_MASK;
          top_level_algo_DW.temporalCounter_i1_d = 0U;
          top_level_algo_B.data = top_level_algo_DW.Holder & 1U;
        }
        break;

       case top_level_algo_IN_LOAD:
        if (top_level_algo_B.PulseGenerator == 1.0) {
          top_level_algo_DW.is_c6_top_level_algo = top_level_algo_IN_Wait_j;
          top_level_algo_DW.temporalCounter_i1_d = 0U;
        }
        break;

       case top_level_algo_IN_MASK:
        if (top_level_algo_DW.temporalCounter_i1_d >= 10U) {
          top_level_algo_DW.is_c6_top_level_algo = top_level_algo_IN_CHECK;
          top_level_algo_DW.temporalCounter_i1_d = 0U;
          top_level_algo_DW.Holder >>= 1;
        }
        break;

       case top_level_algo_IN_START_f:
        if (top_level_algo_DW.temporalCounter_i1_d >= 20U) {
          top_level_algo_DW.is_c6_top_level_algo = top_level_algo_IN_MASK;
          top_level_algo_DW.temporalCounter_i1_d = 0U;
          top_level_algo_B.data = top_level_algo_DW.Holder & 1U;
        }
        break;

       case top_level_algo_IN_WAITING:
        if (top_level_algo_DW.temporalCounter_i1_d >= 10U) {
          top_level_algo_DW.is_c6_top_level_algo = top_level_algo_IN_LOAD;
          top_level_algo_B.data = 0U;
          top_level_algo_DW.Holder = rtb_Add;
        }
        break;

       default:
        /* case IN_Wait: */
        if (top_level_algo_DW.temporalCounter_i1_d >= 5U) {
          top_level_algo_DW.is_c6_top_level_algo = top_level_algo_IN_START_f;
          top_level_algo_DW.temporalCounter_i1_d = 0U;
          top_level_algo_B.data = 1U;
        }
        break;
      }
    }

    /* End of Chart: '<S49>/DataLogic' */

    /* MATLABSystem: '<S16>/Digital Port Write' */
    top_level_algo_B.portNameLoc = GPIOE;
    if (top_level_algo_B.data != 0U) {
      i = 512;
    } else {
      i = 0;
    }

    LL_GPIO_SetOutputPin(top_level_algo_B.portNameLoc, (uint32_T)i);
    LL_GPIO_ResetOutputPin(top_level_algo_B.portNameLoc, ~(uint32_T)i & 512U);

    /* End of MATLABSystem: '<S16>/Digital Port Write' */

    /* Switch: '<S45>/Reset' incorporates:
     *  Delay: '<S8>/Delay2'
     *  Memory: '<S45>/Memory'
     *  MinMax: '<S40>/MinMax'
     */
    if (top_level_algo_DW.Delay2_DSTATE_m[0U]) {
      /* Switch: '<S45>/Reset' incorporates:
       *  Constant: '<S45>/Initial Condition'
       */
      rtb_Reset = top_level_algo_P.MinBDC_vinit;
    } else if ((rtb_Merge <= top_level_algo_DW.Memory_PreviousInput) || rtIsNaN
               (top_level_algo_DW.Memory_PreviousInput)) {
      /* MinMax: '<S40>/MinMax' incorporates:
       *  Switch: '<S45>/Reset'
       */
      rtb_Reset = rtb_Merge;
    } else {
      /* Switch: '<S45>/Reset' incorporates:
       *  Memory: '<S45>/Memory'
       *  MinMax: '<S40>/MinMax'
       */
      rtb_Reset = top_level_algo_DW.Memory_PreviousInput;
    }

    /* End of Switch: '<S45>/Reset' */

    /* Chart: '<S8>/sample and hold1' */
    top_level_algo_sampleandhold(rtb_Reset, rtb_AND,
      &top_level_algo_B.PulseGenerator, &top_level_algo_DW.sf_sampleandhold1);

    /* Logic: '<S8>/Logical Operator4' incorporates:
     *  Logic: '<S5>/Zero'
     *  Logic: '<S8>/OR'
     */
    rtb_AND = !rtb_IsPos;

    /* Logic: '<S8>/Logical Operator5' incorporates:
     *  Delay: '<S8>/Delay1'
     *  Delay: '<S8>/Delay4'
     *  Logic: '<S8>/Logical Operator4'
     *  Logic: '<S8>/Logical Operator6'
     */
    top_level_algo_DW.Delay1_DSTATE_m = (rtb_AND &&
      (top_level_algo_DW.Delay4_DSTATE_a[0] || top_level_algo_DW.Delay1_DSTATE_m));

    /* Logic: '<S8>/Logical Operator7' incorporates:
     *  Delay: '<S8>/Delay1'
     *  Logic: '<S8>/NOT5'
     */
    rtb_LogicalOperator7 = (rtb_IsNeg && (!top_level_algo_DW.Delay1_DSTATE_m));

    /* Switch: '<S44>/Reset' incorporates:
     *  Delay: '<S8>/Delay'
     *  Memory: '<S44>/Memory'
     *  MinMax: '<S39>/MinMax'
     */
    if (top_level_algo_DW.Delay_DSTATE_a[0U]) {
      /* Switch: '<S44>/Reset' incorporates:
       *  Constant: '<S44>/Initial Condition'
       */
      rtb_Reset_f = top_level_algo_P.MaxBDC_vinit;
    } else if ((rtb_Merge >= top_level_algo_DW.Memory_PreviousInput_l) ||
               rtIsNaN(top_level_algo_DW.Memory_PreviousInput_l)) {
      /* MinMax: '<S39>/MinMax' incorporates:
       *  Switch: '<S44>/Reset'
       */
      rtb_Reset_f = rtb_Merge;
    } else {
      /* Switch: '<S44>/Reset' incorporates:
       *  Memory: '<S44>/Memory'
       *  MinMax: '<S39>/MinMax'
       */
      rtb_Reset_f = top_level_algo_DW.Memory_PreviousInput_l;
    }

    /* End of Switch: '<S44>/Reset' */

    /* Chart: '<S8>/sample and hold' incorporates:
     *  Delay: '<S8>/Delay3'
     *  Logic: '<S8>/AND1'
     *  Logic: '<S8>/NOT1'
     */
    top_level_algo_sampleandhold(rtb_Reset_f, rtb_LogicalOperator7 &&
      (!top_level_algo_DW.Delay3_DSTATE_m[0]), &top_level_algo_B.PulseGenerator,
      &top_level_algo_DW.sf_sampleandhold);

    /* Logic: '<S8>/OR1' incorporates:
     *  Logic: '<S5>/Zero'
     *  Logic: '<S8>/OR'
     */
    rtb_NOT2_tmp = ((!rtb_AND) || (!Delay7_DSTATE_tmp));

    /* Logic: '<S8>/NOT2' incorporates:
     *  Logic: '<S8>/OR1'
     */
    rtb_NOT2 = (rtb_NOT2_tmp && Delay7_DSTATE_tmp);

    /* Logic: '<S8>/NOT' incorporates:
     *  Logic: '<S8>/OR'
     */
    rtb_NOT = (rtb_AND && rtb_NOT2_tmp);

    /* Sum: '<S5>/30 Diff' incorporates:
     *  Delay: '<S5>/Delay5'
     */
    top_level_algo_B.u0Diff = rtb_Merge - top_level_algo_DW.Delay5_DSTATE[0];

    /* MATLABSystem: '<S34>/Digital Port Write' incorporates:
     *  Constant: '<S25>/Constant'
     *  RelationalOperator: '<S25>/Compare'
     */
    top_level_algo_B.portNameLoc = GPIOE;
    if (rtb_Merge > top_level_algo_P.CompareToConstant_const) {
      i = 16;
    } else {
      i = 0;
    }

    LL_GPIO_SetOutputPin(top_level_algo_B.portNameLoc, (uint32_T)i);
    LL_GPIO_ResetOutputPin(top_level_algo_B.portNameLoc, ~(uint32_T)i & 16U);

    /* End of MATLABSystem: '<S34>/Digital Port Write' */

    /* MATLABSystem: '<S36>/Digital Port Write' incorporates:
     *  Constant: '<S27>/Constant'
     *  RelationalOperator: '<S27>/Compare'
     */
    top_level_algo_B.portNameLoc = GPIOE;
    if (rtb_Merge > top_level_algo_P.CompareToConstant2_const) {
      i = 8;
    } else {
      i = 0;
    }

    LL_GPIO_SetOutputPin(top_level_algo_B.portNameLoc, (uint32_T)i);
    LL_GPIO_ResetOutputPin(top_level_algo_B.portNameLoc, ~(uint32_T)i & 8U);

    /* End of MATLABSystem: '<S36>/Digital Port Write' */

    /* MATLABSystem: '<S38>/Digital Port Write' incorporates:
     *  Constant: '<S29>/Constant'
     *  RelationalOperator: '<S29>/Compare'
     */
    top_level_algo_B.portNameLoc = GPIOE;
    if (rtb_Merge > top_level_algo_P.CompareToConstant4_const) {
      i = 4;
    } else {
      i = 0;
    }

    LL_GPIO_SetOutputPin(top_level_algo_B.portNameLoc, (uint32_T)i);
    LL_GPIO_ResetOutputPin(top_level_algo_B.portNameLoc, ~(uint32_T)i & 4U);

    /* End of MATLABSystem: '<S38>/Digital Port Write' */

    /* MATLABSystem: '<S14>/Digital Port Write' */
    top_level_algo_B.portNameLoc = GPIOE;
    if (top_level_algo_B.CLK != 0.0) {
      i = 256;
    } else {
      i = 0;
    }

    LL_GPIO_SetOutputPin(top_level_algo_B.portNameLoc, (uint32_T)i);
    LL_GPIO_ResetOutputPin(top_level_algo_B.portNameLoc, ~(uint32_T)i & 256U);

    /* End of MATLABSystem: '<S14>/Digital Port Write' */

    /* MATLABSystem: '<S11>/Analog to Digital Converter' */
    top_level_algo_B.triggerType = ADC_TRIGGER_AND_READ;
    regularReadADCDMA(top_level_algo_DW.obj_c.ADCHandle,
                      top_level_algo_B.triggerType, &data);

    /* DataTypeConversion: '<Root>/Cast To Double' incorporates:
     *  MATLABSystem: '<S11>/Analog to Digital Converter'
     */
    top_level_algo_B.CastToDouble = data;
  }

  {
    int_T i;
    for (i = 0; i < 19; i++) {
      /* Update for S-Function (sfix_udelay): '<S6>/Tapped Delay1' */
      top_level_algo_DW.TappedDelay1_X[i] = top_level_algo_DW.TappedDelay1_X[i +
        1];

      /* Update for S-Function (sfix_udelay): '<S6>/Tapped Delay' */
      top_level_algo_DW.TappedDelay_X_f[i] = top_level_algo_DW.TappedDelay_X_f[i
        + 1];
    }

    /* Update for S-Function (sfix_udelay): '<S6>/Tapped Delay1' */
    top_level_algo_DW.TappedDelay1_X[19] = top_level_algo_B.Product;

    /* Update for S-Function (sfix_udelay): '<S6>/Tapped Delay' */
    top_level_algo_DW.TappedDelay_X_f[19] = top_level_algo_B.CastToDouble;

    /* Update for S-Function (sfix_udelay): '<S5>/Tapped Delay' */
    for (i = 0; i < 99; i++) {
      top_level_algo_DW.TappedDelay_X[i] = top_level_algo_DW.TappedDelay_X[i + 1];
    }

    top_level_algo_DW.TappedDelay_X[99] = top_level_algo_B.u0Diff;

    /* End of Update for S-Function (sfix_udelay): '<S5>/Tapped Delay' */

    /* Update for Delay: '<S5>/Delay' */
    top_level_algo_DW.Delay_DSTATE = rtb_Merge;

    /* Update for Delay: '<S5>/Delay1' */
    top_level_algo_DW.Delay1_DSTATE[0] = top_level_algo_DW.Delay1_DSTATE[1];
    top_level_algo_DW.Delay1_DSTATE[1] = rtb_Merge;

    /* Update for Delay: '<S5>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE[0] = top_level_algo_DW.Delay2_DSTATE[1];
    top_level_algo_DW.Delay2_DSTATE[1] = top_level_algo_DW.Delay2_DSTATE[2];
    top_level_algo_DW.Delay2_DSTATE[2] = rtb_Merge;

    /* Update for Delay: '<S5>/Delay3' */
    top_level_algo_DW.Delay3_DSTATE[0] = top_level_algo_DW.Delay3_DSTATE[1];
    top_level_algo_DW.Delay3_DSTATE[1] = top_level_algo_DW.Delay3_DSTATE[2];
    top_level_algo_DW.Delay3_DSTATE[2] = top_level_algo_DW.Delay3_DSTATE[3];
    top_level_algo_DW.Delay3_DSTATE[3] = rtb_Merge;

    /* Update for Delay: '<S5>/Delay4' */
    top_level_algo_DW.Delay4_DSTATE[0] = top_level_algo_DW.Delay4_DSTATE[1];
    top_level_algo_DW.Delay4_DSTATE[1] = top_level_algo_DW.Delay4_DSTATE[2];
    top_level_algo_DW.Delay4_DSTATE[2] = top_level_algo_DW.Delay4_DSTATE[3];
    top_level_algo_DW.Delay4_DSTATE[3] = top_level_algo_DW.Delay4_DSTATE[4];
    top_level_algo_DW.Delay4_DSTATE[4] = rtb_Merge;

    /* Update for Delay: '<S5>/Delay5' */
    for (i = 0; i < 49; i++) {
      top_level_algo_DW.Delay5_DSTATE[i] = top_level_algo_DW.Delay5_DSTATE[i + 1];
    }

    top_level_algo_DW.Delay5_DSTATE[49] = rtb_Merge;

    /* End of Update for Delay: '<S5>/Delay5' */

    /* Update for Delay: '<S8>/Delay8' */
    top_level_algo_DW.Delay8_DSTATE[0] = top_level_algo_DW.Delay8_DSTATE[1];
    top_level_algo_DW.Delay8_DSTATE[1] = rtb_IsPos;

    /* Update for Delay: '<S8>/Delay6' */
    top_level_algo_DW.Delay6_DSTATE[0] = top_level_algo_DW.Delay6_DSTATE[1];
    top_level_algo_DW.Delay6_DSTATE[1] = rtb_LogicalOperator3;

    /* Update for Memory: '<S45>/Memory' */
    top_level_algo_DW.Memory_PreviousInput = rtb_Reset;

    /* Update for Delay: '<S8>/Delay4' */
    top_level_algo_DW.Delay4_DSTATE_a[0] = top_level_algo_DW.Delay4_DSTATE_a[1];
    top_level_algo_DW.Delay4_DSTATE_a[1] = rtb_IsNeg;

    /* Update for Delay: '<S8>/Delay3' */
    top_level_algo_DW.Delay3_DSTATE_m[0] = top_level_algo_DW.Delay3_DSTATE_m[1];
    top_level_algo_DW.Delay3_DSTATE_m[1] = rtb_LogicalOperator7;

    /* Update for Delay: '<S8>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE_m[0] = top_level_algo_DW.Delay2_DSTATE_m[1];

    /* Update for Delay: '<S8>/Delay' */
    top_level_algo_DW.Delay_DSTATE_a[0] = top_level_algo_DW.Delay_DSTATE_a[1];

    /* Update for Delay: '<S8>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE_m[1] = top_level_algo_DW.Delay2_DSTATE_m[2];

    /* Update for Delay: '<S8>/Delay' */
    top_level_algo_DW.Delay_DSTATE_a[1] = top_level_algo_DW.Delay_DSTATE_a[2];

    /* Update for Delay: '<S8>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE_m[2] = top_level_algo_DW.Delay2_DSTATE_m[3];

    /* Update for Delay: '<S8>/Delay' */
    top_level_algo_DW.Delay_DSTATE_a[2] = top_level_algo_DW.Delay_DSTATE_a[3];

    /* Update for Delay: '<S8>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE_m[3] = top_level_algo_DW.Delay2_DSTATE_m[4];

    /* Update for Delay: '<S8>/Delay' */
    top_level_algo_DW.Delay_DSTATE_a[3] = top_level_algo_DW.Delay_DSTATE_a[4];

    /* Update for Delay: '<S8>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE_m[4] = rtb_NOT2;

    /* Update for Delay: '<S8>/Delay' */
    top_level_algo_DW.Delay_DSTATE_a[4] = rtb_NOT;

    /* Update for Memory: '<S44>/Memory' */
    top_level_algo_DW.Memory_PreviousInput_l = rtb_Reset_f;
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
      /* InitializeConditions for S-Function (sfix_udelay): '<S6>/Tapped Delay1' */
      top_level_algo_DW.TappedDelay1_X[i] = top_level_algo_P.TappedDelay1_vinit;

      /* InitializeConditions for S-Function (sfix_udelay): '<S6>/Tapped Delay' */
      top_level_algo_DW.TappedDelay_X_f[i] =
        top_level_algo_P.TappedDelay_vinit_l;
    }

    /* InitializeConditions for S-Function (sfix_udelay): '<S5>/Tapped Delay' */
    for (i = 0; i < 100; i++) {
      top_level_algo_DW.TappedDelay_X[i] = top_level_algo_P.TappedDelay_vinit;
    }

    /* End of InitializeConditions for S-Function (sfix_udelay): '<S5>/Tapped Delay' */

    /* InitializeConditions for Delay: '<S5>/Delay' */
    top_level_algo_DW.Delay_DSTATE = top_level_algo_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S5>/Delay1' */
    top_level_algo_DW.Delay1_DSTATE[0] =
      top_level_algo_P.Delay1_InitialCondition;
    top_level_algo_DW.Delay1_DSTATE[1] =
      top_level_algo_P.Delay1_InitialCondition;

    /* InitializeConditions for Delay: '<S5>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE[0] =
      top_level_algo_P.Delay2_InitialCondition;
    top_level_algo_DW.Delay2_DSTATE[1] =
      top_level_algo_P.Delay2_InitialCondition;
    top_level_algo_DW.Delay2_DSTATE[2] =
      top_level_algo_P.Delay2_InitialCondition;

    /* InitializeConditions for Delay: '<S5>/Delay3' */
    top_level_algo_DW.Delay3_DSTATE[0] =
      top_level_algo_P.Delay3_InitialCondition;
    top_level_algo_DW.Delay3_DSTATE[1] =
      top_level_algo_P.Delay3_InitialCondition;
    top_level_algo_DW.Delay3_DSTATE[2] =
      top_level_algo_P.Delay3_InitialCondition;
    top_level_algo_DW.Delay3_DSTATE[3] =
      top_level_algo_P.Delay3_InitialCondition;

    /* InitializeConditions for Delay: '<S5>/Delay4' */
    for (i = 0; i < 5; i++) {
      top_level_algo_DW.Delay4_DSTATE[i] =
        top_level_algo_P.Delay4_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S5>/Delay4' */

    /* InitializeConditions for Delay: '<S5>/Delay5' */
    for (i = 0; i < 50; i++) {
      top_level_algo_DW.Delay5_DSTATE[i] =
        top_level_algo_P.Delay5_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S5>/Delay5' */

    /* InitializeConditions for Delay: '<S8>/Delay7' */
    top_level_algo_DW.Delay7_DSTATE = top_level_algo_P.Delay7_InitialCondition;

    /* InitializeConditions for Delay: '<S8>/Delay8' */
    top_level_algo_DW.Delay8_DSTATE[0] =
      top_level_algo_P.Delay8_InitialCondition;

    /* InitializeConditions for Delay: '<S8>/Delay6' */
    top_level_algo_DW.Delay6_DSTATE[0] =
      top_level_algo_P.Delay6_InitialCondition;

    /* InitializeConditions for Delay: '<S8>/Delay8' */
    top_level_algo_DW.Delay8_DSTATE[1] =
      top_level_algo_P.Delay8_InitialCondition;

    /* InitializeConditions for Delay: '<S8>/Delay6' */
    top_level_algo_DW.Delay6_DSTATE[1] =
      top_level_algo_P.Delay6_InitialCondition;

    /* InitializeConditions for Memory: '<S45>/Memory' */
    top_level_algo_DW.Memory_PreviousInput = top_level_algo_P.MinBDC_vinit;

    /* InitializeConditions for Delay: '<S8>/Delay1' */
    top_level_algo_DW.Delay1_DSTATE_m =
      top_level_algo_P.Delay1_InitialCondition_d;

    /* InitializeConditions for Delay: '<S8>/Delay4' */
    top_level_algo_DW.Delay4_DSTATE_a[0] =
      top_level_algo_P.Delay4_InitialCondition_f;

    /* InitializeConditions for Delay: '<S8>/Delay3' */
    top_level_algo_DW.Delay3_DSTATE_m[0] =
      top_level_algo_P.Delay3_InitialCondition_k;

    /* InitializeConditions for Delay: '<S8>/Delay4' */
    top_level_algo_DW.Delay4_DSTATE_a[1] =
      top_level_algo_P.Delay4_InitialCondition_f;

    /* InitializeConditions for Delay: '<S8>/Delay3' */
    top_level_algo_DW.Delay3_DSTATE_m[1] =
      top_level_algo_P.Delay3_InitialCondition_k;
    for (i = 0; i < 5; i++) {
      /* InitializeConditions for Delay: '<S8>/Delay2' */
      top_level_algo_DW.Delay2_DSTATE_m[i] =
        top_level_algo_P.Delay2_InitialCondition_c;

      /* InitializeConditions for Delay: '<S8>/Delay' */
      top_level_algo_DW.Delay_DSTATE_a[i] =
        top_level_algo_P.Delay_InitialCondition_d;
    }

    /* InitializeConditions for Memory: '<S44>/Memory' */
    top_level_algo_DW.Memory_PreviousInput_l = top_level_algo_P.MaxBDC_vinit;

    /* SystemInitialize for Merge: '<S50>/Merge' */
    top_level_algo_B.Merge = top_level_algo_P.Merge_InitialOutput;

    /* SystemInitialize for Merge: '<S51>/Merge' */
    top_level_algo_B.Merge_b = top_level_algo_P.Merge_InitialOutput_i;

    /* SystemInitialize for Merge: '<S52>/Merge' */
    top_level_algo_B.Merge_d = top_level_algo_P.Merge_InitialOutput_j;

    /* SystemInitialize for Chart: '<S8>/sample and hold1' */
    top_level_al_sampleandhold_Init(&displacement);

    /* SystemInitialize for Chart: '<S8>/sample and hold' */
    top_level_al_sampleandhold_Init(&displacement);

    /* Start for MATLABSystem: '<S11>/Analog to Digital Converter' */
    top_level_algo_DW.obj_c.isInitialized = 0;
    top_level_algo_DW.obj_c.matlabCodegenIsDeleted = false;
    top_level_algo_SystemCore_setup(&top_level_algo_DW.obj_c);
  }
}

/* Model terminate function */
void top_level_algo_terminate(void)
{
  uint16_T mode;

  /* Terminate for MATLABSystem: '<S11>/Analog to Digital Converter' */
  if (!top_level_algo_DW.obj_c.matlabCodegenIsDeleted) {
    top_level_algo_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((top_level_algo_DW.obj_c.isInitialized == 1) &&
        top_level_algo_DW.obj_c.isSetupComplete) {
      mode = ADC_DMA_INTERRUPT_MODE;
      ADC_Handle_Deinit(top_level_algo_DW.obj_c.ADCHandle, mode, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S11>/Analog to Digital Converter' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
