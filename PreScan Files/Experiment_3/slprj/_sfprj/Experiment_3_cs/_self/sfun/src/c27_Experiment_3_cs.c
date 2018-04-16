/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_3_cs_sfun.h"
#include "c27_Experiment_3_cs.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Experiment_3_cs_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c27_b_TISdet                   (32.0)
#define c27_b_TISMaxRange              (40.0)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c27_debug_family_names[25] = { "xposit", "yposit",
  "X_offset", "Z_offset", "f", "sx", "u_max", "v_max", "i", "theta_aux", "X",
  "Y", "X_c", "Y_c", "u_r_new", "TISdet", "TISMaxRange", "nargin", "nargout",
  "flag", "theta", "range", "posit", "xs_m", "ys_m" };

/* Function Declarations */
static void initialize_c27_Experiment_3_cs(SFc27_Experiment_3_csInstanceStruct
  *chartInstance);
static void initialize_params_c27_Experiment_3_cs
  (SFc27_Experiment_3_csInstanceStruct *chartInstance);
static void enable_c27_Experiment_3_cs(SFc27_Experiment_3_csInstanceStruct
  *chartInstance);
static void disable_c27_Experiment_3_cs(SFc27_Experiment_3_csInstanceStruct
  *chartInstance);
static void c27_update_debugger_state_c27_Experiment_3_cs
  (SFc27_Experiment_3_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c27_Experiment_3_cs
  (SFc27_Experiment_3_csInstanceStruct *chartInstance);
static void set_sim_state_c27_Experiment_3_cs
  (SFc27_Experiment_3_csInstanceStruct *chartInstance, const mxArray *c27_st);
static void finalize_c27_Experiment_3_cs(SFc27_Experiment_3_csInstanceStruct
  *chartInstance);
static void sf_gateway_c27_Experiment_3_cs(SFc27_Experiment_3_csInstanceStruct
  *chartInstance);
static void mdl_start_c27_Experiment_3_cs(SFc27_Experiment_3_csInstanceStruct
  *chartInstance);
static void c27_chartstep_c27_Experiment_3_cs
  (SFc27_Experiment_3_csInstanceStruct *chartInstance);
static void initSimStructsc27_Experiment_3_cs
  (SFc27_Experiment_3_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c27_machineNumber, uint32_T
  c27_chartNumber, uint32_T c27_instanceNumber);
static const mxArray *c27_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static void c27_emlrt_marshallIn(SFc27_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c27_b_ys_m, const char_T *c27_identifier,
  real_T c27_y[32]);
static void c27_b_emlrt_marshallIn(SFc27_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
  real_T c27_y[32]);
static void c27_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static const mxArray *c27_b_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static void c27_c_emlrt_marshallIn(SFc27_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c27_b_posit, const char_T *c27_identifier,
  real_T c27_y[64]);
static void c27_d_emlrt_marshallIn(SFc27_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
  real_T c27_y[64]);
static void c27_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static const mxArray *c27_c_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static const mxArray *c27_d_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static const mxArray *c27_e_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static real_T c27_e_emlrt_marshallIn(SFc27_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void c27_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static void c27_info_helper(const mxArray **c27_info);
static const mxArray *c27_emlrt_marshallOut(const char * c27_u);
static const mxArray *c27_b_emlrt_marshallOut(const uint32_T c27_u);
static const mxArray *c27_f_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static int32_T c27_f_emlrt_marshallIn(SFc27_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void c27_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static uint8_T c27_g_emlrt_marshallIn(SFc27_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c27_b_is_active_c27_Experiment_3_cs, const
  char_T *c27_identifier);
static uint8_T c27_h_emlrt_marshallIn(SFc27_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void init_dsm_address_info(SFc27_Experiment_3_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc27_Experiment_3_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c27_Experiment_3_cs(SFc27_Experiment_3_csInstanceStruct
  *chartInstance)
{
  chartInstance->c27_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c27_is_active_c27_Experiment_3_cs = 0U;
}

static void initialize_params_c27_Experiment_3_cs
  (SFc27_Experiment_3_csInstanceStruct *chartInstance)
{
  real_T c27_d0;
  real_T c27_d1;
  sf_mex_import_named("TISdet", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c27_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c27_TISdet = c27_d0;
  sf_mex_import_named("TISMaxRange", sf_mex_get_sfun_param(chartInstance->S, 0,
    0), &c27_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c27_TISMaxRange = c27_d1;
}

static void enable_c27_Experiment_3_cs(SFc27_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c27_Experiment_3_cs(SFc27_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c27_update_debugger_state_c27_Experiment_3_cs
  (SFc27_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c27_Experiment_3_cs
  (SFc27_Experiment_3_csInstanceStruct *chartInstance)
{
  const mxArray *c27_st;
  const mxArray *c27_y = NULL;
  int32_T c27_i0;
  real_T c27_u[64];
  const mxArray *c27_b_y = NULL;
  int32_T c27_i1;
  real_T c27_b_u[32];
  const mxArray *c27_c_y = NULL;
  int32_T c27_i2;
  real_T c27_c_u[32];
  const mxArray *c27_d_y = NULL;
  uint8_T c27_hoistedGlobal;
  uint8_T c27_d_u;
  const mxArray *c27_e_y = NULL;
  c27_st = NULL;
  c27_st = NULL;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_createcellmatrix(4, 1), false);
  for (c27_i0 = 0; c27_i0 < 64; c27_i0++) {
    c27_u[c27_i0] = (*chartInstance->c27_posit)[c27_i0];
  }

  c27_b_y = NULL;
  sf_mex_assign(&c27_b_y, sf_mex_create("y", c27_u, 0, 0U, 1U, 0U, 2, 2, 32),
                false);
  sf_mex_setcell(c27_y, 0, c27_b_y);
  for (c27_i1 = 0; c27_i1 < 32; c27_i1++) {
    c27_b_u[c27_i1] = (*chartInstance->c27_xs_m)[c27_i1];
  }

  c27_c_y = NULL;
  sf_mex_assign(&c27_c_y, sf_mex_create("y", c27_b_u, 0, 0U, 1U, 0U, 2, 1, 32),
                false);
  sf_mex_setcell(c27_y, 1, c27_c_y);
  for (c27_i2 = 0; c27_i2 < 32; c27_i2++) {
    c27_c_u[c27_i2] = (*chartInstance->c27_ys_m)[c27_i2];
  }

  c27_d_y = NULL;
  sf_mex_assign(&c27_d_y, sf_mex_create("y", c27_c_u, 0, 0U, 1U, 0U, 2, 1, 32),
                false);
  sf_mex_setcell(c27_y, 2, c27_d_y);
  c27_hoistedGlobal = chartInstance->c27_is_active_c27_Experiment_3_cs;
  c27_d_u = c27_hoistedGlobal;
  c27_e_y = NULL;
  sf_mex_assign(&c27_e_y, sf_mex_create("y", &c27_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c27_y, 3, c27_e_y);
  sf_mex_assign(&c27_st, c27_y, false);
  return c27_st;
}

static void set_sim_state_c27_Experiment_3_cs
  (SFc27_Experiment_3_csInstanceStruct *chartInstance, const mxArray *c27_st)
{
  const mxArray *c27_u;
  real_T c27_dv0[64];
  int32_T c27_i3;
  real_T c27_dv1[32];
  int32_T c27_i4;
  real_T c27_dv2[32];
  int32_T c27_i5;
  chartInstance->c27_doneDoubleBufferReInit = true;
  c27_u = sf_mex_dup(c27_st);
  c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c27_u, 0)),
    "posit", c27_dv0);
  for (c27_i3 = 0; c27_i3 < 64; c27_i3++) {
    (*chartInstance->c27_posit)[c27_i3] = c27_dv0[c27_i3];
  }

  c27_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c27_u, 1)),
                       "xs_m", c27_dv1);
  for (c27_i4 = 0; c27_i4 < 32; c27_i4++) {
    (*chartInstance->c27_xs_m)[c27_i4] = c27_dv1[c27_i4];
  }

  c27_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c27_u, 2)),
                       "ys_m", c27_dv2);
  for (c27_i5 = 0; c27_i5 < 32; c27_i5++) {
    (*chartInstance->c27_ys_m)[c27_i5] = c27_dv2[c27_i5];
  }

  chartInstance->c27_is_active_c27_Experiment_3_cs = c27_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c27_u, 3)),
     "is_active_c27_Experiment_3_cs");
  sf_mex_destroy(&c27_u);
  c27_update_debugger_state_c27_Experiment_3_cs(chartInstance);
  sf_mex_destroy(&c27_st);
}

