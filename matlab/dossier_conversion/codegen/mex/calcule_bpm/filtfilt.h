/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * filtfilt.h
 *
 * Code generation for function 'filtfilt'
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
void filtfilt(const emlrtStack *sp, const real_T ctf[7],
              const real_T varargin_1[7], const real_T varargin_2[740],
              real_T y[740]);

/* End of code generation (filtfilt.h) */
