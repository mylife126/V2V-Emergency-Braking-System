/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_1_cs_sfun.h"
#include "c40_Experiment_1_cs.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Experiment_1_cs_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c40_b_TISdet                   (32.0)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c40_debug_family_names[8] = { "i", "TISdet", "nargin",
  "nargout", "th", "thp", "thd", "th_dot" };

/* Function Declarations */
static void initialize_c40_Experiment_1_cs(SFc40_Experiment_1_csInstanceStruct
  *chartInstance);
static void initialize_params_c40_Experiment_1_cs
  (SFc40_Experiment_1_csInstanceStruct *chartInstance);
static void enable_c40_Experiment_1_cs(SFc40_Experiment_1_csInstanceStruct
  *chartInstance);
static void disable_c40_Experiment_1_cs(SFc40_Experiment_1_csInstanceStruct
  *chartInstance);
static void c40_update_debugger_state_c40_Experiment_1_cs
  (SFc40_Experiment_1_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c40_Experiment_1_cs
  (SFc40_Experiment_1_csInstanceStruct *chartInstance);
static void set_sim_state_c40_Experiment_1_cs
  (SFc40_Experiment_1_csInstanceStruct *chartInstance, const mxArray *c40_st);
static void finalize_c40_Experiment_1_cs(SFc40_Experiment_1_csInstanceStruct
  *chartInstance);
static void sf_gateway_c40_Experiment_1_cs(SFc40_Experiment_1_csInstanceStruct
  *chartInstance);
static void mdl_start_c40_Experiment_1_cs(SFc40_Experiment_1_csInstanceStruct
  *chartInstance);
static void initSimStructsc40_Experiment_1_cs
  (SFc40_Experiment_1_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c40_machineNumber, uint32_T
  c40_chartNumber, uint32_T c40_instanceNumber);
static const mxArray *c40_sf_marshallOut(void *chartInstanceVoid, void
  *c40_inData);
static void c40_emlrt_marshallIn(SFc40_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c40_b_th_dot, const char_T *c40_identifier,
  real_T c40_y[32]);
static void c40_b_emlrt_marshallIn(SFc40_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c40_u, const emlrtMsgIdentifier *c40_parentId,
  real_T c40_y[32]);
static void c40_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c40_mxArrayInData, const char_T *c40_varName, void *c40_outData);
static const mxArray *c40_b_sf_marshallOut(void *chartInstanceVoid, void
  *c40_inData);
static real_T c40_c_emlrt_marshallIn(SFc40_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c40_u, const emlrtMsgIdentifier *c40_parentId);
static void c40_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c40_mxArrayInData, const char_T *c40_varName, void *c40_outData);
static const mxArray *c40_c_sf_marshallOut(void *chartInstanceVoid, void
  *c40_inData);
static int32_T c40_d_emlrt_marshallIn(SFc40_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c40_u, const emlrtMsgIdentifier *c40_parentId);
static void c40_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c40_mxArrayInData, const char_T *c40_varName, void *c40_outData);
static uint8_T c40_e_emlrt_marshallIn(SFc40_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c40_b_is_active_c40_Experiment_1_cs, const
  char_T *c40_identifier);
