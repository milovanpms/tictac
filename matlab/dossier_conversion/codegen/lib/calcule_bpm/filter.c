/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: filter.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 21-May-2025 11:06:32
 */

/* Include Files */
#include "filter.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double x[1200]
 *                double y[1200]
 * Return Type  : void
 */
void b_filter(const double x[1200], double y[1200])
{
  static const double b_dv[5] = {0.029954582208092471, 0.0,
                                 -0.059909164416184942, 0.0,
                                 0.029954582208092471};
  static const double dv1[5] = {1.0, -3.3896867071734995, 4.37041391131624,
                                -2.5537313794916958, 0.57406191508395488};
  double as;
  int i;
  int j;
  int k;
  int y_tmp;
  memset(&y[0], 0, 1200U * sizeof(double));
  for (k = 0; k < 1200; k++) {
    if (1200 - k < 5) {
      i = 1199 - k;
    } else {
      i = 4;
    }
    for (j = 0; j <= i; j++) {
      y_tmp = k + j;
      y[y_tmp] += x[k] * b_dv[j];
    }
    if (1199 - k < 4) {
      i = 1198 - k;
    } else {
      i = 3;
    }
    as = -y[k];
    for (j = 0; j <= i; j++) {
      y_tmp = (k + j) + 1;
      y[y_tmp] += as * dv1[j + 1];
    }
  }
}

/*
 * Arguments    : const double b[7]
 *                const double a[7]
 *                const double x[740]
 *                double y[740]
 * Return Type  : void
 */
void filter(const double b[7], const double a[7], const double x[740],
            double y[740])
{
  double as;
  int i;
  int j;
  int k;
  int y_tmp;
  memset(&y[0], 0, 740U * sizeof(double));
  for (k = 0; k < 740; k++) {
    if (740 - k < 7) {
      i = 739 - k;
    } else {
      i = 6;
    }
    for (j = 0; j <= i; j++) {
      y_tmp = k + j;
      y[y_tmp] += x[k] * b[j];
    }
    if (739 - k < 6) {
      i = 738 - k;
    } else {
      i = 5;
    }
    as = -y[k];
    for (j = 0; j <= i; j++) {
      y_tmp = (k + j) + 1;
      y[y_tmp] += as * a[j + 1];
    }
  }
}

/*
 * File trailer for filter.c
 *
 * [EOF]
 */
