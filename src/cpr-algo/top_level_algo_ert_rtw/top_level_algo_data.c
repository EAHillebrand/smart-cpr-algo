/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo_data.c
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 1.90
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Tue Jan 17 16:34:58 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "top_level_algo.h"
#include "top_level_algo_private.h"

/* Block parameters (default storage) */
P_top_level_algo_T top_level_algo_P = {
  /* Mask Parameter: Longrangemotionup_const
   * Referenced by: '<S5>/Constant'
   */
  3.0,

  /* Mask Parameter: Positive_const
   * Referenced by: '<S7>/Constant'
   */
  0.0,

  /* Mask Parameter: Negative_const
   * Referenced by: '<S6>/Constant'
   */
  0.0,

  /* Mask Parameter: Longrangemotiondown_const
   * Referenced by: '<S4>/Constant'
   */
  -3.0,

  /* Mask Parameter: MaxBDC_vinit
   * Referenced by:
   *   '<S17>/Initial Condition'
   *   '<S17>/Memory'
   */
  0.0,

  /* Mask Parameter: MinBDC_vinit
   * Referenced by:
   *   '<S18>/Initial Condition'
   *   '<S18>/Memory'
   */
  100.0,

  /* Mask Parameter: TappedDelay1_vinit
   * Referenced by: '<S2>/Tapped Delay1'
   */
  0.0,

  /* Mask Parameter: TappedDelay_vinit
   * Referenced by: '<S1>/Tapped Delay'
   */
  0.0,

  /* Mask Parameter: TappedDelay_vinit_l
   * Referenced by: '<S2>/Tapped Delay'
   */
  0U,

  /* Expression: -1
   * Referenced by: '<Root>/Analog Input1'
   */
  -1.0,

  /* Expression: 1024
   * Referenced by: '<S2>/Constant1'
   */
  1024.0,

  /* Expression: 5
   * Referenced by: '<S2>/Constant'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<S2>/Switch'
   */
  0.0,

  /* Expression: 720
   * Referenced by: '<S2>/degrees per volt'
   */
  720.0,

  /* Expression: pi/180
   * Referenced by: '<S2>/Convert to Radians'
   */
  0.017453292519943295,

  /* Expression: 15
   * Referenced by: '<S2>/Radius (mm)'
   */
  15.0,

  /* Expression: 0
   * Referenced by: '<S8>/Constant'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S1>/Delay'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S1>/Gain'
   */
  2.0,

  /* Expression: 0.0
   * Referenced by: '<S1>/Delay1'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S1>/Gain1'
   */
  2.0,

  /* Expression: 0.0
   * Referenced by: '<S1>/Delay2'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S1>/Delay3'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S1>/Delay4'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S1>/Delay5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S14>/Constant'
   */
  0.0,

  /* Computed Parameter: Delay4_InitialCondition_f
   * Referenced by: '<S3>/Delay4'
   */
  false,

  /* Computed Parameter: Delay1_InitialCondition_d
   * Referenced by: '<S3>/Delay1'
   */
  false,

  /* Computed Parameter: Delay3_InitialCondition_k
   * Referenced by: '<S3>/Delay3'
   */
  true,

  /* Computed Parameter: Delay_InitialCondition_d
   * Referenced by: '<S3>/Delay'
   */
  false,

  /* Computed Parameter: Delay8_InitialCondition
   * Referenced by: '<S3>/Delay8'
   */
  false,

  /* Computed Parameter: Delay7_InitialCondition
   * Referenced by: '<S3>/Delay7'
   */
  false,

  /* Computed Parameter: Delay6_InitialCondition
   * Referenced by: '<S3>/Delay6'
   */
  true,

  /* Computed Parameter: Delay2_InitialCondition_c
   * Referenced by: '<S3>/Delay2'
   */
  false
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
