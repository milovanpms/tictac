/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * filter.c
 *
 * Code generation for function 'filter'
 *
 */

/* Include files */
#include "filter.h"
#include "calcule_bpm_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRTEInfo i_emlrtRTEI = {
    154,      /* lineNo */
    5,        /* colNo */
    "filter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" /* pName
                                                                           */
};

static emlrtRTEInfo j_emlrtRTEI = {
    152,      /* lineNo */
    5,        /* colNo */
    "filter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" /* pName
                                                                           */
};

/* Function Definitions */
void b_filter(const real_T x[19], real_T y[19])
{
  static const real_T dv[5] = {0.029954582208092471, 0.0, -0.059909164416184942,
                               0.0, 0.029954582208092471};
  static const real_T dv1[5] = {1.0, -3.3896867071734995, 4.37041391131624,
                                -2.5537313794916958, 0.57406191508395488};
  int32_T j;
  int32_T k;
  memset(&y[0], 0, 19U * sizeof(real_T));
  for (k = 0; k < 19; k++) {
    real_T as;
    int32_T i;
    int32_T y_tmp;
    if (19 - k < 5) {
      i = 18 - k;
    } else {
      i = 4;
    }
    for (j = 0; j <= i; j++) {
      y_tmp = k + j;
      y[y_tmp] += x[k] * dv[j];
    }
    if (18 - k < 4) {
      i = 17 - k;
    } else {
      i = 3;
    }
    as = -y[k];
    for (j = 0; j <= i; j++) {
      y_tmp = (k + j) + 1;
      y[y_tmp] += as * dv1[j + 1];
    }
  }
}

int32_T filter(const emlrtStack *sp, real_T b[7], real_T a[7],
               const real_T x_data[], int32_T x_size, const real_T zi[6],
               real_T y_data[])
{
  int32_T j;
  int32_T k;
  int32_T y_size;
  if (muDoubleScalarIsInf(a[0]) || muDoubleScalarIsNaN(a[0])) {
    emlrtErrorWithMessageIdR2018a(
        sp, &j_emlrtRTEI,
        "Coder:MATLAB:filter_firstElementOfDenominatorFilterNotFinite",
        "Coder:MATLAB:filter_firstElementOfDenominatorFilterNotFinite", 0);
  } else if (a[0] == 0.0) {
    emlrtErrorWithMessageIdR2018a(
        sp, &i_emlrtRTEI,
        "Coder:MATLAB:filter_firstElementOfDenominatorFilterZero",
        "Coder:MATLAB:filter_firstElementOfDenominatorFilterZero", 0);
  } else if (a[0] != 1.0) {
    __m128d r;
    __m128d r1;
    r = _mm_loadu_pd(&b[0]);
    r1 = _mm_set1_pd(a[0]);
    _mm_storeu_pd(&b[0], _mm_div_pd(r, r1));
    r = _mm_loadu_pd(&b[2]);
    _mm_storeu_pd(&b[2], _mm_div_pd(r, r1));
    r = _mm_loadu_pd(&b[4]);
    _mm_storeu_pd(&b[4], _mm_div_pd(r, r1));
    b[6] /= a[0];
    r = _mm_loadu_pd(&a[1]);
    _mm_storeu_pd(&a[1], _mm_div_pd(r, r1));
    r = _mm_loadu_pd(&a[3]);
    _mm_storeu_pd(&a[3], _mm_div_pd(r, r1));
    r = _mm_loadu_pd(&a[5]);
    _mm_storeu_pd(&a[5], _mm_div_pd(r, r1));
    a[0] = 1.0;
  }
  y_size = x_size;
  for (k = 0; k < 6; k++) {
    y_data[k] = zi[k];
  }
  memset(&y_data[6], 0, (uint32_T)(x_size - 6) * sizeof(real_T));
  for (k = 0; k < x_size; k++) {
    real_T as;
    int32_T a_tmp;
    int32_T naxpy;
    int32_T y_tmp;
    a_tmp = x_size - k;
    naxpy = muIntScalarMin_sint32(a_tmp, 7);
    for (j = 0; j < naxpy; j++) {
      y_tmp = k + j;
      y_data[y_tmp] += x_data[k] * b[j];
    }
    if (a_tmp - 1 < 6) {
      naxpy = a_tmp - 2;
    } else {
      naxpy = 5;
    }
    as = -y_data[k];
    for (j = 0; j <= naxpy; j++) {
      y_tmp = (k + j) + 1;
      y_data[y_tmp] += as * a[j + 1];
    }
  }
  return y_size;
}

/* End of code generation (filter.c) */
