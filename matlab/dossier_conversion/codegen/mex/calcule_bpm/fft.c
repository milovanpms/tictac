/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fft.c
 *
 * Code generation for function 'fft'
 *
 */

/* Include files */
#include "fft.h"
#include "calcule_bpm_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void fft(const real_T x[19], creal_T y[19])
{
  emlrtFFTWSetNumThreads(8);
  emlrtFFTW_1D_R2C((real_T *)&x[0], (real_T *)&y[0], 1, 19, 19, 1, -1);
}

/* End of code generation (fft.c) */
