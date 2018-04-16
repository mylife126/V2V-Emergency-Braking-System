/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_3_cs_sfun.h"
#include "c35_Experiment_3_cs.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Experiment_3_cs_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c35_b_TISdet                   (32.0)
#define c35_b_TISMaxRange              (40.0)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c35_debug_family_names[14] = { "d", "i", "j", "TISdet",
  "TISMaxRange", "nargin", "nargout", "r", "th1", "thd", "time", "K1", "th2",
  "K2" };

/* Function Declarations */
static void initialize_c35_Experiment_3_cs(SFc35_Experiment_3_csInstanceStruct
  *chartInstance);
static void initialize_params_c35_Experiment_3_cs
  (SFc35_Experiment_3_csInstanceStruct *chartInstance);
static void enable_c35_Experiment_3_cs(SFc35_Experiment_3_csInstanceStruct
  *chartInstance);
static void disable_c35_Experiment_3_cs(SFc35_Experiment_3_csInstanceStruct
  *chartInstance);
static void c35_update_debugger_state_c35_Experiment_3_cs
  (SFc35_Experiment_3_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c35_Experiment_3_cs
  (SFc35_Experiment_3_csInstanceStruct *chartInstance);
static void set_sim_state_c35_Experiment_3_cs
  (SFc35_Experiment_3_csInstanceStruct *chartInstance, const mxArray *c35_st);
static void finalize_c35_Experiment_3_cs(SFc35_Experiment_3_csInstanceStruct
  *chartInstance);
static void sf_gateway_c35_Experiment_3_cs(SFc35_Experiment_3_csInstanceStruct
  *chartInstance);
static void mdl_start_c35_Experiment_3_cs(SFc35_Experiment_3_csInstanceStruct
  *chartInstance);
static void c35_chartstep_c35_Experiment_3_cs
  (SFc35_Experiment_3_csInstanceStruct *chartInstance);
static void initSimStructsc35_Experiment_3_cs
  (SFc35_Experiment_3_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c35_machineNumber, uint32_T
  c35_chartNumber, uint32_T c35_instanceNumber);
static const mxArray *c35_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static void c35_emlrt_marshallIn(SFc35_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c35_b_K2, const char_T *c35_identifier, real_T
  c35_y[640]);
static void c35_b_emlrt_marshallIn(SFc35_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId,
  real_T c35_y[640]);
static void c35_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static const mxArray *c35_b_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static void c35_c_emlrt_marshallIn(SFc35_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c35_b_th2, const char_T *c35_identifier, real_T
  c35_y[32]);
static void c35_d_emlrt_marshallIn(SFc35_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId,
  real_T c35_y[32]);
static void c35_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static const mxArray *c35_c_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static real_T c35_e_emlrt_marshallIn(SFc35_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId);
static void c35_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static void c35_info_helper(const mxArray **c35_info);
static const mxArray *c35_emlrt_marshallOut(const char * c35_u);
static const mxArray *c35_b_emlrt_marshallOut(const uint32_T c35_u);
static void c35_b_info_helper(const mxArray **c35_info);
static int32_T c35_intmin(SFc35_Experiment_3_csInstanceStruct *chartInstance);
static real_T c35_interp1_work(SFc35_Experiment_3_csInstanceStruct
  *chartInstance, real_T c35_y[3], real_T c35_xi, real_T c35_x[3]);
static void c35_assert(SFc35_Experiment_3_csInstanceStruct *chartInstance);
static void c35_eml_scalar_eg(SFc35_Experiment_3_csInstanceStruct *chartInstance);
static void c35_b_assert(SFc35_Experiment_3_csInstanceStruct *chartInstance);
static void c35_c_assert(SFc35_Experiment_3_csInstanceStruct *chartInstance);
static void c35_StringToMethodID(SFc35_Experiment_3_csInstanceStruct
  *chartInstance);
static void c35_d_assert(SFc35_Experiment_3_csInstanceStruct *chartInstance);
static void c35_e_assert(SFc35_Experiment_3_csInstanceStruct *chartInstance);
static void c35_f_assert(SFc35_Experiment_3_csInstanceStruct *chartInstance);
static void c35_eml_error(SFc35_Experiment_3_csInstanceStruct *chartInstance);
static void c35_b_eml_error(SFc35_Experiment_3_csInstanceStruct *chartInstance);
static const mxArray *c35_d_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static int32_T c35_f_emlrt_marshallIn(SFc35_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId);
static void c35_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static uint8_T c35_g_emlrt_marshallIn(SFc35_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c35_b_is_active_c35_Experiment_3_cs, const
  char_T *c35_identifier);
static uint8_T c35_h_emlrt_marshallIn(SFc35_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId);
static void init_dsm_address_info(SFc35_Experiment_3_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc35_Experiment_3_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c35_Experiment_3_cs(SFc35_Experiment_3_csInstanceStruct
  *chartInstance)
{
  chartInstance->c35_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c35_is_active_c35_Experiment_3_cs = 0U;
}

static void initialize_params_c35_Experiment_3_cs
  (SFc35_Experiment_3_csInstanceStruct *chartInstance)
{
  real_T c35_d0;
  real_T c35_d1;
  sf_mex_import_named("TISdet", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c35_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c35_TISdet = c35_d0;
  sf_mex_import_named("TISMaxRange", sf_mex_get_sfun_param(chartInstance->S, 0,
    0), &c35_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c35_TISMaxRange = c35_d1;
}

static void enable_c35_Experiment_3_cs(SFc35_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c35_Experiment_3_cs(SFc35_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c35_update_debugger_state_c35_Experiment_3_cs
  (SFc35_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c35_Experiment_3_cs
  (SFc35_Experiment_3_csInstanceStruct *chartInstance)
{
  const mxArray *c35_st;
  const mxArray *c35_y = NULL;
  int32_T c35_i0;
  real_T c35_u[640];
  const mxArray *c35_b_y = NULL;
  int32_T c35_i1;
  real_T c35_b_u[32];
  const mxArray *c35_c_y = NULL;
  uint8_T c35_hoistedGlobal;
  uint8_T c35_c_u;
  const mxArray *c35_d_y = NULL;
  c35_st = NULL;
  c35_st = NULL;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_createcellmatrix(3, 1), false);
  for (c35_i0 = 0; c35_i0 < 640; c35_i0++) {
    c35_u[c35_i0] = (*chartInstance->c35_K2)[c35_i0];
  }

  c35_b_y = NULL;
  sf_mex_assign(&c35_b_y, sf_mex_create("y", c35_u, 0, 0U, 1U, 0U, 3, 32, 10, 2),
                false);
  sf_mex_setcell(c35_y, 0, c35_b_y);
  for (c35_i1 = 0; c35_i1 < 32; c35_i1++) {
    c35_b_u[c35_i1] = (*chartInstance->c35_th2)[c35_i1];
  }

  c35_c_y = NULL;
  sf_mex_assign(&c35_c_y, sf_mex_create("y", c35_b_u, 0, 0U, 1U, 0U, 1, 32),
                false);
  sf_mex_setcell(c35_y, 1, c35_c_y);
  c35_hoistedGlobal = chartInstance->c35_is_active_c35_Experiment_3_cs;
  c35_c_u = c35_hoistedGlobal;
  c35_d_y = NULL;
  sf_mex_assign(&c35_d_y, sf_mex_create("y", &c35_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c35_y, 2, c35_d_y);
  sf_mex_assign(&c35_st, c35_y, false);
  return c35_st;
}

static void set_sim_state_c35_Experiment_3_cs
  (SFc35_Experiment_3_csInstanceStruct *chartInstance, const mxArray *c35_st)
{
  const mxArray *c35_u;
  real_T c35_dv0[640];
  int32_T c35_i2;
  real_T c35_dv1[32];
  int32_T c35_i3;
  chartInstance->c35_doneDoubleBufferReInit = true;
  c35_u = sf_mex_dup(c35_st);
  c35_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c35_u, 0)), "K2",
                       c35_dv0);
  for (c35_i2 = 0; c35_i2 < 640; c35_i2++) {
    (*chartInstance->c35_K2)[c35_i2] = c35_dv0[c35_i2];
  }

  c35_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c35_u, 1)),
    "th2", c35_dv1);
  for (c35_i3 = 0; c35_i3 < 32; c35_i3++) {
    (*chartInstance->c35_th2)[c35_i3] = c35_dv1[c35_i3];
  }

  chartInstance->c35_is_active_c35_Experiment_3_cs = c35_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c35_u, 2)),
     "is_active_c35_Experiment_3_cs");
  sf_mex_destroy(&c35_u);
  c35_update_debugger_state_c35_Experiment_3_cs(chartInstance);
  sf_mex_destroy(&c35_st);
}

