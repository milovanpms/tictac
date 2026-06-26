/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calcule_bpm_initialize.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 21-May-2025 11:06:32
 */

/* Include Files */
#include "calcule_bpm_initialize.h"
#include "calcule_bpm_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void calcule_bpm_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_calcule_bpm = true;
}

/*
 * File trailer for calcule_bpm_initialize.c
 *
 * [EOF]
 */
