/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * zp2ss.c
 *
 * Code generation for function 'zp2ss'
 *
 */

/* Include files */
#include "zp2ss.h"
#include "calcule_bpm_data.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtECInfo emlrtECI = {
    -1,      /* nDims */
    206,     /* lineNo */
    9,       /* colNo */
    "zp2ss", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\controllib\\general\\zp2ss.m" /* pName
                                                                            */
};

/* Function Definitions */
real_T zp2ss(const emlrtStack *sp, real_T a[9], real_T b[3], real_T c[3])
{
  creal_T b_c[3];
  real_T b_a[4];
  real_T t[4];
  real_T d;
  real_T re_tmp;
  int32_T b_iv[2];
  int32_T b_iv1[2];
  int32_T j;
  int32_T k;
  memset(&a[0], 0, 9U * sizeof(real_T));
  c[1] = 0.0;
  c[2] = 0.0;
  a[0] = -1.0;
  b[0] = 1.0;
  b_c[0].re = 1.0;
  b_c[0].im = 0.0;
  for (j = 0; j < 2; j++) {
    real_T b_re_tmp;
    d = 1.7320508075688774 * (real_T)j - 0.86602540378443871;
    re_tmp = b_c[j].im;
    b_re_tmp = b_c[j].re;
    b_c[j + 1].re = 0.49999999999999978 * b_re_tmp - -d * re_tmp;
    b_c[j + 1].im = 0.49999999999999978 * re_tmp + -d * b_re_tmp;
    for (k = j + 1; k >= 2; k--) {
      b_c[1].re -= -0.49999999999999978 * b_c[0].re - d * b_c[0].im;
      b_c[1].im -= -0.49999999999999978 * b_c[0].im + d * b_c[0].re;
    }
  }
  t[1] = 0.0;
  t[2] = 0.0;
  t[0] = 1.0;
  t[3] = 1.0000000000000002;
  d = (1.0 - -b_c[1].re * 0.0) / 1.0000000000000002;
  b_a[1] = d;
  b_a[0] = -b_c[1].re - d * 0.0;
  d = (0.0 - -b_c[2].re * 0.0) / 1.0000000000000002;
  b_a[3] = d;
  b_a[2] = -b_c[2].re - d * 0.0;
  a[1] = 1.0;
  b_iv[0] = 2;
  b_iv1[0] = 2;
  a[2] = 0.0;
  b_iv[1] = 1;
  b_iv1[1] = 1;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &b_iv1[0], 2, &emlrtECI,
                                (emlrtCTX)sp);
  c[0] = 0.0;
  for (j = 0; j < 2; j++) {
    d = b_a[j + 2];
    re_tmp = b_a[j];
    a[j + 4] = re_tmp + d * 0.0;
    a[j + 7] = re_tmp * 0.0 + d * 1.0000000000000002;
    c[j + 1] = t[(j << 1) + 1];
    b[j + 1] = 0.0;
  }
  __m128d r;
  r = _mm_loadu_pd(&c[0]);
  _mm_storeu_pd(&c[0], _mm_mul_pd(r, _mm_set1_pd(0.99999999999999989)));
  c[2] *= 0.99999999999999989;
  return 0.0;
}

/* End of code generation (zp2ss.c) */
