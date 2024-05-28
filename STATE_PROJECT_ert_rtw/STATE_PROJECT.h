/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: STATE_PROJECT.h
 *
 * Code generated for Simulink model 'STATE_PROJECT'.
 *
 * Model version                  : 1.42
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sun May 26 09:44:30 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_STATE_PROJECT_h_
#define RTW_HEADER_STATE_PROJECT_h_
#ifndef STATE_PROJECT_COMMON_INCLUDES_
#define STATE_PROJECT_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* STATE_PROJECT_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T WORK_DUR;                     /* '<Root>/AutomaticGate' */
  real_T OPEN_DUR;                     /* '<Root>/AutomaticGate' */
  int32_T sfEvent;                     /* '<Root>/AutomaticGate' */
  uint32_T temporalCounter_i1;         /* '<Root>/AutomaticGate' */
  uint32_T temporalCounter_i2;         /* '<Root>/AutomaticGate' */
  uint8_T is_c2_STATE_PROJECT;         /* '<Root>/AutomaticGate' */
  uint8_T is_AUTOMATIC_GATE;           /* '<Root>/AutomaticGate' */
  uint8_T is_EMERGENCY_P1_CLOSED;      /* '<Root>/AutomaticGate' */
  uint8_T is_WORK_DUR_SETTING;         /* '<Root>/AutomaticGate' */
  uint8_T is_OPEN_DUR_SETTING;         /* '<Root>/AutomaticGate' */
  uint8_T is_OPENING;                  /* '<Root>/AutomaticGate' */
  uint8_T is_CLOSING;                  /* '<Root>/AutomaticGate' */
  uint8_T is_EMERGENCY_P1_OPEN;        /* '<Root>/AutomaticGate' */
  uint8_T is_B1;                       /* '<Root>/AutomaticGate' */
  uint8_T is_B3;                       /* '<Root>/AutomaticGate' */
  uint8_T is_B2;                       /* '<Root>/AutomaticGate' */
  uint8_T is_active_c2_STATE_PROJECT;  /* '<Root>/AutomaticGate' */
  uint8_T is_active_B1;                /* '<Root>/AutomaticGate' */
  uint8_T is_active_B3;                /* '<Root>/AutomaticGate' */
  uint8_T is_active_B2;                /* '<Root>/AutomaticGate' */
  uint8_T is_active_AUTOMATIC_GATE;    /* '<Root>/AutomaticGate' */
  uint8_T is_active_OPEN_DUR_SETTING;  /* '<Root>/AutomaticGate' */
  uint8_T is_active_WORK_DUR_SETTING;  /* '<Root>/AutomaticGate' */
} DW;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* Model entry point functions */
extern void STATE_PROJECT_initialize(void);
extern void STATE_PROJECT_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<Root>/Display1' : Unused code path elimination
 * Block '<Root>/Display2' : Unused code path elimination
 * Block '<Root>/Manual Switch' : Eliminated due to constant selection input
 * Block '<Root>/Manual Switch1' : Eliminated due to constant selection input
 * Block '<Root>/Manual Switch2' : Eliminated due to constant selection input
 * Block '<Root>/Manual Switch3' : Eliminated due to constant selection input
 * Block '<Root>/Manual Switch4' : Eliminated due to constant selection input
 * Block '<Root>/Constant1' : Unused code path elimination
 * Block '<Root>/Constant3' : Unused code path elimination
 * Block '<Root>/Constant5' : Unused code path elimination
 * Block '<Root>/Constant6' : Unused code path elimination
 * Block '<Root>/Constant9' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'STATE_PROJECT'
 * '<S1>'   : 'STATE_PROJECT/AutomaticGate'
 */
#endif                                 /* RTW_HEADER_STATE_PROJECT_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
