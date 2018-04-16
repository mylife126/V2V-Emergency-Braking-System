/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_2_cs_sfun.h"
#include "c29_Experiment_2_cs.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Experiment_2_cs_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c29_debug_family_names[16] = { "limx_sup", "limy_sup",
  "limx_sup_sorted", "limx_inf_sorted", "limy_inf_sorted", "limy_sup_sorted",
  "nn", "mm", "nargin", "nargout", "sub_im", "limx_inf", "limy_inf", "im_x",
  "im_y", "blob_subim_proces" };

/* Function Declarations */
static void initialize_c29_Experiment_2_cs(SFc29_Experiment_2_csInstanceStruct
  *chartInstance);
static void initialize_params_c29_Experiment_2_cs
  (SFc29_Experiment_2_csInstanceStruct *chartInstance);
static void enable_c29_Experiment_2_cs(SFc29_Experiment_2_csInstanceStruct
  *chartInstance);
static void disable_c29_Experiment_2_cs(SFc29_Experiment_2_csInstanceStruct
  *chartInstance);
static void c29_update_debugger_state_c29_Experiment_2_cs
  (SFc29_Experiment_2_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c29_Experiment_2_cs
  (SFc29_Experiment_2_csInstanceStruct *chartInstance);
static void set_sim_state_c29_Experiment_2_cs
  (SFc29_Experiment_2_csInstanceStruct *chartInstance, const mxArray *c29_st);
static void finalize_c29_Experiment_2_cs(SFc29_Experiment_2_csInstanceStruct
  *chartInstance);
static void sf_gateway_c29_Experiment_2_cs(SFc29_Experiment_2_csInstanceStruct
  *chartInstance);
static void mdl_start_c29_Experiment_2_cs(SFc29_Experiment_2_csInstanceStruct
  *chartInstance);
static void c29_chartstep_c29_Experiment_2_cs
  (SFc29_Experiment_2_csInstanceStruct *chartInstance);
static void initSimStructsc29_Experiment_2_cs
  (SFc29_Experiment_2_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c29_machineNumber, uint32_T
  c29_chartNumber, uint32_T c29_instanceNumber);
static const mxArray *c29_sf_marshallOut(void *chartInstanceVoid, void
  *c29_b_inData);
static void c29_emlrt_marshallIn(SFc29_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c29_c_blob_subim_proces, const char_T
  *c29_identifier, real32_T c29_b_y[187500]);
static void c29_b_emlrt_marshallIn(SFc29_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c29_c_u, const emlrtMsgIdentifier *c29_parentId,
  real32_T c29_b_y[187500]);
static void c29_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData);
static const mxArray *c29_b_sf_marshallOut(void *chartInstanceVoid, void
  *c29_b_inData);
static const mxArray *c29_c_sf_marshallOut(void *chartInstanceVoid, real_T
  c29_b_inData_data[], int32_T c29_inData_sizes[2]);
static real_T c29_c_emlrt_marshallIn(SFc29_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c29_c_u, const emlrtMsgIdentifier *c29_parentId);
static void c29_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData);
static void c29_info_helper(const mxArray **c29_info);
static const mxArray *c29_emlrt_marshallOut(const char * c29_c_u);
static const mxArray *c29_b_emlrt_marshallOut(const uint32_T c29_c_u);
static void c29_eml_switch_helper(SFc29_Experiment_2_csInstanceStruct
  *chartInstance);
static real_T c29_abs(SFc29_Experiment_2_csInstanceStruct *chartInstance, real_T
                      c29_x);
static const mxArray *c29_d_sf_marshallOut(void *chartInstanceVoid, void
  *c29_b_inData);
static int32_T c29_d_emlrt_marshallIn(SFc29_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c29_c_u, const emlrtMsgIdentifier *c29_parentId);
static void c29_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData);
static uint8_T c29_e_emlrt_marshallIn(SFc29_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c29_b_is_active_c29_Experiment_2_cs, const
  char_T *c29_identifier);
static uint8_T c29_f_emlrt_marshallIn(SFc29_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c29_c_u, const emlrtMsgIdentifier *c29_parentId);
static void init_dsm_address_info(SFc29_Experiment_2_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc29_Experiment_2_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c29_Experiment_2_cs(SFc29_Experiment_2_csInstanceStruct
  *chartInstance)
{
  chartInstance->c29_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c29_is_active_c29_Experiment_2_cs = 0U;
}

static void initialize_params_c29_Experiment_2_cs
  (SFc29_Experiment_2_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c29_Experiment_2_cs(SFc29_Experiment_2_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c29_Experiment_2_cs(SFc29_Experiment_2_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c29_update_debugger_state_c29_Experiment_2_cs
  (SFc29_Experiment_2_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c29_Experiment_2_cs
  (SFc29_Experiment_2_csInstanceStruct *chartInstance)
{
  const mxArray *c29_st;
  const mxArray *c29_b_y = NULL;
  int32_T c29_i0;
  const mxArray *c29_c_y = NULL;
  uint8_T c29_hoistedGlobal;
  uint8_T c29_c_u;
  const mxArray *c29_d_y = NULL;
  c29_st = NULL;
  c29_st = NULL;
  c29_b_y = NULL;
  sf_mex_assign(&c29_b_y, sf_mex_createcellmatrix(2, 1), false);
  for (c29_i0 = 0; c29_i0 < 187500; c29_i0++) {
    chartInstance->c29_b_u[c29_i0] = (*chartInstance->c29_b_blob_subim_proces)
      [c29_i0];
  }

  c29_c_y = NULL;
  sf_mex_assign(&c29_c_y, sf_mex_create("y", chartInstance->c29_b_u, 1, 0U, 1U,
    0U, 2, 375, 500), false);
  sf_mex_setcell(c29_b_y, 0, c29_c_y);
  c29_hoistedGlobal = chartInstance->c29_is_active_c29_Experiment_2_cs;
  c29_c_u = c29_hoistedGlobal;
  c29_d_y = NULL;
  sf_mex_assign(&c29_d_y, sf_mex_create("y", &c29_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c29_b_y, 1, c29_d_y);
  sf_mex_assign(&c29_st, c29_b_y, false);
  return c29_st;
}

static void set_sim_state_c29_Experiment_2_cs
  (SFc29_Experiment_2_csInstanceStruct *chartInstance, const mxArray *c29_st)
{
  const mxArray *c29_c_u;
  int32_T c29_i1;
  chartInstance->c29_doneDoubleBufferReInit = true;
  c29_c_u = sf_mex_dup(c29_st);
  c29_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c29_c_u, 0)),
                       "blob_subim_proces", chartInstance->c29_fv0);
  for (c29_i1 = 0; c29_i1 < 187500; c29_i1++) {
    (*chartInstance->c29_b_blob_subim_proces)[c29_i1] = chartInstance->
      c29_fv0[c29_i1];
  }

  chartInstance->c29_is_active_c29_Experiment_2_cs = c29_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c29_c_u, 1)),
     "is_active_c29_Experiment_2_cs");
  sf_mex_destroy(&c29_c_u);
  c29_update_debugger_state_c29_Experiment_2_cs(chartInstance);
  sf_mex_destroy(&c29_st);
}

