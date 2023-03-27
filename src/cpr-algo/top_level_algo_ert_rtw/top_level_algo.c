/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo.c
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 3.28
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sun Mar 26 15:35:11 2023
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

/* Named constants for Chart: '<S11>/ClockLogic' */
#define top_level_algo_IN_HIGH         (1U)
#define top_level_algo_IN_LOW          (2U)
#define top_level_algo_IN_START        (3U)
#define top_level_algo_IN_WAIT         (4U)

/* Named constants for Chart: '<S11>/DataLogic' */
#define top_level_algo_IN_CHECK        (1U)
#define top_level_algo_IN_LOAD         (2U)
#define top_level_algo_IN_MASK         (3U)
#define top_level_algo_IN_START_n      (4U)
#define top_level_algo_IN_WAITING      (5U)
#define top_level_algo_IN_Wait         (6U)

/* Named constants for Chart: '<S3>/Chart1' */
#define top_level_algo_IN_Counting     (1U)
#define top_level_algo_IN_First        (2U)
#define top_level_algo_IN_INIT         (3U)

/* Named constants for Chart: '<S5>/timer' */
#define top_level_algo_IN_Finished     (1U)
#define top_level_algo_IN_Starting     (2U)

/* Named constants for Chart: '<S8>/sample and hold' */
#define top_level_algo_IN_Holding      (1U)
#define top_level_algo_IN_Init         (2U)

/* Named constants for Chart: '<Root>/Mode' */
#define top_level_algo_IN_CALIBRATION  (1U)
#define top_level_algo_IN_DEBOUNCE1    (2U)
#define top_level_algo_IN_DEBOUNCE2    (3U)
#define top_level_algo_IN_EVALUATING   (4U)
#define top_level_algo_IN_RUNNING      (5U)

/* Block signals (default storage) */
B_top_level_algo_T top_level_algo_B;

/* Block states (default storage) */
DW_top_level_algo_T top_level_algo_DW;

/* Real-time model */
static RT_MODEL_top_level_algo_T top_level_algo_M_;
RT_MODEL_top_level_algo_T *const top_level_algo_M = &top_level_algo_M_;
static void rate_monotonic_scheduler(void);
int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

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
void top_level_IfActionSubsystem(uint8_T *rty_Out1,
  P_IfActionSubsystem_top_level_T *localP)
{
  /* SignalConversion generated from: '<S15>/Out1' incorporates:
   *  Constant: '<S15>/Constant'
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

uint32_T MWDSP_EPH_R_D(real_T evt, uint32_T *sta)
{
  int32_T curState;
  int32_T lastzcevent;
  int32_T newState;
  int32_T newStateR;
  uint32_T previousState;
  uint32_T retVal;

  /* S-Function (sdspcount2): '<S3>/Counter1' */
  /* Detect rising edge events */
  previousState = *sta;
  retVal = 0U;
  lastzcevent = 0;
  newState = 5;
  newStateR = 5;
  if (evt > 0.0) {
    curState = 2;
  } else {
    curState = !(evt < 0.0);
  }

  if (*sta == 5U) {
    newStateR = curState;
  } else if ((uint32_T)curState != *sta) {
    if (*sta == 3U) {
      if ((uint32_T)curState == 1U) {
        newStateR = 1;
      } else {
        lastzcevent = 2;
        previousState = 1U;
      }
    }

    if (previousState == 4U) {
      if ((uint32_T)curState == 1U) {
        newStateR = 1;
      } else {
        lastzcevent = 3;
        previousState = 1U;
      }
    }

    if ((previousState == 1U) && ((uint32_T)curState == 2U)) {
      retVal = 2U;
    }

    if (previousState == 0U) {
      retVal = 2U;
    }

    if (retVal == (uint32_T)lastzcevent) {
      retVal = 0U;
    }

    if (((uint32_T)curState == 1U) && (retVal == 2U)) {
      newState = 3;
    } else {
      newState = curState;
    }
  }

  if ((uint32_T)newStateR != 5U) {
    *sta = (uint32_T)newStateR;
    retVal = 0U;
  }

  if ((uint32_T)newState != 5U) {
    *sta = (uint32_T)newState;
  }

  /* End of S-Function (sdspcount2): '<S3>/Counter1' */
  return retVal;
}

uint32_T MWDSP_EPH_R_B(boolean_T evt, uint32_T *sta)
{
  int32_T curState;
  int32_T lastzcevent;
  int32_T newState;
  int32_T newStateR;
  uint32_T previousState;
  uint32_T retVal;

  /* S-Function (sdspcount2): '<S3>/Counter1' */
  /* Detect rising edge events */
  previousState = *sta;
  retVal = 0U;
  lastzcevent = 0;
  newState = 5;
  newStateR = 5;
  if (evt) {
    curState = 2;
  } else {
    curState = 1;
  }

  if (*sta == 5U) {
    newStateR = curState;
  } else if ((uint32_T)curState != *sta) {
    if (*sta == 3U) {
      if ((uint32_T)curState == 1U) {
        newStateR = 1;
      } else {
        lastzcevent = 2;
        previousState = 1U;
      }
    }

    if (previousState == 4U) {
      if ((uint32_T)curState == 1U) {
        newStateR = 1;
      } else {
        lastzcevent = 3;
        previousState = 1U;
      }
    }

    if ((previousState == 1U) && ((uint32_T)curState == 2U)) {
      retVal = 2U;
    }

    if (previousState == 0U) {
      retVal = 2U;
    }

    if (retVal == (uint32_T)lastzcevent) {
      retVal = 0U;
    }

    if (((uint32_T)curState == 1U) && (retVal == 2U)) {
      newState = 3;
    } else {
      newState = curState;
    }
  }

  if ((uint32_T)newStateR != 5U) {
    *sta = (uint32_T)newStateR;
    retVal = 0U;
  }

  if ((uint32_T)newState != 5U) {
    *sta = (uint32_T)newState;
  }

  /* End of S-Function (sdspcount2): '<S3>/Counter1' */
  return retVal;
}

