/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_3_cs_sfun.h"
#include "c30_Experiment_3_cs.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Experiment_3_cs_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c30_b_TISdet                   (32.0)
#define c30_b_TISMaxRange              (40.0)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c30_debug_family_names[14] = { "d", "i", "s", "suma", "j",
  "TISdet", "TISMaxRange", "nargin", "nargout", "r", "yp1", "K1", "yp2", "K2" };

/* Function Declarations */
static void initialize_c30_Experiment_3_cs(SFc30_Experiment_3_csInstanceStruct
  *chartInstance);
static void initialize_params_c30_Experiment_3_cs
  (SFc30_Experiment_3_csInstanceStruct *chartInstance);
static void enable_c30_Experiment_3_cs(SFc30_Experiment_3_csInstanceStruct
  *chartInstance);
static void disable_c30_Experiment_3_cs(SFc30_Experiment_3_csInstanceStruct
  *chartInstance);
static void c30_update_debugger_state_c30_Experiment_3_cs
  (SFc30_Experiment_3_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c30_Experiment_3_cs
  (SFc30_Experiment_3_csInstanceStruct *chartInstance);
static void set_sim_state_c30_Experiment_3_cs
  (SFc30_Experiment_3_csInstanceStruct *chartInstance, const mxArray *c30_st);
static void finalize_c30_Experiment_3_cs(SFc30_Experiment_3_csInstanceStruct
  *chartInstance);
static void sf_gateway_c30_Experiment_3_cs(SFc30_Experiment_3_csInstanceStruct
  *chartInstance);
static void mdl_start_c30_Experiment_3_cs(SFc30_Experiment_3_csInstanceStruct
  *chartInstance);
static void c30_chartstep_c30_Experiment_3_cs
  (SFc30_Experiment_3_csInstanceStruct *chartInstance);
static void initSimStructsc30_Experiment_3_cs
  (SFc30_Experiment_3_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c30_machineNumber, uint32_T
  c30_chartNumber, uint32_T c30_instanceNumber);
static const mxArray *c30_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData);
static void c30_emlrt_marshallIn(SFc30_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c30_b_K2, const char_T *c30_identifier, real_T
  c30_y[1600]);
static void c30_b_emlrt_marshallIn(SFc30_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId,
  real_T c30_y[1600]);
static void c30_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData);
static const mxArray *c30_b_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData);
static void c30_c_emlrt_marshallIn(SFc30_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c30_b_yp2, const char_T *c30_identifier, real_T
  c30_y[32]);
static void c30_d_emlrt_marshallIn(SFc30_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId,
  real_T c30_y[32]);
static void c30_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData);
static const mxArray *c30_c_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData);
static real_T c30_e_emlrt_marshallIn(SFc30_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId);
static void c30_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData);
static void c30_info_helper(const mxArray **c30_info);
static const mxArray *c30_emlrt_marshallOut(const char * c30_u);
static const mxArray *c30_b_emlrt_marshallOut(const uint32_T c30_u);
static const mxArray *c30_d_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData);
static int32_T c30_f_emlrt_marshallIn(SFc30_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId);
static void c30_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData);
static uint8_T c30_g_emlrt_marshallIn(SFc30_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c30_b_is_active_c30_Experiment_3_cs, const
  char_T *c30_identifier);
