/*
 * _coder_strategicPort_three_assets_mex.c
 *
 * Code generation for function '_coder_strategicPort_three_assets_mex'
 *
 */

/* Include files */
#include "strategicPort_three_assets.h"
#include "_coder_strategicPort_three_assets_mex.h"
#include "strategicPort_three_assets_terminate.h"
#include "_coder_strategicPort_three_assets_api.h"
#include "strategicPort_three_assets_initialize.h"
#include "strategicPort_three_assets_data.h"
#include "lapacke.h"

/* Variable Definitions */
static c_strategicPort_three_assetsSta *d_strategicPort_three_assetsSta = NULL;

/* Function Declarations */
static void c_strategicPort_three_assets_me(c_strategicPort_three_assetsSta *SD,
  int32_T nlhs, mxArray *plhs[1], int32_T nrhs, const mxArray *prhs[4]);

/* Function Definitions */
static void c_strategicPort_three_assets_me(c_strategicPort_three_assetsSta *SD,
  int32_T nlhs, mxArray *plhs[1], int32_T nrhs, const mxArray *prhs[4])
{
  int32_T n;
  const mxArray *inputs[4];
  const mxArray *outputs[1];
  int32_T b_nlhs;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        26, "strategicPort_three_assets");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 26,
                        "strategicPort_three_assets");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  strategicPort_three_assets_api(SD, inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  strategicPort_three_assets_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  d_strategicPort_three_assetsSta = (c_strategicPort_three_assetsSta *)mxCalloc
    (1, 1U * sizeof(c_strategicPort_three_assetsSta));
  mexAtExit(strategicPort_three_assets_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  strategicPort_three_assets_initialize();

  /* Dispatch the entry-point. */
  c_strategicPort_three_assets_me(d_strategicPort_three_assetsSta, nlhs, plhs,
    nrhs, prhs);
  mxFree(d_strategicPort_three_assetsSta);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_strategicPort_three_assets_mex.c) */