/* Model step function for TID0 */
void top_level_algo_step0(void)        /* Sample time: [0.0s, 0.0s] */
{
  real_T rtb_DividebyConstantandRound;
  real_T rtb_Mod1;
  real_T rtb_TmpMLSysMemLayoutBufferAt_k;
  real_T tmp;
  uint8_T tmp_0;
  boolean_T rtb_Compare_bz;

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(top_level_algo_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC);

  /* Clock: '<S3>/Clock1' */
  top_level_algo_B.Clock1 = top_level_algo_M->Timing.t[0];

  /* RateTransition generated from: '<S3>/Chart1' */
  if (top_level_algo_M->Timing.RateInteraction.TID1_2) {
    /* RateTransition generated from: '<S3>/Chart1' */
    top_level_algo_B.TmpRTBAtChart1Inport2 =
      top_level_algo_DW.TmpRTBAtChart1Inport2_Buffer0;
  }

  /* End of RateTransition generated from: '<S3>/Chart1' */

  /* Chart: '<S3>/Chart1' */
  if (top_level_algo_DW.temporalCounter_i1_jw < 2047U) {
    top_level_algo_DW.temporalCounter_i1_jw++;
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
      if ((top_level_algo_DW.temporalCounter_i1_jw >= 10U) &&
          top_level_algo_B.TmpRTBAtChart1Inport2) {
        top_level_algo_DW.is_c12_top_level_algo = top_level_algo_IN_Counting;
        top_level_algo_DW.temporalCounter_i1_jw = 0U;
        top_level_algo_B.rate = 60.0 / (top_level_algo_B.Clock1 -
          top_level_algo_DW.lastTs);
        top_level_algo_DW.lastTs = top_level_algo_B.Clock1;
      } else if (top_level_algo_DW.temporalCounter_i1_jw >= 2000U) {
        top_level_algo_DW.is_c12_top_level_algo = top_level_algo_IN_INIT;
        top_level_algo_DW.lastTs = 0.0;
        top_level_algo_B.rate = 0.0;
        top_level_algo_B.recoil_active = 0.0;
      }
      break;

     case top_level_algo_IN_First:
      top_level_algo_B.recoil_active = 1.0;
      if ((top_level_algo_DW.temporalCounter_i1_jw >= 50U) &&
          top_level_algo_B.TmpRTBAtChart1Inport2) {
        top_level_algo_DW.is_c12_top_level_algo = top_level_algo_IN_Counting;
        top_level_algo_DW.temporalCounter_i1_jw = 0U;
        top_level_algo_B.rate = 60.0 / (top_level_algo_B.Clock1 -
          top_level_algo_DW.lastTs);
        top_level_algo_DW.lastTs = top_level_algo_B.Clock1;
      }
      break;

     default:
      /* case IN_INIT: */
      top_level_algo_B.recoil_active = 0.0;
      if (top_level_algo_B.TmpRTBAtChart1Inport2) {
        top_level_algo_DW.is_c12_top_level_algo = top_level_algo_IN_First;
        top_level_algo_DW.temporalCounter_i1_jw = 0U;
        top_level_algo_DW.lastTs = top_level_algo_B.Clock1;
        top_level_algo_B.recoil_active = 1.0;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/Chart1' */

  /* RateTransition generated from: '<Root>/Mode' */
  if (top_level_algo_M->Timing.RateInteraction.TID1_3) {
    /* RateTransition generated from: '<Root>/Mode' */
    top_level_algo_B.TmpRTBAtModeOutport2 =
      top_level_algo_DW.TmpRTBAtModeOutport2_Buffer0;
  }

  /* End of RateTransition generated from: '<Root>/Mode' */

  /* Switch: '<Root>/Switch1' */
  if (top_level_algo_B.TmpRTBAtModeOutport2 > top_level_algo_P.Switch1_Threshold)
  {
    /* Switch: '<S2>/Switch' */
    if (top_level_algo_B.recoil_active > top_level_algo_P.Switch_Threshold) {
      /* RelationalOperator: '<S47>/Compare' incorporates:
       *  Constant: '<S47>/Constant'
       */
      rtb_Compare_bz = (top_level_algo_B.Merge <=
                        top_level_algo_P.CompareToConstant_const);

      /* Switch: '<Root>/Switch1' incorporates:
       *  Logic: '<S2>/NOT'
       *  SignalConversion generated from: '<S2>/Vector Concatenate'
       */
      top_level_algo_B.Switch1[0] = rtb_Compare_bz;
      top_level_algo_B.Switch1[1] = !rtb_Compare_bz;
    } else {
      /* Switch: '<Root>/Switch1' incorporates:
       *  Constant: '<S2>/Constant'
       */
      top_level_algo_B.Switch1[0] = top_level_algo_P.Constant_Value[0];
      top_level_algo_B.Switch1[1] = top_level_algo_P.Constant_Value[1];
    }

    /* End of Switch: '<S2>/Switch' */
  } else {
    /* Switch: '<Root>/Switch1' incorporates:
     *  Constant: '<Root>/Constant3'
     */
    top_level_algo_B.Switch1[0] = top_level_algo_P.Constant3_Value[0];
    top_level_algo_B.Switch1[1] = top_level_algo_P.Constant3_Value[1];
  }

  /* End of Switch: '<Root>/Switch1' */

  /* MATLABSystem: '<Root>/Digital Output8' */
  tmp = rt_roundd_snf(top_level_algo_B.Switch1[0]);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(23, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output8' */

  /* MATLABSystem: '<Root>/Digital Output9' */
  tmp = rt_roundd_snf(top_level_algo_B.Switch1[1]);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(22, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output9' */

  /* RateTransition generated from: '<Root>/Scope3' */
  if (top_level_algo_M->Timing.RateInteraction.TID1_2) {
    /* RateTransition generated from: '<Root>/Scope3' */
    top_level_algo_B.Max = top_level_algo_DW.displacement_Buffer0;
  }

  /* End of RateTransition generated from: '<Root>/Scope3' */
  /* RateTransition generated from: '<S3>/Subtract3' */
  if (top_level_algo_M->Timing.RateInteraction.TID1_2) {
    /* RateTransition generated from: '<S3>/Subtract3' */
    top_level_algo_B.displacement = top_level_algo_DW.displacement_Buffer0_g;
  }

  /* End of RateTransition generated from: '<S3>/Subtract3' */

  /* Sum: '<S3>/Subtract3' */
  top_level_algo_B.Subtract3 = top_level_algo_B.displacement -
    top_level_algo_B.Merge;

  /* Math: '<S10>/Mod' incorporates:
   *  Constant: '<S10>/Constant1'
   */
  rtb_TmpMLSysMemLayoutBufferAt_k = rt_modd_snf(top_level_algo_B.rate,
    top_level_algo_P.Constant1_Value);

  /* MATLABSystem: '<S10>/Divide by Constant and Round' incorporates:
   *  Sum: '<S10>/Subtract'
   */
  rtb_DividebyConstantandRound = floor((top_level_algo_B.rate -
    rtb_TmpMLSysMemLayoutBufferAt_k) * 0.01);

  /* SwitchCase: '<S12>/Switch Case' incorporates:
   *  SignalConversion generated from: '<S10>/Divide by Constant and Round'
   */
  if (rtIsNaN(rtb_DividebyConstantandRound) || rtIsInf
      (rtb_DividebyConstantandRound)) {
    tmp = 0.0;
  } else {
    tmp = fmod(rtb_DividebyConstantandRound, 4.294967296E+9);
  }

  switch (tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_i,
      &top_level_algo_P.IfActionSubsystem);

    /* End of Outputs for SubSystem: '<S12>/If Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_i,
      &top_level_algo_P.IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S12>/If Action Subsystem1' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_i,
      &top_level_algo_P.IfActionSubsystem2);

    /* End of Outputs for SubSystem: '<S12>/If Action Subsystem2' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S19>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_i,
      &top_level_algo_P.IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S12>/If Action Subsystem3' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S20>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_i,
      &top_level_algo_P.IfActionSubsystem4);

    /* End of Outputs for SubSystem: '<S12>/If Action Subsystem4' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S21>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_i,
      &top_level_algo_P.IfActionSubsystem5);

    /* End of Outputs for SubSystem: '<S12>/If Action Subsystem5' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S22>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_i,
      &top_level_algo_P.IfActionSubsystem6);

    /* End of Outputs for SubSystem: '<S12>/If Action Subsystem6' */
    break;

   case 7:
    /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S23>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_i,
      &top_level_algo_P.IfActionSubsystem7);

    /* End of Outputs for SubSystem: '<S12>/If Action Subsystem7' */
    break;

   case 8:
    /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S24>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_i,
      &top_level_algo_P.IfActionSubsystem8);

    /* End of Outputs for SubSystem: '<S12>/If Action Subsystem8' */
    break;

   case 9:
    /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem10' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_i,
      &top_level_algo_P.IfActionSubsystem10);

    /* End of Outputs for SubSystem: '<S12>/If Action Subsystem10' */
    break;
  }

  /* End of SwitchCase: '<S12>/Switch Case' */

  /* Math: '<S10>/Mod1' incorporates:
   *  Constant: '<S10>/Constant2'
   */
  rtb_Mod1 = rt_modd_snf(rtb_TmpMLSysMemLayoutBufferAt_k,
    top_level_algo_P.Constant2_Value_c);

  /* MATLABSystem: '<S10>/Divide by Constant and Round1' incorporates:
   *  Sum: '<S10>/Subtract1'
   */
  rtb_TmpMLSysMemLayoutBufferAt_k = floor((rtb_TmpMLSysMemLayoutBufferAt_k -
    rtb_Mod1) * 0.1);

  /* SwitchCase: '<S13>/Switch Case' incorporates:
   *  SignalConversion generated from: '<S10>/Divide by Constant and Round1'
   */
  if (rtIsNaN(rtb_TmpMLSysMemLayoutBufferAt_k) || rtIsInf
      (rtb_TmpMLSysMemLayoutBufferAt_k)) {
    tmp = 0.0;
  } else {
    tmp = fmod(rtb_TmpMLSysMemLayoutBufferAt_k, 4.294967296E+9);
  }

  switch (tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem_e);

    /* End of Outputs for SubSystem: '<S13>/If Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem1_g);

    /* End of Outputs for SubSystem: '<S13>/If Action Subsystem1' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem2_n);

    /* End of Outputs for SubSystem: '<S13>/If Action Subsystem2' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem3_d);

    /* End of Outputs for SubSystem: '<S13>/If Action Subsystem3' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S30>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem4_b);

    /* End of Outputs for SubSystem: '<S13>/If Action Subsystem4' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem5_b);

    /* End of Outputs for SubSystem: '<S13>/If Action Subsystem5' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S32>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem6_j);

    /* End of Outputs for SubSystem: '<S13>/If Action Subsystem6' */
    break;

   case 7:
    /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem7_i);

    /* End of Outputs for SubSystem: '<S13>/If Action Subsystem7' */
    break;

   case 8:
    /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem8_i);

    /* End of Outputs for SubSystem: '<S13>/If Action Subsystem8' */
    break;

   case 9:
    /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem10' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem10_g);

    /* End of Outputs for SubSystem: '<S13>/If Action Subsystem10' */
    break;
  }

  /* End of SwitchCase: '<S13>/Switch Case' */

  /* SwitchCase: '<S14>/Switch Case' */
  if (rtb_Mod1 < 0.0) {
    tmp = ceil(rtb_Mod1);
  } else {
    tmp = floor(rtb_Mod1);
  }

  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  switch (tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem' incorporates:
     *  ActionPort: '<S35>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_n0,
      &top_level_algo_P.IfActionSubsystem_b);

    /* End of Outputs for SubSystem: '<S14>/If Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S36>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_n0,
      &top_level_algo_P.IfActionSubsystem1_m);

    /* End of Outputs for SubSystem: '<S14>/If Action Subsystem1' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S38>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_n0,
      &top_level_algo_P.IfActionSubsystem2_f);

    /* End of Outputs for SubSystem: '<S14>/If Action Subsystem2' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S39>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_n0,
      &top_level_algo_P.IfActionSubsystem3_e);

    /* End of Outputs for SubSystem: '<S14>/If Action Subsystem3' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S40>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_n0,
      &top_level_algo_P.IfActionSubsystem4_o);

    /* End of Outputs for SubSystem: '<S14>/If Action Subsystem4' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S41>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_n0,
      &top_level_algo_P.IfActionSubsystem5_e);

    /* End of Outputs for SubSystem: '<S14>/If Action Subsystem5' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S42>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_n0,
      &top_level_algo_P.IfActionSubsystem6_l);

    /* End of Outputs for SubSystem: '<S14>/If Action Subsystem6' */
    break;

   case 7:
    /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S43>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_n0,
      &top_level_algo_P.IfActionSubsystem7_e);

    /* End of Outputs for SubSystem: '<S14>/If Action Subsystem7' */
    break;

   case 8:
    /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S44>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_n0,
      &top_level_algo_P.IfActionSubsystem8_n);

    /* End of Outputs for SubSystem: '<S14>/If Action Subsystem8' */
    break;

   case 9:
    /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem10' incorporates:
     *  ActionPort: '<S37>/Action Port'
     */
    top_level_IfActionSubsystem(&top_level_algo_B.Merge_n0,
      &top_level_algo_P.IfActionSubsystem10_g1);

    /* End of Outputs for SubSystem: '<S14>/If Action Subsystem10' */
    break;
  }

  /* End of SwitchCase: '<S14>/Switch Case' */

  /* Sum: '<S10>/Add' incorporates:
   *  ArithShift: '<S10>/Shift Arithmetic1'
   *  ArithShift: '<S10>/Shift Arithmetic2'
   *  DataTypeConversion: '<S10>/Cast To Double'
   *  DataTypeConversion: '<S10>/Cast To Double1'
   *  DataTypeConversion: '<S10>/Cast To Double2'
   */
  top_level_algo_B.Add = (((uint32_T)top_level_algo_B.Merge_d << 8) +
    top_level_algo_B.Merge_i) + ((uint32_T)top_level_algo_B.Merge_n0 << 16);

  /* Sum: '<S10>/Add1' incorporates:
   *  ArithShift: '<S10>/Shift Arithmetic3'
   *  Constant: '<S10>/Constant'
   *  Sum: '<S10>/Add'
   */
  top_level_algo_B.Add1 = (top_level_algo_B.Add << 1) +
    top_level_algo_P.Constant_Value_at;

  /* DataTypeConversion: '<S11>/Cast To Double' */
  top_level_algo_B.CastToDouble = top_level_algo_B.Add;

  /* DiscretePulseGenerator: '<S1>/Pulse Generator' */
  top_level_algo_B.PulseGenerator = (top_level_algo_DW.clockTickCounter <
    top_level_algo_P.PulseGenerator_Duty) && (top_level_algo_DW.clockTickCounter
    >= 0) ? top_level_algo_P.PulseGenerator_Amp : 0.0;

  /* DiscretePulseGenerator: '<S1>/Pulse Generator' */
  if (top_level_algo_DW.clockTickCounter >=
      top_level_algo_P.PulseGenerator_Period - 1.0) {
    top_level_algo_DW.clockTickCounter = 0;
  } else {
    top_level_algo_DW.clockTickCounter++;
  }

  /* Chart: '<S11>/DataLogic' */
  if (top_level_algo_DW.temporalCounter_i1_c < 31U) {
    top_level_algo_DW.temporalCounter_i1_c++;
  }

  if (top_level_algo_DW.is_active_c18_top_level_algo == 0U) {
    top_level_algo_DW.is_active_c18_top_level_algo = 1U;
    top_level_algo_DW.is_c18_top_level_algo = top_level_algo_IN_LOAD;
    top_level_algo_B.data = 0U;
    top_level_algo_DW.Holder = top_level_algo_B.CastToDouble;
  } else {
    switch (top_level_algo_DW.is_c18_top_level_algo) {
     case top_level_algo_IN_CHECK:
      if (top_level_algo_DW.Holder == 0U) {
        top_level_algo_DW.is_c18_top_level_algo = top_level_algo_IN_WAITING;
        top_level_algo_DW.temporalCounter_i1_c = 0U;
      } else if (top_level_algo_DW.temporalCounter_i1_c >= 10U) {
        top_level_algo_DW.is_c18_top_level_algo = top_level_algo_IN_MASK;
        top_level_algo_DW.temporalCounter_i1_c = 0U;
        top_level_algo_B.data = top_level_algo_DW.Holder & 1U;
      }
      break;

     case top_level_algo_IN_LOAD:
      if (top_level_algo_B.PulseGenerator == 1.0) {
        top_level_algo_DW.is_c18_top_level_algo = top_level_algo_IN_Wait;
        top_level_algo_DW.temporalCounter_i1_c = 0U;
      }
      break;

     case top_level_algo_IN_MASK:
      if (top_level_algo_DW.temporalCounter_i1_c >= 10U) {
        top_level_algo_DW.is_c18_top_level_algo = top_level_algo_IN_CHECK;
        top_level_algo_DW.temporalCounter_i1_c = 0U;
        top_level_algo_DW.Holder >>= 1;
      }
      break;

     case top_level_algo_IN_START_n:
      if (top_level_algo_DW.temporalCounter_i1_c >= 20U) {
        top_level_algo_DW.is_c18_top_level_algo = top_level_algo_IN_MASK;
        top_level_algo_DW.temporalCounter_i1_c = 0U;
        top_level_algo_B.data = top_level_algo_DW.Holder & 1U;
      }
      break;

     case top_level_algo_IN_WAITING:
      if (top_level_algo_DW.temporalCounter_i1_c >= 10U) {
        top_level_algo_DW.is_c18_top_level_algo = top_level_algo_IN_LOAD;
        top_level_algo_B.data = 0U;
        top_level_algo_DW.Holder = top_level_algo_B.CastToDouble;
      }
      break;

     default:
      /* case IN_Wait: */
      if (top_level_algo_DW.temporalCounter_i1_c >= 5U) {
        top_level_algo_DW.is_c18_top_level_algo = top_level_algo_IN_START_n;
        top_level_algo_DW.temporalCounter_i1_c = 0U;
        top_level_algo_B.data = 1U;
      }
      break;
    }
  }

  /* End of Chart: '<S11>/DataLogic' */

  /* RateTransition generated from: '<Root>/Mode' */
  if (top_level_algo_M->Timing.RateInteraction.TID1_3) {
    /* RateTransition generated from: '<Root>/Mode' */
    top_level_algo_B.TmpRTBAtModeOutport3 =
      top_level_algo_DW.TmpRTBAtModeOutport3_Buffer0;
  }

  /* End of RateTransition generated from: '<Root>/Mode' */

  /* Switch: '<S1>/Switch2' */
  if (top_level_algo_B.TmpRTBAtModeOutport3 > top_level_algo_P.Switch2_Threshold)
  {
    /* Switch: '<S1>/Switch2' */
    top_level_algo_B.Switch2 = top_level_algo_B.data;
  } else {
    /* Switch: '<S1>/Switch2' incorporates:
     *  Constant: '<S1>/Constant4'
     */
    top_level_algo_B.Switch2 = (uint32_T)top_level_algo_P.Constant4_Value;
  }

  /* End of Switch: '<S1>/Switch2' */

  /* Chart: '<S11>/ClockLogic' */
  if (top_level_algo_DW.temporalCounter_i1_f < 15U) {
    top_level_algo_DW.temporalCounter_i1_f++;
  }

  if (top_level_algo_DW.is_active_c17_top_level_algo == 0U) {
    top_level_algo_DW.is_active_c17_top_level_algo = 1U;
    top_level_algo_DW.is_c17_top_level_algo = top_level_algo_IN_START;
    top_level_algo_DW.counter = 0.0;
    top_level_algo_B.CLK = 0.0;
  } else {
    switch (top_level_algo_DW.is_c17_top_level_algo) {
     case top_level_algo_IN_HIGH:
      if (top_level_algo_DW.temporalCounter_i1_f >= 10U) {
        top_level_algo_DW.is_c17_top_level_algo = top_level_algo_IN_LOW;
        top_level_algo_DW.temporalCounter_i1_f = 0U;
        top_level_algo_B.CLK = 0.0;
        top_level_algo_DW.counter++;
      }
      break;

     case top_level_algo_IN_LOW:
      if (top_level_algo_DW.counter == 36.0) {
        top_level_algo_DW.is_c17_top_level_algo = top_level_algo_IN_START;
        top_level_algo_DW.counter = 0.0;
        top_level_algo_B.CLK = 0.0;
      } else if (top_level_algo_DW.temporalCounter_i1_f >= 10U) {
        top_level_algo_DW.is_c17_top_level_algo = top_level_algo_IN_HIGH;
        top_level_algo_DW.temporalCounter_i1_f = 0U;
        top_level_algo_B.CLK = 1.0;
      }
      break;

     case top_level_algo_IN_START:
      if (top_level_algo_B.PulseGenerator == 1.0) {
        top_level_algo_DW.is_c17_top_level_algo = top_level_algo_IN_WAIT;
        top_level_algo_DW.temporalCounter_i1_f = 0U;
      } else {
        top_level_algo_DW.counter = 0.0;
        top_level_algo_B.CLK = 0.0;
      }
      break;

     default:
      /* case IN_WAIT: */
      if (top_level_algo_DW.temporalCounter_i1_f >= 10U) {
        top_level_algo_DW.is_c17_top_level_algo = top_level_algo_IN_HIGH;
        top_level_algo_DW.temporalCounter_i1_f = 0U;
        top_level_algo_B.CLK = 1.0;
      }
      break;
    }
  }

  /* End of Chart: '<S11>/ClockLogic' */
  /* SignalConversion generated from: '<S10>/Vector Concatenate' incorporates:
   *  Concatenate: '<S10>/Vector Concatenate'
   *  SignalConversion generated from: '<S10>/Divide by Constant and Round'
   */
  top_level_algo_B.VectorConcatenate[0] = rtb_DividebyConstantandRound;

  /* SignalConversion generated from: '<S10>/Vector Concatenate' incorporates:
   *  Concatenate: '<S10>/Vector Concatenate'
   *  SignalConversion generated from: '<S10>/Divide by Constant and Round1'
   */
  top_level_algo_B.VectorConcatenate[1] = rtb_TmpMLSysMemLayoutBufferAt_k;

  /* SignalConversion generated from: '<S10>/Vector Concatenate' incorporates:
   *  Concatenate: '<S10>/Vector Concatenate'
   */
  top_level_algo_B.VectorConcatenate[2] = rtb_Mod1;

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
  boolean_T rtb_LogicalOperator7;
  boolean_T rtb_NOT;
  boolean_T rtb_NOT2;

  {
    codertarget_arduinobase_inter_T *obj;
    real_T u;
    int32_T i;
    int32_T measure_period;
    int32_T str;
    int16_T Mean_AccVal_f;
    uint8_T tmp;
    boolean_T Delay1_DSTATE_m_tmp;
    boolean_T Delay7_DSTATE_tmp;
    boolean_T rtb_NOT_tmp;

    /* Reset subsysRan breadcrumbs */
    srClearBC(top_level_algo_DW.IfActionSubsystem_SubsysRanBC_e);

    /* Reset subsysRan breadcrumbs */
    srClearBC(top_level_algo_DW.IfActionSubsystem1_SubsysRanB_h);

    /* Reset subsysRan breadcrumbs */
    srClearBC(top_level_algo_DW.IfActionSubsystem_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(top_level_algo_DW.IfActionSubsystem1_SubsysRanBC);

    /* S-Function (sdspstatfcns): '<S5>/Mean1' incorporates:
     *  S-Function (sfix_udelay): '<S5>/Tapped Delay1'
     */
    top_level_algo_B.Mean1_AccVal = top_level_algo_DW.TappedDelay1_X[0];
    str = 1;
    for (i = 18; i >= 0; i--) {
      top_level_algo_B.Mean1_AccVal += top_level_algo_DW.TappedDelay1_X[str];
      str++;
    }

    /* S-Function (sdspstatfcns): '<S5>/Mean1' */
    top_level_algo_B.Mean1 = top_level_algo_B.Mean1_AccVal / 20.0;

    /* Chart: '<S5>/timer' */
    if (top_level_algo_DW.temporalCounter_i1_j < 511U) {
      top_level_algo_DW.temporalCounter_i1_j++;
    }

    if (top_level_algo_DW.is_active_c3_top_level_algo == 0U) {
      top_level_algo_DW.is_active_c3_top_level_algo = 1U;
      top_level_algo_DW.is_c3_top_level_algo = top_level_algo_IN_Starting;
      top_level_algo_DW.temporalCounter_i1_j = 0U;
      measure_period = 0;
    } else if (top_level_algo_DW.is_c3_top_level_algo ==
               top_level_algo_IN_Finished) {
      measure_period = 1;
    } else {
      /* case IN_Starting: */
      measure_period = 0;
      if (top_level_algo_DW.temporalCounter_i1_j >= 400U) {
        top_level_algo_DW.is_c3_top_level_algo = top_level_algo_IN_Finished;
        top_level_algo_B.baseline = top_level_algo_B.Mean1;
        measure_period = 1;
      }
    }

    /* End of Chart: '<S5>/timer' */

    /* S-Function (sdspstatfcns): '<S5>/Mean' incorporates:
     *  S-Function (sfix_udelay): '<S5>/Tapped Delay'
     */
    Mean_AccVal_f = (int16_T)top_level_algo_DW.TappedDelay_X_f[0];
    str = 1;
    for (i = 8; i >= 0; i--) {
      Mean_AccVal_f += top_level_algo_DW.TappedDelay_X_f[str];
      str++;
    }

    /* Product: '<S5>/Product' incorporates:
     *  Constant: '<S5>/Constant'
     *  Constant: '<S5>/Constant1'
     *  Product: '<S5>/Divide'
     *  S-Function (sdspstatfcns): '<S5>/Mean'
     */
    top_level_algo_B.Product = (real_T)(uint16_T)div_nde_s32_floor(Mean_AccVal_f,
      10) / top_level_algo_P.Constant1_Value_d * top_level_algo_P.Vdd;

    /* Switch: '<S5>/Switch' */
    if (measure_period > top_level_algo_P.Switch_Threshold_c) {
      top_level_algo_B.Mean1_AccVal = top_level_algo_B.baseline;
    } else {
      top_level_algo_B.Mean1_AccVal = top_level_algo_B.Product;
    }

    /* Gain: '<S5>/Radius (mm)' incorporates:
     *  Gain: '<S5>/Gear Down'
     *  Gain: '<S5>/rad  per volt'
     *  Sum: '<S5>/Subtract'
     *  Switch: '<S5>/Switch'
     */
    top_level_algo_B.Merge_n = 6.2831853071795862 / top_level_algo_P.Vdd *
      (top_level_algo_B.Mean1_AccVal - top_level_algo_B.Product) * (1.0 /
      top_level_algo_P.gear_ratio) * top_level_algo_P.Radiusmm_Gain;

    /* If: '<S53>/If' */
    if (top_level_algo_B.Merge_n < 0.0) {
      /* Outputs for IfAction SubSystem: '<S53>/If Action Subsystem' incorporates:
       *  ActionPort: '<S55>/Action Port'
       */
      /* Gain: '<S5>/Radius (mm)' incorporates:
       *  Constant: '<S53>/Constant'
       *  Merge: '<S53>/Merge'
       *  SignalConversion generated from: '<S55>/In1'
       */
      top_level_algo_B.Merge_n = top_level_algo_P.Constant_Value_a;

      /* End of Outputs for SubSystem: '<S53>/If Action Subsystem' */

      /* Update for IfAction SubSystem: '<S53>/If Action Subsystem' incorporates:
       *  ActionPort: '<S55>/Action Port'
       */
      /* Update for If: '<S53>/If' */
      srUpdateBC(top_level_algo_DW.IfActionSubsystem_SubsysRanBC_e);

      /* End of Update for SubSystem: '<S53>/If Action Subsystem' */
    } else {
      /* Update for IfAction SubSystem: '<S53>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S56>/Action Port'
       */
      /* Update for If: '<S53>/If' */
      srUpdateBC(top_level_algo_DW.IfActionSubsystem1_SubsysRanB_h);

      /* End of Update for SubSystem: '<S53>/If Action Subsystem1' */
    }

    /* End of If: '<S53>/If' */

    /* RateTransition generated from: '<Root>/Mode' */
    if (top_level_algo_M->Timing.RateInteraction.TID2_3) {
      /* RateTransition generated from: '<Root>/Mode' */
      top_level_algo_B.TmpRTBAtModeOutport1 =
        top_level_algo_DW.TmpRTBAtModeOutport1_Buffer0;
    }

    /* End of RateTransition generated from: '<Root>/Mode' */

    /* Switch: '<Root>/Switch' */
    if (top_level_algo_B.TmpRTBAtModeOutport1 >
        top_level_algo_P.Switch_Threshold_j) {
      /* Switch: '<Root>/Switch' incorporates:
       *  Constant: '<S57>/Constant'
       *  Constant: '<S58>/Constant'
       *  Constant: '<S59>/Constant'
       *  Constant: '<S60>/Constant'
       *  RelationalOperator: '<S57>/Compare'
       *  RelationalOperator: '<S58>/Compare'
       *  RelationalOperator: '<S59>/Compare'
       *  RelationalOperator: '<S60>/Compare'
       */
      top_level_algo_B.Switch[0] = (top_level_algo_B.Merge_n >
        top_level_algo_P.CompareToConstant1_const);
      top_level_algo_B.Switch[1] = (top_level_algo_B.Merge_n >
        top_level_algo_P.CompareToConstant2_const);
      top_level_algo_B.Switch[2] = (top_level_algo_B.Merge_n >
        top_level_algo_P.CompareToConstant3_const);
      top_level_algo_B.Switch[3] = (top_level_algo_B.Merge_n >
        top_level_algo_P.CompareToConstant4_const);
    } else {
      /* Switch: '<Root>/Switch' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      top_level_algo_B.Switch[0] = top_level_algo_P.Constant2_Value[0];
      top_level_algo_B.Switch[1] = top_level_algo_P.Constant2_Value[1];
      top_level_algo_B.Switch[2] = top_level_algo_P.Constant2_Value[2];
      top_level_algo_B.Switch[3] = top_level_algo_P.Constant2_Value[3];
    }

    /* End of Switch: '<Root>/Switch' */

    /* MATLABSystem: '<Root>/Digital Output4' */
    top_level_algo_B.Mean1_AccVal = rt_roundd_snf(top_level_algo_B.Switch[0]);
    if (top_level_algo_B.Mean1_AccVal < 256.0) {
      if (top_level_algo_B.Mean1_AccVal >= 0.0) {
        tmp = (uint8_T)top_level_algo_B.Mean1_AccVal;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(21, tmp);

    /* End of MATLABSystem: '<Root>/Digital Output4' */

    /* MATLABSystem: '<Root>/Digital Output5' */
    top_level_algo_B.Mean1_AccVal = rt_roundd_snf(top_level_algo_B.Switch[1]);
    if (top_level_algo_B.Mean1_AccVal < 256.0) {
      if (top_level_algo_B.Mean1_AccVal >= 0.0) {
        tmp = (uint8_T)top_level_algo_B.Mean1_AccVal;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(19, tmp);

    /* End of MATLABSystem: '<Root>/Digital Output5' */

    /* MATLABSystem: '<Root>/Digital Output6' */
    top_level_algo_B.Mean1_AccVal = rt_roundd_snf(top_level_algo_B.Switch[2]);
    if (top_level_algo_B.Mean1_AccVal < 256.0) {
      if (top_level_algo_B.Mean1_AccVal >= 0.0) {
        tmp = (uint8_T)top_level_algo_B.Mean1_AccVal;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(18, tmp);

    /* End of MATLABSystem: '<Root>/Digital Output6' */

    /* MATLABSystem: '<Root>/Digital Output7' */
    top_level_algo_B.Mean1_AccVal = rt_roundd_snf(top_level_algo_B.Switch[3]);
    if (top_level_algo_B.Mean1_AccVal < 256.0) {
      if (top_level_algo_B.Mean1_AccVal >= 0.0) {
        tmp = (uint8_T)top_level_algo_B.Mean1_AccVal;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(5, tmp);

    /* End of MATLABSystem: '<Root>/Digital Output7' */
    /* MATLABSystem: '<Root>/Analog Input' */
    if (top_level_algo_DW.obj.SampleTime !=
        top_level_algo_P.AnalogInput_SampleTime) {
      top_level_algo_DW.obj.SampleTime = top_level_algo_P.AnalogInput_SampleTime;
    }

    obj = &top_level_algo_DW.obj;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(15U);
    top_level_algo_B.datatype_id = MW_ANALOGIN_UINT16;

    /* MATLABSystem: '<Root>/Analog Input' */
    MW_AnalogInSingle_ReadResult
      (top_level_algo_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
       &top_level_algo_B.AnalogInput, top_level_algo_B.datatype_id);

    /* Sum: '<S4>/5to30 Diff' incorporates:
     *  Delay: '<S4>/Delay4'
     *  Delay: '<S4>/Delay5'
     */
    top_level_algo_B.Mean = top_level_algo_DW.Delay4_DSTATE[0] -
      top_level_algo_DW.Delay5_DSTATE[0];

    /* Sum: '<S4>/First Diff' incorporates:
     *  Delay: '<S4>/Delay'
     */
    top_level_algo_B.Mean1_AccVal = top_level_algo_B.Merge_n -
      top_level_algo_DW.Delay_DSTATE;

    /* Sum: '<S4>/Second Diff' incorporates:
     *  Delay: '<S4>/Delay'
     *  Delay: '<S4>/Delay1'
     */
    top_level_algo_B.u = top_level_algo_DW.Delay_DSTATE -
      top_level_algo_DW.Delay1_DSTATE[0];

    /* Sum: '<S4>/Third Diff' incorporates:
     *  Delay: '<S4>/Delay1'
     *  Delay: '<S4>/Delay2'
     */
    top_level_algo_B.u_m = top_level_algo_DW.Delay1_DSTATE[0] -
      top_level_algo_DW.Delay2_DSTATE[0];

    /* Sum: '<S4>/Fourth Diff' incorporates:
     *  Delay: '<S4>/Delay2'
     *  Delay: '<S4>/Delay3'
     */
    top_level_algo_B.u_c = top_level_algo_DW.Delay2_DSTATE[0] -
      top_level_algo_DW.Delay3_DSTATE[0];

    /* Sum: '<S4>/Fifth Diff' incorporates:
     *  Delay: '<S4>/Delay3'
     *  Delay: '<S4>/Delay4'
     */
    u = top_level_algo_DW.Delay3_DSTATE[0] - top_level_algo_DW.Delay4_DSTATE[0];

    /* Signum: '<S4>/Sign' */
    if (rtIsNaN(top_level_algo_B.Mean1_AccVal)) {
      top_level_algo_B.Mean1_AccVal = (rtNaN);
    } else if (top_level_algo_B.Mean1_AccVal < 0.0) {
      top_level_algo_B.Mean1_AccVal = -1.0;
    } else {
      top_level_algo_B.Mean1_AccVal = (top_level_algo_B.Mean1_AccVal > 0.0);
    }

    /* Signum: '<S4>/Sign1' */
    if (rtIsNaN(top_level_algo_B.u)) {
      top_level_algo_B.u = (rtNaN);
    } else if (top_level_algo_B.u < 0.0) {
      top_level_algo_B.u = -1.0;
    } else {
      top_level_algo_B.u = (top_level_algo_B.u > 0.0);
    }

    /* Signum: '<S4>/Sign2' */
    if (rtIsNaN(top_level_algo_B.u_m)) {
      top_level_algo_B.u_m = (rtNaN);
    } else if (top_level_algo_B.u_m < 0.0) {
      top_level_algo_B.u_m = -1.0;
    } else {
      top_level_algo_B.u_m = (top_level_algo_B.u_m > 0.0);
    }

    /* Signum: '<S4>/Sign3' */
    if (rtIsNaN(top_level_algo_B.u_c)) {
      top_level_algo_B.u_c = (rtNaN);
    } else if (top_level_algo_B.u_c < 0.0) {
      top_level_algo_B.u_c = -1.0;
    } else {
      top_level_algo_B.u_c = (top_level_algo_B.u_c > 0.0);
    }

    /* Signum: '<S4>/Sign4' */
    if (rtIsNaN(u)) {
      u = (rtNaN);
    } else if (u < 0.0) {
      u = -1.0;
    } else {
      u = (u > 0.0);
    }

    /* Signum: '<S4>/Sign5' */
    if (rtIsNaN(top_level_algo_B.Mean)) {
      top_level_algo_B.Mean = (rtNaN);
    } else if (top_level_algo_B.Mean < 0.0) {
      top_level_algo_B.Mean = -1.0;
    } else {
      top_level_algo_B.Mean = (top_level_algo_B.Mean > 0.0);
    }

    /* Sum: '<S4>/Add' incorporates:
     *  Gain: '<S4>/Gain'
     *  Gain: '<S4>/Gain1'
     *  Signum: '<S4>/Sign'
     *  Signum: '<S4>/Sign1'
     *  Signum: '<S4>/Sign2'
     *  Signum: '<S4>/Sign3'
     *  Signum: '<S4>/Sign4'
     *  Signum: '<S4>/Sign5'
     */
    top_level_algo_B.MajorityVoterSlope = ((((top_level_algo_P.Gain_Gain *
      top_level_algo_B.Mean1_AccVal + top_level_algo_P.Gain1_Gain *
      top_level_algo_B.u) + top_level_algo_B.u_m) + top_level_algo_B.u_c) + u) +
      top_level_algo_B.Mean;

    /* S-Function (sfix_udelay): '<S4>/Tapped Delay' */
    memcpy(&top_level_algo_B.TappedDelay[0], &top_level_algo_DW.TappedDelay_X[0],
           10U * sizeof(real_T));

    /* S-Function (sdspstatfcns): '<S4>/Mean' */
    top_level_algo_B.Mean1_AccVal = top_level_algo_B.TappedDelay[0];
    str = 1;
    for (i = 8; i >= 0; i--) {
      top_level_algo_B.Mean1_AccVal += top_level_algo_B.TappedDelay[str];
      str++;
    }

    /* Gain: '<S4>/Compression  Sensitivity' incorporates:
     *  S-Function (sdspstatfcns): '<S4>/Mean'
     */
    top_level_algo_B.LongRangeDiff = top_level_algo_B.Mean1_AccVal / 10.0 *
      top_level_algo_P.CompressionSensitivity_Gain;

    /* Logic: '<S4>/AND' incorporates:
     *  Constant: '<S50>/Constant'
     *  Constant: '<S52>/Constant'
     *  RelationalOperator: '<S50>/Compare'
     *  RelationalOperator: '<S52>/Compare'
     */
    top_level_algo_B.IsPos = ((top_level_algo_B.MajorityVoterSlope >=
      top_level_algo_P.Positive_const) && (top_level_algo_B.LongRangeDiff >=
      top_level_algo_P.Longrangemotionup_const));

    /* Logic: '<S4>/AND1' incorporates:
     *  Constant: '<S49>/Constant'
     *  Constant: '<S51>/Constant'
     *  RelationalOperator: '<S49>/Compare'
     *  RelationalOperator: '<S51>/Compare'
     */
    top_level_algo_B.IsNeg = ((top_level_algo_B.MajorityVoterSlope <=
      top_level_algo_P.Negative_const) && (top_level_algo_B.LongRangeDiff <=
      top_level_algo_P.Longrangemotiondown_const));

    /* Logic: '<S8>/Logical Operator' incorporates:
     *  Logic: '<S4>/Zero'
     *  Logic: '<S8>/OR1'
     */
    Delay7_DSTATE_tmp = !top_level_algo_B.IsNeg;

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
    top_level_algo_B.LogicalOperator3 = (top_level_algo_B.IsPos &&
      (!top_level_algo_DW.Delay7_DSTATE));

    /* Logic: '<S8>/AND' incorporates:
     *  Delay: '<S8>/Delay6'
     *  Logic: '<S8>/NOT3'
     */
    top_level_algo_B.AND = (top_level_algo_B.LogicalOperator3 &&
      (!top_level_algo_DW.Delay6_DSTATE[0]));

    /* Gain: '<Root>/Gain' */
    top_level_algo_B.comp = (uint8_T)(top_level_algo_B.AND ? (int32_T)
      top_level_algo_P.Gain_Gain_l : 0);

    /* S-Function (sdspcount2): '<S3>/Counter1' incorporates:
     *  Constant: '<S3>/Constant2'
     */
    if (MWDSP_EPH_R_D(top_level_algo_P.Constant2_Value_p,
                      &top_level_algo_DW.Counter1_RstEphState) != 0U) {
      top_level_algo_DW.Counter1_Count = top_level_algo_P.Counter1_InitialCount;
    }

    if (MWDSP_EPH_R_B(top_level_algo_B.AND,
                      &top_level_algo_DW.Counter1_ClkEphState) != 0U) {
      if (top_level_algo_DW.Counter1_Count < 100) {
        top_level_algo_DW.Counter1_Count++;
      } else {
        top_level_algo_DW.Counter1_Count = 0U;
      }
    }

    /* S-Function (sdspcount2): '<S3>/Counter1' */
    top_level_algo_B.Counter1 = top_level_algo_DW.Counter1_Count;

    /* Switch: '<S66>/Reset' incorporates:
     *  Delay: '<S8>/Delay'
     *  MinMax: '<S61>/MinMax'
     */
    if (top_level_algo_DW.Delay_DSTATE_a[0U]) {
      /* Switch: '<S66>/Reset' incorporates:
       *  Constant: '<S66>/Initial Condition'
       */
      top_level_algo_B.Reset = top_level_algo_P.MaxBDC_vinit;
    } else if ((top_level_algo_B.Merge_n >=
                top_level_algo_DW.Memory_PreviousInput) || rtIsNaN
               (top_level_algo_DW.Memory_PreviousInput)) {
      /* MinMax: '<S61>/MinMax' incorporates:
       *  Switch: '<S66>/Reset'
       */
      top_level_algo_B.Reset = top_level_algo_B.Merge_n;
    } else {
      /* Switch: '<S66>/Reset' incorporates:
       *  MinMax: '<S61>/MinMax'
       */
      top_level_algo_B.Reset = top_level_algo_DW.Memory_PreviousInput;
    }

    /* End of Switch: '<S66>/Reset' */

    /* Logic: '<S8>/Logical Operator4' incorporates:
     *  Logic: '<S4>/Zero'
     *  Logic: '<S8>/OR'
     */
    Delay1_DSTATE_m_tmp = !top_level_algo_B.IsPos;

    /* Logic: '<S8>/Logical Operator5' incorporates:
     *  Delay: '<S8>/Delay1'
     *  Delay: '<S8>/Delay4'
     *  Logic: '<S8>/Logical Operator4'
     *  Logic: '<S8>/Logical Operator6'
     */
    top_level_algo_DW.Delay1_DSTATE_m = (Delay1_DSTATE_m_tmp &&
      (top_level_algo_DW.Delay4_DSTATE_a[0] || top_level_algo_DW.Delay1_DSTATE_m));

    /* Logic: '<S8>/Logical Operator7' incorporates:
     *  Delay: '<S8>/Delay1'
     *  Logic: '<S8>/NOT5'
     */
    rtb_LogicalOperator7 = (top_level_algo_B.IsNeg &&
      (!top_level_algo_DW.Delay1_DSTATE_m));

    /* Logic: '<S8>/AND1' incorporates:
     *  Delay: '<S8>/Delay3'
     *  Logic: '<S8>/NOT1'
     */
    top_level_algo_B.AND1 = (rtb_LogicalOperator7 &&
      (!top_level_algo_DW.Delay3_DSTATE_m[0]));

    /* Chart: '<S8>/sample and hold' */
    if (top_level_algo_DW.is_active_c1_top_level_algo == 0U) {
      top_level_algo_DW.is_active_c1_top_level_algo = 1U;
      top_level_algo_DW.is_c1_top_level_algo = top_level_algo_IN_Init;
      top_level_algo_B.displacement_a = 0.0;
    } else if (top_level_algo_DW.is_c1_top_level_algo ==
               top_level_algo_IN_Holding) {
      if (top_level_algo_B.AND1) {
        top_level_algo_B.displacement_a = top_level_algo_B.Reset;
      }

      /* case IN_Init: */
    } else if (top_level_algo_B.AND1) {
      top_level_algo_DW.is_c1_top_level_algo = top_level_algo_IN_Holding;
      top_level_algo_B.displacement_a = top_level_algo_B.Reset;
    }

    /* End of Chart: '<S8>/sample and hold' */
    /* RateTransition generated from: '<S3>/Chart1' */
    top_level_algo_DW.TmpRTBAtChart1Inport2_Buffer0 = top_level_algo_B.AND;

    /* RateTransition generated from: '<S3>/Subtract3' */
    top_level_algo_DW.displacement_Buffer0_g = top_level_algo_B.displacement_a;

    /* Sum: '<S4>/30 Diff' incorporates:
     *  Delay: '<S4>/Delay5'
     */
    top_level_algo_B.u0Diff = top_level_algo_B.Merge_n -
      top_level_algo_DW.Delay5_DSTATE[0];

    /* Switch: '<S67>/Reset' incorporates:
     *  Delay: '<S8>/Delay2'
     *  Memory: '<S67>/Memory'
     *  MinMax: '<S62>/MinMax'
     */
    if (top_level_algo_DW.Delay2_DSTATE_m[0U]) {
      /* Switch: '<S67>/Reset' incorporates:
       *  Constant: '<S67>/Initial Condition'
       */
      top_level_algo_B.Reset_b = top_level_algo_P.MinBDC_vinit;
    } else if ((top_level_algo_B.Merge_n <=
                top_level_algo_DW.Memory_PreviousInput_m) || rtIsNaN
               (top_level_algo_DW.Memory_PreviousInput_m)) {
      /* MinMax: '<S62>/MinMax' incorporates:
       *  Switch: '<S67>/Reset'
       */
      top_level_algo_B.Reset_b = top_level_algo_B.Merge_n;
    } else {
      /* Switch: '<S67>/Reset' incorporates:
       *  Memory: '<S67>/Memory'
       *  MinMax: '<S62>/MinMax'
       */
      top_level_algo_B.Reset_b = top_level_algo_DW.Memory_PreviousInput_m;
    }

    /* End of Switch: '<S67>/Reset' */

    /* Logic: '<S8>/OR' incorporates:
     *  Logic: '<S4>/Zero'
     *  Logic: '<S8>/OR1'
     */
    rtb_NOT_tmp = ((!Delay1_DSTATE_m_tmp) || (!Delay7_DSTATE_tmp));

    /* Logic: '<S8>/NOT' incorporates:
     *  Logic: '<S8>/OR'
     */
    rtb_NOT = (Delay1_DSTATE_m_tmp && rtb_NOT_tmp);

    /* Logic: '<S8>/NOT2' incorporates:
     *  Logic: '<S8>/OR1'
     */
    rtb_NOT2 = (rtb_NOT_tmp && Delay7_DSTATE_tmp);

    /* Chart: '<S8>/sample and hold1' */
    if (top_level_algo_DW.is_active_c2_top_level_algo == 0U) {
      top_level_algo_DW.is_active_c2_top_level_algo = 1U;
      top_level_algo_DW.is_c2_top_level_algo = top_level_algo_IN_Init;
      top_level_algo_B.displacement_e = 0.0;
    } else if (top_level_algo_DW.is_c2_top_level_algo ==
               top_level_algo_IN_Holding) {
      if (top_level_algo_B.AND) {
        top_level_algo_B.displacement_e = top_level_algo_B.Reset_b;
      }

      /* case IN_Init: */
    } else if (top_level_algo_B.AND) {
      top_level_algo_DW.is_c2_top_level_algo = top_level_algo_IN_Holding;
      top_level_algo_B.displacement_e = top_level_algo_B.Reset_b;
    }

    /* End of Chart: '<S8>/sample and hold1' */

    /* If: '<S63>/If' */
    if (top_level_algo_B.displacement_e < 0.0) {
      /* Outputs for IfAction SubSystem: '<S63>/If Action Subsystem' incorporates:
       *  ActionPort: '<S68>/Action Port'
       */
      /* Merge: '<S63>/Merge' incorporates:
       *  Constant: '<S63>/Constant'
       *  SignalConversion generated from: '<S68>/In1'
       */
      top_level_algo_B.Merge = top_level_algo_P.Constant_Value_i;

      /* End of Outputs for SubSystem: '<S63>/If Action Subsystem' */

      /* Update for IfAction SubSystem: '<S63>/If Action Subsystem' incorporates:
       *  ActionPort: '<S68>/Action Port'
       */
      /* Update for If: '<S63>/If' */
      srUpdateBC(top_level_algo_DW.IfActionSubsystem_SubsysRanBC);

      /* End of Update for SubSystem: '<S63>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S63>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S69>/Action Port'
       */
      /* Merge: '<S63>/Merge' incorporates:
       *  SignalConversion generated from: '<S69>/In1'
       */
      top_level_algo_B.Merge = top_level_algo_B.displacement_e;

      /* End of Outputs for SubSystem: '<S63>/If Action Subsystem1' */

      /* Update for IfAction SubSystem: '<S63>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S69>/Action Port'
       */
      /* Update for If: '<S63>/If' */
      srUpdateBC(top_level_algo_DW.IfActionSubsystem1_SubsysRanBC);

      /* End of Update for SubSystem: '<S63>/If Action Subsystem1' */
    }

    /* End of If: '<S63>/If' */

    /* RateTransition generated from: '<Root>/Scope3' */
    top_level_algo_DW.displacement_Buffer0 = top_level_algo_B.displacement_a;
  }

  {
    int_T i;

    /* Update for S-Function (sfix_udelay): '<S5>/Tapped Delay1' */
    for (i = 0; i < 19; i++) {
      top_level_algo_DW.TappedDelay1_X[i] = top_level_algo_DW.TappedDelay1_X[i +
        1];
    }

    top_level_algo_DW.TappedDelay1_X[19] = top_level_algo_B.Product;

    /* End of Update for S-Function (sfix_udelay): '<S5>/Tapped Delay1' */

    /* Update for Delay: '<S4>/Delay' */
    top_level_algo_DW.Delay_DSTATE = top_level_algo_B.Merge_n;

    /* Update for Delay: '<S4>/Delay1' */
    top_level_algo_DW.Delay1_DSTATE[0] = top_level_algo_DW.Delay1_DSTATE[1];
    top_level_algo_DW.Delay1_DSTATE[1] = top_level_algo_B.Merge_n;

    /* Update for Delay: '<S4>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE[0] = top_level_algo_DW.Delay2_DSTATE[1];
    top_level_algo_DW.Delay2_DSTATE[1] = top_level_algo_DW.Delay2_DSTATE[2];
    top_level_algo_DW.Delay2_DSTATE[2] = top_level_algo_B.Merge_n;

    /* Update for Delay: '<S4>/Delay3' */
    top_level_algo_DW.Delay3_DSTATE[0] = top_level_algo_DW.Delay3_DSTATE[1];
    top_level_algo_DW.Delay3_DSTATE[1] = top_level_algo_DW.Delay3_DSTATE[2];
    top_level_algo_DW.Delay3_DSTATE[2] = top_level_algo_DW.Delay3_DSTATE[3];
    top_level_algo_DW.Delay3_DSTATE[3] = top_level_algo_B.Merge_n;

    /* Update for Delay: '<S4>/Delay4' */
    top_level_algo_DW.Delay4_DSTATE[0] = top_level_algo_DW.Delay4_DSTATE[1];
    top_level_algo_DW.Delay4_DSTATE[1] = top_level_algo_DW.Delay4_DSTATE[2];
    top_level_algo_DW.Delay4_DSTATE[2] = top_level_algo_DW.Delay4_DSTATE[3];
    top_level_algo_DW.Delay4_DSTATE[3] = top_level_algo_DW.Delay4_DSTATE[4];
    top_level_algo_DW.Delay4_DSTATE[4] = top_level_algo_B.Merge_n;
    for (i = 0; i < 9; i++) {
      /* Update for S-Function (sfix_udelay): '<S5>/Tapped Delay' */
      top_level_algo_DW.TappedDelay_X_f[i] = top_level_algo_DW.TappedDelay_X_f[i
        + 1];

      /* Update for Delay: '<S4>/Delay5' */
      top_level_algo_DW.Delay5_DSTATE[i] = top_level_algo_DW.Delay5_DSTATE[i + 1];

      /* Update for S-Function (sfix_udelay): '<S4>/Tapped Delay' */
      top_level_algo_DW.TappedDelay_X[i] = top_level_algo_DW.TappedDelay_X[i + 1];
    }

    /* Update for S-Function (sfix_udelay): '<S5>/Tapped Delay' */
    top_level_algo_DW.TappedDelay_X_f[9] = top_level_algo_B.AnalogInput;

    /* Update for Delay: '<S4>/Delay5' */
    top_level_algo_DW.Delay5_DSTATE[9] = top_level_algo_B.Merge_n;

    /* Update for S-Function (sfix_udelay): '<S4>/Tapped Delay' */
    top_level_algo_DW.TappedDelay_X[9] = top_level_algo_B.u0Diff;

    /* Update for Delay: '<S8>/Delay8' */
    top_level_algo_DW.Delay8_DSTATE[0] = top_level_algo_DW.Delay8_DSTATE[1];
    top_level_algo_DW.Delay8_DSTATE[1] = top_level_algo_B.IsPos;

    /* Update for Delay: '<S8>/Delay6' */
    top_level_algo_DW.Delay6_DSTATE[0] = top_level_algo_DW.Delay6_DSTATE[1];
    top_level_algo_DW.Delay6_DSTATE[1] = top_level_algo_B.LogicalOperator3;

    /* Update for Memory: '<S66>/Memory' */
    top_level_algo_DW.Memory_PreviousInput = top_level_algo_B.Reset;

    /* Update for Delay: '<S8>/Delay4' */
    top_level_algo_DW.Delay4_DSTATE_a[0] = top_level_algo_DW.Delay4_DSTATE_a[1];
    top_level_algo_DW.Delay4_DSTATE_a[1] = top_level_algo_B.IsNeg;

    /* Update for Delay: '<S8>/Delay3' */
    top_level_algo_DW.Delay3_DSTATE_m[0] = top_level_algo_DW.Delay3_DSTATE_m[1];
    top_level_algo_DW.Delay3_DSTATE_m[1] = rtb_LogicalOperator7;

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
    top_level_algo_DW.Delay_DSTATE_a[4] = rtb_NOT;

    /* Update for Delay: '<S8>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE_m[4] = rtb_NOT2;

    /* Update for Memory: '<S67>/Memory' */
    top_level_algo_DW.Memory_PreviousInput_m = top_level_algo_B.Reset_b;
  }

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.005, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  top_level_algo_M->Timing.clockTick2++;
}

/* Model step function for TID3 */
void top_level_algo_step3(void)        /* Sample time: [0.05s, 0.0s] */
{
  /* MATLABSystem: '<Root>/Digital Input' */
  if (top_level_algo_DW.obj_d.SampleTime !=
      top_level_algo_P.DigitalInput_SampleTime) {
    top_level_algo_DW.obj_d.SampleTime =
      top_level_algo_P.DigitalInput_SampleTime;
  }

  /* MATLABSystem: '<Root>/Digital Input' */
  top_level_algo_B.DigitalInput = readDigitalPin(13);

  /* RelationalOperator: '<S6>/Compare' incorporates:
   *  Constant: '<S6>/Constant'
   */
  top_level_algo_B.Compare = (top_level_algo_B.DigitalInput ==
    top_level_algo_P.Constant_Value_p);

  /* Chart: '<Root>/Mode' */
  if (top_level_algo_DW.temporalCounter_i1 < 2047U) {
    top_level_algo_DW.temporalCounter_i1++;
  }

  if (top_level_algo_DW.is_active_c16_top_level_algo == 0U) {
    top_level_algo_DW.is_active_c16_top_level_algo = 1U;
    top_level_algo_DW.is_c16_top_level_algo = top_level_algo_IN_CALIBRATION;
    top_level_algo_DW.temporalCounter_i1 = 0U;
    top_level_algo_B.depth_ctrl = 1.0;
    top_level_algo_B.recoil_ctrl = 0.0;
    top_level_algo_B.seven_seg_ctrl = 0.0;
  } else {
    switch (top_level_algo_DW.is_c16_top_level_algo) {
     case top_level_algo_IN_CALIBRATION:
      top_level_algo_B.depth_ctrl = 1.0;
      top_level_algo_B.recoil_ctrl = 0.0;
      top_level_algo_B.seven_seg_ctrl = 0.0;
      if (top_level_algo_DW.temporalCounter_i1 >= 40U) {
        top_level_algo_DW.is_c16_top_level_algo = top_level_algo_IN_RUNNING;
        top_level_algo_DW.temporalCounter_i1 = 0U;
        top_level_algo_B.depth_ctrl = 1.0;
        top_level_algo_B.recoil_ctrl = 1.0;
        top_level_algo_B.seven_seg_ctrl = 1.0;
      }
      break;

     case top_level_algo_IN_DEBOUNCE1:
      if (!top_level_algo_B.Compare) {
        top_level_algo_DW.is_c16_top_level_algo = top_level_algo_IN_EVALUATING;
        top_level_algo_DW.temporalCounter_i1 = 0U;
        top_level_algo_B.depth_ctrl = 0.0;
        top_level_algo_B.recoil_ctrl = 0.0;
        top_level_algo_B.seven_seg_ctrl = 0.0;
      }
      break;

     case top_level_algo_IN_DEBOUNCE2:
      if (!top_level_algo_B.Compare) {
        top_level_algo_DW.is_c16_top_level_algo = top_level_algo_IN_RUNNING;
        top_level_algo_DW.temporalCounter_i1 = 0U;
        top_level_algo_B.depth_ctrl = 1.0;
        top_level_algo_B.recoil_ctrl = 1.0;
        top_level_algo_B.seven_seg_ctrl = 1.0;
      }
      break;

     case top_level_algo_IN_EVALUATING:
      top_level_algo_B.depth_ctrl = 0.0;
      top_level_algo_B.recoil_ctrl = 0.0;
      top_level_algo_B.seven_seg_ctrl = 0.0;
      if (top_level_algo_B.Compare && (top_level_algo_DW.temporalCounter_i1 >=
           8U)) {
        top_level_algo_DW.is_c16_top_level_algo = top_level_algo_IN_DEBOUNCE2;
      } else if (top_level_algo_DW.temporalCounter_i1 >= 1200U) {
        top_level_algo_DW.is_c16_top_level_algo = top_level_algo_IN_RUNNING;
        top_level_algo_DW.temporalCounter_i1 = 0U;
        top_level_algo_B.depth_ctrl = 1.0;
        top_level_algo_B.recoil_ctrl = 1.0;
        top_level_algo_B.seven_seg_ctrl = 1.0;
      }
      break;

     default:
      /* case IN_RUNNING: */
      top_level_algo_B.depth_ctrl = 1.0;
      top_level_algo_B.recoil_ctrl = 1.0;
      top_level_algo_B.seven_seg_ctrl = 1.0;
      if (top_level_algo_B.Compare && (top_level_algo_DW.temporalCounter_i1 >=
           8U)) {
        top_level_algo_DW.is_c16_top_level_algo = top_level_algo_IN_DEBOUNCE1;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Mode' */

  /* RateTransition generated from: '<Root>/Mode' */
  top_level_algo_DW.TmpRTBAtModeOutport1_Buffer0 = top_level_algo_B.depth_ctrl;

  /* RateTransition generated from: '<Root>/Mode' */
  top_level_algo_DW.TmpRTBAtModeOutport2_Buffer0 = top_level_algo_B.recoil_ctrl;

  /* RateTransition generated from: '<Root>/Mode' */
  top_level_algo_DW.TmpRTBAtModeOutport3_Buffer0 =
    top_level_algo_B.seven_seg_ctrl;

  /* Update absolute time */
  /* The "clockTick3" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.05, which is the step size
   * of the task. Size of "clockTick3" ensures timer will not overflow during the
   * application lifespan selected.
   */
  top_level_algo_M->Timing.clockTick3++;
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
  rtmSetTFinal(top_level_algo_M, -1);
  top_level_algo_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  top_level_algo_M->Sizes.checksums[0] = (1904375682U);
  top_level_algo_M->Sizes.checksums[1] = (1822814097U);
  top_level_algo_M->Sizes.checksums[2] = (3332816149U);
  top_level_algo_M->Sizes.checksums[3] = (415183859U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[63];
    top_level_algo_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[2] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem1.IfActionSubsystem_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem10.IfActionSubsystem_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC;
    systemRan[5] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem3.IfActionSubsystem_SubsysRanBC;
    systemRan[6] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem4.IfActionSubsystem_SubsysRanBC;
    systemRan[7] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem5.IfActionSubsystem_SubsysRanBC;
    systemRan[8] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem6.IfActionSubsystem_SubsysRanBC;
    systemRan[9] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem7.IfActionSubsystem_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem8.IfActionSubsystem_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem_e.IfActionSubsystem_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem1_g.IfActionSubsystem_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem10_g.IfActionSubsystem_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem2_n.IfActionSubsystem_SubsysRanBC;
    systemRan[15] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem3_d.IfActionSubsystem_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem4_b.IfActionSubsystem_SubsysRanBC;
    systemRan[17] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem5_b.IfActionSubsystem_SubsysRanBC;
    systemRan[18] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem6_j.IfActionSubsystem_SubsysRanBC;
    systemRan[19] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem7_i.IfActionSubsystem_SubsysRanBC;
    systemRan[20] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem8_i.IfActionSubsystem_SubsysRanBC;
    systemRan[21] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem_b.IfActionSubsystem_SubsysRanBC;
    systemRan[22] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem1_m.IfActionSubsystem_SubsysRanBC;
    systemRan[23] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem10_g1.IfActionSubsystem_SubsysRanBC;
    systemRan[24] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem2_f.IfActionSubsystem_SubsysRanBC;
    systemRan[25] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem3_e.IfActionSubsystem_SubsysRanBC;
    systemRan[26] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem4_o.IfActionSubsystem_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem5_e.IfActionSubsystem_SubsysRanBC;
    systemRan[28] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem6_l.IfActionSubsystem_SubsysRanBC;
    systemRan[29] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem7_e.IfActionSubsystem_SubsysRanBC;
    systemRan[30] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem8_n.IfActionSubsystem_SubsysRanBC;
    systemRan[31] = &rtAlwaysEnabled;
    systemRan[32] = &rtAlwaysEnabled;
    systemRan[33] = &rtAlwaysEnabled;
    systemRan[34] = &rtAlwaysEnabled;
    systemRan[35] = &rtAlwaysEnabled;
    systemRan[36] = &rtAlwaysEnabled;
    systemRan[37] = &rtAlwaysEnabled;
    systemRan[38] = &rtAlwaysEnabled;
    systemRan[39] = &rtAlwaysEnabled;
    systemRan[40] = &rtAlwaysEnabled;
    systemRan[41] = &rtAlwaysEnabled;
    systemRan[42] = &rtAlwaysEnabled;
    systemRan[43] = &rtAlwaysEnabled;
    systemRan[44] = &rtAlwaysEnabled;
    systemRan[45] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem_SubsysRanBC_e;
    systemRan[46] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem1_SubsysRanB_h;
    systemRan[47] = &rtAlwaysEnabled;
    systemRan[48] = &rtAlwaysEnabled;
    systemRan[49] = &rtAlwaysEnabled;
    systemRan[50] = &rtAlwaysEnabled;
    systemRan[51] = &rtAlwaysEnabled;
    systemRan[52] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[53] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[54] = &rtAlwaysEnabled;
    systemRan[55] = &rtAlwaysEnabled;
    systemRan[56] = &rtAlwaysEnabled;
    systemRan[57] = &rtAlwaysEnabled;
    systemRan[58] = &rtAlwaysEnabled;
    systemRan[59] = &rtAlwaysEnabled;
    systemRan[60] = &rtAlwaysEnabled;
    systemRan[61] = &rtAlwaysEnabled;
    systemRan[62] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(top_level_algo_M->extModeInfo,
      &top_level_algo_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(top_level_algo_M->extModeInfo,
                        top_level_algo_M->Sizes.checksums);
    rteiSetTPtr(top_level_algo_M->extModeInfo, rtmGetTPtr(top_level_algo_M));
  }

  {
    codertarget_arduinobase_inter_T *obj;
    int32_T i;

    /* Start for RateTransition generated from: '<S3>/Chart1' */
    top_level_algo_B.TmpRTBAtChart1Inport2 =
      top_level_algo_P.TmpRTBAtChart1Inport2_InitialCo;

    /* Start for RateTransition generated from: '<Root>/Mode' */
    top_level_algo_B.TmpRTBAtModeOutport2 =
      top_level_algo_P.TmpRTBAtModeOutport2_InitialCon;

    /* Start for RateTransition generated from: '<Root>/Scope3' */
    top_level_algo_B.Max = top_level_algo_P.displacement_InitialCondition;

    /* Start for RateTransition generated from: '<S3>/Subtract3' */
    top_level_algo_B.displacement =
      top_level_algo_P.displacement_InitialCondition_j;

    /* Start for DiscretePulseGenerator: '<S1>/Pulse Generator' */
    top_level_algo_DW.clockTickCounter = -2000;

    /* Start for RateTransition generated from: '<Root>/Mode' */
    top_level_algo_B.TmpRTBAtModeOutport3 =
      top_level_algo_P.TmpRTBAtModeOutport3_InitialCon;

    /* Start for RateTransition generated from: '<Root>/Mode' */
    top_level_algo_B.TmpRTBAtModeOutport1 =
      top_level_algo_P.TmpRTBAtModeOutport1_InitialCon;

    /* InitializeConditions for RateTransition generated from: '<S3>/Chart1' */
    top_level_algo_DW.TmpRTBAtChart1Inport2_Buffer0 =
      top_level_algo_P.TmpRTBAtChart1Inport2_InitialCo;

    /* InitializeConditions for RateTransition generated from: '<Root>/Mode' */
    top_level_algo_DW.TmpRTBAtModeOutport2_Buffer0 =
      top_level_algo_P.TmpRTBAtModeOutport2_InitialCon;

    /* InitializeConditions for RateTransition generated from: '<Root>/Scope3' */
    top_level_algo_DW.displacement_Buffer0 =
      top_level_algo_P.displacement_InitialCondition;

    /* InitializeConditions for RateTransition generated from: '<S3>/Subtract3' */
    top_level_algo_DW.displacement_Buffer0_g =
      top_level_algo_P.displacement_InitialCondition_j;

    /* InitializeConditions for RateTransition generated from: '<Root>/Mode' */
    top_level_algo_DW.TmpRTBAtModeOutport3_Buffer0 =
      top_level_algo_P.TmpRTBAtModeOutport3_InitialCon;

    /* InitializeConditions for S-Function (sfix_udelay): '<S5>/Tapped Delay1' */
    for (i = 0; i < 20; i++) {
      top_level_algo_DW.TappedDelay1_X[i] = top_level_algo_P.TappedDelay1_vinit;
    }

    /* End of InitializeConditions for S-Function (sfix_udelay): '<S5>/Tapped Delay1' */

    /* InitializeConditions for S-Function (sfix_udelay): '<S5>/Tapped Delay' */
    for (i = 0; i < 10; i++) {
      top_level_algo_DW.TappedDelay_X_f[i] =
        top_level_algo_P.TappedDelay_vinit_l;
    }

    /* End of InitializeConditions for S-Function (sfix_udelay): '<S5>/Tapped Delay' */

    /* InitializeConditions for RateTransition generated from: '<Root>/Mode' */
    top_level_algo_DW.TmpRTBAtModeOutport1_Buffer0 =
      top_level_algo_P.TmpRTBAtModeOutport1_InitialCon;

    /* InitializeConditions for Delay: '<S4>/Delay' */
    top_level_algo_DW.Delay_DSTATE = top_level_algo_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S4>/Delay1' */
    top_level_algo_DW.Delay1_DSTATE[0] =
      top_level_algo_P.Delay1_InitialCondition;
    top_level_algo_DW.Delay1_DSTATE[1] =
      top_level_algo_P.Delay1_InitialCondition;

    /* InitializeConditions for Delay: '<S4>/Delay2' */
    top_level_algo_DW.Delay2_DSTATE[0] =
      top_level_algo_P.Delay2_InitialCondition;
    top_level_algo_DW.Delay2_DSTATE[1] =
      top_level_algo_P.Delay2_InitialCondition;
    top_level_algo_DW.Delay2_DSTATE[2] =
      top_level_algo_P.Delay2_InitialCondition;

    /* InitializeConditions for Delay: '<S4>/Delay3' */
    top_level_algo_DW.Delay3_DSTATE[0] =
      top_level_algo_P.Delay3_InitialCondition;
    top_level_algo_DW.Delay3_DSTATE[1] =
      top_level_algo_P.Delay3_InitialCondition;
    top_level_algo_DW.Delay3_DSTATE[2] =
      top_level_algo_P.Delay3_InitialCondition;
    top_level_algo_DW.Delay3_DSTATE[3] =
      top_level_algo_P.Delay3_InitialCondition;

    /* InitializeConditions for Delay: '<S4>/Delay4' */
    for (i = 0; i < 5; i++) {
      top_level_algo_DW.Delay4_DSTATE[i] =
        top_level_algo_P.Delay4_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S4>/Delay4' */
    for (i = 0; i < 10; i++) {
      /* InitializeConditions for Delay: '<S4>/Delay5' */
      top_level_algo_DW.Delay5_DSTATE[i] =
        top_level_algo_P.Delay5_InitialCondition;

      /* InitializeConditions for S-Function (sfix_udelay): '<S4>/Tapped Delay' */
      top_level_algo_DW.TappedDelay_X[i] = top_level_algo_P.TappedDelay_vinit;
    }

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

    /* InitializeConditions for S-Function (sdspcount2): '<S3>/Counter1' */
    top_level_algo_DW.Counter1_ClkEphState = 5U;
    top_level_algo_DW.Counter1_RstEphState = 5U;
    top_level_algo_DW.Counter1_Count = top_level_algo_P.Counter1_InitialCount;

    /* InitializeConditions for Memory: '<S66>/Memory' */
    top_level_algo_DW.Memory_PreviousInput = top_level_algo_P.MaxBDC_vinit;

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
      /* InitializeConditions for Delay: '<S8>/Delay' */
      top_level_algo_DW.Delay_DSTATE_a[i] =
        top_level_algo_P.Delay_InitialCondition_d;

      /* InitializeConditions for Delay: '<S8>/Delay2' */
      top_level_algo_DW.Delay2_DSTATE_m[i] =
        top_level_algo_P.Delay2_InitialCondition_c;
    }

    /* InitializeConditions for Memory: '<S67>/Memory' */
    top_level_algo_DW.Memory_PreviousInput_m = top_level_algo_P.MinBDC_vinit;

    /* SystemInitialize for Merge: '<S12>/Merge' */
    top_level_algo_B.Merge_i = top_level_algo_P.Merge_InitialOutput;

    /* SystemInitialize for Merge: '<S13>/Merge' */
    top_level_algo_B.Merge_d = top_level_algo_P.Merge_InitialOutput_k;

    /* SystemInitialize for Merge: '<S14>/Merge' */
    top_level_algo_B.Merge_n0 = top_level_algo_P.Merge_InitialOutput_j;

    /* Start for MATLABSystem: '<Root>/Digital Output8' */
    top_level_algo_DW.obj_m.matlabCodegenIsDeleted = false;
    top_level_algo_DW.obj_m.isInitialized = 1;
    digitalIOSetup(23, 1);
    top_level_algo_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output9' */
    top_level_algo_DW.obj_b.matlabCodegenIsDeleted = false;
    top_level_algo_DW.obj_b.isInitialized = 1;
    digitalIOSetup(22, 1);
    top_level_algo_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output4' */
    top_level_algo_DW.obj_k.matlabCodegenIsDeleted = false;
    top_level_algo_DW.obj_k.isInitialized = 1;
    digitalIOSetup(21, 1);
    top_level_algo_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output5' */
    top_level_algo_DW.obj_j.matlabCodegenIsDeleted = false;
    top_level_algo_DW.obj_j.isInitialized = 1;
    digitalIOSetup(19, 1);
    top_level_algo_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output6' */
    top_level_algo_DW.obj_p.matlabCodegenIsDeleted = false;
    top_level_algo_DW.obj_p.isInitialized = 1;
    digitalIOSetup(18, 1);
    top_level_algo_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output7' */
    top_level_algo_DW.obj_do.matlabCodegenIsDeleted = false;
    top_level_algo_DW.obj_do.isInitialized = 1;
    digitalIOSetup(5, 1);
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
  }
}

/* Model terminate function */
void top_level_algo_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Digital Output8' */
  if (!top_level_algo_DW.obj_m.matlabCodegenIsDeleted) {
    top_level_algo_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output8' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output9' */
  if (!top_level_algo_DW.obj_b.matlabCodegenIsDeleted) {
    top_level_algo_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output9' */
  /* Terminate for MATLABSystem: '<Root>/Digital Output4' */
  if (!top_level_algo_DW.obj_k.matlabCodegenIsDeleted) {
    top_level_algo_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output4' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output5' */
  if (!top_level_algo_DW.obj_j.matlabCodegenIsDeleted) {
    top_level_algo_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output5' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output6' */
  if (!top_level_algo_DW.obj_p.matlabCodegenIsDeleted) {
    top_level_algo_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output6' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output7' */
  if (!top_level_algo_DW.obj_do.matlabCodegenIsDeleted) {
    top_level_algo_DW.obj_do.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output7' */

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
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
