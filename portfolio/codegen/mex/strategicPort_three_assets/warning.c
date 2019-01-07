/*
 * warning.c
 *
 * Code generation for function 'warning'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "strategicPort_three_assets.h"
#include "warning.h"
#include "strategicPort_three_assets_mexutil.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtMCInfo b_emlrtMCI = { 14, 25, "warning",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\warning.m"
};

static emlrtMCInfo c_emlrtMCI = { 14, 9, "warning",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\warning.m"
};

static emlrtRSInfo jd_emlrtRSI = { 14, "warning",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\warning.m"
};

/* Function Declarations */
static void b_feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location);
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);

/* Function Definitions */
static void b_feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = b;
  pArrays[1] = c;
  emlrtCallMATLABR2012b(sp, 0, NULL, 2, pArrays, "feval", true, location);
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m8;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m8, 2, pArrays, "feval", true, location);
}

void b_warning(const emlrtStack *sp, int32_T varargin_1, const char_T
               varargin_2[14])
{
  int32_T i1;
  static const char_T cv5[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv6[2] = { 1, 7 };

  const mxArray *m2;
  static const char_T cv6[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  char_T b_u[7];
  const mxArray *b_y;
  static const int32_T iv7[2] = { 1, 7 };

  static const char_T msgID[32] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'r', 'a', 'n', 'k', 'D', 'e', 'f', 'i', 'c', 'i', 'e',
    'n', 't', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c_u[32];
  const mxArray *c_y;
  static const int32_T iv8[2] = { 1, 32 };

  const mxArray *d_y;
  char_T d_u[14];
  const mxArray *e_y;
  static const int32_T iv9[2] = { 1, 14 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i1 = 0; i1 < 7; i1++) {
    u[i1] = cv5[i1];
  }

  y = NULL;
  m2 = emlrtCreateCharArray(2, iv6);
  emlrtInitCharArrayR2013a(sp, 7, m2, &u[0]);
  emlrtAssign(&y, m2);
  for (i1 = 0; i1 < 7; i1++) {
    b_u[i1] = cv6[i1];
  }

  b_y = NULL;
  m2 = emlrtCreateCharArray(2, iv7);
  emlrtInitCharArrayR2013a(sp, 7, m2, &b_u[0]);
  emlrtAssign(&b_y, m2);
  for (i1 = 0; i1 < 32; i1++) {
    c_u[i1] = msgID[i1];
  }

  c_y = NULL;
  m2 = emlrtCreateCharArray(2, iv8);
  emlrtInitCharArrayR2013a(sp, 32, m2, &c_u[0]);
  emlrtAssign(&c_y, m2);
  d_y = NULL;
  m2 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)mxGetData(m2) = varargin_1;
  emlrtAssign(&d_y, m2);
  for (i1 = 0; i1 < 14; i1++) {
    d_u[i1] = varargin_2[i1];
  }

  e_y = NULL;
  m2 = emlrtCreateCharArray(2, iv9);
  emlrtInitCharArrayR2013a(sp, 14, m2, &d_u[0]);
  emlrtAssign(&e_y, m2);
  st.site = &jd_emlrtRSI;
  b_feval(&st, y, c_feval(&st, b_y, c_y, d_y, e_y, &b_emlrtMCI), &c_emlrtMCI);
}

void warning(const emlrtStack *sp)
{
  int32_T i0;
  static const char_T cv2[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv2[2] = { 1, 7 };

  const mxArray *m0;
  static const char_T cv3[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  char_T b_u[7];
  const mxArray *b_y;
  static const int32_T iv3[2] = { 1, 7 };

  static const char_T msgID[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't',
    'r', 'i', 'x' };

  char_T c_u[27];
  const mxArray *c_y;
  static const int32_T iv4[2] = { 1, 27 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i0 = 0; i0 < 7; i0++) {
    u[i0] = cv2[i0];
  }

  y = NULL;
  m0 = emlrtCreateCharArray(2, iv2);
  emlrtInitCharArrayR2013a(sp, 7, m0, &u[0]);
  emlrtAssign(&y, m0);
  for (i0 = 0; i0 < 7; i0++) {
    b_u[i0] = cv3[i0];
  }

  b_y = NULL;
  m0 = emlrtCreateCharArray(2, iv3);
  emlrtInitCharArrayR2013a(sp, 7, m0, &b_u[0]);
  emlrtAssign(&b_y, m0);
  for (i0 = 0; i0 < 27; i0++) {
    c_u[i0] = msgID[i0];
  }

  c_y = NULL;
  m0 = emlrtCreateCharArray(2, iv4);
  emlrtInitCharArrayR2013a(sp, 27, m0, &c_u[0]);
  emlrtAssign(&c_y, m0);
  st.site = &jd_emlrtRSI;
  b_feval(&st, y, feval(&st, b_y, c_y, &b_emlrtMCI), &c_emlrtMCI);
}

/* End of code generation (warning.c) */
