/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo.h
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

#ifndef RTW_HEADER_top_level_algo_h_
#define RTW_HEADER_top_level_algo_h_
#ifndef top_level_algo_COMMON_INCLUDES_
#define top_level_algo_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* top_level_algo_COMMON_INCLUDES_ */

#include "top_level_algo_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block states (default storage) for system '<S3>/If Action Subsystem' */
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S3>/If Action Subsystem' */
} DW_IfActionSubsystem_top_leve_T;

/* Block signals (default storage) */
typedef struct {
  real_T TmpRTBAtSwitchInport1;        /* '<S2>/clk' */
  real_T CLK;                          /* '<S2>/Switch' */
  real_T PulseGenerator;               /* '<S2>/Pulse Generator' */
  real_T VectorConcatenate[3];         /* '<S1>/Vector Concatenate' */
  real_T Sum;                          /* '<S40>/Sum' */
  uint32_T Add;                        /* '<S1>/Add' */
  uint32_T CastToDouble;               /* '<S2>/Cast To Double' */
  uint32_T data;                       /* '<S2>/DataLogic' */
  boolean_T NOT1;                      /* '<S2>/NOT1' */
} B_top_level_algo_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<Root>/Digital Output3' */
  codertarget_arduinobase_block_T obj_a;/* '<Root>/Digital Output2' */
  real_T Delay_DSTATE[40];             /* '<S2>/Delay' */
  real_T UnitDelay_DSTATE;             /* '<S40>/Unit Delay' */
  real_T TmpRTBAtSwitchInport1_Buffer0;/* synthesized block */
  real_T TmpRTBAtSwitchInport1_Buffer0_d;/* synthesized block */
  real_T TmpRTBAtUnitDelayInport1_Buffer;/* synthesized block */
  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S2>/Scope2' */

  struct {
    void *LoggedData[2];
  } Scope12_PWORK;                     /* '<S2>/Scope12' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S2>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S2>/Scope1' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<S2>/Scope3' */

  int32_T clockTickCounter;            /* '<S2>/Pulse Generator' */
  uint32_T is_c15_top_level_algo;      /* '<S2>/DataLogic' */
  uint32_T Holder;                     /* '<S2>/DataLogic' */
  uint32_T temporalCounter_i1;         /* '<S2>/DataLogic' */
  boolean_T Delay8_DSTATE[2880];       /* '<S2>/Delay8' */
  boolean_T Delay7_DSTATE;             /* '<S2>/Delay7' */
  uint8_T is_active_c15_top_level_algo;/* '<S2>/DataLogic' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem9_j;/* '<S5>/If Action Subsystem9' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem10_b;/* '<S5>/If Action Subsystem10' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem8_ez;/* '<S5>/If Action Subsystem8' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem7_a;/* '<S5>/If Action Subsystem7' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem6_f;/* '<S5>/If Action Subsystem6' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem5_b;/* '<S5>/If Action Subsystem5' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem4_o;/* '<S5>/If Action Subsystem4' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem3_f0;/* '<S5>/If Action Subsystem3' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem2_i;/* '<S5>/If Action Subsystem2' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem1_n;/* '<S5>/If Action Subsystem1' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem_c;/* '<S5>/If Action Subsystem' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem9_p;/* '<S4>/If Action Subsystem9' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem10_a;/* '<S4>/If Action Subsystem10' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem8_e;/* '<S4>/If Action Subsystem8' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem7_c;/* '<S4>/If Action Subsystem7' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem6_l;/* '<S4>/If Action Subsystem6' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem5_h;/* '<S4>/If Action Subsystem5' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem4_j;/* '<S4>/If Action Subsystem4' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem3_f;/* '<S4>/If Action Subsystem3' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem2_p;/* '<S4>/If Action Subsystem2' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem1_b;/* '<S4>/If Action Subsystem1' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem_j;/* '<S4>/If Action Subsystem' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem9;/* '<S3>/If Action Subsystem9' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem10;/* '<S3>/If Action Subsystem10' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem8;/* '<S3>/If Action Subsystem8' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem7;/* '<S3>/If Action Subsystem7' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem6;/* '<S3>/If Action Subsystem6' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem5;/* '<S3>/If Action Subsystem5' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem4;/* '<S3>/If Action Subsystem4' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem3;/* '<S3>/If Action Subsystem3' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem2;/* '<S3>/If Action Subsystem2' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem1;/* '<S3>/If Action Subsystem1' */
  DW_IfActionSubsystem_top_leve_T IfActionSubsystem;/* '<S3>/If Action Subsystem' */
} DW_top_level_algo_T;

