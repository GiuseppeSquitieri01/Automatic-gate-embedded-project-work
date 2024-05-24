/*
 * STATE_PROJECT_S3_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "STATE_PROJECT_S3".
 *
 * Model version              : 1.2
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Fri May 24 12:54:14 2024
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_STATE_PROJECT_S3_types_h_
#define RTW_HEADER_STATE_PROJECT_S3_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_slTestResult_
#define DEFINED_TYPEDEF_FOR_slTestResult_

typedef enum {
  slTestResult_Untested = -1,          /* Default value */
  slTestResult_Pass,
  slTestResult_Fail
} slTestResult;

#endif

/* Parameters (default storage) */
typedef struct P_STATE_PROJECT_S3_T_ P_STATE_PROJECT_S3_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_STATE_PROJECT_S3_T RT_MODEL_STATE_PROJECT_S3_T;

#endif                                /* RTW_HEADER_STATE_PROJECT_S3_types_h_ */
