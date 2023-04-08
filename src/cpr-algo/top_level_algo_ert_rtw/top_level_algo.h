/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo.h
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 3.44
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Apr  6 16:11:01 2023
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

/* Block states (default storage) for system '<S7>/sample and hold' */
typedef struct {
  uint8_T is_c1_top_level_algo;        /* '<S7>/sample and hold' */
  uint8_T is_active_c1_top_level_algo; /* '<S7>/sample and hold' */
} DW_sampleandhold_top_level_al_T;

/* Block signals (default storage) */
typedef struct {
  real_T TappedDelay[20];              /* '<S3>/Tapped Delay' */
  real_T VectorConcatenate[10];        /* '<Root>/Vector Concatenate' */
  char_T b[37];
  MW_AnalogIn_ResultDataType_Type datatype_id;
  real_T TmpRTBAtModeOutport3;         /* '<Root>/Mode' */
  real_T Merge;                        /* '<S65>/Merge' */
  real_T TmpRTBAtModeOutport2;         /* '<Root>/Mode' */
  real_T evaluating;                   /* '<Root>/Mode' */
  real_T Product;                      /* '<S4>/Product' */
  real_T TmpRTBAtModeOutport1;         /* '<Root>/Mode' */
  real_T u0Diff;                       /* '<S3>/30 Diff' */
  real_T depth_ctrl;                   /* '<Root>/Mode' */
  real_T recoil_ctrl;                  /* '<Root>/Mode' */
  real_T seven_seg_ctrl;               /* '<Root>/Mode' */
  real_T evaluating_h;                 /* '<Root>/Mode' */
  real_T displacement;                 /* '<S7>/sample and hold1' */
  real_T displacement_a;               /* '<S7>/sample and hold' */
  real_T baseline;                     /* '<S4>/timer' */
  real_T rate;                         /* '<S2>/Chart1' */
  real_T recoil_active;                /* '<S2>/Chart1' */
  real_T Mean1_AccVal;
  real_T rtb_Switch_j_idx_1;
  real_T rtb_Switch_j_idx_2;
  real_T rtb_Switch_j_idx_3;
  real_T u;
  real_T u_m;
  uint32_T data;                       /* '<S9>/DataLogic' */
  real32_T CastToSingle2;              /* '<Root>/Cast To Single2' */
  boolean_T TmpRTBAtChart1Inport2;
  boolean_T CompressionDetected;       /* '<Root>/MinMax' */
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
  codertarget_arduinobase_blo_o_T obj_f;/* '<Root>/Digital Output10' */
  real_T Delay_DSTATE[4];              /* '<S74>/Delay' */
  real_T Delay_DSTATE_d[4];            /* '<S9>/Delay' */
  real_T TappedDelay1_X[20];           /* '<S4>/Tapped Delay1' */
  real_T Delay_DSTATE_dt;              /* '<S3>/Delay' */
  real_T Delay1_DSTATE[2];             /* '<S3>/Delay1' */
  real_T Delay2_DSTATE[3];             /* '<S3>/Delay2' */
  real_T Delay3_DSTATE[4];             /* '<S3>/Delay3' */
  real_T Delay4_DSTATE[5];             /* '<S3>/Delay4' */
  real_T Delay5_DSTATE[10];            /* '<S3>/Delay5' */
  real_T TappedDelay_X[10];            /* '<S3>/Tapped Delay' */
  real_T TmpRTBAtModeOutport3_Buffer0; /* synthesized block */
  real_T TmpRTBAtModeOutport2_Buffer0; /* synthesized block */
  real_T evaluating_Buffer0;           /* synthesized block */
  real_T TmpRTBAtModeOutport1_Buffer0; /* synthesized block */
  real_T Memory_PreviousInput;         /* '<S68>/Memory' */
  real_T Memory_PreviousInput_m;       /* '<S69>/Memory' */
  real_T rates;                        /* '<Root>/Summarizing' */
  real_T comps;                        /* '<Root>/Summarizing' */
  real_T recoils;                      /* '<Root>/Summarizing' */
  real_T old_cpm;                      /* '<S9>/Write Logic' */
  real_T lastTs;                       /* '<S2>/Chart1' */
  codertarget_arduinobase_int_o_T obj_my;/* '<S10>/BLE Send9' */
  codertarget_arduinobase_int_o_T obj_fn;/* '<S10>/BLE Send8' */
  codertarget_arduinobase_int_o_T obj_o;/* '<S10>/BLE Send7' */
  codertarget_arduinobase_int_o_T obj_ot;/* '<S10>/BLE Send6' */
  codertarget_arduinobase_int_o_T obj_l0;/* '<S10>/BLE Send5' */
  codertarget_arduinobase_int_o_T obj_c;/* '<S10>/BLE Send4' */
  codertarget_arduinobase_int_o_T obj_g;/* '<S10>/BLE Send3' */
  codertarget_arduinobase_int_o_T obj_h;/* '<S10>/BLE Send2' */
  codertarget_arduinobase_int_o_T obj_ki;/* '<S10>/BLE Send10' */
  codertarget_arduinobase_int_o_T obj_mv;/* '<S10>/BLE Send1' */
  real32_T TappedDelay_X_f[10];        /* '<S4>/Tapped Delay' */
  int32_T clockTickCounter;            /* '<S9>/Pulse Generator' */
  uint32_T temporalCounter_i1;         /* '<Root>/Summarizing' */
  uint32_T Holder;                     /* '<S9>/DataLogic' */
  uint32_T temporalCounter_i1_i;       /* '<S9>/DataLogic' */
  uint16_T temporalCounter_i1_f;       /* '<S9>/Write Logic' */
  uint16_T temporalCounter_i1_ir;      /* '<Root>/Mode' */
  uint16_T temporalCounter_i1_c;       /* '<S4>/timer' */
  uint16_T temporalCounter_i1_o;       /* '<S2>/Chart1' */
  boolean_T Delay8_DSTATE[288];        /* '<S9>/Delay8' */
  boolean_T Delay7_DSTATE;             /* '<S9>/Delay7' */
  boolean_T Delay8_DSTATE_b[2];        /* '<S7>/Delay8' */
  boolean_T Delay7_DSTATE_l;           /* '<S7>/Delay7' */
  boolean_T Delay6_DSTATE[2];          /* '<S7>/Delay6' */
  boolean_T Delay4_DSTATE_a[2];        /* '<S7>/Delay4' */
  boolean_T Delay1_DSTATE_m;           /* '<S7>/Delay1' */
  boolean_T Delay3_DSTATE_m[2];        /* '<S7>/Delay3' */
  boolean_T Delay_DSTATE_a[5];         /* '<S7>/Delay' */
  boolean_T Delay2_DSTATE_m[5];        /* '<S7>/Delay2' */
  uint8_T is_c20_top_level_algo;       /* '<Root>/Summarizing' */
  uint8_T is_EVALUATING;               /* '<Root>/Summarizing' */
  uint8_T is_active_c20_top_level_algo;/* '<Root>/Summarizing' */
  uint8_T is_c19_top_level_algo;       /* '<S9>/Write Logic' */
  uint8_T is_active_c19_top_level_algo;/* '<S9>/Write Logic' */
  uint8_T is_c15_top_level_algo;       /* '<S9>/DataLogic' */
  uint8_T is_active_c15_top_level_algo;/* '<S9>/DataLogic' */
  uint8_T is_c16_top_level_algo;       /* '<Root>/Mode' */
  uint8_T is_active_c16_top_level_algo;/* '<Root>/Mode' */
  uint8_T is_c3_top_level_algo;        /* '<S4>/timer' */
  uint8_T is_active_c3_top_level_algo; /* '<S4>/timer' */
  uint8_T is_c12_top_level_algo;       /* '<S2>/Chart1' */
  uint8_T is_active_c12_top_level_algo;/* '<S2>/Chart1' */
  boolean_T TmpRTBAtChart1Inport2_Buffer0;/* synthesized block */
  boolean_T TmpRTBAtSummarizingInport6_Buff;/* synthesized block */
  DW_sampleandhold_top_level_al_T sf_sampleandhold1;/* '<S7>/sample and hold1' */
  DW_sampleandhold_top_level_al_T sf_sampleandhold;/* '<S7>/sample and hold' */
} DW_top_level_algo_T;

