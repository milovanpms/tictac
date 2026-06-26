/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: eigStandard.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 21-May-2025 11:06:32
 */

/* Include Files */
#include "eigStandard.h"
#include "rt_nonfinite.h"
#include "xdlahqr.h"
#include "xnrm2.h"
#include "xzgehrd.h"
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
void eigStandard(const double A[36], creal_T V[6])
{
  __m128d b_r;
  double b_A[36];
  double wi[6];
  double wr[6];
  double absxk;
  double anrm;
  double c;
  double ca;
  double cscale;
  double f;
  double r;
  double s;
  double scale;
  double t;
  double u0;
  int b_i;
  int b_ix0_tmp;
  int b_k;
  int exitg2;
  int exitg3;
  int exitg4;
  int exitg5;
  int i;
  int ira;
  int ix0_tmp;
  int j;
  int k;
  int kend;
  int l;
  boolean_T converged;
  boolean_T exitg1;
  boolean_T exitg6;
  boolean_T exitg7;
  boolean_T notdone;
  boolean_T scalea;
  memcpy(&b_A[0], &A[0], 36U * sizeof(double));
  anrm = 0.0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 36)) {
    absxk = fabs(A[k]);
    if (rtIsNaN(absxk)) {
      anrm = rtNaN;
      exitg1 = true;
    } else {
      if (absxk > anrm) {
        anrm = absxk;
      }
      k++;
    }
  }
  if (rtIsInf(anrm) || rtIsNaN(anrm)) {
    for (i = 0; i < 6; i++) {
      V[i].re = rtNaN;
      V[i].im = 0.0;
    }
  } else {
    cscale = anrm;
    scalea = false;
    if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
      scalea = true;
      cscale = 6.7178761075670888E-139;
      xzlascl(anrm, cscale, b_A);
    } else if (anrm > 1.4885657073574029E+138) {
      scalea = true;
      cscale = 1.4885657073574029E+138;
      xzlascl(anrm, cscale, b_A);
    }
    for (i = 0; i < 6; i++) {
      wr[i] = 1.0;
    }
    k = 1;
    l = 6;
    notdone = true;
    do {
      exitg5 = 0;
      if (notdone) {
        notdone = false;
        j = l;
        do {
          exitg4 = 0;
          if (j > 0) {
            converged = false;
            i = 0;
            exitg6 = false;
            while ((!exitg6) && (i <= (unsigned char)l - 1)) {
              if ((i + 1 == j) || (!(b_A[(j + 6 * i) - 1] != 0.0))) {
                i++;
              } else {
                converged = true;
                exitg6 = true;
              }
            }
            if (converged) {
              j--;
            } else {
              wr[l - 1] = j;
              if (j != l) {
                ira = (j - 1) * 6;
                kend = (l - 1) * 6;
                b_i = (unsigned char)l;
                for (b_k = 0; b_k < b_i; b_k++) {
                  ix0_tmp = ira + b_k;
                  absxk = b_A[ix0_tmp];
                  b_ix0_tmp = kend + b_k;
                  b_A[ix0_tmp] = b_A[b_ix0_tmp];
                  b_A[b_ix0_tmp] = absxk;
                }
                for (b_k = 0; b_k < 6; b_k++) {
                  ix0_tmp = (j + b_k * 6) - 1;
                  absxk = b_A[ix0_tmp];
                  b_ix0_tmp = (l + b_k * 6) - 1;
                  b_A[ix0_tmp] = b_A[b_ix0_tmp];
                  b_A[b_ix0_tmp] = absxk;
                }
              }
              exitg4 = 1;
            }
          } else {
            exitg4 = 2;
          }
        } while (exitg4 == 0);
        if (exitg4 == 1) {
          if (l == 1) {
            k = 1;
            l = 1;
            exitg5 = 1;
          } else {
            l--;
            notdone = true;
          }
        }
      } else {
        notdone = true;
        while (notdone) {
          notdone = false;
          j = k;
          exitg6 = false;
          while ((!exitg6) && (j <= l)) {
            converged = false;
            i = k;
            exitg7 = false;
            while ((!exitg7) && (i <= l)) {
              if ((i == j) || (!(b_A[(i + 6 * (j - 1)) - 1] != 0.0))) {
                i++;
              } else {
                converged = true;
                exitg7 = true;
              }
            }
            if (converged) {
              j++;
            } else {
              wr[k - 1] = j;
              if (j != k) {
                ira = (j - 1) * 6;
                kend = (k - 1) * 6;
                b_i = (unsigned char)l;
                for (b_k = 0; b_k < b_i; b_k++) {
                  ix0_tmp = ira + b_k;
                  absxk = b_A[ix0_tmp];
                  b_ix0_tmp = kend + b_k;
                  b_A[ix0_tmp] = b_A[b_ix0_tmp];
                  b_A[b_ix0_tmp] = absxk;
                }
                ira = (kend + j) - 1;
                kend = (kend + k) - 1;
                b_i = (unsigned char)(7 - k);
                for (b_k = 0; b_k < b_i; b_k++) {
                  ix0_tmp = ira + b_k * 6;
                  absxk = b_A[ix0_tmp];
                  b_ix0_tmp = kend + b_k * 6;
                  b_A[ix0_tmp] = b_A[b_ix0_tmp];
                  b_A[b_ix0_tmp] = absxk;
                }
              }
              k++;
              notdone = true;
              exitg6 = true;
            }
          }
        }
        converged = false;
        exitg5 = 2;
      }
    } while (exitg5 == 0);
    if (exitg5 != 1) {
      exitg1 = false;
      while ((!exitg1) && (!converged)) {
        converged = true;
        i = k - 1;
        do {
          exitg3 = 0;
          if (i + 1 <= l) {
            kend = (l - k) + 1;
            c = xnrm2(kend, b_A, i * 6 + k);
            ix0_tmp = (k - 1) * 6 + i;
            r = 0.0;
            if (kend >= 1) {
              if (kend == 1) {
                r = fabs(b_A[ix0_tmp]);
              } else {
                scale = 3.3121686421112381E-170;
                kend = (ix0_tmp + (kend - 1) * 6) + 1;
                for (b_k = ix0_tmp + 1; b_k <= kend; b_k += 6) {
                  absxk = fabs(b_A[b_k - 1]);
                  if (absxk > scale) {
                    t = scale / absxk;
                    r = r * t * t + 1.0;
                    scale = absxk;
                  } else {
                    t = absxk / scale;
                    r += t * t;
                  }
                }
                r = scale * sqrt(r);
              }
            }
            b_ix0_tmp = i * 6;
            kend = 1;
            if (l > 1) {
              absxk = fabs(b_A[b_ix0_tmp]);
              for (b_k = 2; b_k <= l; b_k++) {
                s = fabs(b_A[(b_ix0_tmp + b_k) - 1]);
                if (s > absxk) {
                  kend = b_k;
                  absxk = s;
                }
              }
            }
            ca = fabs(b_A[(kend + 6 * i) - 1]);
            kend = 7 - k;
            if (7 - k < 1) {
              ira = 0;
            } else {
              ira = 1;
              if (7 - k > 1) {
                absxk = fabs(b_A[ix0_tmp]);
                for (b_k = 2; b_k <= kend; b_k++) {
                  s = fabs(b_A[ix0_tmp + (b_k - 1) * 6]);
                  if (s > absxk) {
                    ira = b_k;
                    absxk = s;
                  }
                }
              }
            }
            absxk = fabs(b_A[i + 6 * ((ira + k) - 2)]);
            if ((c == 0.0) || (r == 0.0)) {
              i++;
            } else {
              scale = r / 2.0;
              f = 1.0;
              s = c + r;
              do {
                exitg2 = 0;
                if (c < scale) {
                  if ((c >= ca) || rtIsNaN(ca)) {
                    t = c;
                  } else {
                    t = ca;
                  }
                  if (f >= t) {
                    t = f;
                  }
                  if (t < 4.9896007738368E+291) {
                    if ((scale <= absxk) || rtIsNaN(absxk)) {
                      t = scale;
                    } else {
                      t = absxk;
                    }
                    if (r <= t) {
                      t = r;
                    }
                    if (t > 2.0041683600089728E-292) {
                      if (rtIsNaN(((((c + f) + ca) + r) + scale) + absxk)) {
                        exitg2 = 1;
                      } else {
                        f *= 2.0;
                        c *= 2.0;
                        ca *= 2.0;
                        r /= 2.0;
                        scale /= 2.0;
                        absxk /= 2.0;
                      }
                    } else {
                      exitg2 = 2;
                    }
                  } else {
                    exitg2 = 2;
                  }
                } else {
                  exitg2 = 2;
                }
              } while (exitg2 == 0);
              if (exitg2 == 1) {
                exitg3 = 2;
              } else {
                scale = c / 2.0;
                exitg6 = false;
                while ((!exitg6) && (scale >= r)) {
                  if ((r >= absxk) || rtIsNaN(absxk)) {
                    t = r;
                  } else {
                    t = absxk;
                  }
                  if (t < 4.9896007738368E+291) {
                    if ((f <= c) || rtIsNaN(c)) {
                      u0 = f;
                    } else {
                      u0 = c;
                    }
                    if ((scale <= ca) || rtIsNaN(ca)) {
                      t = scale;
                    } else {
                      t = ca;
                    }
                    if (u0 <= t) {
                      t = u0;
                    }
                    if (t > 2.0041683600089728E-292) {
                      f /= 2.0;
                      c /= 2.0;
                      scale /= 2.0;
                      ca /= 2.0;
                      r *= 2.0;
                      absxk *= 2.0;
                    } else {
                      exitg6 = true;
                    }
                  } else {
                    exitg6 = true;
                  }
                }
                if ((!(c + r >= 0.95 * s)) &&
                    ((!(f < 1.0)) || (!(wr[i] < 1.0)) ||
                     (!(f * wr[i] <= 1.0020841800044864E-292))) &&
                    ((!(f > 1.0)) || (!(wr[i] > 1.0)) ||
                     (!(wr[i] >= 9.9792015476736E+291 / f)))) {
                  absxk = 1.0 / f;
                  wr[i] *= f;
                  kend = ix0_tmp + 1;
                  b_i = (ix0_tmp + 6 * (6 - k)) + 1;
                  for (b_k = kend; b_k <= b_i; b_k += 6) {
                    b_A[b_k - 1] *= absxk;
                  }
                  b_i = b_ix0_tmp + l;
                  kend = ((((b_i - b_ix0_tmp) / 2) << 1) + b_ix0_tmp) + 1;
                  ira = kend - 2;
                  for (b_k = b_ix0_tmp + 1; b_k <= ira; b_k += 2) {
                    b_r = _mm_loadu_pd(&b_A[b_k - 1]);
                    _mm_storeu_pd(&b_A[b_k - 1],
                                  _mm_mul_pd(_mm_set1_pd(f), b_r));
                  }
                  for (b_k = kend; b_k <= b_i; b_k++) {
                    b_A[b_k - 1] *= f;
                  }
                  converged = false;
                }
                i++;
              }
            }
          } else {
            exitg3 = 1;
          }
        } while (exitg3 == 0);
        if (exitg3 != 1) {
          exitg1 = true;
        }
      }
    }
    xzgehrd(b_A, k, l);
    kend = xdlahqr(k, l, b_A, &absxk, wr, wi);
    if (scalea) {
      b_xzlascl(cscale, anrm, 6 - kend, wr, kend + 1);
      b_xzlascl(cscale, anrm, 6 - kend, wi, kend + 1);
      if (kend != 0) {
        b_xzlascl(cscale, anrm, k - 1, wr, 1);
        b_xzlascl(cscale, anrm, k - 1, wi, 1);
      }
    }
    if (kend != 0) {
      for (i = k; i <= kend; i++) {
        wr[i - 1] = rtNaN;
        wi[i - 1] = 0.0;
      }
    }
    for (i = 0; i < 6; i++) {
      V[i].re = wr[i];
      V[i].im = wi[i];
    }
  }
}

/*
 * File trailer for eigStandard.c
 *
 * [EOF]
 */
