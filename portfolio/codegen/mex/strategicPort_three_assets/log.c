/*
 * log.c
 *
 * Code generation for function 'log'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "strategicPort_three_assets.h"
#include "log.h"
#include "error.h"
#include "eml_int_forloop_overflow_check.h"
#include "strategicPort_three_assets_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo ab_emlrtRSI = { 13, "log",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\elfun\\log.m" };

static emlrtRSInfo bb_emlrtRSI = { 16, "log",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\elfun\\log.m" };

/* Function Definitions */
void b_log(const emlrtStack *sp, emxArray_real_T *x)
{
  boolean_T p;
  int32_T nx;
  int32_T k;
  boolean_T b8;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  p = false;
  nx = x->size[0] * x->size[1];
  for (k = 0; k < nx; k++) {
    if (p || (x->data[k] < 0.0)) {
      p = true;
    } else {
      p = false;
    }
  }

  if (p) {
    st.site = &ab_emlrtRSI;
    error(&st);
  }

  st.site = &bb_emlrtRSI;
  nx = x->size[0] * x->size[1];
  b_st.site = &r_emlrtRSI;
  if (1 > nx) {
    b8 = false;
  } else {
    b8 = (nx > 2147483646);
  }

  if (b8) {
    c_st.site = &s_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (k = 0; k + 1 <= nx; k++) {
    x->data[k] = muDoubleScalarLog(x->data[k]);
  }
}

/* End of code generation (log.c) */
