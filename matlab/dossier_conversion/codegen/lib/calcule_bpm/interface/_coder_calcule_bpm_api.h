/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_calcule_bpm_api.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 21-May-2025 11:06:32
 */

#ifndef _CODER_CALCULE_BPM_API_H
#define _CODER_CALCULE_BPM_API_H

/* Include Files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void calcule_bpm(real_T periode, real_T bat[740], real_T *nb_battements,
                 real_T *bpm_moy);

void calcule_bpm_api(const mxArray *const prhs[2], int32_T nlhs,
                     const mxArray *plhs[2]);

void calcule_bpm_atexit(void);

void calcule_bpm_initialize(void);

void calcule_bpm_terminate(void);

void calcule_bpm_xil_shutdown(void);

void calcule_bpm_xil_terminate(void);

real_T calcule_pas(real_T accX[1200], real_T accY[1200], real_T accZ[1200]);

void calcule_pas_api(const mxArray *const prhs[3], const mxArray **plhs);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_calcule_bpm_api.h
 *
 * [EOF]
 */
