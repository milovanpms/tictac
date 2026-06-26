/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: eig.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 21-May-2025 11:06:32
 */

/* Include Files */
#include "eig.h"
#include "eigStandard.h"
#include "rt_nonfinite.h"
#include "xdlahqr.h"
#include "xdsterf.h"
#include "xzgehrd.h"
#include "xzlarfg.h"
#include "xzlascl.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double A[36]
 *                creal_T V[6]
 * Return Type  : void
 */
void eig(const double A[36], creal_T V[6])
{
  __m128d r;
  __m128d r1;
  __m128d r2;
  double b_A[36];
  double a__3[6];
  double wi[6];
  double e[5];
  double tau[5];
  double absx;
  double anrm;
  double b_tau_tmp;
  double taui;
  double temp1;
  int A_tmp_tmp;
  int b_i;
  int e_tmp_tmp;
  int exitg1;
  int i;
  int i1;
  int i2;
  int ii;
  int jj;
  int k;
  int scalarLB;
  int tau_tmp;
  int temp1_tmp;
  boolean_T exitg2;
  boolean_T iscale;
  iscale = true;
  for (k = 0; k < 36; k++) {
    if (iscale) {
      absx = A[k];
      if (rtIsInf(absx) || rtIsNaN(absx)) {
        iscale = false;
      }
    } else {
      iscale = false;
    }
  }
  if (!iscale) {
    for (i = 0; i < 6; i++) {
      V[i].re = rtNaN;
      V[i].im = 0.0;
    }
  } else {
    iscale = true;
    k = 0;
    exitg2 = false;
    while ((!exitg2) && (k < 6)) {
      i = 0;
      do {
        exitg1 = 0;
        if (i <= k) {
          if (!(A[i + 6 * k] == A[k + 6 * i])) {
            iscale = false;
            exitg1 = 1;
          } else {
            i++;
          }
        } else {
          k++;
          exitg1 = 2;
        }
      } while (exitg1 == 0);
      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
    if (iscale) {
      memcpy(&b_A[0], &A[0], 36U * sizeof(double));
      anrm = 0.0;
      k = 0;
      exitg2 = false;
      while ((!exitg2) && (k < 6)) {
        i = 0;
        do {
          exitg1 = 0;
          if (i <= k) {
            absx = fabs(A[i + 6 * k]);
            if (rtIsNaN(absx)) {
              anrm = rtNaN;
              exitg1 = 1;
            } else {
              if (absx > anrm) {
                anrm = absx;
              }
              i++;
            }
          } else {
            k++;
            exitg1 = 2;
          }
        } while (exitg1 == 0);
        if (exitg1 == 1) {
          exitg2 = true;
        }
      }
      if (rtIsInf(anrm) || rtIsNaN(anrm)) {
        for (i = 0; i < 6; i++) {
          a__3[i] = rtNaN;
        }
      } else {
        iscale = false;
        if ((anrm > 0.0) && (anrm < 1.0010415475915505E-146)) {
          iscale = true;
          anrm = 1.0010415475915505E-146 / anrm;
          xzlascl(1.0, anrm, b_A);
        } else if (anrm > 9.9895953610111751E+145) {
          iscale = true;
          anrm = 9.9895953610111751E+145 / anrm;
          xzlascl(1.0, anrm, b_A);
        }
        for (i = 0; i < 5; i++) {
          e_tmp_tmp = i + 6 * i;
          e[i] = b_A[e_tmp_tmp + 1];
          k = i + 3;
          if (k > 6) {
            k = 6;
          }
          taui = xzlarfg(5 - i, &e[i], b_A, i * 6 + k);
          if (taui != 0.0) {
            b_A[e_tmp_tmp + 1] = 1.0;
            for (k = i + 1; k < 6; k++) {
              tau[k - 1] = 0.0;
            }
            b_i = 4 - i;
            i1 = 6 - i;
            for (jj = 0; jj <= b_i; jj++) {
              temp1_tmp = i + jj;
              temp1 = taui * b_A[(temp1_tmp + 6 * i) + 1];
              absx = 0.0;
              tau_tmp = 6 * (temp1_tmp + 1);
              tau[temp1_tmp] += temp1 * b_A[(temp1_tmp + tau_tmp) + 1];
              i2 = jj + 2;
              for (ii = i2; ii < i1; ii++) {
                k = i + ii;
                b_tau_tmp = b_A[k + tau_tmp];
                tau[k - 1] += temp1 * b_tau_tmp;
                absx += b_tau_tmp * b_A[k + 6 * i];
              }
              tau[temp1_tmp] += taui * absx;
            }
            absx = 0.0;
            for (k = 0; k <= b_i; k++) {
              absx += tau[i + k] * b_A[(e_tmp_tmp + k) + 1];
            }
            absx *= -0.5 * taui;
            if (!(absx == 0.0)) {
              i2 = 5 - i;
              scalarLB = ((5 - i) / 2) << 1;
              temp1_tmp = scalarLB - 2;
              for (k = 0; k <= temp1_tmp; k += 2) {
                r = _mm_loadu_pd(&b_A[(e_tmp_tmp + k) + 1]);
                tau_tmp = i + k;
                r1 = _mm_loadu_pd(&tau[tau_tmp]);
                _mm_storeu_pd(&tau[tau_tmp],
                              _mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(absx), r)));
              }
              for (k = scalarLB; k < i2; k++) {
                tau_tmp = i + k;
                tau[tau_tmp] += absx * b_A[(e_tmp_tmp + k) + 1];
              }
            }
            for (jj = 0; jj <= b_i; jj++) {
              temp1_tmp = i + jj;
              temp1 = b_A[(temp1_tmp + 6 * i) + 1];
              absx = tau[temp1_tmp];
              b_tau_tmp = absx * temp1;
              A_tmp_tmp = 6 * (temp1_tmp + 1);
              tau_tmp = (temp1_tmp + A_tmp_tmp) + 1;
              b_A[tau_tmp] = (b_A[tau_tmp] - b_tau_tmp) - b_tau_tmp;
              i2 = jj + 2;
              scalarLB = ((((4 - temp1_tmp) / 2) << 1) + jj) + 2;
              temp1_tmp = scalarLB - 2;
              for (ii = i2; ii <= temp1_tmp; ii += 2) {
                tau_tmp = i + ii;
                r = _mm_loadu_pd(&tau[tau_tmp - 1]);
                k = tau_tmp + A_tmp_tmp;
                r1 = _mm_loadu_pd(&b_A[k]);
                r2 = _mm_loadu_pd(&b_A[tau_tmp + 6 * i]);
                _mm_storeu_pd(
                    &b_A[k],
                    _mm_sub_pd(
                        _mm_sub_pd(r1, _mm_mul_pd(r, _mm_set1_pd(temp1))),
                        _mm_mul_pd(r2, _mm_set1_pd(absx))));
              }
              for (ii = scalarLB; ii < i1; ii++) {
                tau_tmp = i + ii;
                k = tau_tmp + A_tmp_tmp;
                b_A[k] = (b_A[k] - tau[tau_tmp - 1] * temp1) -
                         b_A[tau_tmp + 6 * i] * absx;
              }
            }
          }
          b_A[e_tmp_tmp + 1] = e[i];
          a__3[i] = b_A[e_tmp_tmp];
          tau[i] = taui;
        }
        a__3[5] = b_A[35];
        k = xdsterf(a__3, e);
        if (k != 0) {
          for (i = 0; i < 6; i++) {
            a__3[i] = rtNaN;
          }
        } else if (iscale) {
          r = _mm_loadu_pd(&a__3[0]);
          r1 = _mm_set1_pd(1.0 / anrm);
          _mm_storeu_pd(&a__3[0], _mm_mul_pd(r1, r));
          r = _mm_loadu_pd(&a__3[2]);
          _mm_storeu_pd(&a__3[2], _mm_mul_pd(r1, r));
          r = _mm_loadu_pd(&a__3[4]);
          _mm_storeu_pd(&a__3[4], _mm_mul_pd(r1, r));
        }
      }
      for (i = 0; i < 6; i++) {
        V[i].re = a__3[i];
        V[i].im = 0.0;
      }
    } else {
      iscale = true;
      k = 0;
      exitg2 = false;
      while ((!exitg2) && (k < 6)) {
        i = 0;
        do {
          exitg1 = 0;
          if (i <= k) {
            if (!(A[i + 6 * k] == -A[k + 6 * i])) {
              iscale = false;
              exitg1 = 1;
            } else {
              i++;
            }
          } else {
            k++;
            exitg1 = 2;
          }
        } while (exitg1 == 0);
        if (exitg1 == 1) {
          exitg2 = true;
        }
      }
      if (iscale) {
        memcpy(&b_A[0], &A[0], 36U * sizeof(double));
        xzgehrd(b_A, 1, 6);
        k = xdlahqr(1, 6, b_A, &absx, a__3, wi);
        b_i = (unsigned char)k;
        for (i = 0; i < b_i; i++) {
          V[i].re = rtNaN;
          V[i].im = 0.0;
        }
        b_i = k + 1;
        for (i = b_i; i < 7; i++) {
          V[i - 1].re = 0.0;
          V[i - 1].im = wi[i - 1];
        }
      } else {
        eigStandard(A, V);
      }
    }
  }
}

/*
 * File trailer for eig.c
 *
 * [EOF]
 */
