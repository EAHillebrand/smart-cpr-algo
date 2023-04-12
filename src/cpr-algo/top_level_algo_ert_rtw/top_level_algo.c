/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo.c
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 3.60
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Apr 10 16:36:37 2023
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
#include <string.h>
#include "top_level_algo_types.h"
#include <float.h>

/* Named constants for Chart: '<S12>/sample and hold' */
#define top_level_algo_IN_Holding      ((uint8_T)1U)
#define top_level_algo_IN_Init         ((uint8_T)2U)

/* Named constants for Chart: '<S6>/Chart1' */
#define top_level_al_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define top_level_algo_IN_Counting     ((uint8_T)1U)
#define top_level_algo_IN_First        ((uint8_T)2U)
#define top_level_algo_IN_INIT         ((uint8_T)3U)

/* Named constants for Chart: '<S10>/timer' */
#define top_level_algo_IN_Finished     ((uint8_T)1U)
#define top_level_algo_IN_Starting     ((uint8_T)2U)

/* Named constants for Chart: '<Root>/Mode' */
#define top_level_algo_IN_CALIBRATION  ((uint8_T)1U)
#define top_level_algo_IN_DEBOUNCE1    ((uint8_T)2U)
#define top_level_algo_IN_DEBOUNCE2    ((uint8_T)3U)
#define top_level_algo_IN_EVALUATING   ((uint8_T)4U)
#define top_level_algo_IN_RUNNING      ((uint8_T)5U)

/* Named constants for Chart: '<S15>/DataLogic' */
#define top_level_algo_IN_CHECK        ((uint8_T)1U)
#define top_level_algo_IN_HOLD         ((uint8_T)2U)
#define top_level_algo_IN_LOAD         ((uint8_T)3U)
#define top_level_algo_IN_MASK         ((uint8_T)4U)
#define top_level_algo_IN_START        ((uint8_T)5U)
#define top_level_algo_IN_WAITING      ((uint8_T)6U)
#define top_level_algo_IN_Wait         ((uint8_T)7U)
#define top_level_algo_clk_period      (8.0)

/* Named constants for Chart: '<S15>/Write Logic' */
#define top_level_algo_IN_CHECKING     ((uint8_T)1U)
#define top_level_algo_IN_DELAY        ((uint8_T)2U)
#define top_level_algo_IN_INITIALIZE   ((uint8_T)3U)
#define top_level_algo_IN_WRITE_TRIGGER ((uint8_T)4U)

