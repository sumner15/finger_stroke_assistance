/*
 * FingerStrokeAssistance.c
 *
 * Code generation for model "FingerStrokeAssistance".
 *
 * Model version              : 1.1213
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Tue Jun 20 17:04:50 2017
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_logging_mmi.h"
#include "FingerStrokeAssistance_capi.h"
#include "FingerStrokeAssistance.h"
#include "FingerStrokeAssistance_private.h"

/* Block signals (auto storage) */
B_FingerStrokeAssistance_T FingerStrokeAssistance_B;

/* Block states (auto storage) */
DW_FingerStrokeAssistance_T FingerStrokeAssistance_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_FingerStrokeAssistance_T FingerStrokeAssistance_PrevZCX;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_FingerStrokeAssistance_T FingerStrokeAssistance_Y;

/* Real-time model */
RT_MODEL_FingerStrokeAssistance_T FingerStrokeAssistance_M_;
RT_MODEL_FingerStrokeAssistance_T *const FingerStrokeAssistance_M =
  &FingerStrokeAssistance_M_;

/*
 * Output and update for atomic system:
 *    '<S30>/MATLAB Function'
 *    '<S32>/MATLAB Function'
 *    '<S33>/MATLAB Function'
 */
void FingerStrokeAssi_MATLABFunction(real_T rtu_input1, real_T rtu_input2,
  real_T rtu_leftyMode, B_MATLABFunction_FingerStroke_T *localB)
{
  /* MATLAB Function 'Robot/account for handedness/MATLAB Function': '<S36>:1' */
  /*  encoder 1 and output 1 relate to the blue mechanism */
  /*  encoder 2, output 2 and accel 2 relate to the gold mechanism */
  /*  in right hand mode, we want the gold mechanism to control the index finger */
  /*  in left hand mode, we want the blue mechanism to control the index finger */
  /*  we wallways want the index finger to be finger 1 */
  if (rtu_leftyMode == 1.0) {
    /* '<S36>:1:10' */
    /* '<S36>:1:11' */
    localB->output1 = rtu_input1;

    /* '<S36>:1:12' */
    localB->output2 = rtu_input2;
  } else {
    /* '<S36>:1:14' */
    localB->output1 = rtu_input2;

    /* '<S36>:1:15' */
    localB->output2 = rtu_input1;
  }
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/*
 * Output and update for atomic system:
 *    '<S42>/gainramp'
 *    '<S43>/gainramp'
 *    '<S44>/gainramp'
 *    '<S45>/gainramp'
 *    '<S46>/gainramp'
 *    '<S47>/gainramp'
 */
void FingerStrokeAssistance_gainramp(real_T rtu_tr, real_T rtu_valD, const
  real_T rtu_state[4], B_gainramp_FingerStrokeAssist_T *localB)
{
  real_T Rd;
  localB->state1[0] = rtu_state[0];
  localB->state1[1] = rtu_state[1];
  localB->state1[2] = rtu_state[2];
  localB->state1[3] = rtu_state[3];

  /* MATLAB Function 'parameters/gain transition/gainramp': '<S48>:1' */
  /*  state contains [valD_,val_,Ro_,t_] */
  /*  first we need to check if they have changed the desired Value */
  if (!(rtu_valD == rtu_state[0])) {
    /* '<S48>:1:6' */
    /* '<S48>:1:7' */
    localB->state1[0] = rtu_valD;

    /* '<S48>:1:8' */
    localB->state1[3] = 0.0;

    /* '<S48>:1:9' */
    localB->state1[2] = rtu_valD - rtu_state[1];
  }

  /* '<S48>:1:12' */
  /* '<S48>:1:13' */
  if ((localB->state1[3] <= rtu_tr) && (rtu_tr != 0.0)) {
    /* '<S48>:1:15' */
    /* '<S48>:1:16' */
    Rd = localB->state1[2] - ((10.0 * rt_powd_snf(localB->state1[3], 3.0) /
      rt_powd_snf(rtu_tr, 3.0) - 15.0 * rt_powd_snf(localB->state1[3], 4.0) /
      rt_powd_snf(rtu_tr, 4.0)) + 6.0 * rt_powd_snf(localB->state1[3], 5.0) /
      rt_powd_snf(rtu_tr, 5.0)) * localB->state1[2];
  } else {
    /* '<S48>:1:18' */
    Rd = 0.0;
  }

  /* '<S48>:1:21' */
  Rd = localB->state1[0] - Rd;

  /* '<S48>:1:22' */
  localB->state1[1] = Rd;

  /* '<S48>:1:23' */
  localB->state1[3] += 0.001;

  /* '<S48>:1:24' */
  localB->val = Rd;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model output function */
static void FingerStrokeAssistance_output(void)
{
  real_T state;
  ZCEventType zcEvent;
  real_T u1;
  real_T u2;

  /* Reset subsysRan breadcrumbs */
  srClearBC(FingerStrokeAssistance_DW.TriggeredSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(FingerStrokeAssistance_DW.TriggeredSubsystem1_SubsysRanBC);

  /* Level2 S-Function Block: '<S7>/PCI-6221 AD1' (adnipcim) */
  {
    SimStruct *rts = FingerStrokeAssistance_M->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }

  /* MATLAB Function: '<S7>/MATLAB Function1' */
  /* MATLAB Function 'Robot/MATLAB Function1': '<S19>:1' */
  /* '<S19>:1:3' */
  FingerStrokeAssistance_B.Pressure = (FingerStrokeAssistance_B.PCI6221AD1_o10 -
    0.5) * 3.75;

  /* MATLAB Function: '<S7>/MATLAB Function3' */
  /* MATLAB Function 'Robot/MATLAB Function3': '<S21>:1' */
  /* '<S21>:1:8' */
  FingerStrokeAssistance_DW.bufSum_a -= FingerStrokeAssistance_DW.buf_g[(int32_T)
    FingerStrokeAssistance_DW.i_g - 1];

  /* '<S21>:1:9' */
  FingerStrokeAssistance_DW.buf_g[(int32_T)FingerStrokeAssistance_DW.i_g - 1] =
    FingerStrokeAssistance_B.PCI6221AD1_o12;

  /* '<S21>:1:10' */
  FingerStrokeAssistance_DW.bufSum_a += FingerStrokeAssistance_B.PCI6221AD1_o12;

  /* '<S21>:1:11' */
  FingerStrokeAssistance_DW.i_g++;
  if (FingerStrokeAssistance_DW.i_g > 50.0) {
    /* '<S21>:1:12' */
    /* '<S21>:1:13' */
    FingerStrokeAssistance_DW.i_g = 1.0;
  }

  /* '<S21>:1:15' */
  FingerStrokeAssistance_B.Raw_Average_Grip_Force =
    FingerStrokeAssistance_DW.bufSum_a / 50.0;

  /* End of MATLAB Function: '<S7>/MATLAB Function3' */

  /* MATLAB Function: '<S7>/MATLAB Function' */
  /* MATLAB Function 'Robot/MATLAB Function': '<S18>:1' */
  /* '<S18>:1:2' */
  /* voltage */
  /* '<S18>:1:4' */
  /* Kilograms */
  /* '<S18>:1:5' */
  /* Kilograms */
  /* '<S18>:1:7' */
  /* '<S18>:1:10' */
  FingerStrokeAssistance_B.GripForce =
    (FingerStrokeAssistance_B.Raw_Average_Grip_Force - 2.43) * 0.5 /
    0.7799999999999998 * 9.80665002864;

  /* MATLAB Function: '<S7>/MATLAB Function4' */
  /*  conversion to Netwons */
  /* MATLAB Function 'Robot/MATLAB Function4': '<S22>:1' */
  /* '<S22>:1:8' */
  FingerStrokeAssistance_DW.bufSum_l -= FingerStrokeAssistance_DW.buf_e[(int32_T)
    FingerStrokeAssistance_DW.i_a - 1];

  /* '<S22>:1:9' */
  FingerStrokeAssistance_DW.buf_e[(int32_T)FingerStrokeAssistance_DW.i_a - 1] =
    FingerStrokeAssistance_B.PCI6221AD1_o9;

  /* '<S22>:1:10' */
  FingerStrokeAssistance_DW.bufSum_l += FingerStrokeAssistance_B.PCI6221AD1_o9;

  /* '<S22>:1:11' */
  FingerStrokeAssistance_DW.i_a++;
  if (FingerStrokeAssistance_DW.i_a > 50.0) {
    /* '<S22>:1:12' */
    /* '<S22>:1:13' */
    FingerStrokeAssistance_DW.i_a = 1.0;
  }

  /* '<S22>:1:15' */
  FingerStrokeAssistance_B.Raw_avg_x_acc = FingerStrokeAssistance_DW.bufSum_l /
    50.0;

  /* End of MATLAB Function: '<S7>/MATLAB Function4' */

  /* MATLAB Function: '<S7>/MATLAB Function7' */
  /* MATLAB Function 'Robot/MATLAB Function7': '<S25>:1' */
  /* '<S25>:1:4' */
  /* '<S25>:1:6' */
  FingerStrokeAssistance_B.x_acc = (FingerStrokeAssistance_B.Raw_avg_x_acc -
    1.24) / 0.24;

  /* MATLAB Function: '<S7>/MATLAB Function2' */
  /* MATLAB Function 'Robot/MATLAB Function2': '<S20>:1' */
  /* '<S20>:1:8' */
  FingerStrokeAssistance_DW.bufSum_e -= FingerStrokeAssistance_DW.buf_i[(int32_T)
    FingerStrokeAssistance_DW.i_o - 1];

  /* '<S20>:1:9' */
  FingerStrokeAssistance_DW.buf_i[(int32_T)FingerStrokeAssistance_DW.i_o - 1] =
    FingerStrokeAssistance_B.PCI6221AD1_o11;

  /* '<S20>:1:10' */
  FingerStrokeAssistance_DW.bufSum_e += FingerStrokeAssistance_B.PCI6221AD1_o11;

  /* '<S20>:1:11' */
  FingerStrokeAssistance_DW.i_o++;
  if (FingerStrokeAssistance_DW.i_o > 50.0) {
    /* '<S20>:1:12' */
    /* '<S20>:1:13' */
    FingerStrokeAssistance_DW.i_o = 1.0;
  }

  /* '<S20>:1:15' */
  FingerStrokeAssistance_B.Raw_avg_y_acc = FingerStrokeAssistance_DW.bufSum_e /
    50.0;

  /* End of MATLAB Function: '<S7>/MATLAB Function2' */

  /* MATLAB Function: '<S7>/MATLAB Function8' */
  /* MATLAB Function 'Robot/MATLAB Function8': '<S26>:1' */
  /* '<S26>:1:4' */
  /* '<S26>:1:6' */
  FingerStrokeAssistance_B.y_acc = (FingerStrokeAssistance_B.Raw_avg_y_acc -
    1.245) / 0.24499999999999988;

  /* MATLAB Function: '<S7>/MATLAB Function5' */
  /* MATLAB Function 'Robot/MATLAB Function5': '<S23>:1' */
  /* '<S23>:1:8' */
  FingerStrokeAssistance_DW.bufSum -= FingerStrokeAssistance_DW.buf[(int32_T)
    FingerStrokeAssistance_DW.i - 1];

  /* '<S23>:1:9' */
  FingerStrokeAssistance_DW.buf[(int32_T)FingerStrokeAssistance_DW.i - 1] =
    FingerStrokeAssistance_B.PCI6221AD1_o2;

  /* '<S23>:1:10' */
  FingerStrokeAssistance_DW.bufSum += FingerStrokeAssistance_B.PCI6221AD1_o2;

  /* '<S23>:1:11' */
  FingerStrokeAssistance_DW.i++;
  if (FingerStrokeAssistance_DW.i > 50.0) {
    /* '<S23>:1:12' */
    /* '<S23>:1:13' */
    FingerStrokeAssistance_DW.i = 1.0;
  }

  /* '<S23>:1:15' */
  FingerStrokeAssistance_B.Raw_avg_Z_acc = FingerStrokeAssistance_DW.bufSum /
    50.0;

  /* End of MATLAB Function: '<S7>/MATLAB Function5' */

  /* MATLAB Function: '<S7>/MATLAB Function6' */
  /* MATLAB Function 'Robot/MATLAB Function6': '<S24>:1' */
  /* '<S24>:1:4' */
  /* '<S24>:1:6' */
  FingerStrokeAssistance_B.Z_acc = (FingerStrokeAssistance_B.Raw_avg_Z_acc -
    1.3250000000000002) / 0.24499999999999988;

  /* Outport: '<Root>/Out1' */
  FingerStrokeAssistance_Y.Out1[0] = FingerStrokeAssistance_B.Pressure;
  FingerStrokeAssistance_Y.Out1[1] = FingerStrokeAssistance_B.GripForce;
  FingerStrokeAssistance_Y.Out1[2] = FingerStrokeAssistance_B.x_acc;
  FingerStrokeAssistance_Y.Out1[3] = FingerStrokeAssistance_B.y_acc;
  FingerStrokeAssistance_Y.Out1[4] = FingerStrokeAssistance_B.Z_acc;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<S5>/Constant'
   */
  FingerStrokeAssistance_B.DataTypeConversion =
    FingerStrokeAssistance_P.Constant_Value_i;

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Constant: '<S6>/Constant'
   */
  FingerStrokeAssistance_B.DataTypeConversion1 =
    FingerStrokeAssistance_P.Constant_Value_j;

  /* Delay: '<S1>/Delay' */
  FingerStrokeAssistance_B.Delay[0] = FingerStrokeAssistance_DW.Delay_DSTATE[0];
  FingerStrokeAssistance_B.Delay[1] = FingerStrokeAssistance_DW.Delay_DSTATE[1];

  /* DiscreteFilter: '<S1>/Discrete Filter1' */
  state = FingerStrokeAssistance_B.Delay[1];
  state -= FingerStrokeAssistance_P.DiscreteFilter1_DenCoef[1] *
    FingerStrokeAssistance_DW.DiscreteFilter1_states;
  state /= FingerStrokeAssistance_P.DiscreteFilter1_DenCoef[0];
  FingerStrokeAssistance_DW.DiscreteFilter1_tmp = state;
  state = FingerStrokeAssistance_P.DiscreteFilter1_NumCoef[0] *
    FingerStrokeAssistance_DW.DiscreteFilter1_tmp;
  state += FingerStrokeAssistance_P.DiscreteFilter1_NumCoef[1] *
    FingerStrokeAssistance_DW.DiscreteFilter1_states;
  FingerStrokeAssistance_B.DiscreteFilter1 = state;

  /* Gain: '<S1>/Gain1' */
  FingerStrokeAssistance_B.Gain1 = FingerStrokeAssistance_P.Gain1_Gain *
    FingerStrokeAssistance_B.DiscreteFilter1;

  /* Gain: '<S1>/Damping' */
  FingerStrokeAssistance_B.Damping = FingerStrokeAssistance_P.Damping_Gain *
    FingerStrokeAssistance_B.Gain1;

  /* Delay: '<S1>/Delay1' */
  FingerStrokeAssistance_B.Delay1 = FingerStrokeAssistance_DW.Delay1_DSTATE;

  /* UnitDelay: '<S13>/Delay Input1' */
  FingerStrokeAssistance_B.Uk1 = FingerStrokeAssistance_DW.DelayInput1_DSTATE;

  /* RelationalOperator: '<S13>/FixPt Relational Operator' */
  FingerStrokeAssistance_B.FixPtRelationalOperator =
    (FingerStrokeAssistance_B.Delay1 != FingerStrokeAssistance_B.Uk1);

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  FingerStrokeAssistance_B.DataTypeConversion_p =
    FingerStrokeAssistance_B.FixPtRelationalOperator;

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  if (((FingerStrokeAssistance_B.DataTypeConversion_p > 0.0) &&
       (FingerStrokeAssistance_DW.DiscreteTimeIntegrator_PrevRese <= 0)) ||
      ((FingerStrokeAssistance_B.DataTypeConversion_p <= 0.0) &&
       (FingerStrokeAssistance_DW.DiscreteTimeIntegrator_PrevRese == 1))) {
    FingerStrokeAssistance_DW.DiscreteTimeIntegrator_DSTATE =
      FingerStrokeAssistance_P.DiscreteTimeIntegrator_IC;
  }

  if (FingerStrokeAssistance_DW.DiscreteTimeIntegrator_DSTATE >=
      FingerStrokeAssistance_P.DiscreteTimeIntegrator_UpperSat) {
    FingerStrokeAssistance_DW.DiscreteTimeIntegrator_DSTATE =
      FingerStrokeAssistance_P.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (FingerStrokeAssistance_DW.DiscreteTimeIntegrator_DSTATE <=
        FingerStrokeAssistance_P.DiscreteTimeIntegrator_LowerSat) {
      FingerStrokeAssistance_DW.DiscreteTimeIntegrator_DSTATE =
        FingerStrokeAssistance_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  FingerStrokeAssistance_B.DiscreteTimeIntegrator =
    FingerStrokeAssistance_DW.DiscreteTimeIntegrator_DSTATE;

  /* End of DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */

  /* UnitDelay: '<Root>/Unit Delay' */
  FingerStrokeAssistance_B.UnitDelay =
    FingerStrokeAssistance_DW.UnitDelay_DSTATE;

  /* UnitDelay: '<S8>/Unit Delay2' */
  FingerStrokeAssistance_B.UnitDelay2 =
    FingerStrokeAssistance_DW.UnitDelay2_DSTATE;

  /* UnitDelay: '<S40>/Delay Input1' */
  FingerStrokeAssistance_B.Uk1_o =
    FingerStrokeAssistance_DW.DelayInput1_DSTATE_l;

  /* RelationalOperator: '<S40>/FixPt Relational Operator' */
  FingerStrokeAssistance_B.FixPtRelationalOperator_i =
    (FingerStrokeAssistance_B.UnitDelay2 != FingerStrokeAssistance_B.Uk1_o);

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  FingerStrokeAssistance_B.DataTypeConversion_o =
    FingerStrokeAssistance_B.FixPtRelationalOperator_i;

  /* DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
  if (((FingerStrokeAssistance_B.DataTypeConversion_o > 0.0) &&
       (FingerStrokeAssistance_DW.DiscreteTimeIntegrator_PrevRe_i <= 0)) ||
      ((FingerStrokeAssistance_B.DataTypeConversion_o <= 0.0) &&
       (FingerStrokeAssistance_DW.DiscreteTimeIntegrator_PrevRe_i == 1))) {
    FingerStrokeAssistance_DW.DiscreteTimeIntegrator_DSTATE_i =
      FingerStrokeAssistance_P.DiscreteTimeIntegrator_IC_k;
  }

  FingerStrokeAssistance_B.DiscreteTimeIntegrator_e =
    FingerStrokeAssistance_DW.DiscreteTimeIntegrator_DSTATE_i;

  /* End of DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */

  /* UnitDelay: '<Root>/Unit Delay3' */
  FingerStrokeAssistance_B.UnitDelay3[0] =
    FingerStrokeAssistance_DW.UnitDelay3_DSTATE[0];

  /* UnitDelay: '<Root>/Unit Delay2' */
  FingerStrokeAssistance_B.UnitDelay2_p[0] =
    FingerStrokeAssistance_DW.UnitDelay2_DSTATE_f[0];

  /* UnitDelay: '<Root>/Unit Delay3' */
  FingerStrokeAssistance_B.UnitDelay3[1] =
    FingerStrokeAssistance_DW.UnitDelay3_DSTATE[1];

  /* UnitDelay: '<Root>/Unit Delay2' */
  FingerStrokeAssistance_B.UnitDelay2_p[1] =
    FingerStrokeAssistance_DW.UnitDelay2_DSTATE_f[1];

  /* UnitDelay: '<S9>/Unit Delay2' */
  FingerStrokeAssistance_B.UnitDelay2_j =
    FingerStrokeAssistance_DW.UnitDelay2_DSTATE_h;

  /* UnitDelay: '<S41>/Delay Input1' */
  FingerStrokeAssistance_B.Uk1_m =
    FingerStrokeAssistance_DW.DelayInput1_DSTATE_j;

  /* RelationalOperator: '<S41>/FixPt Relational Operator' */
  FingerStrokeAssistance_B.FixPtRelationalOperator_f =
    (FingerStrokeAssistance_B.UnitDelay2_j != FingerStrokeAssistance_B.Uk1_m);

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  FingerStrokeAssistance_B.DataTypeConversion_a =
    FingerStrokeAssistance_B.FixPtRelationalOperator_f;

  /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
  if (((FingerStrokeAssistance_B.DataTypeConversion_a > 0.0) &&
       (FingerStrokeAssistance_DW.DiscreteTimeIntegrator_PrevRe_p <= 0)) ||
      ((FingerStrokeAssistance_B.DataTypeConversion_a <= 0.0) &&
       (FingerStrokeAssistance_DW.DiscreteTimeIntegrator_PrevRe_p == 1))) {
    FingerStrokeAssistance_DW.DiscreteTimeIntegrator_DSTATE_o =
      FingerStrokeAssistance_P.DiscreteTimeIntegrator_IC_l;
  }

  FingerStrokeAssistance_B.DiscreteTimeIntegrator_k =
    FingerStrokeAssistance_DW.DiscreteTimeIntegrator_DSTATE_o;

  /* End of DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */

  /* Level2 S-Function Block: '<S7>/PCI 6221 ENC ' (encnipcim) */
  {
    SimStruct *rts = FingerStrokeAssistance_M->childSfunctions[1];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S7>/PCI 6221 ENC 1' (encnipcim) */
  {
    SimStruct *rts = FingerStrokeAssistance_M->childSfunctions[2];
    sfcnOutputs(rts, 0);
  }

  /* Gain: '<S11>/parLeftMode' incorporates:
   *  Constant: '<S11>/paremeters_ must_be_one'
   */
  FingerStrokeAssistance_B.parLeftMode =
    FingerStrokeAssistance_P.parLeftMode_Gain *
    FingerStrokeAssistance_P.paremeters_must_be_one_Value;

  /* Saturate: '<S11>/Saturation' */
  state = FingerStrokeAssistance_B.parLeftMode;
  u1 = FingerStrokeAssistance_P.Saturation_LowerSat;
  u2 = FingerStrokeAssistance_P.Saturation_UpperSat;
  if (state > u2) {
    FingerStrokeAssistance_B.Saturation = u2;
  } else if (state < u1) {
    FingerStrokeAssistance_B.Saturation = u1;
  } else {
    FingerStrokeAssistance_B.Saturation = state;
  }

  /* End of Saturate: '<S11>/Saturation' */

  /* MATLAB Function: '<S32>/MATLAB Function' */
  FingerStrokeAssi_MATLABFunction(FingerStrokeAssistance_B.PCI6221ENC,
    FingerStrokeAssistance_B.PCI6221ENC1, FingerStrokeAssistance_B.Saturation,
    &FingerStrokeAssistance_B.sf_MATLABFunction_e);

  /* Gain: '<S7>/Gain' */
  FingerStrokeAssistance_B.Gain[0] = FingerStrokeAssistance_P.Gain_Gain *
    FingerStrokeAssistance_B.sf_MATLABFunction_e.output1;
  FingerStrokeAssistance_B.Gain[1] = FingerStrokeAssistance_P.Gain_Gain *
    FingerStrokeAssistance_B.sf_MATLABFunction_e.output2;

  /* UnitDelay: '<Root>/Unit Delay1' */
  FingerStrokeAssistance_B.UnitDelay1 =
    FingerStrokeAssistance_DW.UnitDelay1_DSTATE;

  /* MATLAB Function: '<Root>/MATLAB Function' */
  FingerStrokeAssistance_B.state = FingerStrokeAssistance_B.UnitDelay;

  /* MATLAB Function 'MATLAB Function': '<S4>:1' */
  /* '<S4>:1:3' */
  state = FingerStrokeAssistance_B.state;

  /* % Create Finite State Machine for FINGER Robot */
  /* '<S4>:1:5' */
  FingerStrokeAssistance_B.ramp_switch = 0.0;

  /* '<S4>:1:6' */
  FingerStrokeAssistance_B.fp_ramp_switch = 0.0;

  /* '<S4>:1:7' */
  /* '<S4>:1:8' */
  FingerStrokeAssistance_B.f_ref_lim = 0.0;

  /* '<S4>:1:9' */
  FingerStrokeAssistance_B.enc_trigger = 0.0;

  /* '<S4>:1:10' */
  FingerStrokeAssistance_B.p_trigger = 0.0;

  /* '<S4>:1:11' */
  FingerStrokeAssistance_B.pos_ref_Ulim = 1.0;

  /* '<S4>:1:12' */
  FingerStrokeAssistance_B.pos_ref_Llim = 0.0;

  /* UnitDelay: '<S7>/Unit Delay' */
  /* '<S4>:1:13' */
  FingerStrokeAssistance_B.UnitDelay_g[0] =
    FingerStrokeAssistance_DW.UnitDelay_DSTATE_h[0];

  /* Sum: '<S7>/Sum' */
  FingerStrokeAssistance_B.Sum[0] = FingerStrokeAssistance_B.Gain[0] -
    FingerStrokeAssistance_B.UnitDelay_g[0];

  /* MATLAB Function: '<Root>/MATLAB Function' */
  FingerStrokeAssistance_B.f_ref[0] = 0.0;
  FingerStrokeAssistance_B.pos_ref[0] = FingerStrokeAssistance_B.Sum[0];

  /* UnitDelay: '<S7>/Unit Delay' */
  FingerStrokeAssistance_B.UnitDelay_g[1] =
    FingerStrokeAssistance_DW.UnitDelay_DSTATE_h[1];

  /* Sum: '<S7>/Sum' */
  FingerStrokeAssistance_B.Sum[1] = FingerStrokeAssistance_B.Gain[1] -
    FingerStrokeAssistance_B.UnitDelay_g[1];

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   *  Constant: '<Root>/Constant6'
   *  Constant: '<Root>/Constant7'
   *  Constant: '<Root>/Constant8'
   */
  FingerStrokeAssistance_B.f_ref[1] = 0.0;
  FingerStrokeAssistance_B.pos_ref[1] = FingerStrokeAssistance_B.Sum[1];
  switch ((int32_T)FingerStrokeAssistance_B.state) {
   case 1:
    /* standby phase */
    /* '<S4>:1:18' */
    FingerStrokeAssistance_B.f_ref[0] = 0.0;
    FingerStrokeAssistance_B.f_ref[1] = 0.0;

    /*  establish reference force */
    /* '<S4>:1:19' */
    FingerStrokeAssistance_B.f_ref_lim = 0.0;

    /*  establish limit for reference force */
    if (FingerStrokeAssistance_B.DataTypeConversion == 1.0) {
      /* '<S4>:1:21' */
      /*  If the main switch is on proceed to next state */
      /* '<S4>:1:22' */
      state = 2.0;
    }
    break;

   case 2:
    /* Move both linkage arms to position zero */
    /* '<S4>:1:26' */
    FingerStrokeAssistance_B.pos_ref_Ulim = (rtInf);

    /* '<S4>:1:27' */
    FingerStrokeAssistance_B.pos_ref_Llim = (rtMinusInf);

    /* '<S4>:1:28' */
    /* '<S4>:1:29' */
    FingerStrokeAssistance_B.ramp_switch = 1.0;

    /*  Define value of ramp switch */
    /* '<S4>:1:30' */
    FingerStrokeAssistance_B.f_ref[0] =
      FingerStrokeAssistance_B.DiscreteTimeIntegrator_e *
      FingerStrokeAssistance_P.Constant3_Value;
    FingerStrokeAssistance_B.f_ref[1] =
      FingerStrokeAssistance_B.DiscreteTimeIntegrator_e *
      FingerStrokeAssistance_P.Constant3_Value;

    /*  Calculate reference force */
    /* '<S4>:1:31' */
    FingerStrokeAssistance_B.f_ref_lim = 2.5;

    /*  re-establish limit for reference force */
    if ((FingerStrokeAssistance_B.DiscreteTimeIntegrator_e >= 10.0) &&
        (FingerStrokeAssistance_B.DataTypeConversion1 == 1.0)) {
      /* '<S4>:1:33' */
      /* '<S4>:1:34' */
      FingerStrokeAssistance_B.enc_trigger = 1.0;

      /* Calibrate Encoders */
      /* '<S4>:1:35' */
      FingerStrokeAssistance_B.ramp_switch = 0.0;

      /* '<S4>:1:36' */
      FingerStrokeAssistance_B.f_ref[0] = FingerStrokeAssistance_B.UnitDelay2_p
        [0];
      FingerStrokeAssistance_B.f_ref[1] = FingerStrokeAssistance_B.UnitDelay2_p
        [1];

      /* '<S4>:1:37' */
      FingerStrokeAssistance_B.f_ref_lim = 2.5;

      /* '<S4>:1:38' */
      FingerStrokeAssistance_B.p_trigger = 1.0;

      /* '<S4>:1:39' */
      state = 3.0;
    } else if ((FingerStrokeAssistance_B.DiscreteTimeIntegrator_e >= 10.0) &&
               (FingerStrokeAssistance_B.DataTypeConversion1 == 0.0)) {
      /* '<S4>:1:40' */
      /* '<S4>:1:41' */
      FingerStrokeAssistance_B.enc_trigger = 1.0;

      /* '<S4>:1:42' */
      FingerStrokeAssistance_B.ramp_switch = 0.0;

      /* '<S4>:1:43' */
      FingerStrokeAssistance_B.f_ref[0] = FingerStrokeAssistance_B.UnitDelay3[0];
      FingerStrokeAssistance_B.f_ref[1] = FingerStrokeAssistance_B.UnitDelay3[1];

      /* '<S4>:1:44' */
      FingerStrokeAssistance_B.f_ref_lim = 2.5;

      /* '<S4>:1:45' */
      state = 4.0;
    } else {
      /* '<S4>:1:47' */
      state = 2.0;
    }
    break;

   case 3:
    /* '<S4>:1:51' */
    FingerStrokeAssistance_B.pos_ref[0] = FingerStrokeAssistance_B.UnitDelay1;
    FingerStrokeAssistance_B.pos_ref[1] = 0.0;

    /* '<S4>:1:52' */
    FingerStrokeAssistance_B.pos_ref_Ulim = 1.0;

    /* '<S4>:1:53' */
    FingerStrokeAssistance_B.pos_ref_Llim = 0.0;

    /* '<S4>:1:54' */
    FingerStrokeAssistance_B.f_ref_lim = 2.5;
    if (fabs(FingerStrokeAssistance_B.UnitDelay2_p[0]) >=
        FingerStrokeAssistance_P.Constant4_Value) {
      /* '<S4>:1:56' */
      /* '<S4>:1:57' */
      u1 = FingerStrokeAssistance_B.UnitDelay2_p[0] *
        FingerStrokeAssistance_P.Constant2_Value;
      if (FingerStrokeAssistance_B.Sum[1] >=
          FingerStrokeAssistance_P.Constant7_Value) {
        /* '<S4>:1:59' */
        /* '<S4>:1:60' */
        u1 = FingerStrokeAssistance_B.UnitDelay2_p[0] *
          FingerStrokeAssistance_P.Constant8_Value;
      }
    } else {
      /* '<S4>:1:63' */
      u1 = FingerStrokeAssistance_P.Constant5_Value *
        FingerStrokeAssistance_B.Sum[0] +
        FingerStrokeAssistance_P.Constant6_Value;
    }

    /* '<S4>:1:66' */
    FingerStrokeAssistance_B.f_ref[0] = u1;
    FingerStrokeAssistance_B.f_ref[1] = FingerStrokeAssistance_B.UnitDelay2_p[0];
    if (FingerStrokeAssistance_B.DataTypeConversion == 0.0) {
      /* '<S4>:1:68' */
      /* '<S4>:1:69' */
      state = 1.0;
    }
    break;

   case 4:
    /* Operating Mode_Position Control - Control first finger linkage */
    /* '<S4>:1:73' */
    FingerStrokeAssistance_B.pos_ref[0] = FingerStrokeAssistance_B.UnitDelay1;
    FingerStrokeAssistance_B.pos_ref[1] = 0.0;

    /* '<S4>:1:74' */
    FingerStrokeAssistance_B.f_ref[0] = FingerStrokeAssistance_B.UnitDelay3[0];
    FingerStrokeAssistance_B.f_ref[1] = FingerStrokeAssistance_B.UnitDelay3[1];

    /* '<S4>:1:75' */
    FingerStrokeAssistance_B.pos_ref_Ulim = 1.0;

    /* '<S4>:1:76' */
    FingerStrokeAssistance_B.pos_ref_Llim = 0.0;

    /* '<S4>:1:77' */
    FingerStrokeAssistance_B.f_ref_lim = 5.0;
    if (FingerStrokeAssistance_B.DataTypeConversion == 0.0) {
      /* '<S4>:1:79' */
      /* '<S4>:1:80' */
      state = 1.0;
    }
    break;
  }

  FingerStrokeAssistance_B.state = state;

  /* UnitDelay: '<S7>/Unit Delay1' */
  FingerStrokeAssistance_B.UnitDelay1_n =
    FingerStrokeAssistance_DW.UnitDelay1_DSTATE_n;

  /* Sum: '<S3>/Sum1' */
  FingerStrokeAssistance_B.Sum1 = FingerStrokeAssistance_B.Pressure -
    FingerStrokeAssistance_B.UnitDelay1_n;

  /* RelationalOperator: '<S16>/LowerRelop1' incorporates:
   *  Constant: '<S3>/Constant'
   */
  FingerStrokeAssistance_B.LowerRelop1[0] = (FingerStrokeAssistance_B.Sum1 >
    FingerStrokeAssistance_B.pos_ref_Ulim);
  FingerStrokeAssistance_B.LowerRelop1[1] =
    (FingerStrokeAssistance_P.Constant_Value >
     FingerStrokeAssistance_B.pos_ref_Ulim);

  /* RelationalOperator: '<S16>/UpperRelop' incorporates:
   *  Constant: '<S3>/Constant'
   */
  FingerStrokeAssistance_B.UpperRelop[0] = (FingerStrokeAssistance_B.Sum1 <
    FingerStrokeAssistance_B.pos_ref_Llim);
  FingerStrokeAssistance_B.UpperRelop[1] =
    (FingerStrokeAssistance_P.Constant_Value <
     FingerStrokeAssistance_B.pos_ref_Llim);

  /* Switch: '<S16>/Switch' incorporates:
   *  Constant: '<S3>/Constant'
   */
  if (FingerStrokeAssistance_B.UpperRelop[0]) {
    FingerStrokeAssistance_B.Switch[0] = FingerStrokeAssistance_B.pos_ref_Llim;
  } else {
    FingerStrokeAssistance_B.Switch[0] = FingerStrokeAssistance_B.Sum1;
  }

  if (FingerStrokeAssistance_B.UpperRelop[1]) {
    FingerStrokeAssistance_B.Switch[1] = FingerStrokeAssistance_B.pos_ref_Llim;
  } else {
    FingerStrokeAssistance_B.Switch[1] = FingerStrokeAssistance_P.Constant_Value;
  }

  /* End of Switch: '<S16>/Switch' */

  /* Switch: '<S16>/Switch2' */
  if (FingerStrokeAssistance_B.LowerRelop1[0]) {
    FingerStrokeAssistance_B.Switch2[0] = FingerStrokeAssistance_B.pos_ref_Ulim;
  } else {
    FingerStrokeAssistance_B.Switch2[0] = FingerStrokeAssistance_B.Switch[0];
  }

  if (FingerStrokeAssistance_B.LowerRelop1[1]) {
    FingerStrokeAssistance_B.Switch2[1] = FingerStrokeAssistance_B.pos_ref_Ulim;
  } else {
    FingerStrokeAssistance_B.Switch2[1] = FingerStrokeAssistance_B.Switch[1];
  }

  /* End of Switch: '<S16>/Switch2' */

  /* Gain: '<S2>/Gain' */
  FingerStrokeAssistance_B.Gain_d = FingerStrokeAssistance_P.Gain_Gain_i *
    FingerStrokeAssistance_B.Switch2[0];

  /* RelationalOperator: '<S15>/LowerRelop1' */
  FingerStrokeAssistance_B.LowerRelop1_f[0] = (FingerStrokeAssistance_B.pos_ref
    [0] > FingerStrokeAssistance_B.pos_ref_Ulim);

  /* RelationalOperator: '<S15>/UpperRelop' */
  FingerStrokeAssistance_B.UpperRelop_o[0] = (FingerStrokeAssistance_B.pos_ref[0]
    < FingerStrokeAssistance_B.pos_ref_Llim);

  /* Switch: '<S15>/Switch' */
  if (FingerStrokeAssistance_B.UpperRelop_o[0]) {
    FingerStrokeAssistance_B.Switch_g[0] = FingerStrokeAssistance_B.pos_ref_Llim;
  } else {
    FingerStrokeAssistance_B.Switch_g[0] = FingerStrokeAssistance_B.pos_ref[0];
  }

  /* Switch: '<S15>/Switch2' */
  if (FingerStrokeAssistance_B.LowerRelop1_f[0]) {
    FingerStrokeAssistance_B.Switch2_d[0] =
      FingerStrokeAssistance_B.pos_ref_Ulim;
  } else {
    FingerStrokeAssistance_B.Switch2_d[0] = FingerStrokeAssistance_B.Switch_g[0];
  }

  /* Sum: '<S3>/Sum' */
  FingerStrokeAssistance_B.Sum_h[0] = FingerStrokeAssistance_B.Switch2_d[0] -
    FingerStrokeAssistance_B.Sum[0];

  /* Gain: '<S14>/Derivative Gain' */
  FingerStrokeAssistance_B.DerivativeGain[0] =
    FingerStrokeAssistance_P.DiscretePIDController_D *
    FingerStrokeAssistance_B.Sum_h[0];

  /* DiscreteIntegrator: '<S14>/Filter' */
  FingerStrokeAssistance_B.Filter[0] = FingerStrokeAssistance_DW.Filter_DSTATE[0];

  /* Sum: '<S14>/SumD' */
  FingerStrokeAssistance_B.SumD[0] = FingerStrokeAssistance_B.DerivativeGain[0]
    - FingerStrokeAssistance_B.Filter[0];

  /* Gain: '<S14>/Filter Coefficient' */
  FingerStrokeAssistance_B.FilterCoefficient[0] =
    FingerStrokeAssistance_P.DiscretePIDController_N *
    FingerStrokeAssistance_B.SumD[0];

  /* Gain: '<S14>/Integral Gain' */
  FingerStrokeAssistance_B.IntegralGain[0] =
    FingerStrokeAssistance_P.DiscretePIDController_I *
    FingerStrokeAssistance_B.Sum_h[0];

  /* DiscreteIntegrator: '<S14>/Integrator' */
  FingerStrokeAssistance_B.Integrator[0] =
    FingerStrokeAssistance_DW.Integrator_DSTATE[0];

  /* Gain: '<S14>/Proportional Gain' */
  FingerStrokeAssistance_B.ProportionalGain[0] =
    FingerStrokeAssistance_P.DiscretePIDController_P *
    FingerStrokeAssistance_B.Sum_h[0];

  /* Sum: '<S14>/Sum' */
  FingerStrokeAssistance_B.Sum_a[0] =
    (FingerStrokeAssistance_B.ProportionalGain[0] +
     FingerStrokeAssistance_B.Integrator[0]) +
    FingerStrokeAssistance_B.FilterCoefficient[0];

  /* RelationalOperator: '<S15>/LowerRelop1' */
  FingerStrokeAssistance_B.LowerRelop1_f[1] = (FingerStrokeAssistance_B.pos_ref
    [1] > FingerStrokeAssistance_B.pos_ref_Ulim);

  /* RelationalOperator: '<S15>/UpperRelop' */
  FingerStrokeAssistance_B.UpperRelop_o[1] = (FingerStrokeAssistance_B.pos_ref[1]
    < FingerStrokeAssistance_B.pos_ref_Llim);

  /* Switch: '<S15>/Switch' */
  if (FingerStrokeAssistance_B.UpperRelop_o[1]) {
    FingerStrokeAssistance_B.Switch_g[1] = FingerStrokeAssistance_B.pos_ref_Llim;
  } else {
    FingerStrokeAssistance_B.Switch_g[1] = FingerStrokeAssistance_B.pos_ref[1];
  }

  /* Switch: '<S15>/Switch2' */
  if (FingerStrokeAssistance_B.LowerRelop1_f[1]) {
    FingerStrokeAssistance_B.Switch2_d[1] =
      FingerStrokeAssistance_B.pos_ref_Ulim;
  } else {
    FingerStrokeAssistance_B.Switch2_d[1] = FingerStrokeAssistance_B.Switch_g[1];
  }

  /* Sum: '<S3>/Sum' */
  FingerStrokeAssistance_B.Sum_h[1] = FingerStrokeAssistance_B.Switch2_d[1] -
    FingerStrokeAssistance_B.Sum[1];

  /* Gain: '<S14>/Derivative Gain' */
  FingerStrokeAssistance_B.DerivativeGain[1] =
    FingerStrokeAssistance_P.DiscretePIDController_D *
    FingerStrokeAssistance_B.Sum_h[1];

  /* DiscreteIntegrator: '<S14>/Filter' */
  FingerStrokeAssistance_B.Filter[1] = FingerStrokeAssistance_DW.Filter_DSTATE[1];

  /* Sum: '<S14>/SumD' */
  FingerStrokeAssistance_B.SumD[1] = FingerStrokeAssistance_B.DerivativeGain[1]
    - FingerStrokeAssistance_B.Filter[1];

  /* Gain: '<S14>/Filter Coefficient' */
  FingerStrokeAssistance_B.FilterCoefficient[1] =
    FingerStrokeAssistance_P.DiscretePIDController_N *
    FingerStrokeAssistance_B.SumD[1];

  /* Gain: '<S14>/Integral Gain' */
  FingerStrokeAssistance_B.IntegralGain[1] =
    FingerStrokeAssistance_P.DiscretePIDController_I *
    FingerStrokeAssistance_B.Sum_h[1];

  /* DiscreteIntegrator: '<S14>/Integrator' */
  FingerStrokeAssistance_B.Integrator[1] =
    FingerStrokeAssistance_DW.Integrator_DSTATE[1];

  /* Gain: '<S14>/Proportional Gain' */
  FingerStrokeAssistance_B.ProportionalGain[1] =
    FingerStrokeAssistance_P.DiscretePIDController_P *
    FingerStrokeAssistance_B.Sum_h[1];

  /* Sum: '<S14>/Sum' */
  FingerStrokeAssistance_B.Sum_a[1] =
    (FingerStrokeAssistance_B.ProportionalGain[1] +
     FingerStrokeAssistance_B.Integrator[1]) +
    FingerStrokeAssistance_B.FilterCoefficient[1];

  /* DiscreteFilter: '<S7>/Discrete Filter1' */
  FingerStrokeAssistance_DW.DiscreteFilter1_tmp_d[0U] = 0.0;

  /* SampleTimeMath: '<S17>/TSamp'
   *
   * About '<S17>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  FingerStrokeAssistance_B.TSamp[0] = FingerStrokeAssistance_B.Sum[0] *
    FingerStrokeAssistance_P.TSamp_WtEt;

  /* UnitDelay: '<S17>/UD' */
  FingerStrokeAssistance_B.Uk1_d[0] = FingerStrokeAssistance_DW.UD_DSTATE[0];

  /* Sum: '<S17>/Diff' */
  FingerStrokeAssistance_B.Diff[0] = FingerStrokeAssistance_B.TSamp[0] -
    FingerStrokeAssistance_B.Uk1_d[0];

  /* DiscreteFilter: '<S7>/Discrete Filter1' */
  state = FingerStrokeAssistance_B.Diff[0];
  state -= FingerStrokeAssistance_P.DiscreteFilter1_DenCoef_a[1] *
    FingerStrokeAssistance_DW.DiscreteFilter1_states_g[0];
  state /= FingerStrokeAssistance_P.DiscreteFilter1_DenCoef_a[0];
  FingerStrokeAssistance_DW.DiscreteFilter1_tmp_d[0] = state;
  state = FingerStrokeAssistance_P.DiscreteFilter1_NumCoef_g[0] *
    FingerStrokeAssistance_DW.DiscreteFilter1_tmp_d[0];
  state += FingerStrokeAssistance_P.DiscreteFilter1_NumCoef_g[1] *
    FingerStrokeAssistance_DW.DiscreteFilter1_states_g[0];
  FingerStrokeAssistance_B.DiscreteFilter1_j[0] = state;

  /* SampleTimeMath: '<S17>/TSamp'
   *
   * About '<S17>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  FingerStrokeAssistance_B.TSamp[1] = FingerStrokeAssistance_B.Sum[1] *
    FingerStrokeAssistance_P.TSamp_WtEt;

  /* UnitDelay: '<S17>/UD' */
  FingerStrokeAssistance_B.Uk1_d[1] = FingerStrokeAssistance_DW.UD_DSTATE[1];

  /* Sum: '<S17>/Diff' */
  FingerStrokeAssistance_B.Diff[1] = FingerStrokeAssistance_B.TSamp[1] -
    FingerStrokeAssistance_B.Uk1_d[1];

  /* DiscreteFilter: '<S7>/Discrete Filter1' */
  state = FingerStrokeAssistance_B.Diff[1];
  state -= FingerStrokeAssistance_P.DiscreteFilter1_DenCoef_a[1] *
    FingerStrokeAssistance_DW.DiscreteFilter1_states_g[1];
  state /= FingerStrokeAssistance_P.DiscreteFilter1_DenCoef_a[0];
  FingerStrokeAssistance_DW.DiscreteFilter1_tmp_d[1] = state;
  state = FingerStrokeAssistance_P.DiscreteFilter1_NumCoef_g[0] *
    FingerStrokeAssistance_DW.DiscreteFilter1_tmp_d[1];
  state += FingerStrokeAssistance_P.DiscreteFilter1_NumCoef_g[1] *
    FingerStrokeAssistance_DW.DiscreteFilter1_states_g[1];
  FingerStrokeAssistance_B.DiscreteFilter1_j[1] = state;

  /* Outputs for Triggered SubSystem: '<S7>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S28>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &FingerStrokeAssistance_PrevZCX.TriggeredSubsystem_Trig_ZCE,
                     (FingerStrokeAssistance_B.enc_trigger));
  if (zcEvent != NO_ZCEVENT) {
    /* Inport: '<S28>/In1' */
    FingerStrokeAssistance_B.In1_g[0] = FingerStrokeAssistance_B.Gain[0];
    FingerStrokeAssistance_B.In1_g[1] = FingerStrokeAssistance_B.Gain[1];
    FingerStrokeAssistance_DW.TriggeredSubsystem_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S7>/Triggered Subsystem' */

  /* Gain: '<S7>/Gain1' */
  FingerStrokeAssistance_B.Gain1_l = FingerStrokeAssistance_P.Gain1_Gain_a *
    FingerStrokeAssistance_B.f_ref_lim;

  /* RelationalOperator: '<S27>/LowerRelop1' */
  FingerStrokeAssistance_B.LowerRelop1_p[0] = (FingerStrokeAssistance_B.f_ref[0]
    > FingerStrokeAssistance_B.f_ref_lim);

  /* RelationalOperator: '<S27>/UpperRelop' */
  FingerStrokeAssistance_B.UpperRelop_l[0] = (FingerStrokeAssistance_B.f_ref[0] <
    FingerStrokeAssistance_B.Gain1_l);

  /* Switch: '<S27>/Switch' */
  if (FingerStrokeAssistance_B.UpperRelop_l[0]) {
    FingerStrokeAssistance_B.Switch_n[0] = FingerStrokeAssistance_B.Gain1_l;
  } else {
    FingerStrokeAssistance_B.Switch_n[0] = FingerStrokeAssistance_B.f_ref[0];
  }

  /* Switch: '<S27>/Switch2' */
  if (FingerStrokeAssistance_B.LowerRelop1_p[0]) {
    FingerStrokeAssistance_B.Switch2_l[0] = FingerStrokeAssistance_B.f_ref_lim;
  } else {
    FingerStrokeAssistance_B.Switch2_l[0] = FingerStrokeAssistance_B.Switch_n[0];
  }

  /* RelationalOperator: '<S27>/LowerRelop1' */
  FingerStrokeAssistance_B.LowerRelop1_p[1] = (FingerStrokeAssistance_B.f_ref[1]
    > FingerStrokeAssistance_B.f_ref_lim);

  /* RelationalOperator: '<S27>/UpperRelop' */
  FingerStrokeAssistance_B.UpperRelop_l[1] = (FingerStrokeAssistance_B.f_ref[1] <
    FingerStrokeAssistance_B.Gain1_l);

  /* Switch: '<S27>/Switch' */
  if (FingerStrokeAssistance_B.UpperRelop_l[1]) {
    FingerStrokeAssistance_B.Switch_n[1] = FingerStrokeAssistance_B.Gain1_l;
  } else {
    FingerStrokeAssistance_B.Switch_n[1] = FingerStrokeAssistance_B.f_ref[1];
  }

  /* Switch: '<S27>/Switch2' */
  if (FingerStrokeAssistance_B.LowerRelop1_p[1]) {
    FingerStrokeAssistance_B.Switch2_l[1] = FingerStrokeAssistance_B.f_ref_lim;
  } else {
    FingerStrokeAssistance_B.Switch2_l[1] = FingerStrokeAssistance_B.Switch_n[1];
  }

  /* MATLAB Function: '<S30>/MATLAB Function' */
  FingerStrokeAssi_MATLABFunction(FingerStrokeAssistance_B.Switch2_l[0],
    FingerStrokeAssistance_B.Switch2_l[1], FingerStrokeAssistance_B.Saturation,
    &FingerStrokeAssistance_B.sf_MATLABFunction_m);

  /* Level2 S-Function Block: '<S7>/PCI-6221 DA' (danipcim) */
  {
    SimStruct *rts = FingerStrokeAssistance_M->childSfunctions[3];
    sfcnOutputs(rts, 0);
  }

  /* DiscreteStateSpace: '<S34>/Low Pass 100 Hz' */
  FingerStrokeAssistance_B.LowPass100Hz = 0.0;
  FingerStrokeAssistance_B.LowPass100Hz += FingerStrokeAssistance_P.Clow[0] *
    FingerStrokeAssistance_DW.LowPass100Hz_DSTATE[0];
  FingerStrokeAssistance_B.LowPass100Hz += FingerStrokeAssistance_P.Clow[1] *
    FingerStrokeAssistance_DW.LowPass100Hz_DSTATE[1];
  FingerStrokeAssistance_B.LowPass100Hz += FingerStrokeAssistance_P.Dlow *
    FingerStrokeAssistance_B.Switch2_l[0];

  /* DiscreteStateSpace: '<S34>/Low Pass 100 Hz1' */
  FingerStrokeAssistance_B.LowPass100Hz1 = 0.0;
  FingerStrokeAssistance_B.LowPass100Hz1 += FingerStrokeAssistance_P.Clow[0] *
    FingerStrokeAssistance_DW.LowPass100Hz1_DSTATE[0];
  FingerStrokeAssistance_B.LowPass100Hz1 += FingerStrokeAssistance_P.Clow[1] *
    FingerStrokeAssistance_DW.LowPass100Hz1_DSTATE[1];
  FingerStrokeAssistance_B.LowPass100Hz1 += FingerStrokeAssistance_P.Dlow *
    FingerStrokeAssistance_B.Switch2_l[1];

  /* Memory: '<S34>/Memory' */
  FingerStrokeAssistance_B.Memory =
    FingerStrokeAssistance_DW.Memory_PreviousInput;

  /* Memory: '<S34>/Memory1' */
  FingerStrokeAssistance_B.Memory1 =
    FingerStrokeAssistance_DW.Memory1_PreviousInput;

  /* Outputs for Triggered SubSystem: '<S7>/Triggered Subsystem1' incorporates:
   *  TriggerPort: '<S29>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &FingerStrokeAssistance_PrevZCX.TriggeredSubsystem1_Trig_ZCE,
                     (FingerStrokeAssistance_B.p_trigger));
  if (zcEvent != NO_ZCEVENT) {
    /* Inport: '<S29>/In1' */
    FingerStrokeAssistance_B.In1 = FingerStrokeAssistance_B.PCI6221AD1_o10;
    FingerStrokeAssistance_DW.TriggeredSubsystem1_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S7>/Triggered Subsystem1' */

  /* MATLAB Function: '<S33>/MATLAB Function' */
  FingerStrokeAssi_MATLABFunction(FingerStrokeAssistance_B.PCI6221AD1_o1,
    FingerStrokeAssistance_B.PCI6221AD1_o3, FingerStrokeAssistance_B.Saturation,
    &FingerStrokeAssistance_B.sf_MATLABFunction_n);

  /* UnitDelay: '<S8>/Unit Delay1' */
  FingerStrokeAssistance_B.UnitDelay1_g =
    FingerStrokeAssistance_DW.UnitDelay1_DSTATE_l;

  /* UnitDelay: '<S9>/Unit Delay1' */
  FingerStrokeAssistance_B.UnitDelay1_d =
    FingerStrokeAssistance_DW.UnitDelay1_DSTATE_i;

  /* Gain: '<S11>/parTrajMode' incorporates:
   *  Constant: '<S11>/paremeters_ must_be_one'
   */
  FingerStrokeAssistance_B.parTrajMode =
    FingerStrokeAssistance_P.parTrajMode_Gain *
    FingerStrokeAssistance_P.paremeters_must_be_one_Value;

  /* Rounding: '<S11>/Rounding Function' */
  FingerStrokeAssistance_B.RoundingFunction = rt_roundd_snf
    (FingerStrokeAssistance_B.parTrajMode);

  /* Saturate: '<S11>/Saturation1' */
  state = FingerStrokeAssistance_B.RoundingFunction;
  u1 = FingerStrokeAssistance_P.Saturation1_LowerSat;
  u2 = FingerStrokeAssistance_P.Saturation1_UpperSat;
  if (state > u2) {
    FingerStrokeAssistance_B.Saturation1 = u2;
  } else if (state < u1) {
    FingerStrokeAssistance_B.Saturation1 = u1;
  } else {
    FingerStrokeAssistance_B.Saturation1 = state;
  }

  /* End of Saturate: '<S11>/Saturation1' */

  /* Gain: '<S11>/parFixedDur' incorporates:
   *  Constant: '<S11>/paremeters_ must_be_one'
   */
  FingerStrokeAssistance_B.parFixedDur =
    FingerStrokeAssistance_P.parFixedDur_Gain *
    FingerStrokeAssistance_P.paremeters_must_be_one_Value;

  /* Saturate: '<S11>/Saturation2' */
  state = FingerStrokeAssistance_B.parFixedDur;
  u1 = FingerStrokeAssistance_P.Saturation2_LowerSat;
  u2 = FingerStrokeAssistance_P.Saturation2_UpperSat;
  if (state > u2) {
    FingerStrokeAssistance_B.Saturation2 = u2;
  } else if (state < u1) {
    FingerStrokeAssistance_B.Saturation2 = u1;
  } else {
    FingerStrokeAssistance_B.Saturation2 = state;
  }

  /* End of Saturate: '<S11>/Saturation2' */

  /* Memory: '<S42>/Memory' */
  FingerStrokeAssistance_B.Memory_g[0] =
    FingerStrokeAssistance_DW.Memory_PreviousInput_k[0];
  FingerStrokeAssistance_B.Memory_g[1] =
    FingerStrokeAssistance_DW.Memory_PreviousInput_k[1];
  FingerStrokeAssistance_B.Memory_g[2] =
    FingerStrokeAssistance_DW.Memory_PreviousInput_k[2];
  FingerStrokeAssistance_B.Memory_g[3] =
    FingerStrokeAssistance_DW.Memory_PreviousInput_k[3];

  /* Gain: '<S11>/parChangeRate' incorporates:
   *  Constant: '<S11>/paremeters_ must_be_one'
   */
  FingerStrokeAssistance_B.parChangeRate =
    FingerStrokeAssistance_P.parChangeRate_Gain *
    FingerStrokeAssistance_P.paremeters_must_be_one_Value;

  /* Gain: '<S11>/parKp1' incorporates:
   *  Constant: '<S11>/paremeters_ must_be_one'
   */
  FingerStrokeAssistance_B.parKp1 = FingerStrokeAssistance_P.parKp1_Gain *
    FingerStrokeAssistance_P.paremeters_must_be_one_Value;

  /* MATLAB Function: '<S42>/gainramp' */
  FingerStrokeAssistance_gainramp(FingerStrokeAssistance_B.parChangeRate,
    FingerStrokeAssistance_B.parKp1, FingerStrokeAssistance_B.Memory_g,
    &FingerStrokeAssistance_B.sf_gainramp);

  /* Memory: '<S43>/Memory' */
  FingerStrokeAssistance_B.Memory_i[0] =
    FingerStrokeAssistance_DW.Memory_PreviousInput_n[0];
  FingerStrokeAssistance_B.Memory_i[1] =
    FingerStrokeAssistance_DW.Memory_PreviousInput_n[1];
  FingerStrokeAssistance_B.Memory_i[2] =
    FingerStrokeAssistance_DW.Memory_PreviousInput_n[2];
  FingerStrokeAssistance_B.Memory_i[3] =
    FingerStrokeAssistance_DW.Memory_PreviousInput_n[3];

  /* Gain: '<S11>/parKp2' incorporates:
   *  Constant: '<S11>/paremeters_ must_be_one'
   */
  FingerStrokeAssistance_B.parKp2 = FingerStrokeAssistance_P.parKp2_Gain *
    FingerStrokeAssistance_P.paremeters_must_be_one_Value;

  /* MATLAB Function: '<S43>/gainramp' */
  FingerStrokeAssistance_gainramp(FingerStrokeAssistance_B.parChangeRate,
    FingerStrokeAssistance_B.parKp2, FingerStrokeAssistance_B.Memory_i,
    &FingerStrokeAssistance_B.sf_gainramp_i);

  /* Memory: '<S44>/Memory' */
  FingerStrokeAssistance_B.Memory_e[0] =
    FingerStrokeAssistance_DW.Memory_PreviousInput_b[0];
  FingerStrokeAssistance_B.Memory_e[1] =
    FingerStrokeAssistance_DW.Memory_PreviousInput_b[1];
  FingerStrokeAssistance_B.Memory_e[2] =
    FingerStrokeAssistance_DW.Memory_PreviousInput_b[2];
  FingerStrokeAssistance_B.Memory_e[3] =
    FingerStrokeAssistance_DW.Memory_PreviousInput_b[3];

  /* Gain: '<S11>/parKd1' incorporates:
   *  Constant: '<S11>/paremeters_ must_be_one'
   */
  FingerStrokeAssistance_B.parKd1 = FingerStrokeAssistance_P.parKd1_Gain *
    FingerStrokeAssistance_P.paremeters_must_be_one_Value;

  /* MATLAB Function: '<S44>/gainramp' */
  FingerStrokeAssistance_gainramp(FingerStrokeAssistance_B.parChangeRate,
    FingerStrokeAssistance_B.parKd1, FingerStrokeAssistance_B.Memory_e,
    &FingerStrokeAssistance_B.sf_gainramp_id);

  /* Memory: '<S45>/Memory' */
  FingerStrokeAssistance_B.Memory_o[0] =
    FingerStrokeAssistance_DW.Memory_PreviousInput_j[0];
  FingerStrokeAssistance_B.Memory_o[1] =
    FingerStrokeAssistance_DW.Memory_PreviousInput_j[1];
  FingerStrokeAssistance_B.Memory_o[2] =
    FingerStrokeAssistance_DW.Memory_PreviousInput_j[2];
  FingerStrokeAssistance_B.Memory_o[3] =
    FingerStrokeAssistance_DW.Memory_PreviousInput_j[3];

  /* Gain: '<S11>/parKd2' incorporates:
   *  Constant: '<S11>/paremeters_ must_be_one'
   */
  FingerStrokeAssistance_B.parKd2 = FingerStrokeAssistance_P.parKd2_Gain *
    FingerStrokeAssistance_P.paremeters_must_be_one_Value;

  /* MATLAB Function: '<S45>/gainramp' */
  FingerStrokeAssistance_gainramp(FingerStrokeAssistance_B.parChangeRate,
    FingerStrokeAssistance_B.parKd2, FingerStrokeAssistance_B.Memory_o,
    &FingerStrokeAssistance_B.sf_gainramp_b);

  /* Memory: '<S46>/Memory' */
  FingerStrokeAssistance_B.Memory_n[0] =
    FingerStrokeAssistance_DW.Memory_PreviousInput_i[0];
  FingerStrokeAssistance_B.Memory_n[1] =
    FingerStrokeAssistance_DW.Memory_PreviousInput_i[1];
  FingerStrokeAssistance_B.Memory_n[2] =
    FingerStrokeAssistance_DW.Memory_PreviousInput_i[2];
  FingerStrokeAssistance_B.Memory_n[3] =
    FingerStrokeAssistance_DW.Memory_PreviousInput_i[3];

  /* Gain: '<S11>/parKdV1' incorporates:
   *  Constant: '<S11>/paremeters_ must_be_one'
   */
  FingerStrokeAssistance_B.parKdV1 = FingerStrokeAssistance_P.parKdV1_Gain *
    FingerStrokeAssistance_P.paremeters_must_be_one_Value;

  /* MATLAB Function: '<S46>/gainramp' */
  FingerStrokeAssistance_gainramp(FingerStrokeAssistance_B.parChangeRate,
    FingerStrokeAssistance_B.parKdV1, FingerStrokeAssistance_B.Memory_n,
    &FingerStrokeAssistance_B.sf_gainramp_f);

  /* Memory: '<S47>/Memory' */
  FingerStrokeAssistance_B.Memory_os[0] =
    FingerStrokeAssistance_DW.Memory_PreviousInput_c[0];
  FingerStrokeAssistance_B.Memory_os[1] =
    FingerStrokeAssistance_DW.Memory_PreviousInput_c[1];
  FingerStrokeAssistance_B.Memory_os[2] =
    FingerStrokeAssistance_DW.Memory_PreviousInput_c[2];
  FingerStrokeAssistance_B.Memory_os[3] =
    FingerStrokeAssistance_DW.Memory_PreviousInput_c[3];

  /* Gain: '<S11>/parKdV2' incorporates:
   *  Constant: '<S11>/paremeters_ must_be_one'
   */
  FingerStrokeAssistance_B.parKdV2 = FingerStrokeAssistance_P.parKdV2_Gain *
    FingerStrokeAssistance_P.paremeters_must_be_one_Value;

  /* MATLAB Function: '<S47>/gainramp' */
  FingerStrokeAssistance_gainramp(FingerStrokeAssistance_B.parChangeRate,
    FingerStrokeAssistance_B.parKdV2, FingerStrokeAssistance_B.Memory_os,
    &FingerStrokeAssistance_B.sf_gainramp_a);

  /* Gain: '<S11>/parFThresh' incorporates:
   *  Constant: '<S11>/paremeters_ must_be_one'
   */
  FingerStrokeAssistance_B.parFThresh = FingerStrokeAssistance_P.parFThresh_Gain
    * FingerStrokeAssistance_P.paremeters_must_be_one_Value;

  /* Gain: '<S11>/parForceTrigger' incorporates:
   *  Constant: '<S11>/paremeters_ must_be_one'
   */
  FingerStrokeAssistance_B.parForceTrigger =
    FingerStrokeAssistance_P.parForceTrigger_Gain *
    FingerStrokeAssistance_P.paremeters_must_be_one_Value;

  /* Gain: '<S11>/parMarker' incorporates:
   *  Constant: '<S11>/paremeters_ must_be_one'
   */
  FingerStrokeAssistance_B.parMarker = FingerStrokeAssistance_P.parMarker_Gain *
    FingerStrokeAssistance_P.paremeters_must_be_one_Value;

  /* Gain: '<S11>/parMaxTrajDur' incorporates:
   *  Constant: '<S11>/paremeters_ must_be_one'
   */
  FingerStrokeAssistance_B.parMaxTrajDur =
    FingerStrokeAssistance_P.parMaxTrajDur_Gain *
    FingerStrokeAssistance_P.paremeters_must_be_one_Value;

  /* Gain: '<S11>/parPStop' incorporates:
   *  Constant: '<S11>/paremeters_ must_be_one'
   */
  FingerStrokeAssistance_B.parPStop = FingerStrokeAssistance_P.parPStop_Gain *
    FingerStrokeAssistance_P.paremeters_must_be_one_Value;

  /* Gain: '<S11>/parVThresh' incorporates:
   *  Constant: '<S11>/paremeters_ must_be_one'
   */
  FingerStrokeAssistance_B.parVThresh = FingerStrokeAssistance_P.parVThresh_Gain
    * FingerStrokeAssistance_P.paremeters_must_be_one_Value;

  /* Gain: '<S11>/parWiggleAmp' incorporates:
   *  Constant: '<S11>/paremeters_ must_be_one'
   */
  FingerStrokeAssistance_B.parWiggleAmp =
    FingerStrokeAssistance_P.parWiggleAmp_Gain *
    FingerStrokeAssistance_P.paremeters_must_be_one_Value;

  /* ok to acquire for <S61>/S-Function */
  FingerStrokeAssistance_DW.SFunction_IWORK.AcquireOK = 1;

  /* Gain: '<S12>/Gain2' */
  FingerStrokeAssistance_B.Gain2 = FingerStrokeAssistance_P.Gain2_Gain *
    FingerStrokeAssistance_B.f_ref[0];

  /* ok to acquire for <S58>/S-Function */
  FingerStrokeAssistance_DW.SFunction_IWORK_b.AcquireOK = 1;

  /* Gain: '<S12>/Gain' */
  FingerStrokeAssistance_B.Gain_f[0] = FingerStrokeAssistance_P.Gain_Gain_n *
    FingerStrokeAssistance_B.Switch2_l[0];
  FingerStrokeAssistance_B.Gain_f[1] = FingerStrokeAssistance_P.Gain_Gain_n *
    FingerStrokeAssistance_B.Switch2_l[1];

  /* ok to acquire for <S60>/S-Function */
  FingerStrokeAssistance_DW.SFunction_IWORK_h.AcquireOK = 1;

  /* ok to acquire for <S59>/S-Function */
  FingerStrokeAssistance_DW.SFunction_IWORK_l.AcquireOK = 1;
}

/* Model update function */
static void FingerStrokeAssistance_update(void)
{
  real_T xnew;
  real_T xnew_0;
  real_T xnew_idx_0;

  /* Update for Delay: '<S1>/Delay' */
  FingerStrokeAssistance_DW.Delay_DSTATE[0] = FingerStrokeAssistance_B.Switch2[0];
  FingerStrokeAssistance_DW.Delay_DSTATE[1] = FingerStrokeAssistance_B.Switch2[1];

  /* Update for DiscreteFilter: '<S1>/Discrete Filter1' */
  FingerStrokeAssistance_DW.DiscreteFilter1_states =
    FingerStrokeAssistance_DW.DiscreteFilter1_tmp;

  /* Update for Delay: '<S1>/Delay1' */
  FingerStrokeAssistance_DW.Delay1_DSTATE = FingerStrokeAssistance_B.state;

  /* Update for UnitDelay: '<S13>/Delay Input1' */
  FingerStrokeAssistance_DW.DelayInput1_DSTATE = FingerStrokeAssistance_B.Delay1;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  FingerStrokeAssistance_DW.DiscreteTimeIntegrator_DSTATE +=
    FingerStrokeAssistance_P.DiscreteTimeIntegrator_gainval *
    FingerStrokeAssistance_B.Damping;
  if (FingerStrokeAssistance_DW.DiscreteTimeIntegrator_DSTATE >=
      FingerStrokeAssistance_P.DiscreteTimeIntegrator_UpperSat) {
    FingerStrokeAssistance_DW.DiscreteTimeIntegrator_DSTATE =
      FingerStrokeAssistance_P.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (FingerStrokeAssistance_DW.DiscreteTimeIntegrator_DSTATE <=
        FingerStrokeAssistance_P.DiscreteTimeIntegrator_LowerSat) {
      FingerStrokeAssistance_DW.DiscreteTimeIntegrator_DSTATE =
        FingerStrokeAssistance_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  if (FingerStrokeAssistance_B.DataTypeConversion_p > 0.0) {
    FingerStrokeAssistance_DW.DiscreteTimeIntegrator_PrevRese = 1;
  } else if (FingerStrokeAssistance_B.DataTypeConversion_p < 0.0) {
    FingerStrokeAssistance_DW.DiscreteTimeIntegrator_PrevRese = -1;
  } else if (FingerStrokeAssistance_B.DataTypeConversion_p == 0.0) {
    FingerStrokeAssistance_DW.DiscreteTimeIntegrator_PrevRese = 0;
  } else {
    FingerStrokeAssistance_DW.DiscreteTimeIntegrator_PrevRese = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<Root>/Unit Delay' */
  FingerStrokeAssistance_DW.UnitDelay_DSTATE = FingerStrokeAssistance_B.state;

  /* Update for UnitDelay: '<S8>/Unit Delay2' */
  FingerStrokeAssistance_DW.UnitDelay2_DSTATE = FingerStrokeAssistance_B.state;

  /* Update for UnitDelay: '<S40>/Delay Input1' */
  FingerStrokeAssistance_DW.DelayInput1_DSTATE_l =
    FingerStrokeAssistance_B.UnitDelay2;

  /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
  FingerStrokeAssistance_DW.DiscreteTimeIntegrator_DSTATE_i +=
    FingerStrokeAssistance_P.DiscreteTimeIntegrator_gainva_n *
    FingerStrokeAssistance_B.UnitDelay1_g;
  if (FingerStrokeAssistance_B.DataTypeConversion_o > 0.0) {
    FingerStrokeAssistance_DW.DiscreteTimeIntegrator_PrevRe_i = 1;
  } else if (FingerStrokeAssistance_B.DataTypeConversion_o < 0.0) {
    FingerStrokeAssistance_DW.DiscreteTimeIntegrator_PrevRe_i = -1;
  } else if (FingerStrokeAssistance_B.DataTypeConversion_o == 0.0) {
    FingerStrokeAssistance_DW.DiscreteTimeIntegrator_PrevRe_i = 0;
  } else {
    FingerStrokeAssistance_DW.DiscreteTimeIntegrator_PrevRe_i = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<Root>/Unit Delay2' */
  FingerStrokeAssistance_DW.UnitDelay2_DSTATE_f[0] =
    FingerStrokeAssistance_B.Gain_d;
  FingerStrokeAssistance_DW.UnitDelay2_DSTATE_f[1] =
    FingerStrokeAssistance_B.Switch2[0];

  /* Update for UnitDelay: '<S9>/Unit Delay2' */
  FingerStrokeAssistance_DW.UnitDelay2_DSTATE_h = FingerStrokeAssistance_B.state;

  /* Update for UnitDelay: '<S41>/Delay Input1' */
  FingerStrokeAssistance_DW.DelayInput1_DSTATE_j =
    FingerStrokeAssistance_B.UnitDelay2_j;

  /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
  FingerStrokeAssistance_DW.DiscreteTimeIntegrator_DSTATE_o +=
    FingerStrokeAssistance_P.DiscreteTimeIntegrator_gainva_b *
    FingerStrokeAssistance_B.UnitDelay1_d;
  if (FingerStrokeAssistance_B.DataTypeConversion_a > 0.0) {
    FingerStrokeAssistance_DW.DiscreteTimeIntegrator_PrevRe_p = 1;
  } else if (FingerStrokeAssistance_B.DataTypeConversion_a < 0.0) {
    FingerStrokeAssistance_DW.DiscreteTimeIntegrator_PrevRe_p = -1;
  } else if (FingerStrokeAssistance_B.DataTypeConversion_a == 0.0) {
    FingerStrokeAssistance_DW.DiscreteTimeIntegrator_PrevRe_p = 0;
  } else {
    FingerStrokeAssistance_DW.DiscreteTimeIntegrator_PrevRe_p = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<Root>/Unit Delay1' */
  FingerStrokeAssistance_DW.UnitDelay1_DSTATE =
    FingerStrokeAssistance_B.DiscreteTimeIntegrator;

  /* Update for UnitDelay: '<S7>/Unit Delay1' */
  FingerStrokeAssistance_DW.UnitDelay1_DSTATE_n = FingerStrokeAssistance_B.In1;

  /* Update for UnitDelay: '<Root>/Unit Delay3' */
  FingerStrokeAssistance_DW.UnitDelay3_DSTATE[0] =
    FingerStrokeAssistance_B.Switch2[0];

  /* Update for UnitDelay: '<S7>/Unit Delay' */
  FingerStrokeAssistance_DW.UnitDelay_DSTATE_h[0] =
    FingerStrokeAssistance_B.In1_g[0];

  /* Update for DiscreteIntegrator: '<S14>/Filter' */
  FingerStrokeAssistance_DW.Filter_DSTATE[0] +=
    FingerStrokeAssistance_P.Filter_gainval *
    FingerStrokeAssistance_B.FilterCoefficient[0];

  /* Update for DiscreteIntegrator: '<S14>/Integrator' */
  FingerStrokeAssistance_DW.Integrator_DSTATE[0] +=
    FingerStrokeAssistance_P.Integrator_gainval *
    FingerStrokeAssistance_B.IntegralGain[0];

  /* Update for UnitDelay: '<S17>/UD' */
  FingerStrokeAssistance_DW.UD_DSTATE[0] = FingerStrokeAssistance_B.TSamp[0];

  /* Update for DiscreteFilter: '<S7>/Discrete Filter1' */
  FingerStrokeAssistance_DW.DiscreteFilter1_states_g[0] =
    FingerStrokeAssistance_DW.DiscreteFilter1_tmp_d[0];

  /* Update for UnitDelay: '<Root>/Unit Delay3' */
  FingerStrokeAssistance_DW.UnitDelay3_DSTATE[1] =
    FingerStrokeAssistance_B.Switch2[1];

  /* Update for UnitDelay: '<S7>/Unit Delay' */
  FingerStrokeAssistance_DW.UnitDelay_DSTATE_h[1] =
    FingerStrokeAssistance_B.In1_g[1];

  /* Update for DiscreteIntegrator: '<S14>/Filter' */
  FingerStrokeAssistance_DW.Filter_DSTATE[1] +=
    FingerStrokeAssistance_P.Filter_gainval *
    FingerStrokeAssistance_B.FilterCoefficient[1];

  /* Update for DiscreteIntegrator: '<S14>/Integrator' */
  FingerStrokeAssistance_DW.Integrator_DSTATE[1] +=
    FingerStrokeAssistance_P.Integrator_gainval *
    FingerStrokeAssistance_B.IntegralGain[1];

  /* Update for UnitDelay: '<S17>/UD' */
  FingerStrokeAssistance_DW.UD_DSTATE[1] = FingerStrokeAssistance_B.TSamp[1];

  /* Update for DiscreteFilter: '<S7>/Discrete Filter1' */
  FingerStrokeAssistance_DW.DiscreteFilter1_states_g[1] =
    FingerStrokeAssistance_DW.DiscreteFilter1_tmp_d[1];

  /* Update for DiscreteStateSpace: '<S34>/Low Pass 100 Hz' */
  xnew_0 = FingerStrokeAssistance_P.Alow[0] *
    FingerStrokeAssistance_DW.LowPass100Hz_DSTATE[0];
  xnew_0 += FingerStrokeAssistance_P.Alow[2] *
    FingerStrokeAssistance_DW.LowPass100Hz_DSTATE[1];
  xnew_idx_0 = xnew_0;
  xnew_idx_0 += FingerStrokeAssistance_P.Blow[0] *
    FingerStrokeAssistance_B.Switch2_l[0];
  xnew_0 = FingerStrokeAssistance_P.Alow[1] *
    FingerStrokeAssistance_DW.LowPass100Hz_DSTATE[0];
  xnew_0 += FingerStrokeAssistance_P.Alow[3] *
    FingerStrokeAssistance_DW.LowPass100Hz_DSTATE[1];
  xnew_0 += FingerStrokeAssistance_P.Blow[1] *
    FingerStrokeAssistance_B.Switch2_l[0];
  FingerStrokeAssistance_DW.LowPass100Hz_DSTATE[0] = xnew_idx_0;

  /* Update for DiscreteStateSpace: '<S34>/Low Pass 100 Hz1' */
  xnew = FingerStrokeAssistance_P.Alow[0] *
    FingerStrokeAssistance_DW.LowPass100Hz1_DSTATE[0];
  xnew += FingerStrokeAssistance_P.Alow[2] *
    FingerStrokeAssistance_DW.LowPass100Hz1_DSTATE[1];
  xnew_idx_0 = xnew;
  xnew_idx_0 += FingerStrokeAssistance_P.Blow[0] *
    FingerStrokeAssistance_B.Switch2_l[1];

  /* Update for DiscreteStateSpace: '<S34>/Low Pass 100 Hz' */
  FingerStrokeAssistance_DW.LowPass100Hz_DSTATE[1] = xnew_0;

  /* Update for DiscreteStateSpace: '<S34>/Low Pass 100 Hz1' */
  xnew = FingerStrokeAssistance_P.Alow[1] *
    FingerStrokeAssistance_DW.LowPass100Hz1_DSTATE[0];
  xnew += FingerStrokeAssistance_P.Alow[3] *
    FingerStrokeAssistance_DW.LowPass100Hz1_DSTATE[1];
  xnew += FingerStrokeAssistance_P.Blow[1] * FingerStrokeAssistance_B.Switch2_l
    [1];
  FingerStrokeAssistance_DW.LowPass100Hz1_DSTATE[0] = xnew_idx_0;
  FingerStrokeAssistance_DW.LowPass100Hz1_DSTATE[1] = xnew;

  /* Update for Memory: '<S34>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput =
    FingerStrokeAssistance_B.LowPass100Hz;

  /* Update for Memory: '<S34>/Memory1' */
  FingerStrokeAssistance_DW.Memory1_PreviousInput =
    FingerStrokeAssistance_B.LowPass100Hz1;

  /* Update for UnitDelay: '<S8>/Unit Delay1' */
  FingerStrokeAssistance_DW.UnitDelay1_DSTATE_l =
    FingerStrokeAssistance_B.ramp_switch;

  /* Update for UnitDelay: '<S9>/Unit Delay1' */
  FingerStrokeAssistance_DW.UnitDelay1_DSTATE_i =
    FingerStrokeAssistance_B.fp_ramp_switch;

  /* Update for Memory: '<S42>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_k[0] =
    FingerStrokeAssistance_B.sf_gainramp.state1[0];

  /* Update for Memory: '<S43>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_n[0] =
    FingerStrokeAssistance_B.sf_gainramp_i.state1[0];

  /* Update for Memory: '<S44>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_b[0] =
    FingerStrokeAssistance_B.sf_gainramp_id.state1[0];

  /* Update for Memory: '<S45>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_j[0] =
    FingerStrokeAssistance_B.sf_gainramp_b.state1[0];

  /* Update for Memory: '<S46>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_i[0] =
    FingerStrokeAssistance_B.sf_gainramp_f.state1[0];

  /* Update for Memory: '<S47>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_c[0] =
    FingerStrokeAssistance_B.sf_gainramp_a.state1[0];

  /* Update for Memory: '<S42>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_k[1] =
    FingerStrokeAssistance_B.sf_gainramp.state1[1];

  /* Update for Memory: '<S43>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_n[1] =
    FingerStrokeAssistance_B.sf_gainramp_i.state1[1];

  /* Update for Memory: '<S44>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_b[1] =
    FingerStrokeAssistance_B.sf_gainramp_id.state1[1];

  /* Update for Memory: '<S45>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_j[1] =
    FingerStrokeAssistance_B.sf_gainramp_b.state1[1];

  /* Update for Memory: '<S46>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_i[1] =
    FingerStrokeAssistance_B.sf_gainramp_f.state1[1];

  /* Update for Memory: '<S47>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_c[1] =
    FingerStrokeAssistance_B.sf_gainramp_a.state1[1];

  /* Update for Memory: '<S42>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_k[2] =
    FingerStrokeAssistance_B.sf_gainramp.state1[2];

  /* Update for Memory: '<S43>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_n[2] =
    FingerStrokeAssistance_B.sf_gainramp_i.state1[2];

  /* Update for Memory: '<S44>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_b[2] =
    FingerStrokeAssistance_B.sf_gainramp_id.state1[2];

  /* Update for Memory: '<S45>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_j[2] =
    FingerStrokeAssistance_B.sf_gainramp_b.state1[2];

  /* Update for Memory: '<S46>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_i[2] =
    FingerStrokeAssistance_B.sf_gainramp_f.state1[2];

  /* Update for Memory: '<S47>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_c[2] =
    FingerStrokeAssistance_B.sf_gainramp_a.state1[2];

  /* Update for Memory: '<S42>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_k[3] =
    FingerStrokeAssistance_B.sf_gainramp.state1[3];

  /* Update for Memory: '<S43>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_n[3] =
    FingerStrokeAssistance_B.sf_gainramp_i.state1[3];

  /* Update for Memory: '<S44>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_b[3] =
    FingerStrokeAssistance_B.sf_gainramp_id.state1[3];

  /* Update for Memory: '<S45>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_j[3] =
    FingerStrokeAssistance_B.sf_gainramp_b.state1[3];

  /* Update for Memory: '<S46>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_i[3] =
    FingerStrokeAssistance_B.sf_gainramp_f.state1[3];

  /* Update for Memory: '<S47>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_c[3] =
    FingerStrokeAssistance_B.sf_gainramp_a.state1[3];

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++FingerStrokeAssistance_M->Timing.clockTick0)) {
    ++FingerStrokeAssistance_M->Timing.clockTickH0;
  }

  FingerStrokeAssistance_M->Timing.t[0] =
    FingerStrokeAssistance_M->Timing.clockTick0 *
    FingerStrokeAssistance_M->Timing.stepSize0 +
    FingerStrokeAssistance_M->Timing.clockTickH0 *
    FingerStrokeAssistance_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void FingerStrokeAssistance_initialize(void)
{
  /* Level2 S-Function Block: '<S7>/PCI-6221 AD1' (adnipcim) */
  {
    SimStruct *rts = FingerStrokeAssistance_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S7>/PCI 6221 ENC ' (encnipcim) */
  {
    SimStruct *rts = FingerStrokeAssistance_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S7>/PCI 6221 ENC 1' (encnipcim) */
  {
    SimStruct *rts = FingerStrokeAssistance_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S7>/PCI-6221 DA' (danipcim) */
  {
    SimStruct *rts = FingerStrokeAssistance_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* S-Function Block: <S61>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(3)) == 0) {
      if ((i = rl32eDefScope(3,2)) != 0) {
        printf("Error creating scope 3\n");
      } else {
        rl32eAddSignal(3, rl32eGetSignalNo("signals/Gain2"));
        rl32eAddSignal(3, rl32eGetSignalNo(
          "Robot/account for handedness1/MATLAB Function/p1"));
        rl32eAddSignal(3, rl32eGetSignalNo("Robot/Gain/s1"));
        rl32eAddSignal(3, rl32eGetSignalNo("MATLAB Function/p8/s1"));
        rl32eAddSignal(3, rl32eGetSignalNo("Robot/Sum/s1"));
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("signals/Gain2"),
          "f_ref1:%15.6f N");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo(
          "Robot/account for handedness1/MATLAB Function/p1"),"enc_raw:%15.6f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Robot/Gain/s1"),
          "enc_norm:%15.6f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("MATLAB Function/p8/s1"),
          "pos_ref_1:%15.6f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Robot/Sum/s1"),
          "pos_meas_1:%15.6f");
        rl32eSetScope(3, 4, 10);
        rl32eSetScope(3, 5, 0);
        rl32eSetScope(3, 6, 1);
        rl32eSetScope(3, 0, 0);
        rl32eSetScope(3, 3, rl32eGetSignalNo("signals/Gain2"));
        rl32eSetScope(3, 1, 0.0);
        rl32eSetScope(3, 2, 0);
        rl32eSetScope(3, 9, 0);
        rl32eSetTargetScope(3, 1, 0.0);
        rl32eSetTargetScope(3, 11, 0.03);
        rl32eSetTargetScope(3, 10, 0.1);
        xpceScopeAcqOK(3, &FingerStrokeAssistance_DW.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(3);
    }
  }

  /* S-Function Block: <S58>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,2)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo("MATLAB Function/p1"));
        rl32eAddSignal(1, rl32eGetSignalNo("signals/Gain/s1"));
        rl32eAddSignal(1, rl32eGetSignalNo("signals/Gain/s2"));
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("MATLAB Function/p1"),
          "state:%15.6f");
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("signals/Gain/s1"),
          "f_ref_limited_1:%15.6f");
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("signals/Gain/s2"),
          "f_ref_limited_2:%15.6f");
        rl32eSetScope(1, 4, 10);
        rl32eSetScope(1, 5, 0);
        rl32eSetScope(1, 6, 1);
        rl32eSetScope(1, 0, 0);
        rl32eSetScope(1, 3, rl32eGetSignalNo("MATLAB Function/p1"));
        rl32eSetScope(1, 1, 0.0);
        rl32eSetScope(1, 2, 0);
        rl32eSetScope(1, 9, 0);
        rl32eSetTargetScope(1, 1, 0.0);
        rl32eSetTargetScope(1, 11, -1.0);
        rl32eSetTargetScope(1, 10, 5.0);
        xpceScopeAcqOK(1, &FingerStrokeAssistance_DW.SFunction_IWORK_b.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* S-Function Block: <S60>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(2)) == 0) {
      if ((i = rl32eDefScope(2,2)) != 0) {
        printf("Error creating scope 2\n");
      } else {
        rl32eAddSignal(2, rl32eGetSignalNo("Robot/MATLAB Function"));
        rl32eAddSignal(2, rl32eGetSignalNo("Robot/MATLAB Function1"));
        rl32eAddSignal(2, rl32eGetSignalNo("Robot/PCI-6221 AD1/p12"));
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo("Robot/MATLAB Function"),
          "Raw_GripForce:%15.6f");
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo("Robot/MATLAB Function1"),
          "Raw_Pressure_Value:%15.6f");
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo("Robot/PCI-6221 AD1/p12"),
          "%15.6f");
        rl32eSetScope(2, 4, 10);
        rl32eSetScope(2, 5, 0);
        rl32eSetScope(2, 6, 1);
        rl32eSetScope(2, 0, 0);
        rl32eSetScope(2, 3, rl32eGetSignalNo("Robot/MATLAB Function"));
        rl32eSetScope(2, 1, 0.0);
        rl32eSetScope(2, 2, 0);
        rl32eSetScope(2, 9, 0);
        rl32eSetTargetScope(2, 1, 0.0);
        rl32eSetTargetScope(2, 11, -5.0);
        rl32eSetTargetScope(2, 10, 5.0);
        xpceScopeAcqOK(2, &FingerStrokeAssistance_DW.SFunction_IWORK_h.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* S-Function Block: <S59>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(4)) == 0) {
      if ((i = rl32eDefScope(4,2)) != 0) {
        printf("Error creating scope 4\n");
      } else {
        rl32eAddSignal(4, rl32eGetSignalNo("Robot/MATLAB Function7"));
        rl32eAddSignal(4, rl32eGetSignalNo("Robot/MATLAB Function8"));
        rl32eAddSignal(4, rl32eGetSignalNo("Robot/MATLAB Function6"));
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo("Robot/MATLAB Function7"),
          "Raw_X:%15.6f");
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo("Robot/MATLAB Function8"),
          "Raw_Y:%15.6f");
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo("Robot/MATLAB Function6"),
          "Raw_Z:%15.6f");
        rl32eSetScope(4, 4, 10);
        rl32eSetScope(4, 5, 0);
        rl32eSetScope(4, 6, 1);
        rl32eSetScope(4, 0, 0);
        rl32eSetScope(4, 3, rl32eGetSignalNo("Robot/MATLAB Function7"));
        rl32eSetScope(4, 1, 0.0);
        rl32eSetScope(4, 2, 0);
        rl32eSetScope(4, 9, 0);
        rl32eSetTargetScope(4, 1, 0.0);
        rl32eSetTargetScope(4, 11, -2.5);
        rl32eSetTargetScope(4, 10, 2.5);
        xpceScopeAcqOK(4, &FingerStrokeAssistance_DW.SFunction_IWORK_l.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(4);
    }
  }

  FingerStrokeAssistance_PrevZCX.TriggeredSubsystem_Trig_ZCE =
    UNINITIALIZED_ZCSIG;
  FingerStrokeAssistance_PrevZCX.TriggeredSubsystem1_Trig_ZCE =
    UNINITIALIZED_ZCSIG;

  /* InitializeConditions for DiscreteFilter: '<S1>/Discrete Filter1' */
  FingerStrokeAssistance_DW.DiscreteFilter1_states =
    FingerStrokeAssistance_P.DiscreteFilter1_InitialStates;

  /* InitializeConditions for Delay: '<S1>/Delay1' */
  FingerStrokeAssistance_DW.Delay1_DSTATE =
    FingerStrokeAssistance_P.Delay1_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S13>/Delay Input1' */
  FingerStrokeAssistance_DW.DelayInput1_DSTATE =
    FingerStrokeAssistance_P.DetectChange_vinit;

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  FingerStrokeAssistance_DW.DiscreteTimeIntegrator_DSTATE =
    FingerStrokeAssistance_P.DiscreteTimeIntegrator_IC;
  FingerStrokeAssistance_DW.DiscreteTimeIntegrator_PrevRese = 2;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  FingerStrokeAssistance_DW.UnitDelay_DSTATE =
    FingerStrokeAssistance_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S8>/Unit Delay2' */
  FingerStrokeAssistance_DW.UnitDelay2_DSTATE =
    FingerStrokeAssistance_P.UnitDelay2_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S40>/Delay Input1' */
  FingerStrokeAssistance_DW.DelayInput1_DSTATE_l =
    FingerStrokeAssistance_P.DetectChange_vinit_a;

  /* InitializeConditions for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
  FingerStrokeAssistance_DW.DiscreteTimeIntegrator_DSTATE_i =
    FingerStrokeAssistance_P.DiscreteTimeIntegrator_IC_k;
  FingerStrokeAssistance_DW.DiscreteTimeIntegrator_PrevRe_i = 2;

  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay2' */
  FingerStrokeAssistance_DW.UnitDelay2_DSTATE_h =
    FingerStrokeAssistance_P.UnitDelay2_InitialCondition_f;

  /* InitializeConditions for UnitDelay: '<S41>/Delay Input1' */
  FingerStrokeAssistance_DW.DelayInput1_DSTATE_j =
    FingerStrokeAssistance_P.DetectChange_vinit_d;

  /* InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
  FingerStrokeAssistance_DW.DiscreteTimeIntegrator_DSTATE_o =
    FingerStrokeAssistance_P.DiscreteTimeIntegrator_IC_l;
  FingerStrokeAssistance_DW.DiscreteTimeIntegrator_PrevRe_p = 2;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay1' */
  FingerStrokeAssistance_DW.UnitDelay1_DSTATE =
    FingerStrokeAssistance_P.UnitDelay1_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay1' */
  FingerStrokeAssistance_DW.UnitDelay1_DSTATE_n =
    FingerStrokeAssistance_P.UnitDelay1_InitialCondition_k;

  /* InitializeConditions for Delay: '<S1>/Delay' */
  FingerStrokeAssistance_DW.Delay_DSTATE[0] =
    FingerStrokeAssistance_P.Delay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay3' */
  FingerStrokeAssistance_DW.UnitDelay3_DSTATE[0] =
    FingerStrokeAssistance_P.UnitDelay3_InitialCondition;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay2' */
  FingerStrokeAssistance_DW.UnitDelay2_DSTATE_f[0] =
    FingerStrokeAssistance_P.UnitDelay2_InitialCondition_a;

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay' */
  FingerStrokeAssistance_DW.UnitDelay_DSTATE_h[0] =
    FingerStrokeAssistance_P.UnitDelay_InitialCondition_e;

  /* InitializeConditions for DiscreteIntegrator: '<S14>/Filter' */
  FingerStrokeAssistance_DW.Filter_DSTATE[0] =
    FingerStrokeAssistance_P.Filter_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S14>/Integrator' */
  FingerStrokeAssistance_DW.Integrator_DSTATE[0] =
    FingerStrokeAssistance_P.Integrator_IC;

  /* InitializeConditions for UnitDelay: '<S17>/UD' */
  FingerStrokeAssistance_DW.UD_DSTATE[0] =
    FingerStrokeAssistance_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for DiscreteFilter: '<S7>/Discrete Filter1' */
  FingerStrokeAssistance_DW.DiscreteFilter1_states_g[0] =
    FingerStrokeAssistance_P.DiscreteFilter1_InitialStates_c;

  /* InitializeConditions for DiscreteStateSpace: '<S34>/Low Pass 100 Hz' */
  FingerStrokeAssistance_DW.LowPass100Hz_DSTATE[0] =
    FingerStrokeAssistance_P.x0low[0];

  /* InitializeConditions for DiscreteStateSpace: '<S34>/Low Pass 100 Hz1' */
  FingerStrokeAssistance_DW.LowPass100Hz1_DSTATE[0] =
    FingerStrokeAssistance_P.x0low[0];

  /* InitializeConditions for Delay: '<S1>/Delay' */
  FingerStrokeAssistance_DW.Delay_DSTATE[1] =
    FingerStrokeAssistance_P.Delay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay3' */
  FingerStrokeAssistance_DW.UnitDelay3_DSTATE[1] =
    FingerStrokeAssistance_P.UnitDelay3_InitialCondition;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay2' */
  FingerStrokeAssistance_DW.UnitDelay2_DSTATE_f[1] =
    FingerStrokeAssistance_P.UnitDelay2_InitialCondition_a;

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay' */
  FingerStrokeAssistance_DW.UnitDelay_DSTATE_h[1] =
    FingerStrokeAssistance_P.UnitDelay_InitialCondition_e;

  /* InitializeConditions for DiscreteIntegrator: '<S14>/Filter' */
  FingerStrokeAssistance_DW.Filter_DSTATE[1] =
    FingerStrokeAssistance_P.Filter_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S14>/Integrator' */
  FingerStrokeAssistance_DW.Integrator_DSTATE[1] =
    FingerStrokeAssistance_P.Integrator_IC;

  /* InitializeConditions for UnitDelay: '<S17>/UD' */
  FingerStrokeAssistance_DW.UD_DSTATE[1] =
    FingerStrokeAssistance_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for DiscreteFilter: '<S7>/Discrete Filter1' */
  FingerStrokeAssistance_DW.DiscreteFilter1_states_g[1] =
    FingerStrokeAssistance_P.DiscreteFilter1_InitialStates_c;

  /* InitializeConditions for DiscreteStateSpace: '<S34>/Low Pass 100 Hz' */
  FingerStrokeAssistance_DW.LowPass100Hz_DSTATE[1] =
    FingerStrokeAssistance_P.x0low[1];

  /* InitializeConditions for DiscreteStateSpace: '<S34>/Low Pass 100 Hz1' */
  FingerStrokeAssistance_DW.LowPass100Hz1_DSTATE[1] =
    FingerStrokeAssistance_P.x0low[1];

  /* InitializeConditions for Memory: '<S34>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput =
    FingerStrokeAssistance_P.Memory_X0;

  /* InitializeConditions for Memory: '<S34>/Memory1' */
  FingerStrokeAssistance_DW.Memory1_PreviousInput =
    FingerStrokeAssistance_P.Memory1_X0;

  /* InitializeConditions for UnitDelay: '<S8>/Unit Delay1' */
  FingerStrokeAssistance_DW.UnitDelay1_DSTATE_l =
    FingerStrokeAssistance_P.UnitDelay1_InitialCondition_o;

  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay1' */
  FingerStrokeAssistance_DW.UnitDelay1_DSTATE_i =
    FingerStrokeAssistance_P.UnitDelay1_InitialCondition_oy;

  /* InitializeConditions for Memory: '<S42>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_k[0] =
    FingerStrokeAssistance_P.Memory_X0_g[0];

  /* InitializeConditions for Memory: '<S43>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_n[0] =
    FingerStrokeAssistance_P.Memory_X0_a[0];

  /* InitializeConditions for Memory: '<S44>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_b[0] =
    FingerStrokeAssistance_P.Memory_X0_b[0];

  /* InitializeConditions for Memory: '<S45>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_j[0] =
    FingerStrokeAssistance_P.Memory_X0_g0[0];

  /* InitializeConditions for Memory: '<S46>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_i[0] =
    FingerStrokeAssistance_P.Memory_X0_bp[0];

  /* InitializeConditions for Memory: '<S47>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_c[0] =
    FingerStrokeAssistance_P.Memory_X0_e[0];

  /* InitializeConditions for Memory: '<S42>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_k[1] =
    FingerStrokeAssistance_P.Memory_X0_g[1];

  /* InitializeConditions for Memory: '<S43>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_n[1] =
    FingerStrokeAssistance_P.Memory_X0_a[1];

  /* InitializeConditions for Memory: '<S44>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_b[1] =
    FingerStrokeAssistance_P.Memory_X0_b[1];

  /* InitializeConditions for Memory: '<S45>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_j[1] =
    FingerStrokeAssistance_P.Memory_X0_g0[1];

  /* InitializeConditions for Memory: '<S46>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_i[1] =
    FingerStrokeAssistance_P.Memory_X0_bp[1];

  /* InitializeConditions for Memory: '<S47>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_c[1] =
    FingerStrokeAssistance_P.Memory_X0_e[1];

  /* InitializeConditions for Memory: '<S42>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_k[2] =
    FingerStrokeAssistance_P.Memory_X0_g[2];

  /* InitializeConditions for Memory: '<S43>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_n[2] =
    FingerStrokeAssistance_P.Memory_X0_a[2];

  /* InitializeConditions for Memory: '<S44>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_b[2] =
    FingerStrokeAssistance_P.Memory_X0_b[2];

  /* InitializeConditions for Memory: '<S45>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_j[2] =
    FingerStrokeAssistance_P.Memory_X0_g0[2];

  /* InitializeConditions for Memory: '<S46>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_i[2] =
    FingerStrokeAssistance_P.Memory_X0_bp[2];

  /* InitializeConditions for Memory: '<S47>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_c[2] =
    FingerStrokeAssistance_P.Memory_X0_e[2];

  /* InitializeConditions for Memory: '<S42>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_k[3] =
    FingerStrokeAssistance_P.Memory_X0_g[3];

  /* InitializeConditions for Memory: '<S43>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_n[3] =
    FingerStrokeAssistance_P.Memory_X0_a[3];

  /* InitializeConditions for Memory: '<S44>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_b[3] =
    FingerStrokeAssistance_P.Memory_X0_b[3];

  /* InitializeConditions for Memory: '<S45>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_j[3] =
    FingerStrokeAssistance_P.Memory_X0_g0[3];

  /* InitializeConditions for Memory: '<S46>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_i[3] =
    FingerStrokeAssistance_P.Memory_X0_bp[3];

  /* InitializeConditions for Memory: '<S47>/Memory' */
  FingerStrokeAssistance_DW.Memory_PreviousInput_c[3] =
    FingerStrokeAssistance_P.Memory_X0_e[3];

  /* SystemInitialize for MATLAB Function: '<S7>/MATLAB Function3' */
  FingerStrokeAssistance_DW.bufSum_a = 0.0;
  FingerStrokeAssistance_DW.i_g = 1.0;

  /* SystemInitialize for MATLAB Function: '<S7>/MATLAB Function4' */
  FingerStrokeAssistance_DW.bufSum_l = 0.0;
  FingerStrokeAssistance_DW.i_a = 1.0;

  /* SystemInitialize for MATLAB Function: '<S7>/MATLAB Function2' */
  FingerStrokeAssistance_DW.bufSum_e = 0.0;
  FingerStrokeAssistance_DW.i_o = 1.0;

  /* SystemInitialize for MATLAB Function: '<S7>/MATLAB Function3' */
  memset(&FingerStrokeAssistance_DW.buf_g[0], 0, 50U * sizeof(real_T));

  /* SystemInitialize for MATLAB Function: '<S7>/MATLAB Function4' */
  memset(&FingerStrokeAssistance_DW.buf_e[0], 0, 50U * sizeof(real_T));

  /* SystemInitialize for MATLAB Function: '<S7>/MATLAB Function2' */
  memset(&FingerStrokeAssistance_DW.buf_i[0], 0, 50U * sizeof(real_T));

  /* SystemInitialize for MATLAB Function: '<S7>/MATLAB Function5' */
  memset(&FingerStrokeAssistance_DW.buf[0], 0, 50U * sizeof(real_T));
  FingerStrokeAssistance_DW.bufSum = 0.0;
  FingerStrokeAssistance_DW.i = 1.0;

  /* SystemInitialize for Triggered SubSystem: '<S7>/Triggered Subsystem' */
  /* SystemInitialize for Outport: '<S28>/Out1' */
  FingerStrokeAssistance_B.In1_g[0] = FingerStrokeAssistance_P.Out1_Y0;
  FingerStrokeAssistance_B.In1_g[1] = FingerStrokeAssistance_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S7>/Triggered Subsystem' */

  /* SystemInitialize for Triggered SubSystem: '<S7>/Triggered Subsystem1' */
  /* SystemInitialize for Outport: '<S29>/Out1' */
  FingerStrokeAssistance_B.In1 = FingerStrokeAssistance_P.Out1_Y0_o;

  /* End of SystemInitialize for SubSystem: '<S7>/Triggered Subsystem1' */
}

/* Model terminate function */
static void FingerStrokeAssistance_terminate(void)
{
  /* Level2 S-Function Block: '<S7>/PCI-6221 AD1' (adnipcim) */
  {
    SimStruct *rts = FingerStrokeAssistance_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S7>/PCI 6221 ENC ' (encnipcim) */
  {
    SimStruct *rts = FingerStrokeAssistance_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S7>/PCI 6221 ENC 1' (encnipcim) */
  {
    SimStruct *rts = FingerStrokeAssistance_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S7>/PCI-6221 DA' (danipcim) */
  {
    SimStruct *rts = FingerStrokeAssistance_M->childSfunctions[3];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  FingerStrokeAssistance_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  FingerStrokeAssistance_update();
  UNUSED_PARAMETER(tid);
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
  FingerStrokeAssistance_initialize();
}

void MdlTerminate(void)
{
  FingerStrokeAssistance_terminate();
}

/* Registration function */
RT_MODEL_FingerStrokeAssistance_T *FingerStrokeAssistance(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)FingerStrokeAssistance_M, 0,
                sizeof(RT_MODEL_FingerStrokeAssistance_T));
  rtsiSetSolverName(&FingerStrokeAssistance_M->solverInfo,"FixedStepDiscrete");
  FingerStrokeAssistance_M->solverInfoPtr =
    (&FingerStrokeAssistance_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = FingerStrokeAssistance_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    FingerStrokeAssistance_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    FingerStrokeAssistance_M->Timing.sampleTimes =
      (&FingerStrokeAssistance_M->Timing.sampleTimesArray[0]);
    FingerStrokeAssistance_M->Timing.offsetTimes =
      (&FingerStrokeAssistance_M->Timing.offsetTimesArray[0]);

    /* task periods */
    FingerStrokeAssistance_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    FingerStrokeAssistance_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(FingerStrokeAssistance_M, &FingerStrokeAssistance_M->Timing.tArray
             [0]);

  {
    int_T *mdlSampleHits = FingerStrokeAssistance_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    FingerStrokeAssistance_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(FingerStrokeAssistance_M, -1);
  FingerStrokeAssistance_M->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    FingerStrokeAssistance_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(FingerStrokeAssistance_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(FingerStrokeAssistance_M->rtwLogInfo, (NULL));
    rtliSetLogT(FingerStrokeAssistance_M->rtwLogInfo, "tout");
    rtliSetLogX(FingerStrokeAssistance_M->rtwLogInfo, "");
    rtliSetLogXFinal(FingerStrokeAssistance_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(FingerStrokeAssistance_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(FingerStrokeAssistance_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(FingerStrokeAssistance_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(FingerStrokeAssistance_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &FingerStrokeAssistance_Y.Out1[0]
      };

      rtliSetLogYSignalPtrs(FingerStrokeAssistance_M->rtwLogInfo,
                            ((LogSignalPtrsType)rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        5
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        5
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "FingerStrokeAssistance/Out1" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          1,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(FingerStrokeAssistance_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
    }

    rtliSetLogY(FingerStrokeAssistance_M->rtwLogInfo, "yout");
  }

  FingerStrokeAssistance_M->solverInfoPtr =
    (&FingerStrokeAssistance_M->solverInfo);
  FingerStrokeAssistance_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&FingerStrokeAssistance_M->solverInfo, 0.001);
  rtsiSetSolverMode(&FingerStrokeAssistance_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  FingerStrokeAssistance_M->ModelData.blockIO = ((void *)
    &FingerStrokeAssistance_B);
  (void) memset(((void *) &FingerStrokeAssistance_B), 0,
                sizeof(B_FingerStrokeAssistance_T));

  /* parameters */
  FingerStrokeAssistance_M->ModelData.defaultParam = ((real_T *)
    &FingerStrokeAssistance_P);

  /* states (dwork) */
  FingerStrokeAssistance_M->ModelData.dwork = ((void *)
    &FingerStrokeAssistance_DW);
  (void) memset((void *)&FingerStrokeAssistance_DW, 0,
                sizeof(DW_FingerStrokeAssistance_T));

  /* external outputs */
  FingerStrokeAssistance_M->ModelData.outputs = (&FingerStrokeAssistance_Y);
  (void) memset(&FingerStrokeAssistance_Y.Out1[0], 0,
                5U*sizeof(real_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  FingerStrokeAssistance_InitializeDataMapInfo(FingerStrokeAssistance_M);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &FingerStrokeAssistance_M->NonInlinedSFcns.sfcnInfo;
    FingerStrokeAssistance_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(FingerStrokeAssistance_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &FingerStrokeAssistance_M->Sizes.numSampTimes);
    FingerStrokeAssistance_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (FingerStrokeAssistance_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,
                   FingerStrokeAssistance_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(FingerStrokeAssistance_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(FingerStrokeAssistance_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (FingerStrokeAssistance_M));
    rtssSetStepSizePtr(sfcnInfo, &FingerStrokeAssistance_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (FingerStrokeAssistance_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &FingerStrokeAssistance_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &FingerStrokeAssistance_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &FingerStrokeAssistance_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &FingerStrokeAssistance_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &FingerStrokeAssistance_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &FingerStrokeAssistance_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &FingerStrokeAssistance_M->solverInfoPtr);
  }

  FingerStrokeAssistance_M->Sizes.numSFcns = (4);

  /* register each child */
  {
    (void) memset((void *)
                  &FingerStrokeAssistance_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  4*sizeof(SimStruct));
    FingerStrokeAssistance_M->childSfunctions =
      (&FingerStrokeAssistance_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    FingerStrokeAssistance_M->childSfunctions[0] =
      (&FingerStrokeAssistance_M->NonInlinedSFcns.childSFunctions[0]);
    FingerStrokeAssistance_M->childSfunctions[1] =
      (&FingerStrokeAssistance_M->NonInlinedSFcns.childSFunctions[1]);
    FingerStrokeAssistance_M->childSfunctions[2] =
      (&FingerStrokeAssistance_M->NonInlinedSFcns.childSFunctions[2]);
    FingerStrokeAssistance_M->childSfunctions[3] =
      (&FingerStrokeAssistance_M->NonInlinedSFcns.childSFunctions[3]);

    /* Level2 S-Function Block: FingerStrokeAssistance/<S7>/PCI-6221 AD1 (adnipcim) */
    {
      SimStruct *rts = FingerStrokeAssistance_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &FingerStrokeAssistance_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, FingerStrokeAssistance_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &FingerStrokeAssistance_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &FingerStrokeAssistance_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &FingerStrokeAssistance_M->NonInlinedSFcns.statesInfo2
                         [0]);
        ssSetPeriodicStatesInfo(rts,
          &FingerStrokeAssistance_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 12);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &FingerStrokeAssistance_B.PCI6221AD1_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &FingerStrokeAssistance_B.PCI6221AD1_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &FingerStrokeAssistance_B.PCI6221AD1_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            &FingerStrokeAssistance_B.PCI6221AD1_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *)
            &FingerStrokeAssistance_B.PCI6221AD1_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *)
            &FingerStrokeAssistance_B.PCI6221AD1_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *)
            &FingerStrokeAssistance_B.PCI6221AD1_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *)
            &FingerStrokeAssistance_B.PCI6221AD1_o8));
        }

        /* port 8 */
        {
          _ssSetOutputPortNumDimensions(rts, 8, 1);
          ssSetOutputPortWidth(rts, 8, 1);
          ssSetOutputPortSignal(rts, 8, ((real_T *)
            &FingerStrokeAssistance_B.PCI6221AD1_o9));
        }

        /* port 9 */
        {
          _ssSetOutputPortNumDimensions(rts, 9, 1);
          ssSetOutputPortWidth(rts, 9, 1);
          ssSetOutputPortSignal(rts, 9, ((real_T *)
            &FingerStrokeAssistance_B.PCI6221AD1_o10));
        }

        /* port 10 */
        {
          _ssSetOutputPortNumDimensions(rts, 10, 1);
          ssSetOutputPortWidth(rts, 10, 1);
          ssSetOutputPortSignal(rts, 10, ((real_T *)
            &FingerStrokeAssistance_B.PCI6221AD1_o11));
        }

        /* port 11 */
        {
          _ssSetOutputPortNumDimensions(rts, 11, 1);
          ssSetOutputPortWidth(rts, 11, 1);
          ssSetOutputPortSignal(rts, 11, ((real_T *)
            &FingerStrokeAssistance_B.PCI6221AD1_o12));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6221 AD1");
      ssSetPath(rts, "FingerStrokeAssistance/Robot/PCI-6221 AD1");
      ssSetRTModel(rts,FingerStrokeAssistance_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221AD1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221AD1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221AD1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221AD1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221AD1_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221AD1_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221AD1_P7_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &FingerStrokeAssistance_DW.PCI6221AD1_IWORK[0]);
      ssSetPWork(rts, (void **) &FingerStrokeAssistance_DW.PCI6221AD1_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 41);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &FingerStrokeAssistance_DW.PCI6221AD1_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &FingerStrokeAssistance_DW.PCI6221AD1_PWORK);
      }

      /* registration */
      adnipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 0);
      _ssSetOutputPortConnected(rts, 4, 0);
      _ssSetOutputPortConnected(rts, 5, 0);
      _ssSetOutputPortConnected(rts, 6, 0);
      _ssSetOutputPortConnected(rts, 7, 0);
      _ssSetOutputPortConnected(rts, 8, 1);
      _ssSetOutputPortConnected(rts, 9, 1);
      _ssSetOutputPortConnected(rts, 10, 1);
      _ssSetOutputPortConnected(rts, 11, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);
      _ssSetOutputPortBeingMerged(rts, 7, 0);
      _ssSetOutputPortBeingMerged(rts, 8, 0);
      _ssSetOutputPortBeingMerged(rts, 9, 0);
      _ssSetOutputPortBeingMerged(rts, 10, 0);
      _ssSetOutputPortBeingMerged(rts, 11, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: FingerStrokeAssistance/<S7>/PCI 6221 ENC  (encnipcim) */
    {
      SimStruct *rts = FingerStrokeAssistance_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap =
        FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &FingerStrokeAssistance_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, FingerStrokeAssistance_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &FingerStrokeAssistance_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &FingerStrokeAssistance_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &FingerStrokeAssistance_M->NonInlinedSFcns.statesInfo2
                         [1]);
        ssSetPeriodicStatesInfo(rts,
          &FingerStrokeAssistance_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &FingerStrokeAssistance_B.PCI6221ENC));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI 6221 ENC ");
      ssSetPath(rts, "FingerStrokeAssistance/Robot/PCI 6221 ENC ");
      ssSetRTModel(rts,FingerStrokeAssistance_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221ENC_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221ENC_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221ENC_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221ENC_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221ENC_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221ENC_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221ENC_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221ENC_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221ENC_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221ENC_P10_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &FingerStrokeAssistance_DW.PCI6221ENC_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &FingerStrokeAssistance_DW.PCI6221ENC_PWORK);
      }

      /* registration */
      encnipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: FingerStrokeAssistance/<S7>/PCI 6221 ENC 1 (encnipcim) */
    {
      SimStruct *rts = FingerStrokeAssistance_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod =
        FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset =
        FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap =
        FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &FingerStrokeAssistance_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, FingerStrokeAssistance_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &FingerStrokeAssistance_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &FingerStrokeAssistance_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &FingerStrokeAssistance_M->NonInlinedSFcns.statesInfo2
                         [2]);
        ssSetPeriodicStatesInfo(rts,
          &FingerStrokeAssistance_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &FingerStrokeAssistance_B.PCI6221ENC1));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI 6221 ENC 1");
      ssSetPath(rts, "FingerStrokeAssistance/Robot/PCI 6221 ENC 1");
      ssSetRTModel(rts,FingerStrokeAssistance_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221ENC1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221ENC1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221ENC1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221ENC1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221ENC1_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221ENC1_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221ENC1_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221ENC1_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221ENC1_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221ENC1_P10_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &FingerStrokeAssistance_DW.PCI6221ENC1_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &FingerStrokeAssistance_DW.PCI6221ENC1_PWORK);
      }

      /* registration */
      encnipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: FingerStrokeAssistance/<S7>/PCI-6221 DA (danipcim) */
    {
      SimStruct *rts = FingerStrokeAssistance_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod =
        FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset =
        FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap =
        FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &FingerStrokeAssistance_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, FingerStrokeAssistance_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &FingerStrokeAssistance_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &FingerStrokeAssistance_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &FingerStrokeAssistance_M->NonInlinedSFcns.statesInfo2
                         [3]);
        ssSetPeriodicStatesInfo(rts,
          &FingerStrokeAssistance_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &FingerStrokeAssistance_B.sf_MATLABFunction_m.output1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn3.UPtrs1;
          sfcnUPtrs[0] = &FingerStrokeAssistance_B.sf_MATLABFunction_m.output2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6221 DA");
      ssSetPath(rts, "FingerStrokeAssistance/Robot/PCI-6221 DA");
      ssSetRTModel(rts,FingerStrokeAssistance_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221DA_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221DA_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221DA_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221DA_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221DA_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221DA_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       FingerStrokeAssistance_P.PCI6221DA_P7_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &FingerStrokeAssistance_DW.PCI6221DA_RWORK[0]);
      ssSetIWork(rts, (int_T *) &FingerStrokeAssistance_DW.PCI6221DA_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &FingerStrokeAssistance_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &FingerStrokeAssistance_DW.PCI6221DA_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 41);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &FingerStrokeAssistance_DW.PCI6221DA_IWORK[0]);
      }

      /* registration */
      danipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }
  }

  /* Initialize Sizes */
  FingerStrokeAssistance_M->Sizes.numContStates = (0);/* Number of continuous states */
  FingerStrokeAssistance_M->Sizes.numY = (5);/* Number of model outputs */
  FingerStrokeAssistance_M->Sizes.numU = (0);/* Number of model inputs */
  FingerStrokeAssistance_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  FingerStrokeAssistance_M->Sizes.numSampTimes = (1);/* Number of sample times */
  FingerStrokeAssistance_M->Sizes.numBlocks = (155);/* Number of blocks */
  FingerStrokeAssistance_M->Sizes.numBlockIO = (145);/* Number of block outputs */
  FingerStrokeAssistance_M->Sizes.numBlockPrms = (265);/* Sum of parameter "widths" */
  return FingerStrokeAssistance_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
