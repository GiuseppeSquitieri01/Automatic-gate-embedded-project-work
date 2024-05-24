/*
 * STATE_PROJECT_S3.c
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

#include "STATE_PROJECT_S3.h"
#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "STATE_PROJECT_S3_private.h"
#include <string.h>

/* Named constants for Chart: '<Root>/AutomaticGate' */
#define STATE_PROJECT_S3_BUTTON_OFF    (0.0)
#define STATE_PROJECT_S3_BUTTON_ON     (1.0)
#define STATE_PROJECT_S3_CALL_EVENT    (-1)
#define STATE_PROJECT_S3_IN_CLOSED     ((uint8_T)1U)
#define STATE_PROJECT_S3_IN_CLOSING    ((uint8_T)2U)
#define STATE_PROJECT_S3_IN_EMERGENCY  ((uint8_T)3U)
#define STATE_PROJECT_S3_IN_GREEN_OFF  ((uint8_T)1U)
#define STATE_PROJECT_S3_IN_GREEN_ON   ((uint8_T)2U)
#define STATE_PROJECT_S3_IN_LONGPRESSED ((uint8_T)1U)
#define STATE_PROJECT_S3_IN_OPEN       ((uint8_T)7U)
#define STATE_PROJECT_S3_IN_OPENING    ((uint8_T)8U)
#define STATE_PROJECT_S3_IN_PRESSED    ((uint8_T)2U)
#define STATE_PROJECT_S3_IN_RELEASED   ((uint8_T)3U)
#define STATE_PROJECT_S3_IN_YELLOW_OFF ((uint8_T)1U)
#define STATE_PROJECT_S3_IN_YELLOW_ON  ((uint8_T)2U)
#define STATE_PROJECT_S3_P_OFF         (0.0)
#define STATE_PROJECT_S3_P_ON          (1.0)
#define STATE_PROJECT__IN_EMERGENCY_LED ((uint8_T)4U)
#define STATE_PROJECT__event_B1_pressed (0)
#define STATE_PROJECT__event_B2_pressed (1)
#define STATE_PROJECT__event_B3_pressed (2)
#define STATE_PROJEC_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define STATE_PROJ_IN_EMERGENCY_P1_OPEN ((uint8_T)6U)
#define STATE_PR_IN_EMERGENCY_P1_CLOSED ((uint8_T)5U)
#define STATE_P_IN_AUTOMATIC_GATE_LOGIC ((uint8_T)1U)
#define ST_IN_OPEN_DUR_SETTING_INTERNAL ((uint8_T)1U)
#define ST_IN_WORK_DUR_SETTING_INTERNAL ((uint8_T)1U)

/* Named constants for Test Sequence: '<Root>/Test Sequence' */
#define IN_End_Closing_Close_Transition ((uint8_T)2U)
#define IN_End_Test_Blink_Yellow_Closin ((uint8_T)3U)
#define IN_End_Test_Blink_Yellow_Openin ((uint8_T)4U)
#define IN_Start_Closing_Close_Transiti ((uint8_T)7U)
#define IN_Start_Test_Blink_Yellow_Clos ((uint8_T)9U)
#define IN_Start_Test_Blink_Yellow_Open ((uint8_T)10U)
#define STATE_PROJECT_S3_IN_All_Led_ON ((uint8_T)1U)
#define STATE_PROJECT_S3_IN_Run        ((uint8_T)6U)
#define STATE_P_IN_Request_Opening_Test ((uint8_T)5U)
#define ST_IN_Test_Blink_Yellow_Closing ((uint8_T)11U)
#define ST_IN_Test_Blink_Yellow_Opening ((uint8_T)12U)
#define S_IN_Start_Request_Opening_Test ((uint8_T)8U)

/* Block signals (default storage) */
B_STATE_PROJECT_S3_T STATE_PROJECT_S3_B;

/* Block states (default storage) */
DW_STATE_PROJECT_S3_T STATE_PROJECT_S3_DW;

/* Real-time model */
static RT_MODEL_STATE_PROJECT_S3_T STATE_PROJECT_S3_M_;
RT_MODEL_STATE_PROJECT_S3_T *const STATE_PROJECT_S3_M = &STATE_PROJECT_S3_M_;

/* Forward declaration for local functions */
static void broadcast_B1_pressed_c1_STATE_P(void);
static void broadcast_B3_pressed_c1_STATE_P(void);
static void broadcast_B2_pressed_c1_STATE_P(void);
static real_T STATE_PROJECT_S3_mod(real_T x);
static void STATE_PROJECT_S3_CLOSING(void);
static void STATE_PROJECT_S3_OPENING(void);
static void STATE_PROJECT_S3_AUTOMATIC_GATE(void);
static void STATE_PROJE_c1_STATE_PROJECT_S3(void);

