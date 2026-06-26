/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgetrf.c
 *
 * Code generation for function 'xgetrf'
 *
 */

/* Include files */
#include "xgetrf.h"
#include "calcule_bpm_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo mb_emlrtRSI = {
    30,       /* lineNo */
    "xgetrf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrf.m" /* pathName */
};

static emlrtRSInfo nb_emlrtRSI = {
    55,        /* lineNo */
    "xzgetrf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgetrf.m" /* pathName */
};

static emlrtRSInfo ob_emlrtRSI = {
    63,        /* lineNo */
    "xzgetrf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgetrf.m" /* pathName */
};

static emlrtRSInfo pb_emlrtRSI = {
    45,      /* lineNo */
    "xgeru", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgeru."
    "m" /* pathName */
};

/* Function Definitions */
int32_T xgetrf(const emlrtStack *sp, real_T A[36], int32_T ipiv[6])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  int32_T a;
  int32_T b_j;
  int32_T info;
  int32_T j;
  int32_T jp1j;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &mb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  _mm_storeu_si128(
      (__m128i *)&ipiv[0],
      _mm_add_epi32(_mm_set1_epi32(1),
                    _mm_add_epi32(_mm_set1_epi32(0),
                                  _mm_loadu_si128((const __m128i *)&iv[0]))));
  ipiv[4] = 5;
  ipiv[5] = 6;
  info = 0;
  for (j = 0; j < 5; j++) {
    real_T smax;
    int32_T b_tmp;
    int32_T jA;
    int32_T mmj_tmp;
    mmj_tmp = 4 - j;
    b_tmp = j * 7;
    jp1j = b_tmp + 2;
    jA = 7 - j;
    a = 0;
    smax = muDoubleScalarAbs(A[b_tmp]);
    for (k = 2; k < jA; k++) {
      real_T s;
      s = muDoubleScalarAbs(A[(b_tmp + k) - 1]);
      if (s > smax) {
        a = k - 1;
        smax = s;
      }
    }
    if (A[b_tmp + a] != 0.0) {
      if (a != 0) {
        a += j;
        ipiv[j] = a + 1;
        for (k = 0; k < 6; k++) {
          jA = j + k * 6;
          smax = A[jA];
          b_j = a + k * 6;
          A[jA] = A[b_j];
          A[b_j] = smax;
        }
      }
      b_j = (b_tmp - j) + 6;
      b_st.site = &nb_emlrtRSI;
      for (a = jp1j; a <= b_j; a++) {
        A[a - 1] /= A[b_tmp];
      }
    } else {
      info = j + 1;
    }
    b_st.site = &ob_emlrtRSI;
    c_st.site = &pb_emlrtRSI;
    d_st.site = &qb_emlrtRSI;
    e_st.site = &rb_emlrtRSI;
    jA = b_tmp + 8;
    f_st.site = &sb_emlrtRSI;
    for (b_j = 0; b_j <= mmj_tmp; b_j++) {
      smax = A[(b_tmp + b_j * 6) + 6];
      if (smax != 0.0) {
        a = (jA - j) + 4;
        f_st.site = &tb_emlrtRSI;
        if ((jA <= a) && (a > 2147483646)) {
          g_st.site = &s_emlrtRSI;
          check_forloop_overflow_error(&g_st);
        }
        for (jp1j = jA; jp1j <= a; jp1j++) {
          A[jp1j - 1] += A[((b_tmp + jp1j) - jA) + 1] * -smax;
        }
      }
      jA += 6;
    }
  }
  if ((info == 0) && (!(A[35] != 0.0))) {
    info = 6;
  }
  return info;
}

/* End of code generation (xgetrf.c) */
