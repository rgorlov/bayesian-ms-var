/*
 * fprintf.c
 *
 * Code generation for function 'fprintf'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "strategicPort_three_assets.h"
#include "fprintf.h"
#include "warning.h"
#include "strategicPort_three_assets_mexutil.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtMCInfo e_emlrtMCI = { 71, 18, "fprintf",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"
};

static emlrtRSInfo kd_emlrtRSI = { 71, "fprintf",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"
};

/* Function Definitions */
real_T b_fprintf(const emlrtStack *sp, real_T varargin_1)
{
  int32_T i4;
  static const char_T cv7[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv10[2] = { 1, 7 };

  const mxArray *m3;
  const mxArray *b_y;
  static const char_T formatSpec[17] = { 'D', 'o', 'n', 'e', ' ', '%', 'f', ' ',
    'p', 'e', 'r', 'i', 'o', 'd', '.', '\\', 'n' };

  char_T b_u[17];
  const mxArray *c_y;
  static const int32_T iv11[2] = { 1, 17 };

  const mxArray *d_y;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i4 = 0; i4 < 7; i4++) {
    u[i4] = cv7[i4];
  }

  y = NULL;
  m3 = emlrtCreateCharArray(2, iv10);
  emlrtInitCharArrayR2013a(sp, 7, m3, &u[0]);
  emlrtAssign(&y, m3);
  b_y = NULL;
  m3 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&b_y, m3);
  for (i4 = 0; i4 < 17; i4++) {
    b_u[i4] = formatSpec[i4];
  }

  c_y = NULL;
  m3 = emlrtCreateCharArray(2, iv11);
  emlrtInitCharArrayR2013a(sp, 17, m3, &b_u[0]);
  emlrtAssign(&c_y, m3);
  d_y = NULL;
  m3 = emlrtCreateDoubleScalar(varargin_1);
  emlrtAssign(&d_y, m3);
  st.site = &kd_emlrtRSI;
  return c_emlrt_marshallIn(&st, c_feval(&st, y, b_y, c_y, d_y, &e_emlrtMCI),
    "feval");
}

/* End of code generation (fprintf.c) */