static uint8_T c40_f_emlrt_marshallIn(SFc40_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c40_u, const emlrtMsgIdentifier *c40_parentId);
static void init_dsm_address_info(SFc40_Experiment_1_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc40_Experiment_1_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c40_Experiment_1_cs(SFc40_Experiment_1_csInstanceStruct
  *chartInstance)
{
  chartInstance->c40_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c40_is_active_c40_Experiment_1_cs = 0U;
}

static void initialize_params_c40_Experiment_1_cs
  (SFc40_Experiment_1_csInstanceStruct *chartInstance)
{
  real_T c40_d0;
  sf_mex_import_named("TISdet", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c40_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c40_TISdet = c40_d0;
}

static void enable_c40_Experiment_1_cs(SFc40_Experiment_1_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c40_Experiment_1_cs(SFc40_Experiment_1_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c40_update_debugger_state_c40_Experiment_1_cs
  (SFc40_Experiment_1_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c40_Experiment_1_cs
  (SFc40_Experiment_1_csInstanceStruct *chartInstance)
{
  const mxArray *c40_st;
  const mxArray *c40_y = NULL;
  int32_T c40_i0;
  real_T c40_u[32];
  const mxArray *c40_b_y = NULL;
  uint8_T c40_hoistedGlobal;
  uint8_T c40_b_u;
  const mxArray *c40_c_y = NULL;
  c40_st = NULL;
  c40_st = NULL;
  c40_y = NULL;
  sf_mex_assign(&c40_y, sf_mex_createcellmatrix(2, 1), false);
  for (c40_i0 = 0; c40_i0 < 32; c40_i0++) {
    c40_u[c40_i0] = (*chartInstance->c40_th_dot)[c40_i0];
  }

  c40_b_y = NULL;
  sf_mex_assign(&c40_b_y, sf_mex_create("y", c40_u, 0, 0U, 1U, 0U, 1, 32), false);
  sf_mex_setcell(c40_y, 0, c40_b_y);
  c40_hoistedGlobal = chartInstance->c40_is_active_c40_Experiment_1_cs;
  c40_b_u = c40_hoistedGlobal;
  c40_c_y = NULL;
  sf_mex_assign(&c40_c_y, sf_mex_create("y", &c40_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c40_y, 1, c40_c_y);
  sf_mex_assign(&c40_st, c40_y, false);
  return c40_st;
}

static void set_sim_state_c40_Experiment_1_cs
  (SFc40_Experiment_1_csInstanceStruct *chartInstance, const mxArray *c40_st)
{
  const mxArray *c40_u;
  real_T c40_dv0[32];
  int32_T c40_i1;
  chartInstance->c40_doneDoubleBufferReInit = true;
  c40_u = sf_mex_dup(c40_st);
  c40_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c40_u, 0)),
                       "th_dot", c40_dv0);
  for (c40_i1 = 0; c40_i1 < 32; c40_i1++) {
    (*chartInstance->c40_th_dot)[c40_i1] = c40_dv0[c40_i1];
  }

  chartInstance->c40_is_active_c40_Experiment_1_cs = c40_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c40_u, 1)),
     "is_active_c40_Experiment_1_cs");
  sf_mex_destroy(&c40_u);
  c40_update_debugger_state_c40_Experiment_1_cs(chartInstance);
  sf_mex_destroy(&c40_st);
}

