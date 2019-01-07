/*
 * power.c
 *
 * Code generation for function 'power'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "strategicPort_three_assets.h"
#include "power.h"
#include "error.h"
#include "eml_int_forloop_overflow_check.h"
#include "strategicPort_three_assets_emxutil.h"
#include "scalexpAlloc.h"
#include "strategicPort_three_assets_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo ad_emlrtRSI = { 49, "power",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\ops\\power.m" };

static emlrtRSInfo bd_emlrtRSI = { 58, "power",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\ops\\power.m" };

static emlrtRSInfo cd_emlrtRSI = { 61, "power",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\ops\\power.m" };

static emlrtRSInfo dd_emlrtRSI = { 73, "applyScalarFunction",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m"
};

static emlrtRSInfo ed_emlrtRSI = { 132, "applyScalarFunction",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m"
};

static emlrtRTEInfo t_emlrtRTEI = { 16, 9, "scalexpAlloc",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc.m"
};

static emlrtRTEInfo eb_emlrtRTEI = { 17, 19, "scalexpAlloc",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc.m"
};

/* Function Definitions */
void power(const emlrtStack *sp, const emxArray_real_T *a, real_T b,
           emxArray_real_T *y)
{
  uint32_T a_idx_0;
  int32_T k;
  boolean_T overflow;
  boolean_T b6;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ad_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &bd_emlrtRSI;
  c_st.site = &dd_emlrtRSI;
  a_idx_0 = (uint32_T)a->size[0];
  k = y->size[0];
  y->size[0] = (int32_T)a_idx_0;
  emxEnsureCapacity(&c_st, (emxArray__common *)y, k, (int32_T)sizeof(real_T),
                    &t_emlrtRTEI);
  if (dimagree(y, a)) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &eb_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  c_st.site = &ed_emlrtRSI;
  if (1 > a->size[0]) {
    overflow = false;
  } else {
    overflow = (a->size[0] > 2147483646);
  }

  if (overflow) {
    d_st.site = &s_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (k = 0; k + 1 <= a->size[0]; k++) {
    y->data[k] = muDoubleScalarPower(a->data[k], b);
  }

  overflow = false;
  if (a->size[0] == 1) {
    if (a->data[0] < 0.0) {
      if (muDoubleScalarIsNaN(b) || (muDoubleScalarFloor(b) == b)) {
        b6 = true;
      } else {
        b6 = false;
      }

      overflow = !b6;
    }
  } else {
    if (muDoubleScalarIsNaN(b) || (muDoubleScalarFloor(b) == b)) {
      b6 = true;
    } else {
      b6 = false;
    }

    if (!b6) {
      for (k = 0; k < a->size[0]; k++) {
        if (overflow || (a->data[k] < 0.0)) {
          overflow = true;
        } else {
          overflow = false;
        }
      }
    }
  }

  if (overflow) {
    b_st.site = &cd_emlrtRSI;
    f_error(&b_st);
  }
}

/* End of code generation (power.c) */
