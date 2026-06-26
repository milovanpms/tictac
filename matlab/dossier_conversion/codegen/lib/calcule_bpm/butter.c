/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: butter.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 21-May-2025 11:06:32
 */

/* Include Files */
#include "butter.h"
#include "eig.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double Wn[2]
 *                double varargout_1[7]
 *                double varargout_2[7]
 * Return Type  : void
 */
void butter(const double Wn[2], double varargout_1[7], double varargout_2[7])
{
  static const signed char iv[18] = {-1, 0, 0, 0, -1, 0, 0, 0, -1,
                                     0,  0, 0, 0, 0,  0, 0, 0, 0};
  static const signed char iv1[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  static const signed char b[7] = {1, 0, -3, 0, 3, 0, -1};
  static const signed char iv2[6] = {1, 1, 1, -1, -1, -1};
  __m128d r;
  __m128d r1;
  creal_T b_c[7];
  creal_T p[6];
  creal_T x[6];
  creal_T c[3];
  double b_t1_tmp[36];
  double t1[36];
  double t1_tmp[36];
  double a[9];
  double b_a[4];
  double Wn1;
  double q;
  double re_tmp;
  double s;
  double u_idx_0;
  double u_idx_1;
  double x_re;
  int b_tmp;
  int i;
  int i1;
  int j;
  int jA;
  int jBcol;
  int jp1j;
  int k;
  int mmj_tmp;
  int temp_tmp;
  signed char ipiv[6];
  signed char b1[2];
  signed char i2;
  u_idx_0 = 4.0 * tan(3.1415926535897931 * Wn[0] / 2.0);
  u_idx_1 = 4.0 * tan(3.1415926535897931 * Wn[1] / 2.0);
  memset(&a[0], 0, 9U * sizeof(double));
  a[0] = -1.0;
  c[0].re = 1.0;
  c[0].im = 0.0;
  for (j = 0; j < 2; j++) {
    q = 1.7320508075688774 * (double)j - 0.86602540378443871;
    s = c[j].im;
    re_tmp = c[j].re;
    c[j + 1].re = 0.49999999999999978 * re_tmp - -q * s;
    c[j + 1].im = 0.49999999999999978 * s + -q * re_tmp;
    for (k = j + 1; k >= 2; k--) {
      c[1].re -= -0.49999999999999978 * c[0].re - q * c[0].im;
      c[1].im -= -0.49999999999999978 * c[0].im + q * c[0].re;
    }
  }
  s = 1.0 - -c[1].re * 0.0;
  b_a[1] = s;
  b_a[0] = -c[1].re - s * 0.0;
  s = 0.0 - -c[2].re * 0.0;
  b_a[3] = s;
  b_a[2] = -c[2].re - s * 0.0;
  b1[1] = 0;
  b1[0] = 1;
  for (i = 0; i < 2; i++) {
    a[i + 1] = b1[i];
    s = b_a[i + 2];
    q = b_a[i];
    a[i + 4] = q + s * 0.0;
    a[i + 7] = q * 0.0 + s;
  }
  Wn1 = sqrt(u_idx_0 * u_idx_1);
  q = Wn1 / (u_idx_1 - u_idx_0);
  memset(&t1_tmp[0], 0, 36U * sizeof(double));
  for (k = 0; k < 6; k++) {
    t1_tmp[k + 6 * k] = 1.0;
  }
  for (i = 0; i < 3; i++) {
    b_t1_tmp[6 * i] = Wn1 * (a[3 * i] / q) * 0.5 / 2.0;
    jBcol = 6 * (i + 3);
    b_t1_tmp[jBcol] = Wn1 * (double)iv1[3 * i] * 0.5 / 2.0;
    jA = 3 * i + 1;
    b_t1_tmp[6 * i + 1] = Wn1 * (a[jA] / q) * 0.5 / 2.0;
    b_t1_tmp[jBcol + 1] = Wn1 * (double)iv1[jA] * 0.5 / 2.0;
    jA = 3 * i + 2;
    b_t1_tmp[6 * i + 2] = Wn1 * (a[jA] / q) * 0.5 / 2.0;
    b_t1_tmp[jBcol + 2] = Wn1 * (double)iv1[jA] * 0.5 / 2.0;
  }
  for (i = 0; i < 6; i++) {
    b_t1_tmp[6 * i + 3] = Wn1 * (double)iv[3 * i] * 0.5 / 2.0;
    b_t1_tmp[6 * i + 4] = Wn1 * (double)iv[3 * i + 1] * 0.5 / 2.0;
    b_t1_tmp[6 * i + 5] = Wn1 * (double)iv[3 * i + 2] * 0.5 / 2.0;
  }
  for (i = 0; i <= 34; i += 2) {
    r = _mm_loadu_pd(&t1_tmp[i]);
    r1 = _mm_loadu_pd(&b_t1_tmp[i]);
    _mm_storeu_pd(&t1[i], _mm_add_pd(r, r1));
    _mm_storeu_pd(&t1_tmp[i], _mm_sub_pd(r, r1));
  }
  for (i = 0; i < 6; i++) {
    ipiv[i] = (signed char)(i + 1);
  }
  for (j = 0; j < 5; j++) {
    mmj_tmp = 4 - j;
    b_tmp = j * 7;
    jp1j = b_tmp + 2;
    jA = 7 - j;
    jBcol = 0;
    q = fabs(t1_tmp[b_tmp]);
    for (k = 2; k < jA; k++) {
      s = fabs(t1_tmp[(b_tmp + k) - 1]);
      if (s > q) {
        jBcol = k - 1;
        q = s;
      }
    }
    if (t1_tmp[b_tmp + jBcol] != 0.0) {
      if (jBcol != 0) {
        jA = j + jBcol;
        ipiv[j] = (signed char)(jA + 1);
        for (k = 0; k < 6; k++) {
          temp_tmp = j + k * 6;
          q = t1_tmp[temp_tmp];
          jBcol = jA + k * 6;
          t1_tmp[temp_tmp] = t1_tmp[jBcol];
          t1_tmp[jBcol] = q;
        }
      }
      i = (b_tmp - j) + 6;
      for (temp_tmp = jp1j; temp_tmp <= i; temp_tmp++) {
        t1_tmp[temp_tmp - 1] /= t1_tmp[b_tmp];
      }
    }
    jA = b_tmp;
    for (jp1j = 0; jp1j <= mmj_tmp; jp1j++) {
      q = t1_tmp[(b_tmp + jp1j * 6) + 6];
      if (q != 0.0) {
        i = jA + 8;
        i1 = (jA - j) + 12;
        for (jBcol = i; jBcol <= i1; jBcol++) {
          t1_tmp[jBcol - 1] += t1_tmp[((b_tmp + jBcol) - jA) - 7] * -q;
        }
      }
      jA += 6;
    }
    i2 = ipiv[j];
    if (i2 != j + 1) {
      for (jp1j = 0; jp1j < 6; jp1j++) {
        temp_tmp = j + 6 * jp1j;
        q = t1[temp_tmp];
        mmj_tmp = (i2 + 6 * jp1j) - 1;
        t1[temp_tmp] = t1[mmj_tmp];
        t1[mmj_tmp] = q;
      }
    }
  }
  for (j = 0; j < 6; j++) {
    jBcol = 6 * j;
    for (k = 0; k < 6; k++) {
      jA = 6 * k;
      i = k + jBcol;
      if (t1[i] != 0.0) {
        i1 = k + 2;
        for (temp_tmp = i1; temp_tmp < 7; temp_tmp++) {
          mmj_tmp = (temp_tmp + jBcol) - 1;
          t1[mmj_tmp] -= t1[i] * t1_tmp[(temp_tmp + jA) - 1];
        }
      }
    }
  }
  for (j = 0; j < 6; j++) {
    jBcol = 6 * j;
    for (k = 5; k >= 0; k--) {
      jA = 6 * k;
      i = k + jBcol;
      s = t1[i];
      if (s != 0.0) {
        t1[i] = s / t1_tmp[k + jA];
        for (temp_tmp = 0; temp_tmp < k; temp_tmp++) {
          mmj_tmp = temp_tmp + jBcol;
          t1[mmj_tmp] -= t1[i] * t1_tmp[temp_tmp + jA];
        }
      }
    }
  }
  eig(t1, p);
  if (rtIsNaN(Wn1)) {
    q = rtNaN;
  } else {
    q = atan2(Wn1, 4.0);
  }
  Wn1 = 2.0 * q;
  if (2.0 * q * 0.0 == 0.0) {
    u_idx_0 = cos(Wn1);
    Wn1 = sin(Wn1);
  } else if (Wn1 == 0.0) {
    u_idx_0 = rtNaN;
    Wn1 = 0.0;
  } else {
    u_idx_0 = rtNaN;
    Wn1 = rtNaN;
  }
  for (temp_tmp = 0; temp_tmp < 6; temp_tmp++) {
    x[temp_tmp].re = u_idx_0 - p[temp_tmp].re;
    x[temp_tmp].im = Wn1 - p[temp_tmp].im;
  }
  x_re = x[0].re;
  u_idx_1 = x[0].im;
  for (k = 0; k < 5; k++) {
    s = x[k + 1].im;
    re_tmp = x[k + 1].re;
    q = x_re * re_tmp - u_idx_1 * s;
    u_idx_1 = x_re * s + u_idx_1 * re_tmp;
    x_re = q;
  }
  for (temp_tmp = 0; temp_tmp < 6; temp_tmp++) {
    x[temp_tmp].re = u_idx_0 - (double)iv2[temp_tmp];
    x[temp_tmp].im = Wn1;
  }
  u_idx_0 = x[0].re;
  Wn1 = x[0].im;
  for (k = 0; k < 5; k++) {
    s = x[k + 1].im;
    re_tmp = x[k + 1].re;
    q = u_idx_0 * re_tmp - Wn1 * s;
    Wn1 = u_idx_0 * s + Wn1 * re_tmp;
    u_idx_0 = q;
  }
  if (Wn1 == 0.0) {
    if (u_idx_1 == 0.0) {
      x_re /= u_idx_0;
    } else if (x_re == 0.0) {
      x_re = 0.0;
    } else {
      x_re /= u_idx_0;
    }
  } else if (u_idx_0 == 0.0) {
    if (x_re == 0.0) {
      x_re = u_idx_1 / Wn1;
    } else if (u_idx_1 == 0.0) {
      x_re = 0.0;
    } else {
      x_re = u_idx_1 / Wn1;
    }
  } else {
    q = fabs(u_idx_0);
    s = fabs(Wn1);
    if (q > s) {
      s = Wn1 / u_idx_0;
      x_re = (x_re + s * u_idx_1) / (u_idx_0 + s * Wn1);
    } else if (s == q) {
      if (u_idx_0 > 0.0) {
        s = 0.5;
      } else {
        s = -0.5;
      }
      if (Wn1 > 0.0) {
        u_idx_0 = 0.5;
      } else {
        u_idx_0 = -0.5;
      }
      x_re = (x_re * s + u_idx_1 * u_idx_0) / q;
    } else {
      s = u_idx_0 / Wn1;
      x_re = (s * x_re + u_idx_1) / (Wn1 + s * u_idx_0);
    }
  }
  b_c[0].re = 1.0;
  b_c[0].im = 0.0;
  for (j = 0; j < 6; j++) {
    u_idx_0 = p[j].re;
    u_idx_1 = p[j].im;
    s = b_c[j].im;
    re_tmp = b_c[j].re;
    b_c[j + 1].re = -u_idx_0 * re_tmp - -u_idx_1 * s;
    b_c[j + 1].im = -u_idx_0 * s + -u_idx_1 * re_tmp;
    for (k = j + 1; k >= 2; k--) {
      q = b_c[k - 2].im;
      s = b_c[k - 2].re;
      b_c[k - 1].re -= u_idx_0 * s - u_idx_1 * q;
      b_c[k - 1].im -= u_idx_0 * q + u_idx_1 * s;
    }
  }
  for (i = 0; i < 7; i++) {
    varargout_2[i] = b_c[i].re;
    varargout_1[i] = x_re * (double)b[i];
  }
}

/*
 * File trailer for butter.c
 *
 * [EOF]
 */