static void finalize_c40_Experiment_1_cs(SFc40_Experiment_1_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c40_Experiment_1_cs(SFc40_Experiment_1_csInstanceStruct
  *chartInstance)
{
  int32_T c40_i2;
  int32_T c40_i3;
  int32_T c40_i4;
  int32_T c40_i5;
  real_T c40_b_th[32];
  int32_T c40_i6;
  real_T c40_b_thp[32];
  int32_T c40_i7;
  real_T c40_b_thd[32];
  uint32_T c40_debug_family_var_map[8];
  real_T c40_i;
  real_T c40_c_TISdet;
  real_T c40_nargin = 4.0;
  real_T c40_nargout = 1.0;
  real_T c40_b_th_dot[32];
  int32_T c40_i8;
  int32_T c40_b_i;
  real_T c40_d1;
  real_T c40_d2;
  real_T c40_d3;
  real_T c40_d4;
  int32_T c40_i9;
  int32_T c40_i10;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 34U, chartInstance->c40_sfEvent);
  for (c40_i2 = 0; c40_i2 < 32; c40_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c40_th)[c40_i2], 0U);
  }

  for (c40_i3 = 0; c40_i3 < 32; c40_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c40_thp)[c40_i3], 1U);
  }

  for (c40_i4 = 0; c40_i4 < 32; c40_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c40_thd)[c40_i4], 2U);
  }

  chartInstance->c40_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 34U, chartInstance->c40_sfEvent);
  for (c40_i5 = 0; c40_i5 < 32; c40_i5++) {
    c40_b_th[c40_i5] = (*chartInstance->c40_th)[c40_i5];
  }

  for (c40_i6 = 0; c40_i6 < 32; c40_i6++) {
    c40_b_thp[c40_i6] = (*chartInstance->c40_thp)[c40_i6];
  }

  for (c40_i7 = 0; c40_i7 < 32; c40_i7++) {
    c40_b_thd[c40_i7] = (*chartInstance->c40_thd)[c40_i7];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c40_debug_family_names,
    c40_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c40_i, 0U, c40_b_sf_marshallOut,
    c40_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c40_c_TISdet, 1U, c40_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c40_nargin, 2U, c40_b_sf_marshallOut,
    c40_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c40_nargout, 3U, c40_b_sf_marshallOut,
    c40_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c40_b_th, 4U, c40_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c40_b_thp, 5U, c40_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c40_b_thd, 6U, c40_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c40_b_th_dot, 7U, c40_sf_marshallOut,
    c40_sf_marshallIn);
  c40_c_TISdet = c40_b_TISdet;
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c40_sfEvent, 5);
  for (c40_i8 = 0; c40_i8 < 32; c40_i8++) {
    c40_b_th_dot[c40_i8] = c40_b_thd[c40_i8];
  }

  _SFD_EML_CALL(0U, chartInstance->c40_sfEvent, 6);
  c40_i = 1.0;
  c40_b_i = 0;
  while (c40_b_i < 32) {
    c40_i = 1.0 + (real_T)c40_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c40_sfEvent, 7);
    c40_d1 = c40_b_th[_SFD_EML_ARRAY_BOUNDS_CHECK("th", (int32_T)
      _SFD_INTEGER_CHECK("i", c40_i), 1, 32, 1, 0) - 1];
    guard1 = false;
    guard2 = false;
    guard3 = false;
    if (CV_EML_COND(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c40_d1, 0.0, -1, 0U,
          c40_d1 == 0.0))) {
      c40_d2 = c40_b_thp[_SFD_EML_ARRAY_BOUNDS_CHECK("thp", (int32_T)
        _SFD_INTEGER_CHECK("i", c40_i), 1, 32, 1, 0) - 1];
      if (CV_EML_COND(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c40_d2, 0.0, -1, 1U,
            c40_d2 != 0.0))) {
        guard2 = true;
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }

    if (guard3 == true) {
      c40_d3 = c40_b_th[_SFD_EML_ARRAY_BOUNDS_CHECK("th", (int32_T)
        _SFD_INTEGER_CHECK("i", c40_i), 1, 32, 1, 0) - 1];
      if (CV_EML_COND(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 2, c40_d3, 0.0, -1, 1U,
            c40_d3 != 0.0))) {
        c40_d4 = c40_b_thp[_SFD_EML_ARRAY_BOUNDS_CHECK("thp", (int32_T)
          _SFD_INTEGER_CHECK("i", c40_i), 1, 32, 1, 0) - 1];
        if (CV_EML_COND(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 3, c40_d4, 0.0, -1,
              0U, c40_d4 == 0.0))) {
          guard2 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
    }

    if (guard2 == true) {
      CV_EML_MCDC(0, 1, 0, true);
      CV_EML_IF(0, 1, 0, true);
      _SFD_EML_CALL(0U, chartInstance->c40_sfEvent, 8);
      c40_b_th_dot[_SFD_EML_ARRAY_BOUNDS_CHECK("th_dot", (int32_T)
        _SFD_INTEGER_CHECK("i", c40_i), 1, 32, 1, 0) - 1] = 0.0;
    }

    if (guard1 == true) {
      CV_EML_MCDC(0, 1, 0, false);
      CV_EML_IF(0, 1, 0, false);
    }

    c40_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c40_sfEvent, -8);
  _SFD_SYMBOL_SCOPE_POP();
  for (c40_i9 = 0; c40_i9 < 32; c40_i9++) {
    (*chartInstance->c40_th_dot)[c40_i9] = c40_b_th_dot[c40_i9];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 34U, chartInstance->c40_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_1_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c40_i10 = 0; c40_i10 < 32; c40_i10++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c40_th_dot)[c40_i10], 3U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c40_TISdet, 4U);
}

