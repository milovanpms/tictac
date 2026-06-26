/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calcule_bpm.c
 *
 * Code generation for function 'calcule_bpm'
 *
 */

/* Include files */
#include "calcule_bpm.h"
#include "_coder_calcule_bpm_mex.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "cs.h"
#include "lapacke.h"
#include "makeCXSparseMatrix.h"
#include "mwmathutil.h"
#include "solve_from_lu.h"
#include "solve_from_qr.h"
#include <emmintrin.h>
#include <stddef.h>
#include <string.h>

/* Type Definitions */
#ifndef typedef_struct_T
#define typedef_struct_T
typedef struct {
  int32_T xstart;
  int32_T xend;
  int32_T depth;
} struct_T;
#endif /* typedef_struct_T */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T
struct emxArray_int32_T {
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_int32_T */
#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T
typedef struct emxArray_int32_T emxArray_int32_T;
#endif /* typedef_emxArray_int32_T */

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                /* bFirstTime */
    false,                                               /* bInitialized */
    131659U,                                             /* fVersionInfo */
    NULL,                                                /* fErrorFunction */
    "calcule_bpm",                                       /* fFunctionName */
    NULL,                                                /* fRTCallStack */
    false,                                               /* bDebugMode */
    {497312255U, 2566552405U, 2553285182U, 2715458501U}, /* fSigWrd */
    NULL                                                 /* fSigMem */
};

static emlrtRSInfo emlrtRSI = {
    9,             /* lineNo */
    "calcule_bpm", /* fcnName */
    "C:\\Users\\33676\\Documents\\tictac\\MATLAB\\dossier_convertion\\calcule_"
    "bpm.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    10,            /* lineNo */
    "calcule_bpm", /* fcnName */
    "C:\\Users\\33676\\Documents\\tictac\\MATLAB\\dossier_convertion\\calcule_"
    "bpm.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    13,            /* lineNo */
    "calcule_bpm", /* fcnName */
    "C:\\Users\\33676\\Documents\\tictac\\MATLAB\\dossier_convertion\\calcule_"
    "bpm.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    16,            /* lineNo */
    "calcule_bpm", /* fcnName */
    "C:\\Users\\33676\\Documents\\tictac\\MATLAB\\dossier_convertion\\calcule_"
    "bpm.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    18,            /* lineNo */
    "calcule_bpm", /* fcnName */
    "C:\\Users\\33676\\Documents\\tictac\\MATLAB\\dossier_convertion\\calcule_"
    "bpm.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    20,       /* lineNo */
    "butter", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\butter.m" /* pathName
                                                                            */
};

static emlrtRSInfo g_emlrtRSI = {
    31,           /* lineNo */
    "butterImpl", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\butter.m" /* pathName
                                                                            */
};

static emlrtRSInfo h_emlrtRSI = {
    44,           /* lineNo */
    "butterImpl", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\butter.m" /* pathName
                                                                            */
};

static emlrtRSInfo i_emlrtRSI = {
    60,           /* lineNo */
    "butterImpl", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\butter.m" /* pathName
                                                                            */
};

static emlrtRSInfo j_emlrtRSI = {
    64,           /* lineNo */
    "butterImpl", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\butter.m" /* pathName
                                                                            */
};

static emlrtRSInfo k_emlrtRSI = {
    71,           /* lineNo */
    "butterImpl", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\butter.m" /* pathName
                                                                            */
};

static emlrtRSInfo l_emlrtRSI = {
    81,           /* lineNo */
    "butterImpl", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\butter.m" /* pathName
                                                                            */
};

static emlrtRSInfo m_emlrtRSI = {
    102,          /* lineNo */
    "butterImpl", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\butter.m" /* pathName
                                                                            */
};

static emlrtRSInfo n_emlrtRSI = {
    36,                          /* lineNo */
    "classicalIIRFiltersParser", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\+signal\\+internal\\+"
    "classicaliirfilters\\classicalIIRFiltersParser."
    "m" /* pathName */
};

static emlrtRSInfo o_emlrtRSI = {
    93,                   /* lineNo */
    "validateattributes", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes"
    ".m" /* pathName */
};

static emlrtRSInfo s_emlrtRSI = {
    20,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_"
    "overflow_check.m" /* pathName */
};

static emlrtRSInfo u_emlrtRSI = {
    16,     /* lineNo */
    "poly", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\polyfun\\poly.m" /* pathName
                                                                         */
};

static emlrtRSInfo v_emlrtRSI = {
    20,         /* lineNo */
    "mldivide", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" /* pathName
                                                                         */
};

static emlrtRSInfo w_emlrtRSI = {
    42,      /* lineNo */
    "mldiv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" /* pathName
                                                                         */
};