/* Function for Chart: '<Root>/AutomaticGate' */
static void broadcast_B1_pressed_c1_STATE_P(void)
{
  int32_T b_previousEvent;
  b_previousEvent = STATE_PROJECT_S3_DW.sfEvent;
  STATE_PROJECT_S3_DW.sfEvent = STATE_PROJECT__event_B1_pressed;

  /* Chart: '<Root>/AutomaticGate' */
  STATE_PROJE_c1_STATE_PROJECT_S3();
  STATE_PROJECT_S3_DW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/AutomaticGate' */
static void broadcast_B3_pressed_c1_STATE_P(void)
{
  int32_T b_previousEvent;
  b_previousEvent = STATE_PROJECT_S3_DW.sfEvent;
  STATE_PROJECT_S3_DW.sfEvent = STATE_PROJECT__event_B3_pressed;

  /* Chart: '<Root>/AutomaticGate' */
  STATE_PROJE_c1_STATE_PROJECT_S3();
  STATE_PROJECT_S3_DW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/AutomaticGate' */
static void broadcast_B2_pressed_c1_STATE_P(void)
{
  int32_T b_previousEvent;
  b_previousEvent = STATE_PROJECT_S3_DW.sfEvent;
  STATE_PROJECT_S3_DW.sfEvent = STATE_PROJECT__event_B2_pressed;

  /* Chart: '<Root>/AutomaticGate' */
  STATE_PROJE_c1_STATE_PROJECT_S3();
  STATE_PROJECT_S3_DW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/AutomaticGate' */
static real_T STATE_PROJECT_S3_mod(real_T x)
{
  real_T r;
  if (rtIsNaN(x) || rtIsInf(x)) {
    r = (rtNaN);
  } else if (x == 0.0) {
    r = 0.0;
  } else {
    r = fmod(x, 120.0);
    if (r == 0.0) {
      r = 0.0;
    } else if (x < 0.0) {
      r += 120.0;
    }
  }

  return r;
}

/* Function for Chart: '<Root>/AutomaticGate' */
static void STATE_PROJECT_S3_CLOSING(void)
{
  if (STATE_PROJECT_S3_B.P2 == STATE_PROJECT_S3_P_ON) {
    STATE_PROJECT_S3_DW.is_CLOSING = STATE_PROJEC_IN_NO_ACTIVE_CHILD;
    STATE_PROJECT_S3_DW.is_AUTOMATIC_GATE = STATE_PROJECT_S3_IN_CLOSED;
    STATE_PROJECT_S3_DW.is_active_OPEN_DUR_SETTING = 1U;
    STATE_PROJECT_S3_DW.is_OPEN_DUR_SETTING = ST_IN_OPEN_DUR_SETTING_INTERNAL;
    STATE_PROJECT_S3_DW.is_active_WORK_DUR_SETTING = 1U;
    STATE_PROJECT_S3_DW.is_WORK_DUR_SETTING = ST_IN_WORK_DUR_SETTING_INTERNAL;
  } else if ((STATE_PROJECT_S3_DW.sfEvent == STATE_PROJECT__event_B1_pressed) ||
             (STATE_PROJECT_S3_B.P1 == STATE_PROJECT_S3_P_ON)) {
    STATE_PROJECT_S3_DW.is_CLOSING = STATE_PROJEC_IN_NO_ACTIVE_CHILD;
    STATE_PROJECT_S3_DW.is_AUTOMATIC_GATE = STATE_PROJECT_S3_IN_OPENING;
    STATE_PROJECT_S3_DW.temporalCounter_i1 = 0U;
    STATE_PROJECT_S3_DW.is_OPENING = STATE_PROJECT_S3_IN_YELLOW_ON;
    STATE_PROJECT_S3_DW.temporalCounter_i2 = 0U;
  } else if (STATE_PROJECT_S3_DW.temporalCounter_i1 >= (uint32_T)ceil
             (STATE_PROJECT_S3_DW.WORK_DUR * 10.0)) {
    STATE_PROJECT_S3_DW.is_CLOSING = STATE_PROJEC_IN_NO_ACTIVE_CHILD;
    STATE_PROJECT_S3_DW.is_AUTOMATIC_GATE = STATE_PROJECT_S3_IN_EMERGENCY;
    STATE_PROJECT_S3_DW.temporalCounter_i1 = 0U;
  } else {
    switch (STATE_PROJECT_S3_DW.is_CLOSING) {
     case STATE_PROJECT_S3_IN_YELLOW_OFF:
      if (STATE_PROJECT_S3_DW.temporalCounter_i2 >= 10U) {
        STATE_PROJECT_S3_DW.is_CLOSING = STATE_PROJECT_S3_IN_YELLOW_ON;
        STATE_PROJECT_S3_DW.temporalCounter_i2 = 0U;
      }
      break;

     case STATE_PROJECT_S3_IN_YELLOW_ON:
      if (STATE_PROJECT_S3_DW.temporalCounter_i2 >= 10U) {
        STATE_PROJECT_S3_DW.is_CLOSING = STATE_PROJECT_S3_IN_YELLOW_OFF;
        STATE_PROJECT_S3_DW.temporalCounter_i2 = 0U;
      }
      break;

     default:
      /* Unreachable state, for coverage only */
      STATE_PROJECT_S3_DW.is_CLOSING = STATE_PROJEC_IN_NO_ACTIVE_CHILD;
      break;
    }
  }
}

/* Function for Chart: '<Root>/AutomaticGate' */
static void STATE_PROJECT_S3_OPENING(void)
{
  if ((STATE_PROJECT_S3_DW.sfEvent == STATE_PROJECT__event_B1_pressed) &&
      (STATE_PROJECT_S3_B.P1 == STATE_PROJECT_S3_P_OFF)) {
    STATE_PROJECT_S3_DW.is_OPENING = STATE_PROJEC_IN_NO_ACTIVE_CHILD;
    STATE_PROJECT_S3_DW.is_AUTOMATIC_GATE = STATE_PROJECT_S3_IN_CLOSING;
    STATE_PROJECT_S3_DW.temporalCounter_i1 = 0U;
    STATE_PROJECT_S3_DW.is_CLOSING = STATE_PROJECT_S3_IN_YELLOW_ON;
    STATE_PROJECT_S3_DW.temporalCounter_i2 = 0U;
  } else if (STATE_PROJECT_S3_DW.temporalCounter_i1 >= (uint32_T)ceil
             (STATE_PROJECT_S3_DW.WORK_DUR * 10.0)) {
    STATE_PROJECT_S3_DW.is_OPENING = STATE_PROJEC_IN_NO_ACTIVE_CHILD;
    STATE_PROJECT_S3_DW.is_AUTOMATIC_GATE = STATE_PROJECT_S3_IN_OPEN;
    STATE_PROJECT_S3_DW.temporalCounter_i1 = 0U;
  } else {
    switch (STATE_PROJECT_S3_DW.is_OPENING) {
     case STATE_PROJECT_S3_IN_YELLOW_OFF:
      if (STATE_PROJECT_S3_DW.temporalCounter_i2 >= 10U) {
        STATE_PROJECT_S3_DW.is_OPENING = STATE_PROJECT_S3_IN_YELLOW_ON;
        STATE_PROJECT_S3_DW.temporalCounter_i2 = 0U;
      }
      break;

     case STATE_PROJECT_S3_IN_YELLOW_ON:
      if (STATE_PROJECT_S3_DW.temporalCounter_i2 >= 10U) {
        STATE_PROJECT_S3_DW.is_OPENING = STATE_PROJECT_S3_IN_YELLOW_OFF;
        STATE_PROJECT_S3_DW.temporalCounter_i2 = 0U;
      }
      break;

     default:
      /* Unreachable state, for coverage only */
      STATE_PROJECT_S3_DW.is_OPENING = STATE_PROJEC_IN_NO_ACTIVE_CHILD;
      break;
    }
  }
}

/* Function for Chart: '<Root>/AutomaticGate' */
static void STATE_PROJECT_S3_AUTOMATIC_GATE(void)
{
  switch (STATE_PROJECT_S3_DW.is_AUTOMATIC_GATE) {
   case STATE_PROJECT_S3_IN_CLOSED:
    if ((STATE_PROJECT_S3_DW.sfEvent == STATE_PROJECT__event_B1_pressed) &&
        (STATE_PROJECT_S3_B.P1 == STATE_PROJECT_S3_P_ON)) {
      STATE_PROJECT_S3_DW.is_WORK_DUR_SETTING = STATE_PROJEC_IN_NO_ACTIVE_CHILD;
      STATE_PROJECT_S3_DW.is_active_WORK_DUR_SETTING = 0U;
      STATE_PROJECT_S3_DW.is_OPEN_DUR_SETTING = STATE_PROJEC_IN_NO_ACTIVE_CHILD;
      STATE_PROJECT_S3_DW.is_active_OPEN_DUR_SETTING = 0U;
      STATE_PROJECT_S3_DW.is_AUTOMATIC_GATE = STATE_PR_IN_EMERGENCY_P1_CLOSED;
      STATE_PROJECT_S3_DW.temporalCounter_i2 = 0U;
      STATE_PROJECT_S3_DW.is_EMERGENCY_P1_CLOSED = STATE_PROJECT_S3_IN_GREEN_ON;
      STATE_PROJECT_S3_DW.temporalCounter_i1 = 0U;
    } else if (STATE_PROJECT_S3_DW.sfEvent == STATE_PROJECT__event_B1_pressed) {
      STATE_PROJECT_S3_DW.is_WORK_DUR_SETTING = STATE_PROJEC_IN_NO_ACTIVE_CHILD;
      STATE_PROJECT_S3_DW.is_active_WORK_DUR_SETTING = 0U;
      STATE_PROJECT_S3_DW.is_OPEN_DUR_SETTING = STATE_PROJEC_IN_NO_ACTIVE_CHILD;
      STATE_PROJECT_S3_DW.is_active_OPEN_DUR_SETTING = 0U;
      STATE_PROJECT_S3_DW.is_AUTOMATIC_GATE = STATE_PROJECT_S3_IN_OPENING;
      STATE_PROJECT_S3_DW.temporalCounter_i1 = 0U;
      STATE_PROJECT_S3_DW.is_OPENING = STATE_PROJECT_S3_IN_YELLOW_ON;
      STATE_PROJECT_S3_DW.temporalCounter_i2 = 0U;
    } else {
      if ((STATE_PROJECT_S3_DW.is_active_OPEN_DUR_SETTING != 0U) &&
          (STATE_PROJECT_S3_DW.is_OPEN_DUR_SETTING ==
           ST_IN_OPEN_DUR_SETTING_INTERNAL) && (STATE_PROJECT_S3_DW.sfEvent ==
           STATE_PROJECT__event_B2_pressed)) {
        STATE_PROJECT_S3_DW.OPEN_DUR = STATE_PROJECT_S3_mod
          (STATE_PROJECT_S3_DW.OPEN_DUR) + 10.0;
      }

      if ((STATE_PROJECT_S3_DW.is_active_WORK_DUR_SETTING != 0U) &&
          (STATE_PROJECT_S3_DW.is_WORK_DUR_SETTING ==
           ST_IN_WORK_DUR_SETTING_INTERNAL) && (STATE_PROJECT_S3_DW.sfEvent ==
           STATE_PROJECT__event_B3_pressed)) {
        STATE_PROJECT_S3_DW.WORK_DUR = STATE_PROJECT_S3_mod
          (STATE_PROJECT_S3_DW.WORK_DUR) + 10.0;
      }
    }
    break;

   case STATE_PROJECT_S3_IN_CLOSING:
    STATE_PROJECT_S3_CLOSING();
    break;

   case STATE_PROJECT_S3_IN_EMERGENCY:
    if (STATE_PROJECT_S3_DW.temporalCounter_i1 >= 100U) {
      STATE_PROJECT_S3_DW.is_AUTOMATIC_GATE = STATE_PROJECT__IN_EMERGENCY_LED;
    } else if (STATE_PROJECT_S3_B.P2 == STATE_PROJECT_S3_P_ON) {
      STATE_PROJECT_S3_DW.is_AUTOMATIC_GATE = STATE_PROJECT_S3_IN_CLOSED;
      STATE_PROJECT_S3_DW.is_active_OPEN_DUR_SETTING = 1U;
      STATE_PROJECT_S3_DW.is_OPEN_DUR_SETTING = ST_IN_OPEN_DUR_SETTING_INTERNAL;
      STATE_PROJECT_S3_DW.is_active_WORK_DUR_SETTING = 1U;
      STATE_PROJECT_S3_DW.is_WORK_DUR_SETTING = ST_IN_WORK_DUR_SETTING_INTERNAL;
    }
    break;

   case STATE_PROJECT__IN_EMERGENCY_LED:
    if (STATE_PROJECT_S3_B.P2 == STATE_PROJECT_S3_P_ON) {
      STATE_PROJECT_S3_DW.is_AUTOMATIC_GATE = STATE_PROJECT_S3_IN_CLOSED;
      STATE_PROJECT_S3_DW.is_active_OPEN_DUR_SETTING = 1U;
      STATE_PROJECT_S3_DW.is_OPEN_DUR_SETTING = ST_IN_OPEN_DUR_SETTING_INTERNAL;
      STATE_PROJECT_S3_DW.is_active_WORK_DUR_SETTING = 1U;
      STATE_PROJECT_S3_DW.is_WORK_DUR_SETTING = ST_IN_WORK_DUR_SETTING_INTERNAL;
    }
    break;

   case STATE_PR_IN_EMERGENCY_P1_CLOSED:
    if ((STATE_PROJECT_S3_B.P1 == STATE_PROJECT_S3_P_OFF) ||
        (STATE_PROJECT_S3_DW.temporalCounter_i2 >= 300U)) {
      STATE_PROJECT_S3_DW.is_EMERGENCY_P1_CLOSED =
        STATE_PROJEC_IN_NO_ACTIVE_CHILD;
      STATE_PROJECT_S3_DW.is_AUTOMATIC_GATE = STATE_PROJECT_S3_IN_CLOSED;
      STATE_PROJECT_S3_DW.is_active_OPEN_DUR_SETTING = 1U;
      STATE_PROJECT_S3_DW.is_OPEN_DUR_SETTING = ST_IN_OPEN_DUR_SETTING_INTERNAL;
      STATE_PROJECT_S3_DW.is_active_WORK_DUR_SETTING = 1U;
      STATE_PROJECT_S3_DW.is_WORK_DUR_SETTING = ST_IN_WORK_DUR_SETTING_INTERNAL;
    } else {
      switch (STATE_PROJECT_S3_DW.is_EMERGENCY_P1_CLOSED) {
       case STATE_PROJECT_S3_IN_GREEN_OFF:
        if (STATE_PROJECT_S3_DW.temporalCounter_i1 >= 5U) {
          STATE_PROJECT_S3_DW.is_EMERGENCY_P1_CLOSED =
            STATE_PROJECT_S3_IN_GREEN_ON;
          STATE_PROJECT_S3_DW.temporalCounter_i1 = 0U;
        }
        break;

       case STATE_PROJECT_S3_IN_GREEN_ON:
        if (STATE_PROJECT_S3_DW.temporalCounter_i1 >= 5U) {
          STATE_PROJECT_S3_DW.is_EMERGENCY_P1_CLOSED =
            STATE_PROJECT_S3_IN_GREEN_OFF;
          STATE_PROJECT_S3_DW.temporalCounter_i1 = 0U;
        }
        break;

       default:
        /* Unreachable state, for coverage only */
        STATE_PROJECT_S3_DW.is_EMERGENCY_P1_CLOSED =
          STATE_PROJEC_IN_NO_ACTIVE_CHILD;
        break;
      }
    }
    break;

   case STATE_PROJ_IN_EMERGENCY_P1_OPEN:
    if ((STATE_PROJECT_S3_B.P1 == STATE_PROJECT_S3_P_OFF) ||
        (STATE_PROJECT_S3_DW.temporalCounter_i1 >= 300U)) {
      STATE_PROJECT_S3_DW.is_EMERGENCY_P1_OPEN = STATE_PROJEC_IN_NO_ACTIVE_CHILD;
      STATE_PROJECT_S3_DW.is_AUTOMATIC_GATE = STATE_PROJECT_S3_IN_OPEN;
      STATE_PROJECT_S3_DW.temporalCounter_i1 = 0U;
    } else {
      switch (STATE_PROJECT_S3_DW.is_EMERGENCY_P1_OPEN) {
       case STATE_PROJECT_S3_IN_GREEN_OFF:
        if (STATE_PROJECT_S3_DW.temporalCounter_i2 >= 5U) {
          STATE_PROJECT_S3_DW.is_EMERGENCY_P1_OPEN =
            STATE_PROJECT_S3_IN_GREEN_ON;
          STATE_PROJECT_S3_DW.temporalCounter_i2 = 0U;
        }
        break;

       case STATE_PROJECT_S3_IN_GREEN_ON:
        if (STATE_PROJECT_S3_DW.temporalCounter_i2 >= 5U) {
          STATE_PROJECT_S3_DW.is_EMERGENCY_P1_OPEN =
            STATE_PROJECT_S3_IN_GREEN_OFF;
          STATE_PROJECT_S3_DW.temporalCounter_i2 = 0U;
        }
        break;

       default:
        /* Unreachable state, for coverage only */
        STATE_PROJECT_S3_DW.is_EMERGENCY_P1_OPEN =
          STATE_PROJEC_IN_NO_ACTIVE_CHILD;
        break;
      }
    }
    break;

   case STATE_PROJECT_S3_IN_OPEN:
    if ((STATE_PROJECT_S3_DW.temporalCounter_i1 >= (uint32_T)ceil
         (STATE_PROJECT_S3_DW.OPEN_DUR * 10.0)) || (STATE_PROJECT_S3_DW.sfEvent ==
         STATE_PROJECT__event_B1_pressed)) {
      STATE_PROJECT_S3_DW.is_AUTOMATIC_GATE = STATE_PROJECT_S3_IN_CLOSING;
      STATE_PROJECT_S3_DW.temporalCounter_i1 = 0U;
      STATE_PROJECT_S3_DW.is_CLOSING = STATE_PROJECT_S3_IN_YELLOW_ON;
      STATE_PROJECT_S3_DW.temporalCounter_i2 = 0U;
    } else if ((STATE_PROJECT_S3_DW.sfEvent == STATE_PROJECT__event_B1_pressed) &&
               (STATE_PROJECT_S3_B.P1 == STATE_PROJECT_S3_P_ON)) {
      STATE_PROJECT_S3_DW.is_AUTOMATIC_GATE = STATE_PROJ_IN_EMERGENCY_P1_OPEN;
      STATE_PROJECT_S3_DW.temporalCounter_i1 = 0U;
      STATE_PROJECT_S3_DW.is_EMERGENCY_P1_OPEN = STATE_PROJECT_S3_IN_GREEN_ON;
      STATE_PROJECT_S3_DW.temporalCounter_i2 = 0U;
    }
    break;

   case STATE_PROJECT_S3_IN_OPENING:
    STATE_PROJECT_S3_OPENING();
    break;

   default:
    /* Unreachable state, for coverage only */
    STATE_PROJECT_S3_DW.is_AUTOMATIC_GATE = STATE_PROJEC_IN_NO_ACTIVE_CHILD;
    break;
  }
}

/* Function for Chart: '<Root>/AutomaticGate' */
static void STATE_PROJE_c1_STATE_PROJECT_S3(void)
{
  /* Chart: '<Root>/AutomaticGate' */
  if (STATE_PROJECT_S3_DW.is_active_c1_STATE_PROJECT_S3 == 0U) {
    STATE_PROJECT_S3_DW.is_active_c1_STATE_PROJECT_S3 = 1U;
    STATE_PROJECT_S3_DW.is_c1_STATE_PROJECT_S3 = STATE_P_IN_AUTOMATIC_GATE_LOGIC;
    STATE_PROJECT_S3_DW.is_active_B1 = 1U;
    STATE_PROJECT_S3_DW.is_B1 = STATE_PROJECT_S3_IN_RELEASED;
    STATE_PROJECT_S3_DW.is_active_B3 = 1U;
    STATE_PROJECT_S3_DW.is_B3 = STATE_PROJECT_S3_IN_RELEASED;
    STATE_PROJECT_S3_DW.is_active_B2 = 1U;
    STATE_PROJECT_S3_DW.is_B2 = STATE_PROJECT_S3_IN_RELEASED;
    STATE_PROJECT_S3_DW.is_active_AUTOMATIC_GATE = 1U;
    STATE_PROJECT_S3_DW.is_AUTOMATIC_GATE = STATE_PROJECT_S3_IN_CLOSING;
    STATE_PROJECT_S3_DW.temporalCounter_i1 = 0U;
    STATE_PROJECT_S3_DW.is_CLOSING = STATE_PROJECT_S3_IN_YELLOW_ON;
    STATE_PROJECT_S3_DW.temporalCounter_i2 = 0U;
  } else if (STATE_PROJECT_S3_DW.is_c1_STATE_PROJECT_S3 ==
             STATE_P_IN_AUTOMATIC_GATE_LOGIC) {
    if (STATE_PROJECT_S3_DW.is_active_B1 != 0U) {
      switch (STATE_PROJECT_S3_DW.is_B1) {
       case STATE_PROJECT_S3_IN_LONGPRESSED:
        if (STATE_PROJECT_S3_B.B1 == STATE_PROJECT_S3_BUTTON_OFF) {
          STATE_PROJECT_S3_DW.is_B1 = STATE_PROJECT_S3_IN_RELEASED;
        } else {
          broadcast_B1_pressed_c1_STATE_P();
        }
        break;

       case STATE_PROJECT_S3_IN_PRESSED:
        if (STATE_PROJECT_S3_B.B1 == STATE_PROJECT_S3_BUTTON_OFF) {
          STATE_PROJECT_S3_DW.is_B1 = STATE_PROJECT_S3_IN_LONGPRESSED;
          broadcast_B1_pressed_c1_STATE_P();
        }
        break;

       case STATE_PROJECT_S3_IN_RELEASED:
        if (STATE_PROJECT_S3_B.B1 == STATE_PROJECT_S3_BUTTON_ON) {
          STATE_PROJECT_S3_DW.is_B1 = STATE_PROJECT_S3_IN_PRESSED;
        }
        break;

       default:
        /* Unreachable state, for coverage only */
        STATE_PROJECT_S3_DW.is_B1 = STATE_PROJEC_IN_NO_ACTIVE_CHILD;
        break;
      }
    }

    if (STATE_PROJECT_S3_DW.is_active_B3 != 0U) {
      switch (STATE_PROJECT_S3_DW.is_B3) {
       case STATE_PROJECT_S3_IN_LONGPRESSED:
        if (STATE_PROJECT_S3_B.B3 == STATE_PROJECT_S3_BUTTON_OFF) {
          STATE_PROJECT_S3_DW.is_B3 = STATE_PROJECT_S3_IN_RELEASED;
        } else {
          broadcast_B3_pressed_c1_STATE_P();
        }
        break;

       case STATE_PROJECT_S3_IN_PRESSED:
        if (STATE_PROJECT_S3_B.B3 == STATE_PROJECT_S3_BUTTON_OFF) {
          STATE_PROJECT_S3_DW.is_B3 = STATE_PROJECT_S3_IN_LONGPRESSED;
          broadcast_B3_pressed_c1_STATE_P();
        }
        break;

       case STATE_PROJECT_S3_IN_RELEASED:
        if (STATE_PROJECT_S3_B.B3 == STATE_PROJECT_S3_BUTTON_ON) {
          STATE_PROJECT_S3_DW.is_B3 = STATE_PROJECT_S3_IN_PRESSED;
        }
        break;

       default:
        /* Unreachable state, for coverage only */
        STATE_PROJECT_S3_DW.is_B3 = STATE_PROJEC_IN_NO_ACTIVE_CHILD;
        break;
      }
    }

    if (STATE_PROJECT_S3_DW.is_active_B2 != 0U) {
      switch (STATE_PROJECT_S3_DW.is_B2) {
       case STATE_PROJECT_S3_IN_LONGPRESSED:
        if (STATE_PROJECT_S3_B.B2 == STATE_PROJECT_S3_BUTTON_OFF) {
          STATE_PROJECT_S3_DW.is_B2 = STATE_PROJECT_S3_IN_RELEASED;
        } else {
          broadcast_B2_pressed_c1_STATE_P();
        }
        break;

       case STATE_PROJECT_S3_IN_PRESSED:
        if (STATE_PROJECT_S3_B.B2 == STATE_PROJECT_S3_BUTTON_OFF) {
          STATE_PROJECT_S3_DW.is_B2 = STATE_PROJECT_S3_IN_LONGPRESSED;
          broadcast_B2_pressed_c1_STATE_P();
        }
        break;

       case STATE_PROJECT_S3_IN_RELEASED:
        if (STATE_PROJECT_S3_B.B2 == STATE_PROJECT_S3_BUTTON_ON) {
          STATE_PROJECT_S3_DW.is_B2 = STATE_PROJECT_S3_IN_PRESSED;
        }
        break;

       default:
        /* Unreachable state, for coverage only */
        STATE_PROJECT_S3_DW.is_B2 = STATE_PROJEC_IN_NO_ACTIVE_CHILD;
        break;
      }
    }

    if (STATE_PROJECT_S3_DW.is_active_AUTOMATIC_GATE != 0U) {
      STATE_PROJECT_S3_AUTOMATIC_GATE();
    }
  }

  /* End of Chart: '<Root>/AutomaticGate' */
}

/* Model step function */
void STATE_PROJECT_S3_step(void)
{
  /* Test Sequence: '<Root>/Test Sequence' */
  if (STATE_PROJECT_S3_DW.temporalCounter_i1_o < 255U) {
    STATE_PROJECT_S3_DW.temporalCounter_i1_o++;
  }

  if (STATE_PROJECT_S3_DW.is_active_c4_STATE_PROJECT_S3 == 0U) {
    STATE_PROJECT_S3_DW.is_active_c4_STATE_PROJECT_S3 = 1U;
    STATE_PROJECT_S3_DW.is_c4_STATE_PROJECT_S3 = STATE_PROJECT_S3_IN_Run;
    STATE_PROJECT_S3_DW.temporalCounter_i1_o = 0U;
    STATE_PROJECT_S3_B.B1 = 0.0;
    STATE_PROJECT_S3_B.B2 = 0.0;
    STATE_PROJECT_S3_B.B3 = 0.0;
    STATE_PROJECT_S3_B.P1 = 0.0;
    STATE_PROJECT_S3_B.P2 = 0.0;
  } else {
    switch (STATE_PROJECT_S3_DW.is_c4_STATE_PROJECT_S3) {
     case STATE_PROJECT_S3_IN_All_Led_ON:
      break;

     case IN_End_Closing_Close_Transition:
      if (STATE_PROJECT_S3_DW.temporalCounter_i1_o >= 10U) {
        STATE_PROJECT_S3_DW.is_c4_STATE_PROJECT_S3 =
          S_IN_Start_Request_Opening_Test;
        STATE_PROJECT_S3_DW.temporalCounter_i1_o = 0U;
        STATE_PROJECT_S3_B.B1 = 1.0;
      }
      break;

     case IN_End_Test_Blink_Yellow_Closin:
      STATE_PROJECT_S3_DW.is_c4_STATE_PROJECT_S3 =
        IN_Start_Closing_Close_Transiti;
      STATE_PROJECT_S3_DW.temporalCounter_i1_o = 0U;
      STATE_PROJECT_S3_B.P2 = 1.0;
      break;

     case IN_End_Test_Blink_Yellow_Openin:
      if (STATE_PROJECT_S3_DW.temporalCounter_i1_o >= 150U) {
        STATE_PROJECT_S3_DW.is_c4_STATE_PROJECT_S3 =
          STATE_PROJECT_S3_IN_All_Led_ON;
      }
      break;

     case STATE_P_IN_Request_Opening_Test:
      STATE_PROJECT_S3_DW.is_c4_STATE_PROJECT_S3 =
        IN_Start_Test_Blink_Yellow_Open;
      STATE_PROJECT_S3_DW.temporalCounter_i1_o = 0U;
      break;

     case STATE_PROJECT_S3_IN_Run:
      STATE_PROJECT_S3_DW.is_c4_STATE_PROJECT_S3 =
        IN_Start_Test_Blink_Yellow_Clos;
      STATE_PROJECT_S3_DW.temporalCounter_i1_o = 0U;
      STATE_PROJECT_S3_B.B1 = 0.0;
      STATE_PROJECT_S3_B.B2 = 0.0;
      STATE_PROJECT_S3_B.B3 = 0.0;
      STATE_PROJECT_S3_B.P1 = 0.0;
      STATE_PROJECT_S3_B.P2 = 0.0;
      break;

     case IN_Start_Closing_Close_Transiti:
      if (STATE_PROJECT_S3_DW.temporalCounter_i1_o >= 10U) {
        STATE_PROJECT_S3_DW.is_c4_STATE_PROJECT_S3 =
          IN_End_Closing_Close_Transition;
        STATE_PROJECT_S3_DW.temporalCounter_i1_o = 0U;
      } else {
        STATE_PROJECT_S3_B.P2 = 1.0;
      }
      break;

     case S_IN_Start_Request_Opening_Test:
      STATE_PROJECT_S3_DW.is_c4_STATE_PROJECT_S3 =
        STATE_P_IN_Request_Opening_Test;
      STATE_PROJECT_S3_DW.temporalCounter_i1_o = 0U;
      STATE_PROJECT_S3_B.B1 = 0.0;
      break;

     case IN_Start_Test_Blink_Yellow_Clos:
      if (STATE_PROJECT_S3_DW.temporalCounter_i1_o >= 11U) {
        STATE_PROJECT_S3_DW.is_c4_STATE_PROJECT_S3 =
          ST_IN_Test_Blink_Yellow_Closing;
        STATE_PROJECT_S3_DW.temporalCounter_i1_o = 0U;
        STATE_PROJECT_S3_B.B1 = 0.0;
        STATE_PROJECT_S3_B.B2 = 0.0;
        STATE_PROJECT_S3_B.B3 = 0.0;
        STATE_PROJECT_S3_B.P1 = 0.0;
        STATE_PROJECT_S3_B.P2 = 0.0;
      } else {
        STATE_PROJECT_S3_B.B1 = 0.0;
        STATE_PROJECT_S3_B.B2 = 0.0;
        STATE_PROJECT_S3_B.B3 = 0.0;
        STATE_PROJECT_S3_B.P1 = 0.0;
        STATE_PROJECT_S3_B.P2 = 0.0;
      }
      break;

     case IN_Start_Test_Blink_Yellow_Open:
      if (STATE_PROJECT_S3_DW.temporalCounter_i1_o >= 11U) {
        STATE_PROJECT_S3_DW.is_c4_STATE_PROJECT_S3 =
          ST_IN_Test_Blink_Yellow_Opening;
        STATE_PROJECT_S3_DW.temporalCounter_i1_o = 0U;
      }
      break;

     case ST_IN_Test_Blink_Yellow_Closing:
      if (STATE_PROJECT_S3_DW.temporalCounter_i1_o >= 11U) {
        STATE_PROJECT_S3_DW.is_c4_STATE_PROJECT_S3 =
          IN_End_Test_Blink_Yellow_Closin;
        STATE_PROJECT_S3_B.B1 = 0.0;
        STATE_PROJECT_S3_B.B2 = 0.0;
        STATE_PROJECT_S3_B.B3 = 0.0;
        STATE_PROJECT_S3_B.P1 = 0.0;
        STATE_PROJECT_S3_B.P2 = 0.0;
      } else {
        STATE_PROJECT_S3_B.B1 = 0.0;
        STATE_PROJECT_S3_B.B2 = 0.0;
        STATE_PROJECT_S3_B.B3 = 0.0;
        STATE_PROJECT_S3_B.P1 = 0.0;
        STATE_PROJECT_S3_B.P2 = 0.0;
      }
      break;

     default:
      /* case IN_Test_Blink_Yellow_Opening: */
      if (STATE_PROJECT_S3_DW.temporalCounter_i1_o >= 11U) {
        STATE_PROJECT_S3_DW.is_c4_STATE_PROJECT_S3 =
          IN_End_Test_Blink_Yellow_Openin;
        STATE_PROJECT_S3_DW.temporalCounter_i1_o = 0U;
      }
      break;
    }
  }

  /* End of Test Sequence: '<Root>/Test Sequence' */

  /* Chart: '<Root>/AutomaticGate' */
  if (STATE_PROJECT_S3_DW.temporalCounter_i1 < MAX_uint32_T) {
    STATE_PROJECT_S3_DW.temporalCounter_i1++;
  }

  if (STATE_PROJECT_S3_DW.temporalCounter_i2 < 511U) {
    STATE_PROJECT_S3_DW.temporalCounter_i2++;
  }

  STATE_PROJECT_S3_DW.sfEvent = STATE_PROJECT_S3_CALL_EVENT;
  STATE_PROJE_c1_STATE_PROJECT_S3();

  /* End of Chart: '<Root>/AutomaticGate' */

  /* Matfile logging */
  rt_UpdateTXYLogVars(STATE_PROJECT_S3_M->rtwLogInfo,
                      (&STATE_PROJECT_S3_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(STATE_PROJECT_S3_M)!=-1) &&
        !((rtmGetTFinal(STATE_PROJECT_S3_M)-STATE_PROJECT_S3_M->Timing.taskTime0)
          > STATE_PROJECT_S3_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(STATE_PROJECT_S3_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++STATE_PROJECT_S3_M->Timing.clockTick0)) {
    ++STATE_PROJECT_S3_M->Timing.clockTickH0;
  }

  STATE_PROJECT_S3_M->Timing.taskTime0 = STATE_PROJECT_S3_M->Timing.clockTick0 *
    STATE_PROJECT_S3_M->Timing.stepSize0 +
    STATE_PROJECT_S3_M->Timing.clockTickH0 *
    STATE_PROJECT_S3_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void STATE_PROJECT_S3_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)STATE_PROJECT_S3_M, 0,
                sizeof(RT_MODEL_STATE_PROJECT_S3_T));
  rtmSetTFinal(STATE_PROJECT_S3_M, 120.0);
  STATE_PROJECT_S3_M->Timing.stepSize0 = 0.1;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    STATE_PROJECT_S3_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(STATE_PROJECT_S3_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(STATE_PROJECT_S3_M->rtwLogInfo, (NULL));
    rtliSetLogT(STATE_PROJECT_S3_M->rtwLogInfo, "tout");
    rtliSetLogX(STATE_PROJECT_S3_M->rtwLogInfo, "");
    rtliSetLogXFinal(STATE_PROJECT_S3_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(STATE_PROJECT_S3_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(STATE_PROJECT_S3_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(STATE_PROJECT_S3_M->rtwLogInfo, 0);
    rtliSetLogDecimation(STATE_PROJECT_S3_M->rtwLogInfo, 1);
    rtliSetLogY(STATE_PROJECT_S3_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(STATE_PROJECT_S3_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(STATE_PROJECT_S3_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &STATE_PROJECT_S3_B), 0,
                sizeof(B_STATE_PROJECT_S3_T));

  /* states (dwork) */
  (void) memset((void *)&STATE_PROJECT_S3_DW, 0,
                sizeof(DW_STATE_PROJECT_S3_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(STATE_PROJECT_S3_M->rtwLogInfo, 0.0,
    rtmGetTFinal(STATE_PROJECT_S3_M), STATE_PROJECT_S3_M->Timing.stepSize0,
    (&rtmGetErrorStatus(STATE_PROJECT_S3_M)));

  /* SystemInitialize for Test Sequence: '<Root>/Test Sequence' */
  STATE_PROJECT_S3_DW.temporalCounter_i1_o = 0U;
  STATE_PROJECT_S3_DW.is_active_c4_STATE_PROJECT_S3 = 0U;
  STATE_PROJECT_S3_DW.is_c4_STATE_PROJECT_S3 = STATE_PROJEC_IN_NO_ACTIVE_CHILD;
  STATE_PROJECT_S3_B.B1 = 0.0;
  STATE_PROJECT_S3_B.B2 = 0.0;
  STATE_PROJECT_S3_B.B3 = 0.0;
  STATE_PROJECT_S3_B.P1 = 0.0;
  STATE_PROJECT_S3_B.P2 = 0.0;

  /* SystemInitialize for Chart: '<Root>/AutomaticGate' */
  STATE_PROJECT_S3_DW.sfEvent = STATE_PROJECT_S3_CALL_EVENT;
  STATE_PROJECT_S3_DW.is_active_AUTOMATIC_GATE = 0U;
  STATE_PROJECT_S3_DW.is_AUTOMATIC_GATE = STATE_PROJEC_IN_NO_ACTIVE_CHILD;
  STATE_PROJECT_S3_DW.is_active_OPEN_DUR_SETTING = 0U;
  STATE_PROJECT_S3_DW.is_OPEN_DUR_SETTING = STATE_PROJEC_IN_NO_ACTIVE_CHILD;
  STATE_PROJECT_S3_DW.is_active_WORK_DUR_SETTING = 0U;
  STATE_PROJECT_S3_DW.is_WORK_DUR_SETTING = STATE_PROJEC_IN_NO_ACTIVE_CHILD;
  STATE_PROJECT_S3_DW.is_CLOSING = STATE_PROJEC_IN_NO_ACTIVE_CHILD;
  STATE_PROJECT_S3_DW.is_EMERGENCY_P1_CLOSED = STATE_PROJEC_IN_NO_ACTIVE_CHILD;
  STATE_PROJECT_S3_DW.is_EMERGENCY_P1_OPEN = STATE_PROJEC_IN_NO_ACTIVE_CHILD;
  STATE_PROJECT_S3_DW.is_OPENING = STATE_PROJEC_IN_NO_ACTIVE_CHILD;
  STATE_PROJECT_S3_DW.temporalCounter_i1 = 0U;
  STATE_PROJECT_S3_DW.temporalCounter_i2 = 0U;
  STATE_PROJECT_S3_DW.is_active_B1 = 0U;
  STATE_PROJECT_S3_DW.is_B1 = STATE_PROJEC_IN_NO_ACTIVE_CHILD;
  STATE_PROJECT_S3_DW.is_active_B2 = 0U;
  STATE_PROJECT_S3_DW.is_B2 = STATE_PROJEC_IN_NO_ACTIVE_CHILD;
  STATE_PROJECT_S3_DW.is_active_B3 = 0U;
  STATE_PROJECT_S3_DW.is_B3 = STATE_PROJEC_IN_NO_ACTIVE_CHILD;
  STATE_PROJECT_S3_DW.is_active_c1_STATE_PROJECT_S3 = 0U;
  STATE_PROJECT_S3_DW.is_c1_STATE_PROJECT_S3 = STATE_PROJEC_IN_NO_ACTIVE_CHILD;
  STATE_PROJECT_S3_DW.WORK_DUR = 10.0;
  STATE_PROJECT_S3_DW.OPEN_DUR = 10.0;
}

/* Model terminate function */
void STATE_PROJECT_S3_terminate(void)
{
  /* (no terminate code required) */
}