static void finalize_c27_Experiment_3_cs(SFc27_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c27_Experiment_3_cs(SFc27_Experiment_3_csInstanceStruct
  *chartInstance)
{
  int32_T c27_i6;
  int32_T c27_i7;
  int32_T c27_i8;
  int32_T c27_i9;
  int32_T c27_i10;
  int32_T c27_i11;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 26U, chartInstance->c27_sfEvent);
  for (c27_i6 = 0; c27_i6 < 32; c27_i6++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c27_flag)[c27_i6], 0U);
  }

  for (c27_i7 = 0; c27_i7 < 32; c27_i7++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c27_theta)[c27_i7], 1U);
  }

  chartInstance->c27_sfEvent = CALL_EVENT;
  c27_chartstep_c27_Experiment_3_cs(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_3_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c27_i8 = 0; c27_i8 < 64; c27_i8++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c27_posit)[c27_i8], 2U);
  }

  for (c27_i9 = 0; c27_i9 < 32; c27_i9++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c27_range)[c27_i9], 3U);
  }

  for (c27_i10 = 0; c27_i10 < 32; c27_i10++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c27_xs_m)[c27_i10], 4U);
  }

  for (c27_i11 = 0; c27_i11 < 32; c27_i11++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c27_ys_m)[c27_i11], 5U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c27_TISdet, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c27_TISMaxRange, 7U);
}

