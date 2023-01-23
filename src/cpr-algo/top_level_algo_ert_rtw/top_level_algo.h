/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo.h
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 1.90
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Tue Jan 17 16:34:58 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
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
#include "MW_AnalogIn.h"
#endif                                 /* top_level_algo_COMMON_INCLUDES_ */

#include "top_level_algo_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

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

/* Block signals (default storage) */
typedef struct {
  real_T Mean1;                        /* '<S2>/Mean1' */
  real_T Product;                      /* '<S2>/Product' */
  real_T Merge;                        /* '<S8>/Merge' */
  real_T Reset;                        /* '<S17>/Reset' */
  real_T Reset_b;                      /* '<S18>/Reset' */
  real_T Merge_k;                      /* '<S14>/Merge' */
  real_T u0Diff;                       /* '<S1>/30 Diff' */
  real_T displacement;                 /* '<S3>/sample and hold1' */
  real_T displacement_a;               /* '<S3>/sample and hold' */
  real_T baseline;                     /* '<S2>/timer' */
  real_T MajorityVoterSlope;           /* '<S1>/Add' */
  real_T Mean1_AccVal;
  real_T u;
  uint16_T AnalogInput1;               /* '<Root>/Analog Input1' */
  boolean_T AND1;                      /* '<S3>/AND1' */
  boolean_T LogicalOperator3;          /* '<S3>/Logical Operator3' */
  boolean_T AND;                       /* '<S3>/AND' */
} B_top_level_algo_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input1' */
  real_T TappedDelay1_X[20];           /* '<S2>/Tapped Delay1' */
  real_T TappedDelay_X[20];            /* '<S1>/Tapped Delay' */
  real_T Delay_DSTATE;                 /* '<S1>/Delay' */
  real_T Delay1_DSTATE[2];             /* '<S1>/Delay1' */
  real_T Delay2_DSTATE[3];             /* '<S1>/Delay2' */
  real_T Delay3_DSTATE[4];             /* '<S1>/Delay3' */
  real_T Delay4_DSTATE[5];             /* '<S1>/Delay4' */
  real_T Delay5_DSTATE[30];            /* '<S1>/Delay5' */
  real_T Memory_PreviousInput_m;       /* '<S18>/Memory' */
  struct {
    void *LoggedData;
  } Scope10_PWORK;                     /* '<Root>/Scope10' */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_MinMa;   /* synthesized block */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S3>/Scope' */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Logic;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Min_k;   /* synthesized block */

  struct {
    void *LoggedData[2];
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<Root>/Scope4' */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Min_e;   /* synthesized block */

  struct {
    void *LoggedData;
  } Scope_PWORK_g;                     /* '<Root>/Scope' */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Hardw;   /* synthesized block */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Analo;   /* synthesized block */

  uint32_T is_c2_top_level_algo;       /* '<S3>/sample and hold1' */
  uint32_T is_c1_top_level_algo;       /* '<S3>/sample and hold' */
  uint32_T is_c3_top_level_algo;       /* '<S2>/timer' */
  uint16_T TappedDelay_X_f[20];        /* '<S2>/Tapped Delay' */
  uint16_T temporalCounter_i1;         /* '<S2>/timer' */
  boolean_T Delay4_DSTATE_a[2];        /* '<S3>/Delay4' */
  boolean_T Delay1_DSTATE_m;           /* '<S3>/Delay1' */
  boolean_T Delay3_DSTATE_m[2];        /* '<S3>/Delay3' */
  boolean_T Delay_DSTATE_a[5];         /* '<S3>/Delay' */
  boolean_T Delay8_DSTATE[2];          /* '<S3>/Delay8' */
  boolean_T Delay7_DSTATE;             /* '<S3>/Delay7' */
  boolean_T Delay6_DSTATE[2];          /* '<S3>/Delay6' */
  boolean_T Delay2_DSTATE_m[5];        /* '<S3>/Delay2' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S14>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S14>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRanB_h;/* '<S8>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC_e;/* '<S8>/If Action Subsystem' */
  uint8_T is_active_c2_top_level_algo; /* '<S3>/sample and hold1' */
  uint8_T is_active_c1_top_level_algo; /* '<S3>/sample and hold' */
  uint8_T is_active_c3_top_level_algo; /* '<S2>/timer' */
} DW_top_level_algo_T;

