/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * diff.c
 *
 * Code generation for function 'diff'
 *
 */

/* Include files */
#include "diff.h"
#include "calcule_bpm_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRTEInfo t_emlrtRTEI = {
    51,     /* lineNo */
    19,     /* colNo */
    "diff", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m" /* pName
                                                                         */
};

/* Function Definitions */
void diff(const emlrtStack *sp, const real_T x_data[], const int32_T x_size[2],
          real_T y_data[], int32_T y_size[2])
{
  int32_T dimSize;
  int32_T i;
  dimSize = x_size[1];
  if (x_size[1] == 0) {
    y_size[0] = 1;
    y_size[1] = 0;
  } else {
    i = x_size[1] - 1;
    if (muIntScalarMin_sint32(i, 1) < 1) {
      y_size[0] = 1;
      y_size[1] = 0;
    } else {
      real_T work_data;
      if (x_size[1] == 1) {
        emlrtErrorWithMessageIdR2018a(
            sp, &t_emlrtRTEI, "Coder:toolbox:autoDimIncompatibility",
            "Coder:toolbox:autoDimIncompatibility", 0);
      }
      y_size[0] = 1;
      y_size[1] = x_size[1] - 1;
      work_data = x_data[0];
      for (i = 2; i <= dimSize; i++) {
        real_T d;
        real_T tmp1;
        tmp1 = x_data[i - 1];
        d = tmp1;
        tmp1 -= work_data;
        work_data = d;
        y_data[i - 2] = tmp1;
      }
    }
  }
}

/* End of code generation (diff.c) */