/* Parameters for system: '<S3>/If Action Subsystem' */
struct P_IfActionSubsystem_top_level_T_ {
  uint8_T Constant_Value;              /* Expression: 0x3F
                                        * Referenced by: '<S6>/Constant'
                                        */
};

/* Parameters (default storage) */
struct P_top_level_algo_T_ {
  real32_T CompareToConstant_const;   /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S41>/Constant'
                                       */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S40>/Constant1'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S2>/Delay'
                                        */
  real_T TmpRTBAtSwitchInport1_InitialCo;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Constant5_Value;              /* Expression: 120
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant1_Value_h;            /* Expression: 100
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 10
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S2>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<S2>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<S2>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 2
                                        * Referenced by: '<S2>/Pulse Generator'
                                        */
  real_T TmpRTBAtSwitchInport1_Initial_j;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S40>/Constant'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S40>/Unit Delay'
                                        */
  boolean_T Delay8_InitialCondition;
                                  /* Computed Parameter: Delay8_InitialCondition
                                   * Referenced by: '<S2>/Delay8'
                                   */
  boolean_T Delay7_InitialCondition;
                                  /* Computed Parameter: Delay7_InitialCondition
                                   * Referenced by: '<S2>/Delay7'
                                   */
  uint8_T Merge_InitialOutput;        /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S5>/Merge'
                                       */
  uint8_T Merge_InitialOutput_g;    /* Computed Parameter: Merge_InitialOutput_g
                                     * Referenced by: '<S4>/Merge'
                                     */
  uint8_T Merge_InitialOutput_n;    /* Computed Parameter: Merge_InitialOutput_n
                                     * Referenced by: '<S3>/Merge'
                                     */
  P_IfActionSubsystem_top_level_T IfActionSubsystem9_j;/* '<S5>/If Action Subsystem9' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem10_b;/* '<S5>/If Action Subsystem10' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem8_ez;/* '<S5>/If Action Subsystem8' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem7_a;/* '<S5>/If Action Subsystem7' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem6_f;/* '<S5>/If Action Subsystem6' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem5_b;/* '<S5>/If Action Subsystem5' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem4_o;/* '<S5>/If Action Subsystem4' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem3_f0;/* '<S5>/If Action Subsystem3' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem2_i;/* '<S5>/If Action Subsystem2' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem1_n;/* '<S5>/If Action Subsystem1' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem_c;/* '<S5>/If Action Subsystem' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem9_p;/* '<S4>/If Action Subsystem9' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem10_a;/* '<S4>/If Action Subsystem10' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem8_e;/* '<S4>/If Action Subsystem8' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem7_c;/* '<S4>/If Action Subsystem7' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem6_l;/* '<S4>/If Action Subsystem6' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem5_h;/* '<S4>/If Action Subsystem5' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem4_j;/* '<S4>/If Action Subsystem4' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem3_f;/* '<S4>/If Action Subsystem3' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem2_p;/* '<S4>/If Action Subsystem2' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem1_b;/* '<S4>/If Action Subsystem1' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem_j;/* '<S4>/If Action Subsystem' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem9;/* '<S3>/If Action Subsystem9' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem10;/* '<S3>/If Action Subsystem10' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem8;/* '<S3>/If Action Subsystem8' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem7;/* '<S3>/If Action Subsystem7' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem6;/* '<S3>/If Action Subsystem6' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem5;/* '<S3>/If Action Subsystem5' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem4;/* '<S3>/If Action Subsystem4' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem3;/* '<S3>/If Action Subsystem3' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem2;/* '<S3>/If Action Subsystem2' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem1;/* '<S3>/If Action Subsystem1' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem;/* '<S3>/If Action Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_top_level_algo_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_top_level_algo_T top_level_algo_P;

/* Block signals (default storage) */
extern B_top_level_algo_T top_level_algo_B;

/* Block states (default storage) */
extern DW_top_level_algo_T top_level_algo_DW;

/* External function called from main */
extern void top_level_algo_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void top_level_algo_initialize(void);
extern void top_level_algo_step0(void);
extern void top_level_algo_step1(void);
extern void top_level_algo_step(int_T tid);
extern void top_level_algo_terminate(void);

/* Real-time Model object */
extern RT_MODEL_top_level_algo_T *const top_level_algo_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Shift Arithmetic' : Eliminated trivial shift
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'top_level_algo'
 * '<S1>'   : 'top_level_algo/HR Encoding'
 * '<S2>'   : 'top_level_algo/Sped up 7seg Driver1'
 * '<S3>'   : 'top_level_algo/HR Encoding/7seg encoder'
 * '<S4>'   : 'top_level_algo/HR Encoding/7seg encoder1'
 * '<S5>'   : 'top_level_algo/HR Encoding/7seg encoder2'
 * '<S6>'   : 'top_level_algo/HR Encoding/7seg encoder/If Action Subsystem'
 * '<S7>'   : 'top_level_algo/HR Encoding/7seg encoder/If Action Subsystem1'
 * '<S8>'   : 'top_level_algo/HR Encoding/7seg encoder/If Action Subsystem10'
 * '<S9>'   : 'top_level_algo/HR Encoding/7seg encoder/If Action Subsystem2'
 * '<S10>'  : 'top_level_algo/HR Encoding/7seg encoder/If Action Subsystem3'
 * '<S11>'  : 'top_level_algo/HR Encoding/7seg encoder/If Action Subsystem4'
 * '<S12>'  : 'top_level_algo/HR Encoding/7seg encoder/If Action Subsystem5'
 * '<S13>'  : 'top_level_algo/HR Encoding/7seg encoder/If Action Subsystem6'
 * '<S14>'  : 'top_level_algo/HR Encoding/7seg encoder/If Action Subsystem7'
 * '<S15>'  : 'top_level_algo/HR Encoding/7seg encoder/If Action Subsystem8'
 * '<S16>'  : 'top_level_algo/HR Encoding/7seg encoder/If Action Subsystem9'
 * '<S17>'  : 'top_level_algo/HR Encoding/7seg encoder1/If Action Subsystem'
 * '<S18>'  : 'top_level_algo/HR Encoding/7seg encoder1/If Action Subsystem1'
 * '<S19>'  : 'top_level_algo/HR Encoding/7seg encoder1/If Action Subsystem10'
 * '<S20>'  : 'top_level_algo/HR Encoding/7seg encoder1/If Action Subsystem2'
 * '<S21>'  : 'top_level_algo/HR Encoding/7seg encoder1/If Action Subsystem3'
 * '<S22>'  : 'top_level_algo/HR Encoding/7seg encoder1/If Action Subsystem4'
 * '<S23>'  : 'top_level_algo/HR Encoding/7seg encoder1/If Action Subsystem5'
 * '<S24>'  : 'top_level_algo/HR Encoding/7seg encoder1/If Action Subsystem6'
 * '<S25>'  : 'top_level_algo/HR Encoding/7seg encoder1/If Action Subsystem7'
 * '<S26>'  : 'top_level_algo/HR Encoding/7seg encoder1/If Action Subsystem8'
 * '<S27>'  : 'top_level_algo/HR Encoding/7seg encoder1/If Action Subsystem9'
 * '<S28>'  : 'top_level_algo/HR Encoding/7seg encoder2/If Action Subsystem'
 * '<S29>'  : 'top_level_algo/HR Encoding/7seg encoder2/If Action Subsystem1'
 * '<S30>'  : 'top_level_algo/HR Encoding/7seg encoder2/If Action Subsystem10'
 * '<S31>'  : 'top_level_algo/HR Encoding/7seg encoder2/If Action Subsystem2'
 * '<S32>'  : 'top_level_algo/HR Encoding/7seg encoder2/If Action Subsystem3'
 * '<S33>'  : 'top_level_algo/HR Encoding/7seg encoder2/If Action Subsystem4'
 * '<S34>'  : 'top_level_algo/HR Encoding/7seg encoder2/If Action Subsystem5'
 * '<S35>'  : 'top_level_algo/HR Encoding/7seg encoder2/If Action Subsystem6'
 * '<S36>'  : 'top_level_algo/HR Encoding/7seg encoder2/If Action Subsystem7'
 * '<S37>'  : 'top_level_algo/HR Encoding/7seg encoder2/If Action Subsystem8'
 * '<S38>'  : 'top_level_algo/HR Encoding/7seg encoder2/If Action Subsystem9'
 * '<S39>'  : 'top_level_algo/Sped up 7seg Driver1/DataLogic'
 * '<S40>'  : 'top_level_algo/Sped up 7seg Driver1/clk'
 * '<S41>'  : 'top_level_algo/Sped up 7seg Driver1/clk/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_top_level_algo_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
