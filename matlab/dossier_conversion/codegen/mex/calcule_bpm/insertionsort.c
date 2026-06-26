/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * insertionsort.c
 *
 * Code generation for function 'insertionsort'
 *
 */

/* Include files */
#include "insertionsort.h"
#include "calcule_bpm_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo bd_emlrtRSI = {
    18,              /* lineNo */
    "insertionsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\insertionsort.m" /* pathName */
};

/* Function Definitions */
void b_insertionsort(int32_T x_data[], int32_T xend)
{
  int32_T k;
  for (k = 2; k <= xend; k++) {
    int32_T idx;
    int32_T xc;
    boolean_T exitg1;
    xc = x_data[k - 1];
    idx = k - 1;
    exitg1 = false;
    while ((!exitg1) && (idx >= 1)) {
      int32_T i;
      i = x_data[idx - 1];
      if (xc < i) {
        x_data[idx] = i;
        idx--;
      } else {
        exitg1 = true;
      }
    }
    x_data[idx] = xc;
  }
}

void c_insertionsort(const emlrtStack *sp, int32_T x_data[], int32_T xstart,
                     int32_T xend)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T a;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  a = xstart + 1;
  st.site = &bd_emlrtRSI;
  if ((xstart + 1 <= xend) && (xend > 2147483646)) {
    b_st.site = &s_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (k = a; k <= xend; k++) {
    int32_T idx;
    int32_T xc;
    boolean_T exitg1;
    xc = x_data[k - 1];
    idx = k - 1;
    exitg1 = false;
    while ((!exitg1) && (idx >= xstart)) {
      int32_T i;
      i = x_data[idx - 1];
      if (xc < i) {
        x_data[idx] = i;
        idx--;
      } else {
        exitg1 = true;
      }
    }
    x_data[idx] = xc;
  }
}

void insertionsort(int32_T x[16])
{
  int32_T k;
  for (k = 0; k < 15; k++) {
    int32_T idx;
    int32_T xc;
    boolean_T exitg1;
    xc = x[k + 1];
    idx = k;
    exitg1 = false;
    while ((!exitg1) && (idx + 1 >= 1)) {
      int32_T aj;
      int32_T i;
      boolean_T varargout_1;
      aj = iv1[x[idx] - 1];
      i = iv1[xc - 1];
      if (i < aj) {
        varargout_1 = true;
      } else if (i == aj) {
        varargout_1 = (iv2[xc - 1] < iv2[x[idx] - 1]);
      } else {
        varargout_1 = false;
      }
      if (varargout_1) {
        x[idx + 1] = x[idx];
        idx--;
      } else {
        exitg1 = true;
      }
    }
    x[idx + 1] = xc;
  }
}

/* End of code generation (insertionsort.c) */