static void mdl_start_c40_Experiment_1_cs(SFc40_Experiment_1_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc40_Experiment_1_cs
  (SFc40_Experiment_1_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c40_machineNumber, uint32_T
  c40_chartNumber, uint32_T c40_instanceNumber)
{
  (void)c40_machineNumber;
  (void)c40_chartNumber;
  (void)c40_instanceNumber;
}

static const mxArray *c40_sf_marshallOut(void *chartInstanceVoid, void
  *c40_inData)
{
  const mxArray *c40_mxArrayOutData = NULL;
  int32_T c40_i11;
  real_T c40_b_inData[32];
  int32_T c40_i12;
  real_T c40_u[32];
  const mxArray *c40_y = NULL;
  SFc40_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc40_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c40_mxArrayOutData = NULL;
  for (c40_i11 = 0; c40_i11 < 32; c40_i11++) {
    c40_b_inData[c40_i11] = (*(real_T (*)[32])c40_inData)[c40_i11];
  }

  for (c40_i12 = 0; c40_i12 < 32; c40_i12++) {
    c40_u[c40_i12] = c40_b_inData[c40_i12];
  }

  c40_y = NULL;
  sf_mex_assign(&c40_y, sf_mex_create("y", c40_u, 0, 0U, 1U, 0U, 1, 32), false);
  sf_mex_assign(&c40_mxArrayOutData, c40_y, false);
  return c40_mxArrayOutData;
}

static void c40_emlrt_marshallIn(SFc40_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c40_b_th_dot, const char_T *c40_identifier,
  real_T c40_y[32])
{
  emlrtMsgIdentifier c40_thisId;
  c40_thisId.fIdentifier = c40_identifier;
  c40_thisId.fParent = NULL;
  c40_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c40_b_th_dot), &c40_thisId,
    c40_y);
  sf_mex_destroy(&c40_b_th_dot);
}

static void c40_b_emlrt_marshallIn(SFc40_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c40_u, const emlrtMsgIdentifier *c40_parentId,
  real_T c40_y[32])
{
  real_T c40_dv1[32];
  int32_T c40_i13;
  (void)chartInstance;
  sf_mex_import(c40_parentId, sf_mex_dup(c40_u), c40_dv1, 1, 0, 0U, 1, 0U, 1, 32);
  for (c40_i13 = 0; c40_i13 < 32; c40_i13++) {
    c40_y[c40_i13] = c40_dv1[c40_i13];
  }

  sf_mex_destroy(&c40_u);
}

static void c40_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c40_mxArrayInData, const char_T *c40_varName, void *c40_outData)
{
  const mxArray *c40_b_th_dot;
  const char_T *c40_identifier;
  emlrtMsgIdentifier c40_thisId;
  real_T c40_y[32];
  int32_T c40_i14;
  SFc40_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc40_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c40_b_th_dot = sf_mex_dup(c40_mxArrayInData);
  c40_identifier = c40_varName;
  c40_thisId.fIdentifier = c40_identifier;
  c40_thisId.fParent = NULL;
  c40_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c40_b_th_dot), &c40_thisId,
    c40_y);
  sf_mex_destroy(&c40_b_th_dot);
  for (c40_i14 = 0; c40_i14 < 32; c40_i14++) {
    (*(real_T (*)[32])c40_outData)[c40_i14] = c40_y[c40_i14];
  }

  sf_mex_destroy(&c40_mxArrayInData);
}

static const mxArray *c40_b_sf_marshallOut(void *chartInstanceVoid, void
  *c40_inData)
{
  const mxArray *c40_mxArrayOutData = NULL;
  real_T c40_u;
  const mxArray *c40_y = NULL;
  SFc40_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc40_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c40_mxArrayOutData = NULL;
  c40_u = *(real_T *)c40_inData;
  c40_y = NULL;
  sf_mex_assign(&c40_y, sf_mex_create("y", &c40_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c40_mxArrayOutData, c40_y, false);
  return c40_mxArrayOutData;
}

static real_T c40_c_emlrt_marshallIn(SFc40_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c40_u, const emlrtMsgIdentifier *c40_parentId)
{
  real_T c40_y;
  real_T c40_d5;
  (void)chartInstance;
  sf_mex_import(c40_parentId, sf_mex_dup(c40_u), &c40_d5, 1, 0, 0U, 0, 0U, 0);
  c40_y = c40_d5;
  sf_mex_destroy(&c40_u);
  return c40_y;
}

static void c40_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c40_mxArrayInData, const char_T *c40_varName, void *c40_outData)
{
  const mxArray *c40_nargout;
  const char_T *c40_identifier;
  emlrtMsgIdentifier c40_thisId;
  real_T c40_y;
  SFc40_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc40_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c40_nargout = sf_mex_dup(c40_mxArrayInData);
  c40_identifier = c40_varName;
  c40_thisId.fIdentifier = c40_identifier;
  c40_thisId.fParent = NULL;
  c40_y = c40_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c40_nargout),
    &c40_thisId);
  sf_mex_destroy(&c40_nargout);
  *(real_T *)c40_outData = c40_y;
  sf_mex_destroy(&c40_mxArrayInData);
}

