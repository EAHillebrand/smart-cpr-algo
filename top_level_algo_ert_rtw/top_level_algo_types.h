/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: top_level_algo_types.h
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

#ifndef RTW_HEADER_top_level_algo_types_h_
#define RTW_HEADER_top_level_algo_types_h_
#include "rtwtypes.h"
#ifndef struct_tag_9aqKbsbsI7JI0RwgnVwU0C
#define struct_tag_9aqKbsbsI7JI0RwgnVwU0C

struct tag_9aqKbsbsI7JI0RwgnVwU0C
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_9aqKbsbsI7JI0RwgnVwU0C */

#ifndef typedef_b_arduinodriver_ArduinoDigita_T
#define typedef_b_arduinodriver_ArduinoDigita_T

typedef struct tag_9aqKbsbsI7JI0RwgnVwU0C b_arduinodriver_ArduinoDigita_T;

#endif                             /* typedef_b_arduinodriver_ArduinoDigita_T */

#ifndef struct_tag_qrLkTWTW64zZK0sqwALTyG
#define struct_tag_qrLkTWTW64zZK0sqwALTyG

struct tag_qrLkTWTW64zZK0sqwALTyG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_arduinodriver_ArduinoDigita_T DigitalIODriverObj;
};

#endif                                 /* struct_tag_qrLkTWTW64zZK0sqwALTyG */

#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct tag_qrLkTWTW64zZK0sqwALTyG codertarget_arduinobase_block_T;

#endif                             /* typedef_codertarget_arduinobase_block_T */

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

/* Parameters for system: '<S3>/If Action Subsystem' */
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
