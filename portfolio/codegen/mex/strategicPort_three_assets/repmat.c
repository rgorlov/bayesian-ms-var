/*
 * repmat.c
 *
 * Code generation for function 'repmat'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "strategicPort_three_assets.h"
#include "repmat.h"
#include "eml_int_forloop_overflow_check.h"
#include "strategicPort_three_assets_emxutil.h"
#include "assertValidSizeArg.h"
#include "strategicPort_three_assets_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo cb_emlrtRSI = { 18, "repmat",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"
};

static emlrtRSInfo db_emlrtRSI = { 112, "repmat",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"
};

static emlrtRSInfo eb_emlrtRSI = { 119, "repmat",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"
};

static emlrtMCInfo emlrtMCI = { 37, 5, "repmat",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"
};

static emlrtRTEInfo l_emlrtRTEI = { 1, 14, "repmat",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"
};

static emlrtRSInfo id_emlrtRSI = { 37, "repmat",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"
};

/* Function Declarations */
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const char_T u[15]);
static void g_error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
                    *location);

/* Function Definitions */
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const char_T u[15])
{
  const mxArray *y;
  static const int32_T iv12[2] = { 1, 15 };

  const mxArray *m4;
  y = NULL;
  m4 = emlrtCreateCharArray(2, iv12);
  emlrtInitCharArrayR2013a(sp, 15, m4, &u[0]);
  emlrtAssign(&y, m4);
  return y;
}

static void g_error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
                    *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "error", true, location);
}

void repmat(const emlrtStack *sp, const emxArray_real_T *a, real_T varargin_2,
            emxArray_real_T *b)
{
  int32_T outsize_idx_0;
  static const char_T cv1[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm',
    'a', 'x', 's', 'i', 'z', 'e' };

  int32_T jtilecol;
  boolean_T p;
  int32_T ibtile;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &cb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  assertValidSizeArg(&st, varargin_2);
  outsize_idx_0 = a->size[0];
  if (outsize_idx_0 == a->size[0]) {
  } else {
    st.site = &id_emlrtRSI;
    g_error(&st, emlrt_marshallOut(&st, cv1), &emlrtMCI);
  }

  jtilecol = b->size[0] * b->size[1];
  b->size[0] = outsize_idx_0;
  b->size[1] = (int32_T)varargin_2;
  emxEnsureCapacity(sp, (emxArray__common *)b, jtilecol, (int32_T)sizeof(real_T),
                    &l_emlrtRTEI);
  if (!(a->size[0] == 0)) {
    if (outsize_idx_0 == 0) {
      p = true;
    } else if ((int32_T)varargin_2 == 0) {
      p = true;
    } else {
      p = false;
    }

    if (!p) {
      outsize_idx_0 = a->size[0];
      st.site = &db_emlrtRSI;
      for (jtilecol = 1; jtilecol <= (int32_T)varargin_2; jtilecol++) {
        ibtile = (jtilecol - 1) * outsize_idx_0;
        st.site = &eb_emlrtRSI;
        if (outsize_idx_0 > 2147483646) {
          b_st.site = &s_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        for (k = 1; k <= outsize_idx_0; k++) {
          b->data[(ibtile + k) - 1] = a->data[k - 1];
        }
      }
    }
  }
}

/* End of code generation (repmat.c) */
