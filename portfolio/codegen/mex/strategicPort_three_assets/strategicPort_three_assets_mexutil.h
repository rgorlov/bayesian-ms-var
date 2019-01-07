/*
 * strategicPort_three_assets_mexutil.h
 *
 * Code generation for function 'strategicPort_three_assets_mexutil'
 *
 */

#ifndef __STRATEGICPORT_THREE_ASSETS_MEXUTIL_H__
#define __STRATEGICPORT_THREE_ASSETS_MEXUTIL_H__

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "strategicPort_three_assets_types.h"

/* Function Declarations */
extern real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *d_feval,
  const char_T *identifier);

#ifdef __WATCOMC__

#pragma aux c_emlrt_marshallIn value [8087];

#endif

extern const mxArray *c_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, emlrtMCInfo *location);
extern real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);

#ifdef __WATCOMC__

#pragma aux d_emlrt_marshallIn value [8087];

#endif

extern real_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

#ifdef __WATCOMC__

#pragma aux j_emlrt_marshallIn value [8087];

#endif
#endif

/* End of code generation (strategicPort_three_assets_mexutil.h) */