static void finalize_c35_Experiment_3_cs(SFc35_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c35_Experiment_3_cs(SFc35_Experiment_3_csInstanceStruct
  *chartInstance)
{
  int32_T c35_i4;
  int32_T c35_i5;
  int32_T c35_i6;
  int32_T c35_i7;
  int32_T c35_i8;
  int32_T c35_i9;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 34U, chartInstance->c35_sfEvent);
  for (c35_i4 = 0; c35_i4 < 32; c35_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c35_r)[c35_i4], 0U);
  }

  for (c35_i5 = 0; c35_i5 < 32; c35_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c35_th1)[c35_i5], 1U);
  }

  chartInstance->c35_sfEvent = CALL_EVENT;
  c35_chartstep_c35_Experiment_3_cs(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_3_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c35_i6 = 0; c35_i6 < 32; c35_i6++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c35_th2)[c35_i6], 2U);
  }

  for (c35_i7 = 0; c35_i7 < 32; c35_i7++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c35_thd)[c35_i7], 3U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c35_time, 4U);
  for (c35_i8 = 0; c35_i8 < 640; c35_i8++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c35_K1)[c35_i8], 5U);
  }

  for (c35_i9 = 0; c35_i9 < 640; c35_i9++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c35_K2)[c35_i9], 6U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c35_TISdet, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c35_TISMaxRange, 8U);
}

static void mdl_start_c35_Experiment_3_cs(SFc35_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c35_chartstep_c35_Experiment_3_cs
  (SFc35_Experiment_3_csInstanceStruct *chartInstance)
{
  real_T c35_hoistedGlobal;
  int32_T c35_i10;
  real_T c35_b_r[32];
  int32_T c35_i11;
  real_T c35_b_th1[32];
  int32_T c35_i12;
  real_T c35_b_thd[32];
  real_T c35_b_time;
  int32_T c35_i13;
  real_T c35_b_K1[640];
  uint32_T c35_debug_family_var_map[14];
  real_T c35_d;
  real_T c35_i;
  real_T c35_j;
  real_T c35_c_TISdet;
  real_T c35_c_TISMaxRange;
  real_T c35_nargin = 7.0;
  real_T c35_nargout = 2.0;
  real_T c35_b_th2[32];
  real_T c35_b_K2[640];
  int32_T c35_i14;
  int32_T c35_i15;
  int32_T c35_b_i;
  real_T c35_d2;
  int32_T c35_c_i;
  int32_T c35_d_i;
  int32_T c35_i16;
  int32_T c35_i17;
  real_T c35_c_K2[18];
  int32_T c35_i18;
  int32_T c35_i19;
  int32_T c35_e_i;
  int32_T c35_f_i;
  int32_T c35_i20;
  real_T c35_varargin_1[3];
  int32_T c35_g_i;
  int32_T c35_i21;
  real_T c35_varargin_2[3];
  real_T c35_varargin_3;
  int32_T c35_i22;
  real_T c35_b_varargin_2[3];
  int32_T c35_i23;
  real_T c35_b_varargin_1[3];
  real_T c35_Vq;
  int32_T c35_h_i;
  real_T c35_d3;
  real_T c35_d4;
  int32_T c35_i_i;
  int32_T c35_i24;
  int32_T c35_i25;
  int32_T c35_i26;
  int32_T c35_i27;
  boolean_T guard1 = false;
  boolean_T exitg1;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 34U, chartInstance->c35_sfEvent);
  c35_hoistedGlobal = *chartInstance->c35_time;
  for (c35_i10 = 0; c35_i10 < 32; c35_i10++) {
    c35_b_r[c35_i10] = (*chartInstance->c35_r)[c35_i10];
  }

  for (c35_i11 = 0; c35_i11 < 32; c35_i11++) {
    c35_b_th1[c35_i11] = (*chartInstance->c35_th1)[c35_i11];
  }

  for (c35_i12 = 0; c35_i12 < 32; c35_i12++) {
    c35_b_thd[c35_i12] = (*chartInstance->c35_thd)[c35_i12];
  }

  c35_b_time = c35_hoistedGlobal;
  for (c35_i13 = 0; c35_i13 < 640; c35_i13++) {
    c35_b_K1[c35_i13] = (*chartInstance->c35_K1)[c35_i13];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 14U, c35_debug_family_names,
    c35_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c35_d, 0U, c35_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_i, 1U, c35_c_sf_marshallOut,
    c35_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_j, 2U, c35_c_sf_marshallOut,
    c35_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c35_c_TISdet, 3U, c35_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c35_c_TISMaxRange, 4U, c35_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_nargin, 5U, c35_c_sf_marshallOut,
    c35_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_nargout, 6U, c35_c_sf_marshallOut,
    c35_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c35_b_r, 7U, c35_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c35_b_th1, 8U, c35_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c35_b_thd, 9U, c35_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c35_b_time, 10U, c35_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c35_b_K1, 11U, c35_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c35_b_th2, 12U, c35_b_sf_marshallOut,
    c35_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c35_b_K2, 13U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  c35_c_TISMaxRange = c35_b_TISMaxRange;
  c35_c_TISdet = c35_b_TISdet;
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 5);
  for (c35_i14 = 0; c35_i14 < 640; c35_i14++) {
    c35_b_K2[c35_i14] = c35_b_K1[c35_i14];
  }

  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 6);
  for (c35_i15 = 0; c35_i15 < 32; c35_i15++) {
    c35_b_th2[c35_i15] = c35_b_th1[c35_i15];
  }

  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 8);
  c35_d = 10.0;
  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 11);
  c35_i = 1.0;
  c35_b_i = 0;
  while (c35_b_i < 32) {
    c35_i = 1.0 + (real_T)c35_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 12);
    c35_d2 = c35_b_thd[_SFD_EML_ARRAY_BOUNDS_CHECK("thd", (int32_T)
      _SFD_INTEGER_CHECK("i", c35_i), 1, 32, 1, 0) - 1];
    if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c35_d2, 0.0, -1, 1U,
          c35_d2 != 0.0))) {
      _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 13);
      c35_c_i = _SFD_EML_ARRAY_BOUNDS_CHECK("K2", (int32_T)_SFD_INTEGER_CHECK(
        "i", c35_i), 1, 32, 1, 0) - 1;
      c35_d_i = _SFD_EML_ARRAY_BOUNDS_CHECK("K2", (int32_T)_SFD_INTEGER_CHECK(
        "i", c35_i), 1, 32, 1, 0) - 1;
      for (c35_i16 = 0; c35_i16 < 2; c35_i16++) {
        for (c35_i17 = 0; c35_i17 < 9; c35_i17++) {
          c35_c_K2[c35_i17 + 9 * c35_i16] = c35_b_K2[(c35_d_i + ((1 + c35_i17) <<
            5)) + 320 * c35_i16];
        }
      }

      for (c35_i18 = 0; c35_i18 < 2; c35_i18++) {
        for (c35_i19 = 0; c35_i19 < 9; c35_i19++) {
          c35_b_K2[(c35_c_i + (c35_i19 << 5)) + 320 * c35_i18] =
            c35_c_K2[c35_i19 + 9 * c35_i18];
        }
      }

      _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 14);
      c35_b_K2[_SFD_EML_ARRAY_BOUNDS_CHECK("K2", (int32_T)_SFD_INTEGER_CHECK("i",
        c35_i), 1, 32, 1, 0) + 287] = c35_b_time;
      _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 15);
      c35_b_K2[_SFD_EML_ARRAY_BOUNDS_CHECK("K2", (int32_T)_SFD_INTEGER_CHECK("i",
        c35_i), 1, 32, 1, 0) + 607] = c35_b_th1[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "th1", (int32_T)_SFD_INTEGER_CHECK("i", c35_i), 1, 32, 1, 0) - 1];
    }

    c35_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 20);
  c35_i = 1.0;
  c35_e_i = 0;
  while (c35_e_i < 32) {
    c35_i = 1.0 + (real_T)c35_e_i;
    CV_EML_FOR(0, 1, 1, 1);
    _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 21);
    c35_j = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 22);
    exitg1 = false;
    while ((exitg1 == false) && (c35_j < c35_d + 1.0)) {
      if (c35_b_K2[(_SFD_EML_ARRAY_BOUNDS_CHECK("K2", (int32_T)
            _SFD_INTEGER_CHECK("i", c35_i), 1, 32, 1, 0) +
                    ((_SFD_EML_ARRAY_BOUNDS_CHECK("K2", (int32_T)
              _SFD_INTEGER_CHECK("j", c35_j), 1, 10, 2, 0) - 1) << 5)) - 1] ==
          0.0) {
        CV_EML_WHILE(0, 1, 0, true);
        _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 23);
        c35_j++;
        _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 22);
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      } else {
        exitg1 = true;
      }
    }

    CV_EML_WHILE(0, 1, 0, false);
    _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 26);
    if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c35_j, c35_d - 2.0, -1,
          4U, c35_j > c35_d - 2.0))) {
      _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 27);
      c35_b_th2[_SFD_EML_ARRAY_BOUNDS_CHECK("th2", (int32_T)_SFD_INTEGER_CHECK(
        "i", c35_i), 1, 32, 1, 0) - 1] = c35_b_th1[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "th1", (int32_T)_SFD_INTEGER_CHECK("i", c35_i), 1, 32, 1, 0) - 1];
    } else {
      _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 29);
      c35_f_i = _SFD_EML_ARRAY_BOUNDS_CHECK("K2", (int32_T)_SFD_INTEGER_CHECK(
        "i", c35_i), 1, 32, 1, 0) - 1;
      for (c35_i20 = 0; c35_i20 < 3; c35_i20++) {
        c35_varargin_1[c35_i20] = c35_b_K2[c35_f_i + ((7 + c35_i20) << 5)];
      }

      c35_g_i = _SFD_EML_ARRAY_BOUNDS_CHECK("K2", (int32_T)_SFD_INTEGER_CHECK(
        "i", c35_i), 1, 32, 1, 0) - 1;
      for (c35_i21 = 0; c35_i21 < 3; c35_i21++) {
        c35_varargin_2[c35_i21] = c35_b_K2[320 + (c35_g_i + ((7 + c35_i21) << 5))];
      }

      c35_varargin_3 = c35_b_time;
      for (c35_i22 = 0; c35_i22 < 3; c35_i22++) {
        c35_b_varargin_2[c35_i22] = c35_varargin_2[c35_i22];
      }

      for (c35_i23 = 0; c35_i23 < 3; c35_i23++) {
        c35_b_varargin_1[c35_i23] = c35_varargin_1[c35_i23];
      }

      c35_Vq = c35_interp1_work(chartInstance, c35_b_varargin_2, c35_varargin_3,
        c35_b_varargin_1);
      c35_b_th2[_SFD_EML_ARRAY_BOUNDS_CHECK("th2", (int32_T)_SFD_INTEGER_CHECK(
        "i", c35_i), 1, 32, 1, 0) - 1] = c35_Vq;
    }

    c35_e_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 1, 0);
  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 34);
  c35_i = 1.0;
  c35_h_i = 0;
  while (c35_h_i < 32) {
    c35_i = 1.0 + (real_T)c35_h_i;
    CV_EML_FOR(0, 1, 2, 1);
    _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 35);
    c35_d3 = c35_b_r[_SFD_EML_ARRAY_BOUNDS_CHECK("r", (int32_T)
      _SFD_INTEGER_CHECK("i", c35_i), 1, 32, 1, 0) - 1];
    guard1 = false;
    if (CV_EML_COND(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 2, c35_d3,
          c35_b_TISMaxRange, -1, 0U, c35_d3 == c35_b_TISMaxRange))) {
      c35_d4 = c35_b_th1[_SFD_EML_ARRAY_BOUNDS_CHECK("th1", (int32_T)
        _SFD_INTEGER_CHECK("i", c35_i), 1, 32, 1, 0) - 1];
      if (CV_EML_COND(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 3, c35_d4, 0.0, -1, 0U,
            c35_d4 == 0.0))) {
        CV_EML_MCDC(0, 1, 0, true);
        CV_EML_IF(0, 1, 2, true);
        _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 36);
        c35_i_i = _SFD_EML_ARRAY_BOUNDS_CHECK("K2", (int32_T)_SFD_INTEGER_CHECK(
          "i", c35_i), 1, 32, 1, 0) - 1;
        for (c35_i24 = 0; c35_i24 < 2; c35_i24++) {
          for (c35_i25 = 0; c35_i25 < 10; c35_i25++) {
            c35_b_K2[(c35_i_i + (c35_i25 << 5)) + 320 * c35_i24] = 0.0;
          }
        }

        _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 37);
        c35_b_th2[_SFD_EML_ARRAY_BOUNDS_CHECK("th2", (int32_T)_SFD_INTEGER_CHECK
          ("i", c35_i), 1, 32, 1, 0) - 1] = 0.0;
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

    c35_h_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 2, 0);
  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, -37);
  _SFD_SYMBOL_SCOPE_POP();
  for (c35_i26 = 0; c35_i26 < 32; c35_i26++) {
    (*chartInstance->c35_th2)[c35_i26] = c35_b_th2[c35_i26];
  }

  for (c35_i27 = 0; c35_i27 < 640; c35_i27++) {
    (*chartInstance->c35_K2)[c35_i27] = c35_b_K2[c35_i27];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 34U, chartInstance->c35_sfEvent);
}

