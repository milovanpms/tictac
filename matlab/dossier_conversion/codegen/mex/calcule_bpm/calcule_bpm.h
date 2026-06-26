/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calcule_bpm.h
 *
 * Code generation for function 'calcule_bpm'
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

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;
extern covrtInstance emlrtCoverageInstance;

/* Function Declarations */
void calcule_bpm(const emlrtStack *sp, real_T periode, const real_T bat[740],
                 real_T *nb_battements, real_T *bpm_moy);

void calcule_bpm_api(const mxArray *const prhs[2], int32_T nlhs,
                     const mxArray *plhs[2]);

void calcule_bpm_atexit(void);

void calcule_bpm_initialize(void);

void calcule_bpm_terminate(void);

real_T calcule_pas(const emlrtStack *sp, const real_T accX[19],
                   const real_T accY[19], const real_T accZ[19]);

void calcule_pas_api(const mxArray *const prhs[3], const mxArray **plhs);

/* End of code generation (calcule_bpm.h) */