static void mdl_start_c27_Experiment_3_cs(SFc27_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c27_chartstep_c27_Experiment_3_cs
  (SFc27_Experiment_3_csInstanceStruct *chartInstance)
{
  int32_T c27_i12;
  boolean_T c27_b_flag[32];
  int32_T c27_i13;
  real_T c27_b_theta[32];
  int32_T c27_i14;
  real_T c27_b_range[32];
  uint32_T c27_debug_family_var_map[25];
  real_T c27_xposit[32];
  real_T c27_yposit[32];
  real_T c27_X_offset;
  real_T c27_Z_offset;
  real_T c27_f;
  real_T c27_sx;
  real_T c27_u_max;
  real_T c27_v_max;
  real_T c27_i;
  real_T c27_theta_aux;
  real_T c27_X;
  real_T c27_Y;
  real_T c27_X_c;
  real_T c27_Y_c;
  real_T c27_u_r_new;
  real_T c27_c_TISdet;
  real_T c27_c_TISMaxRange;
  real_T c27_nargin = 5.0;
  real_T c27_nargout = 3.0;
  real_T c27_b_posit[64];
  real_T c27_b_xs_m[32];
  real_T c27_b_ys_m[32];
  int32_T c27_i15;
  int32_T c27_i16;
  int32_T c27_i17;
  int32_T c27_i18;
  int32_T c27_i19;
  int32_T c27_b_i;
  real_T c27_d2;
  real_T c27_d3;
  real_T c27_d4;
  real_T c27_A;
  real_T c27_x;
  real_T c27_b_x;
  real_T c27_c_x;
  real_T c27_y;
  real_T c27_d_x;
  real_T c27_e_x;
  real_T c27_b_A;
  real_T c27_f_x;
  real_T c27_g_x;
  real_T c27_h_x;
  real_T c27_b_y;
  real_T c27_i_x;
  real_T c27_j_x;
  real_T c27_c_A;
  real_T c27_k_x;
  real_T c27_l_x;
  real_T c27_m_x;
  real_T c27_n_x;
  real_T c27_o_x;
  real_T c27_p_x;
  real_T c27_q_x;
  int32_T c27_i20;
  int32_T c27_i21;
  int32_T c27_i22;
  boolean_T guard1 = false;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 26U, chartInstance->c27_sfEvent);
  for (c27_i12 = 0; c27_i12 < 32; c27_i12++) {
    c27_b_flag[c27_i12] = (*chartInstance->c27_flag)[c27_i12];
  }

  for (c27_i13 = 0; c27_i13 < 32; c27_i13++) {
    c27_b_theta[c27_i13] = (*chartInstance->c27_theta)[c27_i13];
  }

  for (c27_i14 = 0; c27_i14 < 32; c27_i14++) {
    c27_b_range[c27_i14] = (*chartInstance->c27_range)[c27_i14];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 25U, 25U, c27_debug_family_names,
    c27_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c27_xposit, 0U, c27_sf_marshallOut,
    c27_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c27_yposit, 1U, c27_sf_marshallOut,
    c27_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_X_offset, 2U, c27_e_sf_marshallOut,
    c27_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_Z_offset, 3U, c27_e_sf_marshallOut,
    c27_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c27_f, 4U, c27_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c27_sx, 5U, c27_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c27_u_max, 6U, c27_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_v_max, 7U, c27_e_sf_marshallOut,
    c27_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_i, 8U, c27_e_sf_marshallOut,
    c27_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_theta_aux, 9U, c27_e_sf_marshallOut,
    c27_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_X, 10U, c27_e_sf_marshallOut,
    c27_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_Y, 11U, c27_e_sf_marshallOut,
    c27_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_X_c, 12U, c27_e_sf_marshallOut,
    c27_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_Y_c, 13U, c27_e_sf_marshallOut,
    c27_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_u_r_new, 14U, c27_e_sf_marshallOut,
    c27_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c27_c_TISdet, 15U, c27_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c27_c_TISMaxRange, 16U, c27_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_nargin, 17U, c27_e_sf_marshallOut,
    c27_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_nargout, 18U, c27_e_sf_marshallOut,
    c27_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c27_b_flag, 19U, c27_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c27_b_theta, 20U, c27_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c27_b_range, 21U, c27_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c27_b_posit, 22U, c27_b_sf_marshallOut,
    c27_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c27_b_xs_m, 23U, c27_sf_marshallOut,
    c27_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c27_b_ys_m, 24U, c27_sf_marshallOut,
    c27_sf_marshallIn);
  c27_c_TISMaxRange = c27_b_TISMaxRange;
  c27_c_TISdet = c27_b_TISdet;
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 3);
  for (c27_i15 = 0; c27_i15 < 32; c27_i15++) {
    c27_xposit[c27_i15] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 4);
  for (c27_i16 = 0; c27_i16 < 32; c27_i16++) {
    c27_yposit[c27_i16] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 5);
  for (c27_i17 = 0; c27_i17 < 64; c27_i17++) {
    c27_b_posit[c27_i17] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 6);
  for (c27_i18 = 0; c27_i18 < 32; c27_i18++) {
    c27_b_xs_m[c27_i18] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 7);
  for (c27_i19 = 0; c27_i19 < 32; c27_i19++) {
    c27_b_ys_m[c27_i19] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 8);
  c27_X_offset = 2.0;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 9);
  c27_Z_offset = -0.8600000000000001;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 11);
  c27_f = 0.0075;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 12);
  c27_sx = 0.0048;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 14);
  c27_u_max = 15.693484664142458;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 15);
  c27_v_max = 36.792859892869508;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 17);
  c27_i = 1.0;
  c27_b_i = 0;
  while (c27_b_i < 32) {
    c27_i = 1.0 + (real_T)c27_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 18);
    c27_d2 = (real_T)c27_b_flag[_SFD_EML_ARRAY_BOUNDS_CHECK("flag", (int32_T)
      _SFD_INTEGER_CHECK("i", c27_i), 1, 32, 1, 0) - 1];
    guard1 = false;
    if (CV_EML_COND(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c27_d2, 0.0, -1, 0U,
          c27_d2 == 0.0))) {
      guard1 = true;
    } else {
      c27_d3 = c27_b_theta[_SFD_EML_ARRAY_BOUNDS_CHECK("theta", (int32_T)
        _SFD_INTEGER_CHECK("i", c27_i), 1, 32, 1, 0) - 1];
      if (CV_EML_COND(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c27_d3, 0.0, -1, 0U,
            c27_d3 == 0.0))) {
        guard1 = true;
      } else {
        CV_EML_MCDC(0, 1, 0, false);
        CV_EML_IF(0, 1, 0, false);
        _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 21);
        c27_d4 = (real_T)c27_b_flag[_SFD_EML_ARRAY_BOUNDS_CHECK("flag", (int32_T)
          _SFD_INTEGER_CHECK("i", c27_i), 1, 32, 1, 0) - 1];
        if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 2, c27_d4, 0.0, -1, 1U,
              c27_d4 != 0.0))) {
          _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 22);
          c27_theta_aux = -c27_b_theta[_SFD_EML_ARRAY_BOUNDS_CHECK("theta",
            (int32_T)_SFD_INTEGER_CHECK("i", c27_i), 1, 32, 1, 0) - 1];
          _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 24);
          c27_A = c27_theta_aux * 3.1415926535897931;
          c27_x = c27_A;
          c27_b_x = c27_x;
          c27_c_x = c27_b_x;
          c27_y = c27_c_x / 180.0;
          c27_d_x = c27_y;
          c27_e_x = c27_d_x;
          c27_e_x = muDoubleScalarCos(c27_e_x);
          c27_X = c27_b_range[_SFD_EML_ARRAY_BOUNDS_CHECK("range", (int32_T)
            _SFD_INTEGER_CHECK("i", c27_i), 1, 32, 1, 0) - 1] * c27_e_x;
          _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 25);
          c27_b_A = c27_theta_aux * 3.1415926535897931;
          c27_f_x = c27_b_A;
          c27_g_x = c27_f_x;
          c27_h_x = c27_g_x;
          c27_b_y = c27_h_x / 180.0;
          c27_i_x = c27_b_y;
          c27_j_x = c27_i_x;
          c27_j_x = muDoubleScalarSin(c27_j_x);
          c27_Y = c27_b_range[_SFD_EML_ARRAY_BOUNDS_CHECK("range", (int32_T)
            _SFD_INTEGER_CHECK("i", c27_i), 1, 32, 1, 0) - 1] * c27_j_x;
          _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 27);
          c27_b_xs_m[_SFD_EML_ARRAY_BOUNDS_CHECK("xs_m", (int32_T)
            _SFD_INTEGER_CHECK("i", c27_i), 1, 32, 1, 0) - 1] = c27_Y;
          _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 28);
          c27_b_ys_m[_SFD_EML_ARRAY_BOUNDS_CHECK("ys_m", (int32_T)
            _SFD_INTEGER_CHECK("i", c27_i), 1, 32, 1, 0) - 1] = c27_X;
          _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 30);
          c27_X_c = c27_X + c27_X_offset;
          _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 31);
          c27_Y_c = c27_Y;
          _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 34);
          c27_c_A = c27_Y * 0.0075 * 500.0;
          c27_k_x = c27_c_A;
          c27_l_x = c27_k_x;
          c27_m_x = c27_l_x;
          c27_u_r_new = c27_m_x / 0.0753287263878838;
          _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 37);
          c27_xposit[_SFD_EML_ARRAY_BOUNDS_CHECK("xposit", (int32_T)
            _SFD_INTEGER_CHECK("i", c27_i), 1, 32, 1, 0) - 1] = 250.0 +
            c27_u_r_new;
          _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 38);
          c27_yposit[_SFD_EML_ARRAY_BOUNDS_CHECK("yposit", (int32_T)
            _SFD_INTEGER_CHECK("i", c27_i), 1, 32, 1, 0) - 1] = 188.0;
        }
      }
    }

    if (guard1 == true) {
      CV_EML_MCDC(0, 1, 0, true);
      CV_EML_IF(0, 1, 0, true);
      _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 19);
      c27_xposit[_SFD_EML_ARRAY_BOUNDS_CHECK("xposit", (int32_T)
        _SFD_INTEGER_CHECK("i", c27_i), 1, 32, 1, 0) - 1] = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 20);
      c27_b_posit[(_SFD_EML_ARRAY_BOUNDS_CHECK("posit", (int32_T)
        _SFD_INTEGER_CHECK("i", c27_i), 1, 32, 2, 0) - 1) << 1] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 40);
    c27_n_x = c27_xposit[_SFD_EML_ARRAY_BOUNDS_CHECK("xposit", (int32_T)
      _SFD_INTEGER_CHECK("i", c27_i), 1, 32, 1, 0) - 1];
    c27_o_x = c27_n_x;
    c27_o_x = muDoubleScalarRound(c27_o_x);
    c27_b_posit[1 + ((_SFD_EML_ARRAY_BOUNDS_CHECK("posit", (int32_T)
      _SFD_INTEGER_CHECK("i", c27_i), 1, 32, 2, 0) - 1) << 1)] = c27_o_x;
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 41);
    c27_p_x = c27_yposit[_SFD_EML_ARRAY_BOUNDS_CHECK("yposit", (int32_T)
      _SFD_INTEGER_CHECK("i", c27_i), 1, 32, 1, 0) - 1];
    c27_q_x = c27_p_x;
    c27_q_x = muDoubleScalarRound(c27_q_x);
    c27_b_posit[(_SFD_EML_ARRAY_BOUNDS_CHECK("posit", (int32_T)
      _SFD_INTEGER_CHECK("i", c27_i), 1, 32, 2, 0) - 1) << 1] = c27_q_x;
    c27_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, -41);
  _SFD_SYMBOL_SCOPE_POP();
  for (c27_i20 = 0; c27_i20 < 64; c27_i20++) {
    (*chartInstance->c27_posit)[c27_i20] = c27_b_posit[c27_i20];
  }

  for (c27_i21 = 0; c27_i21 < 32; c27_i21++) {
    (*chartInstance->c27_xs_m)[c27_i21] = c27_b_xs_m[c27_i21];
  }

  for (c27_i22 = 0; c27_i22 < 32; c27_i22++) {
    (*chartInstance->c27_ys_m)[c27_i22] = c27_b_ys_m[c27_i22];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 26U, chartInstance->c27_sfEvent);
}

