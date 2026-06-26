/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * findpeaks.c
 *
 * Code generation for function 'findpeaks'
 *
 */

/* Include files */
#include "findpeaks.h"
#include "calcule_bpm_data.h"
#include "calcule_bpm_mexutil.h"
#include "eml_setop.h"
#include "indexShapeCheck.h"
#include "introsort.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ag_emlrtRSI =
    {
        134,         /* lineNo */
        "findpeaks", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m" /* pathName
                                                                       */
};

static emlrtRSInfo bg_emlrtRSI =
    {
        166,         /* lineNo */
        "findpeaks", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m" /* pathName
                                                                       */
};

static emlrtRSInfo cg_emlrtRSI =
    {
        167,         /* lineNo */
        "findpeaks", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m" /* pathName
                                                                       */
};

static emlrtRSInfo dg_emlrtRSI =
    {
        178,         /* lineNo */
        "findpeaks", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m" /* pathName
                                                                       */
};

static emlrtRSInfo eg_emlrtRSI =
    {
        182,         /* lineNo */
        "findpeaks", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m" /* pathName
                                                                       */
};

static emlrtRSInfo fg_emlrtRSI =
    {
        189,         /* lineNo */
        "findpeaks", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m" /* pathName
                                                                       */
};

static emlrtRSInfo gg_emlrtRSI =
    {
        195,         /* lineNo */
        "findpeaks", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m" /* pathName
                                                                       */
};

static emlrtRSInfo hg_emlrtRSI =
    {
        269,            /* lineNo */
        "parse_inputs", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m" /* pathName
                                                                       */
};

static emlrtRSInfo ig_emlrtRSI =
    {
        356,            /* lineNo */
        "parse_inputs", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m" /* pathName
                                                                       */
};

static emlrtRSInfo jg_emlrtRSI = {
    22,           /* lineNo */
    "validatelt", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatelt.m" /* pathName */
};

static emlrtRSInfo kg_emlrtRSI = {
    17,              /* lineNo */
    "local_num2str", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\private\\local_num2str.m" /* pathName */
};

static emlrtRSInfo
    lg_emlrtRSI =
        {
            15,        /* lineNo */
            "num2str", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\num2str.m" /* pathName */
};

static emlrtRSInfo mg_emlrtRSI =
    {
        551,                /* lineNo */
        "removeSmallPeaks", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m" /* pathName
                                                                       */
};

static emlrtRSInfo ng_emlrtRSI =
    {
        566,            /* lineNo */
        "combinePeaks", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m" /* pathName
                                                                       */
};

static emlrtRSInfo og_emlrtRSI =
    {
        23,      /* lineNo */
        "union", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\union.m" /* pathName
                                                                          */
};

static emlrtRSInfo pg_emlrtRSI = {
    97,          /* lineNo */
    "eml_setop", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" /* pathName */
};

static emlrtRSInfo xg_emlrtRSI =
    {
        641,                                           /* lineNo */
        "findPeaksSeparatedByMoreThanMinPeakDistance", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m" /* pathName
                                                                       */
};

static emlrtMCInfo c_emlrtMCI = {
    53,        /* lineNo */
    19,        /* colNo */
    "flt2str", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\flt2str.m" /* pName */
};

static emlrtRTEInfo l_emlrtRTEI = {
    22,           /* lineNo */
    27,           /* colNo */
    "validatelt", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatelt.m" /* pName */
};

static emlrtRTEInfo m_emlrtRTEI = {
    13,                   /* lineNo */
    37,                   /* colNo */
    "validateincreasing", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validateincreasing.m" /* pName */
};

