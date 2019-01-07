/*
 * strategicPort_three_assets.c
 *
 * Code generation for function 'strategicPort_three_assets'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "strategicPort_three_assets.h"
#include "strategicPort_three_assets_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "abs.h"
#include "sum.h"
#include "exp.h"
#include "log.h"
#include "repmat.h"
#include "power.h"
#include "mldivide.h"
#include "squeeze.h"
#include "fprintf.h"
#include "strategicPort_three_assets_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 5, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtRSInfo b_emlrtRSI = { 6, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtRSInfo c_emlrtRSI = { 26, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtRSInfo d_emlrtRSI = { 28, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtRSInfo e_emlrtRSI = { 29, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtRSInfo f_emlrtRSI = { 43, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtRSInfo g_emlrtRSI = { 44, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtRSInfo h_emlrtRSI = { 47, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtRSInfo i_emlrtRSI = { 48, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtRSInfo j_emlrtRSI = { 49, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtRSInfo k_emlrtRSI = { 52, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtRSInfo l_emlrtRSI = { 56, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtRSInfo m_emlrtRSI = { 61, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtRSInfo n_emlrtRSI = { 62, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtRSInfo o_emlrtRSI = { 65, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtRSInfo p_emlrtRSI = { 69, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtRSInfo t_emlrtRSI = { 68, "eml_mtimes_helper",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"
};

static emlrtRSInfo u_emlrtRSI = { 76, "xgemm",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemm.m"
};

static emlrtRSInfo w_emlrtRSI = { 79, "colon",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo x_emlrtRSI = { 283, "colon",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo y_emlrtRSI = { 291, "colon",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo hb_emlrtRSI = { 21, "eml_mtimes_helper",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"
};

static emlrtRSInfo qc_emlrtRSI = { 18, "max",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\datafun\\max.m"
};

static emlrtRSInfo rc_emlrtRSI = { 15, "minOrMax",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"
};

static emlrtRSInfo sc_emlrtRSI = { 161, "minOrMax",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"
};

static emlrtRSInfo tc_emlrtRSI = { 163, "minOrMax",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"
};

static emlrtRSInfo uc_emlrtRSI = { 308, "minOrMax",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"
};

static emlrtRSInfo vc_emlrtRSI = { 281, "minOrMax",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"
};

static emlrtRSInfo fd_emlrtRSI = { 34, "mean",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m"
};

static emlrtRSInfo gd_emlrtRSI = { 60, "combine_vector_elements",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combine_vector_elements.m"
};

static emlrtRSInfo hd_emlrtRSI = { 35, "fprintf",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"
};

static emlrtRTEInfo emlrtRTEI = { 1, 16, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtRTEInfo b_emlrtRTEI = { 5, 1, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtRTEInfo c_emlrtRTEI = { 6, 1, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtRTEInfo d_emlrtRTEI = { 7, 1, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtRTEInfo e_emlrtRTEI = { 11, 1, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtRTEInfo f_emlrtRTEI = { 22, 1, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtRTEInfo g_emlrtRTEI = { 25, 5, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtRTEInfo h_emlrtRTEI = { 28, 9, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtRTEInfo i_emlrtRTEI = { 47, 9, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtRTEInfo j_emlrtRTEI = { 48, 9, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtRTEInfo k_emlrtRTEI = { 49, 9, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtRTEInfo x_emlrtRTEI = { 98, 23, "eml_mtimes_helper",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"
};

static emlrtRTEInfo y_emlrtRTEI = { 103, 23, "eml_mtimes_helper",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"
};

static emlrtBCInfo emlrtBCI = { -1, -1, 67, 11, "w_T",
  "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m",
  0 };

static emlrtECInfo emlrtECI = { -1, 62, 9, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtECInfo b_emlrtECI = { 2, 62, 34, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtBCInfo b_emlrtBCI = { -1, -1, 62, 53, "log_wealth",
  "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m",
  0 };

static emlrtECInfo c_emlrtECI = { -1, 56, 17, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtECInfo d_emlrtECI = { 2, 56, 22, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtECInfo e_emlrtECI = { -1, 44, 13, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtECInfo f_emlrtECI = { 1, 47, 13, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtBCInfo c_emlrtBCI = { -1, -1, 47, 40, "sim_x",
  "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m",
  0 };

static emlrtECInfo g_emlrtECI = { 2, 44, 38, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtBCInfo d_emlrtBCI = { -1, -1, 44, 57, "log_wealth",
  "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m",
  0 };

static emlrtECInfo h_emlrtECI = { -1, 29, 9, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtBCInfo e_emlrtBCI = { -1, -1, 29, 28, "log_wealth",
  "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m",
  0 };

static emlrtECInfo i_emlrtECI = { 1, 39, 19, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtBCInfo f_emlrtBCI = { -1, -1, 39, 47, "e_sim_br",
  "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m",
  0 };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 39, 31, "e_sim_r",
  "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m",
  0 };

static emlrtRTEInfo ab_emlrtRTEI = { 37, 5, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtBCInfo h_emlrtBCI = { 1, 10201, 17, 23, "portfolios",
  "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m",
  0 };

static emlrtECInfo j_emlrtECI = { 1, 25, 15, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m"
};

static emlrtBCInfo i_emlrtBCI = { -1, -1, 25, 43, "e_sim_br",
  "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m",
  0 };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 25, 27, "e_sim_r",
  "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m",
  0 };

static emlrtBCInfo k_emlrtBCI = { 1, 10201, 62, 47, "log_wealth",
  "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m",
  0 };

static emlrtDCInfo emlrtDCI = { 62, 47, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m",
  1 };

static emlrtBCInfo l_emlrtBCI = { 1, 10201, 53, 30, "portfolios",
  "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m",
  0 };

static emlrtBCInfo m_emlrtBCI = { 1, 10201, 44, 51, "log_wealth",
  "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m",
  0 };

static emlrtDCInfo b_emlrtDCI = { 44, 51, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m",
  1 };

static emlrtDCInfo c_emlrtDCI = { 29, 22, "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m",
  1 };

static emlrtBCInfo n_emlrtBCI = { 1, 10201, 29, 22, "log_wealth",
  "strategicPort_three_assets",
  "C:\\Users\\Bayesd\\msc-thesis\\msc-thesis\\current\\analysis\\portfolio\\strategicPort_three_assets.m",
  0 };

/* Function Declarations */
static int32_T asr_s32(int32_T u, uint32_T n);

/* Function Definitions */
static int32_T asr_s32(int32_T u, uint32_T n)
{
  int32_T y;
  if (u >= 0) {
    y = (int32_T)((uint32_T)u >> n);
  } else {
    y = -(int32_T)((uint32_T)-(u + 1) >> n) - 1;
  }

  return y;
}

