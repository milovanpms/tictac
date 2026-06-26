/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: mean.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 21-May-2025 11:06:32
 */

/* Include Files */
#include "mean.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const double x_data[]
 *                const int x_size[2]
 * Return Type  : double
 */
double b_mean(const double x_data[], const int x_size[2])
{
  double y;
  int k;
  int vlen;
  vlen = x_size[1];
  if (x_size[1] == 0) {
    y = 0.0;
  } else {
    y = x_data[0];
    for (k = 2; k <= vlen; k++) {
      y += x_data[k - 1];
    }
  }
  y /= (double)x_size[1];
  return y;
}

/*
 * Arguments    : const double x[1200]
 * Return Type  : double
 */
double c_mean(const double x[1200])
{
  double accumulatedData;
  double y;
  int k;
  accumulatedData = x[0];
  for (k = 0; k < 1023; k++) {
    accumulatedData += x[k + 1];
  }
  y = x[1024];
  for (k = 0; k < 175; k++) {
    y += x[k + 1025];
  }
  accumulatedData += y;
  return accumulatedData / 1200.0;
}

/*
 * Arguments    : const double x[740]
 * Return Type  : double
 */
double mean(const double x[740])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 739; k++) {
    y += x[k + 1];
  }
  y /= 740.0;
  return y;
}

/*
 * File trailer for mean.c
 *
 * [EOF]
 */