const mxArray *sf_c40_Experiment_1_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c40_nameCaptureInfo = NULL;
  c40_nameCaptureInfo = NULL;
  sf_mex_assign(&c40_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c40_nameCaptureInfo;
}

static const mxArray *c40_c_sf_marshallOut(void *chartInstanceVoid, void
  *c40_inData)
{
  const mxArray *c40_mxArrayOutData = NULL;
  int32_T c40_u;
  const mxArray *c40_y = NULL;
  SFc40_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc40_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c40_mxArrayOutData = NULL;
  c40_u = *(int32_T *)c40_inData;
  c40_y = NULL;
  sf_mex_assign(&c40_y, sf_mex_create("y", &c40_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c40_mxArrayOutData, c40_y, false);
  return c40_mxArrayOutData;
}

static int32_T c40_d_emlrt_marshallIn(SFc40_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c40_u, const emlrtMsgIdentifier *c40_parentId)
{
  int32_T c40_y;
  int32_T c40_i15;
  (void)chartInstance;
  sf_mex_import(c40_parentId, sf_mex_dup(c40_u), &c40_i15, 1, 6, 0U, 0, 0U, 0);
  c40_y = c40_i15;
  sf_mex_destroy(&c40_u);
  return c40_y;
}

static void c40_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c40_mxArrayInData, const char_T *c40_varName, void *c40_outData)
{
  const mxArray *c40_b_sfEvent;
  const char_T *c40_identifier;
  emlrtMsgIdentifier c40_thisId;
  int32_T c40_y;
  SFc40_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc40_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c40_b_sfEvent = sf_mex_dup(c40_mxArrayInData);
  c40_identifier = c40_varName;
  c40_thisId.fIdentifier = c40_identifier;
  c40_thisId.fParent = NULL;
  c40_y = c40_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c40_b_sfEvent),
    &c40_thisId);
  sf_mex_destroy(&c40_b_sfEvent);
  *(int32_T *)c40_outData = c40_y;
  sf_mex_destroy(&c40_mxArrayInData);
}

static uint8_T c40_e_emlrt_marshallIn(SFc40_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c40_b_is_active_c40_Experiment_1_cs, const
  char_T *c40_identifier)
{
  uint8_T c40_y;
  emlrtMsgIdentifier c40_thisId;
  c40_thisId.fIdentifier = c40_identifier;
  c40_thisId.fParent = NULL;
  c40_y = c40_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c40_b_is_active_c40_Experiment_1_cs), &c40_thisId);
  sf_mex_destroy(&c40_b_is_active_c40_Experiment_1_cs);
  return c40_y;
}

static uint8_T c40_f_emlrt_marshallIn(SFc40_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c40_u, const emlrtMsgIdentifier *c40_parentId)
{
  uint8_T c40_y;
  uint8_T c40_u0;
  (void)chartInstance;
  sf_mex_import(c40_parentId, sf_mex_dup(c40_u), &c40_u0, 1, 3, 0U, 0, 0U, 0);
  c40_y = c40_u0;
  sf_mex_destroy(&c40_u);
  return c40_y;
}

static void init_dsm_address_info(SFc40_Experiment_1_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc40_Experiment_1_csInstanceStruct
  *chartInstance)
{
  chartInstance->c40_th = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c40_thp = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c40_thd = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c40_th_dot = (real_T (*)[32])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
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

void sf_c40_Experiment_1_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3922873876U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2265432277U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2461802642U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1818794977U);
}

mxArray* sf_c40_Experiment_1_cs_get_post_codegen_info(void);
mxArray *sf_c40_Experiment_1_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("4Gvrv1C64iq3auDSmaJ8VB");
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

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c40_Experiment_1_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c40_Experiment_1_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c40_Experiment_1_cs_jit_fallback_info(void)
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

