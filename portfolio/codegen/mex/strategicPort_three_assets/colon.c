/*
 * colon.c
 *
 * Code generation for function 'colon'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "strategicPort_three_assets.h"
#include "colon.h"
#include "eml_int_forloop_overflow_check.h"
#include "strategicPort_three_assets_emxutil.h"
#include "strategicPort_three_assets_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo yb_emlrtRSI = { 156, "colon",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo ac_emlrtRSI = { 151, "colon",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRTEInfo p_emlrtRTEI = { 146, 14, "colon",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

/* Function Definitions */
void eml_signed_integer_colon(const emlrtStack *sp, int32_T b, emxArray_int32_T *
  y)
{
  int32_T yk;
  boolean_T b4;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ac_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  yk = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b;
  emxEnsureCapacity(sp, (emxArray__common *)y, yk, (int32_T)sizeof(int32_T),
                    &p_emlrtRTEI);
  y->data[0] = 1;
  yk = 1;
  st.site = &yb_emlrtRSI;
  if (2 > b) {
    b4 = false;
  } else {
    b4 = (b > 2147483646);
  }

  if (b4) {
    b_st.site = &s_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (k = 2; k <= b; k++) {
    yk++;
    y->data[k - 1] = yk;
  }
}

/* End of code generation (colon.c) */