static uint8_T c30_h_emlrt_marshallIn(SFc30_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId);
static void init_dsm_address_info(SFc30_Experiment_3_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc30_Experiment_3_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c30_Experiment_3_cs(SFc30_Experiment_3_csInstanceStruct
  *chartInstance)
{
  chartInstance->c30_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c30_is_active_c30_Experiment_3_cs = 0U;
}

static void initialize_params_c30_Experiment_3_cs
  (SFc30_Experiment_3_csInstanceStruct *chartInstance)
{
  real_T c30_d0;
  real_T c30_d1;
  sf_mex_import_named("TISdet", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c30_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c30_TISdet = c30_d0;
  sf_mex_import_named("TISMaxRange", sf_mex_get_sfun_param(chartInstance->S, 0,
    0), &c30_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c30_TISMaxRange = c30_d1;
}

static void enable_c30_Experiment_3_cs(SFc30_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c30_Experiment_3_cs(SFc30_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c30_update_debugger_state_c30_Experiment_3_cs
  (SFc30_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c30_Experiment_3_cs
  (SFc30_Experiment_3_csInstanceStruct *chartInstance)
{
  const mxArray *c30_st;
  const mxArray *c30_y = NULL;
  int32_T c30_i0;
  real_T c30_u[1600];
  const mxArray *c30_b_y = NULL;
  int32_T c30_i1;
  real_T c30_b_u[32];
  const mxArray *c30_c_y = NULL;
  uint8_T c30_hoistedGlobal;
  uint8_T c30_c_u;
  const mxArray *c30_d_y = NULL;
  c30_st = NULL;
  c30_st = NULL;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_createcellmatrix(3, 1), false);
  for (c30_i0 = 0; c30_i0 < 1600; c30_i0++) {
    c30_u[c30_i0] = (*chartInstance->c30_K2)[c30_i0];
  }

  c30_b_y = NULL;
  sf_mex_assign(&c30_b_y, sf_mex_create("y", c30_u, 0, 0U, 1U, 0U, 2, 32, 50),
                false);
  sf_mex_setcell(c30_y, 0, c30_b_y);
  for (c30_i1 = 0; c30_i1 < 32; c30_i1++) {
    c30_b_u[c30_i1] = (*chartInstance->c30_yp2)[c30_i1];
  }

  c30_c_y = NULL;
  sf_mex_assign(&c30_c_y, sf_mex_create("y", c30_b_u, 0, 0U, 1U, 0U, 1, 32),
                false);
  sf_mex_setcell(c30_y, 1, c30_c_y);
  c30_hoistedGlobal = chartInstance->c30_is_active_c30_Experiment_3_cs;
  c30_c_u = c30_hoistedGlobal;
  c30_d_y = NULL;
  sf_mex_assign(&c30_d_y, sf_mex_create("y", &c30_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c30_y, 2, c30_d_y);
  sf_mex_assign(&c30_st, c30_y, false);
  return c30_st;
}

static void set_sim_state_c30_Experiment_3_cs
  (SFc30_Experiment_3_csInstanceStruct *chartInstance, const mxArray *c30_st)
{
  const mxArray *c30_u;
  real_T c30_dv0[1600];
  int32_T c30_i2;
  real_T c30_dv1[32];
  int32_T c30_i3;
  chartInstance->c30_doneDoubleBufferReInit = true;
  c30_u = sf_mex_dup(c30_st);
  c30_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c30_u, 0)), "K2",
                       c30_dv0);
  for (c30_i2 = 0; c30_i2 < 1600; c30_i2++) {
    (*chartInstance->c30_K2)[c30_i2] = c30_dv0[c30_i2];
  }

  c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c30_u, 1)),
    "yp2", c30_dv1);
  for (c30_i3 = 0; c30_i3 < 32; c30_i3++) {
    (*chartInstance->c30_yp2)[c30_i3] = c30_dv1[c30_i3];
  }

  chartInstance->c30_is_active_c30_Experiment_3_cs = c30_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c30_u, 2)),
     "is_active_c30_Experiment_3_cs");
  sf_mex_destroy(&c30_u);
  c30_update_debugger_state_c30_Experiment_3_cs(chartInstance);
  sf_mex_destroy(&c30_st);
}

static void finalize_c30_Experiment_3_cs(SFc30_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c30_Experiment_3_cs(SFc30_Experiment_3_csInstanceStruct
  *chartInstance)
{
  int32_T c30_i4;
  int32_T c30_i5;
  int32_T c30_i6;
  int32_T c30_i7;
  int32_T c30_i8;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 29U, chartInstance->c30_sfEvent);
  for (c30_i4 = 0; c30_i4 < 32; c30_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c30_r)[c30_i4], 0U);
  }

  chartInstance->c30_sfEvent = CALL_EVENT;
  c30_chartstep_c30_Experiment_3_cs(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_3_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c30_i5 = 0; c30_i5 < 32; c30_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c30_yp2)[c30_i5], 1U);
  }

  for (c30_i6 = 0; c30_i6 < 32; c30_i6++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c30_yp1)[c30_i6], 2U);
  }

  for (c30_i7 = 0; c30_i7 < 1600; c30_i7++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c30_K1)[c30_i7], 3U);
  }

  for (c30_i8 = 0; c30_i8 < 1600; c30_i8++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c30_K2)[c30_i8], 4U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c30_TISdet, 5U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c30_TISMaxRange, 6U);
}

