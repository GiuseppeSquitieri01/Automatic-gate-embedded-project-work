/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AutomaticGate.c
 *
 * Code generated for Simulink model 'AutomaticGate'.
 *
 * Model version                  : 1.43
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue May 28 22:16:21 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "AutomaticGate.h"
#include "rtwtypes.h"
#include <math.h>

/* Named constants for Chart: '<Root>/AutomaticGate' */
#define CALL_EVENT                     (-1)
#define IN_AUTOMATIC_GATE_LOGIC        ((uint8_T)1U)
#define IN_CLOSED                      ((uint8_T)1U)
#define IN_CLOSING                     ((uint8_T)2U)
#define IN_EMERGENCY                   ((uint8_T)3U)
#define IN_EMERGENCY_LED               ((uint8_T)4U)
#define IN_EMERGENCY_P1_CLOSED         ((uint8_T)5U)
#define IN_EMERGENCY_P1_OPEN           ((uint8_T)6U)
#define IN_GREEN_OFF                   ((uint8_T)1U)
#define IN_GREEN_ON                    ((uint8_T)2U)
#define IN_LONGPRESSED                 ((uint8_T)1U)
#define IN_NO_ACTIVE_CHILD             ((uint8_T)0U)
#define IN_OPEN                        ((uint8_T)7U)
#define IN_OPENING                     ((uint8_T)8U)
#define IN_OPEN_DUR_SETTING_INTERNAL   ((uint8_T)1U)
#define IN_PRESSED                     ((uint8_T)2U)
#define IN_RELEASED                    ((uint8_T)3U)
#define IN_WORK_DUR_SETTING_INTERNAL   ((uint8_T)1U)
#define IN_YELLOW_OFF                  ((uint8_T)1U)
#define IN_YELLOW_ON                   ((uint8_T)2U)
#define LED_OFF                        (false)
#define LED_ON                         (true)
#define event_B1_pressed               (0)
#define event_B2_pressed               (1)
#define event_B3_pressed               (2)

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Forward declaration for local functions */
static void broadcast_B1_pressed_c2_Automat(void);
static void broadcast_B3_pressed_c2_Automat(void);
static void broadcast_B2_pressed_c2_Automat(void);
static void CLOSED(void);
static void CLOSING(void);
static void AUTOMATIC_GATE(void);
static void c2_AutomaticGate(void);

