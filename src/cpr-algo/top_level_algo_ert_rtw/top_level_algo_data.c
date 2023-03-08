/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo_data.c
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 3.0
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Mar  8 13:21:33 2023
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
   *   '<S7>/Constant'
   *   '<S7>/rad  per volt'
   */
  3.0,

  /* Variable: gear_ratio
   * Referenced by: '<S7>/Gear Down'
   */
  10.0,

  /* Mask Parameter: Longrangemotionup_const
   * Referenced by: '<S55>/Constant'
   */
  3.0,

  /* Mask Parameter: Positive_const
   * Referenced by: '<S57>/Constant'
   */
  0.0,

  /* Mask Parameter: Negative_const
   * Referenced by: '<S56>/Constant'
   */
  0.0,

  /* Mask Parameter: Longrangemotiondown_const
   * Referenced by: '<S54>/Constant'
   */
  -3.0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S62>/Constant'
   */
  50.0,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S63>/Constant'
   */
  40.0,

  /* Mask Parameter: CompareToConstant2_const
   * Referenced by: '<S64>/Constant'
   */
  30.0,

  /* Mask Parameter: CompareToConstant3_const
   * Referenced by: '<S65>/Constant'
   */
  20.0,

  /* Mask Parameter: CompareToConstant4_const
   * Referenced by: '<S66>/Constant'
   */
  10.0,

  /* Mask Parameter: MaxBDC_vinit
   * Referenced by:
   *   '<S87>/Initial Condition'
   *   '<S87>/Memory'
   */
  0.0,

  /* Mask Parameter: MinBDC_vinit
   * Referenced by:
   *   '<S88>/Initial Condition'
   *   '<S88>/Memory'
   */
  100.0,

  /* Mask Parameter: TappedDelay_vinit
   * Referenced by: '<S3>/Tapped Delay'
   */
  0.0,

  /* Mask Parameter: TappedDelay1_vinit
   * Referenced by: '<S7>/Tapped Delay1'
   */
  0.0,

  /* Mask Parameter: TappedDelay_vinit_f
   * Referenced by: '<S6>/Tapped Delay'
   */
  0.0,

  /* Mask Parameter: TappedDelay_vinit_l
   * Referenced by: '<S7>/Tapped Delay'
   */
  0,

  /* Expression: 2
   * Referenced by: '<S6>/Compression  Sensitivity'
   */
  2.0,

  /* Expression: 4095
   * Referenced by: '<S7>/Constant1'
   */
  4095.0,

  /* Expression: 0
   * Referenced by: '<S7>/Switch'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S7>/Radius (mm)'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S58>/Constant'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S6>/Delay'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S6>/Gain'
   */
  2.0,

  /* Expression: 0.0
   * Referenced by: '<S6>/Delay1'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S6>/Gain1'
   */
  2.0,

  /* Expression: 0.0
   * Referenced by: '<S6>/Delay2'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S6>/Delay3'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S6>/Delay4'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S6>/Delay5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S84>/Constant'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S10>/Constant1'
   */
  100.0,

  /* Expression: 10
   * Referenced by: '<S10>/Constant2'
   */
  10.0,

  /* Expression: 1
   * Referenced by: '<S1>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period
   * Referenced by: '<S1>/Pulse Generator'
   */
  1000.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<S1>/Pulse Generator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Pulse Generator'
   */
  0.0,

  /* Computed Parameter: Delay4_InitialCondition_f
   * Referenced by: '<S9>/Delay4'
   */
  false,

  /* Computed Parameter: Delay1_InitialCondition_d
   * Referenced by: '<S9>/Delay1'
   */
  false,

  /* Computed Parameter: Delay3_InitialCondition_k
   * Referenced by: '<S9>/Delay3'
   */
  true,

  /* Computed Parameter: Delay_InitialCondition_d
   * Referenced by: '<S9>/Delay'
   */
  false,

  /* Computed Parameter: Delay8_InitialCondition
   * Referenced by: '<S9>/Delay8'
   */
  false,

  /* Computed Parameter: Delay7_InitialCondition
   * Referenced by: '<S9>/Delay7'
   */
  false,

  /* Computed Parameter: Delay6_InitialCondition
   * Referenced by: '<S9>/Delay6'
   */
  true,

  /* Computed Parameter: Delay2_InitialCondition_c
   * Referenced by: '<S9>/Delay2'
   */
  false,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S12>/Merge'
   */
  0U,

  /* Computed Parameter: Merge_InitialOutput_i
   * Referenced by: '<S13>/Merge'
   */
  0U,

  /* Computed Parameter: Merge_InitialOutput_j
   * Referenced by: '<S14>/Merge'
   */
  0U,

  /* Start of '<S14>/If Action Subsystem10' */
  {
    /* Expression: 0x6F
     * Referenced by: '<S37>/Constant'
     */
    111U
  }
  ,

  /* End of '<S14>/If Action Subsystem10' */

  /* Start of '<S14>/If Action Subsystem8' */
  {
    /* Expression: 0x7F
     * Referenced by: '<S44>/Constant'
     */
    127U
  }
  ,

  /* End of '<S14>/If Action Subsystem8' */

  /* Start of '<S14>/If Action Subsystem7' */
  {
    /* Expression: 0x07
     * Referenced by: '<S43>/Constant'
     */
    7U
  }
  ,

  /* End of '<S14>/If Action Subsystem7' */

  /* Start of '<S14>/If Action Subsystem6' */
  {
    /* Expression: 0x7D
     * Referenced by: '<S42>/Constant'
     */
    125U
  }
  ,

  /* End of '<S14>/If Action Subsystem6' */

  /* Start of '<S14>/If Action Subsystem5' */
  {
    /* Expression: 0x6D
     * Referenced by: '<S41>/Constant'
     */
    109U
  }
  ,

  /* End of '<S14>/If Action Subsystem5' */

  /* Start of '<S14>/If Action Subsystem4' */
  {
    /* Expression: 0x66
     * Referenced by: '<S40>/Constant'
     */
    102U
  }
  ,

  /* End of '<S14>/If Action Subsystem4' */

  /* Start of '<S14>/If Action Subsystem3' */
  {
    /* Expression: 0x4F
     * Referenced by: '<S39>/Constant'
     */
    79U
  }
  ,

  /* End of '<S14>/If Action Subsystem3' */

  /* Start of '<S14>/If Action Subsystem2' */
  {
    /* Expression: 0x5B
     * Referenced by: '<S38>/Constant'
     */
    91U
  }
  ,

  /* End of '<S14>/If Action Subsystem2' */

  /* Start of '<S14>/If Action Subsystem1' */
  {
    /* Expression: 0x06
     * Referenced by: '<S36>/Constant'
     */
    6U
  }
  ,

  /* End of '<S14>/If Action Subsystem1' */

  /* Start of '<S14>/If Action Subsystem' */
  {
    /* Expression: 0x3F
     * Referenced by: '<S35>/Constant'
     */
    63U
  }
  ,

  /* End of '<S14>/If Action Subsystem' */

  /* Start of '<S13>/If Action Subsystem10' */
  {
    /* Expression: 0x6F
     * Referenced by: '<S27>/Constant'
     */
    111U
  }
  ,

  /* End of '<S13>/If Action Subsystem10' */

  /* Start of '<S13>/If Action Subsystem8' */
  {
    /* Expression: 0x7F
     * Referenced by: '<S34>/Constant'
     */
    127U
  }
  ,

  /* End of '<S13>/If Action Subsystem8' */

  /* Start of '<S13>/If Action Subsystem7' */
  {
    /* Expression: 0x07
     * Referenced by: '<S33>/Constant'
     */
    7U
  }
  ,

  /* End of '<S13>/If Action Subsystem7' */

  /* Start of '<S13>/If Action Subsystem6' */
  {
    /* Expression: 0x7D
     * Referenced by: '<S32>/Constant'
     */
    125U
  }
  ,

  /* End of '<S13>/If Action Subsystem6' */

  /* Start of '<S13>/If Action Subsystem5' */
  {
    /* Expression: 0x6D
     * Referenced by: '<S31>/Constant'
     */
    109U
  }
  ,

  /* End of '<S13>/If Action Subsystem5' */

  /* Start of '<S13>/If Action Subsystem4' */
  {
    /* Expression: 0x66
     * Referenced by: '<S30>/Constant'
     */
    102U
  }
  ,

  /* End of '<S13>/If Action Subsystem4' */

  /* Start of '<S13>/If Action Subsystem3' */
  {
    /* Expression: 0x4F
     * Referenced by: '<S29>/Constant'
     */
    79U
  }
  ,

  /* End of '<S13>/If Action Subsystem3' */

  /* Start of '<S13>/If Action Subsystem2' */
  {
    /* Expression: 0x5B
     * Referenced by: '<S28>/Constant'
     */
    91U
  }
  ,

  /* End of '<S13>/If Action Subsystem2' */

  /* Start of '<S13>/If Action Subsystem1' */
  {
    /* Expression: 0x06
     * Referenced by: '<S26>/Constant'
     */
    6U
  }
  ,

  /* End of '<S13>/If Action Subsystem1' */

  /* Start of '<S13>/If Action Subsystem' */
  {
    /* Expression: 0x3F
     * Referenced by: '<S25>/Constant'
     */
    63U
  }
  ,

  /* End of '<S13>/If Action Subsystem' */

  /* Start of '<S12>/If Action Subsystem10' */
  {
    /* Expression: 0x6F
     * Referenced by: '<S17>/Constant'
     */
    111U
  }
  ,

  /* End of '<S12>/If Action Subsystem10' */

  /* Start of '<S12>/If Action Subsystem8' */
  {
    /* Expression: 0x7F
     * Referenced by: '<S24>/Constant'
     */
    127U
  }
  ,

  /* End of '<S12>/If Action Subsystem8' */

  /* Start of '<S12>/If Action Subsystem7' */
  {
    /* Expression: 0x07
     * Referenced by: '<S23>/Constant'
     */
    7U
  }
  ,

  /* End of '<S12>/If Action Subsystem7' */

  /* Start of '<S12>/If Action Subsystem6' */
  {
    /* Expression: 0x7D
     * Referenced by: '<S22>/Constant'
     */
    125U
  }
  ,

  /* End of '<S12>/If Action Subsystem6' */

  /* Start of '<S12>/If Action Subsystem5' */
  {
    /* Expression: 0x6D
     * Referenced by: '<S21>/Constant'
     */
    109U
  }
  ,

  /* End of '<S12>/If Action Subsystem5' */

  /* Start of '<S12>/If Action Subsystem4' */
  {
    /* Expression: 0x66
     * Referenced by: '<S20>/Constant'
     */
    102U
  }
  ,

  /* End of '<S12>/If Action Subsystem4' */

  /* Start of '<S12>/If Action Subsystem3' */
  {
    /* Expression: 0x4F
     * Referenced by: '<S19>/Constant'
     */
    79U
  }
  ,

  /* End of '<S12>/If Action Subsystem3' */

  /* Start of '<S12>/If Action Subsystem2' */
  {
    /* Expression: 0x5B
     * Referenced by: '<S18>/Constant'
     */
    91U
  }
  ,

  /* End of '<S12>/If Action Subsystem2' */

  /* Start of '<S12>/If Action Subsystem1' */
  {
    /* Expression: 0x06
     * Referenced by: '<S16>/Constant'
     */
    6U
  }
  ,

  /* End of '<S12>/If Action Subsystem1' */

  /* Start of '<S12>/If Action Subsystem' */
  {
    /* Expression: 0x3F
     * Referenced by: '<S15>/Constant'
     */
    63U
  }
  /* End of '<S12>/If Action Subsystem' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