static void initSimStructsc35_Experiment_3_cs
  (SFc35_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c35_machineNumber, uint32_T
  c35_chartNumber, uint32_T c35_instanceNumber)
{
  (void)c35_machineNumber;
  (void)c35_chartNumber;
  (void)c35_instanceNumber;
}

static const mxArray *c35_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  int32_T c35_i28;
  int32_T c35_i29;
  int32_T c35_i30;
  int32_T c35_i31;
  int32_T c35_i32;
  real_T c35_b_inData[640];
  int32_T c35_i33;
  int32_T c35_i34;
  int32_T c35_i35;
  int32_T c35_i36;
  int32_T c35_i37;
  real_T c35_u[640];
  const mxArray *c35_y = NULL;
  SFc35_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc35_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  c35_i28 = 0;
  for (c35_i29 = 0; c35_i29 < 2; c35_i29++) {
    c35_i30 = 0;
    for (c35_i31 = 0; c35_i31 < 10; c35_i31++) {
      for (c35_i32 = 0; c35_i32 < 32; c35_i32++) {
        c35_b_inData[(c35_i32 + c35_i30) + c35_i28] = (*(real_T (*)[640])
          c35_inData)[(c35_i32 + c35_i30) + c35_i28];
      }

      c35_i30 += 32;
    }

    c35_i28 += 320;
  }

  c35_i33 = 0;
  for (c35_i34 = 0; c35_i34 < 2; c35_i34++) {
    c35_i35 = 0;
    for (c35_i36 = 0; c35_i36 < 10; c35_i36++) {
      for (c35_i37 = 0; c35_i37 < 32; c35_i37++) {
        c35_u[(c35_i37 + c35_i35) + c35_i33] = c35_b_inData[(c35_i37 + c35_i35)
          + c35_i33];
      }

      c35_i35 += 32;
    }

    c35_i33 += 320;
  }

  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 0, 0U, 1U, 0U, 3, 32, 10, 2),
                false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

static void c35_emlrt_marshallIn(SFc35_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c35_b_K2, const char_T *c35_identifier, real_T
  c35_y[640])
{
  emlrtMsgIdentifier c35_thisId;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_b_K2), &c35_thisId, c35_y);
  sf_mex_destroy(&c35_b_K2);
}

static void c35_b_emlrt_marshallIn(SFc35_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId,
  real_T c35_y[640])
{
  real_T c35_dv2[640];
  int32_T c35_i38;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), c35_dv2, 1, 0, 0U, 1, 0U, 3, 32,
                10, 2);
  for (c35_i38 = 0; c35_i38 < 640; c35_i38++) {
    c35_y[c35_i38] = c35_dv2[c35_i38];
  }

  sf_mex_destroy(&c35_u);
}

static void c35_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_b_K2;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  real_T c35_y[640];
  int32_T c35_i39;
  int32_T c35_i40;
  int32_T c35_i41;
  int32_T c35_i42;
  int32_T c35_i43;
  SFc35_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc35_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c35_b_K2 = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_b_K2), &c35_thisId, c35_y);
  sf_mex_destroy(&c35_b_K2);
  c35_i39 = 0;
  for (c35_i40 = 0; c35_i40 < 2; c35_i40++) {
    c35_i41 = 0;
    for (c35_i42 = 0; c35_i42 < 10; c35_i42++) {
      for (c35_i43 = 0; c35_i43 < 32; c35_i43++) {
        (*(real_T (*)[640])c35_outData)[(c35_i43 + c35_i41) + c35_i39] = c35_y
          [(c35_i43 + c35_i41) + c35_i39];
      }

      c35_i41 += 32;
    }

    c35_i39 += 320;
  }

  sf_mex_destroy(&c35_mxArrayInData);
}

static const mxArray *c35_b_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  int32_T c35_i44;
  real_T c35_b_inData[32];
  int32_T c35_i45;
  real_T c35_u[32];
  const mxArray *c35_y = NULL;
  SFc35_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc35_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  for (c35_i44 = 0; c35_i44 < 32; c35_i44++) {
    c35_b_inData[c35_i44] = (*(real_T (*)[32])c35_inData)[c35_i44];
  }

  for (c35_i45 = 0; c35_i45 < 32; c35_i45++) {
    c35_u[c35_i45] = c35_b_inData[c35_i45];
  }

  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 0, 0U, 1U, 0U, 1, 32), false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