static void mdl_start_c30_Experiment_3_cs(SFc30_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c30_chartstep_c30_Experiment_3_cs
  (SFc30_Experiment_3_csInstanceStruct *chartInstance)
{
  int32_T c30_i9;
  real_T c30_b_r[32];
  int32_T c30_i10;
  real_T c30_b_yp1[32];
  int32_T c30_i11;
  real_T c30_b_K1[1600];
  uint32_T c30_debug_family_var_map[14];
  real_T c30_d;
  real_T c30_i;
  real_T c30_s;
  real_T c30_suma;
  real_T c30_j;
  real_T c30_c_TISdet;
  real_T c30_c_TISMaxRange;
  real_T c30_nargin = 5.0;
  real_T c30_nargout = 2.0;
  real_T c30_b_yp2[32];
  real_T c30_b_K2[1600];
  int32_T c30_i12;
  int32_T c30_i13;
  int32_T c30_b_i;
  real_T c30_d2;
  int32_T c30_c_i;
  int32_T c30_d_i;
  int32_T c30_i14;
  real_T c30_c_K2[49];
  int32_T c30_i15;
  int32_T c30_e_i;
  int32_T c30_b_j;
  real_T c30_d3;
  real_T c30_A;
  real_T c30_B;
  real_T c30_x;
  real_T c30_y;
  real_T c30_b_x;
  real_T c30_b_y;
  real_T c30_c_x;
  real_T c30_c_y;
  real_T c30_d_y;
  int32_T c30_f_i;
  real_T c30_d4;
  real_T c30_d5;
  int32_T c30_g_i;
  int32_T c30_i16;
  int32_T c30_i17;
  int32_T c30_i18;
  boolean_T guard1 = false;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 29U, chartInstance->c30_sfEvent);
  for (c30_i9 = 0; c30_i9 < 32; c30_i9++) {
    c30_b_r[c30_i9] = (*chartInstance->c30_r)[c30_i9];
  }

  for (c30_i10 = 0; c30_i10 < 32; c30_i10++) {
    c30_b_yp1[c30_i10] = (*chartInstance->c30_yp1)[c30_i10];
  }

  for (c30_i11 = 0; c30_i11 < 1600; c30_i11++) {
    c30_b_K1[c30_i11] = (*chartInstance->c30_K1)[c30_i11];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 14U, c30_debug_family_names,
    c30_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c30_d, 0U, c30_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_i, 1U, c30_c_sf_marshallOut,
    c30_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_s, 2U, c30_c_sf_marshallOut,
    c30_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_suma, 3U, c30_c_sf_marshallOut,
    c30_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_j, 4U, c30_c_sf_marshallOut,
    c30_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c30_c_TISdet, 5U, c30_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c30_c_TISMaxRange, 6U, c30_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_nargin, 7U, c30_c_sf_marshallOut,
    c30_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_nargout, 8U, c30_c_sf_marshallOut,
    c30_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c30_b_r, 9U, c30_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c30_b_yp1, 10U, c30_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c30_b_K1, 11U, c30_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c30_b_yp2, 12U, c30_b_sf_marshallOut,
    c30_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c30_b_K2, 13U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  c30_c_TISMaxRange = c30_b_TISMaxRange;
  c30_c_TISdet = c30_b_TISdet;
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 5);
  for (c30_i12 = 0; c30_i12 < 1600; c30_i12++) {
    c30_b_K2[c30_i12] = c30_b_K1[c30_i12];
  }

  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 6);
  for (c30_i13 = 0; c30_i13 < 32; c30_i13++) {
    c30_b_yp2[c30_i13] = c30_b_yp1[c30_i13];
  }

  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 8);
  c30_d = 50.0;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 11);
  c30_i = 1.0;
  c30_b_i = 0;
  while (c30_b_i < 32) {
    c30_i = 1.0 + (real_T)c30_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 12);
    c30_d2 = c30_b_r[_SFD_EML_ARRAY_BOUNDS_CHECK("r", (int32_T)
      _SFD_INTEGER_CHECK("i", c30_i), 1, 32, 1, 0) - 1];
    if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c30_d2, 150.0, -1, 1U,
          c30_d2 != 150.0))) {
      _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 13);
      c30_c_i = _SFD_EML_ARRAY_BOUNDS_CHECK("K2", (int32_T)_SFD_INTEGER_CHECK(
        "i", c30_i), 1, 32, 1, 0) - 1;
      c30_d_i = _SFD_EML_ARRAY_BOUNDS_CHECK("K2", (int32_T)_SFD_INTEGER_CHECK(
        "i", c30_i), 1, 32, 1, 0) - 1;
      for (c30_i14 = 0; c30_i14 < 49; c30_i14++) {
        c30_c_K2[c30_i14] = c30_b_K2[c30_d_i + ((1 + c30_i14) << 5)];
      }

      for (c30_i15 = 0; c30_i15 < 49; c30_i15++) {
        c30_b_K2[c30_c_i + (c30_i15 << 5)] = c30_c_K2[c30_i15];
      }

      _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 14);
      c30_b_K2[_SFD_EML_ARRAY_BOUNDS_CHECK("K2", (int32_T)_SFD_INTEGER_CHECK("i",
        c30_i), 1, 32, 1, 0) + 1567] = c30_b_yp1[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "yp1", (int32_T)_SFD_INTEGER_CHECK("i", c30_i), 1, 32, 1, 0) - 1];
    }

    c30_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 19);
  c30_i = 1.0;
  c30_e_i = 0;
  while (c30_e_i < 32) {
    c30_i = 1.0 + (real_T)c30_e_i;
    CV_EML_FOR(0, 1, 1, 1);
    _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 20);
    c30_s = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 21);
    c30_suma = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 22);
    c30_j = 1.0;
    c30_b_j = 0;
    while (c30_b_j < 50) {
      c30_j = 1.0 + (real_T)c30_b_j;
      CV_EML_FOR(0, 1, 2, 1);
      _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 23);
      c30_d3 = c30_b_K2[(_SFD_EML_ARRAY_BOUNDS_CHECK("K2", (int32_T)
        _SFD_INTEGER_CHECK("i", c30_i), 1, 32, 1, 0) +
                         ((_SFD_EML_ARRAY_BOUNDS_CHECK("K2", (int32_T)
        _SFD_INTEGER_CHECK("j", c30_j), 1, 50, 2, 0) - 1) << 5)) - 1];
      if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c30_d3, 0.0, -1, 1U,
            c30_d3 != 0.0))) {
        _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 24);
        c30_suma += c30_b_K2[(_SFD_EML_ARRAY_BOUNDS_CHECK("K2", (int32_T)
          _SFD_INTEGER_CHECK("i", c30_i), 1, 32, 1, 0) +
                              ((_SFD_EML_ARRAY_BOUNDS_CHECK("K2", (int32_T)
          _SFD_INTEGER_CHECK("j", c30_j), 1, 50, 2, 0) - 1) << 5)) - 1];
        _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 25);
        c30_s++;
      }

      c30_b_j++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    CV_EML_FOR(0, 1, 2, 0);
    _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 28);
    c30_A = c30_suma;
    c30_B = c30_s;
    c30_x = c30_A;
    c30_y = c30_B;
    c30_b_x = c30_x;
    c30_b_y = c30_y;
    c30_c_x = c30_b_x;
    c30_c_y = c30_b_y;
    c30_d_y = c30_c_x / c30_c_y;
    c30_b_yp2[_SFD_EML_ARRAY_BOUNDS_CHECK("yp2", (int32_T)_SFD_INTEGER_CHECK("i",
      c30_i), 1, 32, 1, 0) - 1] = c30_d_y;
    c30_e_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 1, 0);
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 32);
  c30_i = 1.0;
  c30_f_i = 0;
  while (c30_f_i < 32) {
    c30_i = 1.0 + (real_T)c30_f_i;
    CV_EML_FOR(0, 1, 3, 1);
    _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 33);
    c30_d4 = c30_b_r[_SFD_EML_ARRAY_BOUNDS_CHECK("r", (int32_T)
      _SFD_INTEGER_CHECK("i", c30_i), 1, 32, 1, 0) - 1];
    guard1 = false;
    if (CV_EML_COND(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 2, c30_d4,
          c30_b_TISMaxRange, -1, 0U, c30_d4 == c30_b_TISMaxRange))) {
      c30_d5 = c30_b_yp1[_SFD_EML_ARRAY_BOUNDS_CHECK("yp1", (int32_T)
        _SFD_INTEGER_CHECK("i", c30_i), 1, 32, 1, 0) - 1];
      if (CV_EML_COND(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 3, c30_d5, 0.0, -1, 0U,
            c30_d5 == 0.0))) {
        CV_EML_MCDC(0, 1, 0, true);
        CV_EML_IF(0, 1, 2, true);
        _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 34);
        c30_g_i = _SFD_EML_ARRAY_BOUNDS_CHECK("K2", (int32_T)_SFD_INTEGER_CHECK(
          "i", c30_i), 1, 32, 1, 0) - 1;
        for (c30_i16 = 0; c30_i16 < 50; c30_i16++) {
          c30_b_K2[c30_g_i + (c30_i16 << 5)] = 0.0;
        }

        _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 35);
        c30_b_yp2[_SFD_EML_ARRAY_BOUNDS_CHECK("yp2", (int32_T)_SFD_INTEGER_CHECK
          ("i", c30_i), 1, 32, 1, 0) - 1] = 0.0;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(0, 1, 0, false);
      CV_EML_IF(0, 1, 2, false);
    }

    c30_f_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 3, 0);
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, -35);
  _SFD_SYMBOL_SCOPE_POP();
  for (c30_i17 = 0; c30_i17 < 32; c30_i17++) {
    (*chartInstance->c30_yp2)[c30_i17] = c30_b_yp2[c30_i17];
  }

  for (c30_i18 = 0; c30_i18 < 1600; c30_i18++) {
    (*chartInstance->c30_K2)[c30_i18] = c30_b_K2[c30_i18];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 29U, chartInstance->c30_sfEvent);
}

