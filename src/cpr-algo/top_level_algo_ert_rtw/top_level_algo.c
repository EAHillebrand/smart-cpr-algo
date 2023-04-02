/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo.c
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 3.40
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Apr  1 11:05:00 2023
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

/* Named constants for Chart: '<S1>/timer' */
#define top_level_algo_IN_Finished     (1U)
#define top_level_algo_IN_Starting     (2U)

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
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (top_level_algo_M->Timing.TaskCounters.TID[1])++;
  if ((top_level_algo_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.005s, 0.0s] */
    top_level_algo_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void top_level_algo_step0(void)        /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

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
void top_level_algo_step1(void)        /* Sample time: [0.005s, 0.0s] */
{
  MW_AnalogIn_ResultDataType_Type datatype_id;
  codertarget_arduinobase_inter_T *obj;
  real_T Mean1_AccVal;
  int32_T n;
  int32_T rtb_measure_period;
  int32_T str;
  int16_T Mean_AccVal;

  /* Reset subsysRan breadcrumbs */
  srClearBC(top_level_algo_DW.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(top_level_algo_DW.IfActionSubsystem1_SubsysRanBC);

  /* S-Function (sdspstatfcns): '<S1>/Mean1' incorporates:
   *  S-Function (sfix_udelay): '<S1>/Tapped Delay1'
   */
  Mean1_AccVal = top_level_algo_DW.TappedDelay1_X[0];
  str = 1;
  for (n = 18; n >= 0; n--) {
    Mean1_AccVal += top_level_algo_DW.TappedDelay1_X[str];
    str++;
  }

  /* S-Function (sdspstatfcns): '<S1>/Mean1' */
  top_level_algo_B.Mean1 = Mean1_AccVal / 20.0;

  /* Chart: '<S1>/timer' */
  if (top_level_algo_DW.temporalCounter_i1 < 511U) {
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
    if (top_level_algo_DW.temporalCounter_i1 >= 400U) {
      top_level_algo_DW.is_c3_top_level_algo = top_level_algo_IN_Finished;
      top_level_algo_B.baseline = top_level_algo_B.Mean1;
      rtb_measure_period = 1;
    }
  }

  /* End of Chart: '<S1>/timer' */

  /* S-Function (sdspstatfcns): '<S1>/Mean' incorporates:
   *  S-Function (sfix_udelay): '<S1>/Tapped Delay'
   */
  Mean_AccVal = (int16_T)top_level_algo_DW.TappedDelay_X[0];
  str = 1;
  for (n = 8; n >= 0; n--) {
    Mean_AccVal += top_level_algo_DW.TappedDelay_X[str];
    str++;
  }

  /* Product: '<S1>/Product' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Product: '<S1>/Divide'
   *  S-Function (sdspstatfcns): '<S1>/Mean'
   */
  top_level_algo_B.Product = (real_T)(uint16_T)div_nde_s32_floor(Mean_AccVal, 10)
    / top_level_algo_P.Constant1_Value * top_level_algo_P.Vdd;

  /* Switch: '<S1>/Switch' */
  if (rtb_measure_period > top_level_algo_P.Switch_Threshold) {
    Mean1_AccVal = top_level_algo_B.baseline;
  } else {
    Mean1_AccVal = top_level_algo_B.Product;
  }

  /* Gain: '<S1>/Radius (mm)' incorporates:
   *  Gain: '<S1>/Gear Down'
   *  Gain: '<S1>/rad  per volt'
   *  Sum: '<S1>/Subtract'
   *  Switch: '<S1>/Switch'
   */
  top_level_algo_B.Merge = 6.2831853071795862 / top_level_algo_P.Vdd *
    (Mean1_AccVal - top_level_algo_B.Product) * (1.0 /
    top_level_algo_P.gear_ratio) * top_level_algo_P.Radiusmm_Gain;

  /* If: '<S2>/If' */
  if (top_level_algo_B.Merge < 0.0) {
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Gain: '<S1>/Radius (mm)' incorporates:
     *  Constant: '<S2>/Constant'
     *  Merge: '<S2>/Merge'
     *  SignalConversion generated from: '<S4>/In1'
     */
    top_level_algo_B.Merge = top_level_algo_P.Constant_Value;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Update for If: '<S2>/If' */
    srUpdateBC(top_level_algo_DW.IfActionSubsystem_SubsysRanBC);

    /* End of Update for SubSystem: '<S2>/If Action Subsystem' */
  } else {
    /* Update for IfAction SubSystem: '<S2>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Update for If: '<S2>/If' */
    srUpdateBC(top_level_algo_DW.IfActionSubsystem1_SubsysRanBC);

    /* End of Update for SubSystem: '<S2>/If Action Subsystem1' */
  }

  /* End of If: '<S2>/If' */
  /* MATLABSystem: '<Root>/Analog Input' */
  if (top_level_algo_DW.obj.SampleTime !=
      top_level_algo_P.AnalogInput_SampleTime) {
    top_level_algo_DW.obj.SampleTime = top_level_algo_P.AnalogInput_SampleTime;
  }

  obj = &top_level_algo_DW.obj;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(15U);
  datatype_id = MW_ANALOGIN_UINT16;

  /* MATLABSystem: '<Root>/Analog Input' */
  MW_AnalogInSingle_ReadResult
    (top_level_algo_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &top_level_algo_B.AnalogInput, datatype_id);

  /* Update for S-Function (sfix_udelay): '<S1>/Tapped Delay1' */
  for (n = 0; n < 19; n++) {
    top_level_algo_DW.TappedDelay1_X[n] = top_level_algo_DW.TappedDelay1_X[n + 1];
  }

  top_level_algo_DW.TappedDelay1_X[19] = top_level_algo_B.Product;

  /* End of Update for S-Function (sfix_udelay): '<S1>/Tapped Delay1' */

  /* Update for S-Function (sfix_udelay): '<S1>/Tapped Delay' */
  for (n = 0; n < 9; n++) {
    top_level_algo_DW.TappedDelay_X[n] = top_level_algo_DW.TappedDelay_X[n + 1];
  }

  top_level_algo_DW.TappedDelay_X[9] = top_level_algo_B.AnalogInput;

  /* End of Update for S-Function (sfix_udelay): '<S1>/Tapped Delay' */

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.005, which is the step size
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
  rtmSetTFinal(top_level_algo_M, -1);
  top_level_algo_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  top_level_algo_M->Sizes.checksums[0] = (1884298315U);
  top_level_algo_M->Sizes.checksums[1] = (3088234117U);
  top_level_algo_M->Sizes.checksums[2] = (4213680661U);
  top_level_algo_M->Sizes.checksums[3] = (800737630U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    top_level_algo_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &top_level_algo_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(top_level_algo_M->extModeInfo,
      &top_level_algo_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(top_level_algo_M->extModeInfo,
                        top_level_algo_M->Sizes.checksums);
    rteiSetTPtr(top_level_algo_M->extModeInfo, rtmGetTPtr(top_level_algo_M));
  }

  {
    codertarget_arduinobase_inter_T *obj;
    int32_T i;

    /* InitializeConditions for S-Function (sfix_udelay): '<S1>/Tapped Delay1' */
    for (i = 0; i < 20; i++) {
      top_level_algo_DW.TappedDelay1_X[i] = top_level_algo_P.TappedDelay1_vinit;
    }

    /* End of InitializeConditions for S-Function (sfix_udelay): '<S1>/Tapped Delay1' */

    /* InitializeConditions for S-Function (sfix_udelay): '<S1>/Tapped Delay' */
    for (i = 0; i < 10; i++) {
      top_level_algo_DW.TappedDelay_X[i] = top_level_algo_P.TappedDelay_vinit;
    }

    /* End of InitializeConditions for S-Function (sfix_udelay): '<S1>/Tapped Delay' */

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    top_level_algo_DW.obj.matlabCodegenIsDeleted = false;
    top_level_algo_DW.obj.SampleTime = top_level_algo_P.AnalogInput_SampleTime;
    obj = &top_level_algo_DW.obj;
    top_level_algo_DW.obj.isInitialized = 1;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(15U);
    top_level_algo_DW.obj.isSetupComplete = true;
  }
}

/* Model terminate function */
void top_level_algo_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

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
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
