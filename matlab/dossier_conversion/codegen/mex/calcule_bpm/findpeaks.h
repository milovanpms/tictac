/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * findpeaks.h
 *
 * Code generation for function 'findpeaks'
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
int32_T findpeaks(const emlrtStack *sp, const real_T Yin[740],
                  const real_T varargin_1[740], real_T varargin_3,
                  real_T Ypk_data[], real_T Xpk_data[], int32_T Xpk_size[2]);

/* End of code generation (findpeaks.h) */
