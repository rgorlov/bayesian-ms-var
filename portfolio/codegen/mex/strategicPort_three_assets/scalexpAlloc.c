/*
 * scalexpAlloc.c
 *
 * Code generation for function 'scalexpAlloc'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "strategicPort_three_assets.h"
#include "scalexpAlloc.h"
#include "lapacke.h"

/* Function Definitions */
boolean_T dimagree(const emxArray_real_T *z, const emxArray_real_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int32_T k;
  boolean_T exitg1;
  int32_T i2;
  int32_T i3;
  p = true;
  b_p = true;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k < 3)) {
    if (k <= 1) {
      i2 = z->size[0];
    } else {
      i2 = 1;
    }

    if (k <= 1) {
      i3 = varargin_1->size[0];
    } else {
      i3 = 1;
    }

    if (i2 != i3) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (b_p) {
  } else {
    p = false;
  }

  return p;
}

/* End of code generation (scalexpAlloc.c) */
