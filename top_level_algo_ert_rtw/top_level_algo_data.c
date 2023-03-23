/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo_data.c
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 3.24
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Mar 20 18:53:51 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "top_level_algo.h"

/* Block parameters (default storage) */
P_top_level_algo_T top_level_algo_P = {
  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S41>/Constant'
   */
  1.0F,

  /* Expression: 0
   * Referenced by: '<S2>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S40>/Constant1'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S2>/Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 120
   * Referenced by: '<Root>/Constant5'
   */
  120.0,

  /* Expression: 100
   * Referenced by: '<S1>/Constant1'
   */
  100.0,

  /* Expression: 10
   * Referenced by: '<S1>/Constant2'
   */
  10.0,

  /* Expression: 1
   * Referenced by: '<S2>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period
   * Referenced by: '<S2>/Pulse Generator'
   */
  4000.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<S2>/Pulse Generator'
   */
  8.0,

  /* Expression: 2
   * Referenced by: '<S2>/Pulse Generator'
   */
  2.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S40>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S40>/Unit Delay'
   */
  0.0,

  /* Computed Parameter: Delay8_InitialCondition
   * Referenced by: '<S2>/Delay8'
   */
  false,

  /* Computed Parameter: Delay7_InitialCondition
   * Referenced by: '<S2>/Delay7'
   */
  false,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S5>/Merge'
   */
  0U,

  /* Computed Parameter: Merge_InitialOutput_g
   * Referenced by: '<S4>/Merge'
   */
  0U,

  /* Computed Parameter: Merge_InitialOutput_n
   * Referenced by: '<S3>/Merge'
   */
  0U,

  /* Start of '<S5>/If Action Subsystem9' */
  {
    /* Expression: 0x0
     * Referenced by: '<S38>/Constant'
     */
    0U
  }
  ,

  /* End of '<S5>/If Action Subsystem9' */

  /* Start of '<S5>/If Action Subsystem10' */
  {
    /* Expression: 0x6F
     * Referenced by: '<S30>/Constant'
     */
    111U
  }
  ,

  /* End of '<S5>/If Action Subsystem10' */

  /* Start of '<S5>/If Action Subsystem8' */
  {
    /* Expression: 0x7F
     * Referenced by: '<S37>/Constant'
     */
    127U
  }
  ,

  /* End of '<S5>/If Action Subsystem8' */

  /* Start of '<S5>/If Action Subsystem7' */
  {
    /* Expression: 0x07
     * Referenced by: '<S36>/Constant'
     */
    7U
  }
  ,

  /* End of '<S5>/If Action Subsystem7' */

  /* Start of '<S5>/If Action Subsystem6' */
  {
    /* Expression: 0x7D
     * Referenced by: '<S35>/Constant'
     */
    125U
  }
  ,

  /* End of '<S5>/If Action Subsystem6' */

  /* Start of '<S5>/If Action Subsystem5' */
  {
    /* Expression: 0x6D
     * Referenced by: '<S34>/Constant'
     */
    109U
  }
  ,

  /* End of '<S5>/If Action Subsystem5' */

  /* Start of '<S5>/If Action Subsystem4' */
  {
    /* Expression: 0x66
     * Referenced by: '<S33>/Constant'
     */
    102U
  }
  ,

  /* End of '<S5>/If Action Subsystem4' */

  /* Start of '<S5>/If Action Subsystem3' */
  {
    /* Expression: 0x4F
     * Referenced by: '<S32>/Constant'
     */
    79U
  }
  ,

  /* End of '<S5>/If Action Subsystem3' */

  /* Start of '<S5>/If Action Subsystem2' */
  {
    /* Expression: 0x5B
     * Referenced by: '<S31>/Constant'
     */
    91U
  }
  ,

  /* End of '<S5>/If Action Subsystem2' */

  /* Start of '<S5>/If Action Subsystem1' */
  {
    /* Expression: 0x06
     * Referenced by: '<S29>/Constant'
     */
    6U
  }
  ,

  /* End of '<S5>/If Action Subsystem1' */

  /* Start of '<S5>/If Action Subsystem' */
  {
    /* Expression: 0x3F
     * Referenced by: '<S28>/Constant'
     */
    63U
  }
  ,

  /* End of '<S5>/If Action Subsystem' */

  /* Start of '<S4>/If Action Subsystem9' */
  {
    /* Expression: 0x0
     * Referenced by: '<S27>/Constant'
     */
    0U
  }
  ,

  /* End of '<S4>/If Action Subsystem9' */

  /* Start of '<S4>/If Action Subsystem10' */
  {
    /* Expression: 0x6F
     * Referenced by: '<S19>/Constant'
     */
    111U
  }
  ,

  /* End of '<S4>/If Action Subsystem10' */

  /* Start of '<S4>/If Action Subsystem8' */
  {
    /* Expression: 0x7F
     * Referenced by: '<S26>/Constant'
     */
    127U
  }
  ,

  /* End of '<S4>/If Action Subsystem8' */

  /* Start of '<S4>/If Action Subsystem7' */
  {
    /* Expression: 0x07
     * Referenced by: '<S25>/Constant'
     */
    7U
  }
  ,

  /* End of '<S4>/If Action Subsystem7' */

  /* Start of '<S4>/If Action Subsystem6' */
  {
    /* Expression: 0x7D
     * Referenced by: '<S24>/Constant'
     */
    125U
  }
  ,

  /* End of '<S4>/If Action Subsystem6' */

  /* Start of '<S4>/If Action Subsystem5' */
  {
    /* Expression: 0x6D
     * Referenced by: '<S23>/Constant'
     */
    109U
  }
  ,

  /* End of '<S4>/If Action Subsystem5' */

  /* Start of '<S4>/If Action Subsystem4' */
  {
    /* Expression: 0x66
     * Referenced by: '<S22>/Constant'
     */
    102U
  }
  ,

  /* End of '<S4>/If Action Subsystem4' */

  /* Start of '<S4>/If Action Subsystem3' */
  {
    /* Expression: 0x4F
     * Referenced by: '<S21>/Constant'
     */
    79U
  }
  ,

  /* End of '<S4>/If Action Subsystem3' */

  /* Start of '<S4>/If Action Subsystem2' */
  {
    /* Expression: 0x5B
     * Referenced by: '<S20>/Constant'
     */
    91U
  }
  ,

  /* End of '<S4>/If Action Subsystem2' */

  /* Start of '<S4>/If Action Subsystem1' */
  {
    /* Expression: 0x06
     * Referenced by: '<S18>/Constant'
     */
    6U
  }
  ,

  /* End of '<S4>/If Action Subsystem1' */

  /* Start of '<S4>/If Action Subsystem' */
  {
    /* Expression: 0x3F
     * Referenced by: '<S17>/Constant'
     */
    63U
  }
  ,

  /* End of '<S4>/If Action Subsystem' */

  /* Start of '<S3>/If Action Subsystem9' */
  {
    /* Expression: 0x0
     * Referenced by: '<S16>/Constant'
     */
    0U
  }
  ,

  /* End of '<S3>/If Action Subsystem9' */

  /* Start of '<S3>/If Action Subsystem10' */
  {
    /* Expression: 0x6F
     * Referenced by: '<S8>/Constant'
     */
    111U
  }
  ,

  /* End of '<S3>/If Action Subsystem10' */

  /* Start of '<S3>/If Action Subsystem8' */
  {
    /* Expression: 0x7F
     * Referenced by: '<S15>/Constant'
     */
    127U
  }
  ,

  /* End of '<S3>/If Action Subsystem8' */

  /* Start of '<S3>/If Action Subsystem7' */
  {
    /* Expression: 0x07
     * Referenced by: '<S14>/Constant'
     */
    7U
  }
  ,

  /* End of '<S3>/If Action Subsystem7' */

  /* Start of '<S3>/If Action Subsystem6' */
  {
    /* Expression: 0x7D
     * Referenced by: '<S13>/Constant'
     */
    125U
  }
  ,

  /* End of '<S3>/If Action Subsystem6' */

  /* Start of '<S3>/If Action Subsystem5' */
  {
    /* Expression: 0x6D
     * Referenced by: '<S12>/Constant'
     */
    109U
  }
  ,

  /* End of '<S3>/If Action Subsystem5' */

  /* Start of '<S3>/If Action Subsystem4' */
  {
    /* Expression: 0x66
     * Referenced by: '<S11>/Constant'
     */
    102U
  }
  ,

  /* End of '<S3>/If Action Subsystem4' */

  /* Start of '<S3>/If Action Subsystem3' */
  {
    /* Expression: 0x4F
     * Referenced by: '<S10>/Constant'
     */
    79U
  }
  ,

  /* End of '<S3>/If Action Subsystem3' */

  /* Start of '<S3>/If Action Subsystem2' */
  {
    /* Expression: 0x5B
     * Referenced by: '<S9>/Constant'
     */
    91U
  }
  ,

  /* End of '<S3>/If Action Subsystem2' */

  /* Start of '<S3>/If Action Subsystem1' */
  {
    /* Expression: 0x06
     * Referenced by: '<S7>/Constant'
     */
    6U
  }
  ,

  /* End of '<S3>/If Action Subsystem1' */

  /* Start of '<S3>/If Action Subsystem' */
  {
    /* Expression: 0x3F
     * Referenced by: '<S6>/Constant'
     */
    63U
  }
  /* End of '<S3>/If Action Subsystem' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
