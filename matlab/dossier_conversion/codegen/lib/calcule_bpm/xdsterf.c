/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xdsterf.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 21-May-2025 11:06:32
 */

/* Include Files */
#include "xdsterf.h"
#include "insertionsort.h"
#include "rt_nonfinite.h"
#include "xdlaev2.h"
#include "xzlascl.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : double d[6]
 *                double e[5]
 * Return Type  : int
 */
int xdsterf(double d[6], double e[5])
{
  __m128d r;
  double anorm;
  double b_anorm;
  double b_d;
  double b_gamma;
  double b_r;
  double c;
  double oldc;
  double rte;
  double s;
  double sigma;
  int anorm_tmp;
  int exitg1;
  int exitg3;
  int exitg4;
  int i;
  int info;
  int iscale;
  int jtot;
  int l;
  int l1;
  int lend;
  int lendsv_tmp;
  int lsv;
  int m;
  int n_tmp;
  boolean_T exitg2;
  info = 0;
  jtot = 0;
  l1 = 1;
  do {
    exitg1 = 0;
    if (l1 > 6) {
      b_insertionsort(d);
      exitg1 = 1;
    } else {
      if (l1 > 1) {
        e[l1 - 2] = 0.0;
      }
      m = l1;
      exitg2 = false;
      while ((!exitg2) && (m < 6)) {
        if (fabs(e[m - 1]) <=
            sqrt(fabs(d[m - 1])) * sqrt(fabs(d[m])) * 2.2204460492503131E-16) {
          e[m - 1] = 0.0;
          exitg2 = true;
        } else {
          m++;
        }
      }
      l = l1;
      lsv = l1;
      lend = m;
      lendsv_tmp = m + 1;
      l1 = m + 1;
      if (m != l) {
        n_tmp = m - l;
        if (n_tmp + 1 <= 0) {
          anorm = 0.0;
        } else {
          anorm = fabs(d[(l + n_tmp) - 1]);
          i = -1;
          exitg2 = false;
          while ((!exitg2) && (i + 1 <= n_tmp - 1)) {
            anorm_tmp = l + i;
            b_anorm = fabs(d[anorm_tmp]);
            if (rtIsNaN(b_anorm)) {
              anorm = rtNaN;
              exitg2 = true;
            } else {
              if (b_anorm > anorm) {
                anorm = b_anorm;
              }
              b_anorm = fabs(e[anorm_tmp]);
              if (rtIsNaN(b_anorm)) {
                anorm = rtNaN;
                exitg2 = true;
              } else {
                if (b_anorm > anorm) {
                  anorm = b_anorm;
                }
                i++;
              }
            }
          }
        }
        if (!(anorm == 0.0)) {
          iscale = 0;
          if (anorm > 2.2346346549904327E+153) {
            iscale = 1;
            b_xzlascl(anorm, 2.2346346549904327E+153, n_tmp + 1, d, l);
            c_xzlascl(anorm, 2.2346346549904327E+153, n_tmp, e, l);
          } else if (anorm < 3.02546243347603E-123) {
            iscale = 2;
            b_xzlascl(anorm, 3.02546243347603E-123, n_tmp + 1, d, l);
            c_xzlascl(anorm, 3.02546243347603E-123, n_tmp, e, l);
          }
          anorm_tmp = ((n_tmp / 2) << 1) + l;
          n_tmp = anorm_tmp - 2;
          for (i = l; i <= n_tmp; i += 2) {
            r = _mm_loadu_pd(&e[i - 1]);
            _mm_storeu_pd(&e[i - 1], _mm_mul_pd(r, r));
          }
          for (i = anorm_tmp; i < m; i++) {
            b_anorm = e[i - 1];
            e[i - 1] = b_anorm * b_anorm;
          }
          if (fabs(d[m - 1]) < fabs(d[l - 1])) {
            lend = lsv;
            l = m;
          }
          if (lend >= l) {
            do {
              exitg4 = 0;
              if (l != lend) {
                m = l;
                while ((m < lend) &&
                       (!(fabs(e[m - 1]) <= 4.9303806576313238E-32 *
                                                fabs(d[m - 1]) * fabs(d[m])))) {
                  m++;
                }
              } else {
                m = lend;
              }
              if (m < lend) {
                e[m - 1] = 0.0;
              }
              if (m == l) {
                l++;
                if (l > lend) {
                  exitg4 = 1;
                }
              } else if (m == l + 1) {
                d[l - 1] = xdlaev2(d[l - 1], sqrt(e[l - 1]), d[l], &b_d);
                d[l] = b_d;
                e[l - 1] = 0.0;
                l += 2;
                if (l > lend) {
                  exitg4 = 1;
                }
              } else if (jtot == 180) {
                exitg4 = 1;
              } else {
                jtot++;
                rte = sqrt(e[l - 1]);
                c = d[l - 1];
                sigma = (d[l] - c) / (2.0 * rte);
                b_anorm = fabs(sigma);
                if (b_anorm < 1.0) {
                  b_anorm = sqrt(b_anorm * b_anorm + 1.0);
                } else if (b_anorm > 1.0) {
                  b_r = 1.0 / b_anorm;
                  b_anorm *= sqrt(b_r * b_r + 1.0);
                } else {
                  b_anorm *= 1.4142135623730951;
                }
                if (!(sigma >= 0.0)) {
                  b_anorm = -b_anorm;
                }
                sigma = c - rte / (sigma + b_anorm);
                c = 1.0;
                s = 0.0;
                b_gamma = d[m - 1] - sigma;
                b_anorm = b_gamma * b_gamma;
                anorm_tmp = m - 1;
                for (i = anorm_tmp; i >= l; i--) {
                  b_d = e[i - 1];
                  b_r = b_anorm + b_d;
                  if (i != m - 1) {
                    e[i] = s * b_r;
                  }
                  oldc = c;
                  c = b_anorm / b_r;
                  s = b_d / b_r;
                  b_anorm = b_gamma;
                  rte = d[i - 1];
                  b_gamma = c * (rte - sigma) - s * b_gamma;
                  d[i] = b_anorm + (rte - b_gamma);
                  if (c != 0.0) {
                    b_anorm = b_gamma * b_gamma / c;
                  } else {
                    b_anorm = oldc * b_d;
                  }
                }
                e[l - 1] = s * b_anorm;
                d[l - 1] = sigma + b_gamma;
              }
            } while (exitg4 == 0);
          } else {
            do {
              exitg3 = 0;
              m = l;
              while ((m > lend) && (!(fabs(e[m - 2]) <= 4.9303806576313238E-32 *
                                                            fabs(d[m - 1]) *
                                                            fabs(d[m - 2])))) {
                m--;
              }
              if (m > lend) {
                e[m - 2] = 0.0;
              }
              if (m == l) {
                l--;
                if (l < lend) {
                  exitg3 = 1;
                }
              } else if (m == l - 1) {
                d[l - 1] = xdlaev2(d[l - 1], sqrt(e[l - 2]), d[l - 2], &b_d);
                d[l - 2] = b_d;
                e[l - 2] = 0.0;
                l -= 2;
                if (l < lend) {
                  exitg3 = 1;
                }
              } else if (jtot == 180) {
                exitg3 = 1;
              } else {
                jtot++;
                rte = sqrt(e[l - 2]);
                c = d[l - 1];
                sigma = (d[l - 2] - c) / (2.0 * rte);
                b_anorm = fabs(sigma);
                if (b_anorm < 1.0) {
                  b_anorm = sqrt(b_anorm * b_anorm + 1.0);
                } else if (b_anorm > 1.0) {
                  b_r = 1.0 / b_anorm;
                  b_anorm *= sqrt(b_r * b_r + 1.0);
                } else {
                  b_anorm *= 1.4142135623730951;
                }
                if (!(sigma >= 0.0)) {
                  b_anorm = -b_anorm;
                }
                sigma = c - rte / (sigma + b_anorm);
                c = 1.0;
                s = 0.0;
                b_gamma = d[m - 1] - sigma;
                b_anorm = b_gamma * b_gamma;
                for (i = m; i < l; i++) {
                  b_d = e[i - 1];
                  b_r = b_anorm + b_d;
                  if (i != m) {
                    e[i - 2] = s * b_r;
                  }
                  oldc = c;
                  c = b_anorm / b_r;
                  s = b_d / b_r;
                  b_anorm = b_gamma;
                  b_gamma = c * (d[i] - sigma) - s * b_gamma;
                  d[i - 1] = b_anorm + (d[i] - b_gamma);
                  if (c != 0.0) {
                    b_anorm = b_gamma * b_gamma / c;
                  } else {
                    b_anorm = oldc * b_d;
                  }
                }
                e[l - 2] = s * b_anorm;
                d[l - 1] = sigma + b_gamma;
              }
            } while (exitg3 == 0);
          }
          if (iscale == 1) {
            b_xzlascl(2.2346346549904327E+153, anorm, lendsv_tmp - lsv, d, lsv);
          } else if (iscale == 2) {
            b_xzlascl(3.02546243347603E-123, anorm, lendsv_tmp - lsv, d, lsv);
          }
          if (jtot >= 180) {
            for (i = 0; i < 5; i++) {
              if (e[i] != 0.0) {
                info++;
              }
            }
            exitg1 = 1;
          }
        }
      }
    }
  } while (exitg1 == 0);
  return info;
}

/*
 * File trailer for xdsterf.c
 *
 * [EOF]
 */