static void initSimStructsc27_Experiment_3_cs
  (SFc27_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c27_machineNumber, uint32_T
  c27_chartNumber, uint32_T c27_instanceNumber)
{
  (void)c27_machineNumber;
  (void)c27_chartNumber;
  (void)c27_instanceNumber;
}

static const mxArray *c27_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_i23;
  real_T c27_b_inData[32];
  int32_T c27_i24;
  real_T c27_u[32];
  const mxArray *c27_y = NULL;
  SFc27_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc27_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  for (c27_i23 = 0; c27_i23 < 32; c27_i23++) {
    c27_b_inData[c27_i23] = (*(real_T (*)[32])c27_inData)[c27_i23];
  }

  for (c27_i24 = 0; c27_i24 < 32; c27_i24++) {
    c27_u[c27_i24] = c27_b_inData[c27_i24];
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 0, 0U, 1U, 0U, 2, 1, 32),
                false);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

static void c27_emlrt_marshallIn(SFc27_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c27_b_ys_m, const char_T *c27_identifier,
  real_T c27_y[32])
{
  emlrtMsgIdentifier c27_thisId;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_b_ys_m), &c27_thisId,
    c27_y);
  sf_mex_destroy(&c27_b_ys_m);
}

static void c27_b_emlrt_marshallIn(SFc27_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
  real_T c27_y[32])
{
  real_T c27_dv3[32];
  int32_T c27_i25;
  (void)chartInstance;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), c27_dv3, 1, 0, 0U, 1, 0U, 2, 1,
                32);
  for (c27_i25 = 0; c27_i25 < 32; c27_i25++) {
    c27_y[c27_i25] = c27_dv3[c27_i25];
  }

  sf_mex_destroy(&c27_u);
}

