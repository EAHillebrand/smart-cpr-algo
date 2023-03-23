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
 * C/C++ source code generated on : Mon Mar 20 19:10:56 2023
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

/* Named constants for Chart: '<S3>/ClockLogic' */
#define top_level_algo_IN_HIGH         ((uint8_T)1U)
#define top_level_algo_IN_LOW          ((uint8_T)2U)
#define top_level_algo_IN_START        ((uint8_T)3U)
#define top_level_algo_IN_WAIT         ((uint8_T)4U)

/* Named constants for Chart: '<S3>/DataLogic' */
#define top_level_algo_IN_CHECK        ((uint8_T)1U)
#define top_level_algo_IN_LOAD         ((uint8_T)2U)
#define top_level_algo_IN_MASK         ((uint8_T)3U)
#define top_level_algo_IN_START_n      ((uint8_T)4U)
#define top_level_algo_IN_WAITING      ((uint8_T)5U)
#define top_level_algo_IN_Wait         ((uint8_T)6U)

/* Block signals (default storage) */
B_top_level_algo_T top_level_algo_B;

/* Block states (default storage) */
DW_top_level_algo_T top_level_algo_DW;

/* Real-time model */
static RT_MODEL_top_level_algo_T top_level_algo_M_;
RT_MODEL_top_level_algo_T *const top_level_algo_M = &top_level_algo_M_;

/*
 * Output and update for action system:
 *    '<S4>/If Action Subsystem'
 *    '<S4>/If Action Subsystem1'
 *    '<S4>/If Action Subsystem2'
 *    '<S4>/If Action Subsystem3'
 *    '<S4>/If Action Subsystem4'
 *    '<S4>/If Action Subsystem5'
 *    '<S4>/If Action Subsystem6'
 *    '<S4>/If Action Subsystem7'
 *    '<S4>/If Action Subsystem8'
 *    '<S4>/If Action Subsystem10'
 *    ...
 */
