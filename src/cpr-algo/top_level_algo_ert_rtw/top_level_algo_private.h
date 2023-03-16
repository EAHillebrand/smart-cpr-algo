/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo_private.h
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 3.11
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Mar 14 22:48:37 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_top_level_algo_private_h_
#define RTW_HEADER_top_level_algo_private_h_
#include "rtwtypes.h"
#include "top_level_algo.h"
#include "top_level_algo_types.h"

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

extern real_T rt_modd_snf(real_T u0, real_T u1);
extern int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator);
extern void top_level_al_sampleandhold_Init(real_T *rty_displacement);
extern void top_level_algo_sampleandhold(real_T rtu_max, boolean_T rtu_read,
  real_T *rty_displacement, DW_sampleandhold_top_level_al_T *localDW);
extern void top_level_alg_IfActionSubsystem(uint8_T *rty_Out1,
  P_IfActionSubsystem_top_level_T *localP);

#endif                                /* RTW_HEADER_top_level_algo_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