static void c27_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_b_ys_m;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  real_T c27_y[32];
  int32_T c27_i26;
  SFc27_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc27_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c27_b_ys_m = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_b_ys_m), &c27_thisId,
    c27_y);
  sf_mex_destroy(&c27_b_ys_m);
  for (c27_i26 = 0; c27_i26 < 32; c27_i26++) {
    (*(real_T (*)[32])c27_outData)[c27_i26] = c27_y[c27_i26];
  }

  sf_mex_destroy(&c27_mxArrayInData);
}

static const mxArray *c27_b_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_i27;
  int32_T c27_i28;
  int32_T c27_i29;
  real_T c27_b_inData[64];
  int32_T c27_i30;
  int32_T c27_i31;
  int32_T c27_i32;
  real_T c27_u[64];
  const mxArray *c27_y = NULL;
  SFc27_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc27_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_i27 = 0;
  for (c27_i28 = 0; c27_i28 < 32; c27_i28++) {
    for (c27_i29 = 0; c27_i29 < 2; c27_i29++) {
      c27_b_inData[c27_i29 + c27_i27] = (*(real_T (*)[64])c27_inData)[c27_i29 +
        c27_i27];
    }

    c27_i27 += 2;
  }

  c27_i30 = 0;
  for (c27_i31 = 0; c27_i31 < 32; c27_i31++) {
    for (c27_i32 = 0; c27_i32 < 2; c27_i32++) {
      c27_u[c27_i32 + c27_i30] = c27_b_inData[c27_i32 + c27_i30];
    }

    c27_i30 += 2;
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 0, 0U, 1U, 0U, 2, 2, 32),
                false);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

