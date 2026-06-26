/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * insertionsort.h
 *
 * Code generation for function 'insertionsort'
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
void b_insertionsort(int32_T x_data[], int32_T xend);

void c_insertionsort(const emlrtStack *sp, int32_T x_data[], int32_T xstart,
                     int32_T xend);

void insertionsort(int32_T x[16]);

/* End of code generation (insertionsort.h) */
