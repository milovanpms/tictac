/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * filter.h
 *
 * Code generation for function 'filter'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void b_filter(const real_T x[19], real_T y[19]);

int32_T filter(const emlrtStack *sp, real_T b[7], real_T a[7],
               const real_T x_data[], int32_T x_size, const real_T zi[6],
               real_T y_data[]);

/* End of code generation (filter.h) */
