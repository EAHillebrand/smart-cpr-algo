/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo.h
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 1.158
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Mon Mar  6 18:47:31 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_top_level_algo_h_
#define RTW_HEADER_top_level_algo_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef top_level_algo_COMMON_INCLUDES_
#define top_level_algo_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "main.h"
#endif                                 /* top_level_algo_COMMON_INCLUDES_ */

#include "top_level_algo_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block states (default storage) for system '<S9>/sample and hold' */
typedef struct {
  uint8_T is_active_c1_top_level_algo; /* '<S9>/sample and hold' */
  uint8_T is_c1_top_level_algo;        /* '<S9>/sample and hold' */
} DW_sampleandhold_top_level_al_T;

/* Block signals (default storage) */
typedef struct {
  real_T TappedDelay_l[100];           /* '<S6>/Tapped Delay' */
  GPIO_TypeDef * portNameLoc;
  uint16_T triggerType;
  real_T Product;                      /* '<S7>/Product' */
  real_T u0Diff;                       /* '<S6>/30 Diff' */
  real_T baseline;                     /* '<S7>/timer' */
  real_T rate;                         /* '<S3>/Chart' */
  real_T CLK;                          /* '<S11>/ClockLogic' */
  real_T PulseGenerator;               /* '<S1>/Pulse Generator' */
  real_T TmpMLSysMemLayoutBufferAt_p;/* '<S10>/Divide by Constant and Round1' */
  real_T TmpMLSysMemLayoutBufferAtDi; /* '<S10>/Divide by Constant and Round' */
  real_T Mod1;                         /* '<S10>/Mod1' */
  real_T u;
  real_T u_m;
  real_T u_c;
  real_T u_k;
  uint32_T Add;                        /* '<S10>/Add' */
  uint32_T data;                       /* '<S11>/DataLogic' */
  int32_T CastToDouble;                /* '<Root>/Cast To Double' */
  uint8_T Merge;                       /* '<S12>/Merge' */
  uint8_T Merge_b;                     /* '<S13>/Merge' */
  uint8_T Merge_d;                     /* '<S14>/Merge' */
} B_top_level_algo_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj_c;/* '<S48>/Analog to Digital Converter' */
  real_T TappedDelay_X[5];             /* '<S3>/Tapped Delay' */
  real_T TappedDelay1_X[20];           /* '<S7>/Tapped Delay1' */
  real_T TappedDelay_X_p[100];         /* '<S6>/Tapped Delay' */
  real_T Delay_DSTATE;                 /* '<S6>/Delay' */
  real_T Delay1_DSTATE[2];             /* '<S6>/Delay1' */
  real_T Delay2_DSTATE[3];             /* '<S6>/Delay2' */
  real_T Delay3_DSTATE[4];             /* '<S6>/Delay3' */
  real_T Delay4_DSTATE[5];             /* '<S6>/Delay4' */
  real_T Delay5_DSTATE[50];            /* '<S6>/Delay5' */
  real_T Memory_PreviousInput;         /* '<S88>/Memory' */
  real_T Memory_PreviousInput_l;       /* '<S87>/Memory' */
  real_T comp;                         /* '<S3>/Chart' */
  real_T last_count;                   /* '<S3>/Chart' */
  real_T first;                        /* '<S3>/Chart' */
  real_T second;                       /* '<S3>/Chart' */
  real_T third;                        /* '<S3>/Chart' */
  real_T fourth;                       /* '<S3>/Chart' */
  real_T zero;                         /* '<S3>/Chart' */
  real_T counter;                      /* '<S11>/ClockLogic' */
  int32_T TappedDelay_X_f[20];         /* '<S7>/Tapped Delay' */
  int32_T clockTickCounter;            /* '<S1>/Pulse Generator' */
  uint32_T Holder;                     /* '<S11>/DataLogic' */
  uint16_T temporalCounter_i1;         /* '<S7>/timer' */
  boolean_T Delay8_DSTATE[2];          /* '<S9>/Delay8' */
  boolean_T Delay7_DSTATE;             /* '<S9>/Delay7' */
  boolean_T Delay6_DSTATE[2];          /* '<S9>/Delay6' */
  boolean_T Delay2_DSTATE_m[5];        /* '<S9>/Delay2' */
  boolean_T Delay4_DSTATE_a[2];        /* '<S9>/Delay4' */
  boolean_T Delay1_DSTATE_m;           /* '<S9>/Delay1' */
  boolean_T Delay3_DSTATE_m[2];        /* '<S9>/Delay3' */
  boolean_T Delay_DSTATE_a[5];         /* '<S9>/Delay' */
  uint8_T is_active_c3_top_level_algo; /* '<S7>/timer' */
  uint8_T is_c3_top_level_algo;        /* '<S7>/timer' */
  uint8_T is_active_c4_top_level_algo; /* '<S3>/Chart' */
  uint8_T is_c4_top_level_algo;        /* '<S3>/Chart' */
  uint8_T is_active_c6_top_level_algo; /* '<S11>/DataLogic' */
  uint8_T is_c6_top_level_algo;        /* '<S11>/DataLogic' */
  uint8_T temporalCounter_i1_d;        /* '<S11>/DataLogic' */
  uint8_T is_active_c5_top_level_algo; /* '<S11>/ClockLogic' */
  uint8_T is_c5_top_level_algo;        /* '<S11>/ClockLogic' */
  uint8_T temporalCounter_i1_l;        /* '<S11>/ClockLogic' */
  DW_sampleandhold_top_level_al_T sf_sampleandhold1;/* '<S9>/sample and hold1' */
  DW_sampleandhold_top_level_al_T sf_sampleandhold;/* '<S9>/sample and hold' */
} DW_top_level_algo_T;

