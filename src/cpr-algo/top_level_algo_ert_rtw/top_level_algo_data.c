/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo_data.c
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 3.28
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sun Mar 26 15:35:11 2023
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
   *   '<S5>/Constant'
   *   '<S5>/rad  per volt'
   */
  3.0,

  /* Variable: gear_ratio
   * Referenced by: '<S5>/Gear Down'
   */
  10.0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S47>/Constant'
   */
  5.0,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S57>/Constant'
   */
  40.0,

  /* Mask Parameter: CompareToConstant2_const
   * Referenced by: '<S58>/Constant'
   */
  30.0,

  /* Mask Parameter: CompareToConstant3_const
   * Referenced by: '<S59>/Constant'
   */
  20.0,

  /* Mask Parameter: CompareToConstant4_const
   * Referenced by: '<S60>/Constant'
   */
  10.0,

  /* Mask Parameter: Positive_const
   * Referenced by: '<S52>/Constant'
   */
  0.0,

  /* Mask Parameter: Longrangemotionup_const
   * Referenced by: '<S50>/Constant'
   */
  3.0,

  /* Mask Parameter: Negative_const
   * Referenced by: '<S51>/Constant'
   */
  0.0,

  /* Mask Parameter: Longrangemotiondown_const
   * Referenced by: '<S49>/Constant'
   */
  -3.0,

  /* Mask Parameter: MaxBDC_vinit
   * Referenced by:
   *   '<S66>/Initial Condition'
   *   '<S66>/Memory'
   */
  0.0,

  /* Mask Parameter: MinBDC_vinit
   * Referenced by:
   *   '<S67>/Initial Condition'
   *   '<S67>/Memory'
   */
  100.0,

  /* Mask Parameter: TappedDelay1_vinit
   * Referenced by: '<S5>/Tapped Delay1'
   */
  0.0,

  /* Mask Parameter: TappedDelay_vinit
   * Referenced by: '<S4>/Tapped Delay'
   */
  0.0,

  /* Mask Parameter: TappedDelay_vinit_l
   * Referenced by: '<S5>/Tapped Delay'
   */
  0U,

  /* Mask Parameter: Counter1_InitialCount
   * Referenced by: '<S3>/Counter1'
   */
  0U,

  /* Expression: 0.005
   * Referenced by: '<Root>/Analog Input'
   */
  0.005,

  /* Expression: 0.05
   * Referenced by: '<Root>/Digital Input'
   */
  0.05,

  /* Expression: [0,0]
   * Referenced by: '<S2>/Constant'
   */
  { 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S2>/Switch'
   */
  0.0,

  /* Expression: [0,0]
   * Referenced by: '<Root>/Constant3'
   */
  { 0.0, 0.0 },

  /* Expression: [0,0,0,0]
   * Referenced by: '<Root>/Constant2'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Switch1'
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 0
   * Referenced by:
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

  /* Expression: 2
   * Referenced by: '<S1>/Pulse Generator'
   */
  2.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Switch2'
   */
  0.0,

  /* Expression: 4095
   * Referenced by: '<S5>/Constant1'
   */
  4095.0,

  /* Expression: 0
   * Referenced by: '<S5>/Switch'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S5>/Radius (mm)'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S53>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Switch'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S4>/Delay'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S4>/Gain'
   */
  2.0,

  /* Expression: 0.0
   * Referenced by: '<S4>/Delay1'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S4>/Gain1'
   */
  2.0,

  /* Expression: 0.0
   * Referenced by: '<S4>/Delay2'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S4>/Delay3'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S4>/Delay4'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S4>/Delay5'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S4>/Compression  Sensitivity'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<S3>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S63>/Constant'
   */
  0.0,

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<S1>/Constant4'
   */
  0,

  /* Computed Parameter: Constant_Value_at
   * Referenced by: '<S10>/Constant'
   */
  1U,

  /* Computed Parameter: Constant_Value_p
   * Referenced by: '<S6>/Constant'
   */
  false,

  /* Computed Parameter: TmpRTBAtChart1Inport2_InitialCo
   * Referenced by:
   */
  false,

  /* Computed Parameter: Delay8_InitialCondition
   * Referenced by: '<S8>/Delay8'
   */
  false,

  /* Computed Parameter: Delay7_InitialCondition
   * Referenced by: '<S8>/Delay7'
   */
  false,

  /* Computed Parameter: Delay6_InitialCondition
   * Referenced by: '<S8>/Delay6'
   */
  true,

  /* Computed Parameter: Delay_InitialCondition_d
   * Referenced by: '<S8>/Delay'
   */
  false,

  /* Computed Parameter: Delay4_InitialCondition_f
   * Referenced by: '<S8>/Delay4'
   */
  false,

  /* Computed Parameter: Delay1_InitialCondition_d
   * Referenced by: '<S8>/Delay1'
   */
  false,

  /* Computed Parameter: Delay3_InitialCondition_k
   * Referenced by: '<S8>/Delay3'
   */
  true,

  /* Computed Parameter: Delay2_InitialCondition_c
   * Referenced by: '<S8>/Delay2'
   */
  false,

  /* Computed Parameter: Gain_Gain_l
   * Referenced by: '<Root>/Gain'
   */
  200U,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S12>/Merge'
   */
  0U,

  /* Computed Parameter: Merge_InitialOutput_k
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