/* Parameters for system: '<S15>/If Action Subsystem' */
struct P_IfActionSubsystem_top_level_T_ {
  uint8_T Constant_Value;              /* Expression: 0x3F
                                        * Referenced by: '<S18>/Constant'
                                        */
};

/* Parameters (default storage) */
struct P_top_level_algo_T_ {
  real_T Vdd;                          /* Variable: Vdd
                                        * Referenced by:
                                        *   '<S4>/Constant'
                                        *   '<S4>/rad  per volt'
                                        */
  real_T gear_ratio;                   /* Variable: gear_ratio
                                        * Referenced by: '<S4>/Gear Down'
                                        */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S12>/Constant'
                                       */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S59>/Constant'
                                      */
  real_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S60>/Constant'
                                      */
  real_T CompareToConstant3_const;   /* Mask Parameter: CompareToConstant3_const
                                      * Referenced by: '<S61>/Constant'
                                      */
  real_T CompareToConstant4_const;   /* Mask Parameter: CompareToConstant4_const
                                      * Referenced by: '<S62>/Constant'
                                      */
  real_T Positive_const;               /* Mask Parameter: Positive_const
                                        * Referenced by: '<S54>/Constant'
                                        */
  real_T Longrangemotionup_const;     /* Mask Parameter: Longrangemotionup_const
                                       * Referenced by: '<S52>/Constant'
                                       */
  real_T Negative_const;               /* Mask Parameter: Negative_const
                                        * Referenced by: '<S53>/Constant'
                                        */
  real_T Longrangemotiondown_const; /* Mask Parameter: Longrangemotiondown_const
                                     * Referenced by: '<S51>/Constant'
                                     */
  real_T MaxBDC_vinit;                 /* Mask Parameter: MaxBDC_vinit
                                        * Referenced by:
                                        *   '<S68>/Initial Condition'
                                        *   '<S68>/Memory'
                                        */
  real_T MinBDC_vinit;                 /* Mask Parameter: MinBDC_vinit
                                        * Referenced by:
                                        *   '<S69>/Initial Condition'
                                        *   '<S69>/Memory'
                                        */
  real_T TappedDelay1_vinit;           /* Mask Parameter: TappedDelay1_vinit
                                        * Referenced by: '<S4>/Tapped Delay1'
                                        */
  real_T TappedDelay_vinit;            /* Mask Parameter: TappedDelay_vinit
                                        * Referenced by: '<S3>/Tapped Delay'
                                        */
  real32_T CompareToConstant_const_f;
                                    /* Mask Parameter: CompareToConstant_const_f
                                     * Referenced by: '<S75>/Constant'
                                     */
  real32_T TappedDelay_vinit_l;        /* Mask Parameter: TappedDelay_vinit_l
                                        * Referenced by: '<S4>/Tapped Delay'
                                        */
  real_T AnalogInput_SampleTime;       /* Expression: 0.005
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T Constant_Value[2];            /* Expression: [0,0]
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T DigitalInput_SampleTime;      /* Expression: 0.05
                                        * Referenced by: '<Root>/Digital Input'
                                        */
  real_T Constant_Value_g;             /* Expression: 0
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S74>/Constant1'
                                        */
  real_T Constant3_Value[2];           /* Expression: [0,0]
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant1_Value_a;            /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant2_Value[4];           /* Expression: [0,0,0,0]
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S74>/Constant'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S74>/Delay'
                                        */
  real_T Delay_InitialCondition_n;     /* Expression: 0.0
                                        * Referenced by: '<S9>/Delay'
                                        */
  real_T Constant1_Value_j;            /* Expression: 100
                                        * Referenced by: '<S14>/Constant1'
                                        */
  real_T Constant2_Value_c;            /* Expression: 10
                                        * Referenced by: '<S14>/Constant2'
                                        */
  real_T TmpRTBAtModeOutport3_InitialCon;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch2'
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
  real_T PulseGenerator_PhaseDelay;    /* Expression: 2
                                        * Referenced by: '<S9>/Pulse Generator'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S1>/Switch'
                                        */
  real_T TmpRTBAtModeOutport2_InitialCon;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch1'
                                        */
  real_T evaluating_InitialCondition;  /* Expression: 0
                                        * Referenced by:
                                        */
  real_T Max_InitialCondition;         /* Expression: 0
                                        * Referenced by:
                                        */
  real_T Constant1_Value_d;            /* Expression: 4095
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Switch_Threshold_c;           /* Expression: 0
                                        * Referenced by: '<S4>/Switch'
                                        */
  real_T Radiusmm_Gain;                /* Expression: 103
                                        * Referenced by: '<S4>/Radius (mm)'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S55>/Constant'
                                        */
  real_T TmpRTBAtModeOutport1_InitialCon;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Switch_Threshold_j;           /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Delay_InitialCondition_m;     /* Expression: 0.0
                                        * Referenced by: '<S3>/Delay'
                                        */
  real_T Gain_Gain;                    /* Expression: 2
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S3>/Delay1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 2
                                        * Referenced by: '<S3>/Gain1'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S3>/Delay2'
                                        */
  real_T Delay3_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S3>/Delay3'
                                        */
  real_T Delay4_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S3>/Delay4'
                                        */
  real_T Delay5_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S3>/Delay5'
                                        */
  real_T CompressionSensitivity_Gain;  /* Expression: 0.5
                                        * Referenced by: '<S3>/Compression  Sensitivity'
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S65>/Constant'
                                        */
  boolean_T Constant_Value_p;          /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S5>/Constant'
                                        */
  boolean_T Delay8_InitialCondition;
                                  /* Computed Parameter: Delay8_InitialCondition
                                   * Referenced by: '<S9>/Delay8'
                                   */
  boolean_T Delay7_InitialCondition;
                                  /* Computed Parameter: Delay7_InitialCondition
                                   * Referenced by: '<S9>/Delay7'
                                   */
  boolean_T TmpRTBAtChart1Inport2_InitialCo;
                          /* Computed Parameter: TmpRTBAtChart1Inport2_InitialCo
                           * Referenced by:
                           */
  boolean_T TmpRTBAtSummarizingInport6_Init;
                          /* Computed Parameter: TmpRTBAtSummarizingInport6_Init
                           * Referenced by:
                           */
  boolean_T Delay8_InitialCondition_o;
                                /* Computed Parameter: Delay8_InitialCondition_o
                                 * Referenced by: '<S7>/Delay8'
                                 */
  boolean_T Delay7_InitialCondition_o;
                                /* Computed Parameter: Delay7_InitialCondition_o
                                 * Referenced by: '<S7>/Delay7'
                                 */
  boolean_T Delay6_InitialCondition;
                                  /* Computed Parameter: Delay6_InitialCondition
                                   * Referenced by: '<S7>/Delay6'
                                   */
  boolean_T Delay4_InitialCondition_f;
                                /* Computed Parameter: Delay4_InitialCondition_f
                                 * Referenced by: '<S7>/Delay4'
                                 */
  boolean_T Delay1_InitialCondition_d;
                                /* Computed Parameter: Delay1_InitialCondition_d
                                 * Referenced by: '<S7>/Delay1'
                                 */
  boolean_T Delay3_InitialCondition_k;
                                /* Computed Parameter: Delay3_InitialCondition_k
                                 * Referenced by: '<S7>/Delay3'
                                 */
  boolean_T Delay_InitialCondition_d;
                                 /* Computed Parameter: Delay_InitialCondition_d
                                  * Referenced by: '<S7>/Delay'
                                  */
  boolean_T Delay2_InitialCondition_c;
                                /* Computed Parameter: Delay2_InitialCondition_c
                                 * Referenced by: '<S7>/Delay2'
                                 */
  uint8_T Merge_InitialOutput;        /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S17>/Merge'
                                       */
  uint8_T Merge_InitialOutput_o;    /* Computed Parameter: Merge_InitialOutput_o
                                     * Referenced by: '<S16>/Merge'
                                     */
  uint8_T Merge_InitialOutput_e;    /* Computed Parameter: Merge_InitialOutput_e
                                     * Referenced by: '<S15>/Merge'
                                     */
  P_IfActionSubsystem_top_level_T IfActionSubsystem9_j;/* '<S17>/If Action Subsystem9' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem10_n;/* '<S17>/If Action Subsystem10' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem8_g;/* '<S17>/If Action Subsystem8' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem7_o;/* '<S17>/If Action Subsystem7' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem6_f;/* '<S17>/If Action Subsystem6' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem5_j;/* '<S17>/If Action Subsystem5' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem4_k;/* '<S17>/If Action Subsystem4' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem3_m;/* '<S17>/If Action Subsystem3' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem2_b;/* '<S17>/If Action Subsystem2' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem1_i;/* '<S17>/If Action Subsystem1' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem_a;/* '<S17>/If Action Subsystem' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem9_m;/* '<S16>/If Action Subsystem9' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem10_d;/* '<S16>/If Action Subsystem10' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem8_j;/* '<S16>/If Action Subsystem8' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem7_j;/* '<S16>/If Action Subsystem7' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem6_h;/* '<S16>/If Action Subsystem6' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem5_b;/* '<S16>/If Action Subsystem5' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem4_b;/* '<S16>/If Action Subsystem4' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem3_h;/* '<S16>/If Action Subsystem3' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem2_e;/* '<S16>/If Action Subsystem2' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem1_l;/* '<S16>/If Action Subsystem1' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem_f;/* '<S16>/If Action Subsystem' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem9;/* '<S15>/If Action Subsystem9' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem10;/* '<S15>/If Action Subsystem10' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem8;/* '<S15>/If Action Subsystem8' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem7;/* '<S15>/If Action Subsystem7' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem6;/* '<S15>/If Action Subsystem6' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem5;/* '<S15>/If Action Subsystem5' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem4;/* '<S15>/If Action Subsystem4' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem3;/* '<S15>/If Action Subsystem3' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem2;/* '<S15>/If Action Subsystem2' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem1;/* '<S15>/If Action Subsystem1' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem;/* '<S15>/If Action Subsystem' */
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
 * Block '<S2>/Constant2' : Unused code path elimination
 * Block '<S2>/Counter1' : Unused code path elimination
 * Block '<S14>/Display1' : Unused code path elimination
 * Block '<S14>/Display2' : Unused code path elimination
 * Block '<S2>/Subtract3' : Unused code path elimination
 * Block '<S3>/Scope' : Unused code path elimination
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<Root>/Display2' : Unused code path elimination
 * Block '<Root>/Display3' : Unused code path elimination
 * Block '<Root>/Gain' : Unused code path elimination
 * Block '<S63>/Data Type Duplicate' : Unused code path elimination
 * Block '<S68>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<S64>/Data Type Duplicate' : Unused code path elimination
 * Block '<S69>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<Root>/Scope10' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<Root>/Scope3' : Unused code path elimination
 * Block '<Root>/Scope4' : Unused code path elimination
 * Block '<Root>/Scope5' : Unused code path elimination
 * Block '<Root>/Scope6' : Unused code path elimination
 * Block '<Root>/Scope7' : Unused code path elimination
 * Block '<Root>/Scope8' : Unused code path elimination
 * Block '<Root>/Scope9' : Unused code path elimination
 * Block '<S9>/Scope' : Unused code path elimination
 * Block '<S9>/Scope1' : Unused code path elimination
 * Block '<S9>/Scope12' : Unused code path elimination
 * Block '<S9>/Scope2' : Unused code path elimination
 * Block '<S9>/Scope3' : Unused code path elimination
 * Block '<S14>/Shift Arithmetic' : Eliminated trivial shift
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
 * '<S1>'   : 'top_level_algo/Check Recoil'
 * '<S2>'   : 'top_level_algo/Compression Detection'
 * '<S3>'   : 'top_level_algo/Direction '
 * '<S4>'   : 'top_level_algo/Hardware Hiding'
 * '<S5>'   : 'top_level_algo/IsNonZero'
 * '<S6>'   : 'top_level_algo/LED_display'
 * '<S7>'   : 'top_level_algo/MinMax'
 * '<S8>'   : 'top_level_algo/Mode'
 * '<S9>'   : 'top_level_algo/Sped up 7seg Driver1'
 * '<S10>'  : 'top_level_algo/Subsystem'
 * '<S11>'  : 'top_level_algo/Summarizing'
 * '<S12>'  : 'top_level_algo/Check Recoil/Compare To Constant'
 * '<S13>'  : 'top_level_algo/Compression Detection/Chart1'
 * '<S14>'  : 'top_level_algo/Compression Detection/HR Encoding'
 * '<S15>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder'
 * '<S16>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1'
 * '<S17>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2'
 * '<S18>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem'
 * '<S19>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem1'
 * '<S20>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem10'
 * '<S21>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem2'
 * '<S22>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem3'
 * '<S23>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem4'
 * '<S24>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem5'
 * '<S25>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem6'
 * '<S26>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem7'
 * '<S27>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem8'
 * '<S28>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder/If Action Subsystem9'
 * '<S29>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem'
 * '<S30>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem1'
 * '<S31>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem10'
 * '<S32>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem2'
 * '<S33>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem3'
 * '<S34>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem4'
 * '<S35>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem5'
 * '<S36>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem6'
 * '<S37>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem7'
 * '<S38>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem8'
 * '<S39>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder1/If Action Subsystem9'
 * '<S40>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem'
 * '<S41>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem1'
 * '<S42>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem10'
 * '<S43>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem2'
 * '<S44>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem3'
 * '<S45>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem4'
 * '<S46>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem5'
 * '<S47>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem6'
 * '<S48>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem7'
 * '<S49>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem8'
 * '<S50>'  : 'top_level_algo/Compression Detection/HR Encoding/7seg encoder2/If Action Subsystem9'
 * '<S51>'  : 'top_level_algo/Direction /Long range motion down'
 * '<S52>'  : 'top_level_algo/Direction /Long range motion up'
 * '<S53>'  : 'top_level_algo/Direction /Negative'
 * '<S54>'  : 'top_level_algo/Direction /Positive'
 * '<S55>'  : 'top_level_algo/Hardware Hiding/force min to zero'
 * '<S56>'  : 'top_level_algo/Hardware Hiding/timer'
 * '<S57>'  : 'top_level_algo/Hardware Hiding/force min to zero/If Action Subsystem'
 * '<S58>'  : 'top_level_algo/Hardware Hiding/force min to zero/If Action Subsystem1'
 * '<S59>'  : 'top_level_algo/LED_display/Compare To Constant1'
 * '<S60>'  : 'top_level_algo/LED_display/Compare To Constant2'
 * '<S61>'  : 'top_level_algo/LED_display/Compare To Constant3'
 * '<S62>'  : 'top_level_algo/LED_display/Compare To Constant4'
 * '<S63>'  : 'top_level_algo/MinMax/Max (BDC)'
 * '<S64>'  : 'top_level_algo/MinMax/Min (BDC)'
 * '<S65>'  : 'top_level_algo/MinMax/force min to zero'
 * '<S66>'  : 'top_level_algo/MinMax/sample and hold'
 * '<S67>'  : 'top_level_algo/MinMax/sample and hold1'
 * '<S68>'  : 'top_level_algo/MinMax/Max (BDC)/Subsystem'
 * '<S69>'  : 'top_level_algo/MinMax/Min (BDC)/Subsystem'
 * '<S70>'  : 'top_level_algo/MinMax/force min to zero/If Action Subsystem'
 * '<S71>'  : 'top_level_algo/MinMax/force min to zero/If Action Subsystem1'
 * '<S72>'  : 'top_level_algo/Sped up 7seg Driver1/DataLogic'
 * '<S73>'  : 'top_level_algo/Sped up 7seg Driver1/Write Logic'
 * '<S74>'  : 'top_level_algo/Sped up 7seg Driver1/clk'
 * '<S75>'  : 'top_level_algo/Sped up 7seg Driver1/clk/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_top_level_algo_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
