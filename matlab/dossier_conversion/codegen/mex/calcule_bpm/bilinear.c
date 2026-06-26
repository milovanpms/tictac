/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bilinear.c
 *
 * Code generation for function 'bilinear'
 *
 */

/* Include files */
#include "bilinear.h"
#include "calcule_bpm_data.h"
#include "mrdivide_helper.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "xgetrf.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo v_emlrtRSI = {
    20,         /* lineNo */
    "mldivide", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" /* pathName
                                                                         */
};

static emlrtRSInfo w_emlrtRSI = {
    42,      /* lineNo */
    "mldiv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" /* pathName
                                                                         */
};

static emlrtRSInfo
    cb_emlrtRSI =
        {
            166,        /* lineNo */
            "bilinear", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\bilinear.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    db_emlrtRSI =
        {
            167,        /* lineNo */
            "bilinear", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\bilinear.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    eb_emlrtRSI =
        {
            168,        /* lineNo */
            "bilinear", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\bilinear.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    fb_emlrtRSI =
        {
            169,        /* lineNo */
            "bilinear", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\bilinear.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    hb_emlrtRSI =
        {
            109,          /* lineNo */
            "lusolveNxN", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo
    jb_emlrtRSI =
        {
            124,          /* lineNo */
            "InvAtimesX", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo kb_emlrtRSI = {
    26,        /* lineNo */
    "xgetrfs", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrfs.m" /* pathName */
};

static emlrtRSInfo yb_emlrtRSI = {
    20,                /* lineNo */
    "mrdivide_helper", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_"
    "helper.m" /* pathName */
};

/* Function Definitions */
real_T bilinear(const emlrtStack *sp, const real_T z[36], const real_T p[6],
                const real_T k[6], real_T zd[36], real_T pd[6], real_T kd[6])
{
  __m128d r;
  __m128d r1;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  real_T t1_tmp[36];
  real_T t2[36];
  real_T Y[6];
  real_T dd;
  int32_T ipiv[6];
  int32_T b_i;
  int32_T b_k;
  int32_T i;
  int32_T info;
  int32_T j;
  int32_T jBcol;
  int32_T kAcol;
  int32_T zd_tmp;
  st.prev = sp;
  st.tls = sp->tls;
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
  memset(&t2[0], 0, 36U * sizeof(real_T));
  for (b_k = 0; b_k < 6; b_k++) {
    t2[b_k + 6 * b_k] = 1.0;
  }
  for (i = 0; i <= 34; i += 2) {
    r = _mm_div_pd(_mm_mul_pd(_mm_loadu_pd(&z[i]), _mm_set1_pd(0.5)),
                   _mm_set1_pd(2.0));
    r1 = _mm_loadu_pd(&t2[i]);
    _mm_storeu_pd(&zd[i], _mm_add_pd(r1, r));
    _mm_storeu_pd(&t2[i], _mm_sub_pd(r1, r));
  }
  st.site = &cb_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  c_st.site = &w_emlrtRSI;
  d_st.site = &gb_emlrtRSI;
  e_st.site = &hb_emlrtRSI;
  f_st.site = &jb_emlrtRSI;
  memcpy(&t1_tmp[0], &t2[0], 36U * sizeof(real_T));
  g_st.site = &kb_emlrtRSI;
  info = xgetrf(&g_st, t1_tmp, ipiv);
  for (b_i = 0; b_i < 5; b_i++) {
    i = ipiv[b_i];
    if (i != b_i + 1) {
      for (j = 0; j < 6; j++) {
        jBcol = b_i + 6 * j;
        dd = zd[jBcol];
        zd_tmp = (i + 6 * j) - 1;
        zd[jBcol] = zd[zd_tmp];
        zd[zd_tmp] = dd;
      }
    }
  }
  for (j = 0; j < 6; j++) {
    jBcol = 6 * j;
    for (b_k = 0; b_k < 6; b_k++) {
      kAcol = 6 * b_k;
      i = b_k + jBcol;
      if (zd[i] != 0.0) {
        int32_T i1;
        i1 = b_k + 2;
        for (b_i = i1; b_i < 7; b_i++) {
          zd_tmp = (b_i + jBcol) - 1;
          zd[zd_tmp] -= zd[i] * t1_tmp[(b_i + kAcol) - 1];
        }
      }
    }
  }
  for (j = 0; j < 6; j++) {
    jBcol = 6 * j;
    for (b_k = 5; b_k >= 0; b_k--) {
      kAcol = 6 * b_k;
      i = b_k + jBcol;
      dd = zd[i];
      if (dd != 0.0) {
        zd[i] = dd / t1_tmp[b_k + kAcol];
        for (b_i = 0; b_i < b_k; b_i++) {
          zd_tmp = b_i + jBcol;
          zd[zd_tmp] -= zd[i] * t1_tmp[b_i + kAcol];
        }
      }
    }
  }
  if (info > 0) {
    e_st.site = &ib_emlrtRSI;
    f_st.site = &y_emlrtRSI;
    warning(&f_st);
  }
  st.site = &db_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  c_st.site = &w_emlrtRSI;
  d_st.site = &gb_emlrtRSI;
  for (b_i = 0; b_i < 6; b_i++) {
    pd[b_i] = p[b_i];
  }
  e_st.site = &hb_emlrtRSI;
  f_st.site = &jb_emlrtRSI;
  memcpy(&t1_tmp[0], &t2[0], 36U * sizeof(real_T));
  g_st.site = &kb_emlrtRSI;
  info = xgetrf(&g_st, t1_tmp, ipiv);
  for (b_i = 0; b_i < 5; b_i++) {
    i = ipiv[b_i];
    if (i != b_i + 1) {
      dd = pd[b_i];
      pd[b_i] = pd[i - 1];
      pd[i - 1] = dd;
    }
  }
  for (b_k = 0; b_k < 6; b_k++) {
    kAcol = 6 * b_k;
    if (pd[b_k] != 0.0) {
      i = b_k + 2;
      for (b_i = i; b_i < 7; b_i++) {
        pd[b_i - 1] -= pd[b_k] * t1_tmp[(b_i + kAcol) - 1];
      }
    }
  }
  for (b_k = 5; b_k >= 0; b_k--) {
    kAcol = 6 * b_k;
    dd = pd[b_k];
    if (dd != 0.0) {
      dd /= t1_tmp[b_k + kAcol];
      pd[b_k] = dd;
      for (b_i = 0; b_i < b_k; b_i++) {
        pd[b_i] -= pd[b_k] * t1_tmp[b_i + kAcol];
      }
    }
  }
  if (info > 0) {
    e_st.site = &ib_emlrtRSI;
    f_st.site = &y_emlrtRSI;
    warning(&f_st);
  }
  r = _mm_loadu_pd(&pd[0]);
  r1 = _mm_set1_pd(0.70710678118654746);
  _mm_storeu_pd(&pd[0], _mm_mul_pd(r1, r));
  r = _mm_loadu_pd(&pd[2]);
  _mm_storeu_pd(&pd[2], _mm_mul_pd(r1, r));
  r = _mm_loadu_pd(&pd[4]);
  _mm_storeu_pd(&pd[4], _mm_mul_pd(r1, r));
  st.site = &eb_emlrtRSI;
  r = _mm_set1_pd(0.70710678118654757);
  _mm_storeu_pd(&kd[0], _mm_mul_pd(r, _mm_loadu_pd(&k[0])));
  _mm_storeu_pd(&kd[2], _mm_mul_pd(r, _mm_loadu_pd(&k[2])));
  _mm_storeu_pd(&kd[4], _mm_mul_pd(r, _mm_loadu_pd(&k[4])));
  b_st.site = &yb_emlrtRSI;
  mrdiv(&b_st, kd, t2);
  st.site = &fb_emlrtRSI;
  for (i = 0; i < 6; i++) {
    Y[i] = k[i];
  }
  b_st.site = &yb_emlrtRSI;
  mrdiv(&b_st, Y, t2);
  dd = 0.0;
  for (i = 0; i < 6; i++) {
    dd += Y[i] * p[i];
  }
  return dd * 0.5 / 2.0;
}

/* End of code generation (bilinear.c) */
