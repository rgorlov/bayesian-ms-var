/*
 * eml_int_forloop_overflow_check.c
 *
 * Code generation for function 'eml_int_forloop_overflow_check'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "strategicPort_three_assets.h"
#include "eml_int_forloop_overflow_check.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRTEInfo bb_emlrtRTEI = { 87, 9, "eml_int_forloop_overflow_check",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"
};

/* Function Definitions */
void check_forloop_overflow_error(const emlrtStack *sp)
{
  static const char_T cv0[5] = { 'i', 'n', 't', '3', '2' };

  emlrtErrorWithMessageIdR2012b(sp, &bb_emlrtRTEI,
    "Coder:toolbox:int_forloop_overflow", 3, 4, 5, cv0);
}

/* End of code generation (eml_int_forloop_overflow_check.c) */