static void initSimStructsc30_Experiment_3_cs
  (SFc30_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c30_machineNumber, uint32_T
  c30_chartNumber, uint32_T c30_instanceNumber)
{
  (void)c30_machineNumber;
  (void)c30_chartNumber;
  (void)c30_instanceNumber;
}

static const mxArray *c30_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData)
{
  const mxArray *c30_mxArrayOutData = NULL;
  int32_T c30_i19;
  int32_T c30_i20;
  int32_T c30_i21;
  real_T c30_b_inData[1600];
  int32_T c30_i22;
  int32_T c30_i23;
  int32_T c30_i24;
  real_T c30_u[1600];
  const mxArray *c30_y = NULL;
  SFc30_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc30_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c30_mxArrayOutData = NULL;
  c30_i19 = 0;
  for (c30_i20 = 0; c30_i20 < 50; c30_i20++) {
    for (c30_i21 = 0; c30_i21 < 32; c30_i21++) {
      c30_b_inData[c30_i21 + c30_i19] = (*(real_T (*)[1600])c30_inData)[c30_i21
        + c30_i19];
    }

    c30_i19 += 32;
  }

  c30_i22 = 0;
  for (c30_i23 = 0; c30_i23 < 50; c30_i23++) {
    for (c30_i24 = 0; c30_i24 < 32; c30_i24++) {
      c30_u[c30_i24 + c30_i22] = c30_b_inData[c30_i24 + c30_i22];
    }

    c30_i22 += 32;
  }

  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", c30_u, 0, 0U, 1U, 0U, 2, 32, 50),
                false);
  sf_mex_assign(&c30_mxArrayOutData, c30_y, false);
  return c30_mxArrayOutData;
}

