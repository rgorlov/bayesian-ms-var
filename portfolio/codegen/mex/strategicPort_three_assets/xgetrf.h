/*
 * xgetrf.h
 *
 * Code generation for function 'xgetrf'
 *
 */

#ifndef __XGETRF_H__
#define __XGETRF_H__

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
extern void xgetrf(const emlrtStack *sp, int32_T m, int32_T n, emxArray_real_T
                   *A, int32_T lda, emxArray_int32_T *ipiv, int32_T *info);

#endif

/* End of code generation (xgetrf.h) */
