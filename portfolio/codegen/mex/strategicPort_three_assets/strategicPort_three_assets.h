/*
 * strategicPort_three_assets.h
 *
 * Code generation for function 'strategicPort_three_assets'
 *
 */

#ifndef __STRATEGICPORT_THREE_ASSETS_H__
#define __STRATEGICPORT_THREE_ASSETS_H__

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "strategicPort_three_assets_types.h"

/* Function Declarations */
extern void strategicPort_three_assets(c_strategicPort_three_assetsSta *SD,
  const emlrtStack *sp, const emxArray_real_T *sim_r, const emxArray_real_T
  *sim_br, const emxArray_real_T *sim_x, real_T b_gamma, emxArray_real_T *w_T);

#endif

/* End of code generation (strategicPort_three_assets.h) */
