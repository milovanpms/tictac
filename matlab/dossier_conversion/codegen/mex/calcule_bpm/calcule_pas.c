/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calcule_pas.c
 *
 * Code generation for function 'calcule_pas'
 *
 */

/* Include files */
#include "calcule_pas.h"
#include "calcule_bpm_data.h"
#include "fft.h"
#include "filter.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "sumMatrixIncludeNaN.h"
#include "mwmathutil.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo th_emlrtRSI = {
    3,             /* lineNo */
    "calcule_pas", /* fcnName */
    "C:\\Users\\33676\\Documents\\tictac\\MATLAB\\dossier_convertion\\calcule_"
    "pas.m" /* pathName */
};

/* Function Definitions */
real_T calcule_pas(const emlrtStack *sp, const real_T accX[19],
                   const real_T accY[19], const real_T accZ[19])
{
  __m128d r;
  emlrtStack st;
  creal_T Y[19];
  real_T accFiltered[19];
  real_T accNorm[19];
  real_T Y_half[9];
  real_T pas;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  covrtLogFcn(&emlrtCoverageInstance, 1U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 0U);
  for (k = 0; k <= 16; k += 2) {
    __m128d r1;
    __m128d r2;
    r = _mm_loadu_pd(&accX[k]);
    r1 = _mm_loadu_pd(&accY[k]);
    r2 = _mm_loadu_pd(&accZ[k]);
    _mm_storeu_pd(&accNorm[k],
                  _mm_add_pd(_mm_add_pd(_mm_mul_pd(r, r), _mm_mul_pd(r1, r1)),
                             _mm_mul_pd(r2, r2)));
  }
  accNorm[18] =
      (accX[18] * accX[18] + accY[18] * accY[18]) + accZ[18] * accZ[18];
  st.site = &th_emlrtRSI;
  b_sqrt(&st, accNorm);
  b_filter(accNorm, accFiltered);
  pas = c_sumColumnB(accFiltered) / 19.0;
  for (k = 0; k <= 16; k += 2) {
    r = _mm_loadu_pd(&accFiltered[k]);
    _mm_storeu_pd(&accFiltered[k], _mm_sub_pd(r, _mm_set1_pd(pas)));
  }
  accFiltered[18] -= pas;
  fft(accFiltered, Y);
  for (k = 0; k < 9; k++) {
    Y_half[k] = muDoubleScalarHypot(Y[k].re, Y[k].im);
  }
  if ((Y_half[1] < Y_half[2]) ||
      (muDoubleScalarIsNaN(Y_half[1]) && (!muDoubleScalarIsNaN(Y_half[2])))) {
    k = 2;
  } else {
    k = 1;
  }
  return 2.1052631578947367 * (real_T)k * 60.0;
}

/* End of code generation (calcule_pas.c) */
