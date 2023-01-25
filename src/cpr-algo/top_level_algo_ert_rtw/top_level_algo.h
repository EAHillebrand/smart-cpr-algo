/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo.h
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 1.110
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Wed Jan 25 13:10:13 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_top_level_algo_h_
#define RTW_HEADER_top_level_algo_h_
#include <float.h>
#include <math.h>
#include <stddef.h>
#ifndef top_level_algo_COMMON_INCLUDES_
#define top_level_algo_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
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

/* Block signals (default storage) */
typedef struct {
  uint8_T Merge;                       /* '<S3>/Merge' */
  uint8_T Merge_b;                     /* '<S4>/Merge' */
  uint8_T Merge_d;                     /* '<S5>/Merge' */
} B_top_level_algo_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T counter;                      /* '<S2>/ClockLogic' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  uint32_T Holder;                     /* '<S2>/DataLogic' */
  uint8_T is_active_c6_top_level_algo; /* '<S2>/DataLogic' */
  uint8_T is_c6_top_level_algo;        /* '<S2>/DataLogic' */
  uint8_T temporalCounter_i1;          /* '<S2>/DataLogic' */
  uint8_T is_active_c5_top_level_algo; /* '<S2>/ClockLogic' */
  uint8_T is_c5_top_level_algo;        /* '<S2>/ClockLogic' */
  uint8_T temporalCounter_i1_l;        /* '<S2>/ClockLogic' */
} DW_top_level_algo_T;

/* Parameters for system: '<S3>/If Action Subsystem' */
struct P_IfActionSubsystem_top_level_T_ {
  uint8_T Constant_Value;              /* Expression: 0x3F
                                        * Referenced by: '<S6>/Constant'
                                        */
};

/* Parameters (default storage) */
struct P_top_level_algo_T_ {
  real_T Constant_Value;               /* Expression: 120
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 100
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 10
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<Root>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<Root>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  uint8_T Merge_InitialOutput;        /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S3>/Merge'
                                       */
  uint8_T Merge_InitialOutput_i;    /* Computed Parameter: Merge_InitialOutput_i
                                     * Referenced by: '<S4>/Merge'
                                     */
  uint8_T Merge_InitialOutput_j;    /* Computed Parameter: Merge_InitialOutput_j
                                     * Referenced by: '<S5>/Merge'
                                     */
  P_IfActionSubsystem_top_level_T IfActionSubsystem10_m;/* '<S5>/If Action Subsystem10' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem8_f;/* '<S5>/If Action Subsystem8' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem7_n;/* '<S5>/If Action Subsystem7' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem6_c;/* '<S5>/If Action Subsystem6' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem5_hh;/* '<S5>/If Action Subsystem5' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem4_db;/* '<S5>/If Action Subsystem4' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem3_c;/* '<S5>/If Action Subsystem3' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem2_i;/* '<S5>/If Action Subsystem2' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem1_a;/* '<S5>/If Action Subsystem1' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem_j;/* '<S5>/If Action Subsystem' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem10_l;/* '<S4>/If Action Subsystem10' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem8_p;/* '<S4>/If Action Subsystem8' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem7_h;/* '<S4>/If Action Subsystem7' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem6_b;/* '<S4>/If Action Subsystem6' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem5_h;/* '<S4>/If Action Subsystem5' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem4_d;/* '<S4>/If Action Subsystem4' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem3_p;/* '<S4>/If Action Subsystem3' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem2_d;/* '<S4>/If Action Subsystem2' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem1_d;/* '<S4>/If Action Subsystem1' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem_l;/* '<S4>/If Action Subsystem' */
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
  const char_T * volatile errorStatus;
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
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<S1>/Display1' : Unused code path elimination
 * Block '<S1>/Display2' : Unused code path elimination
 * Block '<Root>/Scope11' : Unused code path elimination
 * Block '<S2>/Add Constant' : Unused code path elimination
 * Block '<Root>/Value' : Unused code path elimination
 * Block '<S2>/Cast To Double' : Eliminate redundant data type conversion
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
 * '<S2>'   : 'top_level_algo/Subsystem'
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
 * '<S16>'  : 'top_level_algo/HR Encoding/7seg encoder1/If Action Subsystem'
 * '<S17>'  : 'top_level_algo/HR Encoding/7seg encoder1/If Action Subsystem1'
 * '<S18>'  : 'top_level_algo/HR Encoding/7seg encoder1/If Action Subsystem10'
 * '<S19>'  : 'top_level_algo/HR Encoding/7seg encoder1/If Action Subsystem2'
 * '<S20>'  : 'top_level_algo/HR Encoding/7seg encoder1/If Action Subsystem3'
 * '<S21>'  : 'top_level_algo/HR Encoding/7seg encoder1/If Action Subsystem4'
 * '<S22>'  : 'top_level_algo/HR Encoding/7seg encoder1/If Action Subsystem5'
 * '<S23>'  : 'top_level_algo/HR Encoding/7seg encoder1/If Action Subsystem6'
 * '<S24>'  : 'top_level_algo/HR Encoding/7seg encoder1/If Action Subsystem7'
 * '<S25>'  : 'top_level_algo/HR Encoding/7seg encoder1/If Action Subsystem8'
 * '<S26>'  : 'top_level_algo/HR Encoding/7seg encoder2/If Action Subsystem'
 * '<S27>'  : 'top_level_algo/HR Encoding/7seg encoder2/If Action Subsystem1'
 * '<S28>'  : 'top_level_algo/HR Encoding/7seg encoder2/If Action Subsystem10'
 * '<S29>'  : 'top_level_algo/HR Encoding/7seg encoder2/If Action Subsystem2'
 * '<S30>'  : 'top_level_algo/HR Encoding/7seg encoder2/If Action Subsystem3'
 * '<S31>'  : 'top_level_algo/HR Encoding/7seg encoder2/If Action Subsystem4'
 * '<S32>'  : 'top_level_algo/HR Encoding/7seg encoder2/If Action Subsystem5'
 * '<S33>'  : 'top_level_algo/HR Encoding/7seg encoder2/If Action Subsystem6'
 * '<S34>'  : 'top_level_algo/HR Encoding/7seg encoder2/If Action Subsystem7'
 * '<S35>'  : 'top_level_algo/HR Encoding/7seg encoder2/If Action Subsystem8'
 * '<S36>'  : 'top_level_algo/Subsystem/ClockLogic'
 * '<S37>'  : 'top_level_algo/Subsystem/DataLogic'
 */
#endif                                 /* RTW_HEADER_top_level_algo_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