static void finalize_c29_Experiment_2_cs(SFc29_Experiment_2_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c29_Experiment_2_cs(SFc29_Experiment_2_csInstanceStruct
  *chartInstance)
{
  int32_T c29_i2;
  int32_T c29_loop_ub;
  int32_T c29_i3;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 28U, chartInstance->c29_sfEvent);
  chartInstance->c29_sfEvent = CALL_EVENT;
  c29_chartstep_c29_Experiment_2_cs(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_2_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c29_i2 = 0; c29_i2 < 187500; c29_i2++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c29_b_blob_subim_proces)
                          [c29_i2], 0U);
  }

  c29_loop_ub = (*chartInstance->c29_sub_im_sizes)[0] *
    (*chartInstance->c29_sub_im_sizes)[1] - 1;
  for (c29_i3 = 0; c29_i3 <= c29_loop_ub; c29_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c29_c_sub_im_data)[c29_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c29_limx_inf, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c29_limy_inf, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c29_im_x, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c29_im_y, 5U);
}

static void mdl_start_c29_Experiment_2_cs(SFc29_Experiment_2_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c29_chartstep_c29_Experiment_2_cs
  (SFc29_Experiment_2_csInstanceStruct *chartInstance)
{
  real_T c29_hoistedGlobal;
  real_T c29_b_hoistedGlobal;
  real_T c29_c_hoistedGlobal;
  real_T c29_d_hoistedGlobal;
  int32_T c29_b_sub_im_sizes[2];
  int32_T c29_sub_im;
  int32_T c29_b_sub_im;
  int32_T c29_loop_ub;
  int32_T c29_i4;
  real_T c29_b_limx_inf;
  real_T c29_b_limy_inf;
  real_T c29_b_im_x;
  real_T c29_b_im_y;
  uint32_T c29_debug_family_var_map[16];
  real_T c29_limx_sup;
  real_T c29_limy_sup;
  real_T c29_limx_sup_sorted;
  real_T c29_limx_inf_sorted;
  real_T c29_limy_inf_sorted;
  real_T c29_limy_sup_sorted;
  real_T c29_nn;
  real_T c29_mm;
  real_T c29_nargin = 5.0;
  real_T c29_nargout = 1.0;
  int32_T c29_i5;
  real_T c29_varargin_1[2];
  int32_T c29_ixstart;
  real_T c29_mtmp;
  real_T c29_x;
  boolean_T c29_b;
  int32_T c29_ix;
  real_T c29_b_x;
  boolean_T c29_b_b;
  int32_T c29_b_ix;
  real_T c29_a;
  real_T c29_c_b;
  boolean_T c29_p;
  real_T c29_b_mtmp;
  int32_T c29_b_ixstart;
  real_T c29_c_mtmp;
  real_T c29_c_x;
  boolean_T c29_d_b;
  int32_T c29_c_ix;
  real_T c29_d_x;
  boolean_T c29_e_b;
  int32_T c29_d_ix;
  real_T c29_b_a;
  real_T c29_f_b;
  boolean_T c29_b_p;
  real_T c29_d_mtmp;
  int32_T c29_c_ixstart;
  real_T c29_e_mtmp;
  real_T c29_e_x;
  boolean_T c29_g_b;
  int32_T c29_e_ix;
  real_T c29_f_x;
  boolean_T c29_h_b;
  int32_T c29_f_ix;
  real_T c29_c_a;
  real_T c29_i_b;
  boolean_T c29_c_p;
  real_T c29_f_mtmp;
  int32_T c29_d_ixstart;
  real_T c29_g_mtmp;
  real_T c29_g_x;
  boolean_T c29_j_b;
  int32_T c29_g_ix;
  real_T c29_h_x;
  boolean_T c29_k_b;
  int32_T c29_h_ix;
  real_T c29_d_a;
  real_T c29_l_b;
  boolean_T c29_d_p;
  real_T c29_h_mtmp;
  real_T c29_b_mm;
  real_T c29_b_nn;
  int32_T c29_c_sub_im;
  int32_T c29_d_sub_im;
  const mxArray *c29_b_y = NULL;
  const mxArray *c29_c_y = NULL;
  int32_T c29_c_im_y[2];
  int32_T c29_tmp_sizes[2];
  int32_T c29_d_im_y[2];
  int32_T c29_i6;
  int32_T c29_i7;
  int32_T c29_b_loop_ub;
  int32_T c29_i8;
  int32_T c29_e_sub_im;
  int32_T c29_f_sub_im;
  int32_T c29_c_loop_ub;
  int32_T c29_i9;
  boolean_T c29_b0;
  boolean_T c29_b1;
  boolean_T c29_b2;
  int32_T c29_i10;
  int32_T c29_i11;
  boolean_T c29_b3;
  boolean_T c29_b4;
  boolean_T c29_b5;
  int32_T c29_i12;
  int32_T c29_i13;
  int32_T c29_b_tmp_sizes;
  int32_T c29_d_loop_ub;
  int32_T c29_i14;
  int32_T c29_b_tmp_data[375];
  int32_T c29_c_tmp_sizes;
  int32_T c29_e_loop_ub;
  int32_T c29_i15;
  int32_T c29_c_tmp_data[500];
  int32_T c29_c_sub_im_sizes[2];
  int32_T c29_g_sub_im;
  int32_T c29_h_sub_im;
  int32_T c29_f_loop_ub;
  int32_T c29_i16;
  int32_T c29_iv0[2];
  int32_T c29_i_sub_im;
  int32_T c29_j_sub_im;
  int32_T c29_g_loop_ub;
  int32_T c29_i17;
  int32_T c29_iv1[2];
  int32_T c29_h_loop_ub;
  int32_T c29_i18;
  int32_T c29_i_loop_ub;
  int32_T c29_i19;
  int32_T c29_i20;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T exitg4;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 28U, chartInstance->c29_sfEvent);
  c29_hoistedGlobal = *chartInstance->c29_limx_inf;
  c29_b_hoistedGlobal = *chartInstance->c29_limy_inf;
  c29_c_hoistedGlobal = *chartInstance->c29_im_x;
  c29_d_hoistedGlobal = *chartInstance->c29_im_y;
  c29_b_sub_im_sizes[0] = (*chartInstance->c29_sub_im_sizes)[0];
  c29_b_sub_im_sizes[1] = (*chartInstance->c29_sub_im_sizes)[1];
  c29_sub_im = c29_b_sub_im_sizes[0];
  c29_b_sub_im = c29_b_sub_im_sizes[1];
  c29_loop_ub = (*chartInstance->c29_sub_im_sizes)[0] *
    (*chartInstance->c29_sub_im_sizes)[1] - 1;
  for (c29_i4 = 0; c29_i4 <= c29_loop_ub; c29_i4++) {
    chartInstance->c29_sub_im_data[c29_i4] = (*chartInstance->c29_c_sub_im_data)
      [c29_i4];
  }

  c29_b_limx_inf = c29_hoistedGlobal;
  c29_b_limy_inf = c29_b_hoistedGlobal;
  c29_b_im_x = c29_c_hoistedGlobal;
  c29_b_im_y = c29_d_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 16U, 16U, c29_debug_family_names,
    c29_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c29_limx_sup, 0U, c29_b_sf_marshallOut,
    c29_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c29_limy_sup, 1U, c29_b_sf_marshallOut,
    c29_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c29_limx_sup_sorted, 2U,
    c29_b_sf_marshallOut, c29_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c29_limx_inf_sorted, 3U,
    c29_b_sf_marshallOut, c29_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c29_limy_inf_sorted, 4U,
    c29_b_sf_marshallOut, c29_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c29_limy_sup_sorted, 5U,
    c29_b_sf_marshallOut, c29_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c29_nn, 6U, c29_b_sf_marshallOut,
    c29_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c29_mm, 7U, c29_b_sf_marshallOut,
    c29_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c29_nargin, 8U, c29_b_sf_marshallOut,
    c29_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c29_nargout, 9U, c29_b_sf_marshallOut,
    c29_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN(chartInstance->c29_sub_im_data, (const int32_T *)
    &c29_b_sub_im_sizes, NULL, 1, 10, (void *)c29_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c29_b_limx_inf, 11U, c29_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c29_b_limy_inf, 12U, c29_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c29_b_im_x, 13U, c29_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c29_b_im_y, 14U, c29_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c29_blob_subim_proces, 15U,
    c29_sf_marshallOut, c29_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c29_sfEvent, 3);
  for (c29_i5 = 0; c29_i5 < 187500; c29_i5++) {
    chartInstance->c29_blob_subim_proces[c29_i5] = 0.0F;
  }

  _SFD_EML_CALL(0U, chartInstance->c29_sfEvent, 5);
  c29_limx_sup = c29_b_limx_inf + c29_b_im_x;
  _SFD_EML_CALL(0U, chartInstance->c29_sfEvent, 6);
  c29_limy_sup = c29_b_limy_inf + c29_b_im_y;
  _SFD_EML_CALL(0U, chartInstance->c29_sfEvent, 9);
  c29_varargin_1[0] = c29_limx_sup;
  c29_varargin_1[1] = c29_b_limx_inf;
  c29_ixstart = 1;
  c29_mtmp = c29_varargin_1[0];
  c29_x = c29_mtmp;
  c29_b = muDoubleScalarIsNaN(c29_x);
  if (c29_b) {
    c29_eml_switch_helper(chartInstance);
    c29_eml_switch_helper(chartInstance);
    c29_ix = 2;
    exitg4 = false;
    while ((exitg4 == false) && (c29_ix < 3)) {
      c29_ixstart = 2;
      c29_b_x = c29_varargin_1[1];
      c29_b_b = muDoubleScalarIsNaN(c29_b_x);
      if (!c29_b_b) {
        c29_mtmp = c29_varargin_1[1];
        exitg4 = true;
      } else {
        c29_ix = 3;
      }
    }
  }

  if (c29_ixstart < 2) {
    c29_eml_switch_helper(chartInstance);
    c29_eml_switch_helper(chartInstance);
    c29_b_ix = 2;
    while (c29_b_ix < 3) {
      c29_a = c29_varargin_1[1];
      c29_c_b = c29_mtmp;
      c29_p = (c29_a > c29_c_b);
      if (c29_p) {
        c29_mtmp = c29_varargin_1[1];
      }

      c29_b_ix = 3;
    }
  }

  c29_b_mtmp = c29_mtmp;
  c29_limx_sup_sorted = c29_b_mtmp;
  _SFD_EML_CALL(0U, chartInstance->c29_sfEvent, 10);
  c29_varargin_1[0] = c29_limx_sup;
  c29_varargin_1[1] = c29_b_limx_inf;
  c29_b_ixstart = 1;
  c29_c_mtmp = c29_varargin_1[0];
  c29_c_x = c29_c_mtmp;
  c29_d_b = muDoubleScalarIsNaN(c29_c_x);
  if (c29_d_b) {
    c29_eml_switch_helper(chartInstance);
    c29_eml_switch_helper(chartInstance);
    c29_c_ix = 2;
    exitg3 = false;
    while ((exitg3 == false) && (c29_c_ix < 3)) {
      c29_b_ixstart = 2;
      c29_d_x = c29_varargin_1[1];
      c29_e_b = muDoubleScalarIsNaN(c29_d_x);
      if (!c29_e_b) {
        c29_c_mtmp = c29_varargin_1[1];
        exitg3 = true;
      } else {
        c29_c_ix = 3;
      }
    }
  }

  if (c29_b_ixstart < 2) {
    c29_eml_switch_helper(chartInstance);
    c29_eml_switch_helper(chartInstance);
    c29_d_ix = 2;
    while (c29_d_ix < 3) {
      c29_b_a = c29_varargin_1[1];
      c29_f_b = c29_c_mtmp;
      c29_b_p = (c29_b_a < c29_f_b);
      if (c29_b_p) {
        c29_c_mtmp = c29_varargin_1[1];
      }

      c29_d_ix = 3;
    }
  }

  c29_d_mtmp = c29_c_mtmp;
  c29_limx_inf_sorted = c29_d_mtmp;
  _SFD_EML_CALL(0U, chartInstance->c29_sfEvent, 11);
  c29_varargin_1[0] = c29_limy_sup;
  c29_varargin_1[1] = c29_b_limy_inf;
  c29_c_ixstart = 1;
  c29_e_mtmp = c29_varargin_1[0];
  c29_e_x = c29_e_mtmp;
  c29_g_b = muDoubleScalarIsNaN(c29_e_x);
  if (c29_g_b) {
    c29_eml_switch_helper(chartInstance);
    c29_eml_switch_helper(chartInstance);
    c29_e_ix = 2;
    exitg2 = false;
    while ((exitg2 == false) && (c29_e_ix < 3)) {
      c29_c_ixstart = 2;
      c29_f_x = c29_varargin_1[1];
      c29_h_b = muDoubleScalarIsNaN(c29_f_x);
      if (!c29_h_b) {
        c29_e_mtmp = c29_varargin_1[1];
        exitg2 = true;
      } else {
        c29_e_ix = 3;
      }
    }
  }

  if (c29_c_ixstart < 2) {
    c29_eml_switch_helper(chartInstance);
    c29_eml_switch_helper(chartInstance);
    c29_f_ix = 2;
    while (c29_f_ix < 3) {
      c29_c_a = c29_varargin_1[1];
      c29_i_b = c29_e_mtmp;
      c29_c_p = (c29_c_a < c29_i_b);
      if (c29_c_p) {
        c29_e_mtmp = c29_varargin_1[1];
      }

      c29_f_ix = 3;
    }
  }

  c29_f_mtmp = c29_e_mtmp;
  c29_limy_inf_sorted = c29_f_mtmp;
  _SFD_EML_CALL(0U, chartInstance->c29_sfEvent, 12);
  c29_varargin_1[0] = c29_limy_sup;
  c29_varargin_1[1] = c29_b_limy_inf;
  c29_d_ixstart = 1;
  c29_g_mtmp = c29_varargin_1[0];
  c29_g_x = c29_g_mtmp;
  c29_j_b = muDoubleScalarIsNaN(c29_g_x);
  if (c29_j_b) {
    c29_eml_switch_helper(chartInstance);
    c29_eml_switch_helper(chartInstance);
    c29_g_ix = 2;
    exitg1 = false;
    while ((exitg1 == false) && (c29_g_ix < 3)) {
      c29_d_ixstart = 2;
      c29_h_x = c29_varargin_1[1];
      c29_k_b = muDoubleScalarIsNaN(c29_h_x);
      if (!c29_k_b) {
        c29_g_mtmp = c29_varargin_1[1];
        exitg1 = true;
      } else {
        c29_g_ix = 3;
      }
    }
  }

  if (c29_d_ixstart < 2) {
    c29_eml_switch_helper(chartInstance);
    c29_eml_switch_helper(chartInstance);
    c29_h_ix = 2;
    while (c29_h_ix < 3) {
      c29_d_a = c29_varargin_1[1];
      c29_l_b = c29_g_mtmp;
      c29_d_p = (c29_d_a > c29_l_b);
      if (c29_d_p) {
        c29_g_mtmp = c29_varargin_1[1];
      }

      c29_h_ix = 3;
    }
  }

  c29_h_mtmp = c29_g_mtmp;
  c29_limy_sup_sorted = c29_h_mtmp;
  _SFD_EML_CALL(0U, chartInstance->c29_sfEvent, 15);
  c29_b_mm = (real_T)c29_b_sub_im_sizes[1];
  c29_b_nn = (real_T)c29_b_sub_im_sizes[0];
  c29_nn = c29_b_nn;
  c29_mm = c29_b_mm;
  _SFD_EML_CALL(0U, chartInstance->c29_sfEvent, 16);
  guard1 = false;
  if (CV_EML_COND(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c29_nn, 3.0, -1, 3U,
        c29_nn <= 3.0))) {
    if (CV_EML_COND(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c29_mm, 3.0, -1, 3U,
          c29_mm <= 3.0))) {
      CV_EML_MCDC(0, 1, 0, true);
      CV_EML_IF(0, 1, 0, true);
      _SFD_EML_CALL(0U, chartInstance->c29_sfEvent, 17);
      c29_b_sub_im_sizes[0] = 1;
      c29_b_sub_im_sizes[1] = 1;
      c29_c_sub_im = c29_b_sub_im_sizes[0];
      c29_d_sub_im = c29_b_sub_im_sizes[1];
      chartInstance->c29_sub_im_data[0] = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c29_sfEvent, 19);
      guard2 = false;
      if (CV_EML_COND(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 2, c29_b_im_x, 0.0, -1,
            1U, c29_b_im_x != 0.0))) {
        guard2 = true;
      } else if (CV_EML_COND(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 3, c29_b_im_y,
                   0.0, -1, 1U, c29_b_im_y != 0.0))) {
        guard2 = true;
      } else {
        CV_EML_MCDC(0, 1, 1, false);
        CV_EML_IF(0, 1, 1, false);
      }

      if (guard2 == true) {
        CV_EML_MCDC(0, 1, 1, true);
        CV_EML_IF(0, 1, 1, true);
        _SFD_EML_CALL(0U, chartInstance->c29_sfEvent, 20);
        c29_b_im_x = c29_abs(chartInstance, c29_b_im_x);
        _SFD_EML_CALL(0U, chartInstance->c29_sfEvent, 21);
        c29_b_im_y = c29_abs(chartInstance, c29_b_im_y);
        _SFD_EML_CALL(0U, chartInstance->c29_sfEvent, 22);
        if (c29_b_im_x < 1000.0) {
        } else {
          c29_b_y = NULL;
          sf_mex_assign(&c29_b_y, sf_mex_create("y", "Assertion failed.", 15, 0U,
            0U, 0U, 2, 1, strlen("Assertion failed.")), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                            c29_b_y);
        }

        _SFD_EML_CALL(0U, chartInstance->c29_sfEvent, 23);
        if (c29_b_im_y < 1000.0) {
        } else {
          c29_c_y = NULL;
          sf_mex_assign(&c29_c_y, sf_mex_create("y", "Assertion failed.", 15, 0U,
            0U, 0U, 2, 1, strlen("Assertion failed.")), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                            c29_c_y);
        }

        _SFD_EML_CALL(0U, chartInstance->c29_sfEvent, 24);
        c29_c_im_y[0] = (int32_T)_SFD_INTEGER_CHECK("im_y+1", c29_b_im_y + 1.0);
        c29_c_im_y[1] = (int32_T)_SFD_INTEGER_CHECK("im_x+1", c29_b_im_x + 1.0);
        c29_tmp_sizes[0] = c29_c_im_y[0];
        c29_d_im_y[0] = (int32_T)_SFD_INTEGER_CHECK("im_y+1", c29_b_im_y + 1.0);
        c29_d_im_y[1] = (int32_T)_SFD_INTEGER_CHECK("im_x+1", c29_b_im_x + 1.0);
        c29_tmp_sizes[1] = c29_d_im_y[1];
        c29_i6 = c29_tmp_sizes[0];
        c29_i7 = c29_tmp_sizes[1];
        c29_b_loop_ub = (int32_T)_SFD_INTEGER_CHECK("im_y+1", c29_b_im_y + 1.0) *
          (int32_T)_SFD_INTEGER_CHECK("im_x+1", c29_b_im_x + 1.0) - 1;
        for (c29_i8 = 0; c29_i8 <= c29_b_loop_ub; c29_i8++) {
          chartInstance->c29_tmp_data[c29_i8] = 0.0;
        }

        _SFD_DIM_SIZE_GEQ_CHECK(375, c29_tmp_sizes[0], 1);
        _SFD_DIM_SIZE_GEQ_CHECK(500, c29_tmp_sizes[1], 2);
        c29_b_sub_im_sizes[0] = c29_tmp_sizes[0];
        c29_b_sub_im_sizes[1] = c29_tmp_sizes[1];
        c29_e_sub_im = c29_b_sub_im_sizes[0];
        c29_f_sub_im = c29_b_sub_im_sizes[1];
        c29_c_loop_ub = c29_tmp_sizes[0] * c29_tmp_sizes[1] - 1;
        for (c29_i9 = 0; c29_i9 <= c29_c_loop_ub; c29_i9++) {
          chartInstance->c29_sub_im_data[c29_i9] = chartInstance->
            c29_tmp_data[c29_i9];
        }
      }
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 0, false);
  }

  _SFD_EML_CALL(0U, chartInstance->c29_sfEvent, 29);
  c29_b0 = (c29_limy_inf_sorted > c29_limy_sup_sorted);
  c29_b1 = c29_b0;
  c29_b2 = c29_b1;
  if (c29_b2) {
    c29_i10 = 1;
    c29_i11 = 0;
  } else {
    c29_i10 = _SFD_EML_ARRAY_BOUNDS_CHECK("blob_subim_proces", (int32_T)
      _SFD_INTEGER_CHECK("limy_inf_sorted", c29_limy_inf_sorted), 1, 375, 0, 0);
    c29_i11 = _SFD_EML_ARRAY_BOUNDS_CHECK("blob_subim_proces", (int32_T)
      _SFD_INTEGER_CHECK("limy_sup_sorted", c29_limy_sup_sorted), 1, 375, 0, 0);
  }

  c29_b3 = (c29_limx_inf_sorted > c29_limx_sup_sorted);
  c29_b4 = c29_b3;
  c29_b5 = c29_b4;
  if (c29_b5) {
    c29_i12 = 1;
    c29_i13 = 0;
  } else {
    c29_i12 = _SFD_EML_ARRAY_BOUNDS_CHECK("blob_subim_proces", (int32_T)
      _SFD_INTEGER_CHECK("limx_inf_sorted", c29_limx_inf_sorted), 1, 500, 0, 0);
    c29_i13 = _SFD_EML_ARRAY_BOUNDS_CHECK("blob_subim_proces", (int32_T)
      _SFD_INTEGER_CHECK("limx_sup_sorted", c29_limx_sup_sorted), 1, 500, 0, 0);
  }

  c29_b_tmp_sizes = (c29_i11 - c29_i10) + 1;
  c29_d_loop_ub = c29_i11 - c29_i10;
  for (c29_i14 = 0; c29_i14 <= c29_d_loop_ub; c29_i14++) {
    c29_b_tmp_data[c29_i14] = (c29_i10 + c29_i14) - 1;
  }

  c29_c_tmp_sizes = (c29_i13 - c29_i12) + 1;
  c29_e_loop_ub = c29_i13 - c29_i12;
  for (c29_i15 = 0; c29_i15 <= c29_e_loop_ub; c29_i15++) {
    c29_c_tmp_data[c29_i15] = (c29_i12 + c29_i15) - 1;
  }

  c29_c_sub_im_sizes[0] = c29_b_sub_im_sizes[0];
  c29_c_sub_im_sizes[1] = c29_b_sub_im_sizes[1];
  c29_g_sub_im = c29_c_sub_im_sizes[0];
  c29_h_sub_im = c29_c_sub_im_sizes[1];
  c29_f_loop_ub = c29_b_sub_im_sizes[0] * c29_b_sub_im_sizes[1] - 1;
  for (c29_i16 = 0; c29_i16 <= c29_f_loop_ub; c29_i16++) {
    chartInstance->c29_b_sub_im_data[c29_i16] = (real32_T)
      chartInstance->c29_sub_im_data[c29_i16];
  }

  c29_iv0[0] = c29_b_tmp_sizes;
  c29_iv0[1] = c29_c_tmp_sizes;
  _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c29_iv0, 2, c29_c_sub_im_sizes, 2);
  c29_c_sub_im_sizes[0] = c29_b_sub_im_sizes[0];
  c29_c_sub_im_sizes[1] = c29_b_sub_im_sizes[1];
  c29_i_sub_im = c29_c_sub_im_sizes[0];
  c29_j_sub_im = c29_c_sub_im_sizes[1];
  c29_g_loop_ub = c29_b_sub_im_sizes[0] * c29_b_sub_im_sizes[1] - 1;
  for (c29_i17 = 0; c29_i17 <= c29_g_loop_ub; c29_i17++) {
    chartInstance->c29_b_sub_im_data[c29_i17] = (real32_T)
      chartInstance->c29_sub_im_data[c29_i17];
  }

  c29_iv1[0] = c29_b_tmp_sizes;
  c29_iv1[1] = c29_c_tmp_sizes;
  c29_h_loop_ub = c29_iv1[1] - 1;
  for (c29_i18 = 0; c29_i18 <= c29_h_loop_ub; c29_i18++) {
    c29_i_loop_ub = c29_iv1[0] - 1;
    for (c29_i19 = 0; c29_i19 <= c29_i_loop_ub; c29_i19++) {
      chartInstance->c29_blob_subim_proces[c29_b_tmp_data[c29_i19] + 375 *
        c29_c_tmp_data[c29_i18]] = chartInstance->c29_b_sub_im_data[c29_i19 +
        c29_iv1[0] * c29_i18];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c29_sfEvent, -29);
  _SFD_SYMBOL_SCOPE_POP();
  for (c29_i20 = 0; c29_i20 < 187500; c29_i20++) {
    (*chartInstance->c29_b_blob_subim_proces)[c29_i20] =
      chartInstance->c29_blob_subim_proces[c29_i20];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 28U, chartInstance->c29_sfEvent);
}

