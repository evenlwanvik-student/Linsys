/*
 * part3_prob3_LQR.c
 *
 * Code generation for model "part3_prob3_LQR".
 *
 * Model version              : 1.78
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Tue Oct 09 11:44:51 2018
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "part3_prob3_LQR.h"
#include "part3_prob3_LQR_private.h"
#include "part3_prob3_LQR_dt.h"

/* Block signals (auto storage) */
B_part3_prob3_LQR_T part3_prob3_LQR_B;

/* Continuous states */
X_part3_prob3_LQR_T part3_prob3_LQR_X;

/* Block states (auto storage) */
DW_part3_prob3_LQR_T part3_prob3_LQR_DW;

/* Real-time model */
RT_MODEL_part3_prob3_LQR_T part3_prob3_LQR_M_;
RT_MODEL_part3_prob3_LQR_T *const part3_prob3_LQR_M = &part3_prob3_LQR_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(part3_prob3_LQR_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(part3_prob3_LQR_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (part3_prob3_LQR_M->Timing.TaskCounters.TID[1] == 0) {
    part3_prob3_LQR_M->Timing.RateInteraction.TID1_2 =
      (part3_prob3_LQR_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    part3_prob3_LQR_M->Timing.perTaskSampleHits[5] =
      part3_prob3_LQR_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (part3_prob3_LQR_M->Timing.TaskCounters.TID[2])++;
  if ((part3_prob3_LQR_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    part3_prob3_LQR_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 5;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  part3_prob3_LQR_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void part3_prob3_LQR_output0(void)     /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_DeadZoney;
  real_T rtb_x[5];
  real_T rtb_r[2];
  int32_T i;
  int32_T i_0;
  real_T rtb_degrad_idx_2;
  real_T rtb_degrad_idx_5;
  real_T u0;
  if (rtmIsMajorTimeStep(part3_prob3_LQR_M)) {
    /* set solver stop time */
    if (!(part3_prob3_LQR_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&part3_prob3_LQR_M->solverInfo,
                            ((part3_prob3_LQR_M->Timing.clockTickH0 + 1) *
        part3_prob3_LQR_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&part3_prob3_LQR_M->solverInfo,
                            ((part3_prob3_LQR_M->Timing.clockTick0 + 1) *
        part3_prob3_LQR_M->Timing.stepSize0 +
        part3_prob3_LQR_M->Timing.clockTickH0 *
        part3_prob3_LQR_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(part3_prob3_LQR_M)) {
    part3_prob3_LQR_M->Timing.t[0] = rtsiGetT(&part3_prob3_LQR_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(part3_prob3_LQR_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S2>/HIL Read Encoder Timebase' */

    /* S-Function Block: part3_prob3_LQR/Heli 3D1/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (part3_prob3_LQR_DW.HILReadEncoderTimebase_Task, 1,
         &part3_prob3_LQR_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(part3_prob3_LQR_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          part3_prob3_LQR_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          part3_prob3_LQR_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_DeadZoney = part3_prob3_LQR_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* Gain: '<S2>/Travel: Count to rad' */
    part3_prob3_LQR_B.TravelCounttorad = part3_prob3_LQR_P.TravelCounttorad_Gain
      * rtb_HILReadEncoderTimebase_o1;

    /* Gain: '<S9>/Gain' */
    part3_prob3_LQR_B.Gain = part3_prob3_LQR_P.Gain_Gain *
      part3_prob3_LQR_B.TravelCounttorad;
  }

  /* Gain: '<S10>/Gain' incorporates:
   *  TransferFcn: '<S2>/Travel: Transfer Fcn'
   */
  part3_prob3_LQR_B.Gain_p = (part3_prob3_LQR_P.TravelTransferFcn_C *
    part3_prob3_LQR_X.TravelTransferFcn_CSTATE +
    part3_prob3_LQR_P.TravelTransferFcn_D * part3_prob3_LQR_B.TravelCounttorad) *
    part3_prob3_LQR_P.Gain_Gain_p;
  if (rtmIsMajorTimeStep(part3_prob3_LQR_M)) {
    /* Gain: '<S2>/Pitch: Count to rad' */
    part3_prob3_LQR_B.PitchCounttorad = part3_prob3_LQR_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2;

    /* Gain: '<S7>/Gain' */
    part3_prob3_LQR_B.Gain_j = part3_prob3_LQR_P.Gain_Gain_e *
      part3_prob3_LQR_B.PitchCounttorad;

    /* Sum: '<Root>/Sum1' incorporates:
     *  Constant: '<Root>/pitch  offset'
     */
    part3_prob3_LQR_B.Sum1 = part3_prob3_LQR_P.pitchoffset_Value +
      part3_prob3_LQR_B.Gain_j;
  }

  /* Gain: '<S8>/Gain' incorporates:
   *  TransferFcn: '<S2>/Pitch: Transfer Fcn'
   */
  part3_prob3_LQR_B.Gain_p2 = (part3_prob3_LQR_P.PitchTransferFcn_C *
    part3_prob3_LQR_X.PitchTransferFcn_CSTATE +
    part3_prob3_LQR_P.PitchTransferFcn_D * part3_prob3_LQR_B.PitchCounttorad) *
    part3_prob3_LQR_P.Gain_Gain_f;
  if (rtmIsMajorTimeStep(part3_prob3_LQR_M)) {
    /* Gain: '<S2>/Elevation: Count to rad' */
    part3_prob3_LQR_B.ElevationCounttorad =
      part3_prob3_LQR_P.ElevationCounttorad_Gain * rtb_DeadZoney;

    /* Gain: '<S5>/Gain' */
    part3_prob3_LQR_B.Gain_g = part3_prob3_LQR_P.Gain_Gain_e2 *
      part3_prob3_LQR_B.ElevationCounttorad;

    /* Sum: '<Root>/Sum2' incorporates:
     *  Constant: '<Root>/elevation  offset'
     */
    part3_prob3_LQR_B.Sum2 = part3_prob3_LQR_B.Gain_g -
      part3_prob3_LQR_P.elevationoffset_Value;
  }

  /* Gain: '<S6>/Gain' incorporates:
   *  TransferFcn: '<S2>/Elevation: Transfer Fcn'
   */
  part3_prob3_LQR_B.Gain_o = (part3_prob3_LQR_P.ElevationTransferFcn_C *
    part3_prob3_LQR_X.ElevationTransferFcn_CSTATE +
    part3_prob3_LQR_P.ElevationTransferFcn_D *
    part3_prob3_LQR_B.ElevationCounttorad) * part3_prob3_LQR_P.Gain_Gain_d;

  /* Gain: '<Root>/deg->rad' */
  rtb_degrad_idx_2 = part3_prob3_LQR_P.degrad_Gain * part3_prob3_LQR_B.Sum1;
  rtb_degrad_idx_5 = part3_prob3_LQR_P.degrad_Gain * part3_prob3_LQR_B.Gain_o;

  /* SignalConversion: '<S4>/ConcatBufferAtxIn1' */
  rtb_x[0] = rtb_degrad_idx_2;

  /* SignalConversion: '<S4>/ConcatBufferAtxIn2' incorporates:
   *  Gain: '<Root>/deg->rad'
   */
  rtb_x[1] = part3_prob3_LQR_P.degrad_Gain * part3_prob3_LQR_B.Gain_p2;

  /* SignalConversion: '<S4>/ConcatBufferAtxIn3' */
  rtb_x[2] = rtb_degrad_idx_5;

  /* Integrator: '<S4>/Integrator1' */
  rtb_x[3] = part3_prob3_LQR_X.Integrator1_CSTATE;

  /* Integrator: '<S4>/Integrator' */
  rtb_x[4] = part3_prob3_LQR_X.Integrator_CSTATE;

  /* RateTransition: '<S3>/Rate Transition: x' */
  if (rtmIsMajorTimeStep(part3_prob3_LQR_M)) {
    if (part3_prob3_LQR_M->Timing.RateInteraction.TID1_2) {
      part3_prob3_LQR_B.RateTransitionx =
        part3_prob3_LQR_DW.RateTransitionx_Buffer0;
    }

    /* DeadZone: '<S3>/Dead Zone: x' */
    if (part3_prob3_LQR_B.RateTransitionx > part3_prob3_LQR_P.DeadZonex_End) {
      rtb_DeadZoney = part3_prob3_LQR_B.RateTransitionx -
        part3_prob3_LQR_P.DeadZonex_End;
    } else if (part3_prob3_LQR_B.RateTransitionx >=
               part3_prob3_LQR_P.DeadZonex_Start) {
      rtb_DeadZoney = 0.0;
    } else {
      rtb_DeadZoney = part3_prob3_LQR_B.RateTransitionx -
        part3_prob3_LQR_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S3>/Dead Zone: x' */

    /* Gain: '<S3>/Joystick_gain_x' incorporates:
     *  Gain: '<S3>/Gain: x'
     */
    part3_prob3_LQR_B.Joystick_gain_x = part3_prob3_LQR_P.Gainx_Gain *
      rtb_DeadZoney * part3_prob3_LQR_P.Joystick_gain_x;

    /* Gain: '<Root>/invert steering 2' */
    part3_prob3_LQR_B.invertsteering2 = part3_prob3_LQR_P.invertsteering2_Gain *
      part3_prob3_LQR_B.Joystick_gain_x;

    /* RateTransition: '<S3>/Rate Transition: y' */
    if (part3_prob3_LQR_M->Timing.RateInteraction.TID1_2) {
      part3_prob3_LQR_B.RateTransitiony =
        part3_prob3_LQR_DW.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S3>/Rate Transition: y' */

    /* DeadZone: '<S3>/Dead Zone: y' */
    if (part3_prob3_LQR_B.RateTransitiony > part3_prob3_LQR_P.DeadZoney_End) {
      rtb_DeadZoney = part3_prob3_LQR_B.RateTransitiony -
        part3_prob3_LQR_P.DeadZoney_End;
    } else if (part3_prob3_LQR_B.RateTransitiony >=
               part3_prob3_LQR_P.DeadZoney_Start) {
      rtb_DeadZoney = 0.0;
    } else {
      rtb_DeadZoney = part3_prob3_LQR_B.RateTransitiony -
        part3_prob3_LQR_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S3>/Dead Zone: y' */

    /* Gain: '<S3>/Joystick_gain_y' incorporates:
     *  Gain: '<S3>/Gain: y'
     */
    part3_prob3_LQR_B.Joystick_gain_y = part3_prob3_LQR_P.Gainy_Gain *
      rtb_DeadZoney * part3_prob3_LQR_P.Joystick_gain_y;

    /* Gain: '<Root>/invert steering 1' */
    part3_prob3_LQR_B.invertsteering1 = part3_prob3_LQR_P.invertsteering1_Gain *
      part3_prob3_LQR_B.Joystick_gain_y;

    /* Gain: '<S4>/P_LQR' incorporates:
     *  SignalConversion: '<S4>/ConcatBufferAtrIn1'
     *  SignalConversion: '<S4>/ConcatBufferAtrIn2'
     */
    part3_prob3_LQR_B.P_LQR[0] = 0.0;
    part3_prob3_LQR_B.P_LQR[0] += part3_prob3_LQR_P.P_LQR[0] *
      part3_prob3_LQR_B.invertsteering2;
    part3_prob3_LQR_B.P_LQR[0] += part3_prob3_LQR_P.P_LQR[2] *
      part3_prob3_LQR_B.invertsteering1;
    part3_prob3_LQR_B.P_LQR[1] = 0.0;
    part3_prob3_LQR_B.P_LQR[1] += part3_prob3_LQR_P.P_LQR[1] *
      part3_prob3_LQR_B.invertsteering2;
    part3_prob3_LQR_B.P_LQR[1] += part3_prob3_LQR_P.P_LQR[3] *
      part3_prob3_LQR_B.invertsteering1;
  }

  /* End of RateTransition: '<S3>/Rate Transition: x' */

  /* Sum: '<S4>/Sum' incorporates:
   *  Gain: '<S4>/K_LQR'
   */
  for (i = 0; i < 2; i++) {
    u0 = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      u0 += part3_prob3_LQR_P.K_LQR[(i_0 << 1) + i] * rtb_x[i_0];
    }

    rtb_r[i] = part3_prob3_LQR_B.P_LQR[i] - u0;
  }

  /* End of Sum: '<S4>/Sum' */
  if (rtmIsMajorTimeStep(part3_prob3_LQR_M)) {
  }

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  u0 = (rtb_r[1] + rtb_r[0]) * part3_prob3_LQR_P.Frontgain_Gain;

  /* Saturate: '<S2>/Front motor: Saturation' */
  if (u0 > part3_prob3_LQR_P.FrontmotorSaturation_UpperSat) {
    part3_prob3_LQR_B.FrontmotorSaturation =
      part3_prob3_LQR_P.FrontmotorSaturation_UpperSat;
  } else if (u0 < part3_prob3_LQR_P.FrontmotorSaturation_LowerSat) {
    part3_prob3_LQR_B.FrontmotorSaturation =
      part3_prob3_LQR_P.FrontmotorSaturation_LowerSat;
  } else {
    part3_prob3_LQR_B.FrontmotorSaturation = u0;
  }

  /* End of Saturate: '<S2>/Front motor: Saturation' */

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  u0 = (rtb_r[0] - rtb_r[1]) * part3_prob3_LQR_P.Backgain_Gain;

  /* Saturate: '<S2>/Back motor: Saturation' */
  if (u0 > part3_prob3_LQR_P.BackmotorSaturation_UpperSat) {
    part3_prob3_LQR_B.BackmotorSaturation =
      part3_prob3_LQR_P.BackmotorSaturation_UpperSat;
  } else if (u0 < part3_prob3_LQR_P.BackmotorSaturation_LowerSat) {
    part3_prob3_LQR_B.BackmotorSaturation =
      part3_prob3_LQR_P.BackmotorSaturation_LowerSat;
  } else {
    part3_prob3_LQR_B.BackmotorSaturation = u0;
  }

  /* End of Saturate: '<S2>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(part3_prob3_LQR_M)) {
    /* S-Function (hil_write_analog_block): '<S2>/HIL Write Analog' */

    /* S-Function Block: part3_prob3_LQR/Heli 3D1/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      part3_prob3_LQR_DW.HILWriteAnalog_Buffer[0] =
        part3_prob3_LQR_B.FrontmotorSaturation;
      part3_prob3_LQR_DW.HILWriteAnalog_Buffer[1] =
        part3_prob3_LQR_B.BackmotorSaturation;
      result = hil_write_analog(part3_prob3_LQR_DW.HILInitialize_Card,
        part3_prob3_LQR_P.HILWriteAnalog_channels, 2,
        &part3_prob3_LQR_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(part3_prob3_LQR_M, _rt_error_message);
      }
    }
  }

  /* Sum: '<S4>/Sum2' */
  part3_prob3_LQR_B.Sum2_m = rtb_degrad_idx_2 -
    part3_prob3_LQR_B.invertsteering2;

  /* Sum: '<S4>/Sum3' */
  part3_prob3_LQR_B.Sum3 = rtb_degrad_idx_5 - part3_prob3_LQR_B.invertsteering1;
}

/* Model update function for TID0 */
void part3_prob3_LQR_update0(void)     /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(part3_prob3_LQR_M)) {
    rt_ertODEUpdateContinuousStates(&part3_prob3_LQR_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++part3_prob3_LQR_M->Timing.clockTick0)) {
    ++part3_prob3_LQR_M->Timing.clockTickH0;
  }

  part3_prob3_LQR_M->Timing.t[0] = rtsiGetSolverStopTime
    (&part3_prob3_LQR_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++part3_prob3_LQR_M->Timing.clockTick1)) {
    ++part3_prob3_LQR_M->Timing.clockTickH1;
  }

  part3_prob3_LQR_M->Timing.t[1] = part3_prob3_LQR_M->Timing.clockTick1 *
    part3_prob3_LQR_M->Timing.stepSize1 + part3_prob3_LQR_M->Timing.clockTickH1 *
    part3_prob3_LQR_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void part3_prob3_LQR_derivatives(void)
{
  XDot_part3_prob3_LQR_T *_rtXdot;
  _rtXdot = ((XDot_part3_prob3_LQR_T *) part3_prob3_LQR_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S2>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += part3_prob3_LQR_P.TravelTransferFcn_A *
    part3_prob3_LQR_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += part3_prob3_LQR_B.TravelCounttorad;

  /* Derivatives for TransferFcn: '<S2>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += part3_prob3_LQR_P.PitchTransferFcn_A *
    part3_prob3_LQR_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += part3_prob3_LQR_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S2>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE +=
    part3_prob3_LQR_P.ElevationTransferFcn_A *
    part3_prob3_LQR_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += part3_prob3_LQR_B.ElevationCounttorad;

  /* Derivatives for Integrator: '<S4>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = part3_prob3_LQR_B.Sum2_m;

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE = part3_prob3_LQR_B.Sum3;
}

/* Model output function for TID2 */
void part3_prob3_LQR_output2(void)     /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: part3_prob3_LQR/Joystick1/Game Controller (game_controller_block) */
  {
    if (part3_prob3_LQR_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll(part3_prob3_LQR_DW.GameController_Controller,
        &state, &new_data);
      if (result == 0) {
        part3_prob3_LQR_B.GameController_o4 = state.x;
        part3_prob3_LQR_B.GameController_o5 = state.y;
      }
    } else {
      part3_prob3_LQR_B.GameController_o4 = 0;
      part3_prob3_LQR_B.GameController_o5 = 0;
    }
  }
}

/* Model update function for TID2 */
void part3_prob3_LQR_update2(void)     /* Sample time: [0.01s, 0.0s] */
{
  /* Update for RateTransition: '<S3>/Rate Transition: x' */
  part3_prob3_LQR_DW.RateTransitionx_Buffer0 =
    part3_prob3_LQR_B.GameController_o4;

  /* Update for RateTransition: '<S3>/Rate Transition: y' */
  part3_prob3_LQR_DW.RateTransitiony_Buffer0 =
    part3_prob3_LQR_B.GameController_o5;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++part3_prob3_LQR_M->Timing.clockTick2)) {
    ++part3_prob3_LQR_M->Timing.clockTickH2;
  }

  part3_prob3_LQR_M->Timing.t[2] = part3_prob3_LQR_M->Timing.clockTick2 *
    part3_prob3_LQR_M->Timing.stepSize2 + part3_prob3_LQR_M->Timing.clockTickH2 *
    part3_prob3_LQR_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void part3_prob3_LQR_output(int_T tid)
{
  switch (tid) {
   case 0 :
    part3_prob3_LQR_output0();
    break;

   case 2 :
    part3_prob3_LQR_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void part3_prob3_LQR_update(int_T tid)
{
  switch (tid) {
   case 0 :
    part3_prob3_LQR_update0();
    break;

   case 2 :
    part3_prob3_LQR_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void part3_prob3_LQR_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: part3_prob3_LQR/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &part3_prob3_LQR_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(part3_prob3_LQR_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(part3_prob3_LQR_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(part3_prob3_LQR_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(part3_prob3_LQR_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(part3_prob3_LQR_M, _rt_error_message);
      return;
    }

    if ((part3_prob3_LQR_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (part3_prob3_LQR_P.HILInitialize_set_analog_inpu_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &part3_prob3_LQR_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = part3_prob3_LQR_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &part3_prob3_LQR_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = part3_prob3_LQR_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges(part3_prob3_LQR_DW.HILInitialize_Card,
        part3_prob3_LQR_P.HILInitialize_analog_input_chan, 8U,
        &part3_prob3_LQR_DW.HILInitialize_AIMinimums[0],
        &part3_prob3_LQR_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(part3_prob3_LQR_M, _rt_error_message);
        return;
      }
    }

    if ((part3_prob3_LQR_P.HILInitialize_set_analog_output && !is_switching) ||
        (part3_prob3_LQR_P.HILInitialize_set_analog_outp_b && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &part3_prob3_LQR_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = part3_prob3_LQR_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &part3_prob3_LQR_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = part3_prob3_LQR_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges
        (part3_prob3_LQR_DW.HILInitialize_Card,
         part3_prob3_LQR_P.HILInitialize_analog_output_cha, 8U,
         &part3_prob3_LQR_DW.HILInitialize_AOMinimums[0],
         &part3_prob3_LQR_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(part3_prob3_LQR_M, _rt_error_message);
        return;
      }
    }

    if ((part3_prob3_LQR_P.HILInitialize_set_analog_outp_e && !is_switching) ||
        (part3_prob3_LQR_P.HILInitialize_set_analog_outp_j && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &part3_prob3_LQR_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = part3_prob3_LQR_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(part3_prob3_LQR_DW.HILInitialize_Card,
        part3_prob3_LQR_P.HILInitialize_analog_output_cha, 8U,
        &part3_prob3_LQR_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(part3_prob3_LQR_M, _rt_error_message);
        return;
      }
    }

    if (part3_prob3_LQR_P.HILInitialize_set_analog_outp_p) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &part3_prob3_LQR_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = part3_prob3_LQR_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (part3_prob3_LQR_DW.HILInitialize_Card,
         part3_prob3_LQR_P.HILInitialize_analog_output_cha, 8U,
         &part3_prob3_LQR_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(part3_prob3_LQR_M, _rt_error_message);
        return;
      }
    }

    if ((part3_prob3_LQR_P.HILInitialize_set_encoder_param && !is_switching) ||
        (part3_prob3_LQR_P.HILInitialize_set_encoder_par_m && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &part3_prob3_LQR_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = part3_prob3_LQR_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (part3_prob3_LQR_DW.HILInitialize_Card,
         part3_prob3_LQR_P.HILInitialize_encoder_channels, 8U,
         (t_encoder_quadrature_mode *)
         &part3_prob3_LQR_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(part3_prob3_LQR_M, _rt_error_message);
        return;
      }
    }

    if ((part3_prob3_LQR_P.HILInitialize_set_encoder_count && !is_switching) ||
        (part3_prob3_LQR_P.HILInitialize_set_encoder_cou_k && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &part3_prob3_LQR_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] =
            part3_prob3_LQR_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(part3_prob3_LQR_DW.HILInitialize_Card,
        part3_prob3_LQR_P.HILInitialize_encoder_channels, 8U,
        &part3_prob3_LQR_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(part3_prob3_LQR_M, _rt_error_message);
        return;
      }
    }

    if ((part3_prob3_LQR_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (part3_prob3_LQR_P.HILInitialize_set_pwm_params__f && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &part3_prob3_LQR_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = part3_prob3_LQR_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(part3_prob3_LQR_DW.HILInitialize_Card,
        part3_prob3_LQR_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &part3_prob3_LQR_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(part3_prob3_LQR_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          part3_prob3_LQR_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues =
          &part3_prob3_LQR_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            part3_prob3_LQR_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = p_HILInitialize_pwm_channels[i1];
            part3_prob3_LQR_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = part3_prob3_LQR_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            part3_prob3_LQR_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = p_HILInitialize_pwm_channels[i1];
            part3_prob3_LQR_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              part3_prob3_LQR_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(part3_prob3_LQR_DW.HILInitialize_Card,
          &part3_prob3_LQR_DW.HILInitialize_POSortedChans[0],
          num_duty_cycle_modes, &part3_prob3_LQR_DW.HILInitialize_POSortedFreqs
          [0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(part3_prob3_LQR_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(part3_prob3_LQR_DW.HILInitialize_Card,
          &part3_prob3_LQR_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &part3_prob3_LQR_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(part3_prob3_LQR_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &part3_prob3_LQR_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            part3_prob3_LQR_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &part3_prob3_LQR_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = part3_prob3_LQR_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &part3_prob3_LQR_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = part3_prob3_LQR_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration(part3_prob3_LQR_DW.HILInitialize_Card,
        part3_prob3_LQR_P.HILInitialize_pwm_channels, 8U,
        (t_pwm_configuration *) &part3_prob3_LQR_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &part3_prob3_LQR_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &part3_prob3_LQR_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(part3_prob3_LQR_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &part3_prob3_LQR_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] =
            part3_prob3_LQR_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &part3_prob3_LQR_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = part3_prob3_LQR_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(part3_prob3_LQR_DW.HILInitialize_Card,
        part3_prob3_LQR_P.HILInitialize_pwm_channels, 8U,
        &part3_prob3_LQR_DW.HILInitialize_POSortedFreqs[0],
        &part3_prob3_LQR_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(part3_prob3_LQR_M, _rt_error_message);
        return;
      }
    }

    if ((part3_prob3_LQR_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (part3_prob3_LQR_P.HILInitialize_set_pwm_outputs_g && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &part3_prob3_LQR_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = part3_prob3_LQR_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(part3_prob3_LQR_DW.HILInitialize_Card,
        part3_prob3_LQR_P.HILInitialize_pwm_channels, 8U,
        &part3_prob3_LQR_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(part3_prob3_LQR_M, _rt_error_message);
        return;
      }
    }

    if (part3_prob3_LQR_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &part3_prob3_LQR_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = part3_prob3_LQR_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (part3_prob3_LQR_DW.HILInitialize_Card,
         part3_prob3_LQR_P.HILInitialize_pwm_channels, 8U,
         &part3_prob3_LQR_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(part3_prob3_LQR_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S2>/HIL Read Encoder Timebase' */

  /* S-Function Block: part3_prob3_LQR/Heli 3D1/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (part3_prob3_LQR_DW.HILInitialize_Card,
       part3_prob3_LQR_P.HILReadEncoderTimebase_samples_,
       part3_prob3_LQR_P.HILReadEncoderTimebase_channels, 3,
       &part3_prob3_LQR_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(part3_prob3_LQR_M, _rt_error_message);
    }
  }

  /* Start for RateTransition: '<S3>/Rate Transition: x' */
  part3_prob3_LQR_B.RateTransitionx = part3_prob3_LQR_P.RateTransitionx_X0;

  /* Start for RateTransition: '<S3>/Rate Transition: y' */
  part3_prob3_LQR_B.RateTransitiony = part3_prob3_LQR_P.RateTransitiony_X0;

  /* Start for S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: part3_prob3_LQR/Joystick1/Game Controller (game_controller_block) */
  {
    if (part3_prob3_LQR_P.GameController_Enabled) {
      t_double deadzone[6];
      t_double saturation[6];
      t_int index;
      t_error result;
      for (index = 0; index < 6; index++) {
        deadzone[index] = -1;
      }

      for (index = 0; index < 6; index++) {
        saturation[index] = -1;
      }

      result = game_controller_open
        (part3_prob3_LQR_P.GameController_ControllerNumber,
         part3_prob3_LQR_P.GameController_BufferSize, deadzone, saturation,
         part3_prob3_LQR_P.GameController_AutoCenter, 0, 1.0,
         &part3_prob3_LQR_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(part3_prob3_LQR_M, _rt_error_message);
      }
    }
  }

  /* InitializeConditions for TransferFcn: '<S2>/Travel: Transfer Fcn' */
  part3_prob3_LQR_X.TravelTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S2>/Pitch: Transfer Fcn' */
  part3_prob3_LQR_X.PitchTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S2>/Elevation: Transfer Fcn' */
  part3_prob3_LQR_X.ElevationTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S4>/Integrator1' */
  part3_prob3_LQR_X.Integrator1_CSTATE = part3_prob3_LQR_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  part3_prob3_LQR_X.Integrator_CSTATE = part3_prob3_LQR_P.Integrator_IC;

  /* InitializeConditions for RateTransition: '<S3>/Rate Transition: x' */
  part3_prob3_LQR_DW.RateTransitionx_Buffer0 =
    part3_prob3_LQR_P.RateTransitionx_X0;

  /* InitializeConditions for RateTransition: '<S3>/Rate Transition: y' */
  part3_prob3_LQR_DW.RateTransitiony_Buffer0 =
    part3_prob3_LQR_P.RateTransitiony_X0;
}

/* Model terminate function */
void part3_prob3_LQR_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: part3_prob3_LQR/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(part3_prob3_LQR_DW.HILInitialize_Card);
    hil_monitor_stop_all(part3_prob3_LQR_DW.HILInitialize_Card);
    is_switching = false;
    if ((part3_prob3_LQR_P.HILInitialize_set_analog_out_ex && !is_switching) ||
        (part3_prob3_LQR_P.HILInitialize_set_analog_outp_c && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &part3_prob3_LQR_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = part3_prob3_LQR_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((part3_prob3_LQR_P.HILInitialize_set_pwm_output_ap && !is_switching) ||
        (part3_prob3_LQR_P.HILInitialize_set_pwm_outputs_p && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &part3_prob3_LQR_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = part3_prob3_LQR_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(part3_prob3_LQR_DW.HILInitialize_Card
                         , part3_prob3_LQR_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , part3_prob3_LQR_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &part3_prob3_LQR_DW.HILInitialize_AOVoltages[0]
                         , &part3_prob3_LQR_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(part3_prob3_LQR_DW.HILInitialize_Card,
            part3_prob3_LQR_P.HILInitialize_analog_output_cha,
            num_final_analog_outputs,
            &part3_prob3_LQR_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(part3_prob3_LQR_DW.HILInitialize_Card,
            part3_prob3_LQR_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &part3_prob3_LQR_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(part3_prob3_LQR_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(part3_prob3_LQR_DW.HILInitialize_Card);
    hil_monitor_delete_all(part3_prob3_LQR_DW.HILInitialize_Card);
    hil_close(part3_prob3_LQR_DW.HILInitialize_Card);
    part3_prob3_LQR_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: part3_prob3_LQR/Joystick1/Game Controller (game_controller_block) */
  {
    if (part3_prob3_LQR_P.GameController_Enabled) {
      game_controller_close(part3_prob3_LQR_DW.GameController_Controller);
      part3_prob3_LQR_DW.GameController_Controller = NULL;
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  part3_prob3_LQR_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  part3_prob3_LQR_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  part3_prob3_LQR_initialize();
}

void MdlTerminate(void)
{
  part3_prob3_LQR_terminate();
}

/* Registration function */
RT_MODEL_part3_prob3_LQR_T *part3_prob3_LQR(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)part3_prob3_LQR_M, 0,
                sizeof(RT_MODEL_part3_prob3_LQR_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&part3_prob3_LQR_M->solverInfo,
                          &part3_prob3_LQR_M->Timing.simTimeStep);
    rtsiSetTPtr(&part3_prob3_LQR_M->solverInfo, &rtmGetTPtr(part3_prob3_LQR_M));
    rtsiSetStepSizePtr(&part3_prob3_LQR_M->solverInfo,
                       &part3_prob3_LQR_M->Timing.stepSize0);
    rtsiSetdXPtr(&part3_prob3_LQR_M->solverInfo,
                 &part3_prob3_LQR_M->ModelData.derivs);
    rtsiSetContStatesPtr(&part3_prob3_LQR_M->solverInfo, (real_T **)
                         &part3_prob3_LQR_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&part3_prob3_LQR_M->solverInfo,
      &part3_prob3_LQR_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&part3_prob3_LQR_M->solverInfo, (&rtmGetErrorStatus
      (part3_prob3_LQR_M)));
    rtsiSetRTModelPtr(&part3_prob3_LQR_M->solverInfo, part3_prob3_LQR_M);
  }

  rtsiSetSimTimeStep(&part3_prob3_LQR_M->solverInfo, MAJOR_TIME_STEP);
  part3_prob3_LQR_M->ModelData.intgData.f[0] = part3_prob3_LQR_M->
    ModelData.odeF[0];
  part3_prob3_LQR_M->ModelData.contStates = ((real_T *) &part3_prob3_LQR_X);
  rtsiSetSolverData(&part3_prob3_LQR_M->solverInfo, (void *)
                    &part3_prob3_LQR_M->ModelData.intgData);
  rtsiSetSolverName(&part3_prob3_LQR_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = part3_prob3_LQR_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    part3_prob3_LQR_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    part3_prob3_LQR_M->Timing.sampleTimes =
      (&part3_prob3_LQR_M->Timing.sampleTimesArray[0]);
    part3_prob3_LQR_M->Timing.offsetTimes =
      (&part3_prob3_LQR_M->Timing.offsetTimesArray[0]);

    /* task periods */
    part3_prob3_LQR_M->Timing.sampleTimes[0] = (0.0);
    part3_prob3_LQR_M->Timing.sampleTimes[1] = (0.002);
    part3_prob3_LQR_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    part3_prob3_LQR_M->Timing.offsetTimes[0] = (0.0);
    part3_prob3_LQR_M->Timing.offsetTimes[1] = (0.0);
    part3_prob3_LQR_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(part3_prob3_LQR_M, &part3_prob3_LQR_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = part3_prob3_LQR_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      part3_prob3_LQR_M->Timing.perTaskSampleHitsArray;
    part3_prob3_LQR_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    part3_prob3_LQR_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(part3_prob3_LQR_M, -1);
  part3_prob3_LQR_M->Timing.stepSize0 = 0.002;
  part3_prob3_LQR_M->Timing.stepSize1 = 0.002;
  part3_prob3_LQR_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  part3_prob3_LQR_M->Sizes.checksums[0] = (3667483918U);
  part3_prob3_LQR_M->Sizes.checksums[1] = (4183282443U);
  part3_prob3_LQR_M->Sizes.checksums[2] = (1759694757U);
  part3_prob3_LQR_M->Sizes.checksums[3] = (505352774U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    part3_prob3_LQR_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(part3_prob3_LQR_M->extModeInfo,
      &part3_prob3_LQR_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(part3_prob3_LQR_M->extModeInfo,
                        part3_prob3_LQR_M->Sizes.checksums);
    rteiSetTPtr(part3_prob3_LQR_M->extModeInfo, rtmGetTPtr(part3_prob3_LQR_M));
  }

  part3_prob3_LQR_M->solverInfoPtr = (&part3_prob3_LQR_M->solverInfo);
  part3_prob3_LQR_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&part3_prob3_LQR_M->solverInfo, 0.002);
  rtsiSetSolverMode(&part3_prob3_LQR_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  part3_prob3_LQR_M->ModelData.blockIO = ((void *) &part3_prob3_LQR_B);

  {
    part3_prob3_LQR_B.TravelCounttorad = 0.0;
    part3_prob3_LQR_B.Gain = 0.0;
    part3_prob3_LQR_B.Gain_p = 0.0;
    part3_prob3_LQR_B.PitchCounttorad = 0.0;
    part3_prob3_LQR_B.Gain_j = 0.0;
    part3_prob3_LQR_B.Sum1 = 0.0;
    part3_prob3_LQR_B.Gain_p2 = 0.0;
    part3_prob3_LQR_B.ElevationCounttorad = 0.0;
    part3_prob3_LQR_B.Gain_g = 0.0;
    part3_prob3_LQR_B.Sum2 = 0.0;
    part3_prob3_LQR_B.Gain_o = 0.0;
    part3_prob3_LQR_B.RateTransitionx = 0.0;
    part3_prob3_LQR_B.Joystick_gain_x = 0.0;
    part3_prob3_LQR_B.invertsteering2 = 0.0;
    part3_prob3_LQR_B.RateTransitiony = 0.0;
    part3_prob3_LQR_B.Joystick_gain_y = 0.0;
    part3_prob3_LQR_B.invertsteering1 = 0.0;
    part3_prob3_LQR_B.P_LQR[0] = 0.0;
    part3_prob3_LQR_B.P_LQR[1] = 0.0;
    part3_prob3_LQR_B.FrontmotorSaturation = 0.0;
    part3_prob3_LQR_B.BackmotorSaturation = 0.0;
    part3_prob3_LQR_B.GameController_o4 = 0.0;
    part3_prob3_LQR_B.GameController_o5 = 0.0;
    part3_prob3_LQR_B.Sum2_m = 0.0;
    part3_prob3_LQR_B.Sum3 = 0.0;
  }

  /* parameters */
  part3_prob3_LQR_M->ModelData.defaultParam = ((real_T *)&part3_prob3_LQR_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &part3_prob3_LQR_X;
    part3_prob3_LQR_M->ModelData.contStates = (x);
    (void) memset((void *)&part3_prob3_LQR_X, 0,
                  sizeof(X_part3_prob3_LQR_T));
  }

  /* states (dwork) */
  part3_prob3_LQR_M->ModelData.dwork = ((void *) &part3_prob3_LQR_DW);
  (void) memset((void *)&part3_prob3_LQR_DW, 0,
                sizeof(DW_part3_prob3_LQR_T));

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      part3_prob3_LQR_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      part3_prob3_LQR_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      part3_prob3_LQR_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      part3_prob3_LQR_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      part3_prob3_LQR_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      part3_prob3_LQR_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      part3_prob3_LQR_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      part3_prob3_LQR_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  part3_prob3_LQR_DW.RateTransitionx_Buffer0 = 0.0;
  part3_prob3_LQR_DW.RateTransitiony_Buffer0 = 0.0;
  part3_prob3_LQR_DW.HILWriteAnalog_Buffer[0] = 0.0;
  part3_prob3_LQR_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    part3_prob3_LQR_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  part3_prob3_LQR_M->Sizes.numContStates = (5);/* Number of continuous states */
  part3_prob3_LQR_M->Sizes.numY = (0); /* Number of model outputs */
  part3_prob3_LQR_M->Sizes.numU = (0); /* Number of model inputs */
  part3_prob3_LQR_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  part3_prob3_LQR_M->Sizes.numSampTimes = (3);/* Number of sample times */
  part3_prob3_LQR_M->Sizes.numBlocks = (59);/* Number of blocks */
  part3_prob3_LQR_M->Sizes.numBlockIO = (24);/* Number of block outputs */
  part3_prob3_LQR_M->Sizes.numBlockPrms = (162);/* Sum of parameter "widths" */
  return part3_prob3_LQR_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
