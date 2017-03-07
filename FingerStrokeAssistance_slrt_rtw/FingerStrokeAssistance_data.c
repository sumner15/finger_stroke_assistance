/*
 * FingerStrokeAssistance_data.c
 *
 * Code generation for model "FingerStrokeAssistance".
 *
 * Model version              : 1.1127
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Mon Mar 06 14:20:29 2017
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FingerStrokeAssistance.h"
#include "FingerStrokeAssistance_private.h"

/* Block parameters (auto storage) */
P_FingerStrokeAssistance_T FingerStrokeAssistance_P = {
  /*  Variable: Alow
   * Referenced by:
   *   '<S26>/Low Pass 100 Hz'
   *   '<S26>/Low Pass 100 Hz1'
   */
  { 0.97351956087880709, 0.018600534405527915, -0.018600534405527919,
    0.9998246889024921 },

  /*  Variable: Blow
   * Referenced by:
   *   '<S26>/Low Pass 100 Hz'
   *   '<S26>/Low Pass 100 Hz1'
   */
  { 0.02630512802368495, 0.00024792733173036719 },

  /*  Variable: Clow
   * Referenced by:
   *   '<S26>/Low Pass 100 Hz'
   *   '<S26>/Low Pass 100 Hz1'
   */
  { 0.0065762820059212393, 0.707044799353615 },
  8.7655548754014668E-5,               /* Variable: Dlow
                                        * Referenced by:
                                        *   '<S26>/Low Pass 100 Hz'
                                        *   '<S26>/Low Pass 100 Hz1'
                                        */

  /*  Variable: x0low
   * Referenced by:
   *   '<S26>/Low Pass 100 Hz'
   *   '<S26>/Low Pass 100 Hz1'
   */
  { -0.0, 0.0 },
  0.0,                                 /* Mask Parameter: DiscretePIDController_D
                                        * Referenced by: '<S17>/Derivative Gain'
                                        */
  0.0,                                 /* Mask Parameter: DiscretePIDController_I
                                        * Referenced by: '<S17>/Integral Gain'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                        * Referenced by: '<S19>/UD'
                                        */
  100.0,                               /* Mask Parameter: DiscretePIDController_N
                                        * Referenced by: '<S17>/Filter Coefficient'
                                        */
  10.0,                                /* Mask Parameter: DiscretePIDController_P
                                        * Referenced by: '<S17>/Proportional Gain'
                                        */
  0.0,                                 /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S12>/Delay Input1'
                                        */
  0.0,                                 /* Mask Parameter: DetectChange_vinit_a
                                        * Referenced by: '<S32>/Delay Input1'
                                        */
  0.0,                                 /* Mask Parameter: DetectChange_vinit_d
                                        * Referenced by: '<S33>/Delay Input1'
                                        */
  0.0,                                 /* Expression: [0]
                                        * Referenced by: '<S21>/Out1'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  -0.1,                                /* Expression: -0.1
                                        * Referenced by: '<Root>/Constant3'
                                        */
  0.2,                                 /* Expression: .2
                                        * Referenced by: '<Root>/Constant4'
                                        */
  -0.7,                                /* Expression: -0.7
                                        * Referenced by: '<Root>/Constant5'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Constant6'
                                        */
  -0.1,                                /* Expression: -.1
                                        * Referenced by: '<Root>/Constant7'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Delay'
                                        */

  /*  Expression: [b_hp]
   * Referenced by: '<S1>/Discrete Filter1'
   */
  { 0.99968593938935957, -0.99968593938935957 },

  /*  Expression: [a_hp]
   * Referenced by: '<S1>/Discrete Filter1'
   */
  { 1.0, -0.99937187877871914 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Discrete Filter1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S1>/Gain1'
                                        */
  1.0,                                 /* Expression: 1/1
                                        * Referenced by: '<S1>/Damping'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Delay1'
                                        */
  0.001,                               /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S1>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Discrete-Time Integrator'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Discrete-Time Integrator'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Unit Delay2'
                                        */
  0.001,                               /* Computed Parameter: DiscreteTimeIntegrator_gainva_n
                                        * Referenced by: '<S8>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Unit Delay2'
                                        */
  0.001,                               /* Computed Parameter: DiscreteTimeIntegrator_gainva_b
                                        * Referenced by: '<S9>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Discrete-Time Integrator'
                                        */

  /*  Computed Parameter: PCI6221ENC_P1_Size
   * Referenced by: '<S7>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },
  21.0,                                /* Expression: device
                                        * Referenced by: '<S7>/PCI 6221 ENC '
                                        */

  /*  Computed Parameter: PCI6221ENC_P2_Size
   * Referenced by: '<S7>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: channel
                                        * Referenced by: '<S7>/PCI 6221 ENC '
                                        */

  /*  Computed Parameter: PCI6221ENC_P3_Size
   * Referenced by: '<S7>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: countMode
                                        * Referenced by: '<S7>/PCI 6221 ENC '
                                        */

  /*  Computed Parameter: PCI6221ENC_P4_Size
   * Referenced by: '<S7>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initCount
                                        * Referenced by: '<S7>/PCI 6221 ENC '
                                        */

  /*  Computed Parameter: PCI6221ENC_P5_Size
   * Referenced by: '<S7>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: reload
                                        * Referenced by: '<S7>/PCI 6221 ENC '
                                        */

  /*  Computed Parameter: PCI6221ENC_P6_Size
   * Referenced by: '<S7>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: indexPhase
                                        * Referenced by: '<S7>/PCI 6221 ENC '
                                        */

  /*  Computed Parameter: PCI6221ENC_P7_Size
   * Referenced by: '<S7>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: filter
                                        * Referenced by: '<S7>/PCI 6221 ENC '
                                        */

  /*  Computed Parameter: PCI6221ENC_P8_Size
   * Referenced by: '<S7>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: outmask
                                        * Referenced by: '<S7>/PCI 6221 ENC '
                                        */

  /*  Computed Parameter: PCI6221ENC_P9_Size
   * Referenced by: '<S7>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampleTime
                                        * Referenced by: '<S7>/PCI 6221 ENC '
                                        */

  /*  Computed Parameter: PCI6221ENC_P10_Size
   * Referenced by: '<S7>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<S7>/PCI 6221 ENC '
                                        */

  /*  Computed Parameter: PCI6221ENC1_P1_Size
   * Referenced by: '<S7>/PCI 6221 ENC 1'
   */
  { 1.0, 1.0 },
  21.0,                                /* Expression: device
                                        * Referenced by: '<S7>/PCI 6221 ENC 1'
                                        */

  /*  Computed Parameter: PCI6221ENC1_P2_Size
   * Referenced by: '<S7>/PCI 6221 ENC 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channel
                                        * Referenced by: '<S7>/PCI 6221 ENC 1'
                                        */

  /*  Computed Parameter: PCI6221ENC1_P3_Size
   * Referenced by: '<S7>/PCI 6221 ENC 1'
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: countMode
                                        * Referenced by: '<S7>/PCI 6221 ENC 1'
                                        */

  /*  Computed Parameter: PCI6221ENC1_P4_Size
   * Referenced by: '<S7>/PCI 6221 ENC 1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initCount
                                        * Referenced by: '<S7>/PCI 6221 ENC 1'
                                        */

  /*  Computed Parameter: PCI6221ENC1_P5_Size
   * Referenced by: '<S7>/PCI 6221 ENC 1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: reload
                                        * Referenced by: '<S7>/PCI 6221 ENC 1'
                                        */

  /*  Computed Parameter: PCI6221ENC1_P6_Size
   * Referenced by: '<S7>/PCI 6221 ENC 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: indexPhase
                                        * Referenced by: '<S7>/PCI 6221 ENC 1'
                                        */

  /*  Computed Parameter: PCI6221ENC1_P7_Size
   * Referenced by: '<S7>/PCI 6221 ENC 1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: filter
                                        * Referenced by: '<S7>/PCI 6221 ENC 1'
                                        */

  /*  Computed Parameter: PCI6221ENC1_P8_Size
   * Referenced by: '<S7>/PCI 6221 ENC 1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: outmask
                                        * Referenced by: '<S7>/PCI 6221 ENC 1'
                                        */

  /*  Computed Parameter: PCI6221ENC1_P9_Size
   * Referenced by: '<S7>/PCI 6221 ENC 1'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampleTime
                                        * Referenced by: '<S7>/PCI 6221 ENC 1'
                                        */

  /*  Computed Parameter: PCI6221ENC1_P10_Size
   * Referenced by: '<S7>/PCI 6221 ENC 1'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<S7>/PCI 6221 ENC 1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S10>/paremeters_ must_be_one'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/parLeftMode'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S10>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Saturation'
                                        */
  0.00022222222222222223,              /* Expression: 1/4500.0
                                        * Referenced by: '<S7>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Unit Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay1'
                                        */
  0.001,                               /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S17>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S17>/Integrator'
                                        */
  0.001,                               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S17>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S17>/Filter'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S2>/Gain'
                                        */
  1000.0,                              /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S19>/TSamp'
                                        */

  /*  Expression: [b_lp]
   * Referenced by: '<S7>/Discrete Filter1'
   */
  { 0.00094159064659332659, 0.00094159064659332659 },

  /*  Expression: [a_lp]
   * Referenced by: '<S7>/Discrete Filter1'
   */
  { 1.0, -0.99811681870681335 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Discrete Filter1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S7>/Gain1'
                                        */

  /*  Computed Parameter: PCI6221DA_P1_Size
   * Referenced by: '<S7>/PCI-6221 DA'
   */
  { 1.0, 2.0 },

  /*  Expression: channel
   * Referenced by: '<S7>/PCI-6221 DA'
   */
  { 1.0, 2.0 },

  /*  Computed Parameter: PCI6221DA_P2_Size
   * Referenced by: '<S7>/PCI-6221 DA'
   */
  { 1.0, 2.0 },

  /*  Expression: range
   * Referenced by: '<S7>/PCI-6221 DA'
   */
  { 0.0, 0.0 },

  /*  Computed Parameter: PCI6221DA_P3_Size
   * Referenced by: '<S7>/PCI-6221 DA'
   */
  { 1.0, 2.0 },

  /*  Expression: reset
   * Referenced by: '<S7>/PCI-6221 DA'
   */
  { 1.0, 1.0 },

  /*  Computed Parameter: PCI6221DA_P4_Size
   * Referenced by: '<S7>/PCI-6221 DA'
   */
  { 1.0, 2.0 },

  /*  Expression: initValue
   * Referenced by: '<S7>/PCI-6221 DA'
   */
  { 0.0, 0.0 },

  /*  Computed Parameter: PCI6221DA_P5_Size
   * Referenced by: '<S7>/PCI-6221 DA'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampletime
                                        * Referenced by: '<S7>/PCI-6221 DA'
                                        */

  /*  Computed Parameter: PCI6221DA_P6_Size
   * Referenced by: '<S7>/PCI-6221 DA'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<S7>/PCI-6221 DA'
                                        */

  /*  Computed Parameter: PCI6221DA_P7_Size
   * Referenced by: '<S7>/PCI-6221 DA'
   */
  { 1.0, 1.0 },
  21.0,                                /* Expression: boardType
                                        * Referenced by: '<S7>/PCI-6221 DA'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S26>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S26>/Memory1'
                                        */
  1.5,                                 /* Expression: 1.5
                                        * Referenced by: '<S27>/Constant'
                                        */

  /*  Computed Parameter: PCI6221AD1_P1_Size
   * Referenced by: '<S7>/PCI-6221 AD1'
   */
  { 1.0, 8.0 },

  /*  Expression: channel
   * Referenced by: '<S7>/PCI-6221 AD1'
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 },

  /*  Computed Parameter: PCI6221AD1_P2_Size
   * Referenced by: '<S7>/PCI-6221 AD1'
   */
  { 1.0, 8.0 },

  /*  Expression: range
   * Referenced by: '<S7>/PCI-6221 AD1'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Computed Parameter: PCI6221AD1_P3_Size
   * Referenced by: '<S7>/PCI-6221 AD1'
   */
  { 1.0, 8.0 },

  /*  Expression: coupling
   * Referenced by: '<S7>/PCI-6221 AD1'
   */
  { 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0 },

  /*  Computed Parameter: PCI6221AD1_P4_Size
   * Referenced by: '<S7>/PCI-6221 AD1'
   */
  { 1.0, 1.0 },
  5.0E-6,                              /* Expression: scantime
                                        * Referenced by: '<S7>/PCI-6221 AD1'
                                        */

  /*  Computed Parameter: PCI6221AD1_P5_Size
   * Referenced by: '<S7>/PCI-6221 AD1'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampletime
                                        * Referenced by: '<S7>/PCI-6221 AD1'
                                        */

  /*  Computed Parameter: PCI6221AD1_P6_Size
   * Referenced by: '<S7>/PCI-6221 AD1'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<S7>/PCI-6221 AD1'
                                        */

  /*  Computed Parameter: PCI6221AD1_P7_Size
   * Referenced by: '<S7>/PCI-6221 AD1'
   */
  { 1.0, 1.0 },
  21.0,                                /* Expression: boardType
                                        * Referenced by: '<S7>/PCI-6221 AD1'
                                        */
  0.172,                               /* Expression: .172
                                        * Referenced by: '<S27>/gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Unit Delay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Unit Delay1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S10>/parTrajMode'
                                        */
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<S10>/Saturation1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S10>/Saturation1'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S10>/parFixedDur'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S10>/Saturation2'
                                        */
  0.25,                                /* Expression: .25
                                        * Referenced by: '<S10>/Saturation2'
                                        */

  /*  Expression: zeros(1,4)
   * Referenced by: '<S34>/Memory'
   */
  { 0.0, 0.0, 0.0, 0.0 },
  0.05,                                /* Expression: .05
                                        * Referenced by: '<S10>/parChangeRate'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/parKp1'
                                        */

  /*  Expression: zeros(1,4)
   * Referenced by: '<S35>/Memory'
   */
  { 0.0, 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/parKp2'
                                        */

  /*  Expression: zeros(1,4)
   * Referenced by: '<S36>/Memory'
   */
  { 0.0, 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S10>/parKd1'
                                        */

  /*  Expression: zeros(1,4)
   * Referenced by: '<S37>/Memory'
   */
  { 0.0, 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S10>/parKd2'
                                        */

  /*  Expression: zeros(1,4)
   * Referenced by: '<S38>/Memory'
   */
  { 0.0, 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S10>/parKdV1'
                                        */

  /*  Expression: zeros(1,4)
   * Referenced by: '<S39>/Memory'
   */
  { 0.0, 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S10>/parKdV2'
                                        */
  0.25,                                /* Expression: 0.25
                                        * Referenced by: '<S10>/parFThresh'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/parForceTrigger'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/parMarker'
                                        */
  0.4,                                 /* Expression: .4
                                        * Referenced by: '<S10>/parMaxTrajDur'
                                        */
  0.75,                                /* Expression: 0.75
                                        * Referenced by: '<S10>/parPStop'
                                        */
  0.375,                               /* Expression: .375
                                        * Referenced by: '<S10>/parVThresh'
                                        */
  0.5,                                 /* Expression: .5
                                        * Referenced by: '<S10>/parWiggleAmp'
                                        */
  7.66,                                /* Expression: 7.66
                                        * Referenced by: '<S11>/Gain3'
                                        */
  7.66,                                /* Expression: 7.66
                                        * Referenced by: '<S11>/Gain2'
                                        */
  7.66,                                /* Expression: 7.66
                                        * Referenced by: '<S11>/Gain'
                                        */
  7.66,                                /* Expression: 7.66
                                        * Referenced by: '<S11>/Gain1'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S1>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S1>/Delay1'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S5>/Constant'
                                        */
  0                                    /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S6>/Constant'
                                        */
};