static void initSimStructsc29_Experiment_2_cs
  (SFc29_Experiment_2_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c29_machineNumber, uint32_T
  c29_chartNumber, uint32_T c29_instanceNumber)
{
  (void)c29_machineNumber;
  (void)c29_chartNumber;
  (void)c29_instanceNumber;
}

static const mxArray *c29_sf_marshallOut(void *chartInstanceVoid, void
  *c29_b_inData)
{
  const mxArray *c29_mxArrayOutData = NULL;
  int32_T c29_i21;
  int32_T c29_i22;
  int32_T c29_i23;
  int32_T c29_i24;
  int32_T c29_i25;
  int32_T c29_i26;
  const mxArray *c29_b_y = NULL;
  SFc29_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc29_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c29_mxArrayOutData = NULL;
  c29_i21 = 0;
  for (c29_i22 = 0; c29_i22 < 500; c29_i22++) {
    for (c29_i23 = 0; c29_i23 < 375; c29_i23++) {
      chartInstance->c29_inData[c29_i23 + c29_i21] = (*(real32_T (*)[187500])
        c29_b_inData)[c29_i23 + c29_i21];
    }

    c29_i21 += 375;
  }

  c29_i24 = 0;
  for (c29_i25 = 0; c29_i25 < 500; c29_i25++) {
    for (c29_i26 = 0; c29_i26 < 375; c29_i26++) {
      chartInstance->c29_u[c29_i26 + c29_i24] = chartInstance->
        c29_inData[c29_i26 + c29_i24];
    }

    c29_i24 += 375;
  }

  c29_b_y = NULL;
  sf_mex_assign(&c29_b_y, sf_mex_create("y", chartInstance->c29_u, 1, 0U, 1U, 0U,
    2, 375, 500), false);
  sf_mex_assign(&c29_mxArrayOutData, c29_b_y, false);
  return c29_mxArrayOutData;
}

