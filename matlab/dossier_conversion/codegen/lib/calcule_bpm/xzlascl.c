/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xzlascl.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 21-May-2025 11:06:32
 */

/* Include Files */
#include "xzlascl.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : double cfrom
 *                double cto
 *                int m
 *                double A[6]
 *                int iA0
 * Return Type  : void
 */
void b_xzlascl(double cfrom, double cto, int m, double A[6], int iA0)
{
  __m128d r;
  double cfrom1;
  double cfromc;
  double cto1;
  double ctoc;
  double mul;
  int b_i;
  int i;
  int scalarLB;
  int vectorUB;
  boolean_T notdone;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((fabs(cfrom1) > fabs(ctoc)) && (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (fabs(cto1) > fabs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }
    scalarLB = m / 2 * 2;
    vectorUB = scalarLB - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      b_i = (iA0 + i) - 1;
      r = _mm_loadu_pd(&A[b_i]);
      r = _mm_mul_pd(r, _mm_set1_pd(mul));
      _mm_storeu_pd(&A[b_i], r);
    }
    for (i = scalarLB; i < m; i++) {
      b_i = (iA0 + i) - 1;
      A[b_i] *= mul;
    }
  }
}

/*
 * Arguments    : double cfrom
 *                double cto
 *                int m
 *                double A[5]
 *                int iA0
 * Return Type  : void
 */
void c_xzlascl(double cfrom, double cto, int m, double A[5], int iA0)
{
  __m128d r;
  double cfrom1;
  double cfromc;
  double cto1;
  double ctoc;
  double mul;
  int b_i;
  int i;
  int scalarLB;
  int vectorUB;
  boolean_T notdone;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((fabs(cfrom1) > fabs(ctoc)) && (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (fabs(cto1) > fabs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }
    scalarLB = m / 2 * 2;
    vectorUB = scalarLB - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      b_i = (iA0 + i) - 1;
      r = _mm_loadu_pd(&A[b_i]);
      r = _mm_mul_pd(r, _mm_set1_pd(mul));
      _mm_storeu_pd(&A[b_i], r);
    }
    for (i = scalarLB; i < m; i++) {
      b_i = (iA0 + i) - 1;
      A[b_i] *= mul;
    }
  }
}

/*
 * Arguments    : double cfrom
 *                double cto
 *                double A[36]
 * Return Type  : void
 */
void xzlascl(double cfrom, double cto, double A[36])
{
  __m128d r;
  double cfrom1;
  double cfromc;
  double cto1;
  double ctoc;
  double mul;
  int i;
  boolean_T notdone;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((fabs(cfrom1) > fabs(ctoc)) && (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (fabs(cto1) > fabs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }
    for (i = 0; i <= 34; i += 2) {
      r = _mm_loadu_pd(&A[i]);
      r = _mm_mul_pd(r, _mm_set1_pd(mul));
      _mm_storeu_pd(&A[i], r);
    }
  }
}

/*
 * File trailer for xzlascl.c
 *
 * [EOF]
 */
