/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xhseqr.c
 *
 * Code generation for function 'xhseqr'
 *
 */

/* Include files */
#include "xhseqr.h"
#include "calcule_bpm_data.h"
#include "rt_nonfinite.h"
#include "xdlanv2.h"
#include "xnrm2.h"
#include "xrot.h"
#include "mwmathutil.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo xd_emlrtRSI = {
    32,       /* lineNo */
    "xhseqr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xhseqr.m" /* pathName */
};

static emlrtRSInfo yd_emlrtRSI = {
    22,        /* lineNo */
    "xdhseqr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdhseqr.m" /* pathName */
};

static emlrtRSInfo he_emlrtRSI = {
    342,       /* lineNo */
    "xdlahqr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdlahqr.m" /* pathName */
};

static emlrtRSInfo ie_emlrtRSI = {
    345,       /* lineNo */
    "xdlahqr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdlahqr.m" /* pathName */
};

/* Function Definitions */
int32_T xhseqr(const emlrtStack *sp, real_T h[36])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T v[3];
  real_T aa;
  real_T d;
  real_T h12;
  real_T h21;
  real_T h22;
  real_T rt2r;
  real_T s;
  real_T tst;
  int32_T b_i;
  int32_T b_k;
  int32_T i;
  int32_T info;
  int32_T kdefl;
  int32_T nr;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &xd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &yd_emlrtRSI;
  info = 0;
  h[2] = 0.0;
  h[3] = 0.0;
  h[9] = 0.0;
  h[10] = 0.0;
  h[16] = 0.0;
  h[17] = 0.0;
  h[23] = 0.0;
  kdefl = 0;
  i = 5;
  exitg1 = false;
  while ((!exitg1) && (i + 1 >= 1)) {
    int32_T its;
    int32_T knt;
    int32_T l;
    int32_T scalarLB_tmp;
    boolean_T converged;
    boolean_T exitg2;
    l = 1;
    converged = false;
    its = 0;
    exitg2 = false;
    while ((!exitg2) && (its < 301)) {
      int32_T k;
      boolean_T exitg3;
      k = i;
      exitg3 = false;
      while ((!exitg3) && (k + 1 > l)) {
        b_i = k + 6 * (k - 1);
        d = muDoubleScalarAbs(h[b_i]);
        if (d <= 6.0125050800269183E-292) {
          exitg3 = true;
        } else {
          knt = k + 6 * k;
          h12 = muDoubleScalarAbs(h[knt]);
          tst = muDoubleScalarAbs(h[b_i - 1]) + h12;
          if (tst == 0.0) {
            if (k - 1 >= 1) {
              tst = muDoubleScalarAbs(h[(k + 6 * (k - 2)) - 1]);
            }
            if (k + 2 <= 6) {
              tst += muDoubleScalarAbs(h[knt + 1]);
            }
          }
          if (d <= 2.2204460492503131E-16 * tst) {
            h21 = muDoubleScalarAbs(h[knt - 1]);
            tst = muDoubleScalarAbs(h[b_i - 1] - h[knt]);
            aa = muDoubleScalarMax(h12, tst);
            tst = muDoubleScalarMin(h12, tst);
            s = aa + tst;
            if (muDoubleScalarMin(d, h21) * (muDoubleScalarMax(d, h21) / s) <=
                muDoubleScalarMax(6.0125050800269183E-292,
                                  2.2204460492503131E-16 * (tst * (aa / s)))) {
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
      if (k + 1 > 1) {
        h[k + 6 * (k - 1)] = 0.0;
      }
      if (k + 1 >= i) {
        converged = true;
        exitg2 = true;
      } else {
        __m128d r;
        real_T rt1r;
        int32_T m;
        kdefl++;
        if (kdefl - kdefl / 20 * 20 == 0) {
          s = muDoubleScalarAbs(h[i + 6 * (i - 1)]) +
              muDoubleScalarAbs(h[(i + 6 * (i - 2)) - 1]);
          tst = 0.75 * s + h[i + 6 * i];
          h12 = -0.4375 * s;
          h21 = s;
          h22 = tst;
        } else if (kdefl - kdefl / 10 * 10 == 0) {
          knt = k + 6 * k;
          s = muDoubleScalarAbs(h[knt + 1]) +
              muDoubleScalarAbs(h[(k + 6 * (k + 1)) + 2]);
          tst = 0.75 * s + h[knt];
          h12 = -0.4375 * s;
          h21 = s;
          h22 = tst;
        } else {
          knt = i + 6 * (i - 1);
          tst = h[knt - 1];
          h21 = h[knt];
          knt = i + 6 * i;
          h12 = h[knt - 1];
          h22 = h[knt];
        }
        s = ((muDoubleScalarAbs(tst) + muDoubleScalarAbs(h12)) +
             muDoubleScalarAbs(h21)) +
            muDoubleScalarAbs(h22);
        if (s == 0.0) {
          rt1r = 0.0;
          tst = 0.0;
          rt2r = 0.0;
          h21 = 0.0;
        } else {
          tst /= s;
          h21 /= s;
          h12 /= s;
          h22 /= s;
          aa = (tst + h22) / 2.0;
          tst = (tst - aa) * (h22 - aa) - h12 * h21;
          h21 = muDoubleScalarSqrt(muDoubleScalarAbs(tst));
          if (tst >= 0.0) {
            rt1r = aa * s;
            rt2r = rt1r;
            tst = h21 * s;
            h21 = -tst;
          } else {
            rt1r = aa + h21;
            rt2r = aa - h21;
            if (muDoubleScalarAbs(rt1r - h22) <=
                muDoubleScalarAbs(rt2r - h22)) {
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
        m = i - 1;
        exitg3 = false;
        while ((!exitg3) && (m >= k + 1)) {
          knt = m + 6 * (m - 1);
          h12 = h[knt - 1];
          aa = h12 - rt2r;
          s = (muDoubleScalarAbs(aa) + muDoubleScalarAbs(h21)) +
              muDoubleScalarAbs(h[knt]);
          h22 = h[knt] / s;
          knt = m + 6 * m;
          v[0] = (h22 * h[knt - 1] + aa * (aa / s)) - tst * (h21 / s);
          v[1] = h22 * (((h12 + h[knt]) - rt1r) - rt2r);
          v[2] = h22 * h[knt + 1];
          s = (muDoubleScalarAbs(v[0]) + muDoubleScalarAbs(v[1])) +
              muDoubleScalarAbs(v[2]);
          r = _mm_loadu_pd(&v[0]);
          _mm_storeu_pd(&v[0], _mm_div_pd(r, _mm_set1_pd(s)));
          v[2] /= s;
          if (m == k + 1) {
            exitg3 = true;
          } else {
            b_i = m + 6 * (m - 2);
            if (muDoubleScalarAbs(h[b_i - 1]) *
                    (muDoubleScalarAbs(v[1]) + muDoubleScalarAbs(v[2])) <=
                2.2204460492503131E-16 * muDoubleScalarAbs(v[0]) *
                    ((muDoubleScalarAbs(h[b_i - 2]) + muDoubleScalarAbs(h12)) +
                     muDoubleScalarAbs(h[knt]))) {
              exitg3 = true;
            } else {
              m--;
            }
          }
        }
        for (b_k = m; b_k <= i; b_k++) {
          int32_T scalarLB;
          int32_T vectorUB;
          int32_T vectorUB_tmp;
          b_i = (i - b_k) + 2;
          nr = muIntScalarMin_sint32(3, b_i);
          if (b_k > m) {
            knt = ((b_k - 2) * 6 + b_k) - 1;
            for (b_i = 0; b_i < nr; b_i++) {
              v[b_i] = h[knt + b_i];
            }
          }
          h12 = v[0];
          aa = 0.0;
          if (nr > 0) {
            tst = b_xnrm2(nr - 1, v);
            if (tst != 0.0) {
              h21 = muDoubleScalarHypot(v[0], tst);
              if (v[0] >= 0.0) {
                h21 = -h21;
              }
              if (muDoubleScalarAbs(h21) < 1.0020841800044864E-292) {
                knt = 0;
                do {
                  knt++;
                  scalarLB_tmp = (((nr - 1) / 2) << 1) + 2;
                  vectorUB_tmp = scalarLB_tmp - 2;
                  for (b_i = 2; b_i <= vectorUB_tmp; b_i += 2) {
                    r = _mm_loadu_pd(&v[1]);
                    _mm_storeu_pd(
                        &v[1],
                        _mm_mul_pd(_mm_set1_pd(9.9792015476736E+291), r));
                  }
                  for (b_i = scalarLB_tmp; b_i <= nr; b_i++) {
                    v[b_i - 1] *= 9.9792015476736E+291;
                  }
                  h21 *= 9.9792015476736E+291;
                  h12 *= 9.9792015476736E+291;
                } while ((muDoubleScalarAbs(h21) < 1.0020841800044864E-292) &&
                         (knt < 20));
                h21 = muDoubleScalarHypot(h12, b_xnrm2(nr - 1, v));
                if (h12 >= 0.0) {
                  h21 = -h21;
                }
                aa = (h21 - h12) / h21;
                tst = 1.0 / (h12 - h21);
                for (b_i = 2; b_i <= vectorUB_tmp; b_i += 2) {
                  r = _mm_loadu_pd(&v[1]);
                  _mm_storeu_pd(&v[1], _mm_mul_pd(_mm_set1_pd(tst), r));
                }
                for (b_i = scalarLB_tmp; b_i <= nr; b_i++) {
                  v[b_i - 1] *= tst;
                }
                for (b_i = 0; b_i < knt; b_i++) {
                  h21 *= 1.0020841800044864E-292;
                }
                h12 = h21;
              } else {
                aa = (h21 - v[0]) / h21;
                tst = 1.0 / (v[0] - h21);
                scalarLB = (((nr - 1) / 2) << 1) + 2;
                vectorUB = scalarLB - 2;
                for (b_i = 2; b_i <= vectorUB; b_i += 2) {
                  r = _mm_loadu_pd(&v[1]);
                  _mm_storeu_pd(&v[1], _mm_mul_pd(_mm_set1_pd(tst), r));
                }
                for (b_i = scalarLB; b_i <= nr; b_i++) {
                  v[b_i - 1] *= tst;
                }
                h12 = h21;
              }
            }
          }
          if (b_k > m) {
            b_i = b_k + 6 * (b_k - 2);
            h[b_i - 1] = h12;
            h[b_i] = 0.0;
            if (b_k < i) {
              h[b_i + 1] = 0.0;
            }
          } else if (m > k + 1) {
            b_i = (b_k + 6 * (b_k - 2)) - 1;
            h[b_i] *= 1.0 - aa;
          }
          d = v[1];
          tst = aa * v[1];
          if (nr == 3) {
            h22 = v[2];
            h12 = aa * v[2];
            for (nr = b_k; nr < 7; nr++) {
              b_i = b_k + 6 * (nr - 1);
              rt2r = h[b_i - 1];
              rt1r = h[b_i];
              s = h[b_i + 1];
              h21 = (rt2r + d * rt1r) + h22 * s;
              rt2r -= h21 * aa;
              h[b_i - 1] = rt2r;
              rt1r -= h21 * tst;
              h[b_i] = rt1r;
              s -= h21 * h12;
              h[b_i + 1] = s;
            }
            b_i = b_k + 3;
            nr = i + 1;
            b_i = muIntScalarMin_sint32(b_i, nr);
            scalarLB = (b_i / 2) << 1;
            vectorUB = scalarLB - 2;
            for (nr = 0; nr <= vectorUB; nr += 2) {
              __m128d r1;
              __m128d r2;
              __m128d r3;
              knt = nr + 6 * b_k;
              r = _mm_loadu_pd(&h[knt]);
              scalarLB_tmp = nr + 6 * (b_k + 1);
              r1 = _mm_loadu_pd(&h[scalarLB_tmp]);
              vectorUB_tmp = nr + 6 * (b_k - 1);
              r2 = _mm_loadu_pd(&h[vectorUB_tmp]);
              r3 = _mm_add_pd(_mm_add_pd(r2, _mm_mul_pd(_mm_set1_pd(d), r)),
                              _mm_mul_pd(_mm_set1_pd(h22), r1));
              _mm_storeu_pd(&h[vectorUB_tmp],
                            _mm_sub_pd(r2, _mm_mul_pd(r3, _mm_set1_pd(aa))));
              _mm_storeu_pd(&h[knt],
                            _mm_sub_pd(r, _mm_mul_pd(r3, _mm_set1_pd(tst))));
              _mm_storeu_pd(&h[scalarLB_tmp],
                            _mm_sub_pd(r1, _mm_mul_pd(r3, _mm_set1_pd(h12))));
            }
            for (nr = scalarLB; nr < b_i; nr++) {
              knt = nr + 6 * (b_k - 1);
              rt2r = h[knt];
              scalarLB_tmp = nr + 6 * b_k;
              rt1r = h[scalarLB_tmp];
              vectorUB_tmp = nr + 6 * (b_k + 1);
              s = h[vectorUB_tmp];
              h21 = (rt2r + d * rt1r) + h22 * s;
              rt2r -= h21 * aa;
              h[knt] = rt2r;
              rt1r -= h21 * tst;
              h[scalarLB_tmp] = rt1r;
              s -= h21 * h12;
              h[vectorUB_tmp] = s;
            }
          } else if (nr == 2) {
            for (nr = b_k; nr < 7; nr++) {
              b_i = b_k + 6 * (nr - 1);
              h22 = h[b_i - 1];
              rt2r = h[b_i];
              h21 = h22 + d * rt2r;
              h22 -= h21 * aa;
              h[b_i - 1] = h22;
              rt2r -= h21 * tst;
              h[b_i] = rt2r;
            }
            scalarLB = ((i + 1) / 2) << 1;
            vectorUB = scalarLB - 2;
            for (nr = 0; nr <= vectorUB; nr += 2) {
              __m128d r1;
              __m128d r2;
              b_i = nr + 6 * b_k;
              r = _mm_loadu_pd(&h[b_i]);
              knt = nr + 6 * (b_k - 1);
              r1 = _mm_loadu_pd(&h[knt]);
              r2 = _mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(d), r));
              _mm_storeu_pd(&h[knt],
                            _mm_sub_pd(r1, _mm_mul_pd(r2, _mm_set1_pd(aa))));
              _mm_storeu_pd(&h[b_i],
                            _mm_sub_pd(r, _mm_mul_pd(r2, _mm_set1_pd(tst))));
            }
            for (nr = scalarLB; nr <= i; nr++) {
              b_i = nr + 6 * (b_k - 1);
              h22 = h[b_i];
              knt = nr + 6 * b_k;
              rt2r = h[knt];
              h21 = h22 + d * rt2r;
              h22 -= h21 * aa;
              h[b_i] = h22;
              rt2r -= h21 * tst;
              h[knt] = rt2r;
            }
          }
        }
        its++;
      }
    }
    if (!converged) {
      info = i + 1;
      exitg1 = true;
    } else {
      if ((l != i + 1) && (l == i)) {
        b_i = i + 6 * i;
        d = h[b_i - 1];
        knt = 6 * (i - 1);
        scalarLB_tmp = i + knt;
        h22 = h[scalarLB_tmp];
        rt2r = h[b_i];
        xdlanv2(&h[scalarLB_tmp - 1], &d, &h22, &rt2r, &s, &tst, &h21, &h12,
                &aa);
        h[b_i - 1] = d;
        h[scalarLB_tmp] = h22;
        h[b_i] = rt2r;
        if (i + 1 < 6) {
          b_i = (i + 1) * 6 + i;
          c_st.site = &he_emlrtRSI;
          xrot(&c_st, 5 - i, h, b_i, b_i + 1, h12, aa);
        }
        c_st.site = &ie_emlrtRSI;
        b_xrot(&c_st, i - 1, h, knt + 1, i * 6 + 1, h12, aa);
      }
      kdefl = 0;
      i = l - 2;
    }
  }
  for (nr = 0; nr < 4; nr++) {
    for (i = nr + 3; i < 7; i++) {
      h[(i + 6 * nr) - 1] = 0.0;
    }
  }
  return info;
}

/* End of code generation (xhseqr.c) */