static void c29_emlrt_marshallIn(SFc29_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c29_c_blob_subim_proces, const char_T
  *c29_identifier, real32_T c29_b_y[187500])
{
  emlrtMsgIdentifier c29_thisId;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c29_c_blob_subim_proces),
    &c29_thisId, c29_b_y);
  sf_mex_destroy(&c29_c_blob_subim_proces);
}

static void c29_b_emlrt_marshallIn(SFc29_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c29_c_u, const emlrtMsgIdentifier *c29_parentId,
  real32_T c29_b_y[187500])
{
  int32_T c29_i27;
  sf_mex_import(c29_parentId, sf_mex_dup(c29_c_u), chartInstance->c29_fv1, 1, 1,
                0U, 1, 0U, 2, 375, 500);
  for (c29_i27 = 0; c29_i27 < 187500; c29_i27++) {
    c29_b_y[c29_i27] = chartInstance->c29_fv1[c29_i27];
  }

  sf_mex_destroy(&c29_c_u);
}

static void c29_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData)
{
  const mxArray *c29_c_blob_subim_proces;
  const char_T *c29_identifier;
  emlrtMsgIdentifier c29_thisId;
  int32_T c29_i28;
  int32_T c29_i29;
  int32_T c29_i30;
  SFc29_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc29_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c29_c_blob_subim_proces = sf_mex_dup(c29_mxArrayInData);
  c29_identifier = c29_varName;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c29_c_blob_subim_proces),
    &c29_thisId, chartInstance->c29_y);
  sf_mex_destroy(&c29_c_blob_subim_proces);
  c29_i28 = 0;
  for (c29_i29 = 0; c29_i29 < 500; c29_i29++) {
    for (c29_i30 = 0; c29_i30 < 375; c29_i30++) {
      (*(real32_T (*)[187500])c29_outData)[c29_i30 + c29_i28] =
        chartInstance->c29_y[c29_i30 + c29_i28];
    }

    c29_i28 += 375;
  }

  sf_mex_destroy(&c29_mxArrayInData);
}

