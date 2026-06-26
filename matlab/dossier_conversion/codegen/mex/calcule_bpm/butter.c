/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * butter.c
 *
 * Code generation for function 'butter'
 *
 */

/* Include files */
#include "butter.h"
#include "anyNonFinite.h"
#include "bilinear.h"
#include "calcule_bpm_data.h"
#include "eigSkewHermitianStandard.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "zp2ss.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo f_emlrtRSI = {
    20,       /* lineNo */
    "butter", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\butter.m" /* pathName
                                                                            */
};

static emlrtRSInfo g_emlrtRSI = {
    31,           /* lineNo */
    "butterImpl", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\butter.m" /* pathName
                                                                            */
};

static emlrtRSInfo h_emlrtRSI = {
    44,           /* lineNo */
    "butterImpl", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\butter.m" /* pathName
                                                                            */
};

static emlrtRSInfo i_emlrtRSI = {
    60,           /* lineNo */
    "butterImpl", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\butter.m" /* pathName
                                                                            */
};

static emlrtRSInfo j_emlrtRSI = {
    64,           /* lineNo */
    "butterImpl", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\butter.m" /* pathName
                                                                            */
};

static emlrtRSInfo k_emlrtRSI = {
    71,           /* lineNo */
    "butterImpl", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\butter.m" /* pathName
                                                                            */
};

static emlrtRSInfo l_emlrtRSI = {
    81,           /* lineNo */
    "butterImpl", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\butter.m" /* pathName
                                                                            */
};

static emlrtRSInfo m_emlrtRSI = {
    102,          /* lineNo */
    "butterImpl", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\butter.m" /* pathName
                                                                            */
};

static emlrtRSInfo n_emlrtRSI = {
    36,                          /* lineNo */
    "classicalIIRFiltersParser", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\+signal\\+internal\\+"
    "classicaliirfilters\\classicalIIRFiltersParser."
    "m" /* pathName */
};

static emlrtRSInfo u_emlrtRSI = {
    16,     /* lineNo */
    "poly", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\polyfun\\poly.m" /* pathName
                                                                         */
};

static emlrtRSInfo ab_emlrtRSI = {
    63,      /* lineNo */
    "lp2bp", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\lp2bp.m" /* pathName
                                                                           */
};

static emlrtRSInfo bb_emlrtRSI = {
    64,      /* lineNo */
    "lp2bp", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\lp2bp.m" /* pathName
                                                                           */
};

static emlrtRSInfo fc_emlrtRSI = {
    81,    /* lineNo */
    "eig", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m" /* pathName
                                                                       */
};

static emlrtRSInfo gc_emlrtRSI = {
    127,   /* lineNo */
    "eig", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m" /* pathName
                                                                       */
};

static emlrtRSInfo hc_emlrtRSI = {
    135,   /* lineNo */
    "eig", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m" /* pathName
                                                                       */
};

static emlrtRSInfo ic_emlrtRSI = {
    143,   /* lineNo */
    "eig", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m" /* pathName
                                                                       */
};

static emlrtRSInfo mc_emlrtRSI = {
    13,                     /* lineNo */
    "eigHermitianStandard", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eigHerm"
    "itianStandard.m" /* pathName */
};

static emlrtRSInfo nc_emlrtRSI = {
    40,                     /* lineNo */
    "eigHermitianStandard", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eigHerm"
    "itianStandard.m" /* pathName */
};

static emlrtRSInfo oc_emlrtRSI = {
    8,         /* lineNo */
    "xsyheev", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xsyheev.m" /* pathName */
};

static emlrtRSInfo pc_emlrtRSI = {
    61,              /* lineNo */
    "ceval_xsyheev", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xsyheev.m" /* pathName */
};

static emlrtRSInfo se_emlrtRSI = {
    34,            /* lineNo */
    "eigStandard", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eigStan"
    "dard.m" /* pathName */
};

static emlrtRSInfo te_emlrtRSI = {
    45,            /* lineNo */
    "eigStandard", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eigStan"
    "dard.m" /* pathName */
};

