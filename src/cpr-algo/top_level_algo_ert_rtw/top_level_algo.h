/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo.h
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 1.146
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sat Mar  4 22:35:31 2023
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

/* Block states (default storage) for system '<S8>/sample and hold' */
typedef struct {
  uint8_T is_active_c1_top_level_algo; /* '<S8>/sample and hold' */
  uint8_T is_c1_top_level_algo;        /* '<S8>/sample and hold' */
} DW_sampleandhold_top_level_al_T;

/* Block signals (default storage) */
typedef struct {
  real_T TappedDelay[100];             /* '<S5>/Tapped Delay' */
  GPIO_TypeDef * portNameLoc;
  uint16_T triggerType;
  real_T Product;                      /* '<S6>/Product' */
  real_T u0Diff;                       /* '<S5>/30 Diff' */
  real_T CLK;                          /* '<S49>/ClockLogic' */
  real_T baseline;                     /* '<S6>/timer' */
  real_T rate;                         /* '<S2>/Chart' */
  real_T PulseGenerator;               /* '<S9>/Pulse Generator' */
  real_T TmpMLSysMemLayoutBufferAtDi;/* '<S48>/Divide by Constant and Round1' */
  real_T Mean_AccVal;
  real_T Mean1_AccVal;
  real_T u;
  real_T u_m;
  real_T u_c;
  real_T u_k;
  real_T u_cx;
  uint32_T data;                       /* '<S49>/DataLogic' */
  int32_T CastToDouble;                /* '<Root>/Cast To Double' */
  uint8_T Merge;                       /* '<S50>/Merge' */
  uint8_T Merge_b;                     /* '<S51>/Merge' */
  uint8_T Merge_d;                     /* '<S52>/Merge' */
} B_top_level_algo_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj_c;/* '<S11>/Analog to Digital Converter' */
  real_T TappedDelay1_X[20];           /* '<S6>/Tapped Delay1' */
  real_T TappedDelay_X[100];           /* '<S5>/Tapped Delay' */
  real_T Delay_DSTATE;                 /* '<S5>/Delay' */
  real_T Delay1_DSTATE[2];             /* '<S5>/Delay1' */
  real_T Delay2_DSTATE[3];             /* '<S5>/Delay2' */
  real_T Delay3_DSTATE[4];             /* '<S5>/Delay3' */
  real_T Delay4_DSTATE[5];             /* '<S5>/Delay4' */
  real_T Delay5_DSTATE[50];            /* '<S5>/Delay5' */
  real_T Memory_PreviousInput;         /* '<S45>/Memory' */
  real_T Memory_PreviousInput_l;       /* '<S44>/Memory' */
  real_T counter;                      /* '<S49>/ClockLogic' */
  real_T comp;                         /* '<S2>/Chart' */
  real_T last_count;                   /* '<S2>/Chart' */
  real_T first;                        /* '<S2>/Chart' */
  real_T second;                       /* '<S2>/Chart' */
  real_T third;                        /* '<S2>/Chart' */
  real_T fourth;                       /* '<S2>/Chart' */
  real_T zero;                         /* '<S2>/Chart' */
  int32_T TappedDelay_X_f[20];         /* '<S6>/Tapped Delay' */
  int32_T clockTickCounter;            /* '<S9>/Pulse Generator' */
  uint32_T Holder;                     /* '<S49>/DataLogic' */
  uint16_T temporalCounter_i1;         /* '<S6>/timer' */
  boolean_T Delay8_DSTATE[2];          /* '<S8>/Delay8' */
  boolean_T Delay7_DSTATE;             /* '<S8>/Delay7' */
  boolean_T Delay6_DSTATE[2];          /* '<S8>/Delay6' */
  boolean_T Delay2_DSTATE_m[5];        /* '<S8>/Delay2' */
  boolean_T Delay4_DSTATE_a[2];        /* '<S8>/Delay4' */
  boolean_T Delay1_DSTATE_m;           /* '<S8>/Delay1' */
  boolean_T Delay3_DSTATE_m[2];        /* '<S8>/Delay3' */
  boolean_T Delay_DSTATE_a[5];         /* '<S8>/Delay' */
  uint8_T is_active_c6_top_level_algo; /* '<S49>/DataLogic' */
  uint8_T is_c6_top_level_algo;        /* '<S49>/DataLogic' */
  uint8_T temporalCounter_i1_d;        /* '<S49>/DataLogic' */
  uint8_T is_active_c5_top_level_algo; /* '<S49>/ClockLogic' */
  uint8_T is_c5_top_level_algo;        /* '<S49>/ClockLogic' */
  uint8_T temporalCounter_i1_l;        /* '<S49>/ClockLogic' */
  uint8_T is_active_c3_top_level_algo; /* '<S6>/timer' */
  uint8_T is_c3_top_level_algo;        /* '<S6>/timer' */
  uint8_T is_active_c4_top_level_algo; /* '<S2>/Chart' */
  uint8_T is_c4_top_level_algo;        /* '<S2>/Chart' */
  DW_sampleandhold_top_level_al_T sf_sampleandhold1;/* '<S8>/sample and hold1' */
  DW_sampleandhold_top_level_al_T sf_sampleandhold;/* '<S8>/sample and hold' */
} DW_top_level_algo_T;

