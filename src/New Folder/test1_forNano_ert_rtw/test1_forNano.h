/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test1_forNano.h
 *
 * Code generated for Simulink model 'test1_forNano'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Tue Jan 31 16:14:44 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_test1_forNano_h_
#define RTW_HEADER_test1_forNano_h_
#include <math.h>
#include <stddef.h>
#ifndef test1_forNano_COMMON_INCLUDES_
#define test1_forNano_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* test1_forNano_COMMON_INCLUDES_ */

#include "test1_forNano_types.h"
#include "MW_target_hardware_resources.h"

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

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<Root>/Digital Output' */
} DW_test1_forNano_T;

/* Parameters (default storage) */
struct P_test1_forNano_T_ {
  real_T SquareWaveGenerator_Amplitude;/* Expression: 1
                                        * Referenced by: '<Root>/Square Wave Generator'
                                        */
  real_T SquareWaveGenerator_Frequency;/* Expression: 1
                                        * Referenced by: '<Root>/Square Wave Generator'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_test1_forNano_T {
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
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[1];
  } Timing;
};

/* Block parameters (default storage) */
extern P_test1_forNano_T test1_forNano_P;

/* Block states (default storage) */
extern DW_test1_forNano_T test1_forNano_DW;

/* Model entry point functions */
extern void test1_forNano_initialize(void);
extern void test1_forNano_step(void);
extern void test1_forNano_terminate(void);

/* Real-time Model object */
extern RT_MODEL_test1_forNano_T *const test1_forNano_M;
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
 * '<Root>' : 'test1_forNano'
 */
#endif                                 /* RTW_HEADER_test1_forNano_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