static const mxArray *c29_b_sf_marshallOut(void *chartInstanceVoid, void
  *c29_b_inData)
{
  const mxArray *c29_mxArrayOutData = NULL;
  real_T c29_c_u;
  const mxArray *c29_b_y = NULL;
  SFc29_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc29_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c29_mxArrayOutData = NULL;
  c29_c_u = *(real_T *)c29_b_inData;
  c29_b_y = NULL;
  sf_mex_assign(&c29_b_y, sf_mex_create("y", &c29_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c29_mxArrayOutData, c29_b_y, false);
  return c29_mxArrayOutData;
}

static const mxArray *c29_c_sf_marshallOut(void *chartInstanceVoid, real_T
  c29_b_inData_data[], int32_T c29_inData_sizes[2])
{
  const mxArray *c29_mxArrayOutData = NULL;
  int32_T c29_u_sizes[2];
  int32_T c29_c_u;
  int32_T c29_d_u;
  int32_T c29_b_inData;
  int32_T c29_c_inData;
  int32_T c29_b_inData_sizes;
  int32_T c29_loop_ub;
  int32_T c29_i31;
  int32_T c29_b_loop_ub;
  int32_T c29_i32;
  const mxArray *c29_b_y = NULL;
  SFc29_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc29_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c29_mxArrayOutData = NULL;
  c29_u_sizes[0] = c29_inData_sizes[0];
  c29_u_sizes[1] = c29_inData_sizes[1];
  c29_c_u = c29_u_sizes[0];
  c29_d_u = c29_u_sizes[1];
  c29_b_inData = c29_inData_sizes[0];
  c29_c_inData = c29_inData_sizes[1];
  c29_b_inData_sizes = c29_b_inData * c29_c_inData;
  c29_loop_ub = c29_b_inData * c29_c_inData - 1;
  for (c29_i31 = 0; c29_i31 <= c29_loop_ub; c29_i31++) {
    chartInstance->c29_inData_data[c29_i31] = c29_b_inData_data[c29_i31];
  }

  c29_b_loop_ub = c29_b_inData_sizes - 1;
  for (c29_i32 = 0; c29_i32 <= c29_b_loop_ub; c29_i32++) {
    chartInstance->c29_u_data[c29_i32] = chartInstance->c29_inData_data[c29_i32];
  }

  c29_b_y = NULL;
  sf_mex_assign(&c29_b_y, sf_mex_create("y", chartInstance->c29_u_data, 0, 0U,
    1U, 0U, 2, c29_u_sizes[0], c29_u_sizes[1]), false);
  sf_mex_assign(&c29_mxArrayOutData, c29_b_y, false);
  return c29_mxArrayOutData;
}

static real_T c29_c_emlrt_marshallIn(SFc29_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c29_c_u, const emlrtMsgIdentifier *c29_parentId)
{
  real_T c29_b_y;
  real_T c29_d0;
  (void)chartInstance;
  sf_mex_import(c29_parentId, sf_mex_dup(c29_c_u), &c29_d0, 1, 0, 0U, 0, 0U, 0);
  c29_b_y = c29_d0;
  sf_mex_destroy(&c29_c_u);
  return c29_b_y;
}

static void c29_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData)
{
  const mxArray *c29_nargout;
  const char_T *c29_identifier;
  emlrtMsgIdentifier c29_thisId;
  real_T c29_b_y;
  SFc29_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc29_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c29_nargout = sf_mex_dup(c29_mxArrayInData);
  c29_identifier = c29_varName;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_b_y = c29_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c29_nargout),
    &c29_thisId);
  sf_mex_destroy(&c29_nargout);
  *(real_T *)c29_outData = c29_b_y;
  sf_mex_destroy(&c29_mxArrayInData);
}