static void c27_c_emlrt_marshallIn(SFc27_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c27_b_posit, const char_T *c27_identifier,
  real_T c27_y[64])
{
  emlrtMsgIdentifier c27_thisId;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_b_posit), &c27_thisId,
    c27_y);
  sf_mex_destroy(&c27_b_posit);
}

static void c27_d_emlrt_marshallIn(SFc27_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
  real_T c27_y[64])
{
  real_T c27_dv4[64];
  int32_T c27_i33;
  (void)chartInstance;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), c27_dv4, 1, 0, 0U, 1, 0U, 2, 2,
                32);
  for (c27_i33 = 0; c27_i33 < 64; c27_i33++) {
    c27_y[c27_i33] = c27_dv4[c27_i33];
  }

  sf_mex_destroy(&c27_u);
}

static void c27_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_b_posit;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  real_T c27_y[64];
  int32_T c27_i34;
  int32_T c27_i35;
  int32_T c27_i36;
  SFc27_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc27_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c27_b_posit = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_b_posit), &c27_thisId,
    c27_y);
  sf_mex_destroy(&c27_b_posit);
  c27_i34 = 0;
  for (c27_i35 = 0; c27_i35 < 32; c27_i35++) {
    for (c27_i36 = 0; c27_i36 < 2; c27_i36++) {
      (*(real_T (*)[64])c27_outData)[c27_i36 + c27_i34] = c27_y[c27_i36 +
        c27_i34];
    }

    c27_i34 += 2;
  }

  sf_mex_destroy(&c27_mxArrayInData);
}

static const mxArray *c27_c_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_i37;
  real_T c27_b_inData[32];
  int32_T c27_i38;
  real_T c27_u[32];
  const mxArray *c27_y = NULL;
  SFc27_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc27_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  for (c27_i37 = 0; c27_i37 < 32; c27_i37++) {
    c27_b_inData[c27_i37] = (*(real_T (*)[32])c27_inData)[c27_i37];
  }

  for (c27_i38 = 0; c27_i38 < 32; c27_i38++) {
    c27_u[c27_i38] = c27_b_inData[c27_i38];
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 0, 0U, 1U, 0U, 1, 32), false);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

static const mxArray *c27_d_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_i39;
  boolean_T c27_b_inData[32];
  int32_T c27_i40;
  boolean_T c27_u[32];
  const mxArray *c27_y = NULL;
  SFc27_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc27_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  for (c27_i39 = 0; c27_i39 < 32; c27_i39++) {
    c27_b_inData[c27_i39] = (*(boolean_T (*)[32])c27_inData)[c27_i39];
  }

  for (c27_i40 = 0; c27_i40 < 32; c27_i40++) {
    c27_u[c27_i40] = c27_b_inData[c27_i40];
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 11, 0U, 1U, 0U, 1, 32), false);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

static const mxArray *c27_e_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  real_T c27_u;
  const mxArray *c27_y = NULL;
  SFc27_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc27_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_u = *(real_T *)c27_inData;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", &c27_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

static real_T c27_e_emlrt_marshallIn(SFc27_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  real_T c27_y;
  real_T c27_d5;
  (void)chartInstance;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_d5, 1, 0, 0U, 0, 0U, 0);
  c27_y = c27_d5;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void c27_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_nargout;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  real_T c27_y;
  SFc27_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc27_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c27_nargout = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_nargout),
    &c27_thisId);
  sf_mex_destroy(&c27_nargout);
  *(real_T *)c27_outData = c27_y;
  sf_mex_destroy(&c27_mxArrayInData);
}

const mxArray *sf_c27_Experiment_3_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c27_nameCaptureInfo = NULL;
  c27_nameCaptureInfo = NULL;
  sf_mex_assign(&c27_nameCaptureInfo, sf_mex_createstruct("structure", 2, 14, 1),
                false);
  c27_info_helper(&c27_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c27_nameCaptureInfo);
  return c27_nameCaptureInfo;
}

