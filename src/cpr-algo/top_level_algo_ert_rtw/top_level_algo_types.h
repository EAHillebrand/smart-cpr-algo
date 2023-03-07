/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo_types.h
 *
 * Code generated for Simulink model 'top_level_algo'.
 *
 * Model version                  : 1.158
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Mon Mar  6 18:47:31 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_top_level_algo_types_h_
#define RTW_HEADER_top_level_algo_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
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
#ifndef struct_tag_AQAmVTLzTXfccnSnmJwAiF
#define struct_tag_AQAmVTLzTXfccnSnmJwAiF

struct tag_AQAmVTLzTXfccnSnmJwAiF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  uint16_T ADCInternalBuffer[4];
  ADC_Type_T* ADCHandle;
};

#endif                                 /* struct_tag_AQAmVTLzTXfccnSnmJwAiF */

#ifndef typedef_stm32cube_blocks_AnalogInput__T
#define typedef_stm32cube_blocks_AnalogInput__T

typedef struct tag_AQAmVTLzTXfccnSnmJwAiF stm32cube_blocks_AnalogInput__T;

#endif                             /* typedef_stm32cube_blocks_AnalogInput__T */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_top_level_algo_T
#define typedef_cell_wrap_top_level_algo_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_top_level_algo_T;

#endif                                 /* typedef_cell_wrap_top_level_algo_T */

#ifndef struct_tag_pXqB0JYFCgtuRHpfOp5C9
#define struct_tag_pXqB0JYFCgtuRHpfOp5C9

struct tag_pXqB0JYFCgtuRHpfOp5C9
{
  int32_T isInitialized;
  cell_wrap_top_level_algo_T inputVarSize;
};

#endif                                 /* struct_tag_pXqB0JYFCgtuRHpfOp5C9 */

#ifndef typedef_stm32cube_blocks_DigitalPortW_T
#define typedef_stm32cube_blocks_DigitalPortW_T

typedef struct tag_pXqB0JYFCgtuRHpfOp5C9 stm32cube_blocks_DigitalPortW_T;

#endif                             /* typedef_stm32cube_blocks_DigitalPortW_T */

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
