/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bilinear.h
 *
 * Code generation for function 'bilinear'
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
real_T bilinear(const emlrtStack *sp, const real_T z[36], const real_T p[6],
                const real_T k[6], real_T zd[36], real_T pd[6], real_T kd[6]);

/* End of code generation (bilinear.h) */
