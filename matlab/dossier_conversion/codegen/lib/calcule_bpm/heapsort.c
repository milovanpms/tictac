/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: heapsort.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 21-May-2025 11:06:32
 */

/* Include Files */
#include "heapsort.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void heapify(int x_data[], int idx, int xstart, int xend);

/* Function Definitions */
/*
 * Arguments    : int x_data[]
 *                int idx
 *                int xstart
 *                int xend
 * Return Type  : void
 */
static void heapify(int x_data[], int idx, int xstart, int xend)
{
  int cmpIdx;
  int extremum;
  int extremumIdx;
  int leftIdx;
  int xcmp;
  boolean_T changed;
  boolean_T exitg1;
  changed = true;
  extremumIdx = (idx + xstart) - 2;
  leftIdx = ((idx << 1) + xstart) - 1;
  exitg1 = false;
  while ((!exitg1) && (leftIdx < xend)) {
    changed = false;
    extremum = x_data[extremumIdx];
    cmpIdx = leftIdx - 1;
    xcmp = x_data[leftIdx - 1];
    if (xcmp < x_data[leftIdx]) {
      cmpIdx = leftIdx;
      xcmp = x_data[leftIdx];
    }
    if (x_data[extremumIdx] < xcmp) {
      x_data[extremumIdx] = xcmp;
      x_data[cmpIdx] = extremum;
      extremumIdx = cmpIdx;
      leftIdx = ((((cmpIdx - xstart) + 2) << 1) + xstart) - 1;
      changed = true;
    } else {
      exitg1 = true;
    }
  }
  if (changed && (leftIdx <= xend)) {
    extremum = x_data[extremumIdx];
    cmpIdx = x_data[leftIdx - 1];
    if (x_data[extremumIdx] < cmpIdx) {
      x_data[extremumIdx] = cmpIdx;
      x_data[leftIdx - 1] = extremum;
    }
  }
}

/*
 * Arguments    : int x_data[]
 *                int xstart
 *                int xend
 * Return Type  : void
 */
void b_heapsort(int x_data[], int xstart, int xend)
{
  int idx;
  int k;
  int n;
  int t;
  n = xend - xstart;
  for (idx = n + 1; idx >= 1; idx--) {
    heapify(x_data, idx, xstart, xend);
  }
  for (k = 0; k < n; k++) {
    idx = (xend - k) - 1;
    t = x_data[idx];
    x_data[idx] = x_data[xstart - 1];
    x_data[xstart - 1] = t;
    heapify(x_data, 1, xstart, idx);
  }
}

/*
 * File trailer for heapsort.c
 *
 * [EOF]
 */
