/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eml_setop.h
 *
 * Code generation for function 'eml_setop'
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
int32_T do_vectors(const emlrtStack *sp, const int32_T a_data[], int32_T a_size,
                   const int32_T b_data[], int32_T b_size, int32_T c_data[],
                   int32_T ia_data[], int32_T *ia_size, int32_T ib_data[],
                   int32_T *ib_size);

/* End of code generation (eml_setop.h) */
