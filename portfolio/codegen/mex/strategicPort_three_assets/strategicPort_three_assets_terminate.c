/*
 * strategicPort_three_assets_terminate.c
 *
 * Code generation for function 'strategicPort_three_assets_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "strategicPort_three_assets.h"
#include "strategicPort_three_assets_terminate.h"
#include "_coder_strategicPort_three_assets_mex.h"
#include "strategicPort_three_assets_data.h"
#include "lapacke.h"

/* Function Definitions */
void strategicPort_three_assets_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void strategicPort_three_assets_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (strategicPort_three_assets_terminate.c) */
