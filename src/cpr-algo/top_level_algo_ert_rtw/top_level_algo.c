/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo.c
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 1.110
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Wed Jan 25 13:10:13 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "top_level_algo.h"
#include "top_level_algo_private.h"

/* Named constants for Chart: '<S2>/ClockLogic' */
#define top_level_algo_IN_HIGH         ((uint8_T)1U)
#define top_level_algo_IN_LOW          ((uint8_T)2U)
#define top_level_algo_IN_START        ((uint8_T)3U)
#define top_level_algo_IN_WAIT         ((uint8_T)4U)

/* Named constants for Chart: '<S2>/DataLogic' */
#define top_level_algo_IN_CHECK        ((uint8_T)1U)
#define top_level_algo_IN_LOAD         ((uint8_T)2U)
#define top_level_algo_IN_MASK         ((uint8_T)3U)
#define top_level_algo_IN_START_f      ((uint8_T)4U)
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
void top_level_alg_IfActionSubsystem(uint8_T *rty_Out1,
  P_IfActionSubsystem_top_level_T *localP)
{
  /* SignalConversion generated from: '<S6>/Out1' incorporates:
   *  Constant: '<S6>/Constant'
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

/* Model step function */
void top_level_algo_step(void)
{
  real_T rtb_Mod1;
  real_T rtb_TmpMLSysMemLayoutBufferAtDi;
  real_T tmp;
  uint32_T Add;

  /* Math: '<S1>/Mod' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<S1>/Constant1'
   */
  rtb_TmpMLSysMemLayoutBufferAtDi = rt_modd_snf(top_level_algo_P.Constant_Value,
    top_level_algo_P.Constant1_Value);

  /* SwitchCase: '<S3>/Switch Case' incorporates:
   *  Constant: '<Root>/Constant'
   *  MATLABSystem: '<S1>/Divide by Constant and Round'
   *  Sum: '<S1>/Subtract'
   */
  tmp = floor((top_level_algo_P.Constant_Value - rtb_TmpMLSysMemLayoutBufferAtDi)
              * 0.01);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  switch (tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp) {
   case 0L:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
      &top_level_algo_P.IfActionSubsystem);

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem' */
    break;

   case 1L:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
      &top_level_algo_P.IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem1' */
    break;

   case 2L:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
      &top_level_algo_P.IfActionSubsystem2);

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem2' */
    break;

   case 3L:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
      &top_level_algo_P.IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem3' */
    break;

   case 4L:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
      &top_level_algo_P.IfActionSubsystem4);

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem4' */
    break;

   case 5L:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
      &top_level_algo_P.IfActionSubsystem5);

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem5' */
    break;

   case 6L:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
      &top_level_algo_P.IfActionSubsystem6);

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem6' */
    break;

   case 7L:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
      &top_level_algo_P.IfActionSubsystem7);

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem7' */
    break;

   case 8L:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
      &top_level_algo_P.IfActionSubsystem8);

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem8' */
    break;

   case 9L:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem10' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge,
      &top_level_algo_P.IfActionSubsystem10);

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem10' */
    break;
  }

  /* End of SwitchCase: '<S3>/Switch Case' */

  /* Math: '<S1>/Mod1' incorporates:
   *  Constant: '<S1>/Constant2'
   */
  rtb_Mod1 = rt_modd_snf(rtb_TmpMLSysMemLayoutBufferAtDi,
    top_level_algo_P.Constant2_Value);

  /* SwitchCase: '<S4>/Switch Case' incorporates:
   *  MATLABSystem: '<S1>/Divide by Constant and Round1'
   *  Sum: '<S1>/Subtract1'
   */
  tmp = floor((rtb_TmpMLSysMemLayoutBufferAtDi - rtb_Mod1) * 0.1);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  switch (tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp) {
   case 0L:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
      &top_level_algo_P.IfActionSubsystem_l);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem' */
    break;

   case 1L:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
      &top_level_algo_P.IfActionSubsystem1_d);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem1' */
    break;

   case 2L:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S19>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
      &top_level_algo_P.IfActionSubsystem2_d);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem2' */
    break;

   case 3L:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S20>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
      &top_level_algo_P.IfActionSubsystem3_p);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem3' */
    break;

   case 4L:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S21>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
      &top_level_algo_P.IfActionSubsystem4_d);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem4' */
    break;

   case 5L:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S22>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
      &top_level_algo_P.IfActionSubsystem5_h);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem5' */
    break;

   case 6L:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S23>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
      &top_level_algo_P.IfActionSubsystem6_b);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem6' */
    break;

   case 7L:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S24>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
      &top_level_algo_P.IfActionSubsystem7_h);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem7' */
    break;

   case 8L:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
      &top_level_algo_P.IfActionSubsystem8_p);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem8' */
    break;

   case 9L:
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem10' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_b,
      &top_level_algo_P.IfActionSubsystem10_l);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem10' */
    break;
  }

  /* End of SwitchCase: '<S4>/Switch Case' */

  /* SwitchCase: '<S5>/Switch Case' */
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
   case 0L:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem_j);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem' */
    break;

   case 1L:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem1_a);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem1' */
    break;

   case 2L:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem2_i);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem2' */
    break;

   case 3L:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S30>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem3_c);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem3' */
    break;

   case 4L:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem4_db);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem4' */
    break;

   case 5L:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S32>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem5_hh);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem5' */
    break;

   case 6L:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem6_c);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem6' */
    break;

   case 7L:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem7_n);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem7' */
    break;

   case 8L:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S35>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem8_f);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem8' */
    break;

   case 9L:
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem10' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    top_level_alg_IfActionSubsystem(&top_level_algo_B.Merge_d,
      &top_level_algo_P.IfActionSubsystem10_m);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem10' */
    break;
  }

  /* End of SwitchCase: '<S5>/Switch Case' */

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_TmpMLSysMemLayoutBufferAtDi = (top_level_algo_DW.clockTickCounter <
    top_level_algo_P.PulseGenerator_Duty) && (top_level_algo_DW.clockTickCounter
    >= 0L) ? top_level_algo_P.PulseGenerator_Amp : 0.0;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  if (top_level_algo_DW.clockTickCounter >=
      top_level_algo_P.PulseGenerator_Period - 1.0) {
    top_level_algo_DW.clockTickCounter = 0L;
  } else {
    top_level_algo_DW.clockTickCounter++;
  }

  /* Chart: '<S2>/ClockLogic' */
  if (top_level_algo_DW.temporalCounter_i1_l < 15U) {
    top_level_algo_DW.temporalCounter_i1_l++;
  }

  if (top_level_algo_DW.is_active_c5_top_level_algo == 0U) {
    top_level_algo_DW.is_active_c5_top_level_algo = 1U;
    top_level_algo_DW.is_c5_top_level_algo = top_level_algo_IN_START;
    top_level_algo_DW.counter = 0.0;
  } else {
    switch (top_level_algo_DW.is_c5_top_level_algo) {
     case top_level_algo_IN_HIGH:
      if (top_level_algo_DW.temporalCounter_i1_l >= 10U) {
        top_level_algo_DW.is_c5_top_level_algo = top_level_algo_IN_LOW;
        top_level_algo_DW.temporalCounter_i1_l = 0U;
        top_level_algo_DW.counter++;
      }
      break;

     case top_level_algo_IN_LOW:
      if (top_level_algo_DW.counter == 36.0) {
        top_level_algo_DW.is_c5_top_level_algo = top_level_algo_IN_START;
        top_level_algo_DW.counter = 0.0;
      } else if (top_level_algo_DW.temporalCounter_i1_l >= 10U) {
        top_level_algo_DW.is_c5_top_level_algo = top_level_algo_IN_HIGH;
        top_level_algo_DW.temporalCounter_i1_l = 0U;
      }
      break;

     case top_level_algo_IN_START:
      if (rtb_TmpMLSysMemLayoutBufferAtDi == 1.0) {
        top_level_algo_DW.is_c5_top_level_algo = top_level_algo_IN_WAIT;
        top_level_algo_DW.temporalCounter_i1_l = 0U;
      } else {
        top_level_algo_DW.counter = 0.0;
      }
      break;

     default:
      /* case IN_WAIT: */
      if (top_level_algo_DW.temporalCounter_i1_l >= 10U) {
        top_level_algo_DW.is_c5_top_level_algo = top_level_algo_IN_HIGH;
        top_level_algo_DW.temporalCounter_i1_l = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S2>/ClockLogic' */

  /* Sum: '<S1>/Add' incorporates:
   *  ArithShift: '<S1>/Shift Arithmetic'
   *  ArithShift: '<S1>/Shift Arithmetic1'
   *  ArithShift: '<S1>/Shift Arithmetic2'
   *  DataTypeConversion: '<S1>/Cast To Double'
   *  DataTypeConversion: '<S1>/Cast To Double1'
   *  DataTypeConversion: '<S1>/Cast To Double2'
   */
  Add = (((uint32_T)top_level_algo_B.Merge << 24) + ((uint32_T)
          top_level_algo_B.Merge_b << 16)) + ((uint16_T)top_level_algo_B.Merge_d
    << 8);

  /* Chart: '<S2>/DataLogic' */
  if (top_level_algo_DW.temporalCounter_i1 < 31U) {
    top_level_algo_DW.temporalCounter_i1++;
  }

  if (top_level_algo_DW.is_active_c6_top_level_algo == 0U) {
    top_level_algo_DW.is_active_c6_top_level_algo = 1U;
    top_level_algo_DW.is_c6_top_level_algo = top_level_algo_IN_LOAD;
    top_level_algo_DW.Holder = Add;
  } else {
    switch (top_level_algo_DW.is_c6_top_level_algo) {
     case top_level_algo_IN_CHECK:
      if (top_level_algo_DW.Holder == 0UL) {
        top_level_algo_DW.is_c6_top_level_algo = top_level_algo_IN_WAITING;
        top_level_algo_DW.temporalCounter_i1 = 0U;
      } else if (top_level_algo_DW.temporalCounter_i1 >= 10U) {
        top_level_algo_DW.is_c6_top_level_algo = top_level_algo_IN_MASK;
        top_level_algo_DW.temporalCounter_i1 = 0U;
      }
      break;

     case top_level_algo_IN_LOAD:
      if (rtb_TmpMLSysMemLayoutBufferAtDi == 1.0) {
        top_level_algo_DW.is_c6_top_level_algo = top_level_algo_IN_Wait;
        top_level_algo_DW.temporalCounter_i1 = 0U;
      }
      break;

     case top_level_algo_IN_MASK:
      if (top_level_algo_DW.temporalCounter_i1 >= 10U) {
        top_level_algo_DW.is_c6_top_level_algo = top_level_algo_IN_CHECK;
        top_level_algo_DW.temporalCounter_i1 = 0U;
        top_level_algo_DW.Holder <<= 1;
      }
      break;

     case top_level_algo_IN_START_f:
      if (top_level_algo_DW.temporalCounter_i1 >= 20U) {
        top_level_algo_DW.is_c6_top_level_algo = top_level_algo_IN_MASK;
        top_level_algo_DW.temporalCounter_i1 = 0U;
      }
      break;

     case top_level_algo_IN_WAITING:
      if (top_level_algo_DW.temporalCounter_i1 >= 10U) {
        top_level_algo_DW.is_c6_top_level_algo = top_level_algo_IN_LOAD;
        top_level_algo_DW.Holder = Add;
      }
      break;

     default:
      /* case IN_Wait: */
      if (top_level_algo_DW.temporalCounter_i1 >= 25U) {
        top_level_algo_DW.is_c6_top_level_algo = top_level_algo_IN_START_f;
        top_level_algo_DW.temporalCounter_i1 = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S2>/DataLogic' */
}

/* Model initialize function */
void top_level_algo_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* SystemInitialize for Merge: '<S3>/Merge' */
  top_level_algo_B.Merge = top_level_algo_P.Merge_InitialOutput;

  /* SystemInitialize for Merge: '<S4>/Merge' */
  top_level_algo_B.Merge_b = top_level_algo_P.Merge_InitialOutput_i;

  /* SystemInitialize for Merge: '<S5>/Merge' */
  top_level_algo_B.Merge_d = top_level_algo_P.Merge_InitialOutput_j;
}

/* Model terminate function */
void top_level_algo_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
