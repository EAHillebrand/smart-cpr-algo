/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo.h
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 3.56
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Apr  8 20:58:24 2023
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
#include "MW_arduino_digitalio.h"
#include "MW_AnalogIn.h"
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

/* Block states (default storage) for system '<S11>/sample and hold' */
typedef struct {
  uint8_T is_c1_top_level_algo;        /* '<S11>/sample and hold' */
  uint8_T is_active_c1_top_level_algo; /* '<S11>/sample and hold' */
} DW_sampleandhold_top_level_al_T;

/* Block signals (default storage) */
typedef struct {
  real_T TappedDelay[20];              /* '<S8>/Tapped Delay' */
  MW_AnalogIn_ResultDataType_Type datatype_id;
  real_T TmpRTBAtModeOutport3;         /* '<Root>/Mode' */
  real_T TmpRTBAtModeOutport2;         /* '<Root>/Mode' */
  real_T Max;                          /* '<S11>/sample and hold' */
  real_T evaluating;                   /* '<Root>/Mode' */
  real_T Product;                      /* '<S9>/Product' */
  real_T TmpRTBAtModeOutport1;         /* '<Root>/Mode' */
  real_T u0Diff;                       /* '<S8>/30 Diff' */
  real_T depth_ctrl;                   /* '<Root>/Mode' */
  real_T recoil_ctrl;                  /* '<Root>/Mode' */
  real_T seven_seg_ctrl;               /* '<Root>/Mode' */
  real_T evaluating_h;                 /* '<Root>/Mode' */
  real_T displacement;                 /* '<S11>/sample and hold1' */
  real_T displacement_a;               /* '<S11>/sample and hold' */
  real_T baseline;                     /* '<S9>/timer' */
  real_T rate;                         /* '<S5>/Chart1' */
  real_T recoil_active;                /* '<S5>/Chart1' */
  real_T Merge;                        /* '<S70>/Merge' */
  real_T Mean1_AccVal;
  real_T rtb_Switch_j_idx_1;
  real_T rtb_Switch_j_idx_2;
  real_T rtb_Switch_j_idx_3;
  real_T u;
  real_T u_m;
  uint32_T data;                       /* '<S14>/DataLogic' */
  real32_T CastToSingle2;              /* '<Root>/Cast To Single2' */
  boolean_T TmpRTBAtChart1Inport2;
  boolean_T TmpRTBAtSummarizingInport7;
} B_top_level_algo_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input' */
  codertarget_arduinobase_blo_o_T obj_d;/* '<Root>/Digital Input' */
  codertarget_arduinobase_block_T obj_b;/* '<S13>/Digital Output9' */
  codertarget_arduinobase_block_T obj_m;/* '<S13>/Digital Output8' */
  codertarget_arduinobase_block_T obj_f;/* '<Root>/Digital Output10' */
  codertarget_arduinobase_block_T obj_do;/* '<S6>/Digital Output7' */
  codertarget_arduinobase_block_T obj_p;/* '<S6>/Digital Output6' */
  codertarget_arduinobase_block_T obj_j;/* '<S6>/Digital Output5' */
  codertarget_arduinobase_block_T obj_k;/* '<S6>/Digital Output4' */
  codertarget_arduinobase_block_T obj_l;/* '<S2>/Digital Output3' */
  codertarget_arduinobase_block_T obj_a;/* '<S2>/Digital Output2' */
  real_T Delay_DSTATE[4];              /* '<S79>/Delay' */
  real_T Delay_DSTATE_d[4];            /* '<S14>/Delay' */
  real_T TappedDelay1_X[20];           /* '<S9>/Tapped Delay1' */
  real_T Delay_DSTATE_dt;              /* '<S8>/Delay' */
  real_T Delay1_DSTATE[2];             /* '<S8>/Delay1' */
  real_T Delay2_DSTATE[3];             /* '<S8>/Delay2' */
  real_T Delay3_DSTATE[4];             /* '<S8>/Delay3' */
  real_T Delay4_DSTATE[5];             /* '<S8>/Delay4' */
  real_T Delay5_DSTATE[10];            /* '<S8>/Delay5' */
  real_T TappedDelay_X[10];            /* '<S8>/Tapped Delay' */
  real_T TmpRTBAtModeOutport3_Buffer0; /* synthesized block */
  real_T TmpRTBAtModeOutport2_Buffer0; /* synthesized block */
  real_T Max_Buffer0;                  /* synthesized block */
  real_T evaluating_Buffer0;           /* synthesized block */
  real_T TmpRTBAtModeOutport1_Buffer0; /* synthesized block */
  real_T Memory_PreviousInput;         /* '<S73>/Memory' */
  real_T Memory_PreviousInput_m;       /* '<S74>/Memory' */
  real_T rates;                        /* '<Root>/Summarizing' */
  real_T comps;                        /* '<Root>/Summarizing' */
  real_T recoils;                      /* '<Root>/Summarizing' */
  real_T depths;                       /* '<Root>/Summarizing' */
  real_T max_r;                        /* '<Root>/Summarizing' */
  real_T min_d;                        /* '<Root>/Summarizing' */
  real_T rate_sum;                     /* '<Root>/Summarizing' */
  real_T min_r;                        /* '<Root>/Summarizing' */
  real_T max_d;                        /* '<Root>/Summarizing' */
  real_T depth_sum;                    /* '<Root>/Summarizing' */
  real_T old_cpm;                      /* '<S14>/Write Logic' */
  real_T lastTs;                       /* '<S5>/Chart1' */
  real32_T TappedDelay_X_f[10];        /* '<S9>/Tapped Delay' */
  int32_T clockTickCounter;            /* '<S14>/Pulse Generator' */
  uint32_T temporalCounter_i1;         /* '<Root>/Summarizing' */
  uint32_T Holder;                     /* '<S14>/DataLogic' */
  uint32_T temporalCounter_i1_i;       /* '<S14>/DataLogic' */
  uint16_T temporalCounter_i1_f;       /* '<S14>/Write Logic' */
  uint16_T temporalCounter_i1_ir;      /* '<Root>/Mode' */
  uint16_T temporalCounter_i1_c;       /* '<S9>/timer' */
  uint16_T temporalCounter_i1_o;       /* '<S5>/Chart1' */
  boolean_T Delay8_DSTATE[288];        /* '<S14>/Delay8' */
  boolean_T Delay7_DSTATE;             /* '<S14>/Delay7' */
  boolean_T Delay8_DSTATE_b[2];        /* '<S11>/Delay8' */
  boolean_T Delay7_DSTATE_l;           /* '<S11>/Delay7' */
  boolean_T Delay6_DSTATE[2];          /* '<S11>/Delay6' */
  boolean_T Delay4_DSTATE_a[2];        /* '<S11>/Delay4' */
  boolean_T Delay1_DSTATE_m;           /* '<S11>/Delay1' */
  boolean_T Delay3_DSTATE_m[2];        /* '<S11>/Delay3' */
  boolean_T Delay_DSTATE_a[5];         /* '<S11>/Delay' */
  boolean_T Delay2_DSTATE_m[5];        /* '<S11>/Delay2' */
  uint8_T is_c20_top_level_algo;       /* '<Root>/Summarizing' */
  uint8_T is_EVALUATING;               /* '<Root>/Summarizing' */
  uint8_T is_active_c20_top_level_algo;/* '<Root>/Summarizing' */
  uint8_T is_c19_top_level_algo;       /* '<S14>/Write Logic' */
  uint8_T is_active_c19_top_level_algo;/* '<S14>/Write Logic' */
  uint8_T is_c15_top_level_algo;       /* '<S14>/DataLogic' */
  uint8_T is_active_c15_top_level_algo;/* '<S14>/DataLogic' */
  uint8_T is_c16_top_level_algo;       /* '<Root>/Mode' */
  uint8_T is_active_c16_top_level_algo;/* '<Root>/Mode' */
  uint8_T is_c3_top_level_algo;        /* '<S9>/timer' */
  uint8_T is_active_c3_top_level_algo; /* '<S9>/timer' */
  uint8_T is_c12_top_level_algo;       /* '<S5>/Chart1' */
  uint8_T is_active_c12_top_level_algo;/* '<S5>/Chart1' */
  boolean_T TmpRTBAtChart1Inport2_Buffer0;/* synthesized block */
  boolean_T TmpRTBAtSummarizingInport7_Buff;/* synthesized block */
  DW_sampleandhold_top_level_al_T sf_sampleandhold1;/* '<S11>/sample and hold1' */
  DW_sampleandhold_top_level_al_T sf_sampleandhold;/* '<S11>/sample and hold' */
} DW_top_level_algo_T;