static void c27_info_helper(const mxArray **c27_info)
{
  const mxArray *c27_rhs0 = NULL;
  const mxArray *c27_lhs0 = NULL;
  const mxArray *c27_rhs1 = NULL;
  const mxArray *c27_lhs1 = NULL;
  const mxArray *c27_rhs2 = NULL;
  const mxArray *c27_lhs2 = NULL;
  const mxArray *c27_rhs3 = NULL;
  const mxArray *c27_lhs3 = NULL;
  const mxArray *c27_rhs4 = NULL;
  const mxArray *c27_lhs4 = NULL;
  const mxArray *c27_rhs5 = NULL;
  const mxArray *c27_lhs5 = NULL;
  const mxArray *c27_rhs6 = NULL;
  const mxArray *c27_lhs6 = NULL;
  const mxArray *c27_rhs7 = NULL;
  const mxArray *c27_lhs7 = NULL;
  const mxArray *c27_rhs8 = NULL;
  const mxArray *c27_lhs8 = NULL;
  const mxArray *c27_rhs9 = NULL;
  const mxArray *c27_lhs9 = NULL;
  const mxArray *c27_rhs10 = NULL;
  const mxArray *c27_lhs10 = NULL;
  const mxArray *c27_rhs11 = NULL;
  const mxArray *c27_lhs11 = NULL;
  const mxArray *c27_rhs12 = NULL;
  const mxArray *c27_lhs12 = NULL;
  const mxArray *c27_rhs13 = NULL;
  const mxArray *c27_lhs13 = NULL;
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c27_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c27_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c27_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c27_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c27_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c27_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c27_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("sin"), "name", "name", 7);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1395346504U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c27_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 8);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1286840336U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c27_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "context", "context", 9);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("cos"), "name", "name", 9);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1395346496U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c27_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 10);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1286840322U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c27_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "context", "context", 11);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("round"), "name", "name", 11);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c27_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 12);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c27_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalar_round"), "name",
                  "name", 13);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1307672838U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c27_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs13), "lhs", "lhs",
                  13);
  sf_mex_destroy(&c27_rhs0);
  sf_mex_destroy(&c27_lhs0);
  sf_mex_destroy(&c27_rhs1);
  sf_mex_destroy(&c27_lhs1);
  sf_mex_destroy(&c27_rhs2);
  sf_mex_destroy(&c27_lhs2);
  sf_mex_destroy(&c27_rhs3);
  sf_mex_destroy(&c27_lhs3);
  sf_mex_destroy(&c27_rhs4);
  sf_mex_destroy(&c27_lhs4);
  sf_mex_destroy(&c27_rhs5);
  sf_mex_destroy(&c27_lhs5);
  sf_mex_destroy(&c27_rhs6);
  sf_mex_destroy(&c27_lhs6);
  sf_mex_destroy(&c27_rhs7);
  sf_mex_destroy(&c27_lhs7);
  sf_mex_destroy(&c27_rhs8);
  sf_mex_destroy(&c27_lhs8);
  sf_mex_destroy(&c27_rhs9);
  sf_mex_destroy(&c27_lhs9);
  sf_mex_destroy(&c27_rhs10);
  sf_mex_destroy(&c27_lhs10);
  sf_mex_destroy(&c27_rhs11);
  sf_mex_destroy(&c27_lhs11);
  sf_mex_destroy(&c27_rhs12);
  sf_mex_destroy(&c27_lhs12);
  sf_mex_destroy(&c27_rhs13);
  sf_mex_destroy(&c27_lhs13);
}

static const mxArray *c27_emlrt_marshallOut(const char * c27_u)
{
  const mxArray *c27_y = NULL;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c27_u)), false);
  return c27_y;
}

static const mxArray *c27_b_emlrt_marshallOut(const uint32_T c27_u)
{
  const mxArray *c27_y = NULL;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", &c27_u, 7, 0U, 0U, 0U, 0), false);
  return c27_y;
}

static const mxArray *c27_f_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_u;
  const mxArray *c27_y = NULL;
  SFc27_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc27_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_u = *(int32_T *)c27_inData;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", &c27_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

static int32_T c27_f_emlrt_marshallIn(SFc27_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  int32_T c27_y;
  int32_T c27_i41;
  (void)chartInstance;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_i41, 1, 6, 0U, 0, 0U, 0);
  c27_y = c27_i41;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void c27_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_b_sfEvent;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  int32_T c27_y;
  SFc27_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc27_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c27_b_sfEvent = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_b_sfEvent),
    &c27_thisId);
  sf_mex_destroy(&c27_b_sfEvent);
  *(int32_T *)c27_outData = c27_y;
  sf_mex_destroy(&c27_mxArrayInData);
}

static uint8_T c27_g_emlrt_marshallIn(SFc27_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c27_b_is_active_c27_Experiment_3_cs, const
  char_T *c27_identifier)
{
  uint8_T c27_y;
  emlrtMsgIdentifier c27_thisId;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c27_b_is_active_c27_Experiment_3_cs), &c27_thisId);
  sf_mex_destroy(&c27_b_is_active_c27_Experiment_3_cs);
  return c27_y;
}

