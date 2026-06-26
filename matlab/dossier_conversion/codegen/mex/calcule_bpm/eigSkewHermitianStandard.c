/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eigSkewHermitianStandard.c
 *
 * Code generation for function 'eigSkewHermitianStandard'
 *
 */

/* Include files */
#include "eigSkewHermitianStandard.h"
#include "anyNonFinite.h"
#include "calcule_bpm_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "xhseqr.h"
#include "xnrm2.h"
#include "xscal.h"
#include "xzlarf.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo qc_emlrtRSI = {
    20,        /* lineNo */
    "xzlarfg", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarfg.m" /* pathName */
};

static emlrtRSInfo rc_emlrtRSI = {
    41,        /* lineNo */
    "xzlarfg", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarfg.m" /* pathName */
};

static emlrtRSInfo sc_emlrtRSI = {
    53,        /* lineNo */
    "xzlarfg", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarfg.m" /* pathName */
};

static emlrtRSInfo tc_emlrtRSI = {
    68,        /* lineNo */
    "xzlarfg", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarfg.m" /* pathName */
};

static emlrtRSInfo uc_emlrtRSI = {
    71,        /* lineNo */
    "xzlarfg", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarfg.m" /* pathName */
};

static emlrtRSInfo vc_emlrtRSI = {
    81,        /* lineNo */
    "xzlarfg", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarfg.m" /* pathName */
};

static emlrtRSInfo cd_emlrtRSI = {
    10,                         /* lineNo */
    "eigSkewHermitianStandard", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eigSkew"
    "HermitianStandard.m" /* pathName */
};

static emlrtRSInfo dd_emlrtRSI = {
    19,                             /* lineNo */
    "eigRealSkewSymmetricStandard", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eigReal"
    "SkewSymmetricStandard.m" /* pathName */
};

static emlrtRSInfo ed_emlrtRSI = {
    35,      /* lineNo */
    "schur", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m" /* pathName
                                                                         */
};

static emlrtRSInfo fd_emlrtRSI = {
    52,      /* lineNo */
    "schur", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m" /* pathName
                                                                         */
};

static emlrtRSInfo gd_emlrtRSI = {
    54,      /* lineNo */
    "schur", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m" /* pathName
                                                                         */
};

static emlrtRSInfo hd_emlrtRSI = {
    83,      /* lineNo */
    "schur", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m" /* pathName
                                                                         */
};

static emlrtRSInfo id_emlrtRSI = {
    18,       /* lineNo */
    "xgehrd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgehrd.m" /* pathName */
};

static emlrtRSInfo jd_emlrtRSI = {
    46,        /* lineNo */
    "xzgehrd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgehrd.m" /* pathName */
};

static emlrtRSInfo kd_emlrtRSI = {
    50,        /* lineNo */
    "xzgehrd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgehrd.m" /* pathName */
};

static emlrtRSInfo ld_emlrtRSI = {
    58,        /* lineNo */
    "xzgehrd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgehrd.m" /* pathName */
};

static emlrtRSInfo md_emlrtRSI = {
    84,       /* lineNo */
    "xzlarf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarf.m" /* pathName */
};

static emlrtRSInfo nd_emlrtRSI = {
    91,       /* lineNo */
    "xzlarf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarf.m" /* pathName */
};

static emlrtRSInfo pd_emlrtRSI = {
    58,      /* lineNo */
    "xgemv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgemv.m" /* pathName */
};

