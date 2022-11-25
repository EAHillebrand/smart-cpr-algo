/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo.h
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 1.70
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Fri Nov 25 11:53:29 2022
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

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint16_T AnalogInput1;               /* '<Root>/Analog Input1' */
} B_top_level_algo_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input1' */
  uint16_T TappedDelay_X[20];          /* '<S2>/Tapped Delay' */
} DW_top_level_algo_T;

/* Parameters (default storage) */
struct P_top_level_algo_T_ {
  uint16_T TappedDelay_vinit;          /* Mask Parameter: TappedDelay_vinit
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
                                        * Referenced by: '<S7>/Constant'
                                        */
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
 * Block '<S1>/30 Diff' : Unused code path elimination
 * Block '<S1>/5to30 Diff' : Unused code path elimination
 * Block '<S1>/AND' : Unused code path elimination
 * Block '<S1>/AND1' : Unused code path elimination
 * Block '<S1>/Add' : Unused code path elimination
 * Block '<S1>/Delay' : Unused code path elimination
 * Block '<S1>/Delay1' : Unused code path elimination
 * Block '<S1>/Delay2' : Unused code path elimination
 * Block '<S1>/Delay3' : Unused code path elimination
 * Block '<S1>/Delay4' : Unused code path elimination
 * Block '<S1>/Delay5' : Unused code path elimination
 * Block '<S1>/Fifth Diff' : Unused code path elimination
 * Block '<S1>/First Diff' : Unused code path elimination
 * Block '<S1>/Fourth Diff' : Unused code path elimination
 * Block '<S1>/Gain' : Unused code path elimination
 * Block '<S1>/Gain1' : Unused code path elimination
 * Block '<S3>/Compare' : Unused code path elimination
 * Block '<S3>/Constant' : Unused code path elimination
 * Block '<S4>/Compare' : Unused code path elimination
 * Block '<S4>/Constant' : Unused code path elimination
 * Block '<S1>/Mean' : Unused code path elimination
 * Block '<S5>/Compare' : Unused code path elimination
 * Block '<S5>/Constant' : Unused code path elimination
 * Block '<S6>/Compare' : Unused code path elimination
 * Block '<S6>/Constant' : Unused code path elimination
 * Block '<S1>/Second Diff' : Unused code path elimination
 * Block '<S1>/Sign' : Unused code path elimination
 * Block '<S1>/Sign1' : Unused code path elimination
 * Block '<S1>/Sign2' : Unused code path elimination
 * Block '<S1>/Sign3' : Unused code path elimination
 * Block '<S1>/Sign4' : Unused code path elimination
 * Block '<S1>/Sign5' : Unused code path elimination
 * Block '<S1>/Tapped Delay' : Unused code path elimination
 * Block '<S1>/Third Diff' : Unused code path elimination
 * Block '<S1>/Zero' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope10' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<Root>/Scope3' : Unused code path elimination
 * Block '<Root>/Scope4' : Unused code path elimination
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
 * '<S3>'   : 'top_level_algo/Direction /Long range motion down'
 * '<S4>'   : 'top_level_algo/Direction /Long range motion up'
 * '<S5>'   : 'top_level_algo/Direction /Negative'
 * '<S6>'   : 'top_level_algo/Direction /Positive'
 * '<S7>'   : 'top_level_algo/Hardware Hiding/force min to zero'
 * '<S8>'   : 'top_level_algo/Hardware Hiding/force min to zero/If Action Subsystem'
 * '<S9>'   : 'top_level_algo/Hardware Hiding/force min to zero/If Action Subsystem1'
 */
#endif                                 /* RTW_HEADER_top_level_algo_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
