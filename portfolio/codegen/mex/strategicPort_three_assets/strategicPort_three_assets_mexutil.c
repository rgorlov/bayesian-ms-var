/*
 * strategicPort_three_assets_mexutil.c
 *
 * Code generation for function 'strategicPort_three_assets_mexutil'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "strategicPort_three_assets.h"
#include "strategicPort_three_assets_mexutil.h"
#include "fprintf.h"
#include "lapacke.h"

/* Function Definitions */
real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *d_feval, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(d_feval), &thisId);
  emlrtDestroyArray(&d_feval);
  return y;
}

const mxArray *c_feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
  const mxArray *d, const mxArray *e, emlrtMCInfo *location)
{
  const mxArray *pArrays[4];
  const mxArray *m10;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  return emlrtCallMATLABR2012b(sp, 1, &m10, 4, pArrays, "feval", true, location);
}

real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = j_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

real_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/* End of code generation (strategicPort_three_assets_mexutil.c) */
