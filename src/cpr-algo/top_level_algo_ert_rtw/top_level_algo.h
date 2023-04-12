/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo.h
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

#ifndef RTW_HEADER_top_level_algo_h_
#define RTW_HEADER_top_level_algo_h_
#ifndef top_level_algo_COMMON_INCLUDES_
#define top_level_algo_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#include "MW_AnalogIn.h"
#include "MW_ArduinoBLE.h"
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

/* Block states (default storage) for system '<S12>/sample and hold' */
typedef struct {
  uint8_T is_c1_top_level_algo;        /* '<S12>/sample and hold' */
  uint8_T is_active_c1_top_level_algo; /* '<S12>/sample and hold' */
} DW_sampleandhold_top_level_al_T;

/* Block signals (default storage) */
typedef struct {
  real_T TappedDelay[20];              /* '<S9>/Tapped Delay' */
  char_T b[37];
  MW_AnalogIn_ResultDataType_Type datatype_id;
  real_T TmpRTBAtModeOutport3;         /* '<Root>/Mode' */
  real_T evaluating;                   /* '<Root>/Mode' */
  real_T Max;                          /* '<S12>/sample and hold' */
  real_T VectorConcatenate[10];        /* '<Root>/Vector Concatenate' */
  real_T TmpRTBAtModeOutport2;         /* '<Root>/Mode' */
  real_T Product;                      /* '<S10>/Product' */
  real_T TmpRTBAtModeOutport1;         /* '<Root>/Mode' */
  real_T u0Diff;                       /* '<S9>/30 Diff' */
  real_T depth_ctrl;                   /* '<Root>/Mode' */
  real_T recoil_ctrl;                  /* '<Root>/Mode' */
  real_T seven_seg_ctrl;               /* '<Root>/Mode' */
  real_T evaluating_h;                 /* '<Root>/Mode' */
  real_T displacement;                 /* '<S12>/sample and hold1' */
  real_T displacement_a;               /* '<S12>/sample and hold' */
  real_T baseline;                     /* '<S10>/timer' */
  real_T rate;                         /* '<S6>/Chart1' */
  real_T recoil_active;                /* '<S6>/Chart1' */
  real_T Merge;                        /* '<S74>/Merge' */
  real_T Mean1_AccVal;
  real_T rtb_Switch_j_idx_1;
  real_T rtb_Switch_j_idx_2;
  real_T rtb_Switch_j_idx_3;
  real_T u;
  real_T u_m;
  real_T TmpMLSysMemLayoutBufferAt_p;/* '<S20>/Divide by Constant and Round1' */
  real_T Mod1;                         /* '<S20>/Mod1' */
  uint32_T data;                       /* '<S15>/DataLogic' */
  real32_T CastToSingle2;              /* '<Root>/Cast To Single2' */
  boolean_T TmpRTBAtChart1Inport2;
  boolean_T TmpRTBAtSummarizingInport7;
} B_top_level_algo_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input' */
  codertarget_arduinobase_blo_o_T obj_d;/* '<Root>/Digital Input' */
  codertarget_arduinobase_block_T obj_b;/* '<S14>/Digital Output9' */
  codertarget_arduinobase_block_T obj_m;/* '<S14>/Digital Output8' */
  codertarget_arduinobase_block_T obj_f;/* '<Root>/Digital Output10' */
  codertarget_arduinobase_block_T obj_do;/* '<S7>/Digital Output7' */
  codertarget_arduinobase_block_T obj_p;/* '<S7>/Digital Output6' */
  codertarget_arduinobase_block_T obj_j;/* '<S7>/Digital Output5' */
  codertarget_arduinobase_block_T obj_k;/* '<S7>/Digital Output4' */
  codertarget_arduinobase_block_T obj_l;/* '<S2>/Digital Output3' */
  codertarget_arduinobase_block_T obj_a;/* '<S2>/Digital Output2' */
  real_T Delay_DSTATE[4];              /* '<S83>/Delay' */
  real_T Delay_DSTATE_d[4];            /* '<S15>/Delay' */
  real_T TappedDelay1_X[20];           /* '<S10>/Tapped Delay1' */
  real_T Delay_DSTATE_dt;              /* '<S9>/Delay' */
  real_T Delay1_DSTATE[2];             /* '<S9>/Delay1' */
  real_T Delay2_DSTATE[3];             /* '<S9>/Delay2' */
  real_T Delay3_DSTATE[4];             /* '<S9>/Delay3' */
  real_T Delay4_DSTATE[5];             /* '<S9>/Delay4' */
  real_T Delay5_DSTATE[10];            /* '<S9>/Delay5' */
  real_T TappedDelay_X[10];            /* '<S9>/Tapped Delay' */
  real_T TmpRTBAtModeOutport3_Buffer0; /* synthesized block */
  real_T evaluating_Buffer0;           /* synthesized block */
  real_T Max_Buffer0;                  /* synthesized block */
  real_T TmpRTBAtModeOutport2_Buffer0; /* synthesized block */
  real_T TmpRTBAtModeOutport1_Buffer0; /* synthesized block */
  real_T Memory_PreviousInput;         /* '<S77>/Memory' */
  real_T Memory_PreviousInput_m;       /* '<S78>/Memory' */
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
  real_T old_cpm;                      /* '<S15>/Write Logic' */
  real_T lastTs;                       /* '<S6>/Chart1' */
  codertarget_arduinobase_int_o_T obj_i;/* '<S3>/BLE Send13' */
  codertarget_arduinobase_int_o_T obj_pa;/* '<S3>/BLE Send12' */
  codertarget_arduinobase_int_o_T obj_fk;/* '<S3>/BLE Send11' */
  real32_T TappedDelay_X_f[10];        /* '<S10>/Tapped Delay' */
  int32_T clockTickCounter;            /* '<S15>/Pulse Generator' */
  uint32_T temporalCounter_i1;         /* '<Root>/Summarizing' */
  uint32_T Holder;                     /* '<S15>/DataLogic' */
  uint32_T temporalCounter_i1_i;       /* '<S15>/DataLogic' */
  uint16_T temporalCounter_i1_f;       /* '<S15>/Write Logic' */
  uint16_T temporalCounter_i1_ir;      /* '<Root>/Mode' */
  uint16_T temporalCounter_i1_c;       /* '<S10>/timer' */
  uint16_T temporalCounter_i1_o;       /* '<S6>/Chart1' */
  boolean_T Delay8_DSTATE[288];        /* '<S15>/Delay8' */
  boolean_T Delay7_DSTATE;             /* '<S15>/Delay7' */
  boolean_T Delay8_DSTATE_b[2];        /* '<S12>/Delay8' */
  boolean_T Delay7_DSTATE_l;           /* '<S12>/Delay7' */
  boolean_T Delay6_DSTATE[2];          /* '<S12>/Delay6' */
  boolean_T Delay4_DSTATE_a[2];        /* '<S12>/Delay4' */
  boolean_T Delay1_DSTATE_m;           /* '<S12>/Delay1' */
  boolean_T Delay3_DSTATE_m[2];        /* '<S12>/Delay3' */
  boolean_T Delay_DSTATE_a[5];         /* '<S12>/Delay' */
  boolean_T Delay2_DSTATE_m[5];        /* '<S12>/Delay2' */
  uint8_T is_c20_top_level_algo;       /* '<Root>/Summarizing' */
  uint8_T is_EVALUATING;               /* '<Root>/Summarizing' */
  uint8_T is_active_c20_top_level_algo;/* '<Root>/Summarizing' */
  uint8_T is_c19_top_level_algo;       /* '<S15>/Write Logic' */
  uint8_T is_active_c19_top_level_algo;/* '<S15>/Write Logic' */
  uint8_T is_c15_top_level_algo;       /* '<S15>/DataLogic' */
  uint8_T is_active_c15_top_level_algo;/* '<S15>/DataLogic' */
  uint8_T is_c16_top_level_algo;       /* '<Root>/Mode' */
  uint8_T is_active_c16_top_level_algo;/* '<Root>/Mode' */
  uint8_T is_c3_top_level_algo;        /* '<S10>/timer' */
  uint8_T is_active_c3_top_level_algo; /* '<S10>/timer' */
  uint8_T is_c12_top_level_algo;       /* '<S6>/Chart1' */
  uint8_T is_active_c12_top_level_algo;/* '<S6>/Chart1' */
  boolean_T TmpRTBAtChart1Inport2_Buffer0;/* synthesized block */
  boolean_T TmpRTBAtSummarizingInport7_Buff;/* synthesized block */
  DW_sampleandhold_top_level_al_T sf_sampleandhold1;/* '<S12>/sample and hold1' */
  DW_sampleandhold_top_level_al_T sf_sampleandhold;/* '<S12>/sample and hold' */
} DW_top_level_algo_T;

