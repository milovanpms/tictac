/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: insertionsort.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 21-May-2025 11:06:32
 */

/* Include Files */
#include "insertionsort.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : double x[6]
 * Return Type  : void
 */
void b_insertionsort(double x[6])
{
  double d;
  double xc;
  int idx;
  int k;
  boolean_T exitg1;
  for (k = 2; k < 7; k++) {
    xc = x[k - 1];
    idx = k - 1;
    exitg1 = false;
    while ((!exitg1) && (idx >= 1)) {
      d = x[idx - 1];
      if (xc < d) {
        x[idx] = d;
        idx--;
      } else {
        exitg1 = true;
      }
    }
    x[idx] = xc;
  }
}

/*
 * Arguments    : int x_data[]
 *                int xstart
 *                int xend
 * Return Type  : void
 */
void insertionsort(int x_data[], int xstart, int xend)
{
  int i;
  int i1;
  int idx;
  int k;
  int xc;
  boolean_T exitg1;
  i = xstart + 1;
  for (k = i; k <= xend; k++) {
    xc = x_data[k - 1];
    idx = k - 1;
    exitg1 = false;
    while ((!exitg1) && (idx >= xstart)) {
      i1 = x_data[idx - 1];
      if (xc < i1) {
        x_data[idx] = i1;
        idx--;
      } else {
        exitg1 = true;
      }
    }
    x_data[idx] = xc;
  }
}

/*
 * File trailer for insertionsort.c
 *
 * [EOF]
 */
