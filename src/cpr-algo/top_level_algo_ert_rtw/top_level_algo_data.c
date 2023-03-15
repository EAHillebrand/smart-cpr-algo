/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo_data.c
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

#include "top_level_algo.h"

/* Block parameters (default storage) */
P_top_level_algo_T top_level_algo_P = {
  /* Variable: Vdd
   * Referenced by:
   *   '<S6>/Constant'
   *   '<S6>/rad  per volt'
   */
  3.0,

  /* Variable: gear_ratio
   * Referenced by: '<S6>/Gear Down'
   */
  10.0,

  /* Mask Parameter: Longrangemotionup_const
   * Referenced by: '<S18>/Constant'
   */
  3.0,

  /* Mask Parameter: Positive_const
   * Referenced by: '<S20>/Constant'
   */
  0.0,

  /* Mask Parameter: Negative_const
   * Referenced by: '<S19>/Constant'
   */
  0.0,

  /* Mask Parameter: Longrangemotiondown_const
   * Referenced by: '<S17>/Constant'
   */
  -3.0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S25>/Constant'
   */
  50.0,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S26>/Constant'
   */
  40.0,

  /* Mask Parameter: CompareToConstant2_const
   * Referenced by: '<S27>/Constant'
   */
  30.0,

  /* Mask Parameter: CompareToConstant3_const
   * Referenced by: '<S28>/Constant'
   */
  20.0,

  /* Mask Parameter: CompareToConstant4_const
   * Referenced by: '<S29>/Constant'
   */
  10.0,

  /* Mask Parameter: MaxBDC_vinit
   * Referenced by:
   *   '<S50>/Initial Condition'
   *   '<S50>/Memory'
   */
  0.0,

  /* Mask Parameter: MinBDC_vinit
   * Referenced by:
   *   '<S51>/Initial Condition'
   *   '<S51>/Memory'
   */
  100.0,

  /* Mask Parameter: TappedDelay1_vinit
   * Referenced by: '<S6>/Tapped Delay1'
   */
  0.0,

  /* Mask Parameter: TappedDelay_vinit
   * Referenced by: '<S5>/Tapped Delay'
   */
  0.0,

  /* Mask Parameter: TappedDelay_vinit_l
   * Referenced by: '<S6>/Tapped Delay'
   */
  0,

  /* Mask Parameter: CompareToConstant_const_f
   * Referenced by: '<S90>/Constant'
   */
  1.0F,

  /* Expression: 0
   * Referenced by: '<S9>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S56>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S56>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S56>/Unit Delay'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S9>/Delay'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S5>/Compression  Sensitivity'
   */
  0.5,

  /* Expression: 4095
   * Referenced by: '<S6>/Constant1'
   */
  4095.0,

  /* Expression: 0
   * Referenced by: '<S6>/Switch'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S6>/Radius (mm)'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S21>/Constant'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<Root>/Gain1'
   */
  2.0,

  /* Expression: 0.0
   * Referenced by: '<S5>/Delay'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S5>/Gain'
   */
  2.0,

  /* Expression: 0.0
   * Referenced by: '<S5>/Delay1'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S5>/Gain1'
   */
  2.0,

  /* Expression: 0.0
   * Referenced by: '<S5>/Delay2'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S5>/Delay3'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S5>/Delay4'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S5>/Delay5'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S55>/Constant1'
   */
  100.0,

  /* Expression: 10
   * Referenced by: '<S55>/Constant2'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S47>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S9>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period
   * Referenced by: '<S9>/Pulse Generator'
   */
  300.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<S9>/Pulse Generator'
   */
  10.0,

  /* Expression: 2
   * Referenced by: '<S9>/Pulse Generator'
   */
  2.0,

  /* Computed Parameter: Delay8_InitialCondition
   * Referenced by: '<S9>/Delay8'
   */
  false,

  /* Computed Parameter: Delay7_InitialCondition
   * Referenced by: '<S9>/Delay7'
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

  /* Computed Parameter: Delay_InitialCondition_d
   * Referenced by: '<S8>/Delay'
   */
  false,

  /* Computed Parameter: Delay8_InitialCondition_o
   * Referenced by: '<S8>/Delay8'
   */
  false,

  /* Computed Parameter: Delay7_InitialCondition_o
   * Referenced by: '<S8>/Delay7'
   */
  false,

  /* Computed Parameter: Delay6_InitialCondition
   * Referenced by: '<S8>/Delay6'
   */
  true,

  /* Computed Parameter: Delay2_InitialCondition_c
   * Referenced by: '<S8>/Delay2'
   */
  false,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S57>/Merge'
   */
  0U,

  /* Computed Parameter: Merge_InitialOutput_p
   * Referenced by: '<S58>/Merge'
   */
  0U,

  /* Computed Parameter: Merge_InitialOutput_e
   * Referenced by: '<S59>/Merge'
   */
  0U,

  /* Start of '<S59>/If Action Subsystem10' */
  {
    /* Expression: 0x6F
     * Referenced by: '<S82>/Constant'
     */
    111U
  }
  ,

  /* End of '<S59>/If Action Subsystem10' */

  /* Start of '<S59>/If Action Subsystem8' */
  {
    /* Expression: 0x7F
     * Referenced by: '<S89>/Constant'
     */
    127U
  }
  ,

  /* End of '<S59>/If Action Subsystem8' */

  /* Start of '<S59>/If Action Subsystem7' */
  {
    /* Expression: 0x07
     * Referenced by: '<S88>/Constant'
     */
    7U
  }
  ,

  /* End of '<S59>/If Action Subsystem7' */

  /* Start of '<S59>/If Action Subsystem6' */
  {
    /* Expression: 0x7D
     * Referenced by: '<S87>/Constant'
     */
    125U
  }
  ,

  /* End of '<S59>/If Action Subsystem6' */

  /* Start of '<S59>/If Action Subsystem5' */
  {
    /* Expression: 0x6D
     * Referenced by: '<S86>/Constant'
     */
    109U
  }
  ,

  /* End of '<S59>/If Action Subsystem5' */

  /* Start of '<S59>/If Action Subsystem4' */
  {
    /* Expression: 0x66
     * Referenced by: '<S85>/Constant'
     */
    102U
  }
  ,

  /* End of '<S59>/If Action Subsystem4' */

  /* Start of '<S59>/If Action Subsystem3' */
  {
    /* Expression: 0x4F
     * Referenced by: '<S84>/Constant'
     */
    79U
  }
  ,

  /* End of '<S59>/If Action Subsystem3' */

  /* Start of '<S59>/If Action Subsystem2' */
  {
    /* Expression: 0x5B
     * Referenced by: '<S83>/Constant'
     */
    91U
  }
  ,

  /* End of '<S59>/If Action Subsystem2' */

  /* Start of '<S59>/If Action Subsystem1' */
  {
    /* Expression: 0x06
     * Referenced by: '<S81>/Constant'
     */
    6U
  }
  ,

  /* End of '<S59>/If Action Subsystem1' */

  /* Start of '<S59>/If Action Subsystem' */
  {
    /* Expression: 0x3F
     * Referenced by: '<S80>/Constant'
     */
    63U
  }
  ,

  /* End of '<S59>/If Action Subsystem' */

  /* Start of '<S58>/If Action Subsystem10' */
  {
    /* Expression: 0x6F
     * Referenced by: '<S72>/Constant'
     */
    111U
  }
  ,

  /* End of '<S58>/If Action Subsystem10' */

  /* Start of '<S58>/If Action Subsystem8' */
  {
    /* Expression: 0x7F
     * Referenced by: '<S79>/Constant'
     */
    127U
  }
  ,

  /* End of '<S58>/If Action Subsystem8' */

  /* Start of '<S58>/If Action Subsystem7' */
  {
    /* Expression: 0x07
     * Referenced by: '<S78>/Constant'
     */
    7U
  }
  ,

  /* End of '<S58>/If Action Subsystem7' */

  /* Start of '<S58>/If Action Subsystem6' */
  {
    /* Expression: 0x7D
     * Referenced by: '<S77>/Constant'
     */
    125U
  }
  ,

  /* End of '<S58>/If Action Subsystem6' */

  /* Start of '<S58>/If Action Subsystem5' */
  {
    /* Expression: 0x6D
     * Referenced by: '<S76>/Constant'
     */
    109U
  }
  ,

  /* End of '<S58>/If Action Subsystem5' */

  /* Start of '<S58>/If Action Subsystem4' */
  {
    /* Expression: 0x66
     * Referenced by: '<S75>/Constant'
     */
    102U
  }
  ,

  /* End of '<S58>/If Action Subsystem4' */

  /* Start of '<S58>/If Action Subsystem3' */
  {
    /* Expression: 0x4F
     * Referenced by: '<S74>/Constant'
     */
    79U
  }
  ,

  /* End of '<S58>/If Action Subsystem3' */

  /* Start of '<S58>/If Action Subsystem2' */
  {
    /* Expression: 0x5B
     * Referenced by: '<S73>/Constant'
     */
    91U
  }
  ,

  /* End of '<S58>/If Action Subsystem2' */

  /* Start of '<S58>/If Action Subsystem1' */
  {
    /* Expression: 0x06
     * Referenced by: '<S71>/Constant'
     */
    6U
  }
  ,

  /* End of '<S58>/If Action Subsystem1' */

  /* Start of '<S58>/If Action Subsystem' */
  {
    /* Expression: 0x3F
     * Referenced by: '<S70>/Constant'
     */
    63U
  }
  ,

  /* End of '<S58>/If Action Subsystem' */

  /* Start of '<S57>/If Action Subsystem10' */
  {
    /* Expression: 0x6F
     * Referenced by: '<S62>/Constant'
     */
    111U
  }
  ,

  /* End of '<S57>/If Action Subsystem10' */

  /* Start of '<S57>/If Action Subsystem8' */
  {
    /* Expression: 0x7F
     * Referenced by: '<S69>/Constant'
     */
    127U
  }
  ,

  /* End of '<S57>/If Action Subsystem8' */

  /* Start of '<S57>/If Action Subsystem7' */
  {
    /* Expression: 0x07
     * Referenced by: '<S68>/Constant'
     */
    7U
  }
  ,

  /* End of '<S57>/If Action Subsystem7' */

  /* Start of '<S57>/If Action Subsystem6' */
  {
    /* Expression: 0x7D
     * Referenced by: '<S67>/Constant'
     */
    125U
  }
  ,

  /* End of '<S57>/If Action Subsystem6' */

  /* Start of '<S57>/If Action Subsystem5' */
  {
    /* Expression: 0x6D
     * Referenced by: '<S66>/Constant'
     */
    109U
  }
  ,

  /* End of '<S57>/If Action Subsystem5' */

  /* Start of '<S57>/If Action Subsystem4' */
  {
    /* Expression: 0x66
     * Referenced by: '<S65>/Constant'
     */
    102U
  }
  ,

  /* End of '<S57>/If Action Subsystem4' */

  /* Start of '<S57>/If Action Subsystem3' */
  {
    /* Expression: 0x4F
     * Referenced by: '<S64>/Constant'
     */
    79U
  }
  ,

  /* End of '<S57>/If Action Subsystem3' */

  /* Start of '<S57>/If Action Subsystem2' */
  {
    /* Expression: 0x5B
     * Referenced by: '<S63>/Constant'
     */
    91U
  }
  ,

  /* End of '<S57>/If Action Subsystem2' */

  /* Start of '<S57>/If Action Subsystem1' */
  {
    /* Expression: 0x06
     * Referenced by: '<S61>/Constant'
     */
    6U
  }
  ,

  /* End of '<S57>/If Action Subsystem1' */

  /* Start of '<S57>/If Action Subsystem' */
  {
    /* Expression: 0x3F
     * Referenced by: '<S60>/Constant'
     */
    63U
  }
  /* End of '<S57>/If Action Subsystem' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
