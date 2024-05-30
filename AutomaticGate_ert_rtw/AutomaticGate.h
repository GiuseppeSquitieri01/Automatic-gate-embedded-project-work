/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AutomaticGate.h
 *
 * Code generated for Simulink model 'AutomaticGate'.
 *
 * Model version                  : 1.44
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu May 30 09:24:38 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_AutomaticGate_h_
#define RTW_HEADER_AutomaticGate_h_
#ifndef AutomaticGate_COMMON_INCLUDES_
#define AutomaticGate_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* AutomaticGate_COMMON_INCLUDES_ */

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
  uint8_T is_c2_AutomaticGate;         /* '<Root>/AutomaticGate' */
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
  uint8_T is_active_c2_AutomaticGate;  /* '<Root>/AutomaticGate' */
  uint8_T is_active_B1;                /* '<Root>/AutomaticGate' */
  uint8_T is_active_B3;                /* '<Root>/AutomaticGate' */
  uint8_T is_active_B2;                /* '<Root>/AutomaticGate' */
  uint8_T is_active_AUTOMATIC_GATE;    /* '<Root>/AutomaticGate' */
  uint8_T is_active_OPEN_DUR_SETTING;  /* '<Root>/AutomaticGate' */
  uint8_T is_active_WORK_DUR_SETTING;  /* '<Root>/AutomaticGate' */
  uint8_T temporalCounter_i2;          /* '<Root>/AutomaticGate' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  boolean_T B1;                        /* '<Root>/B1' */
  boolean_T B2;                        /* '<Root>/B2' */
  boolean_T B3;                        /* '<Root>/B3' */
  boolean_T P1;                        /* '<Root>/P1' */
  boolean_T P2;                        /* '<Root>/P2' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T Red_Led;                   /* '<Root>/Red_Led' */
  boolean_T Green_Led;                 /* '<Root>/Green_Led' */
  boolean_T Yellow_Led;                /* '<Root>/Yellow_Led' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void AutomaticGate_initialize(void);
extern void AutomaticGate_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('STATE_PROJECT/AutomaticGate')    - opens subsystem STATE_PROJECT/AutomaticGate
 * hilite_system('STATE_PROJECT/AutomaticGate/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'STATE_PROJECT'
 * '<S1>'   : 'STATE_PROJECT/AutomaticGate'
 */
#endif                                 /* RTW_HEADER_AutomaticGate_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
