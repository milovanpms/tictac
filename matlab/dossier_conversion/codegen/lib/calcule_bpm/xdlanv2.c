/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xdlanv2.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 21-May-2025 11:06:32
 */

/* Include Files */
#include "xdlanv2.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : double *a
 *                double *b
 *                double *c
 *                double *d
 *                double *rt1i
 *                double *rt2r
 *                double *rt2i
 *                double *cs
 *                double *sn
 * Return Type  : double
 */
double xdlanv2(double *a, double *b, double *c, double *d, double *rt1i,
               double *rt2r, double *rt2i, double *cs, double *sn)
{
  double bcmax;
  double bcmis;
  double p;
  double rt1r;
  double scale;
  double sigma;
  double tau;
  double z;
  int count;
  int i;
  boolean_T bcmax_tmp;
  if (*c == 0.0) {
    *cs = 1.0;
    *sn = 0.0;
  } else if (*b == 0.0) {
    *cs = 0.0;
    *sn = 1.0;
    rt1r = *d;
    *d = *a;
    *a = rt1r;
    *b = -*c;
    *c = 0.0;
  } else {
    rt1r = *a - *d;
    if ((rt1r == 0.0) && ((*b < 0.0) != (*c < 0.0))) {
      *cs = 1.0;
      *sn = 0.0;
    } else {
      p = 0.5 * rt1r;
      bcmis = fabs(*b);
      sigma = fabs(*c);
      bcmax_tmp = rtIsNaN(sigma);
      if ((bcmis >= sigma) || bcmax_tmp) {
        bcmax = bcmis;
      } else {
        bcmax = sigma;
      }
      if ((!(bcmis <= sigma)) && (!bcmax_tmp)) {
        bcmis = sigma;
      }
      if (!(*b < 0.0)) {
        count = 1;
      } else {
        count = -1;
      }
      if (!(*c < 0.0)) {
        i = 1;
      } else {
        i = -1;
      }
      bcmis = bcmis * (double)count * (double)i;
      scale = fabs(p);
      if ((!(scale >= bcmax)) && (!rtIsNaN(bcmax))) {
        scale = bcmax;
      }
      z = p / scale * p + bcmax / scale * bcmis;
      if (z >= 8.8817841970012523E-16) {
        *a = sqrt(scale) * sqrt(z);
        if (!(p < 0.0)) {
          rt1r = *a;
        } else {
          rt1r = -*a;
        }
        z = p + rt1r;
        *a = *d + z;
        *d -= bcmax / z * bcmis;
        bcmax = fabs(z);
        if (sigma < bcmax) {
          scale = sigma / bcmax;
          tau = bcmax * sqrt(scale * scale + 1.0);
        } else if (sigma > bcmax) {
          bcmax /= sigma;
          tau = sigma * sqrt(bcmax * bcmax + 1.0);
        } else if (rtIsNaN(bcmax)) {
          tau = rtNaN;
        } else {
          tau = sigma * 1.4142135623730951;
        }
        *cs = z / tau;
        *sn = *c / tau;
        *b -= *c;
        *c = 0.0;
      } else {
        sigma = *b + *c;
        scale = fabs(rt1r);
        bcmis = fabs(sigma);
        if ((!(scale >= bcmis)) && (!rtIsNaN(bcmis))) {
          scale = bcmis;
        }
        count = 0;
        while ((scale >= 7.4428285367870146E+137) && (count <= 20)) {
          sigma *= 1.3435752215134178E-138;
          rt1r *= 1.3435752215134178E-138;
          scale = fabs(rt1r);
          bcmis = fabs(sigma);
          if ((!(scale >= bcmis)) && (!rtIsNaN(bcmis))) {
            scale = bcmis;
          }
          count++;
        }
        while ((scale <= 1.3435752215134178E-138) && (count <= 20)) {
          sigma *= 7.4428285367870146E+137;
          rt1r *= 7.4428285367870146E+137;
          scale = fabs(rt1r);
          bcmis = fabs(sigma);
          if ((!(scale >= bcmis)) && (!rtIsNaN(bcmis))) {
            scale = bcmis;
          }
          count++;
        }
        bcmis = fabs(sigma);
        bcmax = fabs(rt1r);
        if (bcmis < bcmax) {
          scale = bcmis / bcmax;
          tau = bcmax * sqrt(scale * scale + 1.0);
        } else if (bcmis > bcmax) {
          bcmax /= bcmis;
          tau = bcmis * sqrt(bcmax * bcmax + 1.0);
        } else if (rtIsNaN(bcmax)) {
          tau = rtNaN;
        } else {
          tau = bcmis * 1.4142135623730951;
        }
        *cs = sqrt(0.5 * (bcmis / tau + 1.0));
        if (!(sigma < 0.0)) {
          count = 1;
        } else {
          count = -1;
        }
        *sn = -(0.5 * rt1r / (tau * *cs)) * (double)count;
        sigma = *a * *cs + *b * *sn;
        scale = -*a * *sn + *b * *cs;
        bcmax = *c * *cs + *d * *sn;
        bcmis = -*c * *sn + *d * *cs;
        *b = scale * *cs + bcmis * *sn;
        *c = -sigma * *sn + bcmax * *cs;
        rt1r =
            0.5 * ((sigma * *cs + bcmax * *sn) + (-scale * *sn + bcmis * *cs));
        *a = rt1r;
        *d = rt1r;
        if (*c != 0.0) {
          if (*b != 0.0) {
            if ((*b < 0.0) == (*c < 0.0)) {
              bcmis = sqrt(fabs(*b));
              bcmax = sqrt(fabs(*c));
              *a = bcmis * bcmax;
              if (!(*c < 0.0)) {
                p = *a;
              } else {
                p = -*a;
              }
              tau = 1.0 / sqrt(fabs(*b + *c));
              *a = rt1r + p;
              *d = rt1r - p;
              *b -= *c;
              *c = 0.0;
              scale = bcmis * tau;
              bcmis = bcmax * tau;
              rt1r = *cs * scale - *sn * bcmis;
              *sn = *cs * bcmis + *sn * scale;
              *cs = rt1r;
            }
          } else {
            *b = -*c;
            *c = 0.0;
            rt1r = *cs;
            *cs = -*sn;
            *sn = rt1r;
          }
        }
      }
    }
  }
  rt1r = *a;
  *rt2r = *d;
  if (*c == 0.0) {
    *rt1i = 0.0;
    *rt2i = 0.0;
  } else {
    *rt1i = sqrt(fabs(*b)) * sqrt(fabs(*c));
    *rt2i = -*rt1i;
  }
  return rt1r;
}

/*
 * File trailer for xdlanv2.c
 *
 * [EOF]
 */
