/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_cs_sfun.h"
#include "c52_Experiment_cs.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Experiment_cs_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c52_b_TISdet                   (32.0)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c52_debug_family_names[7] = { "i", "TISdet", "nargin",
  "nargout", "v", "xpd", "xp_dot" };

/* Function Declarations */
static void initialize_c52_Experiment_cs(SFc52_Experiment_csInstanceStruct
  *chartInstance);
static void initialize_params_c52_Experiment_cs
  (SFc52_Experiment_csInstanceStruct *chartInstance);
static void enable_c52_Experiment_cs(SFc52_Experiment_csInstanceStruct
  *chartInstance);
static void disable_c52_Experiment_cs(SFc52_Experiment_csInstanceStruct
  *chartInstance);
static void c52_update_debugger_state_c52_Experiment_cs
  (SFc52_Experiment_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c52_Experiment_cs
  (SFc52_Experiment_csInstanceStruct *chartInstance);
static void set_sim_state_c52_Experiment_cs(SFc52_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c52_st);
static void finalize_c52_Experiment_cs(SFc52_Experiment_csInstanceStruct
  *chartInstance);
static void sf_gateway_c52_Experiment_cs(SFc52_Experiment_csInstanceStruct
  *chartInstance);
static void mdl_start_c52_Experiment_cs(SFc52_Experiment_csInstanceStruct
  *chartInstance);
static void initSimStructsc52_Experiment_cs(SFc52_Experiment_csInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c52_machineNumber, uint32_T
  c52_chartNumber, uint32_T c52_instanceNumber);
static const mxArray *c52_sf_marshallOut(void *chartInstanceVoid, void
  *c52_inData);
static void c52_emlrt_marshallIn(SFc52_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c52_b_xp_dot, const char_T *c52_identifier,
  real_T c52_y[32]);
static void c52_b_emlrt_marshallIn(SFc52_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c52_u, const emlrtMsgIdentifier *c52_parentId,
  real_T c52_y[32]);
static void c52_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c52_mxArrayInData, const char_T *c52_varName, void *c52_outData);
static const mxArray *c52_b_sf_marshallOut(void *chartInstanceVoid, void
  *c52_inData);
static real_T c52_c_emlrt_marshallIn(SFc52_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c52_u, const emlrtMsgIdentifier *c52_parentId);
static void c52_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c52_mxArrayInData, const char_T *c52_varName, void *c52_outData);
static const mxArray *c52_c_sf_marshallOut(void *chartInstanceVoid, void
  *c52_inData);
static int32_T c52_d_emlrt_marshallIn(SFc52_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c52_u, const emlrtMsgIdentifier *c52_parentId);
static void c52_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c52_mxArrayInData, const char_T *c52_varName, void *c52_outData);
static uint8_T c52_e_emlrt_marshallIn(SFc52_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c52_b_is_active_c52_Experiment_cs, const char_T
  *c52_identifier);