static void c30_emlrt_marshallIn(SFc30_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c30_b_K2, const char_T *c30_identifier, real_T
  c30_y[1600])
{
  emlrtMsgIdentifier c30_thisId;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_b_K2), &c30_thisId, c30_y);
  sf_mex_destroy(&c30_b_K2);
}

static void c30_b_emlrt_marshallIn(SFc30_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId,
  real_T c30_y[1600])
{
  real_T c30_dv2[1600];
  int32_T c30_i25;
  (void)chartInstance;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_u), c30_dv2, 1, 0, 0U, 1, 0U, 2, 32,
                50);
  for (c30_i25 = 0; c30_i25 < 1600; c30_i25++) {
    c30_y[c30_i25] = c30_dv2[c30_i25];
  }

  sf_mex_destroy(&c30_u);
}

static void c30_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData)
{
  const mxArray *c30_b_K2;
  const char_T *c30_identifier;
  emlrtMsgIdentifier c30_thisId;
  real_T c30_y[1600];
  int32_T c30_i26;
  int32_T c30_i27;
  int32_T c30_i28;
  SFc30_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc30_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c30_b_K2 = sf_mex_dup(c30_mxArrayInData);
  c30_identifier = c30_varName;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_b_K2), &c30_thisId, c30_y);
  sf_mex_destroy(&c30_b_K2);
  c30_i26 = 0;
  for (c30_i27 = 0; c30_i27 < 50; c30_i27++) {
    for (c30_i28 = 0; c30_i28 < 32; c30_i28++) {
      (*(real_T (*)[1600])c30_outData)[c30_i28 + c30_i26] = c30_y[c30_i28 +
        c30_i26];
    }

    c30_i26 += 32;
  }

  sf_mex_destroy(&c30_mxArrayInData);
}

