/*
 * sum.c
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "strategicPort_three_assets.h"
#include "sum.h"
#include "eml_int_forloop_overflow_check.h"
#include "strategicPort_three_assets_emxutil.h"
#include "strategicPort_three_assets_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo wc_emlrtRSI = { 13, "sum",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m"
};

static emlrtRSInfo xc_emlrtRSI = { 46, "sumprod",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"
};

static emlrtRSInfo yc_emlrtRSI = { 56, "combine_vector_elements",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combine_vector_elements.m"
};

static emlrtRTEInfo s_emlrtRTEI = { 1, 14, "sum",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m"
};

/* Function Definitions */
void b_sum(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  int32_T vstride;
  int32_T iy;
  int32_T ixstart;
  boolean_T overflow;
  int32_T j;
  int32_T ix;
  real_T s;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &wc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &xc_emlrtRSI;
  vstride = y->size[0];
  y->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)y, vstride, (int32_T)sizeof
                    (real_T), &s_emlrtRTEI);
  if (x->size[0] == 0) {
    iy = y->size[0];
    vstride = y->size[0];
    y->size[0] = iy;
    emxEnsureCapacity(&b_st, (emxArray__common *)y, vstride, (int32_T)sizeof
                      (real_T), &s_emlrtRTEI);
    for (vstride = 0; vstride < iy; vstride++) {
      y->data[vstride] = 0.0;
    }
  } else {
    vstride = x->size[0];
    iy = -1;
    ixstart = -1;
    c_st.site = &yc_emlrtRSI;
    overflow = (x->size[0] > 2147483646);
    if (overflow) {
      d_st.site = &s_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (j = 1; j <= vstride; j++) {
      ixstart++;
      ix = ixstart;
      s = x->data[ixstart];
      for (k = 0; k < 2; k++) {
        ix += vstride;
        s += x->data[ix];
      }

      iy++;
      y->data[iy] = s;
    }
  }
}

real_T sum(const real_T x[3])
{
  real_T y;
  int32_T k;
  y = x[0];
  for (k = 0; k < 2; k++) {
    y += x[k + 1];
  }

  return y;
}

/* End of code generation (sum.c) */