static void c35_c_emlrt_marshallIn(SFc35_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c35_b_th2, const char_T *c35_identifier, real_T
  c35_y[32])
{
  emlrtMsgIdentifier c35_thisId;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_b_th2), &c35_thisId,
    c35_y);
  sf_mex_destroy(&c35_b_th2);
}

static void c35_d_emlrt_marshallIn(SFc35_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId,
  real_T c35_y[32])
{
  real_T c35_dv3[32];
  int32_T c35_i46;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), c35_dv3, 1, 0, 0U, 1, 0U, 1, 32);
  for (c35_i46 = 0; c35_i46 < 32; c35_i46++) {
    c35_y[c35_i46] = c35_dv3[c35_i46];
  }

  sf_mex_destroy(&c35_u);
}

static void c35_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_b_th2;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  real_T c35_y[32];
  int32_T c35_i47;
  SFc35_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc35_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c35_b_th2 = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_b_th2), &c35_thisId,
    c35_y);
  sf_mex_destroy(&c35_b_th2);
  for (c35_i47 = 0; c35_i47 < 32; c35_i47++) {
    (*(real_T (*)[32])c35_outData)[c35_i47] = c35_y[c35_i47];
  }

  sf_mex_destroy(&c35_mxArrayInData);
}

static const mxArray *c35_c_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  real_T c35_u;
  const mxArray *c35_y = NULL;
  SFc35_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc35_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  c35_u = *(real_T *)c35_inData;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", &c35_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

static real_T c35_e_emlrt_marshallIn(SFc35_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId)
{
  real_T c35_y;
  real_T c35_d5;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), &c35_d5, 1, 0, 0U, 0, 0U, 0);
  c35_y = c35_d5;
  sf_mex_destroy(&c35_u);
  return c35_y;
}

static void c35_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_nargout;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  real_T c35_y;
  SFc35_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc35_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c35_nargout = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_nargout),
    &c35_thisId);
  sf_mex_destroy(&c35_nargout);
  *(real_T *)c35_outData = c35_y;
  sf_mex_destroy(&c35_mxArrayInData);
}

const mxArray *sf_c35_Experiment_3_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c35_nameCaptureInfo = NULL;
  c35_nameCaptureInfo = NULL;
  sf_mex_assign(&c35_nameCaptureInfo, sf_mex_createstruct("structure", 2, 80, 1),
                false);
  c35_info_helper(&c35_nameCaptureInfo);
  c35_b_info_helper(&c35_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c35_nameCaptureInfo);
  return c35_nameCaptureInfo;
}

