/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: STATE_PROJECT.c
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

#include "STATE_PROJECT.h"
#include "rtwtypes.h"
#include <math.h>
#include <stddef.h>

/* Named constants for Chart: '<Root>/AutomaticGate' */
#define CALL_EVENT                     (-1)
#define IN_AUTOMATIC_GATE_LOGIC        ((uint8_T)1U)
#define IN_CLOSED                      ((uint8_T)1U)
#define IN_CLOSING                     ((uint8_T)2U)
#define IN_EMERGENCY                   ((uint8_T)3U)
#define IN_EMERGENCY_LED               ((uint8_T)4U)
#define IN_EMERGENCY_P1_CLOSED         ((uint8_T)5U)
#define IN_EMERGENCY_P1_OPEN           ((uint8_T)6U)
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
#define event_B1_pressed               (0)
#define event_B2_pressed               (1)
#define event_B3_pressed               (2)
#define NumBitsPerChar                 8U

/* Block signals and states (default storage) */
DW rtDW;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Forward declaration for local functions */
static void broadcast_B1_pressed_c2_STATE_P(void);
static void broadcast_B3_pressed_c2_STATE_P(void);
static void broadcast_B2_pressed_c2_STATE_P(void);
static real_T mod(real_T x);
static void CLOSING(void);
static void OPENING(void);
static void AUTOMATIC_GATE(void);
static void c2_STATE_PROJECT(void);
static real_T rtGetNaN(void);
static real32_T rtGetNaNF(void);

#define NOT_USING_NONFINITE_LITERALS   1

extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
static void rt_InitInfAndNaN(size_t realSize);
static boolean_T rtIsInf(real_T value);
static boolean_T rtIsInfF(real32_T value);
static boolean_T rtIsNaN(real_T value);
static boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;
static real_T rtGetInf(void);
static real32_T rtGetInfF(void);
static real_T rtGetMinusInf(void);
static real32_T rtGetMinusInfF(void);

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0.0F } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
static void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
static boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
static boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
static boolean_T rtIsNaN(real_T value)
{
  boolean_T result = (boolean_T) 0;
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  if (bitsPerReal == 32U) {
    result = rtIsNaNF((real32_T)value);
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.fltVal = value;
    result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) == 0x7FF00000 &&
                         ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                          (tmpVal.bitVal.words.wordL != 0) ));
  }

  return result;
}