/* Parameters for system: '<S20>/If Action Subsystem' */
struct P_IfActionSubsystem_top_level_T_ {
  uint8_T Constant_Value;              /* Expression: 0x3F
                                        * Referenced by: '<S23>/Constant'
                                        */
};

/* Parameters (default storage) */
struct P_top_level_algo_T_ {
  real_T Vdd;                          /* Variable: Vdd
                                        * Referenced by:
                                        *   '<S9>/Constant'
                                        *   '<S9>/rad  per volt'
                                        */
  real_T gear_ratio;                   /* Variable: gear_ratio
                                        * Referenced by: '<S9>/Gear Down'
                                        */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S17>/Constant'
                                       */
  real_T CompareToConstant_const_g; /* Mask Parameter: CompareToConstant_const_g
                                     * Referenced by: '<S4>/Constant'
                                     */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S81>/Constant'
                                      */
  real_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S82>/Constant'
                                      */
  real_T CompareToConstant1_const_k;
                                   /* Mask Parameter: CompareToConstant1_const_k
                                    * Referenced by: '<S56>/Constant'
                                    */
  real_T CompareToConstant2_const_h;
                                   /* Mask Parameter: CompareToConstant2_const_h
                                    * Referenced by: '<S57>/Constant'
                                    */
  real_T CompareToConstant3_const;   /* Mask Parameter: CompareToConstant3_const
                                      * Referenced by: '<S58>/Constant'
                                      */
  real_T CompareToConstant4_const;   /* Mask Parameter: CompareToConstant4_const
                                      * Referenced by: '<S59>/Constant'
                                      */
  real_T Positive_const;               /* Mask Parameter: Positive_const
                                        * Referenced by: '<S63>/Constant'
                                        */
  real_T Longrangemotionup_const;     /* Mask Parameter: Longrangemotionup_const
                                       * Referenced by: '<S61>/Constant'
                                       */
  real_T Negative_const;               /* Mask Parameter: Negative_const
                                        * Referenced by: '<S62>/Constant'
                                        */
  real_T Longrangemotiondown_const; /* Mask Parameter: Longrangemotiondown_const
                                     * Referenced by: '<S60>/Constant'
                                     */
  real_T MaxBDC_vinit;                 /* Mask Parameter: MaxBDC_vinit
                                        * Referenced by:
                                        *   '<S73>/Initial Condition'
                                        *   '<S73>/Memory'
                                        */
  real_T MinBDC_vinit;                 /* Mask Parameter: MinBDC_vinit
                                        * Referenced by:
                                        *   '<S74>/Initial Condition'
                                        *   '<S74>/Memory'
                                        */
  real_T TappedDelay1_vinit;           /* Mask Parameter: TappedDelay1_vinit
                                        * Referenced by: '<S9>/Tapped Delay1'
                                        */
  real_T TappedDelay_vinit;            /* Mask Parameter: TappedDelay_vinit
                                        * Referenced by: '<S8>/Tapped Delay'
                                        */
  real32_T CompareToConstant_const_f;
                                    /* Mask Parameter: CompareToConstant_const_f
                                     * Referenced by: '<S80>/Constant'
                                     */
  real32_T TappedDelay_vinit_l;        /* Mask Parameter: TappedDelay_vinit_l
                                        * Referenced by: '<S9>/Tapped Delay'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T AnalogInput_SampleTime;       /* Expression: 0.005
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T Constant2_Value[4];           /* Expression: [0,0,0,0]
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T DigitalInput_SampleTime;      /* Expression: 0.05
                                        * Referenced by: '<Root>/Digital Input'
                                        */
  real_T Constant_Value[2];            /* Expression: [0,0]
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S3>/Switch'
                                        */
  real_T Constant3_Value[2];           /* Expression: [0,0]
                                        * Referenced by: '<S13>/Constant3'
                                        */
  real_T Constant_Value_g;             /* Expression: 0
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T Constant1_Value_b;            /* Expression: 0
                                        * Referenced by: '<S79>/Constant1'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S79>/Constant'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S79>/Delay'
                                        */
  real_T Delay_InitialCondition_n;     /* Expression: 0.0
                                        * Referenced by: '<S14>/Delay'
                                        */
  real_T Constant1_Value_j;            /* Expression: 100
                                        * Referenced by: '<S19>/Constant1'
                                        */
  real_T Constant2_Value_c;            /* Expression: 10
                                        * Referenced by: '<S19>/Constant2'
                                        */
  real_T TmpRTBAtModeOutport3_InitialCon;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S1>/Switch2'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S14>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<S14>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<S14>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 2
                                        * Referenced by: '<S14>/Pulse Generator'
                                        */
  real_T TmpRTBAtModeOutport2_InitialCon;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S13>/Switch1'
                                        */
  real_T Max_InitialCondition;         /* Expression: 0
                                        * Referenced by:
                                        */
  real_T evaluating_InitialCondition;  /* Expression: 0
                                        * Referenced by:
                                        */
  real_T Constant1_Value_d;            /* Expression: 4095
                                        * Referenced by: '<S9>/Constant1'
                                        */
  real_T Switch_Threshold_c;           /* Expression: 0
                                        * Referenced by: '<S9>/Switch'
                                        */
  real_T Radiusmm_Gain;                /* Expression: 103
                                        * Referenced by: '<S9>/Radius (mm)'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S64>/Constant'
                                        */
  real_T TmpRTBAtModeOutport1_InitialCon;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Switch_Threshold_j;           /* Expression: 0
                                        * Referenced by: '<S6>/Switch'
                                        */
  real_T Delay_InitialCondition_m;     /* Expression: 0.0
                                        * Referenced by: '<S8>/Delay'
                                        */
  real_T Gain_Gain;                    /* Expression: 2
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S8>/Delay1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 2
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S8>/Delay2'
                                        */
  real_T Delay3_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S8>/Delay3'
                                        */
  real_T Delay4_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S8>/Delay4'
                                        */
  real_T Delay5_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S8>/Delay5'
                                        */
  real_T CompressionSensitivity_Gain;  /* Expression: 0.5
                                        * Referenced by: '<S8>/Compression  Sensitivity'
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S70>/Constant'
                                        */
  boolean_T Constant_Value_p;          /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S10>/Constant'
                                        */
  boolean_T Delay8_InitialCondition;
                                  /* Computed Parameter: Delay8_InitialCondition
                                   * Referenced by: '<S14>/Delay8'
                                   */
  boolean_T Delay7_InitialCondition;
                                  /* Computed Parameter: Delay7_InitialCondition
                                   * Referenced by: '<S14>/Delay7'
                                   */
  boolean_T TmpRTBAtChart1Inport2_InitialCo;
                          /* Computed Parameter: TmpRTBAtChart1Inport2_InitialCo
                           * Referenced by:
                           */
  boolean_T TmpRTBAtSummarizingInport7_Init;
                          /* Computed Parameter: TmpRTBAtSummarizingInport7_Init
                           * Referenced by:
                           */
  boolean_T Delay8_InitialCondition_o;
                                /* Computed Parameter: Delay8_InitialCondition_o
                                 * Referenced by: '<S11>/Delay8'
                                 */
  boolean_T Delay7_InitialCondition_o;
                                /* Computed Parameter: Delay7_InitialCondition_o
                                 * Referenced by: '<S11>/Delay7'
                                 */
  boolean_T Delay6_InitialCondition;
                                  /* Computed Parameter: Delay6_InitialCondition
                                   * Referenced by: '<S11>/Delay6'
                                   */
  boolean_T Delay4_InitialCondition_f;
                                /* Computed Parameter: Delay4_InitialCondition_f
                                 * Referenced by: '<S11>/Delay4'
                                 */
  boolean_T Delay1_InitialCondition_d;
                                /* Computed Parameter: Delay1_InitialCondition_d
                                 * Referenced by: '<S11>/Delay1'
                                 */
  boolean_T Delay3_InitialCondition_k;
                                /* Computed Parameter: Delay3_InitialCondition_k
                                 * Referenced by: '<S11>/Delay3'
                                 */
  boolean_T Delay_InitialCondition_d;
                                 /* Computed Parameter: Delay_InitialCondition_d
                                  * Referenced by: '<S11>/Delay'
                                  */
  boolean_T Delay2_InitialCondition_c;
                                /* Computed Parameter: Delay2_InitialCondition_c
                                 * Referenced by: '<S11>/Delay2'
                                 */
  uint8_T Merge_InitialOutput;        /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S22>/Merge'
                                       */
  uint8_T Merge_InitialOutput_o;    /* Computed Parameter: Merge_InitialOutput_o
                                     * Referenced by: '<S21>/Merge'
                                     */
  uint8_T Merge_InitialOutput_e;    /* Computed Parameter: Merge_InitialOutput_e
                                     * Referenced by: '<S20>/Merge'
                                     */
  P_IfActionSubsystem_top_level_T IfActionSubsystem9_j;/* '<S22>/If Action Subsystem9' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem10_n;/* '<S22>/If Action Subsystem10' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem8_g;/* '<S22>/If Action Subsystem8' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem7_o;/* '<S22>/If Action Subsystem7' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem6_f;/* '<S22>/If Action Subsystem6' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem5_j;/* '<S22>/If Action Subsystem5' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem4_k;/* '<S22>/If Action Subsystem4' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem3_m;/* '<S22>/If Action Subsystem3' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem2_b;/* '<S22>/If Action Subsystem2' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem1_i;/* '<S22>/If Action Subsystem1' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem_a;/* '<S22>/If Action Subsystem' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem9_m;/* '<S21>/If Action Subsystem9' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem10_d;/* '<S21>/If Action Subsystem10' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem8_j;/* '<S21>/If Action Subsystem8' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem7_j;/* '<S21>/If Action Subsystem7' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem6_h;/* '<S21>/If Action Subsystem6' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem5_b;/* '<S21>/If Action Subsystem5' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem4_b;/* '<S21>/If Action Subsystem4' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem3_h;/* '<S21>/If Action Subsystem3' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem2_e;/* '<S21>/If Action Subsystem2' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem1_l;/* '<S21>/If Action Subsystem1' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem_f;/* '<S21>/If Action Subsystem' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem9;/* '<S20>/If Action Subsystem9' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem10;/* '<S20>/If Action Subsystem10' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem8;/* '<S20>/If Action Subsystem8' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem7;/* '<S20>/If Action Subsystem7' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem6;/* '<S20>/If Action Subsystem6' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem5;/* '<S20>/If Action Subsystem5' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem4;/* '<S20>/If Action Subsystem4' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem3;/* '<S20>/If Action Subsystem3' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem2;/* '<S20>/If Action Subsystem2' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem1;/* '<S20>/If Action Subsystem1' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem;/* '<S20>/If Action Subsystem' */
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
 * Block '<S19>/Display1' : Unused code path elimination
 * Block '<S19>/Display2' : Unused code path elimination
 * Block '<S8>/Scope' : Unused code path elimination
 * Block '<Root>/Display2' : Unused code path elimination
 * Block '<Root>/Gain' : Unused code path elimination
 * Block '<S68>/Data Type Duplicate' : Unused code path elimination
 * Block '<S73>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<S69>/Data Type Duplicate' : Unused code path elimination
 * Block '<S74>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope10' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<Root>/Scope3' : Unused code path elimination
 * Block '<S14>/Scope' : Unused code path elimination
 * Block '<S14>/Scope1' : Unused code path elimination
 * Block '<S14>/Scope12' : Unused code path elimination
 * Block '<S14>/Scope2' : Unused code path elimination
 * Block '<S14>/Scope3' : Unused code path elimination
 * Block '<S19>/Shift Arithmetic' : Eliminated trivial shift
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
 * '<S1>'   : 'top_level_algo/7 Seg Switch'
 * '<S2>'   : 'top_level_algo/7seg GPIO'
 * '<S3>'   : 'top_level_algo/Check Recoil'
 * '<S4>'   : 'top_level_algo/Compare To Constant'
 * '<S5>'   : 'top_level_algo/Compression Detection'
 * '<S6>'   : 'top_level_algo/Depth GPIO '
 * '<S7>'   : 'top_level_algo/Depth ctrl'
 * '<S8>'   : 'top_level_algo/Direction '
 * '<S9>'   : 'top_level_algo/Hardware Hiding'
 * '<S10>'  : 'top_level_algo/IsNonZero'
 * '<S11>'  : 'top_level_algo/MinMax'
 * '<S12>'  : 'top_level_algo/Mode'
 * '<S13>'  : 'top_level_algo/Recoil GPIO'
 * '<S14>'  : 'top_level_algo/Sped up 7seg Driver'
 * '<S15>'  : 'top_level_algo/Subsystem1'
 * '<S16>'  : 'top_level_algo/Summarizing'
 * '<S17>'  : 'top_level_algo/Check Recoil/Compare To Constant'
 * '<S18>'  : 'top_level_algo/Compression Detection/Chart1'
 * '<S19>'  : 'top_level_algo/Compression Detection/HR Encoding'
 * '<S20>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder'
 * '<S21>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1'
 * '<S22>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2'
 * '<S23>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem'
 * '<S24>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem1'
 * '<S25>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem10'
 * '<S26>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem2'
 * '<S27>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem3'
 * '<S28>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem4'
 * '<S29>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem5'
 * '<S30>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem6'
 * '<S31>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem7'
 * '<S32>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem8'
 * '<S33>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem9'
 * '<S34>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem'
 * '<S35>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem1'
 * '<S36>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem10'
 * '<S37>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem2'
 * '<S38>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem3'
 * '<S39>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem4'
 * '<S40>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem5'
 * '<S41>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem6'
 * '<S42>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem7'
 * '<S43>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem8'
 * '<S44>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem9'
 * '<S45>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem'
 * '<S46>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem1'
 * '<S47>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem10'
 * '<S48>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem2'
 * '<S49>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem3'
 * '<S50>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem4'
 * '<S51>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem5'
 * '<S52>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem6'
 * '<S53>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem7'
 * '<S54>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem8'
 * '<S55>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem9'
 * '<S56>'  : 'top_level_algo/Depth ctrl/Compare To Constant1'
 * '<S57>'  : 'top_level_algo/Depth ctrl/Compare To Constant2'
 * '<S58>'  : 'top_level_algo/Depth ctrl/Compare To Constant3'
 * '<S59>'  : 'top_level_algo/Depth ctrl/Compare To Constant4'
 * '<S60>'  : 'top_level_algo/Direction /Long range motion down'
 * '<S61>'  : 'top_level_algo/Direction /Long range motion up'
 * '<S62>'  : 'top_level_algo/Direction /Negative'
 * '<S63>'  : 'top_level_algo/Direction /Positive'
 * '<S64>'  : 'top_level_algo/Hardware Hiding/force min to zero'
 * '<S65>'  : 'top_level_algo/Hardware Hiding/timer'
 * '<S66>'  : 'top_level_algo/Hardware Hiding/force min to zero/If Action Subsystem'
 * '<S67>'  : 'top_level_algo/Hardware Hiding/force min to zero/If Action Subsystem1'
 * '<S68>'  : 'top_level_algo/MinMax/Max (BDC)'
 * '<S69>'  : 'top_level_algo/MinMax/Min (BDC)'
 * '<S70>'  : 'top_level_algo/MinMax/force min to zero'
 * '<S71>'  : 'top_level_algo/MinMax/sample and hold'
 * '<S72>'  : 'top_level_algo/MinMax/sample and hold1'
 * '<S73>'  : 'top_level_algo/MinMax/Max (BDC)/Subsystem'
 * '<S74>'  : 'top_level_algo/MinMax/Min (BDC)/Subsystem'
 * '<S75>'  : 'top_level_algo/MinMax/force min to zero/If Action Subsystem'
 * '<S76>'  : 'top_level_algo/MinMax/force min to zero/If Action Subsystem1'
 * '<S77>'  : 'top_level_algo/Sped up 7seg Driver/DataLogic'
 * '<S78>'  : 'top_level_algo/Sped up 7seg Driver/Write Logic'
 * '<S79>'  : 'top_level_algo/Sped up 7seg Driver/clk'
 * '<S80>'  : 'top_level_algo/Sped up 7seg Driver/clk/Compare To Constant'
 * '<S81>'  : 'top_level_algo/Subsystem1/Compare To Constant1'
 * '<S82>'  : 'top_level_algo/Subsystem1/Compare To Constant2'
 */
#endif                                 /* RTW_HEADER_top_level_algo_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
