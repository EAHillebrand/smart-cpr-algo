/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo.h
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 1.86
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Fri Nov 25 20:36:29 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_top_level_algo_h_
#define RTW_HEADER_top_level_algo_h_
#include <stddef.h>
#ifndef top_level_algo_COMMON_INCLUDES_
#define top_level_algo_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#endif                                 /* top_level_algo_COMMON_INCLUDES_ */

#include "top_level_algo_types.h"
#include "MW_target_hardware_resources.h"
#include "rtGetNaN.h"
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

/* Block states (default storage) for system '<S5>/sample and hold' */
typedef struct {
  uint8_T is_active_c1_top_level_algo; /* '<S5>/sample and hold' */
  uint8_T is_c1_top_level_algo;        /* '<S5>/sample and hold' */
} DW_sampleandhold_top_level_al_T;

/* Block signals (default storage) */
typedef struct {
  real_T Product;                      /* '<S4>/Product' */
  real_T u0Diff;                       /* '<S3>/30 Diff' */
  real_T baseline;                     /* '<S4>/timer' */
  real_T MajorityVoterSlope;           /* '<S3>/Add' */
  real_T Mean1_AccVal;
  real_T u;
  real_T u_m;
  real_T u_c;
  real_T u_k;
  uint16_T AnalogInput1;               /* '<Root>/Analog Input1' */
} B_top_level_algo_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input1' */
  real_T TappedDelay1_X[20];           /* '<S4>/Tapped Delay1' */
  real_T TappedDelay_X[20];            /* '<S3>/Tapped Delay' */
  real_T Delay_DSTATE;                 /* '<S3>/Delay' */
  real_T Delay1_DSTATE[2];             /* '<S3>/Delay1' */
  real_T Delay2_DSTATE[3];             /* '<S3>/Delay2' */
  real_T Delay3_DSTATE[4];             /* '<S3>/Delay3' */
  real_T Delay4_DSTATE[5];             /* '<S3>/Delay4' */
  real_T Delay5_DSTATE[30];            /* '<S3>/Delay5' */
  real_T Memory_PreviousInput;         /* '<S21>/Memory' */
  real_T Memory_PreviousInput_m;       /* '<S22>/Memory' */
  real_T comp;                         /* '<S2>/Chart' */
  real_T last_count;                   /* '<S2>/Chart' */
  real_T first;                        /* '<S2>/Chart' */
  real_T second;                       /* '<S2>/Chart' */
  real_T third;                        /* '<S2>/Chart' */
  real_T fourth;                       /* '<S2>/Chart' */
  uint16_T TappedDelay_X_f[20];        /* '<S4>/Tapped Delay' */
  uint16_T temporalCounter_i1;         /* '<S4>/timer' */
  boolean_T Delay4_DSTATE_a[2];        /* '<S5>/Delay4' */
  boolean_T Delay1_DSTATE_m;           /* '<S5>/Delay1' */
  boolean_T Delay3_DSTATE_m[2];        /* '<S5>/Delay3' */
  boolean_T Delay_DSTATE_a[5];         /* '<S5>/Delay' */
  boolean_T Delay8_DSTATE[2];          /* '<S5>/Delay8' */
  boolean_T Delay7_DSTATE;             /* '<S5>/Delay7' */
  boolean_T Delay6_DSTATE[2];          /* '<S5>/Delay6' */
  boolean_T Delay2_DSTATE_m[5];        /* '<S5>/Delay2' */
  uint8_T is_active_c3_top_level_algo; /* '<S4>/timer' */
  uint8_T is_c3_top_level_algo;        /* '<S4>/timer' */
  uint8_T is_active_c4_top_level_algo; /* '<S2>/Chart' */
  uint8_T is_c4_top_level_algo;        /* '<S2>/Chart' */
  DW_sampleandhold_top_level_al_T sf_sampleandhold1;/* '<S5>/sample and hold1' */
  DW_sampleandhold_top_level_al_T sf_sampleandhold;/* '<S5>/sample and hold' */
} DW_top_level_algo_T;

