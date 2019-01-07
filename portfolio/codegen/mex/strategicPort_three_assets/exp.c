/*
 * exp.c
 *
 * Code generation for function 'exp'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "strategicPort_three_assets.h"
#include "exp.h"
#include "eml_int_forloop_overflow_check.h"
#include "strategicPort_three_assets_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo q_emlrtRSI = { 9, "exp",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\elfun\\exp.m" };

/* Function Definitions */
void b_exp(const emlrtStack *sp, emxArray_real_T *x)
{
  int32_T nx;
  boolean_T b7;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &q_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nx = x->size[0] * x->size[1];
  b_st.site = &r_emlrtRSI;
  if (1 > nx) {
    b7 = false;
  } else {
    b7 = (nx > 2147483646);
  }

  if (b7) {
    c_st.site = &s_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (k = 0; k + 1 <= nx; k++) {
    x->data[k] = muDoubleScalarExp(x->data[k]);
  }
}

/* End of code generation (exp.c) */
