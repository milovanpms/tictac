/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: filter.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 21-May-2025 11:06:32
 */

#ifndef FILTER_H
#define FILTER_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_filter(const double x[1200], double y[1200]);

void filter(const double b[7], const double a[7], const double x[740],
            double y[740]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for filter.h
 *
 * [EOF]
 */