/* Test if single-precision value is not a number */
static boolean_T rtIsNaNF(real32_T value)
{
  IEEESingle tmp;
  tmp.wordL.wordLreal = value;
  return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                     (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
}

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

/* Function for Chart: '<Root>/AutomaticGate' */
static void broadcast_B1_pressed_c2_STATE_P(void)
{
  int32_T b_previousEvent;
  b_previousEvent = rtDW.sfEvent;
  rtDW.sfEvent = event_B1_pressed;

  /* Chart: '<Root>/AutomaticGate' */
  c2_STATE_PROJECT();
  rtDW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/AutomaticGate' */
static void broadcast_B3_pressed_c2_STATE_P(void)
{
  int32_T b_previousEvent;
  b_previousEvent = rtDW.sfEvent;
  rtDW.sfEvent = event_B3_pressed;

  /* Chart: '<Root>/AutomaticGate' */
  c2_STATE_PROJECT();
  rtDW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/AutomaticGate' */
static void broadcast_B2_pressed_c2_STATE_P(void)
{
  int32_T b_previousEvent;
  b_previousEvent = rtDW.sfEvent;
  rtDW.sfEvent = event_B2_pressed;

  /* Chart: '<Root>/AutomaticGate' */
  c2_STATE_PROJECT();
  rtDW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/AutomaticGate' */
static real_T mod(real_T x)
{
  real_T r;
  if (rtIsNaN(x)) {
    r = (rtNaN);
  } else if (rtIsInf(x)) {
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
static void CLOSING(void)
{
  rtDW.is_CLOSING = IN_NO_ACTIVE_CHILD;
  rtDW.is_AUTOMATIC_GATE = IN_CLOSED;
  rtDW.is_active_OPEN_DUR_SETTING = 1U;
  rtDW.is_OPEN_DUR_SETTING = IN_OPEN_DUR_SETTING_INTERNAL;
  rtDW.is_active_WORK_DUR_SETTING = 1U;
  rtDW.is_WORK_DUR_SETTING = IN_WORK_DUR_SETTING_INTERNAL;
}

/* Function for Chart: '<Root>/AutomaticGate' */
static void OPENING(void)
{
  if (rtDW.sfEvent == event_B1_pressed) {
    rtDW.is_OPENING = IN_NO_ACTIVE_CHILD;
    rtDW.is_AUTOMATIC_GATE = IN_CLOSING;
    rtDW.temporalCounter_i2 = 0U;
    rtDW.is_CLOSING = IN_YELLOW_ON;
    rtDW.temporalCounter_i1 = 0U;
  } else if (rtDW.temporalCounter_i2 >= (uint32_T)ceil(rtDW.WORK_DUR * 10.0)) {
    rtDW.is_OPENING = IN_NO_ACTIVE_CHILD;
    rtDW.is_AUTOMATIC_GATE = IN_OPEN;
    rtDW.temporalCounter_i1 = 0U;
  } else {
    switch (rtDW.is_OPENING) {
     case IN_YELLOW_OFF:
      if (rtDW.temporalCounter_i1 >= 10U) {
        rtDW.is_OPENING = IN_YELLOW_ON;
        rtDW.temporalCounter_i1 = 0U;
      }
      break;

     case IN_YELLOW_ON:
      if (rtDW.temporalCounter_i1 >= 10U) {
        rtDW.is_OPENING = IN_YELLOW_OFF;
        rtDW.temporalCounter_i1 = 0U;
      }
      break;
    }
  }
}

/* Function for Chart: '<Root>/AutomaticGate' */
static void AUTOMATIC_GATE(void)
{
  switch (rtDW.is_AUTOMATIC_GATE) {
   case IN_CLOSED:
    if (rtDW.sfEvent == event_B1_pressed) {
      rtDW.is_WORK_DUR_SETTING = IN_NO_ACTIVE_CHILD;
      rtDW.is_active_WORK_DUR_SETTING = 0U;
      rtDW.is_OPEN_DUR_SETTING = IN_NO_ACTIVE_CHILD;
      rtDW.is_active_OPEN_DUR_SETTING = 0U;
      rtDW.is_AUTOMATIC_GATE = IN_OPENING;
      rtDW.temporalCounter_i2 = 0U;
      rtDW.is_OPENING = IN_YELLOW_ON;
      rtDW.temporalCounter_i1 = 0U;
    } else {
      if ((rtDW.is_active_OPEN_DUR_SETTING != 0U) && (rtDW.is_OPEN_DUR_SETTING ==
           IN_OPEN_DUR_SETTING_INTERNAL) && (rtDW.sfEvent == event_B2_pressed))
      {
        rtDW.OPEN_DUR = mod(rtDW.OPEN_DUR) + 10.0;
      }

      if ((rtDW.is_active_WORK_DUR_SETTING != 0U) && (rtDW.is_WORK_DUR_SETTING ==
           IN_WORK_DUR_SETTING_INTERNAL) && (rtDW.sfEvent == event_B3_pressed))
      {
        rtDW.WORK_DUR = mod(rtDW.WORK_DUR) + 10.0;
      }
    }
    break;

   case IN_CLOSING:
    CLOSING();
    break;

   case IN_EMERGENCY:
    if (rtDW.temporalCounter_i1 >= 100U) {
      rtDW.is_AUTOMATIC_GATE = IN_EMERGENCY_LED;
    } else {
      rtDW.is_AUTOMATIC_GATE = IN_CLOSED;
      rtDW.is_active_OPEN_DUR_SETTING = 1U;
      rtDW.is_OPEN_DUR_SETTING = IN_OPEN_DUR_SETTING_INTERNAL;
      rtDW.is_active_WORK_DUR_SETTING = 1U;
      rtDW.is_WORK_DUR_SETTING = IN_WORK_DUR_SETTING_INTERNAL;
    }
    break;

   case IN_EMERGENCY_LED:
    rtDW.is_AUTOMATIC_GATE = IN_CLOSED;
    rtDW.is_active_OPEN_DUR_SETTING = 1U;
    rtDW.is_OPEN_DUR_SETTING = IN_OPEN_DUR_SETTING_INTERNAL;
    rtDW.is_active_WORK_DUR_SETTING = 1U;
    rtDW.is_WORK_DUR_SETTING = IN_WORK_DUR_SETTING_INTERNAL;
    break;

   case IN_EMERGENCY_P1_CLOSED:
    rtDW.is_EMERGENCY_P1_CLOSED = IN_NO_ACTIVE_CHILD;
    rtDW.is_AUTOMATIC_GATE = IN_CLOSED;
    rtDW.is_active_OPEN_DUR_SETTING = 1U;
    rtDW.is_OPEN_DUR_SETTING = IN_OPEN_DUR_SETTING_INTERNAL;
    rtDW.is_active_WORK_DUR_SETTING = 1U;
    rtDW.is_WORK_DUR_SETTING = IN_WORK_DUR_SETTING_INTERNAL;
    break;

   case IN_EMERGENCY_P1_OPEN:
    rtDW.is_EMERGENCY_P1_OPEN = IN_NO_ACTIVE_CHILD;
    rtDW.is_AUTOMATIC_GATE = IN_OPEN;
    rtDW.temporalCounter_i1 = 0U;
    break;

   case IN_OPEN:
    if ((rtDW.temporalCounter_i1 >= (uint32_T)ceil(rtDW.OPEN_DUR * 10.0)) ||
        (rtDW.sfEvent == event_B1_pressed)) {
      rtDW.is_AUTOMATIC_GATE = IN_CLOSING;
      rtDW.temporalCounter_i2 = 0U;
      rtDW.is_CLOSING = IN_YELLOW_ON;
      rtDW.temporalCounter_i1 = 0U;
    }
    break;

   case IN_OPENING:
    OPENING();
    break;
  }
}

/* Function for Chart: '<Root>/AutomaticGate' */
static void c2_STATE_PROJECT(void)
{
  /* Chart: '<Root>/AutomaticGate' */
  if (rtDW.is_active_c2_STATE_PROJECT == 0U) {
    rtDW.is_active_c2_STATE_PROJECT = 1U;
    rtDW.is_c2_STATE_PROJECT = IN_AUTOMATIC_GATE_LOGIC;
    rtDW.is_active_B1 = 1U;
    rtDW.is_B1 = IN_RELEASED;
    rtDW.is_active_B3 = 1U;
    rtDW.is_B3 = IN_RELEASED;
    rtDW.is_active_B2 = 1U;
    rtDW.is_B2 = IN_RELEASED;
    rtDW.is_active_AUTOMATIC_GATE = 1U;
    rtDW.is_AUTOMATIC_GATE = IN_CLOSING;
    rtDW.temporalCounter_i2 = 0U;
    rtDW.is_CLOSING = IN_YELLOW_ON;
    rtDW.temporalCounter_i1 = 0U;
  } else if (rtDW.is_c2_STATE_PROJECT == IN_AUTOMATIC_GATE_LOGIC) {
    if (rtDW.is_active_B1 != 0U) {
      switch (rtDW.is_B1) {
       case IN_LONGPRESSED:
        rtDW.is_B1 = IN_RELEASED;
        break;

       case IN_PRESSED:
        rtDW.is_B1 = IN_LONGPRESSED;
        broadcast_B1_pressed_c2_STATE_P();
        break;

       case IN_RELEASED:
        break;
      }
    }

    if (rtDW.is_active_B3 != 0U) {
      switch (rtDW.is_B3) {
       case IN_LONGPRESSED:
        rtDW.is_B3 = IN_RELEASED;
        break;

       case IN_PRESSED:
        rtDW.is_B3 = IN_LONGPRESSED;
        broadcast_B3_pressed_c2_STATE_P();
        break;

       case IN_RELEASED:
        break;
      }
    }

    if (rtDW.is_active_B2 != 0U) {
      switch (rtDW.is_B2) {
       case IN_LONGPRESSED:
        rtDW.is_B2 = IN_RELEASED;
        break;

       case IN_PRESSED:
        rtDW.is_B2 = IN_LONGPRESSED;
        broadcast_B2_pressed_c2_STATE_P();
        break;

       case IN_RELEASED:
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
void STATE_PROJECT_step(void)
{
  /* Chart: '<Root>/AutomaticGate' */
  if (rtDW.temporalCounter_i1 < MAX_uint32_T) {
    rtDW.temporalCounter_i1++;
  }

  if (rtDW.temporalCounter_i2 < MAX_uint32_T) {
    rtDW.temporalCounter_i2++;
  }

  rtDW.sfEvent = CALL_EVENT;
  c2_STATE_PROJECT();

  /* End of Chart: '<Root>/AutomaticGate' */
}

/* Model initialize function */
void STATE_PROJECT_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

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
