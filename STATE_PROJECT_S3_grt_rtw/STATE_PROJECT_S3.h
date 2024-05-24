/*
 * STATE_PROJECT_S3.h
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

#ifndef RTW_HEADER_STATE_PROJECT_S3_h_
#define RTW_HEADER_STATE_PROJECT_S3_h_
#ifndef STATE_PROJECT_S3_COMMON_INCLUDES_
#define STATE_PROJECT_S3_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* STATE_PROJECT_S3_COMMON_INCLUDES_ */

#include "STATE_PROJECT_S3_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include <float.h>
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T B1;                           /* '<Root>/Test Sequence' */
  real_T B2;                           /* '<Root>/Test Sequence' */
  real_T B3;                           /* '<Root>/Test Sequence' */
  real_T P1;                           /* '<Root>/Test Sequence' */
  real_T P2;                           /* '<Root>/Test Sequence' */
} B_STATE_PROJECT_S3_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T WORK_DUR;                     /* '<Root>/AutomaticGate' */
  real_T OPEN_DUR;                     /* '<Root>/AutomaticGate' */
  int32_T sfEvent;                     /* '<Root>/AutomaticGate' */
  uint32_T temporalCounter_i1;         /* '<Root>/AutomaticGate' */
  uint16_T temporalCounter_i2;         /* '<Root>/AutomaticGate' */
  uint8_T is_c4_STATE_PROJECT_S3;      /* '<Root>/Test Sequence' */
  uint8_T is_active_c4_STATE_PROJECT_S3;/* '<Root>/Test Sequence' */
  uint8_T temporalCounter_i1_o;        /* '<Root>/Test Sequence' */
  uint8_T is_c1_STATE_PROJECT_S3;      /* '<Root>/AutomaticGate' */
  uint8_T is_EMERGENCY_P1_CLOSED;      /* '<Root>/AutomaticGate' */
  uint8_T is_AUTOMATIC_GATE;           /* '<Root>/AutomaticGate' */
  uint8_T is_WORK_DUR_SETTING;         /* '<Root>/AutomaticGate' */
  uint8_T is_OPENING;                  /* '<Root>/AutomaticGate' */
  uint8_T is_CLOSING;                  /* '<Root>/AutomaticGate' */
  uint8_T is_EMERGENCY_P1_OPEN;        /* '<Root>/AutomaticGate' */
  uint8_T is_B1;                       /* '<Root>/AutomaticGate' */
  uint8_T is_B3;                       /* '<Root>/AutomaticGate' */
  uint8_T is_B2;                       /* '<Root>/AutomaticGate' */
  uint8_T is_OPEN_DUR_SETTING;         /* '<Root>/AutomaticGate' */
  uint8_T is_active_c1_STATE_PROJECT_S3;/* '<Root>/AutomaticGate' */
  uint8_T is_active_B1;                /* '<Root>/AutomaticGate' */
  uint8_T is_active_B3;                /* '<Root>/AutomaticGate' */
  uint8_T is_active_B2;                /* '<Root>/AutomaticGate' */
  uint8_T is_active_AUTOMATIC_GATE;    /* '<Root>/AutomaticGate' */
  uint8_T is_active_OPEN_DUR_SETTING;  /* '<Root>/AutomaticGate' */
  uint8_T is_active_WORK_DUR_SETTING;  /* '<Root>/AutomaticGate' */
} DW_STATE_PROJECT_S3_T;

/* Parameters (default storage) */
struct P_STATE_PROJECT_S3_T_ {
  real_T delay_1_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S3>/delay_1'
                                        */
  real_T delay_2_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S3>/delay_2'
                                        */
  real_T delay_3_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S3>/delay_3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_STATE_PROJECT_S3_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_STATE_PROJECT_S3_T STATE_PROJECT_S3_P;

/* Block signals (default storage) */
extern B_STATE_PROJECT_S3_T STATE_PROJECT_S3_B;

/* Block states (default storage) */
extern DW_STATE_PROJECT_S3_T STATE_PROJECT_S3_DW;

/* Model entry point functions */
extern void STATE_PROJECT_S3_initialize(void);
extern void STATE_PROJECT_S3_step(void);
extern void STATE_PROJECT_S3_terminate(void);

/* Real-time Model object */
extern RT_MODEL_STATE_PROJECT_S3_T *const STATE_PROJECT_S3_M;

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
 * '<Root>' : 'STATE_PROJECT_S3'
 * '<S1>'   : 'STATE_PROJECT_S3/AutomaticGate'
 * '<S2>'   : 'STATE_PROJECT_S3/Input Conversion Subsystem'
 * '<S3>'   : 'STATE_PROJECT_S3/Output Conversion Subsystem'
 * '<S4>'   : 'STATE_PROJECT_S3/Test Sequence'
 */
#endif                                 /* RTW_HEADER_STATE_PROJECT_S3_h_ */