/* Function Definitions */
void eigSkewHermitianStandard(const emlrtStack *sp, const real_T A[36],
                              creal_T V[6])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
  emlrtStack k_st;
  emlrtStack st;
  real_T T[36];
  real_T work[6];
  real_T xnorm;
  int32_T exitg1;
  int32_T i;
  int32_T ia;
  int32_T j;
  int32_T k;
  int32_T vectorUB;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &cd_emlrtRSI;
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
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  k_st.prev = &j_st;
  k_st.tls = j_st.tls;
  b_st.site = &dd_emlrtRSI;
  memcpy(&T[0], &A[0], 36U * sizeof(real_T));
  c_st.site = &ed_emlrtRSI;
  if (anyNonFinite(A)) {
    int32_T b_i;
    for (j = 0; j < 36; j++) {
      T[j] = rtNaN;
    }
    b_i = 2;
    for (j = 0; j < 5; j++) {
      if (b_i <= 6) {
        memset(&T[(j * 6 + b_i) + -1], 0,
               (uint32_T)(-b_i + 7) * sizeof(real_T));
      }
      b_i++;
    }
  } else {
    real_T tau[5];
    int32_T b_i;
    c_st.site = &fd_emlrtRSI;
    d_st.site = &id_emlrtRSI;
    for (i = 0; i < 6; i++) {
      work[i] = 0.0;
    }
    for (i = 0; i < 5; i++) {
      __m128d r;
      real_T alpha1_tmp;
      int32_T alpha1_tmp_tmp;
      int32_T in;
      int32_T knt;
      int32_T lastc;
      int32_T lastv;
      int32_T scalarLB;
      in = (i + 1) * 6;
      alpha1_tmp_tmp = (i + 6 * i) + 1;
      alpha1_tmp = T[alpha1_tmp_tmp];
      b_i = i + 3;
      b_i = muIntScalarMin_sint32(b_i, 6) + i * 6;
      e_st.site = &jd_emlrtRSI;
      tau[i] = 0.0;
      f_st.site = &qc_emlrtRSI;
      xnorm = xnrm2(&f_st, 4 - i, T, b_i);
      if (xnorm != 0.0) {
        xnorm = muDoubleScalarHypot(alpha1_tmp, xnorm);
        if (alpha1_tmp >= 0.0) {
          xnorm = -xnorm;
        }
        if (muDoubleScalarAbs(xnorm) < 1.0020841800044864E-292) {
          knt = 0;
          j = (b_i - i) + 3;
          do {
            knt++;
            f_st.site = &rc_emlrtRSI;
            g_st.site = &yc_emlrtRSI;
            h_st.site = &ad_emlrtRSI;
            scalarLB = ((((j - b_i) + 1) / 2) << 1) + b_i;
            vectorUB = scalarLB - 2;
            for (k = b_i; k <= vectorUB; k += 2) {
              r = _mm_loadu_pd(&T[k - 1]);
              _mm_storeu_pd(&T[k - 1],
                            _mm_mul_pd(_mm_set1_pd(9.9792015476736E+291), r));
            }
            for (k = scalarLB; k <= j; k++) {
              T[k - 1] *= 9.9792015476736E+291;
            }
            xnorm *= 9.9792015476736E+291;
            alpha1_tmp *= 9.9792015476736E+291;
          } while ((muDoubleScalarAbs(xnorm) < 1.0020841800044864E-292) &&
                   (knt < 20));
          f_st.site = &sc_emlrtRSI;
          xnorm = xnrm2(&f_st, 4 - i, T, b_i);
          xnorm = muDoubleScalarHypot(alpha1_tmp, xnorm);
          if (alpha1_tmp >= 0.0) {
            xnorm = -xnorm;
          }
          tau[i] = (xnorm - alpha1_tmp) / xnorm;
          f_st.site = &tc_emlrtRSI;
          xscal(&f_st, 4 - i, 1.0 / (alpha1_tmp - xnorm), T, b_i);
          f_st.site = &uc_emlrtRSI;
          for (k = 0; k < knt; k++) {
            xnorm *= 1.0020841800044864E-292;
          }
          alpha1_tmp = xnorm;
        } else {
          tau[i] = (xnorm - alpha1_tmp) / xnorm;
          f_st.site = &vc_emlrtRSI;
          xscal(&f_st, 4 - i, 1.0 / (alpha1_tmp - xnorm), T, b_i);
          alpha1_tmp = xnorm;
        }
      }
      T[alpha1_tmp_tmp] = 1.0;
      scalarLB = in + 1;
      e_st.site = &kd_emlrtRSI;
      if (tau[i] != 0.0) {
        boolean_T exitg2;
        lastv = 4 - i;
        b_i = (alpha1_tmp_tmp - i) + 4;
        while ((lastv + 1 > 0) && (T[b_i] == 0.0)) {
          lastv--;
          b_i--;
        }
        lastc = 6;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          b_i = in + lastc;
          ia = b_i;
          do {
            exitg1 = 0;
            if (ia <= b_i + lastv * 6) {
              if (T[ia - 1] != 0.0) {
                exitg1 = 1;
              } else {
                ia += 6;
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
        f_st.site = &md_emlrtRSI;
        g_st.site = &od_emlrtRSI;
        if (lastc != 0) {
          h_st.site = &qd_emlrtRSI;
          memset(&work[0], 0, (uint32_T)lastc * sizeof(real_T));
          b_i = alpha1_tmp_tmp;
          j = (in + 6 * lastv) + 1;
          for (vectorUB = scalarLB; vectorUB <= j; vectorUB += 6) {
            knt = vectorUB + lastc;
            h_st.site = &pd_emlrtRSI;
            for (ia = vectorUB; ia < knt; ia++) {
              k = ia - vectorUB;
              work[k] += T[ia - 1] * T[b_i];
            }
            b_i++;
          }
        }
        f_st.site = &nd_emlrtRSI;
        g_st.site = &rd_emlrtRSI;
        h_st.site = &qb_emlrtRSI;
        i_st.site = &rb_emlrtRSI;
        if (!(-tau[i] == 0.0)) {
          b_i = in;
          j_st.site = &sb_emlrtRSI;
          for (j = 0; j <= lastv; j++) {
            xnorm = T[alpha1_tmp_tmp + j];
            if (xnorm != 0.0) {
              xnorm *= -tau[i];
              knt = b_i + 1;
              k = lastc + b_i;
              j_st.site = &tb_emlrtRSI;
              if ((b_i + 1 <= k) && (k > 2147483646)) {
                k_st.site = &s_emlrtRSI;
                check_forloop_overflow_error(&k_st);
              }
              scalarLB = ((((k - b_i) / 2) << 1) + b_i) + 1;
              vectorUB = scalarLB - 2;
              for (ia = knt; ia <= vectorUB; ia += 2) {
                __m128d r1;
                r = _mm_loadu_pd(&work[(ia - b_i) - 1]);
                r1 = _mm_loadu_pd(&T[ia - 1]);
                _mm_storeu_pd(
                    &T[ia - 1],
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(xnorm))));
              }
              for (ia = scalarLB; ia <= k; ia++) {
                T[ia - 1] += work[(ia - b_i) - 1] * xnorm;
              }
            }
            b_i += 6;
          }
        }
      }
      e_st.site = &ld_emlrtRSI;
      xzlarf(&e_st, 5 - i, 5 - i, alpha1_tmp_tmp + 1, tau[i], T, (i + in) + 2,
             work);
      T[alpha1_tmp_tmp] = alpha1_tmp;
    }
    c_st.site = &gd_emlrtRSI;
    b_i = xhseqr(&c_st, T);
    if (b_i != 0) {
      c_st.site = &hd_emlrtRSI;
      c_warning(&c_st);
    }
  }
  i = 1;
  do {
    exitg1 = 0;
    if (i <= 6) {
      boolean_T guard1;
      guard1 = false;
      if (i != 6) {
        xnorm = T[i + 6 * (i - 1)];
        if (xnorm != 0.0) {
          xnorm = muDoubleScalarAbs(xnorm);
          V[i - 1].re = 0.0;
          V[i - 1].im = xnorm;
          V[i].re = 0.0;
          V[i].im = -xnorm;
          i += 2;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        V[i - 1].re = 0.0;
        V[i - 1].im = 0.0;
        i++;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

/* End of code generation (eigSkewHermitianStandard.c) */