/* Function for Chart: '<Root>/AutomaticGate' */
static void broadcast_B1_pressed_c2_Automat(void)
{
  int32_T b_previousEvent;
  b_previousEvent = rtDW.sfEvent;
  rtDW.sfEvent = event_B1_pressed;

  /* Chart: '<Root>/AutomaticGate' */
  c2_AutomaticGate();
  rtDW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/AutomaticGate' */
static void broadcast_B3_pressed_c2_Automat(void)
{
  int32_T b_previousEvent;
  b_previousEvent = rtDW.sfEvent;
  rtDW.sfEvent = event_B3_pressed;

  /* Chart: '<Root>/AutomaticGate' */
  c2_AutomaticGate();
  rtDW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/AutomaticGate' */
static void broadcast_B2_pressed_c2_Automat(void)
{
  int32_T b_previousEvent;
  b_previousEvent = rtDW.sfEvent;
  rtDW.sfEvent = event_B2_pressed;

  /* Chart: '<Root>/AutomaticGate' */
  c2_AutomaticGate();
  rtDW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/AutomaticGate' */
static void CLOSED(void)
{
  /* Outport: '<Root>/Green_Led' */
  rtY.Green_Led = LED_OFF;

  /* Outport: '<Root>/Yellow_Led' */
  rtY.Yellow_Led = LED_OFF;

  /* Outport: '<Root>/Red_Led' */
  rtY.Red_Led = LED_OFF;

  /* Inport: '<Root>/P1' */
  if ((rtDW.sfEvent == event_B1_pressed) && rtU.P1) {
    rtDW.is_WORK_DUR_SETTING = IN_NO_ACTIVE_CHILD;
    rtDW.is_active_WORK_DUR_SETTING = 0U;
    rtDW.is_OPEN_DUR_SETTING = IN_NO_ACTIVE_CHILD;
    rtDW.is_active_OPEN_DUR_SETTING = 0U;
    rtDW.is_AUTOMATIC_GATE = IN_EMERGENCY_P1_CLOSED;
    rtDW.temporalCounter_i1 = 0U;
    rtDW.is_EMERGENCY_P1_CLOSED = IN_GREEN_ON;
    rtDW.temporalCounter_i2 = 0U;

    /* Outport: '<Root>/Green_Led' */
    rtY.Green_Led = LED_ON;
  } else if (rtDW.sfEvent == event_B1_pressed) {
    rtDW.is_WORK_DUR_SETTING = IN_NO_ACTIVE_CHILD;
    rtDW.is_active_WORK_DUR_SETTING = 0U;
    rtDW.is_OPEN_DUR_SETTING = IN_NO_ACTIVE_CHILD;
    rtDW.is_active_OPEN_DUR_SETTING = 0U;
    rtDW.is_AUTOMATIC_GATE = IN_OPENING;
    rtDW.temporalCounter_i1 = 0U;
    rtDW.is_OPENING = IN_YELLOW_ON;
    rtDW.temporalCounter_i2 = 0U;

    /* Outport: '<Root>/Yellow_Led' */
    rtY.Yellow_Led = LED_ON;
  } else {
    real_T r;
    if ((rtDW.is_active_OPEN_DUR_SETTING != 0U) && (rtDW.is_OPEN_DUR_SETTING ==
         IN_OPEN_DUR_SETTING_INTERNAL) && (rtDW.sfEvent == event_B2_pressed)) {
      if (rtDW.OPEN_DUR == 0.0) {
        r = 0.0;
      } else {
        r = fmod(rtDW.OPEN_DUR, 120.0);
        if (r == 0.0) {
          r = 0.0;
        } else if (rtDW.OPEN_DUR < 0.0) {
          r += 120.0;
        }
      }

      rtDW.OPEN_DUR = r + 10.0;
    }

    if ((rtDW.is_active_WORK_DUR_SETTING != 0U) && (rtDW.is_WORK_DUR_SETTING ==
         IN_WORK_DUR_SETTING_INTERNAL) && (rtDW.sfEvent == event_B3_pressed)) {
      if (rtDW.WORK_DUR == 0.0) {
        r = 0.0;
      } else {
        r = fmod(rtDW.WORK_DUR, 120.0);
        if (r == 0.0) {
          r = 0.0;
        } else if (rtDW.WORK_DUR < 0.0) {
          r += 120.0;
        }
      }

      rtDW.WORK_DUR = r + 10.0;
    }
  }

  /* End of Inport: '<Root>/P1' */
}

/* Function for Chart: '<Root>/AutomaticGate' */
static void CLOSING(void)
{
  /* Inport: '<Root>/P2' incorporates:
   *  Inport: '<Root>/P1'
   */
  if (rtU.P2) {
    rtDW.is_CLOSING = IN_NO_ACTIVE_CHILD;
    rtDW.is_AUTOMATIC_GATE = IN_CLOSED;

    /* Outport: '<Root>/Green_Led' */
    rtY.Green_Led = LED_OFF;

    /* Outport: '<Root>/Yellow_Led' */
    rtY.Yellow_Led = LED_OFF;

    /* Outport: '<Root>/Red_Led' */
    rtY.Red_Led = LED_OFF;
    rtDW.is_active_OPEN_DUR_SETTING = 1U;
    rtDW.is_OPEN_DUR_SETTING = IN_OPEN_DUR_SETTING_INTERNAL;
    rtDW.is_active_WORK_DUR_SETTING = 1U;
    rtDW.is_WORK_DUR_SETTING = IN_WORK_DUR_SETTING_INTERNAL;
  } else if ((rtDW.sfEvent == event_B1_pressed) || rtU.P1) {
    rtDW.is_CLOSING = IN_NO_ACTIVE_CHILD;
    rtDW.is_AUTOMATIC_GATE = IN_OPENING;
    rtDW.temporalCounter_i1 = 0U;
    rtDW.is_OPENING = IN_YELLOW_ON;
    rtDW.temporalCounter_i2 = 0U;

    /* Outport: '<Root>/Green_Led' */
    rtY.Green_Led = LED_OFF;

    /* Outport: '<Root>/Yellow_Led' */
    rtY.Yellow_Led = LED_ON;

    /* Outport: '<Root>/Red_Led' */
    rtY.Red_Led = LED_OFF;
  } else if (rtDW.temporalCounter_i1 >= (uint32_T)ceil(rtDW.WORK_DUR * 10.0)) {
    rtDW.is_CLOSING = IN_NO_ACTIVE_CHILD;
    rtDW.is_AUTOMATIC_GATE = IN_EMERGENCY;
    rtDW.temporalCounter_i1 = 0U;

    /* Outport: '<Root>/Green_Led' */
    rtY.Green_Led = LED_OFF;

    /* Outport: '<Root>/Yellow_Led' */
    rtY.Yellow_Led = LED_OFF;

    /* Outport: '<Root>/Red_Led' */
    rtY.Red_Led = LED_OFF;
  } else {
    switch (rtDW.is_CLOSING) {
     case IN_YELLOW_OFF:
      /* Outport: '<Root>/Green_Led' */
      rtY.Green_Led = LED_OFF;

      /* Outport: '<Root>/Yellow_Led' */
      rtY.Yellow_Led = LED_OFF;

      /* Outport: '<Root>/Red_Led' */
      rtY.Red_Led = LED_OFF;
      if (rtDW.temporalCounter_i2 >= 10U) {
        rtDW.is_CLOSING = IN_YELLOW_ON;
        rtDW.temporalCounter_i2 = 0U;

        /* Outport: '<Root>/Yellow_Led' */
        rtY.Yellow_Led = LED_ON;
      }
      break;

     case IN_YELLOW_ON:
      /* Outport: '<Root>/Green_Led' */
      rtY.Green_Led = LED_OFF;

      /* Outport: '<Root>/Yellow_Led' */
      rtY.Yellow_Led = LED_ON;

      /* Outport: '<Root>/Red_Led' */
      rtY.Red_Led = LED_OFF;
      if (rtDW.temporalCounter_i2 >= 10U) {
        rtDW.is_CLOSING = IN_YELLOW_OFF;
        rtDW.temporalCounter_i2 = 0U;

        /* Outport: '<Root>/Yellow_Led' */
        rtY.Yellow_Led = LED_OFF;
      }
      break;
    }
  }

  /* End of Inport: '<Root>/P2' */
}

/* Function for Chart: '<Root>/AutomaticGate' */
static void AUTOMATIC_GATE(void)
{
  switch (rtDW.is_AUTOMATIC_GATE) {
   case IN_CLOSED:
    CLOSED();
    break;

   case IN_CLOSING:
    CLOSING();
    break;

   case IN_EMERGENCY:
    /* Outport: '<Root>/Green_Led' */
    rtY.Green_Led = LED_OFF;

    /* Outport: '<Root>/Yellow_Led' */
    rtY.Yellow_Led = LED_OFF;

    /* Outport: '<Root>/Red_Led' */
    /* Inport: '<Root>/P2' */
    rtY.Red_Led = LED_OFF;
    if (rtDW.temporalCounter_i1 >= 100U) {
      rtDW.is_AUTOMATIC_GATE = IN_EMERGENCY_LED;

      /* Outport: '<Root>/Red_Led' */
      rtY.Red_Led = LED_ON;
    } else if (rtU.P2) {
      rtDW.is_AUTOMATIC_GATE = IN_CLOSED;
      rtDW.is_active_OPEN_DUR_SETTING = 1U;
      rtDW.is_OPEN_DUR_SETTING = IN_OPEN_DUR_SETTING_INTERNAL;
      rtDW.is_active_WORK_DUR_SETTING = 1U;
      rtDW.is_WORK_DUR_SETTING = IN_WORK_DUR_SETTING_INTERNAL;
    }
    break;

   case IN_EMERGENCY_LED:
    /* Outport: '<Root>/Green_Led' */
    rtY.Green_Led = LED_OFF;

    /* Outport: '<Root>/Yellow_Led' */
    rtY.Yellow_Led = LED_OFF;

    /* Outport: '<Root>/Red_Led' */
    rtY.Red_Led = LED_ON;

    /* Inport: '<Root>/P2' */
    if (rtU.P2) {
      rtDW.is_AUTOMATIC_GATE = IN_CLOSED;

      /* Outport: '<Root>/Red_Led' */
      rtY.Red_Led = LED_OFF;
      rtDW.is_active_OPEN_DUR_SETTING = 1U;
      rtDW.is_OPEN_DUR_SETTING = IN_OPEN_DUR_SETTING_INTERNAL;
      rtDW.is_active_WORK_DUR_SETTING = 1U;
      rtDW.is_WORK_DUR_SETTING = IN_WORK_DUR_SETTING_INTERNAL;
    }
    break;

   case IN_EMERGENCY_P1_CLOSED:
    /* Inport: '<Root>/P1' */
    if ((!rtU.P1) || (rtDW.temporalCounter_i1 >= 300U)) {
      rtDW.is_EMERGENCY_P1_CLOSED = IN_NO_ACTIVE_CHILD;
      rtDW.is_AUTOMATIC_GATE = IN_CLOSED;

      /* Outport: '<Root>/Green_Led' */
      rtY.Green_Led = LED_OFF;

      /* Outport: '<Root>/Yellow_Led' */
      rtY.Yellow_Led = LED_OFF;

      /* Outport: '<Root>/Red_Led' */
      rtY.Red_Led = LED_OFF;
      rtDW.is_active_OPEN_DUR_SETTING = 1U;
      rtDW.is_OPEN_DUR_SETTING = IN_OPEN_DUR_SETTING_INTERNAL;
      rtDW.is_active_WORK_DUR_SETTING = 1U;
      rtDW.is_WORK_DUR_SETTING = IN_WORK_DUR_SETTING_INTERNAL;
    } else {
      switch (rtDW.is_EMERGENCY_P1_CLOSED) {
       case IN_GREEN_OFF:
        /* Outport: '<Root>/Green_Led' */
        rtY.Green_Led = LED_OFF;

        /* Outport: '<Root>/Yellow_Led' */
        rtY.Yellow_Led = LED_OFF;

        /* Outport: '<Root>/Red_Led' */
        rtY.Red_Led = LED_OFF;
        if (rtDW.temporalCounter_i2 >= 5U) {
          rtDW.is_EMERGENCY_P1_CLOSED = IN_GREEN_ON;
          rtDW.temporalCounter_i2 = 0U;

          /* Outport: '<Root>/Green_Led' */
          rtY.Green_Led = LED_ON;
        }
        break;

       case IN_GREEN_ON:
        /* Outport: '<Root>/Green_Led' */
        rtY.Green_Led = LED_ON;

        /* Outport: '<Root>/Yellow_Led' */
        rtY.Yellow_Led = LED_OFF;

        /* Outport: '<Root>/Red_Led' */
        rtY.Red_Led = LED_OFF;
        if (rtDW.temporalCounter_i2 >= 5U) {
          rtDW.is_EMERGENCY_P1_CLOSED = IN_GREEN_OFF;
          rtDW.temporalCounter_i2 = 0U;

          /* Outport: '<Root>/Green_Led' */
          rtY.Green_Led = LED_OFF;
        }
        break;
      }
    }
    break;

   case IN_EMERGENCY_P1_OPEN:
    /* Inport: '<Root>/P1' */
    if ((!rtU.P1) || (rtDW.temporalCounter_i1 >= 300U)) {
      rtDW.is_EMERGENCY_P1_OPEN = IN_NO_ACTIVE_CHILD;
      rtDW.is_AUTOMATIC_GATE = IN_OPEN;
      rtDW.temporalCounter_i1 = 0U;

      /* Outport: '<Root>/Green_Led' */
      rtY.Green_Led = LED_ON;

      /* Outport: '<Root>/Yellow_Led' */
      rtY.Yellow_Led = LED_ON;

      /* Outport: '<Root>/Red_Led' */
      rtY.Red_Led = LED_ON;
    } else {
      switch (rtDW.is_EMERGENCY_P1_OPEN) {
       case IN_GREEN_OFF:
        /* Outport: '<Root>/Green_Led' */
        rtY.Green_Led = LED_OFF;

        /* Outport: '<Root>/Yellow_Led' */
        rtY.Yellow_Led = LED_OFF;

        /* Outport: '<Root>/Red_Led' */
        rtY.Red_Led = LED_OFF;
        if (rtDW.temporalCounter_i2 >= 5U) {
          rtDW.is_EMERGENCY_P1_OPEN = IN_GREEN_ON;
          rtDW.temporalCounter_i2 = 0U;

          /* Outport: '<Root>/Green_Led' */
          rtY.Green_Led = LED_ON;
        }
        break;

       case IN_GREEN_ON:
        /* Outport: '<Root>/Green_Led' */
        rtY.Green_Led = LED_ON;

        /* Outport: '<Root>/Yellow_Led' */
        rtY.Yellow_Led = LED_OFF;

        /* Outport: '<Root>/Red_Led' */
        rtY.Red_Led = LED_OFF;
        if (rtDW.temporalCounter_i2 >= 5U) {
          rtDW.is_EMERGENCY_P1_OPEN = IN_GREEN_OFF;
          rtDW.temporalCounter_i2 = 0U;

          /* Outport: '<Root>/Green_Led' */
          rtY.Green_Led = LED_OFF;
        }
        break;
      }
    }
    break;

   case IN_OPEN:
    /* Outport: '<Root>/Green_Led' */
    rtY.Green_Led = LED_ON;

    /* Outport: '<Root>/Yellow_Led' */
    rtY.Yellow_Led = LED_ON;

    /* Outport: '<Root>/Red_Led' */
    rtY.Red_Led = LED_ON;

    /* Inport: '<Root>/P1' */
    if ((rtDW.temporalCounter_i1 >= (uint32_T)ceil(rtDW.OPEN_DUR * 10.0)) ||
        ((rtDW.sfEvent == event_B1_pressed) && (!rtU.P1))) {
      rtDW.is_AUTOMATIC_GATE = IN_CLOSING;
      rtDW.temporalCounter_i1 = 0U;
      rtDW.is_CLOSING = IN_YELLOW_ON;
      rtDW.temporalCounter_i2 = 0U;

      /* Outport: '<Root>/Green_Led' */
      rtY.Green_Led = LED_OFF;

      /* Outport: '<Root>/Red_Led' */
      rtY.Red_Led = LED_OFF;
    } else if ((rtDW.sfEvent == event_B1_pressed) && rtU.P1) {
      rtDW.is_AUTOMATIC_GATE = IN_EMERGENCY_P1_OPEN;
      rtDW.temporalCounter_i1 = 0U;
      rtDW.is_EMERGENCY_P1_OPEN = IN_GREEN_ON;
      rtDW.temporalCounter_i2 = 0U;

      /* Outport: '<Root>/Yellow_Led' */
      rtY.Yellow_Led = LED_OFF;

      /* Outport: '<Root>/Red_Led' */
      rtY.Red_Led = LED_OFF;
    }
    break;

   case IN_OPENING:
    /* Inport: '<Root>/P1' */
    if ((rtDW.sfEvent == event_B1_pressed) && (!rtU.P1)) {
      rtDW.is_OPENING = IN_NO_ACTIVE_CHILD;
      rtDW.is_AUTOMATIC_GATE = IN_CLOSING;
      rtDW.temporalCounter_i1 = 0U;
      rtDW.is_CLOSING = IN_YELLOW_ON;
      rtDW.temporalCounter_i2 = 0U;

      /* Outport: '<Root>/Green_Led' */
      rtY.Green_Led = LED_OFF;

      /* Outport: '<Root>/Yellow_Led' */
      rtY.Yellow_Led = LED_ON;

      /* Outport: '<Root>/Red_Led' */
      rtY.Red_Led = LED_OFF;
    } else if (rtDW.temporalCounter_i1 >= (uint32_T)ceil(rtDW.WORK_DUR * 10.0))
    {
      rtDW.is_OPENING = IN_NO_ACTIVE_CHILD;
      rtDW.is_AUTOMATIC_GATE = IN_OPEN;
      rtDW.temporalCounter_i1 = 0U;

      /* Outport: '<Root>/Green_Led' */
      rtY.Green_Led = LED_ON;

      /* Outport: '<Root>/Yellow_Led' */
      rtY.Yellow_Led = LED_ON;

      /* Outport: '<Root>/Red_Led' */
      rtY.Red_Led = LED_ON;
    } else {
      switch (rtDW.is_OPENING) {
       case IN_YELLOW_OFF:
        /* Outport: '<Root>/Green_Led' */
        rtY.Green_Led = LED_OFF;

        /* Outport: '<Root>/Yellow_Led' */
        rtY.Yellow_Led = LED_OFF;

        /* Outport: '<Root>/Red_Led' */
        rtY.Red_Led = LED_OFF;
        if (rtDW.temporalCounter_i2 >= 10U) {
          rtDW.is_OPENING = IN_YELLOW_ON;
          rtDW.temporalCounter_i2 = 0U;

          /* Outport: '<Root>/Yellow_Led' */
          rtY.Yellow_Led = LED_ON;
        }
        break;

       case IN_YELLOW_ON:
        /* Outport: '<Root>/Green_Led' */
        rtY.Green_Led = LED_OFF;

        /* Outport: '<Root>/Yellow_Led' */
        rtY.Yellow_Led = LED_ON;

        /* Outport: '<Root>/Red_Led' */
        rtY.Red_Led = LED_OFF;
        if (rtDW.temporalCounter_i2 >= 10U) {
          rtDW.is_OPENING = IN_YELLOW_OFF;
          rtDW.temporalCounter_i2 = 0U;

          /* Outport: '<Root>/Yellow_Led' */
          rtY.Yellow_Led = LED_OFF;
        }
        break;
      }
    }
    break;
  }
}

/* Function for Chart: '<Root>/AutomaticGate' */
static void c2_AutomaticGate(void)
{
  /* Chart: '<Root>/AutomaticGate' incorporates:
   *  Inport: '<Root>/B1'
   *  Inport: '<Root>/B2'
   *  Inport: '<Root>/B3'
   */
  if (rtDW.is_active_c2_AutomaticGate == 0U) {
    rtDW.is_active_c2_AutomaticGate = 1U;
    rtDW.is_c2_AutomaticGate = IN_AUTOMATIC_GATE_LOGIC;
    rtDW.is_active_B1 = 1U;
    rtDW.is_B1 = IN_RELEASED;
    rtDW.is_active_B3 = 1U;
    rtDW.is_B3 = IN_RELEASED;
    rtDW.is_active_B2 = 1U;
    rtDW.is_B2 = IN_RELEASED;
    rtDW.is_active_AUTOMATIC_GATE = 1U;
    rtDW.is_AUTOMATIC_GATE = IN_CLOSING;
    rtDW.temporalCounter_i1 = 0U;
    rtDW.is_CLOSING = IN_YELLOW_ON;
    rtDW.temporalCounter_i2 = 0U;

    /* Outport: '<Root>/Green_Led' */
    rtY.Green_Led = LED_OFF;

    /* Outport: '<Root>/Yellow_Led' */
    rtY.Yellow_Led = LED_ON;

    /* Outport: '<Root>/Red_Led' */
    rtY.Red_Led = LED_OFF;
  } else if (rtDW.is_c2_AutomaticGate == IN_AUTOMATIC_GATE_LOGIC) {
    if (rtDW.is_active_B1 != 0U) {
      switch (rtDW.is_B1) {
       case IN_LONGPRESSED:
        if (!rtU.B1) {
          rtDW.is_B1 = IN_RELEASED;
        } else {
          broadcast_B1_pressed_c2_Automat();
        }
        break;

       case IN_PRESSED:
        if (!rtU.B1) {
          rtDW.is_B1 = IN_LONGPRESSED;
          broadcast_B1_pressed_c2_Automat();
        }
        break;

       case IN_RELEASED:
        if (rtU.B1) {
          rtDW.is_B1 = IN_PRESSED;
        }
        break;
      }
    }

    if (rtDW.is_active_B3 != 0U) {
      switch (rtDW.is_B3) {
       case IN_LONGPRESSED:
        if (!rtU.B3) {
          rtDW.is_B3 = IN_RELEASED;
        } else {
          broadcast_B3_pressed_c2_Automat();
        }
        break;

       case IN_PRESSED:
        if (!rtU.B3) {
          rtDW.is_B3 = IN_LONGPRESSED;
          broadcast_B3_pressed_c2_Automat();
        }
        break;

       case IN_RELEASED:
        if (rtU.B3) {
          rtDW.is_B3 = IN_PRESSED;
        }
        break;
      }
    }

    if (rtDW.is_active_B2 != 0U) {
      switch (rtDW.is_B2) {
       case IN_LONGPRESSED:
        if (!rtU.B2) {
          rtDW.is_B2 = IN_RELEASED;
        } else {
          broadcast_B2_pressed_c2_Automat();
        }
        break;

       case IN_PRESSED:
        if (!rtU.B2) {
          rtDW.is_B2 = IN_LONGPRESSED;
          broadcast_B2_pressed_c2_Automat();
        }
        break;

       case IN_RELEASED:
        if (rtU.B2) {
          rtDW.is_B2 = IN_PRESSED;
        }
        break;
      }
    }

    if (rtDW.is_active_AUTOMATIC_GATE != 0U) {
      AUTOMATIC_GATE();
    }
  }

  /* End of Chart: '<Root>/AutomaticGate' */
}

/* Model step function */
void AutomaticGate_step(void)
{
  /* Chart: '<Root>/AutomaticGate' */
  if (rtDW.temporalCounter_i1 < MAX_uint32_T) {
    rtDW.temporalCounter_i1++;
  }

  if (rtDW.temporalCounter_i2 < 15U) {
    rtDW.temporalCounter_i2++;
  }

  rtDW.sfEvent = CALL_EVENT;
  c2_AutomaticGate();

  /* End of Chart: '<Root>/AutomaticGate' */
}

/* Model initialize function */
void AutomaticGate_initialize(void)
{
  /* SystemInitialize for Chart: '<Root>/AutomaticGate' */
  rtDW.sfEvent = CALL_EVENT;
  rtDW.WORK_DUR = 10.0;
  rtDW.OPEN_DUR = 10.0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