/* Parameters for system: '<S22>/If Action Subsystem' */
struct P_IfActionSubsystem_top_level_T_ {
  uint8_T Constant_Value;              /* Expression: 0x3F
                                        * Referenced by: '<S25>/Constant'
                                        */
};

/* Parameters (default storage) */
struct P_top_level_algo_T_ {
  real_T Vdd;                          /* Variable: Vdd
                                        * Referenced by:
                                        *   '<S10>/Constant'
                                        *   '<S10>/rad  per volt'
                                        */
  real_T gear_ratio;                   /* Variable: gear_ratio
                                        * Referenced by: '<S10>/Gear Down'
                                        */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S85>/Constant'
                                      */
  real_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S86>/Constant'
                                      */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S18>/Constant'
                                       */
  real_T CompareToConstant_const_g; /* Mask Parameter: CompareToConstant_const_g
                                     * Referenced by: '<S5>/Constant'
                                     */
  real_T CompareToConstant1_const_k;
                                   /* Mask Parameter: CompareToConstant1_const_k
                                    * Referenced by: '<S60>/Constant'
                                    */
  real_T CompareToConstant2_const_h;
                                   /* Mask Parameter: CompareToConstant2_const_h
                                    * Referenced by: '<S61>/Constant'
                                    */
  real_T CompareToConstant3_const;   /* Mask Parameter: CompareToConstant3_const
                                      * Referenced by: '<S62>/Constant'
                                      */
  real_T CompareToConstant4_const;   /* Mask Parameter: CompareToConstant4_const
                                      * Referenced by: '<S63>/Constant'
                                      */
  real_T Positive_const;               /* Mask Parameter: Positive_const
                                        * Referenced by: '<S67>/Constant'
                                        */
  real_T Longrangemotionup_const;     /* Mask Parameter: Longrangemotionup_const
                                       * Referenced by: '<S65>/Constant'
                                       */
  real_T Negative_const;               /* Mask Parameter: Negative_const
                                        * Referenced by: '<S66>/Constant'
                                        */
  real_T Longrangemotiondown_const; /* Mask Parameter: Longrangemotiondown_const
                                     * Referenced by: '<S64>/Constant'
                                     */
  real_T MaxBDC_vinit;                 /* Mask Parameter: MaxBDC_vinit
                                        * Referenced by:
                                        *   '<S77>/Initial Condition'
                                        *   '<S77>/Memory'
                                        */
  real_T MinBDC_vinit;                 /* Mask Parameter: MinBDC_vinit
                                        * Referenced by:
                                        *   '<S78>/Initial Condition'
                                        *   '<S78>/Memory'
                                        */
  real_T TappedDelay1_vinit;           /* Mask Parameter: TappedDelay1_vinit
                                        * Referenced by: '<S10>/Tapped Delay1'
                                        */
  real_T TappedDelay_vinit;            /* Mask Parameter: TappedDelay_vinit
                                        * Referenced by: '<S9>/Tapped Delay'
                                        */
  real32_T CompareToConstant_const_f;
                                    /* Mask Parameter: CompareToConstant_const_f
                                     * Referenced by: '<S84>/Constant'
                                     */
  real32_T TappedDelay_vinit_l;        /* Mask Parameter: TappedDelay_vinit_l
                                        * Referenced by: '<S10>/Tapped Delay'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T AnalogInput_SampleTime;       /* Expression: 0.005
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T Constant2_Value[4];           /* Expression: [0,0,0,0]
                                        * Referenced by: '<S7>/Constant2'
                                        */
  real_T DigitalInput_SampleTime;      /* Expression: 0.05
                                        * Referenced by: '<Root>/Digital Input'
                                        */
  real_T Constant_Value[2];            /* Expression: [0,0]
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S4>/Switch'
                                        */
  real_T Constant3_Value[2];           /* Expression: [0,0]
                                        * Referenced by: '<S14>/Constant3'
                                        */
  real_T Constant_Value_g;             /* Expression: 0
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T Constant1_Value_b;            /* Expression: 0
                                        * Referenced by: '<S83>/Constant1'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S83>/Constant'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S83>/Delay'
                                        */
  real_T Delay_InitialCondition_n;     /* Expression: 0.0
                                        * Referenced by: '<S15>/Delay'
                                        */
  real_T Constant_Value_j;             /* Expression: 253
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T Constant1_Value_j;            /* Expression: 100
                                        * Referenced by: '<S20>/Constant1'
                                        */
  real_T Constant2_Value_c;            /* Expression: 10
                                        * Referenced by: '<S20>/Constant2'
                                        */
  real_T TmpRTBAtModeOutport3_InitialCon;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S1>/Switch2'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S15>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<S15>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<S15>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 2
                                        * Referenced by: '<S15>/Pulse Generator'
                                        */
  real_T evaluating_InitialCondition;  /* Expression: 0
                                        * Referenced by:
                                        */
  real_T Max_InitialCondition;         /* Expression: 0
                                        * Referenced by:
                                        */
  real_T Constant_Value_o;             /* Expression: -1
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant1_Value_c;            /* Expression: -1
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T TmpRTBAtModeOutport2_InitialCon;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S14>/Switch1'
                                        */
  real_T Constant1_Value_d;            /* Expression: 4095
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T Switch_Threshold_c;           /* Expression: 0
                                        * Referenced by: '<S10>/Switch'
                                        */
  real_T Radiusmm_Gain;                /* Expression: 103
                                        * Referenced by: '<S10>/Radius (mm)'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S68>/Constant'
                                        */
  real_T TmpRTBAtModeOutport1_InitialCon;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Switch_Threshold_j;           /* Expression: 0
                                        * Referenced by: '<S7>/Switch'
                                        */
  real_T Delay_InitialCondition_m;     /* Expression: 0.0
                                        * Referenced by: '<S9>/Delay'
                                        */
  real_T Gain_Gain;                    /* Expression: 2
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S9>/Delay1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 2
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S9>/Delay2'
                                        */
  real_T Delay3_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S9>/Delay3'
                                        */
  real_T Delay4_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S9>/Delay4'
                                        */
  real_T Delay5_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S9>/Delay5'
                                        */
  real_T CompressionSensitivity_Gain;  /* Expression: 0.5
                                        * Referenced by: '<S9>/Compression  Sensitivity'
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S74>/Constant'
                                        */
  boolean_T Constant_Value_p;          /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S11>/Constant'
                                        */
  boolean_T Delay8_InitialCondition;
                                  /* Computed Parameter: Delay8_InitialCondition
                                   * Referenced by: '<S15>/Delay8'
                                   */
  boolean_T Delay7_InitialCondition;
                                  /* Computed Parameter: Delay7_InitialCondition
                                   * Referenced by: '<S15>/Delay7'
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
                                 * Referenced by: '<S12>/Delay8'
                                 */
  boolean_T Delay7_InitialCondition_o;
                                /* Computed Parameter: Delay7_InitialCondition_o
                                 * Referenced by: '<S12>/Delay7'
                                 */
  boolean_T Delay6_InitialCondition;
                                  /* Computed Parameter: Delay6_InitialCondition
                                   * Referenced by: '<S12>/Delay6'
                                   */
  boolean_T Delay4_InitialCondition_f;
                                /* Computed Parameter: Delay4_InitialCondition_f
                                 * Referenced by: '<S12>/Delay4'
                                 */
  boolean_T Delay1_InitialCondition_d;
                                /* Computed Parameter: Delay1_InitialCondition_d
                                 * Referenced by: '<S12>/Delay1'
                                 */
  boolean_T Delay3_InitialCondition_k;
                                /* Computed Parameter: Delay3_InitialCondition_k
                                 * Referenced by: '<S12>/Delay3'
                                 */
  boolean_T Delay_InitialCondition_d;
                                 /* Computed Parameter: Delay_InitialCondition_d
                                  * Referenced by: '<S12>/Delay'
                                  */
  boolean_T Delay2_InitialCondition_c;
                                /* Computed Parameter: Delay2_InitialCondition_c
                                 * Referenced by: '<S12>/Delay2'
                                 */
  uint8_T Merge_InitialOutput;        /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S24>/Merge'
                                       */
  uint8_T Merge_InitialOutput_o;    /* Computed Parameter: Merge_InitialOutput_o
                                     * Referenced by: '<S23>/Merge'
                                     */
  uint8_T Merge_InitialOutput_e;    /* Computed Parameter: Merge_InitialOutput_e
                                     * Referenced by: '<S22>/Merge'
                                     */
  P_IfActionSubsystem_top_level_T IfActionSubsystem9_j;/* '<S24>/If Action Subsystem9' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem10_n;/* '<S24>/If Action Subsystem10' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem8_g;/* '<S24>/If Action Subsystem8' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem7_o;/* '<S24>/If Action Subsystem7' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem6_f;/* '<S24>/If Action Subsystem6' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem5_j;/* '<S24>/If Action Subsystem5' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem4_k;/* '<S24>/If Action Subsystem4' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem3_m;/* '<S24>/If Action Subsystem3' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem2_b;/* '<S24>/If Action Subsystem2' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem1_i;/* '<S24>/If Action Subsystem1' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem_a;/* '<S24>/If Action Subsystem' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem9_m;/* '<S23>/If Action Subsystem9' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem10_d;/* '<S23>/If Action Subsystem10' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem8_j;/* '<S23>/If Action Subsystem8' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem7_j;/* '<S23>/If Action Subsystem7' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem6_h;/* '<S23>/If Action Subsystem6' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem5_b;/* '<S23>/If Action Subsystem5' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem4_b;/* '<S23>/If Action Subsystem4' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem3_h;/* '<S23>/If Action Subsystem3' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem2_e;/* '<S23>/If Action Subsystem2' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem1_l;/* '<S23>/If Action Subsystem1' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem_f;/* '<S23>/If Action Subsystem' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem9;/* '<S22>/If Action Subsystem9' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem10;/* '<S22>/If Action Subsystem10' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem8;/* '<S22>/If Action Subsystem8' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem7;/* '<S22>/If Action Subsystem7' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem6;/* '<S22>/If Action Subsystem6' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem5;/* '<S22>/If Action Subsystem5' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem4;/* '<S22>/If Action Subsystem4' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem3;/* '<S22>/If Action Subsystem3' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem2;/* '<S22>/If Action Subsystem2' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem1;/* '<S22>/If Action Subsystem1' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem;/* '<S22>/If Action Subsystem' */
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
 * Block '<S20>/Display1' : Unused code path elimination
 * Block '<S20>/Display2' : Unused code path elimination
 * Block '<S9>/Scope' : Unused code path elimination
 * Block '<Root>/Display2' : Unused code path elimination
 * Block '<Root>/Gain' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate' : Unused code path elimination
 * Block '<S77>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<S73>/Data Type Duplicate' : Unused code path elimination
 * Block '<S78>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope10' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<Root>/Scope3' : Unused code path elimination
 * Block '<S15>/Scope' : Unused code path elimination
 * Block '<S15>/Scope1' : Unused code path elimination
 * Block '<S15>/Scope12' : Unused code path elimination
 * Block '<S15>/Scope2' : Unused code path elimination
 * Block '<S15>/Scope3' : Unused code path elimination
 * Block '<S20>/Shift Arithmetic' : Eliminated trivial shift
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
 * '<S3>'   : 'top_level_algo/BLE Send'
 * '<S4>'   : 'top_level_algo/Check Recoil'
 * '<S5>'   : 'top_level_algo/Compare To Constant'
 * '<S6>'   : 'top_level_algo/Compression Detection'
 * '<S7>'   : 'top_level_algo/Depth GPIO '
 * '<S8>'   : 'top_level_algo/Depth ctrl'
 * '<S9>'   : 'top_level_algo/Direction '
 * '<S10>'  : 'top_level_algo/Hardware Hiding'
 * '<S11>'  : 'top_level_algo/IsNonZero'
 * '<S12>'  : 'top_level_algo/MinMax'
 * '<S13>'  : 'top_level_algo/Mode'
 * '<S14>'  : 'top_level_algo/Recoil GPIO'
 * '<S15>'  : 'top_level_algo/Sped up 7seg Driver'
 * '<S16>'  : 'top_level_algo/Subsystem1'
 * '<S17>'  : 'top_level_algo/Summarizing'
 * '<S18>'  : 'top_level_algo/Check Recoil/Compare To Constant'
 * '<S19>'  : 'top_level_algo/Compression Detection/Chart1'
 * '<S20>'  : 'top_level_algo/Compression Detection/HR Encoding'
 * '<S21>'  : 'top_level_algo/Compression Detection/force max to 253'
 * '<S22>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder'
 * '<S23>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1'
 * '<S24>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2'
 * '<S25>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem'
 * '<S26>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem1'
 * '<S27>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem10'
 * '<S28>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem2'
 * '<S29>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem3'
 * '<S30>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem4'
 * '<S31>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem5'
 * '<S32>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem6'
 * '<S33>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem7'
 * '<S34>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem8'
 * '<S35>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem9'
 * '<S36>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem'
 * '<S37>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem1'
 * '<S38>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem10'
 * '<S39>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem2'
 * '<S40>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem3'
 * '<S41>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem4'
 * '<S42>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem5'
 * '<S43>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem6'
 * '<S44>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem7'
 * '<S45>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem8'
 * '<S46>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem9'
 * '<S47>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem'
 * '<S48>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem1'
 * '<S49>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem10'
 * '<S50>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem2'
 * '<S51>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem3'
 * '<S52>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem4'
 * '<S53>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem5'
 * '<S54>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem6'
 * '<S55>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem7'
 * '<S56>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem8'
 * '<S57>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem9'
 * '<S58>'  : 'top_level_algo/Compression Detection/force max to 253/If Action Subsystem'
 * '<S59>'  : 'top_level_algo/Compression Detection/force max to 253/If Action Subsystem1'
 * '<S60>'  : 'top_level_algo/Depth ctrl/Compare To Constant1'
 * '<S61>'  : 'top_level_algo/Depth ctrl/Compare To Constant2'
 * '<S62>'  : 'top_level_algo/Depth ctrl/Compare To Constant3'
 * '<S63>'  : 'top_level_algo/Depth ctrl/Compare To Constant4'
 * '<S64>'  : 'top_level_algo/Direction /Long range motion down'
 * '<S65>'  : 'top_level_algo/Direction /Long range motion up'
 * '<S66>'  : 'top_level_algo/Direction /Negative'
 * '<S67>'  : 'top_level_algo/Direction /Positive'
 * '<S68>'  : 'top_level_algo/Hardware Hiding/force min to zero'
 * '<S69>'  : 'top_level_algo/Hardware Hiding/timer'
 * '<S70>'  : 'top_level_algo/Hardware Hiding/force min to zero/If Action Subsystem'
 * '<S71>'  : 'top_level_algo/Hardware Hiding/force min to zero/If Action Subsystem1'
 * '<S72>'  : 'top_level_algo/MinMax/Max (BDC)'
 * '<S73>'  : 'top_level_algo/MinMax/Min (BDC)'
 * '<S74>'  : 'top_level_algo/MinMax/force min to zero'
 * '<S75>'  : 'top_level_algo/MinMax/sample and hold'
 * '<S76>'  : 'top_level_algo/MinMax/sample and hold1'
 * '<S77>'  : 'top_level_algo/MinMax/Max (BDC)/Subsystem'
 * '<S78>'  : 'top_level_algo/MinMax/Min (BDC)/Subsystem'
 * '<S79>'  : 'top_level_algo/MinMax/force min to zero/If Action Subsystem'
 * '<S80>'  : 'top_level_algo/MinMax/force min to zero/If Action Subsystem1'
 * '<S81>'  : 'top_level_algo/Sped up 7seg Driver/DataLogic'
 * '<S82>'  : 'top_level_algo/Sped up 7seg Driver/Write Logic'
 * '<S83>'  : 'top_level_algo/Sped up 7seg Driver/clk'
 * '<S84>'  : 'top_level_algo/Sped up 7seg Driver/clk/Compare To Constant'
 * '<S85>'  : 'top_level_algo/Subsystem1/Compare To Constant1'
 * '<S86>'  : 'top_level_algo/Subsystem1/Compare To Constant2'
 */
#endif                                 /* RTW_HEADER_top_level_algo_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
