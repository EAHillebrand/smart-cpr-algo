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
 * C/C++ source code generated on : Mon Mar 20 19:10:56 2023
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
#endif                                 /* top_level_algo_COMMON_INCLUDES_ */

#include "top_level_algo_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T CLK;                          /* '<S3>/ClockLogic' */
  uint32_T data;                       /* '<S3>/DataLogic' */
  uint8_T Merge;                       /* '<S4>/Merge' */
  uint8_T Merge_d;                     /* '<S5>/Merge' */
  uint8_T Merge_n;                     /* '<S6>/Merge' */
} B_top_level_algo_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<Root>/Digital Output3' */
  codertarget_arduinobase_block_T obj_a;/* '<Root>/Digital Output2' */
  real_T counter;                      /* '<S3>/ClockLogic' */
  int32_T clockTickCounter;            /* '<S1>/Pulse Generator' */
  uint32_T Holder;                     /* '<S3>/DataLogic' */
  uint8_T is_c18_top_level_algo;       /* '<S3>/DataLogic' */
  uint8_T is_active_c18_top_level_algo;/* '<S3>/DataLogic' */
  uint8_T temporalCounter_i1;          /* '<S3>/DataLogic' */
  uint8_T is_c17_top_level_algo;       /* '<S3>/ClockLogic' */
  uint8_T is_active_c17_top_level_algo;/* '<S3>/ClockLogic' */
  uint8_T temporalCounter_i1_o;        /* '<S3>/ClockLogic' */
} DW_top_level_algo_T;

/* Parameters for system: '<S4>/If Action Subsystem' */
struct P_IfActionSubsystem_top_level_T_ {
  uint8_T Constant_Value;              /* Expression: 0x3F
                                        * Referenced by: '<S7>/Constant'
                                        */
};

/* Parameters (default storage) */
struct P_top_level_algo_T_ {
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
  real_T Constant5_Value;              /* Expression: 120
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant1_Value;              /* Expression: 100
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 10
                                        * Referenced by: '<S2>/Constant2'
                                        */
  uint8_T Merge_InitialOutput;        /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S4>/Merge'
                                       */
  uint8_T Merge_InitialOutput_k;    /* Computed Parameter: Merge_InitialOutput_k
                                     * Referenced by: '<S5>/Merge'
                                     */
  uint8_T Merge_InitialOutput_j;    /* Computed Parameter: Merge_InitialOutput_j
                                     * Referenced by: '<S6>/Merge'
                                     */
  P_IfActionSubsystem_top_level_T IfActionSubsystem10_g1;/* '<S6>/If Action Subsystem10' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem8_n;/* '<S6>/If Action Subsystem8' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem7_e;/* '<S6>/If Action Subsystem7' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem6_l;/* '<S6>/If Action Subsystem6' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem5_e;/* '<S6>/If Action Subsystem5' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem4_o;/* '<S6>/If Action Subsystem4' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem3_e;/* '<S6>/If Action Subsystem3' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem2_f;/* '<S6>/If Action Subsystem2' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem1_m;/* '<S6>/If Action Subsystem1' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem_b;/* '<S6>/If Action Subsystem' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem10_g;/* '<S5>/If Action Subsystem10' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem8_i;/* '<S5>/If Action Subsystem8' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem7_i;/* '<S5>/If Action Subsystem7' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem6_j;/* '<S5>/If Action Subsystem6' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem5_b;/* '<S5>/If Action Subsystem5' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem4_b;/* '<S5>/If Action Subsystem4' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem3_d;/* '<S5>/If Action Subsystem3' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem2_n;/* '<S5>/If Action Subsystem2' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem1_g;/* '<S5>/If Action Subsystem1' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem_e;/* '<S5>/If Action Subsystem' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem10;/* '<S4>/If Action Subsystem10' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem8;/* '<S4>/If Action Subsystem8' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem7;/* '<S4>/If Action Subsystem7' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem6;/* '<S4>/If Action Subsystem6' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem5;/* '<S4>/If Action Subsystem5' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem4;/* '<S4>/If Action Subsystem4' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem3;/* '<S4>/If Action Subsystem3' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem2;/* '<S4>/If Action Subsystem2' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem1;/* '<S4>/If Action Subsystem1' */
  P_IfActionSubsystem_top_level_T IfActionSubsystem;/* '<S4>/If Action Subsystem' */
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
 * Block '<S1>/Display1' : Unused code path elimination
 * Block '<S1>/Display2' : Unused code path elimination
 * Block '<S2>/Add1' : Unused code path elimination
 * Block '<S2>/Constant' : Unused code path elimination
 * Block '<S2>/Display1' : Unused code path elimination
 * Block '<S2>/Display2' : Unused code path elimination
 * Block '<S2>/Shift Arithmetic3' : Unused code path elimination
 * Block '<S1>/Scope12' : Unused code path elimination
 * Block '<S2>/Shift Arithmetic' : Eliminated trivial shift
 * Block '<S3>/Cast To Double' : Eliminate redundant data type conversion
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
 * '<S2>'   : 'top_level_algo/7seg Driver1/HR Encoding'
 * '<S3>'   : 'top_level_algo/7seg Driver1/Subsystem'
 * '<S4>'   : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder'
 * '<S5>'   : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder1'
 * '<S6>'   : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder2'
 * '<S7>'   : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder/If Action Subsystem'
 * '<S8>'   : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder/If Action Subsystem1'
 * '<S9>'   : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder/If Action Subsystem10'
 * '<S10>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder/If Action Subsystem2'
 * '<S11>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder/If Action Subsystem3'
 * '<S12>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder/If Action Subsystem4'
 * '<S13>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder/If Action Subsystem5'
 * '<S14>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder/If Action Subsystem6'
 * '<S15>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder/If Action Subsystem7'
 * '<S16>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder/If Action Subsystem8'
 * '<S17>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder1/If Action Subsystem'
 * '<S18>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder1/If Action Subsystem1'
 * '<S19>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder1/If Action Subsystem10'
 * '<S20>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder1/If Action Subsystem2'
 * '<S21>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder1/If Action Subsystem3'
 * '<S22>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder1/If Action Subsystem4'
 * '<S23>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder1/If Action Subsystem5'
 * '<S24>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder1/If Action Subsystem6'
 * '<S25>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder1/If Action Subsystem7'
 * '<S26>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder1/If Action Subsystem8'
 * '<S27>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder2/If Action Subsystem'
 * '<S28>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder2/If Action Subsystem1'
 * '<S29>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder2/If Action Subsystem10'
 * '<S30>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder2/If Action Subsystem2'
 * '<S31>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder2/If Action Subsystem3'
 * '<S32>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder2/If Action Subsystem4'
 * '<S33>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder2/If Action Subsystem5'
 * '<S34>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder2/If Action Subsystem6'
 * '<S35>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder2/If Action Subsystem7'
 * '<S36>'  : 'top_level_algo/7seg Driver1/HR Encoding/7seg encoder2/If Action Subsystem8'
 * '<S37>'  : 'top_level_algo/7seg Driver1/Subsystem/ClockLogic'
 * '<S38>'  : 'top_level_algo/7seg Driver1/Subsystem/DataLogic'
 */
#endif                                 /* RTW_HEADER_top_level_algo_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
