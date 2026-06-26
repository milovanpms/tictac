/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calcule_pas.h
 *
 * Code generation for function 'calcule_pas'
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
real_T calcule_pas(const emlrtStack *sp, const real_T accX[19],
                   const real_T accY[19], const real_T accZ[19]);

/* End of code generation (calcule_pas.h) */