static const mxArray *c30_b_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData)
{
  const mxArray *c30_mxArrayOutData = NULL;
  int32_T c30_i29;
  real_T c30_b_inData[32];
  int32_T c30_i30;
  real_T c30_u[32];
  const mxArray *c30_y = NULL;
  SFc30_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc30_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c30_mxArrayOutData = NULL;
  for (c30_i29 = 0; c30_i29 < 32; c30_i29++) {
    c30_b_inData[c30_i29] = (*(real_T (*)[32])c30_inData)[c30_i29];
  }

  for (c30_i30 = 0; c30_i30 < 32; c30_i30++) {
    c30_u[c30_i30] = c30_b_inData[c30_i30];
  }

  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", c30_u, 0, 0U, 1U, 0U, 1, 32), false);
  sf_mex_assign(&c30_mxArrayOutData, c30_y, false);
  return c30_mxArrayOutData;
}

static void c30_c_emlrt_marshallIn(SFc30_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c30_b_yp2, const char_T *c30_identifier, real_T
  c30_y[32])
{
  emlrtMsgIdentifier c30_thisId;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_b_yp2), &c30_thisId,
    c30_y);
  sf_mex_destroy(&c30_b_yp2);
}

static void c30_d_emlrt_marshallIn(SFc30_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId,
  real_T c30_y[32])
{
  real_T c30_dv3[32];
  int32_T c30_i31;
  (void)chartInstance;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_u), c30_dv3, 1, 0, 0U, 1, 0U, 1, 32);
  for (c30_i31 = 0; c30_i31 < 32; c30_i31++) {
    c30_y[c30_i31] = c30_dv3[c30_i31];
  }

  sf_mex_destroy(&c30_u);
}

static void c30_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData)
{
  const mxArray *c30_b_yp2;
  const char_T *c30_identifier;
  emlrtMsgIdentifier c30_thisId;
  real_T c30_y[32];
  int32_T c30_i32;
  SFc30_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc30_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c30_b_yp2 = sf_mex_dup(c30_mxArrayInData);
  c30_identifier = c30_varName;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_b_yp2), &c30_thisId,
    c30_y);
  sf_mex_destroy(&c30_b_yp2);
  for (c30_i32 = 0; c30_i32 < 32; c30_i32++) {
    (*(real_T (*)[32])c30_outData)[c30_i32] = c30_y[c30_i32];
  }

  sf_mex_destroy(&c30_mxArrayInData);
}

static const mxArray *c30_c_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData)
{
  const mxArray *c30_mxArrayOutData = NULL;
  real_T c30_u;
  const mxArray *c30_y = NULL;
  SFc30_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc30_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c30_mxArrayOutData = NULL;
  c30_u = *(real_T *)c30_inData;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", &c30_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c30_mxArrayOutData, c30_y, false);
  return c30_mxArrayOutData;
}

static real_T c30_e_emlrt_marshallIn(SFc30_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId)
{
  real_T c30_y;
  real_T c30_d6;
  (void)chartInstance;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_u), &c30_d6, 1, 0, 0U, 0, 0U, 0);
  c30_y = c30_d6;
  sf_mex_destroy(&c30_u);
  return c30_y;
}

static void c30_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData)
{
  const mxArray *c30_nargout;
  const char_T *c30_identifier;
  emlrtMsgIdentifier c30_thisId;
  real_T c30_y;
  SFc30_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc30_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c30_nargout = sf_mex_dup(c30_mxArrayInData);
  c30_identifier = c30_varName;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_y = c30_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_nargout),
    &c30_thisId);
  sf_mex_destroy(&c30_nargout);
  *(real_T *)c30_outData = c30_y;
  sf_mex_destroy(&c30_mxArrayInData);
}

const mxArray *sf_c30_Experiment_3_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c30_nameCaptureInfo = NULL;
  c30_nameCaptureInfo = NULL;
  sf_mex_assign(&c30_nameCaptureInfo, sf_mex_createstruct("structure", 2, 7, 1),
                false);
  c30_info_helper(&c30_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c30_nameCaptureInfo);
  return c30_nameCaptureInfo;
}

