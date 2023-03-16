/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo.c
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 3.11
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Mar 14 22:48:37 2023
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
#include <math.h>
#include "rt_nonfinite.h"
#include "stm_adc_ll.h"
#include <float.h>

/* Named constants for Chart: '<S8>/sample and hold' */
#define top_level_algo_IN_Holding      ((uint8_T)1U)
#define top_level_algo_IN_Init         ((uint8_T)2U)

/* Named constants for Chart: '<S2>/Chart1' */
#define top_level_algo_IN_Counting     ((uint8_T)1U)
#define top_level_algo_IN_First        ((uint8_T)2U)
#define top_level_algo_IN_INIT         ((uint8_T)3U)

/* Named constants for Chart: '<S6>/timer' */
#define top_level_algo_IN_Finished     ((uint8_T)1U)
#define top_level_algo_IN_Starting     ((uint8_T)2U)

/* Named constants for Chart: '<S9>/DataLogic' */
#define top_level_algo_IN_CHECK        ((uint8_T)1U)
#define top_level_algo_IN_HOLD         ((uint8_T)2U)
#define top_level_algo_IN_LOAD         ((uint8_T)3U)
#define top_level_algo_IN_MASK         ((uint8_T)4U)
#define top_level_algo_IN_START        ((uint8_T)5U)
#define top_level_algo_IN_WAITING      ((uint8_T)6U)
#define top_level_algo_IN_Wait         ((uint8_T)7U)
#define top_level_algo_clk_period      (8.0)

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
  if ((top_level_algo_M->Timing.TaskCounters.TID[2]) > 3) {/* Sample time: [0.004s, 0.0s] */
    top_level_algo_M->Timing.TaskCounters.TID[2] = 0;
  }

  (top_level_algo_M->Timing.TaskCounters.TID[3])++;
  if ((top_level_algo_M->Timing.TaskCounters.TID[3]) > 4) {/* Sample time: [0.005s, 0.0s] */
    top_level_algo_M->Timing.TaskCounters.TID[3] = 0;
  }
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
 *    '<S57>/If Action Subsystem'
 *    '<S57>/If Action Subsystem1'
 *    '<S57>/If Action Subsystem2'
 *    '<S57>/If Action Subsystem3'
 *    '<S57>/If Action Subsystem4'
 *    '<S57>/If Action Subsystem5'
 *    '<S57>/If Action Subsystem6'
 *    '<S57>/If Action Subsystem7'
 *    '<S57>/If Action Subsystem8'
 *    '<S57>/If Action Subsystem10'
 *    ...
 */
