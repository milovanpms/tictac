/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * issorted.c
 *
 * Code generation for function 'issorted'
 *
 */

/* Include files */
#include "issorted.h"
#include "calcule_bpm_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
boolean_T issorted(const int32_T x_data[], int32_T x_size)
{
  int32_T dim;
  boolean_T y;
  y = true;
  dim = 2;
  if (x_size != 1) {
    dim = 1;
  }
  if (x_size != 0) {
    int32_T i;
    if (dim <= 1) {
      i = x_size;
    } else {
      i = 1;
    }
    if (i != 1) {
      int32_T k;
      boolean_T exitg1;
      if (dim == 2) {
        i = -1;
      } else {
        i = 0;
      }
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= i)) {
        int32_T i1;
        boolean_T exitg2;
        if (dim == 1) {
          i1 = x_size - 1;
        } else {
          i1 = x_size;
        }
        k = 0;
        exitg2 = false;
        while ((!exitg2) && (k <= i1 - 1)) {
          int16_T subs[2];
          subs[0] = (int16_T)(k + 1);
          subs[1] = 1;
          subs[dim - 1]++;
          y = (x_data[k] <= x_data[subs[0] - 1]);
          if (!y) {
            exitg2 = true;
          } else {
            k++;
          }
        }
        if (!y) {
          exitg1 = true;
        } else {
          k = 1;
        }
      }
    }
  }
  return y;
}

/* End of code generation (issorted.c) */