/* Parameters for system: '<S50>/If Action Subsystem' */
struct P_IfActionSubsystem_top_level_T_ {
  uint8_T Constant_Value;              /* Expression: 0x3F
                                        * Referenced by: '<S53>/Constant'
                                        */
};

/* Parameters (default storage) */
struct P_top_level_algo_T_ {
  real_T Vdd;                          /* Variable: Vdd
                                        * Referenced by:
                                        *   '<S6>/Constant'
                                        *   '<S6>/rad  per volt'
                                        */
  real_T gear_ratio;                   /* Variable: gear_ratio
                                        * Referenced by: '<S6>/Gear Down'
                                        */
  real_T Positive_const;               /* Mask Parameter: Positive_const
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T Longrangemotionup_const;     /* Mask Parameter: Longrangemotionup_const
                                       * Referenced by: '<S18>/Constant'
                                       */
  real_T Negative_const;               /* Mask Parameter: Negative_const
                                        * Referenced by: '<S19>/Constant'
                                        */
  real_T Longrangemotiondown_const; /* Mask Parameter: Longrangemotiondown_const
                                     * Referenced by: '<S17>/Constant'
                                     */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S25>/Constant'
                                       */
  real_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S27>/Constant'
                                      */
  real_T CompareToConstant4_const;   /* Mask Parameter: CompareToConstant4_const
                                      * Referenced by: '<S29>/Constant'
                                      */
  real_T MaxBDC_vinit;                 /* Mask Parameter: MaxBDC_vinit
                                        * Referenced by:
                                        *   '<S44>/Initial Condition'
                                        *   '<S44>/Memory'
                                        */
  real_T MinBDC_vinit;                 /* Mask Parameter: MinBDC_vinit
                                        * Referenced by:
                                        *   '<S45>/Initial Condition'
                                        *   '<S45>/Memory'
                                        */
  real_T TappedDelay1_vinit;           /* Mask Parameter: TappedDelay1_vinit
                                        * Referenced by: '<S6>/Tapped Delay1'
                                        */
  real_T TappedDelay_vinit;            /* Mask Parameter: TappedDelay_vinit
                                        * Referenced by: '<S5>/Tapped Delay'
                                        */
  int32_T TappedDelay_vinit_l;         /* Mask Parameter: TappedDelay_vinit_l
                                        * Referenced by: '<S6>/Tapped Delay'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S9>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<S9>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<S9>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S9>/Pulse Generator'
                                        */
  real_T Constant1_Value;              /* Expression: 4095
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S6>/Switch'
                                        */
  real_T Radiusmm_Gain;                /* Expression: 110
                                        * Referenced by: '<S6>/Radius (mm)'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S5>/Delay'
                                        */
  real_T Gain_Gain;                    /* Expression: 2
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S5>/Delay1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 2
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S5>/Delay2'
                                        */
  real_T Delay3_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S5>/Delay3'
                                        */
  real_T Delay4_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S5>/Delay4'
                                        */
  real_T Delay5_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S5>/Delay5'
                                        */
  real_T CompressionSensitivity_Gain;  /* Expression: 2
                                        * Referenced by: '<S5>/Compression  Sensitivity'
                                        */
  real_T Constant1_Value_g;            /* Expression: 100
                                        * Referenced by: '<S48>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 10
                                        * Referenced by: '<S48>/Constant2'
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S41>/Constant'
                                        */
  boolean_T Delay8_InitialCondition;
                                  /* Computed Parameter: Delay8_InitialCondition
                                   * Referenced by: '<S8>/Delay8'
                                   */
  boolean_T Delay7_InitialCondition;
                                  /* Computed Parameter: Delay7_InitialCondition
                                   * Referenced by: '<S8>/Delay7'
                                   */
  boolean_T Delay6_InitialCondition;
                                  /* Computed Parameter: Delay6_InitialCondition
                                   * Referenced by: '<S8>/Delay6'
                                   */
  boolean_T Delay2_InitialCondition_c;
                                /* Computed Parameter: Delay2_InitialCondition_c
                                 * Referenced by: '<S8>/Delay2'
                                 */
  boolean_T Delay4_InitialCondition_f;
                                /* Computed Parameter: Delay4_InitialCondition_f
                                 * Referenced by: '<S8>/Delay4'
                                 */
  boolean_T Delay1_InitialCondition_d;
                                /* Computed Parameter: Delay1_InitialCondition_d
                                 * Referenced by: '<S8>/Delay1'
                                 */
  boolean_T Delay3_InitialCondition_k;
                                /* Computed Parameter: Delay3_InitialCondition_k
                                 * Referenced by: '<S8>/Delay3'
                                 */
  boolean_T Delay_InitialCondition_d;
                                 /* Computed Parameter: Delay_InitialCondition_d
                                  * Referenced by: '<S8>/Delay'
                                  */
  uint8_T Merge_InitialOutput;        /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S50>/Merge'
                                       */
  uint8_T Merge_InitialOutput_i;    /* Computed Parameter: Merge_InitialOutput_i
                                     * Referenced by: '<S51>/Merge'
                                     */
  uint8_T Merge_InitialOutput_j;    /* Computed Parameter: Merge_InitialOutput_j
                                     * Referenced by: '<S52>/Merge'
                                     */
  P_IfActionSubsystem_top_level_T IfActionSubsystem10_m;/* '<S52>/If Action Subsystem10' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem8_f;/* '<S52>/If Action Subsystem8' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem7_n;/* '<S52>/If Action Subsystem7' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem6_c;/* '<S52>/If Action Subsystem6' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem5_hh;/* '<S52>/If Action Subsystem5' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem4_db;/* '<S52>/If Action Subsystem4' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem3_c;/* '<S52>/If Action Subsystem3' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem2_i;/* '<S52>/If Action Subsystem2' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem1_a;/* '<S52>/If Action Subsystem1' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem_j;/* '<S52>/If Action Subsystem' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem10_l;/* '<S51>/If Action Subsystem10' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem8_p;/* '<S51>/If Action Subsystem8' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem7_h;/* '<S51>/If Action Subsystem7' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem6_b;/* '<S51>/If Action Subsystem6' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem5_h;/* '<S51>/If Action Subsystem5' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem4_d;/* '<S51>/If Action Subsystem4' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem3_p;/* '<S51>/If Action Subsystem3' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem2_d;/* '<S51>/If Action Subsystem2' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem1_d;/* '<S51>/If Action Subsystem1' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem_l;/* '<S51>/If Action Subsystem' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem10;/* '<S50>/If Action Subsystem10' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem8;/* '<S50>/If Action Subsystem8' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem7;/* '<S50>/If Action Subsystem7' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem6;/* '<S50>/If Action Subsystem6' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem5;/* '<S50>/If Action Subsystem5' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem4;/* '<S50>/If Action Subsystem4' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem3;/* '<S50>/If Action Subsystem3' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem2;/* '<S50>/If Action Subsystem2' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem1_f;/* '<S50>/If Action Subsystem1' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem_o;/* '<S50>/If Action Subsystem' */
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
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
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
 * Block '<S2>/Constant2' : Unused code path elimination
 * Block '<S2>/Counter1' : Unused code path elimination
 * Block '<S2>/Mean' : Unused code path elimination
 * Block '<S2>/Subtract3' : Unused code path elimination
 * Block '<S2>/Tapped Delay' : Unused code path elimination
 * Block '<S5>/Scope' : Unused code path elimination
 * Block '<Root>/Gain' : Unused code path elimination
 * Block '<S26>/Compare' : Unused code path elimination
 * Block '<S26>/Constant' : Unused code path elimination
 * Block '<S28>/Compare' : Unused code path elimination
 * Block '<S28>/Constant' : Unused code path elimination
 * Block '<S39>/Data Type Duplicate' : Unused code path elimination
 * Block '<S44>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<S40>/Data Type Duplicate' : Unused code path elimination
 * Block '<S45>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<S8>/Scope' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope10' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<Root>/Scope3' : Unused code path elimination
 * Block '<Root>/Scope7' : Unused code path elimination
 * Block '<Root>/Scope8' : Unused code path elimination
 * Block '<Root>/Scope9' : Unused code path elimination
 * Block '<S9>/Display1' : Unused code path elimination
 * Block '<S9>/Display2' : Unused code path elimination
 * Block '<S48>/Add1' : Unused code path elimination
 * Block '<S48>/Constant' : Unused code path elimination
 * Block '<S48>/Display1' : Unused code path elimination
 * Block '<S48>/Display2' : Unused code path elimination
 * Block '<S48>/Shift Arithmetic3' : Unused code path elimination
 * Block '<S9>/Scope12' : Unused code path elimination
 * Block '<S48>/Shift Arithmetic' : Eliminated trivial shift
 * Block '<S49>/Cast To Double' : Eliminate redundant data type conversion
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
 * '<S1>'   : 'top_level_algo/Analog to Digital Converter'
 * '<S2>'   : 'top_level_algo/Compression Detection'
 * '<S3>'   : 'top_level_algo/Digital Port Write4'
 * '<S4>'   : 'top_level_algo/Digital Port Write5'
 * '<S5>'   : 'top_level_algo/Direction '
 * '<S6>'   : 'top_level_algo/Hardware Hiding'
 * '<S7>'   : 'top_level_algo/LED_display'
 * '<S8>'   : 'top_level_algo/MinMax'
 * '<S9>'   : 'top_level_algo/Subsystem1'
 * '<S10>'  : 'top_level_algo/Analog to Digital Converter/ECSoC'
 * '<S11>'  : 'top_level_algo/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S12>'  : 'top_level_algo/Compression Detection/Chart'
 * '<S13>'  : 'top_level_algo/Digital Port Write4/ECSoC'
 * '<S14>'  : 'top_level_algo/Digital Port Write4/ECSoC/ECSimCodegen'
 * '<S15>'  : 'top_level_algo/Digital Port Write5/ECSoC'
 * '<S16>'  : 'top_level_algo/Digital Port Write5/ECSoC/ECSimCodegen'
 * '<S17>'  : 'top_level_algo/Direction /Long range motion down'
 * '<S18>'  : 'top_level_algo/Direction /Long range motion up'
 * '<S19>'  : 'top_level_algo/Direction /Negative'
 * '<S20>'  : 'top_level_algo/Direction /Positive'
 * '<S21>'  : 'top_level_algo/Hardware Hiding/force min to zero'
 * '<S22>'  : 'top_level_algo/Hardware Hiding/timer'
 * '<S23>'  : 'top_level_algo/Hardware Hiding/force min to zero/If Action Subsystem'
 * '<S24>'  : 'top_level_algo/Hardware Hiding/force min to zero/If Action Subsystem1'
 * '<S25>'  : 'top_level_algo/LED_display/Compare To Constant'
 * '<S26>'  : 'top_level_algo/LED_display/Compare To Constant1'
 * '<S27>'  : 'top_level_algo/LED_display/Compare To Constant2'
 * '<S28>'  : 'top_level_algo/LED_display/Compare To Constant3'
 * '<S29>'  : 'top_level_algo/LED_display/Compare To Constant4'
 * '<S30>'  : 'top_level_algo/LED_display/Digital Port Write'
 * '<S31>'  : 'top_level_algo/LED_display/Digital Port Write2'
 * '<S32>'  : 'top_level_algo/LED_display/Digital Port Write4'
 * '<S33>'  : 'top_level_algo/LED_display/Digital Port Write/ECSoC'
 * '<S34>'  : 'top_level_algo/LED_display/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S35>'  : 'top_level_algo/LED_display/Digital Port Write2/ECSoC'
 * '<S36>'  : 'top_level_algo/LED_display/Digital Port Write2/ECSoC/ECSimCodegen'
 * '<S37>'  : 'top_level_algo/LED_display/Digital Port Write4/ECSoC'
 * '<S38>'  : 'top_level_algo/LED_display/Digital Port Write4/ECSoC/ECSimCodegen'
 * '<S39>'  : 'top_level_algo/MinMax/Max (BDC)'
 * '<S40>'  : 'top_level_algo/MinMax/Min (BDC)'
 * '<S41>'  : 'top_level_algo/MinMax/force min to zero'
 * '<S42>'  : 'top_level_algo/MinMax/sample and hold'
 * '<S43>'  : 'top_level_algo/MinMax/sample and hold1'
 * '<S44>'  : 'top_level_algo/MinMax/Max (BDC)/Subsystem'
 * '<S45>'  : 'top_level_algo/MinMax/Min (BDC)/Subsystem'
 * '<S46>'  : 'top_level_algo/MinMax/force min to zero/If Action Subsystem'
 * '<S47>'  : 'top_level_algo/MinMax/force min to zero/If Action Subsystem1'
 * '<S48>'  : 'top_level_algo/Subsystem1/HR Encoding'
 * '<S49>'  : 'top_level_algo/Subsystem1/Subsystem'
 * '<S50>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder'
 * '<S51>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder1'
 * '<S52>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder2'
 * '<S53>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder/If Action Subsystem'
 * '<S54>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder/If Action Subsystem1'
 * '<S55>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder/If Action Subsystem10'
 * '<S56>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder/If Action Subsystem2'
 * '<S57>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder/If Action Subsystem3'
 * '<S58>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder/If Action Subsystem4'
 * '<S59>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder/If Action Subsystem5'
 * '<S60>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder/If Action Subsystem6'
 * '<S61>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder/If Action Subsystem7'
 * '<S62>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder/If Action Subsystem8'
 * '<S63>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder1/If Action Subsystem'
 * '<S64>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder1/If Action Subsystem1'
 * '<S65>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder1/If Action Subsystem10'
 * '<S66>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder1/If Action Subsystem2'
 * '<S67>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder1/If Action Subsystem3'
 * '<S68>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder1/If Action Subsystem4'
 * '<S69>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder1/If Action Subsystem5'
 * '<S70>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder1/If Action Subsystem6'
 * '<S71>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder1/If Action Subsystem7'
 * '<S72>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder1/If Action Subsystem8'
 * '<S73>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder2/If Action Subsystem'
 * '<S74>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder2/If Action Subsystem1'
 * '<S75>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder2/If Action Subsystem10'
 * '<S76>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder2/If Action Subsystem2'
 * '<S77>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder2/If Action Subsystem3'
 * '<S78>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder2/If Action Subsystem4'
 * '<S79>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder2/If Action Subsystem5'
 * '<S80>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder2/If Action Subsystem6'
 * '<S81>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder2/If Action Subsystem7'
 * '<S82>'  : 'top_level_algo/Subsystem1/HR Encoding/7seg encoder2/If Action Subsystem8'
 * '<S83>'  : 'top_level_algo/Subsystem1/Subsystem/ClockLogic'
 * '<S84>'  : 'top_level_algo/Subsystem1/Subsystem/DataLogic'
 */
#endif                                 /* RTW_HEADER_top_level_algo_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