static void c30_info_helper(const mxArray **c30_info)
{
  const mxArray *c30_rhs0 = NULL;
  const mxArray *c30_lhs0 = NULL;
  const mxArray *c30_rhs1 = NULL;
  const mxArray *c30_lhs1 = NULL;
  const mxArray *c30_rhs2 = NULL;
  const mxArray *c30_lhs2 = NULL;
  const mxArray *c30_rhs3 = NULL;
  const mxArray *c30_lhs3 = NULL;
  const mxArray *c30_rhs4 = NULL;
  const mxArray *c30_lhs4 = NULL;
  const mxArray *c30_rhs5 = NULL;
  const mxArray *c30_lhs5 = NULL;
  const mxArray *c30_rhs6 = NULL;
  const mxArray *c30_lhs6 = NULL;
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c30_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c30_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c30_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c30_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c30_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c30_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c30_info, c30_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c30_info, c30_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c30_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c30_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c30_info, sf_mex_duplicatearraysafe(&c30_lhs6), "lhs", "lhs",
                  6);
  sf_mex_destroy(&c30_rhs0);
  sf_mex_destroy(&c30_lhs0);
  sf_mex_destroy(&c30_rhs1);
  sf_mex_destroy(&c30_lhs1);
  sf_mex_destroy(&c30_rhs2);
  sf_mex_destroy(&c30_lhs2);
  sf_mex_destroy(&c30_rhs3);
  sf_mex_destroy(&c30_lhs3);
  sf_mex_destroy(&c30_rhs4);
  sf_mex_destroy(&c30_lhs4);
  sf_mex_destroy(&c30_rhs5);
  sf_mex_destroy(&c30_lhs5);
  sf_mex_destroy(&c30_rhs6);
  sf_mex_destroy(&c30_lhs6);
}

static const mxArray *c30_emlrt_marshallOut(const char * c30_u)
{
  const mxArray *c30_y = NULL;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", c30_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c30_u)), false);
  return c30_y;
}

static const mxArray *c30_b_emlrt_marshallOut(const uint32_T c30_u)
{
  const mxArray *c30_y = NULL;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", &c30_u, 7, 0U, 0U, 0U, 0), false);
  return c30_y;
}

static const mxArray *c30_d_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData)
{
  const mxArray *c30_mxArrayOutData = NULL;
  int32_T c30_u;
  const mxArray *c30_y = NULL;
  SFc30_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc30_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c30_mxArrayOutData = NULL;
  c30_u = *(int32_T *)c30_inData;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", &c30_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c30_mxArrayOutData, c30_y, false);
  return c30_mxArrayOutData;
}

static int32_T c30_f_emlrt_marshallIn(SFc30_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId)
{
  int32_T c30_y;
  int32_T c30_i33;
  (void)chartInstance;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_u), &c30_i33, 1, 6, 0U, 0, 0U, 0);
  c30_y = c30_i33;
  sf_mex_destroy(&c30_u);
  return c30_y;
}

static void c30_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData)
{
  const mxArray *c30_b_sfEvent;
  const char_T *c30_identifier;
  emlrtMsgIdentifier c30_thisId;
  int32_T c30_y;
  SFc30_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc30_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c30_b_sfEvent = sf_mex_dup(c30_mxArrayInData);
  c30_identifier = c30_varName;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_y = c30_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_b_sfEvent),
    &c30_thisId);
  sf_mex_destroy(&c30_b_sfEvent);
  *(int32_T *)c30_outData = c30_y;
  sf_mex_destroy(&c30_mxArrayInData);
}

static uint8_T c30_g_emlrt_marshallIn(SFc30_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c30_b_is_active_c30_Experiment_3_cs, const
  char_T *c30_identifier)
{
  uint8_T c30_y;
  emlrtMsgIdentifier c30_thisId;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_y = c30_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c30_b_is_active_c30_Experiment_3_cs), &c30_thisId);
  sf_mex_destroy(&c30_b_is_active_c30_Experiment_3_cs);
  return c30_y;
}

static uint8_T c30_h_emlrt_marshallIn(SFc30_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId)
{
  uint8_T c30_y;
  uint8_T c30_u0;
  (void)chartInstance;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_u), &c30_u0, 1, 3, 0U, 0, 0U, 0);
  c30_y = c30_u0;
  sf_mex_destroy(&c30_u);
  return c30_y;
}

