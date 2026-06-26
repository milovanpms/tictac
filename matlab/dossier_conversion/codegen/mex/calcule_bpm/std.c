/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * std.c
 *
 * Code generation for function 'std'
 *
 */

/* Include files */
#include "std.h"
#include "calcule_bpm_data.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "blas.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <stddef.h>

/* Function Definitions */
real_T b_std(const real_T x[740])
{
  ptrdiff_t incx_t;
  ptrdiff_t n_t;
  real_T absdiff[740];
  real_T dv[2];
  real_T dv1[2];
  real_T y;
  int32_T k;
  y = sumColumnB(x) / 740.0;
  for (k = 0; k <= 738; k += 2) {
    __m128d r;
    _mm_storeu_pd(&dv[0], _mm_sub_pd(_mm_loadu_pd(&x[k]), _mm_set1_pd(y)));
    dv1[0] = muDoubleScalarAbs(dv[0]);
    dv1[1] = muDoubleScalarAbs(dv[1]);
    r = _mm_loadu_pd(&dv1[0]);
    _mm_storeu_pd(&absdiff[k], r);
  }
  n_t = (ptrdiff_t)740;
  incx_t = (ptrdiff_t)1;
  y = dnrm2(&n_t, &absdiff[0], &incx_t);
  y /= 27.184554438136374;
  return y;
}

/* End of code generation (std.c) */