void top_level_alg_IfActionSubsystem(uint8_T *rty_Out1,
  P_IfActionSubsystem_top_level_T *localP)
{
  /* SignalConversion generated from: '<S60>/Out1' incorporates:
   *  Constant: '<S60>/Constant'
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
  real_T rtb_PulseGenerator;
  boolean_T rtb_LogicalOperator;
  real_T rtb_Gain1;
  real_T rtb_Reset;
  boolean_T rtb_IsPos;
  boolean_T rtb_IsNeg;
  boolean_T rtb_LogicalOperator7;
  boolean_T rtb_LogicalOperator3;
  boolean_T rtb_NOT2;
  boolean_T rtb_NOT_c;

  {
    int32_T Mean_AccVal_f;
    int32_T pinWriteLoc;
    int32_T str;
    uint32_T rtb_Add;
    uint16_T data;
    boolean_T rtb_IsZero_tmp;
    boolean_T rtb_NOT1_j;
    boolean_T rtb_NOT2_tmp;
    if (top_level_algo_M->Timing.TaskCounters.TID[2] == 0) {
      /* Sum: '<S56>/Sum' incorporates:
       *  Constant: '<S56>/Constant'
       *  UnitDelay: '<S56>/Unit Delay'
       */
      top_level_algo_B.Sum = top_level_algo_P.Constant_Value_k -
        top_level_algo_DW.UnitDelay_DSTATE;
    }

    /* Logic: '<S9>/Logical Operator' incorporates:
     *  Delay: '<S9>/Delay'
     */
    rtb_LogicalOperator = !(top_level_algo_DW.Delay_DSTATE[0] != 0.0);

    /* Logic: '<S9>/Logical Operator1' incorporates:
     *  Delay: '<S9>/Delay7'
     *  Delay: '<S9>/Delay8'
     *  Logic: '<S9>/Logical Operator2'
     *  Logic: '<S9>/NOT'
     */
    top_level_algo_DW.Delay7_DSTATE = (rtb_LogicalOperator &&
      ((!top_level_algo_DW.Delay8_DSTATE[0]) || top_level_algo_DW.Delay7_DSTATE));

    /* Logic: '<S9>/NOT1' incorporates:
     *  Delay: '<S9>/Delay7'
     */
    rtb_NOT1_j = !top_level_algo_DW.Delay7_DSTATE;

    /* MATLABSystem: '<S14>/Digital Port Write' */
    top_level_algo_B.portNameLoc = GPIOE;

    /* Switch: '<S9>/Switch' incorporates:
     *  Constant: '<S9>/Constant'
     */
    if (rtb_NOT1_j) {
      top_level_algo_B.MajorityVoterSlope = top_level_algo_B.Sum;
    } else {
      top_level_algo_B.MajorityVoterSlope = top_level_algo_P.Constant_Value;
    }

    /* MATLABSystem: '<S14>/Digital Port Write' incorporates:
     *  Switch: '<S9>/Switch'
     */
    if (top_level_algo_B.MajorityVoterSlope != 0.0) {
      pinWriteLoc = 256;
    } else {
      pinWriteLoc = 0;
    }

    LL_GPIO_SetOutputPin(top_level_algo_B.portNameLoc, (uint32_T)pinWriteLoc);
    LL_GPIO_ResetOutputPin(top_level_algo_B.portNameLoc, ~(uint32_T)pinWriteLoc
      & 256U);

    /* Switch: '<S56>/Switch' incorporates:
     *  Constant: '<S90>/Constant'
     *  DataTypeConversion: '<S56>/Cast To Single'
     *  RelationalOperator: '<S90>/Compare'
     */
    if ((real32_T)rtb_NOT1_j >= top_level_algo_P.CompareToConstant_const_f) {
      /* Switch: '<S56>/Switch' */
      top_level_algo_B.Switch = top_level_algo_B.Sum;
    } else {
      /* Switch: '<S56>/Switch' incorporates:
       *  Constant: '<S56>/Constant1'
       */
      top_level_algo_B.Switch = top_level_algo_P.Constant1_Value;
    }

    /* End of Switch: '<S56>/Switch' */
    if (top_level_algo_M->Timing.TaskCounters.TID[3] == 0) {
      /* S-Function (sdspstatfcns): '<S6>/Mean1' incorporates:
       *  S-Function (sfix_udelay): '<S6>/Tapped Delay1'
       */
      top_level_algo_B.Mean1_AccVal = top_level_algo_DW.TappedDelay1_X[0];
      str = 1;
      for (pinWriteLoc = 18; pinWriteLoc >= 0; pinWriteLoc--) {
        top_level_algo_B.Mean1_AccVal += top_level_algo_DW.TappedDelay1_X[str];
        str++;
      }

      /* S-Function (sdspstatfcns): '<S6>/Mean' incorporates:
       *  S-Function (sfix_udelay): '<S6>/Tapped Delay'
       */
      Mean_AccVal_f = top_level_algo_DW.TappedDelay_X_f[0];
      str = 1;
      for (pinWriteLoc = 8; pinWriteLoc >= 0; pinWriteLoc--) {
        Mean_AccVal_f += top_level_algo_DW.TappedDelay_X_f[str];
        str++;
      }

      /* S-Function (sfix_udelay): '<S5>/Tapped Delay' */
      memcpy(&top_level_algo_B.TappedDelay[0], &top_level_algo_DW.TappedDelay_X
             [0], 10U * sizeof(real_T));

      /* S-Function (sdspstatfcns): '<S5>/Mean' */
      top_level_algo_B.Mean_AccVal = top_level_algo_B.TappedDelay[0];
      str = 1;
      for (pinWriteLoc = 8; pinWriteLoc >= 0; pinWriteLoc--) {
        top_level_algo_B.Mean_AccVal += top_level_algo_B.TappedDelay[str];
        str++;
      }

      /* Gain: '<S5>/Compression  Sensitivity' incorporates:
       *  S-Function (sdspstatfcns): '<S5>/Mean'
       */
      top_level_algo_B.Mean_AccVal = top_level_algo_B.Mean_AccVal / 10.0 *
        top_level_algo_P.CompressionSensitivity_Gain;

      /* Product: '<S6>/Product' incorporates:
       *  Constant: '<S6>/Constant'
       *  Constant: '<S6>/Constant1'
       *  Product: '<S6>/Divide'
       *  S-Function (sdspstatfcns): '<S6>/Mean'
       */
      top_level_algo_B.Product = (real_T)div_nde_s32_floor(Mean_AccVal_f, 10) /
        top_level_algo_P.Constant1_Value_d * top_level_algo_P.Vdd;

      /* Chart: '<S6>/timer' incorporates:
       *  S-Function (sdspstatfcns): '<S6>/Mean1'
       */
      if (top_level_algo_DW.temporalCounter_i1_c < 511U) {
        top_level_algo_DW.temporalCounter_i1_c++;
      }

      if (top_level_algo_DW.is_active_c3_top_level_algo == 0U) {
        top_level_algo_DW.is_active_c3_top_level_algo = 1U;
        top_level_algo_DW.is_c3_top_level_algo = top_level_algo_IN_Starting;
        top_level_algo_DW.temporalCounter_i1_c = 0U;
        pinWriteLoc = 0;
      } else if (top_level_algo_DW.is_c3_top_level_algo ==
                 top_level_algo_IN_Finished) {
        pinWriteLoc = 1;
      } else {
        /* case IN_Starting: */
        pinWriteLoc = 0;
        if (top_level_algo_DW.temporalCounter_i1_c >= 400U) {
          top_level_algo_DW.is_c3_top_level_algo = top_level_algo_IN_Finished;
          top_level_algo_B.baseline = top_level_algo_B.Mean1_AccVal / 20.0;
          pinWriteLoc = 1;
        }
      }

      /* End of Chart: '<S6>/timer' */

      /* Switch: '<S6>/Switch' */
      if (pinWriteLoc > top_level_algo_P.Switch_Threshold) {
        top_level_algo_B.MajorityVoterSlope = top_level_algo_B.baseline;
      } else {
        top_level_algo_B.MajorityVoterSlope = top_level_algo_B.Product;
      }

      /* Gain: '<S6>/Radius (mm)' incorporates:
       *  Gain: '<S6>/Gear Down'
       *  Gain: '<S6>/rad  per volt'
       *  Sum: '<S6>/Subtract'
       *  Switch: '<S6>/Switch'
       */
      top_level_algo_B.Mean1_AccVal = 6.2831853071795862 / top_level_algo_P.Vdd *
        (top_level_algo_B.MajorityVoterSlope - top_level_algo_B.Product) * (1.0 /
        top_level_algo_P.gear_ratio) * top_level_algo_P.Radiusmm_Gain;

      /* If: '<S21>/If' incorporates:
       *  Constant: '<S21>/Constant'
       *  Gain: '<Root>/Gain1'
       */
      if (top_level_algo_B.Mean1_AccVal < 0.0) {
        top_level_algo_B.Mean1_AccVal = top_level_algo_P.Constant_Value_a;
      }

      rtb_Gain1 = top_level_algo_P.Gain1_Gain * top_level_algo_B.Mean1_AccVal;

      /* End of If: '<S21>/If' */

      /* Delay: '<S5>/Delay5' */
      top_level_algo_B.Mean1_AccVal = top_level_algo_DW.Delay5_DSTATE[0];

      /* Sum: '<S5>/First Diff' incorporates:
       *  Delay: '<S5>/Delay'
       */
      top_level_algo_B.MajorityVoterSlope = rtb_Gain1 -
        top_level_algo_DW.Delay_DSTATE_d;

      /* Sum: '<S5>/Second Diff' incorporates:
       *  Delay: '<S5>/Delay'
       *  Delay: '<S5>/Delay1'
       */
      top_level_algo_B.u = top_level_algo_DW.Delay_DSTATE_d -
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
      top_level_algo_B.Mod1 = top_level_algo_DW.Delay4_DSTATE[0] -
        top_level_algo_DW.Delay5_DSTATE[0];

      /* Signum: '<S5>/Sign' */
      if (rtIsNaN(top_level_algo_B.MajorityVoterSlope)) {
        top_level_algo_B.MajorityVoterSlope = (rtNaN);
      } else if (top_level_algo_B.MajorityVoterSlope < 0.0) {
        top_level_algo_B.MajorityVoterSlope = -1.0;
      } else {
        top_level_algo_B.MajorityVoterSlope =
          (top_level_algo_B.MajorityVoterSlope > 0.0);
      }

      /* Signum: '<S5>/Sign1' */
      if (rtIsNaN(top_level_algo_B.u)) {
        top_level_algo_B.u = (rtNaN);
      } else if (top_level_algo_B.u < 0.0) {
        top_level_algo_B.u = -1.0;
      } else {
        top_level_algo_B.u = (top_level_algo_B.u > 0.0);
      }

      /* Signum: '<S5>/Sign2' */
      if (rtIsNaN(top_level_algo_B.u_m)) {
        top_level_algo_B.u_m = (rtNaN);
      } else if (top_level_algo_B.u_m < 0.0) {
        top_level_algo_B.u_m = -1.0;
      } else {
        top_level_algo_B.u_m = (top_level_algo_B.u_m > 0.0);
      }

      /* Signum: '<S5>/Sign3' */
      if (rtIsNaN(top_level_algo_B.u_c)) {
        top_level_algo_B.u_c = (rtNaN);
      } else if (top_level_algo_B.u_c < 0.0) {
        top_level_algo_B.u_c = -1.0;
      } else {
        top_level_algo_B.u_c = (top_level_algo_B.u_c > 0.0);
      }

      /* Signum: '<S5>/Sign4' */
      if (rtIsNaN(top_level_algo_B.u_k)) {
        top_level_algo_B.u_k = (rtNaN);
      } else if (top_level_algo_B.u_k < 0.0) {
        top_level_algo_B.u_k = -1.0;
      } else {
        top_level_algo_B.u_k = (top_level_algo_B.u_k > 0.0);
      }

      /* Signum: '<S5>/Sign5' */
      if (rtIsNaN(top_level_algo_B.Mod1)) {
        top_level_algo_B.Mod1 = (rtNaN);
      } else if (top_level_algo_B.Mod1 < 0.0) {
        top_level_algo_B.Mod1 = -1.0;
      } else {
        top_level_algo_B.Mod1 = (top_level_algo_B.Mod1 > 0.0);
      }

      /* Sum: '<S5>/Add' incorporates:
       *  Gain: '<S5>/Gain'
       *  Gain: '<S5>/Gain1'
       *  Signum: '<S5>/Sign'
       *  Signum: '<S5>/Sign1'
       *  Signum: '<S5>/Sign2'
       *  Signum: '<S5>/Sign3'
       *  Signum: '<S5>/Sign4'
       *  Signum: '<S5>/Sign5'
       */
      top_level_algo_B.MajorityVoterSlope = ((((top_level_algo_P.Gain_Gain *
        top_level_algo_B.MajorityVoterSlope + top_level_algo_P.Gain1_Gain_g *
        top_level_algo_B.u) + top_level_algo_B.u_m) + top_level_algo_B.u_c) +
        top_level_algo_B.u_k) + top_level_algo_B.Mod1;

      /* Logic: '<S5>/AND' incorporates:
       *  Constant: '<S18>/Constant'
       *  Constant: '<S20>/Constant'
       *  RelationalOperator: '<S18>/Compare'
       *  RelationalOperator: '<S20>/Compare'
       */
      rtb_IsPos = ((top_level_algo_B.MajorityVoterSlope >=
                    top_level_algo_P.Positive_const) &&
                   (top_level_algo_B.Mean_AccVal >=
                    top_level_algo_P.Longrangemotionup_const));

      /* Logic: '<S8>/Logical Operator5' incorporates:
       *  Delay: '<S8>/Delay1'
       *  Delay: '<S8>/Delay4'
       *  Logic: '<S8>/Logical Operator4'
       *  Logic: '<S8>/Logical Operator6'
       */
      top_level_algo_DW.Delay1_DSTATE_m = ((!rtb_IsPos) &&
        (top_level_algo_DW.Delay4_DSTATE_a[0] ||
         top_level_algo_DW.Delay1_DSTATE_m));

      /* Logic: '<S5>/AND1' incorporates:
       *  Constant: '<S17>/Constant'
       *  Constant: '<S19>/Constant'
       *  RelationalOperator: '<S17>/Compare'
       *  RelationalOperator: '<S19>/Compare'
       */
      rtb_IsNeg = ((top_level_algo_B.MajorityVoterSlope <=
                    top_level_algo_P.Negative_const) &&
                   (top_level_algo_B.Mean_AccVal <=
                    top_level_algo_P.Longrangemotiondown_const));

      /* Logic: '<S8>/Logical Operator7' incorporates:
       *  Delay: '<S8>/Delay1'
       *  Logic: '<S8>/NOT5'
       */
      rtb_LogicalOperator7 = (rtb_IsNeg && (!top_level_algo_DW.Delay1_DSTATE_m));

      /* Switch: '<S50>/Reset' incorporates:
       *  Delay: '<S8>/Delay'
       *  Memory: '<S50>/Memory'
       *  MinMax: '<S45>/MinMax'
       */
      if (top_level_algo_DW.Delay_DSTATE_a[0U]) {
        /* Switch: '<S50>/Reset' incorporates:
         *  Constant: '<S50>/Initial Condition'
         */
        rtb_Reset = top_level_algo_P.MaxBDC_vinit;
      } else if ((rtb_Gain1 >= top_level_algo_DW.Memory_PreviousInput) ||
                 rtIsNaN(top_level_algo_DW.Memory_PreviousInput)) {
        /* MinMax: '<S45>/MinMax' incorporates:
         *  Switch: '<S50>/Reset'
         */
        rtb_Reset = rtb_Gain1;
      } else {
        /* Switch: '<S50>/Reset' incorporates:
         *  Memory: '<S50>/Memory'
         *  MinMax: '<S45>/MinMax'
         */
        rtb_Reset = top_level_algo_DW.Memory_PreviousInput;
      }

      /* End of Switch: '<S50>/Reset' */

      /* Chart: '<S8>/sample and hold' incorporates:
       *  Delay: '<S8>/Delay3'
       *  Logic: '<S8>/AND1'
       *  Logic: '<S8>/NOT1'
       */
      top_level_algo_sampleandhold(rtb_Reset, rtb_LogicalOperator7 &&
        (!top_level_algo_DW.Delay3_DSTATE_m[0]), &top_level_algo_B.Mean_AccVal,
        &top_level_algo_DW.sf_sampleandhold);

      /* Logic: '<S8>/Logical Operator1' incorporates:
       *  Delay: '<S8>/Delay7'
       *  Delay: '<S8>/Delay8'
       *  Logic: '<S8>/Logical Operator'
       *  Logic: '<S8>/Logical Operator2'
       */
      top_level_algo_DW.Delay7_DSTATE_l = ((!rtb_IsNeg) &&
        (top_level_algo_DW.Delay8_DSTATE_b[0] ||
         top_level_algo_DW.Delay7_DSTATE_l));

      /* Logic: '<S8>/Logical Operator3' incorporates:
       *  Delay: '<S8>/Delay7'
       *  Logic: '<S8>/NOT4'
       */
      rtb_LogicalOperator3 = (rtb_IsPos && (!top_level_algo_DW.Delay7_DSTATE_l));

      /* Logic: '<S8>/AND' incorporates:
       *  Delay: '<S8>/Delay6'
       *  Logic: '<S8>/NOT3'
       */
      top_level_algo_B.AND = (rtb_LogicalOperator3 &&
        (!top_level_algo_DW.Delay6_DSTATE[0]));
    }

    /* Clock: '<S2>/Clock1' */
    top_level_algo_B.Mean_AccVal = top_level_algo_M->Timing.t[0];

    /* Chart: '<S2>/Chart1' */
    if (top_level_algo_DW.temporalCounter_i1_o < 2047U) {
      top_level_algo_DW.temporalCounter_i1_o++;
    }

    if (top_level_algo_DW.is_active_c12_top_level_algo == 0U) {
      top_level_algo_DW.is_active_c12_top_level_algo = 1U;
      top_level_algo_DW.is_c12_top_level_algo = top_level_algo_IN_INIT;
      top_level_algo_DW.lastTs = 0.0;
      top_level_algo_B.paceDetect = 0.0;
    } else {
      switch (top_level_algo_DW.is_c12_top_level_algo) {
       case top_level_algo_IN_Counting:
        if ((top_level_algo_DW.temporalCounter_i1_o >= 10U) &&
            top_level_algo_B.AND) {
          top_level_algo_DW.is_c12_top_level_algo = top_level_algo_IN_Counting;
          top_level_algo_DW.temporalCounter_i1_o = 0U;
          top_level_algo_B.paceDetect = 60.0 / (top_level_algo_B.Mean_AccVal -
            top_level_algo_DW.lastTs);
          top_level_algo_DW.lastTs = top_level_algo_B.Mean_AccVal;
        } else if (top_level_algo_DW.temporalCounter_i1_o >= 2000U) {
          top_level_algo_DW.is_c12_top_level_algo = top_level_algo_IN_INIT;
          top_level_algo_DW.lastTs = 0.0;
          top_level_algo_B.paceDetect = 0.0;
        }
        break;

       case top_level_algo_IN_First:
        if ((top_level_algo_DW.temporalCounter_i1_o >= 50U) &&
            top_level_algo_B.AND) {
          top_level_algo_DW.is_c12_top_level_algo = top_level_algo_IN_Counting;
          top_level_algo_DW.temporalCounter_i1_o = 0U;
          top_level_algo_B.paceDetect = 60.0 / (top_level_algo_B.Mean_AccVal -
            top_level_algo_DW.lastTs);
          top_level_algo_DW.lastTs = top_level_algo_B.Mean_AccVal;
        }
        break;

       default:
        /* case IN_INIT: */
        if (top_level_algo_B.AND) {
          top_level_algo_DW.is_c12_top_level_algo = top_level_algo_IN_First;
          top_level_algo_DW.temporalCounter_i1_o = 0U;
          top_level_algo_DW.lastTs = top_level_algo_B.Mean_AccVal;
        }
        break;
      }
    }

    /* End of Chart: '<S2>/Chart1' */

    /* Math: '<S55>/Mod' incorporates:
     *  Constant: '<S55>/Constant1'
     */
    top_level_algo_B.Mean_AccVal = rt_modd_snf(top_level_algo_B.paceDetect,
      top_level_algo_P.Constant1_Value_j);

    /* SwitchCase: '<S57>/Switch Case' incorporates:
     *  MATLABSystem: '<S55>/Divide by Constant and Round'
     *  Sum: '<S55>/Subtract'
     */
    top_level_algo_B.MajorityVoterSlope = floor((top_level_algo_B.paceDetect -
      top_level_algo_B.Mean_AccVal) * 0.01);
    if (rtIsNaN(top_level_algo_B.MajorityVoterSlope) || rtIsInf
        (top_level_algo_B.MajorityVoterSlope)) {
      top_level_algo_B.MajorityVoterSlope = 0.0;
    } else {
      top_level_algo_B.MajorityVoterSlope = fmod
        (top_level_algo_B.MajorityVoterSlope, 4.294967296E+9);
    }

    switch (top_level_algo_B.MajorityVoterSlope < 0.0 ? -(int32_T)(uint32_T)
            -top_level_algo_B.MajorityVoterSlope : (int32_T)(uint32_T)
            top_level_algo_B.MajorityVoterSlope) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S57>/If Action Subsystem' incorporates:
       *  ActionPort: '<S60>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem_n);

      /* End of Outputs for SubSystem: '<S57>/If Action Subsystem' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S57>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S61>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem1_d);

      /* End of Outputs for SubSystem: '<S57>/If Action Subsystem1' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S57>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S63>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem2);

      /* End of Outputs for SubSystem: '<S57>/If Action Subsystem2' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S57>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S64>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem3);

      /* End of Outputs for SubSystem: '<S57>/If Action Subsystem3' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S57>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S65>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem4);

      /* End of Outputs for SubSystem: '<S57>/If Action Subsystem4' */
      break;

     case 5:
      /* Outputs for IfAction SubSystem: '<S57>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S66>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem5);

      /* End of Outputs for SubSystem: '<S57>/If Action Subsystem5' */
      break;

     case 6:
      /* Outputs for IfAction SubSystem: '<S57>/If Action Subsystem6' incorporates:
       *  ActionPort: '<S67>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem6);

      /* End of Outputs for SubSystem: '<S57>/If Action Subsystem6' */
      break;

     case 7:
      /* Outputs for IfAction SubSystem: '<S57>/If Action Subsystem7' incorporates:
       *  ActionPort: '<S68>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem7);

      /* End of Outputs for SubSystem: '<S57>/If Action Subsystem7' */
      break;

     case 8:
      /* Outputs for IfAction SubSystem: '<S57>/If Action Subsystem8' incorporates:
       *  ActionPort: '<S69>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem8);

      /* End of Outputs for SubSystem: '<S57>/If Action Subsystem8' */
      break;

     case 9:
      /* Outputs for IfAction SubSystem: '<S57>/If Action Subsystem10' incorporates:
       *  ActionPort: '<S62>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
        &top_level_algo_P.IfActionSubsystem10);

      /* End of Outputs for SubSystem: '<S57>/If Action Subsystem10' */
      break;
    }

    /* End of SwitchCase: '<S57>/Switch Case' */

    /* Math: '<S55>/Mod1' incorporates:
     *  Constant: '<S55>/Constant2'
     */
    top_level_algo_B.Mod1 = rt_modd_snf(top_level_algo_B.Mean_AccVal,
      top_level_algo_P.Constant2_Value);

    /* SwitchCase: '<S58>/Switch Case' incorporates:
     *  MATLABSystem: '<S55>/Divide by Constant and Round1'
     *  Sum: '<S55>/Subtract1'
     */
    top_level_algo_B.MajorityVoterSlope = floor((top_level_algo_B.Mean_AccVal -
      top_level_algo_B.Mod1) * 0.1);
    if (rtIsNaN(top_level_algo_B.MajorityVoterSlope) || rtIsInf
        (top_level_algo_B.MajorityVoterSlope)) {
      top_level_algo_B.MajorityVoterSlope = 0.0;
    } else {
      top_level_algo_B.MajorityVoterSlope = fmod
        (top_level_algo_B.MajorityVoterSlope, 4.294967296E+9);
    }

    switch (top_level_algo_B.MajorityVoterSlope < 0.0 ? -(int32_T)(uint32_T)
            -top_level_algo_B.MajorityVoterSlope : (int32_T)(uint32_T)
            top_level_algo_B.MajorityVoterSlope) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S58>/If Action Subsystem' incorporates:
       *  ActionPort: '<S70>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_a,
        &top_level_algo_P.IfActionSubsystem_i);

      /* End of Outputs for SubSystem: '<S58>/If Action Subsystem' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S58>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S71>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_a,
        &top_level_algo_P.IfActionSubsystem1_h);

      /* End of Outputs for SubSystem: '<S58>/If Action Subsystem1' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S58>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S73>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_a,
        &top_level_algo_P.IfActionSubsystem2_k);

      /* End of Outputs for SubSystem: '<S58>/If Action Subsystem2' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S58>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S74>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_a,
        &top_level_algo_P.IfActionSubsystem3_b);

      /* End of Outputs for SubSystem: '<S58>/If Action Subsystem3' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S58>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S75>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_a,
        &top_level_algo_P.IfActionSubsystem4_m);

      /* End of Outputs for SubSystem: '<S58>/If Action Subsystem4' */
      break;

     case 5:
      /* Outputs for IfAction SubSystem: '<S58>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S76>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_a,
        &top_level_algo_P.IfActionSubsystem5_o);

      /* End of Outputs for SubSystem: '<S58>/If Action Subsystem5' */
      break;

     case 6:
      /* Outputs for IfAction SubSystem: '<S58>/If Action Subsystem6' incorporates:
       *  ActionPort: '<S77>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_a,
        &top_level_algo_P.IfActionSubsystem6_n);

      /* End of Outputs for SubSystem: '<S58>/If Action Subsystem6' */
      break;

     case 7:
      /* Outputs for IfAction SubSystem: '<S58>/If Action Subsystem7' incorporates:
       *  ActionPort: '<S78>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_a,
        &top_level_algo_P.IfActionSubsystem7_h);

      /* End of Outputs for SubSystem: '<S58>/If Action Subsystem7' */
      break;

     case 8:
      /* Outputs for IfAction SubSystem: '<S58>/If Action Subsystem8' incorporates:
       *  ActionPort: '<S79>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_a,
        &top_level_algo_P.IfActionSubsystem8_n);

      /* End of Outputs for SubSystem: '<S58>/If Action Subsystem8' */
      break;

     case 9:
      /* Outputs for IfAction SubSystem: '<S58>/If Action Subsystem10' incorporates:
       *  ActionPort: '<S72>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_a,
        &top_level_algo_P.IfActionSubsystem10_i);

      /* End of Outputs for SubSystem: '<S58>/If Action Subsystem10' */
      break;
    }

    /* End of SwitchCase: '<S58>/Switch Case' */

    /* SwitchCase: '<S59>/Switch Case' */
    if (top_level_algo_B.Mod1 < 0.0) {
      top_level_algo_B.MajorityVoterSlope = ceil(top_level_algo_B.Mod1);
    } else {
      top_level_algo_B.MajorityVoterSlope = floor(top_level_algo_B.Mod1);
    }

    if (rtIsNaN(top_level_algo_B.MajorityVoterSlope) || rtIsInf
        (top_level_algo_B.MajorityVoterSlope)) {
      top_level_algo_B.MajorityVoterSlope = 0.0;
    } else {
      top_level_algo_B.MajorityVoterSlope = fmod
        (top_level_algo_B.MajorityVoterSlope, 4.294967296E+9);
    }

    switch (top_level_algo_B.MajorityVoterSlope < 0.0 ? -(int32_T)(uint32_T)
            -top_level_algo_B.MajorityVoterSlope : (int32_T)(uint32_T)
            top_level_algo_B.MajorityVoterSlope) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S59>/If Action Subsystem' incorporates:
       *  ActionPort: '<S80>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_e,
        &top_level_algo_P.IfActionSubsystem_a);

      /* End of Outputs for SubSystem: '<S59>/If Action Subsystem' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S59>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S81>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_e,
        &top_level_algo_P.IfActionSubsystem1_dx);

      /* End of Outputs for SubSystem: '<S59>/If Action Subsystem1' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S59>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S83>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_e,
        &top_level_algo_P.IfActionSubsystem2_o);

      /* End of Outputs for SubSystem: '<S59>/If Action Subsystem2' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S59>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S84>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_e,
        &top_level_algo_P.IfActionSubsystem3_a);

      /* End of Outputs for SubSystem: '<S59>/If Action Subsystem3' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S59>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S85>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_e,
        &top_level_algo_P.IfActionSubsystem4_b);

      /* End of Outputs for SubSystem: '<S59>/If Action Subsystem4' */
      break;

     case 5:
      /* Outputs for IfAction SubSystem: '<S59>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S86>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_e,
        &top_level_algo_P.IfActionSubsystem5_l);

      /* End of Outputs for SubSystem: '<S59>/If Action Subsystem5' */
      break;

     case 6:
      /* Outputs for IfAction SubSystem: '<S59>/If Action Subsystem6' incorporates:
       *  ActionPort: '<S87>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_e,
        &top_level_algo_P.IfActionSubsystem6_o);

      /* End of Outputs for SubSystem: '<S59>/If Action Subsystem6' */
      break;

     case 7:
      /* Outputs for IfAction SubSystem: '<S59>/If Action Subsystem7' incorporates:
       *  ActionPort: '<S88>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_e,
        &top_level_algo_P.IfActionSubsystem7_he);

      /* End of Outputs for SubSystem: '<S59>/If Action Subsystem7' */
      break;

     case 8:
      /* Outputs for IfAction SubSystem: '<S59>/If Action Subsystem8' incorporates:
       *  ActionPort: '<S89>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_e,
        &top_level_algo_P.IfActionSubsystem8_p);

      /* End of Outputs for SubSystem: '<S59>/If Action Subsystem8' */
      break;

     case 9:
      /* Outputs for IfAction SubSystem: '<S59>/If Action Subsystem10' incorporates:
       *  ActionPort: '<S82>/Action Port'
       */
      top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_e,
        &top_level_algo_P.IfActionSubsystem10_o);

      /* End of Outputs for SubSystem: '<S59>/If Action Subsystem10' */
      break;
    }

    /* End of SwitchCase: '<S59>/Switch Case' */
    if (top_level_algo_M->Timing.TaskCounters.TID[3] == 0) {
      /* Switch: '<S51>/Reset' incorporates:
       *  Delay: '<S8>/Delay2'
       *  Memory: '<S51>/Memory'
       *  MinMax: '<S46>/MinMax'
       */
      if (top_level_algo_DW.Delay2_DSTATE_m[0U]) {
        /* Switch: '<S51>/Reset' incorporates:
         *  Constant: '<S51>/Initial Condition'
         */
        top_level_algo_B.Reset_b = top_level_algo_P.MinBDC_vinit;
      } else if ((rtb_Gain1 <= top_level_algo_DW.Memory_PreviousInput_m) ||
                 rtIsNaN(top_level_algo_DW.Memory_PreviousInput_m)) {
        /* MinMax: '<S46>/MinMax' incorporates:
         *  Switch: '<S51>/Reset'
         */
        top_level_algo_B.Reset_b = rtb_Gain1;
      } else {
        /* Switch: '<S51>/Reset' incorporates:
         *  Memory: '<S51>/Memory'
         *  MinMax: '<S46>/MinMax'
         */
        top_level_algo_B.Reset_b = top_level_algo_DW.Memory_PreviousInput_m;
      }

      /* End of Switch: '<S51>/Reset' */

      /* Chart: '<S8>/sample and hold1' */
      top_level_algo_sampleandhold(top_level_algo_B.Reset_b,
        top_level_algo_B.AND, &top_level_algo_B.Mean_AccVal,
        &top_level_algo_DW.sf_sampleandhold1);

      /* Logic: '<S5>/Zero' incorporates:
       *  Logic: '<S8>/OR'
       *  Logic: '<S8>/OR1'
       */
      rtb_IsZero_tmp = !rtb_IsNeg;
      rtb_NOT1_j = !rtb_IsPos;

      /* Logic: '<S8>/OR1' incorporates:
       *  Logic: '<S5>/Zero'
       *  Logic: '<S8>/OR'
       */
      rtb_NOT2_tmp = ((!rtb_NOT1_j) || (!rtb_IsZero_tmp));

      /* Logic: '<S8>/NOT2' incorporates:
       *  Logic: '<S8>/OR1'
       */
      rtb_NOT2 = (rtb_NOT2_tmp && rtb_IsZero_tmp);

      /* Logic: '<S8>/NOT' incorporates:
       *  Logic: '<S8>/OR'
       */
      rtb_NOT_c = (rtb_NOT1_j && rtb_NOT2_tmp);

      /* Sum: '<S5>/30 Diff' */
      top_level_algo_B.u0Diff = rtb_Gain1 - top_level_algo_B.Mean1_AccVal;

      /* MATLABSystem: '<S36>/Digital Port Write' incorporates:
       *  Constant: '<S25>/Constant'
       *  RelationalOperator: '<S25>/Compare'
       */
      top_level_algo_B.portNameLoc = GPIOE;
      if (rtb_Gain1 > top_level_algo_P.CompareToConstant_const) {
        pinWriteLoc = 64;
      } else {
        pinWriteLoc = 0;
      }

      LL_GPIO_SetOutputPin(top_level_algo_B.portNameLoc, (uint32_T)pinWriteLoc);
      LL_GPIO_ResetOutputPin(top_level_algo_B.portNameLoc, ~(uint32_T)
        pinWriteLoc & 64U);

      /* End of MATLABSystem: '<S36>/Digital Port Write' */

      /* MATLABSystem: '<S38>/Digital Port Write' incorporates:
       *  Constant: '<S26>/Constant'
       *  RelationalOperator: '<S26>/Compare'
       */
      top_level_algo_B.portNameLoc = GPIOE;
      if (rtb_Gain1 > top_level_algo_P.CompareToConstant1_const) {
        pinWriteLoc = 32;
      } else {
        pinWriteLoc = 0;
      }

      LL_GPIO_SetOutputPin(top_level_algo_B.portNameLoc, (uint32_T)pinWriteLoc);
      LL_GPIO_ResetOutputPin(top_level_algo_B.portNameLoc, ~(uint32_T)
        pinWriteLoc & 32U);

      /* End of MATLABSystem: '<S38>/Digital Port Write' */

      /* MATLABSystem: '<S40>/Digital Port Write' incorporates:
       *  Constant: '<S27>/Constant'
       *  RelationalOperator: '<S27>/Compare'
       */
      top_level_algo_B.portNameLoc = GPIOE;
      if (rtb_Gain1 > top_level_algo_P.CompareToConstant2_const) {
        pinWriteLoc = 16;
      } else {
        pinWriteLoc = 0;
      }

      LL_GPIO_SetOutputPin(top_level_algo_B.portNameLoc, (uint32_T)pinWriteLoc);
      LL_GPIO_ResetOutputPin(top_level_algo_B.portNameLoc, ~(uint32_T)
        pinWriteLoc & 16U);

      /* End of MATLABSystem: '<S40>/Digital Port Write' */

      /* MATLABSystem: '<S42>/Digital Port Write' incorporates:
       *  Constant: '<S28>/Constant'
       *  RelationalOperator: '<S28>/Compare'
       */
      top_level_algo_B.portNameLoc = GPIOE;
      if (rtb_Gain1 > top_level_algo_P.CompareToConstant3_const) {
        pinWriteLoc = 8;
      } else {
        pinWriteLoc = 0;
      }

      LL_GPIO_SetOutputPin(top_level_algo_B.portNameLoc, (uint32_T)pinWriteLoc);
      LL_GPIO_ResetOutputPin(top_level_algo_B.portNameLoc, ~(uint32_T)
        pinWriteLoc & 8U);

      /* End of MATLABSystem: '<S42>/Digital Port Write' */

      /* MATLABSystem: '<S44>/Digital Port Write' incorporates:
       *  Constant: '<S29>/Constant'
       *  RelationalOperator: '<S29>/Compare'
       */
      top_level_algo_B.portNameLoc = GPIOE;
      if (rtb_Gain1 > top_level_algo_P.CompareToConstant4_const) {
        pinWriteLoc = 4;
      } else {
        pinWriteLoc = 0;
      }

      LL_GPIO_SetOutputPin(top_level_algo_B.portNameLoc, (uint32_T)pinWriteLoc);
      LL_GPIO_ResetOutputPin(top_level_algo_B.portNameLoc, ~(uint32_T)
        pinWriteLoc & 4U);

      /* End of MATLABSystem: '<S44>/Digital Port Write' */
    }

    /* DiscretePulseGenerator: '<S9>/Pulse Generator' */
    rtb_PulseGenerator = (top_level_algo_DW.clockTickCounter <
                          top_level_algo_P.PulseGenerator_Duty) &&
      (top_level_algo_DW.clockTickCounter >= 0) ?
      top_level_algo_P.PulseGenerator_Amp : 0.0;

    /* DiscretePulseGenerator: '<S9>/Pulse Generator' */
    if (top_level_algo_DW.clockTickCounter >=
        top_level_algo_P.PulseGenerator_Period - 1.0) {
      top_level_algo_DW.clockTickCounter = 0;
    } else {
      top_level_algo_DW.clockTickCounter++;
    }

    /* Sum: '<S55>/Add' incorporates:
     *  ArithShift: '<S55>/Shift Arithmetic1'
     *  ArithShift: '<S55>/Shift Arithmetic2'
     *  DataTypeConversion: '<S55>/Cast To Double'
     *  DataTypeConversion: '<S55>/Cast To Double1'
     *  DataTypeConversion: '<S55>/Cast To Double2'
     */
    rtb_Add = (((uint32_T)top_level_algo_B.Merge_a << 8) +
               top_level_algo_B.Merge) + ((uint32_T)top_level_algo_B.Merge_e <<
      16);

    /* Chart: '<S9>/DataLogic' */
    if (top_level_algo_DW.temporalCounter_i1 < MAX_uint32_T) {
      top_level_algo_DW.temporalCounter_i1++;
    }

    if (top_level_algo_DW.is_active_c15_top_level_algo == 0U) {
      top_level_algo_DW.is_active_c15_top_level_algo = 1U;
      top_level_algo_DW.is_c15_top_level_algo = top_level_algo_IN_LOAD;
      top_level_algo_B.data = 0U;
      top_level_algo_DW.Holder = rtb_Add;
    } else {
      switch (top_level_algo_DW.is_c15_top_level_algo) {
       case top_level_algo_IN_CHECK:
        if (top_level_algo_DW.Holder == 0U) {
          top_level_algo_DW.is_c15_top_level_algo = top_level_algo_IN_WAITING;
          top_level_algo_DW.temporalCounter_i1 = 0U;
        } else if (top_level_algo_DW.temporalCounter_i1 >= 4U) {
          top_level_algo_DW.is_c15_top_level_algo = top_level_algo_IN_MASK;
          top_level_algo_DW.temporalCounter_i1 = 0U;
          top_level_algo_B.data = top_level_algo_DW.Holder & 1U;
        }
        break;

       case top_level_algo_IN_HOLD:
        if (rtb_PulseGenerator == 0.0) {
          top_level_algo_DW.is_c15_top_level_algo = top_level_algo_IN_LOAD;
          top_level_algo_B.data = 0U;
          top_level_algo_DW.Holder = rtb_Add;
        }
        break;

       case top_level_algo_IN_LOAD:
        if (rtb_PulseGenerator == 1.0) {
          top_level_algo_DW.is_c15_top_level_algo = top_level_algo_IN_Wait;
          top_level_algo_DW.temporalCounter_i1 = 0U;
        }
        break;

       case top_level_algo_IN_MASK:
        if (top_level_algo_DW.temporalCounter_i1 >= 4U) {
          top_level_algo_DW.is_c15_top_level_algo = top_level_algo_IN_CHECK;
          top_level_algo_DW.temporalCounter_i1 = 0U;
          top_level_algo_DW.Holder >>= 1;
        }
        break;

       case top_level_algo_IN_START:
        if (top_level_algo_DW.temporalCounter_i1 >= (uint32_T)
            top_level_algo_clk_period) {
          top_level_algo_DW.is_c15_top_level_algo = top_level_algo_IN_MASK;
          top_level_algo_DW.temporalCounter_i1 = 0U;
          top_level_algo_B.data = top_level_algo_DW.Holder & 1U;
        }
        break;

       case top_level_algo_IN_WAITING:
        if (top_level_algo_DW.temporalCounter_i1 >= 4U) {
          top_level_algo_DW.is_c15_top_level_algo = top_level_algo_IN_HOLD;
          top_level_algo_B.data = 0U;
        }
        break;

       default:
        /* case IN_Wait: */
        if (top_level_algo_DW.temporalCounter_i1 >= 2U) {
          top_level_algo_DW.is_c15_top_level_algo = top_level_algo_IN_START;
          top_level_algo_DW.temporalCounter_i1 = 0U;
          top_level_algo_B.data = 1U;
        }
        break;
      }
    }

    /* End of Chart: '<S9>/DataLogic' */

    /* MATLABSystem: '<S16>/Digital Port Write' */
    top_level_algo_B.portNameLoc = GPIOE;
    if (top_level_algo_B.data != 0U) {
      pinWriteLoc = 512;
    } else {
      pinWriteLoc = 0;
    }

    LL_GPIO_SetOutputPin(top_level_algo_B.portNameLoc, (uint32_T)pinWriteLoc);
    LL_GPIO_ResetOutputPin(top_level_algo_B.portNameLoc, ~(uint32_T)pinWriteLoc
      & 512U);

    /* End of MATLABSystem: '<S16>/Digital Port Write' */
    if (top_level_algo_M->Timing.TaskCounters.TID[3] == 0) {
      /* MATLABSystem: '<S11>/Analog to Digital Converter' */
      top_level_algo_B.triggerType = ADC_TRIGGER_AND_READ;
      regularReadADCDMA(top_level_algo_DW.obj.ADCHandle,
                        top_level_algo_B.triggerType, &data);

      /* DataTypeConversion: '<Root>/Cast To Double' incorporates:
       *  MATLABSystem: '<S11>/Analog to Digital Converter'
       */
      top_level_algo_B.CastToDouble = data;
    }
  }

  {
    int_T idxDelay;
    if (top_level_algo_M->Timing.TaskCounters.TID[2] == 0) {
      /* Update for UnitDelay: '<S56>/Unit Delay' */
      top_level_algo_DW.UnitDelay_DSTATE = top_level_algo_B.Switch;
    }

    /* Update for Delay: '<S9>/Delay' */
    top_level_algo_DW.Delay_DSTATE[0] = top_level_algo_DW.Delay_DSTATE[1];
    top_level_algo_DW.Delay_DSTATE[1] = top_level_algo_DW.Delay_DSTATE[2];
    top_level_algo_DW.Delay_DSTATE[2] = top_level_algo_DW.Delay_DSTATE[3];
    top_level_algo_DW.Delay_DSTATE[3] = rtb_PulseGenerator;

    /* Update for Delay: '<S9>/Delay8' */
    for (idxDelay = 0; idxDelay < 287; idxDelay++) {
      top_level_algo_DW.Delay8_DSTATE[idxDelay] =
        top_level_algo_DW.Delay8_DSTATE[idxDelay + 1];
    }

    top_level_algo_DW.Delay8_DSTATE[287] = rtb_LogicalOperator;

    /* End of Update for Delay: '<S9>/Delay8' */
    if (top_level_algo_M->Timing.TaskCounters.TID[3] == 0) {
      /* Update for S-Function (sfix_udelay): '<S6>/Tapped Delay1' */
      for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        top_level_algo_DW.TappedDelay1_X[idxDelay] =
          top_level_algo_DW.TappedDelay1_X[idxDelay + 1];
      }

      top_level_algo_DW.TappedDelay1_X[19] = top_level_algo_B.Product;

      /* End of Update for S-Function (sfix_udelay): '<S6>/Tapped Delay1' */

      /* Update for Delay: '<S5>/Delay' */
      top_level_algo_DW.Delay_DSTATE_d = rtb_Gain1;

      /* Update for Delay: '<S5>/Delay1' */
      top_level_algo_DW.Delay1_DSTATE[0] = top_level_algo_DW.Delay1_DSTATE[1];
      top_level_algo_DW.Delay1_DSTATE[1] = rtb_Gain1;

      /* Update for Delay: '<S5>/Delay2' */
      top_level_algo_DW.Delay2_DSTATE[0] = top_level_algo_DW.Delay2_DSTATE[1];
      top_level_algo_DW.Delay2_DSTATE[1] = top_level_algo_DW.Delay2_DSTATE[2];
      top_level_algo_DW.Delay2_DSTATE[2] = rtb_Gain1;

      /* Update for Delay: '<S5>/Delay3' */
      top_level_algo_DW.Delay3_DSTATE[0] = top_level_algo_DW.Delay3_DSTATE[1];
      top_level_algo_DW.Delay3_DSTATE[1] = top_level_algo_DW.Delay3_DSTATE[2];
      top_level_algo_DW.Delay3_DSTATE[2] = top_level_algo_DW.Delay3_DSTATE[3];
      top_level_algo_DW.Delay3_DSTATE[3] = rtb_Gain1;

      /* Update for Delay: '<S5>/Delay4' */
      top_level_algo_DW.Delay4_DSTATE[0] = top_level_algo_DW.Delay4_DSTATE[1];
      top_level_algo_DW.Delay4_DSTATE[1] = top_level_algo_DW.Delay4_DSTATE[2];
      top_level_algo_DW.Delay4_DSTATE[2] = top_level_algo_DW.Delay4_DSTATE[3];
      top_level_algo_DW.Delay4_DSTATE[3] = top_level_algo_DW.Delay4_DSTATE[4];
      top_level_algo_DW.Delay4_DSTATE[4] = rtb_Gain1;
      for (idxDelay = 0; idxDelay < 9; idxDelay++) {
        /* Update for S-Function (sfix_udelay): '<S6>/Tapped Delay' */
        top_level_algo_DW.TappedDelay_X_f[idxDelay] =
          top_level_algo_DW.TappedDelay_X_f[idxDelay + 1];

        /* Update for S-Function (sfix_udelay): '<S5>/Tapped Delay' */
        top_level_algo_DW.TappedDelay_X[idxDelay] =
          top_level_algo_DW.TappedDelay_X[idxDelay + 1];

        /* Update for Delay: '<S5>/Delay5' */
        top_level_algo_DW.Delay5_DSTATE[idxDelay] =
          top_level_algo_DW.Delay5_DSTATE[idxDelay + 1];
      }

      /* Update for S-Function (sfix_udelay): '<S6>/Tapped Delay' */
      top_level_algo_DW.TappedDelay_X_f[9] = top_level_algo_B.CastToDouble;

      /* Update for S-Function (sfix_udelay): '<S5>/Tapped Delay' */
      top_level_algo_DW.TappedDelay_X[9] = top_level_algo_B.u0Diff;

      /* Update for Delay: '<S5>/Delay5' */
      top_level_algo_DW.Delay5_DSTATE[9] = rtb_Gain1;

      /* Update for Delay: '<S8>/Delay4' */
      top_level_algo_DW.Delay4_DSTATE_a[0] = top_level_algo_DW.Delay4_DSTATE_a[1];
      top_level_algo_DW.Delay4_DSTATE_a[1] = rtb_IsNeg;

      /* Update for Delay: '<S8>/Delay3' */
      top_level_algo_DW.Delay3_DSTATE_m[0] = top_level_algo_DW.Delay3_DSTATE_m[1];
      top_level_algo_DW.Delay3_DSTATE_m[1] = rtb_LogicalOperator7;

      /* Update for Memory: '<S50>/Memory' */
      top_level_algo_DW.Memory_PreviousInput = rtb_Reset;

      /* Update for Delay: '<S8>/Delay8' */
      top_level_algo_DW.Delay8_DSTATE_b[0] = top_level_algo_DW.Delay8_DSTATE_b[1];
      top_level_algo_DW.Delay8_DSTATE_b[1] = rtb_IsPos;

      /* Update for Delay: '<S8>/Delay6' */
      top_level_algo_DW.Delay6_DSTATE[0] = top_level_algo_DW.Delay6_DSTATE[1];
      top_level_algo_DW.Delay6_DSTATE[1] = rtb_LogicalOperator3;

      /* Update for Delay: '<S8>/Delay' */
      top_level_algo_DW.Delay_DSTATE_a[0] = top_level_algo_DW.Delay_DSTATE_a[1];

      /* Update for Delay: '<S8>/Delay2' */
      top_level_algo_DW.Delay2_DSTATE_m[0] = top_level_algo_DW.Delay2_DSTATE_m[1];

      /* Update for Delay: '<S8>/Delay' */
      top_level_algo_DW.Delay_DSTATE_a[1] = top_level_algo_DW.Delay_DSTATE_a[2];

      /* Update for Delay: '<S8>/Delay2' */
      top_level_algo_DW.Delay2_DSTATE_m[1] = top_level_algo_DW.Delay2_DSTATE_m[2];

      /* Update for Delay: '<S8>/Delay' */
      top_level_algo_DW.Delay_DSTATE_a[2] = top_level_algo_DW.Delay_DSTATE_a[3];

      /* Update for Delay: '<S8>/Delay2' */
      top_level_algo_DW.Delay2_DSTATE_m[2] = top_level_algo_DW.Delay2_DSTATE_m[3];

      /* Update for Delay: '<S8>/Delay' */
      top_level_algo_DW.Delay_DSTATE_a[3] = top_level_algo_DW.Delay_DSTATE_a[4];

      /* Update for Delay: '<S8>/Delay2' */
      top_level_algo_DW.Delay2_DSTATE_m[3] = top_level_algo_DW.Delay2_DSTATE_m[4];

      /* Update for Delay: '<S8>/Delay' */
      top_level_algo_DW.Delay_DSTATE_a[4] = rtb_NOT_c;

      /* Update for Delay: '<S8>/Delay2' */
      top_level_algo_DW.Delay2_DSTATE_m[4] = rtb_NOT2;

      /* Update for Memory: '<S51>/Memory' */
      top_level_algo_DW.Memory_PreviousInput_m = top_level_algo_B.Reset_b;
    }
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
    real_T displacement_a;
    int32_T i;

    /* Start for DiscretePulseGenerator: '<S9>/Pulse Generator' */
    top_level_algo_DW.clockTickCounter = -2000;

    /* InitializeConditions for UnitDelay: '<S56>/Unit Delay' */
    top_level_algo_DW.UnitDelay_DSTATE =
      top_level_algo_P.UnitDelay_InitialCondition;

    /* InitializeConditions for Delay: '<S9>/Delay' */
    top_level_algo_DW.Delay_DSTATE[0] = top_level_algo_P.Delay_InitialCondition;
    top_level_algo_DW.Delay_DSTATE[1] = top_level_algo_P.Delay_InitialCondition;
    top_level_algo_DW.Delay_DSTATE[2] = top_level_algo_P.Delay_InitialCondition;
    top_level_algo_DW.Delay_DSTATE[3] = top_level_algo_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S9>/Delay8' */
    for (i = 0; i < 288; i++) {
      top_level_algo_DW.Delay8_DSTATE[i] =
        top_level_algo_P.Delay8_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S9>/Delay8' */

    /* InitializeConditions for Delay: '<S9>/Delay7' */
    top_level_algo_DW.Delay7_DSTATE = top_level_algo_P.Delay7_InitialCondition;

    /* InitializeConditions for S-Function (sfix_udelay): '<S6>/Tapped Delay1' */
    for (i = 0; i < 20; i++) {
      top_level_algo_DW.TappedDelay1_X[i] = top_level_algo_P.TappedDelay1_vinit;
    }

    /* End of InitializeConditions for S-Function (sfix_udelay): '<S6>/Tapped Delay1' */
    for (i = 0; i < 10; i++) {
      /* InitializeConditions for S-Function (sfix_udelay): '<S6>/Tapped Delay' */
      top_level_algo_DW.TappedDelay_X_f[i] =
        top_level_algo_P.TappedDelay_vinit_l;

      /* InitializeConditions for S-Function (sfix_udelay): '<S5>/Tapped Delay' */
      top_level_algo_DW.TappedDelay_X[i] = top_level_algo_P.TappedDelay_vinit;
    }

    /* InitializeConditions for Delay: '<S5>/Delay' */
    top_level_algo_DW.Delay_DSTATE_d = top_level_algo_P.Delay_InitialCondition_m;

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
    for (i = 0; i < 10; i++) {
      top_level_algo_DW.Delay5_DSTATE[i] =
        top_level_algo_P.Delay5_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S5>/Delay5' */

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

    /* InitializeConditions for Memory: '<S50>/Memory' */
    top_level_algo_DW.Memory_PreviousInput = top_level_algo_P.MaxBDC_vinit;

    /* InitializeConditions for Delay: '<S8>/Delay7' */
    top_level_algo_DW.Delay7_DSTATE_l =
      top_level_algo_P.Delay7_InitialCondition_o;

    /* InitializeConditions for Delay: '<S8>/Delay8' */
    top_level_algo_DW.Delay8_DSTATE_b[0] =
      top_level_algo_P.Delay8_InitialCondition_o;

    /* InitializeConditions for Delay: '<S8>/Delay6' */
    top_level_algo_DW.Delay6_DSTATE[0] =
      top_level_algo_P.Delay6_InitialCondition;

    /* InitializeConditions for Delay: '<S8>/Delay8' */
    top_level_algo_DW.Delay8_DSTATE_b[1] =
      top_level_algo_P.Delay8_InitialCondition_o;

    /* InitializeConditions for Delay: '<S8>/Delay6' */
    top_level_algo_DW.Delay6_DSTATE[1] =
      top_level_algo_P.Delay6_InitialCondition;
    for (i = 0; i < 5; i++) {
      /* InitializeConditions for Delay: '<S8>/Delay' */
      top_level_algo_DW.Delay_DSTATE_a[i] =
        top_level_algo_P.Delay_InitialCondition_d;

      /* InitializeConditions for Delay: '<S8>/Delay2' */
      top_level_algo_DW.Delay2_DSTATE_m[i] =
        top_level_algo_P.Delay2_InitialCondition_c;
    }

    /* InitializeConditions for Memory: '<S51>/Memory' */
    top_level_algo_DW.Memory_PreviousInput_m = top_level_algo_P.MinBDC_vinit;

    /* SystemInitialize for Chart: '<S8>/sample and hold' */
    top_level_al_sampleandhold_Init(&displacement_a);

    /* SystemInitialize for Chart: '<S8>/sample and hold1' */
    top_level_al_sampleandhold_Init(&displacement_a);

    /* SystemInitialize for Merge: '<S57>/Merge' */
    top_level_algo_B.Merge = top_level_algo_P.Merge_InitialOutput;

    /* SystemInitialize for Merge: '<S58>/Merge' */
    top_level_algo_B.Merge_a = top_level_algo_P.Merge_InitialOutput_p;

    /* SystemInitialize for Merge: '<S59>/Merge' */
    top_level_algo_B.Merge_e = top_level_algo_P.Merge_InitialOutput_e;

    /* Start for MATLABSystem: '<S11>/Analog to Digital Converter' */
    top_level_algo_DW.obj.isInitialized = 0;
    top_level_algo_DW.obj.matlabCodegenIsDeleted = false;
    top_level_algo_SystemCore_setup(&top_level_algo_DW.obj);
  }
}

/* Model terminate function */
void top_level_algo_terminate(void)
{
  uint16_T mode;

  /* Terminate for MATLABSystem: '<S11>/Analog to Digital Converter' */
  if (!top_level_algo_DW.obj.matlabCodegenIsDeleted) {
    top_level_algo_DW.obj.matlabCodegenIsDeleted = true;
    if ((top_level_algo_DW.obj.isInitialized == 1) &&
        top_level_algo_DW.obj.isSetupComplete) {
      mode = ADC_DMA_INTERRUPT_MODE;
      ADC_Handle_Deinit(top_level_algo_DW.obj.ADCHandle, mode, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S11>/Analog to Digital Converter' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