void strategicPort_three_assets(c_strategicPort_three_assetsSta *SD, const
  emlrtStack *sp, const emxArray_real_T *sim_r, const emxArray_real_T *sim_br,
  const emxArray_real_T *sim_x, real_T b_gamma, emxArray_real_T *w_T)
{
  emxArray_real_T *e_sim_r;
  emxArray_real_T *beta;
  int32_T K;
  int32_T M;
  real_T aversion;
  real_T appetite;
  int32_T ixstart;
  int32_T ixstop;
  emxArray_real_T *e_sim_br;
  emxArray_real_T *U_fut;
  emxArray_real_T *U;
  int32_T w;
  int32_T stock_weight;
  real_T b_stock_weight;
  int32_T bond_weight;
  real_T b_bond_weight;
  real_T weights[3];
  real_T dv0[3];
  real_T s;
  real_T dv1[3];
  emxArray_real_T *log_wealth;
  int32_T t;
  emxArray_real_T *returns;
  emxArray_real_T *batch;
  emxArray_real_T *r0;
  emxArray_real_T *a;
  emxArray_int32_T *iindx;
  emxArray_real_T *b_e_sim_r;
  emxArray_real_T *b_e_sim_br;
  emxArray_real_T *r1;
  int32_T apnd;
  int32_T cindx;
  int32_T vlen;
  uint32_T unnamed_idx_0;
  real_T beta1;
  char_T TRANSB;
  char_T TRANSA;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  int32_T buffer;
  int32_T cdiff;
  int32_T tmp_data[10201];
  int32_T b_iindx[2];
  emxArray_real_T *X;
  emxArray_real_T *U_cond;
  emxArray_real_T *r2;
  emxArray_real_T *r3;
  emxArray_real_T *C;
  emxArray_real_T *b_C;
  emxArray_real_T *indx;
  emxArray_real_T *b_returns;
  emxArray_real_T *b_sim_x;
  emxArray_real_T *b_log_wealth;
  emxArray_real_T *c_e_sim_r;
  emxArray_real_T *c_e_sim_br;
  emxArray_real_T *r4;
  emxArray_real_T *r5;
  emxArray_real_T *portfolios;
  emxArray_real_T *c_log_wealth;
  int32_T period;
  int32_T b_period;
  int32_T d_log_wealth[2];
  int32_T iv0[2];
  int32_T c_iindx[2];
  uint32_T unnamed_idx_1;
  int32_T ix;
  int32_T iy;
  boolean_T overflow;
  int32_T itmp;
  boolean_T exitg2;
  int32_T c_returns[2];
  int32_T b_portfolios[2];
  int32_T e_log_wealth[2];
  int32_T iv1[2];
  int32_T d_iindx[2];
  real_T y[10201];
  boolean_T b0;
  boolean_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &e_sim_r, 2, &b_emlrtRTEI, true);
  emxInit_real_T(sp, &beta, 2, &j_emlrtRTEI, true);
  K = sim_r->size[1] - 1;
  M = sim_r->size[0];
  aversion = 1.0 / (1.0 - b_gamma);
  appetite = 1.0 / aversion;
  ixstart = e_sim_r->size[0] * e_sim_r->size[1];
  e_sim_r->size[0] = sim_r->size[0];
  e_sim_r->size[1] = sim_r->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)e_sim_r, ixstart, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  ixstop = sim_r->size[0] * sim_r->size[1];
  for (ixstart = 0; ixstart < ixstop; ixstart++) {
    e_sim_r->data[ixstart] = sim_r->data[ixstart];
  }

  emxInit_real_T(sp, &e_sim_br, 2, &c_emlrtRTEI, true);
  st.site = &emlrtRSI;
  b_exp(&st, e_sim_r);
  ixstart = e_sim_br->size[0] * e_sim_br->size[1];
  e_sim_br->size[0] = sim_br->size[0];
  e_sim_br->size[1] = sim_br->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)e_sim_br, ixstart, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  ixstop = sim_br->size[0] * sim_br->size[1];
  for (ixstart = 0; ixstart < ixstop; ixstart++) {
    e_sim_br->data[ixstart] = sim_br->data[ixstart];
  }

  emxInit_real_T1(sp, &U_fut, 1, &d_emlrtRTEI, true);
  st.site = &b_emlrtRSI;
  b_exp(&st, e_sim_br);
  ixstart = U_fut->size[0];
  U_fut->size[0] = sim_r->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)U_fut, ixstart, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  ixstop = sim_r->size[0];
  for (ixstart = 0; ixstart < ixstop; ixstart++) {
    U_fut->data[ixstart] = 1.0;
  }

  ixstart = w_T->size[0] * w_T->size[1];
  w_T->size[0] = 3;
  w_T->size[1] = sim_r->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)w_T, ixstart, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  ixstop = 3 * sim_r->size[1];
  for (ixstart = 0; ixstart < ixstop; ixstart++) {
    w_T->data[ixstart] = 1.0;
  }

  memset(&SD->f0.portfolios[0], 0, 30603U * sizeof(real_T));
  emxInit_real_T(sp, &U, 2, &e_emlrtRTEI, true);
  ixstart = U->size[0] * U->size[1];
  U->size[0] = sim_r->size[0];
  U->size[1] = 10201;
  emxEnsureCapacity(sp, (emxArray__common *)U, ixstart, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  ixstop = sim_r->size[0] * 10201;
  for (ixstart = 0; ixstart < ixstop; ixstart++) {
    U->data[ixstart] = 1.0;
  }

  /*  create portfolios for grid search */
  w = 1;
  stock_weight = 0;
  while (stock_weight < 101) {
    b_stock_weight = (real_T)stock_weight * 0.01;
    bond_weight = 0;
    while (bond_weight < 101) {
      b_bond_weight = (real_T)bond_weight * 0.01;
      weights[0] = b_stock_weight;
      weights[1] = b_bond_weight;
      weights[2] = (1.0 - b_stock_weight) - b_bond_weight;
      b_abs(weights, dv0);
      s = sum(dv0);
      b_abs(weights, dv1);
      if (!((w >= 1) && (w <= 10201))) {
        emlrtDynamicBoundsCheckR2012b(w, 1, 10201, &h_emlrtBCI, sp);
      }

      for (ixstart = 0; ixstart < 3; ixstart++) {
        SD->f0.portfolios[ixstart + 3 * (w - 1)] = dv1[ixstart] / s;
      }

      w++;
      bond_weight++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    stock_weight++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxInit_real_T2(sp, &log_wealth, 3, &f_emlrtRTEI, true);

  /*  compute wealths for each period */
  ixstart = log_wealth->size[0] * log_wealth->size[1] * log_wealth->size[2];
  log_wealth->size[0] = sim_r->size[0];
  log_wealth->size[1] = 10201;
  log_wealth->size[2] = sim_r->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)log_wealth, ixstart, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  ixstop = sim_r->size[0] * 10201 * sim_r->size[1];
  for (ixstart = 0; ixstart < ixstop; ixstart++) {
    log_wealth->data[ixstart] = 0.0;
  }

  t = 0;
  emxInit_real_T(sp, &returns, 2, &g_emlrtRTEI, true);
  emxInit_real_T(sp, &batch, 2, &h_emlrtRTEI, true);
  emxInit_real_T(sp, &r0, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &a, 2, &emlrtRTEI, true);
  emxInit_int32_T(sp, &iindx, 1, &emlrtRTEI, true);
  emxInit_real_T1(sp, &b_e_sim_r, 1, &emlrtRTEI, true);
  emxInit_real_T1(sp, &b_e_sim_br, 1, &emlrtRTEI, true);
  emxInit_real_T1(sp, &r1, 1, &emlrtRTEI, true);
  while (t <= K) {
    ixstart = e_sim_r->size[1];
    apnd = t + 1;
    if (!((apnd >= 1) && (apnd <= ixstart))) {
      emlrtDynamicBoundsCheckR2012b(apnd, 1, ixstart, &j_emlrtBCI, sp);
    }

    ixstart = e_sim_br->size[1];
    apnd = t + 1;
    if (!((apnd >= 1) && (apnd <= ixstart))) {
      emlrtDynamicBoundsCheckR2012b(apnd, 1, ixstart, &i_emlrtBCI, sp);
    }

    ixstart = e_sim_r->size[0];
    apnd = e_sim_br->size[0];
    if (ixstart != apnd) {
      emlrtDimSizeEqCheckR2012b(ixstart, apnd, &j_emlrtECI, sp);
    }

    ixstart = e_sim_r->size[0];
    if (ixstart != M) {
      emlrtDimSizeEqCheckR2012b(ixstart, M, &j_emlrtECI, sp);
    }

    ixstop = e_sim_r->size[0];
    cindx = e_sim_br->size[0];
    vlen = e_sim_r->size[0];
    ixstart = b_e_sim_r->size[0];
    b_e_sim_r->size[0] = vlen;
    emxEnsureCapacity(sp, (emxArray__common *)b_e_sim_r, ixstart, (int32_T)
                      sizeof(real_T), &emlrtRTEI);
    for (ixstart = 0; ixstart < vlen; ixstart++) {
      b_e_sim_r->data[ixstart] = e_sim_r->data[ixstart + e_sim_r->size[0] * t];
    }

    vlen = e_sim_br->size[0];
    ixstart = b_e_sim_br->size[0];
    b_e_sim_br->size[0] = vlen;
    emxEnsureCapacity(sp, (emxArray__common *)b_e_sim_br, ixstart, (int32_T)
                      sizeof(real_T), &emlrtRTEI);
    for (ixstart = 0; ixstart < vlen; ixstart++) {
      b_e_sim_br->data[ixstart] = e_sim_br->data[ixstart + e_sim_br->size[0] * t];
    }

    ixstart = r1->size[0];
    r1->size[0] = M;
    emxEnsureCapacity(sp, (emxArray__common *)r1, ixstart, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    for (ixstart = 0; ixstart < M; ixstart++) {
      r1->data[ixstart] = 1.0;
    }

    ixstart = returns->size[0] * returns->size[1];
    returns->size[0] = ixstop;
    returns->size[1] = 3;
    emxEnsureCapacity(sp, (emxArray__common *)returns, ixstart, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    for (ixstart = 0; ixstart < ixstop; ixstart++) {
      returns->data[ixstart] = b_e_sim_r->data[ixstart];
    }

    for (ixstart = 0; ixstart < cindx; ixstart++) {
      returns->data[ixstart + returns->size[0]] = b_e_sim_br->data[ixstart];
    }

    for (ixstart = 0; ixstart < M; ixstart++) {
      returns->data[ixstart + (returns->size[0] << 1)] = r1->data[ixstart];
    }

    st.site = &c_emlrtRSI;
    unnamed_idx_0 = (uint32_T)returns->size[0];
    ixstart = beta->size[0] * beta->size[1];
    beta->size[0] = (int32_T)unnamed_idx_0;
    beta->size[1] = 10201;
    beta->size[1] = 10201;
    emxEnsureCapacity(&st, (emxArray__common *)beta, ixstart, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    for (ixstart = 0; ixstart < 10201; ixstart++) {
      ixstop = beta->size[0];
      for (apnd = 0; apnd < ixstop; apnd++) {
        beta->data[apnd + beta->size[0] * ixstart] = 0.0;
      }
    }

    b_st.site = &t_emlrtRSI;
    if (returns->size[0] < 1) {
    } else {
      c_st.site = &u_emlrtRSI;
      s = 1.0;
      beta1 = 0.0;
      TRANSB = 'N';
      TRANSA = 'N';
      m_t = (ptrdiff_t)returns->size[0];
      n_t = (ptrdiff_t)10201;
      k_t = (ptrdiff_t)3;
      lda_t = (ptrdiff_t)returns->size[0];
      ldb_t = (ptrdiff_t)3;
      ldc_t = (ptrdiff_t)returns->size[0];
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &s, &returns->data[0], &lda_t,
            &SD->f0.portfolios[0], &ldb_t, &beta1, &beta->data[0], &ldc_t);
    }

    buffer = 0;
    while (buffer < 35) {
      ixstop = (int32_T)muDoubleScalarMin(300.0 * (1.0 + (real_T)buffer),
        10201.0);
      st.site = &d_emlrtRSI;
      cindx = 300 * buffer + 1;
      b_st.site = &v_emlrtRSI;
      c_st.site = &w_emlrtRSI;
      if (ixstop < cindx) {
        cdiff = 0;
        apnd = ixstop;
      } else {
        vlen = (int32_T)muDoubleScalarFloor((real_T)(ixstop - cindx) + 0.5);
        apnd = cindx + vlen;
        cdiff = apnd - ixstop;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)
            muIntScalarMax_sint32(cindx, ixstop)) {
          vlen++;
          apnd = ixstop;
        } else if (cdiff > 0) {
          apnd = (cindx + vlen) - 1;
        } else {
          vlen++;
        }

        if (vlen >= 0) {
          cdiff = vlen;
        } else {
          cdiff = 0;
        }
      }

      d_st.site = &x_emlrtRSI;
      ixstart = batch->size[0] * batch->size[1];
      batch->size[0] = 1;
      batch->size[1] = cdiff;
      emxEnsureCapacity(&c_st, (emxArray__common *)batch, ixstart, (int32_T)
                        sizeof(real_T), &emlrtRTEI);
      if (cdiff > 0) {
        batch->data[0] = cindx;
        if (cdiff > 1) {
          batch->data[cdiff - 1] = apnd;
          ixstart = cdiff - 1;
          vlen = asr_s32(ixstart, 1U);
          d_st.site = &y_emlrtRSI;
          for (ixstop = 1; ixstop < vlen; ixstop++) {
            batch->data[ixstop] = cindx + ixstop;
            batch->data[(cdiff - ixstop) - 1] = apnd - ixstop;
          }

          if (vlen << 1 == cdiff - 1) {
            batch->data[vlen] = (real_T)(cindx + apnd) / 2.0;
          } else {
            batch->data[vlen] = cindx + vlen;
            batch->data[vlen + 1] = apnd - vlen;
          }
        }
      }

      ixstop = log_wealth->size[0];
      ixstart = iindx->size[0];
      iindx->size[0] = ixstop;
      emxEnsureCapacity(sp, (emxArray__common *)iindx, ixstart, (int32_T)sizeof
                        (int32_T), &emlrtRTEI);
      for (ixstart = 0; ixstart < ixstop; ixstart++) {
        iindx->data[ixstart] = ixstart;
      }

      vlen = batch->size[1];
      ixstop = batch->size[1];
      for (ixstart = 0; ixstart < ixstop; ixstart++) {
        s = batch->data[batch->size[0] * ixstart];
        if (s != (int32_T)muDoubleScalarFloor(s)) {
          emlrtIntegerCheckR2012b(s, &c_emlrtDCI, sp);
        }

        apnd = (int32_T)s;
        if (!((apnd >= 1) && (apnd <= 10201))) {
          emlrtDynamicBoundsCheckR2012b(apnd, 1, 10201, &n_emlrtBCI, sp);
        }

        tmp_data[ixstart] = apnd - 1;
      }

      ixstart = log_wealth->size[2];
      apnd = t + 1;
      if (!((apnd >= 1) && (apnd <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(apnd, 1, ixstart, &e_emlrtBCI, sp);
      }

      ixstop = beta->size[0];
      ixstart = r0->size[0] * r0->size[1];
      r0->size[0] = ixstop;
      r0->size[1] = batch->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)r0, ixstart, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      cindx = batch->size[1];
      for (ixstart = 0; ixstart < cindx; ixstart++) {
        for (apnd = 0; apnd < ixstop; apnd++) {
          r0->data[apnd + r0->size[0] * ixstart] = beta->data[apnd + beta->size
            [0] * ((int32_T)batch->data[batch->size[0] * ixstart] - 1)];
        }
      }

      st.site = &e_emlrtRSI;
      b_log(&st, r0);
      ixstart = a->size[0] * a->size[1];
      a->size[0] = r0->size[0];
      a->size[1] = r0->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)a, ixstart, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      ixstop = r0->size[0] * r0->size[1];
      for (ixstart = 0; ixstart < ixstop; ixstart++) {
        a->data[ixstart] = appetite * r0->data[ixstart];
      }

      st.site = &e_emlrtRSI;
      b_exp(&st, a);
      ixstart = r0->size[0] * r0->size[1];
      r0->size[0] = a->size[0];
      r0->size[1] = a->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)r0, ixstart, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      ixstop = a->size[0] * a->size[1];
      for (ixstart = 0; ixstart < ixstop; ixstart++) {
        r0->data[ixstart] = a->data[ixstart];
      }

      b_iindx[0] = iindx->size[0];
      b_iindx[1] = vlen;
      emlrtSubAssignSizeCheckR2012b(b_iindx, 2, *(int32_T (*)[2])r0->size, 2,
        &h_emlrtECI, sp);
      ixstop = r0->size[1];
      for (ixstart = 0; ixstart < ixstop; ixstart++) {
        cindx = r0->size[0];
        for (apnd = 0; apnd < cindx; apnd++) {
          log_wealth->data[(iindx->data[apnd] + log_wealth->size[0] *
                            tmp_data[ixstart]) + log_wealth->size[0] *
            log_wealth->size[1] * t] = r0->data[apnd + r0->size[0] * ixstart];
        }
      }

      buffer++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    t++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&r1);
  emxFree_real_T(&b_e_sim_br);
  emxFree_real_T(&b_e_sim_r);
  t = 0;
  emxInit_real_T(sp, &X, 2, &i_emlrtRTEI, true);
  emxInit_real_T(sp, &U_cond, 2, &k_emlrtRTEI, true);
  emxInit_real_T1(sp, &r2, 1, &emlrtRTEI, true);
  emxInit_real_T(sp, &r3, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &C, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &b_C, 2, &emlrtRTEI, true);
  emxInit_real_T1(sp, &indx, 1, &emlrtRTEI, true);
  emxInit_real_T(sp, &b_returns, 2, &emlrtRTEI, true);
  emxInit_real_T2(sp, &b_sim_x, 3, &emlrtRTEI, true);
  emxInit_real_T(sp, &b_log_wealth, 2, &emlrtRTEI, true);
  emxInit_real_T1(sp, &c_e_sim_r, 1, &emlrtRTEI, true);
  emxInit_real_T1(sp, &c_e_sim_br, 1, &emlrtRTEI, true);
  emxInit_real_T1(sp, &r4, 1, &emlrtRTEI, true);
  emxInit_real_T1(sp, &r5, 1, &emlrtRTEI, true);
  emxInit_real_T(sp, &portfolios, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &c_log_wealth, 2, &emlrtRTEI, true);
  while (t <= K) {
    emlrtForLoopVectorCheckR2012b((1.0 + (real_T)t) - 1.0, -1.0, 1.0,
      mxDOUBLE_CLASS, t, &ab_emlrtRTEI, sp);
    period = 0;
    while (period <= t - 1) {
      b_period = t - period;

      /*  set returns */
      ixstart = e_sim_r->size[1];
      apnd = 1 + t;
      if (!(apnd <= ixstart)) {
        emlrtDynamicBoundsCheckR2012b(apnd, 1, ixstart, &g_emlrtBCI, sp);
      }

      ixstart = e_sim_br->size[1];
      apnd = 1 + t;
      if (!(apnd <= ixstart)) {
        emlrtDynamicBoundsCheckR2012b(apnd, 1, ixstart, &f_emlrtBCI, sp);
      }

      ixstart = e_sim_r->size[0];
      apnd = e_sim_br->size[0];
      if (ixstart != apnd) {
        emlrtDimSizeEqCheckR2012b(ixstart, apnd, &i_emlrtECI, sp);
      }

      ixstart = e_sim_r->size[0];
      if (ixstart != M) {
        emlrtDimSizeEqCheckR2012b(ixstart, M, &i_emlrtECI, sp);
      }

      ixstop = e_sim_r->size[0];
      cindx = e_sim_br->size[0];
      vlen = e_sim_r->size[0];
      ixstart = c_e_sim_r->size[0];
      c_e_sim_r->size[0] = vlen;
      emxEnsureCapacity(sp, (emxArray__common *)c_e_sim_r, ixstart, (int32_T)
                        sizeof(real_T), &emlrtRTEI);
      for (ixstart = 0; ixstart < vlen; ixstart++) {
        c_e_sim_r->data[ixstart] = e_sim_r->data[ixstart + e_sim_r->size[0] * t];
      }

      vlen = e_sim_br->size[0];
      ixstart = c_e_sim_br->size[0];
      c_e_sim_br->size[0] = vlen;
      emxEnsureCapacity(sp, (emxArray__common *)c_e_sim_br, ixstart, (int32_T)
                        sizeof(real_T), &emlrtRTEI);
      for (ixstart = 0; ixstart < vlen; ixstart++) {
        c_e_sim_br->data[ixstart] = e_sim_br->data[ixstart + e_sim_br->size[0] *
          t];
      }

      ixstart = r4->size[0];
      r4->size[0] = M;
      emxEnsureCapacity(sp, (emxArray__common *)r4, ixstart, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      for (ixstart = 0; ixstart < M; ixstart++) {
        r4->data[ixstart] = 1.0;
      }

      ixstart = returns->size[0] * returns->size[1];
      returns->size[0] = ixstop;
      returns->size[1] = 3;
      emxEnsureCapacity(sp, (emxArray__common *)returns, ixstart, (int32_T)
                        sizeof(real_T), &emlrtRTEI);
      for (ixstart = 0; ixstart < ixstop; ixstart++) {
        returns->data[ixstart] = c_e_sim_r->data[ixstart];
      }

      for (ixstart = 0; ixstart < cindx; ixstart++) {
        returns->data[ixstart + returns->size[0]] = c_e_sim_br->data[ixstart];
      }

      for (ixstart = 0; ixstart < M; ixstart++) {
        returns->data[ixstart + (returns->size[0] << 1)] = r4->data[ixstart];
      }

      /*  compute wealth from portfolios */
      buffer = 0;
      while (buffer < 35) {
        ixstop = (int32_T)muDoubleScalarMin(300.0 * (1.0 + (real_T)buffer),
          10201.0);
        st.site = &f_emlrtRSI;
        cindx = 300 * buffer + 1;
        b_st.site = &v_emlrtRSI;
        c_st.site = &w_emlrtRSI;
        if (ixstop < cindx) {
          cdiff = 0;
          apnd = ixstop;
        } else {
          vlen = (int32_T)muDoubleScalarFloor((real_T)(ixstop - cindx) + 0.5);
          apnd = cindx + vlen;
          cdiff = apnd - ixstop;
          if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)
              muIntScalarMax_sint32(cindx, ixstop)) {
            vlen++;
            apnd = ixstop;
          } else if (cdiff > 0) {
            apnd = (cindx + vlen) - 1;
          } else {
            vlen++;
          }

          if (vlen >= 0) {
            cdiff = vlen;
          } else {
            cdiff = 0;
          }
        }

        d_st.site = &x_emlrtRSI;
        ixstart = batch->size[0] * batch->size[1];
        batch->size[0] = 1;
        batch->size[1] = cdiff;
        emxEnsureCapacity(&c_st, (emxArray__common *)batch, ixstart, (int32_T)
                          sizeof(real_T), &emlrtRTEI);
        if (cdiff > 0) {
          batch->data[0] = cindx;
          if (cdiff > 1) {
            batch->data[cdiff - 1] = apnd;
            ixstart = cdiff - 1;
            vlen = asr_s32(ixstart, 1U);
            d_st.site = &y_emlrtRSI;
            for (ixstop = 1; ixstop < vlen; ixstop++) {
              batch->data[ixstop] = cindx + ixstop;
              batch->data[(cdiff - ixstop) - 1] = apnd - ixstop;
            }

            if (vlen << 1 == cdiff - 1) {
              batch->data[vlen] = (real_T)(cindx + apnd) / 2.0;
            } else {
              batch->data[vlen] = cindx + vlen;
              batch->data[vlen + 1] = apnd - vlen;
            }
          }
        }

        ixstop = log_wealth->size[0];
        ixstart = log_wealth->size[2];
        if (!((b_period + 1 >= 1) && (b_period + 1 <= ixstart))) {
          emlrtDynamicBoundsCheckR2012b(b_period + 1, 1, ixstart, &d_emlrtBCI,
            sp);
        }

        vlen = b_period + 1;
        ixstart = r0->size[0] * r0->size[1];
        r0->size[0] = ixstop;
        r0->size[1] = batch->size[1];
        emxEnsureCapacity(sp, (emxArray__common *)r0, ixstart, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        cindx = batch->size[1];
        for (ixstart = 0; ixstart < cindx; ixstart++) {
          for (apnd = 0; apnd < ixstop; apnd++) {
            s = batch->data[batch->size[0] * ixstart];
            if (s != (int32_T)muDoubleScalarFloor(s)) {
              emlrtIntegerCheckR2012b(s, &b_emlrtDCI, sp);
            }

            cdiff = (int32_T)s;
            if (!((cdiff >= 1) && (cdiff <= 10201))) {
              emlrtDynamicBoundsCheckR2012b(cdiff, 1, 10201, &m_emlrtBCI, sp);
            }

            r0->data[apnd + r0->size[0] * ixstart] = log_wealth->data[(apnd +
              log_wealth->size[0] * (cdiff - 1)) + log_wealth->size[0] *
              log_wealth->size[1] * (vlen - 1)];
          }
        }

        st.site = &g_emlrtRSI;
        repmat(&st, U_fut, batch->size[1], r3);
        ixstop = log_wealth->size[0];
        ixstart = c_log_wealth->size[0] * c_log_wealth->size[1];
        c_log_wealth->size[0] = ixstop;
        c_log_wealth->size[1] = batch->size[1];
        emxEnsureCapacity(sp, (emxArray__common *)c_log_wealth, ixstart,
                          (int32_T)sizeof(real_T), &emlrtRTEI);
        cindx = batch->size[1];
        for (ixstart = 0; ixstart < cindx; ixstart++) {
          for (apnd = 0; apnd < ixstop; apnd++) {
            c_log_wealth->data[apnd + c_log_wealth->size[0] * ixstart] =
              log_wealth->data[(apnd + log_wealth->size[0] * ((int32_T)
              batch->data[batch->size[0] * ixstart] - 1)) + log_wealth->size[0] *
              log_wealth->size[1] * b_period];
          }
        }

        for (ixstart = 0; ixstart < 2; ixstart++) {
          d_log_wealth[ixstart] = c_log_wealth->size[ixstart];
        }

        for (ixstart = 0; ixstart < 2; ixstart++) {
          iv0[ixstart] = r3->size[ixstart];
        }

        if ((d_log_wealth[0] != iv0[0]) || (d_log_wealth[1] != iv0[1])) {
          emlrtSizeEqCheckNDR2012b(&d_log_wealth[0], &iv0[0], &g_emlrtECI, sp);
        }

        ixstop = U->size[0];
        ixstart = iindx->size[0];
        iindx->size[0] = ixstop;
        emxEnsureCapacity(sp, (emxArray__common *)iindx, ixstart, (int32_T)
                          sizeof(int32_T), &emlrtRTEI);
        for (ixstart = 0; ixstart < ixstop; ixstart++) {
          iindx->data[ixstart] = ixstart;
        }

        vlen = batch->size[1];
        ixstop = batch->size[1];
        for (ixstart = 0; ixstart < ixstop; ixstart++) {
          tmp_data[ixstart] = (int32_T)batch->data[batch->size[0] * ixstart] - 1;
        }

        ixstart = r0->size[0] * r0->size[1];
        emxEnsureCapacity(sp, (emxArray__common *)r0, ixstart, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        ixstart = r0->size[0];
        apnd = r0->size[1];
        ixstop = ixstart * apnd;
        for (ixstart = 0; ixstart < ixstop; ixstart++) {
          r0->data[ixstart] = aversion * (r0->data[ixstart] * r3->data[ixstart]);
        }

        c_iindx[0] = iindx->size[0];
        c_iindx[1] = vlen;
        emlrtSubAssignSizeCheckR2012b(c_iindx, 2, *(int32_T (*)[2])r0->size, 2,
          &e_emlrtECI, sp);
        ixstop = r0->size[1];
        for (ixstart = 0; ixstart < ixstop; ixstart++) {
          cindx = r0->size[0];
          for (apnd = 0; apnd < cindx; apnd++) {
            U->data[iindx->data[apnd] + U->size[0] * tmp_data[ixstart]] =
              r0->data[apnd + r0->size[0] * ixstart];
          }
        }

        buffer++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      /*  compute utility for weight pairs */
      ixstop = sim_x->size[0];
      cindx = sim_x->size[2];
      ixstart = sim_x->size[1];
      if (!((b_period >= 1) && (b_period <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(b_period, 1, ixstart, &c_emlrtBCI, sp);
      }

      ixstart = b_sim_x->size[0] * b_sim_x->size[1] * b_sim_x->size[2];
      b_sim_x->size[0] = ixstop;
      b_sim_x->size[1] = 1;
      b_sim_x->size[2] = cindx;
      emxEnsureCapacity(sp, (emxArray__common *)b_sim_x, ixstart, (int32_T)
                        sizeof(real_T), &emlrtRTEI);
      for (ixstart = 0; ixstart < cindx; ixstart++) {
        for (apnd = 0; apnd < ixstop; apnd++) {
          b_sim_x->data[apnd + b_sim_x->size[0] * b_sim_x->size[1] * ixstart] =
            sim_x->data[(apnd + sim_x->size[0] * (b_period - 1)) + sim_x->size[0]
            * sim_x->size[1] * ixstart];
        }
      }

      st.site = &h_emlrtRSI;
      squeeze(&st, b_sim_x, a);
      ixstart = a->size[1];
      if (M != ixstart) {
        emlrtDimSizeEqCheckR2012b(M, ixstart, &f_emlrtECI, sp);
      }

      ixstart = r5->size[0];
      r5->size[0] = M;
      emxEnsureCapacity(sp, (emxArray__common *)r5, ixstart, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      for (ixstart = 0; ixstart < M; ixstart++) {
        r5->data[ixstart] = 1.0;
      }

      ixstart = X->size[0] * X->size[1];
      X->size[0] = M;
      X->size[1] = 1 + a->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)X, ixstart, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      for (ixstart = 0; ixstart < M; ixstart++) {
        X->data[ixstart] = r5->data[ixstart];
      }

      ixstop = a->size[0];
      for (ixstart = 0; ixstart < ixstop; ixstart++) {
        cindx = a->size[1];
        for (apnd = 0; apnd < cindx; apnd++) {
          X->data[apnd + X->size[0] * (ixstart + 1)] = a->data[ixstart + a->
            size[0] * apnd];
        }
      }

      st.site = &i_emlrtRSI;
      ixstart = a->size[0] * a->size[1];
      a->size[0] = X->size[1];
      a->size[1] = X->size[0];
      emxEnsureCapacity(&st, (emxArray__common *)a, ixstart, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      ixstop = X->size[0];
      for (ixstart = 0; ixstart < ixstop; ixstart++) {
        cindx = X->size[1];
        for (apnd = 0; apnd < cindx; apnd++) {
          a->data[apnd + a->size[0] * ixstart] = X->data[ixstart + X->size[0] *
            apnd];
        }
      }

      b_st.site = &hb_emlrtRSI;
      if (!(a->size[1] == X->size[0])) {
        if (((a->size[0] == 1) && (a->size[1] == 1)) || ((X->size[0] == 1) &&
             (X->size[1] == 1))) {
          emlrtErrorWithMessageIdR2012b(&b_st, &x_emlrtRTEI,
            "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
        } else {
          emlrtErrorWithMessageIdR2012b(&b_st, &y_emlrtRTEI,
            "Coder:MATLAB:innerdim", 0);
        }
      }

      if ((a->size[1] == 1) || (X->size[0] == 1)) {
        ixstart = C->size[0] * C->size[1];
        C->size[0] = a->size[0];
        C->size[1] = X->size[1];
        emxEnsureCapacity(&st, (emxArray__common *)C, ixstart, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        ixstop = a->size[0];
        for (ixstart = 0; ixstart < ixstop; ixstart++) {
          cindx = X->size[1];
          for (apnd = 0; apnd < cindx; apnd++) {
            C->data[ixstart + C->size[0] * apnd] = 0.0;
            vlen = a->size[1];
            for (cdiff = 0; cdiff < vlen; cdiff++) {
              C->data[ixstart + C->size[0] * apnd] += a->data[ixstart + a->size
                [0] * cdiff] * X->data[cdiff + X->size[0] * apnd];
            }
          }
        }
      } else {
        unnamed_idx_0 = (uint32_T)a->size[0];
        unnamed_idx_1 = (uint32_T)X->size[1];
        ixstart = C->size[0] * C->size[1];
        C->size[0] = (int32_T)unnamed_idx_0;
        C->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity(&st, (emxArray__common *)C, ixstart, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        ixstop = C->size[1];
        for (ixstart = 0; ixstart < ixstop; ixstart++) {
          cindx = C->size[0];
          for (apnd = 0; apnd < cindx; apnd++) {
            C->data[apnd + C->size[0] * ixstart] = 0.0;
          }
        }

        b_st.site = &t_emlrtRSI;
        if (a->size[1] < 1) {
        } else {
          c_st.site = &u_emlrtRSI;
          s = 1.0;
          beta1 = 0.0;
          TRANSB = 'N';
          TRANSA = 'N';
          m_t = (ptrdiff_t)a->size[0];
          n_t = (ptrdiff_t)X->size[1];
          k_t = (ptrdiff_t)a->size[1];
          lda_t = (ptrdiff_t)a->size[0];
          ldb_t = (ptrdiff_t)a->size[1];
          ldc_t = (ptrdiff_t)a->size[0];
          dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &s, &a->data[0], &lda_t,
                &X->data[0], &ldb_t, &beta1, &C->data[0], &ldc_t);
        }
      }

      st.site = &i_emlrtRSI;
      ixstart = a->size[0] * a->size[1];
      a->size[0] = X->size[1];
      a->size[1] = X->size[0];
      emxEnsureCapacity(&st, (emxArray__common *)a, ixstart, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      ixstop = X->size[0];
      for (ixstart = 0; ixstart < ixstop; ixstart++) {
        cindx = X->size[1];
        for (apnd = 0; apnd < cindx; apnd++) {
          a->data[apnd + a->size[0] * ixstart] = X->data[ixstart + X->size[0] *
            apnd];
        }
      }

      b_st.site = &hb_emlrtRSI;
      if (!(a->size[1] == U->size[0])) {
        if ((a->size[0] == 1) && (a->size[1] == 1)) {
          emlrtErrorWithMessageIdR2012b(&b_st, &x_emlrtRTEI,
            "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
        } else {
          emlrtErrorWithMessageIdR2012b(&b_st, &y_emlrtRTEI,
            "Coder:MATLAB:innerdim", 0);
        }
      }

      if ((a->size[1] == 1) || (U->size[0] == 1)) {
        ixstart = b_C->size[0] * b_C->size[1];
        b_C->size[0] = a->size[0];
        b_C->size[1] = 10201;
        emxEnsureCapacity(&st, (emxArray__common *)b_C, ixstart, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        ixstop = a->size[0];
        for (ixstart = 0; ixstart < ixstop; ixstart++) {
          for (apnd = 0; apnd < 10201; apnd++) {
            b_C->data[ixstart + b_C->size[0] * apnd] = 0.0;
            cindx = a->size[1];
            for (cdiff = 0; cdiff < cindx; cdiff++) {
              b_C->data[ixstart + b_C->size[0] * apnd] += a->data[ixstart +
                a->size[0] * cdiff] * U->data[cdiff + U->size[0] * apnd];
            }
          }
        }
      } else {
        unnamed_idx_0 = (uint32_T)a->size[0];
        ixstart = b_C->size[0] * b_C->size[1];
        b_C->size[0] = (int32_T)unnamed_idx_0;
        b_C->size[1] = 10201;
        b_C->size[1] = 10201;
        emxEnsureCapacity(&st, (emxArray__common *)b_C, ixstart, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        for (ixstart = 0; ixstart < 10201; ixstart++) {
          ixstop = b_C->size[0];
          for (apnd = 0; apnd < ixstop; apnd++) {
            b_C->data[apnd + b_C->size[0] * ixstart] = 0.0;
          }
        }

        b_st.site = &t_emlrtRSI;
        if (a->size[1] < 1) {
        } else {
          c_st.site = &u_emlrtRSI;
          s = 1.0;
          beta1 = 0.0;
          TRANSB = 'N';
          TRANSA = 'N';
          m_t = (ptrdiff_t)a->size[0];
          n_t = (ptrdiff_t)10201;
          k_t = (ptrdiff_t)a->size[1];
          lda_t = (ptrdiff_t)a->size[0];
          ldb_t = (ptrdiff_t)a->size[1];
          ldc_t = (ptrdiff_t)a->size[0];
          dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &s, &a->data[0], &lda_t,
                &U->data[0], &ldb_t, &beta1, &b_C->data[0], &ldc_t);
        }
      }

      ixstart = beta->size[0] * beta->size[1];
      beta->size[0] = b_C->size[0];
      beta->size[1] = 10201;
      emxEnsureCapacity(sp, (emxArray__common *)beta, ixstart, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      ixstop = b_C->size[0] * b_C->size[1];
      for (ixstart = 0; ixstart < ixstop; ixstart++) {
        beta->data[ixstart] = b_C->data[ixstart];
      }

      st.site = &i_emlrtRSI;
      mldivide(&st, C, beta);
      st.site = &j_emlrtRSI;
      b_st.site = &hb_emlrtRSI;
      if (!(X->size[1] == beta->size[0])) {
        if ((X->size[0] == 1) && (X->size[1] == 1)) {
          emlrtErrorWithMessageIdR2012b(&b_st, &x_emlrtRTEI,
            "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
        } else {
          emlrtErrorWithMessageIdR2012b(&b_st, &y_emlrtRTEI,
            "Coder:MATLAB:innerdim", 0);
        }
      }

      if ((X->size[1] == 1) || (beta->size[0] == 1)) {
        ixstart = U_cond->size[0] * U_cond->size[1];
        U_cond->size[0] = X->size[0];
        U_cond->size[1] = 10201;
        emxEnsureCapacity(&st, (emxArray__common *)U_cond, ixstart, (int32_T)
                          sizeof(real_T), &emlrtRTEI);
        ixstop = X->size[0];
        for (ixstart = 0; ixstart < ixstop; ixstart++) {
          for (apnd = 0; apnd < 10201; apnd++) {
            U_cond->data[ixstart + U_cond->size[0] * apnd] = 0.0;
            cindx = X->size[1];
            for (cdiff = 0; cdiff < cindx; cdiff++) {
              U_cond->data[ixstart + U_cond->size[0] * apnd] += X->data[ixstart
                + X->size[0] * cdiff] * beta->data[cdiff + beta->size[0] * apnd];
            }
          }
        }
      } else {
        unnamed_idx_0 = (uint32_T)X->size[0];
        ixstart = U_cond->size[0] * U_cond->size[1];
        U_cond->size[0] = (int32_T)unnamed_idx_0;
        U_cond->size[1] = 10201;
        U_cond->size[1] = 10201;
        emxEnsureCapacity(&st, (emxArray__common *)U_cond, ixstart, (int32_T)
                          sizeof(real_T), &emlrtRTEI);
        for (ixstart = 0; ixstart < 10201; ixstart++) {
          ixstop = U_cond->size[0];
          for (apnd = 0; apnd < ixstop; apnd++) {
            U_cond->data[apnd + U_cond->size[0] * ixstart] = 0.0;
          }
        }

        b_st.site = &t_emlrtRSI;
        if (X->size[0] < 1) {
        } else {
          c_st.site = &u_emlrtRSI;
          s = 1.0;
          beta1 = 0.0;
          TRANSB = 'N';
          TRANSA = 'N';
          m_t = (ptrdiff_t)X->size[0];
          n_t = (ptrdiff_t)10201;
          k_t = (ptrdiff_t)X->size[1];
          lda_t = (ptrdiff_t)X->size[0];
          ldb_t = (ptrdiff_t)X->size[1];
          ldc_t = (ptrdiff_t)X->size[0];
          dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &s, &X->data[0], &lda_t,
                &beta->data[0], &ldb_t, &beta1, &U_cond->data[0], &ldc_t);
        }
      }

      /*  select optimal portfolio */
      st.site = &k_emlrtRSI;
      b_st.site = &qc_emlrtRSI;
      c_st.site = &rc_emlrtRSI;
      unnamed_idx_0 = (uint32_T)U_cond->size[0];
      ixstart = iindx->size[0];
      iindx->size[0] = (int32_T)unnamed_idx_0;
      emxEnsureCapacity(&c_st, (emxArray__common *)iindx, ixstart, (int32_T)
                        sizeof(int32_T), &emlrtRTEI);
      ixstop = (int32_T)unnamed_idx_0;
      for (ixstart = 0; ixstart < ixstop; ixstart++) {
        iindx->data[ixstart] = 1;
      }

      vlen = U_cond->size[0];
      ix = 0;
      iy = -1;
      d_st.site = &sc_emlrtRSI;
      if (1 > U_cond->size[0]) {
        overflow = false;
      } else {
        overflow = (U_cond->size[0] > 2147483646);
      }

      if (overflow) {
        e_st.site = &s_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }

      for (cdiff = 1; cdiff <= vlen; cdiff++) {
        ix++;
        d_st.site = &tc_emlrtRSI;
        ixstart = ix;
        ixstop = ix + 10200 * vlen;
        s = U_cond->data[ix - 1];
        itmp = 1;
        cindx = 1;
        if (muDoubleScalarIsNaN(U_cond->data[ix - 1])) {
          apnd = ix + vlen;
          e_st.site = &vc_emlrtRSI;
          if ((vlen == 0) || (apnd > ixstop)) {
            overflow = false;
          } else {
            overflow = (ixstop > MAX_int32_T - vlen);
          }

          if (overflow) {
            f_st.site = &s_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }

          exitg2 = false;
          while ((!exitg2) && ((vlen > 0) && (apnd <= ixstop))) {
            cindx++;
            ixstart = apnd;
            if (!muDoubleScalarIsNaN(U_cond->data[apnd - 1])) {
              s = U_cond->data[apnd - 1];
              itmp = cindx;
              exitg2 = true;
            } else {
              apnd += vlen;
            }
          }
        }

        if (ixstart < ixstop) {
          apnd = ixstart + vlen;
          e_st.site = &uc_emlrtRSI;
          if ((vlen == 0) || (apnd > ixstop)) {
            overflow = false;
          } else {
            overflow = (ixstop > MAX_int32_T - vlen);
          }

          if (overflow) {
            f_st.site = &s_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }

          while ((vlen > 0) && (apnd <= ixstop)) {
            cindx++;
            if (U_cond->data[apnd - 1] > s) {
              s = U_cond->data[apnd - 1];
              itmp = cindx;
            }

            apnd += vlen;
          }
        }

        iy++;
        iindx->data[iy] = itmp;
      }

      ixstart = indx->size[0];
      indx->size[0] = iindx->size[0];
      emxEnsureCapacity(&b_st, (emxArray__common *)indx, ixstart, (int32_T)
                        sizeof(real_T), &emlrtRTEI);
      ixstop = iindx->size[0];
      for (ixstart = 0; ixstart < ixstop; ixstart++) {
        indx->data[ixstart] = iindx->data[ixstart];
      }

      ixstop = indx->size[0];
      for (ixstart = 0; ixstart < ixstop; ixstart++) {
        apnd = (int32_T)indx->data[ixstart];
        if (!((apnd >= 1) && (apnd <= 10201))) {
          emlrtDynamicBoundsCheckR2012b(apnd, 1, 10201, &l_emlrtBCI, sp);
        }
      }

      /*  update vectors */
      for (ixstart = 0; ixstart < 2; ixstart++) {
        c_returns[ixstart] = returns->size[ixstart];
      }

      ixstart = portfolios->size[0] * portfolios->size[1];
      portfolios->size[0] = indx->size[0];
      portfolios->size[1] = 3;
      emxEnsureCapacity(sp, (emxArray__common *)portfolios, ixstart, (int32_T)
                        sizeof(real_T), &emlrtRTEI);
      for (ixstart = 0; ixstart < 3; ixstart++) {
        ixstop = indx->size[0];
        for (apnd = 0; apnd < ixstop; apnd++) {
          portfolios->data[apnd + portfolios->size[0] * ixstart] =
            SD->f0.portfolios[ixstart + 3 * ((int32_T)indx->data[apnd] - 1)];
        }
      }

      for (ixstart = 0; ixstart < 2; ixstart++) {
        b_portfolios[ixstart] = portfolios->size[ixstart];
      }

      if ((c_returns[0] != b_portfolios[0]) || (c_returns[1] != b_portfolios[1]))
      {
        emlrtSizeEqCheckNDR2012b(&c_returns[0], &b_portfolios[0], &d_emlrtECI,
          sp);
      }

      ixstart = b_returns->size[0] * b_returns->size[1];
      b_returns->size[0] = returns->size[0];
      b_returns->size[1] = 3;
      emxEnsureCapacity(sp, (emxArray__common *)b_returns, ixstart, (int32_T)
                        sizeof(real_T), &emlrtRTEI);
      for (ixstart = 0; ixstart < 3; ixstart++) {
        ixstop = returns->size[0];
        for (apnd = 0; apnd < ixstop; apnd++) {
          b_returns->data[apnd + b_returns->size[0] * ixstart] = returns->
            data[apnd + returns->size[0] * ixstart] * SD->f0.portfolios[ixstart
            + 3 * ((int32_T)indx->data[apnd] - 1)];
        }
      }

      st.site = &l_emlrtRSI;
      b_sum(&st, b_returns, indx);
      st.site = &l_emlrtRSI;
      power(&st, indx, appetite, r2);
      ixstart = r2->size[0];
      apnd = U_fut->size[0];
      if (ixstart != apnd) {
        emlrtSizeEqCheck1DR2012b(ixstart, apnd, &c_emlrtECI, sp);
      }

      ixstart = U_fut->size[0];
      U_fut->size[0] = r2->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)U_fut, ixstart, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      ixstop = r2->size[0];
      for (ixstart = 0; ixstart < ixstop; ixstart++) {
        U_fut->data[ixstart] *= r2->data[ixstart];
      }

      period++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /*  solve for first period */
    buffer = 0;
    while (buffer < 35) {
      ixstop = (int32_T)muDoubleScalarMin(300.0 * (1.0 + (real_T)buffer),
        10201.0);
      st.site = &m_emlrtRSI;
      cindx = 300 * buffer + 1;
      b_st.site = &v_emlrtRSI;
      c_st.site = &w_emlrtRSI;
      if (ixstop < cindx) {
        cdiff = 0;
        apnd = ixstop;
      } else {
        vlen = (int32_T)muDoubleScalarFloor((real_T)(ixstop - cindx) + 0.5);
        apnd = cindx + vlen;
        cdiff = apnd - ixstop;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)
            muIntScalarMax_sint32(cindx, ixstop)) {
          vlen++;
          apnd = ixstop;
        } else if (cdiff > 0) {
          apnd = (cindx + vlen) - 1;
        } else {
          vlen++;
        }

        if (vlen >= 0) {
          cdiff = vlen;
        } else {
          cdiff = 0;
        }
      }

      d_st.site = &x_emlrtRSI;
      ixstart = batch->size[0] * batch->size[1];
      batch->size[0] = 1;
      batch->size[1] = cdiff;
      emxEnsureCapacity(&c_st, (emxArray__common *)batch, ixstart, (int32_T)
                        sizeof(real_T), &emlrtRTEI);
      if (cdiff > 0) {
        batch->data[0] = cindx;
        if (cdiff > 1) {
          batch->data[cdiff - 1] = apnd;
          ixstart = cdiff - 1;
          vlen = asr_s32(ixstart, 1U);
          d_st.site = &y_emlrtRSI;
          for (ixstop = 1; ixstop < vlen; ixstop++) {
            batch->data[ixstop] = cindx + ixstop;
            batch->data[(cdiff - ixstop) - 1] = apnd - ixstop;
          }

          if (vlen << 1 == cdiff - 1) {
            batch->data[vlen] = (real_T)(cindx + apnd) / 2.0;
          } else {
            batch->data[vlen] = cindx + vlen;
            batch->data[vlen + 1] = apnd - vlen;
          }
        }
      }

      ixstart = log_wealth->size[2];
      if (!(1 <= ixstart)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, ixstart, &b_emlrtBCI, sp);
      }

      ixstop = log_wealth->size[0];
      ixstart = r0->size[0] * r0->size[1];
      r0->size[0] = ixstop;
      r0->size[1] = batch->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)r0, ixstart, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      cindx = batch->size[1];
      for (ixstart = 0; ixstart < cindx; ixstart++) {
        for (apnd = 0; apnd < ixstop; apnd++) {
          s = batch->data[batch->size[0] * ixstart];
          if (s != (int32_T)muDoubleScalarFloor(s)) {
            emlrtIntegerCheckR2012b(s, &emlrtDCI, sp);
          }

          cdiff = (int32_T)s;
          if (!((cdiff >= 1) && (cdiff <= 10201))) {
            emlrtDynamicBoundsCheckR2012b(cdiff, 1, 10201, &k_emlrtBCI, sp);
          }

          r0->data[apnd + r0->size[0] * ixstart] = log_wealth->data[apnd +
            log_wealth->size[0] * (cdiff - 1)];
        }
      }

      st.site = &n_emlrtRSI;
      repmat(&st, U_fut, batch->size[1], r3);
      ixstop = log_wealth->size[0];
      ixstart = b_log_wealth->size[0] * b_log_wealth->size[1];
      b_log_wealth->size[0] = ixstop;
      b_log_wealth->size[1] = batch->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)b_log_wealth, ixstart, (int32_T)
                        sizeof(real_T), &emlrtRTEI);
      cindx = batch->size[1];
      for (ixstart = 0; ixstart < cindx; ixstart++) {
        for (apnd = 0; apnd < ixstop; apnd++) {
          b_log_wealth->data[apnd + b_log_wealth->size[0] * ixstart] =
            log_wealth->data[apnd + log_wealth->size[0] * ((int32_T)batch->
            data[batch->size[0] * ixstart] - 1)];
        }
      }

      for (ixstart = 0; ixstart < 2; ixstart++) {
        e_log_wealth[ixstart] = b_log_wealth->size[ixstart];
      }

      for (ixstart = 0; ixstart < 2; ixstart++) {
        iv1[ixstart] = r3->size[ixstart];
      }

      if ((e_log_wealth[0] != iv1[0]) || (e_log_wealth[1] != iv1[1])) {
        emlrtSizeEqCheckNDR2012b(&e_log_wealth[0], &iv1[0], &b_emlrtECI, sp);
      }

      ixstop = U->size[0];
      ixstart = iindx->size[0];
      iindx->size[0] = ixstop;
      emxEnsureCapacity(sp, (emxArray__common *)iindx, ixstart, (int32_T)sizeof
                        (int32_T), &emlrtRTEI);
      for (ixstart = 0; ixstart < ixstop; ixstart++) {
        iindx->data[ixstart] = ixstart;
      }

      vlen = batch->size[1];
      ixstop = batch->size[1];
      for (ixstart = 0; ixstart < ixstop; ixstart++) {
        tmp_data[ixstart] = (int32_T)batch->data[batch->size[0] * ixstart] - 1;
      }

      ixstart = r0->size[0] * r0->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)r0, ixstart, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      ixstart = r0->size[0];
      apnd = r0->size[1];
      ixstop = ixstart * apnd;
      for (ixstart = 0; ixstart < ixstop; ixstart++) {
        r0->data[ixstart] = aversion * (r0->data[ixstart] * r3->data[ixstart]);
      }

      d_iindx[0] = iindx->size[0];
      d_iindx[1] = vlen;
      emlrtSubAssignSizeCheckR2012b(d_iindx, 2, *(int32_T (*)[2])r0->size, 2,
        &emlrtECI, sp);
      ixstop = r0->size[1];
      for (ixstart = 0; ixstart < ixstop; ixstart++) {
        cindx = r0->size[0];
        for (apnd = 0; apnd < cindx; apnd++) {
          U->data[iindx->data[apnd] + U->size[0] * tmp_data[ixstart]] = r0->
            data[apnd + r0->size[0] * ixstart];
        }
      }

      buffer++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /*  compute utility for weight pairs */
    st.site = &o_emlrtRSI;
    b_st.site = &fd_emlrtRSI;
    if (U->size[0] == 0) {
      memset(&y[0], 0, 10201U * sizeof(real_T));
    } else {
      vlen = U->size[0];
      ix = -1;
      iy = -1;
      for (cdiff = 0; cdiff < 10201; cdiff++) {
        ixstart = ix + 1;
        ix++;
        s = U->data[ixstart];
        c_st.site = &gd_emlrtRSI;
        if (2 > vlen) {
          b0 = false;
        } else {
          b0 = (vlen > 2147483646);
        }

        if (b0) {
          d_st.site = &s_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }

        for (ixstop = 2; ixstop <= vlen; ixstop++) {
          ix++;
          s += U->data[ix];
        }

        iy++;
        y[iy] = s;
      }
    }

    vlen = U->size[0];
    for (ixstart = 0; ixstart < 10201; ixstart++) {
      y[ixstart] /= (real_T)vlen;
    }

    ixstart = 1;
    s = y[0];
    itmp = 0;
    if (muDoubleScalarIsNaN(y[0])) {
      ix = 2;
      exitg1 = false;
      while ((!exitg1) && (ix < 10202)) {
        ixstart = ix;
        if (!muDoubleScalarIsNaN(y[ix - 1])) {
          s = y[ix - 1];
          itmp = ix - 1;
          exitg1 = true;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < 10201) {
      while (ixstart + 1 < 10202) {
        if (y[ixstart] > s) {
          s = y[ixstart];
          itmp = ixstart;
        }

        ixstart++;
      }
    }

    vlen = w_T->size[1];
    ixstart = 1 + t;
    if (!(ixstart <= vlen)) {
      emlrtDynamicBoundsCheckR2012b(ixstart, 1, vlen, &emlrtBCI, sp);
    }

    for (ixstart = 0; ixstart < 3; ixstart++) {
      w_T->data[ixstart + w_T->size[0] * t] = SD->f0.portfolios[ixstart + 3 *
        itmp];
    }

    ixstart = U_fut->size[0];
    U_fut->size[0] = M;
    emxEnsureCapacity(sp, (emxArray__common *)U_fut, ixstart, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    for (ixstart = 0; ixstart < M; ixstart++) {
      U_fut->data[ixstart] = 1.0;
    }

    st.site = &p_emlrtRSI;
    b_st.site = &hd_emlrtRSI;
    b_fprintf(&b_st, 1.0 + (real_T)t);
    t++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&c_log_wealth);
  emxFree_real_T(&portfolios);
  emxFree_real_T(&r5);
  emxFree_real_T(&r4);
  emxFree_real_T(&c_e_sim_br);
  emxFree_real_T(&c_e_sim_r);
  emxFree_real_T(&b_log_wealth);
  emxFree_real_T(&b_sim_x);
  emxFree_real_T(&b_returns);
  emxFree_int32_T(&iindx);
  emxFree_real_T(&indx);
  emxFree_real_T(&a);
  emxFree_real_T(&b_C);
  emxFree_real_T(&C);
  emxFree_real_T(&r3);
  emxFree_real_T(&r0);
  emxFree_real_T(&r2);
  emxFree_real_T(&U_cond);
  emxFree_real_T(&X);
  emxFree_real_T(&batch);
  emxFree_real_T(&returns);
  emxFree_real_T(&log_wealth);
  emxFree_real_T(&U);
  emxFree_real_T(&U_fut);
  emxFree_real_T(&e_sim_br);
  emxFree_real_T(&e_sim_r);
  emxFree_real_T(&beta);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (strategicPort_three_assets.c) */