static uint8_T c52_f_emlrt_marshallIn(SFc52_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c52_u, const emlrtMsgIdentifier *c52_parentId);
static void init_dsm_address_info(SFc52_Experiment_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc52_Experiment_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c52_Experiment_cs(SFc52_Experiment_csInstanceStruct
  *chartInstance)
{
  chartInstance->c52_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c52_is_active_c52_Experiment_cs = 0U;
}

static void initialize_params_c52_Experiment_cs
  (SFc52_Experiment_csInstanceStruct *chartInstance)
{
  real_T c52_d0;
  sf_mex_import_named("TISdet", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c52_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c52_TISdet = c52_d0;
}

static void enable_c52_Experiment_cs(SFc52_Experiment_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c52_Experiment_cs(SFc52_Experiment_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c52_update_debugger_state_c52_Experiment_cs
  (SFc52_Experiment_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c52_Experiment_cs
  (SFc52_Experiment_csInstanceStruct *chartInstance)
{
  const mxArray *c52_st;
  const mxArray *c52_y = NULL;
  int32_T c52_i0;
  real_T c52_u[32];
  const mxArray *c52_b_y = NULL;
  uint8_T c52_hoistedGlobal;
  uint8_T c52_b_u;
  const mxArray *c52_c_y = NULL;
  c52_st = NULL;
  c52_st = NULL;
  c52_y = NULL;
  sf_mex_assign(&c52_y, sf_mex_createcellmatrix(2, 1), false);
  for (c52_i0 = 0; c52_i0 < 32; c52_i0++) {
    c52_u[c52_i0] = (*chartInstance->c52_xp_dot)[c52_i0];
  }

  c52_b_y = NULL;
  sf_mex_assign(&c52_b_y, sf_mex_create("y", c52_u, 0, 0U, 1U, 0U, 1, 32), false);
  sf_mex_setcell(c52_y, 0, c52_b_y);
  c52_hoistedGlobal = chartInstance->c52_is_active_c52_Experiment_cs;
  c52_b_u = c52_hoistedGlobal;
  c52_c_y = NULL;
  sf_mex_assign(&c52_c_y, sf_mex_create("y", &c52_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c52_y, 1, c52_c_y);
  sf_mex_assign(&c52_st, c52_y, false);
  return c52_st;
}

static void set_sim_state_c52_Experiment_cs(SFc52_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c52_st)
{
  const mxArray *c52_u;
  real_T c52_dv0[32];
  int32_T c52_i1;
  chartInstance->c52_doneDoubleBufferReInit = true;
  c52_u = sf_mex_dup(c52_st);
  c52_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c52_u, 0)),
                       "xp_dot", c52_dv0);
  for (c52_i1 = 0; c52_i1 < 32; c52_i1++) {
    (*chartInstance->c52_xp_dot)[c52_i1] = c52_dv0[c52_i1];
  }

  chartInstance->c52_is_active_c52_Experiment_cs = c52_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c52_u, 1)),
     "is_active_c52_Experiment_cs");
  sf_mex_destroy(&c52_u);
  c52_update_debugger_state_c52_Experiment_cs(chartInstance);
  sf_mex_destroy(&c52_st);
}

static void finalize_c52_Experiment_cs(SFc52_Experiment_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c52_Experiment_cs(SFc52_Experiment_csInstanceStruct
  *chartInstance)
{
  int32_T c52_i2;
  real_T c52_hoistedGlobal;
  real_T c52_b_v;
  int32_T c52_i3;
  real_T c52_b_xpd[32];
  uint32_T c52_debug_family_var_map[7];
  real_T c52_i;
  real_T c52_c_TISdet;
  real_T c52_nargin = 3.0;
  real_T c52_nargout = 1.0;
  real_T c52_b_xp_dot[32];
  int32_T c52_i4;
  int32_T c52_b_i;
  real_T c52_d1;
  int32_T c52_i5;
  int32_T c52_i6;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 51U, chartInstance->c52_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c52_v, 0U);
  for (c52_i2 = 0; c52_i2 < 32; c52_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c52_xpd)[c52_i2], 1U);
  }

  chartInstance->c52_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 51U, chartInstance->c52_sfEvent);
  c52_hoistedGlobal = *chartInstance->c52_v;
  c52_b_v = c52_hoistedGlobal;
  for (c52_i3 = 0; c52_i3 < 32; c52_i3++) {
    c52_b_xpd[c52_i3] = (*chartInstance->c52_xpd)[c52_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c52_debug_family_names,
    c52_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c52_i, 0U, c52_b_sf_marshallOut,
    c52_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c52_c_TISdet, 1U, c52_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c52_nargin, 2U, c52_b_sf_marshallOut,
    c52_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c52_nargout, 3U, c52_b_sf_marshallOut,
    c52_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c52_b_v, 4U, c52_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c52_b_xpd, 5U, c52_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c52_b_xp_dot, 6U, c52_sf_marshallOut,
    c52_sf_marshallIn);
  c52_c_TISdet = c52_b_TISdet;
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c52_sfEvent, 5);
  for (c52_i4 = 0; c52_i4 < 32; c52_i4++) {
    c52_b_xp_dot[c52_i4] = c52_b_xpd[c52_i4];
  }

  _SFD_EML_CALL(0U, chartInstance->c52_sfEvent, 6);
  c52_i = 1.0;
  c52_b_i = 0;
  while (c52_b_i < 32) {
    c52_i = 1.0 + (real_T)c52_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c52_sfEvent, 7);
    c52_d1 = c52_b_xpd[_SFD_EML_ARRAY_BOUNDS_CHECK("xpd", (int32_T)
      _SFD_INTEGER_CHECK("i", c52_i), 1, 32, 1, 0) - 1];
    if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c52_d1, c52_b_v, -1, 0U,
          c52_d1 == c52_b_v))) {
      _SFD_EML_CALL(0U, chartInstance->c52_sfEvent, 8);
      c52_b_xp_dot[_SFD_EML_ARRAY_BOUNDS_CHECK("xp_dot", (int32_T)
        _SFD_INTEGER_CHECK("i", c52_i), 1, 32, 1, 0) - 1] = 0.0;
    }

    c52_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c52_sfEvent, -8);
  _SFD_SYMBOL_SCOPE_POP();
  for (c52_i5 = 0; c52_i5 < 32; c52_i5++) {
    (*chartInstance->c52_xp_dot)[c52_i5] = c52_b_xp_dot[c52_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 51U, chartInstance->c52_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c52_i6 = 0; c52_i6 < 32; c52_i6++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c52_xp_dot)[c52_i6], 2U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c52_TISdet, 3U);
}

