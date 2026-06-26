/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * introsort.c
 *
 * Code generation for function 'introsort'
 *
 */

/* Include files */
#include "introsort.h"
#include "calcule_bpm_data.h"
#include "heapsort.h"
#include "insertionsort.h"
#include "rt_nonfinite.h"

/* Type Definitions */
#ifndef typedef_struct_T
#define typedef_struct_T
typedef struct {
  int32_T xstart;
  int32_T xend;
  int32_T depth;
} struct_T;
#endif /* typedef_struct_T */

/* Variable Definitions */
static emlrtRSInfo ch_emlrtRSI = {
    42,          /* lineNo */
    "introsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" /* pathName */
};

static emlrtRSInfo eh_emlrtRSI = {
    47,          /* lineNo */
    "introsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" /* pathName */
};

static emlrtRSInfo fh_emlrtRSI = {
    49,          /* lineNo */
    "introsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" /* pathName */
};

static emlrtRSInfo gh_emlrtRSI = {
    55,          /* lineNo */
    "introsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" /* pathName */
};

static emlrtRSInfo hh_emlrtRSI = {
    58,          /* lineNo */
    "introsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" /* pathName */
};

static emlrtRSInfo ih_emlrtRSI = {
    41,          /* lineNo */
    "introsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" /* pathName */
};

static emlrtRTEInfo w_emlrtRTEI = {
    62,           /* lineNo */
    39,           /* colNo */
    "stack/push", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\stack.m" /* pName */
};

static emlrtDCInfo emlrtDCI = {
    48,            /* lineNo */
    63,            /* colNo */
    "stack/stack", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\stack.m", /* pName */
    4                    /* checkKind */
};

/* Function Definitions */
void b_introsort(const emlrtStack *sp, int32_T x_data[], int32_T xend)
{
  emlrtStack st;
  struct_T frame;
  int32_T pmax;
  int32_T pmin;
  st.prev = sp;
  st.tls = sp->tls;
  if (xend > 1) {
    if (xend <= 32) {
      b_insertionsort(x_data, xend);
    } else {
      struct_T st_d_data[120];
      int32_T MAXDEPTH;
      int32_T pow2p;
      int32_T st_d_size;
      int32_T st_n;
      int32_T xmid;
      boolean_T exitg1;
      pmax = 31;
      pmin = 0;
      exitg1 = false;
      while ((!exitg1) && (pmax - pmin > 1)) {
        xmid = (pmin + pmax) >> 1;
        pow2p = 1 << xmid;
        if (pow2p == xend) {
          pmax = xmid;
          exitg1 = true;
        } else if (pow2p > xend) {
          pmax = xmid;
        } else {
          pmin = xmid;
        }
      }
      MAXDEPTH = (pmax - 1) << 1;
      frame.xstart = 1;
      frame.xend = xend;
      frame.depth = 0;
      st.site = &ih_emlrtRSI;
      st_d_size = MAXDEPTH << 1;
      if (st_d_size < 0) {
        emlrtNonNegativeCheckR2012b(st_d_size, &emlrtDCI, &st);
      }
      st.site = &ch_emlrtRSI;
      if (st_d_size <= 0) {
        emlrtErrorWithMessageIdR2018a(&st, &w_emlrtRTEI,
                                      "Coder:toolbox:StackPushLimit",
                                      "Coder:toolbox:StackPushLimit", 0);
      }
      st_d_data[0] = frame;
      st_n = 1;
      while (st_n > 0) {
        frame = st_d_data[st_n - 1];
        st_n--;
        pmin = frame.xend - frame.xstart;
        if (pmin + 1 <= 32) {
          st.site = &eh_emlrtRSI;
          c_insertionsort(&st, x_data, frame.xstart, frame.xend);
        } else if (frame.depth == MAXDEPTH) {
          st.site = &fh_emlrtRSI;
          b_heapsort(&st, x_data, frame.xstart, frame.xend);
        } else {
          int32_T t;
          xmid = (frame.xstart + pmin / 2) - 1;
          pmin = x_data[frame.xstart - 1];
          if (x_data[xmid] < pmin) {
            x_data[frame.xstart - 1] = x_data[xmid];
            x_data[xmid] = pmin;
          }
          pmin = x_data[frame.xstart - 1];
          pmax = x_data[frame.xend - 1];
          if (pmax < pmin) {
            x_data[frame.xstart - 1] = pmax;
            x_data[frame.xend - 1] = pmin;
          }
          pmin = x_data[frame.xend - 1];
          if (pmin < x_data[xmid]) {
            t = x_data[xmid];
            x_data[xmid] = pmin;
            x_data[frame.xend - 1] = t;
          }
          pow2p = x_data[xmid];
          x_data[xmid] = x_data[frame.xend - 2];
          x_data[frame.xend - 2] = pow2p;
          pmax = frame.xstart - 1;
          pmin = frame.xend - 2;
          int32_T exitg2;
          do {
            exitg2 = 0;
            for (pmax++; x_data[pmax] < pow2p; pmax++) {
            }
            for (pmin--; pow2p < x_data[pmin]; pmin--) {
            }
            if (pmax + 1 >= pmin + 1) {
              exitg2 = 1;
            } else {
              t = x_data[pmax];
              x_data[pmax] = x_data[pmin];
              x_data[pmin] = t;
            }
          } while (exitg2 == 0);
          x_data[frame.xend - 2] = x_data[pmax];
          x_data[pmax] = pow2p;
          if (pmax + 2 < frame.xend) {
            st.site = &gh_emlrtRSI;
            if (st_n >= st_d_size) {
              emlrtErrorWithMessageIdR2018a(&st, &w_emlrtRTEI,
                                            "Coder:toolbox:StackPushLimit",
                                            "Coder:toolbox:StackPushLimit", 0);
            }
            st_d_data[st_n].xstart = pmax + 2;
            st_d_data[st_n].xend = frame.xend;
            st_d_data[st_n].depth = frame.depth + 1;
            st_n++;
          }
          if (frame.xstart < pmax + 1) {
            st.site = &hh_emlrtRSI;
            if (st_n >= st_d_size) {
              emlrtErrorWithMessageIdR2018a(&st, &w_emlrtRTEI,
                                            "Coder:toolbox:StackPushLimit",
                                            "Coder:toolbox:StackPushLimit", 0);
            }
            st_d_data[st_n].xstart = frame.xstart;
            st_d_data[st_n].xend = pmax + 1;
            st_d_data[st_n].depth = frame.depth + 1;
            st_n++;
          }
        }
      }
    }
  }
}

void introsort(int32_T x[16])
{
  insertionsort(x);
}

/* End of code generation (introsort.c) */
