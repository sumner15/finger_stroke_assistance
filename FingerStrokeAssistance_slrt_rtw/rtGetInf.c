/*
 * rtGetInf.c
 *
 * Code generation for model "FingerStrokeAssistance".
 *
 * Model version              : 1.1275
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Mon Jul 03 13:01:17 2017
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

/*
 * Abstract:
 *      Function to intialize non-finite, Inf
 */
#include "rtGetInf.h"
#define NumBitsPerChar                 8U

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    uint16_T one = 1U;
    enum {
      LittleEndian,
      BigEndian
    } machByteOrder = (*((uint8_T *) &one) == 1U) ? LittleEndian : BigEndian;
    switch (machByteOrder) {
     case LittleEndian:
      {
        union {
          LittleEndianIEEEDouble bitVal;
          real_T fltVal;
        } tmpVal;

        tmpVal.bitVal.words.wordH = 0x7FF00000U;
        tmpVal.bitVal.words.wordL = 0x00000000U;
        inf = tmpVal.fltVal;
        break;
      }

     case BigEndian:
      {
        union {
          BigEndianIEEEDouble bitVal;
          real_T fltVal;
        } tmpVal;

        tmpVal.bitVal.words.wordH = 0x7FF00000U;
        tmpVal.bitVal.words.wordL = 0x00000000U;
        inf = tmpVal.fltVal;
        break;
      }
    }
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    uint16_T one = 1U;
    enum {
      LittleEndian,
      BigEndian
    } machByteOrder = (*((uint8_T *) &one) == 1U) ? LittleEndian : BigEndian;
    switch (machByteOrder) {
     case LittleEndian:
      {
        union {
          LittleEndianIEEEDouble bitVal;
          real_T fltVal;
        } tmpVal;

        tmpVal.bitVal.words.wordH = 0xFFF00000U;
        tmpVal.bitVal.words.wordL = 0x00000000U;
        minf = tmpVal.fltVal;
        break;
      }

     case BigEndian:
      {
        union {
          BigEndianIEEEDouble bitVal;
          real_T fltVal;
        } tmpVal;

        tmpVal.bitVal.words.wordH = 0xFFF00000U;
        tmpVal.bitVal.words.wordL = 0x00000000U;
        minf = tmpVal.fltVal;
        break;
      }
    }
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}