static void c35_info_helper(const mxArray **c35_info)
{
  const mxArray *c35_rhs0 = NULL;
  const mxArray *c35_lhs0 = NULL;
  const mxArray *c35_rhs1 = NULL;
  const mxArray *c35_lhs1 = NULL;
  const mxArray *c35_rhs2 = NULL;
  const mxArray *c35_lhs2 = NULL;
  const mxArray *c35_rhs3 = NULL;
  const mxArray *c35_lhs3 = NULL;
  const mxArray *c35_rhs4 = NULL;
  const mxArray *c35_lhs4 = NULL;
  const mxArray *c35_rhs5 = NULL;
  const mxArray *c35_lhs5 = NULL;
  const mxArray *c35_rhs6 = NULL;
  const mxArray *c35_lhs6 = NULL;
  const mxArray *c35_rhs7 = NULL;
  const mxArray *c35_lhs7 = NULL;
  const mxArray *c35_rhs8 = NULL;
  const mxArray *c35_lhs8 = NULL;
  const mxArray *c35_rhs9 = NULL;
  const mxArray *c35_lhs9 = NULL;
  const mxArray *c35_rhs10 = NULL;
  const mxArray *c35_lhs10 = NULL;
  const mxArray *c35_rhs11 = NULL;
  const mxArray *c35_lhs11 = NULL;
  const mxArray *c35_rhs12 = NULL;
  const mxArray *c35_lhs12 = NULL;
  const mxArray *c35_rhs13 = NULL;
  const mxArray *c35_lhs13 = NULL;
  const mxArray *c35_rhs14 = NULL;
  const mxArray *c35_lhs14 = NULL;
  const mxArray *c35_rhs15 = NULL;
  const mxArray *c35_lhs15 = NULL;
  const mxArray *c35_rhs16 = NULL;
  const mxArray *c35_lhs16 = NULL;
  const mxArray *c35_rhs17 = NULL;
  const mxArray *c35_lhs17 = NULL;
  const mxArray *c35_rhs18 = NULL;
  const mxArray *c35_lhs18 = NULL;
  const mxArray *c35_rhs19 = NULL;
  const mxArray *c35_lhs19 = NULL;
  const mxArray *c35_rhs20 = NULL;
  const mxArray *c35_lhs20 = NULL;
  const mxArray *c35_rhs21 = NULL;
  const mxArray *c35_lhs21 = NULL;
  const mxArray *c35_rhs22 = NULL;
  const mxArray *c35_lhs22 = NULL;
  const mxArray *c35_rhs23 = NULL;
  const mxArray *c35_lhs23 = NULL;
  const mxArray *c35_rhs24 = NULL;
  const mxArray *c35_lhs24 = NULL;
  const mxArray *c35_rhs25 = NULL;
  const mxArray *c35_lhs25 = NULL;
  const mxArray *c35_rhs26 = NULL;
  const mxArray *c35_lhs26 = NULL;
  const mxArray *c35_rhs27 = NULL;
  const mxArray *c35_lhs27 = NULL;
  const mxArray *c35_rhs28 = NULL;
  const mxArray *c35_lhs28 = NULL;
  const mxArray *c35_rhs29 = NULL;
  const mxArray *c35_lhs29 = NULL;
  const mxArray *c35_rhs30 = NULL;
  const mxArray *c35_lhs30 = NULL;
  const mxArray *c35_rhs31 = NULL;
  const mxArray *c35_lhs31 = NULL;
  const mxArray *c35_rhs32 = NULL;
  const mxArray *c35_lhs32 = NULL;
  const mxArray *c35_rhs33 = NULL;
  const mxArray *c35_lhs33 = NULL;
  const mxArray *c35_rhs34 = NULL;
  const mxArray *c35_lhs34 = NULL;
  const mxArray *c35_rhs35 = NULL;
  const mxArray *c35_lhs35 = NULL;
  const mxArray *c35_rhs36 = NULL;
  const mxArray *c35_lhs36 = NULL;
  const mxArray *c35_rhs37 = NULL;
  const mxArray *c35_lhs37 = NULL;
  const mxArray *c35_rhs38 = NULL;
  const mxArray *c35_lhs38 = NULL;
  const mxArray *c35_rhs39 = NULL;
  const mxArray *c35_lhs39 = NULL;
  const mxArray *c35_rhs40 = NULL;
  const mxArray *c35_lhs40 = NULL;
  const mxArray *c35_rhs41 = NULL;
  const mxArray *c35_lhs41 = NULL;
  const mxArray *c35_rhs42 = NULL;
  const mxArray *c35_lhs42 = NULL;
  const mxArray *c35_rhs43 = NULL;
  const mxArray *c35_lhs43 = NULL;
  const mxArray *c35_rhs44 = NULL;
  const mxArray *c35_lhs44 = NULL;
  const mxArray *c35_rhs45 = NULL;
  const mxArray *c35_lhs45 = NULL;
  const mxArray *c35_rhs46 = NULL;
  const mxArray *c35_lhs46 = NULL;
  const mxArray *c35_rhs47 = NULL;
  const mxArray *c35_lhs47 = NULL;
  const mxArray *c35_rhs48 = NULL;
  const mxArray *c35_lhs48 = NULL;
  const mxArray *c35_rhs49 = NULL;
  const mxArray *c35_lhs49 = NULL;
  const mxArray *c35_rhs50 = NULL;
  const mxArray *c35_lhs50 = NULL;
  const mxArray *c35_rhs51 = NULL;
  const mxArray *c35_lhs51 = NULL;
  const mxArray *c35_rhs52 = NULL;
  const mxArray *c35_lhs52 = NULL;
  const mxArray *c35_rhs53 = NULL;
  const mxArray *c35_lhs53 = NULL;
  const mxArray *c35_rhs54 = NULL;
  const mxArray *c35_lhs54 = NULL;
  const mxArray *c35_rhs55 = NULL;
  const mxArray *c35_lhs55 = NULL;
  const mxArray *c35_rhs56 = NULL;
  const mxArray *c35_lhs56 = NULL;
  const mxArray *c35_rhs57 = NULL;
  const mxArray *c35_lhs57 = NULL;
  const mxArray *c35_rhs58 = NULL;
  const mxArray *c35_lhs58 = NULL;
  const mxArray *c35_rhs59 = NULL;
  const mxArray *c35_lhs59 = NULL;
  const mxArray *c35_rhs60 = NULL;
  const mxArray *c35_lhs60 = NULL;
  const mxArray *c35_rhs61 = NULL;
  const mxArray *c35_lhs61 = NULL;
  const mxArray *c35_rhs62 = NULL;
  const mxArray *c35_lhs62 = NULL;
  const mxArray *c35_rhs63 = NULL;
  const mxArray *c35_lhs63 = NULL;
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("interp1"), "name", "name", 0);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1381871906U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c35_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c35_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!convert_extrapval"),
                  "context", "context", 2);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("length"), "name", "name", 2);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1303167806U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c35_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!convert_extrapval"),
                  "context", "context", 3);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("max"), "name", "name", 3);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1311276916U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c35_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 4);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1378317584U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c35_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 5);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 5);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c35_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 6);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c35_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 7);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 7);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c35_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 8);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c35_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 9);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 9);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c35_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 10);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 10);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c35_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 11);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 11);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c35_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!convert_extrapval"),
                  "context", "context", 12);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("strncmpi"), "name", "name",
                  12);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strncmpi.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1328879522U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c35_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strncmpi.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_assert_supported_string"),
                  "name", "name", 13);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1327440710U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c35_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m!inrange"),
                  "context", "context", 14);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 14);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1327440710U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c35_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("intmax"), "name", "name", 15);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c35_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 16);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c35_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strncmpi.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("min"), "name", "name", 17);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1311276918U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c35_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 18);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1378317584U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c35_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strncmpi.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("lower"), "name", "name", 19);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/lower.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1327440710U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c35_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/lower.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_string_transform"),
                  "name", "name", 20);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1327440710U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c35_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 21);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_assert_supported_string"),
                  "name", "name", 21);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1327440710U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c35_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m"),
                  "context", "context", 22);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 22);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1327440710U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c35_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 23);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 23);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1327440710U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c35_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 24);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("colon"), "name", "name", 24);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1378317588U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c35_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("colon"), "name", "name", 25);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1378317588U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c35_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 26);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c35_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 27);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c35_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("floor"), "name", "name", 28);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c35_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 29);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c35_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 30);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1286840326U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c35_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 31);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("intmin"), "name", "name", 31);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c35_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 32);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c35_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 33);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("intmax"), "name", "name", 33);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c35_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 34);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("intmin"), "name", "name", 34);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c35_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 35);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("intmax"), "name", "name", 35);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c35_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 36);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 36);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c35_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.isaUint"),
                  "name", "name", 37);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/isaUint.p"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c35_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 38);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_unsigned_class"), "name",
                  "name", 38);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c35_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "context", "context", 39);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "coder.internal.unsignedClass"), "name", "name", 39);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c35_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 40);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 40);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c35_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 41);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 41);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c35_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 42);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("intmax"), "name", "name", 42);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c35_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 43);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 43);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 43);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c35_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 44);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 44);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c35_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 45);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 45);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c35_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon"),
                  "context", "context", 46);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 46);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c35_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 47);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("isfi"), "name", "name", 47);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 47);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 47);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1346531958U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c35_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 48);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 48);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 48);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1398897198U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c35_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 49);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("intmax"), "name", "name", 49);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 49);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c35_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 50);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("intmin"), "name", "name", 50);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 50);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c35_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 51);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "name", "name", 51);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m"), "resolved",
                  "resolved", 51);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1319751568U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c35_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!convert_extrapval"),
                  "context", "context", 52);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 52);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 52);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c35_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!interp1_work"),
                  "context", "context", 53);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 53);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 53);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c35_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!interp1_work"),
                  "context", "context", 54);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 54);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 54);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c35_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!StringToMethodID"),
                  "context", "context", 55);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 55);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 55);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c35_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!StringToMethodID"),
                  "context", "context", 56);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("length"), "name", "name", 56);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 56);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1303167806U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c35_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!StringToMethodID"),
                  "context", "context", 57);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("max"), "name", "name", 57);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 57);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1311276916U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c35_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!StringToMethodID"),
                  "context", "context", 58);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("strncmpi"), "name", "name",
                  58);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/strncmpi.m"), "resolved",
                  "resolved", 58);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1328879522U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c35_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!interp1_work"),
                  "context", "context", 59);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 59);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 59);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c35_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!interp1_work"),
                  "context", "context", 60);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("isnan"), "name", "name", 60);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 60);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c35_rhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 61);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 61);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 61);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c35_rhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!interp1_work"),
                  "context", "context", 62);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_error"), "name", "name",
                  62);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 62);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1343851958U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c35_rhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!interp1_work"),
                  "context", "context", 63);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("fliplr"), "name", "name", 63);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 63);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/fliplr.m"), "resolved",
                  "resolved", 63);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1395346490U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c35_rhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs63), "lhs", "lhs",
                  63);
  sf_mex_destroy(&c35_rhs0);
  sf_mex_destroy(&c35_lhs0);
  sf_mex_destroy(&c35_rhs1);
  sf_mex_destroy(&c35_lhs1);
  sf_mex_destroy(&c35_rhs2);
  sf_mex_destroy(&c35_lhs2);
  sf_mex_destroy(&c35_rhs3);
  sf_mex_destroy(&c35_lhs3);
  sf_mex_destroy(&c35_rhs4);
  sf_mex_destroy(&c35_lhs4);
  sf_mex_destroy(&c35_rhs5);
  sf_mex_destroy(&c35_lhs5);
  sf_mex_destroy(&c35_rhs6);
  sf_mex_destroy(&c35_lhs6);
  sf_mex_destroy(&c35_rhs7);
  sf_mex_destroy(&c35_lhs7);
  sf_mex_destroy(&c35_rhs8);
  sf_mex_destroy(&c35_lhs8);
  sf_mex_destroy(&c35_rhs9);
  sf_mex_destroy(&c35_lhs9);
  sf_mex_destroy(&c35_rhs10);
  sf_mex_destroy(&c35_lhs10);
  sf_mex_destroy(&c35_rhs11);
  sf_mex_destroy(&c35_lhs11);
  sf_mex_destroy(&c35_rhs12);
  sf_mex_destroy(&c35_lhs12);
  sf_mex_destroy(&c35_rhs13);
  sf_mex_destroy(&c35_lhs13);
  sf_mex_destroy(&c35_rhs14);
  sf_mex_destroy(&c35_lhs14);
  sf_mex_destroy(&c35_rhs15);
  sf_mex_destroy(&c35_lhs15);
  sf_mex_destroy(&c35_rhs16);
  sf_mex_destroy(&c35_lhs16);
  sf_mex_destroy(&c35_rhs17);
  sf_mex_destroy(&c35_lhs17);
  sf_mex_destroy(&c35_rhs18);
  sf_mex_destroy(&c35_lhs18);
  sf_mex_destroy(&c35_rhs19);
  sf_mex_destroy(&c35_lhs19);
  sf_mex_destroy(&c35_rhs20);
  sf_mex_destroy(&c35_lhs20);
  sf_mex_destroy(&c35_rhs21);
  sf_mex_destroy(&c35_lhs21);
  sf_mex_destroy(&c35_rhs22);
  sf_mex_destroy(&c35_lhs22);
  sf_mex_destroy(&c35_rhs23);
  sf_mex_destroy(&c35_lhs23);
  sf_mex_destroy(&c35_rhs24);
  sf_mex_destroy(&c35_lhs24);
  sf_mex_destroy(&c35_rhs25);
  sf_mex_destroy(&c35_lhs25);
  sf_mex_destroy(&c35_rhs26);
  sf_mex_destroy(&c35_lhs26);
  sf_mex_destroy(&c35_rhs27);
  sf_mex_destroy(&c35_lhs27);
  sf_mex_destroy(&c35_rhs28);
  sf_mex_destroy(&c35_lhs28);
  sf_mex_destroy(&c35_rhs29);
  sf_mex_destroy(&c35_lhs29);
  sf_mex_destroy(&c35_rhs30);
  sf_mex_destroy(&c35_lhs30);
  sf_mex_destroy(&c35_rhs31);
  sf_mex_destroy(&c35_lhs31);
  sf_mex_destroy(&c35_rhs32);
  sf_mex_destroy(&c35_lhs32);
  sf_mex_destroy(&c35_rhs33);
  sf_mex_destroy(&c35_lhs33);
  sf_mex_destroy(&c35_rhs34);
  sf_mex_destroy(&c35_lhs34);
  sf_mex_destroy(&c35_rhs35);
  sf_mex_destroy(&c35_lhs35);
  sf_mex_destroy(&c35_rhs36);
  sf_mex_destroy(&c35_lhs36);
  sf_mex_destroy(&c35_rhs37);
  sf_mex_destroy(&c35_lhs37);
  sf_mex_destroy(&c35_rhs38);
  sf_mex_destroy(&c35_lhs38);
  sf_mex_destroy(&c35_rhs39);
  sf_mex_destroy(&c35_lhs39);
  sf_mex_destroy(&c35_rhs40);
  sf_mex_destroy(&c35_lhs40);
  sf_mex_destroy(&c35_rhs41);
  sf_mex_destroy(&c35_lhs41);
  sf_mex_destroy(&c35_rhs42);
  sf_mex_destroy(&c35_lhs42);
  sf_mex_destroy(&c35_rhs43);
  sf_mex_destroy(&c35_lhs43);
  sf_mex_destroy(&c35_rhs44);
  sf_mex_destroy(&c35_lhs44);
  sf_mex_destroy(&c35_rhs45);
  sf_mex_destroy(&c35_lhs45);
  sf_mex_destroy(&c35_rhs46);
  sf_mex_destroy(&c35_lhs46);
  sf_mex_destroy(&c35_rhs47);
  sf_mex_destroy(&c35_lhs47);
  sf_mex_destroy(&c35_rhs48);
  sf_mex_destroy(&c35_lhs48);
  sf_mex_destroy(&c35_rhs49);
  sf_mex_destroy(&c35_lhs49);
  sf_mex_destroy(&c35_rhs50);
  sf_mex_destroy(&c35_lhs50);
  sf_mex_destroy(&c35_rhs51);
  sf_mex_destroy(&c35_lhs51);
  sf_mex_destroy(&c35_rhs52);
  sf_mex_destroy(&c35_lhs52);
  sf_mex_destroy(&c35_rhs53);
  sf_mex_destroy(&c35_lhs53);
  sf_mex_destroy(&c35_rhs54);
  sf_mex_destroy(&c35_lhs54);
  sf_mex_destroy(&c35_rhs55);
  sf_mex_destroy(&c35_lhs55);
  sf_mex_destroy(&c35_rhs56);
  sf_mex_destroy(&c35_lhs56);
  sf_mex_destroy(&c35_rhs57);
  sf_mex_destroy(&c35_lhs57);
  sf_mex_destroy(&c35_rhs58);
  sf_mex_destroy(&c35_lhs58);
  sf_mex_destroy(&c35_rhs59);
  sf_mex_destroy(&c35_lhs59);
  sf_mex_destroy(&c35_rhs60);
  sf_mex_destroy(&c35_lhs60);
  sf_mex_destroy(&c35_rhs61);
  sf_mex_destroy(&c35_lhs61);
  sf_mex_destroy(&c35_rhs62);
  sf_mex_destroy(&c35_lhs62);
  sf_mex_destroy(&c35_rhs63);
  sf_mex_destroy(&c35_lhs63);
}

