/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: std.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 21-May-2025 11:06:32
 */

/* Include Files */
#include "std.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const double x[740]
 * Return Type  : double
 */
double b_std(const double x[740])
{
  double d;
  double scale;
  double t;
  double xbar;
  double y;
  int k;
  xbar = x[0];
  for (k = 0; k < 739; k++) {
    xbar += x[k + 1];
  }
  xbar /= 740.0;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = 0; k < 740; k++) {
    d = fabs(x[k] - xbar);
    if (d > scale) {
      t = scale / d;
      y = y * t * t + 1.0;
      scale = d;
    } else {
      t = d / scale;
      y += t * t;
    }
  }
  y = scale * sqrt(y);
  y /= 27.184554438136374;
  return y;
}

/*
 * File trailer for std.c
 *
 * [EOF]
 */
