/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: stm32f4discovery_gettingstarted.h
 *
 * Code generated for Simulink model 'stm32f4discovery_gettingstarted'.
 *
 * Model version                  : 12.0
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Mar 18 09:36:49 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_stm32f4discovery_gettingstarted_h_
#define RTW_HEADER_stm32f4discovery_gettingstarted_h_
#ifndef stm32f4discovery_gettingstarted_COMMON_INCLUDES_
#define stm32f4discovery_gettingstarted_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "main.h"
#endif                    /* stm32f4discovery_gettingstarted_COMMON_INCLUDES_ */

#include "stm32f4discovery_gettingstarted_types.h"
#include <stddef.h>
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#define stm32f4discovery_gettingstarted_M (stm32f4discovery_gettingstar_M)

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
} DW_stm32f4discovery_gettingst_T;

/* Parameters (default storage) */
struct P_stm32f4discovery_gettingsta_T_ {
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: 10
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: 5
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_stm32f4discovery_gett_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_stm32f4discovery_gettingsta_T stm32f4discovery_gettingstart_P;

/* Block states (default storage) */
extern DW_stm32f4discovery_gettingst_T stm32f4discovery_gettingstar_DW;

/* Model entry point functions */
extern void stm32f4discovery_gettingstarted_initialize(void);
extern void stm32f4discovery_gettingstarted_step(void);
extern void stm32f4discovery_gettingstarted_terminate(void);

/* Real-time Model object */
extern RT_MODEL_stm32f4discovery_get_T *const stm32f4discovery_gettingstar_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'stm32f4discovery_gettingstarted'
 * '<S1>'   : 'stm32f4discovery_gettingstarted/Digital Port Write'
 * '<S2>'   : 'stm32f4discovery_gettingstarted/Digital Port Write/ECSoC'
 * '<S3>'   : 'stm32f4discovery_gettingstarted/Digital Port Write/ECSoC/ECSimCodegen'
 */
#endif                       /* RTW_HEADER_stm32f4discovery_gettingstarted_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
