/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo.c
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 1.90
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Tue Jan 17 16:34:58 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "top_level_algo.h"
#include "top_level_algo_private.h"

/* Named constants for Chart: '<S2>/timer' */
#define top_level_algo_IN_Finished     (1UL)
#define top_level_algo_IN_Starting     (2UL)

/* Named constants for Chart: '<S3>/sample and hold' */
#define top_level_algo_IN_Holding      (1UL)
#define top_level_algo_IN_Init         (2UL)

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
  real_T u;
  real_T u_0;
  real_T u_1;
  real_T u_2;
  int32_T str;
  int32_T str_0;
  int16_T Mean_AccVal_f;
  int16_T n;
  int16_T rtb_measure_period;
  boolean_T Delay7_DSTATE_tmp;
  boolean_T rtb_IsNeg;
  boolean_T rtb_IsPos;
  boolean_T rtb_LogicalOperator7;

  /* Reset subsysRan breadcrumbs */
  srClearBC(top_level_algo_DW.IfActionSubsystem_SubsysRanBC_e);

  /* Reset subsysRan breadcrumbs */
  srClearBC(top_level_algo_DW.IfActionSubsystem1_SubsysRanB_h);

  /* Reset subsysRan breadcrumbs */
  srClearBC(top_level_algo_DW.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(top_level_algo_DW.IfActionSubsystem1_SubsysRanBC);

  /* S-Function (sdspstatfcns): '<S2>/Mean1' incorporates:
   *  S-Function (sfix_udelay): '<S2>/Tapped Delay1'
   */
  top_level_algo_B.Mean1_AccVal = top_level_algo_DW.TappedDelay1_X[0L];
  str = 1L;
  for (n = 18; n >= 0; n--) {
    top_level_algo_B.Mean1_AccVal += top_level_algo_DW.TappedDelay1_X[str];
    str++;
  }

  /* S-Function (sdspstatfcns): '<S2>/Mean1' */
  top_level_algo_B.Mean1 = top_level_algo_B.Mean1_AccVal / 20.0;

  /* Chart: '<S2>/timer' */
  if (top_level_algo_DW.temporalCounter_i1 < 2047U) {
    top_level_algo_DW.temporalCounter_i1++;
  }

  if (top_level_algo_DW.is_active_c3_top_level_algo == 0U) {
    top_level_algo_DW.is_active_c3_top_level_algo = 1U;
    top_level_algo_DW.is_c3_top_level_algo = top_level_algo_IN_Starting;
    top_level_algo_DW.temporalCounter_i1 = 0U;
    rtb_measure_period = 0;
  } else if (top_level_algo_DW.is_c3_top_level_algo ==
             top_level_algo_IN_Finished) {
    rtb_measure_period = 1;
  } else {
    /* case IN_Starting: */
    rtb_measure_period = 0;
    if (top_level_algo_DW.temporalCounter_i1 >= 2000U) {
      top_level_algo_DW.is_c3_top_level_algo = top_level_algo_IN_Finished;
      top_level_algo_B.baseline = top_level_algo_B.Mean1;
      rtb_measure_period = 1;
    }
  }

  /* End of Chart: '<S2>/timer' */

  /* S-Function (sdspstatfcns): '<S2>/Mean' incorporates:
   *  S-Function (sfix_udelay): '<S2>/Tapped Delay'
   */
  Mean_AccVal_f = (int16_T)top_level_algo_DW.TappedDelay_X_f[0L];
  str = 1L;

  /* S-Function (sdspstatfcns): '<S1>/Mean' incorporates:
   *  S-Function (sfix_udelay): '<S1>/Tapped Delay'
   */
  top_level_algo_B.Mean1_AccVal = top_level_algo_DW.TappedDelay_X[0L];
  str_0 = 1L;
  for (n = 18; n >= 0; n--) {
    /* S-Function (sdspstatfcns): '<S2>/Mean' incorporates:
     *  S-Function (sfix_udelay): '<S2>/Tapped Delay'
     */
    Mean_AccVal_f += (int16_T)top_level_algo_DW.TappedDelay_X_f[str];
    str++;

    /* S-Function (sdspstatfcns): '<S1>/Mean' incorporates:
     *  S-Function (sfix_udelay): '<S1>/Tapped Delay'
     */
    top_level_algo_B.Mean1_AccVal += top_level_algo_DW.TappedDelay_X[str_0];
    str_0++;
  }

  /* S-Function (sdspstatfcns): '<S1>/Mean' */
  top_level_algo_B.Mean1_AccVal /= 20.0;

  /* Product: '<S2>/Product' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Product: '<S2>/Divide'
   *  S-Function (sdspstatfcns): '<S2>/Mean'
   */
  top_level_algo_B.Product = (real_T)(uint16_T)div_nde_s32_floor(Mean_AccVal_f,
    20L) / top_level_algo_P.Constant1_Value * top_level_algo_P.Constant_Value;

  /* Switch: '<S2>/Switch' */
  if (rtb_measure_period > top_level_algo_P.Switch_Threshold) {
    top_level_algo_B.MajorityVoterSlope = top_level_algo_B.baseline;
  } else {
    top_level_algo_B.MajorityVoterSlope = top_level_algo_B.Product;
  }

  /* End of Switch: '<S2>/Switch' */

  /* Gain: '<S2>/Radius (mm)' incorporates:
   *  Gain: '<S2>/Convert to Radians'
   *  Gain: '<S2>/degrees per volt'
   *  Sum: '<S2>/Subtract'
   */
  top_level_algo_B.Merge = (top_level_algo_B.MajorityVoterSlope -
    top_level_algo_B.Product) * top_level_algo_P.degreespervolt_Gain *
    top_level_algo_P.ConverttoRadians_Gain * top_level_algo_P.Radiusmm_Gain;

  /* If: '<S8>/If' */
  if (top_level_algo_B.Merge < 0.0) {
    /* Outputs for IfAction SubSystem: '<S8>/If Action Subsystem' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* Gain: '<S2>/Radius (mm)' incorporates:
     *  Constant: '<S8>/Constant'
     *  Inport: '<S10>/In1'
     *  Merge: '<S8>/Merge'
     */
    top_level_algo_B.Merge = top_level_algo_P.Constant_Value_a;

    /* End of Outputs for SubSystem: '<S8>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<S8>/If Action Subsystem' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* Update for If: '<S8>/If' */
    srUpdateBC(top_level_algo_DW.IfActionSubsystem_SubsysRanBC_e);

    /* End of Update for SubSystem: '<S8>/If Action Subsystem' */
  } else {
    /* Update for IfAction SubSystem: '<S8>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    /* Update for If: '<S8>/If' */
    srUpdateBC(top_level_algo_DW.IfActionSubsystem1_SubsysRanB_h);

    /* End of Update for SubSystem: '<S8>/If Action Subsystem1' */
  }

  /* End of If: '<S8>/If' */

  /* Sum: '<S1>/First Diff' incorporates:
   *  Delay: '<S1>/Delay'
   */
  top_level_algo_B.MajorityVoterSlope = top_level_algo_B.Merge -
    top_level_algo_DW.Delay_DSTATE;

  /* Sum: '<S1>/Second Diff' incorporates:
   *  Delay: '<S1>/Delay'
   *  Delay: '<S1>/Delay1'
   */
  top_level_algo_B.u = top_level_algo_DW.Delay_DSTATE -
    top_level_algo_DW.Delay1_DSTATE[0];

  /* Sum: '<S1>/Third Diff' incorporates:
   *  Delay: '<S1>/Delay1'
   *  Delay: '<S1>/Delay2'
   */
  u = top_level_algo_DW.Delay1_DSTATE[0] - top_level_algo_DW.Delay2_DSTATE[0];

  /* Sum: '<S1>/Fourth Diff' incorporates:
   *  Delay: '<S1>/Delay2'
   *  Delay: '<S1>/Delay3'
   */
  u_0 = top_level_algo_DW.Delay2_DSTATE[0] - top_level_algo_DW.Delay3_DSTATE[0];

  /* Sum: '<S1>/Fifth Diff' incorporates:
   *  Delay: '<S1>/Delay3'
   *  Delay: '<S1>/Delay4'
   */
  u_1 = top_level_algo_DW.Delay3_DSTATE[0] - top_level_algo_DW.Delay4_DSTATE[0];

  /* Sum: '<S1>/5to30 Diff' incorporates:
   *  Delay: '<S1>/Delay4'
   *  Delay: '<S1>/Delay5'
   */
  u_2 = top_level_algo_DW.Delay4_DSTATE[0] - top_level_algo_DW.Delay5_DSTATE[0];

  /* Signum: '<S1>/Sign' */
  if (top_level_algo_B.MajorityVoterSlope < 0.0) {
    top_level_algo_B.MajorityVoterSlope = -1.0;
  } else if (top_level_algo_B.MajorityVoterSlope > 0.0) {
    top_level_algo_B.MajorityVoterSlope = 1.0;
  } else if (top_level_algo_B.MajorityVoterSlope == 0.0) {
    top_level_algo_B.MajorityVoterSlope = 0.0;
  } else {
    top_level_algo_B.MajorityVoterSlope = (rtNaN);
  }

  /* End of Signum: '<S1>/Sign' */

  /* Signum: '<S1>/Sign1' */
  if (top_level_algo_B.u < 0.0) {
    top_level_algo_B.u = -1.0;
  } else if (top_level_algo_B.u > 0.0) {
    top_level_algo_B.u = 1.0;
  } else if (top_level_algo_B.u == 0.0) {
    top_level_algo_B.u = 0.0;
  } else {
    top_level_algo_B.u = (rtNaN);
  }

  /* End of Signum: '<S1>/Sign1' */

  /* Signum: '<S1>/Sign2' */
  if (u < 0.0) {
    u = -1.0;
  } else if (u > 0.0) {
    u = 1.0;
  } else if (u == 0.0) {
    u = 0.0;
  } else {
    u = (rtNaN);
  }

  /* End of Signum: '<S1>/Sign2' */

  /* Signum: '<S1>/Sign3' */
  if (u_0 < 0.0) {
    u_0 = -1.0;
  } else if (u_0 > 0.0) {
    u_0 = 1.0;
  } else if (u_0 == 0.0) {
    u_0 = 0.0;
  } else {
    u_0 = (rtNaN);
  }

  /* End of Signum: '<S1>/Sign3' */

  /* Signum: '<S1>/Sign4' */
  if (u_1 < 0.0) {
    u_1 = -1.0;
  } else if (u_1 > 0.0) {
    u_1 = 1.0;
  } else if (u_1 == 0.0) {
    u_1 = 0.0;
  } else {
    u_1 = (rtNaN);
  }

  /* End of Signum: '<S1>/Sign4' */

  /* Signum: '<S1>/Sign5' */
  if (u_2 < 0.0) {
    u_2 = -1.0;
  } else if (u_2 > 0.0) {
    u_2 = 1.0;
  } else if (u_2 == 0.0) {
    u_2 = 0.0;
  } else {
    u_2 = (rtNaN);
  }

  /* End of Signum: '<S1>/Sign5' */

  /* Sum: '<S1>/Add' incorporates:
   *  Gain: '<S1>/Gain'
   *  Gain: '<S1>/Gain1'
   */
  top_level_algo_B.MajorityVoterSlope = ((((top_level_algo_P.Gain_Gain *
    top_level_algo_B.MajorityVoterSlope + top_level_algo_P.Gain1_Gain *
    top_level_algo_B.u) + u) + u_0) + u_1) + u_2;

  /* Logic: '<S1>/AND' incorporates:
   *  Constant: '<S5>/Constant'
   *  Constant: '<S7>/Constant'
   *  RelationalOperator: '<S5>/Compare'
   *  RelationalOperator: '<S7>/Compare'
   */
  rtb_IsPos = ((top_level_algo_B.MajorityVoterSlope >=
                top_level_algo_P.Positive_const) &&
               (top_level_algo_B.Mean1_AccVal >=
                top_level_algo_P.Longrangemotionup_const));

  /* Logic: '<S3>/Logical Operator5' incorporates:
   *  Delay: '<S3>/Delay1'
   *  Delay: '<S3>/Delay4'
   *  Logic: '<S3>/Logical Operator4'
   *  Logic: '<S3>/Logical Operator6'
   */
  top_level_algo_DW.Delay1_DSTATE_m = ((!rtb_IsPos) &&
    (top_level_algo_DW.Delay4_DSTATE_a[0] || top_level_algo_DW.Delay1_DSTATE_m));

  /* Logic: '<S1>/AND1' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S6>/Constant'
   *  RelationalOperator: '<S4>/Compare'
   *  RelationalOperator: '<S6>/Compare'
   */
  rtb_IsNeg = ((top_level_algo_B.MajorityVoterSlope <=
                top_level_algo_P.Negative_const) &&
               (top_level_algo_B.Mean1_AccVal <=
                top_level_algo_P.Longrangemotiondown_const));

  /* Logic: '<S3>/Logical Operator7' incorporates:
   *  Delay: '<S3>/Delay1'
   *  Logic: '<S3>/NOT5'
   */
  rtb_LogicalOperator7 = (rtb_IsNeg && (!top_level_algo_DW.Delay1_DSTATE_m));

  /* Logic: '<S3>/AND1' incorporates:
   *  Delay: '<S3>/Delay3'
   *  Logic: '<S3>/NOT1'
   */
  top_level_algo_B.AND1 = (rtb_LogicalOperator7 &&
    (!top_level_algo_DW.Delay3_DSTATE_m[0]));

  /* Switch: '<S17>/Reset' incorporates:
   *  Delay: '<S3>/Delay'
   *  Memory: '<S17>/Memory'
   *  MinMax: '<S12>/MinMax'
   */
  if (top_level_algo_DW.Delay_DSTATE_a[0U]) {
    /* Switch: '<S17>/Reset' incorporates:
     *  Constant: '<S17>/Initial Condition'
     */
    top_level_algo_B.Reset = top_level_algo_P.MaxBDC_vinit;
  } else if ((top_level_algo_B.Merge >= top_level_algo_B.Reset) || rtIsNaN
             (top_level_algo_B.Reset)) {
    /* MinMax: '<S12>/MinMax' incorporates:
     *  Switch: '<S17>/Reset'
     */
    top_level_algo_B.Reset = top_level_algo_B.Merge;
  }

  /* End of Switch: '<S17>/Reset' */

  /* Chart: '<S3>/sample and hold' */
  if (top_level_algo_DW.is_active_c1_top_level_algo == 0U) {
    top_level_algo_DW.is_active_c1_top_level_algo = 1U;
    top_level_algo_DW.is_c1_top_level_algo = top_level_algo_IN_Init;
    top_level_algo_B.displacement_a = 0.0;
  } else if (top_level_algo_DW.is_c1_top_level_algo == top_level_algo_IN_Holding)
  {
    if (top_level_algo_B.AND1) {
      top_level_algo_DW.is_c1_top_level_algo = top_level_algo_IN_Holding;
      top_level_algo_B.displacement_a = top_level_algo_B.Reset;
    }

    /* case IN_Init: */
  } else if (top_level_algo_B.AND1) {
    top_level_algo_DW.is_c1_top_level_algo = top_level_algo_IN_Holding;
    top_level_algo_B.displacement_a = top_level_algo_B.Reset;
  }

  /* End of Chart: '<S3>/sample and hold' */

  /* Logic: '<S3>/Logical Operator' incorporates:
   *  Logic: '<S1>/Zero'
   *  Logic: '<S3>/OR1'
   */
  Delay7_DSTATE_tmp = !rtb_IsNeg;

  /* Logic: '<S3>/Logical Operator1' incorporates:
   *  Delay: '<S3>/Delay7'
   *  Delay: '<S3>/Delay8'
   *  Logic: '<S3>/Logical Operator'
   *  Logic: '<S3>/Logical Operator2'
   */
  top_level_algo_DW.Delay7_DSTATE = (Delay7_DSTATE_tmp &&
    (top_level_algo_DW.Delay8_DSTATE[0] || top_level_algo_DW.Delay7_DSTATE));

  /* Logic: '<S3>/Logical Operator3' incorporates:
   *  Delay: '<S3>/Delay7'
   *  Logic: '<S3>/NOT4'
   */
  top_level_algo_B.LogicalOperator3 = (rtb_IsPos &&
    (!top_level_algo_DW.Delay7_DSTATE));

  /* Logic: '<S3>/AND' incorporates:
   *  Delay: '<S3>/Delay6'
   *  Logic: '<S3>/NOT3'
   */
  top_level_algo_B.AND = (top_level_algo_B.LogicalOperator3 &&
    (!top_level_algo_DW.Delay6_DSTATE[0]));

  /* Switch: '<S18>/Reset' incorporates:
   *  Delay: '<S3>/Delay2'
   *  Memory: '<S18>/Memory'
   *  MinMax: '<S13>/MinMax'
   */
  if (top_level_algo_DW.Delay2_DSTATE_m[0U]) {
    /* Switch: '<S18>/Reset' incorporates:
     *  Constant: '<S18>/Initial Condition'
     */
    top_level_algo_B.Reset_b = top_level_algo_P.MinBDC_vinit;
  } else if ((top_level_algo_B.Merge <= top_level_algo_DW.Memory_PreviousInput_m)
             || rtIsNaN(top_level_algo_DW.Memory_PreviousInput_m)) {
    /* MinMax: '<S13>/MinMax' incorporates:
     *  Switch: '<S18>/Reset'
     */
    top_level_algo_B.Reset_b = top_level_algo_B.Merge;
  } else {
    /* Switch: '<S18>/Reset' incorporates:
     *  Memory: '<S18>/Memory'
     *  MinMax: '<S13>/MinMax'
     */
    top_level_algo_B.Reset_b = top_level_algo_DW.Memory_PreviousInput_m;
  }

  /* End of Switch: '<S18>/Reset' */

  /* Chart: '<S3>/sample and hold1' */
  if (top_level_algo_DW.is_active_c2_top_level_algo == 0U) {
    top_level_algo_DW.is_active_c2_top_level_algo = 1U;
    top_level_algo_DW.is_c2_top_level_algo = top_level_algo_IN_Init;
    top_level_algo_B.displacement = 0.0;
  } else if (top_level_algo_DW.is_c2_top_level_algo == top_level_algo_IN_Holding)
  {
    if (top_level_algo_B.AND) {
      top_level_algo_DW.is_c2_top_level_algo = top_level_algo_IN_Holding;
      top_level_algo_B.displacement = top_level_algo_B.Reset_b;
    }

    /* case IN_Init: */
  } else if (top_level_algo_B.AND) {
    top_level_algo_DW.is_c2_top_level_algo = top_level_algo_IN_Holding;
    top_level_algo_B.displacement = top_level_algo_B.Reset_b;
  }

  /* End of Chart: '<S3>/sample and hold1' */

  /* If: '<S14>/If' */
  if (top_level_algo_B.displacement < 0.0) {
    /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem' incorporates:
     *  ActionPort: '<S19>/Action Port'
     */
    /* Merge: '<S14>/Merge' incorporates:
     *  Constant: '<S14>/Constant'
     *  Inport: '<S19>/In1'
     */
    top_level_algo_B.Merge_k = top_level_algo_P.Constant_Value_i;

    /* End of Outputs for SubSystem: '<S14>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<S14>/If Action Subsystem' incorporates:
     *  ActionPort: '<S19>/Action Port'
     */
    /* Update for If: '<S14>/If' */
    srUpdateBC(top_level_algo_DW.IfActionSubsystem_SubsysRanBC);

    /* End of Update for SubSystem: '<S14>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S20>/Action Port'
     */
    /* Merge: '<S14>/Merge' incorporates:
     *  Inport: '<S20>/In1'
     */
    top_level_algo_B.Merge_k = top_level_algo_B.displacement;

    /* End of Outputs for SubSystem: '<S14>/If Action Subsystem1' */

    /* Update for IfAction SubSystem: '<S14>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S20>/Action Port'
     */
    /* Update for If: '<S14>/If' */
    srUpdateBC(top_level_algo_DW.IfActionSubsystem1_SubsysRanBC);

    /* End of Update for SubSystem: '<S14>/If Action Subsystem1' */
  }

  /* End of If: '<S14>/If' */
  /* Sum: '<S1>/30 Diff' incorporates:
   *  Delay: '<S1>/Delay5'
   */
  top_level_algo_B.u0Diff = top_level_algo_B.Merge -
    top_level_algo_DW.Delay5_DSTATE[0];

  /* MATLABSystem: '<Root>/Analog Input1' */
  if (top_level_algo_DW.obj.SampleTime !=
      top_level_algo_P.AnalogInput1_SampleTime) {
    top_level_algo_DW.obj.SampleTime = top_level_algo_P.AnalogInput1_SampleTime;
  }

  obj = &top_level_algo_DW.obj;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(14UL);

  /* MATLABSystem: '<Root>/Analog Input1' */
  MW_AnalogInSingle_ReadResult
    (top_level_algo_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &top_level_algo_B.AnalogInput1, 3);
  for (n = 0; n < 19; n++) {
    /* Update for S-Function (sfix_udelay): '<S2>/Tapped Delay1' */
    top_level_algo_DW.TappedDelay1_X[n] = top_level_algo_DW.TappedDelay1_X[n + 1];

    /* Update for S-Function (sfix_udelay): '<S2>/Tapped Delay' */
    top_level_algo_DW.TappedDelay_X_f[n] = top_level_algo_DW.TappedDelay_X_f[n +
      1];

    /* Update for S-Function (sfix_udelay): '<S1>/Tapped Delay' */
    top_level_algo_DW.TappedDelay_X[n] = top_level_algo_DW.TappedDelay_X[n + 1];
  }

  /* Update for S-Function (sfix_udelay): '<S2>/Tapped Delay1' */
  top_level_algo_DW.TappedDelay1_X[19] = top_level_algo_B.Product;

  /* Update for S-Function (sfix_udelay): '<S2>/Tapped Delay' */
  top_level_algo_DW.TappedDelay_X_f[19] = top_level_algo_B.AnalogInput1;

  /* Update for S-Function (sfix_udelay): '<S1>/Tapped Delay' */
  top_level_algo_DW.TappedDelay_X[19] = top_level_algo_B.u0Diff;

  /* Update for Delay: '<S1>/Delay' */
  top_level_algo_DW.Delay_DSTATE = top_level_algo_B.Merge;

  /* Update for Delay: '<S1>/Delay1' */
  top_level_algo_DW.Delay1_DSTATE[0] = top_level_algo_DW.Delay1_DSTATE[1];
  top_level_algo_DW.Delay1_DSTATE[1] = top_level_algo_B.Merge;

  /* Update for Delay: '<S1>/Delay2' */
  top_level_algo_DW.Delay2_DSTATE[0] = top_level_algo_DW.Delay2_DSTATE[1];
  top_level_algo_DW.Delay2_DSTATE[1] = top_level_algo_DW.Delay2_DSTATE[2];
  top_level_algo_DW.Delay2_DSTATE[2] = top_level_algo_B.Merge;

  /* Update for Delay: '<S1>/Delay3' */
  top_level_algo_DW.Delay3_DSTATE[0] = top_level_algo_DW.Delay3_DSTATE[1];
  top_level_algo_DW.Delay3_DSTATE[1] = top_level_algo_DW.Delay3_DSTATE[2];
  top_level_algo_DW.Delay3_DSTATE[2] = top_level_algo_DW.Delay3_DSTATE[3];
  top_level_algo_DW.Delay3_DSTATE[3] = top_level_algo_B.Merge;

  /* Update for Delay: '<S1>/Delay4' */
  top_level_algo_DW.Delay4_DSTATE[0] = top_level_algo_DW.Delay4_DSTATE[1];
  top_level_algo_DW.Delay4_DSTATE[1] = top_level_algo_DW.Delay4_DSTATE[2];
  top_level_algo_DW.Delay4_DSTATE[2] = top_level_algo_DW.Delay4_DSTATE[3];
  top_level_algo_DW.Delay4_DSTATE[3] = top_level_algo_DW.Delay4_DSTATE[4];
  top_level_algo_DW.Delay4_DSTATE[4] = top_level_algo_B.Merge;

  /* Update for Delay: '<S1>/Delay5' */
  for (n = 0; n < 29; n++) {
    top_level_algo_DW.Delay5_DSTATE[n] = top_level_algo_DW.Delay5_DSTATE[n + 1];
  }

  top_level_algo_DW.Delay5_DSTATE[29] = top_level_algo_B.Merge;

  /* End of Update for Delay: '<S1>/Delay5' */

  /* Update for Delay: '<S3>/Delay4' */
  top_level_algo_DW.Delay4_DSTATE_a[0] = top_level_algo_DW.Delay4_DSTATE_a[1];
  top_level_algo_DW.Delay4_DSTATE_a[1] = rtb_IsNeg;

  /* Update for Delay: '<S3>/Delay3' */
  top_level_algo_DW.Delay3_DSTATE_m[0] = top_level_algo_DW.Delay3_DSTATE_m[1];
  top_level_algo_DW.Delay3_DSTATE_m[1] = rtb_LogicalOperator7;

  /* Update for Delay: '<S3>/Delay8' */
  top_level_algo_DW.Delay8_DSTATE[0] = top_level_algo_DW.Delay8_DSTATE[1];
  top_level_algo_DW.Delay8_DSTATE[1] = rtb_IsPos;

  /* Update for Delay: '<S3>/Delay6' */
  top_level_algo_DW.Delay6_DSTATE[0] = top_level_algo_DW.Delay6_DSTATE[1];
  top_level_algo_DW.Delay6_DSTATE[1] = top_level_algo_B.LogicalOperator3;

  /* Update for Delay: '<S3>/Delay' */
  top_level_algo_DW.Delay_DSTATE_a[0] = top_level_algo_DW.Delay_DSTATE_a[1];

  /* Update for Delay: '<S3>/Delay2' */
  top_level_algo_DW.Delay2_DSTATE_m[0] = top_level_algo_DW.Delay2_DSTATE_m[1];

  /* Update for Delay: '<S3>/Delay' */
  top_level_algo_DW.Delay_DSTATE_a[1] = top_level_algo_DW.Delay_DSTATE_a[2];

  /* Update for Delay: '<S3>/Delay2' */
  top_level_algo_DW.Delay2_DSTATE_m[1] = top_level_algo_DW.Delay2_DSTATE_m[2];

  /* Update for Delay: '<S3>/Delay' */
  top_level_algo_DW.Delay_DSTATE_a[2] = top_level_algo_DW.Delay_DSTATE_a[3];

  /* Update for Delay: '<S3>/Delay2' */
  top_level_algo_DW.Delay2_DSTATE_m[2] = top_level_algo_DW.Delay2_DSTATE_m[3];

  /* Update for Delay: '<S3>/Delay' */
  top_level_algo_DW.Delay_DSTATE_a[3] = top_level_algo_DW.Delay_DSTATE_a[4];

  /* Update for Delay: '<S3>/Delay2' */
  top_level_algo_DW.Delay2_DSTATE_m[3] = top_level_algo_DW.Delay2_DSTATE_m[4];

  /* Logic: '<S3>/OR' incorporates:
   *  Logic: '<S1>/Zero'
   *  Logic: '<S3>/OR1'
   */
  rtb_IsNeg = (rtb_IsPos || (!Delay7_DSTATE_tmp));

  /* Update for Delay: '<S3>/Delay' incorporates:
   *  Logic: '<S3>/NOT'
   *  Logic: '<S3>/OR'
   */
  top_level_algo_DW.Delay_DSTATE_a[4] = ((!rtb_IsPos) && rtb_IsNeg);

  /* Update for Delay: '<S3>/Delay2' incorporates:
   *  Logic: '<S3>/NOT2'
   *  Logic: '<S3>/OR1'
   */
  top_level_algo_DW.Delay2_DSTATE_m[4] = (rtb_IsNeg && Delay7_DSTATE_tmp);

  /* Update for Memory: '<S18>/Memory' */
  top_level_algo_DW.Memory_PreviousInput_m = top_level_algo_B.Reset_b;

  {                                    /* Sample time: [0.001s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  top_level_algo_M->Timing.taskTime0 =
    ((time_T)(++top_level_algo_M->Timing.clockTick0)) *
    top_level_algo_M->Timing.stepSize0;
}

/* Model initialize function */
void top_level_algo_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(top_level_algo_M, -1);
  top_level_algo_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  top_level_algo_M->Sizes.checksums[0] = (110816815U);
  top_level_algo_M->Sizes.checksums[1] = (3497474922U);
  top_level_algo_M->Sizes.checksums[2] = (2918552220U);
  top_level_algo_M->Sizes.checksums[3] = (1173729265U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[13];
    top_level_algo_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem_SubsysRanBC_e;
    systemRan[3] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem1_SubsysRanB_h;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(top_level_algo_M->extModeInfo,
      &top_level_algo_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(top_level_algo_M->extModeInfo,
                        top_level_algo_M->Sizes.checksums);
    rteiSetTPtr(top_level_algo_M->extModeInfo, rtmGetTPtr(top_level_algo_M));
  }

  {
    codertarget_arduinobase_inter_T *obj;
    int16_T i;
    for (i = 0; i < 20; i++) {
      /* InitializeConditions for S-Function (sfix_udelay): '<S2>/Tapped Delay1' */
      top_level_algo_DW.TappedDelay1_X[i] = top_level_algo_P.TappedDelay1_vinit;

      /* InitializeConditions for S-Function (sfix_udelay): '<S2>/Tapped Delay' */
      top_level_algo_DW.TappedDelay_X_f[i] =
        top_level_algo_P.TappedDelay_vinit_l;

      /* InitializeConditions for S-Function (sfix_udelay): '<S1>/Tapped Delay' */
      top_level_algo_DW.TappedDelay_X[i] = top_level_algo_P.TappedDelay_vinit;
    }

    /* InitializeConditions for Delay: '<S1>/Delay' */
    top_level_algo_DW.Delay_DSTATE = top_level_algo_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S1>/Delay1' */
    top_level_algo_DW.Delay1_DSTATE[0] =
      top_level_algo_P.Delay1_InitialCondition;
    top_level_algo_DW.Delay1_DSTATE[1] =
      top_level_algo_P.Delay1_InitialCondition;

    /* InitializeConditions for Delay: '<S1>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE[0] =
      top_level_algo_P.Delay2_InitialCondition;
    top_level_algo_DW.Delay2_DSTATE[1] =
      top_level_algo_P.Delay2_InitialCondition;
    top_level_algo_DW.Delay2_DSTATE[2] =
      top_level_algo_P.Delay2_InitialCondition;

    /* InitializeConditions for Delay: '<S1>/Delay3' */
    top_level_algo_DW.Delay3_DSTATE[0] =
      top_level_algo_P.Delay3_InitialCondition;
    top_level_algo_DW.Delay3_DSTATE[1] =
      top_level_algo_P.Delay3_InitialCondition;
    top_level_algo_DW.Delay3_DSTATE[2] =
      top_level_algo_P.Delay3_InitialCondition;
    top_level_algo_DW.Delay3_DSTATE[3] =
      top_level_algo_P.Delay3_InitialCondition;

    /* InitializeConditions for Delay: '<S1>/Delay4' */
    for (i = 0; i < 5; i++) {
      top_level_algo_DW.Delay4_DSTATE[i] =
        top_level_algo_P.Delay4_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S1>/Delay4' */

    /* InitializeConditions for Delay: '<S1>/Delay5' */
    for (i = 0; i < 30; i++) {
      top_level_algo_DW.Delay5_DSTATE[i] =
        top_level_algo_P.Delay5_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S1>/Delay5' */

    /* InitializeConditions for Delay: '<S3>/Delay1' */
    top_level_algo_DW.Delay1_DSTATE_m =
      top_level_algo_P.Delay1_InitialCondition_d;

    /* InitializeConditions for Delay: '<S3>/Delay4' */
    top_level_algo_DW.Delay4_DSTATE_a[0] =
      top_level_algo_P.Delay4_InitialCondition_f;

    /* InitializeConditions for Delay: '<S3>/Delay3' */
    top_level_algo_DW.Delay3_DSTATE_m[0] =
      top_level_algo_P.Delay3_InitialCondition_k;

    /* InitializeConditions for Delay: '<S3>/Delay4' */
    top_level_algo_DW.Delay4_DSTATE_a[1] =
      top_level_algo_P.Delay4_InitialCondition_f;

    /* InitializeConditions for Delay: '<S3>/Delay3' */
    top_level_algo_DW.Delay3_DSTATE_m[1] =
      top_level_algo_P.Delay3_InitialCondition_k;

    /* InitializeConditions for Memory: '<S17>/Memory' */
    top_level_algo_B.Reset = top_level_algo_P.MaxBDC_vinit;

    /* InitializeConditions for Delay: '<S3>/Delay7' */
    top_level_algo_DW.Delay7_DSTATE = top_level_algo_P.Delay7_InitialCondition;

    /* InitializeConditions for Delay: '<S3>/Delay8' */
    top_level_algo_DW.Delay8_DSTATE[0] =
      top_level_algo_P.Delay8_InitialCondition;

    /* InitializeConditions for Delay: '<S3>/Delay6' */
    top_level_algo_DW.Delay6_DSTATE[0] =
      top_level_algo_P.Delay6_InitialCondition;

    /* InitializeConditions for Delay: '<S3>/Delay8' */
    top_level_algo_DW.Delay8_DSTATE[1] =
      top_level_algo_P.Delay8_InitialCondition;

    /* InitializeConditions for Delay: '<S3>/Delay6' */
    top_level_algo_DW.Delay6_DSTATE[1] =
      top_level_algo_P.Delay6_InitialCondition;
    for (i = 0; i < 5; i++) {
      /* InitializeConditions for Delay: '<S3>/Delay' */
      top_level_algo_DW.Delay_DSTATE_a[i] =
        top_level_algo_P.Delay_InitialCondition_d;

      /* InitializeConditions for Delay: '<S3>/Delay2' */
      top_level_algo_DW.Delay2_DSTATE_m[i] =
        top_level_algo_P.Delay2_InitialCondition_c;
    }

    /* InitializeConditions for Memory: '<S18>/Memory' */
    top_level_algo_DW.Memory_PreviousInput_m = top_level_algo_P.MinBDC_vinit;

    /* Start for MATLABSystem: '<Root>/Analog Input1' */
    top_level_algo_DW.obj.matlabCodegenIsDeleted = true;
    top_level_algo_DW.obj.isInitialized = 0L;
    top_level_algo_DW.obj.SampleTime = -1.0;
    top_level_algo_DW.obj.matlabCodegenIsDeleted = false;
    top_level_algo_DW.obj.SampleTime = top_level_algo_P.AnalogInput1_SampleTime;
    obj = &top_level_algo_DW.obj;
    top_level_algo_DW.obj.isSetupComplete = false;
    top_level_algo_DW.obj.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(14UL);
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
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(14UL);
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
