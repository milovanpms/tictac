/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xzgehrd.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 21-May-2025 11:06:32
 */

/* Include Files */
#include "xzgehrd.h"
#include "rt_nonfinite.h"
#include "xzlarfg.h"
#include <emmintrin.h>
#include <string.h>

/* Function Declarations */
static int div_nde_s32_floor(int numerator);

/* Function Definitions */
/*
 * Arguments    : int numerator
 * Return Type  : int
 */
static int div_nde_s32_floor(int numerator)
{
  int quotient;
  if ((numerator < 0) && (numerator % 6 != 0)) {
    quotient = -1;
  } else {
    quotient = 0;
  }
  quotient += numerator / 6;
  return quotient;
}

/*
 * Arguments    : double a[36]
 *                int ilo
 *                int ihi
 * Return Type  : void
 */
void xzgehrd(double a[36], int ilo, int ihi)
{
  __m128d r;
  __m128d r1;
  double work[6];
  double tau[5];
  double alpha1;
  double d;
  double temp;
  int alpha1_tmp_tmp;
  int b_i;
  int b_lastv;
  int c_i;
  int exitg1;
  int i;
  int i1;
  int ia;
  int iac;
  int ic0;
  int in;
  int jA;
  int lastc;
  int lastv;
  int work_tmp;
  boolean_T exitg2;
  if ((ihi - ilo) + 1 > 1) {
    i = (unsigned char)(ilo - 1);
    if (i - 1 >= 0) {
      memset(&tau[0], 0, (unsigned int)i * sizeof(double));
    }
    for (b_i = ihi; b_i < 6; b_i++) {
      tau[b_i - 1] = 0.0;
    }
    for (b_i = 0; b_i < 6; b_i++) {
      work[b_i] = 0.0;
    }
    for (b_i = ilo; b_i < ihi; b_i++) {
      c_i = (b_i - 1) * 6;
      in = b_i * 6;
      lastv = ihi - b_i;
      alpha1_tmp_tmp = b_i + c_i;
      alpha1 = a[alpha1_tmp_tmp];
      if (b_i + 2 <= 6) {
        i = b_i + 1;
      } else {
        i = 5;
      }
      d = xzlarfg(lastv, &alpha1, a, (i + c_i) + 1);
      tau[b_i - 1] = d;
      a[alpha1_tmp_tmp] = 1.0;
      ic0 = in + 1;
      if (d != 0.0) {
        b_lastv = lastv;
        c_i = alpha1_tmp_tmp + lastv;
        while ((b_lastv > 0) && (a[c_i - 1] == 0.0)) {
          b_lastv--;
          c_i--;
        }
        lastc = ihi;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          c_i = in + lastc;
          ia = c_i;
          do {
            exitg1 = 0;
            if (ia <= c_i + (b_lastv - 1) * 6) {
              if (a[ia - 1] != 0.0) {
                exitg1 = 1;
              } else {
                ia += 6;
              }
            } else {
              lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);
          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        b_lastv = 0;
        lastc = 0;
      }
      if (b_lastv > 0) {
        if (lastc != 0) {
          i = (unsigned char)lastc;
          memset(&work[0], 0, (unsigned int)i * sizeof(double));
          c_i = alpha1_tmp_tmp;
          i = (in + 6 * (b_lastv - 1)) + 1;
          for (iac = ic0; iac <= i; iac += 6) {
            i1 = iac + lastc;
            for (ia = iac; ia < i1; ia++) {
              work_tmp = ia - iac;
              work[work_tmp] += a[ia - 1] * a[c_i];
            }
            c_i++;
          }
        }
        d = -tau[b_i - 1];
        if (!(d == 0.0)) {
          jA = in;
          i = (unsigned char)b_lastv;
          for (iac = 0; iac < i; iac++) {
            temp = a[alpha1_tmp_tmp + iac];
            if (temp != 0.0) {
              temp *= d;
              i1 = jA + 1;
              c_i = lastc + jA;
              work_tmp = ((c_i - i1) + 1) / 2 * 2 + i1;
              ic0 = work_tmp - 2;
              for (b_lastv = i1; b_lastv <= ic0; b_lastv += 2) {
                r = _mm_loadu_pd(&work[(b_lastv - jA) - 1]);
                r = _mm_mul_pd(r, _mm_set1_pd(temp));
                r1 = _mm_loadu_pd(&a[b_lastv - 1]);
                r = _mm_add_pd(r1, r);
                _mm_storeu_pd(&a[b_lastv - 1], r);
              }
              for (b_lastv = work_tmp; b_lastv <= c_i; b_lastv++) {
                a[b_lastv - 1] += work[(b_lastv - jA) - 1] * temp;
              }
            }
            jA += 6;
          }
        }
      }
      jA = (b_i + in) + 1;
      d = tau[b_i - 1];
      if (d != 0.0) {
        c_i = alpha1_tmp_tmp + lastv;
        while ((lastv > 0) && (a[c_i - 1] == 0.0)) {
          lastv--;
          c_i--;
        }
        lastc = 6 - b_i;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          c_i = jA + (lastc - 1) * 6;
          ia = c_i;
          do {
            exitg1 = 0;
            if (ia <= (c_i + lastv) - 1) {
              if (a[ia - 1] != 0.0) {
                exitg1 = 1;
              } else {
                ia++;
              }
            } else {
              lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);
          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        lastv = 0;
        lastc = 0;
      }
      if (lastv > 0) {
        if (lastc != 0) {
          i = (unsigned char)lastc;
          memset(&work[0], 0, (unsigned int)i * sizeof(double));
          i = jA + 6 * (lastc - 1);
          for (iac = jA; iac <= i; iac += 6) {
            temp = 0.0;
            i1 = iac + lastv;
            for (ia = iac; ia < i1; ia++) {
              temp += a[ia - 1] * a[(alpha1_tmp_tmp + ia) - iac];
            }
            work_tmp = div_nde_s32_floor(iac - jA);
            work[work_tmp] += temp;
          }
        }
        if (!(-d == 0.0)) {
          i = (unsigned char)lastc;
          for (iac = 0; iac < i; iac++) {
            temp = work[iac];
            if (temp != 0.0) {
              temp *= -d;
              i1 = lastv + jA;
              for (b_lastv = jA; b_lastv < i1; b_lastv++) {
                a[b_lastv - 1] += a[(alpha1_tmp_tmp + b_lastv) - jA] * temp;
              }
            }
            jA += 6;
          }
        }
      }
      a[alpha1_tmp_tmp] = alpha1;
    }
  }
}

/*
 * File trailer for xzgehrd.c
 *
 * [EOF]
 */
