/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xdlahqr.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 21-May-2025 11:06:32
 */

/* Include Files */
#include "xdlahqr.h"
#include "rt_nonfinite.h"
#include "xdlanv2.h"
#include "xzlarfg.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : int ilo
 *                int ihi
 *                double h[36]
 *                double *z
 *                double wr[6]
 *                double wi[6]
 * Return Type  : int
 */
int xdlahqr(int ilo, int ihi, double h[36], double *z, double wr[6],
            double wi[6])
{
  __m128d r;
  __m128d r1;
  __m128d r2;
  __m128d r3;
  double v[3];
  double aa;
  double d;
  double h21;
  double h22;
  double rt1r;
  double rt2r;
  double s;
  double smlnum;
  double tr;
  double tst;
  int b_i;
  int b_k;
  int c_k;
  int i;
  int i1;
  int i2;
  int info;
  int its;
  int j;
  int k;
  int kdefl;
  int l;
  int m;
  int nr;
  int u0_tmp;
  boolean_T aa_tmp;
  boolean_T converged;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  *z = 1.0;
  info = 0;
  i = (unsigned char)(ilo - 1);
  for (b_i = 0; b_i < i; b_i++) {
    wr[b_i] = h[b_i + 6 * b_i];
    wi[b_i] = 0.0;
  }
  i = ihi + 1;
  for (b_i = i; b_i < 7; b_i++) {
    wr[b_i - 1] = h[(b_i + 6 * (b_i - 1)) - 1];
    wi[b_i - 1] = 0.0;
  }
  if (ilo == ihi) {
    wr[ilo - 1] = h[(ilo + 6 * (ilo - 1)) - 1];
    wi[ilo - 1] = 0.0;
  } else {
    i = ihi - 3;
    for (j = ilo; j <= i; j++) {
      u0_tmp = j + 6 * (j - 1);
      h[u0_tmp + 1] = 0.0;
      h[u0_tmp + 2] = 0.0;
    }
    if (ilo <= ihi - 2) {
      h[(ihi + 6 * (ihi - 3)) - 1] = 0.0;
    }
    smlnum = 2.2250738585072014E-308 *
             ((double)((ihi - ilo) + 1) / 2.2204460492503131E-16);
    kdefl = 0;
    b_i = ihi - 1;
    exitg1 = false;
    while ((!exitg1) && (b_i + 1 >= ilo)) {
      l = ilo;
      converged = false;
      its = 0;
      exitg2 = false;
      while ((!exitg2) && (its < 301)) {
        k = b_i;
        exitg3 = false;
        while ((!exitg3) && (k + 1 > l)) {
          u0_tmp = k + 6 * (k - 1);
          h22 = fabs(h[u0_tmp]);
          if (h22 <= smlnum) {
            exitg3 = true;
          } else {
            nr = k + 6 * k;
            h21 = fabs(h[nr]);
            tst = fabs(h[u0_tmp - 1]) + h21;
            if (tst == 0.0) {
              if (k - 1 >= ilo) {
                tst = fabs(h[(k + 6 * (k - 2)) - 1]);
              }
              if (k + 2 <= ihi) {
                tst += fabs(h[nr + 1]);
              }
            }
            if (h22 <= 2.2204460492503131E-16 * tst) {
              tr = fabs(h[nr - 1]);
              tst = fabs(h[u0_tmp - 1] - h[nr]);
              aa_tmp = rtIsNaN(tst);
              if ((h21 >= tst) || aa_tmp) {
                aa = h21;
              } else {
                aa = tst;
              }
              if ((h21 <= tst) || aa_tmp) {
                tst = h21;
              }
              s = aa + tst;
              tst = 2.2204460492503131E-16 * (tst * (aa / s));
              aa_tmp = rtIsNaN(tr);
              if ((h22 <= tr) || aa_tmp) {
                rt2r = h22;
              } else {
                rt2r = tr;
              }
              if ((h22 >= tr) || aa_tmp) {
                tr = h22;
              }
              if ((smlnum >= tst) || rtIsNaN(tst)) {
                tst = smlnum;
              }
              if (rt2r * (tr / s) <= tst) {
                exitg3 = true;
              } else {
                k--;
              }
            } else {
              k--;
            }
          }
        }
        l = k + 1;
        if (k + 1 > ilo) {
          h[k + 6 * (k - 1)] = 0.0;
        }
        if (k + 1 >= b_i) {
          converged = true;
          exitg2 = true;
        } else {
          kdefl++;
          if (kdefl - kdefl / 20 * 20 == 0) {
            s = fabs(h[b_i + 6 * (b_i - 1)]) +
                fabs(h[(b_i + 6 * (b_i - 2)) - 1]);
            tst = 0.75 * s + h[b_i + 6 * b_i];
            aa = -0.4375 * s;
            h21 = s;
            h22 = tst;
          } else if (kdefl - kdefl / 10 * 10 == 0) {
            u0_tmp = k + 6 * k;
            s = fabs(h[u0_tmp + 1]) + fabs(h[(k + 6 * (k + 1)) + 2]);
            tst = 0.75 * s + h[u0_tmp];
            aa = -0.4375 * s;
            h21 = s;
            h22 = tst;
          } else {
            u0_tmp = b_i + 6 * (b_i - 1);
            tst = h[u0_tmp - 1];
            h21 = h[u0_tmp];
            u0_tmp = b_i + 6 * b_i;
            aa = h[u0_tmp - 1];
            h22 = h[u0_tmp];
          }
          s = ((fabs(tst) + fabs(aa)) + fabs(h21)) + fabs(h22);
          if (s == 0.0) {
            rt1r = 0.0;
            tst = 0.0;
            rt2r = 0.0;
            h21 = 0.0;
          } else {
            tst /= s;
            h21 /= s;
            aa /= s;
            h22 /= s;
            tr = (tst + h22) / 2.0;
            tst = (tst - tr) * (h22 - tr) - aa * h21;
            h21 = sqrt(fabs(tst));
            if (tst >= 0.0) {
              rt1r = tr * s;
              rt2r = rt1r;
              tst = h21 * s;
              h21 = -tst;
            } else {
              rt1r = tr + h21;
              rt2r = tr - h21;
              if (fabs(rt1r - h22) <= fabs(rt2r - h22)) {
                rt1r *= s;
                rt2r = rt1r;
              } else {
                rt2r *= s;
                rt1r = rt2r;
              }
              tst = 0.0;
              h21 = 0.0;
            }
          }
          m = b_i - 1;
          exitg3 = false;
          while ((!exitg3) && (m >= k + 1)) {
            u0_tmp = m + 6 * (m - 1);
            aa = h[u0_tmp - 1];
            tr = aa - rt2r;
            s = (fabs(tr) + fabs(h21)) + fabs(h[u0_tmp]);
            h22 = h[u0_tmp] / s;
            nr = m + 6 * m;
            v[0] = (h22 * h[nr - 1] + tr * (tr / s)) - tst * (h21 / s);
            v[1] = h22 * (((aa + h[nr]) - rt1r) - rt2r);
            v[2] = h22 * h[nr + 1];
            s = (fabs(v[0]) + fabs(v[1])) + fabs(v[2]);
            r = _mm_loadu_pd(&v[0]);
            _mm_storeu_pd(&v[0], _mm_div_pd(r, _mm_set1_pd(s)));
            v[2] /= s;
            if (m == k + 1) {
              exitg3 = true;
            } else {
              i = m + 6 * (m - 2);
              if (fabs(h[i - 1]) * (fabs(v[1]) + fabs(v[2])) <=
                  2.2204460492503131E-16 * fabs(v[0]) *
                      ((fabs(h[i - 2]) + fabs(h[u0_tmp - 1])) + fabs(h[nr]))) {
                exitg3 = true;
              } else {
                m--;
              }
            }
          }
          for (b_k = m; b_k <= b_i; b_k++) {
            u0_tmp = (b_i - b_k) + 2;
            if (u0_tmp >= 3) {
              nr = 3;
            } else {
              nr = u0_tmp;
            }
            if (b_k > m) {
              u0_tmp = ((b_k - 2) * 6 + b_k) - 1;
              for (c_k = 0; c_k < nr; c_k++) {
                v[c_k] = h[u0_tmp + c_k];
              }
            }
            tst = v[0];
            tr = b_xzlarfg(nr, &tst, v);
            if (b_k > m) {
              i = b_k + 6 * (b_k - 2);
              h[i - 1] = tst;
              h[i] = 0.0;
              if (b_k < b_i) {
                h[i + 1] = 0.0;
              }
            } else if (m > k + 1) {
              i = (b_k + 6 * (b_k - 2)) - 1;
              h[i] *= 1.0 - tr;
            }
            h22 = v[1];
            tst = tr * v[1];
            if (nr == 3) {
              rt2r = v[2];
              aa = tr * v[2];
              for (j = b_k; j <= b_i + 1; j++) {
                i = b_k + 6 * (j - 1);
                rt1r = h[i - 1];
                s = h[i];
                d = h[i + 1];
                h21 = (rt1r + h22 * s) + rt2r * d;
                rt1r -= h21 * tr;
                h[i - 1] = rt1r;
                s -= h21 * tst;
                h[i] = s;
                d -= h21 * aa;
                h[i + 1] = d;
              }
              if (b_k + 3 <= b_i + 1) {
                i = b_k;
              } else {
                i = b_i - 2;
              }
              nr = (((((i - k) + 3) / 2) << 1) + k) + 1;
              c_k = nr - 2;
              for (j = k + 1; j <= c_k; j += 2) {
                u0_tmp = (j + 6 * b_k) - 1;
                r = _mm_loadu_pd(&h[u0_tmp]);
                i1 = (j + 6 * (b_k + 1)) - 1;
                r1 = _mm_loadu_pd(&h[i1]);
                i2 = (j + 6 * (b_k - 1)) - 1;
                r2 = _mm_loadu_pd(&h[i2]);
                r3 = _mm_add_pd(_mm_add_pd(r2, _mm_mul_pd(_mm_set1_pd(h22), r)),
                                _mm_mul_pd(_mm_set1_pd(rt2r), r1));
                _mm_storeu_pd(&h[i2],
                              _mm_sub_pd(r2, _mm_mul_pd(r3, _mm_set1_pd(tr))));
                _mm_storeu_pd(&h[u0_tmp],
                              _mm_sub_pd(r, _mm_mul_pd(r3, _mm_set1_pd(tst))));
                _mm_storeu_pd(&h[i1],
                              _mm_sub_pd(r1, _mm_mul_pd(r3, _mm_set1_pd(aa))));
              }
              for (j = nr; j <= i + 3; j++) {
                u0_tmp = (j + 6 * (b_k - 1)) - 1;
                rt1r = h[u0_tmp];
                i1 = (j + 6 * b_k) - 1;
                s = h[i1];
                i2 = (j + 6 * (b_k + 1)) - 1;
                d = h[i2];
                h21 = (rt1r + h22 * s) + rt2r * d;
                rt1r -= h21 * tr;
                h[u0_tmp] = rt1r;
                s -= h21 * tst;
                h[i1] = s;
                d -= h21 * aa;
                h[i2] = d;
              }
            } else if (nr == 2) {
              for (j = b_k; j <= b_i + 1; j++) {
                i = b_k + 6 * (j - 1);
                rt2r = h[i - 1];
                rt1r = h[i];
                h21 = rt2r + h22 * rt1r;
                rt2r -= h21 * tr;
                h[i - 1] = rt2r;
                rt1r -= h21 * tst;
                h[i] = rt1r;
              }
              nr = (((((b_i - k) + 1) / 2) << 1) + k) + 1;
              c_k = nr - 2;
              for (j = k + 1; j <= c_k; j += 2) {
                i = (j + 6 * b_k) - 1;
                r = _mm_loadu_pd(&h[i]);
                u0_tmp = (j + 6 * (b_k - 1)) - 1;
                r1 = _mm_loadu_pd(&h[u0_tmp]);
                r2 = _mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(h22), r));
                _mm_storeu_pd(&h[u0_tmp],
                              _mm_sub_pd(r1, _mm_mul_pd(r2, _mm_set1_pd(tr))));
                _mm_storeu_pd(&h[i],
                              _mm_sub_pd(r, _mm_mul_pd(r2, _mm_set1_pd(tst))));
              }
              for (j = nr; j <= b_i + 1; j++) {
                i = (j + 6 * (b_k - 1)) - 1;
                rt2r = h[i];
                u0_tmp = (j + 6 * b_k) - 1;
                rt1r = h[u0_tmp];
                h21 = rt2r + h22 * rt1r;
                rt2r -= h21 * tr;
                h[i] = rt2r;
                rt1r -= h21 * tst;
                h[u0_tmp] = rt1r;
              }
            }
          }
          its++;
        }
      }
      if (!converged) {
        info = b_i + 1;
        exitg1 = true;
      } else {
        if (l == b_i + 1) {
          wr[b_i] = h[b_i + 6 * b_i];
          wi[b_i] = 0.0;
        } else if (l == b_i) {
          i = b_i + 6 * b_i;
          h22 = h[i - 1];
          u0_tmp = b_i + 6 * (b_i - 1);
          rt2r = h[u0_tmp];
          rt1r = h[i];
          wr[b_i - 1] = xdlanv2(&h[u0_tmp - 1], &h22, &rt2r, &rt1r,
                                &wi[b_i - 1], &s, &d, &tst, &h21);
          wr[b_i] = s;
          wi[b_i] = d;
          h[i - 1] = h22;
          h[u0_tmp] = rt2r;
          h[i] = rt1r;
        }
        kdefl = 0;
        b_i = l - 2;
      }
    }
    if (info != 0) {
      for (j = 0; j < 4; j++) {
        for (b_i = j + 3; b_i < 7; b_i++) {
          h[(b_i + 6 * j) - 1] = 0.0;
        }
      }
    }
  }
  return info;
}

/*
 * File trailer for xdlahqr.c
 *
 * [EOF]
 */