/* Parameters (default storage) */
struct P_top_level_algo_T_ {
  real_T Longrangemotionup_const;     /* Mask Parameter: Longrangemotionup_const
                                       * Referenced by: '<S9>/Constant'
                                       */
  real_T Positive_const;               /* Mask Parameter: Positive_const
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Negative_const;               /* Mask Parameter: Negative_const
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Longrangemotiondown_const; /* Mask Parameter: Longrangemotiondown_const
                                     * Referenced by: '<S8>/Constant'
                                     */
  real_T MaxBDC_vinit;                 /* Mask Parameter: MaxBDC_vinit
                                        * Referenced by:
                                        *   '<S21>/Initial Condition'
                                        *   '<S21>/Memory'
                                        */
  real_T MinBDC_vinit;                 /* Mask Parameter: MinBDC_vinit
                                        * Referenced by:
                                        *   '<S22>/Initial Condition'
                                        *   '<S22>/Memory'
                                        */
  real_T TappedDelay1_vinit;           /* Mask Parameter: TappedDelay1_vinit
                                        * Referenced by: '<S4>/Tapped Delay1'
                                        */
  real_T TappedDelay_vinit;            /* Mask Parameter: TappedDelay_vinit
                                        * Referenced by: '<S3>/Tapped Delay'
                                        */
  uint16_T TappedDelay_vinit_l;        /* Mask Parameter: TappedDelay_vinit_l
                                        * Referenced by: '<S4>/Tapped Delay'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  real_T Constant1_Value;              /* Expression: 1024
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 5
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S4>/Switch'
                                        */
  real_T degreespervolt_Gain;          /* Expression: 720
                                        * Referenced by: '<S4>/degrees per volt'
                                        */
  real_T ConverttoRadians_Gain;        /* Expression: pi/180
                                        * Referenced by: '<S4>/Convert to Radians'
                                        */
  real_T Radiusmm_Gain;                /* Expression: 15
                                        * Referenced by: '<S4>/Radius (mm)'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
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
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S18>/Constant'
                                        */
  boolean_T Delay4_InitialCondition_f;
                                /* Computed Parameter: Delay4_InitialCondition_f
                                 * Referenced by: '<S5>/Delay4'
                                 */
  boolean_T Delay1_InitialCondition_d;
                                /* Computed Parameter: Delay1_InitialCondition_d
                                 * Referenced by: '<S5>/Delay1'
                                 */
  boolean_T Delay3_InitialCondition_k;
                                /* Computed Parameter: Delay3_InitialCondition_k
                                 * Referenced by: '<S5>/Delay3'
                                 */
  boolean_T Delay_InitialCondition_d;
                                 /* Computed Parameter: Delay_InitialCondition_d
                                  * Referenced by: '<S5>/Delay'
                                  */
  boolean_T Delay8_InitialCondition;
                                  /* Computed Parameter: Delay8_InitialCondition
                                   * Referenced by: '<S5>/Delay8'
                                   */
  boolean_T Delay7_InitialCondition;
                                  /* Computed Parameter: Delay7_InitialCondition
                                   * Referenced by: '<S5>/Delay7'
                                   */
  boolean_T Delay6_InitialCondition;
                                  /* Computed Parameter: Delay6_InitialCondition
                                   * Referenced by: '<S5>/Delay6'
                                   */
  boolean_T Delay2_InitialCondition_c;
                                /* Computed Parameter: Delay2_InitialCondition_c
                                 * Referenced by: '<S5>/Delay2'
                                 */
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
 * Block '<S6>/Compare' : Unused code path elimination
 * Block '<S6>/Constant' : Unused code path elimination
 * Block '<S2>/Constant2' : Unused code path elimination
 * Block '<S2>/Counter1' : Unused code path elimination
 * Block '<S2>/Subtract3' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<S17>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/FixPt Data Type Duplicate2' : Unused code path elimination
 * Block '<S5>/Scope' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope10' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<Root>/Scope3' : Unused code path elimination
 * Block '<Root>/Scope4' : Unused code path elimination
 * Block '<Root>/Scope7' : Unused code path elimination
 * Block '<Root>/Scope8' : Unused code path elimination
 * Block '<Root>/Scope9' : Unused code path elimination
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
 * '<S5>'   : 'top_level_algo/MinMax'
 * '<S6>'   : 'top_level_algo/Check Recoil/Compare To Constant'
 * '<S7>'   : 'top_level_algo/Compression Detection/Chart'
 * '<S8>'   : 'top_level_algo/Direction /Long range motion down'
 * '<S9>'   : 'top_level_algo/Direction /Long range motion up'
 * '<S10>'  : 'top_level_algo/Direction /Negative'
 * '<S11>'  : 'top_level_algo/Direction /Positive'
 * '<S12>'  : 'top_level_algo/Hardware Hiding/force min to zero'
 * '<S13>'  : 'top_level_algo/Hardware Hiding/timer'
 * '<S14>'  : 'top_level_algo/Hardware Hiding/force min to zero/If Action Subsystem'
 * '<S15>'  : 'top_level_algo/Hardware Hiding/force min to zero/If Action Subsystem1'
 * '<S16>'  : 'top_level_algo/MinMax/Max (BDC)'
 * '<S17>'  : 'top_level_algo/MinMax/Min (BDC)'
 * '<S18>'  : 'top_level_algo/MinMax/force min to zero'
 * '<S19>'  : 'top_level_algo/MinMax/sample and hold'
 * '<S20>'  : 'top_level_algo/MinMax/sample and hold1'
 * '<S21>'  : 'top_level_algo/MinMax/Max (BDC)/Subsystem'
 * '<S22>'  : 'top_level_algo/MinMax/Min (BDC)/Subsystem'
 * '<S23>'  : 'top_level_algo/MinMax/force min to zero/If Action Subsystem'
 * '<S24>'  : 'top_level_algo/MinMax/force min to zero/If Action Subsystem1'
 */
#endif                                 /* RTW_HEADER_top_level_algo_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
