/*
 * xgetrf.c
 *
 * Code generation for function 'xgetrf'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "strategicPort_three_assets.h"
#include "xgetrf.h"
#include "strategicPort_three_assets_emxutil.h"
#include "error.h"
#include "strategicPort_three_assets_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo pb_emlrtRSI = { 25, "xgetrf",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"
};

static emlrtRSInfo qb_emlrtRSI = { 86, "xgetrf",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"
};

static emlrtRSInfo rb_emlrtRSI = { 53, "xgetrf",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"
};

static emlrtRTEInfo o_emlrtRTEI = { 1, 26, "xgetrf",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"
};

static emlrtRTEInfo v_emlrtRTEI = { 53, 5, "xgetrf",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"
};

/* Function Definitions */
void xgetrf(const emlrtStack *sp, int32_T m, int32_T n, emxArray_real_T *A,
            int32_T lda, emxArray_int32_T *ipiv, int32_T *info)
{
  int32_T k;
  emxArray_ptrdiff_t *ipiv_t;
  int32_T i5;
  ptrdiff_t info_t;
  int32_T b_info;
  int32_T NPIV;
  boolean_T p;
  int32_T loop_ub;
  int32_T i6;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &pb_emlrtRSI;
  k = muIntScalarMin_sint32(m, n);
  if (k < 1) {
    k = 1;
  }

  b_st.site = &rb_emlrtRSI;
  emxInit_ptrdiff_t(&b_st, &ipiv_t, 1, &v_emlrtRTEI, true);
  i5 = ipiv_t->size[0];
  ipiv_t->size[0] = k;
  emxEnsureCapacity(&st, (emxArray__common *)ipiv_t, i5, (int32_T)sizeof
                    (ptrdiff_t), &o_emlrtRTEI);
  info_t = LAPACKE_dgetrf_work(102, (ptrdiff_t)m, (ptrdiff_t)n, &A->data[0],
    (ptrdiff_t)lda, &ipiv_t->data[0]);
  b_info = (int32_T)info_t;
  i5 = ipiv->size[0] * ipiv->size[1];
  ipiv->size[0] = 1;
  ipiv->size[1] = ipiv_t->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)ipiv, i5, (int32_T)sizeof(int32_T),
                    &o_emlrtRTEI);
  NPIV = ipiv->size[1] - 1;
  b_st.site = &qb_emlrtRSI;
  if (b_info < 0) {
    if (b_info == -1010) {
      c_st.site = &sb_emlrtRSI;
      b_error(&c_st);
    } else {
      c_st.site = &tb_emlrtRSI;
      c_error(&c_st, b_info);
    }

    p = true;
  } else {
    p = false;
  }

  if (p) {
    i5 = A->size[0] * A->size[1];
    emxEnsureCapacity(&st, (emxArray__common *)A, i5, (int32_T)sizeof(real_T),
                      &o_emlrtRTEI);
    k = A->size[1];
    for (i5 = 0; i5 < k; i5++) {
      loop_ub = A->size[0];
      for (i6 = 0; i6 < loop_ub; i6++) {
        A->data[i6 + A->size[0] * i5] = rtNaN;
      }
    }

    for (k = 0; k <= NPIV; k++) {
      ipiv->data[k] = k + 1;
    }
  } else {
    for (k = 0; k <= NPIV; k++) {
      ipiv->data[k] = (int32_T)ipiv_t->data[k];
    }
  }

  emxFree_ptrdiff_t(&ipiv_t);
  *info = b_info;
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (xgetrf.c) */