const mxArray *sf_c29_Experiment_2_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c29_nameCaptureInfo = NULL;
  c29_nameCaptureInfo = NULL;
  sf_mex_assign(&c29_nameCaptureInfo, sf_mex_createstruct("structure", 2, 25, 1),
                false);
  c29_info_helper(&c29_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c29_nameCaptureInfo);
  return c29_nameCaptureInfo;
}

static void c29_info_helper(const mxArray **c29_info)
{
  const mxArray *c29_rhs0 = NULL;
  const mxArray *c29_lhs0 = NULL;
  const mxArray *c29_rhs1 = NULL;
  const mxArray *c29_lhs1 = NULL;
  const mxArray *c29_rhs2 = NULL;
  const mxArray *c29_lhs2 = NULL;
  const mxArray *c29_rhs3 = NULL;
  const mxArray *c29_lhs3 = NULL;
  const mxArray *c29_rhs4 = NULL;
  const mxArray *c29_lhs4 = NULL;
  const mxArray *c29_rhs5 = NULL;
  const mxArray *c29_lhs5 = NULL;
  const mxArray *c29_rhs6 = NULL;
  const mxArray *c29_lhs6 = NULL;
  const mxArray *c29_rhs7 = NULL;
  const mxArray *c29_lhs7 = NULL;
  const mxArray *c29_rhs8 = NULL;
  const mxArray *c29_lhs8 = NULL;
  const mxArray *c29_rhs9 = NULL;
  const mxArray *c29_lhs9 = NULL;
  const mxArray *c29_rhs10 = NULL;
  const mxArray *c29_lhs10 = NULL;
  const mxArray *c29_rhs11 = NULL;
  const mxArray *c29_lhs11 = NULL;
  const mxArray *c29_rhs12 = NULL;
  const mxArray *c29_lhs12 = NULL;
  const mxArray *c29_rhs13 = NULL;
  const mxArray *c29_lhs13 = NULL;
  const mxArray *c29_rhs14 = NULL;
  const mxArray *c29_lhs14 = NULL;
  const mxArray *c29_rhs15 = NULL;
  const mxArray *c29_lhs15 = NULL;
  const mxArray *c29_rhs16 = NULL;
  const mxArray *c29_lhs16 = NULL;
  const mxArray *c29_rhs17 = NULL;
  const mxArray *c29_lhs17 = NULL;
  const mxArray *c29_rhs18 = NULL;
  const mxArray *c29_lhs18 = NULL;
  const mxArray *c29_rhs19 = NULL;
  const mxArray *c29_lhs19 = NULL;
  const mxArray *c29_rhs20 = NULL;
  const mxArray *c29_lhs20 = NULL;
  const mxArray *c29_rhs21 = NULL;
  const mxArray *c29_lhs21 = NULL;
  const mxArray *c29_rhs22 = NULL;
  const mxArray *c29_lhs22 = NULL;
  const mxArray *c29_rhs23 = NULL;
  const mxArray *c29_lhs23 = NULL;
  const mxArray *c29_rhs24 = NULL;
  const mxArray *c29_lhs24 = NULL;
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("max"), "name", "name", 0);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1311276916U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c29_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 1);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1378317584U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c29_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 2);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_const_nonsingleton_dim"),
                  "name", "name", 2);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c29_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 3);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c29_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 4);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 4);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c29_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 5);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c29_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 6);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 6);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c29_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 7);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 7);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c29_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 8);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("isnan"), "name", "name", 8);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c29_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 9);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c29_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 10);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 10);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 10);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c29_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 11);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 11);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c29_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 12);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 12);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c29_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 13);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("isfi"), "name", "name", 13);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 13);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1346531958U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c29_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 14);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1398897198U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c29_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 15);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("intmax"), "name", "name", 15);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c29_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 16);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c29_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 17);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("intmin"), "name", "name", 17);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c29_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 18);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c29_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 19);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_relop"), "name", "name",
                  19);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("function_handle"),
                  "dominantType", "dominantType", 19);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1342472782U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c29_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(""), "context", "context", 20);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("min"), "name", "name", 20);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1311276918U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c29_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 21);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1378317584U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c29_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(""), "context", "context", 22);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("abs"), "name", "name", 22);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c29_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 23);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c29_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 24);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c29_info, c29_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c29_info, c29_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c29_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c29_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c29_info, sf_mex_duplicatearraysafe(&c29_lhs24), "lhs", "lhs",
                  24);
  sf_mex_destroy(&c29_rhs0);
  sf_mex_destroy(&c29_lhs0);
  sf_mex_destroy(&c29_rhs1);
  sf_mex_destroy(&c29_lhs1);
  sf_mex_destroy(&c29_rhs2);
  sf_mex_destroy(&c29_lhs2);
  sf_mex_destroy(&c29_rhs3);
  sf_mex_destroy(&c29_lhs3);
  sf_mex_destroy(&c29_rhs4);
  sf_mex_destroy(&c29_lhs4);
  sf_mex_destroy(&c29_rhs5);
  sf_mex_destroy(&c29_lhs5);
  sf_mex_destroy(&c29_rhs6);
  sf_mex_destroy(&c29_lhs6);
  sf_mex_destroy(&c29_rhs7);
  sf_mex_destroy(&c29_lhs7);
  sf_mex_destroy(&c29_rhs8);
  sf_mex_destroy(&c29_lhs8);
  sf_mex_destroy(&c29_rhs9);
  sf_mex_destroy(&c29_lhs9);
  sf_mex_destroy(&c29_rhs10);
  sf_mex_destroy(&c29_lhs10);
  sf_mex_destroy(&c29_rhs11);
  sf_mex_destroy(&c29_lhs11);
  sf_mex_destroy(&c29_rhs12);
  sf_mex_destroy(&c29_lhs12);
  sf_mex_destroy(&c29_rhs13);
  sf_mex_destroy(&c29_lhs13);
  sf_mex_destroy(&c29_rhs14);
  sf_mex_destroy(&c29_lhs14);
  sf_mex_destroy(&c29_rhs15);
  sf_mex_destroy(&c29_lhs15);
  sf_mex_destroy(&c29_rhs16);
  sf_mex_destroy(&c29_lhs16);
  sf_mex_destroy(&c29_rhs17);
  sf_mex_destroy(&c29_lhs17);
  sf_mex_destroy(&c29_rhs18);
  sf_mex_destroy(&c29_lhs18);
  sf_mex_destroy(&c29_rhs19);
  sf_mex_destroy(&c29_lhs19);
  sf_mex_destroy(&c29_rhs20);
  sf_mex_destroy(&c29_lhs20);
  sf_mex_destroy(&c29_rhs21);
  sf_mex_destroy(&c29_lhs21);
  sf_mex_destroy(&c29_rhs22);
  sf_mex_destroy(&c29_lhs22);
  sf_mex_destroy(&c29_rhs23);
  sf_mex_destroy(&c29_lhs23);
  sf_mex_destroy(&c29_rhs24);
  sf_mex_destroy(&c29_lhs24);
}

