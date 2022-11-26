/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo_private.h
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

#ifndef RTW_HEADER_top_level_algo_private_h_
#define RTW_HEADER_top_level_algo_private_h_
#include "rtwtypes.h"
#include "top_level_algo.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator);
extern void top_level_al_sampleandhold_Init(real_T *rty_displacement);
extern void top_level_algo_sampleandhold(real_T rtu_max, boolean_T rtu_read,
  real_T *rty_displacement, DW_sampleandhold_top_level_al_T *localDW);

#endif                                /* RTW_HEADER_top_level_algo_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
