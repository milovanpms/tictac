/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xzlarfg.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 21-May-2025 11:06:32
 */

/* Include Files */
#include "xzlarfg.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : int n
 *                double *alpha1
 *                double x[3]
 * Return Type  : double
 */
double b_xzlarfg(int n, double *alpha1, double x[3])
{
  __m128d r;
  double a_tmp;
  double tau;
  double xnorm;
  int k;
  int knt;
  int vectorUB;
  int vectorUB_tmp;
  tau = 0.0;
  if (n > 0) {
    xnorm = b_xnrm2(n - 1, x);
    if (xnorm != 0.0) {
      a_tmp = fabs(*alpha1);
      xnorm = fabs(xnorm);
      if (a_tmp < xnorm) {
        a_tmp /= xnorm;
        xnorm *= sqrt(a_tmp * a_tmp + 1.0);
      } else if (a_tmp > xnorm) {
        xnorm /= a_tmp;
        xnorm = a_tmp * sqrt(xnorm * xnorm + 1.0);
      } else if (rtIsNaN(xnorm)) {
        xnorm = rtNaN;
      } else {
        xnorm = a_tmp * 1.4142135623730951;
      }
      if (*alpha1 >= 0.0) {
        xnorm = -xnorm;
      }
      if (fabs(xnorm) < 1.0020841800044864E-292) {
        knt = 0;
        do {
          knt++;
          vectorUB = (((n - 1) / 2) << 1) + 2;
          vectorUB_tmp = vectorUB - 2;
          for (k = 2; k <= vectorUB_tmp; k += 2) {
            r = _mm_loadu_pd(&x[k - 1]);
            _mm_storeu_pd(&x[k - 1],
                          _mm_mul_pd(_mm_set1_pd(9.9792015476736E+291), r));
          }
          for (k = vectorUB; k <= n; k++) {
            x[k - 1] *= 9.9792015476736E+291;
          }
          xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while ((fabs(xnorm) < 1.0020841800044864E-292) && (knt < 20));
        a_tmp = fabs(*alpha1);
        xnorm = fabs(b_xnrm2(n - 1, x));
        if (a_tmp < xnorm) {
          a_tmp /= xnorm;
          xnorm *= sqrt(a_tmp * a_tmp + 1.0);
        } else if (a_tmp > xnorm) {
          xnorm /= a_tmp;
          xnorm = a_tmp * sqrt(xnorm * xnorm + 1.0);
        } else if (rtIsNaN(xnorm)) {
          xnorm = rtNaN;
        } else {
          xnorm = a_tmp * 1.4142135623730951;
        }
        if (*alpha1 >= 0.0) {
          xnorm = -xnorm;
        }
        tau = (xnorm - *alpha1) / xnorm;
        a_tmp = 1.0 / (*alpha1 - xnorm);
        for (k = 2; k <= vectorUB_tmp; k += 2) {
          r = _mm_loadu_pd(&x[k - 1]);
          _mm_storeu_pd(&x[k - 1], _mm_mul_pd(_mm_set1_pd(a_tmp), r));
        }
        for (k = vectorUB; k <= n; k++) {
          x[k - 1] *= a_tmp;
        }
        for (k = 0; k < knt; k++) {
          xnorm *= 1.0020841800044864E-292;
        }
        *alpha1 = xnorm;
      } else {
        tau = (xnorm - *alpha1) / xnorm;
        a_tmp = 1.0 / (*alpha1 - xnorm);
        knt = (((n - 1) / 2) << 1) + 2;
        vectorUB = knt - 2;
        for (k = 2; k <= vectorUB; k += 2) {
          r = _mm_loadu_pd(&x[k - 1]);
          _mm_storeu_pd(&x[k - 1], _mm_mul_pd(_mm_set1_pd(a_tmp), r));
        }
        for (k = knt; k <= n; k++) {
          x[k - 1] *= a_tmp;
        }
        *alpha1 = xnorm;
      }
    }
  }
  return tau;
}

/*
 * Arguments    : int n
 *                double *alpha1
 *                double x[36]
 *                int ix0
 * Return Type  : double
 */
double xzlarfg(int n, double *alpha1, double x[36], int ix0)
{
  __m128d r;
  double a_tmp;
  double tau;
  double xnorm;
  int i;
  int k;
  int knt;
  int scalarLB;
  int vectorUB;
  tau = 0.0;
  if (n > 0) {
    xnorm = xnrm2(n - 1, x, ix0);
    if (xnorm != 0.0) {
      a_tmp = fabs(*alpha1);
      xnorm = fabs(xnorm);
      if (a_tmp < xnorm) {
        a_tmp /= xnorm;
        xnorm *= sqrt(a_tmp * a_tmp + 1.0);
      } else if (a_tmp > xnorm) {
        xnorm /= a_tmp;
        xnorm = a_tmp * sqrt(xnorm * xnorm + 1.0);
      } else if (rtIsNaN(xnorm)) {
        xnorm = rtNaN;
      } else {
        xnorm = a_tmp * 1.4142135623730951;
      }
      if (*alpha1 >= 0.0) {
        xnorm = -xnorm;
      }
      if (fabs(xnorm) < 1.0020841800044864E-292) {
        knt = 0;
        i = (ix0 + n) - 2;
        do {
          knt++;
          scalarLB = ((i - ix0) + 1) / 2 * 2 + ix0;
          vectorUB = scalarLB - 2;
          for (k = ix0; k <= vectorUB; k += 2) {
            r = _mm_loadu_pd(&x[k - 1]);
            r = _mm_mul_pd(_mm_set1_pd(9.9792015476736E+291), r);
            _mm_storeu_pd(&x[k - 1], r);
          }
          for (k = scalarLB; k <= i; k++) {
            x[k - 1] *= 9.9792015476736E+291;
          }
          xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while ((fabs(xnorm) < 1.0020841800044864E-292) && (knt < 20));
        a_tmp = fabs(*alpha1);
        xnorm = fabs(xnrm2(n - 1, x, ix0));
        if (a_tmp < xnorm) {
          a_tmp /= xnorm;
          xnorm *= sqrt(a_tmp * a_tmp + 1.0);
        } else if (a_tmp > xnorm) {
          xnorm /= a_tmp;
          xnorm = a_tmp * sqrt(xnorm * xnorm + 1.0);
        } else if (rtIsNaN(xnorm)) {
          xnorm = rtNaN;
        } else {
          xnorm = a_tmp * 1.4142135623730951;
        }
        if (*alpha1 >= 0.0) {
          xnorm = -xnorm;
        }
        tau = (xnorm - *alpha1) / xnorm;
        a_tmp = 1.0 / (*alpha1 - xnorm);
        scalarLB = ((i - ix0) + 1) / 2 * 2 + ix0;
        vectorUB = scalarLB - 2;
        for (k = ix0; k <= vectorUB; k += 2) {
          r = _mm_loadu_pd(&x[k - 1]);
          r = _mm_mul_pd(_mm_set1_pd(a_tmp), r);
          _mm_storeu_pd(&x[k - 1], r);
        }
        for (k = scalarLB; k <= i; k++) {
          x[k - 1] *= a_tmp;
        }
        for (k = 0; k < knt; k++) {
          xnorm *= 1.0020841800044864E-292;
        }
        *alpha1 = xnorm;
      } else {
        tau = (xnorm - *alpha1) / xnorm;
        a_tmp = 1.0 / (*alpha1 - xnorm);
        i = (ix0 + n) - 2;
        scalarLB = ((i - ix0) + 1) / 2 * 2 + ix0;
        vectorUB = scalarLB - 2;
        for (k = ix0; k <= vectorUB; k += 2) {
          r = _mm_loadu_pd(&x[k - 1]);
          r = _mm_mul_pd(_mm_set1_pd(a_tmp), r);
          _mm_storeu_pd(&x[k - 1], r);
        }
        for (k = scalarLB; k <= i; k++) {
          x[k - 1] *= a_tmp;
        }
        *alpha1 = xnorm;
      }
    }
  }
  return tau;
}

/*
 * File trailer for xzlarfg.c
 *
 * [EOF]
 */