static const mxArray *c29_emlrt_marshallOut(const char * c29_c_u)
{
  const mxArray *c29_b_y = NULL;
  c29_b_y = NULL;
  sf_mex_assign(&c29_b_y, sf_mex_create("y", c29_c_u, 15, 0U, 0U, 0U, 2, 1,
    strlen(c29_c_u)), false);
  return c29_b_y;
}

static const mxArray *c29_b_emlrt_marshallOut(const uint32_T c29_c_u)
{
  const mxArray *c29_b_y = NULL;
  c29_b_y = NULL;
  sf_mex_assign(&c29_b_y, sf_mex_create("y", &c29_c_u, 7, 0U, 0U, 0U, 0), false);
  return c29_b_y;
}

static void c29_eml_switch_helper(SFc29_Experiment_2_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static real_T c29_abs(SFc29_Experiment_2_csInstanceStruct *chartInstance, real_T
                      c29_x)
{
  real_T c29_b_x;
  (void)chartInstance;
  c29_b_x = c29_x;
  return muDoubleScalarAbs(c29_b_x);
}

static const mxArray *c29_d_sf_marshallOut(void *chartInstanceVoid, void
  *c29_b_inData)
{
  const mxArray *c29_mxArrayOutData = NULL;
  int32_T c29_c_u;
  const mxArray *c29_b_y = NULL;
  SFc29_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc29_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c29_mxArrayOutData = NULL;
  c29_c_u = *(int32_T *)c29_b_inData;
  c29_b_y = NULL;
  sf_mex_assign(&c29_b_y, sf_mex_create("y", &c29_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c29_mxArrayOutData, c29_b_y, false);
  return c29_mxArrayOutData;
}

static int32_T c29_d_emlrt_marshallIn(SFc29_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c29_c_u, const emlrtMsgIdentifier *c29_parentId)
{
  int32_T c29_b_y;
  int32_T c29_i33;
  (void)chartInstance;
  sf_mex_import(c29_parentId, sf_mex_dup(c29_c_u), &c29_i33, 1, 6, 0U, 0, 0U, 0);
  c29_b_y = c29_i33;
  sf_mex_destroy(&c29_c_u);
  return c29_b_y;
}

static void c29_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData)
{
  const mxArray *c29_b_sfEvent;
  const char_T *c29_identifier;
  emlrtMsgIdentifier c29_thisId;
  int32_T c29_b_y;
  SFc29_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc29_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c29_b_sfEvent = sf_mex_dup(c29_mxArrayInData);
  c29_identifier = c29_varName;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_b_y = c29_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c29_b_sfEvent),
    &c29_thisId);
  sf_mex_destroy(&c29_b_sfEvent);
  *(int32_T *)c29_outData = c29_b_y;
  sf_mex_destroy(&c29_mxArrayInData);
}

