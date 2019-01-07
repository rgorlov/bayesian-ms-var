/*
 * assertValidSizeArg.c
 *
 * Code generation for function 'assertValidSizeArg'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "strategicPort_three_assets.h"
#include "assertValidSizeArg.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRTEInfo db_emlrtRTEI = { 53, 23, "assertValidSizeArg",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"
};

/* Function Definitions */
void assertValidSizeArg(const emlrtStack *sp, real_T varargin_2)
{
  boolean_T b1;
  if ((!(varargin_2 != varargin_2)) && (!(2.147483647E+9 < varargin_2))) {
    b1 = true;
  } else {
    b1 = false;
  }

  if (b1) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &db_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }
}

/* End of code generation (assertValidSizeArg.c) */
