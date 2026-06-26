/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * heapsort.c
 *
 * Code generation for function 'heapsort'
 *
 */

/* Include files */
#include "heapsort.h"
#include "calcule_bpm_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo jh_emlrtRSI = {
    20,         /* lineNo */
    "heapsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\heapsort.m" /* pathName */
};

/* Function Declarations */
static void heapify(int32_T x_data[], int32_T idx, int32_T xstart,
                    int32_T xend);

/* Function Definitions */
static void heapify(int32_T x_data[], int32_T idx, int32_T xstart, int32_T xend)
{
  int32_T cmpIdx;
  int32_T extremum;
  int32_T extremumIdx;
  int32_T leftIdx;
  boolean_T changed;
  boolean_T exitg1;
  changed = true;
  extremumIdx = (idx + xstart) - 2;
  leftIdx = ((idx << 1) + xstart) - 1;
  exitg1 = false;
  while ((!exitg1) && (leftIdx < xend)) {
    int32_T xcmp;
    changed = false;
    extremum = x_data[extremumIdx];
    cmpIdx = leftIdx - 1;
    xcmp = x_data[leftIdx - 1];
    if (xcmp < x_data[leftIdx]) {
      cmpIdx = leftIdx;
      xcmp = x_data[leftIdx];
    }
    if (x_data[extremumIdx] < xcmp) {
      x_data[extremumIdx] = xcmp;
      x_data[cmpIdx] = extremum;
      extremumIdx = cmpIdx;
      leftIdx = ((((cmpIdx - xstart) + 2) << 1) + xstart) - 1;
      changed = true;
    } else {
      exitg1 = true;
    }
  }
  if (changed && (leftIdx <= xend)) {
    extremum = x_data[extremumIdx];
    cmpIdx = x_data[leftIdx - 1];
    if (x_data[extremumIdx] < cmpIdx) {
      x_data[extremumIdx] = cmpIdx;
      x_data[leftIdx - 1] = extremum;
    }
  }
}

void b_heapsort(const emlrtStack *sp, int32_T x_data[], int32_T xstart,
                int32_T xend)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T idx;
  int32_T k;
  int32_T n;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  n = xend - xstart;
  for (idx = n + 1; idx >= 1; idx--) {
    heapify(x_data, idx, xstart, xend);
  }
  st.site = &jh_emlrtRSI;
  if (n > 2147483646) {
    b_st.site = &s_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (k = 0; k < n; k++) {
    int32_T t;
    idx = (xend - k) - 1;
    t = x_data[idx];
    x_data[idx] = x_data[xstart - 1];
    x_data[xstart - 1] = t;
    heapify(x_data, 1, xstart, idx);
  }
}

/* End of code generation (heapsort.c) */
