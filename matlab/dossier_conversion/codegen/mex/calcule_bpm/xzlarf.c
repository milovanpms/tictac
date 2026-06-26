/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzlarf.c
 *
 * Code generation for function 'xzlarf'
 *
 */

/* Include files */
#include "xzlarf.h"
#include "calcule_bpm_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo sd_emlrtRSI = {
    50,       /* lineNo */
    "xzlarf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarf.m" /* pathName */
};

static emlrtRSInfo td_emlrtRSI = {
    68,       /* lineNo */
    "xzlarf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarf.m" /* pathName */
};

static emlrtRSInfo ud_emlrtRSI = {
    75,       /* lineNo */
    "xzlarf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarf.m" /* pathName */
};

static emlrtRSInfo vd_emlrtRSI = {
    103,      /* lineNo */
    "ilazlc", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarf.m" /* pathName */
};

static emlrtRSInfo wd_emlrtRSI = {
    74,      /* lineNo */
    "xgemv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgemv.m" /* pathName */
};

/* Function Declarations */
static int32_T div_nde_s32_floor(int32_T numerator);

/* Function Definitions */
static int32_T div_nde_s32_floor(int32_T numerator)
{
  int32_T quotient;
  if ((numerator < 0) && (numerator % 6 != 0)) {
    quotient = -1;
  } else {
    quotient = 0;
  }
  quotient += numerator / 6;
  return quotient;
}

void xzlarf(const emlrtStack *sp, int32_T m, int32_T n, int32_T iv0, real_T tau,
            real_T C[36], int32_T ic0, real_T work[6])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  int32_T colbottom;
  int32_T i;
  int32_T iac;
  int32_T lastc;
  int32_T lastv;
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
  if (tau != 0.0) {
    boolean_T exitg2;
    lastv = m - 1;
    i = iv0 + m;
    while ((lastv + 1 > 0) && (C[i - 2] == 0.0)) {
      lastv--;
      i--;
    }
    st.site = &sd_emlrtRSI;
    lastc = n;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      int32_T exitg1;
      i = ic0 + (lastc - 1) * 6;
      colbottom = i + lastv;
      b_st.site = &vd_emlrtRSI;
      if ((i <= colbottom) && (colbottom > 2147483646)) {
        c_st.site = &s_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      do {
        exitg1 = 0;
        if (i <= colbottom) {
          if (C[i - 1] != 0.0) {
            exitg1 = 1;
          } else {
            i++;
          }
        } else {
          lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);
      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    lastv = -1;
    lastc = 0;
  }
  if (lastv + 1 > 0) {
    real_T c;
    int32_T b_i;
    st.site = &td_emlrtRSI;
    b_st.site = &od_emlrtRSI;
    if (lastc != 0) {
      c_st.site = &qd_emlrtRSI;
      if (lastc > 2147483646) {
        d_st.site = &s_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      b_i = (uint8_T)lastc;
      memset(&work[0], 0, (uint32_T)b_i * sizeof(real_T));
      b_i = ic0 + 6 * (lastc - 1);
      for (iac = ic0; iac <= b_i; iac += 6) {
        c = 0.0;
        colbottom = iac + lastv;
        c_st.site = &wd_emlrtRSI;
        if ((iac <= colbottom) && (colbottom > 2147483646)) {
          d_st.site = &s_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }
        for (i = iac; i <= colbottom; i++) {
          c += C[i - 1] * C[((iv0 + i) - iac) - 1];
        }
        i = div_nde_s32_floor(iac - ic0);
        work[i] += c;
      }
    }
    st.site = &ud_emlrtRSI;
    b_st.site = &rd_emlrtRSI;
    c_st.site = &qb_emlrtRSI;
    d_st.site = &rb_emlrtRSI;
    if (!(-tau == 0.0)) {
      i = ic0;
      e_st.site = &sb_emlrtRSI;
      b_i = (uint8_T)lastc;
      for (lastc = 0; lastc < b_i; lastc++) {
        c = work[lastc];
        if (c != 0.0) {
          c *= -tau;
          colbottom = lastv + i;
          e_st.site = &tb_emlrtRSI;
          if ((i <= colbottom) && (colbottom > 2147483646)) {
            f_st.site = &s_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }
          for (iac = i; iac <= colbottom; iac++) {
            C[iac - 1] += C[((iv0 + iac) - i) - 1] * c;
          }
        }
        i += 6;
      }
    }
  }
}

/* End of code generation (xzlarf.c) */