static void mdl_start_c52_Experiment_cs(SFc52_Experiment_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc52_Experiment_cs(SFc52_Experiment_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c52_machineNumber, uint32_T
  c52_chartNumber, uint32_T c52_instanceNumber)
{
  (void)c52_machineNumber;
  (void)c52_chartNumber;
  (void)c52_instanceNumber;
}

static const mxArray *c52_sf_marshallOut(void *chartInstanceVoid, void
  *c52_inData)
{
  const mxArray *c52_mxArrayOutData = NULL;
  int32_T c52_i7;
  real_T c52_b_inData[32];
  int32_T c52_i8;
  real_T c52_u[32];
  const mxArray *c52_y = NULL;
  SFc52_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc52_Experiment_csInstanceStruct *)chartInstanceVoid;
  c52_mxArrayOutData = NULL;
  for (c52_i7 = 0; c52_i7 < 32; c52_i7++) {
    c52_b_inData[c52_i7] = (*(real_T (*)[32])c52_inData)[c52_i7];
  }

  for (c52_i8 = 0; c52_i8 < 32; c52_i8++) {
    c52_u[c52_i8] = c52_b_inData[c52_i8];
  }

  c52_y = NULL;
  sf_mex_assign(&c52_y, sf_mex_create("y", c52_u, 0, 0U, 1U, 0U, 1, 32), false);
  sf_mex_assign(&c52_mxArrayOutData, c52_y, false);
  return c52_mxArrayOutData;
}

static void c52_emlrt_marshallIn(SFc52_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c52_b_xp_dot, const char_T *c52_identifier,
  real_T c52_y[32])
{
  emlrtMsgIdentifier c52_thisId;
  c52_thisId.fIdentifier = c52_identifier;
  c52_thisId.fParent = NULL;
  c52_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c52_b_xp_dot), &c52_thisId,
    c52_y);
  sf_mex_destroy(&c52_b_xp_dot);
}

static void c52_b_emlrt_marshallIn(SFc52_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c52_u, const emlrtMsgIdentifier *c52_parentId,
  real_T c52_y[32])
{
  real_T c52_dv1[32];
  int32_T c52_i9;
  (void)chartInstance;
  sf_mex_import(c52_parentId, sf_mex_dup(c52_u), c52_dv1, 1, 0, 0U, 1, 0U, 1, 32);
  for (c52_i9 = 0; c52_i9 < 32; c52_i9++) {
    c52_y[c52_i9] = c52_dv1[c52_i9];
  }

  sf_mex_destroy(&c52_u);
}

static void c52_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c52_mxArrayInData, const char_T *c52_varName, void *c52_outData)
{
  const mxArray *c52_b_xp_dot;
  const char_T *c52_identifier;
  emlrtMsgIdentifier c52_thisId;
  real_T c52_y[32];
  int32_T c52_i10;
  SFc52_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc52_Experiment_csInstanceStruct *)chartInstanceVoid;
  c52_b_xp_dot = sf_mex_dup(c52_mxArrayInData);
  c52_identifier = c52_varName;
  c52_thisId.fIdentifier = c52_identifier;
  c52_thisId.fParent = NULL;
  c52_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c52_b_xp_dot), &c52_thisId,
    c52_y);
  sf_mex_destroy(&c52_b_xp_dot);
  for (c52_i10 = 0; c52_i10 < 32; c52_i10++) {
    (*(real_T (*)[32])c52_outData)[c52_i10] = c52_y[c52_i10];
  }

  sf_mex_destroy(&c52_mxArrayInData);
}

static const mxArray *c52_b_sf_marshallOut(void *chartInstanceVoid, void
  *c52_inData)
{
  const mxArray *c52_mxArrayOutData = NULL;
  real_T c52_u;
  const mxArray *c52_y = NULL;
  SFc52_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc52_Experiment_csInstanceStruct *)chartInstanceVoid;
  c52_mxArrayOutData = NULL;
  c52_u = *(real_T *)c52_inData;
  c52_y = NULL;
  sf_mex_assign(&c52_y, sf_mex_create("y", &c52_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c52_mxArrayOutData, c52_y, false);
  return c52_mxArrayOutData;
}