/* Parameters (default storage) */
struct P_top_level_algo_T_ {
  real_T Longrangemotionup_const;     /* Mask Parameter: Longrangemotionup_const
                                       * Referenced by: '<S5>/Constant'
                                       */
  real_T Positive_const;               /* Mask Parameter: Positive_const
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Negative_const;               /* Mask Parameter: Negative_const
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Longrangemotiondown_const; /* Mask Parameter: Longrangemotiondown_const
                                     * Referenced by: '<S4>/Constant'
                                     */
  real_T MaxBDC_vinit;                 /* Mask Parameter: MaxBDC_vinit
                                        * Referenced by:
                                        *   '<S17>/Initial Condition'
                                        *   '<S17>/Memory'
                                        */
  real_T MinBDC_vinit;                 /* Mask Parameter: MinBDC_vinit
                                        * Referenced by:
                                        *   '<S18>/Initial Condition'
                                        *   '<S18>/Memory'
                                        */
  real_T TappedDelay1_vinit;           /* Mask Parameter: TappedDelay1_vinit
                                        * Referenced by: '<S2>/Tapped Delay1'
                                        */
  real_T TappedDelay_vinit;            /* Mask Parameter: TappedDelay_vinit
                                        * Referenced by: '<S1>/Tapped Delay'
                                        */
  uint16_T TappedDelay_vinit_l;        /* Mask Parameter: TappedDelay_vinit_l
                                        * Referenced by: '<S2>/Tapped Delay'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  real_T Constant1_Value;              /* Expression: 1024
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 5
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S2>/Switch'
                                        */
  real_T degreespervolt_Gain;          /* Expression: 720
                                        * Referenced by: '<S2>/degrees per volt'
                                        */
  real_T ConverttoRadians_Gain;        /* Expression: pi/180
                                        * Referenced by: '<S2>/Convert to Radians'
                                        */
  real_T Radiusmm_Gain;                /* Expression: 15
                                        * Referenced by: '<S2>/Radius (mm)'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S1>/Delay'
                                        */
  real_T Gain_Gain;                    /* Expression: 2
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S1>/Delay1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 2
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S1>/Delay2'
                                        */
  real_T Delay3_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S1>/Delay3'
                                        */
  real_T Delay4_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S1>/Delay4'
                                        */
  real_T Delay5_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S1>/Delay5'
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S14>/Constant'
                                        */
  boolean_T Delay4_InitialCondition_f;
                                /* Computed Parameter: Delay4_InitialCondition_f
                                 * Referenced by: '<S3>/Delay4'
                                 */
  boolean_T Delay1_InitialCondition_d;
                                /* Computed Parameter: Delay1_InitialCondition_d
                                 * Referenced by: '<S3>/Delay1'
                                 */
  boolean_T Delay3_InitialCondition_k;
                                /* Computed Parameter: Delay3_InitialCondition_k
                                 * Referenced by: '<S3>/Delay3'
                                 */
  boolean_T Delay_InitialCondition_d;
                                 /* Computed Parameter: Delay_InitialCondition_d
                                  * Referenced by: '<S3>/Delay'
                                  */
  boolean_T Delay8_InitialCondition;
                                  /* Computed Parameter: Delay8_InitialCondition
                                   * Referenced by: '<S3>/Delay8'
                                   */
  boolean_T Delay7_InitialCondition;
                                  /* Computed Parameter: Delay7_InitialCondition
                                   * Referenced by: '<S3>/Delay7'
                                   */
  boolean_T Delay6_InitialCondition;
                                  /* Computed Parameter: Delay6_InitialCondition
                                   * Referenced by: '<S3>/Delay6'
                                   */
  boolean_T Delay2_InitialCondition_c;
                                /* Computed Parameter: Delay2_InitialCondition_c
                                 * Referenced by: '<S3>/Delay2'
                                 */
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
 * Block '<S12>/Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<S13>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/FixPt Data Type Duplicate2' : Unused code path elimination
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
 * '<S1>'   : 'top_level_algo/Direction '
 * '<S2>'   : 'top_level_algo/Hardware Hiding'
 * '<S3>'   : 'top_level_algo/MinMax'
 * '<S4>'   : 'top_level_algo/Direction /Long range motion down'
 * '<S5>'   : 'top_level_algo/Direction /Long range motion up'
 * '<S6>'   : 'top_level_algo/Direction /Negative'
 * '<S7>'   : 'top_level_algo/Direction /Positive'
 * '<S8>'   : 'top_level_algo/Hardware Hiding/force min to zero'
 * '<S9>'   : 'top_level_algo/Hardware Hiding/timer'
 * '<S10>'  : 'top_level_algo/Hardware Hiding/force min to zero/If Action Subsystem'
 * '<S11>'  : 'top_level_algo/Hardware Hiding/force min to zero/If Action Subsystem1'
 * '<S12>'  : 'top_level_algo/MinMax/Max (BDC)'
 * '<S13>'  : 'top_level_algo/MinMax/Min (BDC)'
 * '<S14>'  : 'top_level_algo/MinMax/force min to zero'
 * '<S15>'  : 'top_level_algo/MinMax/sample and hold'
 * '<S16>'  : 'top_level_algo/MinMax/sample and hold1'
 * '<S17>'  : 'top_level_algo/MinMax/Max (BDC)/Subsystem'
 * '<S18>'  : 'top_level_algo/MinMax/Min (BDC)/Subsystem'
 * '<S19>'  : 'top_level_algo/MinMax/force min to zero/If Action Subsystem'
 * '<S20>'  : 'top_level_algo/MinMax/force min to zero/If Action Subsystem1'
 */
#endif                                 /* RTW_HEADER_top_level_algo_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
