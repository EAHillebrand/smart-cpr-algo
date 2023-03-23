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
 * C/C++ source code generated on : Mon Mar 20 19:10:56 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "top_level_algo.h"

/* Block parameters (default storage) */
P_top_level_algo_T top_level_algo_P = {
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

  /* Expression: 120
   * Referenced by: '<Root>/Constant5'
   */
  120.0,

  /* Expression: 100
   * Referenced by: '<S2>/Constant1'
   */
  100.0,

  /* Expression: 10
   * Referenced by: '<S2>/Constant2'
   */
  10.0,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S4>/Merge'
   */
  0U,

  /* Computed Parameter: Merge_InitialOutput_k
   * Referenced by: '<S5>/Merge'
   */
  0U,

  /* Computed Parameter: Merge_InitialOutput_j
   * Referenced by: '<S6>/Merge'
   */
  0U,

  /* Start of '<S6>/If Action Subsystem10' */
  {
    /* Expression: 0x6F
     * Referenced by: '<S29>/Constant'
     */
    111U
  }
  ,

  /* End of '<S6>/If Action Subsystem10' */

  /* Start of '<S6>/If Action Subsystem8' */
  {
    /* Expression: 0x7F
     * Referenced by: '<S36>/Constant'
     */
    127U
  }
  ,

  /* End of '<S6>/If Action Subsystem8' */

  /* Start of '<S6>/If Action Subsystem7' */
  {
    /* Expression: 0x07
     * Referenced by: '<S35>/Constant'
     */
    7U
  }
  ,

  /* End of '<S6>/If Action Subsystem7' */

  /* Start of '<S6>/If Action Subsystem6' */
  {
    /* Expression: 0x7D
     * Referenced by: '<S34>/Constant'
     */
    125U
  }
  ,

  /* End of '<S6>/If Action Subsystem6' */

  /* Start of '<S6>/If Action Subsystem5' */
  {
    /* Expression: 0x6D
     * Referenced by: '<S33>/Constant'
     */
    109U
  }
  ,

  /* End of '<S6>/If Action Subsystem5' */

  /* Start of '<S6>/If Action Subsystem4' */
  {
    /* Expression: 0x66
     * Referenced by: '<S32>/Constant'
     */
    102U
  }
  ,

  /* End of '<S6>/If Action Subsystem4' */

  /* Start of '<S6>/If Action Subsystem3' */
  {
    /* Expression: 0x4F
     * Referenced by: '<S31>/Constant'
     */
    79U
  }
  ,

  /* End of '<S6>/If Action Subsystem3' */

  /* Start of '<S6>/If Action Subsystem2' */
  {
    /* Expression: 0x5B
     * Referenced by: '<S30>/Constant'
     */
    91U
  }
  ,

  /* End of '<S6>/If Action Subsystem2' */

  /* Start of '<S6>/If Action Subsystem1' */
  {
    /* Expression: 0x06
     * Referenced by: '<S28>/Constant'
     */
    6U
  }
  ,

  /* End of '<S6>/If Action Subsystem1' */

  /* Start of '<S6>/If Action Subsystem' */
  {
    /* Expression: 0x3F
     * Referenced by: '<S27>/Constant'
     */
    63U
  }
  ,

  /* End of '<S6>/If Action Subsystem' */

  /* Start of '<S5>/If Action Subsystem10' */
  {
    /* Expression: 0x6F
     * Referenced by: '<S19>/Constant'
     */
    111U
  }
  ,

  /* End of '<S5>/If Action Subsystem10' */

  /* Start of '<S5>/If Action Subsystem8' */
  {
    /* Expression: 0x7F
     * Referenced by: '<S26>/Constant'
     */
    127U
  }
  ,

  /* End of '<S5>/If Action Subsystem8' */

  /* Start of '<S5>/If Action Subsystem7' */
  {
    /* Expression: 0x07
     * Referenced by: '<S25>/Constant'
     */
    7U
  }
  ,

  /* End of '<S5>/If Action Subsystem7' */

  /* Start of '<S5>/If Action Subsystem6' */
  {
    /* Expression: 0x7D
     * Referenced by: '<S24>/Constant'
     */
    125U
  }
  ,

  /* End of '<S5>/If Action Subsystem6' */

  /* Start of '<S5>/If Action Subsystem5' */
  {
    /* Expression: 0x6D
     * Referenced by: '<S23>/Constant'
     */
    109U
  }
  ,

  /* End of '<S5>/If Action Subsystem5' */

  /* Start of '<S5>/If Action Subsystem4' */
  {
    /* Expression: 0x66
     * Referenced by: '<S22>/Constant'
     */
    102U
  }
  ,

  /* End of '<S5>/If Action Subsystem4' */

  /* Start of '<S5>/If Action Subsystem3' */
  {
    /* Expression: 0x4F
     * Referenced by: '<S21>/Constant'
     */
    79U
  }
  ,

  /* End of '<S5>/If Action Subsystem3' */

  /* Start of '<S5>/If Action Subsystem2' */
  {
    /* Expression: 0x5B
     * Referenced by: '<S20>/Constant'
     */
    91U
  }
  ,

  /* End of '<S5>/If Action Subsystem2' */

  /* Start of '<S5>/If Action Subsystem1' */
  {
    /* Expression: 0x06
     * Referenced by: '<S18>/Constant'
     */
    6U
  }
  ,

  /* End of '<S5>/If Action Subsystem1' */

  /* Start of '<S5>/If Action Subsystem' */
  {
    /* Expression: 0x3F
     * Referenced by: '<S17>/Constant'
     */
    63U
  }
  ,

  /* End of '<S5>/If Action Subsystem' */

  /* Start of '<S4>/If Action Subsystem10' */
  {
    /* Expression: 0x6F
     * Referenced by: '<S9>/Constant'
     */
    111U
  }
  ,

  /* End of '<S4>/If Action Subsystem10' */

  /* Start of '<S4>/If Action Subsystem8' */
  {
    /* Expression: 0x7F
     * Referenced by: '<S16>/Constant'
     */
    127U
  }
  ,

  /* End of '<S4>/If Action Subsystem8' */

  /* Start of '<S4>/If Action Subsystem7' */
  {
    /* Expression: 0x07
     * Referenced by: '<S15>/Constant'
     */
    7U
  }
  ,

  /* End of '<S4>/If Action Subsystem7' */

  /* Start of '<S4>/If Action Subsystem6' */
  {
    /* Expression: 0x7D
     * Referenced by: '<S14>/Constant'
     */
    125U
  }
  ,

  /* End of '<S4>/If Action Subsystem6' */

  /* Start of '<S4>/If Action Subsystem5' */
  {
    /* Expression: 0x6D
     * Referenced by: '<S13>/Constant'
     */
    109U
  }
  ,

  /* End of '<S4>/If Action Subsystem5' */

  /* Start of '<S4>/If Action Subsystem4' */
  {
    /* Expression: 0x66
     * Referenced by: '<S12>/Constant'
     */
    102U
  }
  ,

  /* End of '<S4>/If Action Subsystem4' */

  /* Start of '<S4>/If Action Subsystem3' */
  {
    /* Expression: 0x4F
     * Referenced by: '<S11>/Constant'
     */
    79U
  }
  ,

  /* End of '<S4>/If Action Subsystem3' */

  /* Start of '<S4>/If Action Subsystem2' */
  {
    /* Expression: 0x5B
     * Referenced by: '<S10>/Constant'
     */
    91U
  }
  ,

  /* End of '<S4>/If Action Subsystem2' */

  /* Start of '<S4>/If Action Subsystem1' */
  {
    /* Expression: 0x06
     * Referenced by: '<S8>/Constant'
     */
    6U
  }
  ,

  /* End of '<S4>/If Action Subsystem1' */

  /* Start of '<S4>/If Action Subsystem' */
  {
    /* Expression: 0x3F
     * Referenced by: '<S7>/Constant'
     */
    63U
  }
  /* End of '<S4>/If Action Subsystem' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
