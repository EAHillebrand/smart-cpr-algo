/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo.c
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 1.86
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Fri Nov 25 20:36:29 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "top_level_algo.h"
#include "top_level_algo_private.h"

/* Named constants for Chart: '<S5>/sample and hold' */
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

/* Named constants for Chart: '<S4>/timer' */
#define top_level_algo_IN_Finished     ((uint8_T)1U)
#define top_level_algo_IN_Starting     ((uint8_T)2U)

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

/*
 * System initialize for atomic system:
 *    '<S5>/sample and hold'
 *    '<S5>/sample and hold1'
 */
void top_level_al_sampleandhold_Init(real_T *rty_displacement)
{
  *rty_displacement = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S5>/sample and hold'
 *    '<S5>/sample and hold1'
 */
void top_level_algo_sampleandhold(real_T rtu_max, boolean_T rtu_read, real_T
  *rty_displacement, DW_sampleandhold_top_level_al_T *localDW)
{
  /* Chart: '<S5>/sample and hold' */
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

  /* End of Chart: '<S5>/sample and hold' */
}

/* Model step function */
void top_level_algo_step(void)
{
  /* local block i/o variables */
  real_T rtb_Merge;
  real_T rtb_Reset;
  real_T rtb_Reset_b;
  boolean_T rtb_IsPos;
  boolean_T rtb_IsNeg;
  boolean_T rtb_LogicalOperator7;
  boolean_T rtb_LogicalOperator3;
  boolean_T rtb_NOT2;
  boolean_T rtb_NOT;

  {
    codertarget_arduinobase_inter_T *obj;
    real_T u;
    int32_T str;
    int32_T str_0;
    int16_T Mean_AccVal_f;
    int16_T n;
    int16_T rtb_measure_period;
    boolean_T Delay7_DSTATE_tmp;
    boolean_T rtb_AND;

    /* S-Function (sdspstatfcns): '<S4>/Mean1' incorporates:
     *  S-Function (sfix_udelay): '<S4>/Tapped Delay1'
     */
    top_level_algo_B.Mean1_AccVal = top_level_algo_DW.TappedDelay1_X[0L];
    str = 1L;
    for (n = 18; n >= 0; n--) {
      top_level_algo_B.Mean1_AccVal += top_level_algo_DW.TappedDelay1_X[str];
      str++;
    }

    /* Chart: '<S4>/timer' incorporates:
     *  S-Function (sdspstatfcns): '<S4>/Mean1'
     */
    if (top_level_algo_DW.temporalCounter_i1 < 8191U) {
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
      if (top_level_algo_DW.temporalCounter_i1 >= 5000U) {
        top_level_algo_DW.is_c3_top_level_algo = top_level_algo_IN_Finished;
        top_level_algo_B.baseline = top_level_algo_B.Mean1_AccVal / 20.0;
        rtb_measure_period = 1;
      }
    }

    /* End of Chart: '<S4>/timer' */

    /* S-Function (sdspstatfcns): '<S4>/Mean' incorporates:
     *  S-Function (sfix_udelay): '<S4>/Tapped Delay'
     */
    Mean_AccVal_f = (int16_T)top_level_algo_DW.TappedDelay_X_f[0L];
    str = 1L;

    /* S-Function (sdspstatfcns): '<S3>/Mean' incorporates:
     *  S-Function (sfix_udelay): '<S3>/Tapped Delay'
     */
    top_level_algo_B.Mean1_AccVal = top_level_algo_DW.TappedDelay_X[0L];
    str_0 = 1L;
    for (n = 18; n >= 0; n--) {
      /* S-Function (sdspstatfcns): '<S4>/Mean' incorporates:
       *  S-Function (sfix_udelay): '<S4>/Tapped Delay'
       */
      Mean_AccVal_f += (int16_T)top_level_algo_DW.TappedDelay_X_f[str];
      str++;

      /* S-Function (sdspstatfcns): '<S3>/Mean' incorporates:
       *  S-Function (sfix_udelay): '<S3>/Tapped Delay'
       */
      top_level_algo_B.Mean1_AccVal += top_level_algo_DW.TappedDelay_X[str_0];
      str_0++;
    }

    /* S-Function (sdspstatfcns): '<S3>/Mean' */
    top_level_algo_B.Mean1_AccVal /= 20.0;

    /* Product: '<S4>/Product' incorporates:
     *  Constant: '<S4>/Constant'
     *  Constant: '<S4>/Constant1'
     *  Product: '<S4>/Divide'
     *  S-Function (sdspstatfcns): '<S4>/Mean'
     */
    top_level_algo_B.Product = (real_T)(uint16_T)div_nde_s32_floor(Mean_AccVal_f,
      20L) / top_level_algo_P.Constant1_Value * top_level_algo_P.Constant_Value;

    /* Switch: '<S4>/Switch' */
    if (rtb_measure_period > top_level_algo_P.Switch_Threshold) {
      top_level_algo_B.MajorityVoterSlope = top_level_algo_B.baseline;
    } else {
      top_level_algo_B.MajorityVoterSlope = top_level_algo_B.Product;
    }

    /* End of Switch: '<S4>/Switch' */

    /* Gain: '<S4>/Radius (mm)' incorporates:
     *  Gain: '<S4>/Convert to Radians'
     *  Gain: '<S4>/degrees per volt'
     *  Sum: '<S4>/Subtract'
     */
    rtb_Merge = (top_level_algo_B.MajorityVoterSlope - top_level_algo_B.Product)
      * top_level_algo_P.degreespervolt_Gain *
      top_level_algo_P.ConverttoRadians_Gain * top_level_algo_P.Radiusmm_Gain;

    /* If: '<S12>/If' */
    if (rtb_Merge < 0.0) {
      /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      /* Gain: '<S4>/Radius (mm)' incorporates:
       *  Constant: '<S12>/Constant'
       *  Inport: '<S14>/In1'
       *  Merge: '<S12>/Merge'
       */
      rtb_Merge = top_level_algo_P.Constant_Value_a;

      /* End of Outputs for SubSystem: '<S12>/If Action Subsystem' */
    }

    /* End of If: '<S12>/If' */

    /* Sum: '<S3>/First Diff' incorporates:
     *  Delay: '<S3>/Delay'
     */
    top_level_algo_B.MajorityVoterSlope = rtb_Merge -
      top_level_algo_DW.Delay_DSTATE;

    /* Sum: '<S3>/Second Diff' incorporates:
     *  Delay: '<S3>/Delay'
     *  Delay: '<S3>/Delay1'
     */
    top_level_algo_B.u = top_level_algo_DW.Delay_DSTATE -
      top_level_algo_DW.Delay1_DSTATE[0];

    /* Sum: '<S3>/Third Diff' incorporates:
     *  Delay: '<S3>/Delay1'
     *  Delay: '<S3>/Delay2'
     */
    top_level_algo_B.u_m = top_level_algo_DW.Delay1_DSTATE[0] -
      top_level_algo_DW.Delay2_DSTATE[0];

    /* Sum: '<S3>/Fourth Diff' incorporates:
     *  Delay: '<S3>/Delay2'
     *  Delay: '<S3>/Delay3'
     */
    top_level_algo_B.u_c = top_level_algo_DW.Delay2_DSTATE[0] -
      top_level_algo_DW.Delay3_DSTATE[0];

    /* Sum: '<S3>/Fifth Diff' incorporates:
     *  Delay: '<S3>/Delay3'
     *  Delay: '<S3>/Delay4'
     */
    top_level_algo_B.u_k = top_level_algo_DW.Delay3_DSTATE[0] -
      top_level_algo_DW.Delay4_DSTATE[0];

    /* Sum: '<S3>/5to30 Diff' incorporates:
     *  Delay: '<S3>/Delay4'
     *  Delay: '<S3>/Delay5'
     */
    u = top_level_algo_DW.Delay4_DSTATE[0] - top_level_algo_DW.Delay5_DSTATE[0];

    /* Signum: '<S3>/Sign' */
    if (top_level_algo_B.MajorityVoterSlope < 0.0) {
      top_level_algo_B.MajorityVoterSlope = -1.0;
    } else if (top_level_algo_B.MajorityVoterSlope > 0.0) {
      top_level_algo_B.MajorityVoterSlope = 1.0;
    } else if (top_level_algo_B.MajorityVoterSlope == 0.0) {
      top_level_algo_B.MajorityVoterSlope = 0.0;
    } else {
      top_level_algo_B.MajorityVoterSlope = (rtNaN);
    }

    /* End of Signum: '<S3>/Sign' */

    /* Signum: '<S3>/Sign1' */
    if (top_level_algo_B.u < 0.0) {
      top_level_algo_B.u = -1.0;
    } else if (top_level_algo_B.u > 0.0) {
      top_level_algo_B.u = 1.0;
    } else if (top_level_algo_B.u == 0.0) {
      top_level_algo_B.u = 0.0;
    } else {
      top_level_algo_B.u = (rtNaN);
    }

    /* End of Signum: '<S3>/Sign1' */

    /* Signum: '<S3>/Sign2' */
    if (top_level_algo_B.u_m < 0.0) {
      top_level_algo_B.u_m = -1.0;
    } else if (top_level_algo_B.u_m > 0.0) {
      top_level_algo_B.u_m = 1.0;
    } else if (top_level_algo_B.u_m == 0.0) {
      top_level_algo_B.u_m = 0.0;
    } else {
      top_level_algo_B.u_m = (rtNaN);
    }

    /* End of Signum: '<S3>/Sign2' */

    /* Signum: '<S3>/Sign3' */
    if (top_level_algo_B.u_c < 0.0) {
      top_level_algo_B.u_c = -1.0;
    } else if (top_level_algo_B.u_c > 0.0) {
      top_level_algo_B.u_c = 1.0;
    } else if (top_level_algo_B.u_c == 0.0) {
      top_level_algo_B.u_c = 0.0;
    } else {
      top_level_algo_B.u_c = (rtNaN);
    }

    /* End of Signum: '<S3>/Sign3' */

    /* Signum: '<S3>/Sign4' */
    if (top_level_algo_B.u_k < 0.0) {
      top_level_algo_B.u_k = -1.0;
    } else if (top_level_algo_B.u_k > 0.0) {
      top_level_algo_B.u_k = 1.0;
    } else if (top_level_algo_B.u_k == 0.0) {
      top_level_algo_B.u_k = 0.0;
    } else {
      top_level_algo_B.u_k = (rtNaN);
    }

    /* End of Signum: '<S3>/Sign4' */

    /* Signum: '<S3>/Sign5' */
    if (u < 0.0) {
      u = -1.0;
    } else if (u > 0.0) {
      u = 1.0;
    } else if (u == 0.0) {
      u = 0.0;
    } else {
      u = (rtNaN);
    }

    /* End of Signum: '<S3>/Sign5' */

    /* Sum: '<S3>/Add' incorporates:
     *  Gain: '<S3>/Gain'
     *  Gain: '<S3>/Gain1'
     */
    top_level_algo_B.MajorityVoterSlope = ((((top_level_algo_P.Gain_Gain *
      top_level_algo_B.MajorityVoterSlope + top_level_algo_P.Gain1_Gain *
      top_level_algo_B.u) + top_level_algo_B.u_m) + top_level_algo_B.u_c) +
      top_level_algo_B.u_k) + u;

    /* Logic: '<S3>/AND' incorporates:
     *  Constant: '<S11>/Constant'
     *  Constant: '<S9>/Constant'
     *  RelationalOperator: '<S11>/Compare'
     *  RelationalOperator: '<S9>/Compare'
     */
    rtb_IsPos = ((top_level_algo_B.MajorityVoterSlope >=
                  top_level_algo_P.Positive_const) &&
                 (top_level_algo_B.Mean1_AccVal >=
                  top_level_algo_P.Longrangemotionup_const));

    /* Logic: '<S5>/Logical Operator5' incorporates:
     *  Delay: '<S5>/Delay1'
     *  Delay: '<S5>/Delay4'
     *  Logic: '<S5>/Logical Operator4'
     *  Logic: '<S5>/Logical Operator6'
     */
    top_level_algo_DW.Delay1_DSTATE_m = ((!rtb_IsPos) &&
      (top_level_algo_DW.Delay4_DSTATE_a[0] || top_level_algo_DW.Delay1_DSTATE_m));

    /* Logic: '<S3>/AND1' incorporates:
     *  Constant: '<S10>/Constant'
     *  Constant: '<S8>/Constant'
     *  RelationalOperator: '<S10>/Compare'
     *  RelationalOperator: '<S8>/Compare'
     */
    rtb_IsNeg = ((top_level_algo_B.MajorityVoterSlope <=
                  top_level_algo_P.Negative_const) &&
                 (top_level_algo_B.Mean1_AccVal <=
                  top_level_algo_P.Longrangemotiondown_const));

    /* Logic: '<S5>/Logical Operator7' incorporates:
     *  Delay: '<S5>/Delay1'
     *  Logic: '<S5>/NOT5'
     */
    rtb_LogicalOperator7 = (rtb_IsNeg && (!top_level_algo_DW.Delay1_DSTATE_m));

    /* Switch: '<S21>/Reset' incorporates:
     *  Delay: '<S5>/Delay'
     *  Memory: '<S21>/Memory'
     *  MinMax: '<S16>/MinMax'
     */
    if (top_level_algo_DW.Delay_DSTATE_a[0U]) {
      /* Switch: '<S21>/Reset' incorporates:
       *  Constant: '<S21>/Initial Condition'
       */
      rtb_Reset = top_level_algo_P.MaxBDC_vinit;
    } else if ((rtb_Merge >= top_level_algo_DW.Memory_PreviousInput) || rtIsNaN
               (top_level_algo_DW.Memory_PreviousInput)) {
      /* MinMax: '<S16>/MinMax' incorporates:
       *  Switch: '<S21>/Reset'
       */
      rtb_Reset = rtb_Merge;
    } else {
      /* Switch: '<S21>/Reset' incorporates:
       *  Memory: '<S21>/Memory'
       *  MinMax: '<S16>/MinMax'
       */
      rtb_Reset = top_level_algo_DW.Memory_PreviousInput;
    }

    /* End of Switch: '<S21>/Reset' */

    /* Logic: '<S5>/Logical Operator' incorporates:
     *  Logic: '<S3>/Zero'
     *  Logic: '<S5>/OR1'
     */
    Delay7_DSTATE_tmp = !rtb_IsNeg;

    /* Logic: '<S5>/Logical Operator1' incorporates:
     *  Delay: '<S5>/Delay7'
     *  Delay: '<S5>/Delay8'
     *  Logic: '<S5>/Logical Operator'
     *  Logic: '<S5>/Logical Operator2'
     */
    top_level_algo_DW.Delay7_DSTATE = (Delay7_DSTATE_tmp &&
      (top_level_algo_DW.Delay8_DSTATE[0] || top_level_algo_DW.Delay7_DSTATE));

    /* Logic: '<S5>/Logical Operator3' incorporates:
     *  Delay: '<S5>/Delay7'
     *  Logic: '<S5>/NOT4'
     */
    rtb_LogicalOperator3 = (rtb_IsPos && (!top_level_algo_DW.Delay7_DSTATE));

    /* Logic: '<S5>/AND' incorporates:
     *  Delay: '<S5>/Delay6'
     *  Logic: '<S5>/NOT3'
     */
    rtb_AND = (rtb_LogicalOperator3 && (!top_level_algo_DW.Delay6_DSTATE[0]));

    /* Clock: '<S2>/Clock1' */
    top_level_algo_B.Mean1_AccVal = top_level_algo_M->Timing.t[0];

    /* Chart: '<S2>/Chart' */
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
          top_level_algo_DW.fourth = top_level_algo_B.Mean1_AccVal;
        } else if (!rtb_AND) {
          top_level_algo_DW.is_c4_top_level_algo = top_level_algo_IN_POLLING;
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
        } else if (top_level_algo_B.Mean1_AccVal - top_level_algo_DW.last_count >
                   2.0) {
          top_level_algo_DW.is_c4_top_level_algo = top_level_algo_IN_INIT;
          top_level_algo_DW.comp = 0.0;
          top_level_algo_DW.first = 0.0;
          top_level_algo_DW.second = 0.0;
          top_level_algo_DW.third = 0.0;
          top_level_algo_DW.fourth = 0.0;
        } else if (rtb_AND && (top_level_algo_DW.comp > 3.0)) {
          top_level_algo_DW.is_c4_top_level_algo = top_level_algo_IN_SHORTEN;
          top_level_algo_DW.last_count = top_level_algo_B.Mean1_AccVal;
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

    /* Switch: '<S22>/Reset' incorporates:
     *  Delay: '<S5>/Delay2'
     *  Memory: '<S22>/Memory'
     *  MinMax: '<S17>/MinMax'
     */
    if (top_level_algo_DW.Delay2_DSTATE_m[0U]) {
      /* Switch: '<S22>/Reset' incorporates:
       *  Constant: '<S22>/Initial Condition'
       */
      rtb_Reset_b = top_level_algo_P.MinBDC_vinit;
    } else if ((rtb_Merge <= top_level_algo_DW.Memory_PreviousInput_m) ||
               rtIsNaN(top_level_algo_DW.Memory_PreviousInput_m)) {
      /* MinMax: '<S17>/MinMax' incorporates:
       *  Switch: '<S22>/Reset'
       */
      rtb_Reset_b = rtb_Merge;
    } else {
      /* Switch: '<S22>/Reset' incorporates:
       *  Memory: '<S22>/Memory'
       *  MinMax: '<S17>/MinMax'
       */
      rtb_Reset_b = top_level_algo_DW.Memory_PreviousInput_m;
    }

    /* End of Switch: '<S22>/Reset' */

    /* Chart: '<S5>/sample and hold1' */
    top_level_algo_sampleandhold(rtb_Reset_b, rtb_AND,
      &top_level_algo_B.Mean1_AccVal, &top_level_algo_DW.sf_sampleandhold1);

    /* Chart: '<S5>/sample and hold' incorporates:
     *  Delay: '<S5>/Delay3'
     *  Logic: '<S5>/AND1'
     *  Logic: '<S5>/NOT1'
     */
    top_level_algo_sampleandhold(rtb_Reset, rtb_LogicalOperator7 &&
      (!top_level_algo_DW.Delay3_DSTATE_m[0]), &top_level_algo_B.Mean1_AccVal,
      &top_level_algo_DW.sf_sampleandhold);

    /* Logic: '<S5>/OR1' incorporates:
     *  Logic: '<S3>/Zero'
     *  Logic: '<S5>/OR'
     */
    rtb_AND = (rtb_IsPos || (!Delay7_DSTATE_tmp));

    /* Logic: '<S5>/NOT2' incorporates:
     *  Logic: '<S5>/OR1'
     */
    rtb_NOT2 = (rtb_AND && Delay7_DSTATE_tmp);

    /* Logic: '<S5>/NOT' incorporates:
     *  Logic: '<S5>/OR'
     */
    rtb_NOT = ((!rtb_IsPos) && rtb_AND);

    /* Sum: '<S3>/30 Diff' incorporates:
     *  Delay: '<S3>/Delay5'
     */
    top_level_algo_B.u0Diff = rtb_Merge - top_level_algo_DW.Delay5_DSTATE[0];

    /* MATLABSystem: '<Root>/Analog Input1' */
    if (top_level_algo_DW.obj.SampleTime !=
        top_level_algo_P.AnalogInput1_SampleTime) {
      top_level_algo_DW.obj.SampleTime =
        top_level_algo_P.AnalogInput1_SampleTime;
    }

    obj = &top_level_algo_DW.obj;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(18UL);

    /* MATLABSystem: '<Root>/Analog Input1' */
    MW_AnalogInSingle_ReadResult
      (top_level_algo_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
       &top_level_algo_B.AnalogInput1, 3);
  }

  {
    int_T i;
    for (i = 0; i < 19; i++) {
      /* Update for S-Function (sfix_udelay): '<S4>/Tapped Delay1' */
      top_level_algo_DW.TappedDelay1_X[i] = top_level_algo_DW.TappedDelay1_X[i +
        1];

      /* Update for S-Function (sfix_udelay): '<S4>/Tapped Delay' */
      top_level_algo_DW.TappedDelay_X_f[i] = top_level_algo_DW.TappedDelay_X_f[i
        + 1];

      /* Update for S-Function (sfix_udelay): '<S3>/Tapped Delay' */
      top_level_algo_DW.TappedDelay_X[i] = top_level_algo_DW.TappedDelay_X[i + 1];
    }

    /* Update for S-Function (sfix_udelay): '<S4>/Tapped Delay1' */
    top_level_algo_DW.TappedDelay1_X[19] = top_level_algo_B.Product;

    /* Update for S-Function (sfix_udelay): '<S4>/Tapped Delay' */
    top_level_algo_DW.TappedDelay_X_f[19] = top_level_algo_B.AnalogInput1;

    /* Update for S-Function (sfix_udelay): '<S3>/Tapped Delay' */
    top_level_algo_DW.TappedDelay_X[19] = top_level_algo_B.u0Diff;

    /* Update for Delay: '<S3>/Delay' */
    top_level_algo_DW.Delay_DSTATE = rtb_Merge;

    /* Update for Delay: '<S3>/Delay1' */
    top_level_algo_DW.Delay1_DSTATE[0] = top_level_algo_DW.Delay1_DSTATE[1];
    top_level_algo_DW.Delay1_DSTATE[1] = rtb_Merge;

    /* Update for Delay: '<S3>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE[0] = top_level_algo_DW.Delay2_DSTATE[1];
    top_level_algo_DW.Delay2_DSTATE[1] = top_level_algo_DW.Delay2_DSTATE[2];
    top_level_algo_DW.Delay2_DSTATE[2] = rtb_Merge;

    /* Update for Delay: '<S3>/Delay3' */
    top_level_algo_DW.Delay3_DSTATE[0] = top_level_algo_DW.Delay3_DSTATE[1];
    top_level_algo_DW.Delay3_DSTATE[1] = top_level_algo_DW.Delay3_DSTATE[2];
    top_level_algo_DW.Delay3_DSTATE[2] = top_level_algo_DW.Delay3_DSTATE[3];
    top_level_algo_DW.Delay3_DSTATE[3] = rtb_Merge;

    /* Update for Delay: '<S3>/Delay4' */
    top_level_algo_DW.Delay4_DSTATE[0] = top_level_algo_DW.Delay4_DSTATE[1];
    top_level_algo_DW.Delay4_DSTATE[1] = top_level_algo_DW.Delay4_DSTATE[2];
    top_level_algo_DW.Delay4_DSTATE[2] = top_level_algo_DW.Delay4_DSTATE[3];
    top_level_algo_DW.Delay4_DSTATE[3] = top_level_algo_DW.Delay4_DSTATE[4];
    top_level_algo_DW.Delay4_DSTATE[4] = rtb_Merge;

    /* Update for Delay: '<S3>/Delay5' */
    for (i = 0; i < 29; i++) {
      top_level_algo_DW.Delay5_DSTATE[i] = top_level_algo_DW.Delay5_DSTATE[i + 1];
    }

    top_level_algo_DW.Delay5_DSTATE[29] = rtb_Merge;

    /* End of Update for Delay: '<S3>/Delay5' */

    /* Update for Delay: '<S5>/Delay4' */
    top_level_algo_DW.Delay4_DSTATE_a[0] = top_level_algo_DW.Delay4_DSTATE_a[1];
    top_level_algo_DW.Delay4_DSTATE_a[1] = rtb_IsNeg;

    /* Update for Delay: '<S5>/Delay3' */
    top_level_algo_DW.Delay3_DSTATE_m[0] = top_level_algo_DW.Delay3_DSTATE_m[1];
    top_level_algo_DW.Delay3_DSTATE_m[1] = rtb_LogicalOperator7;

    /* Update for Memory: '<S21>/Memory' */
    top_level_algo_DW.Memory_PreviousInput = rtb_Reset;

    /* Update for Delay: '<S5>/Delay8' */
    top_level_algo_DW.Delay8_DSTATE[0] = top_level_algo_DW.Delay8_DSTATE[1];
    top_level_algo_DW.Delay8_DSTATE[1] = rtb_IsPos;

    /* Update for Delay: '<S5>/Delay6' */
    top_level_algo_DW.Delay6_DSTATE[0] = top_level_algo_DW.Delay6_DSTATE[1];
    top_level_algo_DW.Delay6_DSTATE[1] = rtb_LogicalOperator3;

    /* Update for Delay: '<S5>/Delay' */
    top_level_algo_DW.Delay_DSTATE_a[0] = top_level_algo_DW.Delay_DSTATE_a[1];

    /* Update for Delay: '<S5>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE_m[0] = top_level_algo_DW.Delay2_DSTATE_m[1];

    /* Update for Delay: '<S5>/Delay' */
    top_level_algo_DW.Delay_DSTATE_a[1] = top_level_algo_DW.Delay_DSTATE_a[2];

    /* Update for Delay: '<S5>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE_m[1] = top_level_algo_DW.Delay2_DSTATE_m[2];

    /* Update for Delay: '<S5>/Delay' */
    top_level_algo_DW.Delay_DSTATE_a[2] = top_level_algo_DW.Delay_DSTATE_a[3];

    /* Update for Delay: '<S5>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE_m[2] = top_level_algo_DW.Delay2_DSTATE_m[3];

    /* Update for Delay: '<S5>/Delay' */
    top_level_algo_DW.Delay_DSTATE_a[3] = top_level_algo_DW.Delay_DSTATE_a[4];

    /* Update for Delay: '<S5>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE_m[3] = top_level_algo_DW.Delay2_DSTATE_m[4];

    /* Update for Delay: '<S5>/Delay' */
    top_level_algo_DW.Delay_DSTATE_a[4] = rtb_NOT;

    /* Update for Delay: '<S5>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE_m[4] = rtb_NOT2;

    /* Update for Memory: '<S22>/Memory' */
    top_level_algo_DW.Memory_PreviousInput_m = rtb_Reset_b;
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
    codertarget_arduinobase_inter_T *obj;
    real_T displacement;
    int16_T i;
    for (i = 0; i < 20; i++) {
      /* InitializeConditions for S-Function (sfix_udelay): '<S4>/Tapped Delay1' */
      top_level_algo_DW.TappedDelay1_X[i] = top_level_algo_P.TappedDelay1_vinit;

      /* InitializeConditions for S-Function (sfix_udelay): '<S4>/Tapped Delay' */
      top_level_algo_DW.TappedDelay_X_f[i] =
        top_level_algo_P.TappedDelay_vinit_l;

      /* InitializeConditions for S-Function (sfix_udelay): '<S3>/Tapped Delay' */
      top_level_algo_DW.TappedDelay_X[i] = top_level_algo_P.TappedDelay_vinit;
    }

    /* InitializeConditions for Delay: '<S3>/Delay' */
    top_level_algo_DW.Delay_DSTATE = top_level_algo_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S3>/Delay1' */
    top_level_algo_DW.Delay1_DSTATE[0] =
      top_level_algo_P.Delay1_InitialCondition;
    top_level_algo_DW.Delay1_DSTATE[1] =
      top_level_algo_P.Delay1_InitialCondition;

    /* InitializeConditions for Delay: '<S3>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE[0] =
      top_level_algo_P.Delay2_InitialCondition;
    top_level_algo_DW.Delay2_DSTATE[1] =
      top_level_algo_P.Delay2_InitialCondition;
    top_level_algo_DW.Delay2_DSTATE[2] =
      top_level_algo_P.Delay2_InitialCondition;

    /* InitializeConditions for Delay: '<S3>/Delay3' */
    top_level_algo_DW.Delay3_DSTATE[0] =
      top_level_algo_P.Delay3_InitialCondition;
    top_level_algo_DW.Delay3_DSTATE[1] =
      top_level_algo_P.Delay3_InitialCondition;
    top_level_algo_DW.Delay3_DSTATE[2] =
      top_level_algo_P.Delay3_InitialCondition;
    top_level_algo_DW.Delay3_DSTATE[3] =
      top_level_algo_P.Delay3_InitialCondition;

    /* InitializeConditions for Delay: '<S3>/Delay4' */
    for (i = 0; i < 5; i++) {
      top_level_algo_DW.Delay4_DSTATE[i] =
        top_level_algo_P.Delay4_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S3>/Delay4' */

    /* InitializeConditions for Delay: '<S3>/Delay5' */
    for (i = 0; i < 30; i++) {
      top_level_algo_DW.Delay5_DSTATE[i] =
        top_level_algo_P.Delay5_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S3>/Delay5' */

    /* InitializeConditions for Delay: '<S5>/Delay1' */
    top_level_algo_DW.Delay1_DSTATE_m =
      top_level_algo_P.Delay1_InitialCondition_d;

    /* InitializeConditions for Delay: '<S5>/Delay4' */
    top_level_algo_DW.Delay4_DSTATE_a[0] =
      top_level_algo_P.Delay4_InitialCondition_f;

    /* InitializeConditions for Delay: '<S5>/Delay3' */
    top_level_algo_DW.Delay3_DSTATE_m[0] =
      top_level_algo_P.Delay3_InitialCondition_k;

    /* InitializeConditions for Delay: '<S5>/Delay4' */
    top_level_algo_DW.Delay4_DSTATE_a[1] =
      top_level_algo_P.Delay4_InitialCondition_f;

    /* InitializeConditions for Delay: '<S5>/Delay3' */
    top_level_algo_DW.Delay3_DSTATE_m[1] =
      top_level_algo_P.Delay3_InitialCondition_k;

    /* InitializeConditions for Memory: '<S21>/Memory' */
    top_level_algo_DW.Memory_PreviousInput = top_level_algo_P.MaxBDC_vinit;

    /* InitializeConditions for Delay: '<S5>/Delay7' */
    top_level_algo_DW.Delay7_DSTATE = top_level_algo_P.Delay7_InitialCondition;

    /* InitializeConditions for Delay: '<S5>/Delay8' */
    top_level_algo_DW.Delay8_DSTATE[0] =
      top_level_algo_P.Delay8_InitialCondition;

    /* InitializeConditions for Delay: '<S5>/Delay6' */
    top_level_algo_DW.Delay6_DSTATE[0] =
      top_level_algo_P.Delay6_InitialCondition;

    /* InitializeConditions for Delay: '<S5>/Delay8' */
    top_level_algo_DW.Delay8_DSTATE[1] =
      top_level_algo_P.Delay8_InitialCondition;

    /* InitializeConditions for Delay: '<S5>/Delay6' */
    top_level_algo_DW.Delay6_DSTATE[1] =
      top_level_algo_P.Delay6_InitialCondition;
    for (i = 0; i < 5; i++) {
      /* InitializeConditions for Delay: '<S5>/Delay' */
      top_level_algo_DW.Delay_DSTATE_a[i] =
        top_level_algo_P.Delay_InitialCondition_d;

      /* InitializeConditions for Delay: '<S5>/Delay2' */
      top_level_algo_DW.Delay2_DSTATE_m[i] =
        top_level_algo_P.Delay2_InitialCondition_c;
    }

    /* InitializeConditions for Memory: '<S22>/Memory' */
    top_level_algo_DW.Memory_PreviousInput_m = top_level_algo_P.MinBDC_vinit;

    /* SystemInitialize for Chart: '<S5>/sample and hold1' */
    top_level_al_sampleandhold_Init(&displacement);

    /* SystemInitialize for Chart: '<S5>/sample and hold' */
    top_level_al_sampleandhold_Init(&displacement);

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