static emlrtRSInfo
    y_emlrtRSI =
        {
            90,              /* lineNo */
            "warn_singular", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo ab_emlrtRSI = {
    63,      /* lineNo */
    "lp2bp", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\lp2bp.m" /* pathName
                                                                           */
};

static emlrtRSInfo bb_emlrtRSI = {
    64,      /* lineNo */
    "lp2bp", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\lp2bp.m" /* pathName
                                                                           */
};

static emlrtRSInfo
    cb_emlrtRSI =
        {
            166,        /* lineNo */
            "bilinear", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\bilinear.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    db_emlrtRSI =
        {
            167,        /* lineNo */
            "bilinear", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\bilinear.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    eb_emlrtRSI =
        {
            168,        /* lineNo */
            "bilinear", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\bilinear.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    fb_emlrtRSI =
        {
            169,        /* lineNo */
            "bilinear", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\bilinear.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    gb_emlrtRSI =
        {
            67,        /* lineNo */
            "lusolve", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo
    hb_emlrtRSI =
        {
            109,          /* lineNo */
            "lusolveNxN", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo
    ib_emlrtRSI =
        {
            112,          /* lineNo */
            "lusolveNxN", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo
    jb_emlrtRSI =
        {
            124,          /* lineNo */
            "InvAtimesX", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo kb_emlrtRSI = {
    26,        /* lineNo */
    "xgetrfs", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrfs.m" /* pathName */
};

static emlrtRSInfo mb_emlrtRSI = {
    30,       /* lineNo */
    "xgetrf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrf.m" /* pathName */
};

static emlrtRSInfo nb_emlrtRSI = {
    55,        /* lineNo */
    "xzgetrf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgetrf.m" /* pathName */
};

static emlrtRSInfo ob_emlrtRSI = {
    63,        /* lineNo */
    "xzgetrf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgetrf.m" /* pathName */
};

static emlrtRSInfo pb_emlrtRSI = {
    45,      /* lineNo */
    "xgeru", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgeru."
    "m" /* pathName */
};

static emlrtRSInfo qb_emlrtRSI =
    {
        45,     /* lineNo */
        "xger", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "blas\\xger.m" /* pathName */
};

static emlrtRSInfo rb_emlrtRSI = {
    15,     /* lineNo */
    "xger", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xger.m" /* pathName */
};

static emlrtRSInfo sb_emlrtRSI = {
    41,      /* lineNo */
    "xgerx", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgerx.m" /* pathName */
};

static emlrtRSInfo tb_emlrtRSI = {
    54,      /* lineNo */
    "xgerx", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgerx.m" /* pathName */
};

static emlrtRSInfo yb_emlrtRSI = {
    20,                /* lineNo */
    "mrdivide_helper", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_"
    "helper.m" /* pathName */
};

static emlrtRSInfo ac_emlrtRSI = {
    42,      /* lineNo */
    "mrdiv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_"
    "helper.m" /* pathName */
};

static emlrtRSInfo
    bc_emlrtRSI =
        {
            107,          /* lineNo */
            "lusolveNxN", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo
    cc_emlrtRSI =
        {
            135,          /* lineNo */
            "XtimesInvA", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo fc_emlrtRSI = {
    81,    /* lineNo */
    "eig", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m" /* pathName
                                                                       */
};

static emlrtRSInfo gc_emlrtRSI = {
    127,   /* lineNo */
    "eig", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m" /* pathName
                                                                       */
};

static emlrtRSInfo hc_emlrtRSI = {
    135,   /* lineNo */
    "eig", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m" /* pathName
                                                                       */
};

static emlrtRSInfo ic_emlrtRSI = {
    143,   /* lineNo */
    "eig", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m" /* pathName
                                                                       */
};

static emlrtRSInfo mc_emlrtRSI = {
    13,                     /* lineNo */
    "eigHermitianStandard", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eigHerm"
    "itianStandard.m" /* pathName */
};

static emlrtRSInfo nc_emlrtRSI = {
    40,                     /* lineNo */
    "eigHermitianStandard", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eigHerm"
    "itianStandard.m" /* pathName */
};

static emlrtRSInfo oc_emlrtRSI = {
    8,         /* lineNo */
    "xsyheev", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xsyheev.m" /* pathName */
};

static emlrtRSInfo pc_emlrtRSI = {
    61,              /* lineNo */
    "ceval_xsyheev", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xsyheev.m" /* pathName */
};

static emlrtRSInfo qc_emlrtRSI = {
    20,        /* lineNo */
    "xzlarfg", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarfg.m" /* pathName */
};

static emlrtRSInfo rc_emlrtRSI = {
    41,        /* lineNo */
    "xzlarfg", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarfg.m" /* pathName */
};

static emlrtRSInfo sc_emlrtRSI = {
    53,        /* lineNo */
    "xzlarfg", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarfg.m" /* pathName */
};

static emlrtRSInfo tc_emlrtRSI = {
    68,        /* lineNo */
    "xzlarfg", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarfg.m" /* pathName */
};

static emlrtRSInfo uc_emlrtRSI = {
    71,        /* lineNo */
    "xzlarfg", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarfg.m" /* pathName */
};

static emlrtRSInfo vc_emlrtRSI = {
    81,        /* lineNo */
    "xzlarfg", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarfg.m" /* pathName */
};

static emlrtRSInfo wc_emlrtRSI = {
    23,      /* lineNo */
    "xnrm2", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xnrm2."
    "m" /* pathName */
};

static emlrtRSInfo xc_emlrtRSI = {
    38,      /* lineNo */
    "xnrm2", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xnrm2.m" /* pathName */
};

static emlrtRSInfo yc_emlrtRSI = {
    31,      /* lineNo */
    "xscal", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xscal."
    "m" /* pathName */
};

static emlrtRSInfo ad_emlrtRSI = {
    18,      /* lineNo */
    "xscal", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xscal.m" /* pathName */
};

static emlrtRSInfo bd_emlrtRSI = {
    18,              /* lineNo */
    "insertionsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\insertionsort.m" /* pathName */
};

static emlrtRSInfo cd_emlrtRSI = {
    10,                         /* lineNo */
    "eigSkewHermitianStandard", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eigSkew"
    "HermitianStandard.m" /* pathName */
};

static emlrtRSInfo dd_emlrtRSI = {
    19,                             /* lineNo */
    "eigRealSkewSymmetricStandard", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eigReal"
    "SkewSymmetricStandard.m" /* pathName */
};

static emlrtRSInfo ed_emlrtRSI = {
    35,      /* lineNo */
    "schur", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m" /* pathName
                                                                         */
};

static emlrtRSInfo fd_emlrtRSI = {
    52,      /* lineNo */
    "schur", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m" /* pathName
                                                                         */
};

static emlrtRSInfo gd_emlrtRSI = {
    54,      /* lineNo */
    "schur", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m" /* pathName
                                                                         */
};

static emlrtRSInfo hd_emlrtRSI = {
    83,      /* lineNo */
    "schur", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m" /* pathName
                                                                         */
};

static emlrtRSInfo id_emlrtRSI = {
    18,       /* lineNo */
    "xgehrd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgehrd.m" /* pathName */
};

static emlrtRSInfo jd_emlrtRSI = {
    46,        /* lineNo */
    "xzgehrd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgehrd.m" /* pathName */
};

static emlrtRSInfo kd_emlrtRSI = {
    50,        /* lineNo */
    "xzgehrd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgehrd.m" /* pathName */
};

static emlrtRSInfo ld_emlrtRSI = {
    58,        /* lineNo */
    "xzgehrd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgehrd.m" /* pathName */
};

static emlrtRSInfo md_emlrtRSI = {
    84,       /* lineNo */
    "xzlarf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarf.m" /* pathName */
};

static emlrtRSInfo nd_emlrtRSI = {
    91,       /* lineNo */
    "xzlarf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarf.m" /* pathName */
};

static emlrtRSInfo od_emlrtRSI = {
    86,      /* lineNo */
    "xgemv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemv."
    "m" /* pathName */
};

static emlrtRSInfo pd_emlrtRSI = {
    58,      /* lineNo */
    "xgemv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgemv.m" /* pathName */
};

static emlrtRSInfo qd_emlrtRSI = {
    37,      /* lineNo */
    "xgemv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgemv.m" /* pathName */
};

static emlrtRSInfo rd_emlrtRSI = {
    45,      /* lineNo */
    "xgerc", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgerc."
    "m" /* pathName */
};

static emlrtRSInfo sd_emlrtRSI = {
    50,       /* lineNo */
    "xzlarf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarf.m" /* pathName */
};

static emlrtRSInfo td_emlrtRSI = {
    68,       /* lineNo */
    "xzlarf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarf.m" /* pathName */
};

static emlrtRSInfo ud_emlrtRSI = {
    75,       /* lineNo */
    "xzlarf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarf.m" /* pathName */
};

static emlrtRSInfo vd_emlrtRSI = {
    103,      /* lineNo */
    "ilazlc", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarf.m" /* pathName */
};

static emlrtRSInfo wd_emlrtRSI = {
    74,      /* lineNo */
    "xgemv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgemv.m" /* pathName */
};

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

static emlrtRSInfo qe_emlrtRSI =
    {
        32,     /* lineNo */
        "xrot", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "blas\\xrot.m" /* pathName */
};

static emlrtRSInfo re_emlrtRSI = {
    24,     /* lineNo */
    "xrot", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xrot.m" /* pathName */
};

static emlrtRSInfo se_emlrtRSI = {
    34,            /* lineNo */
    "eigStandard", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eigStan"
    "dard.m" /* pathName */
};

static emlrtRSInfo te_emlrtRSI = {
    45,            /* lineNo */
    "eigStandard", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eigStan"
    "dard.m" /* pathName */
};

static emlrtRSInfo ue_emlrtRSI = {
    159,           /* lineNo */
    "ceval_xgeev", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeev.m" /* pathName */
};

static emlrtRSInfo ve_emlrtRSI = {
    42,      /* lineNo */
    "xgeev", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeev.m" /* pathName */
};

static emlrtRSInfo
    we_emlrtRSI =
        {
            123,        /* lineNo */
            "filtfilt", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    xe_emlrtRSI =
        {
            150,        /* lineNo */
            "filtfilt", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    ye_emlrtRSI =
        {
            505,              /* lineNo */
            "filtfiltParser", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    af_emlrtRSI =
        {
            579,                     /* lineNo */
            "validateAndCastInputs", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    bf_emlrtRSI =
        {
            582,                     /* lineNo */
            "validateAndCastInputs", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    cf_emlrtRSI =
        {
            584,                     /* lineNo */
            "validateAndCastInputs", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    df_emlrtRSI =
        {
            174,            /* lineNo */
            "filtfiltImpl", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    ef_emlrtRSI =
        {
            179,            /* lineNo */
            "filtfiltImpl", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    ff_emlrtRSI =
        {
            261,                             /* lineNo */
            "getCoeffsAndInitialConditions", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo gf_emlrtRSI = {
    13,       /* lineNo */
    "sparse", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m" /* pathName
                                                                           */
};

static emlrtRSInfo hf_emlrtRSI = {
    219,             /* lineNo */
    "sparse/sparse", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pathName */
};

static emlrtRSInfo jf_emlrtRSI = {
    1450,              /* lineNo */
    "sparse/mldivide", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pathName */
};

static emlrtRSInfo kf_emlrtRSI =
    {
        160,                         /* lineNo */
        "CXSparseAPI/iteratedSolve", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" /* pathName */
};

static emlrtRSInfo mf_emlrtRSI =
    {
        312,                      /* lineNo */
        "CXSparseAPI/iteratedLU", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" /* pathName */
};

static emlrtRSInfo
    qf_emlrtRSI =
        {
            309,            /* lineNo */
            "ffOneChanCat", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    rf_emlrtRSI =
        {
            308,            /* lineNo */
            "ffOneChanCat", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    sf_emlrtRSI =
        {
            307,            /* lineNo */
            "ffOneChanCat", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo yf_emlrtRSI = {
    42,                /* lineNo */
    "indexShapeCheck", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\indexShapeCheck.m" /* pathName */
};

static emlrtRSInfo ag_emlrtRSI =
    {
        134,         /* lineNo */
        "findpeaks", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m" /* pathName
                                                                       */
};

static emlrtRSInfo bg_emlrtRSI =
    {
        166,         /* lineNo */
        "findpeaks", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m" /* pathName
                                                                       */
};

static emlrtRSInfo cg_emlrtRSI =
    {
        167,         /* lineNo */
        "findpeaks", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m" /* pathName
                                                                       */
};

static emlrtRSInfo dg_emlrtRSI =
    {
        178,         /* lineNo */
        "findpeaks", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m" /* pathName
                                                                       */
};

static emlrtRSInfo eg_emlrtRSI =
    {
        182,         /* lineNo */
        "findpeaks", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m" /* pathName
                                                                       */
};

static emlrtRSInfo fg_emlrtRSI =
    {
        189,         /* lineNo */
        "findpeaks", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m" /* pathName
                                                                       */
};

static emlrtRSInfo gg_emlrtRSI =
    {
        195,         /* lineNo */
        "findpeaks", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m" /* pathName
                                                                       */
};

static emlrtRSInfo hg_emlrtRSI =
    {
        269,            /* lineNo */
        "parse_inputs", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m" /* pathName
                                                                       */
};

static emlrtRSInfo ig_emlrtRSI =
    {
        356,            /* lineNo */
        "parse_inputs", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m" /* pathName
                                                                       */
};

static emlrtRSInfo jg_emlrtRSI = {
    22,           /* lineNo */
    "validatelt", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatelt.m" /* pathName */
};

static emlrtRSInfo kg_emlrtRSI = {
    17,              /* lineNo */
    "local_num2str", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\private\\local_num2str.m" /* pathName */
};

static emlrtRSInfo
    lg_emlrtRSI =
        {
            15,        /* lineNo */
            "num2str", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\num2str.m" /* pathName */
};

static emlrtRSInfo mg_emlrtRSI =
    {
        551,                /* lineNo */
        "removeSmallPeaks", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m" /* pathName
                                                                       */
};

static emlrtRSInfo ng_emlrtRSI =
    {
        566,            /* lineNo */
        "combinePeaks", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m" /* pathName
                                                                       */
};

static emlrtRSInfo og_emlrtRSI =
    {
        23,      /* lineNo */
        "union", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\union.m" /* pathName
                                                                          */
};

static emlrtRSInfo pg_emlrtRSI = {
    97,          /* lineNo */
    "eml_setop", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" /* pathName */
};

static emlrtRSInfo xg_emlrtRSI =
    {
        641,                                           /* lineNo */
        "findPeaksSeparatedByMoreThanMinPeakDistance", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m" /* pathName
                                                                       */
};

static emlrtRSInfo ch_emlrtRSI = {
    42,          /* lineNo */
    "introsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" /* pathName */
};

static emlrtRSInfo eh_emlrtRSI = {
    47,          /* lineNo */
    "introsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" /* pathName */
};

static emlrtRSInfo fh_emlrtRSI = {
    49,          /* lineNo */
    "introsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" /* pathName */
};

static emlrtRSInfo gh_emlrtRSI = {
    55,          /* lineNo */
    "introsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" /* pathName */
};

static emlrtRSInfo hh_emlrtRSI = {
    58,          /* lineNo */
    "introsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" /* pathName */
};

static emlrtRSInfo ih_emlrtRSI = {
    41,          /* lineNo */
    "introsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" /* pathName */
};

static emlrtRSInfo jh_emlrtRSI = {
    20,         /* lineNo */
    "heapsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\heapsort.m" /* pathName */
};

static emlrtRSInfo mh_emlrtRSI = {
    112,    /* lineNo */
    "mean", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" /* pathName
                                                                         */
};

static emlrtRSInfo nh_emlrtRSI = {
    86,                      /* lineNo */
    "combineVectorElements", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" /* pathName */
};

static emlrtRSInfo oh_emlrtRSI = {
    99,                 /* lineNo */
    "blockedSummation", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" /* pathName */
};

static emlrtRSInfo ph_emlrtRSI = {
    22,                    /* lineNo */
    "sumMatrixIncludeNaN", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo qh_emlrtRSI = {
    42,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo rh_emlrtRSI = {
    178,          /* lineNo */
    "sumColumnB", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo sh_emlrtRSI = {
    210,         /* lineNo */
    "sumColumn", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo th_emlrtRSI = {
    3,             /* lineNo */
    "calcule_pas", /* fcnName */
    "C:\\Users\\33676\\Documents\\tictac\\MATLAB\\dossier_convertion\\calcule_"
    "pas.m" /* pathName */
};

static emlrtMCInfo emlrtMCI = {
    14,        /* lineNo */
    25,        /* colNo */
    "warning", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\warning.m" /* pName */
};

static emlrtMCInfo b_emlrtMCI = {
    14,        /* lineNo */
    9,         /* colNo */
    "warning", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\warning.m" /* pName */
};

static emlrtMCInfo c_emlrtMCI = {
    53,        /* lineNo */
    19,        /* colNo */
    "flt2str", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\flt2str.m" /* pName */
};

static emlrtRTEInfo emlrtRTEI = {
    138,                         /* lineNo */
    1,                           /* colNo */
    "classicalIIRFiltersParser", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\+signal\\+internal\\+"
    "classicaliirfilters\\classicalIIRFiltersParser."
    "m" /* pName */
};

static emlrtRTEInfo b_emlrtRTEI = {
    13,     /* lineNo */
    9,      /* colNo */
    "sqrt", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m" /* pName
                                                                       */
};

static emlrtRTEInfo c_emlrtRTEI = {
    14,                 /* lineNo */
    37,                 /* colNo */
    "validatepositive", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatepositive.m" /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = {
    14,               /* lineNo */
    37,               /* colNo */
    "validatefinite", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatefinite.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI = {
    40,            /* lineNo */
    9,             /* colNo */
    "vector_poly", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\polyfun\\poly.m" /* pName
                                                                         */
};

static emlrtRTEInfo f_emlrtRTEI = {
    45,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    48,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" /* pName */
};

static emlrtECInfo emlrtECI = {
    -1,      /* nDims */
    206,     /* lineNo */
    9,       /* colNo */
    "zp2ss", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\controllib\\general\\zp2ss.m" /* pName
                                                                            */
};

static emlrtECInfo
    b_emlrtECI =
        {
            -1,             /* nDims */
            304,            /* lineNo */
            5,              /* colNo */
            "ffOneChanCat", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pName
                                                                          */
};

static emlrtBCInfo emlrtBCI =
    {
        -1,             /* iFirst */
        -1,             /* iLast */
        308,            /* lineNo */
        19,             /* colNo */
        "",             /* aName */
        "ffOneChanCat", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo b_emlrtBCI =
    {
        -1,             /* iFirst */
        -1,             /* iLast */
        312,            /* lineNo */
        21,             /* colNo */
        "",             /* aName */
        "ffOneChanCat", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtECInfo
    c_emlrtECI =
        {
            -1,             /* nDims */
            312,            /* lineNo */
            5,              /* colNo */
            "ffOneChanCat", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pName
                                                                          */
};

static emlrtRTEInfo
    h_emlrtRTEI =
        {
            159,            /* lineNo */
            1,              /* colNo */
            "filtfiltImpl", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pName
                                                                          */
};

static emlrtRTEInfo i_emlrtRTEI = {
    154,      /* lineNo */
    5,        /* colNo */
    "filter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" /* pName
                                                                           */
};

static emlrtRTEInfo j_emlrtRTEI = {
    152,      /* lineNo */
    5,        /* colNo */
    "filter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" /* pName
                                                                           */
};

static emlrtRTEInfo k_emlrtRTEI = {
    122,           /* lineNo */
    5,             /* colNo */
    "errOrWarnIf", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\indexShapeCheck.m" /* pName */
};

static emlrtRTEInfo l_emlrtRTEI = {
    22,           /* lineNo */
    27,           /* colNo */
    "validatelt", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatelt.m" /* pName */
};

static emlrtRTEInfo m_emlrtRTEI = {
    13,                   /* lineNo */
    37,                   /* colNo */
    "validateincreasing", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validateincreasing.m" /* pName */
};

static emlrtBCInfo c_emlrtBCI =
    {
        -1,                 /* iFirst */
        -1,                 /* iLast */
        562,                /* lineNo */
        13,                 /* colNo */
        "",                 /* aName */
        "removeSmallPeaks", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo d_emlrtBCI =
    {
        -1,                 /* iFirst */
        -1,                 /* iLast */
        562,                /* lineNo */
        11,                 /* colNo */
        "",                 /* aName */
        "removeSmallPeaks", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo e_emlrtBCI =
    {
        1,                  /* iFirst */
        740,                /* iLast */
        555,                /* lineNo */
        31,                 /* colNo */
        "",                 /* aName */
        "removeSmallPeaks", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo f_emlrtBCI =
    {
        1,                  /* iFirst */
        740,                /* iLast */
        555,                /* lineNo */
        22,                 /* colNo */
        "",                 /* aName */
        "removeSmallPeaks", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo g_emlrtBCI =
    {
        1,                  /* iFirst */
        740,                /* iLast */
        553,                /* lineNo */
        12,                 /* colNo */
        "",                 /* aName */
        "removeSmallPeaks", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo h_emlrtBCI =
    {
        -1,                   /* iFirst */
        -1,                   /* iLast */
        475,                  /* lineNo */
        14,                   /* colNo */
        "",                   /* aName */
        "getAllPeaksCodegen", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo i_emlrtBCI =
    {
        -1,                   /* iFirst */
        -1,                   /* iLast */
        502,                  /* lineNo */
        25,                   /* colNo */
        "",                   /* aName */
        "getAllPeaksCodegen", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo j_emlrtBCI =
    {
        -1,                   /* iFirst */
        -1,                   /* iLast */
        523,                  /* lineNo */
        14,                   /* colNo */
        "",                   /* aName */
        "getAllPeaksCodegen", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo k_emlrtBCI =
    {
        -1,                   /* iFirst */
        -1,                   /* iLast */
        511,                  /* lineNo */
        26,                   /* colNo */
        "",                   /* aName */
        "getAllPeaksCodegen", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo l_emlrtBCI =
    {
        -1,                   /* iFirst */
        -1,                   /* iLast */
        497,                  /* lineNo */
        26,                   /* colNo */
        "",                   /* aName */
        "getAllPeaksCodegen", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo m_emlrtBCI =
    {
        -1,                   /* iFirst */
        -1,                   /* iLast */
        489,                  /* lineNo */
        26,                   /* colNo */
        "",                   /* aName */
        "getAllPeaksCodegen", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo n_emlrtBCI =
    {
        -1,          /* iFirst */
        -1,          /* iLast */
        195,         /* lineNo */
        19,          /* colNo */
        "",          /* aName */
        "findpeaks", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo o_emlrtBCI =
    {
        -1,                 /* iFirst */
        -1,                 /* iLast */
        552,                /* lineNo */
        17,                 /* colNo */
        "",                 /* aName */
        "removeSmallPeaks", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo p_emlrtBCI =
    {
        -1,                 /* iFirst */
        -1,                 /* iLast */
        558,                /* lineNo */
        17,                 /* colNo */
        "",                 /* aName */
        "removeSmallPeaks", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo q_emlrtBCI =
    {
        -1,          /* iFirst */
        -1,          /* iLast */
        195,         /* lineNo */
        15,          /* colNo */
        "",          /* aName */
        "findpeaks", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtRTEInfo n_emlrtRTEI = {
    242,          /* lineNo */
    13,           /* colNo */
    "do_vectors", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" /* pName */
};

static emlrtRTEInfo o_emlrtRTEI = {
    245,          /* lineNo */
    13,           /* colNo */
    "do_vectors", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" /* pName */
};

static emlrtRTEInfo p_emlrtRTEI = {
    409,          /* lineNo */
    5,            /* colNo */
    "do_vectors", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" /* pName */
};

static emlrtRTEInfo q_emlrtRTEI = {
    420,          /* lineNo */
    9,            /* colNo */
    "do_vectors", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" /* pName */
};

static emlrtRTEInfo r_emlrtRTEI = {
    447,          /* lineNo */
    5,            /* colNo */
    "do_vectors", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" /* pName */
};

static emlrtRTEInfo s_emlrtRTEI =
    {
        618,                                           /* lineNo */
        18,                                            /* colNo */
        "findPeaksSeparatedByMoreThanMinPeakDistance", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m" /* pName
                                                                       */
};

static emlrtBCInfo r_emlrtBCI =
    {
        -1,                                            /* iFirst */
        -1,                                            /* iLast */
        619,                                           /* lineNo */
        35,                                            /* colNo */
        "",                                            /* aName */
        "findPeaksSeparatedByMoreThanMinPeakDistance", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo s_emlrtBCI =
    {
        -1,                                            /* iFirst */
        -1,                                            /* iLast */
        619,                                           /* lineNo */
        52,                                            /* colNo */
        "",                                            /* aName */
        "findPeaksSeparatedByMoreThanMinPeakDistance", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo t_emlrtBCI =
    {
        -1,                                            /* iFirst */
        -1,                                            /* iLast */
        619,                                           /* lineNo */
        67,                                            /* colNo */
        "",                                            /* aName */
        "findPeaksSeparatedByMoreThanMinPeakDistance", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo u_emlrtBCI =
    {
        -1,                                            /* iFirst */
        -1,                                            /* iLast */
        619,                                           /* lineNo */
        85,                                            /* colNo */
        "",                                            /* aName */
        "findPeaksSeparatedByMoreThanMinPeakDistance", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo v_emlrtBCI =
    {
        -1,                                            /* iFirst */
        -1,                                            /* iLast */
        619,                                           /* lineNo */
        100,                                           /* colNo */
        "",                                            /* aName */
        "findPeaksSeparatedByMoreThanMinPeakDistance", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo w_emlrtBCI =
    {
        -1,                                            /* iFirst */
        -1,                                            /* iLast */
        598,                                           /* lineNo */
        23,                                            /* colNo */
        "",                                            /* aName */
        "findPeaksSeparatedByMoreThanMinPeakDistance", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo x_emlrtBCI =
    {
        -1,                                            /* iFirst */
        -1,                                            /* iLast */
        603,                                           /* lineNo */
        15,                                            /* colNo */
        "",                                            /* aName */
        "findPeaksSeparatedByMoreThanMinPeakDistance", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo y_emlrtBCI =
    {
        -1,                                            /* iFirst */
        -1,                                            /* iLast */
        623,                                           /* lineNo */
        13,                                            /* colNo */
        "",                                            /* aName */
        "findPeaksSeparatedByMoreThanMinPeakDistance", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI =
    {
        -1,                                            /* iFirst */
        -1,                                            /* iLast */
        628,                                           /* lineNo */
        15,                                            /* colNo */
        "",                                            /* aName */
        "findPeaksSeparatedByMoreThanMinPeakDistance", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI =
    {
        -1,                                            /* iFirst */
        -1,                                            /* iLast */
        619,                                           /* lineNo */
        21,                                            /* colNo */
        "",                                            /* aName */
        "findPeaksSeparatedByMoreThanMinPeakDistance", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\findpeaks.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtRTEInfo t_emlrtRTEI = {
    51,     /* lineNo */
    19,     /* colNo */
    "diff", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m" /* pName
                                                                         */
};

static emlrtRTEInfo v_emlrtRTEI = {
    87,                             /* lineNo */
    33,                             /* colNo */
    "check_forloop_overflow_error", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_"
    "overflow_check.m" /* pName */
};

static emlrtRTEInfo w_emlrtRTEI = {
    62,           /* lineNo */
    39,           /* colNo */
    "stack/push", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\stack.m" /* pName */
};

static emlrtDCInfo emlrtDCI = {
    48,            /* lineNo */
    63,            /* colNo */
    "stack/stack", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\stack.m", /* pName */
    4                    /* checkKind */
};

static emlrtRTEInfo x_emlrtRTEI = {
    13,       /* lineNo */
    1,        /* colNo */
    "sparse", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m" /* pName
                                                                           */
};

static emlrtRTEInfo
    y_emlrtRTEI =
        {
            261,        /* lineNo */
            19,         /* colNo */
            "filtfilt", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pName
                                                                          */
};

static const int32_T iv[4] = {0, 1, 2, 3};

static const int8_T iv1[16] = {1, 1, 1, 1, 1, 1, 2, 3, 4, 5, 6, 2, 3, 4, 5, 6};

static const int8_T iv2[16] = {1, 2, 3, 4, 5, 6, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5};

static emlrtRSInfo ei_emlrtRSI = {
    14,        /* lineNo */
    "warning", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\warning.m" /* pathName */
};

static emlrtRSInfo fi_emlrtRSI = {
    53,        /* lineNo */
    "flt2str", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\flt2str.m" /* pathName */
};

covrtInstance emlrtCoverageInstance;

/* Function Declarations */
static boolean_T anyNonFinite(const real_T x[36]);

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               char_T y[23]);

static void b_feval(const emlrtStack *sp, const mxArray *m, const mxArray *m1,
                    emlrtMCInfo *location);

static void b_filter(const real_T x[19], real_T y[19]);

static void b_heapsort(const emlrtStack *sp, int32_T x_data[], int32_T xstart,
                       int32_T xend);

static void b_indexShapeCheck(void);

static void b_insertionsort(int32_T x_data[], int32_T xend);

static void b_introsort(const emlrtStack *sp, int32_T x_data[], int32_T xend);

static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *m1,
                                const mxArray *m2, emlrtMCInfo *location);

static void b_sqrt(const emlrtStack *sp, real_T x[19]);

static real_T b_std(const real_T x[740]);

static real_T b_sumColumnB(const emlrtStack *sp, const real_T x_data[],
                           int32_T vlen);

static void b_warning(const emlrtStack *sp);

static real_T b_xnrm2(int32_T n, const real_T x[3]);

static void b_xrot(const emlrtStack *sp, int32_T n, real_T x[36], int32_T ix0,
                   int32_T iy0, real_T c, real_T s);

static real_T bilinear(const emlrtStack *sp, const real_T z[36],
                       const real_T p[6], const real_T k[6], real_T zd[36],
                       real_T pd[6], real_T kd[6]);

static void butter(const emlrtStack *sp, const real_T Wn[2],
                   real_T varargout_1[7], real_T varargout_2[7]);

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier);

static int32_T
c_findPeaksSeparatedByMoreThanM(const emlrtStack *sp, const real_T y[740],
                                const real_T x[740], const int32_T iPk_data[],
                                int32_T iPk_size, int32_T idx_data[]);

static void c_insertionsort(const emlrtStack *sp, int32_T x_data[],
                            int32_T xstart, int32_T xend);

static real_T c_sumColumnB(const real_T x[19]);

static void c_warning(const emlrtStack *sp);

static void calcule_bpm_once(void);

static void check_forloop_overflow_error(const emlrtStack *sp);

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static void diff(const emlrtStack *sp, const real_T x_data[],
                 const int32_T x_size[2], real_T y_data[], int32_T y_size[2]);

static int32_T div_nde_s32_floor(int32_T numerator);

static int32_T do_vectors(const emlrtStack *sp, const int32_T a_data[],
                          int32_T a_size, const int32_T b_data[],
                          int32_T b_size, int32_T c_data[], int32_T ia_data[],
                          int32_T *ia_size, int32_T ib_data[],
                          int32_T *ib_size);

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[740];

static void eigSkewHermitianStandard(const emlrtStack *sp, const real_T A[36],
                                     creal_T V[6]);

static void emlrtExitTimeCleanupDtorFcn(const void *r);

static void emlrt_marshallIn(const emlrtStack *sp,
                             const mxArray *a__output_of_sprintf_,
                             const char_T *identifier, char_T y[23]);

static const mxArray *emlrt_marshallOut(const real_T u);

static void emxEnsureCapacity_int32_T(const emlrtStack *sp,
                                      emxArray_int32_T *emxArray,
                                      int32_T oldNumel,
                                      const emlrtRTEInfo *srcLocation);

static void emxEnsureCapacity_real_T(const emlrtStack *sp,
                                     emxArray_real_T *emxArray,
                                     int32_T oldNumel,
                                     const emlrtRTEInfo *srcLocation);

static void emxFree_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray);

static void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray);

static void emxInit_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray,
                            const emlrtRTEInfo *srcLocation);

static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                           const emlrtRTEInfo *srcLocation);

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[740];

static const mxArray *feval(const emlrtStack *sp, const mxArray *m1,
                            const mxArray *m2, emlrtMCInfo *location);

static void fft(const real_T x[19], creal_T y[19]);

static int32_T filter(const emlrtStack *sp, real_T b[7], real_T a[7],
                      const real_T x_data[], int32_T x_size, const real_T zi[6],
                      real_T y_data[]);

static void filtfilt(const emlrtStack *sp, const real_T ctf[7],
                     const real_T varargin_1[7], const real_T varargin_2[740],
                     real_T y[740]);

static int32_T findEffectiveFilterLen(real_T coef[7], real_T effLen_data[]);

static int32_T findpeaks(const emlrtStack *sp, const real_T Yin[740],
                         const real_T varargin_1[740], real_T varargin_3,
                         real_T Ypk_data[], real_T Xpk_data[],
                         int32_T Xpk_size[2]);

static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[19];

static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[19];

static void heapify(int32_T x_data[], int32_T idx, int32_T xstart,
                    int32_T xend);

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[23]);

static void indexShapeCheck(const emlrtStack *sp, int32_T matrixSize,
                            const int32_T indexSize[2]);

static void insertionsort(int32_T x[16]);

static void introsort(int32_T x[16]);

static boolean_T issorted(const int32_T x_data[], int32_T x_size);

static real_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[740];

static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[19];

static real_T mean(const emlrtStack *sp, const real_T x_data[],
                   const int32_T x_size[2]);

static void mrdiv(const emlrtStack *sp, real_T A[6], const real_T B[36]);

static real_T sumColumnB(const real_T x[740]);

static void warning(const emlrtStack *sp);

static real_T xdlanv2(real_T *a, real_T *b, real_T *c, real_T *d, real_T *rt1i,
                      real_T *rt2r, real_T *rt2i, real_T *cs, real_T *sn);

static int32_T xgetrf(const emlrtStack *sp, real_T A[36], int32_T ipiv[6]);

static int32_T xhseqr(const emlrtStack *sp, real_T h[36]);

static real_T xnrm2(const emlrtStack *sp, int32_T n, const real_T x[36],
                    int32_T ix0);

static void xrot(const emlrtStack *sp, int32_T n, real_T x[36], int32_T ix0,
                 int32_T iy0, real_T c, real_T s);

static void xscal(const emlrtStack *sp, int32_T n, real_T a, real_T x[36],
                  int32_T ix0);

static void xzlarf(const emlrtStack *sp, int32_T m, int32_T n, int32_T iv0,
                   real_T tau, real_T C[36], int32_T ic0, real_T work[6]);

static real_T zp2ss(const emlrtStack *sp, real_T a[9], real_T b[3],
                    real_T c[3]);

/* Function Definitions */
static boolean_T anyNonFinite(const real_T x[36])
{
  int32_T k;
  boolean_T p;
  p = true;
  for (k = 0; k < 36; k++) {
    if (p) {
      real_T d;
      d = x[k];
      if (muDoubleScalarIsInf(d) || muDoubleScalarIsNaN(d)) {
        p = false;
      }
    } else {
      p = false;
    }
  }
  return !p;
}

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[23])
{
  i_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void b_feval(const emlrtStack *sp, const mxArray *m, const mxArray *m1,
                    emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = m;
  pArrays[1] = m1;
  emlrtCallMATLABR2012b((emlrtConstCTX)sp, 0, NULL, 2, &pArrays[0], "feval",
                        true, location);
}

static void b_filter(const real_T x[19], real_T y[19])
{
  static const real_T dv[5] = {0.029954582208092471, 0.0, -0.059909164416184942,
                               0.0, 0.029954582208092471};
  static const real_T dv1[5] = {1.0, -3.3896867071734995, 4.37041391131624,
                                -2.5537313794916958, 0.57406191508395488};
  int32_T j;
  int32_T k;
  memset(&y[0], 0, 19U * sizeof(real_T));
  for (k = 0; k < 19; k++) {
    real_T as;
    int32_T i;
    int32_T y_tmp;
    if (19 - k < 5) {
      i = 18 - k;
    } else {
      i = 4;
    }
    for (j = 0; j <= i; j++) {
      y_tmp = k + j;
      y[y_tmp] += x[k] * dv[j];
    }
    if (18 - k < 4) {
      i = 17 - k;
    } else {
      i = 3;
    }
    as = -y[k];
    for (j = 0; j <= i; j++) {
      y_tmp = (k + j) + 1;
      y[y_tmp] += as * dv1[j + 1];
    }
  }
}

static void b_heapsort(const emlrtStack *sp, int32_T x_data[], int32_T xstart,
                       int32_T xend)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T idx;
  int32_T k;
  int32_T n;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  n = xend - xstart;
  for (idx = n + 1; idx >= 1; idx--) {
    heapify(x_data, idx, xstart, xend);
  }
  st.site = &jh_emlrtRSI;
  if (n > 2147483646) {
    b_st.site = &s_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (k = 0; k < n; k++) {
    int32_T t;
    idx = (xend - k) - 1;
    t = x_data[idx];
    x_data[idx] = x_data[xstart - 1];
    x_data[xstart - 1] = t;
    heapify(x_data, 1, xstart, idx);
  }
}

static void b_indexShapeCheck(void)
{
}

static void b_insertionsort(int32_T x_data[], int32_T xend)
{
  int32_T k;
  for (k = 2; k <= xend; k++) {
    int32_T idx;
    int32_T xc;
    boolean_T exitg1;
    xc = x_data[k - 1];
    idx = k - 1;
    exitg1 = false;
    while ((!exitg1) && (idx >= 1)) {
      int32_T i;
      i = x_data[idx - 1];
      if (xc < i) {
        x_data[idx] = i;
        idx--;
      } else {
        exitg1 = true;
      }
    }
    x_data[idx] = xc;
  }
}

static void b_introsort(const emlrtStack *sp, int32_T x_data[], int32_T xend)
{
  emlrtStack st;
  struct_T frame;
  int32_T pmax;
  int32_T pmin;
  st.prev = sp;
  st.tls = sp->tls;
  if (xend > 1) {
    if (xend <= 32) {
      b_insertionsort(x_data, xend);
    } else {
      struct_T st_d_data[120];
      int32_T MAXDEPTH;
      int32_T pow2p;
      int32_T st_d_size;
      int32_T st_n;
      int32_T xmid;
      boolean_T exitg1;
      pmax = 31;
      pmin = 0;
      exitg1 = false;
      while ((!exitg1) && (pmax - pmin > 1)) {
        xmid = (pmin + pmax) >> 1;
        pow2p = 1 << xmid;
        if (pow2p == xend) {
          pmax = xmid;
          exitg1 = true;
        } else if (pow2p > xend) {
          pmax = xmid;
        } else {
          pmin = xmid;
        }
      }
      MAXDEPTH = (pmax - 1) << 1;
      frame.xstart = 1;
      frame.xend = xend;
      frame.depth = 0;
      st.site = &ih_emlrtRSI;
      st_d_size = MAXDEPTH << 1;
      if (st_d_size < 0) {
        emlrtNonNegativeCheckR2012b(st_d_size, &emlrtDCI, &st);
      }
      st.site = &ch_emlrtRSI;
      if (st_d_size <= 0) {
        emlrtErrorWithMessageIdR2018a(&st, &w_emlrtRTEI,
                                      "Coder:toolbox:StackPushLimit",
                                      "Coder:toolbox:StackPushLimit", 0);
      }
      st_d_data[0] = frame;
      st_n = 1;
      while (st_n > 0) {
        frame = st_d_data[st_n - 1];
        st_n--;
        pmin = frame.xend - frame.xstart;
        if (pmin + 1 <= 32) {
          st.site = &eh_emlrtRSI;
          c_insertionsort(&st, x_data, frame.xstart, frame.xend);
        } else if (frame.depth == MAXDEPTH) {
          st.site = &fh_emlrtRSI;
          b_heapsort(&st, x_data, frame.xstart, frame.xend);
        } else {
          int32_T t;
          xmid = (frame.xstart + pmin / 2) - 1;
          pmin = x_data[frame.xstart - 1];
          if (x_data[xmid] < pmin) {
            x_data[frame.xstart - 1] = x_data[xmid];
            x_data[xmid] = pmin;
          }
          pmin = x_data[frame.xstart - 1];
          pmax = x_data[frame.xend - 1];
          if (pmax < pmin) {
            x_data[frame.xstart - 1] = pmax;
            x_data[frame.xend - 1] = pmin;
          }
          pmin = x_data[frame.xend - 1];
          if (pmin < x_data[xmid]) {
            t = x_data[xmid];
            x_data[xmid] = pmin;
            x_data[frame.xend - 1] = t;
          }
          pow2p = x_data[xmid];
          x_data[xmid] = x_data[frame.xend - 2];
          x_data[frame.xend - 2] = pow2p;
          pmax = frame.xstart - 1;
          pmin = frame.xend - 2;
          int32_T exitg2;
          do {
            exitg2 = 0;
            for (pmax++; x_data[pmax] < pow2p; pmax++) {
            }
            for (pmin--; pow2p < x_data[pmin]; pmin--) {
            }
            if (pmax + 1 >= pmin + 1) {
              exitg2 = 1;
            } else {
              t = x_data[pmax];
              x_data[pmax] = x_data[pmin];
              x_data[pmin] = t;
            }
          } while (exitg2 == 0);
          x_data[frame.xend - 2] = x_data[pmax];
          x_data[pmax] = pow2p;
          if (pmax + 2 < frame.xend) {
            st.site = &gh_emlrtRSI;
            if (st_n >= st_d_size) {
              emlrtErrorWithMessageIdR2018a(&st, &w_emlrtRTEI,
                                            "Coder:toolbox:StackPushLimit",
                                            "Coder:toolbox:StackPushLimit", 0);
            }
            st_d_data[st_n].xstart = pmax + 2;
            st_d_data[st_n].xend = frame.xend;
            st_d_data[st_n].depth = frame.depth + 1;
            st_n++;
          }
          if (frame.xstart < pmax + 1) {
            st.site = &hh_emlrtRSI;
            if (st_n >= st_d_size) {
              emlrtErrorWithMessageIdR2018a(&st, &w_emlrtRTEI,
                                            "Coder:toolbox:StackPushLimit",
                                            "Coder:toolbox:StackPushLimit", 0);
            }
            st_d_data[st_n].xstart = frame.xstart;
            st_d_data[st_n].xend = pmax + 1;
            st_d_data[st_n].depth = frame.depth + 1;
            st_n++;
          }
        }
      }
    }
  }
}

static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *m1,
                                const mxArray *m2, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  return emlrtCallMATLABR2012b((emlrtConstCTX)sp, 1, &m, 2, &pArrays[0],
                               "sprintf", true, location);
}

static void b_sqrt(const emlrtStack *sp, real_T x[19])
{
  int32_T k;
  boolean_T p;
  p = false;
  for (k = 0; k < 19; k++) {
    if (p || (x[k] < 0.0)) {
      p = true;
    }
  }
  if (p) {
    emlrtErrorWithMessageIdR2018a(
        sp, &b_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  for (k = 0; k <= 16; k += 2) {
    __m128d r;
    r = _mm_loadu_pd(&x[k]);
    _mm_storeu_pd(&x[k], _mm_sqrt_pd(r));
  }
  x[18] = muDoubleScalarSqrt(x[18]);
}

static real_T b_std(const real_T x[740])
{
  ptrdiff_t incx_t;
  ptrdiff_t n_t;
  real_T absdiff[740];
  real_T dv[2];
  real_T dv1[2];
  real_T y;
  int32_T k;
  y = sumColumnB(x) / 740.0;
  for (k = 0; k <= 738; k += 2) {
    __m128d r;
    _mm_storeu_pd(&dv[0], _mm_sub_pd(_mm_loadu_pd(&x[k]), _mm_set1_pd(y)));
    dv1[0] = muDoubleScalarAbs(dv[0]);
    dv1[1] = muDoubleScalarAbs(dv[1]);
    r = _mm_loadu_pd(&dv1[0]);
    _mm_storeu_pd(&absdiff[k], r);
  }
  n_t = (ptrdiff_t)740;
  incx_t = (ptrdiff_t)1;
  y = dnrm2(&n_t, &absdiff[0], &incx_t);
  y /= 27.184554438136374;
  return y;
}

static real_T b_sumColumnB(const emlrtStack *sp, const real_T x_data[],
                           int32_T vlen)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T y;
  int32_T i;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &rh_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  y = x_data[0];
  b_st.site = &sh_emlrtRSI;
  if (vlen - 1 > 2147483646) {
    c_st.site = &s_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  i = (uint16_T)(vlen - 1);
  for (k = 0; k < i; k++) {
    y += x_data[k + 1];
  }
  return y;
}

static void b_warning(const emlrtStack *sp)
{
  static const int32_T b_iv[2] = {1, 7};
  static const int32_T b_iv1[2] = {1, 7};
  static const int32_T b_iv2[2] = {1, 24};
  static const char_T msgID[24] = {'M', 'A', 'T', 'L', 'A', 'B', ':', 'e',
                                   'i', 'g', ':', 'N', 'o', 'C', 'o', 'n',
                                   'v', 'e', 'r', 'g', 'e', 'n', 'c', 'e'};
  static const char_T b_u[7] = {'m', 'e', 's', 's', 'a', 'g', 'e'};
  static const char_T u[7] = {'w', 'a', 'r', 'n', 'i', 'n', 'g'};
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  const mxArray *y;
  st.prev = sp;
  st.tls = sp->tls;
  y = NULL;
  m = emlrtCreateCharArray(2, &b_iv[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 7, m, &u[0]);
  emlrtAssign(&y, m);
  b_y = NULL;
  m = emlrtCreateCharArray(2, &b_iv1[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 7, m, &b_u[0]);
  emlrtAssign(&b_y, m);
  c_y = NULL;
  m = emlrtCreateCharArray(2, &b_iv2[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 24, m, &msgID[0]);
  emlrtAssign(&c_y, m);
  st.site = &ei_emlrtRSI;
  b_feval(&st, y, feval(&st, b_y, c_y, &emlrtMCI), &b_emlrtMCI);
}

static real_T b_xnrm2(int32_T n, const real_T x[3])
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = muDoubleScalarAbs(x[1]);
    } else {
      real_T absxk;
      real_T scale;
      real_T t;
      scale = 3.3121686421112381E-170;
      absxk = muDoubleScalarAbs(x[1]);
      if (absxk > 3.3121686421112381E-170) {
        y = 1.0;
        scale = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        y = t * t;
      }
      absxk = muDoubleScalarAbs(x[2]);
      if (absxk > scale) {
        t = scale / absxk;
        y = y * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        y += t * t;
      }
      y = scale * muDoubleScalarSqrt(y);
    }
  }
  return y;
}

static void b_xrot(const emlrtStack *sp, int32_T n, real_T x[36], int32_T ix0,
                   int32_T iy0, real_T c, real_T s)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &qe_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (n >= 1) {
    int32_T i;
    b_st.site = &re_emlrtRSI;
    if (n > 2147483646) {
      c_st.site = &s_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    i = (uint8_T)n;
    for (k = 0; k < i; k++) {
      real_T b_temp_tmp;
      real_T temp_tmp;
      int32_T b_temp_tmp_tmp;
      int32_T temp_tmp_tmp;
      temp_tmp_tmp = (iy0 + k) - 1;
      temp_tmp = x[temp_tmp_tmp];
      b_temp_tmp_tmp = (ix0 + k) - 1;
      b_temp_tmp = x[b_temp_tmp_tmp];
      x[temp_tmp_tmp] = c * temp_tmp - s * b_temp_tmp;
      x[b_temp_tmp_tmp] = c * b_temp_tmp + s * temp_tmp;
    }
  }
}

static real_T bilinear(const emlrtStack *sp, const real_T z[36],
                       const real_T p[6], const real_T k[6], real_T zd[36],
                       real_T pd[6], real_T kd[6])
{
  __m128d r;
  __m128d r1;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  real_T t1_tmp[36];
  real_T t2[36];
  real_T Y[6];
  real_T dd;
  int32_T ipiv[6];
  int32_T b_i;
  int32_T b_k;
  int32_T i;
  int32_T info;
  int32_T j;
  int32_T jBcol;
  int32_T kAcol;
  int32_T zd_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  memset(&t2[0], 0, 36U * sizeof(real_T));
  for (b_k = 0; b_k < 6; b_k++) {
    t2[b_k + 6 * b_k] = 1.0;
  }
  for (i = 0; i <= 34; i += 2) {
    r = _mm_div_pd(_mm_mul_pd(_mm_loadu_pd(&z[i]), _mm_set1_pd(0.5)),
                   _mm_set1_pd(2.0));
    r1 = _mm_loadu_pd(&t2[i]);
    _mm_storeu_pd(&zd[i], _mm_add_pd(r1, r));
    _mm_storeu_pd(&t2[i], _mm_sub_pd(r1, r));
  }
  st.site = &cb_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  c_st.site = &w_emlrtRSI;
  d_st.site = &gb_emlrtRSI;
  e_st.site = &hb_emlrtRSI;
  f_st.site = &jb_emlrtRSI;
  memcpy(&t1_tmp[0], &t2[0], 36U * sizeof(real_T));
  g_st.site = &kb_emlrtRSI;
  info = xgetrf(&g_st, t1_tmp, ipiv);
  for (b_i = 0; b_i < 5; b_i++) {
    i = ipiv[b_i];
    if (i != b_i + 1) {
      for (j = 0; j < 6; j++) {
        jBcol = b_i + 6 * j;
        dd = zd[jBcol];
        zd_tmp = (i + 6 * j) - 1;
        zd[jBcol] = zd[zd_tmp];
        zd[zd_tmp] = dd;
      }
    }
  }
  for (j = 0; j < 6; j++) {
    jBcol = 6 * j;
    for (b_k = 0; b_k < 6; b_k++) {
      kAcol = 6 * b_k;
      i = b_k + jBcol;
      if (zd[i] != 0.0) {
        int32_T i1;
        i1 = b_k + 2;
        for (b_i = i1; b_i < 7; b_i++) {
          zd_tmp = (b_i + jBcol) - 1;
          zd[zd_tmp] -= zd[i] * t1_tmp[(b_i + kAcol) - 1];
        }
      }
    }
  }
  for (j = 0; j < 6; j++) {
    jBcol = 6 * j;
    for (b_k = 5; b_k >= 0; b_k--) {
      kAcol = 6 * b_k;
      i = b_k + jBcol;
      dd = zd[i];
      if (dd != 0.0) {
        zd[i] = dd / t1_tmp[b_k + kAcol];
        for (b_i = 0; b_i < b_k; b_i++) {
          zd_tmp = b_i + jBcol;
          zd[zd_tmp] -= zd[i] * t1_tmp[b_i + kAcol];
        }
      }
    }
  }
  if (info > 0) {
    e_st.site = &ib_emlrtRSI;
    f_st.site = &y_emlrtRSI;
    warning(&f_st);
  }
  st.site = &db_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  c_st.site = &w_emlrtRSI;
  d_st.site = &gb_emlrtRSI;
  for (b_i = 0; b_i < 6; b_i++) {
    pd[b_i] = p[b_i];
  }
  e_st.site = &hb_emlrtRSI;
  f_st.site = &jb_emlrtRSI;
  memcpy(&t1_tmp[0], &t2[0], 36U * sizeof(real_T));
  g_st.site = &kb_emlrtRSI;
  info = xgetrf(&g_st, t1_tmp, ipiv);
  for (b_i = 0; b_i < 5; b_i++) {
    i = ipiv[b_i];
    if (i != b_i + 1) {
      dd = pd[b_i];
      pd[b_i] = pd[i - 1];
      pd[i - 1] = dd;
    }
  }
  for (b_k = 0; b_k < 6; b_k++) {
    kAcol = 6 * b_k;
    if (pd[b_k] != 0.0) {
      i = b_k + 2;
      for (b_i = i; b_i < 7; b_i++) {
        pd[b_i - 1] -= pd[b_k] * t1_tmp[(b_i + kAcol) - 1];
      }
    }
  }
  for (b_k = 5; b_k >= 0; b_k--) {
    kAcol = 6 * b_k;
    dd = pd[b_k];
    if (dd != 0.0) {
      dd /= t1_tmp[b_k + kAcol];
      pd[b_k] = dd;
      for (b_i = 0; b_i < b_k; b_i++) {
        pd[b_i] -= pd[b_k] * t1_tmp[b_i + kAcol];
      }
    }
  }
  if (info > 0) {
    e_st.site = &ib_emlrtRSI;
    f_st.site = &y_emlrtRSI;
    warning(&f_st);
  }
  r = _mm_loadu_pd(&pd[0]);
  r1 = _mm_set1_pd(0.70710678118654746);
  _mm_storeu_pd(&pd[0], _mm_mul_pd(r1, r));
  r = _mm_loadu_pd(&pd[2]);
  _mm_storeu_pd(&pd[2], _mm_mul_pd(r1, r));
  r = _mm_loadu_pd(&pd[4]);
  _mm_storeu_pd(&pd[4], _mm_mul_pd(r1, r));
  st.site = &eb_emlrtRSI;
  r = _mm_set1_pd(0.70710678118654757);
  _mm_storeu_pd(&kd[0], _mm_mul_pd(r, _mm_loadu_pd(&k[0])));
  _mm_storeu_pd(&kd[2], _mm_mul_pd(r, _mm_loadu_pd(&k[2])));
  _mm_storeu_pd(&kd[4], _mm_mul_pd(r, _mm_loadu_pd(&k[4])));
  b_st.site = &yb_emlrtRSI;
  mrdiv(&b_st, kd, t2);
  st.site = &fb_emlrtRSI;
  for (i = 0; i < 6; i++) {
    Y[i] = k[i];
  }
  b_st.site = &yb_emlrtRSI;
  mrdiv(&b_st, Y, t2);
  dd = 0.0;
  for (i = 0; i < 6; i++) {
    dd += Y[i] * p[i];
  }
  return dd * 0.5 / 2.0;
}

static void butter(const emlrtStack *sp, const real_T Wn[2],
                   real_T varargout_1[7], real_T varargout_2[7])
{
  static const char_T b_fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                     '_', 'd', 'g', 'e', 'e', 'v', 'x'};
  static const char_T fname[13] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                   '_', 'd', 's', 'y', 'e', 'v'};
  static const int8_T b_iv[18] = {-1, 0, 0, 0, -1, 0, 0, 0, -1,
                                  0,  0, 0, 0, 0,  0, 0, 0, 0};
  static const int8_T b_iv1[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  static const int8_T b_b[7] = {1, 0, -3, 0, 3, 0, -1};
  static const int8_T b_iv2[6] = {1, 1, 1, -1, -1, -1};
  ptrdiff_t ihi_t;
  ptrdiff_t ilo_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  creal_T c_c[7];
  creal_T b_p[6];
  creal_T x[6];
  real_T A[36];
  real_T b_Wn1[36];
  real_T a[9];
  real_T b_c[6];
  real_T scale[6];
  real_T wimag[6];
  real_T wreal[6];
  real_T b[3];
  real_T c[3];
  real_T Wn1;
  real_T q;
  real_T rconde;
  real_T rcondv;
  real_T u_idx_0;
  real_T u_idx_1;
  real_T x_re;
  int32_T Wn1_tmp;
  int32_T j;
  int32_T k;
  boolean_T varargin_1[2];
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &f_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  b_st.site = &g_emlrtRSI;
  c_st.site = &n_emlrtRSI;
  d_st.site = &o_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(Wn[k] <= 0.0)) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &c_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:butter:expectedPositive", 3, 4, 2, "Wn");
  }
  d_st.site = &o_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(Wn[k])) && (!muDoubleScalarIsNaN(Wn[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:butter:expectedFinite", 3, 4, 2, "Wn");
  }
  varargin_1[0] = (Wn[0] >= 1.0);
  varargin_1[1] = (Wn[1] >= 1.0);
  p = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (varargin_1[k]) {
      p = true;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &emlrtRTEI,
        "signal:classicaliirfilters:freqMustBeWithinUnitInterval",
        "signal:classicaliirfilters:freqMustBeWithinUnitInterval", 0);
  }
  u_idx_0 = 4.0 * muDoubleScalarTan(3.1415926535897931 * Wn[0] / 2.0);
  u_idx_1 = 4.0 * muDoubleScalarTan(3.1415926535897931 * Wn[1] / 2.0);
  b_st.site = &h_emlrtRSI;
  zp2ss(&b_st, a, b, c);
  q = u_idx_1 - u_idx_0;
  b_st.site = &i_emlrtRSI;
  Wn1 = u_idx_0 * u_idx_1;
  if (Wn1 < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &b_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  Wn1 = muDoubleScalarSqrt(Wn1);
  b_st.site = &j_emlrtRSI;
  c_st.site = &ab_emlrtRSI;
  d_st.site = &o_emlrtRSI;
  if (muDoubleScalarIsInf(Wn1) || muDoubleScalarIsNaN(Wn1)) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:lp2bp:expectedFinite", 3, 4, 19, "input number 5, Wo,");
  }
  c_st.site = &bb_emlrtRSI;
  d_st.site = &o_emlrtRSI;
  if (muDoubleScalarIsInf(q) || muDoubleScalarIsNaN(q)) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:lp2bp:expectedFinite", 3, 4, 19, "input number 6, Bw,");
  }
  q = Wn1 / q;
  for (j = 0; j < 3; j++) {
    b_Wn1[6 * j] = Wn1 * (a[3 * j] / q);
    k = 6 * (j + 3);
    b_Wn1[k] = Wn1 * (real_T)b_iv1[3 * j];
    Wn1_tmp = 3 * j + 1;
    b_Wn1[6 * j + 1] = Wn1 * (a[Wn1_tmp] / q);
    b_Wn1[k + 1] = Wn1 * (real_T)b_iv1[Wn1_tmp];
    Wn1_tmp = 3 * j + 2;
    b_Wn1[6 * j + 2] = Wn1 * (a[Wn1_tmp] / q);
    b_Wn1[k + 2] = Wn1 * (real_T)b_iv1[Wn1_tmp];
  }
  for (j = 0; j < 6; j++) {
    b_Wn1[6 * j + 3] = Wn1 * (real_T)b_iv[3 * j];
    b_Wn1[6 * j + 4] = Wn1 * (real_T)b_iv[3 * j + 1];
    b_Wn1[6 * j + 5] = Wn1 * (real_T)b_iv[3 * j + 2];
  }
  __m128d r;
  r = _mm_loadu_pd(&b[0]);
  _mm_storeu_pd(&wimag[0],
                _mm_mul_pd(_mm_set1_pd(Wn1), _mm_div_pd(r, _mm_set1_pd(q))));
  _mm_storeu_pd(&wimag[3], _mm_set1_pd(Wn1 * 0.0));
  r = _mm_loadu_pd(&c[0]);
  _mm_storeu_pd(&b_c[0], r);
  _mm_storeu_pd(&b_c[3], _mm_set1_pd(0.0));
  wimag[2] = Wn1 * (b[2] / q);
  wimag[5] = Wn1 * 0.0;
  b_c[2] = c[2];
  b_c[5] = 0.0;
  b_st.site = &k_emlrtRSI;
  bilinear(&b_st, b_Wn1, wimag, b_c, A, scale, wreal);
  b_st.site = &l_emlrtRSI;
  c_st.site = &fc_emlrtRSI;
  if (anyNonFinite(A)) {
    for (Wn1_tmp = 0; Wn1_tmp < 6; Wn1_tmp++) {
      b_p[Wn1_tmp].re = rtNaN;
      b_p[Wn1_tmp].im = 0.0;
    }
  } else {
    int32_T exitg2;
    p = true;
    j = 0;
    exitg1 = false;
    while ((!exitg1) && (j < 6)) {
      Wn1_tmp = 0;
      do {
        exitg2 = 0;
        if (Wn1_tmp <= j) {
          if (!(A[Wn1_tmp + 6 * j] == A[j + 6 * Wn1_tmp])) {
            p = false;
            exitg2 = 1;
          } else {
            Wn1_tmp++;
          }
        } else {
          j++;
          exitg2 = 2;
        }
      } while (exitg2 == 0);
      if (exitg2 == 1) {
        exitg1 = true;
      }
    }
    if (p) {
      ptrdiff_t info_t;
      c_st.site = &gc_emlrtRSI;
      d_st.site = &mc_emlrtRSI;
      e_st.site = &oc_emlrtRSI;
      ilo_t = (ptrdiff_t)6;
      info_t = LAPACKE_dsyev(102, 'N', 'L', ilo_t, &A[0], ilo_t, &scale[0]);
      f_st.site = &pc_emlrtRSI;
      if ((int32_T)info_t < 0) {
        if ((int32_T)info_t == -1010) {
          emlrtErrorWithMessageIdR2018a(&f_st, &f_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&f_st, &g_emlrtRTEI,
                                        "Coder:toolbox:LAPACKCallErrorInfo",
                                        "Coder:toolbox:LAPACKCallErrorInfo", 5,
                                        4, 13, &fname[0], 12, (int32_T)info_t);
        }
      }
      for (Wn1_tmp = 0; Wn1_tmp < 6; Wn1_tmp++) {
        b_p[Wn1_tmp].re = scale[Wn1_tmp];
        b_p[Wn1_tmp].im = 0.0;
      }
      if ((int32_T)info_t != 0) {
        d_st.site = &nc_emlrtRSI;
        b_warning(&d_st);
      }
    } else {
      p = true;
      j = 0;
      exitg1 = false;
      while ((!exitg1) && (j < 6)) {
        Wn1_tmp = 0;
        do {
          exitg2 = 0;
          if (Wn1_tmp <= j) {
            if (!(A[Wn1_tmp + 6 * j] == -A[j + 6 * Wn1_tmp])) {
              p = false;
              exitg2 = 1;
            } else {
              Wn1_tmp++;
            }
          } else {
            j++;
            exitg2 = 2;
          }
        } while (exitg2 == 0);
        if (exitg2 == 1) {
          exitg1 = true;
        }
      }
      if (p) {
        c_st.site = &hc_emlrtRSI;
        eigSkewHermitianStandard(&c_st, A, b_p);
      } else {
        ptrdiff_t info_t;
        c_st.site = &ic_emlrtRSI;
        d_st.site = &se_emlrtRSI;
        e_st.site = &ve_emlrtRSI;
        info_t = LAPACKE_dgeevx(102, 'B', 'N', 'N', 'N', (ptrdiff_t)6, &A[0],
                                (ptrdiff_t)6, &wreal[0], &wimag[0], &q,
                                (ptrdiff_t)1, &u_idx_0, (ptrdiff_t)1, &ilo_t,
                                &ihi_t, &scale[0], &u_idx_1, &rconde, &rcondv);
        f_st.site = &ue_emlrtRSI;
        if ((int32_T)info_t < 0) {
          if ((int32_T)info_t == -1010) {
            emlrtErrorWithMessageIdR2018a(&f_st, &f_emlrtRTEI, "MATLAB:nomem",
                                          "MATLAB:nomem", 0);
          } else {
            emlrtErrorWithMessageIdR2018a(
                &f_st, &g_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
                "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &b_fname[0], 12,
                (int32_T)info_t);
          }
        }
        for (Wn1_tmp = 0; Wn1_tmp < 6; Wn1_tmp++) {
          b_p[Wn1_tmp].re = wreal[Wn1_tmp];
          b_p[Wn1_tmp].im = wimag[Wn1_tmp];
        }
        if ((int32_T)info_t != 0) {
          d_st.site = &te_emlrtRSI;
          b_warning(&d_st);
        }
      }
    }
  }
  q = 2.0 * muDoubleScalarAtan2(Wn1, 4.0);
  if (q * 0.0 == 0.0) {
    Wn1 = muDoubleScalarCos(q);
    u_idx_1 = muDoubleScalarSin(q);
  } else if (q == 0.0) {
    Wn1 = rtNaN;
    u_idx_1 = 0.0;
  } else {
    Wn1 = rtNaN;
    u_idx_1 = rtNaN;
  }
  for (Wn1_tmp = 0; Wn1_tmp < 6; Wn1_tmp++) {
    x[Wn1_tmp].re = Wn1 - b_p[Wn1_tmp].re;
    x[Wn1_tmp].im = u_idx_1 - b_p[Wn1_tmp].im;
  }
  x_re = x[0].re;
  rconde = x[0].im;
  for (k = 0; k < 5; k++) {
    u_idx_0 = x[k + 1].im;
    rcondv = x[k + 1].re;
    q = x_re * rcondv - rconde * u_idx_0;
    rconde = x_re * u_idx_0 + rconde * rcondv;
    x_re = q;
  }
  for (Wn1_tmp = 0; Wn1_tmp < 6; Wn1_tmp++) {
    x[Wn1_tmp].re = Wn1 - (real_T)b_iv2[Wn1_tmp];
    x[Wn1_tmp].im = u_idx_1;
  }
  Wn1 = x[0].re;
  u_idx_1 = x[0].im;
  for (k = 0; k < 5; k++) {
    u_idx_0 = x[k + 1].im;
    rcondv = x[k + 1].re;
    q = Wn1 * rcondv - u_idx_1 * u_idx_0;
    u_idx_1 = Wn1 * u_idx_0 + u_idx_1 * rcondv;
    Wn1 = q;
  }
  if (u_idx_1 == 0.0) {
    if (rconde == 0.0) {
      x_re /= Wn1;
    } else if (x_re == 0.0) {
      x_re = 0.0;
    } else {
      x_re /= Wn1;
    }
  } else if (Wn1 == 0.0) {
    if (x_re == 0.0) {
      x_re = rconde / u_idx_1;
    } else if (rconde == 0.0) {
      x_re = 0.0;
    } else {
      x_re = rconde / u_idx_1;
    }
  } else {
    q = muDoubleScalarAbs(Wn1);
    u_idx_0 = muDoubleScalarAbs(u_idx_1);
    if (q > u_idx_0) {
      q = u_idx_1 / Wn1;
      x_re = (x_re + q * rconde) / (Wn1 + q * u_idx_1);
    } else if (u_idx_0 == q) {
      if (Wn1 > 0.0) {
        Wn1 = 0.5;
      } else {
        Wn1 = -0.5;
      }
      if (u_idx_1 > 0.0) {
        u_idx_0 = 0.5;
      } else {
        u_idx_0 = -0.5;
      }
      x_re = (x_re * Wn1 + rconde * u_idx_0) / q;
    } else {
      q = Wn1 / u_idx_1;
      x_re = (q * x_re + rconde) / (u_idx_1 + q * Wn1);
    }
  }
  b_st.site = &m_emlrtRSI;
  c_st.site = &u_emlrtRSI;
  for (j = 0; j < 6; j++) {
    q = b_p[j].re;
    u_idx_0 = b_p[j].im;
    if (muDoubleScalarIsInf(q) || muDoubleScalarIsInf(u_idx_0) ||
        (muDoubleScalarIsNaN(q) || muDoubleScalarIsNaN(u_idx_0))) {
      emlrtErrorWithMessageIdR2018a(
          &c_st, &e_emlrtRTEI, "Coder:toolbox:nonfiniteValuesNotSupported",
          "Coder:toolbox:nonfiniteValuesNotSupported", 0);
    }
  }
  c_c[0].re = 1.0;
  c_c[0].im = 0.0;
  for (j = 0; j < 6; j++) {
    u_idx_1 = b_p[j].re;
    rconde = b_p[j].im;
    u_idx_0 = c_c[j].im;
    rcondv = c_c[j].re;
    c_c[j + 1].re = -u_idx_1 * rcondv - -rconde * u_idx_0;
    c_c[j + 1].im = -u_idx_1 * u_idx_0 + -rconde * rcondv;
    for (k = j + 1; k >= 2; k--) {
      q = c_c[k - 2].im;
      u_idx_0 = c_c[k - 2].re;
      c_c[k - 1].re -= u_idx_1 * u_idx_0 - rconde * q;
      c_c[k - 1].im -= u_idx_1 * q + rconde * u_idx_0;
    }
  }
  for (j = 0; j < 7; j++) {
    varargout_2[j] = c_c[j].re;
    varargout_1[j] = x_re * (real_T)b_b[j];
  }
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static int32_T
c_findPeaksSeparatedByMoreThanM(const emlrtStack *sp, const real_T y[740],
                                const real_T x[740], const int32_T iPk_data[],
                                int32_T iPk_size, int32_T idx_data[])
{
  emlrtStack st;
  int32_T iwork_data[1480];
  int32_T b_i;
  int32_T i;
  int32_T idx_size;
  int32_T j;
  int32_T k;
  int32_T qEnd;
  int16_T tmp_data[1480];
  boolean_T idelete_data[1480];
  st.prev = sp;
  st.tls = sp->tls;
  if (iPk_size == 0) {
    idx_size = 0;
  } else {
    real_T idelete_tmp;
    int32_T sortIdx_data[1480];
    int32_T i2;
    i = iPk_size - 1;
    for (k = 1; k <= i; k += 2) {
      idelete_tmp = y[iPk_data[k - 1] - 1];
      if ((idelete_tmp >= y[iPk_data[k] - 1]) ||
          muDoubleScalarIsNaN(idelete_tmp)) {
        sortIdx_data[k - 1] = k;
        sortIdx_data[k] = k + 1;
      } else {
        sortIdx_data[k - 1] = k + 1;
        sortIdx_data[k] = k;
      }
    }
    if (((uint32_T)iPk_size & 1U) != 0U) {
      sortIdx_data[iPk_size - 1] = iPk_size;
    }
    b_i = 2;
    while (b_i < iPk_size) {
      i2 = b_i << 1;
      j = 1;
      for (idx_size = b_i + 1; idx_size < iPk_size + 1; idx_size = qEnd + b_i) {
        int32_T kEnd;
        int32_T p;
        int32_T q;
        p = j - 1;
        q = idx_size;
        qEnd = j + i2;
        if (qEnd > iPk_size + 1) {
          qEnd = iPk_size + 1;
        }
        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          idelete_tmp = y[iPk_data[sortIdx_data[p] - 1] - 1];
          i = sortIdx_data[q - 1];
          if ((idelete_tmp >= y[iPk_data[i - 1] - 1]) ||
              muDoubleScalarIsNaN(idelete_tmp)) {
            iwork_data[k] = sortIdx_data[p];
            p++;
            if (p + 1 == idx_size) {
              while (q < qEnd) {
                k++;
                iwork_data[k] = sortIdx_data[q - 1];
                q++;
              }
            }
          } else {
            iwork_data[k] = i;
            q++;
            if (q == qEnd) {
              while (p + 1 < idx_size) {
                k++;
                iwork_data[k] = sortIdx_data[p];
                p++;
              }
            }
          }
          k++;
        }
        for (k = 0; k < kEnd; k++) {
          sortIdx_data[(j + k) - 1] = iwork_data[k];
        }
        j = qEnd;
      }
      b_i = i2;
    }
    for (i = 0; i < iPk_size; i++) {
      i2 = sortIdx_data[i];
      if ((i2 < 1) || (i2 > iPk_size)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, iPk_size, &w_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
    }
    memset(&idelete_data[0], 0, (uint32_T)iPk_size * sizeof(boolean_T));
    for (b_i = 0; b_i < iPk_size; b_i++) {
      if (b_i + 1 > iPk_size) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, iPk_size, &x_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (!idelete_data[b_i]) {
        emlrtForLoopVectorCheckR2021a(iPk_size, -1.0, 1.0, mxDOUBLE_CLASS,
                                      iPk_size, &s_emlrtRTEI,
                                      (emlrtConstCTX)sp);
        idelete_tmp = x[iPk_data[sortIdx_data[b_i] - 1] - 1];
        for (j = 0; j < iPk_size; j++) {
          real_T b_idelete_tmp;
          i2 = iPk_size - j;
          if ((i2 < 1) || (i2 > iPk_size)) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, iPk_size, &r_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          if (i2 > iPk_size) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, iPk_size, &s_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          if (b_i + 1 > iPk_size) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, iPk_size, &t_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          if (i2 > iPk_size) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, iPk_size, &u_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          if (b_i + 1 > iPk_size) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, iPk_size, &v_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          if (i2 > iPk_size) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, iPk_size, &bb_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          b_idelete_tmp = x[iPk_data[sortIdx_data[i2 - 1] - 1] - 1];
          idelete_data[i2 - 1] =
              (idelete_data[i2 - 1] || ((b_idelete_tmp >= idelete_tmp - 0.4) &&
                                        (b_idelete_tmp <= idelete_tmp + 0.4)));
        }
        if (b_i + 1 > iPk_size) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, iPk_size, &y_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        idelete_data[b_i] = false;
      }
    }
    idx_size = 0;
    i2 = 0;
    for (b_i = 0; b_i < iPk_size; b_i++) {
      if (!idelete_data[b_i]) {
        idx_size++;
        tmp_data[i2] = (int16_T)b_i;
        i2++;
      }
    }
    for (i = 0; i < idx_size; i++) {
      int16_T i1;
      i1 = tmp_data[i];
      if (i1 > iPk_size - 1) {
        emlrtDynamicBoundsCheckR2012b(i1, 0, iPk_size - 1, &ab_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      idx_data[i] = sortIdx_data[i1];
    }
    if (idx_size != 0) {
      st.site = &xg_emlrtRSI;
      b_introsort(&st, idx_data, idx_size);
    }
  }
  return idx_size;
}

static void c_insertionsort(const emlrtStack *sp, int32_T x_data[],
                            int32_T xstart, int32_T xend)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T a;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  a = xstart + 1;
  st.site = &bd_emlrtRSI;
  if ((xstart + 1 <= xend) && (xend > 2147483646)) {
    b_st.site = &s_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (k = a; k <= xend; k++) {
    int32_T idx;
    int32_T xc;
    boolean_T exitg1;
    xc = x_data[k - 1];
    idx = k - 1;
    exitg1 = false;
    while ((!exitg1) && (idx >= xstart)) {
      int32_T i;
      i = x_data[idx - 1];
      if (xc < i) {
        x_data[idx] = i;
        idx--;
      } else {
        exitg1 = true;
      }
    }
    x_data[idx] = xc;
  }
}

static real_T c_sumColumnB(const real_T x[19])
{
  real_T y;
  int32_T k;
  y = x[0];
  for (k = 0; k < 18; k++) {
    y += x[k + 1];
  }
  return y;
}

static void c_warning(const emlrtStack *sp)
{
  static const int32_T b_iv[2] = {1, 7};
  static const int32_T b_iv1[2] = {1, 7};
  static const int32_T b_iv2[2] = {1, 26};
  static const char_T msgID[26] = {'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
                                   'l', 'b', 'o', 'x', ':', 's', 'c', 'h', 'u',
                                   'r', '_', 'f', 'a', 'i', 'l', 'e', 'd'};
  static const char_T b_u[7] = {'m', 'e', 's', 's', 'a', 'g', 'e'};
  static const char_T u[7] = {'w', 'a', 'r', 'n', 'i', 'n', 'g'};
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  const mxArray *y;
  st.prev = sp;
  st.tls = sp->tls;
  y = NULL;
  m = emlrtCreateCharArray(2, &b_iv[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 7, m, &u[0]);
  emlrtAssign(&y, m);
  b_y = NULL;
  m = emlrtCreateCharArray(2, &b_iv1[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 7, m, &b_u[0]);
  emlrtAssign(&b_y, m);
  c_y = NULL;
  m = emlrtCreateCharArray(2, &b_iv2[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 26, m, &msgID[0]);
  emlrtAssign(&c_y, m);
  st.site = &ei_emlrtRSI;
  b_feval(&st, y, feval(&st, b_y, c_y, &emlrtMCI), &b_emlrtMCI);
}

static void calcule_bpm_once(void)
{
  mex_InitInfAndNan();
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\33676\\Documents\\tictac\\MATLAB\\dossier_"
                  "convertion\\calcule_bpm.m",
                  0U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "calcule_bpm", 0, -1, 550);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 60, -1, 546);
  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 0U);
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\33676\\Documents\\tictac\\MATLAB\\dossier_"
                  "convertion\\calcule_pas.m",
                  1U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 1U, 0U, "calcule_pas", 0, -1, 616);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 0U, 43, -1, 611);
  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 1U);
}

static void check_forloop_overflow_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2018a(
      sp, &v_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
      "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
}

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = j_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void diff(const emlrtStack *sp, const real_T x_data[],
                 const int32_T x_size[2], real_T y_data[], int32_T y_size[2])
{
  int32_T dimSize;
  int32_T i;
  dimSize = x_size[1];
  if (x_size[1] == 0) {
    y_size[0] = 1;
    y_size[1] = 0;
  } else {
    i = x_size[1] - 1;
    if (muIntScalarMin_sint32(i, 1) < 1) {
      y_size[0] = 1;
      y_size[1] = 0;
    } else {
      real_T work_data;
      if (x_size[1] == 1) {
        emlrtErrorWithMessageIdR2018a(
            sp, &t_emlrtRTEI, "Coder:toolbox:autoDimIncompatibility",
            "Coder:toolbox:autoDimIncompatibility", 0);
      }
      y_size[0] = 1;
      y_size[1] = x_size[1] - 1;
      work_data = x_data[0];
      for (i = 2; i <= dimSize; i++) {
        real_T d;
        real_T tmp1;
        tmp1 = x_data[i - 1];
        d = tmp1;
        tmp1 -= work_data;
        work_data = d;
        y_data[i - 2] = tmp1;
      }
    }
  }
}

static int32_T div_nde_s32_floor(int32_T numerator)
{
  int32_T quotient;
  if ((numerator < 0) && (numerator % 6 != 0)) {
    quotient = -1;
  } else {
    quotient = 0;
  }
  quotient += numerator / 6;
  return quotient;
}

static int32_T do_vectors(const emlrtStack *sp, const int32_T a_data[],
                          int32_T a_size, const int32_T b_data[],
                          int32_T b_size, int32_T c_data[], int32_T ia_data[],
                          int32_T *ia_size, int32_T ib_data[], int32_T *ib_size)
{
  int32_T b_ialast;
  int32_T b_iblast;
  int32_T c_size;
  int32_T iafirst;
  int32_T ialast;
  int32_T ibfirst;
  int32_T iblast;
  int32_T nc;
  int32_T nia;
  int32_T nib;
  c_size = a_size + b_size;
  *ia_size = a_size;
  *ib_size = b_size;
  if (!issorted(a_data, a_size)) {
    emlrtErrorWithMessageIdR2018a(sp, &n_emlrtRTEI,
                                  "Coder:toolbox:eml_setop_unsortedA",
                                  "Coder:toolbox:eml_setop_unsortedA", 0);
  }
  if (!issorted(b_data, b_size)) {
    emlrtErrorWithMessageIdR2018a(sp, &o_emlrtRTEI,
                                  "Coder:toolbox:eml_setop_unsortedB",
                                  "Coder:toolbox:eml_setop_unsortedB", 0);
  }
  nc = -1;
  nia = 0;
  nib = 0;
  iafirst = 1;
  ialast = 0;
  ibfirst = 0;
  iblast = 0;
  while ((ialast + 1 <= a_size) && (iblast + 1 <= b_size)) {
    int32_T ak;
    int32_T bk;
    b_ialast = ialast + 1;
    ak = a_data[ialast];
    while ((b_ialast < a_size) && (a_data[b_ialast] == ak)) {
      b_ialast++;
    }
    ialast = b_ialast - 1;
    b_iblast = iblast + 1;
    bk = b_data[iblast];
    while ((b_iblast < b_size) && (b_data[b_iblast] == bk)) {
      b_iblast++;
    }
    iblast = b_iblast - 1;
    if (ak == bk) {
      nc++;
      c_data[nc] = ak;
      nia++;
      ia_data[nia - 1] = iafirst;
      ialast = b_ialast;
      iafirst = b_ialast + 1;
      iblast = b_iblast;
      ibfirst = b_iblast;
    } else if (ak < bk) {
      nc++;
      nia++;
      c_data[nc] = ak;
      ia_data[nia - 1] = iafirst;
      ialast = b_ialast;
      iafirst = b_ialast + 1;
    } else {
      nc++;
      nib++;
      c_data[nc] = bk;
      ib_data[nib - 1] = ibfirst + 1;
      iblast = b_iblast;
      ibfirst = b_iblast;
    }
  }
  while (ialast + 1 <= a_size) {
    b_ialast = ialast + 1;
    while ((b_ialast < a_size) && (a_data[b_ialast] == a_data[ialast])) {
      b_ialast++;
    }
    nc++;
    nia++;
    c_data[nc] = a_data[ialast];
    ia_data[nia - 1] = iafirst;
    ialast = b_ialast;
    iafirst = b_ialast + 1;
  }
  while (iblast + 1 <= b_size) {
    b_iblast = iblast + 1;
    while ((b_iblast < b_size) && (b_data[b_iblast] == b_data[iblast])) {
      b_iblast++;
    }
    nc++;
    nib++;
    c_data[nc] = b_data[iblast];
    ib_data[nib - 1] = ibfirst + 1;
    iblast = b_iblast;
    ibfirst = b_iblast;
  }
  if (a_size > 0) {
    if (nia > a_size) {
      emlrtErrorWithMessageIdR2018a(sp, &p_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (nia < 1) {
      *ia_size = 0;
    } else {
      *ia_size = nia;
    }
  }
  if (b_size > 0) {
    if (nib > b_size) {
      emlrtErrorWithMessageIdR2018a(sp, &q_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (nib < 1) {
      *ib_size = 0;
    } else {
      *ib_size = nib;
    }
  }
  if (c_size > 0) {
    if (nc + 1 > c_size) {
      emlrtErrorWithMessageIdR2018a(sp, &r_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (nc + 1 < 1) {
      c_size = 0;
    } else {
      c_size = nc + 1;
    }
  }
  return c_size;
}

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[740]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[740];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static void eigSkewHermitianStandard(const emlrtStack *sp, const real_T A[36],
                                     creal_T V[6])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
  emlrtStack k_st;
  emlrtStack st;
  real_T T[36];
  real_T work[6];
  real_T xnorm;
  int32_T exitg1;
  int32_T i;
  int32_T ia;
  int32_T j;
  int32_T k;
  int32_T vectorUB;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &cd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  k_st.prev = &j_st;
  k_st.tls = j_st.tls;
  b_st.site = &dd_emlrtRSI;
  memcpy(&T[0], &A[0], 36U * sizeof(real_T));
  c_st.site = &ed_emlrtRSI;
  if (anyNonFinite(A)) {
    int32_T b_i;
    for (j = 0; j < 36; j++) {
      T[j] = rtNaN;
    }
    b_i = 2;
    for (j = 0; j < 5; j++) {
      if (b_i <= 6) {
        memset(&T[(j * 6 + b_i) + -1], 0,
               (uint32_T)(-b_i + 7) * sizeof(real_T));
      }
      b_i++;
    }
  } else {
    real_T tau[5];
    int32_T b_i;
    c_st.site = &fd_emlrtRSI;
    d_st.site = &id_emlrtRSI;
    for (i = 0; i < 6; i++) {
      work[i] = 0.0;
    }
    for (i = 0; i < 5; i++) {
      __m128d r;
      real_T alpha1_tmp;
      int32_T alpha1_tmp_tmp;
      int32_T in;
      int32_T knt;
      int32_T lastc;
      int32_T lastv;
      int32_T scalarLB;
      in = (i + 1) * 6;
      alpha1_tmp_tmp = (i + 6 * i) + 1;
      alpha1_tmp = T[alpha1_tmp_tmp];
      b_i = i + 3;
      b_i = muIntScalarMin_sint32(b_i, 6) + i * 6;
      e_st.site = &jd_emlrtRSI;
      tau[i] = 0.0;
      f_st.site = &qc_emlrtRSI;
      xnorm = xnrm2(&f_st, 4 - i, T, b_i);
      if (xnorm != 0.0) {
        xnorm = muDoubleScalarHypot(alpha1_tmp, xnorm);
        if (alpha1_tmp >= 0.0) {
          xnorm = -xnorm;
        }
        if (muDoubleScalarAbs(xnorm) < 1.0020841800044864E-292) {
          knt = 0;
          j = (b_i - i) + 3;
          do {
            knt++;
            f_st.site = &rc_emlrtRSI;
            g_st.site = &yc_emlrtRSI;
            h_st.site = &ad_emlrtRSI;
            scalarLB = ((((j - b_i) + 1) / 2) << 1) + b_i;
            vectorUB = scalarLB - 2;
            for (k = b_i; k <= vectorUB; k += 2) {
              r = _mm_loadu_pd(&T[k - 1]);
              _mm_storeu_pd(&T[k - 1],
                            _mm_mul_pd(_mm_set1_pd(9.9792015476736E+291), r));
            }
            for (k = scalarLB; k <= j; k++) {
              T[k - 1] *= 9.9792015476736E+291;
            }
            xnorm *= 9.9792015476736E+291;
            alpha1_tmp *= 9.9792015476736E+291;
          } while ((muDoubleScalarAbs(xnorm) < 1.0020841800044864E-292) &&
                   (knt < 20));
          f_st.site = &sc_emlrtRSI;
          xnorm = xnrm2(&f_st, 4 - i, T, b_i);
          xnorm = muDoubleScalarHypot(alpha1_tmp, xnorm);
          if (alpha1_tmp >= 0.0) {
            xnorm = -xnorm;
          }
          tau[i] = (xnorm - alpha1_tmp) / xnorm;
          f_st.site = &tc_emlrtRSI;
          xscal(&f_st, 4 - i, 1.0 / (alpha1_tmp - xnorm), T, b_i);
          f_st.site = &uc_emlrtRSI;
          for (k = 0; k < knt; k++) {
            xnorm *= 1.0020841800044864E-292;
          }
          alpha1_tmp = xnorm;
        } else {
          tau[i] = (xnorm - alpha1_tmp) / xnorm;
          f_st.site = &vc_emlrtRSI;
          xscal(&f_st, 4 - i, 1.0 / (alpha1_tmp - xnorm), T, b_i);
          alpha1_tmp = xnorm;
        }
      }
      T[alpha1_tmp_tmp] = 1.0;
      scalarLB = in + 1;
      e_st.site = &kd_emlrtRSI;
      if (tau[i] != 0.0) {
        boolean_T exitg2;
        lastv = 4 - i;
        b_i = (alpha1_tmp_tmp - i) + 4;
        while ((lastv + 1 > 0) && (T[b_i] == 0.0)) {
          lastv--;
          b_i--;
        }
        lastc = 6;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          b_i = in + lastc;
          ia = b_i;
          do {
            exitg1 = 0;
            if (ia <= b_i + lastv * 6) {
              if (T[ia - 1] != 0.0) {
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
        lastv = -1;
        lastc = 0;
      }
      if (lastv + 1 > 0) {
        f_st.site = &md_emlrtRSI;
        g_st.site = &od_emlrtRSI;
        if (lastc != 0) {
          h_st.site = &qd_emlrtRSI;
          memset(&work[0], 0, (uint32_T)lastc * sizeof(real_T));
          b_i = alpha1_tmp_tmp;
          j = (in + 6 * lastv) + 1;
          for (vectorUB = scalarLB; vectorUB <= j; vectorUB += 6) {
            knt = vectorUB + lastc;
            h_st.site = &pd_emlrtRSI;
            for (ia = vectorUB; ia < knt; ia++) {
              k = ia - vectorUB;
              work[k] += T[ia - 1] * T[b_i];
            }
            b_i++;
          }
        }
        f_st.site = &nd_emlrtRSI;
        g_st.site = &rd_emlrtRSI;
        h_st.site = &qb_emlrtRSI;
        i_st.site = &rb_emlrtRSI;
        if (!(-tau[i] == 0.0)) {
          b_i = in;
          j_st.site = &sb_emlrtRSI;
          for (j = 0; j <= lastv; j++) {
            xnorm = T[alpha1_tmp_tmp + j];
            if (xnorm != 0.0) {
              xnorm *= -tau[i];
              knt = b_i + 1;
              k = lastc + b_i;
              j_st.site = &tb_emlrtRSI;
              if ((b_i + 1 <= k) && (k > 2147483646)) {
                k_st.site = &s_emlrtRSI;
                check_forloop_overflow_error(&k_st);
              }
              scalarLB = ((((k - b_i) / 2) << 1) + b_i) + 1;
              vectorUB = scalarLB - 2;
              for (ia = knt; ia <= vectorUB; ia += 2) {
                __m128d r1;
                r = _mm_loadu_pd(&work[(ia - b_i) - 1]);
                r1 = _mm_loadu_pd(&T[ia - 1]);
                _mm_storeu_pd(
                    &T[ia - 1],
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(xnorm))));
              }
              for (ia = scalarLB; ia <= k; ia++) {
                T[ia - 1] += work[(ia - b_i) - 1] * xnorm;
              }
            }
            b_i += 6;
          }
        }
      }
      e_st.site = &ld_emlrtRSI;
      xzlarf(&e_st, 5 - i, 5 - i, alpha1_tmp_tmp + 1, tau[i], T, (i + in) + 2,
             work);
      T[alpha1_tmp_tmp] = alpha1_tmp;
    }
    c_st.site = &gd_emlrtRSI;
    b_i = xhseqr(&c_st, T);
    if (b_i != 0) {
      c_st.site = &hd_emlrtRSI;
      c_warning(&c_st);
    }
  }
  i = 1;
  do {
    exitg1 = 0;
    if (i <= 6) {
      boolean_T guard1;
      guard1 = false;
      if (i != 6) {
        xnorm = T[i + 6 * (i - 1)];
        if (xnorm != 0.0) {
          xnorm = muDoubleScalarAbs(xnorm);
          V[i - 1].re = 0.0;
          V[i - 1].im = xnorm;
          V[i].re = 0.0;
          V[i].im = -xnorm;
          i += 2;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        V[i - 1].re = 0.0;
        V[i - 1].im = 0.0;
        i++;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

static void emlrtExitTimeCleanupDtorFcn(const void *r)
{
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

static void emlrt_marshallIn(const emlrtStack *sp,
                             const mxArray *a__output_of_sprintf_,
                             const char_T *identifier, char_T y[23])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(a__output_of_sprintf_), &thisId, y);
  emlrtDestroyArray(&a__output_of_sprintf_);
}

static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

static void emxEnsureCapacity_int32_T(const emlrtStack *sp,
                                      emxArray_int32_T *emxArray,
                                      int32_T oldNumel,
                                      const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)newNumel,
                                           (size_t)(uint32_T)emxArray->size[i],
                                           srcLocation, (emlrtCTX)sp);
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = emlrtMallocMex((uint32_T)i * sizeof(int32_T));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(int32_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (int32_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void emxEnsureCapacity_real_T(const emlrtStack *sp,
                                     emxArray_real_T *emxArray,
                                     int32_T oldNumel,
                                     const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)newNumel,
                                           (size_t)(uint32_T)emxArray->size[i],
                                           srcLocation, (emlrtCTX)sp);
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = emlrtMallocMex((uint32_T)i * sizeof(real_T));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void emxFree_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int32_T *)NULL) {
    if (((*pEmxArray)->data != (int32_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_int32_T *)NULL;
  }
}

static void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

static void emxInit_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray,
                            const emlrtRTEInfo *srcLocation)
{
  emxArray_int32_T *emxArray;
  *pEmxArray =
      (emxArray_int32_T *)emlrtMallocEmxArray(sizeof(emxArray_int32_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_int32_T, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (int32_T *)NULL;
  emxArray->numDimensions = 1;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T));
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  emxArray->size[0] = 0;
}

static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                           const emlrtRTEInfo *srcLocation)
{
  emxArray_real_T *emxArray;
  *pEmxArray = (emxArray_real_T *)emlrtMallocEmxArray(sizeof(emxArray_real_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_real_T, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = 1;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T));
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  emxArray->size[0] = 0;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[740]
{
  real_T(*y)[740];
  y = k_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *m1,
                            const mxArray *m2, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  return emlrtCallMATLABR2012b((emlrtConstCTX)sp, 1, &m, 2, &pArrays[0],
                               "feval", true, location);
}

static void fft(const real_T x[19], creal_T y[19])
{
  emlrtFFTWSetNumThreads(8);
  emlrtFFTW_1D_R2C((real_T *)&x[0], (real_T *)&y[0], 1, 19, 19, 1, -1);
}

static int32_T filter(const emlrtStack *sp, real_T b[7], real_T a[7],
                      const real_T x_data[], int32_T x_size, const real_T zi[6],
                      real_T y_data[])
{
  int32_T j;
  int32_T k;
  int32_T y_size;
  if (muDoubleScalarIsInf(a[0]) || muDoubleScalarIsNaN(a[0])) {
    emlrtErrorWithMessageIdR2018a(
        sp, &j_emlrtRTEI,
        "Coder:MATLAB:filter_firstElementOfDenominatorFilterNotFinite",
        "Coder:MATLAB:filter_firstElementOfDenominatorFilterNotFinite", 0);
  } else if (a[0] == 0.0) {
    emlrtErrorWithMessageIdR2018a(
        sp, &i_emlrtRTEI,
        "Coder:MATLAB:filter_firstElementOfDenominatorFilterZero",
        "Coder:MATLAB:filter_firstElementOfDenominatorFilterZero", 0);
  } else if (a[0] != 1.0) {
    __m128d r;
    __m128d r1;
    r = _mm_loadu_pd(&b[0]);
    r1 = _mm_set1_pd(a[0]);
    _mm_storeu_pd(&b[0], _mm_div_pd(r, r1));
    r = _mm_loadu_pd(&b[2]);
    _mm_storeu_pd(&b[2], _mm_div_pd(r, r1));
    r = _mm_loadu_pd(&b[4]);
    _mm_storeu_pd(&b[4], _mm_div_pd(r, r1));
    b[6] /= a[0];
    r = _mm_loadu_pd(&a[1]);
    _mm_storeu_pd(&a[1], _mm_div_pd(r, r1));
    r = _mm_loadu_pd(&a[3]);
    _mm_storeu_pd(&a[3], _mm_div_pd(r, r1));
    r = _mm_loadu_pd(&a[5]);
    _mm_storeu_pd(&a[5], _mm_div_pd(r, r1));
    a[0] = 1.0;
  }
  y_size = x_size;
  for (k = 0; k < 6; k++) {
    y_data[k] = zi[k];
  }
  memset(&y_data[6], 0, (uint32_T)(x_size - 6) * sizeof(real_T));
  for (k = 0; k < x_size; k++) {
    real_T as;
    int32_T a_tmp;
    int32_T naxpy;
    int32_T y_tmp;
    a_tmp = x_size - k;
    naxpy = muIntScalarMin_sint32(a_tmp, 7);
    for (j = 0; j < naxpy; j++) {
      y_tmp = k + j;
      y_data[y_tmp] += x_data[k] * b[j];
    }
    if (a_tmp - 1 < 6) {
      naxpy = a_tmp - 2;
    } else {
      naxpy = 5;
    }
    as = -y_data[k];
    for (j = 0; j <= naxpy; j++) {
      y_tmp = (k + j) + 1;
      y_data[y_tmp] += as * a[j + 1];
    }
  }
  return y_size;
}

static void filtfilt(const emlrtStack *sp, const real_T ctf[7],
                     const real_T varargin_1[7], const real_T varargin_2[740],
                     real_T y[740])
{
  __m128d r;
  __m128d r1;
  cs_di *cxA;
  cs_din *N;
  cs_dis *S;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_int32_T *y_colidx;
  emxArray_int32_T *y_rowidx;
  emxArray_real_T *y_d;
  real_T b_ytemp_data[776];
  real_T ytemp_data[776];
  real_T vals[16];
  real_T A[7];
  real_T B[7];
  real_T b_A[7];
  real_T b_B[7];
  real_T b_outBuff[6];
  real_T outBuff[6];
  real_T Letr;
  real_T tol;
  real_T val;
  real_T *y_d_data;
  int32_T sortedIndices[16];
  int32_T b_iv[2];
  int32_T c;
  int32_T cptr;
  int32_T currRowIdx;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T ridx;
  int32_T *y_colidx_data;
  int32_T *y_rowidx_data;
  int8_T cidxInt[16];
  int8_T ridxInt[16];
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &we_emlrtRSI;
  b_st.site = &ye_emlrtRSI;
  c_st.site = &af_emlrtRSI;
  d_st.site = &o_emlrtRSI;
  p = true;
  cptr = 0;
  exitg1 = false;
  while ((!exitg1) && (cptr < 740)) {
    if ((!muDoubleScalarIsInf(varargin_2[cptr])) &&
        (!muDoubleScalarIsNaN(varargin_2[cptr]))) {
      cptr++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:filtfilt:expectedFinite", 3, 4, 12, "input signal");
  }
  c_st.site = &bf_emlrtRSI;
  d_st.site = &o_emlrtRSI;
  p = true;
  cptr = 0;
  exitg1 = false;
  while ((!exitg1) && (cptr < 7)) {
    if ((!muDoubleScalarIsInf(ctf[cptr])) &&
        (!muDoubleScalarIsNaN(ctf[cptr]))) {
      cptr++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:filtfilt:expectedFinite", 3, 4, 36,
        "input number 1, filter coefficients,");
  }
  c_st.site = &cf_emlrtRSI;
  d_st.site = &o_emlrtRSI;
  p = true;
  cptr = 0;
  exitg1 = false;
  while ((!exitg1) && (cptr < 7)) {
    if ((!muDoubleScalarIsInf(varargin_1[cptr])) &&
        (!muDoubleScalarIsNaN(varargin_1[cptr]))) {
      cptr++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:filtfilt:expectedFinite", 3, 4, 36,
        "input number 2, filter coefficients,");
  }
  st.site = &xe_emlrtRSI;
  if (varargin_1[0] == 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &h_emlrtRTEI,
                                  "signal:filtfilt:ZeroA0Coeffs",
                                  "signal:filtfilt:ZeroA0Coeffs", 0);
  }
  b_st.site = &df_emlrtRSI;
  for (i = 0; i < 7; i++) {
    B[i] = ctf[i];
  }
  findEffectiveFilterLen(B, (real_T *)&val);
  for (i1 = 0; i1 < 7; i1++) {
    B[i1] = varargin_1[i1];
  }
  findEffectiveFilterLen(B, (real_T *)&tol);
  Letr = muDoubleScalarMax(1.0, 3.0 * (muDoubleScalarMax(val, tol) - 1.0));
  r = _mm_set1_pd(varargin_1[0]);
  _mm_storeu_pd(&B[0], _mm_div_pd(_mm_loadu_pd(&ctf[0]), r));
  _mm_storeu_pd(&A[0], _mm_div_pd(_mm_loadu_pd(&varargin_1[0]), r));
  _mm_storeu_pd(&B[2], _mm_div_pd(_mm_loadu_pd(&ctf[2]), r));
  _mm_storeu_pd(&A[2], _mm_div_pd(_mm_loadu_pd(&varargin_1[2]), r));
  _mm_storeu_pd(&B[4], _mm_div_pd(_mm_loadu_pd(&ctf[4]), r));
  _mm_storeu_pd(&A[4], _mm_div_pd(_mm_loadu_pd(&varargin_1[4]), r));
  B[6] = ctf[6] / varargin_1[0];
  A[6] = varargin_1[6] / varargin_1[0];
  vals[0] = A[1] + 1.0;
  for (c = 0; c < 5; c++) {
    vals[c + 1] = A[c + 2];
    vals[c + 6] = 1.0;
    vals[c + 11] = -1.0;
  }
  __m128d r2;
  __m128i r3;
  __m128i r4;
  r = _mm_loadu_pd(&A[1]);
  r1 = _mm_loadu_pd(&B[1]);
  r2 = _mm_set1_pd(B[0]);
  _mm_storeu_pd(&outBuff[0], _mm_sub_pd(r1, _mm_mul_pd(r2, r)));
  r = _mm_loadu_pd(&A[3]);
  r1 = _mm_loadu_pd(&B[3]);
  _mm_storeu_pd(&outBuff[2], _mm_sub_pd(r1, _mm_mul_pd(r2, r)));
  r = _mm_loadu_pd(&A[5]);
  r1 = _mm_loadu_pd(&B[5]);
  _mm_storeu_pd(&outBuff[4], _mm_sub_pd(r1, _mm_mul_pd(r2, r)));
  c_st.site = &ff_emlrtRSI;
  d_st.site = &gf_emlrtRSI;
  emxInit_real_T(&d_st, &y_d, &y_emlrtRTEI);
  emxInit_int32_T(&d_st, &y_colidx, &y_emlrtRTEI);
  emxInit_int32_T(&d_st, &y_rowidx, &y_emlrtRTEI);
  r3 = _mm_set1_epi32(1);
  r4 = _mm_loadu_si128((const __m128i *)&iv[0]);
  _mm_storeu_si128((__m128i *)&sortedIndices[0],
                   _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32(0), r4), r3));
  _mm_storeu_si128((__m128i *)&sortedIndices[4],
                   _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32(4), r4), r3));
  _mm_storeu_si128((__m128i *)&sortedIndices[8],
                   _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32(8), r4), r3));
  _mm_storeu_si128((__m128i *)&sortedIndices[12],
                   _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32(12), r4), r3));
  introsort(sortedIndices);
  c = y_d->size[0];
  y_d->size[0] = 16;
  emxEnsureCapacity_real_T(&d_st, y_d, c, &x_emlrtRTEI);
  y_d_data = y_d->data;
  for (cptr = 0; cptr < 16; cptr++) {
    c = sortedIndices[cptr];
    cidxInt[cptr] = iv1[c - 1];
    ridxInt[cptr] = iv2[c - 1];
    y_d_data[cptr] = 0.0;
  }
  c = y_colidx->size[0];
  y_colidx->size[0] = 7;
  emxEnsureCapacity_int32_T(&d_st, y_colidx, c, &x_emlrtRTEI);
  y_colidx_data = y_colidx->data;
  for (c = 0; c < 7; c++) {
    y_colidx_data[c] = 0;
  }
  y_colidx_data[0] = 1;
  c = y_rowidx->size[0];
  y_rowidx->size[0] = 16;
  emxEnsureCapacity_int32_T(&d_st, y_rowidx, c, &x_emlrtRTEI);
  y_rowidx_data = y_rowidx->data;
  for (c = 0; c < 16; c++) {
    y_rowidx_data[c] = 0;
  }
  cptr = 0;
  for (c = 0; c < 6; c++) {
    while ((cptr + 1 <= 16) && (cidxInt[cptr] == c + 1)) {
      y_rowidx_data[cptr] = ridxInt[cptr];
      cptr++;
    }
    y_colidx_data[c + 1] = cptr + 1;
  }
  for (cptr = 0; cptr < 16; cptr++) {
    y_d_data[cptr] = vals[sortedIndices[cptr] - 1];
  }
  e_st.site = &hf_emlrtRSI;
  cptr = 1;
  for (c = 0; c < 6; c++) {
    ridx = y_colidx_data[c];
    y_colidx_data[c] = cptr;
    while (ridx < y_colidx_data[c + 1]) {
      val = 0.0;
      currRowIdx = y_rowidx_data[ridx - 1];
      while ((ridx < y_colidx_data[c + 1]) &&
             (y_rowidx_data[ridx - 1] == currRowIdx)) {
        val += y_d_data[ridx - 1];
        ridx++;
      }
      if (val != 0.0) {
        y_d_data[cptr - 1] = val;
        y_rowidx_data[cptr - 1] = currRowIdx;
        cptr++;
      }
    }
  }
  y_colidx_data[6] = cptr;
  c_st.site = &ff_emlrtRSI;
  d_st.site = &jf_emlrtRSI;
  e_st.site = &kf_emlrtRSI;
  cxA = makeCXSparseMatrix(y_colidx_data[6] - 1, 6, 6, &y_colidx_data[0],
                           &y_rowidx_data[0], &y_d_data[0]);
  S = cs_di_sqr(2, cxA, 0);
  N = cs_di_lu(cxA, S, 1);
  cs_di_spfree(cxA);
  if (N == NULL) {
    f_st.site = &mf_emlrtRSI;
    warning(&f_st);
    cs_di_sfree(S);
    cs_di_nfree(N);
    cxA = makeCXSparseMatrix(y_colidx_data[6] - 1, 6, 6, &y_colidx_data[0],
                             &y_rowidx_data[0], &y_d_data[0]);
    S = cs_di_sqr(2, cxA, 1);
    N = cs_di_qr(cxA, S);
    cs_di_spfree(cxA);
    qr_rank_di(N, &tol);
    solve_from_qr_di(N, S, (double *)&outBuff[0], 6, 6);
    cs_di_sfree(S);
    cs_di_nfree(N);
  } else {
    solve_from_lu_di(N, S, (double *)&outBuff[0], 6);
    cs_di_sfree(S);
    cs_di_nfree(N);
  }
  emxFree_int32_T(&e_st, &y_rowidx);
  emxFree_int32_T(&e_st, &y_colidx);
  emxFree_real_T(&e_st, &y_d);
  b_st.site = &ef_emlrtRSI;
  val = 2.0 * varargin_2[0];
  tol = 2.0 * varargin_2[739];
  cptr = ((int32_T)(Letr + 1.0) - (int32_T)(740.0 - Letr)) + 1479;
  ridx = (int32_T)(Letr + 1.0) - 2;
  for (c = 0; c <= ridx; c++) {
    b_ytemp_data[c] = val - varargin_2[((int32_T)(Letr + 1.0) - c) - 1];
  }
  for (c = 0; c < 740; c++) {
    b_ytemp_data[(c + (int32_T)(Letr + 1.0)) - 1] = varargin_2[c];
  }
  ridx = 739 - (int32_T)(740.0 - Letr);
  for (c = 0; c <= ridx; c++) {
    b_ytemp_data[(c + (int32_T)(Letr + 1.0)) + 739] = tol - varargin_2[738 - c];
  }
  c = (int32_T)(2.0 * Letr + 740.0);
  if (c != cptr) {
    emlrtSubAssignSizeCheck1dR2017a(c, cptr, &b_emlrtECI, &b_st);
  }
  r = _mm_loadu_pd(&outBuff[0]);
  r1 = _mm_set1_pd(b_ytemp_data[0]);
  _mm_storeu_pd(&b_outBuff[0], _mm_mul_pd(r, r1));
  r = _mm_loadu_pd(&outBuff[2]);
  _mm_storeu_pd(&b_outBuff[2], _mm_mul_pd(r, r1));
  r = _mm_loadu_pd(&outBuff[4]);
  _mm_storeu_pd(&b_outBuff[4], _mm_mul_pd(r, r1));
  for (i2 = 0; i2 < 7; i2++) {
    b_B[i2] = B[i2];
  }
  for (i3 = 0; i3 < 7; i3++) {
    b_A[i3] = A[i3];
  }
  c_st.site = &sf_emlrtRSI;
  currRowIdx =
      filter(&c_st, b_B, b_A, b_ytemp_data, cptr, b_outBuff, ytemp_data);
  if (currRowIdx < 1) {
    emlrtDynamicBoundsCheckR2012b(currRowIdx, 1, currRowIdx, &emlrtBCI, &b_st);
  }
  b_iv[0] = 1;
  b_iv[1] = currRowIdx;
  c_st.site = &rf_emlrtRSI;
  indexShapeCheck(&c_st, currRowIdx, b_iv);
  cptr = currRowIdx - 1;
  for (c = 0; c <= cptr; c++) {
    b_ytemp_data[c] = ytemp_data[(currRowIdx - c) - 1];
  }
  if (currRowIdx - 1 >= 0) {
    memcpy(&ytemp_data[0], &b_ytemp_data[0],
           (uint32_T)currRowIdx * sizeof(real_T));
  }
  r = _mm_loadu_pd(&outBuff[0]);
  r1 = _mm_set1_pd(ytemp_data[0]);
  _mm_storeu_pd(&outBuff[0], _mm_mul_pd(r, r1));
  r = _mm_loadu_pd(&outBuff[2]);
  _mm_storeu_pd(&outBuff[2], _mm_mul_pd(r, r1));
  r = _mm_loadu_pd(&outBuff[4]);
  _mm_storeu_pd(&outBuff[4], _mm_mul_pd(r, r1));
  ridx = currRowIdx - 1;
  if (ridx >= 0) {
    memcpy(&b_ytemp_data[0], &ytemp_data[0],
           (uint32_T)(ridx + 1) * sizeof(real_T));
  }
  c_st.site = &qf_emlrtRSI;
  currRowIdx =
      filter(&c_st, B, A, b_ytemp_data, currRowIdx, outBuff, ytemp_data);
  c = (int32_T)((real_T)currRowIdx - Letr);
  if ((c < 1) || (c > currRowIdx)) {
    emlrtDynamicBoundsCheckR2012b(c, 1, currRowIdx, &b_emlrtBCI, &b_st);
  }
  cptr = (c - (int32_T)(Letr + 1.0)) + 1;
  if (cptr != 740) {
    emlrtSubAssignSizeCheck1dR2017a(740, cptr, &c_emlrtECI, &b_st);
  }
  for (cptr = 0; cptr < 740; cptr++) {
    y[cptr] = ytemp_data[(c - cptr) - 1];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static int32_T findEffectiveFilterLen(real_T coef[7], real_T effLen_data[])
{
  real_T varargin_1[7];
  real_T maxCoef;
  int32_T effLen_size;
  int32_T idx;
  int32_T ii;
  int32_T k;
  int8_T ii_data;
  boolean_T x[7];
  boolean_T exitg1;
  for (k = 0; k < 7; k++) {
    varargin_1[k] = muDoubleScalarAbs(coef[k]);
  }
  if (!muDoubleScalarIsNaN(varargin_1[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!muDoubleScalarIsNaN(varargin_1[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    maxCoef = varargin_1[0];
  } else {
    maxCoef = varargin_1[idx - 1];
    ii = idx + 1;
    for (k = ii; k < 8; k++) {
      real_T d;
      d = varargin_1[k - 1];
      if (maxCoef < d) {
        maxCoef = d;
      }
    }
  }
  if (maxCoef != 0.0) {
    __m128d r;
    __m128d r1;
    r = _mm_loadu_pd(&coef[0]);
    r1 = _mm_set1_pd(maxCoef);
    _mm_storeu_pd(&coef[0], _mm_div_pd(r, r1));
    r = _mm_loadu_pd(&coef[2]);
    _mm_storeu_pd(&coef[2], _mm_div_pd(r, r1));
    r = _mm_loadu_pd(&coef[4]);
    _mm_storeu_pd(&coef[4], _mm_div_pd(r, r1));
    coef[6] /= maxCoef;
  }
  for (ii = 0; ii < 7; ii++) {
    x[ii] = (coef[ii] != 0.0);
  }
  idx = 0;
  effLen_size = 1;
  ii = 7;
  exitg1 = false;
  while ((!exitg1) && (ii > 0)) {
    if (x[ii - 1]) {
      idx = 1;
      ii_data = (int8_T)ii;
      exitg1 = true;
    } else {
      ii--;
    }
  }
  if (idx == 0) {
    effLen_size = 0;
  }
  if (effLen_size - 1 >= 0) {
    effLen_data[0] = ii_data;
  }
  if (effLen_size == 0) {
    effLen_size = 1;
    effLen_data[0] = 0.0;
  }
  return effLen_size;
}

static int32_T findpeaks(const emlrtStack *sp, const real_T Yin[740],
                         const real_T varargin_1[740], real_T varargin_3,
                         real_T Ypk_data[], real_T Xpk_data[],
                         int32_T Xpk_size[2])
{
  static const int32_T b_iv[2] = {1, 7};
  static const char_T rfmt[7] = {'%', '2', '3', '.', '1', '5', 'e'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  const mxArray *m;
  const mxArray *y;
  real_T ykfirst;
  int32_T c_data[1480];
  int32_T idx_data[1480];
  int32_T fPk_data[740];
  int32_T iFinite_data[740];
  int32_T iInfinite_data[740];
  int32_T iPk_data[740];
  int32_T b_iv1[2];
  int32_T Ypk_size;
  int32_T k;
  int32_T kfirst;
  int32_T nInf;
  int32_T nInflect;
  int32_T nPk;
  char_T dir;
  boolean_T exitg1;
  boolean_T isinfykfirst;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ag_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  b_st.site = &hg_emlrtRSI;
  c_st.site = &o_emlrtRSI;
  isinfykfirst = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 740)) {
    if ((!muDoubleScalarIsInf(varargin_1[k])) &&
        (!muDoubleScalarIsNaN(varargin_1[k]))) {
      k++;
    } else {
      isinfykfirst = false;
      exitg1 = true;
    }
  }
  if (!isinfykfirst) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:findpeaks:expectedFinite", 3, 4, 1, "X");
  }
  c_st.site = &o_emlrtRSI;
  isinfykfirst = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 739)) {
    if (!(varargin_1[k] < varargin_1[k + 1])) {
      isinfykfirst = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!isinfykfirst) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &m_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedIncreasing",
        "MATLAB:findpeaks:expectedIncreasing", 3, 4, 1, "X");
  }
  ykfirst = varargin_1[739] - varargin_1[0];
  b_st.site = &ig_emlrtRSI;
  c_st.site = &o_emlrtRSI;
  if (!(ykfirst > 0.4)) {
    char_T numstr[23];
    d_st.site = &jg_emlrtRSI;
    e_st.site = &kg_emlrtRSI;
    f_st.site = &lg_emlrtRSI;
    y = NULL;
    m = emlrtCreateCharArray(2, &b_iv[0]);
    emlrtInitCharArrayR2013a(&f_st, 7, m, &rfmt[0]);
    emlrtAssign(&y, m);
    g_st.site = &fi_emlrtRSI;
    emlrt_marshallIn(
        &g_st, b_sprintf(&g_st, y, emlrt_marshallOut(ykfirst), &c_emlrtMCI),
        "<output of sprintf>", numstr);
    emlrtErrorWithMessageIdR2018a(
        &c_st, &l_emlrtRTEI, "MATLAB:validateattributes:expectedScalar",
        "MATLAB:findpeaks:notLess", 9, 4, 15, "MinPeakDistance", 4, 1, "<", 4,
        23, &numstr[0]);
  }
  st.site = &bg_emlrtRSI;
  nPk = 0;
  nInf = 0;
  nInflect = 0;
  dir = 'n';
  kfirst = 0;
  ykfirst = rtInf;
  isinfykfirst = true;
  for (k = 0; k < 740; k++) {
    real_T yk;
    boolean_T isinfyk;
    yk = Yin[k];
    if (muDoubleScalarIsNaN(yk)) {
      yk = rtInf;
      isinfyk = true;
    } else if (muDoubleScalarIsInf(yk) && (yk > 0.0)) {
      isinfyk = true;
      nInf++;
      if (nInf > 740) {
        emlrtDynamicBoundsCheckR2012b(741, 1, 740, &h_emlrtBCI, &st);
      }
      iInfinite_data[nInf - 1] = k + 1;
    } else {
      isinfyk = false;
    }
    if (yk != ykfirst) {
      char_T previousdir;
      previousdir = dir;
      if (isinfyk || isinfykfirst) {
        dir = 'n';
        if (kfirst >= 1) {
          nInflect++;
          if (nInflect > 740) {
            emlrtDynamicBoundsCheckR2012b(741, 1, 740, &m_emlrtBCI, &st);
          }
          fPk_data[nInflect - 1] = kfirst;
        }
      } else if (yk < ykfirst) {
        dir = 'd';
        if (previousdir != 'd') {
          nInflect++;
          if (nInflect > 740) {
            emlrtDynamicBoundsCheckR2012b(741, 1, 740, &l_emlrtBCI, &st);
          }
          fPk_data[nInflect - 1] = kfirst;
          if (previousdir == 'i') {
            nPk++;
            if (nPk > 740) {
              emlrtDynamicBoundsCheckR2012b(741, 1, 740, &i_emlrtBCI, &st);
            }
            iFinite_data[nPk - 1] = kfirst;
          }
        }
      } else {
        dir = 'i';
        if (previousdir != 'i') {
          nInflect++;
          if (nInflect > 740) {
            emlrtDynamicBoundsCheckR2012b(741, 1, 740, &k_emlrtBCI, &st);
          }
          fPk_data[nInflect - 1] = kfirst;
        }
      }
      ykfirst = yk;
      kfirst = k + 1;
      isinfykfirst = isinfyk;
    }
  }
  if ((!isinfykfirst) && ((nInflect == 0) || (fPk_data[nInflect - 1] < 740)) &&
      (nInflect + 1 > 740)) {
    emlrtDynamicBoundsCheckR2012b(741, 1, 740, &j_emlrtBCI, &st);
  }
  st.site = &cg_emlrtRSI;
  Ypk_size = 0;
  b_st.site = &mg_emlrtRSI;
  for (k = 0; k < nPk; k++) {
    if (k + 1 > nPk) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, nPk, &o_emlrtBCI, &st);
    }
    kfirst = iFinite_data[k];
    if (kfirst < 1) {
      emlrtDynamicBoundsCheckR2012b(0, 1, 740, &g_emlrtBCI, &st);
    }
    ykfirst = Yin[kfirst - 1];
    if (ykfirst > varargin_3) {
      if (kfirst - 1 < 1) {
        emlrtDynamicBoundsCheckR2012b(0, 1, 740, &f_emlrtBCI, &st);
      }
      if (kfirst + 1 > 740) {
        emlrtDynamicBoundsCheckR2012b(741, 1, 740, &e_emlrtBCI, &st);
      }
      if (ykfirst - muDoubleScalarMax(Yin[kfirst - 2], Yin[kfirst]) >= 0.0) {
        Ypk_size++;
        if ((Ypk_size < 1) || (Ypk_size > nPk)) {
          emlrtDynamicBoundsCheckR2012b(Ypk_size, 1, nPk, &p_emlrtBCI, &st);
        }
        iPk_data[Ypk_size - 1] = kfirst;
      }
    }
  }
  if (Ypk_size < 1) {
    Ypk_size = 0;
  } else {
    if (nPk < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, nPk, &d_emlrtBCI, &st);
    }
    if (Ypk_size > nPk) {
      emlrtDynamicBoundsCheckR2012b(Ypk_size, 1, nPk, &c_emlrtBCI, &st);
    }
  }
  st.site = &dg_emlrtRSI;
  b_st.site = &ng_emlrtRSI;
  c_st.site = &og_emlrtRSI;
  d_st.site = &pg_emlrtRSI;
  nPk = do_vectors(&d_st, iPk_data, Ypk_size, iInfinite_data, nInf, c_data,
                   fPk_data, &kfirst, iFinite_data, &nInflect);
  st.site = &eg_emlrtRSI;
  nInflect = c_findPeaksSeparatedByMoreThanM(&st, Yin, varargin_1, c_data, nPk,
                                             idx_data);
  if (nInflect > 740) {
    kfirst = 740;
    st.site = &fg_emlrtRSI;
    b_indexShapeCheck();
    nInflect = 740;
  } else {
    kfirst = nInflect;
  }
  if (kfirst < 1) {
    Ypk_size = 0;
  } else {
    if (nInflect < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, nInflect, &n_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    Ypk_size = nInflect;
  }
  b_iv1[0] = 1;
  b_iv1[1] = Ypk_size;
  st.site = &gg_emlrtRSI;
  indexShapeCheck(&st, nInflect, b_iv1);
  for (kfirst = 0; kfirst < Ypk_size; kfirst++) {
    nInflect = idx_data[kfirst];
    if ((nInflect < 1) || (nInflect > nPk)) {
      emlrtDynamicBoundsCheckR2012b(nInflect, 1, nPk, &q_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    fPk_data[kfirst] = c_data[nInflect - 1];
  }
  Xpk_size[0] = 1;
  Xpk_size[1] = Ypk_size;
  for (kfirst = 0; kfirst < Ypk_size; kfirst++) {
    nInflect = fPk_data[kfirst];
    Ypk_data[kfirst] = Yin[nInflect - 1];
    Xpk_data[kfirst] = varargin_1[nInflect - 1];
  }
  return Ypk_size;
}

static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[19]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[19];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = h_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[19]
{
  real_T(*y)[19];
  y = l_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void heapify(int32_T x_data[], int32_T idx, int32_T xstart, int32_T xend)
{
  int32_T cmpIdx;
  int32_T extremum;
  int32_T extremumIdx;
  int32_T leftIdx;
  boolean_T changed;
  boolean_T exitg1;
  changed = true;
  extremumIdx = (idx + xstart) - 2;
  leftIdx = ((idx << 1) + xstart) - 1;
  exitg1 = false;
  while ((!exitg1) && (leftIdx < xend)) {
    int32_T xcmp;
    changed = false;
    extremum = x_data[extremumIdx];
    cmpIdx = leftIdx - 1;
    xcmp = x_data[leftIdx - 1];
    if (xcmp < x_data[leftIdx]) {
      cmpIdx = leftIdx;
      xcmp = x_data[leftIdx];
    }
    if (x_data[extremumIdx] < xcmp) {
      x_data[extremumIdx] = xcmp;
      x_data[cmpIdx] = extremum;
      extremumIdx = cmpIdx;
      leftIdx = ((((cmpIdx - xstart) + 2) << 1) + xstart) - 1;
      changed = true;
    } else {
      exitg1 = true;
    }
  }
  if (changed && (leftIdx <= xend)) {
    extremum = x_data[extremumIdx];
    cmpIdx = x_data[leftIdx - 1];
    if (x_data[extremumIdx] < cmpIdx) {
      x_data[extremumIdx] = cmpIdx;
      x_data[leftIdx - 1] = extremum;
    }
  }
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[23])
{
  static const int32_T dims[2] = {1, 23};
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "char", false, 2U,
                          (const void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtConstCTX)sp, src, &ret[0], 23);
  emlrtDestroyArray(&src);
}

static void indexShapeCheck(const emlrtStack *sp, int32_T matrixSize,
                            const int32_T indexSize[2])
{
  emlrtStack st;
  boolean_T c;
  st.prev = sp;
  st.tls = sp->tls;
  if ((matrixSize == 1) && (indexSize[1] != 1)) {
    c = true;
  } else {
    c = false;
  }
  st.site = &yf_emlrtRSI;
  if (c) {
    emlrtErrorWithMessageIdR2018a(&st, &k_emlrtRTEI,
                                  "Coder:FE:PotentialVectorVector",
                                  "Coder:FE:PotentialVectorVector", 0);
  }
}

static void insertionsort(int32_T x[16])
{
  int32_T k;
  for (k = 0; k < 15; k++) {
    int32_T idx;
    int32_T xc;
    boolean_T exitg1;
    xc = x[k + 1];
    idx = k;
    exitg1 = false;
    while ((!exitg1) && (idx + 1 >= 1)) {
      int32_T aj;
      int32_T i;
      boolean_T varargout_1;
      aj = iv1[x[idx] - 1];
      i = iv1[xc - 1];
      if (i < aj) {
        varargout_1 = true;
      } else if (i == aj) {
        varargout_1 = (iv2[xc - 1] < iv2[x[idx] - 1]);
      } else {
        varargout_1 = false;
      }
      if (varargout_1) {
        x[idx + 1] = x[idx];
        idx--;
      } else {
        exitg1 = true;
      }
    }
    x[idx + 1] = xc;
  }
}

static void introsort(int32_T x[16])
{
  insertionsort(x);
}

static boolean_T issorted(const int32_T x_data[], int32_T x_size)
{
  int32_T dim;
  boolean_T y;
  y = true;
  dim = 2;
  if (x_size != 1) {
    dim = 1;
  }
  if (x_size != 0) {
    int32_T i;
    if (dim <= 1) {
      i = x_size;
    } else {
      i = 1;
    }
    if (i != 1) {
      int32_T k;
      boolean_T exitg1;
      if (dim == 2) {
        i = -1;
      } else {
        i = 0;
      }
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= i)) {
        int32_T i1;
        boolean_T exitg2;
        if (dim == 1) {
          i1 = x_size - 1;
        } else {
          i1 = x_size;
        }
        k = 0;
        exitg2 = false;
        while ((!exitg2) && (k <= i1 - 1)) {
          int16_T subs[2];
          subs[0] = (int16_T)(k + 1);
          subs[1] = 1;
          subs[dim - 1]++;
          y = (x_data[k] <= x_data[subs[0] - 1]);
          if (!y) {
            exitg2 = true;
          } else {
            k++;
          }
        }
        if (!y) {
          exitg1 = true;
        } else {
          k = 1;
        }
      }
    }
  }
  return y;
}

static real_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[740]
{
  static const int32_T dims = 740;
  real_T(*ret)[740];
  int32_T i;
  boolean_T b = false;
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret = (real_T(*)[740])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[19]
{
  static const int32_T dims = 19;
  real_T(*ret)[19];
  int32_T i;
  boolean_T b = false;
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret = (real_T(*)[19])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T mean(const emlrtStack *sp, const real_T x_data[],
                   const int32_T x_size[2])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T y;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &mh_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &nh_emlrtRSI;
  if (x_size[1] == 0) {
    y = 0.0;
  } else {
    c_st.site = &oh_emlrtRSI;
    d_st.site = &ph_emlrtRSI;
    e_st.site = &qh_emlrtRSI;
    y = b_sumColumnB(&e_st, x_data, x_size[1]);
  }
  y /= (real_T)x_size[1];
  return y;
}

static void mrdiv(const emlrtStack *sp, real_T A[6], const real_T B[36])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T b_A[36];
  real_T temp;
  int32_T ipiv[6];
  int32_T i;
  int32_T info;
  int32_T j;
  int32_T jAcol;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ac_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &gb_emlrtRSI;
  c_st.site = &bc_emlrtRSI;
  memcpy(&b_A[0], &B[0], 36U * sizeof(real_T));
  d_st.site = &cc_emlrtRSI;
  info = xgetrf(&d_st, b_A, ipiv);
  for (j = 0; j < 6; j++) {
    jAcol = 6 * j;
    for (k = 0; k < j; k++) {
      temp = b_A[k + jAcol];
      if (temp != 0.0) {
        A[j] -= temp * A[k];
      }
    }
    A[j] *= 1.0 / b_A[j + jAcol];
  }
  for (j = 5; j >= 0; j--) {
    jAcol = 6 * j - 1;
    i = j + 2;
    for (k = i; k < 7; k++) {
      temp = b_A[k + jAcol];
      if (temp != 0.0) {
        A[j] -= temp * A[k - 1];
      }
    }
  }
  for (j = 4; j >= 0; j--) {
    i = ipiv[j];
    if (i != j + 1) {
      temp = A[j];
      A[j] = A[i - 1];
      A[i - 1] = temp;
    }
  }
  if (info > 0) {
    c_st.site = &ib_emlrtRSI;
    d_st.site = &y_emlrtRSI;
    warning(&d_st);
  }
}

static real_T sumColumnB(const real_T x[740])
{
  real_T y;
  int32_T k;
  y = x[0];
  for (k = 0; k < 739; k++) {
    y += x[k + 1];
  }
  return y;
}

static void warning(const emlrtStack *sp)
{
  static const int32_T b_iv[2] = {1, 7};
  static const int32_T b_iv1[2] = {1, 7};
  static const int32_T b_iv2[2] = {1, 21};
  static const char_T msgID[21] = {'M', 'A', 'T', 'L', 'A', 'B', ':',
                                   's', 'i', 'n', 'g', 'u', 'l', 'a',
                                   'r', 'M', 'a', 't', 'r', 'i', 'x'};
  static const char_T b_u[7] = {'m', 'e', 's', 's', 'a', 'g', 'e'};
  static const char_T u[7] = {'w', 'a', 'r', 'n', 'i', 'n', 'g'};
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  const mxArray *y;
  st.prev = sp;
  st.tls = sp->tls;
  y = NULL;
  m = emlrtCreateCharArray(2, &b_iv[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 7, m, &u[0]);
  emlrtAssign(&y, m);
  b_y = NULL;
  m = emlrtCreateCharArray(2, &b_iv1[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 7, m, &b_u[0]);
  emlrtAssign(&b_y, m);
  c_y = NULL;
  m = emlrtCreateCharArray(2, &b_iv2[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 21, m, &msgID[0]);
  emlrtAssign(&c_y, m);
  st.site = &ei_emlrtRSI;
  b_feval(&st, y, feval(&st, b_y, c_y, &emlrtMCI), &b_emlrtMCI);
}

static real_T xdlanv2(real_T *a, real_T *b, real_T *c, real_T *d, real_T *rt1i,
                      real_T *rt2r, real_T *rt2i, real_T *cs, real_T *sn)
{
  real_T rt1r;
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
      real_T bcmax;
      real_T bcmis;
      real_T p;
      real_T scale;
      real_T z;
      int32_T count;
      int32_T i;
      p = 0.5 * rt1r;
      bcmis = muDoubleScalarAbs(*b);
      scale = muDoubleScalarAbs(*c);
      bcmax = muDoubleScalarMax(bcmis, scale);
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
      bcmis = muDoubleScalarMin(bcmis, scale) * (real_T)count * (real_T)i;
      scale = muDoubleScalarMax(muDoubleScalarAbs(p), bcmax);
      z = p / scale * p + bcmax / scale * bcmis;
      if (z >= 8.8817841970012523E-16) {
        real_T tau;
        *a = muDoubleScalarSqrt(scale) * muDoubleScalarSqrt(z);
        if (!(p < 0.0)) {
          rt1r = *a;
        } else {
          rt1r = -*a;
        }
        z = p + rt1r;
        *a = *d + z;
        *d -= bcmax / z * bcmis;
        tau = muDoubleScalarHypot(*c, z);
        *cs = z / tau;
        *sn = *c / tau;
        *b -= *c;
        *c = 0.0;
      } else {
        real_T tau;
        bcmis = *b + *c;
        scale = muDoubleScalarMax(muDoubleScalarAbs(rt1r),
                                  muDoubleScalarAbs(bcmis));
        count = 0;
        while ((scale >= 7.4428285367870146E+137) && (count <= 20)) {
          bcmis *= 1.3435752215134178E-138;
          rt1r *= 1.3435752215134178E-138;
          scale = muDoubleScalarMax(muDoubleScalarAbs(rt1r),
                                    muDoubleScalarAbs(bcmis));
          count++;
        }
        while ((scale <= 1.3435752215134178E-138) && (count <= 20)) {
          bcmis *= 7.4428285367870146E+137;
          rt1r *= 7.4428285367870146E+137;
          scale = muDoubleScalarMax(muDoubleScalarAbs(rt1r),
                                    muDoubleScalarAbs(bcmis));
          count++;
        }
        tau = muDoubleScalarHypot(bcmis, rt1r);
        *cs = muDoubleScalarSqrt(0.5 * (muDoubleScalarAbs(bcmis) / tau + 1.0));
        if (!(bcmis < 0.0)) {
          count = 1;
        } else {
          count = -1;
        }
        *sn = -(0.5 * rt1r / (tau * *cs)) * (real_T)count;
        bcmax = *a * *cs + *b * *sn;
        scale = -*a * *sn + *b * *cs;
        z = *c * *cs + *d * *sn;
        bcmis = -*c * *sn + *d * *cs;
        *b = scale * *cs + bcmis * *sn;
        *c = -bcmax * *sn + z * *cs;
        rt1r = 0.5 * ((bcmax * *cs + z * *sn) + (-scale * *sn + bcmis * *cs));
        *a = rt1r;
        *d = rt1r;
        if (*c != 0.0) {
          if (*b != 0.0) {
            if ((*b < 0.0) == (*c < 0.0)) {
              bcmis = muDoubleScalarSqrt(muDoubleScalarAbs(*b));
              scale = muDoubleScalarSqrt(muDoubleScalarAbs(*c));
              *a = bcmis * scale;
              if (!(*c < 0.0)) {
                p = *a;
              } else {
                p = -*a;
              }
              tau = 1.0 / muDoubleScalarSqrt(muDoubleScalarAbs(*b + *c));
              *a = rt1r + p;
              *d = rt1r - p;
              *b -= *c;
              *c = 0.0;
              bcmax = bcmis * tau;
              bcmis = scale * tau;
              rt1r = *cs * bcmax - *sn * bcmis;
              *sn = *cs * bcmis + *sn * bcmax;
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
    *rt1i = muDoubleScalarSqrt(muDoubleScalarAbs(*b)) *
            muDoubleScalarSqrt(muDoubleScalarAbs(*c));
    *rt2i = -*rt1i;
  }
  return rt1r;
}

static int32_T xgetrf(const emlrtStack *sp, real_T A[36], int32_T ipiv[6])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  int32_T a;
  int32_T b_j;
  int32_T info;
  int32_T j;
  int32_T jp1j;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &mb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  _mm_storeu_si128(
      (__m128i *)&ipiv[0],
      _mm_add_epi32(_mm_set1_epi32(1),
                    _mm_add_epi32(_mm_set1_epi32(0),
                                  _mm_loadu_si128((const __m128i *)&iv[0]))));
  ipiv[4] = 5;
  ipiv[5] = 6;
  info = 0;
  for (j = 0; j < 5; j++) {
    real_T smax;
    int32_T b_tmp;
    int32_T jA;
    int32_T mmj_tmp;
    mmj_tmp = 4 - j;
    b_tmp = j * 7;
    jp1j = b_tmp + 2;
    jA = 7 - j;
    a = 0;
    smax = muDoubleScalarAbs(A[b_tmp]);
    for (k = 2; k < jA; k++) {
      real_T s;
      s = muDoubleScalarAbs(A[(b_tmp + k) - 1]);
      if (s > smax) {
        a = k - 1;
        smax = s;
      }
    }
    if (A[b_tmp + a] != 0.0) {
      if (a != 0) {
        a += j;
        ipiv[j] = a + 1;
        for (k = 0; k < 6; k++) {
          jA = j + k * 6;
          smax = A[jA];
          b_j = a + k * 6;
          A[jA] = A[b_j];
          A[b_j] = smax;
        }
      }
      b_j = (b_tmp - j) + 6;
      b_st.site = &nb_emlrtRSI;
      for (a = jp1j; a <= b_j; a++) {
        A[a - 1] /= A[b_tmp];
      }
    } else {
      info = j + 1;
    }
    b_st.site = &ob_emlrtRSI;
    c_st.site = &pb_emlrtRSI;
    d_st.site = &qb_emlrtRSI;
    e_st.site = &rb_emlrtRSI;
    jA = b_tmp + 8;
    f_st.site = &sb_emlrtRSI;
    for (b_j = 0; b_j <= mmj_tmp; b_j++) {
      smax = A[(b_tmp + b_j * 6) + 6];
      if (smax != 0.0) {
        a = (jA - j) + 4;
        f_st.site = &tb_emlrtRSI;
        if ((jA <= a) && (a > 2147483646)) {
          g_st.site = &s_emlrtRSI;
          check_forloop_overflow_error(&g_st);
        }
        for (jp1j = jA; jp1j <= a; jp1j++) {
          A[jp1j - 1] += A[((b_tmp + jp1j) - jA) + 1] * -smax;
        }
      }
      jA += 6;
    }
  }
  if ((info == 0) && (!(A[35] != 0.0))) {
    info = 6;
  }
  return info;
}

static int32_T xhseqr(const emlrtStack *sp, real_T h[36])
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

static real_T xnrm2(const emlrtStack *sp, int32_T n, const real_T x[36],
                    int32_T ix0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T y;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &wc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = muDoubleScalarAbs(x[ix0 - 1]);
    } else {
      real_T scale;
      int32_T kend;
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      b_st.site = &xc_emlrtRSI;
      if ((ix0 <= kend) && (kend > 2147483646)) {
        c_st.site = &s_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (k = ix0; k <= kend; k++) {
        real_T absxk;
        absxk = muDoubleScalarAbs(x[k - 1]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }
      y = scale * muDoubleScalarSqrt(y);
    }
  }
  return y;
}

static void xrot(const emlrtStack *sp, int32_T n, real_T x[36], int32_T ix0,
                 int32_T iy0, real_T c, real_T s)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T i;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &qe_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &re_emlrtRSI;
  if (n > 2147483646) {
    c_st.site = &s_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  i = (uint8_T)n;
  for (k = 0; k < i; k++) {
    real_T b_temp_tmp;
    real_T temp_tmp;
    int32_T b_temp_tmp_tmp;
    int32_T temp_tmp_tmp;
    temp_tmp_tmp = (iy0 + k * 6) - 1;
    temp_tmp = x[temp_tmp_tmp];
    b_temp_tmp_tmp = (ix0 + k * 6) - 1;
    b_temp_tmp = x[b_temp_tmp_tmp];
    x[temp_tmp_tmp] = c * temp_tmp - s * b_temp_tmp;
    x[b_temp_tmp_tmp] = c * b_temp_tmp + s * temp_tmp;
  }
}

static void xscal(const emlrtStack *sp, int32_T n, real_T a, real_T x[36],
                  int32_T ix0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T b;
  int32_T k;
  int32_T scalarLB;
  int32_T vectorUB;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &yc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b = (ix0 + n) - 1;
  b_st.site = &ad_emlrtRSI;
  if ((ix0 <= b) && (b > 2147483646)) {
    c_st.site = &s_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  scalarLB = ((b - ix0) + 1) / 2 * 2 + ix0;
  vectorUB = scalarLB - 2;
  for (k = ix0; k <= vectorUB; k += 2) {
    __m128d r;
    r = _mm_loadu_pd(&x[k - 1]);
    r = _mm_mul_pd(_mm_set1_pd(a), r);
    _mm_storeu_pd(&x[k - 1], r);
  }
  for (k = scalarLB; k <= b; k++) {
    x[k - 1] *= a;
  }
}

static void xzlarf(const emlrtStack *sp, int32_T m, int32_T n, int32_T iv0,
                   real_T tau, real_T C[36], int32_T ic0, real_T work[6])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  int32_T colbottom;
  int32_T i;
  int32_T iac;
  int32_T lastc;
  int32_T lastv;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  if (tau != 0.0) {
    boolean_T exitg2;
    lastv = m - 1;
    i = iv0 + m;
    while ((lastv + 1 > 0) && (C[i - 2] == 0.0)) {
      lastv--;
      i--;
    }
    st.site = &sd_emlrtRSI;
    lastc = n;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      int32_T exitg1;
      i = ic0 + (lastc - 1) * 6;
      colbottom = i + lastv;
      b_st.site = &vd_emlrtRSI;
      if ((i <= colbottom) && (colbottom > 2147483646)) {
        c_st.site = &s_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      do {
        exitg1 = 0;
        if (i <= colbottom) {
          if (C[i - 1] != 0.0) {
            exitg1 = 1;
          } else {
            i++;
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
    lastv = -1;
    lastc = 0;
  }
  if (lastv + 1 > 0) {
    real_T c;
    int32_T b_i;
    st.site = &td_emlrtRSI;
    b_st.site = &od_emlrtRSI;
    if (lastc != 0) {
      c_st.site = &qd_emlrtRSI;
      if (lastc > 2147483646) {
        d_st.site = &s_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      b_i = (uint8_T)lastc;
      memset(&work[0], 0, (uint32_T)b_i * sizeof(real_T));
      b_i = ic0 + 6 * (lastc - 1);
      for (iac = ic0; iac <= b_i; iac += 6) {
        c = 0.0;
        colbottom = iac + lastv;
        c_st.site = &wd_emlrtRSI;
        if ((iac <= colbottom) && (colbottom > 2147483646)) {
          d_st.site = &s_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }
        for (i = iac; i <= colbottom; i++) {
          c += C[i - 1] * C[((iv0 + i) - iac) - 1];
        }
        i = div_nde_s32_floor(iac - ic0);
        work[i] += c;
      }
    }
    st.site = &ud_emlrtRSI;
    b_st.site = &rd_emlrtRSI;
    c_st.site = &qb_emlrtRSI;
    d_st.site = &rb_emlrtRSI;
    if (!(-tau == 0.0)) {
      i = ic0;
      e_st.site = &sb_emlrtRSI;
      b_i = (uint8_T)lastc;
      for (lastc = 0; lastc < b_i; lastc++) {
        c = work[lastc];
        if (c != 0.0) {
          c *= -tau;
          colbottom = lastv + i;
          e_st.site = &tb_emlrtRSI;
          if ((i <= colbottom) && (colbottom > 2147483646)) {
            f_st.site = &s_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }
          for (iac = i; iac <= colbottom; iac++) {
            C[iac - 1] += C[((iv0 + iac) - i) - 1] * c;
          }
        }
        i += 6;
      }
    }
  }
}

static real_T zp2ss(const emlrtStack *sp, real_T a[9], real_T b[3], real_T c[3])
{
  creal_T b_c[3];
  real_T b_a[4];
  real_T t[4];
  real_T d;
  real_T re_tmp;
  int32_T b_iv[2];
  int32_T b_iv1[2];
  int32_T j;
  int32_T k;
  memset(&a[0], 0, 9U * sizeof(real_T));
  c[1] = 0.0;
  c[2] = 0.0;
  a[0] = -1.0;
  b[0] = 1.0;
  b_c[0].re = 1.0;
  b_c[0].im = 0.0;
  for (j = 0; j < 2; j++) {
    real_T b_re_tmp;
    d = 1.7320508075688774 * (real_T)j - 0.86602540378443871;
    re_tmp = b_c[j].im;
    b_re_tmp = b_c[j].re;
    b_c[j + 1].re = 0.49999999999999978 * b_re_tmp - -d * re_tmp;
    b_c[j + 1].im = 0.49999999999999978 * re_tmp + -d * b_re_tmp;
    for (k = j + 1; k >= 2; k--) {
      b_c[1].re -= -0.49999999999999978 * b_c[0].re - d * b_c[0].im;
      b_c[1].im -= -0.49999999999999978 * b_c[0].im + d * b_c[0].re;
    }
  }
  t[1] = 0.0;
  t[2] = 0.0;
  t[0] = 1.0;
  t[3] = 1.0000000000000002;
  d = (1.0 - -b_c[1].re * 0.0) / 1.0000000000000002;
  b_a[1] = d;
  b_a[0] = -b_c[1].re - d * 0.0;
  d = (0.0 - -b_c[2].re * 0.0) / 1.0000000000000002;
  b_a[3] = d;
  b_a[2] = -b_c[2].re - d * 0.0;
  a[1] = 1.0;
  b_iv[0] = 2;
  b_iv1[0] = 2;
  a[2] = 0.0;
  b_iv[1] = 1;
  b_iv1[1] = 1;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &b_iv1[0], 2, &emlrtECI,
                                (emlrtCTX)sp);
  c[0] = 0.0;
  for (j = 0; j < 2; j++) {
    d = b_a[j + 2];
    re_tmp = b_a[j];
    a[j + 4] = re_tmp + d * 0.0;
    a[j + 7] = re_tmp * 0.0 + d * 1.0000000000000002;
    c[j + 1] = t[(j << 1) + 1];
    b[j + 1] = 0.0;
  }
  __m128d r;
  r = _mm_loadu_pd(&c[0]);
  _mm_storeu_pd(&c[0], _mm_mul_pd(r, _mm_set1_pd(0.99999999999999989)));
  c[2] *= 0.99999999999999989;
  return 0.0;
}

void calcule_bpm(const emlrtStack *sp, real_T periode, const real_T bat[740],
                 real_T *nb_battements, real_T *bpm_moy)
{
  emlrtStack st;
  real_T dv1[740];
  real_T locs_data[740];
  real_T peaks_data[740];
  real_T ppg_filt[740];
  real_T IBI_data[739];
  real_T tmp_data[739];
  real_T a[7];
  real_T b[7];
  real_T dv[2];
  real_T b_fs;
  real_T fs;
  int32_T tmp_size[2];
  int32_T i;
  int32_T loop_ub;
  int32_T peaks_size;
  int32_T scalarLB;
  int32_T vectorUB;
  st.prev = sp;
  st.tls = sp->tls;
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0U);
  fs = 1.0 / periode;
  b_fs = fs / 2.0;
  dv[0] = 0.5 / b_fs;
  dv[1] = 5.0 / b_fs;
  st.site = &emlrtRSI;
  butter(&st, dv, b, a);
  st.site = &b_emlrtRSI;
  filtfilt(&st, b, a, bat, ppg_filt);
  for (i = 0; i < 740; i++) {
    dv1[i] = (real_T)i / fs;
  }
  int32_T locs_size[2];
  st.site = &c_emlrtRSI;
  peaks_size = findpeaks(&st, ppg_filt, dv1,
                         sumColumnB(ppg_filt) / 740.0 + 0.5 * b_std(ppg_filt),
                         peaks_data, locs_data, locs_size);
  st.site = &d_emlrtRSI;
  diff(&st, locs_data, locs_size, IBI_data, tmp_size);
  tmp_size[0] = 1;
  loop_ub = tmp_size[1];
  scalarLB = (tmp_size[1] / 2) << 1;
  vectorUB = scalarLB - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    __m128d r;
    r = _mm_loadu_pd(&IBI_data[i]);
    _mm_storeu_pd(&tmp_data[i], _mm_div_pd(_mm_set1_pd(60.0), r));
  }
  for (i = scalarLB; i < loop_ub; i++) {
    tmp_data[i] = 60.0 / IBI_data[i];
  }
  st.site = &e_emlrtRSI;
  *bpm_moy = mean(&st, tmp_data, tmp_size);
  *nb_battements = peaks_size;
}

void calcule_bpm_api(const mxArray *const prhs[2], int32_T nlhs,
                     const mxArray *plhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*bat)[740];
  real_T bpm_moy;
  real_T nb_battements;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  nb_battements = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "periode");
  bat = e_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "bat");
  /* Invoke the target function */
  calcule_bpm(&st, nb_battements, *bat, &nb_battements, &bpm_moy);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(nb_battements);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(bpm_moy);
  }
}

void calcule_bpm_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtPushHeapReferenceStackR2021a(
      &st, false, NULL, (void *)&emlrtExitTimeCleanupDtorFcn, NULL, NULL, NULL);
  emlrtEnterRtStackR2012b(&st);
  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);
  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void calcule_bpm_initialize(void)
{
  static const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
                          "signal_toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    calcule_bpm_once();
  }
}

void calcule_bpm_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

real_T calcule_pas(const emlrtStack *sp, const real_T accX[19],
                   const real_T accY[19], const real_T accZ[19])
{
  __m128d r;
  emlrtStack st;
  creal_T Y[19];
  real_T accFiltered[19];
  real_T accNorm[19];
  real_T Y_half[9];
  real_T pas;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  covrtLogFcn(&emlrtCoverageInstance, 1U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 0U);
  for (k = 0; k <= 16; k += 2) {
    __m128d r1;
    __m128d r2;
    r = _mm_loadu_pd(&accX[k]);
    r1 = _mm_loadu_pd(&accY[k]);
    r2 = _mm_loadu_pd(&accZ[k]);
    _mm_storeu_pd(&accNorm[k],
                  _mm_add_pd(_mm_add_pd(_mm_mul_pd(r, r), _mm_mul_pd(r1, r1)),
                             _mm_mul_pd(r2, r2)));
  }
  accNorm[18] =
      (accX[18] * accX[18] + accY[18] * accY[18]) + accZ[18] * accZ[18];
  st.site = &th_emlrtRSI;
  b_sqrt(&st, accNorm);
  b_filter(accNorm, accFiltered);
  pas = c_sumColumnB(accFiltered) / 19.0;
  for (k = 0; k <= 16; k += 2) {
    r = _mm_loadu_pd(&accFiltered[k]);
    _mm_storeu_pd(&accFiltered[k], _mm_sub_pd(r, _mm_set1_pd(pas)));
  }
  accFiltered[18] -= pas;
  fft(accFiltered, Y);
  for (k = 0; k < 9; k++) {
    Y_half[k] = muDoubleScalarHypot(Y[k].re, Y[k].im);
  }
  if ((Y_half[1] < Y_half[2]) ||
      (muDoubleScalarIsNaN(Y_half[1]) && (!muDoubleScalarIsNaN(Y_half[2])))) {
    k = 2;
  } else {
    k = 1;
  }
  return 2.1052631578947367 * (real_T)k * 60.0;
}

void calcule_pas_api(const mxArray *const prhs[3], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*accX)[19];
  real_T(*accY)[19];
  real_T(*accZ)[19];
  real_T pas;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  accX = g_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "accX");
  accY = g_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "accY");
  accZ = g_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "accZ");
  /* Invoke the target function */
  pas = calcule_pas(&st, *accX, *accY, *accZ);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(pas);
}

/* End of code generation (calcule_bpm.c) */
