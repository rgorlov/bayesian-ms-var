/*
 * xgeqp3.c
 *
 * Code generation for function 'xgeqp3'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "strategicPort_three_assets.h"
#include "xgeqp3.h"
#include "error.h"
#include "strategicPort_three_assets_emxutil.h"
#include "colon.h"
#include "strategicPort_three_assets_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo wb_emlrtRSI = { 75, "colon",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo xb_emlrtRSI = { 112, "colon",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo gc_emlrtRSI = { 14, "xgeqp3",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"
};

static emlrtRSInfo hc_emlrtRSI = { 78, "xgeqp3",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"
};

static emlrtRSInfo ic_emlrtRSI = { 75, "xgeqp3",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"
};

static emlrtRTEInfo r_emlrtRTEI = { 1, 25, "xgeqp3",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"
};

static emlrtRTEInfo w_emlrtRTEI = { 44, 5, "xgeqp3",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"
};

/* Function Definitions */
void xgeqp3(const emlrtStack *sp, emxArray_real_T *A, emxArray_real_T *tau,
            emxArray_int32_T *jpvt)
{
  emxArray_ptrdiff_t *jpvt_t;
  int32_T m;
  int32_T n;
  int32_T i7;
  ptrdiff_t m_t;
  boolean_T p;
  int32_T loop_ub;
  int32_T i8;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_ptrdiff_t(sp, &jpvt_t, 1, &w_emlrtRTEI, true);
  st.site = &gc_emlrtRSI;
  m = A->size[0];
  n = A->size[1];
  i7 = tau->size[0];
  tau->size[0] = muIntScalarMin_sint32(m, n);
  emxEnsureCapacity(&st, (emxArray__common *)tau, i7, (int32_T)sizeof(real_T),
                    &r_emlrtRTEI);
  i7 = jpvt_t->size[0];
  jpvt_t->size[0] = A->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)jpvt_t, i7, (int32_T)sizeof
                    (ptrdiff_t), &r_emlrtRTEI);
  m = A->size[1];
  for (i7 = 0; i7 < m; i7++) {
    jpvt_t->data[i7] = (ptrdiff_t)0;
  }

  m_t = (ptrdiff_t)A->size[0];
  m_t = LAPACKE_dgeqp3(102, m_t, (ptrdiff_t)A->size[1], &A->data[0], m_t,
                       &jpvt_t->data[0], &tau->data[0]);
  m = (int32_T)m_t;
  b_st.site = &ic_emlrtRSI;
  if (m != 0) {
    p = false;
    if (m == -4) {
      p = true;
    }

    if (!p) {
      if (m == -1010) {
        c_st.site = &sb_emlrtRSI;
        b_error(&c_st);
      } else {
        c_st.site = &tb_emlrtRSI;
        d_error(&c_st, m);
      }
    }

    p = true;
  } else {
    p = false;
  }

  if (p) {
    i7 = A->size[0] * A->size[1];
    emxEnsureCapacity(&st, (emxArray__common *)A, i7, (int32_T)sizeof(real_T),
                      &r_emlrtRTEI);
    m = A->size[1];
    for (i7 = 0; i7 < m; i7++) {
      loop_ub = A->size[0];
      for (i8 = 0; i8 < loop_ub; i8++) {
        A->data[i8 + A->size[0] * i7] = rtNaN;
      }
    }

    m = tau->size[0];
    i7 = tau->size[0];
    tau->size[0] = m;
    emxEnsureCapacity(&st, (emxArray__common *)tau, i7, (int32_T)sizeof(real_T),
                      &r_emlrtRTEI);
    for (i7 = 0; i7 < m; i7++) {
      tau->data[i7] = rtNaN;
    }

    b_st.site = &hc_emlrtRSI;
    c_st.site = &v_emlrtRSI;
    d_st.site = &wb_emlrtRSI;
    e_st.site = &xb_emlrtRSI;
    eml_signed_integer_colon(&e_st, n, jpvt);
  } else {
    i7 = jpvt->size[0] * jpvt->size[1];
    jpvt->size[0] = 1;
    jpvt->size[1] = jpvt_t->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)jpvt, i7, (int32_T)sizeof(int32_T),
                      &r_emlrtRTEI);
    m = jpvt_t->size[0];
    for (i7 = 0; i7 < m; i7++) {
      jpvt->data[jpvt->size[0] * i7] = (int32_T)jpvt_t->data[i7];
    }
  }

  emxFree_ptrdiff_t(&jpvt_t);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (xgeqp3.c) */