static const mxArray *c35_emlrt_marshallOut(const char * c35_u)
{
  const mxArray *c35_y = NULL;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c35_u)), false);
  return c35_y;
}

static const mxArray *c35_b_emlrt_marshallOut(const uint32_T c35_u)
{
  const mxArray *c35_y = NULL;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", &c35_u, 7, 0U, 0U, 0U, 0), false);
  return c35_y;
}

static void c35_b_info_helper(const mxArray **c35_info)
{
  const mxArray *c35_rhs64 = NULL;
  const mxArray *c35_lhs64 = NULL;
  const mxArray *c35_rhs65 = NULL;
  const mxArray *c35_lhs65 = NULL;
  const mxArray *c35_rhs66 = NULL;
  const mxArray *c35_lhs66 = NULL;
  const mxArray *c35_rhs67 = NULL;
  const mxArray *c35_lhs67 = NULL;
  const mxArray *c35_rhs68 = NULL;
  const mxArray *c35_lhs68 = NULL;
  const mxArray *c35_rhs69 = NULL;
  const mxArray *c35_lhs69 = NULL;
  const mxArray *c35_rhs70 = NULL;
  const mxArray *c35_lhs70 = NULL;
  const mxArray *c35_rhs71 = NULL;
  const mxArray *c35_lhs71 = NULL;
  const mxArray *c35_rhs72 = NULL;
  const mxArray *c35_lhs72 = NULL;
  const mxArray *c35_rhs73 = NULL;
  const mxArray *c35_lhs73 = NULL;
  const mxArray *c35_rhs74 = NULL;
  const mxArray *c35_lhs74 = NULL;
  const mxArray *c35_rhs75 = NULL;
  const mxArray *c35_lhs75 = NULL;
  const mxArray *c35_rhs76 = NULL;
  const mxArray *c35_lhs76 = NULL;
  const mxArray *c35_rhs77 = NULL;
  const mxArray *c35_lhs77 = NULL;
  const mxArray *c35_rhs78 = NULL;
  const mxArray *c35_lhs78 = NULL;
  const mxArray *c35_rhs79 = NULL;
  const mxArray *c35_lhs79 = NULL;
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/fliplr.m"), "context",
                  "context", 64);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 64);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 64);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 64);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 64);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 64);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 64);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 64);
  sf_mex_assign(&c35_rhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs64), "rhs", "rhs",
                  64);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs64), "lhs", "lhs",
                  64);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/fliplr.m"), "context",
                  "context", 65);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.prodsize"),
                  "name", "name", 65);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 65);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/prodsize.m"),
                  "resolved", "resolved", 65);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1360304188U), "fileTimeLo",
                  "fileTimeLo", 65);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 65);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 65);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 65);
  sf_mex_assign(&c35_rhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs65), "rhs", "rhs",
                  65);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs65), "lhs", "lhs",
                  65);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!interp1Linear"),
                  "context", "context", 66);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("isnan"), "name", "name", 66);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 66);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 66);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 66);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 66);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 66);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 66);
  sf_mex_assign(&c35_rhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs66), "rhs", "rhs",
                  66);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs66), "lhs", "lhs",
                  66);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!interp1Linear"),
                  "context", "context", 67);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.nan"), "name",
                  "name", 67);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 67);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/nan.m"),
                  "resolved", "resolved", 67);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1362283632U), "fileTimeLo",
                  "fileTimeLo", 67);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 67);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 67);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 67);
  sf_mex_assign(&c35_rhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs67), "rhs", "rhs",
                  67);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs67), "lhs", "lhs",
                  67);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!interp1Linear"),
                  "context", "context", 68);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("mrdivide"), "name", "name",
                  68);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 68);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 68);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 68);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 68);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 68);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 68);
  sf_mex_assign(&c35_rhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs68), "rhs", "rhs",
                  68);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs68), "lhs", "lhs",
                  68);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 69);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 69);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 69);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 69);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 69);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 69);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 69);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 69);
  sf_mex_assign(&c35_rhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs69), "rhs", "rhs",
                  69);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs69), "lhs", "lhs",
                  69);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 70);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("rdivide"), "name", "name",
                  70);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 70);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 70);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 70);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 70);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 70);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 70);
  sf_mex_assign(&c35_rhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs70), "rhs", "rhs",
                  70);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs70), "lhs", "lhs",
                  70);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 71);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 71);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 71);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 71);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 71);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 71);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 71);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 71);
  sf_mex_assign(&c35_rhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs71), "rhs", "rhs",
                  71);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs71), "lhs", "lhs",
                  71);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 72);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 72);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 72);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 72);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 72);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 72);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 72);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 72);
  sf_mex_assign(&c35_rhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs72), "rhs", "rhs",
                  72);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs72), "lhs", "lhs",
                  72);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 73);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_div"), "name", "name",
                  73);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 73);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 73);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 73);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 73);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 73);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 73);
  sf_mex_assign(&c35_rhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs73), "rhs", "rhs",
                  73);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs73), "lhs", "lhs",
                  73);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 74);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 74);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 74);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 74);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 74);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 74);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 74);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 74);
  sf_mex_assign(&c35_rhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs74), "rhs", "rhs",
                  74);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs74), "lhs", "lhs",
                  74);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m!interp1Linear"),
                  "context", "context", 75);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.bsearch"),
                  "name", "name", 75);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 75);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/bsearch.p"),
                  "resolved", "resolved", 75);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 75);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 75);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 75);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 75);
  sf_mex_assign(&c35_rhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs75), "rhs", "rhs",
                  75);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs75), "lhs", "lhs",
                  75);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/bsearch.p"),
                  "context", "context", 76);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.narginchk"),
                  "name", "name", 76);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 76);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/narginchk.m"),
                  "resolved", "resolved", 76);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1363732558U), "fileTimeLo",
                  "fileTimeLo", 76);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 76);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 76);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 76);
  sf_mex_assign(&c35_rhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs76), "rhs", "rhs",
                  76);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs76), "lhs", "lhs",
                  76);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/narginchk.m"),
                  "context", "context", 77);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("floor"), "name", "name", 77);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 77);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 77);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 77);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 77);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 77);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 77);
  sf_mex_assign(&c35_rhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs77), "rhs", "rhs",
                  77);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs77), "lhs", "lhs",
                  77);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/narginchk.m"),
                  "context", "context", 78);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 78);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 78);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 78);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 78);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 78);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 78);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 78);
  sf_mex_assign(&c35_rhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs78), "rhs", "rhs",
                  78);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs78), "lhs", "lhs",
                  78);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/bsearch.p"),
                  "context", "context", 79);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("intmax"), "name", "name", 79);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 79);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 79);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 79);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 79);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 79);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 79);
  sf_mex_assign(&c35_rhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs79), "rhs", "rhs",
                  79);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs79), "lhs", "lhs",
                  79);
  sf_mex_destroy(&c35_rhs64);
  sf_mex_destroy(&c35_lhs64);
  sf_mex_destroy(&c35_rhs65);
  sf_mex_destroy(&c35_lhs65);
  sf_mex_destroy(&c35_rhs66);
  sf_mex_destroy(&c35_lhs66);
  sf_mex_destroy(&c35_rhs67);
  sf_mex_destroy(&c35_lhs67);
  sf_mex_destroy(&c35_rhs68);
  sf_mex_destroy(&c35_lhs68);
  sf_mex_destroy(&c35_rhs69);
  sf_mex_destroy(&c35_lhs69);
  sf_mex_destroy(&c35_rhs70);
  sf_mex_destroy(&c35_lhs70);
  sf_mex_destroy(&c35_rhs71);
  sf_mex_destroy(&c35_lhs71);
  sf_mex_destroy(&c35_rhs72);
  sf_mex_destroy(&c35_lhs72);
  sf_mex_destroy(&c35_rhs73);
  sf_mex_destroy(&c35_lhs73);
  sf_mex_destroy(&c35_rhs74);
  sf_mex_destroy(&c35_lhs74);
  sf_mex_destroy(&c35_rhs75);
  sf_mex_destroy(&c35_lhs75);
  sf_mex_destroy(&c35_rhs76);
  sf_mex_destroy(&c35_lhs76);
  sf_mex_destroy(&c35_rhs77);
  sf_mex_destroy(&c35_lhs77);
  sf_mex_destroy(&c35_rhs78);
  sf_mex_destroy(&c35_lhs78);
  sf_mex_destroy(&c35_rhs79);
  sf_mex_destroy(&c35_lhs79);
}

