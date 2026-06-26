/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mrdivide_helper.c
 *
 * Code generation for function 'mrdivide_helper'
 *
 */

/* Include files */
#include "mrdivide_helper.h"
#include "calcule_bpm_data.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "xgetrf.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ac_emlrtRSI = {
    42,      /* lineNo */
    "mrdiv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_"
    "helper.m" /* pathName */
};

static emlrtRSInfo
    bc_emlrtRSI =
        {
            107,          /* lineNo */
            "lusolveNxN", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo
    cc_emlrtRSI =
        {
            135,          /* lineNo */
            "XtimesInvA", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

/* Function Definitions */
void mrdiv(const emlrtStack *sp, real_T A[6], const real_T B[36])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T b_A[36];
  real_T temp;
  int32_T ipiv[6];
  int32_T i;
  int32_T info;
  int32_T j;
  int32_T jAcol;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ac_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &gb_emlrtRSI;
  c_st.site = &bc_emlrtRSI;
  memcpy(&b_A[0], &B[0], 36U * sizeof(real_T));
  d_st.site = &cc_emlrtRSI;
  info = xgetrf(&d_st, b_A, ipiv);
  for (j = 0; j < 6; j++) {
    jAcol = 6 * j;
    for (k = 0; k < j; k++) {
      temp = b_A[k + jAcol];
      if (temp != 0.0) {
        A[j] -= temp * A[k];
      }
    }
    A[j] *= 1.0 / b_A[j + jAcol];
  }
  for (j = 5; j >= 0; j--) {
    jAcol = 6 * j - 1;
    i = j + 2;
    for (k = i; k < 7; k++) {
      temp = b_A[k + jAcol];
      if (temp != 0.0) {
        A[j] -= temp * A[k - 1];
      }
    }
  }
  for (j = 4; j >= 0; j--) {
    i = ipiv[j];
    if (i != j + 1) {
      temp = A[j];
      A[j] = A[i - 1];
      A[i - 1] = temp;
    }
  }
  if (info > 0) {
    c_st.site = &ib_emlrtRSI;
    d_st.site = &y_emlrtRSI;
    warning(&d_st);
  }
}

/* End of code generation (mrdivide_helper.c) */
