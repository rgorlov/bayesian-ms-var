/*
 * mldivide.c
 *
 * Code generation for function 'mldivide'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "strategicPort_three_assets.h"
#include "mldivide.h"
#include "strategicPort_three_assets_emxutil.h"
#include "warning.h"
#include "xgetrf.h"
#include "qrsolve.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo ib_emlrtRSI = { 1, "mldivide",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.p"
};

static emlrtRSInfo jb_emlrtRSI = { 42, "lusolve",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"
};

static emlrtRSInfo kb_emlrtRSI = { 92, "lusolve",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"
};

static emlrtRSInfo lb_emlrtRSI = { 90, "lusolve",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"
};

static emlrtRSInfo mb_emlrtRSI = { 117, "lusolve",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"
};

static emlrtRSInfo nb_emlrtRSI = { 128, "lusolve",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"
};

static emlrtRSInfo ob_emlrtRSI = { 130, "lusolve",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"
};

static emlrtRSInfo bc_emlrtRSI = { 76, "lusolve",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"
};

static emlrtRTEInfo n_emlrtRTEI = { 1, 2, "mldivide",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.p"
};

static emlrtRTEInfo fb_emlrtRTEI = { 1, 1, "mldivide",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.p"
};

/* Function Definitions */
void mldivide(const emlrtStack *sp, const emxArray_real_T *A, emxArray_real_T *B)
{
  emxArray_real_T *b_A;
  int32_T info;
  int32_T ip;
  emxArray_int32_T *ipiv;
  int32_T xj;
  real_T temp;
  char_T DIAGA;
  char_T TRANSA;
  char_T UPLO;
  char_T SIDE;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  emxArray_real_T *b_B;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_A, 2, &n_emlrtRTEI, true);
  if (B->size[0] == A->size[0]) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &fb_emlrtRTEI, "Coder:MATLAB:dimagree", 0);
  }

  if (A->size[0] == A->size[1]) {
    st.site = &ib_emlrtRSI;
    b_st.site = &jb_emlrtRSI;
    info = b_A->size[0] * b_A->size[1];
    b_A->size[0] = A->size[0];
    b_A->size[1] = A->size[1];
    emxEnsureCapacity(&b_st, (emxArray__common *)b_A, info, (int32_T)sizeof
                      (real_T), &n_emlrtRTEI);
    ip = A->size[0] * A->size[1];
    for (info = 0; info < ip; info++) {
      b_A->data[info] = A->data[info];
    }

    emxInit_int32_T1(&b_st, &ipiv, 2, &n_emlrtRTEI, true);
    c_st.site = &lb_emlrtRSI;
    xgetrf(&c_st, A->size[1], A->size[1], b_A, A->size[1], ipiv, &info);
    if (info > 0) {
      c_st.site = &kb_emlrtRSI;
      d_st.site = &bc_emlrtRSI;
      warning(&d_st);
    }

    c_st.site = &mb_emlrtRSI;
    for (info = 0; info + 1 < A->size[1]; info++) {
      if (ipiv->data[info] != info + 1) {
        ip = ipiv->data[info] - 1;
        for (xj = 0; xj < 10201; xj++) {
          temp = B->data[info + B->size[0] * xj];
          B->data[info + B->size[0] * xj] = B->data[ip + B->size[0] * xj];
          B->data[ip + B->size[0] * xj] = temp;
        }
      }
    }

    emxFree_int32_T(&ipiv);
    c_st.site = &nb_emlrtRSI;
    temp = 1.0;
    DIAGA = 'U';
    TRANSA = 'N';
    UPLO = 'L';
    SIDE = 'L';
    m_t = (ptrdiff_t)A->size[1];
    n_t = (ptrdiff_t)10201;
    lda_t = (ptrdiff_t)A->size[1];
    ldb_t = (ptrdiff_t)A->size[1];
    dtrsm(&SIDE, &UPLO, &TRANSA, &DIAGA, &m_t, &n_t, &temp, &b_A->data[0],
          &lda_t, &B->data[0], &ldb_t);
    c_st.site = &ob_emlrtRSI;
    temp = 1.0;
    DIAGA = 'N';
    TRANSA = 'N';
    UPLO = 'U';
    SIDE = 'L';
    m_t = (ptrdiff_t)A->size[1];
    n_t = (ptrdiff_t)10201;
    lda_t = (ptrdiff_t)A->size[1];
    ldb_t = (ptrdiff_t)A->size[1];
    dtrsm(&SIDE, &UPLO, &TRANSA, &DIAGA, &m_t, &n_t, &temp, &b_A->data[0],
          &lda_t, &B->data[0], &ldb_t);
  } else {
    emxInit_real_T(sp, &b_B, 2, &n_emlrtRTEI, true);
    info = b_B->size[0] * b_B->size[1];
    b_B->size[0] = B->size[0];
    b_B->size[1] = 10201;
    emxEnsureCapacity(sp, (emxArray__common *)b_B, info, (int32_T)sizeof(real_T),
                      &n_emlrtRTEI);
    ip = B->size[0] * B->size[1];
    for (info = 0; info < ip; info++) {
      b_B->data[info] = B->data[info];
    }

    st.site = &ib_emlrtRSI;
    qrsolve(&st, A, b_B, B);
    emxFree_real_T(&b_B);
  }

  emxFree_real_T(&b_A);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (mldivide.c) */
