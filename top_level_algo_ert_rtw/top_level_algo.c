/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo.c
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 3.24
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Mar 20 18:53:51 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "top_level_algo.h"
#include "rtwtypes.h"
#include "top_level_algo_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <float.h>

/* Named constants for Chart: '<S2>/DataLogic' */
#define top_level_algo_IN_CHECK        (1U)
#define top_level_algo_IN_HOLD         (2U)
#define top_level_algo_IN_LOAD         (3U)
#define top_level_algo_IN_MASK         (4U)
#define top_level_algo_IN_START        (5U)
#define top_level_algo_IN_WAITING      (6U)
#define top_level_algo_IN_Wait         (7U)
#define top_level_algo_clk_period      (80.0)

/* Block signals (default storage) */
B_top_level_algo_T top_level_algo_B;

/* Block states (default storage) */
DW_top_level_algo_T top_level_algo_DW;

/* Real-time model */
static RT_MODEL_top_level_algo_T top_level_algo_M_;
RT_MODEL_top_level_algo_T *const top_level_algo_M = &top_level_algo_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void top_level_algo_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(top_level_algo_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  top_level_algo_M->Timing.RateInteraction.TID0_1 =
    (top_level_algo_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (top_level_algo_M->Timing.TaskCounters.TID[1])++;
  if ((top_level_algo_M->Timing.TaskCounters.TID[1]) > 39) {/* Sample time: [0.04s, 0.0s] */
    top_level_algo_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for action system:
 *    '<S3>/If Action Subsystem'
 *    '<S3>/If Action Subsystem1'
 *    '<S3>/If Action Subsystem2'
 *    '<S3>/If Action Subsystem3'
 *    '<S3>/If Action Subsystem4'
 *    '<S3>/If Action Subsystem5'
 *    '<S3>/If Action Subsystem6'
 *    '<S3>/If Action Subsystem7'
 *    '<S3>/If Action Subsystem8'
 *    '<S3>/If Action Subsystem10'
 *    ...
 */
void top_level_IfActionSubsystem(uint8_T *rty_Out1,
  P_IfActionSubsystem_top_level_T *localP)
{
  /* SignalConversion generated from: '<S6>/Out1' incorporates:
   *  Constant: '<S6>/Constant'
   */
  *rty_Out1 = localP->Constant_Value;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
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

/* Model step function for TID0 */
void top_level_algo_step0(void)        /* Sample time: [0.001s, 0.0s] */
{
  real_T rtb_DividebyConstantandRound;
  real_T rtb_Mod1;
  real_T rtb_TmpMLSysMemLayoutBufferAt_k;
  real_T tmp_0;
  int_T idxDelay;
  uint32_T tmp;
  uint8_T Merge;
  uint8_T Merge_m;
  uint8_T Merge_n;
  boolean_T rtb_LogicalOperator;

  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(top_level_algo_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC);

  /* Logic: '<S2>/Logical Operator' incorporates:
   *  Delay: '<S2>/Delay'
   */
  rtb_LogicalOperator = !(top_level_algo_DW.Delay_DSTATE[0] != 0.0);

  /* Logic: '<S2>/Logical Operator1' incorporates:
   *  Delay: '<S2>/Delay7'
   *  Delay: '<S2>/Delay8'
   *  Logic: '<S2>/Logical Operator2'
   *  Logic: '<S2>/NOT'
   */
  top_level_algo_DW.Delay7_DSTATE = (rtb_LogicalOperator &&
    ((!top_level_algo_DW.Delay8_DSTATE[0]) || top_level_algo_DW.Delay7_DSTATE));

  /* Logic: '<S2>/NOT1' incorporates:
   *  Delay: '<S2>/Delay7'
   */
  top_level_algo_B.NOT1 = !top_level_algo_DW.Delay7_DSTATE;

  /* RateTransition generated from: '<S2>/Switch' */
  if (top_level_algo_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition generated from: '<S2>/Switch' */
    top_level_algo_B.TmpRTBAtSwitchInport1 =
      top_level_algo_DW.TmpRTBAtSwitchInport1_Buffer0;
  }

  /* End of RateTransition generated from: '<S2>/Switch' */

  /* Switch: '<S2>/Switch' */
  if (top_level_algo_B.NOT1) {
    /* Switch: '<S2>/Switch' */
    top_level_algo_B.CLK = top_level_algo_B.TmpRTBAtSwitchInport1;
  } else {
    /* Switch: '<S2>/Switch' incorporates:
     *  Constant: '<S2>/Constant'
     */
    top_level_algo_B.CLK = top_level_algo_P.Constant_Value;
  }

  /* End of Switch: '<S2>/Switch' */

  /* MATLABSystem: '<Root>/Digital Output2' */
  tmp_0 = rt_roundd_snf(top_level_algo_B.CLK);
  if (tmp_0 < 256.0) {
    if (tmp_0 >= 0.0) {
      Merge = (uint8_T)tmp_0;
    } else {
      Merge = 0U;
    }
  } else {
    Merge = MAX_uint8_T;
  }

  writeDigitalPin(25, Merge);

  /* End of MATLABSystem: '<Root>/Digital Output2' */
  /* Math: '<S1>/Mod' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Constant: '<S1>/Constant1'
   */
  rtb_TmpMLSysMemLayoutBufferAt_k = rt_modd_snf(top_level_algo_P.Constant5_Value,
    top_level_algo_P.Constant1_Value_h);

  /* MATLABSystem: '<S1>/Divide by Constant and Round' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Sum: '<S1>/Subtract'
   */
  rtb_DividebyConstantandRound = floor((top_level_algo_P.Constant5_Value -
    rtb_TmpMLSysMemLayoutBufferAt_k) * 0.01);

  /* SwitchCase: '<S5>/Switch Case' incorporates:
   *  SignalConversion generated from: '<S1>/Divide by Constant and Round'
   */
  if (rtIsNaN(rtb_DividebyConstantandRound) || rtIsInf
      (rtb_DividebyConstantandRound)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(rtb_DividebyConstantandRound, 4.294967296E+9);
  }

  switch (tmp_0 < 0.0 ? -(int32_T)(uint32_T)-tmp_0 : (int32_T)(uint32_T)tmp_0) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge, &top_level_algo_P.IfActionSubsystem_c);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge, &top_level_algo_P.IfActionSubsystem1_n);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem1' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge, &top_level_algo_P.IfActionSubsystem2_i);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem2' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S32>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge, &top_level_algo_P.IfActionSubsystem3_f0);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem3' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge, &top_level_algo_P.IfActionSubsystem4_o);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem4' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge, &top_level_algo_P.IfActionSubsystem5_b);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem5' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S35>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge, &top_level_algo_P.IfActionSubsystem6_f);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem6' */
    break;

   case 7:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S36>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge, &top_level_algo_P.IfActionSubsystem7_a);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem7' */
    break;

   case 8:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S37>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge, &top_level_algo_P.IfActionSubsystem8_ez);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem8' */
    break;

   case 9:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem10' incorporates:
     *  ActionPort: '<S30>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge, &top_level_algo_P.IfActionSubsystem10_b);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem10' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem9' incorporates:
     *  ActionPort: '<S38>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge, &top_level_algo_P.IfActionSubsystem9_j);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem9' */
    break;
  }

  /* End of SwitchCase: '<S5>/Switch Case' */

  /* Math: '<S1>/Mod1' incorporates:
   *  Constant: '<S1>/Constant2'
   */
  rtb_Mod1 = rt_modd_snf(rtb_TmpMLSysMemLayoutBufferAt_k,
    top_level_algo_P.Constant2_Value);

  /* MATLABSystem: '<S1>/Divide by Constant and Round1' incorporates:
   *  Sum: '<S1>/Subtract1'
   */
  rtb_TmpMLSysMemLayoutBufferAt_k = floor((rtb_TmpMLSysMemLayoutBufferAt_k -
    rtb_Mod1) * 0.1);

  /* SwitchCase: '<S4>/Switch Case' incorporates:
   *  SignalConversion generated from: '<S1>/Divide by Constant and Round1'
   */
  if (rtIsNaN(rtb_TmpMLSysMemLayoutBufferAt_k) || rtIsInf
      (rtb_TmpMLSysMemLayoutBufferAt_k)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(rtb_TmpMLSysMemLayoutBufferAt_k, 4.294967296E+9);
  }

  switch (tmp_0 < 0.0 ? -(int32_T)(uint32_T)-tmp_0 : (int32_T)(uint32_T)tmp_0) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge_n, &top_level_algo_P.IfActionSubsystem_j);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge_n, &top_level_algo_P.IfActionSubsystem1_b);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem1' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S20>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge_n, &top_level_algo_P.IfActionSubsystem2_p);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem2' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S21>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge_n, &top_level_algo_P.IfActionSubsystem3_f);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem3' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S22>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge_n, &top_level_algo_P.IfActionSubsystem4_j);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem4' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S23>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge_n, &top_level_algo_P.IfActionSubsystem5_h);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem5' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S24>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge_n, &top_level_algo_P.IfActionSubsystem6_l);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem6' */
    break;

   case 7:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge_n, &top_level_algo_P.IfActionSubsystem7_c);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem7' */
    break;

   case 8:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge_n, &top_level_algo_P.IfActionSubsystem8_e);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem8' */
    break;

   case 9:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem10' incorporates:
     *  ActionPort: '<S19>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge_n,
      &top_level_algo_P.IfActionSubsystem10_a);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem10' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem9' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge_n, &top_level_algo_P.IfActionSubsystem9_p);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem9' */
    break;
  }

  /* End of SwitchCase: '<S4>/Switch Case' */

  /* MATLABSystem: '<S1>/Divide by Constant and Round2' */
  rtb_Mod1 = floor(rtb_Mod1);

  /* SwitchCase: '<S3>/Switch Case' incorporates:
   *  SignalConversion generated from: '<S1>/Divide by Constant and Round2'
   */
  if (rtIsNaN(rtb_Mod1) || rtIsInf(rtb_Mod1)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(rtb_Mod1, 4.294967296E+9);
  }

  switch (tmp_0 < 0.0 ? -(int32_T)(uint32_T)-tmp_0 : (int32_T)(uint32_T)tmp_0) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge_m, &top_level_algo_P.IfActionSubsystem);

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge_m, &top_level_algo_P.IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem1' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge_m, &top_level_algo_P.IfActionSubsystem2);

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem2' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge_m, &top_level_algo_P.IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem3' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge_m, &top_level_algo_P.IfActionSubsystem4);

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem4' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge_m, &top_level_algo_P.IfActionSubsystem5);

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem5' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge_m, &top_level_algo_P.IfActionSubsystem6);

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem6' */
    break;

   case 7:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge_m, &top_level_algo_P.IfActionSubsystem7);

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem7' */
    break;

   case 8:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge_m, &top_level_algo_P.IfActionSubsystem8);

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem8' */
    break;

   case 9:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem10' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge_m, &top_level_algo_P.IfActionSubsystem10);

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem10' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem9' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    top_level_IfActionSubsystem(&Merge_m, &top_level_algo_P.IfActionSubsystem9);

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem9' */
    break;
  }

  /* End of SwitchCase: '<S3>/Switch Case' */

  /* Sum: '<S1>/Add' incorporates:
   *  ArithShift: '<S1>/Shift Arithmetic1'
   *  ArithShift: '<S1>/Shift Arithmetic2'
   *  DataTypeConversion: '<S1>/Cast To Double'
   *  DataTypeConversion: '<S1>/Cast To Double1'
   *  DataTypeConversion: '<S1>/Cast To Double2'
   */
  top_level_algo_B.Add = (((uint32_T)Merge_n << 8) + Merge) + ((uint32_T)Merge_m
    << 16);

  /* DataTypeConversion: '<S2>/Cast To Double' */
  top_level_algo_B.CastToDouble = top_level_algo_B.Add;

  /* DiscretePulseGenerator: '<S2>/Pulse Generator' */
  top_level_algo_B.PulseGenerator = (top_level_algo_DW.clockTickCounter <
    top_level_algo_P.PulseGenerator_Duty) && (top_level_algo_DW.clockTickCounter
    >= 0) ? top_level_algo_P.PulseGenerator_Amp : 0.0;

  /* DiscretePulseGenerator: '<S2>/Pulse Generator' */
  if (top_level_algo_DW.clockTickCounter >=
      top_level_algo_P.PulseGenerator_Period - 1.0) {
    top_level_algo_DW.clockTickCounter = 0;
  } else {
    top_level_algo_DW.clockTickCounter++;
  }

  /* Chart: '<S2>/DataLogic' */
  if (top_level_algo_DW.temporalCounter_i1 < MAX_uint32_T) {
    top_level_algo_DW.temporalCounter_i1++;
  }

  if (top_level_algo_DW.is_active_c15_top_level_algo == 0U) {
    top_level_algo_DW.is_active_c15_top_level_algo = 1U;
    top_level_algo_DW.is_c15_top_level_algo = top_level_algo_IN_LOAD;
    top_level_algo_B.data = 0U;
    top_level_algo_DW.Holder = top_level_algo_B.CastToDouble;
  } else {
    switch (top_level_algo_DW.is_c15_top_level_algo) {
     case top_level_algo_IN_CHECK:
      if (top_level_algo_DW.Holder == 0U) {
        top_level_algo_DW.is_c15_top_level_algo = top_level_algo_IN_WAITING;
        top_level_algo_DW.temporalCounter_i1 = 0U;
      } else if (top_level_algo_DW.temporalCounter_i1 >= 40U) {
        top_level_algo_DW.is_c15_top_level_algo = top_level_algo_IN_MASK;
        top_level_algo_DW.temporalCounter_i1 = 0U;
        top_level_algo_B.data = top_level_algo_DW.Holder & 1U;
      }
      break;

     case top_level_algo_IN_HOLD:
      if (top_level_algo_B.PulseGenerator == 0.0) {
        top_level_algo_DW.is_c15_top_level_algo = top_level_algo_IN_LOAD;
        top_level_algo_B.data = 0U;
        top_level_algo_DW.Holder = top_level_algo_B.CastToDouble;
      }
      break;

     case top_level_algo_IN_LOAD:
      if (top_level_algo_B.PulseGenerator == 1.0) {
        top_level_algo_DW.is_c15_top_level_algo = top_level_algo_IN_Wait;
        top_level_algo_DW.temporalCounter_i1 = 0U;
      }
      break;

     case top_level_algo_IN_MASK:
      if (top_level_algo_DW.temporalCounter_i1 >= 40U) {
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
      if (top_level_algo_DW.temporalCounter_i1 >= 40U) {
        top_level_algo_DW.is_c15_top_level_algo = top_level_algo_IN_HOLD;
        top_level_algo_B.data = 0U;
      }
      break;

     default:
      /* case IN_Wait: */
      if (top_level_algo_DW.temporalCounter_i1 >= 20U) {
        top_level_algo_DW.is_c15_top_level_algo = top_level_algo_IN_START;
        top_level_algo_DW.temporalCounter_i1 = 0U;
        top_level_algo_B.data = 1U;
      }
      break;
    }
  }

  /* End of Chart: '<S2>/DataLogic' */
  /* MATLABSystem: '<Root>/Digital Output3' */
  tmp = top_level_algo_B.data;
  if (top_level_algo_B.data > 255U) {
    tmp = 255U;
  }

  writeDigitalPin(26, (uint8_T)tmp);

  /* End of MATLABSystem: '<Root>/Digital Output3' */
  /* SignalConversion generated from: '<S1>/Vector Concatenate' incorporates:
   *  Concatenate: '<S1>/Vector Concatenate'
   *  SignalConversion generated from: '<S1>/Divide by Constant and Round2'
   */
  top_level_algo_B.VectorConcatenate[2] = rtb_Mod1;

  /* SignalConversion generated from: '<S1>/Vector Concatenate' incorporates:
   *  Concatenate: '<S1>/Vector Concatenate'
   *  SignalConversion generated from: '<S1>/Divide by Constant and Round1'
   */
  top_level_algo_B.VectorConcatenate[1] = rtb_TmpMLSysMemLayoutBufferAt_k;

  /* SignalConversion generated from: '<S1>/Vector Concatenate' incorporates:
   *  Concatenate: '<S1>/Vector Concatenate'
   *  SignalConversion generated from: '<S1>/Divide by Constant and Round'
   */
  top_level_algo_B.VectorConcatenate[0] = rtb_DividebyConstantandRound;

  /* RateTransition generated from: '<S40>/Switch' incorporates:
   *  RateTransition generated from: '<S40>/Unit Delay'
   */
  if (top_level_algo_M->Timing.RateInteraction.TID0_1) {
    /* Switch: '<S40>/Switch' incorporates:
     *  Constant: '<S40>/Constant1'
     *  Constant: '<S41>/Constant'
     *  DataTypeConversion: '<S40>/Cast To Single'
     *  RelationalOperator: '<S41>/Compare'
     */
    if ((real32_T)top_level_algo_B.NOT1 >=
        top_level_algo_P.CompareToConstant_const) {
      top_level_algo_DW.TmpRTBAtUnitDelayInport1_Buffer =
        top_level_algo_DW.TmpRTBAtSwitchInport1_Buffer0_d;
    } else {
      top_level_algo_DW.TmpRTBAtUnitDelayInport1_Buffer =
        top_level_algo_P.Constant1_Value;
    }

    /* End of Switch: '<S40>/Switch' */
  }

  /* End of RateTransition generated from: '<S40>/Switch' */
  /* Update for Delay: '<S2>/Delay' */
  for (idxDelay = 0; idxDelay < 39; idxDelay++) {
    top_level_algo_DW.Delay_DSTATE[idxDelay] =
      top_level_algo_DW.Delay_DSTATE[idxDelay + 1];
  }

  top_level_algo_DW.Delay_DSTATE[39] = top_level_algo_B.PulseGenerator;

  /* End of Update for Delay: '<S2>/Delay' */

  /* Update for Delay: '<S2>/Delay8' */
  for (idxDelay = 0; idxDelay < 2879; idxDelay++) {
    top_level_algo_DW.Delay8_DSTATE[idxDelay] =
      top_level_algo_DW.Delay8_DSTATE[idxDelay + 1];
  }

  top_level_algo_DW.Delay8_DSTATE[2879] = rtb_LogicalOperator;

  /* End of Update for Delay: '<S2>/Delay8' */

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  top_level_algo_M->Timing.taskTime0 =
    ((time_T)(++top_level_algo_M->Timing.clockTick0)) *
    top_level_algo_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void top_level_algo_step1(void)        /* Sample time: [0.04s, 0.0s] */
{
  /* Sum: '<S40>/Sum' incorporates:
   *  Constant: '<S40>/Constant'
   *  UnitDelay: '<S40>/Unit Delay'
   */
  top_level_algo_B.Sum = top_level_algo_P.Constant_Value_k -
    top_level_algo_DW.UnitDelay_DSTATE;

  /* RateTransition generated from: '<S2>/Switch' */
  top_level_algo_DW.TmpRTBAtSwitchInport1_Buffer0 = top_level_algo_B.Sum;

  /* RateTransition generated from: '<S40>/Switch' */
  top_level_algo_DW.TmpRTBAtSwitchInport1_Buffer0_d = top_level_algo_B.Sum;

  /* RateTransition generated from: '<S40>/Unit Delay' incorporates:
   *  UnitDelay: '<S40>/Unit Delay'
   */
  top_level_algo_DW.UnitDelay_DSTATE =
    top_level_algo_DW.TmpRTBAtUnitDelayInport1_Buffer;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.04, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  top_level_algo_M->Timing.clockTick1++;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void top_level_algo_step(int_T tid)
{
  switch (tid) {
   case 0 :
    top_level_algo_step0();
    break;

   case 1 :
    top_level_algo_step1();
    break;

   default :
    /* do nothing */
    break;
  }
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
  top_level_algo_M->Sizes.checksums[0] = (4208139868U);
  top_level_algo_M->Sizes.checksums[1] = (4183635474U);
  top_level_algo_M->Sizes.checksums[2] = (2284600284U);
  top_level_algo_M->Sizes.checksums[3] = (134528521U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[42];
    top_level_algo_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem1.IfActionSubsystem_SubsysRanBC;
    systemRan[5] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem10.IfActionSubsystem_SubsysRanBC;
    systemRan[6] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC;
    systemRan[7] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem3.IfActionSubsystem_SubsysRanBC;
    systemRan[8] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem4.IfActionSubsystem_SubsysRanBC;
    systemRan[9] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem5.IfActionSubsystem_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem6.IfActionSubsystem_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem7.IfActionSubsystem_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem8.IfActionSubsystem_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem9.IfActionSubsystem_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem_j.IfActionSubsystem_SubsysRanBC;
    systemRan[15] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem1_b.IfActionSubsystem_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem10_a.IfActionSubsystem_SubsysRanBC;
    systemRan[17] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem2_p.IfActionSubsystem_SubsysRanBC;
    systemRan[18] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem3_f.IfActionSubsystem_SubsysRanBC;
    systemRan[19] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem4_j.IfActionSubsystem_SubsysRanBC;
    systemRan[20] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem5_h.IfActionSubsystem_SubsysRanBC;
    systemRan[21] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem6_l.IfActionSubsystem_SubsysRanBC;
    systemRan[22] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem7_c.IfActionSubsystem_SubsysRanBC;
    systemRan[23] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem8_e.IfActionSubsystem_SubsysRanBC;
    systemRan[24] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem9_p.IfActionSubsystem_SubsysRanBC;
    systemRan[25] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem_c.IfActionSubsystem_SubsysRanBC;
    systemRan[26] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem1_n.IfActionSubsystem_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem10_b.IfActionSubsystem_SubsysRanBC;
    systemRan[28] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem2_i.IfActionSubsystem_SubsysRanBC;
    systemRan[29] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem3_f0.IfActionSubsystem_SubsysRanBC;
    systemRan[30] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem4_o.IfActionSubsystem_SubsysRanBC;
    systemRan[31] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem5_b.IfActionSubsystem_SubsysRanBC;
    systemRan[32] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem6_f.IfActionSubsystem_SubsysRanBC;
    systemRan[33] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem7_a.IfActionSubsystem_SubsysRanBC;
    systemRan[34] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem8_ez.IfActionSubsystem_SubsysRanBC;
    systemRan[35] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem9_j.IfActionSubsystem_SubsysRanBC;
    systemRan[36] = &rtAlwaysEnabled;
    systemRan[37] = &rtAlwaysEnabled;
    systemRan[38] = &rtAlwaysEnabled;
    systemRan[39] = &rtAlwaysEnabled;
    systemRan[40] = &rtAlwaysEnabled;
    systemRan[41] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(top_level_algo_M->extModeInfo,
      &top_level_algo_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(top_level_algo_M->extModeInfo,
                        top_level_algo_M->Sizes.checksums);
    rteiSetTPtr(top_level_algo_M->extModeInfo, rtmGetTPtr(top_level_algo_M));
  }

  {
    int32_T i;

    /* Start for RateTransition generated from: '<S2>/Switch' */
    top_level_algo_B.TmpRTBAtSwitchInport1 =
      top_level_algo_P.TmpRTBAtSwitchInport1_InitialCo;

    /* Start for DiscretePulseGenerator: '<S2>/Pulse Generator' */
    top_level_algo_DW.clockTickCounter = -2000;

    /* InitializeConditions for Delay: '<S2>/Delay' */
    for (i = 0; i < 40; i++) {
      top_level_algo_DW.Delay_DSTATE[i] =
        top_level_algo_P.Delay_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S2>/Delay' */

    /* InitializeConditions for Delay: '<S2>/Delay8' */
    for (i = 0; i < 2880; i++) {
      top_level_algo_DW.Delay8_DSTATE[i] =
        top_level_algo_P.Delay8_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S2>/Delay8' */

    /* InitializeConditions for Delay: '<S2>/Delay7' */
    top_level_algo_DW.Delay7_DSTATE = top_level_algo_P.Delay7_InitialCondition;

    /* InitializeConditions for RateTransition generated from: '<S2>/Switch' */
    top_level_algo_DW.TmpRTBAtSwitchInport1_Buffer0 =
      top_level_algo_P.TmpRTBAtSwitchInport1_InitialCo;

    /* InitializeConditions for RateTransition generated from: '<S40>/Switch' */
    top_level_algo_DW.TmpRTBAtSwitchInport1_Buffer0_d =
      top_level_algo_P.TmpRTBAtSwitchInport1_Initial_j;

    /* InitializeConditions for UnitDelay: '<S40>/Unit Delay' */
    top_level_algo_DW.UnitDelay_DSTATE =
      top_level_algo_P.UnitDelay_InitialCondition;

    /* Start for MATLABSystem: '<Root>/Digital Output2' */
    top_level_algo_DW.obj_a.matlabCodegenIsDeleted = false;
    top_level_algo_DW.obj_a.isInitialized = 1;
    digitalIOSetup(25, 1);
    top_level_algo_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output3' */
    top_level_algo_DW.obj.matlabCodegenIsDeleted = false;
    top_level_algo_DW.obj.isInitialized = 1;
    digitalIOSetup(26, 1);
    top_level_algo_DW.obj.isSetupComplete = true;
  }
}

/* Model terminate function */
void top_level_algo_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output2' */
  if (!top_level_algo_DW.obj_a.matlabCodegenIsDeleted) {
    top_level_algo_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output2' */
  /* Terminate for MATLABSystem: '<Root>/Digital Output3' */
  if (!top_level_algo_DW.obj.matlabCodegenIsDeleted) {
    top_level_algo_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output3' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