static uint8_T c29_e_emlrt_marshallIn(SFc29_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c29_b_is_active_c29_Experiment_2_cs, const
  char_T *c29_identifier)
{
  uint8_T c29_b_y;
  emlrtMsgIdentifier c29_thisId;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_b_y = c29_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c29_b_is_active_c29_Experiment_2_cs), &c29_thisId);
  sf_mex_destroy(&c29_b_is_active_c29_Experiment_2_cs);
  return c29_b_y;
}

static uint8_T c29_f_emlrt_marshallIn(SFc29_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c29_c_u, const emlrtMsgIdentifier *c29_parentId)
{
  uint8_T c29_b_y;
  uint8_T c29_u0;
  (void)chartInstance;
  sf_mex_import(c29_parentId, sf_mex_dup(c29_c_u), &c29_u0, 1, 3, 0U, 0, 0U, 0);
  c29_b_y = c29_u0;
  sf_mex_destroy(&c29_c_u);
  return c29_b_y;
}

static void init_dsm_address_info(SFc29_Experiment_2_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc29_Experiment_2_csInstanceStruct
  *chartInstance)
{
  chartInstance->c29_b_blob_subim_proces = (real32_T (*)[187500])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c29_c_sub_im_data = (real_T (*)[187500])
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c29_sub_im_sizes = (int32_T (*)[2])
    ssGetCurrentInputPortDimensions_wrapper(chartInstance->S, 0);
  chartInstance->c29_limx_inf = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c29_limy_inf = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c29_im_x = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c29_im_y = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c29_Experiment_2_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(579798382U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3788881077U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1642615341U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1594614041U);
}

mxArray* sf_c29_Experiment_2_cs_get_post_codegen_info(void);
mxArray *sf_c29_Experiment_2_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("CKMF7Z16xaIZEFHYZMjvfG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(375);
      pr[1] = (double)(500);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(375);
      pr[1] = (double)(500);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c29_Experiment_2_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c29_Experiment_2_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c29_Experiment_2_cs_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "incompatibleSymbol", };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 3, infoFields);
  mxArray *fallbackReason = mxCreateString("feature_off");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxArray *fallbackType = mxCreateString("early");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c29_Experiment_2_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c29_Experiment_2_cs_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c29_Experiment_2_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[14],T\"blob_subim_proces\",},{M[8],M[0],T\"is_active_c29_Experiment_2_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c29_Experiment_2_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc29_Experiment_2_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc29_Experiment_2_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_2_csMachineNumber_,
           29,
           1,
           1,
           0,
           6,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_Experiment_2_csMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Experiment_2_csMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Experiment_2_csMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"blob_subim_proces");
          _SFD_SET_DATA_PROPS(1,1,1,0,"sub_im");
          _SFD_SET_DATA_PROPS(2,1,1,0,"limx_inf");
          _SFD_SET_DATA_PROPS(3,1,1,0,"limy_inf");
          _SFD_SET_DATA_PROPS(4,1,1,0,"im_x");
          _SFD_SET_DATA_PROPS(5,1,1,0,"im_y");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,0,0,4,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,780);
        _SFD_CV_INIT_EML_IF(0,1,0,417,446,-1,687);
        _SFD_CV_INIT_EML_IF(0,1,1,515,536,-1,683);

        {
          static int condStart[] = { 422, 437 };

          static int condEnd[] = { 429, 444 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,420,446,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 518, 529 };

          static int condEnd[] = { 525, 536 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,518,536,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,422,429,-1,3);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,437,444,-1,3);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,518,525,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,529,536,-1,1);

        {
          unsigned int dimVector[2];
          dimVector[0]= 375;
          dimVector[1]= 500;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_SINGLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c29_sf_marshallOut,(MexInFcnForType)
            c29_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 375;
          dimVector[1]= 500;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c29_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c29_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c29_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c29_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c29_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c29_b_blob_subim_proces);
        _SFD_SET_DATA_VALUE_PTR_VAR_DIM(1U, *chartInstance->c29_c_sub_im_data,
          (void *)chartInstance->c29_sub_im_sizes);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c29_limx_inf);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c29_limy_inf);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c29_im_x);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c29_im_y);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Experiment_2_csMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "Rw5gpLN6S8JgPeyilJenyF";
}

static void sf_opaque_initialize_c29_Experiment_2_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc29_Experiment_2_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c29_Experiment_2_cs((SFc29_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
  initialize_c29_Experiment_2_cs((SFc29_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c29_Experiment_2_cs(void *chartInstanceVar)
{
  enable_c29_Experiment_2_cs((SFc29_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c29_Experiment_2_cs(void *chartInstanceVar)
{
  disable_c29_Experiment_2_cs((SFc29_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c29_Experiment_2_cs(void *chartInstanceVar)
{
  sf_gateway_c29_Experiment_2_cs((SFc29_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c29_Experiment_2_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c29_Experiment_2_cs((SFc29_Experiment_2_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c29_Experiment_2_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c29_Experiment_2_cs((SFc29_Experiment_2_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c29_Experiment_2_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc29_Experiment_2_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_2_cs_optimization_info();
    }

    finalize_c29_Experiment_2_cs((SFc29_Experiment_2_csInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc29_Experiment_2_cs((SFc29_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c29_Experiment_2_cs(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c29_Experiment_2_cs((SFc29_Experiment_2_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c29_Experiment_2_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Experiment_2_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      29);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,29,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,29,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,29);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,29,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,29,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,29);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(462635111U));
  ssSetChecksum1(S,(3982579640U));
  ssSetChecksum2(S,(3582667483U));
  ssSetChecksum3(S,(4035879125U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c29_Experiment_2_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c29_Experiment_2_cs(SimStruct *S)
{
  SFc29_Experiment_2_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc29_Experiment_2_csInstanceStruct *)utMalloc(sizeof
    (SFc29_Experiment_2_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc29_Experiment_2_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c29_Experiment_2_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c29_Experiment_2_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c29_Experiment_2_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c29_Experiment_2_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c29_Experiment_2_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c29_Experiment_2_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c29_Experiment_2_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c29_Experiment_2_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c29_Experiment_2_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c29_Experiment_2_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c29_Experiment_2_cs;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->checksum = SF_RUNTIME_INFO_CHECKSUM;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  crtInfo->compiledInfo = NULL;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c29_Experiment_2_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c29_Experiment_2_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c29_Experiment_2_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c29_Experiment_2_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c29_Experiment_2_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
