/*
 * _coder_strategicPort_three_assets_api.c
 *
 * Code generation for function '_coder_strategicPort_three_assets_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "strategicPort_three_assets.h"
#include "_coder_strategicPort_three_assets_api.h"
#include "strategicPort_three_assets_emxutil.h"
#include "fprintf.h"
#include "strategicPort_three_assets_mexutil.h"
#include "strategicPort_three_assets_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRTEInfo u_emlrtRTEI = { 1, 1,
  "_coder_strategicPort_three_assets_api", "" };

/* Function Declarations */
static const mxArray *d_emlrt_marshallOut(const emxArray_real_T *u);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *sim_r, const
  char_T *identifier, emxArray_real_T *y);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *sim_x, const
  char_T *identifier, emxArray_real_T *y);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);

/* Function Definitions */
static const mxArray *d_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  static const int32_T iv13[2] = { 0, 0 };

  const mxArray *m7;
  y = NULL;
  m7 = emlrtCreateNumericArray(2, iv13, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m7, (void *)u->data);
  emlrtSetDimensions((mxArray *)m7, u->size, 2);
  emlrtAssign(&y, m7);
  return y;
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *sim_r, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(sim_r), &thisId, y);
  emlrtDestroyArray(&sim_r);
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  k_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *sim_x, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(sim_x), &thisId, y);
  emlrtDestroyArray(&sim_x);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  l_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv14[2];
  boolean_T bv0[2] = { true, true };

  static const int32_T dims[2] = { -1, -1 };

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv0[0],
    iv14);
  ret->size[0] = iv14[0];
  ret->size[1] = iv14[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv15[3];
  boolean_T bv1[3] = { true, true, true };

  static const int32_T dims[3] = { -1, -1, -1 };

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 3U, dims, &bv1[0],
    iv15);
  ret->size[0] = iv15[0];
  ret->size[1] = iv15[1];
  ret->size[2] = iv15[2];
  ret->allocatedSize = ret->size[0] * ret->size[1] * ret->size[2];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

void strategicPort_three_assets_api(c_strategicPort_three_assetsSta *SD, const
  mxArray * const prhs[4], const mxArray *plhs[1])
{
  emxArray_real_T *sim_r;
  emxArray_real_T *sim_br;
  emxArray_real_T *sim_x;
  emxArray_real_T *w_T;
  real_T b_gamma;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &sim_r, 2, &u_emlrtRTEI, true);
  emxInit_real_T(&st, &sim_br, 2, &u_emlrtRTEI, true);
  emxInit_real_T2(&st, &sim_x, 3, &u_emlrtRTEI, true);
  emxInit_real_T(&st, &w_T, 2, &u_emlrtRTEI, true);

  /* Marshall function inputs */
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "sim_r", sim_r);
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "sim_br", sim_br);
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "sim_x", sim_x);
  b_gamma = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "gamma");

  /* Invoke the target function */
  strategicPort_three_assets(SD, &st, sim_r, sim_br, sim_x, b_gamma, w_T);

  /* Marshall function outputs */
  plhs[0] = d_emlrt_marshallOut(w_T);
  w_T->canFreeData = false;
  emxFree_real_T(&w_T);
  sim_x->canFreeData = false;
  emxFree_real_T(&sim_x);
  sim_br->canFreeData = false;
  emxFree_real_T(&sim_br);
  sim_r->canFreeData = false;
  emxFree_real_T(&sim_r);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_strategicPort_three_assets_api.c) */