void top_level_alg_IfActionSubsystem(uint8_T *rty_Out1,
  P_IfActionSubsystem_top_level_T *localP)
{
  /* SignalConversion generated from: '<S7>/Out1' incorporates:
   *  Constant: '<S7>/Constant'
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

/* Model step function */
void top_level_algo_step(void)
{
  real_T rtb_Mod1;
  real_T rtb_PulseGenerator;
  real_T rtb_TmpMLSysMemLayoutBufferAt_k;
  real_T tmp;
  uint32_T rtb_Add;
  uint8_T tmp_0;

  /* DiscretePulseGenerator: '<S1>/Pulse Generator' */
  rtb_PulseGenerator = (top_level_algo_DW.clockTickCounter <
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

  /* Chart: '<S3>/ClockLogic' */
  if (top_level_algo_DW.temporalCounter_i1_o < 15U) {
    top_level_algo_DW.temporalCounter_i1_o++;
  }

  if (top_level_algo_DW.is_active_c17_top_level_algo == 0U) {
    top_level_algo_DW.is_active_c17_top_level_algo = 1U;
    top_level_algo_DW.is_c17_top_level_algo = top_level_algo_IN_START;
    top_level_algo_DW.counter = 0.0;
    top_level_algo_B.CLK = 0.0;
  } else {
    switch (top_level_algo_DW.is_c17_top_level_algo) {
     case top_level_algo_IN_HIGH:
      if (top_level_algo_DW.temporalCounter_i1_o >= 10U) {
        top_level_algo_DW.is_c17_top_level_algo = top_level_algo_IN_LOW;
        top_level_algo_DW.temporalCounter_i1_o = 0U;
        top_level_algo_B.CLK = 0.0;
        top_level_algo_DW.counter++;
      }
      break;

     case top_level_algo_IN_LOW:
      if (top_level_algo_DW.counter == 36.0) {
        top_level_algo_DW.is_c17_top_level_algo = top_level_algo_IN_START;
        top_level_algo_DW.counter = 0.0;
        top_level_algo_B.CLK = 0.0;
      } else if (top_level_algo_DW.temporalCounter_i1_o >= 10U) {
        top_level_algo_DW.is_c17_top_level_algo = top_level_algo_IN_HIGH;
        top_level_algo_DW.temporalCounter_i1_o = 0U;
        top_level_algo_B.CLK = 1.0;
      }
      break;

     case top_level_algo_IN_START:
      if (rtb_PulseGenerator == 1.0) {
        top_level_algo_DW.is_c17_top_level_algo = top_level_algo_IN_WAIT;
        top_level_algo_DW.temporalCounter_i1_o = 0U;
      } else {
        top_level_algo_DW.counter = 0.0;
        top_level_algo_B.CLK = 0.0;
      }
      break;

     default:
      /* case IN_WAIT: */
      if (top_level_algo_DW.temporalCounter_i1_o >= 10U) {
        top_level_algo_DW.is_c17_top_level_algo = top_level_algo_IN_HIGH;
        top_level_algo_DW.temporalCounter_i1_o = 0U;
        top_level_algo_B.CLK = 1.0;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/ClockLogic' */

  /* MATLABSystem: '<Root>/Digital Output2' */
  tmp = rt_roundd_snf(top_level_algo_B.CLK);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(25, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output2' */

  /* Math: '<S2>/Mod' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Constant: '<S2>/Constant1'
   */
  rtb_TmpMLSysMemLayoutBufferAt_k = rt_modd_snf(top_level_algo_P.Constant5_Value,
    top_level_algo_P.Constant1_Value);

  /* SwitchCase: '<S4>/Switch Case' incorporates:
   *  Constant: '<Root>/Constant5'
   *  MATLABSystem: '<S2>/Divide by Constant and Round'
   *  Sum: '<S2>/Subtract'
   */
  tmp = floor((top_level_algo_P.Constant5_Value -
               rtb_TmpMLSysMemLayoutBufferAt_k) * 0.01);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  switch (tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
      &top_level_algo_P.IfActionSubsystem);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
      &top_level_algo_P.IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem1' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
      &top_level_algo_P.IfActionSubsystem2);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem2' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
      &top_level_algo_P.IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem3' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
      &top_level_algo_P.IfActionSubsystem4);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem4' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
      &top_level_algo_P.IfActionSubsystem5);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem5' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
      &top_level_algo_P.IfActionSubsystem6);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem6' */
    break;

   case 7:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
      &top_level_algo_P.IfActionSubsystem7);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem7' */
    break;

   case 8:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
      &top_level_algo_P.IfActionSubsystem8);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem8' */
    break;

   case 9:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem10' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
      &top_level_algo_P.IfActionSubsystem10);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem10' */
    break;
  }

  /* End of SwitchCase: '<S4>/Switch Case' */

  /* Math: '<S2>/Mod1' incorporates:
   *  Constant: '<S2>/Constant2'
   */
  rtb_Mod1 = rt_modd_snf(rtb_TmpMLSysMemLayoutBufferAt_k,
    top_level_algo_P.Constant2_Value);

  /* SwitchCase: '<S5>/Switch Case' incorporates:
   *  MATLABSystem: '<S2>/Divide by Constant and Round1'
   *  Sum: '<S2>/Subtract1'
   */
  tmp = floor((rtb_TmpMLSysMemLayoutBufferAt_k - rtb_Mod1) * 0.1);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  switch (tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem_e);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem1_g);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem1' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S20>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem2_n);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem2' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S21>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem3_d);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem3' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S22>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem4_b);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem4' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S23>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem5_b);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem5' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S24>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem6_j);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem6' */
    break;

   case 7:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem7_i);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem7' */
    break;

   case 8:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem8_i);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem8' */
    break;

   case 9:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem10' incorporates:
     *  ActionPort: '<S19>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem10_g);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem10' */
    break;
  }

  /* End of SwitchCase: '<S5>/Switch Case' */

  /* SwitchCase: '<S6>/Switch Case' */
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
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_n,
      &top_level_algo_P.IfActionSubsystem_b);

    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_n,
      &top_level_algo_P.IfActionSubsystem1_m);

    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem1' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S30>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_n,
      &top_level_algo_P.IfActionSubsystem2_f);

    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem2' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_n,
      &top_level_algo_P.IfActionSubsystem3_e);

    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem3' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S32>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_n,
      &top_level_algo_P.IfActionSubsystem4_o);

    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem4' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_n,
      &top_level_algo_P.IfActionSubsystem5_e);

    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem5' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_n,
      &top_level_algo_P.IfActionSubsystem6_l);

    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem6' */
    break;

   case 7:
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S35>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_n,
      &top_level_algo_P.IfActionSubsystem7_e);

    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem7' */
    break;

   case 8:
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S36>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_n,
      &top_level_algo_P.IfActionSubsystem8_n);

    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem8' */
    break;

   case 9:
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem10' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_n,
      &top_level_algo_P.IfActionSubsystem10_g1);

    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem10' */
    break;
  }

  /* End of SwitchCase: '<S6>/Switch Case' */

  /* Sum: '<S2>/Add' incorporates:
   *  ArithShift: '<S2>/Shift Arithmetic1'
   *  ArithShift: '<S2>/Shift Arithmetic2'
   *  DataTypeConversion: '<S2>/Cast To Double'
   *  DataTypeConversion: '<S2>/Cast To Double1'
   *  DataTypeConversion: '<S2>/Cast To Double2'
   */
  rtb_Add = (((uint32_T)top_level_algo_B.Merge_d << 8) + top_level_algo_B.Merge)
    + ((uint32_T)top_level_algo_B.Merge_n << 16);

  /* Chart: '<S3>/DataLogic' */
  if (top_level_algo_DW.temporalCounter_i1 < 31U) {
    top_level_algo_DW.temporalCounter_i1++;
  }

  if (top_level_algo_DW.is_active_c18_top_level_algo == 0U) {
    top_level_algo_DW.is_active_c18_top_level_algo = 1U;
    top_level_algo_DW.is_c18_top_level_algo = top_level_algo_IN_LOAD;
    top_level_algo_B.data = 0U;
    top_level_algo_DW.Holder = rtb_Add;
  } else {
    switch (top_level_algo_DW.is_c18_top_level_algo) {
     case top_level_algo_IN_CHECK:
      if (top_level_algo_DW.Holder == 0U) {
        top_level_algo_DW.is_c18_top_level_algo = top_level_algo_IN_WAITING;
        top_level_algo_DW.temporalCounter_i1 = 0U;
      } else if (top_level_algo_DW.temporalCounter_i1 >= 10U) {
        top_level_algo_DW.is_c18_top_level_algo = top_level_algo_IN_MASK;
        top_level_algo_DW.temporalCounter_i1 = 0U;
        top_level_algo_B.data = top_level_algo_DW.Holder & 1U;
      }
      break;

     case top_level_algo_IN_LOAD:
      if (rtb_PulseGenerator == 1.0) {
        top_level_algo_DW.is_c18_top_level_algo = top_level_algo_IN_Wait;
        top_level_algo_DW.temporalCounter_i1 = 0U;
      }
      break;

     case top_level_algo_IN_MASK:
      if (top_level_algo_DW.temporalCounter_i1 >= 10U) {
        top_level_algo_DW.is_c18_top_level_algo = top_level_algo_IN_CHECK;
        top_level_algo_DW.temporalCounter_i1 = 0U;
        top_level_algo_DW.Holder >>= 1;
      }
      break;

     case top_level_algo_IN_START_n:
      if (top_level_algo_DW.temporalCounter_i1 >= 20U) {
        top_level_algo_DW.is_c18_top_level_algo = top_level_algo_IN_MASK;
        top_level_algo_DW.temporalCounter_i1 = 0U;
        top_level_algo_B.data = top_level_algo_DW.Holder & 1U;
      }
      break;

     case top_level_algo_IN_WAITING:
      if (top_level_algo_DW.temporalCounter_i1 >= 10U) {
        top_level_algo_DW.is_c18_top_level_algo = top_level_algo_IN_LOAD;
        top_level_algo_B.data = 0U;
        top_level_algo_DW.Holder = rtb_Add;
      }
      break;

     default:
      /* case IN_Wait: */
      if (top_level_algo_DW.temporalCounter_i1 >= 5U) {
        top_level_algo_DW.is_c18_top_level_algo = top_level_algo_IN_START_n;
        top_level_algo_DW.temporalCounter_i1 = 0U;
        top_level_algo_B.data = 1U;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/DataLogic' */

  /* MATLABSystem: '<Root>/Digital Output3' */
  rtb_Add = top_level_algo_B.data;
  if (top_level_algo_B.data > 255U) {
    rtb_Add = 255U;
  }

  writeDigitalPin(26, (uint8_T)rtb_Add);

  /* End of MATLABSystem: '<Root>/Digital Output3' */
}

/* Model initialize function */
void top_level_algo_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* SystemInitialize for Merge: '<S4>/Merge' */
  top_level_algo_B.Merge = top_level_algo_P.Merge_InitialOutput;

  /* SystemInitialize for Merge: '<S5>/Merge' */
  top_level_algo_B.Merge_d = top_level_algo_P.Merge_InitialOutput_k;

  /* SystemInitialize for Merge: '<S6>/Merge' */
  top_level_algo_B.Merge_n = top_level_algo_P.Merge_InitialOutput_j;

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