static void init_dsm_address_info(SFc30_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc30_Experiment_3_csInstanceStruct
  *chartInstance)
{
  chartInstance->c30_r = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c30_yp2 = (real_T (*)[32])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c30_yp1 = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c30_K1 = (real_T (*)[1600])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c30_K2 = (real_T (*)[1600])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
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

void sf_c30_Experiment_3_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(690327419U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(736660722U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(940458375U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1833704291U);
}

mxArray* sf_c30_Experiment_3_cs_get_post_codegen_info(void);
mxArray *sf_c30_Experiment_3_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("nDDfnFIsBFD22JthXQA9QE");
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      pr[1] = (double)(50);
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

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(32);
      pr[1] = (double)(50);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c30_Experiment_3_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c30_Experiment_3_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c30_Experiment_3_cs_jit_fallback_info(void)
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

mxArray *sf_c30_Experiment_3_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c30_Experiment_3_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c30_Experiment_3_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[10],T\"K2\",},{M[1],M[5],T\"yp2\",},{M[8],M[0],T\"is_active_c30_Experiment_3_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c30_Experiment_3_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc30_Experiment_3_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc30_Experiment_3_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_3_csMachineNumber_,
           30,
           1,
           1,
           0,
           7,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"r");
          _SFD_SET_DATA_PROPS(1,2,0,1,"yp2");
          _SFD_SET_DATA_PROPS(2,1,1,0,"yp1");
          _SFD_SET_DATA_PROPS(3,1,1,0,"K1");
          _SFD_SET_DATA_PROPS(4,2,0,1,"K2");
          _SFD_SET_DATA_PROPS(5,10,0,0,"TISdet");
          _SFD_SET_DATA_PROPS(6,10,0,0,"TISMaxRange");
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
        _SFD_CV_INIT_EML(0,1,1,3,0,0,0,4,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,624);
        _SFD_CV_INIT_EML_IF(0,1,0,160,174,-1,236);
        _SFD_CV_INIT_EML_IF(0,1,1,337,352,-1,422);
        _SFD_CV_INIT_EML_IF(0,1,2,518,555,-1,615);
        _SFD_CV_INIT_EML_FOR(0,1,0,138,157,240);
        _SFD_CV_INIT_EML_FOR(0,1,1,266,285,455);
        _SFD_CV_INIT_EML_FOR(0,1,2,314,329,430);
        _SFD_CV_INIT_EML_FOR(0,1,3,496,514,623);

        {
          static int condStart[] = { 521, 544 };

          static int condEnd[] = { 540, 555 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,521,555,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,163,174,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,340,352,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,521,540,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,544,555,-1,0);

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c30_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c30_b_sf_marshallOut,(MexInFcnForType)
            c30_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c30_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 32;
          dimVector[1]= 50;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 32;
          dimVector[1]= 50;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)
            c30_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_c_sf_marshallOut,(MexInFcnForType)
          c30_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_c_sf_marshallOut,(MexInFcnForType)
          c30_c_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c30_r);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c30_yp2);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c30_yp1);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c30_K1);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c30_K2);
        _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c30_TISdet);
        _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c30_TISMaxRange);
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
  return "c2XqHVumRGDNakH30AUlxD";
}

static void sf_opaque_initialize_c30_Experiment_3_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc30_Experiment_3_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c30_Experiment_3_cs((SFc30_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
  initialize_c30_Experiment_3_cs((SFc30_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c30_Experiment_3_cs(void *chartInstanceVar)
{
  enable_c30_Experiment_3_cs((SFc30_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c30_Experiment_3_cs(void *chartInstanceVar)
{
  disable_c30_Experiment_3_cs((SFc30_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c30_Experiment_3_cs(void *chartInstanceVar)
{
  sf_gateway_c30_Experiment_3_cs((SFc30_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c30_Experiment_3_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c30_Experiment_3_cs((SFc30_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c30_Experiment_3_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c30_Experiment_3_cs((SFc30_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c30_Experiment_3_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc30_Experiment_3_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_3_cs_optimization_info();
    }

    finalize_c30_Experiment_3_cs((SFc30_Experiment_3_csInstanceStruct*)
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
  initSimStructsc30_Experiment_3_cs((SFc30_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c30_Experiment_3_cs(SimStruct *S)
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
    initialize_params_c30_Experiment_3_cs((SFc30_Experiment_3_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c30_Experiment_3_cs(SimStruct *S)
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
      30);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,30,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,30,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,30);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,30,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,30,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,30);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(818026922U));
  ssSetChecksum1(S,(49653834U));
  ssSetChecksum2(S,(2229671800U));
  ssSetChecksum3(S,(2708144882U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c30_Experiment_3_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c30_Experiment_3_cs(SimStruct *S)
{
  SFc30_Experiment_3_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc30_Experiment_3_csInstanceStruct *)utMalloc(sizeof
    (SFc30_Experiment_3_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc30_Experiment_3_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c30_Experiment_3_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c30_Experiment_3_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c30_Experiment_3_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c30_Experiment_3_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c30_Experiment_3_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c30_Experiment_3_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c30_Experiment_3_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c30_Experiment_3_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c30_Experiment_3_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c30_Experiment_3_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c30_Experiment_3_cs;
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

void c30_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c30_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c30_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c30_Experiment_3_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c30_Experiment_3_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
