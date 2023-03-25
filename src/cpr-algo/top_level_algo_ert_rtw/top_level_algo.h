/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo.h
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 3.25
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Mar 25 13:47:25 2023
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
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* top_level_algo_COMMON_INCLUDES_ */

#include "top_level_algo_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block states (default storage) for system '<S8>/sample and hold' */
typedef struct {
  uint8_T is_c1_top_level_algo;        /* '<S8>/sample and hold' */
  uint8_T is_active_c1_top_level_algo; /* '<S8>/sample and hold' */
} DW_sampleandhold_top_level_al_T;

/* Block signals (default storage) */
typedef struct {
  real_T TappedDelay[20];              /* '<S4>/Tapped Delay' */
  MW_AnalogIn_ResultDataType_Type datatype_id;
  real_T TmpRTBAtModeOutport3;         /* '<Root>/Mode' */
  real_T Merge;                        /* '<S63>/Merge' */
  real_T TmpRTBAtModeOutport2;         /* '<Root>/Mode' */
  real_T Product;                      /* '<S5>/Product' */
  real_T TmpRTBAtModeOutport1;         /* '<Root>/Mode' */
  real_T u0Diff;                       /* '<S4>/30 Diff' */
  real_T depth_ctrl;                   /* '<Root>/Mode' */
  real_T recoil_ctrl;                  /* '<Root>/Mode' */
  real_T seven_seg_ctrl;               /* '<Root>/Mode' */
  real_T displacement;                 /* '<S8>/sample and hold1' */
  real_T baseline;                     /* '<S5>/timer' */
  real_T rate;                         /* '<S3>/Chart1' */
  real_T recoil_active;                /* '<S3>/Chart1' */
  real_T CLK;                          /* '<S11>/ClockLogic' */
  real_T Mean1_AccVal;
  real_T rtb_Switch_idx_1;
  real_T rtb_Switch_idx_2;
  real_T rtb_Switch_idx_3;
  real_T u;
  real_T u_m;
  uint32_T data;                       /* '<S11>/DataLogic' */
  uint16_T AnalogInput;                /* '<Root>/Analog Input' */
  uint8_T Merge_i;                     /* '<S12>/Merge' */
  uint8_T Merge_d;                     /* '<S13>/Merge' */
  uint8_T Merge_n;                     /* '<S14>/Merge' */
  boolean_T TmpRTBAtChart1Inport2;
} B_top_level_algo_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input' */
  codertarget_arduinobase_block_T obj_d;/* '<Root>/Digital Input' */
  codertarget_arduinobase_blo_o_T obj_b;/* '<Root>/Digital Output9' */
  codertarget_arduinobase_blo_o_T obj_m;/* '<Root>/Digital Output8' */
  codertarget_arduinobase_blo_o_T obj_do;/* '<Root>/Digital Output7' */
  codertarget_arduinobase_blo_o_T obj_p;/* '<Root>/Digital Output6' */
  codertarget_arduinobase_blo_o_T obj_j;/* '<Root>/Digital Output5' */
  codertarget_arduinobase_blo_o_T obj_k;/* '<Root>/Digital Output4' */
  codertarget_arduinobase_blo_o_T obj_l;/* '<Root>/Digital Output3' */
  codertarget_arduinobase_blo_o_T obj_a;/* '<Root>/Digital Output2' */
  real_T TappedDelay1_X[20];           /* '<S5>/Tapped Delay1' */
  real_T Delay_DSTATE;                 /* '<S4>/Delay' */
  real_T Delay1_DSTATE[2];             /* '<S4>/Delay1' */
  real_T Delay2_DSTATE[3];             /* '<S4>/Delay2' */
  real_T Delay3_DSTATE[4];             /* '<S4>/Delay3' */
  real_T Delay4_DSTATE[5];             /* '<S4>/Delay4' */
  real_T Delay5_DSTATE[10];            /* '<S4>/Delay5' */
  real_T TappedDelay_X[10];            /* '<S4>/Tapped Delay' */
  real_T TmpRTBAtModeOutport3_Buffer0; /* synthesized block */
  real_T TmpRTBAtModeOutport2_Buffer0; /* synthesized block */
  real_T TmpRTBAtModeOutport1_Buffer0; /* synthesized block */
  real_T Memory_PreviousInput;         /* '<S66>/Memory' */
  real_T Memory_PreviousInput_m;       /* '<S67>/Memory' */
  real_T lastTs;                       /* '<S3>/Chart1' */
  real_T counter;                      /* '<S11>/ClockLogic' */
  int32_T clockTickCounter;            /* '<S1>/Pulse Generator' */
  uint32_T Holder;                     /* '<S11>/DataLogic' */
  uint16_T TappedDelay_X_f[10];        /* '<S5>/Tapped Delay' */
  uint16_T temporalCounter_i1;         /* '<Root>/Mode' */
  uint16_T temporalCounter_i1_c;       /* '<S5>/timer' */
  uint16_T temporalCounter_i1_o;       /* '<S3>/Chart1' */
  boolean_T Delay8_DSTATE[2];          /* '<S8>/Delay8' */
  boolean_T Delay7_DSTATE;             /* '<S8>/Delay7' */
  boolean_T Delay6_DSTATE[2];          /* '<S8>/Delay6' */
  boolean_T Delay4_DSTATE_a[2];        /* '<S8>/Delay4' */
  boolean_T Delay1_DSTATE_m;           /* '<S8>/Delay1' */
  boolean_T Delay3_DSTATE_m[2];        /* '<S8>/Delay3' */
  boolean_T Delay_DSTATE_a[5];         /* '<S8>/Delay' */
  boolean_T Delay2_DSTATE_m[5];        /* '<S8>/Delay2' */
  uint8_T is_c16_top_level_algo;       /* '<Root>/Mode' */
  uint8_T is_active_c16_top_level_algo;/* '<Root>/Mode' */
  uint8_T is_c3_top_level_algo;        /* '<S5>/timer' */
  uint8_T is_active_c3_top_level_algo; /* '<S5>/timer' */
  uint8_T is_c12_top_level_algo;       /* '<S3>/Chart1' */
  uint8_T is_active_c12_top_level_algo;/* '<S3>/Chart1' */
  uint8_T is_c18_top_level_algo;       /* '<S11>/DataLogic' */
  uint8_T is_active_c18_top_level_algo;/* '<S11>/DataLogic' */
  uint8_T temporalCounter_i1_n;        /* '<S11>/DataLogic' */
  uint8_T is_c17_top_level_algo;       /* '<S11>/ClockLogic' */
  uint8_T is_active_c17_top_level_algo;/* '<S11>/ClockLogic' */
  uint8_T temporalCounter_i1_o2;       /* '<S11>/ClockLogic' */
  boolean_T TmpRTBAtChart1Inport2_Buffer0;/* synthesized block */
  DW_sampleandhold_top_level_al_T sf_sampleandhold1;/* '<S8>/sample and hold1' */
  DW_sampleandhold_top_level_al_T sf_sampleandhold;/* '<S8>/sample and hold' */
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
                                        *   '<S5>/Constant'
                                        *   '<S5>/rad  per volt'
                                        */
  real_T gear_ratio;                   /* Variable: gear_ratio
                                        * Referenced by: '<S5>/Gear Down'
                                        */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S47>/Constant'
                                       */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S57>/Constant'
                                      */
  real_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S58>/Constant'
                                      */
  real_T CompareToConstant3_const;   /* Mask Parameter: CompareToConstant3_const
                                      * Referenced by: '<S59>/Constant'
                                      */
  real_T CompareToConstant4_const;   /* Mask Parameter: CompareToConstant4_const
                                      * Referenced by: '<S60>/Constant'
                                      */
  real_T Positive_const;               /* Mask Parameter: Positive_const
                                        * Referenced by: '<S52>/Constant'
                                        */
  real_T Longrangemotionup_const;     /* Mask Parameter: Longrangemotionup_const
                                       * Referenced by: '<S50>/Constant'
                                       */
  real_T Negative_const;               /* Mask Parameter: Negative_const
                                        * Referenced by: '<S51>/Constant'
                                        */
  real_T Longrangemotiondown_const; /* Mask Parameter: Longrangemotiondown_const
                                     * Referenced by: '<S49>/Constant'
                                     */
  real_T MaxBDC_vinit;                 /* Mask Parameter: MaxBDC_vinit
                                        * Referenced by:
                                        *   '<S66>/Initial Condition'
                                        *   '<S66>/Memory'
                                        */
  real_T MinBDC_vinit;                 /* Mask Parameter: MinBDC_vinit
                                        * Referenced by:
                                        *   '<S67>/Initial Condition'
                                        *   '<S67>/Memory'
                                        */
  real_T TappedDelay1_vinit;           /* Mask Parameter: TappedDelay1_vinit
                                        * Referenced by: '<S5>/Tapped Delay1'
                                        */
  real_T TappedDelay_vinit;            /* Mask Parameter: TappedDelay_vinit
                                        * Referenced by: '<S4>/Tapped Delay'
                                        */
  uint16_T TappedDelay_vinit_l;        /* Mask Parameter: TappedDelay_vinit_l
                                        * Referenced by: '<S5>/Tapped Delay'
                                        */
  real_T AnalogInput_SampleTime;       /* Expression: 0.005
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T DigitalInput_SampleTime;      /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Input'
                                        */
  real_T Constant_Value[2];            /* Expression: [0,0]
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S2>/Switch'
                                        */
  real_T Constant3_Value[2];           /* Expression: [0,0]
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant2_Value[4];           /* Expression: [0,0,0,0]
                                        * Referenced by: '<Root>/Constant2'
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
  real_T TmpRTBAtModeOutport3_InitialCon;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch2'
                                        */
  real_T Constant1_Value;              /* Expression: 100
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T Constant2_Value_c;            /* Expression: 10
                                        * Referenced by: '<S10>/Constant2'
                                        */
  real_T TmpRTBAtModeOutport2_InitialCon;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch1'
                                        */
  real_T Constant1_Value_d;            /* Expression: 4095
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Switch_Threshold_c;           /* Expression: 0
                                        * Referenced by: '<S5>/Switch'
                                        */
  real_T Radiusmm_Gain;                /* Expression: 100
                                        * Referenced by: '<S5>/Radius (mm)'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S53>/Constant'
                                        */
  real_T TmpRTBAtModeOutport1_InitialCon;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Switch_Threshold_j;           /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S4>/Delay'
                                        */
  real_T Gain_Gain;                    /* Expression: 2
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S4>/Delay1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 2
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S4>/Delay2'
                                        */
  real_T Delay3_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S4>/Delay3'
                                        */
  real_T Delay4_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S4>/Delay4'
                                        */
  real_T Delay5_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S4>/Delay5'
                                        */
  real_T CompressionSensitivity_Gain;  /* Expression: 0.5
                                        * Referenced by: '<S4>/Compression  Sensitivity'
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S63>/Constant'
                                        */
  int32_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<Root>/Constant4'
                                        */
  boolean_T Constant_Value_p;          /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S6>/Constant'
                                        */
  boolean_T TmpRTBAtChart1Inport2_InitialCo;
                          /* Computed Parameter: TmpRTBAtChart1Inport2_InitialCo
                           * Referenced by:
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
  boolean_T Delay2_InitialCondition_c;
                                /* Computed Parameter: Delay2_InitialCondition_c
                                 * Referenced by: '<S8>/Delay2'
                                 */
  uint8_T Merge_InitialOutput;        /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S12>/Merge'
                                       */
  uint8_T Merge_InitialOutput_k;    /* Computed Parameter: Merge_InitialOutput_k
                                     * Referenced by: '<S13>/Merge'
                                     */
  uint8_T Merge_InitialOutput_j;    /* Computed Parameter: Merge_InitialOutput_j
                                     * Referenced by: '<S14>/Merge'
                                     */
  P_IfActionSubsystem_top_level_T IfActionSubsystem10_g1;/* '<S14>/If Action Subsystem10' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem8_n;/* '<S14>/If Action Subsystem8' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem7_e;/* '<S14>/If Action Subsystem7' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem6_l;/* '<S14>/If Action Subsystem6' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem5_e;/* '<S14>/If Action Subsystem5' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem4_o;/* '<S14>/If Action Subsystem4' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem3_e;/* '<S14>/If Action Subsystem3' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem2_f;/* '<S14>/If Action Subsystem2' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem1_m;/* '<S14>/If Action Subsystem1' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem_b;/* '<S14>/If Action Subsystem' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem10_g;/* '<S13>/If Action Subsystem10' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem8_i;/* '<S13>/If Action Subsystem8' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem7_i;/* '<S13>/If Action Subsystem7' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem6_j;/* '<S13>/If Action Subsystem6' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem5_b;/* '<S13>/If Action Subsystem5' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem4_b;/* '<S13>/If Action Subsystem4' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem3_d;/* '<S13>/If Action Subsystem3' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem2_n;/* '<S13>/If Action Subsystem2' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem1_g;/* '<S13>/If Action Subsystem1' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem_e;/* '<S13>/If Action Subsystem' */
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
      uint8_T TID[4];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
      boolean_T TID1_3;
      boolean_T TID2_3;
    } RateInteraction;

    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[4];
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
extern void top_level_algo_step2(void);
extern void top_level_algo_step3(void);
extern void top_level_algo_step(int_T tid);
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
 * Block '<S4>/Scope' : Unused code path elimination
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<Root>/Display1' : Unused code path elimination
 * Block '<Root>/Display2' : Unused code path elimination
 * Block '<Root>/Display3' : Unused code path elimination
 * Block '<Root>/Gain' : Unused code path elimination
 * Block '<S61>/Data Type Duplicate' : Unused code path elimination
 * Block '<S66>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<S62>/Data Type Duplicate' : Unused code path elimination
 * Block '<S67>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<S8>/Scope' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope10' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<Root>/Scope3' : Unused code path elimination
 * Block '<Root>/Scope4' : Unused code path elimination
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
 * '<S1>'   : 'top_level_algo/7seg Driver1'
 * '<S2>'   : 'top_level_algo/Check Recoil'
 * '<S3>'   : 'top_level_algo/Compression Detection'
 * '<S4>'   : 'top_level_algo/Direction '
 * '<S5>'   : 'top_level_algo/Hardware Hiding'
 * '<S6>'   : 'top_level_algo/IsNonZero'
 * '<S7>'   : 'top_level_algo/LED_display'
 * '<S8>'   : 'top_level_algo/MinMax'
 * '<S9>'   : 'top_level_algo/Mode'
 * '<S10>'  : 'top_level_algo/7seg Driver1/HR Encoding'
 * '<S11>'  : 'top_level_algo/7seg Driver1/Subsystem'
 * '<S12>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder'
 * '<S13>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder1'
 * '<S14>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder2'
 * '<S15>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder/If Action Subsystem'
 * '<S16>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder/If Action Subsystem1'
 * '<S17>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder/If Action Subsystem10'
 * '<S18>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder/If Action Subsystem2'
 * '<S19>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder/If Action Subsystem3'
 * '<S20>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder/If Action Subsystem4'
 * '<S21>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder/If Action Subsystem5'
 * '<S22>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder/If Action Subsystem6'
 * '<S23>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder/If Action Subsystem7'
 * '<S24>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder/If Action Subsystem8'
 * '<S25>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder1/If Action Subsystem'
 * '<S26>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder1/If Action Subsystem1'
 * '<S27>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder1/If Action Subsystem10'
 * '<S28>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder1/If Action Subsystem2'
 * '<S29>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder1/If Action Subsystem3'
 * '<S30>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder1/If Action Subsystem4'
 * '<S31>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder1/If Action Subsystem5'
 * '<S32>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder1/If Action Subsystem6'
 * '<S33>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder1/If Action Subsystem7'
 * '<S34>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder1/If Action Subsystem8'
 * '<S35>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder2/If Action Subsystem'
 * '<S36>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder2/If Action Subsystem1'
 * '<S37>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder2/If Action Subsystem10'
 * '<S38>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder2/If Action Subsystem2'
 * '<S39>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder2/If Action Subsystem3'
 * '<S40>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder2/If Action Subsystem4'
 * '<S41>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder2/If Action Subsystem5'
 * '<S42>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder2/If Action Subsystem6'
 * '<S43>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder2/If Action Subsystem7'
 * '<S44>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder2/If Action Subsystem8'
 * '<S45>'  : 'top_level_algo/7seg Driver1/Subsystem/ClockLogic'
 * '<S46>'  : 'top_level_algo/7seg Driver1/Subsystem/DataLogic'
 * '<S47>'  : 'top_level_algo/Check Recoil/Compare To Constant'
 * '<S48>'  : 'top_level_algo/Compression Detection/Chart1'
 * '<S49>'  : 'top_level_algo/Direction /Long range motion down'
 * '<S50>'  : 'top_level_algo/Direction /Long range motion up'
 * '<S51>'  : 'top_level_algo/Direction /Negative'
 * '<S52>'  : 'top_level_algo/Direction /Positive'
 * '<S53>'  : 'top_level_algo/Hardware Hiding/force min to zero'
 * '<S54>'  : 'top_level_algo/Hardware Hiding/timer'
 * '<S55>'  : 'top_level_algo/Hardware Hiding/force min to zero/If Action Subsystem'
 * '<S56>'  : 'top_level_algo/Hardware Hiding/force min to zero/If Action Subsystem1'
 * '<S57>'  : 'top_level_algo/LED_display/Compare To Constant1'
 * '<S58>'  : 'top_level_algo/LED_display/Compare To Constant2'
 * '<S59>'  : 'top_level_algo/LED_display/Compare To Constant3'
 * '<S60>'  : 'top_level_algo/LED_display/Compare To Constant4'
 * '<S61>'  : 'top_level_algo/MinMax/Max (BDC)'
 * '<S62>'  : 'top_level_algo/MinMax/Min (BDC)'
 * '<S63>'  : 'top_level_algo/MinMax/force min to zero'
 * '<S64>'  : 'top_level_algo/MinMax/sample and hold'
 * '<S65>'  : 'top_level_algo/MinMax/sample and hold1'
 * '<S66>'  : 'top_level_algo/MinMax/Max (BDC)/Subsystem'
 * '<S67>'  : 'top_level_algo/MinMax/Min (BDC)/Subsystem'
 * '<S68>'  : 'top_level_algo/MinMax/force min to zero/If Action Subsystem'
 * '<S69>'  : 'top_level_algo/MinMax/force min to zero/If Action Subsystem1'
 */
#endif                                 /* RTW_HEADER_top_level_algo_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