static real_T c52_c_emlrt_marshallIn(SFc52_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c52_u, const emlrtMsgIdentifier *c52_parentId)
{
  real_T c52_y;
  real_T c52_d2;
  (void)chartInstance;
  sf_mex_import(c52_parentId, sf_mex_dup(c52_u), &c52_d2, 1, 0, 0U, 0, 0U, 0);
  c52_y = c52_d2;
  sf_mex_destroy(&c52_u);
  return c52_y;
}

static void c52_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c52_mxArrayInData, const char_T *c52_varName, void *c52_outData)
{
  const mxArray *c52_nargout;
  const char_T *c52_identifier;
  emlrtMsgIdentifier c52_thisId;
  real_T c52_y;
  SFc52_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc52_Experiment_csInstanceStruct *)chartInstanceVoid;
  c52_nargout = sf_mex_dup(c52_mxArrayInData);
  c52_identifier = c52_varName;
  c52_thisId.fIdentifier = c52_identifier;
  c52_thisId.fParent = NULL;
  c52_y = c52_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c52_nargout),
    &c52_thisId);
  sf_mex_destroy(&c52_nargout);
  *(real_T *)c52_outData = c52_y;
  sf_mex_destroy(&c52_mxArrayInData);
}

const mxArray *sf_c52_Experiment_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c52_nameCaptureInfo = NULL;
  c52_nameCaptureInfo = NULL;
  sf_mex_assign(&c52_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c52_nameCaptureInfo;
}

static const mxArray *c52_c_sf_marshallOut(void *chartInstanceVoid, void
  *c52_inData)
{
  const mxArray *c52_mxArrayOutData = NULL;
  int32_T c52_u;
  const mxArray *c52_y = NULL;
  SFc52_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc52_Experiment_csInstanceStruct *)chartInstanceVoid;
  c52_mxArrayOutData = NULL;
  c52_u = *(int32_T *)c52_inData;
  c52_y = NULL;
  sf_mex_assign(&c52_y, sf_mex_create("y", &c52_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c52_mxArrayOutData, c52_y, false);
  return c52_mxArrayOutData;
}

static int32_T c52_d_emlrt_marshallIn(SFc52_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c52_u, const emlrtMsgIdentifier *c52_parentId)
{
  int32_T c52_y;
  int32_T c52_i11;
  (void)chartInstance;
  sf_mex_import(c52_parentId, sf_mex_dup(c52_u), &c52_i11, 1, 6, 0U, 0, 0U, 0);
  c52_y = c52_i11;
  sf_mex_destroy(&c52_u);
  return c52_y;
}

static void c52_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c52_mxArrayInData, const char_T *c52_varName, void *c52_outData)
{
  const mxArray *c52_b_sfEvent;
  const char_T *c52_identifier;
  emlrtMsgIdentifier c52_thisId;
  int32_T c52_y;
  SFc52_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc52_Experiment_csInstanceStruct *)chartInstanceVoid;
  c52_b_sfEvent = sf_mex_dup(c52_mxArrayInData);
  c52_identifier = c52_varName;
  c52_thisId.fIdentifier = c52_identifier;
  c52_thisId.fParent = NULL;
  c52_y = c52_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c52_b_sfEvent),
    &c52_thisId);
  sf_mex_destroy(&c52_b_sfEvent);
  *(int32_T *)c52_outData = c52_y;
  sf_mex_destroy(&c52_mxArrayInData);
}

static uint8_T c52_e_emlrt_marshallIn(SFc52_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c52_b_is_active_c52_Experiment_cs, const char_T
  *c52_identifier)
{
  uint8_T c52_y;
  emlrtMsgIdentifier c52_thisId;
  c52_thisId.fIdentifier = c52_identifier;
  c52_thisId.fParent = NULL;
  c52_y = c52_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c52_b_is_active_c52_Experiment_cs), &c52_thisId);
  sf_mex_destroy(&c52_b_is_active_c52_Experiment_cs);
  return c52_y;
}