static emlrtRSInfo ue_emlrtRSI = {
    159,           /* lineNo */
    "ceval_xgeev", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeev.m" /* pathName */
};

static emlrtRSInfo ve_emlrtRSI = {
    42,      /* lineNo */
    "xgeev", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeev.m" /* pathName */
};

static emlrtRTEInfo emlrtRTEI = {
    138,                         /* lineNo */
    1,                           /* colNo */
    "classicalIIRFiltersParser", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\+signal\\+internal\\+"
    "classicaliirfilters\\classicalIIRFiltersParser."
    "m" /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = {
    14,                 /* lineNo */
    37,                 /* colNo */
    "validatepositive", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatepositive.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI = {
    40,            /* lineNo */
    9,             /* colNo */
    "vector_poly", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\polyfun\\poly.m" /* pName
                                                                         */
};

static emlrtRTEInfo f_emlrtRTEI = {
    45,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    48,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" /* pName */
};

/* Function Definitions */
void butter(const emlrtStack *sp, const real_T Wn[2], real_T varargout_1[7],
            real_T varargout_2[7])
{
  static const char_T b_fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                     '_', 'd', 'g', 'e', 'e', 'v', 'x'};
  static const char_T fname[13] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                   '_', 'd', 's', 'y', 'e', 'v'};
  static const int8_T b_iv[18] = {-1, 0, 0, 0, -1, 0, 0, 0, -1,
                                  0,  0, 0, 0, 0,  0, 0, 0, 0};
  static const int8_T b_iv1[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  static const int8_T b_b[7] = {1, 0, -3, 0, 3, 0, -1};
  static const int8_T b_iv2[6] = {1, 1, 1, -1, -1, -1};
  ptrdiff_t ihi_t;
  ptrdiff_t ilo_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  creal_T c_c[7];
  creal_T b_p[6];
  creal_T x[6];
  real_T A[36];
  real_T b_Wn1[36];
  real_T a[9];
  real_T b_c[6];
  real_T scale[6];
  real_T wimag[6];
  real_T wreal[6];
  real_T b[3];
  real_T c[3];
  real_T Wn1;
  real_T q;
  real_T rconde;
  real_T rcondv;
  real_T u_idx_0;
  real_T u_idx_1;
  real_T x_re;
  int32_T Wn1_tmp;
  int32_T j;
  int32_T k;
  boolean_T varargin_1[2];
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &f_emlrtRSI;
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
  b_st.site = &g_emlrtRSI;
  c_st.site = &n_emlrtRSI;
  d_st.site = &o_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(Wn[k] <= 0.0)) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &c_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:butter:expectedPositive", 3, 4, 2, "Wn");
  }
  d_st.site = &o_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(Wn[k])) && (!muDoubleScalarIsNaN(Wn[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:butter:expectedFinite", 3, 4, 2, "Wn");
  }
  varargin_1[0] = (Wn[0] >= 1.0);
  varargin_1[1] = (Wn[1] >= 1.0);
  p = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (varargin_1[k]) {
      p = true;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &emlrtRTEI,
        "signal:classicaliirfilters:freqMustBeWithinUnitInterval",
        "signal:classicaliirfilters:freqMustBeWithinUnitInterval", 0);
  }
  u_idx_0 = 4.0 * muDoubleScalarTan(3.1415926535897931 * Wn[0] / 2.0);
  u_idx_1 = 4.0 * muDoubleScalarTan(3.1415926535897931 * Wn[1] / 2.0);
  b_st.site = &h_emlrtRSI;
  zp2ss(&b_st, a, b, c);
  q = u_idx_1 - u_idx_0;
  b_st.site = &i_emlrtRSI;
  Wn1 = u_idx_0 * u_idx_1;
  if (Wn1 < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &b_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  Wn1 = muDoubleScalarSqrt(Wn1);
  b_st.site = &j_emlrtRSI;
  c_st.site = &ab_emlrtRSI;
  d_st.site = &o_emlrtRSI;
  if (muDoubleScalarIsInf(Wn1) || muDoubleScalarIsNaN(Wn1)) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:lp2bp:expectedFinite", 3, 4, 19, "input number 5, Wo,");
  }
  c_st.site = &bb_emlrtRSI;
  d_st.site = &o_emlrtRSI;
  if (muDoubleScalarIsInf(q) || muDoubleScalarIsNaN(q)) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:lp2bp:expectedFinite", 3, 4, 19, "input number 6, Bw,");
  }
  q = Wn1 / q;
  for (j = 0; j < 3; j++) {
    b_Wn1[6 * j] = Wn1 * (a[3 * j] / q);
    k = 6 * (j + 3);
    b_Wn1[k] = Wn1 * (real_T)b_iv1[3 * j];
    Wn1_tmp = 3 * j + 1;
    b_Wn1[6 * j + 1] = Wn1 * (a[Wn1_tmp] / q);
    b_Wn1[k + 1] = Wn1 * (real_T)b_iv1[Wn1_tmp];
    Wn1_tmp = 3 * j + 2;
    b_Wn1[6 * j + 2] = Wn1 * (a[Wn1_tmp] / q);
    b_Wn1[k + 2] = Wn1 * (real_T)b_iv1[Wn1_tmp];
  }
  for (j = 0; j < 6; j++) {
    b_Wn1[6 * j + 3] = Wn1 * (real_T)b_iv[3 * j];
    b_Wn1[6 * j + 4] = Wn1 * (real_T)b_iv[3 * j + 1];
    b_Wn1[6 * j + 5] = Wn1 * (real_T)b_iv[3 * j + 2];
  }
  __m128d r;
  r = _mm_loadu_pd(&b[0]);
  _mm_storeu_pd(&wimag[0],
                _mm_mul_pd(_mm_set1_pd(Wn1), _mm_div_pd(r, _mm_set1_pd(q))));
  _mm_storeu_pd(&wimag[3], _mm_set1_pd(Wn1 * 0.0));
  r = _mm_loadu_pd(&c[0]);
  _mm_storeu_pd(&b_c[0], r);
  _mm_storeu_pd(&b_c[3], _mm_set1_pd(0.0));
  wimag[2] = Wn1 * (b[2] / q);
  wimag[5] = Wn1 * 0.0;
  b_c[2] = c[2];
  b_c[5] = 0.0;
  b_st.site = &k_emlrtRSI;
  bilinear(&b_st, b_Wn1, wimag, b_c, A, scale, wreal);
  b_st.site = &l_emlrtRSI;
  c_st.site = &fc_emlrtRSI;
  if (anyNonFinite(A)) {
    for (Wn1_tmp = 0; Wn1_tmp < 6; Wn1_tmp++) {
      b_p[Wn1_tmp].re = rtNaN;
      b_p[Wn1_tmp].im = 0.0;
    }
  } else {
    int32_T exitg2;
    p = true;
    j = 0;
    exitg1 = false;
    while ((!exitg1) && (j < 6)) {
      Wn1_tmp = 0;
      do {
        exitg2 = 0;
        if (Wn1_tmp <= j) {
          if (!(A[Wn1_tmp + 6 * j] == A[j + 6 * Wn1_tmp])) {
            p = false;
            exitg2 = 1;
          } else {
            Wn1_tmp++;
          }
        } else {
          j++;
          exitg2 = 2;
        }
      } while (exitg2 == 0);
      if (exitg2 == 1) {
        exitg1 = true;
      }
    }
    if (p) {
      ptrdiff_t info_t;
      c_st.site = &gc_emlrtRSI;
      d_st.site = &mc_emlrtRSI;
      e_st.site = &oc_emlrtRSI;
      ilo_t = (ptrdiff_t)6;
      info_t = LAPACKE_dsyev(102, 'N', 'L', ilo_t, &A[0], ilo_t, &scale[0]);
      f_st.site = &pc_emlrtRSI;
      if ((int32_T)info_t < 0) {
        if ((int32_T)info_t == -1010) {
          emlrtErrorWithMessageIdR2018a(&f_st, &f_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&f_st, &g_emlrtRTEI,
                                        "Coder:toolbox:LAPACKCallErrorInfo",
                                        "Coder:toolbox:LAPACKCallErrorInfo", 5,
                                        4, 13, &fname[0], 12, (int32_T)info_t);
        }
      }
      for (Wn1_tmp = 0; Wn1_tmp < 6; Wn1_tmp++) {
        b_p[Wn1_tmp].re = scale[Wn1_tmp];
        b_p[Wn1_tmp].im = 0.0;
      }
      if ((int32_T)info_t != 0) {
        d_st.site = &nc_emlrtRSI;
        b_warning(&d_st);
      }
    } else {
      p = true;
      j = 0;
      exitg1 = false;
      while ((!exitg1) && (j < 6)) {
        Wn1_tmp = 0;
        do {
          exitg2 = 0;
          if (Wn1_tmp <= j) {
            if (!(A[Wn1_tmp + 6 * j] == -A[j + 6 * Wn1_tmp])) {
              p = false;
              exitg2 = 1;
            } else {
              Wn1_tmp++;
            }
          } else {
            j++;
            exitg2 = 2;
          }
        } while (exitg2 == 0);
        if (exitg2 == 1) {
          exitg1 = true;
        }
      }
      if (p) {
        c_st.site = &hc_emlrtRSI;
        eigSkewHermitianStandard(&c_st, A, b_p);
      } else {
        ptrdiff_t info_t;
        c_st.site = &ic_emlrtRSI;
        d_st.site = &se_emlrtRSI;
        e_st.site = &ve_emlrtRSI;
        info_t = LAPACKE_dgeevx(102, 'B', 'N', 'N', 'N', (ptrdiff_t)6, &A[0],
                                (ptrdiff_t)6, &wreal[0], &wimag[0], &q,
                                (ptrdiff_t)1, &u_idx_0, (ptrdiff_t)1, &ilo_t,
                                &ihi_t, &scale[0], &u_idx_1, &rconde, &rcondv);
        f_st.site = &ue_emlrtRSI;
        if ((int32_T)info_t < 0) {
          if ((int32_T)info_t == -1010) {
            emlrtErrorWithMessageIdR2018a(&f_st, &f_emlrtRTEI, "MATLAB:nomem",
                                          "MATLAB:nomem", 0);
          } else {
            emlrtErrorWithMessageIdR2018a(
                &f_st, &g_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
                "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &b_fname[0], 12,
                (int32_T)info_t);
          }
        }
        for (Wn1_tmp = 0; Wn1_tmp < 6; Wn1_tmp++) {
          b_p[Wn1_tmp].re = wreal[Wn1_tmp];
          b_p[Wn1_tmp].im = wimag[Wn1_tmp];
        }
        if ((int32_T)info_t != 0) {
          d_st.site = &te_emlrtRSI;
          b_warning(&d_st);
        }
      }
    }
  }
  q = 2.0 * muDoubleScalarAtan2(Wn1, 4.0);
  if (q * 0.0 == 0.0) {
    Wn1 = muDoubleScalarCos(q);
    u_idx_1 = muDoubleScalarSin(q);
  } else if (q == 0.0) {
    Wn1 = rtNaN;
    u_idx_1 = 0.0;
  } else {
    Wn1 = rtNaN;
    u_idx_1 = rtNaN;
  }
  for (Wn1_tmp = 0; Wn1_tmp < 6; Wn1_tmp++) {
    x[Wn1_tmp].re = Wn1 - b_p[Wn1_tmp].re;
    x[Wn1_tmp].im = u_idx_1 - b_p[Wn1_tmp].im;
  }
  x_re = x[0].re;
  rconde = x[0].im;
  for (k = 0; k < 5; k++) {
    u_idx_0 = x[k + 1].im;
    rcondv = x[k + 1].re;
    q = x_re * rcondv - rconde * u_idx_0;
    rconde = x_re * u_idx_0 + rconde * rcondv;
    x_re = q;
  }
  for (Wn1_tmp = 0; Wn1_tmp < 6; Wn1_tmp++) {
    x[Wn1_tmp].re = Wn1 - (real_T)b_iv2[Wn1_tmp];
    x[Wn1_tmp].im = u_idx_1;
  }
  Wn1 = x[0].re;
  u_idx_1 = x[0].im;
  for (k = 0; k < 5; k++) {
    u_idx_0 = x[k + 1].im;
    rcondv = x[k + 1].re;
    q = Wn1 * rcondv - u_idx_1 * u_idx_0;
    u_idx_1 = Wn1 * u_idx_0 + u_idx_1 * rcondv;
    Wn1 = q;
  }
  if (u_idx_1 == 0.0) {
    if (rconde == 0.0) {
      x_re /= Wn1;
    } else if (x_re == 0.0) {
      x_re = 0.0;
    } else {
      x_re /= Wn1;
    }
  } else if (Wn1 == 0.0) {
    if (x_re == 0.0) {
      x_re = rconde / u_idx_1;
    } else if (rconde == 0.0) {
      x_re = 0.0;
    } else {
      x_re = rconde / u_idx_1;
    }
  } else {
    q = muDoubleScalarAbs(Wn1);
    u_idx_0 = muDoubleScalarAbs(u_idx_1);
    if (q > u_idx_0) {
      q = u_idx_1 / Wn1;
      x_re = (x_re + q * rconde) / (Wn1 + q * u_idx_1);
    } else if (u_idx_0 == q) {
      if (Wn1 > 0.0) {
        Wn1 = 0.5;
      } else {
        Wn1 = -0.5;
      }
      if (u_idx_1 > 0.0) {
        u_idx_0 = 0.5;
      } else {
        u_idx_0 = -0.5;
      }
      x_re = (x_re * Wn1 + rconde * u_idx_0) / q;
    } else {
      q = Wn1 / u_idx_1;
      x_re = (q * x_re + rconde) / (u_idx_1 + q * Wn1);
    }
  }
  b_st.site = &m_emlrtRSI;
  c_st.site = &u_emlrtRSI;
  for (j = 0; j < 6; j++) {
    q = b_p[j].re;
    u_idx_0 = b_p[j].im;
    if (muDoubleScalarIsInf(q) || muDoubleScalarIsInf(u_idx_0) ||
        (muDoubleScalarIsNaN(q) || muDoubleScalarIsNaN(u_idx_0))) {
      emlrtErrorWithMessageIdR2018a(
          &c_st, &e_emlrtRTEI, "Coder:toolbox:nonfiniteValuesNotSupported",
          "Coder:toolbox:nonfiniteValuesNotSupported", 0);
    }
  }
  c_c[0].re = 1.0;
  c_c[0].im = 0.0;
  for (j = 0; j < 6; j++) {
    u_idx_1 = b_p[j].re;
    rconde = b_p[j].im;
    u_idx_0 = c_c[j].im;
    rcondv = c_c[j].re;
    c_c[j + 1].re = -u_idx_1 * rcondv - -rconde * u_idx_0;
    c_c[j + 1].im = -u_idx_1 * u_idx_0 + -rconde * rcondv;
    for (k = j + 1; k >= 2; k--) {
      q = c_c[k - 2].im;
      u_idx_0 = c_c[k - 2].re;
      c_c[k - 1].re -= u_idx_1 * u_idx_0 - rconde * q;
      c_c[k - 1].im -= u_idx_1 * q + rconde * u_idx_0;
    }
  }
  for (j = 0; j < 7; j++) {
    varargout_2[j] = c_c[j].re;
    varargout_1[j] = x_re * (real_T)b_b[j];
  }
}

/* End of code generation (butter.c) */
