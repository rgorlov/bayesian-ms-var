/*
 * qrsolve.c
 *
 * Code generation for function 'qrsolve'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "strategicPort_three_assets.h"
#include "qrsolve.h"
#include "strategicPort_three_assets_emxutil.h"
#include "error.h"
#include "eml_int_forloop_overflow_check.h"
#include "warning.h"
#include "xgeqp3.h"
#include "strategicPort_three_assets_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo dc_emlrtRSI = { 28, "qrsolve",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"
};

static emlrtRSInfo ec_emlrtRSI = { 32, "qrsolve",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"
};

static emlrtRSInfo fc_emlrtRSI = { 39, "qrsolve",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"
};

static emlrtRSInfo jc_emlrtRSI = { 120, "qrsolve",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"
};

static emlrtRSInfo kc_emlrtRSI = { 121, "qrsolve",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"
};

static emlrtRSInfo lc_emlrtRSI = { 72, "qrsolve",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"
};

static emlrtRSInfo mc_emlrtRSI = { 79, "qrsolve",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"
};

static emlrtRSInfo nc_emlrtRSI = { 89, "qrsolve",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"
};

static emlrtRSInfo oc_emlrtRSI = { 29, "xunormqr",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xunormqr.m"
};

static emlrtRSInfo pc_emlrtRSI = { 97, "xunormqr",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xunormqr.m"
};

static emlrtMCInfo d_emlrtMCI = { 52, 19, "flt2str",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\flt2str.m"
};

static emlrtRTEInfo q_emlrtRTEI = { 1, 24, "qrsolve",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"
};

static emlrtRSInfo ld_emlrtRSI = { 52, "flt2str",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\flt2str.m"
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[14]);
static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_sprintf,
  const char_T *identifier, char_T y[14]);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[14]);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[14])
{
  i_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m9;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m9, 2, pArrays, "sprintf", true, location);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_sprintf,
  const char_T *identifier, char_T y[14])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(c_sprintf), &thisId, y);
  emlrtDestroyArray(&c_sprintf);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[14])
{
  static const int32_T dims[2] = { 1, 14 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, ret, 14);
  emlrtDestroyArray(&src);
}

void qrsolve(const emlrtStack *sp, const emxArray_real_T *A, const
             emxArray_real_T *B, emxArray_real_T *Y)
{
  emxArray_real_T *b_A;
  int32_T j;
  int32_T minmn;
  emxArray_real_T *tau;
  emxArray_int32_T *jpvt;
  int32_T rankR;
  int32_T maxmn;
  real_T tol;
  static const char_T rfmt[6] = { '%', '1', '4', '.', '6', 'e' };

  char_T u[6];
  const mxArray *y;
  static const int32_T iv5[2] = { 1, 6 };

  const mxArray *m1;
  const mxArray *b_y;
  char_T cv4[14];
  emxArray_real_T *b_B;
  ptrdiff_t nrc_t;
  boolean_T p;
  boolean_T b5;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
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
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_A, 2, &q_emlrtRTEI, true);
  j = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = A->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_A, j, (int32_T)sizeof(real_T),
                    &q_emlrtRTEI);
  minmn = A->size[0] * A->size[1];
  for (j = 0; j < minmn; j++) {
    b_A->data[j] = A->data[j];
  }

  emxInit_real_T1(sp, &tau, 1, &q_emlrtRTEI, true);
  emxInit_int32_T1(sp, &jpvt, 2, &q_emlrtRTEI, true);
  st.site = &dc_emlrtRSI;
  xgeqp3(&st, b_A, tau, jpvt);
  st.site = &ec_emlrtRSI;
  rankR = 0;
  if (b_A->size[0] < b_A->size[1]) {
    minmn = b_A->size[0];
    maxmn = b_A->size[1];
  } else {
    minmn = b_A->size[1];
    maxmn = b_A->size[0];
  }

  tol = (real_T)maxmn * muDoubleScalarAbs(b_A->data[0]) * 2.2204460492503131E-16;
  while ((rankR < minmn) && (muDoubleScalarAbs(b_A->data[rankR + b_A->size[0] *
           rankR]) >= tol)) {
    rankR++;
  }

  if (rankR < minmn) {
    b_st.site = &kc_emlrtRSI;
    for (j = 0; j < 6; j++) {
      u[j] = rfmt[j];
    }

    y = NULL;
    m1 = emlrtCreateCharArray(2, iv5);
    emlrtInitCharArrayR2013a(&b_st, 6, m1, &u[0]);
    emlrtAssign(&y, m1);
    b_y = NULL;
    m1 = emlrtCreateDoubleScalar(tol);
    emlrtAssign(&b_y, m1);
    c_st.site = &ld_emlrtRSI;
    emlrt_marshallIn(&c_st, b_sprintf(&c_st, y, b_y, &d_emlrtMCI), "sprintf",
                     cv4);
    b_st.site = &jc_emlrtRSI;
    b_warning(&b_st, rankR, cv4);
  }

  st.site = &fc_emlrtRSI;
  minmn = b_A->size[1];
  j = Y->size[0] * Y->size[1];
  Y->size[0] = minmn;
  Y->size[1] = 10201;
  emxEnsureCapacity(&st, (emxArray__common *)Y, j, (int32_T)sizeof(real_T),
                    &q_emlrtRTEI);
  minmn *= 10201;
  for (j = 0; j < minmn; j++) {
    Y->data[j] = 0.0;
  }

  emxInit_real_T(&st, &b_B, 2, &q_emlrtRTEI, true);
  b_st.site = &lc_emlrtRSI;
  c_st.site = &oc_emlrtRSI;
  j = b_B->size[0] * b_B->size[1];
  b_B->size[0] = B->size[0];
  b_B->size[1] = 10201;
  emxEnsureCapacity(&c_st, (emxArray__common *)b_B, j, (int32_T)sizeof(real_T),
                    &q_emlrtRTEI);
  minmn = B->size[0] * B->size[1];
  for (j = 0; j < minmn; j++) {
    b_B->data[j] = B->data[j];
  }

  minmn = muIntScalarMin_sint32(b_A->size[0], b_A->size[1]);
  nrc_t = (ptrdiff_t)b_B->size[0];
  nrc_t = LAPACKE_dormqr(102, 'L', 'T', nrc_t, (ptrdiff_t)10201, (ptrdiff_t)
    minmn, &b_A->data[0], (ptrdiff_t)b_A->size[0], &tau->data[0], &b_B->data[0],
    nrc_t);
  minmn = (int32_T)nrc_t;
  d_st.site = &pc_emlrtRSI;
  emxFree_real_T(&tau);
  if (minmn != 0) {
    if (minmn == -1010) {
      e_st.site = &sb_emlrtRSI;
      b_error(&e_st);
    } else {
      e_st.site = &tb_emlrtRSI;
      e_error(&e_st, minmn);
    }

    p = true;
  } else {
    p = false;
  }

  if (p) {
    j = b_B->size[0] * b_B->size[1];
    b_B->size[1] = 10201;
    emxEnsureCapacity(&c_st, (emxArray__common *)b_B, j, (int32_T)sizeof(real_T),
                      &q_emlrtRTEI);
    for (j = 0; j < 10201; j++) {
      minmn = b_B->size[0];
      for (maxmn = 0; maxmn < minmn; maxmn++) {
        b_B->data[maxmn + b_B->size[0] * j] = rtNaN;
      }
    }
  }

  for (minmn = 0; minmn < 10201; minmn++) {
    b_st.site = &mc_emlrtRSI;
    if (1 > rankR) {
      b5 = false;
    } else {
      b5 = (rankR > 2147483646);
    }

    if (b5) {
      c_st.site = &s_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (maxmn = 0; maxmn + 1 <= rankR; maxmn++) {
      Y->data[(jpvt->data[maxmn] + Y->size[0] * minmn) - 1] = b_B->data[maxmn +
        b_B->size[0] * minmn];
    }

    for (j = rankR - 1; j + 1 > 0; j--) {
      Y->data[(jpvt->data[j] + Y->size[0] * minmn) - 1] /= b_A->data[j +
        b_A->size[0] * j];
      b_st.site = &nc_emlrtRSI;
      for (maxmn = 0; maxmn + 1 <= j; maxmn++) {
        Y->data[(jpvt->data[maxmn] + Y->size[0] * minmn) - 1] -= Y->data
          [(jpvt->data[j] + Y->size[0] * minmn) - 1] * b_A->data[maxmn +
          b_A->size[0] * j];
      }
    }
  }

  emxFree_real_T(&b_B);
  emxFree_int32_T(&jpvt);
  emxFree_real_T(&b_A);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (qrsolve.c) */