mxArray *sf_c40_Experiment_1_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c40_Experiment_1_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c40_Experiment_1_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"th_dot\",},{M[8],M[0],T\"is_active_c40_Experiment_1_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c40_Experiment_1_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc40_Experiment_1_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc40_Experiment_1_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_1_csMachineNumber_,
           40,
           1,
           1,
           0,
           5,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_Experiment_1_csMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Experiment_1_csMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Experiment_1_csMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"th");
          _SFD_SET_DATA_PROPS(1,1,1,0,"thp");
          _SFD_SET_DATA_PROPS(2,1,1,0,"thd");
          _SFD_SET_DATA_PROPS(3,2,0,1,"th_dot");
          _SFD_SET_DATA_PROPS(4,10,0,0,"TISdet");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,1,0,4,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,224);
        _SFD_CV_INIT_EML_IF(0,1,0,132,185,-1,216);
        _SFD_CV_INIT_EML_FOR(0,1,0,109,128,220);

        {
          static int condStart[] = { 136, 148, 163, 175 };

          static int condEnd[] = { 144, 157, 171, 184 };

          static int pfixExpr[] = { 0, 1, -3, 2, 3, -3, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,135,185,4,0,&(condStart[0]),&(condEnd[0]),
                                7,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,136,144,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,148,157,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,163,171,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,175,184,-1,0);

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c40_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c40_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c40_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c40_sf_marshallOut,(MexInFcnForType)
            c40_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c40_b_sf_marshallOut,(MexInFcnForType)
          c40_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c40_th);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c40_thp);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c40_thd);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c40_th_dot);
        _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c40_TISdet);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Experiment_1_csMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "jIGMOZCgQ2HiOeP3Gv9ggE";
}

static void sf_opaque_initialize_c40_Experiment_1_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc40_Experiment_1_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c40_Experiment_1_cs((SFc40_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
  initialize_c40_Experiment_1_cs((SFc40_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c40_Experiment_1_cs(void *chartInstanceVar)
{
  enable_c40_Experiment_1_cs((SFc40_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c40_Experiment_1_cs(void *chartInstanceVar)
{
  disable_c40_Experiment_1_cs((SFc40_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c40_Experiment_1_cs(void *chartInstanceVar)
{
  sf_gateway_c40_Experiment_1_cs((SFc40_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c40_Experiment_1_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c40_Experiment_1_cs((SFc40_Experiment_1_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c40_Experiment_1_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c40_Experiment_1_cs((SFc40_Experiment_1_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c40_Experiment_1_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc40_Experiment_1_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_1_cs_optimization_info();
    }

    finalize_c40_Experiment_1_cs((SFc40_Experiment_1_csInstanceStruct*)
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
  initSimStructsc40_Experiment_1_cs((SFc40_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c40_Experiment_1_cs(SimStruct *S)
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
    initialize_params_c40_Experiment_1_cs((SFc40_Experiment_1_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c40_Experiment_1_cs(SimStruct *S)
{
  /* Actual parameters from chart:
     TISdet
   */
  const char_T *rtParamNames[] = { "TISdet" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for TISdet*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Experiment_1_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      40);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,40,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,40,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,40);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,40,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,40,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,40);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4273533684U));
  ssSetChecksum1(S,(3332179222U));
  ssSetChecksum2(S,(1239189083U));
  ssSetChecksum3(S,(2618407181U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c40_Experiment_1_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c40_Experiment_1_cs(SimStruct *S)
{
  SFc40_Experiment_1_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc40_Experiment_1_csInstanceStruct *)utMalloc(sizeof
    (SFc40_Experiment_1_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc40_Experiment_1_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c40_Experiment_1_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c40_Experiment_1_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c40_Experiment_1_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c40_Experiment_1_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c40_Experiment_1_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c40_Experiment_1_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c40_Experiment_1_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c40_Experiment_1_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c40_Experiment_1_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c40_Experiment_1_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c40_Experiment_1_cs;
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

void c40_Experiment_1_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c40_Experiment_1_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c40_Experiment_1_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c40_Experiment_1_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c40_Experiment_1_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
