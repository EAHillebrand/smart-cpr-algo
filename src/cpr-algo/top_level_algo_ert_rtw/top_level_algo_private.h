/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo_private.h
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 3.40
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Apr  1 11:05:00 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_top_level_algo_private_h_
#define RTW_HEADER_top_level_algo_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "top_level_algo_types.h"
#include "top_level_algo.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator);

#endif                                /* RTW_HEADER_top_level_algo_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