/* Named constants for Chart: '<Root>/Summarizing' */
#define top_level__IN_LEARNINGAFTEREVAL ((uint8_T)4U)
#define top_level_algo_IN_EVALUATING_j ((uint8_T)1U)
#define top_level_algo_IN_INIT_k       ((uint8_T)2U)
#define top_level_algo_IN_LEARNING     ((uint8_T)3U)
#define top_level_algo_IN_UPDATE       ((uint8_T)2U)

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
  eventFlags[2] = ((boolean_T)rtmStepTask(top_level_algo_M, 2));
  eventFlags[3] = ((boolean_T)rtmStepTask(top_level_algo_M, 3));
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

  /* tid 1 shares data with slower tid rates: 2, 3 */
  if (top_level_algo_M->Timing.TaskCounters.TID[1] == 0) {
    top_level_algo_M->Timing.RateInteraction.TID1_2 =
      (top_level_algo_M->Timing.TaskCounters.TID[2] == 0);
    top_level_algo_M->Timing.RateInteraction.TID1_3 =
      (top_level_algo_M->Timing.TaskCounters.TID[3] == 0);
  }

  /* tid 2 shares data with slower tid rate: 3 */
  if (top_level_algo_M->Timing.TaskCounters.TID[2] == 0) {
    top_level_algo_M->Timing.RateInteraction.TID2_3 =
      (top_level_algo_M->Timing.TaskCounters.TID[3] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (top_level_algo_M->Timing.TaskCounters.TID[2])++;
  if ((top_level_algo_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.005s, 0.0s] */
    top_level_algo_M->Timing.TaskCounters.TID[2] = 0;
  }

  (top_level_algo_M->Timing.TaskCounters.TID[3])++;
  if ((top_level_algo_M->Timing.TaskCounters.TID[3]) > 49) {/* Sample time: [0.05s, 0.0s] */
    top_level_algo_M->Timing.TaskCounters.TID[3] = 0;
  }
}

/*
 * Output and update for action system:
 *    '<S22>/If Action Subsystem'
 *    '<S22>/If Action Subsystem1'
 *    '<S22>/If Action Subsystem2'
 *    '<S22>/If Action Subsystem3'
 *    '<S22>/If Action Subsystem4'
 *    '<S22>/If Action Subsystem5'
 *    '<S22>/If Action Subsystem6'
 *    '<S22>/If Action Subsystem7'
 *    '<S22>/If Action Subsystem8'
 *    '<S22>/If Action Subsystem10'
 *    ...
 */
void top_level_IfActionSubsystem(uint8_T *rty_Out1,
  P_IfActionSubsystem_top_level_T *localP)
{
  /* SignalConversion generated from: '<S25>/Out1' incorporates:
   *  Constant: '<S25>/Constant'
   */
  *rty_Out1 = localP->Constant_Value;
}

/*
 * System initialize for atomic system:
 *    '<S12>/sample and hold'
 *    '<S12>/sample and hold1'
 */
void top_leve_sampleandhold_Init(real_T *rty_displacement)
{
  *rty_displacement = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S12>/sample and hold'
 *    '<S12>/sample and hold1'
 */
void top_level_alg_sampleandhold(real_T rtu_max, boolean_T rtu_read, real_T
  *rty_displacement, DW_sampleandhold_top_level_al_T *localDW)
{
  /* Chart: '<S12>/sample and hold' */
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

  /* End of Chart: '<S12>/sample and hold' */
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
void top_level_algo_step0(void)        /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_PulseGenerator;
  real_T rtb_Switch;
  boolean_T rtb_LogicalOperator;

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  {
    real_T Clock1;
    real_T rtb_Subtract3;
    real_T tmp;
    uint32_T rtb_CastToDouble;
    uint8_T Merge_e;
    uint8_T Merge_i;
    uint8_T Merge_j;
    boolean_T rtb_AND;
    boolean_T rtb_Compare_b;
    boolean_T rtb_Compare_bz;
    boolean_T rtb_NOT1_j;

    /* Sum: '<S83>/Sum' incorporates:
     *  Constant: '<S83>/Constant'
     *  Delay: '<S83>/Delay'
     */
    rtb_Switch = top_level_algo_P.Constant_Value_k -
      top_level_algo_DW.Delay_DSTATE[0];

    /* Logic: '<S15>/Logical Operator' incorporates:
     *  Delay: '<S15>/Delay'
     */
    rtb_LogicalOperator = !(top_level_algo_DW.Delay_DSTATE_d[0] != 0.0);

    /* Logic: '<S15>/Logical Operator1' incorporates:
     *  Delay: '<S15>/Delay7'
     *  Delay: '<S15>/Delay8'
     *  Logic: '<S15>/Logical Operator2'
     *  Logic: '<S15>/NOT'
     */
    top_level_algo_DW.Delay7_DSTATE = (rtb_LogicalOperator &&
      ((!top_level_algo_DW.Delay8_DSTATE[0]) || top_level_algo_DW.Delay7_DSTATE));

    /* Logic: '<S15>/NOT1' incorporates:
     *  Delay: '<S15>/Delay7'
     */
    rtb_NOT1_j = !top_level_algo_DW.Delay7_DSTATE;

    /* Switch: '<S15>/Switch' incorporates:
     *  Constant: '<S15>/Constant'
     */
    if (rtb_NOT1_j) {
      rtb_Subtract3 = rtb_Switch;
    } else {
      rtb_Subtract3 = top_level_algo_P.Constant_Value_g;
    }

    /* MATLABSystem: '<S2>/Digital Output2' incorporates:
     *  Switch: '<S15>/Switch'
     */
    rtb_Subtract3 = rt_roundd_snf(rtb_Subtract3);
    if (rtb_Subtract3 < 256.0) {
      if (rtb_Subtract3 >= 0.0) {
        Merge_j = (uint8_T)rtb_Subtract3;
      } else {
        Merge_j = 0U;
      }
    } else {
      Merge_j = MAX_uint8_T;
    }

    writeDigitalPin(1, Merge_j);

    /* End of MATLABSystem: '<S2>/Digital Output2' */

    /* Clock: '<S6>/Clock1' */
    Clock1 = top_level_algo_M->Timing.t[0];

    /* RateTransition generated from: '<S6>/Chart1' */
    if (top_level_algo_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition generated from: '<S6>/Chart1' */
      top_level_algo_B.TmpRTBAtChart1Inport2 =
        top_level_algo_DW.TmpRTBAtChart1Inport2_Buffer0;
    }

    /* End of RateTransition generated from: '<S6>/Chart1' */

    /* Chart: '<S6>/Chart1' */
    if (top_level_algo_DW.temporalCounter_i1_o < 2047U) {
      top_level_algo_DW.temporalCounter_i1_o++;
    }

    if (top_level_algo_DW.is_active_c12_top_level_algo == 0U) {
      top_level_algo_DW.is_active_c12_top_level_algo = 1U;
      top_level_algo_DW.is_c12_top_level_algo = top_level_algo_IN_INIT;
      top_level_algo_DW.lastTs = 0.0;
      top_level_algo_B.rate = 0.0;
      top_level_algo_B.recoil_active = 0.0;
    } else {
      switch (top_level_algo_DW.is_c12_top_level_algo) {
       case top_level_algo_IN_Counting:
        if ((top_level_algo_DW.temporalCounter_i1_o >= 10U) &&
            top_level_algo_B.TmpRTBAtChart1Inport2) {
          top_level_algo_DW.is_c12_top_level_algo = top_level_algo_IN_Counting;
          top_level_algo_DW.temporalCounter_i1_o = 0U;
          top_level_algo_B.rate = 60.0 / (Clock1 - top_level_algo_DW.lastTs);
          top_level_algo_DW.lastTs = Clock1;
        } else if (top_level_algo_DW.temporalCounter_i1_o >= 2000U) {
          top_level_algo_DW.is_c12_top_level_algo = top_level_algo_IN_INIT;
          top_level_algo_DW.lastTs = 0.0;
          top_level_algo_B.rate = 0.0;
          top_level_algo_B.recoil_active = 0.0;
        }
        break;

       case top_level_algo_IN_First:
        top_level_algo_B.recoil_active = 1.0;
        if ((top_level_algo_DW.temporalCounter_i1_o >= 50U) &&
            top_level_algo_B.TmpRTBAtChart1Inport2) {
          top_level_algo_DW.is_c12_top_level_algo = top_level_algo_IN_Counting;
          top_level_algo_DW.temporalCounter_i1_o = 0U;
          top_level_algo_B.rate = 60.0 / (Clock1 - top_level_algo_DW.lastTs);
          top_level_algo_DW.lastTs = Clock1;
        }
        break;

       default:
        /* case IN_INIT: */
        top_level_algo_B.recoil_active = 0.0;
        if (top_level_algo_B.TmpRTBAtChart1Inport2) {
          top_level_algo_DW.is_c12_top_level_algo = top_level_algo_IN_First;
          top_level_algo_DW.temporalCounter_i1_o = 0U;
          top_level_algo_DW.lastTs = Clock1;
          top_level_algo_B.recoil_active = 1.0;
        }
        break;
      }
    }

    /* End of Chart: '<S6>/Chart1' */

    /* If: '<S21>/If' */
    if (top_level_algo_B.rate > 253.0) {
      /* Outputs for IfAction SubSystem: '<S21>/If Action Subsystem' incorporates:
       *  ActionPort: '<S58>/Action Port'
       */
      /* SignalConversion generated from: '<S58>/In1' incorporates:
       *  Constant: '<S21>/Constant'
       */
      Clock1 = top_level_algo_P.Constant_Value_j;

      /* End of Outputs for SubSystem: '<S21>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S21>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S59>/Action Port'
       */
      /* SignalConversion generated from: '<S59>/In1' */
      Clock1 = top_level_algo_B.rate;

      /* End of Outputs for SubSystem: '<S21>/If Action Subsystem1' */
    }

    /* End of If: '<S21>/If' */

    /* Math: '<S20>/Mod' incorporates:
     *  Constant: '<S20>/Constant1'
     */
    top_level_algo_B.TmpMLSysMemLayoutBufferAt_p = rt_modd_snf(Clock1,
      top_level_algo_P.Constant1_Value_j);

    /* SwitchCase: '<S24>/Switch Case' incorporates:
     *  MATLABSystem: '<S20>/Divide by Constant and Round'
     *  Sum: '<S20>/Subtract'
     */
    rtb_Subtract3 = floor((Clock1 - top_level_algo_B.TmpMLSysMemLayoutBufferAt_p)
                          * 0.01);
    if (rtIsNaN(rtb_Subtract3) || rtIsInf(rtb_Subtract3)) {
      rtb_Subtract3 = 0.0;
    } else {
      rtb_Subtract3 = fmod(rtb_Subtract3, 4.294967296E+9);
    }

    switch (rtb_Subtract3 < 0.0 ? -(int32_T)(uint32_T)-rtb_Subtract3 : (int32_T)
            (uint32_T)rtb_Subtract3) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem' incorporates:
       *  ActionPort: '<S47>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_j,
        &top_level_algo_P.IfActionSubsystem_a);

      /* End of Outputs for SubSystem: '<S24>/If Action Subsystem' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S48>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_j,
        &top_level_algo_P.IfActionSubsystem1_i);

      /* End of Outputs for SubSystem: '<S24>/If Action Subsystem1' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S50>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_j,
        &top_level_algo_P.IfActionSubsystem2_b);

      /* End of Outputs for SubSystem: '<S24>/If Action Subsystem2' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S51>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_j,
        &top_level_algo_P.IfActionSubsystem3_m);

      /* End of Outputs for SubSystem: '<S24>/If Action Subsystem3' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S52>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_j,
        &top_level_algo_P.IfActionSubsystem4_k);

      /* End of Outputs for SubSystem: '<S24>/If Action Subsystem4' */
      break;

     case 5:
      /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S53>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_j,
        &top_level_algo_P.IfActionSubsystem5_j);

      /* End of Outputs for SubSystem: '<S24>/If Action Subsystem5' */
      break;

     case 6:
      /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem6' incorporates:
       *  ActionPort: '<S54>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_j,
        &top_level_algo_P.IfActionSubsystem6_f);

      /* End of Outputs for SubSystem: '<S24>/If Action Subsystem6' */
      break;

     case 7:
      /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem7' incorporates:
       *  ActionPort: '<S55>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_j,
        &top_level_algo_P.IfActionSubsystem7_o);

      /* End of Outputs for SubSystem: '<S24>/If Action Subsystem7' */
      break;

     case 8:
      /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem8' incorporates:
       *  ActionPort: '<S56>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_j,
        &top_level_algo_P.IfActionSubsystem8_g);

      /* End of Outputs for SubSystem: '<S24>/If Action Subsystem8' */
      break;

     case 9:
      /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem10' incorporates:
       *  ActionPort: '<S49>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_j,
        &top_level_algo_P.IfActionSubsystem10_n);

      /* End of Outputs for SubSystem: '<S24>/If Action Subsystem10' */
      break;

     default:
      /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem9' incorporates:
       *  ActionPort: '<S57>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_j,
        &top_level_algo_P.IfActionSubsystem9_j);

      /* End of Outputs for SubSystem: '<S24>/If Action Subsystem9' */
      break;
    }

    /* End of SwitchCase: '<S24>/Switch Case' */

    /* Math: '<S20>/Mod1' incorporates:
     *  Constant: '<S20>/Constant2'
     */
    top_level_algo_B.Mod1 = rt_modd_snf
      (top_level_algo_B.TmpMLSysMemLayoutBufferAt_p,
       top_level_algo_P.Constant2_Value_c);

    /* SwitchCase: '<S23>/Switch Case' incorporates:
     *  MATLABSystem: '<S20>/Divide by Constant and Round1'
     *  Sum: '<S20>/Subtract1'
     */
    rtb_Subtract3 = floor((top_level_algo_B.TmpMLSysMemLayoutBufferAt_p -
      top_level_algo_B.Mod1) * 0.1);
    if (rtIsNaN(rtb_Subtract3) || rtIsInf(rtb_Subtract3)) {
      rtb_Subtract3 = 0.0;
    } else {
      rtb_Subtract3 = fmod(rtb_Subtract3, 4.294967296E+9);
    }

    switch (rtb_Subtract3 < 0.0 ? -(int32_T)(uint32_T)-rtb_Subtract3 : (int32_T)
            (uint32_T)rtb_Subtract3) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem' incorporates:
       *  ActionPort: '<S36>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_i,
        &top_level_algo_P.IfActionSubsystem_f);

      /* End of Outputs for SubSystem: '<S23>/If Action Subsystem' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S37>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_i,
        &top_level_algo_P.IfActionSubsystem1_l);

      /* End of Outputs for SubSystem: '<S23>/If Action Subsystem1' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S39>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_i,
        &top_level_algo_P.IfActionSubsystem2_e);

      /* End of Outputs for SubSystem: '<S23>/If Action Subsystem2' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S40>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_i,
        &top_level_algo_P.IfActionSubsystem3_h);

      /* End of Outputs for SubSystem: '<S23>/If Action Subsystem3' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S41>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_i,
        &top_level_algo_P.IfActionSubsystem4_b);

      /* End of Outputs for SubSystem: '<S23>/If Action Subsystem4' */
      break;

     case 5:
      /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S42>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_i,
        &top_level_algo_P.IfActionSubsystem5_b);

      /* End of Outputs for SubSystem: '<S23>/If Action Subsystem5' */
      break;

     case 6:
      /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem6' incorporates:
       *  ActionPort: '<S43>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_i,
        &top_level_algo_P.IfActionSubsystem6_h);

      /* End of Outputs for SubSystem: '<S23>/If Action Subsystem6' */
      break;

     case 7:
      /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem7' incorporates:
       *  ActionPort: '<S44>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_i,
        &top_level_algo_P.IfActionSubsystem7_j);

      /* End of Outputs for SubSystem: '<S23>/If Action Subsystem7' */
      break;

     case 8:
      /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem8' incorporates:
       *  ActionPort: '<S45>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_i,
        &top_level_algo_P.IfActionSubsystem8_j);

      /* End of Outputs for SubSystem: '<S23>/If Action Subsystem8' */
      break;

     case 9:
      /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem10' incorporates:
       *  ActionPort: '<S38>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_i,
        &top_level_algo_P.IfActionSubsystem10_d);

      /* End of Outputs for SubSystem: '<S23>/If Action Subsystem10' */
      break;

     default:
      /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem9' incorporates:
       *  ActionPort: '<S46>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_i,
        &top_level_algo_P.IfActionSubsystem9_m);

      /* End of Outputs for SubSystem: '<S23>/If Action Subsystem9' */
      break;
    }

    /* End of SwitchCase: '<S23>/Switch Case' */

    /* SwitchCase: '<S22>/Switch Case' incorporates:
     *  MATLABSystem: '<S20>/Divide by Constant and Round2'
     */
    rtb_Subtract3 = floor(top_level_algo_B.Mod1);
    if (rtIsNaN(rtb_Subtract3) || rtIsInf(rtb_Subtract3)) {
      rtb_Subtract3 = 0.0;
    } else {
      rtb_Subtract3 = fmod(rtb_Subtract3, 4.294967296E+9);
    }

    switch (rtb_Subtract3 < 0.0 ? -(int32_T)(uint32_T)-rtb_Subtract3 : (int32_T)
            (uint32_T)rtb_Subtract3) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem' incorporates:
       *  ActionPort: '<S25>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_e, &top_level_algo_P.IfActionSubsystem);

      /* End of Outputs for SubSystem: '<S22>/If Action Subsystem' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S26>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_e, &top_level_algo_P.IfActionSubsystem1);

      /* End of Outputs for SubSystem: '<S22>/If Action Subsystem1' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S28>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_e, &top_level_algo_P.IfActionSubsystem2);

      /* End of Outputs for SubSystem: '<S22>/If Action Subsystem2' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S29>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_e, &top_level_algo_P.IfActionSubsystem3);

      /* End of Outputs for SubSystem: '<S22>/If Action Subsystem3' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S30>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_e, &top_level_algo_P.IfActionSubsystem4);

      /* End of Outputs for SubSystem: '<S22>/If Action Subsystem4' */
      break;

     case 5:
      /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S31>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_e, &top_level_algo_P.IfActionSubsystem5);

      /* End of Outputs for SubSystem: '<S22>/If Action Subsystem5' */
      break;

     case 6:
      /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem6' incorporates:
       *  ActionPort: '<S32>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_e, &top_level_algo_P.IfActionSubsystem6);

      /* End of Outputs for SubSystem: '<S22>/If Action Subsystem6' */
      break;

     case 7:
      /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem7' incorporates:
       *  ActionPort: '<S33>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_e, &top_level_algo_P.IfActionSubsystem7);

      /* End of Outputs for SubSystem: '<S22>/If Action Subsystem7' */
      break;

     case 8:
      /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem8' incorporates:
       *  ActionPort: '<S34>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_e, &top_level_algo_P.IfActionSubsystem8);

      /* End of Outputs for SubSystem: '<S22>/If Action Subsystem8' */
      break;

     case 9:
      /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem10' incorporates:
       *  ActionPort: '<S27>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_e,
        &top_level_algo_P.IfActionSubsystem10);

      /* End of Outputs for SubSystem: '<S22>/If Action Subsystem10' */
      break;

     default:
      /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem9' incorporates:
       *  ActionPort: '<S35>/Action Port'
       */
      top_level_IfActionSubsystem(&Merge_e, &top_level_algo_P.IfActionSubsystem9);

      /* End of Outputs for SubSystem: '<S22>/If Action Subsystem9' */
      break;
    }

    /* End of SwitchCase: '<S22>/Switch Case' */

    /* RateTransition generated from: '<Root>/Mode' */
    if (top_level_algo_M->Timing.RateInteraction.TID1_3) {
      /* RateTransition generated from: '<Root>/Mode' */
      top_level_algo_B.TmpRTBAtModeOutport3 =
        top_level_algo_DW.TmpRTBAtModeOutport3_Buffer0;
    }

    /* End of RateTransition generated from: '<Root>/Mode' */

    /* Switch: '<S1>/Switch2' incorporates:
     *  ArithShift: '<S20>/Shift Arithmetic1'
     *  ArithShift: '<S20>/Shift Arithmetic2'
     *  Constant: '<S1>/Constant1'
     *  DataTypeConversion: '<S20>/Cast To Double'
     *  DataTypeConversion: '<S20>/Cast To Double1'
     *  DataTypeConversion: '<S20>/Cast To Double2'
     *  Sum: '<S20>/Add'
     */
    if (top_level_algo_B.TmpRTBAtModeOutport3 >
        top_level_algo_P.Switch2_Threshold) {
      rtb_Subtract3 = (int32_T)(((uint32_T)Merge_i << 8) + Merge_j) + (int32_T)
        ((uint32_T)Merge_e << 16);
    } else {
      rtb_Subtract3 = top_level_algo_P.Constant1_Value;
    }

    /* DataTypeConversion: '<S15>/Cast To Double' incorporates:
     *  Switch: '<S1>/Switch2'
     */
    rtb_Subtract3 = floor(rtb_Subtract3);
    if (rtIsNaN(rtb_Subtract3) || rtIsInf(rtb_Subtract3)) {
      rtb_Subtract3 = 0.0;
    } else {
      rtb_Subtract3 = fmod(rtb_Subtract3, 4.294967296E+9);
    }

    rtb_CastToDouble = rtb_Subtract3 < 0.0 ? (uint32_T)-(int32_T)(uint32_T)
      -rtb_Subtract3 : (uint32_T)rtb_Subtract3;

    /* End of DataTypeConversion: '<S15>/Cast To Double' */

    /* DiscretePulseGenerator: '<S15>/Pulse Generator' */
    rtb_PulseGenerator = (top_level_algo_DW.clockTickCounter <
                          top_level_algo_P.PulseGenerator_Duty) &&
      (top_level_algo_DW.clockTickCounter >= 0) ?
      top_level_algo_P.PulseGenerator_Amp : 0.0;

    /* DiscretePulseGenerator: '<S15>/Pulse Generator' */
    if (top_level_algo_DW.clockTickCounter >=
        top_level_algo_P.PulseGenerator_Period - 1.0) {
      top_level_algo_DW.clockTickCounter = 0;
    } else {
      top_level_algo_DW.clockTickCounter++;
    }

    /* Chart: '<S15>/DataLogic' */
    if (top_level_algo_DW.temporalCounter_i1_i < MAX_uint32_T) {
      top_level_algo_DW.temporalCounter_i1_i++;
    }

    if (top_level_algo_DW.is_active_c15_top_level_algo == 0U) {
      top_level_algo_DW.is_active_c15_top_level_algo = 1U;
      top_level_algo_DW.is_c15_top_level_algo = top_level_algo_IN_LOAD;
      top_level_algo_B.data = 0U;
      top_level_algo_DW.Holder = rtb_CastToDouble;
    } else {
      switch (top_level_algo_DW.is_c15_top_level_algo) {
       case top_level_algo_IN_CHECK:
        if (top_level_algo_DW.Holder == 0U) {
          top_level_algo_DW.is_c15_top_level_algo = top_level_algo_IN_WAITING;
          top_level_algo_DW.temporalCounter_i1_i = 0U;
        } else if (top_level_algo_DW.temporalCounter_i1_i >= 4U) {
          top_level_algo_DW.is_c15_top_level_algo = top_level_algo_IN_MASK;
          top_level_algo_DW.temporalCounter_i1_i = 0U;
          top_level_algo_B.data = top_level_algo_DW.Holder & 1U;
        }
        break;

       case top_level_algo_IN_HOLD:
        if (rtb_PulseGenerator == 0.0) {
          top_level_algo_DW.is_c15_top_level_algo = top_level_algo_IN_LOAD;
          top_level_algo_B.data = 0U;
          top_level_algo_DW.Holder = rtb_CastToDouble;
        }
        break;

       case top_level_algo_IN_LOAD:
        if (rtb_PulseGenerator == 1.0) {
          top_level_algo_DW.is_c15_top_level_algo = top_level_algo_IN_Wait;
          top_level_algo_DW.temporalCounter_i1_i = 0U;
        }
        break;

       case top_level_algo_IN_MASK:
        if (top_level_algo_DW.temporalCounter_i1_i >= 4U) {
          top_level_algo_DW.is_c15_top_level_algo = top_level_algo_IN_CHECK;
          top_level_algo_DW.temporalCounter_i1_i = 0U;
          top_level_algo_DW.Holder >>= 1;
        }
        break;

       case top_level_algo_IN_START:
        if (top_level_algo_DW.temporalCounter_i1_i >= (uint32_T)
            top_level_algo_clk_period) {
          top_level_algo_DW.is_c15_top_level_algo = top_level_algo_IN_MASK;
          top_level_algo_DW.temporalCounter_i1_i = 0U;
          top_level_algo_B.data = top_level_algo_DW.Holder & 1U;
        }
        break;

       case top_level_algo_IN_WAITING:
        if (top_level_algo_DW.temporalCounter_i1_i >= 4U) {
          top_level_algo_DW.is_c15_top_level_algo = top_level_algo_IN_HOLD;
          top_level_algo_B.data = 0U;
        }
        break;

       default:
        /* case IN_Wait: */
        if (top_level_algo_DW.temporalCounter_i1_i >= 2U) {
          top_level_algo_DW.is_c15_top_level_algo = top_level_algo_IN_START;
          top_level_algo_DW.temporalCounter_i1_i = 0U;
          top_level_algo_B.data = 1U;
        }
        break;
      }
    }

    /* End of Chart: '<S15>/DataLogic' */

    /* MATLABSystem: '<S2>/Digital Output3' */
    rtb_CastToDouble = top_level_algo_B.data;
    if (top_level_algo_B.data > 255U) {
      rtb_CastToDouble = 255U;
    }

    writeDigitalPin(3, (uint8_T)rtb_CastToDouble);

    /* End of MATLABSystem: '<S2>/Digital Output3' */

    /* RateTransition generated from: '<Root>/Summarizing' */
    if (top_level_algo_M->Timing.RateInteraction.TID1_3) {
      /* RateTransition generated from: '<Root>/Summarizing' */
      top_level_algo_B.evaluating = top_level_algo_DW.evaluating_Buffer0;
    }

    /* End of RateTransition generated from: '<Root>/Summarizing' */

    /* Logic: '<S16>/AND' incorporates:
     *  Constant: '<S85>/Constant'
     *  Constant: '<S86>/Constant'
     *  RelationalOperator: '<S85>/Compare'
     *  RelationalOperator: '<S86>/Compare'
     */
    rtb_AND = ((Clock1 >= top_level_algo_P.CompareToConstant1_const) && (Clock1 <=
                top_level_algo_P.CompareToConstant2_const));

    /* RelationalOperator: '<S18>/Compare' incorporates:
     *  Constant: '<S18>/Constant'
     */
    rtb_Compare_bz = (top_level_algo_B.Merge <=
                      top_level_algo_P.CompareToConstant_const);

    /* RateTransition generated from: '<S12>/sample and hold' incorporates:
     *  RateTransition generated from: '<Root>/Summarizing'
     */
    if (top_level_algo_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition generated from: '<S12>/sample and hold' */
      top_level_algo_B.Max = top_level_algo_DW.Max_Buffer0;

      /* RateTransition generated from: '<Root>/Summarizing' */
      top_level_algo_B.TmpRTBAtSummarizingInport7 =
        top_level_algo_DW.TmpRTBAtSummarizingInport7_Buff;
    }

    /* End of RateTransition generated from: '<S12>/sample and hold' */

    /* Sum: '<S6>/Subtract3' */
    rtb_Subtract3 = top_level_algo_B.Max - top_level_algo_B.Merge;

    /* RelationalOperator: '<S5>/Compare' incorporates:
     *  Constant: '<S5>/Constant'
     */
    rtb_Compare_b = (rtb_Subtract3 >= top_level_algo_P.CompareToConstant_const_g);

    /* Chart: '<Root>/Summarizing' incorporates:
     *  Concatenate: '<Root>/Vector Concatenate'
     */
    if (top_level_algo_DW.temporalCounter_i1 < MAX_uint32_T) {
      top_level_algo_DW.temporalCounter_i1++;
    }

    if (top_level_algo_DW.is_active_c20_top_level_algo == 0U) {
      top_level_algo_DW.is_active_c20_top_level_algo = 1U;
      top_level_algo_DW.is_c20_top_level_algo = top_level_algo_IN_INIT_k;
      top_level_algo_DW.temporalCounter_i1 = 0U;
      top_level_algo_B.VectorConcatenate[0] = -1.0;
      top_level_algo_B.VectorConcatenate[1] = -1.0;
      top_level_algo_B.VectorConcatenate[2] = -1.0;
      top_level_algo_B.VectorConcatenate[8] = -1.0;
      top_level_algo_B.VectorConcatenate[6] = -1.0;
      top_level_algo_B.VectorConcatenate[7] = -1.0;
      top_level_algo_B.VectorConcatenate[5] = -1.0;
      top_level_algo_B.VectorConcatenate[4] = -1.0;
      top_level_algo_B.VectorConcatenate[3] = -1.0;
      top_level_algo_B.VectorConcatenate[9] = 0.0;
    } else {
      switch (top_level_algo_DW.is_c20_top_level_algo) {
       case top_level_algo_IN_EVALUATING_j:
        if ((!(top_level_algo_B.evaluating != 0.0)) && (top_level_algo_DW.comps >=
             4.0)) {
          top_level_algo_DW.is_EVALUATING = top_level_al_IN_NO_ACTIVE_CHILD;
          top_level_algo_B.VectorConcatenate[9] = (real_T)
            top_level_algo_DW.temporalCounter_i1 * 0.001;
          top_level_algo_DW.is_c20_top_level_algo =
            top_level__IN_LEARNINGAFTEREVAL;
          top_level_algo_B.VectorConcatenate[0] = 100.0 *
            top_level_algo_DW.depths / top_level_algo_DW.comps;
          top_level_algo_B.VectorConcatenate[1] = 100.0 *
            top_level_algo_DW.rates / top_level_algo_DW.comps;
          top_level_algo_B.VectorConcatenate[2] = 100.0 *
            top_level_algo_DW.recoils / top_level_algo_DW.comps;
          top_level_algo_B.VectorConcatenate[8] = top_level_algo_DW.rate_sum /
            top_level_algo_DW.comps;
          top_level_algo_B.VectorConcatenate[7] = top_level_algo_DW.max_r;
          top_level_algo_B.VectorConcatenate[6] = top_level_algo_DW.min_r;
          top_level_algo_B.VectorConcatenate[5] = top_level_algo_DW.depth_sum /
            top_level_algo_DW.comps;
          top_level_algo_B.VectorConcatenate[4] = top_level_algo_DW.max_d;
          top_level_algo_B.VectorConcatenate[3] = top_level_algo_DW.min_d;
        } else if ((!(top_level_algo_B.evaluating != 0.0)) &&
                   (top_level_algo_DW.comps < 4.0)) {
          top_level_algo_DW.is_EVALUATING = top_level_al_IN_NO_ACTIVE_CHILD;
          top_level_algo_B.VectorConcatenate[9] = (real_T)
            top_level_algo_DW.temporalCounter_i1 * 0.001;
          top_level_algo_DW.is_c20_top_level_algo = top_level_algo_IN_LEARNING;
        } else if (top_level_algo_DW.is_EVALUATING == top_level_algo_IN_CHECK) {
          top_level_algo_DW.is_EVALUATING = top_level_algo_IN_UPDATE;
          top_level_algo_DW.depths += (real_T)rtb_Compare_b;
          top_level_algo_DW.recoils += (real_T)rtb_Compare_bz;
          top_level_algo_DW.rates += (real_T)rtb_AND;
          top_level_algo_DW.depth_sum += rtb_Subtract3;
          top_level_algo_DW.rate_sum += Clock1;
          top_level_algo_DW.comps++;

          /* case IN_UPDATE: */
        } else if (top_level_algo_B.TmpRTBAtSummarizingInport7) {
          top_level_algo_DW.is_EVALUATING = top_level_algo_IN_CHECK;
          if ((Clock1 < top_level_algo_DW.min_r) && (Clock1 != 0.0)) {
            top_level_algo_DW.min_r = Clock1;
          } else if (Clock1 > top_level_algo_DW.max_r) {
            top_level_algo_DW.max_r = Clock1;
          }

          if ((rtb_Subtract3 < top_level_algo_DW.min_d) && (rtb_Subtract3 != 0.0))
          {
            top_level_algo_DW.min_d = rtb_Subtract3;
          } else if (rtb_Subtract3 > top_level_algo_DW.max_d) {
            top_level_algo_DW.max_d = rtb_Subtract3;
          }
        }
        break;

       case top_level_algo_IN_INIT_k:
        if (top_level_algo_DW.temporalCounter_i1 >= 1000U) {
          top_level_algo_DW.is_c20_top_level_algo = top_level_algo_IN_LEARNING;
        }
        break;

       case top_level_algo_IN_LEARNING:
        if ((top_level_algo_B.evaluating != 0.0) &&
            top_level_algo_B.TmpRTBAtSummarizingInport7) {
          top_level_algo_DW.min_r = 200.0;
          top_level_algo_DW.max_r = 0.0;
          top_level_algo_DW.min_d = 100.0;
          top_level_algo_DW.max_d = 0.0;
          top_level_algo_DW.is_c20_top_level_algo =
            top_level_algo_IN_EVALUATING_j;
          top_level_algo_DW.temporalCounter_i1 = 0U;
          top_level_algo_B.VectorConcatenate[0] = -1.0;
          top_level_algo_B.VectorConcatenate[1] = -1.0;
          top_level_algo_B.VectorConcatenate[2] = -1.0;
          top_level_algo_B.VectorConcatenate[8] = -1.0;
          top_level_algo_B.VectorConcatenate[6] = -1.0;
          top_level_algo_B.VectorConcatenate[7] = -1.0;
          top_level_algo_B.VectorConcatenate[5] = -1.0;
          top_level_algo_B.VectorConcatenate[4] = -1.0;
          top_level_algo_B.VectorConcatenate[3] = -1.0;
          top_level_algo_B.VectorConcatenate[9] = 0.0;
          top_level_algo_DW.is_EVALUATING = top_level_algo_IN_UPDATE;
          top_level_algo_DW.depths = rtb_Compare_b;
          top_level_algo_DW.recoils = rtb_Compare_bz;
          top_level_algo_DW.rates = rtb_AND;
          top_level_algo_DW.depth_sum = rtb_Subtract3;
          top_level_algo_DW.rate_sum = Clock1;
          top_level_algo_DW.comps = 1.0;
        }
        break;

       default:
        /* case IN_LEARNINGAFTEREVAL: */
        if (top_level_algo_B.evaluating != 0.0) {
          top_level_algo_DW.min_r = 200.0;
          top_level_algo_DW.max_r = 0.0;
          top_level_algo_DW.min_d = 100.0;
          top_level_algo_DW.max_d = 0.0;
          top_level_algo_DW.is_c20_top_level_algo =
            top_level_algo_IN_EVALUATING_j;
          top_level_algo_DW.temporalCounter_i1 = 0U;
          top_level_algo_B.VectorConcatenate[0] = -1.0;
          top_level_algo_B.VectorConcatenate[1] = -1.0;
          top_level_algo_B.VectorConcatenate[2] = -1.0;
          top_level_algo_B.VectorConcatenate[8] = -1.0;
          top_level_algo_B.VectorConcatenate[6] = -1.0;
          top_level_algo_B.VectorConcatenate[7] = -1.0;
          top_level_algo_B.VectorConcatenate[5] = -1.0;
          top_level_algo_B.VectorConcatenate[4] = -1.0;
          top_level_algo_B.VectorConcatenate[3] = -1.0;
          top_level_algo_B.VectorConcatenate[9] = 0.0;
          top_level_algo_DW.is_EVALUATING = top_level_algo_IN_UPDATE;
          top_level_algo_DW.depths = rtb_Compare_b;
          top_level_algo_DW.recoils = rtb_Compare_bz;
          top_level_algo_DW.rates = rtb_AND;
          top_level_algo_DW.depth_sum = rtb_Subtract3;
          top_level_algo_DW.rate_sum = Clock1;
          top_level_algo_DW.comps = 1.0;
        }
        break;
      }
    }

    /* End of Chart: '<Root>/Summarizing' */

    /* DataTypeConversion: '<S3>/Cast To Double1' */
    rtb_Subtract3 = floor(top_level_algo_B.VectorConcatenate[0]);
    if (rtIsNaN(rtb_Subtract3) || rtIsInf(rtb_Subtract3)) {
      rtb_Subtract3 = 0.0;
    } else {
      rtb_Subtract3 = fmod(rtb_Subtract3, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S3>/Cast To Double2' */
    top_level_algo_B.TmpMLSysMemLayoutBufferAt_p = floor
      (top_level_algo_B.VectorConcatenate[1]);
    if (rtIsNaN(top_level_algo_B.TmpMLSysMemLayoutBufferAt_p) || rtIsInf
        (top_level_algo_B.TmpMLSysMemLayoutBufferAt_p)) {
      top_level_algo_B.TmpMLSysMemLayoutBufferAt_p = 0.0;
    } else {
      top_level_algo_B.TmpMLSysMemLayoutBufferAt_p = fmod
        (top_level_algo_B.TmpMLSysMemLayoutBufferAt_p, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S3>/Cast To Double3' */
    top_level_algo_B.Mod1 = floor(top_level_algo_B.VectorConcatenate[2]);
    if (rtIsNaN(top_level_algo_B.Mod1) || rtIsInf(top_level_algo_B.Mod1)) {
      top_level_algo_B.Mod1 = 0.0;
    } else {
      top_level_algo_B.Mod1 = fmod(top_level_algo_B.Mod1, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S3>/Cast To Double4' */
    tmp = floor(top_level_algo_B.VectorConcatenate[3]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    /* Sum: '<S3>/Sum of Elements' incorporates:
     *  ArithShift: '<S3>/Shift Arithmetic1'
     *  ArithShift: '<S3>/Shift Arithmetic2'
     *  ArithShift: '<S3>/Shift Arithmetic3'
     *  DataTypeConversion: '<S3>/Cast To Double1'
     *  DataTypeConversion: '<S3>/Cast To Double2'
     *  DataTypeConversion: '<S3>/Cast To Double3'
     *  DataTypeConversion: '<S3>/Cast To Double4'
     */
    rtb_CastToDouble = ((((top_level_algo_B.TmpMLSysMemLayoutBufferAt_p < 0.0 ?
      (uint32_T)-(int32_T)(uint32_T)
      -top_level_algo_B.TmpMLSysMemLayoutBufferAt_p : (uint32_T)
      top_level_algo_B.TmpMLSysMemLayoutBufferAt_p) << 8) + (rtb_Subtract3 < 0.0
      ? (uint32_T)-(int32_T)(uint32_T)-rtb_Subtract3 : (uint32_T)rtb_Subtract3))
                        + ((top_level_algo_B.Mod1 < 0.0 ? (uint32_T)-(int32_T)
      (uint32_T)-top_level_algo_B.Mod1 : (uint32_T)top_level_algo_B.Mod1) << 16))
      + ((tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp) << 24);

    /* MATLABSystem: '<S3>/BLE Send11' */
    SEND_SERVER_DATA(top_level_algo_DW.obj_fk.Index, &rtb_CastToDouble, 4.0);

    /* DataTypeConversion: '<S3>/Cast To Double5' */
    rtb_Subtract3 = floor(top_level_algo_B.VectorConcatenate[4]);
    if (rtIsNaN(rtb_Subtract3) || rtIsInf(rtb_Subtract3)) {
      rtb_Subtract3 = 0.0;
    } else {
      rtb_Subtract3 = fmod(rtb_Subtract3, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S3>/Cast To Double6' */
    top_level_algo_B.TmpMLSysMemLayoutBufferAt_p = floor
      (top_level_algo_B.VectorConcatenate[5]);
    if (rtIsNaN(top_level_algo_B.TmpMLSysMemLayoutBufferAt_p) || rtIsInf
        (top_level_algo_B.TmpMLSysMemLayoutBufferAt_p)) {
      top_level_algo_B.TmpMLSysMemLayoutBufferAt_p = 0.0;
    } else {
      top_level_algo_B.TmpMLSysMemLayoutBufferAt_p = fmod
        (top_level_algo_B.TmpMLSysMemLayoutBufferAt_p, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S3>/Cast To Double7' */
    top_level_algo_B.Mod1 = floor(top_level_algo_B.VectorConcatenate[6]);
    if (rtIsNaN(top_level_algo_B.Mod1) || rtIsInf(top_level_algo_B.Mod1)) {
      top_level_algo_B.Mod1 = 0.0;
    } else {
      top_level_algo_B.Mod1 = fmod(top_level_algo_B.Mod1, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S3>/Cast To Double8' */
    tmp = floor(top_level_algo_B.VectorConcatenate[7]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    /* Sum: '<S3>/Sum of Elements1' incorporates:
     *  ArithShift: '<S3>/Shift Arithmetic4'
     *  ArithShift: '<S3>/Shift Arithmetic5'
     *  ArithShift: '<S3>/Shift Arithmetic6'
     *  DataTypeConversion: '<S3>/Cast To Double5'
     *  DataTypeConversion: '<S3>/Cast To Double6'
     *  DataTypeConversion: '<S3>/Cast To Double7'
     *  DataTypeConversion: '<S3>/Cast To Double8'
     */
    rtb_CastToDouble = ((((top_level_algo_B.TmpMLSysMemLayoutBufferAt_p < 0.0 ?
      (uint32_T)-(int32_T)(uint32_T)
      -top_level_algo_B.TmpMLSysMemLayoutBufferAt_p : (uint32_T)
      top_level_algo_B.TmpMLSysMemLayoutBufferAt_p) << 8) + (rtb_Subtract3 < 0.0
      ? (uint32_T)-(int32_T)(uint32_T)-rtb_Subtract3 : (uint32_T)rtb_Subtract3))
                        + ((top_level_algo_B.Mod1 < 0.0 ? (uint32_T)-(int32_T)
      (uint32_T)-top_level_algo_B.Mod1 : (uint32_T)top_level_algo_B.Mod1) << 16))
      + ((tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp) << 24);

    /* MATLABSystem: '<S3>/BLE Send12' */
    SEND_SERVER_DATA(top_level_algo_DW.obj_pa.Index, &rtb_CastToDouble, 4.0);

    /* DataTypeConversion: '<S3>/Cast To Double9' */
    rtb_Subtract3 = floor(top_level_algo_B.VectorConcatenate[8]);
    if (rtIsNaN(rtb_Subtract3) || rtIsInf(rtb_Subtract3)) {
      rtb_Subtract3 = 0.0;
    } else {
      rtb_Subtract3 = fmod(rtb_Subtract3, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S3>/Cast To Double10' */
    top_level_algo_B.TmpMLSysMemLayoutBufferAt_p = floor
      (top_level_algo_B.VectorConcatenate[9]);
    if (rtIsNaN(top_level_algo_B.TmpMLSysMemLayoutBufferAt_p) || rtIsInf
        (top_level_algo_B.TmpMLSysMemLayoutBufferAt_p)) {
      top_level_algo_B.TmpMLSysMemLayoutBufferAt_p = 0.0;
    } else {
      top_level_algo_B.TmpMLSysMemLayoutBufferAt_p = fmod
        (top_level_algo_B.TmpMLSysMemLayoutBufferAt_p, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S3>/Cast To Double11' incorporates:
     *  Constant: '<S3>/Constant'
     */
    top_level_algo_B.Mod1 = floor(top_level_algo_P.Constant_Value_o);
    if (rtIsNaN(top_level_algo_B.Mod1) || rtIsInf(top_level_algo_B.Mod1)) {
      top_level_algo_B.Mod1 = 0.0;
    } else {
      top_level_algo_B.Mod1 = fmod(top_level_algo_B.Mod1, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S3>/Cast To Double12' incorporates:
     *  Constant: '<S3>/Constant1'
     */
    tmp = floor(top_level_algo_P.Constant1_Value_c);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    /* Sum: '<S3>/Sum of Elements2' incorporates:
     *  ArithShift: '<S3>/Shift Arithmetic7'
     *  ArithShift: '<S3>/Shift Arithmetic8'
     *  ArithShift: '<S3>/Shift Arithmetic9'
     *  DataTypeConversion: '<S3>/Cast To Double10'
     *  DataTypeConversion: '<S3>/Cast To Double11'
     *  DataTypeConversion: '<S3>/Cast To Double12'
     *  DataTypeConversion: '<S3>/Cast To Double9'
     */
    rtb_CastToDouble = ((((top_level_algo_B.TmpMLSysMemLayoutBufferAt_p < 0.0 ?
      (uint32_T)-(int32_T)(uint32_T)
      -top_level_algo_B.TmpMLSysMemLayoutBufferAt_p : (uint32_T)
      top_level_algo_B.TmpMLSysMemLayoutBufferAt_p) << 8) + (rtb_Subtract3 < 0.0
      ? (uint32_T)-(int32_T)(uint32_T)-rtb_Subtract3 : (uint32_T)rtb_Subtract3))
                        + ((top_level_algo_B.Mod1 < 0.0 ? (uint32_T)-(int32_T)
      (uint32_T)-top_level_algo_B.Mod1 : (uint32_T)top_level_algo_B.Mod1) << 16))
      + ((tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp) << 24);

    /* MATLABSystem: '<S3>/BLE Send13' */
    SEND_SERVER_DATA(top_level_algo_DW.obj_i.Index, &rtb_CastToDouble, 4.0);

    /* RateTransition generated from: '<Root>/Mode' */
    if (top_level_algo_M->Timing.RateInteraction.TID1_3) {
      /* RateTransition generated from: '<Root>/Mode' */
      top_level_algo_B.TmpRTBAtModeOutport2 =
        top_level_algo_DW.TmpRTBAtModeOutport2_Buffer0;
    }

    /* End of RateTransition generated from: '<Root>/Mode' */

    /* Switch: '<S14>/Switch1' incorporates:
     *  Constant: '<S14>/Constant3'
     */
    if (top_level_algo_B.TmpRTBAtModeOutport2 >
        top_level_algo_P.Switch1_Threshold) {
      /* Switch: '<S4>/Switch' incorporates:
       *  Constant: '<S4>/Constant'
       *  Logic: '<S4>/NOT'
       *  SignalConversion generated from: '<S4>/Vector Concatenate'
       */
      if (top_level_algo_B.recoil_active > top_level_algo_P.Switch_Threshold) {
        rtb_Subtract3 = rtb_Compare_bz;
        top_level_algo_B.TmpMLSysMemLayoutBufferAt_p = !rtb_Compare_bz;
      } else {
        rtb_Subtract3 = top_level_algo_P.Constant_Value[0];
        top_level_algo_B.TmpMLSysMemLayoutBufferAt_p =
          top_level_algo_P.Constant_Value[1];
      }

      /* End of Switch: '<S4>/Switch' */
    } else {
      rtb_Subtract3 = top_level_algo_P.Constant3_Value[0];
      top_level_algo_B.TmpMLSysMemLayoutBufferAt_p =
        top_level_algo_P.Constant3_Value[1];
    }

    /* End of Switch: '<S14>/Switch1' */

    /* MATLABSystem: '<S14>/Digital Output8' */
    rtb_Subtract3 = rt_roundd_snf(rtb_Subtract3);
    if (rtb_Subtract3 < 256.0) {
      if (rtb_Subtract3 >= 0.0) {
        Merge_j = (uint8_T)rtb_Subtract3;
      } else {
        Merge_j = 0U;
      }
    } else {
      Merge_j = MAX_uint8_T;
    }

    writeDigitalPin(23, Merge_j);

    /* End of MATLABSystem: '<S14>/Digital Output8' */

    /* MATLABSystem: '<S14>/Digital Output9' */
    rtb_Subtract3 = rt_roundd_snf(top_level_algo_B.TmpMLSysMemLayoutBufferAt_p);
    if (rtb_Subtract3 < 256.0) {
      if (rtb_Subtract3 >= 0.0) {
        Merge_j = (uint8_T)rtb_Subtract3;
      } else {
        Merge_j = 0U;
      }
    } else {
      Merge_j = MAX_uint8_T;
    }

    writeDigitalPin(22, Merge_j);

    /* End of MATLABSystem: '<S14>/Digital Output9' */

    /* Switch: '<S83>/Switch' incorporates:
     *  Constant: '<S84>/Constant'
     *  DataTypeConversion: '<S83>/Cast To Single'
     *  RelationalOperator: '<S84>/Compare'
     */
    if (!((real32_T)rtb_NOT1_j >= top_level_algo_P.CompareToConstant_const_f)) {
      /* Sum: '<S83>/Sum' incorporates:
       *  Constant: '<S83>/Constant1'
       *  Switch: '<S83>/Switch'
       */
      rtb_Switch = top_level_algo_P.Constant1_Value_b;
    }

    /* End of Switch: '<S83>/Switch' */

    /* Chart: '<S15>/Write Logic' */
    if (top_level_algo_DW.temporalCounter_i1_f < 2047U) {
      top_level_algo_DW.temporalCounter_i1_f++;
    }

    if (top_level_algo_DW.is_active_c19_top_level_algo == 0U) {
      top_level_algo_DW.is_active_c19_top_level_algo = 1U;
      top_level_algo_DW.is_c19_top_level_algo = top_level_algo_IN_INITIALIZE;
      top_level_algo_DW.temporalCounter_i1_f = 0U;
      top_level_algo_DW.old_cpm = 0.0;
    } else {
      switch (top_level_algo_DW.is_c19_top_level_algo) {
       case top_level_algo_IN_CHECKING:
        if (top_level_algo_DW.old_cpm != Clock1) {
          top_level_algo_DW.old_cpm = Clock1;
          top_level_algo_DW.is_c19_top_level_algo =
            top_level_algo_IN_WRITE_TRIGGER;
          top_level_algo_DW.temporalCounter_i1_f = 0U;
        }
        break;

       case top_level_algo_IN_DELAY:
        if (top_level_algo_DW.temporalCounter_i1_f >= 300U) {
          top_level_algo_DW.is_c19_top_level_algo = top_level_algo_IN_CHECKING;
        }
        break;

       case top_level_algo_IN_INITIALIZE:
        if (top_level_algo_DW.temporalCounter_i1_f >= 2000U) {
          top_level_algo_DW.is_c19_top_level_algo = top_level_algo_IN_CHECKING;
        }
        break;

       default:
        /* case IN_WRITE_TRIGGER: */
        if (top_level_algo_DW.temporalCounter_i1_f >= 2U) {
          top_level_algo_DW.is_c19_top_level_algo = top_level_algo_IN_DELAY;
          top_level_algo_DW.temporalCounter_i1_f = 0U;
        }
        break;
      }
    }

    /* End of Chart: '<S15>/Write Logic' */
  }

  {
    int_T idxDelay;

    /* Update for Delay: '<S83>/Delay' */
    top_level_algo_DW.Delay_DSTATE[0] = top_level_algo_DW.Delay_DSTATE[1];

    /* Update for Delay: '<S15>/Delay' */
    top_level_algo_DW.Delay_DSTATE_d[0] = top_level_algo_DW.Delay_DSTATE_d[1];

    /* Update for Delay: '<S83>/Delay' */
    top_level_algo_DW.Delay_DSTATE[1] = top_level_algo_DW.Delay_DSTATE[2];

    /* Update for Delay: '<S15>/Delay' */
    top_level_algo_DW.Delay_DSTATE_d[1] = top_level_algo_DW.Delay_DSTATE_d[2];

    /* Update for Delay: '<S83>/Delay' */
    top_level_algo_DW.Delay_DSTATE[2] = top_level_algo_DW.Delay_DSTATE[3];

    /* Update for Delay: '<S15>/Delay' */
    top_level_algo_DW.Delay_DSTATE_d[2] = top_level_algo_DW.Delay_DSTATE_d[3];

    /* Update for Delay: '<S83>/Delay' */
    top_level_algo_DW.Delay_DSTATE[3] = rtb_Switch;

    /* Update for Delay: '<S15>/Delay' */
    top_level_algo_DW.Delay_DSTATE_d[3] = rtb_PulseGenerator;

    /* Update for Delay: '<S15>/Delay8' */
    for (idxDelay = 0; idxDelay < 287; idxDelay++) {
      top_level_algo_DW.Delay8_DSTATE[idxDelay] =
        top_level_algo_DW.Delay8_DSTATE[idxDelay + 1];
    }

    top_level_algo_DW.Delay8_DSTATE[287] = rtb_LogicalOperator;

    /* End of Update for Delay: '<S15>/Delay8' */
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  top_level_algo_M->Timing.t[0] =
    ((time_T)(++top_level_algo_M->Timing.clockTick0)) *
    top_level_algo_M->Timing.stepSize0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.001, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  top_level_algo_M->Timing.clockTick1++;
}

/* Model step function for TID2 */
void top_level_algo_step2(void)        /* Sample time: [0.005s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_Merge_n;
  real_T rtb_Reset;
  real_T rtb_Reset_b;
  boolean_T rtb_IsPos;
  boolean_T rtb_IsNeg;
  boolean_T rtb_LogicalOperator3;
  boolean_T rtb_LogicalOperator7;
  boolean_T rtb_NOT_c;
  boolean_T rtb_NOT2;

  {
    codertarget_arduinobase_inter_T *obj;
    int32_T i;
    int32_T rtb_measure_period;
    int32_T str;
    real32_T Mean_AccVal_f;
    uint16_T b_varargout_1;
    uint8_T tmp;
    boolean_T Delay7_DSTATE_l_tmp;
    boolean_T rtb_AND;
    boolean_T rtb_IsZero_tmp;
    boolean_T rtb_NOT_c_tmp;

    /* S-Function (sdspstatfcns): '<S10>/Mean1' incorporates:
     *  S-Function (sfix_udelay): '<S10>/Tapped Delay1'
     */
    top_level_algo_B.Mean1_AccVal = top_level_algo_DW.TappedDelay1_X[0];
    str = 1;
    for (i = 18; i >= 0; i--) {
      top_level_algo_B.Mean1_AccVal += top_level_algo_DW.TappedDelay1_X[str];
      str++;
    }

    /* Chart: '<S10>/timer' incorporates:
     *  S-Function (sdspstatfcns): '<S10>/Mean1'
     */
    if (top_level_algo_DW.temporalCounter_i1_c < 511U) {
      top_level_algo_DW.temporalCounter_i1_c++;
    }

    if (top_level_algo_DW.is_active_c3_top_level_algo == 0U) {
      top_level_algo_DW.is_active_c3_top_level_algo = 1U;
      top_level_algo_DW.is_c3_top_level_algo = top_level_algo_IN_Starting;
      top_level_algo_DW.temporalCounter_i1_c = 0U;
      rtb_measure_period = 0;
    } else if (top_level_algo_DW.is_c3_top_level_algo ==
               top_level_algo_IN_Finished) {
      rtb_measure_period = 1;
    } else {
      /* case IN_Starting: */
      rtb_measure_period = 0;
      if (top_level_algo_DW.temporalCounter_i1_c >= 400U) {
        top_level_algo_DW.is_c3_top_level_algo = top_level_algo_IN_Finished;
        top_level_algo_B.baseline = top_level_algo_B.Mean1_AccVal / 20.0;
        rtb_measure_period = 1;
      }
    }

    /* End of Chart: '<S10>/timer' */

    /* S-Function (sdspstatfcns): '<S10>/Mean' incorporates:
     *  S-Function (sfix_udelay): '<S10>/Tapped Delay'
     */
    Mean_AccVal_f = top_level_algo_DW.TappedDelay_X_f[0];
    str = 1;
    for (i = 8; i >= 0; i--) {
      Mean_AccVal_f += top_level_algo_DW.TappedDelay_X_f[str];
      str++;
    }

    /* Product: '<S10>/Product' incorporates:
     *  Constant: '<S10>/Constant'
     *  Constant: '<S10>/Constant1'
     *  Product: '<S10>/Divide'
     *  S-Function (sdspstatfcns): '<S10>/Mean'
     */
    top_level_algo_B.Product = Mean_AccVal_f / 10.0F /
      top_level_algo_P.Constant1_Value_d * top_level_algo_P.Vdd;

    /* Switch: '<S10>/Switch' */
    if (rtb_measure_period > top_level_algo_P.Switch_Threshold_c) {
      top_level_algo_B.Mean1_AccVal = top_level_algo_B.baseline;
    } else {
      top_level_algo_B.Mean1_AccVal = top_level_algo_B.Product;
    }

    /* Gain: '<S10>/Radius (mm)' incorporates:
     *  Gain: '<S10>/Gear Down'
     *  Gain: '<S10>/rad  per volt'
     *  Sum: '<S10>/Subtract'
     *  Switch: '<S10>/Switch'
     */
    rtb_Merge_n = 6.2831853071795862 / top_level_algo_P.Vdd *
      (top_level_algo_B.Mean1_AccVal - top_level_algo_B.Product) * (1.0 /
      top_level_algo_P.gear_ratio) * top_level_algo_P.Radiusmm_Gain;

    /* If: '<S68>/If' */
    if (rtb_Merge_n < 0.0) {
      /* Outputs for IfAction SubSystem: '<S68>/If Action Subsystem' incorporates:
       *  ActionPort: '<S70>/Action Port'
       */
      /* Gain: '<S10>/Radius (mm)' incorporates:
       *  Constant: '<S68>/Constant'
       *  Merge: '<S68>/Merge'
       *  SignalConversion generated from: '<S70>/In1'
       */
      rtb_Merge_n = top_level_algo_P.Constant_Value_a;

      /* End of Outputs for SubSystem: '<S68>/If Action Subsystem' */
    }

    /* End of If: '<S68>/If' */

    /* RateTransition generated from: '<Root>/Mode' */
    if (top_level_algo_M->Timing.RateInteraction.TID2_3) {
      /* RateTransition generated from: '<Root>/Mode' */
      top_level_algo_B.TmpRTBAtModeOutport1 =
        top_level_algo_DW.TmpRTBAtModeOutport1_Buffer0;
    }

    /* End of RateTransition generated from: '<Root>/Mode' */

    /* Switch: '<S7>/Switch' incorporates:
     *  Constant: '<S60>/Constant'
     *  Constant: '<S61>/Constant'
     *  Constant: '<S62>/Constant'
     *  Constant: '<S63>/Constant'
     *  Constant: '<S7>/Constant2'
     *  RelationalOperator: '<S60>/Compare'
     *  RelationalOperator: '<S61>/Compare'
     *  RelationalOperator: '<S62>/Compare'
     *  RelationalOperator: '<S63>/Compare'
     */
    if (top_level_algo_B.TmpRTBAtModeOutport1 >
        top_level_algo_P.Switch_Threshold_j) {
      top_level_algo_B.Mean1_AccVal = (rtb_Merge_n >
        top_level_algo_P.CompareToConstant1_const_k);
      top_level_algo_B.rtb_Switch_j_idx_1 = (rtb_Merge_n >
        top_level_algo_P.CompareToConstant2_const_h);
      top_level_algo_B.rtb_Switch_j_idx_2 = (rtb_Merge_n >
        top_level_algo_P.CompareToConstant3_const);
      top_level_algo_B.rtb_Switch_j_idx_3 = (rtb_Merge_n >
        top_level_algo_P.CompareToConstant4_const);
    } else {
      top_level_algo_B.Mean1_AccVal = top_level_algo_P.Constant2_Value[0];
      top_level_algo_B.rtb_Switch_j_idx_1 = top_level_algo_P.Constant2_Value[1];
      top_level_algo_B.rtb_Switch_j_idx_2 = top_level_algo_P.Constant2_Value[2];
      top_level_algo_B.rtb_Switch_j_idx_3 = top_level_algo_P.Constant2_Value[3];
    }

    /* End of Switch: '<S7>/Switch' */

    /* MATLABSystem: '<S7>/Digital Output4' */
    top_level_algo_B.Mean1_AccVal = rt_roundd_snf(top_level_algo_B.Mean1_AccVal);
    if (top_level_algo_B.Mean1_AccVal < 256.0) {
      if (top_level_algo_B.Mean1_AccVal >= 0.0) {
        tmp = (uint8_T)top_level_algo_B.Mean1_AccVal;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(33, tmp);

    /* End of MATLABSystem: '<S7>/Digital Output4' */

    /* MATLABSystem: '<S7>/Digital Output5' */
    top_level_algo_B.Mean1_AccVal = rt_roundd_snf
      (top_level_algo_B.rtb_Switch_j_idx_1);
    if (top_level_algo_B.Mean1_AccVal < 256.0) {
      if (top_level_algo_B.Mean1_AccVal >= 0.0) {
        tmp = (uint8_T)top_level_algo_B.Mean1_AccVal;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(25, tmp);

    /* End of MATLABSystem: '<S7>/Digital Output5' */

    /* MATLABSystem: '<S7>/Digital Output6' */
    top_level_algo_B.Mean1_AccVal = rt_roundd_snf
      (top_level_algo_B.rtb_Switch_j_idx_2);
    if (top_level_algo_B.Mean1_AccVal < 256.0) {
      if (top_level_algo_B.Mean1_AccVal >= 0.0) {
        tmp = (uint8_T)top_level_algo_B.Mean1_AccVal;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(26, tmp);

    /* End of MATLABSystem: '<S7>/Digital Output6' */

    /* MATLABSystem: '<S7>/Digital Output7' */
    top_level_algo_B.Mean1_AccVal = rt_roundd_snf
      (top_level_algo_B.rtb_Switch_j_idx_3);
    if (top_level_algo_B.Mean1_AccVal < 256.0) {
      if (top_level_algo_B.Mean1_AccVal >= 0.0) {
        tmp = (uint8_T)top_level_algo_B.Mean1_AccVal;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(27, tmp);

    /* End of MATLABSystem: '<S7>/Digital Output7' */

    /* MATLABSystem: '<Root>/Analog Input' */
    if (top_level_algo_DW.obj.SampleTime !=
        top_level_algo_P.AnalogInput_SampleTime) {
      top_level_algo_DW.obj.SampleTime = top_level_algo_P.AnalogInput_SampleTime;
    }

    obj = &top_level_algo_DW.obj;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(15U);
    top_level_algo_B.datatype_id = MW_ANALOGIN_UINT16;
    MW_AnalogInSingle_ReadResult
      (top_level_algo_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
       &b_varargout_1, top_level_algo_B.datatype_id);

    /* DataTypeConversion: '<Root>/Cast To Single2' incorporates:
     *  MATLABSystem: '<Root>/Analog Input'
     */
    top_level_algo_B.CastToSingle2 = b_varargout_1;

    /* Sum: '<S9>/First Diff' incorporates:
     *  Delay: '<S9>/Delay'
     */
    top_level_algo_B.Mean1_AccVal = rtb_Merge_n -
      top_level_algo_DW.Delay_DSTATE_dt;

    /* Sum: '<S9>/Second Diff' incorporates:
     *  Delay: '<S9>/Delay'
     *  Delay: '<S9>/Delay1'
     */
    top_level_algo_B.rtb_Switch_j_idx_3 = top_level_algo_DW.Delay_DSTATE_dt -
      top_level_algo_DW.Delay1_DSTATE[0];

    /* Sum: '<S9>/Third Diff' incorporates:
     *  Delay: '<S9>/Delay1'
     *  Delay: '<S9>/Delay2'
     */
    top_level_algo_B.u = top_level_algo_DW.Delay1_DSTATE[0] -
      top_level_algo_DW.Delay2_DSTATE[0];

    /* Sum: '<S9>/Fourth Diff' incorporates:
     *  Delay: '<S9>/Delay2'
     *  Delay: '<S9>/Delay3'
     */
    top_level_algo_B.u_m = top_level_algo_DW.Delay2_DSTATE[0] -
      top_level_algo_DW.Delay3_DSTATE[0];

    /* Sum: '<S9>/Fifth Diff' incorporates:
     *  Delay: '<S9>/Delay3'
     *  Delay: '<S9>/Delay4'
     */
    top_level_algo_B.rtb_Switch_j_idx_2 = top_level_algo_DW.Delay3_DSTATE[0] -
      top_level_algo_DW.Delay4_DSTATE[0];

    /* Sum: '<S9>/5to30 Diff' incorporates:
     *  Delay: '<S9>/Delay4'
     *  Delay: '<S9>/Delay5'
     */
    top_level_algo_B.rtb_Switch_j_idx_1 = top_level_algo_DW.Delay4_DSTATE[0] -
      top_level_algo_DW.Delay5_DSTATE[0];

    /* Signum: '<S9>/Sign' */
    if (rtIsNaN(top_level_algo_B.Mean1_AccVal)) {
      top_level_algo_B.Mean1_AccVal = (rtNaN);
    } else if (top_level_algo_B.Mean1_AccVal < 0.0) {
      top_level_algo_B.Mean1_AccVal = -1.0;
    } else {
      top_level_algo_B.Mean1_AccVal = (top_level_algo_B.Mean1_AccVal > 0.0);
    }

    /* Signum: '<S9>/Sign1' */
    if (rtIsNaN(top_level_algo_B.rtb_Switch_j_idx_3)) {
      top_level_algo_B.rtb_Switch_j_idx_3 = (rtNaN);
    } else if (top_level_algo_B.rtb_Switch_j_idx_3 < 0.0) {
      top_level_algo_B.rtb_Switch_j_idx_3 = -1.0;
    } else {
      top_level_algo_B.rtb_Switch_j_idx_3 = (top_level_algo_B.rtb_Switch_j_idx_3
        > 0.0);
    }

    /* Signum: '<S9>/Sign2' */
    if (rtIsNaN(top_level_algo_B.u)) {
      top_level_algo_B.u = (rtNaN);
    } else if (top_level_algo_B.u < 0.0) {
      top_level_algo_B.u = -1.0;
    } else {
      top_level_algo_B.u = (top_level_algo_B.u > 0.0);
    }

    /* Signum: '<S9>/Sign3' */
    if (rtIsNaN(top_level_algo_B.u_m)) {
      top_level_algo_B.u_m = (rtNaN);
    } else if (top_level_algo_B.u_m < 0.0) {
      top_level_algo_B.u_m = -1.0;
    } else {
      top_level_algo_B.u_m = (top_level_algo_B.u_m > 0.0);
    }

    /* Signum: '<S9>/Sign4' */
    if (rtIsNaN(top_level_algo_B.rtb_Switch_j_idx_2)) {
      top_level_algo_B.rtb_Switch_j_idx_2 = (rtNaN);
    } else if (top_level_algo_B.rtb_Switch_j_idx_2 < 0.0) {
      top_level_algo_B.rtb_Switch_j_idx_2 = -1.0;
    } else {
      top_level_algo_B.rtb_Switch_j_idx_2 = (top_level_algo_B.rtb_Switch_j_idx_2
        > 0.0);
    }

    /* Signum: '<S9>/Sign5' */
    if (rtIsNaN(top_level_algo_B.rtb_Switch_j_idx_1)) {
      top_level_algo_B.rtb_Switch_j_idx_1 = (rtNaN);
    } else if (top_level_algo_B.rtb_Switch_j_idx_1 < 0.0) {
      top_level_algo_B.rtb_Switch_j_idx_1 = -1.0;
    } else {
      top_level_algo_B.rtb_Switch_j_idx_1 = (top_level_algo_B.rtb_Switch_j_idx_1
        > 0.0);
    }

    /* Sum: '<S9>/Add' incorporates:
     *  Gain: '<S9>/Gain'
     *  Gain: '<S9>/Gain1'
     *  Signum: '<S9>/Sign'
     *  Signum: '<S9>/Sign1'
     *  Signum: '<S9>/Sign2'
     *  Signum: '<S9>/Sign3'
     *  Signum: '<S9>/Sign4'
     *  Signum: '<S9>/Sign5'
     */
    top_level_algo_B.Mean1_AccVal = ((((top_level_algo_P.Gain_Gain *
      top_level_algo_B.Mean1_AccVal + top_level_algo_P.Gain1_Gain *
      top_level_algo_B.rtb_Switch_j_idx_3) + top_level_algo_B.u) +
      top_level_algo_B.u_m) + top_level_algo_B.rtb_Switch_j_idx_2) +
      top_level_algo_B.rtb_Switch_j_idx_1;

    /* S-Function (sfix_udelay): '<S9>/Tapped Delay' */
    memcpy(&top_level_algo_B.TappedDelay[0], &top_level_algo_DW.TappedDelay_X[0],
           10U * sizeof(real_T));

    /* S-Function (sdspstatfcns): '<S9>/Mean' */
    top_level_algo_B.rtb_Switch_j_idx_1 = top_level_algo_B.TappedDelay[0];
    str = 1;
    for (i = 8; i >= 0; i--) {
      top_level_algo_B.rtb_Switch_j_idx_1 += top_level_algo_B.TappedDelay[str];
      str++;
    }

    /* Gain: '<S9>/Compression  Sensitivity' incorporates:
     *  S-Function (sdspstatfcns): '<S9>/Mean'
     */
    top_level_algo_B.rtb_Switch_j_idx_1 = top_level_algo_B.rtb_Switch_j_idx_1 /
      10.0 * top_level_algo_P.CompressionSensitivity_Gain;

    /* Logic: '<S9>/AND' incorporates:
     *  Constant: '<S65>/Constant'
     *  Constant: '<S67>/Constant'
     *  RelationalOperator: '<S65>/Compare'
     *  RelationalOperator: '<S67>/Compare'
     */
    rtb_IsPos = ((top_level_algo_B.Mean1_AccVal >=
                  top_level_algo_P.Positive_const) &&
                 (top_level_algo_B.rtb_Switch_j_idx_1 >=
                  top_level_algo_P.Longrangemotionup_const));

    /* Logic: '<S9>/AND1' incorporates:
     *  Constant: '<S64>/Constant'
     *  Constant: '<S66>/Constant'
     *  RelationalOperator: '<S64>/Compare'
     *  RelationalOperator: '<S66>/Compare'
     */
    rtb_IsNeg = ((top_level_algo_B.Mean1_AccVal <=
                  top_level_algo_P.Negative_const) &&
                 (top_level_algo_B.rtb_Switch_j_idx_1 <=
                  top_level_algo_P.Longrangemotiondown_const));

    /* Logic: '<S12>/Logical Operator' incorporates:
     *  Logic: '<S12>/OR1'
     *  Logic: '<S9>/Zero'
     */
    Delay7_DSTATE_l_tmp = !rtb_IsNeg;

    /* Logic: '<S12>/Logical Operator1' incorporates:
     *  Delay: '<S12>/Delay7'
     *  Delay: '<S12>/Delay8'
     *  Logic: '<S12>/Logical Operator'
     *  Logic: '<S12>/Logical Operator2'
     */
    top_level_algo_DW.Delay7_DSTATE_l = (Delay7_DSTATE_l_tmp &&
      (top_level_algo_DW.Delay8_DSTATE_b[0] || top_level_algo_DW.Delay7_DSTATE_l));

    /* Logic: '<S12>/Logical Operator3' incorporates:
     *  Delay: '<S12>/Delay7'
     *  Logic: '<S12>/NOT4'
     */
    rtb_LogicalOperator3 = (rtb_IsPos && (!top_level_algo_DW.Delay7_DSTATE_l));

    /* Logic: '<S12>/AND' incorporates:
     *  Delay: '<S12>/Delay6'
     *  Logic: '<S12>/NOT3'
     */
    rtb_AND = (rtb_LogicalOperator3 && (!top_level_algo_DW.Delay6_DSTATE[0]));

    /* RateTransition generated from: '<S6>/Chart1' */
    top_level_algo_DW.TmpRTBAtChart1Inport2_Buffer0 = rtb_AND;

    /* Sum: '<S9>/30 Diff' incorporates:
     *  Delay: '<S9>/Delay5'
     */
    top_level_algo_B.u0Diff = rtb_Merge_n - top_level_algo_DW.Delay5_DSTATE[0];

    /* Logic: '<S9>/Zero' incorporates:
     *  Logic: '<S12>/Logical Operator4'
     *  Logic: '<S12>/OR'
     */
    rtb_IsZero_tmp = !rtb_IsPos;

    /* Logic: '<S12>/Logical Operator5' incorporates:
     *  Delay: '<S12>/Delay1'
     *  Delay: '<S12>/Delay4'
     *  Logic: '<S12>/Logical Operator6'
     */
    top_level_algo_DW.Delay1_DSTATE_m = (rtb_IsZero_tmp &&
      (top_level_algo_DW.Delay4_DSTATE_a[0] || top_level_algo_DW.Delay1_DSTATE_m));

    /* Logic: '<S12>/Logical Operator7' incorporates:
     *  Delay: '<S12>/Delay1'
     *  Logic: '<S12>/NOT5'
     */
    rtb_LogicalOperator7 = (rtb_IsNeg && (!top_level_algo_DW.Delay1_DSTATE_m));

    /* Switch: '<S77>/Reset' incorporates:
     *  Delay: '<S12>/Delay'
     *  Memory: '<S77>/Memory'
     *  MinMax: '<S72>/MinMax'
     */
    if (top_level_algo_DW.Delay_DSTATE_a[0U]) {
      /* Switch: '<S77>/Reset' incorporates:
       *  Constant: '<S77>/Initial Condition'
       */
      rtb_Reset = top_level_algo_P.MaxBDC_vinit;
    } else if ((rtb_Merge_n >= top_level_algo_DW.Memory_PreviousInput) ||
               rtIsNaN(top_level_algo_DW.Memory_PreviousInput)) {
      /* MinMax: '<S72>/MinMax' incorporates:
       *  Switch: '<S77>/Reset'
       */
      rtb_Reset = rtb_Merge_n;
    } else {
      /* Switch: '<S77>/Reset' incorporates:
       *  Memory: '<S77>/Memory'
       *  MinMax: '<S72>/MinMax'
       */
      rtb_Reset = top_level_algo_DW.Memory_PreviousInput;
    }

    /* End of Switch: '<S77>/Reset' */

    /* Chart: '<S12>/sample and hold' incorporates:
     *  Delay: '<S12>/Delay3'
     *  Logic: '<S12>/AND1'
     *  Logic: '<S12>/NOT1'
     */
    top_level_alg_sampleandhold(rtb_Reset, rtb_LogicalOperator7 &&
      (!top_level_algo_DW.Delay3_DSTATE_m[0]), &top_level_algo_B.displacement_a,
      &top_level_algo_DW.sf_sampleandhold);

    /* RateTransition generated from: '<S12>/sample and hold' */
    top_level_algo_DW.Max_Buffer0 = top_level_algo_B.displacement_a;

    /* Switch: '<S78>/Reset' incorporates:
     *  Delay: '<S12>/Delay2'
     *  Memory: '<S78>/Memory'
     *  MinMax: '<S73>/MinMax'
     */
    if (top_level_algo_DW.Delay2_DSTATE_m[0U]) {
      /* Switch: '<S78>/Reset' incorporates:
       *  Constant: '<S78>/Initial Condition'
       */
      rtb_Reset_b = top_level_algo_P.MinBDC_vinit;
    } else if ((rtb_Merge_n <= top_level_algo_DW.Memory_PreviousInput_m) ||
               rtIsNaN(top_level_algo_DW.Memory_PreviousInput_m)) {
      /* MinMax: '<S73>/MinMax' incorporates:
       *  Switch: '<S78>/Reset'
       */
      rtb_Reset_b = rtb_Merge_n;
    } else {
      /* Switch: '<S78>/Reset' incorporates:
       *  Memory: '<S78>/Memory'
       *  MinMax: '<S73>/MinMax'
       */
      rtb_Reset_b = top_level_algo_DW.Memory_PreviousInput_m;
    }

    /* End of Switch: '<S78>/Reset' */

    /* Logic: '<S12>/OR' incorporates:
     *  Logic: '<S12>/OR1'
     *  Logic: '<S9>/Zero'
     */
    rtb_NOT_c_tmp = ((!rtb_IsZero_tmp) || (!Delay7_DSTATE_l_tmp));

    /* Logic: '<S12>/NOT' incorporates:
     *  Logic: '<S12>/OR'
     */
    rtb_NOT_c = (rtb_IsZero_tmp && rtb_NOT_c_tmp);

    /* Logic: '<S12>/NOT2' incorporates:
     *  Logic: '<S12>/OR1'
     */
    rtb_NOT2 = (rtb_NOT_c_tmp && Delay7_DSTATE_l_tmp);

    /* Chart: '<S12>/sample and hold1' */
    top_level_alg_sampleandhold(rtb_Reset_b, rtb_AND,
      &top_level_algo_B.displacement, &top_level_algo_DW.sf_sampleandhold1);

    /* If: '<S74>/If' */
    if (top_level_algo_B.displacement < 0.0) {
      /* Outputs for IfAction SubSystem: '<S74>/If Action Subsystem' incorporates:
       *  ActionPort: '<S79>/Action Port'
       */
      /* Merge: '<S74>/Merge' incorporates:
       *  Constant: '<S74>/Constant'
       *  SignalConversion generated from: '<S79>/In1'
       */
      top_level_algo_B.Merge = top_level_algo_P.Constant_Value_i;

      /* End of Outputs for SubSystem: '<S74>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S74>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S80>/Action Port'
       */
      /* Merge: '<S74>/Merge' incorporates:
       *  SignalConversion generated from: '<S80>/In1'
       */
      top_level_algo_B.Merge = top_level_algo_B.displacement;

      /* End of Outputs for SubSystem: '<S74>/If Action Subsystem1' */
    }

    /* End of If: '<S74>/If' */

    /* RateTransition generated from: '<Root>/Summarizing' */
    top_level_algo_DW.TmpRTBAtSummarizingInport7_Buff = rtb_AND;
  }

  {
    int_T i;

    /* Update for S-Function (sfix_udelay): '<S10>/Tapped Delay1' */
    for (i = 0; i < 19; i++) {
      top_level_algo_DW.TappedDelay1_X[i] = top_level_algo_DW.TappedDelay1_X[i +
        1];
    }

    top_level_algo_DW.TappedDelay1_X[19] = top_level_algo_B.Product;

    /* End of Update for S-Function (sfix_udelay): '<S10>/Tapped Delay1' */

    /* Update for Delay: '<S9>/Delay' */
    top_level_algo_DW.Delay_DSTATE_dt = rtb_Merge_n;

    /* Update for Delay: '<S9>/Delay1' */
    top_level_algo_DW.Delay1_DSTATE[0] = top_level_algo_DW.Delay1_DSTATE[1];
    top_level_algo_DW.Delay1_DSTATE[1] = rtb_Merge_n;

    /* Update for Delay: '<S9>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE[0] = top_level_algo_DW.Delay2_DSTATE[1];
    top_level_algo_DW.Delay2_DSTATE[1] = top_level_algo_DW.Delay2_DSTATE[2];
    top_level_algo_DW.Delay2_DSTATE[2] = rtb_Merge_n;

    /* Update for Delay: '<S9>/Delay3' */
    top_level_algo_DW.Delay3_DSTATE[0] = top_level_algo_DW.Delay3_DSTATE[1];
    top_level_algo_DW.Delay3_DSTATE[1] = top_level_algo_DW.Delay3_DSTATE[2];
    top_level_algo_DW.Delay3_DSTATE[2] = top_level_algo_DW.Delay3_DSTATE[3];
    top_level_algo_DW.Delay3_DSTATE[3] = rtb_Merge_n;

    /* Update for Delay: '<S9>/Delay4' */
    top_level_algo_DW.Delay4_DSTATE[0] = top_level_algo_DW.Delay4_DSTATE[1];
    top_level_algo_DW.Delay4_DSTATE[1] = top_level_algo_DW.Delay4_DSTATE[2];
    top_level_algo_DW.Delay4_DSTATE[2] = top_level_algo_DW.Delay4_DSTATE[3];
    top_level_algo_DW.Delay4_DSTATE[3] = top_level_algo_DW.Delay4_DSTATE[4];
    top_level_algo_DW.Delay4_DSTATE[4] = rtb_Merge_n;
    for (i = 0; i < 9; i++) {
      /* Update for S-Function (sfix_udelay): '<S10>/Tapped Delay' */
      top_level_algo_DW.TappedDelay_X_f[i] = top_level_algo_DW.TappedDelay_X_f[i
        + 1];

      /* Update for Delay: '<S9>/Delay5' */
      top_level_algo_DW.Delay5_DSTATE[i] = top_level_algo_DW.Delay5_DSTATE[i + 1];

      /* Update for S-Function (sfix_udelay): '<S9>/Tapped Delay' */
      top_level_algo_DW.TappedDelay_X[i] = top_level_algo_DW.TappedDelay_X[i + 1];
    }

    /* Update for S-Function (sfix_udelay): '<S10>/Tapped Delay' */
    top_level_algo_DW.TappedDelay_X_f[9] = top_level_algo_B.CastToSingle2;

    /* Update for Delay: '<S9>/Delay5' */
    top_level_algo_DW.Delay5_DSTATE[9] = rtb_Merge_n;

    /* Update for S-Function (sfix_udelay): '<S9>/Tapped Delay' */
    top_level_algo_DW.TappedDelay_X[9] = top_level_algo_B.u0Diff;

    /* Update for Delay: '<S12>/Delay8' */
    top_level_algo_DW.Delay8_DSTATE_b[0] = top_level_algo_DW.Delay8_DSTATE_b[1];
    top_level_algo_DW.Delay8_DSTATE_b[1] = rtb_IsPos;

    /* Update for Delay: '<S12>/Delay6' */
    top_level_algo_DW.Delay6_DSTATE[0] = top_level_algo_DW.Delay6_DSTATE[1];
    top_level_algo_DW.Delay6_DSTATE[1] = rtb_LogicalOperator3;

    /* Update for Delay: '<S12>/Delay4' */
    top_level_algo_DW.Delay4_DSTATE_a[0] = top_level_algo_DW.Delay4_DSTATE_a[1];
    top_level_algo_DW.Delay4_DSTATE_a[1] = rtb_IsNeg;

    /* Update for Delay: '<S12>/Delay3' */
    top_level_algo_DW.Delay3_DSTATE_m[0] = top_level_algo_DW.Delay3_DSTATE_m[1];
    top_level_algo_DW.Delay3_DSTATE_m[1] = rtb_LogicalOperator7;

    /* Update for Delay: '<S12>/Delay' */
    top_level_algo_DW.Delay_DSTATE_a[0] = top_level_algo_DW.Delay_DSTATE_a[1];

    /* Update for Delay: '<S12>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE_m[0] = top_level_algo_DW.Delay2_DSTATE_m[1];

    /* Update for Delay: '<S12>/Delay' */
    top_level_algo_DW.Delay_DSTATE_a[1] = top_level_algo_DW.Delay_DSTATE_a[2];

    /* Update for Delay: '<S12>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE_m[1] = top_level_algo_DW.Delay2_DSTATE_m[2];

    /* Update for Delay: '<S12>/Delay' */
    top_level_algo_DW.Delay_DSTATE_a[2] = top_level_algo_DW.Delay_DSTATE_a[3];

    /* Update for Delay: '<S12>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE_m[2] = top_level_algo_DW.Delay2_DSTATE_m[3];

    /* Update for Delay: '<S12>/Delay' */
    top_level_algo_DW.Delay_DSTATE_a[3] = top_level_algo_DW.Delay_DSTATE_a[4];

    /* Update for Delay: '<S12>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE_m[3] = top_level_algo_DW.Delay2_DSTATE_m[4];

    /* Update for Delay: '<S12>/Delay' */
    top_level_algo_DW.Delay_DSTATE_a[4] = rtb_NOT_c;

    /* Update for Delay: '<S12>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE_m[4] = rtb_NOT2;

    /* Update for Memory: '<S77>/Memory' */
    top_level_algo_DW.Memory_PreviousInput = rtb_Reset;

    /* Update for Memory: '<S78>/Memory' */
    top_level_algo_DW.Memory_PreviousInput_m = rtb_Reset_b;
  }
}

/* Model step function for TID3 */
void top_level_algo_step3(void)        /* Sample time: [0.05s, 0.0s] */
{
  real_T tmp;
  uint8_T tmp_0;
  boolean_T rtb_Compare_m;

  /* MATLABSystem: '<Root>/Digital Input' */
  if (top_level_algo_DW.obj_d.SampleTime !=
      top_level_algo_P.DigitalInput_SampleTime) {
    top_level_algo_DW.obj_d.SampleTime =
      top_level_algo_P.DigitalInput_SampleTime;
  }

  rtb_Compare_m = readDigitalPin(13);

  /* RelationalOperator: '<S11>/Compare' incorporates:
   *  Constant: '<S11>/Constant'
   *  MATLABSystem: '<Root>/Digital Input'
   */
  rtb_Compare_m = (rtb_Compare_m == top_level_algo_P.Constant_Value_p);

  /* Chart: '<Root>/Mode' */
  if (top_level_algo_DW.temporalCounter_i1_ir < 1023U) {
    top_level_algo_DW.temporalCounter_i1_ir++;
  }

  if (top_level_algo_DW.is_active_c16_top_level_algo == 0U) {
    top_level_algo_DW.is_active_c16_top_level_algo = 1U;
    top_level_algo_DW.is_c16_top_level_algo = top_level_algo_IN_CALIBRATION;
    top_level_algo_DW.temporalCounter_i1_ir = 0U;
    top_level_algo_B.depth_ctrl = 0.0;
    top_level_algo_B.recoil_ctrl = 0.0;
    top_level_algo_B.seven_seg_ctrl = 0.0;
    top_level_algo_B.evaluating_h = 0.0;
  } else {
    switch (top_level_algo_DW.is_c16_top_level_algo) {
     case top_level_algo_IN_CALIBRATION:
      top_level_algo_B.depth_ctrl = 0.0;
      top_level_algo_B.recoil_ctrl = 0.0;
      top_level_algo_B.seven_seg_ctrl = 0.0;
      top_level_algo_B.evaluating_h = 0.0;
      if (top_level_algo_DW.temporalCounter_i1_ir >= 40U) {
        top_level_algo_DW.is_c16_top_level_algo = top_level_algo_IN_RUNNING;
        top_level_algo_DW.temporalCounter_i1_ir = 0U;
        top_level_algo_B.depth_ctrl = 1.0;
        top_level_algo_B.recoil_ctrl = 1.0;
        top_level_algo_B.seven_seg_ctrl = 1.0;
        top_level_algo_B.evaluating_h = 0.0;
      }
      break;

     case top_level_algo_IN_DEBOUNCE1:
      if (!rtb_Compare_m) {
        top_level_algo_DW.is_c16_top_level_algo = top_level_algo_IN_EVALUATING;
        top_level_algo_DW.temporalCounter_i1_ir = 0U;
        top_level_algo_B.depth_ctrl = 0.0;
        top_level_algo_B.recoil_ctrl = 0.0;
        top_level_algo_B.seven_seg_ctrl = 0.0;
        top_level_algo_B.evaluating_h = 1.0;
      }
      break;

     case top_level_algo_IN_DEBOUNCE2:
      if (!rtb_Compare_m) {
        top_level_algo_DW.is_c16_top_level_algo = top_level_algo_IN_RUNNING;
        top_level_algo_DW.temporalCounter_i1_ir = 0U;
        top_level_algo_B.depth_ctrl = 1.0;
        top_level_algo_B.recoil_ctrl = 1.0;
        top_level_algo_B.seven_seg_ctrl = 1.0;
        top_level_algo_B.evaluating_h = 0.0;
      }
      break;

     case top_level_algo_IN_EVALUATING:
      top_level_algo_B.depth_ctrl = 0.0;
      top_level_algo_B.recoil_ctrl = 0.0;
      top_level_algo_B.seven_seg_ctrl = 0.0;
      top_level_algo_B.evaluating_h = 1.0;
      if (rtb_Compare_m && (top_level_algo_DW.temporalCounter_i1_ir >= 8U)) {
        top_level_algo_DW.is_c16_top_level_algo = top_level_algo_IN_DEBOUNCE2;
      } else if (top_level_algo_DW.temporalCounter_i1_ir >= 600U) {
        top_level_algo_DW.is_c16_top_level_algo = top_level_algo_IN_RUNNING;
        top_level_algo_DW.temporalCounter_i1_ir = 0U;
        top_level_algo_B.depth_ctrl = 1.0;
        top_level_algo_B.recoil_ctrl = 1.0;
        top_level_algo_B.seven_seg_ctrl = 1.0;
        top_level_algo_B.evaluating_h = 0.0;
      }
      break;

     default:
      /* case IN_RUNNING: */
      top_level_algo_B.depth_ctrl = 1.0;
      top_level_algo_B.recoil_ctrl = 1.0;
      top_level_algo_B.seven_seg_ctrl = 1.0;
      top_level_algo_B.evaluating_h = 0.0;
      if (rtb_Compare_m && (top_level_algo_DW.temporalCounter_i1_ir >= 8U)) {
        top_level_algo_DW.is_c16_top_level_algo = top_level_algo_IN_DEBOUNCE1;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Mode' */

  /* MATLABSystem: '<Root>/Digital Output10' */
  tmp = rt_roundd_snf(top_level_algo_B.evaluating_h);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(2, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output10' */

  /* RateTransition generated from: '<Root>/Mode' */
  top_level_algo_DW.TmpRTBAtModeOutport1_Buffer0 = top_level_algo_B.depth_ctrl;

  /* RateTransition generated from: '<Root>/Mode' */
  top_level_algo_DW.TmpRTBAtModeOutport2_Buffer0 = top_level_algo_B.recoil_ctrl;

  /* RateTransition generated from: '<Root>/Mode' */
  top_level_algo_DW.TmpRTBAtModeOutport3_Buffer0 =
    top_level_algo_B.seven_seg_ctrl;

  /* RateTransition generated from: '<Root>/Summarizing' */
  top_level_algo_DW.evaluating_Buffer0 = top_level_algo_B.evaluating_h;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void top_level_algo_step(int_T tid)
{
  switch (tid) {
   case 0 :
    top_level_algo_step0();
    break;

   case 2 :
    top_level_algo_step2();
    break;

   case 3 :
    top_level_algo_step3();
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
    int32_T i;
    char_T c[37];
    static const char_T tmp[37] = "0000180d-0000-1000-8000-00805f9b34fb";
    static const char_T tmp_0[37] = "00002a37-0000-1000-8000-00805f9b34fb";
    static const char_T tmp_1[37] = "00001810-0000-1000-8000-00805f9b34fb";
    static const char_T tmp_2[37] = "00002a35-0000-1000-8000-00805f9b34fb";
    static const char_T tmp_3[37] = "00001808-0000-1000-8000-00805f9b34fb";
    static const char_T tmp_4[37] = "00002a18-0000-1000-8000-00805f9b34fb";

    /* Start for RateTransition generated from: '<S6>/Chart1' */
    top_level_algo_B.TmpRTBAtChart1Inport2 =
      top_level_algo_P.TmpRTBAtChart1Inport2_InitialCo;

    /* Start for RateTransition generated from: '<Root>/Mode' */
    top_level_algo_B.TmpRTBAtModeOutport3 =
      top_level_algo_P.TmpRTBAtModeOutport3_InitialCon;

    /* Start for DiscretePulseGenerator: '<S15>/Pulse Generator' */
    top_level_algo_DW.clockTickCounter = -2000;

    /* Start for RateTransition generated from: '<Root>/Summarizing' */
    top_level_algo_B.evaluating = top_level_algo_P.evaluating_InitialCondition;

    /* Start for RateTransition generated from: '<S12>/sample and hold' */
    top_level_algo_B.Max = top_level_algo_P.Max_InitialCondition;

    /* Start for RateTransition generated from: '<Root>/Summarizing' */
    top_level_algo_B.TmpRTBAtSummarizingInport7 =
      top_level_algo_P.TmpRTBAtSummarizingInport7_Init;

    /* Start for RateTransition generated from: '<Root>/Mode' */
    top_level_algo_B.TmpRTBAtModeOutport2 =
      top_level_algo_P.TmpRTBAtModeOutport2_InitialCon;

    /* Start for RateTransition generated from: '<Root>/Mode' */
    top_level_algo_B.TmpRTBAtModeOutport1 =
      top_level_algo_P.TmpRTBAtModeOutport1_InitialCon;

    /* InitializeConditions for Delay: '<S83>/Delay' */
    top_level_algo_DW.Delay_DSTATE[0] = top_level_algo_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S15>/Delay' */
    top_level_algo_DW.Delay_DSTATE_d[0] =
      top_level_algo_P.Delay_InitialCondition_n;

    /* InitializeConditions for Delay: '<S83>/Delay' */
    top_level_algo_DW.Delay_DSTATE[1] = top_level_algo_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S15>/Delay' */
    top_level_algo_DW.Delay_DSTATE_d[1] =
      top_level_algo_P.Delay_InitialCondition_n;

    /* InitializeConditions for Delay: '<S83>/Delay' */
    top_level_algo_DW.Delay_DSTATE[2] = top_level_algo_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S15>/Delay' */
    top_level_algo_DW.Delay_DSTATE_d[2] =
      top_level_algo_P.Delay_InitialCondition_n;

    /* InitializeConditions for Delay: '<S83>/Delay' */
    top_level_algo_DW.Delay_DSTATE[3] = top_level_algo_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S15>/Delay' */
    top_level_algo_DW.Delay_DSTATE_d[3] =
      top_level_algo_P.Delay_InitialCondition_n;

    /* InitializeConditions for Delay: '<S15>/Delay8' */
    for (i = 0; i < 288; i++) {
      top_level_algo_DW.Delay8_DSTATE[i] =
        top_level_algo_P.Delay8_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S15>/Delay8' */

    /* InitializeConditions for Delay: '<S15>/Delay7' */
    top_level_algo_DW.Delay7_DSTATE = top_level_algo_P.Delay7_InitialCondition;

    /* InitializeConditions for RateTransition generated from: '<S6>/Chart1' */
    top_level_algo_DW.TmpRTBAtChart1Inport2_Buffer0 =
      top_level_algo_P.TmpRTBAtChart1Inport2_InitialCo;

    /* InitializeConditions for RateTransition generated from: '<Root>/Mode' */
    top_level_algo_DW.TmpRTBAtModeOutport3_Buffer0 =
      top_level_algo_P.TmpRTBAtModeOutport3_InitialCon;

    /* InitializeConditions for RateTransition generated from: '<Root>/Summarizing' */
    top_level_algo_DW.evaluating_Buffer0 =
      top_level_algo_P.evaluating_InitialCondition;

    /* InitializeConditions for RateTransition generated from: '<S12>/sample and hold' */
    top_level_algo_DW.Max_Buffer0 = top_level_algo_P.Max_InitialCondition;

    /* InitializeConditions for RateTransition generated from: '<Root>/Summarizing' */
    top_level_algo_DW.TmpRTBAtSummarizingInport7_Buff =
      top_level_algo_P.TmpRTBAtSummarizingInport7_Init;

    /* InitializeConditions for RateTransition generated from: '<Root>/Mode' */
    top_level_algo_DW.TmpRTBAtModeOutport2_Buffer0 =
      top_level_algo_P.TmpRTBAtModeOutport2_InitialCon;

    /* InitializeConditions for S-Function (sfix_udelay): '<S10>/Tapped Delay1' */
    for (i = 0; i < 20; i++) {
      top_level_algo_DW.TappedDelay1_X[i] = top_level_algo_P.TappedDelay1_vinit;
    }

    /* End of InitializeConditions for S-Function (sfix_udelay): '<S10>/Tapped Delay1' */

    /* InitializeConditions for S-Function (sfix_udelay): '<S10>/Tapped Delay' */
    for (i = 0; i < 10; i++) {
      top_level_algo_DW.TappedDelay_X_f[i] =
        top_level_algo_P.TappedDelay_vinit_l;
    }

    /* End of InitializeConditions for S-Function (sfix_udelay): '<S10>/Tapped Delay' */

    /* InitializeConditions for RateTransition generated from: '<Root>/Mode' */
    top_level_algo_DW.TmpRTBAtModeOutport1_Buffer0 =
      top_level_algo_P.TmpRTBAtModeOutport1_InitialCon;

    /* InitializeConditions for Delay: '<S9>/Delay' */
    top_level_algo_DW.Delay_DSTATE_dt =
      top_level_algo_P.Delay_InitialCondition_m;

    /* InitializeConditions for Delay: '<S9>/Delay1' */
    top_level_algo_DW.Delay1_DSTATE[0] =
      top_level_algo_P.Delay1_InitialCondition;
    top_level_algo_DW.Delay1_DSTATE[1] =
      top_level_algo_P.Delay1_InitialCondition;

    /* InitializeConditions for Delay: '<S9>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE[0] =
      top_level_algo_P.Delay2_InitialCondition;
    top_level_algo_DW.Delay2_DSTATE[1] =
      top_level_algo_P.Delay2_InitialCondition;
    top_level_algo_DW.Delay2_DSTATE[2] =
      top_level_algo_P.Delay2_InitialCondition;

    /* InitializeConditions for Delay: '<S9>/Delay3' */
    top_level_algo_DW.Delay3_DSTATE[0] =
      top_level_algo_P.Delay3_InitialCondition;
    top_level_algo_DW.Delay3_DSTATE[1] =
      top_level_algo_P.Delay3_InitialCondition;
    top_level_algo_DW.Delay3_DSTATE[2] =
      top_level_algo_P.Delay3_InitialCondition;
    top_level_algo_DW.Delay3_DSTATE[3] =
      top_level_algo_P.Delay3_InitialCondition;

    /* InitializeConditions for Delay: '<S9>/Delay4' */
    for (i = 0; i < 5; i++) {
      top_level_algo_DW.Delay4_DSTATE[i] =
        top_level_algo_P.Delay4_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S9>/Delay4' */
    for (i = 0; i < 10; i++) {
      /* InitializeConditions for Delay: '<S9>/Delay5' */
      top_level_algo_DW.Delay5_DSTATE[i] =
        top_level_algo_P.Delay5_InitialCondition;

      /* InitializeConditions for S-Function (sfix_udelay): '<S9>/Tapped Delay' */
      top_level_algo_DW.TappedDelay_X[i] = top_level_algo_P.TappedDelay_vinit;
    }

    /* InitializeConditions for Delay: '<S12>/Delay7' */
    top_level_algo_DW.Delay7_DSTATE_l =
      top_level_algo_P.Delay7_InitialCondition_o;

    /* InitializeConditions for Delay: '<S12>/Delay1' */
    top_level_algo_DW.Delay1_DSTATE_m =
      top_level_algo_P.Delay1_InitialCondition_d;

    /* InitializeConditions for Delay: '<S12>/Delay8' */
    top_level_algo_DW.Delay8_DSTATE_b[0] =
      top_level_algo_P.Delay8_InitialCondition_o;

    /* InitializeConditions for Delay: '<S12>/Delay6' */
    top_level_algo_DW.Delay6_DSTATE[0] =
      top_level_algo_P.Delay6_InitialCondition;

    /* InitializeConditions for Delay: '<S12>/Delay4' */
    top_level_algo_DW.Delay4_DSTATE_a[0] =
      top_level_algo_P.Delay4_InitialCondition_f;

    /* InitializeConditions for Delay: '<S12>/Delay3' */
    top_level_algo_DW.Delay3_DSTATE_m[0] =
      top_level_algo_P.Delay3_InitialCondition_k;

    /* InitializeConditions for Delay: '<S12>/Delay8' */
    top_level_algo_DW.Delay8_DSTATE_b[1] =
      top_level_algo_P.Delay8_InitialCondition_o;

    /* InitializeConditions for Delay: '<S12>/Delay6' */
    top_level_algo_DW.Delay6_DSTATE[1] =
      top_level_algo_P.Delay6_InitialCondition;

    /* InitializeConditions for Delay: '<S12>/Delay4' */
    top_level_algo_DW.Delay4_DSTATE_a[1] =
      top_level_algo_P.Delay4_InitialCondition_f;

    /* InitializeConditions for Delay: '<S12>/Delay3' */
    top_level_algo_DW.Delay3_DSTATE_m[1] =
      top_level_algo_P.Delay3_InitialCondition_k;
    for (i = 0; i < 5; i++) {
      /* InitializeConditions for Delay: '<S12>/Delay' */
      top_level_algo_DW.Delay_DSTATE_a[i] =
        top_level_algo_P.Delay_InitialCondition_d;

      /* InitializeConditions for Delay: '<S12>/Delay2' */
      top_level_algo_DW.Delay2_DSTATE_m[i] =
        top_level_algo_P.Delay2_InitialCondition_c;
    }

    /* InitializeConditions for Memory: '<S77>/Memory' */
    top_level_algo_DW.Memory_PreviousInput = top_level_algo_P.MaxBDC_vinit;

    /* InitializeConditions for Memory: '<S78>/Memory' */
    top_level_algo_DW.Memory_PreviousInput_m = top_level_algo_P.MinBDC_vinit;

    /* SystemInitialize for Chart: '<S12>/sample and hold' */
    top_leve_sampleandhold_Init(&top_level_algo_B.displacement_a);

    /* SystemInitialize for Chart: '<S12>/sample and hold1' */
    top_leve_sampleandhold_Init(&top_level_algo_B.displacement);

    /* Start for MATLABSystem: '<S2>/Digital Output2' */
    top_level_algo_DW.obj_a.matlabCodegenIsDeleted = false;
    top_level_algo_DW.obj_a.isInitialized = 1;
    digitalIOSetup(1, 1);
    top_level_algo_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Output3' */
    top_level_algo_DW.obj_l.matlabCodegenIsDeleted = false;
    top_level_algo_DW.obj_l.isInitialized = 1;
    digitalIOSetup(3, 1);
    top_level_algo_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/BLE Send11' */
    top_level_algo_DW.obj_fk.Index = 0U;
    top_level_algo_DW.obj_fk.isInitialized = 1;
    for (i = 0; i < 37; i++) {
      top_level_algo_B.b[i] = tmp[i];
      c[i] = tmp_0[i];
    }

    INIT_BLE_RECECIVE_PERI(&top_level_algo_DW.obj_fk.Index, &top_level_algo_B.b
      [0], &c[0]);

    /* End of Start for MATLABSystem: '<S3>/BLE Send11' */

    /* Start for MATLABSystem: '<S3>/BLE Send12' */
    top_level_algo_DW.obj_pa.Index = 0U;
    top_level_algo_DW.obj_pa.isInitialized = 1;
    for (i = 0; i < 37; i++) {
      top_level_algo_B.b[i] = tmp_1[i];
      c[i] = tmp_2[i];
    }

    INIT_BLE_RECECIVE_PERI(&top_level_algo_DW.obj_pa.Index, &top_level_algo_B.b
      [0], &c[0]);

    /* End of Start for MATLABSystem: '<S3>/BLE Send12' */

    /* Start for MATLABSystem: '<S3>/BLE Send13' */
    top_level_algo_DW.obj_i.Index = 0U;
    top_level_algo_DW.obj_i.isInitialized = 1;
    for (i = 0; i < 37; i++) {
      top_level_algo_B.b[i] = tmp_3[i];
      c[i] = tmp_4[i];
    }

    INIT_BLE_RECECIVE_PERI(&top_level_algo_DW.obj_i.Index, &top_level_algo_B.b[0],
      &c[0]);

    /* End of Start for MATLABSystem: '<S3>/BLE Send13' */

    /* Start for MATLABSystem: '<S14>/Digital Output8' */
    top_level_algo_DW.obj_m.matlabCodegenIsDeleted = false;
    top_level_algo_DW.obj_m.isInitialized = 1;
    digitalIOSetup(23, 1);
    top_level_algo_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S14>/Digital Output9' */
    top_level_algo_DW.obj_b.matlabCodegenIsDeleted = false;
    top_level_algo_DW.obj_b.isInitialized = 1;
    digitalIOSetup(22, 1);
    top_level_algo_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S7>/Digital Output4' */
    top_level_algo_DW.obj_k.matlabCodegenIsDeleted = false;
    top_level_algo_DW.obj_k.isInitialized = 1;
    digitalIOSetup(33, 1);
    top_level_algo_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S7>/Digital Output5' */
    top_level_algo_DW.obj_j.matlabCodegenIsDeleted = false;
    top_level_algo_DW.obj_j.isInitialized = 1;
    digitalIOSetup(25, 1);
    top_level_algo_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S7>/Digital Output6' */
    top_level_algo_DW.obj_p.matlabCodegenIsDeleted = false;
    top_level_algo_DW.obj_p.isInitialized = 1;
    digitalIOSetup(26, 1);
    top_level_algo_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S7>/Digital Output7' */
    top_level_algo_DW.obj_do.matlabCodegenIsDeleted = false;
    top_level_algo_DW.obj_do.isInitialized = 1;
    digitalIOSetup(27, 1);
    top_level_algo_DW.obj_do.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    top_level_algo_DW.obj.matlabCodegenIsDeleted = false;
    top_level_algo_DW.obj.SampleTime = top_level_algo_P.AnalogInput_SampleTime;
    obj = &top_level_algo_DW.obj;
    top_level_algo_DW.obj.isInitialized = 1;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(15U);
    top_level_algo_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Input' */
    top_level_algo_DW.obj_d.matlabCodegenIsDeleted = false;
    top_level_algo_DW.obj_d.SampleTime =
      top_level_algo_P.DigitalInput_SampleTime;
    top_level_algo_DW.obj_d.isInitialized = 1;
    digitalIOSetup(13, 0);
    top_level_algo_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output10' */
    top_level_algo_DW.obj_f.matlabCodegenIsDeleted = false;
    top_level_algo_DW.obj_f.isInitialized = 1;
    digitalIOSetup(2, 1);
    top_level_algo_DW.obj_f.isSetupComplete = true;
  }
}

/* Model terminate function */
void top_level_algo_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S2>/Digital Output2' */
  if (!top_level_algo_DW.obj_a.matlabCodegenIsDeleted) {
    top_level_algo_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Output2' */

  /* Terminate for MATLABSystem: '<S2>/Digital Output3' */
  if (!top_level_algo_DW.obj_l.matlabCodegenIsDeleted) {
    top_level_algo_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Output3' */

  /* Terminate for MATLABSystem: '<S14>/Digital Output8' */
  if (!top_level_algo_DW.obj_m.matlabCodegenIsDeleted) {
    top_level_algo_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S14>/Digital Output8' */

  /* Terminate for MATLABSystem: '<S14>/Digital Output9' */
  if (!top_level_algo_DW.obj_b.matlabCodegenIsDeleted) {
    top_level_algo_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S14>/Digital Output9' */

  /* Terminate for MATLABSystem: '<S7>/Digital Output4' */
  if (!top_level_algo_DW.obj_k.matlabCodegenIsDeleted) {
    top_level_algo_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S7>/Digital Output4' */

  /* Terminate for MATLABSystem: '<S7>/Digital Output5' */
  if (!top_level_algo_DW.obj_j.matlabCodegenIsDeleted) {
    top_level_algo_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S7>/Digital Output5' */

  /* Terminate for MATLABSystem: '<S7>/Digital Output6' */
  if (!top_level_algo_DW.obj_p.matlabCodegenIsDeleted) {
    top_level_algo_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S7>/Digital Output6' */

  /* Terminate for MATLABSystem: '<S7>/Digital Output7' */
  if (!top_level_algo_DW.obj_do.matlabCodegenIsDeleted) {
    top_level_algo_DW.obj_do.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S7>/Digital Output7' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  obj = &top_level_algo_DW.obj;
  if (!top_level_algo_DW.obj.matlabCodegenIsDeleted) {
    top_level_algo_DW.obj.matlabCodegenIsDeleted = true;
    if ((top_level_algo_DW.obj.isInitialized == 1) &&
        top_level_algo_DW.obj.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(15U);
      MW_AnalogIn_Close
        (top_level_algo_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/Digital Input' */
  if (!top_level_algo_DW.obj_d.matlabCodegenIsDeleted) {
    top_level_algo_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output10' */
  if (!top_level_algo_DW.obj_f.matlabCodegenIsDeleted) {
    top_level_algo_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output10' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
