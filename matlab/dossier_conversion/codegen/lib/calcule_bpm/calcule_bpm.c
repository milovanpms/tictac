/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calcule_bpm.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 21-May-2025 11:06:32
 */

/* Include Files */
#include "calcule_bpm.h"
#include "butter.h"
#include "calcule_bpm_data.h"
#include "calcule_bpm_initialize.h"
#include "diff.h"
#include "filter.h"
#include "findpeaks.h"
#include "mean.h"
#include "rt_nonfinite.h"
#include "std.h"
#include <emmintrin.h>

/* Function Definitions */
/*
 * Arguments    : double periode
 *                const double bat[740]
 *                double *nb_battements
 *                double *bpm_moy
 * Return Type  : void
 */
void calcule_bpm(double periode, const double bat[740], double *nb_battements,
                 double *bpm_moy)
{
  __m128d r;
  double dv1[740];
  double locs_data[740];
  double peaks_data[740];
  double ppg_filt[740];
  double b_tmp_data[739];
  double tmp_data[739];
  double a[7];
  double b[7];
  double b_dv[2];
  double b_fs;
  double fs;
  int locs_size[2];
  int tmp_size[2];
  int i;
  int loop_ub;
  int peaks_size;
  int scalarLB;
  int vectorUB;
  if (!isInitialized_calcule_bpm) {
    calcule_bpm_initialize();
  }
  fs = 1.0 / periode;
  b_fs = fs / 2.0;
  b_dv[0] = 0.5 / b_fs;
  b_dv[1] = 5.0 / b_fs;
  butter(b_dv, b, a);
  filter(b, a, bat, ppg_filt);
  for (i = 0; i < 740; i++) {
    dv1[i] = (double)i / fs;
  }
  peaks_size = findpeaks(ppg_filt, dv1, mean(ppg_filt) + 0.5 * b_std(ppg_filt),
                         peaks_data, locs_data, locs_size);
  diff(locs_data, locs_size, tmp_data, tmp_size);
  tmp_size[0] = 1;
  loop_ub = tmp_size[1];
  scalarLB = (tmp_size[1] / 2) << 1;
  vectorUB = scalarLB - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    r = _mm_loadu_pd(&tmp_data[i]);
    _mm_storeu_pd(&b_tmp_data[i], _mm_div_pd(_mm_set1_pd(60.0), r));
  }
  for (i = scalarLB; i < loop_ub; i++) {
    b_tmp_data[i] = 60.0 / tmp_data[i];
  }
  *bpm_moy = b_mean(b_tmp_data, tmp_size);
  *nb_battements = peaks_size;
}

/*
 * File trailer for calcule_bpm.c
 *
 * [EOF]
 */