static uint8_T c52_f_emlrt_marshallIn(SFc52_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c52_u, const emlrtMsgIdentifier *c52_parentId)
{
  uint8_T c52_y;
  uint8_T c52_u0;
  (void)chartInstance;
  sf_mex_import(c52_parentId, sf_mex_dup(c52_u), &c52_u0, 1, 3, 0U, 0, 0U, 0);
  c52_y = c52_u0;
  sf_mex_destroy(&c52_u);
  return c52_y;
}

static void init_dsm_address_info(SFc52_Experiment_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc52_Experiment_csInstanceStruct
  *chartInstance)
{
  chartInstance->c52_v = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    0);
  chartInstance->c52_xpd = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c52_xp_dot = (real_T (*)[32])ssGetOutputPortSignal_wrapper
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

void sf_c52_Experiment_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(967388019U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(656571879U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(793011943U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(882530439U);
}

mxArray* sf_c52_Experiment_cs_get_post_codegen_info(void);
mxArray *sf_c52_Experiment_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("yG0fEs3biY9eHzo0EWbYxF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxArray* mxPostCodegenInfo = sf_c52_Experiment_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c52_Experiment_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c52_Experiment_cs_jit_fallback_info(void)
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

mxArray *sf_c52_Experiment_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c52_Experiment_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c52_Experiment_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"xp_dot\",},{M[8],M[0],T\"is_active_c52_Experiment_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c52_Experiment_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc52_Experiment_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc52_Experiment_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_csMachineNumber_,
           52,
           1,
           1,
           0,
           4,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_Experiment_csMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Experiment_csMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Experiment_csMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"v");
          _SFD_SET_DATA_PROPS(1,1,1,0,"xpd");
          _SFD_SET_DATA_PROPS(2,2,0,1,"xp_dot");
          _SFD_SET_DATA_PROPS(3,10,0,0,"TISdet");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,166);
        _SFD_CV_INIT_EML_IF(0,1,0,114,128,-1,158);
        _SFD_CV_INIT_EML_FOR(0,1,0,91,110,162);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,117,128,-1,0);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c52_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c52_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c52_sf_marshallOut,(MexInFcnForType)
            c52_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c52_b_sf_marshallOut,(MexInFcnForType)
          c52_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c52_v);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c52_xpd);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c52_xp_dot);
        _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c52_TISdet);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Experiment_csMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "W62ODce4JzEarUupGRZFwD";
}

static void sf_opaque_initialize_c52_Experiment_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc52_Experiment_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c52_Experiment_cs((SFc52_Experiment_csInstanceStruct*)
    chartInstanceVar);
  initialize_c52_Experiment_cs((SFc52_Experiment_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c52_Experiment_cs(void *chartInstanceVar)
{
  enable_c52_Experiment_cs((SFc52_Experiment_csInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c52_Experiment_cs(void *chartInstanceVar)
{
  disable_c52_Experiment_cs((SFc52_Experiment_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c52_Experiment_cs(void *chartInstanceVar)
{
  sf_gateway_c52_Experiment_cs((SFc52_Experiment_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c52_Experiment_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c52_Experiment_cs((SFc52_Experiment_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c52_Experiment_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c52_Experiment_cs((SFc52_Experiment_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c52_Experiment_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc52_Experiment_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_cs_optimization_info();
    }

    finalize_c52_Experiment_cs((SFc52_Experiment_csInstanceStruct*)
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
  initSimStructsc52_Experiment_cs((SFc52_Experiment_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c52_Experiment_cs(SimStruct *S)
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
    initialize_params_c52_Experiment_cs((SFc52_Experiment_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c52_Experiment_cs(SimStruct *S)
{
  /* Actual parameters from chart:
     TISdet
   */
  const char_T *rtParamNames[] = { "TISdet" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for TISdet*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Experiment_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      52);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,52,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,52,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,52);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,52,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,52,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,52);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(40159749U));
  ssSetChecksum1(S,(4128157534U));
  ssSetChecksum2(S,(1533392348U));
  ssSetChecksum3(S,(1453042677U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c52_Experiment_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c52_Experiment_cs(SimStruct *S)
{
  SFc52_Experiment_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc52_Experiment_csInstanceStruct *)utMalloc(sizeof
    (SFc52_Experiment_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc52_Experiment_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c52_Experiment_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c52_Experiment_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c52_Experiment_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c52_Experiment_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c52_Experiment_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c52_Experiment_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c52_Experiment_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c52_Experiment_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c52_Experiment_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c52_Experiment_cs;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c52_Experiment_cs;
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

void c52_Experiment_cs_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c52_Experiment_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c52_Experiment_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c52_Experiment_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c52_Experiment_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
