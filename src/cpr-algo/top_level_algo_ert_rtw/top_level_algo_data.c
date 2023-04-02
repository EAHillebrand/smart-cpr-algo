/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo_data.c
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

#include "top_level_algo.h"

/* Block parameters (default storage) */
P_top_level_algo_T top_level_algo_P = {
  /* Variable: Vdd
   * Referenced by:
   *   '<S1>/Constant'
   *   '<S1>/rad  per volt'
   */
  3.0,

  /* Variable: gear_ratio
   * Referenced by: '<S1>/Gear Down'
   */
  10.0,

  /* Mask Parameter: TappedDelay1_vinit
   * Referenced by: '<S1>/Tapped Delay1'
   */
  0.0,

  /* Mask Parameter: TappedDelay_vinit
   * Referenced by: '<S1>/Tapped Delay'
   */
  0U,

  /* Expression: 0.005
   * Referenced by: '<Root>/Analog Input'
   */
  0.005,

  /* Expression: 4095
   * Referenced by: '<S1>/Constant1'
   */
  4095.0,

  /* Expression: 0
   * Referenced by: '<S1>/Switch'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S1>/Radius (mm)'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S2>/Constant'
   */
  0.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
