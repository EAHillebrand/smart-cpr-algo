/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo_data.c
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 3.44
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Apr  6 16:11:01 2023
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
   *   '<S4>/Constant'
   *   '<S4>/rad  per volt'
   */
  3.0,

  /* Variable: gear_ratio
   * Referenced by: '<S4>/Gear Down'
   */
  10.0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S12>/Constant'
   */
  5.0,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S59>/Constant'
   */
  40.0,

  /* Mask Parameter: CompareToConstant2_const
   * Referenced by: '<S60>/Constant'
   */
  30.0,

  /* Mask Parameter: CompareToConstant3_const
   * Referenced by: '<S61>/Constant'
   */
  20.0,

  /* Mask Parameter: CompareToConstant4_const
   * Referenced by: '<S62>/Constant'
   */
  10.0,

  /* Mask Parameter: Positive_const
   * Referenced by: '<S54>/Constant'
   */
  0.0,

  /* Mask Parameter: Longrangemotionup_const
   * Referenced by: '<S52>/Constant'
   */
  3.0,

  /* Mask Parameter: Negative_const
   * Referenced by: '<S53>/Constant'
   */
  0.0,

  /* Mask Parameter: Longrangemotiondown_const
   * Referenced by: '<S51>/Constant'
   */
  -3.0,

  /* Mask Parameter: MaxBDC_vinit
   * Referenced by:
   *   '<S68>/Initial Condition'
   *   '<S68>/Memory'
   */
  0.0,

  /* Mask Parameter: MinBDC_vinit
   * Referenced by:
   *   '<S69>/Initial Condition'
   *   '<S69>/Memory'
   */
  100.0,

  /* Mask Parameter: TappedDelay1_vinit
   * Referenced by: '<S4>/Tapped Delay1'
   */
  0.0,

  /* Mask Parameter: TappedDelay_vinit
   * Referenced by: '<S3>/Tapped Delay'
   */
  0.0,

  /* Mask Parameter: CompareToConstant_const_f
   * Referenced by: '<S75>/Constant'
   */
  1.0F,

  /* Mask Parameter: TappedDelay_vinit_l
   * Referenced by: '<S4>/Tapped Delay'
   */
  0.0F,

  /* Expression: 0.005
   * Referenced by: '<Root>/Analog Input'
   */
  0.005,

  /* Expression: [0,0]
   * Referenced by: '<S1>/Constant'
   */
  { 0.0, 0.0 },

  /* Expression: 0.05
   * Referenced by: '<Root>/Digital Input'
   */
  0.05,

  /* Expression: 0
   * Referenced by: '<S9>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S74>/Constant1'
   */
  0.0,

  /* Expression: [0,0]
   * Referenced by: '<Root>/Constant3'
   */
  { 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<Root>/Constant1'
   */
  0.0,

  /* Expression: [0,0,0,0]
   * Referenced by: '<Root>/Constant2'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<S74>/Constant'
   */
  1.0,

  /* Expression: 0.0
   * Referenced by: '<S74>/Delay'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S9>/Delay'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S14>/Constant1'
   */
  100.0,

  /* Expression: 10
   * Referenced by: '<S14>/Constant2'
   */
  10.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Switch2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S9>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period
   * Referenced by: '<S9>/Pulse Generator'
   */
  400.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<S9>/Pulse Generator'
   */
  2.0,

  /* Expression: 2
   * Referenced by: '<S9>/Pulse Generator'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S1>/Switch'
   */
  0.0,

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

  /* Expression: 4095
   * Referenced by: '<S4>/Constant1'
   */
  4095.0,

  /* Expression: 0
   * Referenced by: '<S4>/Switch'
   */
  0.0,

  /* Expression: 103
   * Referenced by: '<S4>/Radius (mm)'
   */
  103.0,

  /* Expression: 0
   * Referenced by: '<S55>/Constant'
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
   * Referenced by: '<S3>/Delay'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S3>/Gain'
   */
  2.0,

  /* Expression: 0.0
   * Referenced by: '<S3>/Delay1'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S3>/Gain1'
   */
  2.0,

  /* Expression: 0.0
   * Referenced by: '<S3>/Delay2'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S3>/Delay3'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S3>/Delay4'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S3>/Delay5'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S3>/Compression  Sensitivity'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<S65>/Constant'
   */
  0.0,

  /* Computed Parameter: Constant_Value_p
   * Referenced by: '<S5>/Constant'
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

  /* Computed Parameter: TmpRTBAtChart1Inport2_InitialCo
   * Referenced by:
   */
  false,

  /* Computed Parameter: TmpRTBAtSummarizingInport6_Init
   * Referenced by:
   */
  false,

  /* Computed Parameter: Delay8_InitialCondition_o
   * Referenced by: '<S7>/Delay8'
   */
  false,

  /* Computed Parameter: Delay7_InitialCondition_o
   * Referenced by: '<S7>/Delay7'
   */
  false,

  /* Computed Parameter: Delay6_InitialCondition
   * Referenced by: '<S7>/Delay6'
   */
  true,

  /* Computed Parameter: Delay4_InitialCondition_f
   * Referenced by: '<S7>/Delay4'
   */
  false,

  /* Computed Parameter: Delay1_InitialCondition_d
   * Referenced by: '<S7>/Delay1'
   */
  false,

  /* Computed Parameter: Delay3_InitialCondition_k
   * Referenced by: '<S7>/Delay3'
   */
  true,

  /* Computed Parameter: Delay_InitialCondition_d
   * Referenced by: '<S7>/Delay'
   */
  false,

  /* Computed Parameter: Delay2_InitialCondition_c
   * Referenced by: '<S7>/Delay2'
   */
  false,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S17>/Merge'
   */
  0U,

  /* Computed Parameter: Merge_InitialOutput_o
   * Referenced by: '<S16>/Merge'
   */
  0U,

  /* Computed Parameter: Merge_InitialOutput_e
   * Referenced by: '<S15>/Merge'
   */
  0U,

  /* Start of '<S17>/If Action Subsystem9' */
  {
    /* Expression: 0x0
     * Referenced by: '<S50>/Constant'
     */
    0U
  }
  ,

  /* End of '<S17>/If Action Subsystem9' */

  /* Start of '<S17>/If Action Subsystem10' */
  {
    /* Expression: 0x6F
     * Referenced by: '<S42>/Constant'
     */
    111U
  }
  ,

  /* End of '<S17>/If Action Subsystem10' */

  /* Start of '<S17>/If Action Subsystem8' */
  {
    /* Expression: 0x7F
     * Referenced by: '<S49>/Constant'
     */
    127U
  }
  ,

  /* End of '<S17>/If Action Subsystem8' */

  /* Start of '<S17>/If Action Subsystem7' */
  {
    /* Expression: 0x07
     * Referenced by: '<S48>/Constant'
     */
    7U
  }
  ,

  /* End of '<S17>/If Action Subsystem7' */

  /* Start of '<S17>/If Action Subsystem6' */
  {
    /* Expression: 0x7D
     * Referenced by: '<S47>/Constant'
     */
    125U
  }
  ,

  /* End of '<S17>/If Action Subsystem6' */

  /* Start of '<S17>/If Action Subsystem5' */
  {
    /* Expression: 0x6D
     * Referenced by: '<S46>/Constant'
     */
    109U
  }
  ,

  /* End of '<S17>/If Action Subsystem5' */

  /* Start of '<S17>/If Action Subsystem4' */
  {
    /* Expression: 0x66
     * Referenced by: '<S45>/Constant'
     */
    102U
  }
  ,

  /* End of '<S17>/If Action Subsystem4' */

  /* Start of '<S17>/If Action Subsystem3' */
  {
    /* Expression: 0x4F
     * Referenced by: '<S44>/Constant'
     */
    79U
  }
  ,

  /* End of '<S17>/If Action Subsystem3' */

  /* Start of '<S17>/If Action Subsystem2' */
  {
    /* Expression: 0x5B
     * Referenced by: '<S43>/Constant'
     */
    91U
  }
  ,

  /* End of '<S17>/If Action Subsystem2' */

  /* Start of '<S17>/If Action Subsystem1' */
  {
    /* Expression: 0x06
     * Referenced by: '<S41>/Constant'
     */
    6U
  }
  ,

  /* End of '<S17>/If Action Subsystem1' */

  /* Start of '<S17>/If Action Subsystem' */
  {
    /* Expression: 0x3F
     * Referenced by: '<S40>/Constant'
     */
    63U
  }
  ,

  /* End of '<S17>/If Action Subsystem' */

  /* Start of '<S16>/If Action Subsystem9' */
  {
    /* Expression: 0x0
     * Referenced by: '<S39>/Constant'
     */
    0U
  }
  ,

  /* End of '<S16>/If Action Subsystem9' */

  /* Start of '<S16>/If Action Subsystem10' */
  {
    /* Expression: 0x6F
     * Referenced by: '<S31>/Constant'
     */
    111U
  }
  ,

  /* End of '<S16>/If Action Subsystem10' */

  /* Start of '<S16>/If Action Subsystem8' */
  {
    /* Expression: 0x7F
     * Referenced by: '<S38>/Constant'
     */
    127U
  }
  ,

  /* End of '<S16>/If Action Subsystem8' */

  /* Start of '<S16>/If Action Subsystem7' */
  {
    /* Expression: 0x07
     * Referenced by: '<S37>/Constant'
     */
    7U
  }
  ,

  /* End of '<S16>/If Action Subsystem7' */

  /* Start of '<S16>/If Action Subsystem6' */
  {
    /* Expression: 0x7D
     * Referenced by: '<S36>/Constant'
     */
    125U
  }
  ,

  /* End of '<S16>/If Action Subsystem6' */

  /* Start of '<S16>/If Action Subsystem5' */
  {
    /* Expression: 0x6D
     * Referenced by: '<S35>/Constant'
     */
    109U
  }
  ,

  /* End of '<S16>/If Action Subsystem5' */

  /* Start of '<S16>/If Action Subsystem4' */
  {
    /* Expression: 0x66
     * Referenced by: '<S34>/Constant'
     */
    102U
  }
  ,

  /* End of '<S16>/If Action Subsystem4' */

  /* Start of '<S16>/If Action Subsystem3' */
  {
    /* Expression: 0x4F
     * Referenced by: '<S33>/Constant'
     */
    79U
  }
  ,

  /* End of '<S16>/If Action Subsystem3' */

  /* Start of '<S16>/If Action Subsystem2' */
  {
    /* Expression: 0x5B
     * Referenced by: '<S32>/Constant'
     */
    91U
  }
  ,

  /* End of '<S16>/If Action Subsystem2' */

  /* Start of '<S16>/If Action Subsystem1' */
  {
    /* Expression: 0x06
     * Referenced by: '<S30>/Constant'
     */
    6U
  }
  ,

  /* End of '<S16>/If Action Subsystem1' */

  /* Start of '<S16>/If Action Subsystem' */
  {
    /* Expression: 0x3F
     * Referenced by: '<S29>/Constant'
     */
    63U
  }
  ,

  /* End of '<S16>/If Action Subsystem' */

  /* Start of '<S15>/If Action Subsystem9' */
  {
    /* Expression: 0x0
     * Referenced by: '<S28>/Constant'
     */
    0U
  }
  ,

  /* End of '<S15>/If Action Subsystem9' */

  /* Start of '<S15>/If Action Subsystem10' */
  {
    /* Expression: 0x6F
     * Referenced by: '<S20>/Constant'
     */
    111U
  }
  ,

  /* End of '<S15>/If Action Subsystem10' */

  /* Start of '<S15>/If Action Subsystem8' */
  {
    /* Expression: 0x7F
     * Referenced by: '<S27>/Constant'
     */
    127U
  }
  ,

  /* End of '<S15>/If Action Subsystem8' */

  /* Start of '<S15>/If Action Subsystem7' */
  {
    /* Expression: 0x07
     * Referenced by: '<S26>/Constant'
     */
    7U
  }
  ,

  /* End of '<S15>/If Action Subsystem7' */

  /* Start of '<S15>/If Action Subsystem6' */
  {
    /* Expression: 0x7D
     * Referenced by: '<S25>/Constant'
     */
    125U
  }
  ,

  /* End of '<S15>/If Action Subsystem6' */

  /* Start of '<S15>/If Action Subsystem5' */
  {
    /* Expression: 0x6D
     * Referenced by: '<S24>/Constant'
     */
    109U
  }
  ,

  /* End of '<S15>/If Action Subsystem5' */

  /* Start of '<S15>/If Action Subsystem4' */
  {
    /* Expression: 0x66
     * Referenced by: '<S23>/Constant'
     */
    102U
  }
  ,

  /* End of '<S15>/If Action Subsystem4' */

  /* Start of '<S15>/If Action Subsystem3' */
  {
    /* Expression: 0x4F
     * Referenced by: '<S22>/Constant'
     */
    79U
  }
  ,

  /* End of '<S15>/If Action Subsystem3' */

  /* Start of '<S15>/If Action Subsystem2' */
  {
    /* Expression: 0x5B
     * Referenced by: '<S21>/Constant'
     */
    91U
  }
  ,

  /* End of '<S15>/If Action Subsystem2' */

  /* Start of '<S15>/If Action Subsystem1' */
  {
    /* Expression: 0x06
     * Referenced by: '<S19>/Constant'
     */
    6U
  }
  ,

  /* End of '<S15>/If Action Subsystem1' */

  /* Start of '<S15>/If Action Subsystem' */
  {
    /* Expression: 0x3F
     * Referenced by: '<S18>/Constant'
     */
    63U
  }
  /* End of '<S15>/If Action Subsystem' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
