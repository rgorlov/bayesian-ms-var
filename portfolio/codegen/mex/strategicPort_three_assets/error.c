/*
 * error.c
 *
 * Code generation for function 'error'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "strategicPort_three_assets.h"
#include "error.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRTEInfo cb_emlrtRTEI = { 17, 9, "error",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\error.m"
};

/* Function Definitions */
void b_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &cb_emlrtRTEI, "MATLAB:nomem", 0);
}

void c_error(const emlrtStack *sp, int32_T varargin_2)
{
  static const char_T varargin_1[19] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_',
    'd', 'g', 'e', 't', 'r', 'f', '_', 'w', 'o', 'r', 'k' };

  emlrtErrorWithMessageIdR2012b(sp, &cb_emlrtRTEI,
    "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 19, varargin_1, 12, varargin_2);
}

void d_error(const emlrtStack *sp, int32_T varargin_2)
{
  static const char_T varargin_1[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_',
    'd', 'g', 'e', 'q', 'p', '3' };

  emlrtErrorWithMessageIdR2012b(sp, &cb_emlrtRTEI,
    "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, varargin_1, 12, varargin_2);
}

void e_error(const emlrtStack *sp, int32_T varargin_2)
{
  static const char_T varargin_1[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_',
    'd', 'o', 'r', 'm', 'q', 'r' };

  emlrtErrorWithMessageIdR2012b(sp, &cb_emlrtRTEI,
    "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, varargin_1, 12, varargin_2);
}

void error(const emlrtStack *sp)
{
  static const char_T varargin_1[3] = { 'l', 'o', 'g' };

  emlrtErrorWithMessageIdR2012b(sp, &cb_emlrtRTEI,
    "Coder:toolbox:ElFunDomainError", 3, 4, 3, varargin_1);
}

void f_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &cb_emlrtRTEI,
    "Coder:toolbox:power_domainError", 0);
}

/* End of code generation (error.c) */