static int32_T c35_intmin(SFc35_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
  return MIN_int32_T;
}

static real_T c35_interp1_work(SFc35_Experiment_3_csInstanceStruct
  *chartInstance, real_T c35_y[3], real_T c35_xi, real_T c35_x[3])
{
  real_T c35_yi;
  int32_T c35_k;
  int32_T c35_b_k;
  real_T c35_b_x;
  boolean_T c35_b;
  real_T c35_xtmp;
  real_T c35_b_xtmp;
  int32_T c35_c_k;
  real_T c35_b_xi;
  real_T c35_minx;
  real_T c35_penx;
  real_T c35_maxx;
  real_T c35_xik;
  real_T c35_c_x;
  boolean_T c35_b_b;
  real_T c35_A;
  real_T c35_B;
  real_T c35_d_x;
  real_T c35_b_y;
  real_T c35_e_x;
  real_T c35_c_y;
  real_T c35_f_x;
  real_T c35_d_y;
  real_T c35_b_r;
  real_T c35_b_A;
  real_T c35_b_B;
  real_T c35_g_x;
  real_T c35_e_y;
  real_T c35_h_x;
  real_T c35_f_y;
  real_T c35_i_x;
  real_T c35_g_y;
  real_T c35_c_xi;
  int32_T c35_low_i;
  int32_T c35_low_ip1;
  int32_T c35_high_i;
  int32_T c35_b_low_i;
  int32_T c35_b_high_i;
  int32_T c35_mid_i;
  int32_T c35_n;
  real_T c35_xn;
  real_T c35_xnp1;
  real_T c35_c_A;
  real_T c35_c_B;
  real_T c35_j_x;
  real_T c35_h_y;
  real_T c35_k_x;
  real_T c35_i_y;
  real_T c35_l_x;
  real_T c35_j_y;
  real_T c35_onemr;
  real_T c35_y1;
  real_T c35_y2;
  int32_T exitg1;
  c35_assert(chartInstance);
  c35_eml_scalar_eg(chartInstance);
  c35_b_assert(chartInstance);
  c35_c_assert(chartInstance);
  c35_StringToMethodID(chartInstance);
  c35_d_assert(chartInstance);
  c35_e_assert(chartInstance);
  c35_f_assert(chartInstance);
  c35_intmin(chartInstance);
  c35_k = 1;
  do {
    exitg1 = 0;
    if (c35_k < 4) {
      c35_b_k = c35_k;
      c35_b_x = c35_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c35_b_k), 1, 3, 1, 0) - 1];
      c35_b = muDoubleScalarIsNaN(c35_b_x);
      if (c35_b) {
        c35_eml_error(chartInstance);
        exitg1 = 1;
      } else {
        c35_k++;
      }
    } else {
      if (c35_x[1] < c35_x[0]) {
        c35_xtmp = c35_x[0];
        c35_x[0] = c35_x[2];
        c35_x[2] = c35_xtmp;
        c35_b_xtmp = c35_y[0];
        c35_y[0] = c35_y[2];
        c35_y[2] = c35_b_xtmp;
      }

      c35_intmin(chartInstance);
      for (c35_c_k = 2; c35_c_k < 4; c35_c_k++) {
        c35_b_k = c35_c_k;
        if (c35_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c35_b_k), 1, 3, 1, 0) - 1] <=
            c35_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)(c35_b_k - 1)), 1, 3, 1, 0) - 1]) {
          c35_b_eml_error(chartInstance);
        }
      }

      c35_b_xi = c35_xi;
      c35_minx = c35_x[0];
      c35_penx = c35_x[1];
      c35_maxx = c35_x[2];
      c35_xik = c35_b_xi;
      c35_c_x = c35_xik;
      c35_b_b = muDoubleScalarIsNaN(c35_c_x);
      if (c35_b_b) {
        c35_yi = rtNaN;
      } else if (c35_xik > c35_maxx) {
        c35_A = c35_xik - c35_maxx;
        c35_B = c35_maxx - c35_penx;
        c35_d_x = c35_A;
        c35_b_y = c35_B;
        c35_e_x = c35_d_x;
        c35_c_y = c35_b_y;
        c35_f_x = c35_e_x;
        c35_d_y = c35_c_y;
        c35_b_r = c35_f_x / c35_d_y;
        c35_yi = c35_y[2] + c35_b_r * (c35_y[2] - c35_y[1]);
      } else if (c35_xik < c35_minx) {
        c35_b_A = c35_xik - c35_minx;
        c35_b_B = c35_x[1] - c35_minx;
        c35_g_x = c35_b_A;
        c35_e_y = c35_b_B;
        c35_h_x = c35_g_x;
        c35_f_y = c35_e_y;
        c35_i_x = c35_h_x;
        c35_g_y = c35_f_y;
        c35_b_r = c35_i_x / c35_g_y;
        c35_yi = c35_y[0] + c35_b_r * (c35_y[1] - c35_y[0]);
      } else {
        c35_c_xi = c35_xik;
        c35_low_i = 1;
        c35_low_ip1 = 1;
        c35_high_i = 3;
        while (c35_high_i > c35_low_ip1 + 1) {
          c35_b_low_i = c35_low_i;
          c35_b_high_i = c35_high_i;
          c35_mid_i = (c35_b_low_i + c35_b_high_i) >> 1;
          if (c35_c_xi >= c35_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
               _SFD_INTEGER_CHECK("", (real_T)c35_mid_i), 1, 3, 1, 0) - 1]) {
            c35_low_i = c35_mid_i;
            c35_low_ip1 = c35_low_i;
          } else {
            c35_high_i = c35_mid_i;
          }
        }

        c35_n = c35_low_i;
        c35_xn = c35_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c35_n), 1, 3, 1, 0) - 1];
        c35_xnp1 = c35_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c35_n + 1)), 1, 3, 1, 0) - 1];
        c35_c_A = c35_xik - c35_xn;
        c35_c_B = c35_xnp1 - c35_xn;
        c35_j_x = c35_c_A;
        c35_h_y = c35_c_B;
        c35_k_x = c35_j_x;
        c35_i_y = c35_h_y;
        c35_l_x = c35_k_x;
        c35_j_y = c35_i_y;
        c35_b_r = c35_l_x / c35_j_y;
        c35_onemr = 1.0 - c35_b_r;
        c35_y1 = c35_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c35_n), 1, 3, 1, 0) - 1];
        c35_y2 = c35_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c35_n + 1)), 1, 3, 1, 0) - 1];
        if (c35_y1 == c35_y2) {
          c35_yi = c35_y1;
        } else {
          c35_yi = c35_onemr * c35_y1 + c35_b_r * c35_y2;
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c35_yi;
}

