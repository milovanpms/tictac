/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eml_setop.c
 *
 * Code generation for function 'eml_setop'
 *
 */

/* Include files */
#include "eml_setop.h"
#include "calcule_bpm_data.h"
#include "issorted.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo n_emlrtRTEI = {
    242,          /* lineNo */
    13,           /* colNo */
    "do_vectors", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" /* pName */
};

static emlrtRTEInfo o_emlrtRTEI = {
    245,          /* lineNo */
    13,           /* colNo */
    "do_vectors", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" /* pName */
};

static emlrtRTEInfo p_emlrtRTEI = {
    409,          /* lineNo */
    5,            /* colNo */
    "do_vectors", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" /* pName */
};

static emlrtRTEInfo q_emlrtRTEI = {
    420,          /* lineNo */
    9,            /* colNo */
    "do_vectors", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" /* pName */
};

static emlrtRTEInfo r_emlrtRTEI = {
    447,          /* lineNo */
    5,            /* colNo */
    "do_vectors", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" /* pName */
};

/* Function Definitions */
int32_T do_vectors(const emlrtStack *sp, const int32_T a_data[], int32_T a_size,
                   const int32_T b_data[], int32_T b_size, int32_T c_data[],
                   int32_T ia_data[], int32_T *ia_size, int32_T ib_data[],
                   int32_T *ib_size)
{
  int32_T b_ialast;
  int32_T b_iblast;
  int32_T c_size;
  int32_T iafirst;
  int32_T ialast;
  int32_T ibfirst;
  int32_T iblast;
  int32_T nc;
  int32_T nia;
  int32_T nib;
  c_size = a_size + b_size;
  *ia_size = a_size;
  *ib_size = b_size;
  if (!issorted(a_data, a_size)) {
    emlrtErrorWithMessageIdR2018a(sp, &n_emlrtRTEI,
                                  "Coder:toolbox:eml_setop_unsortedA",
                                  "Coder:toolbox:eml_setop_unsortedA", 0);
  }
  if (!issorted(b_data, b_size)) {
    emlrtErrorWithMessageIdR2018a(sp, &o_emlrtRTEI,
                                  "Coder:toolbox:eml_setop_unsortedB",
                                  "Coder:toolbox:eml_setop_unsortedB", 0);
  }
  nc = -1;
  nia = 0;
  nib = 0;
  iafirst = 1;
  ialast = 0;
  ibfirst = 0;
  iblast = 0;
  while ((ialast + 1 <= a_size) && (iblast + 1 <= b_size)) {
    int32_T ak;
    int32_T bk;
    b_ialast = ialast + 1;
    ak = a_data[ialast];
    while ((b_ialast < a_size) && (a_data[b_ialast] == ak)) {
      b_ialast++;
    }
    ialast = b_ialast - 1;
    b_iblast = iblast + 1;
    bk = b_data[iblast];
    while ((b_iblast < b_size) && (b_data[b_iblast] == bk)) {
      b_iblast++;
    }
    iblast = b_iblast - 1;
    if (ak == bk) {
      nc++;
      c_data[nc] = ak;
      nia++;
      ia_data[nia - 1] = iafirst;
      ialast = b_ialast;
      iafirst = b_ialast + 1;
      iblast = b_iblast;
      ibfirst = b_iblast;
    } else if (ak < bk) {
      nc++;
      nia++;
      c_data[nc] = ak;
      ia_data[nia - 1] = iafirst;
      ialast = b_ialast;
      iafirst = b_ialast + 1;
    } else {
      nc++;
      nib++;
      c_data[nc] = bk;
      ib_data[nib - 1] = ibfirst + 1;
      iblast = b_iblast;
      ibfirst = b_iblast;
    }
  }
  while (ialast + 1 <= a_size) {
    b_ialast = ialast + 1;
    while ((b_ialast < a_size) && (a_data[b_ialast] == a_data[ialast])) {
      b_ialast++;
    }
    nc++;
    nia++;
    c_data[nc] = a_data[ialast];
    ia_data[nia - 1] = iafirst;
    ialast = b_ialast;
    iafirst = b_ialast + 1;
  }
  while (iblast + 1 <= b_size) {
    b_iblast = iblast + 1;
    while ((b_iblast < b_size) && (b_data[b_iblast] == b_data[iblast])) {
      b_iblast++;
    }
    nc++;
    nib++;
    c_data[nc] = b_data[iblast];
    ib_data[nib - 1] = ibfirst + 1;
    iblast = b_iblast;
    ibfirst = b_iblast;
  }
  if (a_size > 0) {
    if (nia > a_size) {
      emlrtErrorWithMessageIdR2018a(sp, &p_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (nia < 1) {
      *ia_size = 0;
    } else {
      *ia_size = nia;
    }
  }
  if (b_size > 0) {
    if (nib > b_size) {
      emlrtErrorWithMessageIdR2018a(sp, &q_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (nib < 1) {
      *ib_size = 0;
    } else {
      *ib_size = nib;
    }
  }
  if (c_size > 0) {
    if (nc + 1 > c_size) {
      emlrtErrorWithMessageIdR2018a(sp, &r_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (nc + 1 < 1) {
      c_size = 0;
    } else {
      c_size = nc + 1;
    }
  }
  return c_size;
}

/* End of code generation (eml_setop.c) */