static emlrtBCInfo c_emlrtBCI =
    {
        -1,                 /* iFirst */
        -1,                 /* iLast */
        562,                /* lineNo */
        13,                 /* colNo */
        "",                 /* aName */
        "removeSmallPeaks", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo d_emlrtBCI =
    {
        -1,                 /* iFirst */
        -1,                 /* iLast */
        562,                /* lineNo */
        11,                 /* colNo */
        "",                 /* aName */
        "removeSmallPeaks", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo e_emlrtBCI =
    {
        1,                  /* iFirst */
        740,                /* iLast */
        555,                /* lineNo */
        31,                 /* colNo */
        "",                 /* aName */
        "removeSmallPeaks", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo f_emlrtBCI =
    {
        1,                  /* iFirst */
        740,                /* iLast */
        555,                /* lineNo */
        22,                 /* colNo */
        "",                 /* aName */
        "removeSmallPeaks", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo g_emlrtBCI =
    {
        1,                  /* iFirst */
        740,                /* iLast */
        553,                /* lineNo */
        12,                 /* colNo */
        "",                 /* aName */
        "removeSmallPeaks", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo h_emlrtBCI =
    {
        -1,                   /* iFirst */
        -1,                   /* iLast */
        475,                  /* lineNo */
        14,                   /* colNo */
        "",                   /* aName */
        "getAllPeaksCodegen", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo i_emlrtBCI =
    {
        -1,                   /* iFirst */
        -1,                   /* iLast */
        502,                  /* lineNo */
        25,                   /* colNo */
        "",                   /* aName */
        "getAllPeaksCodegen", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo j_emlrtBCI =
    {
        -1,                   /* iFirst */
        -1,                   /* iLast */
        523,                  /* lineNo */
        14,                   /* colNo */
        "",                   /* aName */
        "getAllPeaksCodegen", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo k_emlrtBCI =
    {
        -1,                   /* iFirst */
        -1,                   /* iLast */
        511,                  /* lineNo */
        26,                   /* colNo */
        "",                   /* aName */
        "getAllPeaksCodegen", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo l_emlrtBCI =
    {
        -1,                   /* iFirst */
        -1,                   /* iLast */
        497,                  /* lineNo */
        26,                   /* colNo */
        "",                   /* aName */
        "getAllPeaksCodegen", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo m_emlrtBCI =
    {
        -1,                   /* iFirst */
        -1,                   /* iLast */
        489,                  /* lineNo */
        26,                   /* colNo */
        "",                   /* aName */
        "getAllPeaksCodegen", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo n_emlrtBCI =
    {
        -1,          /* iFirst */
        -1,          /* iLast */
        195,         /* lineNo */
        19,          /* colNo */
        "",          /* aName */
        "findpeaks", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo o_emlrtBCI =
    {
        -1,                 /* iFirst */
        -1,                 /* iLast */
        552,                /* lineNo */
        17,                 /* colNo */
        "",                 /* aName */
        "removeSmallPeaks", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo p_emlrtBCI =
    {
        -1,                 /* iFirst */
        -1,                 /* iLast */
        558,                /* lineNo */
        17,                 /* colNo */
        "",                 /* aName */
        "removeSmallPeaks", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo q_emlrtBCI =
    {
        -1,          /* iFirst */
        -1,          /* iLast */
        195,         /* lineNo */
        15,          /* colNo */
        "",          /* aName */
        "findpeaks", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtRTEInfo s_emlrtRTEI =
    {
        618,                                           /* lineNo */
        18,                                            /* colNo */
        "findPeaksSeparatedByMoreThanMinPeakDistance", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m" /* pName
                                                                       */
};

static emlrtBCInfo r_emlrtBCI =
    {
        -1,                                            /* iFirst */
        -1,                                            /* iLast */
        619,                                           /* lineNo */
        35,                                            /* colNo */
        "",                                            /* aName */
        "findPeaksSeparatedByMoreThanMinPeakDistance", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo s_emlrtBCI =
    {
        -1,                                            /* iFirst */
        -1,                                            /* iLast */
        619,                                           /* lineNo */
        52,                                            /* colNo */
        "",                                            /* aName */
        "findPeaksSeparatedByMoreThanMinPeakDistance", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo t_emlrtBCI =
    {
        -1,                                            /* iFirst */
        -1,                                            /* iLast */
        619,                                           /* lineNo */
        67,                                            /* colNo */
        "",                                            /* aName */
        "findPeaksSeparatedByMoreThanMinPeakDistance", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo u_emlrtBCI =
    {
        -1,                                            /* iFirst */
        -1,                                            /* iLast */
        619,                                           /* lineNo */
        85,                                            /* colNo */
        "",                                            /* aName */
        "findPeaksSeparatedByMoreThanMinPeakDistance", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo v_emlrtBCI =
    {
        -1,                                            /* iFirst */
        -1,                                            /* iLast */
        619,                                           /* lineNo */
        100,                                           /* colNo */
        "",                                            /* aName */
        "findPeaksSeparatedByMoreThanMinPeakDistance", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo w_emlrtBCI =
    {
        -1,                                            /* iFirst */
        -1,                                            /* iLast */
        598,                                           /* lineNo */
        23,                                            /* colNo */
        "",                                            /* aName */
        "findPeaksSeparatedByMoreThanMinPeakDistance", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo x_emlrtBCI =
    {
        -1,                                            /* iFirst */
        -1,                                            /* iLast */
        603,                                           /* lineNo */
        15,                                            /* colNo */
        "",                                            /* aName */
        "findPeaksSeparatedByMoreThanMinPeakDistance", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo y_emlrtBCI =
    {
        -1,                                            /* iFirst */
        -1,                                            /* iLast */
        623,                                           /* lineNo */
        13,                                            /* colNo */
        "",                                            /* aName */
        "findPeaksSeparatedByMoreThanMinPeakDistance", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI =
    {
        -1,                                            /* iFirst */
        -1,                                            /* iLast */
        628,                                           /* lineNo */
        15,                                            /* colNo */
        "",                                            /* aName */
        "findPeaksSeparatedByMoreThanMinPeakDistance", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI =
    {
        -1,                                            /* iFirst */
        -1,                                            /* iLast */
        619,                                           /* lineNo */
        21,                                            /* colNo */
        "",                                            /* aName */
        "findPeaksSeparatedByMoreThanMinPeakDistance", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtRSInfo fi_emlrtRSI = {
    53,        /* lineNo */
    "flt2str", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\flt2str.m" /* pathName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               char_T y[23]);

static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *m1,
                                const mxArray *m2, emlrtMCInfo *location);

static int32_T
c_findPeaksSeparatedByMoreThanM(const emlrtStack *sp, const real_T y[740],
                                const real_T x[740], const int32_T iPk_data[],
                                int32_T iPk_size, int32_T idx_data[]);

static void emlrt_marshallIn(const emlrtStack *sp,
                             const mxArray *a__output_of_sprintf_,
                             const char_T *identifier, char_T y[23]);

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[23]);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[23])
{
  i_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *m1,
                                const mxArray *m2, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  return emlrtCallMATLABR2012b((emlrtConstCTX)sp, 1, &m, 2, &pArrays[0],
                               "sprintf", true, location);
}

static int32_T
c_findPeaksSeparatedByMoreThanM(const emlrtStack *sp, const real_T y[740],
                                const real_T x[740], const int32_T iPk_data[],
                                int32_T iPk_size, int32_T idx_data[])
{
  emlrtStack st;
  int32_T iwork_data[1480];
  int32_T b_i;
  int32_T i;
  int32_T idx_size;
  int32_T j;
  int32_T k;
  int32_T qEnd;
  int16_T tmp_data[1480];
  boolean_T idelete_data[1480];
  st.prev = sp;
  st.tls = sp->tls;
  if (iPk_size == 0) {
    idx_size = 0;
  } else {
    real_T idelete_tmp;
    int32_T sortIdx_data[1480];
    int32_T i2;
    i = iPk_size - 1;
    for (k = 1; k <= i; k += 2) {
      idelete_tmp = y[iPk_data[k - 1] - 1];
      if ((idelete_tmp >= y[iPk_data[k] - 1]) ||
          muDoubleScalarIsNaN(idelete_tmp)) {
        sortIdx_data[k - 1] = k;
        sortIdx_data[k] = k + 1;
      } else {
        sortIdx_data[k - 1] = k + 1;
        sortIdx_data[k] = k;
      }
    }
    if (((uint32_T)iPk_size & 1U) != 0U) {
      sortIdx_data[iPk_size - 1] = iPk_size;
    }
    b_i = 2;
    while (b_i < iPk_size) {
      i2 = b_i << 1;
      j = 1;
      for (idx_size = b_i + 1; idx_size < iPk_size + 1; idx_size = qEnd + b_i) {
        int32_T kEnd;
        int32_T p;
        int32_T q;
        p = j - 1;
        q = idx_size;
        qEnd = j + i2;
        if (qEnd > iPk_size + 1) {
          qEnd = iPk_size + 1;
        }
        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          idelete_tmp = y[iPk_data[sortIdx_data[p] - 1] - 1];
          i = sortIdx_data[q - 1];
          if ((idelete_tmp >= y[iPk_data[i - 1] - 1]) ||
              muDoubleScalarIsNaN(idelete_tmp)) {
            iwork_data[k] = sortIdx_data[p];
            p++;
            if (p + 1 == idx_size) {
              while (q < qEnd) {
                k++;
                iwork_data[k] = sortIdx_data[q - 1];
                q++;
              }
            }
          } else {
            iwork_data[k] = i;
            q++;
            if (q == qEnd) {
              while (p + 1 < idx_size) {
                k++;
                iwork_data[k] = sortIdx_data[p];
                p++;
              }
            }
          }
          k++;
        }
        for (k = 0; k < kEnd; k++) {
          sortIdx_data[(j + k) - 1] = iwork_data[k];
        }
        j = qEnd;
      }
      b_i = i2;
    }
    for (i = 0; i < iPk_size; i++) {
      i2 = sortIdx_data[i];
      if ((i2 < 1) || (i2 > iPk_size)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, iPk_size, &w_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
    }
    memset(&idelete_data[0], 0, (uint32_T)iPk_size * sizeof(boolean_T));
    for (b_i = 0; b_i < iPk_size; b_i++) {
      if (b_i + 1 > iPk_size) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, iPk_size, &x_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (!idelete_data[b_i]) {
        emlrtForLoopVectorCheckR2021a(iPk_size, -1.0, 1.0, mxDOUBLE_CLASS,
                                      iPk_size, &s_emlrtRTEI,
                                      (emlrtConstCTX)sp);
        idelete_tmp = x[iPk_data[sortIdx_data[b_i] - 1] - 1];
        for (j = 0; j < iPk_size; j++) {
          real_T b_idelete_tmp;
          i2 = iPk_size - j;
          if ((i2 < 1) || (i2 > iPk_size)) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, iPk_size, &r_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          if (i2 > iPk_size) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, iPk_size, &s_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          if (b_i + 1 > iPk_size) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, iPk_size, &t_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          if (i2 > iPk_size) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, iPk_size, &u_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          if (b_i + 1 > iPk_size) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, iPk_size, &v_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          if (i2 > iPk_size) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, iPk_size, &bb_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          b_idelete_tmp = x[iPk_data[sortIdx_data[i2 - 1] - 1] - 1];
          idelete_data[i2 - 1] =
              (idelete_data[i2 - 1] || ((b_idelete_tmp >= idelete_tmp - 0.4) &&
                                        (b_idelete_tmp <= idelete_tmp + 0.4)));
        }
        if (b_i + 1 > iPk_size) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, iPk_size, &y_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        idelete_data[b_i] = false;
      }
    }
    idx_size = 0;
    i2 = 0;
    for (b_i = 0; b_i < iPk_size; b_i++) {
      if (!idelete_data[b_i]) {
        idx_size++;
        tmp_data[i2] = (int16_T)b_i;
        i2++;
      }
    }
    for (i = 0; i < idx_size; i++) {
      int16_T i1;
      i1 = tmp_data[i];
      if (i1 > iPk_size - 1) {
        emlrtDynamicBoundsCheckR2012b(i1, 0, iPk_size - 1, &ab_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      idx_data[i] = sortIdx_data[i1];
    }
    if (idx_size != 0) {
      st.site = &xg_emlrtRSI;
      b_introsort(&st, idx_data, idx_size);
    }
  }
  return idx_size;
}

static void emlrt_marshallIn(const emlrtStack *sp,
                             const mxArray *a__output_of_sprintf_,
                             const char_T *identifier, char_T y[23])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(a__output_of_sprintf_), &thisId, y);
  emlrtDestroyArray(&a__output_of_sprintf_);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[23])
{
  static const int32_T dims[2] = {1, 23};
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "char", false, 2U,
                          (const void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtConstCTX)sp, src, &ret[0], 23);
  emlrtDestroyArray(&src);
}

int32_T findpeaks(const emlrtStack *sp, const real_T Yin[740],
                  const real_T varargin_1[740], real_T varargin_3,
                  real_T Ypk_data[], real_T Xpk_data[], int32_T Xpk_size[2])
{
  static const int32_T b_iv[2] = {1, 7};
  static const char_T rfmt[7] = {'%', '2', '3', '.', '1', '5', 'e'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  const mxArray *m;
  const mxArray *y;
  real_T ykfirst;
  int32_T c_data[1480];
  int32_T idx_data[1480];
  int32_T fPk_data[740];
  int32_T iFinite_data[740];
  int32_T iInfinite_data[740];
  int32_T iPk_data[740];
  int32_T b_iv1[2];
  int32_T Ypk_size;
  int32_T k;
  int32_T kfirst;
  int32_T nInf;
  int32_T nInflect;
  int32_T nPk;
  char_T dir;
  boolean_T exitg1;
  boolean_T isinfykfirst;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ag_emlrtRSI;
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
  b_st.site = &hg_emlrtRSI;
  c_st.site = &o_emlrtRSI;
  isinfykfirst = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 740)) {
    if ((!muDoubleScalarIsInf(varargin_1[k])) &&
        (!muDoubleScalarIsNaN(varargin_1[k]))) {
      k++;
    } else {
      isinfykfirst = false;
      exitg1 = true;
    }
  }
  if (!isinfykfirst) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:findpeaks:expectedFinite", 3, 4, 1, "X");
  }
  c_st.site = &o_emlrtRSI;
  isinfykfirst = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 739)) {
    if (!(varargin_1[k] < varargin_1[k + 1])) {
      isinfykfirst = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!isinfykfirst) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &m_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedIncreasing",
        "MATLAB:findpeaks:expectedIncreasing", 3, 4, 1, "X");
  }
  ykfirst = varargin_1[739] - varargin_1[0];
  b_st.site = &ig_emlrtRSI;
  c_st.site = &o_emlrtRSI;
  if (!(ykfirst > 0.4)) {
    char_T numstr[23];
    d_st.site = &jg_emlrtRSI;
    e_st.site = &kg_emlrtRSI;
    f_st.site = &lg_emlrtRSI;
    y = NULL;
    m = emlrtCreateCharArray(2, &b_iv[0]);
    emlrtInitCharArrayR2013a(&f_st, 7, m, &rfmt[0]);
    emlrtAssign(&y, m);
    g_st.site = &fi_emlrtRSI;
    emlrt_marshallIn(
        &g_st, b_sprintf(&g_st, y, emlrt_marshallOut(ykfirst), &c_emlrtMCI),
        "<output of sprintf>", numstr);
    emlrtErrorWithMessageIdR2018a(
        &c_st, &l_emlrtRTEI, "MATLAB:validateattributes:expectedScalar",
        "MATLAB:findpeaks:notLess", 9, 4, 15, "MinPeakDistance", 4, 1, "<", 4,
        23, &numstr[0]);
  }
  st.site = &bg_emlrtRSI;
  nPk = 0;
  nInf = 0;
  nInflect = 0;
  dir = 'n';
  kfirst = 0;
  ykfirst = rtInf;
  isinfykfirst = true;
  for (k = 0; k < 740; k++) {
    real_T yk;
    boolean_T isinfyk;
    yk = Yin[k];
    if (muDoubleScalarIsNaN(yk)) {
      yk = rtInf;
      isinfyk = true;
    } else if (muDoubleScalarIsInf(yk) && (yk > 0.0)) {
      isinfyk = true;
      nInf++;
      if (nInf > 740) {
        emlrtDynamicBoundsCheckR2012b(741, 1, 740, &h_emlrtBCI, &st);
      }
      iInfinite_data[nInf - 1] = k + 1;
    } else {
      isinfyk = false;
    }
    if (yk != ykfirst) {
      char_T previousdir;
      previousdir = dir;
      if (isinfyk || isinfykfirst) {
        dir = 'n';
        if (kfirst >= 1) {
          nInflect++;
          if (nInflect > 740) {
            emlrtDynamicBoundsCheckR2012b(741, 1, 740, &m_emlrtBCI, &st);
          }
          fPk_data[nInflect - 1] = kfirst;
        }
      } else if (yk < ykfirst) {
        dir = 'd';
        if (previousdir != 'd') {
          nInflect++;
          if (nInflect > 740) {
            emlrtDynamicBoundsCheckR2012b(741, 1, 740, &l_emlrtBCI, &st);
          }
          fPk_data[nInflect - 1] = kfirst;
          if (previousdir == 'i') {
            nPk++;
            if (nPk > 740) {
              emlrtDynamicBoundsCheckR2012b(741, 1, 740, &i_emlrtBCI, &st);
            }
            iFinite_data[nPk - 1] = kfirst;
          }
        }
      } else {
        dir = 'i';
        if (previousdir != 'i') {
          nInflect++;
          if (nInflect > 740) {
            emlrtDynamicBoundsCheckR2012b(741, 1, 740, &k_emlrtBCI, &st);
          }
          fPk_data[nInflect - 1] = kfirst;
        }
      }
      ykfirst = yk;
      kfirst = k + 1;
      isinfykfirst = isinfyk;
    }
  }
  if ((!isinfykfirst) && ((nInflect == 0) || (fPk_data[nInflect - 1] < 740)) &&
      (nInflect + 1 > 740)) {
    emlrtDynamicBoundsCheckR2012b(741, 1, 740, &j_emlrtBCI, &st);
  }
  st.site = &cg_emlrtRSI;
  Ypk_size = 0;
  b_st.site = &mg_emlrtRSI;
  for (k = 0; k < nPk; k++) {
    if (k + 1 > nPk) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, nPk, &o_emlrtBCI, &st);
    }
    kfirst = iFinite_data[k];
    if (kfirst < 1) {
      emlrtDynamicBoundsCheckR2012b(0, 1, 740, &g_emlrtBCI, &st);
    }
    ykfirst = Yin[kfirst - 1];
    if (ykfirst > varargin_3) {
      if (kfirst - 1 < 1) {
        emlrtDynamicBoundsCheckR2012b(0, 1, 740, &f_emlrtBCI, &st);
      }
      if (kfirst + 1 > 740) {
        emlrtDynamicBoundsCheckR2012b(741, 1, 740, &e_emlrtBCI, &st);
      }
      if (ykfirst - muDoubleScalarMax(Yin[kfirst - 2], Yin[kfirst]) >= 0.0) {
        Ypk_size++;
        if ((Ypk_size < 1) || (Ypk_size > nPk)) {
          emlrtDynamicBoundsCheckR2012b(Ypk_size, 1, nPk, &p_emlrtBCI, &st);
        }
        iPk_data[Ypk_size - 1] = kfirst;
      }
    }
  }
  if (Ypk_size < 1) {
    Ypk_size = 0;
  } else {
    if (nPk < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, nPk, &d_emlrtBCI, &st);
    }
    if (Ypk_size > nPk) {
      emlrtDynamicBoundsCheckR2012b(Ypk_size, 1, nPk, &c_emlrtBCI, &st);
    }
  }
  st.site = &dg_emlrtRSI;
  b_st.site = &ng_emlrtRSI;
  c_st.site = &og_emlrtRSI;
  d_st.site = &pg_emlrtRSI;
  nPk = do_vectors(&d_st, iPk_data, Ypk_size, iInfinite_data, nInf, c_data,
                   fPk_data, &kfirst, iFinite_data, &nInflect);
  st.site = &eg_emlrtRSI;
  nInflect = c_findPeaksSeparatedByMoreThanM(&st, Yin, varargin_1, c_data, nPk,
                                             idx_data);
  if (nInflect > 740) {
    kfirst = 740;
    st.site = &fg_emlrtRSI;
    b_indexShapeCheck();
    nInflect = 740;
  } else {
    kfirst = nInflect;
  }
  if (kfirst < 1) {
    Ypk_size = 0;
  } else {
    if (nInflect < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, nInflect, &n_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    Ypk_size = nInflect;
  }
  b_iv1[0] = 1;
  b_iv1[1] = Ypk_size;
  st.site = &gg_emlrtRSI;
  indexShapeCheck(&st, nInflect, b_iv1);
  for (kfirst = 0; kfirst < Ypk_size; kfirst++) {
    nInflect = idx_data[kfirst];
    if ((nInflect < 1) || (nInflect > nPk)) {
      emlrtDynamicBoundsCheckR2012b(nInflect, 1, nPk, &q_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    fPk_data[kfirst] = c_data[nInflect - 1];
  }
  Xpk_size[0] = 1;
  Xpk_size[1] = Ypk_size;
  for (kfirst = 0; kfirst < Ypk_size; kfirst++) {
    nInflect = fPk_data[kfirst];
    Ypk_data[kfirst] = Yin[nInflect - 1];
    Xpk_data[kfirst] = varargin_1[nInflect - 1];
  }
  return Ypk_size;
}

/* End of code generation (findpeaks.c) */