static void c35_assert(SFc35_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c35_eml_scalar_eg(SFc35_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c35_b_assert(SFc35_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c35_c_assert(SFc35_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c35_StringToMethodID(SFc35_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c35_d_assert(SFc35_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c35_e_assert(SFc35_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c35_f_assert(SFc35_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c35_eml_error(SFc35_Experiment_3_csInstanceStruct *chartInstance)
{
  int32_T c35_i48;
  static char_T c35_cv0[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'n', 't',
    'e', 'r', 'p', '1', ':', 'N', 'a', 'N', 'i', 'n', 'X' };

  char_T c35_u[21];
  const mxArray *c35_y = NULL;
  (void)chartInstance;
  for (c35_i48 = 0; c35_i48 < 21; c35_i48++) {
    c35_u[c35_i48] = c35_cv0[c35_i48];
  }

  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 10, 0U, 1U, 0U, 2, 1, 21),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c35_y));
}

static void c35_b_eml_error(SFc35_Experiment_3_csInstanceStruct *chartInstance)
{
  int32_T c35_i49;
  static char_T c35_cv1[35] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', 'e', 'r', 'p', '1', '_', 'n', 'o', 'n',
    'M', 'o', 'n', 'o', 't', 'o', 'n', 'i', 'c', 'X' };

  char_T c35_u[35];
  const mxArray *c35_y = NULL;
  (void)chartInstance;
  for (c35_i49 = 0; c35_i49 < 35; c35_i49++) {
    c35_u[c35_i49] = c35_cv1[c35_i49];
  }

  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 10, 0U, 1U, 0U, 2, 1, 35),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c35_y));
}

static const mxArray *c35_d_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  int32_T c35_u;
  const mxArray *c35_y = NULL;
  SFc35_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc35_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  c35_u = *(int32_T *)c35_inData;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", &c35_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

static int32_T c35_f_emlrt_marshallIn(SFc35_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId)
{
  int32_T c35_y;
  int32_T c35_i50;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), &c35_i50, 1, 6, 0U, 0, 0U, 0);
  c35_y = c35_i50;
  sf_mex_destroy(&c35_u);
  return c35_y;
}

static void c35_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_b_sfEvent;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  int32_T c35_y;
  SFc35_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc35_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c35_b_sfEvent = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_b_sfEvent),
    &c35_thisId);
  sf_mex_destroy(&c35_b_sfEvent);
  *(int32_T *)c35_outData = c35_y;
  sf_mex_destroy(&c35_mxArrayInData);
}

static uint8_T c35_g_emlrt_marshallIn(SFc35_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c35_b_is_active_c35_Experiment_3_cs, const
  char_T *c35_identifier)
{
  uint8_T c35_y;
  emlrtMsgIdentifier c35_thisId;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c35_b_is_active_c35_Experiment_3_cs), &c35_thisId);
  sf_mex_destroy(&c35_b_is_active_c35_Experiment_3_cs);
  return c35_y;
}

static uint8_T c35_h_emlrt_marshallIn(SFc35_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId)
{
  uint8_T c35_y;
  uint8_T c35_u0;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), &c35_u0, 1, 3, 0U, 0, 0U, 0);
  c35_y = c35_u0;
  sf_mex_destroy(&c35_u);
  return c35_y;
}

static void init_dsm_address_info(SFc35_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc35_Experiment_3_csInstanceStruct
  *chartInstance)
{
  chartInstance->c35_r = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c35_th1 = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c35_th2 = (real_T (*)[32])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c35_thd = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c35_time = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c35_K1 = (real_T (*)[640])ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c35_K2 = (real_T (*)[640])ssGetOutputPortSignal_wrapper
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

void sf_c35_Experiment_3_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(996749915U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4078208565U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3870524140U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2975346406U);
}

mxArray* sf_c35_Experiment_3_cs_get_post_codegen_info(void);
mxArray *sf_c35_Experiment_3_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("cJxudKYRXfEsw8Lg3xFmw");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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
      mxArray *mxSize = mxCreateDoubleMatrix(1,3,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(32);
      pr[1] = (double)(10);
      pr[2] = (double)(2);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,3,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(32);
      pr[1] = (double)(10);
      pr[2] = (double)(2);
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
    mxArray* mxPostCodegenInfo = sf_c35_Experiment_3_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c35_Experiment_3_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c35_Experiment_3_cs_jit_fallback_info(void)
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

mxArray *sf_c35_Experiment_3_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c35_Experiment_3_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c35_Experiment_3_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[8],T\"K2\",},{M[1],M[5],T\"th2\",},{M[8],M[0],T\"is_active_c35_Experiment_3_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c35_Experiment_3_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc35_Experiment_3_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc35_Experiment_3_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_3_csMachineNumber_,
           35,
           1,
           1,
           0,
           9,
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
          _SFD_SET_DATA_PROPS(1,1,1,0,"th1");
          _SFD_SET_DATA_PROPS(2,2,0,1,"th2");
          _SFD_SET_DATA_PROPS(3,1,1,0,"thd");
          _SFD_SET_DATA_PROPS(4,1,1,0,"time");
          _SFD_SET_DATA_PROPS(5,1,1,0,"K1");
          _SFD_SET_DATA_PROPS(6,2,0,1,"K2");
          _SFD_SET_DATA_PROPS(7,10,0,0,"TISdet");
          _SFD_SET_DATA_PROPS(8,10,0,0,"TISMaxRange");
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
        _SFD_CV_INIT_EML(0,1,1,3,0,0,0,3,1,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,766);
        _SFD_CV_INIT_EML_IF(0,1,0,218,232,-1,335);
        _SFD_CV_INIT_EML_IF(0,1,1,459,469,499,589);
        _SFD_CV_INIT_EML_IF(0,1,2,656,693,-1,753);
        _SFD_CV_INIT_EML_FOR(0,1,0,195,214,339);
        _SFD_CV_INIT_EML_FOR(0,1,1,357,376,593);
        _SFD_CV_INIT_EML_FOR(0,1,2,634,652,761);
        _SFD_CV_INIT_EML_WHILE(0,1,0,391,423,449);

        {
          static int condStart[] = { 659, 682 };

          static int condEnd[] = { 678, 693 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,659,693,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,221,232,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,462,469,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,659,678,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,682,693,-1,0);

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c35_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c35_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c35_b_sf_marshallOut,(MexInFcnForType)
            c35_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c35_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[3];
          dimVector[0]= 32;
          dimVector[1]= 10;
          dimVector[2]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,3,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[3];
          dimVector[0]= 32;
          dimVector[1]= 10;
          dimVector[2]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,3,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)
            c35_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_c_sf_marshallOut,(MexInFcnForType)
          c35_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_c_sf_marshallOut,(MexInFcnForType)
          c35_c_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c35_r);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c35_th1);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c35_th2);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c35_thd);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c35_time);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c35_K1);
        _SFD_SET_DATA_VALUE_PTR(6U, *chartInstance->c35_K2);
        _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c35_TISdet);
        _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c35_TISMaxRange);
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
  return "1vjMvBnAuxVlGfGp0iz8dE";
}

static void sf_opaque_initialize_c35_Experiment_3_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc35_Experiment_3_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c35_Experiment_3_cs((SFc35_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
  initialize_c35_Experiment_3_cs((SFc35_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c35_Experiment_3_cs(void *chartInstanceVar)
{
  enable_c35_Experiment_3_cs((SFc35_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c35_Experiment_3_cs(void *chartInstanceVar)
{
  disable_c35_Experiment_3_cs((SFc35_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c35_Experiment_3_cs(void *chartInstanceVar)
{
  sf_gateway_c35_Experiment_3_cs((SFc35_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c35_Experiment_3_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c35_Experiment_3_cs((SFc35_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c35_Experiment_3_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c35_Experiment_3_cs((SFc35_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c35_Experiment_3_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc35_Experiment_3_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_3_cs_optimization_info();
    }

    finalize_c35_Experiment_3_cs((SFc35_Experiment_3_csInstanceStruct*)
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
  initSimStructsc35_Experiment_3_cs((SFc35_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c35_Experiment_3_cs(SimStruct *S)
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
    initialize_params_c35_Experiment_3_cs((SFc35_Experiment_3_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c35_Experiment_3_cs(SimStruct *S)
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
      35);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,35,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,35,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,35);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,35,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,35,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,35);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2849904045U));
  ssSetChecksum1(S,(236028484U));
  ssSetChecksum2(S,(2537861924U));
  ssSetChecksum3(S,(1574929187U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c35_Experiment_3_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c35_Experiment_3_cs(SimStruct *S)
{
  SFc35_Experiment_3_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc35_Experiment_3_csInstanceStruct *)utMalloc(sizeof
    (SFc35_Experiment_3_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc35_Experiment_3_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c35_Experiment_3_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c35_Experiment_3_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c35_Experiment_3_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c35_Experiment_3_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c35_Experiment_3_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c35_Experiment_3_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c35_Experiment_3_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c35_Experiment_3_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c35_Experiment_3_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c35_Experiment_3_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c35_Experiment_3_cs;
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

void c35_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c35_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c35_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c35_Experiment_3_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c35_Experiment_3_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
