/*
 * strategicPort_three_assets_initialize.c
 *
 * Code generation for function 'strategicPort_three_assets_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "strategicPort_three_assets.h"
#include "strategicPort_three_assets_initialize.h"
#include "_coder_strategicPort_three_assets_mex.h"
#include "strategicPort_three_assets_data.h"
#include "lapacke.h"

/* Function Definitions */
void strategicPort_three_assets_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (strategicPort_three_assets_initialize.c) */
