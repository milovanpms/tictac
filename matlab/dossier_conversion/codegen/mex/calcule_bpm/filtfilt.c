/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * filtfilt.c
 *
 * Code generation for function 'filtfilt'
 *
 */

/* Include files */
#include "filtfilt.h"
#include "calcule_bpm_data.h"
#include "calcule_bpm_emxutil.h"
#include "calcule_bpm_types.h"
#include "filter.h"
#include "indexShapeCheck.h"
#include "introsort.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "cs.h"
#include "makeCXSparseMatrix.h"
#include "mwmathutil.h"
#include "solve_from_lu.h"
#include "solve_from_qr.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo
    we_emlrtRSI =
        {
            123,        /* lineNo */
            "filtfilt", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    xe_emlrtRSI =
        {
            150,        /* lineNo */
            "filtfilt", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    ye_emlrtRSI =
        {
            505,              /* lineNo */
            "filtfiltParser", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    af_emlrtRSI =
        {
            579,                     /* lineNo */
            "validateAndCastInputs", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    bf_emlrtRSI =
        {
            582,                     /* lineNo */
            "validateAndCastInputs", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    cf_emlrtRSI =
        {
            584,                     /* lineNo */
            "validateAndCastInputs", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    df_emlrtRSI =
        {
            174,            /* lineNo */
            "filtfiltImpl", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    ef_emlrtRSI =
        {
            179,            /* lineNo */
            "filtfiltImpl", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    ff_emlrtRSI =
        {
            261,                             /* lineNo */
            "getCoeffsAndInitialConditions", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo gf_emlrtRSI = {
    13,       /* lineNo */
    "sparse", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m" /* pathName
                                                                           */
};

static emlrtRSInfo hf_emlrtRSI = {
    219,             /* lineNo */
    "sparse/sparse", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pathName */
};

static emlrtRSInfo jf_emlrtRSI = {
    1450,              /* lineNo */
    "sparse/mldivide", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pathName */
};

static emlrtRSInfo kf_emlrtRSI =
    {
        160,                         /* lineNo */
        "CXSparseAPI/iteratedSolve", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" /* pathName */
};

static emlrtRSInfo mf_emlrtRSI =
    {
        312,                      /* lineNo */
        "CXSparseAPI/iteratedLU", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" /* pathName */
};

static emlrtRSInfo
    qf_emlrtRSI =
        {
            309,            /* lineNo */
            "ffOneChanCat", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    rf_emlrtRSI =
        {
            308,            /* lineNo */
            "ffOneChanCat", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    sf_emlrtRSI =
        {
            307,            /* lineNo */
            "ffOneChanCat", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtECInfo
    b_emlrtECI =
        {
            -1,             /* nDims */
            304,            /* lineNo */
            5,              /* colNo */
            "ffOneChanCat", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pName
                                                                          */
};

static emlrtBCInfo emlrtBCI =
    {
        -1,             /* iFirst */
        -1,             /* iLast */
        308,            /* lineNo */
        19,             /* colNo */
        "",             /* aName */
        "ffOneChanCat", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo b_emlrtBCI =
    {
        -1,             /* iFirst */
        -1,             /* iLast */
        312,            /* lineNo */
        21,             /* colNo */
        "",             /* aName */
        "ffOneChanCat", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtECInfo
    c_emlrtECI =
        {
            -1,             /* nDims */
            312,            /* lineNo */
            5,              /* colNo */
            "ffOneChanCat", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pName
                                                                          */
};

static emlrtRTEInfo
    h_emlrtRTEI =
        {
            159,            /* lineNo */
            1,              /* colNo */
            "filtfiltImpl", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pName
                                                                          */
};

static emlrtRTEInfo x_emlrtRTEI = {
    13,       /* lineNo */
    1,        /* colNo */
    "sparse", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m" /* pName
                                                                           */
};

static emlrtRTEInfo
    y_emlrtRTEI =
        {
            261,        /* lineNo */
            19,         /* colNo */
            "filtfilt", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pName
                                                                          */
};

/* Function Declarations */
static int32_T findEffectiveFilterLen(real_T coef[7], real_T effLen_data[]);

/* Function Definitions */
static int32_T findEffectiveFilterLen(real_T coef[7], real_T effLen_data[])
{
  real_T varargin_1[7];
  real_T maxCoef;
  int32_T effLen_size;
  int32_T idx;
  int32_T ii;
  int32_T k;
  int8_T ii_data;
  boolean_T x[7];
  boolean_T exitg1;
  for (k = 0; k < 7; k++) {
    varargin_1[k] = muDoubleScalarAbs(coef[k]);
  }
  if (!muDoubleScalarIsNaN(varargin_1[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!muDoubleScalarIsNaN(varargin_1[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    maxCoef = varargin_1[0];
  } else {
    maxCoef = varargin_1[idx - 1];
    ii = idx + 1;
    for (k = ii; k < 8; k++) {
      real_T d;
      d = varargin_1[k - 1];
      if (maxCoef < d) {
        maxCoef = d;
      }
    }
  }
  if (maxCoef != 0.0) {
    __m128d r;
    __m128d r1;
    r = _mm_loadu_pd(&coef[0]);
    r1 = _mm_set1_pd(maxCoef);
    _mm_storeu_pd(&coef[0], _mm_div_pd(r, r1));
    r = _mm_loadu_pd(&coef[2]);
    _mm_storeu_pd(&coef[2], _mm_div_pd(r, r1));
    r = _mm_loadu_pd(&coef[4]);
    _mm_storeu_pd(&coef[4], _mm_div_pd(r, r1));
    coef[6] /= maxCoef;
  }
  for (ii = 0; ii < 7; ii++) {
    x[ii] = (coef[ii] != 0.0);
  }
  idx = 0;
  effLen_size = 1;
  ii = 7;
  exitg1 = false;
  while ((!exitg1) && (ii > 0)) {
    if (x[ii - 1]) {
      idx = 1;
      ii_data = (int8_T)ii;
      exitg1 = true;
    } else {
      ii--;
    }
  }
  if (idx == 0) {
    effLen_size = 0;
  }
  if (effLen_size - 1 >= 0) {
    effLen_data[0] = ii_data;
  }
  if (effLen_size == 0) {
    effLen_size = 1;
    effLen_data[0] = 0.0;
  }
  return effLen_size;
}

void filtfilt(const emlrtStack *sp, const real_T ctf[7],
              const real_T varargin_1[7], const real_T varargin_2[740],
              real_T y[740])
{
  __m128d r;
  __m128d r1;
  cs_di *cxA;
  cs_din *N;
  cs_dis *S;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_int32_T *y_colidx;
  emxArray_int32_T *y_rowidx;
  emxArray_real_T *y_d;
  real_T b_ytemp_data[776];
  real_T ytemp_data[776];
  real_T vals[16];
  real_T A[7];
  real_T B[7];
  real_T b_A[7];
  real_T b_B[7];
  real_T b_outBuff[6];
  real_T outBuff[6];
  real_T Letr;
  real_T tol;
  real_T val;
  real_T *y_d_data;
  int32_T sortedIndices[16];
  int32_T b_iv[2];
  int32_T c;
  int32_T cptr;
  int32_T currRowIdx;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T ridx;
  int32_T *y_colidx_data;
  int32_T *y_rowidx_data;
  int8_T cidxInt[16];
  int8_T ridxInt[16];
  boolean_T exitg1;
  boolean_T p;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &we_emlrtRSI;
  b_st.site = &ye_emlrtRSI;
  c_st.site = &af_emlrtRSI;
  d_st.site = &o_emlrtRSI;
  p = true;
  cptr = 0;
  exitg1 = false;
  while ((!exitg1) && (cptr < 740)) {
    if ((!muDoubleScalarIsInf(varargin_2[cptr])) &&
        (!muDoubleScalarIsNaN(varargin_2[cptr]))) {
      cptr++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:filtfilt:expectedFinite", 3, 4, 12, "input signal");
  }
  c_st.site = &bf_emlrtRSI;
  d_st.site = &o_emlrtRSI;
  p = true;
  cptr = 0;
  exitg1 = false;
  while ((!exitg1) && (cptr < 7)) {
    if ((!muDoubleScalarIsInf(ctf[cptr])) &&
        (!muDoubleScalarIsNaN(ctf[cptr]))) {
      cptr++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:filtfilt:expectedFinite", 3, 4, 36,
        "input number 1, filter coefficients,");
  }
  c_st.site = &cf_emlrtRSI;
  d_st.site = &o_emlrtRSI;
  p = true;
  cptr = 0;
  exitg1 = false;
  while ((!exitg1) && (cptr < 7)) {
    if ((!muDoubleScalarIsInf(varargin_1[cptr])) &&
        (!muDoubleScalarIsNaN(varargin_1[cptr]))) {
      cptr++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:filtfilt:expectedFinite", 3, 4, 36,
        "input number 2, filter coefficients,");
  }
  st.site = &xe_emlrtRSI;
  if (varargin_1[0] == 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &h_emlrtRTEI,
                                  "signal:filtfilt:ZeroA0Coeffs",
                                  "signal:filtfilt:ZeroA0Coeffs", 0);
  }
  b_st.site = &df_emlrtRSI;
  for (i = 0; i < 7; i++) {
    B[i] = ctf[i];
  }
  findEffectiveFilterLen(B, (real_T *)&val);
  for (i1 = 0; i1 < 7; i1++) {
    B[i1] = varargin_1[i1];
  }
  findEffectiveFilterLen(B, (real_T *)&tol);
  Letr = muDoubleScalarMax(1.0, 3.0 * (muDoubleScalarMax(val, tol) - 1.0));
  r = _mm_set1_pd(varargin_1[0]);
  _mm_storeu_pd(&B[0], _mm_div_pd(_mm_loadu_pd(&ctf[0]), r));
  _mm_storeu_pd(&A[0], _mm_div_pd(_mm_loadu_pd(&varargin_1[0]), r));
  _mm_storeu_pd(&B[2], _mm_div_pd(_mm_loadu_pd(&ctf[2]), r));
  _mm_storeu_pd(&A[2], _mm_div_pd(_mm_loadu_pd(&varargin_1[2]), r));
  _mm_storeu_pd(&B[4], _mm_div_pd(_mm_loadu_pd(&ctf[4]), r));
  _mm_storeu_pd(&A[4], _mm_div_pd(_mm_loadu_pd(&varargin_1[4]), r));
  B[6] = ctf[6] / varargin_1[0];
  A[6] = varargin_1[6] / varargin_1[0];
  vals[0] = A[1] + 1.0;
  for (c = 0; c < 5; c++) {
    vals[c + 1] = A[c + 2];
    vals[c + 6] = 1.0;
    vals[c + 11] = -1.0;
  }
  __m128d r2;
  __m128i r3;
  __m128i r4;
  r = _mm_loadu_pd(&A[1]);
  r1 = _mm_loadu_pd(&B[1]);
  r2 = _mm_set1_pd(B[0]);
  _mm_storeu_pd(&outBuff[0], _mm_sub_pd(r1, _mm_mul_pd(r2, r)));
  r = _mm_loadu_pd(&A[3]);
  r1 = _mm_loadu_pd(&B[3]);
  _mm_storeu_pd(&outBuff[2], _mm_sub_pd(r1, _mm_mul_pd(r2, r)));
  r = _mm_loadu_pd(&A[5]);
  r1 = _mm_loadu_pd(&B[5]);
  _mm_storeu_pd(&outBuff[4], _mm_sub_pd(r1, _mm_mul_pd(r2, r)));
  c_st.site = &ff_emlrtRSI;
  d_st.site = &gf_emlrtRSI;
  emxInit_real_T(&d_st, &y_d, &y_emlrtRTEI);
  emxInit_int32_T(&d_st, &y_colidx, &y_emlrtRTEI);
  emxInit_int32_T(&d_st, &y_rowidx, &y_emlrtRTEI);
  r3 = _mm_set1_epi32(1);
  r4 = _mm_loadu_si128((const __m128i *)&iv[0]);
  _mm_storeu_si128((__m128i *)&sortedIndices[0],
                   _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32(0), r4), r3));
  _mm_storeu_si128((__m128i *)&sortedIndices[4],
                   _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32(4), r4), r3));
  _mm_storeu_si128((__m128i *)&sortedIndices[8],
                   _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32(8), r4), r3));
  _mm_storeu_si128((__m128i *)&sortedIndices[12],
                   _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32(12), r4), r3));
  introsort(sortedIndices);
  c = y_d->size[0];
  y_d->size[0] = 16;
  emxEnsureCapacity_real_T(&d_st, y_d, c, &x_emlrtRTEI);
  y_d_data = y_d->data;
  for (cptr = 0; cptr < 16; cptr++) {
    c = sortedIndices[cptr];
    cidxInt[cptr] = iv1[c - 1];
    ridxInt[cptr] = iv2[c - 1];
    y_d_data[cptr] = 0.0;
  }
  c = y_colidx->size[0];
  y_colidx->size[0] = 7;
  emxEnsureCapacity_int32_T(&d_st, y_colidx, c, &x_emlrtRTEI);
  y_colidx_data = y_colidx->data;
  for (c = 0; c < 7; c++) {
    y_colidx_data[c] = 0;
  }
  y_colidx_data[0] = 1;
  c = y_rowidx->size[0];
  y_rowidx->size[0] = 16;
  emxEnsureCapacity_int32_T(&d_st, y_rowidx, c, &x_emlrtRTEI);
  y_rowidx_data = y_rowidx->data;
  for (c = 0; c < 16; c++) {
    y_rowidx_data[c] = 0;
  }
  cptr = 0;
  for (c = 0; c < 6; c++) {
    while ((cptr + 1 <= 16) && (cidxInt[cptr] == c + 1)) {
      y_rowidx_data[cptr] = ridxInt[cptr];
      cptr++;
    }
    y_colidx_data[c + 1] = cptr + 1;
  }
  for (cptr = 0; cptr < 16; cptr++) {
    y_d_data[cptr] = vals[sortedIndices[cptr] - 1];
  }
  e_st.site = &hf_emlrtRSI;
  cptr = 1;
  for (c = 0; c < 6; c++) {
    ridx = y_colidx_data[c];
    y_colidx_data[c] = cptr;
    while (ridx < y_colidx_data[c + 1]) {
      val = 0.0;
      currRowIdx = y_rowidx_data[ridx - 1];
      while ((ridx < y_colidx_data[c + 1]) &&
             (y_rowidx_data[ridx - 1] == currRowIdx)) {
        val += y_d_data[ridx - 1];
        ridx++;
      }
      if (val != 0.0) {
        y_d_data[cptr - 1] = val;
        y_rowidx_data[cptr - 1] = currRowIdx;
        cptr++;
      }
    }
  }
  y_colidx_data[6] = cptr;
  c_st.site = &ff_emlrtRSI;
  d_st.site = &jf_emlrtRSI;
  e_st.site = &kf_emlrtRSI;
  cxA = makeCXSparseMatrix(y_colidx_data[6] - 1, 6, 6, &y_colidx_data[0],
                           &y_rowidx_data[0], &y_d_data[0]);
  S = cs_di_sqr(2, cxA, 0);
  N = cs_di_lu(cxA, S, 1);
  cs_di_spfree(cxA);
  if (N == NULL) {
    f_st.site = &mf_emlrtRSI;
    warning(&f_st);
    cs_di_sfree(S);
    cs_di_nfree(N);
    cxA = makeCXSparseMatrix(y_colidx_data[6] - 1, 6, 6, &y_colidx_data[0],
                             &y_rowidx_data[0], &y_d_data[0]);
    S = cs_di_sqr(2, cxA, 1);
    N = cs_di_qr(cxA, S);
    cs_di_spfree(cxA);
    qr_rank_di(N, &tol);
    solve_from_qr_di(N, S, (double *)&outBuff[0], 6, 6);
    cs_di_sfree(S);
    cs_di_nfree(N);
  } else {
    solve_from_lu_di(N, S, (double *)&outBuff[0], 6);
    cs_di_sfree(S);
    cs_di_nfree(N);
  }
  emxFree_int32_T(&e_st, &y_rowidx);
  emxFree_int32_T(&e_st, &y_colidx);
  emxFree_real_T(&e_st, &y_d);
  b_st.site = &ef_emlrtRSI;
  val = 2.0 * varargin_2[0];
  tol = 2.0 * varargin_2[739];
  cptr = ((int32_T)(Letr + 1.0) - (int32_T)(740.0 - Letr)) + 1479;
  ridx = (int32_T)(Letr + 1.0) - 2;
  for (c = 0; c <= ridx; c++) {
    b_ytemp_data[c] = val - varargin_2[((int32_T)(Letr + 1.0) - c) - 1];
  }
  for (c = 0; c < 740; c++) {
    b_ytemp_data[(c + (int32_T)(Letr + 1.0)) - 1] = varargin_2[c];
  }
  ridx = 739 - (int32_T)(740.0 - Letr);
  for (c = 0; c <= ridx; c++) {
    b_ytemp_data[(c + (int32_T)(Letr + 1.0)) + 739] = tol - varargin_2[738 - c];
  }
  c = (int32_T)(2.0 * Letr + 740.0);
  if (c != cptr) {
    emlrtSubAssignSizeCheck1dR2017a(c, cptr, &b_emlrtECI, &b_st);
  }
  r = _mm_loadu_pd(&outBuff[0]);
  r1 = _mm_set1_pd(b_ytemp_data[0]);
  _mm_storeu_pd(&b_outBuff[0], _mm_mul_pd(r, r1));
  r = _mm_loadu_pd(&outBuff[2]);
  _mm_storeu_pd(&b_outBuff[2], _mm_mul_pd(r, r1));
  r = _mm_loadu_pd(&outBuff[4]);
  _mm_storeu_pd(&b_outBuff[4], _mm_mul_pd(r, r1));
  for (i2 = 0; i2 < 7; i2++) {
    b_B[i2] = B[i2];
  }
  for (i3 = 0; i3 < 7; i3++) {
    b_A[i3] = A[i3];
  }
  c_st.site = &sf_emlrtRSI;
  currRowIdx =
      filter(&c_st, b_B, b_A, b_ytemp_data, cptr, b_outBuff, ytemp_data);
  if (currRowIdx < 1) {
    emlrtDynamicBoundsCheckR2012b(currRowIdx, 1, currRowIdx, &emlrtBCI, &b_st);
  }
  b_iv[0] = 1;
  b_iv[1] = currRowIdx;
  c_st.site = &rf_emlrtRSI;
  indexShapeCheck(&c_st, currRowIdx, b_iv);
  cptr = currRowIdx - 1;
  for (c = 0; c <= cptr; c++) {
    b_ytemp_data[c] = ytemp_data[(currRowIdx - c) - 1];
  }
  if (currRowIdx - 1 >= 0) {
    memcpy(&ytemp_data[0], &b_ytemp_data[0],
           (uint32_T)currRowIdx * sizeof(real_T));
  }
  r = _mm_loadu_pd(&outBuff[0]);
  r1 = _mm_set1_pd(ytemp_data[0]);
  _mm_storeu_pd(&outBuff[0], _mm_mul_pd(r, r1));
  r = _mm_loadu_pd(&outBuff[2]);
  _mm_storeu_pd(&outBuff[2], _mm_mul_pd(r, r1));
  r = _mm_loadu_pd(&outBuff[4]);
  _mm_storeu_pd(&outBuff[4], _mm_mul_pd(r, r1));
  ridx = currRowIdx - 1;
  if (ridx >= 0) {
    memcpy(&b_ytemp_data[0], &ytemp_data[0],
           (uint32_T)(ridx + 1) * sizeof(real_T));
  }
  c_st.site = &qf_emlrtRSI;
  currRowIdx =
      filter(&c_st, B, A, b_ytemp_data, currRowIdx, outBuff, ytemp_data);
  c = (int32_T)((real_T)currRowIdx - Letr);
  if ((c < 1) || (c > currRowIdx)) {
    emlrtDynamicBoundsCheckR2012b(c, 1, currRowIdx, &b_emlrtBCI, &b_st);
  }
  cptr = (c - (int32_T)(Letr + 1.0)) + 1;
  if (cptr != 740) {
    emlrtSubAssignSizeCheck1dR2017a(740, cptr, &c_emlrtECI, &b_st);
  }
  for (cptr = 0; cptr < 740; cptr++) {
    y[cptr] = ytemp_data[(c - cptr) - 1];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (filtfilt.c) */