/* Parameters for system: '<S12>/If Action Subsystem' */
struct P_IfActionSubsystem_top_level_T_ {
  uint8_T Constant_Value;              /* Expression: 0x3F
                                        * Referenced by: '<S15>/Constant'
                                        */
};

/* Parameters (default storage) */
struct P_top_level_algo_T_ {
  real_T Vdd;                          /* Variable: Vdd
                                        * Referenced by:
                                        *   '<S7>/Constant'
                                        *   '<S7>/rad  per volt'
                                        */
  real_T gear_ratio;                   /* Variable: gear_ratio
                                        * Referenced by: '<S7>/Gear Down'
                                        */
  real_T Positive_const;               /* Mask Parameter: Positive_const
                                        * Referenced by: '<S57>/Constant'
                                        */
  real_T Longrangemotionup_const;     /* Mask Parameter: Longrangemotionup_const
                                       * Referenced by: '<S55>/Constant'
                                       */
  real_T Negative_const;               /* Mask Parameter: Negative_const
                                        * Referenced by: '<S56>/Constant'
                                        */
  real_T Longrangemotiondown_const; /* Mask Parameter: Longrangemotiondown_const
                                     * Referenced by: '<S54>/Constant'
                                     */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S62>/Constant'
                                       */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S63>/Constant'
                                      */
  real_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S64>/Constant'
                                      */
  real_T CompareToConstant3_const;   /* Mask Parameter: CompareToConstant3_const
                                      * Referenced by: '<S65>/Constant'
                                      */
  real_T CompareToConstant4_const;   /* Mask Parameter: CompareToConstant4_const
                                      * Referenced by: '<S66>/Constant'
                                      */
  real_T MaxBDC_vinit;                 /* Mask Parameter: MaxBDC_vinit
                                        * Referenced by:
                                        *   '<S87>/Initial Condition'
                                        *   '<S87>/Memory'
                                        */
  real_T MinBDC_vinit;                 /* Mask Parameter: MinBDC_vinit
                                        * Referenced by:
                                        *   '<S88>/Initial Condition'
                                        *   '<S88>/Memory'
                                        */
  real_T TappedDelay_vinit;            /* Mask Parameter: TappedDelay_vinit
                                        * Referenced by: '<S3>/Tapped Delay'
                                        */
  real_T TappedDelay1_vinit;           /* Mask Parameter: TappedDelay1_vinit
                                        * Referenced by: '<S7>/Tapped Delay1'
                                        */
  real_T TappedDelay_vinit_f;          /* Mask Parameter: TappedDelay_vinit_f
                                        * Referenced by: '<S6>/Tapped Delay'
                                        */
  int32_T TappedDelay_vinit_l;         /* Mask Parameter: TappedDelay_vinit_l
                                        * Referenced by: '<S7>/Tapped Delay'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S1>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<S1>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<S1>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S1>/Pulse Generator'
                                        */
  real_T Constant1_Value;              /* Expression: 100
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 10
                                        * Referenced by: '<S10>/Constant2'
                                        */
  real_T Constant1_Value_d;            /* Expression: 4095
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S7>/Switch'
                                        */
  real_T Radiusmm_Gain;                /* Expression: 100
                                        * Referenced by: '<S7>/Radius (mm)'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S58>/Constant'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S6>/Delay'
                                        */
  real_T Gain_Gain;                    /* Expression: 2
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S6>/Delay1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 2
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S6>/Delay2'
                                        */
  real_T Delay3_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S6>/Delay3'
                                        */
  real_T Delay4_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S6>/Delay4'
                                        */
  real_T Delay5_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S6>/Delay5'
                                        */
  real_T CompressionSensitivity_Gain;  /* Expression: 2
                                        * Referenced by: '<S6>/Compression  Sensitivity'
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S84>/Constant'
                                        */
  boolean_T Delay8_InitialCondition;
                                  /* Computed Parameter: Delay8_InitialCondition
                                   * Referenced by: '<S9>/Delay8'
                                   */
  boolean_T Delay7_InitialCondition;
                                  /* Computed Parameter: Delay7_InitialCondition
                                   * Referenced by: '<S9>/Delay7'
                                   */
  boolean_T Delay6_InitialCondition;
                                  /* Computed Parameter: Delay6_InitialCondition
                                   * Referenced by: '<S9>/Delay6'
                                   */
  boolean_T Delay2_InitialCondition_c;
                                /* Computed Parameter: Delay2_InitialCondition_c
                                 * Referenced by: '<S9>/Delay2'
                                 */
  boolean_T Delay4_InitialCondition_f;
                                /* Computed Parameter: Delay4_InitialCondition_f
                                 * Referenced by: '<S9>/Delay4'
                                 */
  boolean_T Delay1_InitialCondition_d;
                                /* Computed Parameter: Delay1_InitialCondition_d
                                 * Referenced by: '<S9>/Delay1'
                                 */
  boolean_T Delay3_InitialCondition_k;
                                /* Computed Parameter: Delay3_InitialCondition_k
                                 * Referenced by: '<S9>/Delay3'
                                 */
  boolean_T Delay_InitialCondition_d;
                                 /* Computed Parameter: Delay_InitialCondition_d
                                  * Referenced by: '<S9>/Delay'
                                  */
  uint8_T Merge_InitialOutput;        /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S12>/Merge'
                                       */
  uint8_T Merge_InitialOutput_i;    /* Computed Parameter: Merge_InitialOutput_i
                                     * Referenced by: '<S13>/Merge'
                                     */
  uint8_T Merge_InitialOutput_j;    /* Computed Parameter: Merge_InitialOutput_j
                                     * Referenced by: '<S14>/Merge'
                                     */
  P_IfActionSubsystem_top_level_T IfActionSubsystem10_m;/* '<S14>/If Action Subsystem10' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem8_f;/* '<S14>/If Action Subsystem8' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem7_n;/* '<S14>/If Action Subsystem7' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem6_c;/* '<S14>/If Action Subsystem6' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem5_hh;/* '<S14>/If Action Subsystem5' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem4_db;/* '<S14>/If Action Subsystem4' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem3_c;/* '<S14>/If Action Subsystem3' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem2_i;/* '<S14>/If Action Subsystem2' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem1_a;/* '<S14>/If Action Subsystem1' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem_j;/* '<S14>/If Action Subsystem' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem10_l;/* '<S13>/If Action Subsystem10' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem8_p;/* '<S13>/If Action Subsystem8' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem7_h;/* '<S13>/If Action Subsystem7' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem6_b;/* '<S13>/If Action Subsystem6' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem5_h;/* '<S13>/If Action Subsystem5' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem4_d;/* '<S13>/If Action Subsystem4' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem3_p;/* '<S13>/If Action Subsystem3' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem2_d;/* '<S13>/If Action Subsystem2' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem1_d;/* '<S13>/If Action Subsystem1' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem_l;/* '<S13>/If Action Subsystem' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem10;/* '<S12>/If Action Subsystem10' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem8;/* '<S12>/If Action Subsystem8' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem7;/* '<S12>/If Action Subsystem7' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem6;/* '<S12>/If Action Subsystem6' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem5;/* '<S12>/If Action Subsystem5' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem4;/* '<S12>/If Action Subsystem4' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem3;/* '<S12>/If Action Subsystem3' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem2;/* '<S12>/If Action Subsystem2' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem1;/* '<S12>/If Action Subsystem1' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem;/* '<S12>/If Action Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_top_level_algo_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_top_level_algo_T top_level_algo_P;

/* Block signals (default storage) */
extern B_top_level_algo_T top_level_algo_B;

/* Block states (default storage) */
extern DW_top_level_algo_T top_level_algo_DW;

/* Model entry point functions */
extern void top_level_algo_initialize(void);
extern void top_level_algo_step(void);
extern void top_level_algo_terminate(void);

/* Real-time Model object */
extern RT_MODEL_top_level_algo_T *const top_level_algo_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Display1' : Unused code path elimination
 * Block '<S1>/Display2' : Unused code path elimination
 * Block '<S10>/Add1' : Unused code path elimination
 * Block '<S10>/Constant' : Unused code path elimination
 * Block '<S10>/Display1' : Unused code path elimination
 * Block '<S10>/Display2' : Unused code path elimination
 * Block '<S10>/Shift Arithmetic3' : Unused code path elimination
 * Block '<S1>/Scope12' : Unused code path elimination
 * Block '<S3>/Constant2' : Unused code path elimination
 * Block '<S3>/Counter1' : Unused code path elimination
 * Block '<S3>/Subtract3' : Unused code path elimination
 * Block '<S6>/Scope' : Unused code path elimination
 * Block '<Root>/Gain' : Unused code path elimination
 * Block '<S82>/Data Type Duplicate' : Unused code path elimination
 * Block '<S87>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<S83>/Data Type Duplicate' : Unused code path elimination
 * Block '<S88>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<S9>/Scope' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope10' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<Root>/Scope7' : Unused code path elimination
 * Block '<Root>/Scope8' : Unused code path elimination
 * Block '<Root>/Scope9' : Unused code path elimination
 * Block '<S10>/Shift Arithmetic' : Eliminated trivial shift
 * Block '<S11>/Cast To Double' : Eliminate redundant data type conversion
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
 * '<S1>'   : 'top_level_algo/7seg Driver'
 * '<S2>'   : 'top_level_algo/Analog to Digital Converter'
 * '<S3>'   : 'top_level_algo/Compression Detection'
 * '<S4>'   : 'top_level_algo/Digital Port Write4'
 * '<S5>'   : 'top_level_algo/Digital Port Write5'
 * '<S6>'   : 'top_level_algo/Direction '
 * '<S7>'   : 'top_level_algo/Hardware Hiding'
 * '<S8>'   : 'top_level_algo/LED_display'
 * '<S9>'   : 'top_level_algo/MinMax'
 * '<S10>'  : 'top_level_algo/7seg Driver/HR Encoding'
 * '<S11>'  : 'top_level_algo/7seg Driver/Subsystem'
 * '<S12>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder'
 * '<S13>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder1'
 * '<S14>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder2'
 * '<S15>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder/If Action Subsystem'
 * '<S16>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder/If Action Subsystem1'
 * '<S17>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder/If Action Subsystem10'
 * '<S18>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder/If Action Subsystem2'
 * '<S19>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder/If Action Subsystem3'
 * '<S20>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder/If Action Subsystem4'
 * '<S21>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder/If Action Subsystem5'
 * '<S22>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder/If Action Subsystem6'
 * '<S23>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder/If Action Subsystem7'
 * '<S24>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder/If Action Subsystem8'
 * '<S25>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder1/If Action Subsystem'
 * '<S26>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder1/If Action Subsystem1'
 * '<S27>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder1/If Action Subsystem10'
 * '<S28>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder1/If Action Subsystem2'
 * '<S29>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder1/If Action Subsystem3'
 * '<S30>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder1/If Action Subsystem4'
 * '<S31>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder1/If Action Subsystem5'
 * '<S32>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder1/If Action Subsystem6'
 * '<S33>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder1/If Action Subsystem7'
 * '<S34>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder1/If Action Subsystem8'
 * '<S35>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder2/If Action Subsystem'
 * '<S36>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder2/If Action Subsystem1'
 * '<S37>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder2/If Action Subsystem10'
 * '<S38>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder2/If Action Subsystem2'
 * '<S39>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder2/If Action Subsystem3'
 * '<S40>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder2/If Action Subsystem4'
 * '<S41>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder2/If Action Subsystem5'
 * '<S42>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder2/If Action Subsystem6'
 * '<S43>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder2/If Action Subsystem7'
 * '<S44>'  : 'top_level_algo/7seg Driver/HR Encoding/7seg encoder2/If Action Subsystem8'
 * '<S45>'  : 'top_level_algo/7seg Driver/Subsystem/ClockLogic'
 * '<S46>'  : 'top_level_algo/7seg Driver/Subsystem/DataLogic'
 * '<S47>'  : 'top_level_algo/Analog to Digital Converter/ECSoC'
 * '<S48>'  : 'top_level_algo/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S49>'  : 'top_level_algo/Compression Detection/Chart'
 * '<S50>'  : 'top_level_algo/Digital Port Write4/ECSoC'
 * '<S51>'  : 'top_level_algo/Digital Port Write4/ECSoC/ECSimCodegen'
 * '<S52>'  : 'top_level_algo/Digital Port Write5/ECSoC'
 * '<S53>'  : 'top_level_algo/Digital Port Write5/ECSoC/ECSimCodegen'
 * '<S54>'  : 'top_level_algo/Direction /Long range motion down'
 * '<S55>'  : 'top_level_algo/Direction /Long range motion up'
 * '<S56>'  : 'top_level_algo/Direction /Negative'
 * '<S57>'  : 'top_level_algo/Direction /Positive'
 * '<S58>'  : 'top_level_algo/Hardware Hiding/force min to zero'
 * '<S59>'  : 'top_level_algo/Hardware Hiding/timer'
 * '<S60>'  : 'top_level_algo/Hardware Hiding/force min to zero/If Action Subsystem'
 * '<S61>'  : 'top_level_algo/Hardware Hiding/force min to zero/If Action Subsystem1'
 * '<S62>'  : 'top_level_algo/LED_display/Compare To Constant'
 * '<S63>'  : 'top_level_algo/LED_display/Compare To Constant1'
 * '<S64>'  : 'top_level_algo/LED_display/Compare To Constant2'
 * '<S65>'  : 'top_level_algo/LED_display/Compare To Constant3'
 * '<S66>'  : 'top_level_algo/LED_display/Compare To Constant4'
 * '<S67>'  : 'top_level_algo/LED_display/Digital Port Write'
 * '<S68>'  : 'top_level_algo/LED_display/Digital Port Write1'
 * '<S69>'  : 'top_level_algo/LED_display/Digital Port Write2'
 * '<S70>'  : 'top_level_algo/LED_display/Digital Port Write3'
 * '<S71>'  : 'top_level_algo/LED_display/Digital Port Write4'
 * '<S72>'  : 'top_level_algo/LED_display/Digital Port Write/ECSoC'
 * '<S73>'  : 'top_level_algo/LED_display/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S74>'  : 'top_level_algo/LED_display/Digital Port Write1/ECSoC'
 * '<S75>'  : 'top_level_algo/LED_display/Digital Port Write1/ECSoC/ECSimCodegen'
 * '<S76>'  : 'top_level_algo/LED_display/Digital Port Write2/ECSoC'
 * '<S77>'  : 'top_level_algo/LED_display/Digital Port Write2/ECSoC/ECSimCodegen'
 * '<S78>'  : 'top_level_algo/LED_display/Digital Port Write3/ECSoC'
 * '<S79>'  : 'top_level_algo/LED_display/Digital Port Write3/ECSoC/ECSimCodegen'
 * '<S80>'  : 'top_level_algo/LED_display/Digital Port Write4/ECSoC'
 * '<S81>'  : 'top_level_algo/LED_display/Digital Port Write4/ECSoC/ECSimCodegen'
 * '<S82>'  : 'top_level_algo/MinMax/Max (BDC)'
 * '<S83>'  : 'top_level_algo/MinMax/Min (BDC)'
 * '<S84>'  : 'top_level_algo/MinMax/force min to zero'
 * '<S85>'  : 'top_level_algo/MinMax/sample and hold'
 * '<S86>'  : 'top_level_algo/MinMax/sample and hold1'
 * '<S87>'  : 'top_level_algo/MinMax/Max (BDC)/Subsystem'
 * '<S88>'  : 'top_level_algo/MinMax/Min (BDC)/Subsystem'
 * '<S89>'  : 'top_level_algo/MinMax/force min to zero/If Action Subsystem'
 * '<S90>'  : 'top_level_algo/MinMax/force min to zero/If Action Subsystem1'
 */
#endif                                 /* RTW_HEADER_top_level_algo_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