static uint8_T c27_h_emlrt_marshallIn(SFc27_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  uint8_T c27_y;
  uint8_T c27_u0;
  (void)chartInstance;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_u0, 1, 3, 0U, 0, 0U, 0);
  c27_y = c27_u0;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void init_dsm_address_info(SFc27_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc27_Experiment_3_csInstanceStruct
  *chartInstance)
{
  chartInstance->c27_flag = (boolean_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c27_theta = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c27_posit = (real_T (*)[64])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c27_range = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c27_xs_m = (real_T (*)[32])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c27_ys_m = (real_T (*)[32])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
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

void sf_c27_Experiment_3_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4162793749U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1304066080U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(605573733U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1103894961U);
}

mxArray* sf_c27_Experiment_3_cs_get_post_codegen_info(void);
mxArray *sf_c27_Experiment_3_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("WN7VlkbZNCTMN6eJEb1rXH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(32);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(32);
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
      pr[0] = (double)(32);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(32);
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
      pr[1] = (double)(32);
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
      pr[1] = (double)(32);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c27_Experiment_3_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c27_Experiment_3_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c27_Experiment_3_cs_jit_fallback_info(void)
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

mxArray *sf_c27_Experiment_3_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c27_Experiment_3_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c27_Experiment_3_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[5],T\"posit\",},{M[1],M[20],T\"xs_m\",},{M[1],M[21],T\"ys_m\",},{M[8],M[0],T\"is_active_c27_Experiment_3_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c27_Experiment_3_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc27_Experiment_3_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc27_Experiment_3_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_3_csMachineNumber_,
           27,
           1,
           1,
           0,
           8,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_Experiment_3_csMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Experiment_3_csMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Experiment_3_csMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"flag");
          _SFD_SET_DATA_PROPS(1,1,1,0,"theta");
          _SFD_SET_DATA_PROPS(2,2,0,1,"posit");
          _SFD_SET_DATA_PROPS(3,1,1,0,"range");
          _SFD_SET_DATA_PROPS(4,2,0,1,"xs_m");
          _SFD_SET_DATA_PROPS(5,2,0,1,"ys_m");
          _SFD_SET_DATA_PROPS(6,10,0,0,"TISdet");
          _SFD_SET_DATA_PROPS(7,10,0,0,"TISMaxRange");
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
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,1,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1387);
        _SFD_CV_INIT_EML_IF(0,1,0,747,779,831,850);
        _SFD_CV_INIT_EML_IF(0,1,1,831,850,-1,850);
        _SFD_CV_INIT_EML_FOR(0,1,0,728,743,1383);

        {
          static int condStart[] = { 751, 767 };

          static int condEnd[] = { 761, 778 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,750,779,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,751,761,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,767,778,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,839,849,-1,1);

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c27_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c27_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c27_b_sf_marshallOut,(MexInFcnForType)
            c27_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c27_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c27_sf_marshallOut,(MexInFcnForType)
            c27_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c27_sf_marshallOut,(MexInFcnForType)
            c27_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_e_sf_marshallOut,(MexInFcnForType)
          c27_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_e_sf_marshallOut,(MexInFcnForType)
          c27_c_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c27_flag);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c27_theta);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c27_posit);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c27_range);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c27_xs_m);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c27_ys_m);
        _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c27_TISdet);
        _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c27_TISMaxRange);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Experiment_3_csMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "oWALyYEQMgo1riZhlfcqgC";
}

static void sf_opaque_initialize_c27_Experiment_3_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc27_Experiment_3_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c27_Experiment_3_cs((SFc27_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
  initialize_c27_Experiment_3_cs((SFc27_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c27_Experiment_3_cs(void *chartInstanceVar)
{
  enable_c27_Experiment_3_cs((SFc27_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c27_Experiment_3_cs(void *chartInstanceVar)
{
  disable_c27_Experiment_3_cs((SFc27_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c27_Experiment_3_cs(void *chartInstanceVar)
{
  sf_gateway_c27_Experiment_3_cs((SFc27_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c27_Experiment_3_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c27_Experiment_3_cs((SFc27_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c27_Experiment_3_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c27_Experiment_3_cs((SFc27_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c27_Experiment_3_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc27_Experiment_3_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_3_cs_optimization_info();
    }

    finalize_c27_Experiment_3_cs((SFc27_Experiment_3_csInstanceStruct*)
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
  initSimStructsc27_Experiment_3_cs((SFc27_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c27_Experiment_3_cs(SimStruct *S)
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
    initialize_params_c27_Experiment_3_cs((SFc27_Experiment_3_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c27_Experiment_3_cs(SimStruct *S)
{
  /* Actual parameters from chart:
     TISMaxRange TISdet
   */
  const char_T *rtParamNames[] = { "TISMaxRange", "TISdet" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for TISMaxRange*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for TISdet*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Experiment_3_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      27);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,27,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,27,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,27);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,27,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,27,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,27);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1464584826U));
  ssSetChecksum1(S,(2577037637U));
  ssSetChecksum2(S,(3270500961U));
  ssSetChecksum3(S,(3446759083U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c27_Experiment_3_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c27_Experiment_3_cs(SimStruct *S)
{
  SFc27_Experiment_3_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc27_Experiment_3_csInstanceStruct *)utMalloc(sizeof
    (SFc27_Experiment_3_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc27_Experiment_3_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c27_Experiment_3_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c27_Experiment_3_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c27_Experiment_3_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c27_Experiment_3_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c27_Experiment_3_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c27_Experiment_3_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c27_Experiment_3_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c27_Experiment_3_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c27_Experiment_3_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c27_Experiment_3_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c27_Experiment_3_cs;
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

void c27_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c27_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c27_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c27_Experiment_3_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c27_Experiment_3_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
