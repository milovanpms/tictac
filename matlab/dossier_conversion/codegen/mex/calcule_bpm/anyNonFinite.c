/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * anyNonFinite.c
 *
 * Code generation for function 'anyNonFinite'
 *
 */

/* Include files */
#include "anyNonFinite.h"
#include "calcule_bpm_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Function Definitions */
boolean_T anyNonFinite(const real_T x[36])
{
  int32_T k;
  boolean_T p;
  p = true;
  for (k = 0; k < 36; k++) {
    if (p) {
      real_T d;
      d = x[k];
      if (muDoubleScalarIsInf(d) || muDoubleScalarIsNaN(d)) {
        p = false;
      }
    } else {
      p = false;
    }
  }
  return !p;
}

/* End of code generation (anyNonFinite.c) */
