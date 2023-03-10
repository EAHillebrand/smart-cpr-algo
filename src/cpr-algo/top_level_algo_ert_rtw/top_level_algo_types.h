/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo_types.h
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 3.4
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Mar  9 17:14:06 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_top_level_algo_types_h_
#define RTW_HEADER_top_level_algo_types_h_
#include "rtwtypes.h"
#include "stm_adc_ll.h"
#ifndef struct_tag_vboetmpsA6pP5KWZSA57JC
#define struct_tag_vboetmpsA6pP5KWZSA57JC

struct tag_vboetmpsA6pP5KWZSA57JC
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_vboetmpsA6pP5KWZSA57JC */

#ifndef typedef_fixed_system_DivideByConstant_T
#define typedef_fixed_system_DivideByConstant_T

typedef struct tag_vboetmpsA6pP5KWZSA57JC fixed_system_DivideByConstant_T;

#endif                             /* typedef_fixed_system_DivideByConstant_T */

/* Custom Type definition for MATLABSystem: '<S48>/Analog to Digital Converter' */
#include "stm_adc_ll.h"
#include "stm_adc_ll.h"
#ifndef struct_tag_S5MMpcz8vT0FlmhmEl4q5C
#define struct_tag_S5MMpcz8vT0FlmhmEl4q5C

struct tag_S5MMpcz8vT0FlmhmEl4q5C
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_S5MMpcz8vT0FlmhmEl4q5C */

#ifndef typedef_stm32cube_blocks_DigitalPortW_T
#define typedef_stm32cube_blocks_DigitalPortW_T

typedef struct tag_S5MMpcz8vT0FlmhmEl4q5C stm32cube_blocks_DigitalPortW_T;

#endif                             /* typedef_stm32cube_blocks_DigitalPortW_T */

#ifndef struct_tag_eNlr4mnkAt8yejvnq8gf4D
#define struct_tag_eNlr4mnkAt8yejvnq8gf4D

struct tag_eNlr4mnkAt8yejvnq8gf4D
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  ADC_Type_T* ADCHandle;
  uint16_T ADCInternalBuffer[2];
};

#endif                                 /* struct_tag_eNlr4mnkAt8yejvnq8gf4D */

#ifndef typedef_stm32cube_blocks_AnalogInput__T
#define typedef_stm32cube_blocks_AnalogInput__T

typedef struct tag_eNlr4mnkAt8yejvnq8gf4D stm32cube_blocks_AnalogInput__T;

#endif                             /* typedef_stm32cube_blocks_AnalogInput__T */

/* Parameters for system: '<S12>/If Action Subsystem' */
typedef struct P_IfActionSubsystem_top_level_T_ P_IfActionSubsystem_top_level_T;

/* Parameters (default storage) */
typedef struct P_top_level_algo_T_ P_top_level_algo_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_top_level_algo_T RT_MODEL_top_level_algo_T;

#endif                                 /* RTW_HEADER_top_level_algo_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
