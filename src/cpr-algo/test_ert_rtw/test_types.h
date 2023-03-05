/*
 * test_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "test".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Tue Feb  7 12:17:20 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_test_types_h_
#define RTW_HEADER_test_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_test_T
#define typedef_cell_wrap_test_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_test_T;

#endif                                 /* typedef_cell_wrap_test_T */

#ifndef struct_tag_pXqB0JYFCgtuRHpfOp5C9
#define struct_tag_pXqB0JYFCgtuRHpfOp5C9

struct tag_pXqB0JYFCgtuRHpfOp5C9
{
  int32_T isInitialized;
  cell_wrap_test_T inputVarSize;
};

#endif                                 /* struct_tag_pXqB0JYFCgtuRHpfOp5C9 */

#ifndef typedef_stm32cube_blocks_DigitalPortW_T
#define typedef_stm32cube_blocks_DigitalPortW_T

typedef struct tag_pXqB0JYFCgtuRHpfOp5C9 stm32cube_blocks_DigitalPortW_T;

#endif                             /* typedef_stm32cube_blocks_DigitalPortW_T */

/* Parameters (default storage) */
typedef struct P_test_T_ P_test_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_test_T RT_MODEL_test_T;

#endif                                 /* RTW_HEADER_test_types_h_ */
