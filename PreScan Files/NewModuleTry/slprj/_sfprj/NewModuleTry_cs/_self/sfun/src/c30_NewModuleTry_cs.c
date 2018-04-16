/* Include files */

#include <stddef.h>
#include "blas.h"
#include "NewModuleTry_cs_sfun.h"
#include "c30_NewModuleTry_cs.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "NewModuleTry_cs_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c30_b_TISdet                   (32.0)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c30_debug_family_names[8] = { "i", "TISdet", "nargin",
  "nargout", "th", "thp", "thd", "th_dot" };

/* Function Declarations */
static void initialize_c30_NewModuleTry_cs(SFc30_NewModuleTry_csInstanceStruct
  *chartInstance);
static void initialize_params_c30_NewModuleTry_cs
  (SFc30_NewModuleTry_csInstanceStruct *chartInstance);
static void enable_c30_NewModuleTry_cs(SFc30_NewModuleTry_csInstanceStruct
  *chartInstance);
static void disable_c30_NewModuleTry_cs(SFc30_NewModuleTry_csInstanceStruct
  *chartInstance);
static void c30_update_debugger_state_c30_NewModuleTry_cs
  (SFc30_NewModuleTry_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c30_NewModuleTry_cs
  (SFc30_NewModuleTry_csInstanceStruct *chartInstance);
static void set_sim_state_c30_NewModuleTry_cs
  (SFc30_NewModuleTry_csInstanceStruct *chartInstance, const mxArray *c30_st);
static void finalize_c30_NewModuleTry_cs(SFc30_NewModuleTry_csInstanceStruct
  *chartInstance);
static void sf_gateway_c30_NewModuleTry_cs(SFc30_NewModuleTry_csInstanceStruct
  *chartInstance);
static void mdl_start_c30_NewModuleTry_cs(SFc30_NewModuleTry_csInstanceStruct
  *chartInstance);
static void initSimStructsc30_NewModuleTry_cs
  (SFc30_NewModuleTry_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c30_machineNumber, uint32_T
  c30_chartNumber, uint32_T c30_instanceNumber);
static const mxArray *c30_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData);
static void c30_emlrt_marshallIn(SFc30_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c30_b_th_dot, const char_T *c30_identifier,
  real_T c30_y[32]);
static void c30_b_emlrt_marshallIn(SFc30_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId,
  real_T c30_y[32]);
static void c30_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData);
static const mxArray *c30_b_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData);
static real_T c30_c_emlrt_marshallIn(SFc30_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId);
static void c30_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData);
static const mxArray *c30_c_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData);
static int32_T c30_d_emlrt_marshallIn(SFc30_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId);
static void c30_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData);
static uint8_T c30_e_emlrt_marshallIn(SFc30_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c30_b_is_active_c30_NewModuleTry_cs, const
  char_T *c30_identifier);
static uint8_T c30_f_emlrt_marshallIn(SFc30_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId);
static void init_dsm_address_info(SFc30_NewModuleTry_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc30_NewModuleTry_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c30_NewModuleTry_cs(SFc30_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  chartInstance->c30_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c30_is_active_c30_NewModuleTry_cs = 0U;
}

static void initialize_params_c30_NewModuleTry_cs
  (SFc30_NewModuleTry_csInstanceStruct *chartInstance)
{
  real_T c30_d0;
  sf_mex_import_named("TISdet", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c30_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c30_TISdet = c30_d0;
}

static void enable_c30_NewModuleTry_cs(SFc30_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c30_NewModuleTry_cs(SFc30_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c30_update_debugger_state_c30_NewModuleTry_cs
  (SFc30_NewModuleTry_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c30_NewModuleTry_cs
  (SFc30_NewModuleTry_csInstanceStruct *chartInstance)
{
  const mxArray *c30_st;
  const mxArray *c30_y = NULL;
  int32_T c30_i0;
  real_T c30_u[32];
  const mxArray *c30_b_y = NULL;
  uint8_T c30_hoistedGlobal;
  uint8_T c30_b_u;
  const mxArray *c30_c_y = NULL;
  c30_st = NULL;
  c30_st = NULL;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_createcellmatrix(2, 1), false);
  for (c30_i0 = 0; c30_i0 < 32; c30_i0++) {
    c30_u[c30_i0] = (*chartInstance->c30_th_dot)[c30_i0];
  }

  c30_b_y = NULL;
  sf_mex_assign(&c30_b_y, sf_mex_create("y", c30_u, 0, 0U, 1U, 0U, 1, 32), false);
  sf_mex_setcell(c30_y, 0, c30_b_y);
  c30_hoistedGlobal = chartInstance->c30_is_active_c30_NewModuleTry_cs;
  c30_b_u = c30_hoistedGlobal;
  c30_c_y = NULL;
  sf_mex_assign(&c30_c_y, sf_mex_create("y", &c30_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c30_y, 1, c30_c_y);
  sf_mex_assign(&c30_st, c30_y, false);
  return c30_st;
}

static void set_sim_state_c30_NewModuleTry_cs
  (SFc30_NewModuleTry_csInstanceStruct *chartInstance, const mxArray *c30_st)
{
  const mxArray *c30_u;
  real_T c30_dv0[32];
  int32_T c30_i1;
  chartInstance->c30_doneDoubleBufferReInit = true;
  c30_u = sf_mex_dup(c30_st);
  c30_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c30_u, 0)),
                       "th_dot", c30_dv0);
  for (c30_i1 = 0; c30_i1 < 32; c30_i1++) {
    (*chartInstance->c30_th_dot)[c30_i1] = c30_dv0[c30_i1];
  }

  chartInstance->c30_is_active_c30_NewModuleTry_cs = c30_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c30_u, 1)),
     "is_active_c30_NewModuleTry_cs");
  sf_mex_destroy(&c30_u);
  c30_update_debugger_state_c30_NewModuleTry_cs(chartInstance);
  sf_mex_destroy(&c30_st);
}

static void finalize_c30_NewModuleTry_cs(SFc30_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c30_NewModuleTry_cs(SFc30_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  int32_T c30_i2;
  int32_T c30_i3;
  int32_T c30_i4;
  int32_T c30_i5;
  real_T c30_b_th[32];
  int32_T c30_i6;
  real_T c30_b_thp[32];
  int32_T c30_i7;
  real_T c30_b_thd[32];
  uint32_T c30_debug_family_var_map[8];
  real_T c30_i;
  real_T c30_c_TISdet;
  real_T c30_nargin = 4.0;
  real_T c30_nargout = 1.0;
  real_T c30_b_th_dot[32];
  int32_T c30_i8;
  int32_T c30_b_i;
  real_T c30_d1;
  real_T c30_d2;
  real_T c30_d3;
  real_T c30_d4;
  int32_T c30_i9;
  int32_T c30_i10;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 29U, chartInstance->c30_sfEvent);
  for (c30_i2 = 0; c30_i2 < 32; c30_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c30_th)[c30_i2], 0U);
  }

  for (c30_i3 = 0; c30_i3 < 32; c30_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c30_thp)[c30_i3], 1U);
  }

  for (c30_i4 = 0; c30_i4 < 32; c30_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c30_thd)[c30_i4], 2U);
  }

  chartInstance->c30_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 29U, chartInstance->c30_sfEvent);
  for (c30_i5 = 0; c30_i5 < 32; c30_i5++) {
    c30_b_th[c30_i5] = (*chartInstance->c30_th)[c30_i5];
  }

  for (c30_i6 = 0; c30_i6 < 32; c30_i6++) {
    c30_b_thp[c30_i6] = (*chartInstance->c30_thp)[c30_i6];
  }

  for (c30_i7 = 0; c30_i7 < 32; c30_i7++) {
    c30_b_thd[c30_i7] = (*chartInstance->c30_thd)[c30_i7];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c30_debug_family_names,
    c30_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_i, 0U, c30_b_sf_marshallOut,
    c30_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c30_c_TISdet, 1U, c30_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_nargin, 2U, c30_b_sf_marshallOut,
    c30_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_nargout, 3U, c30_b_sf_marshallOut,
    c30_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c30_b_th, 4U, c30_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c30_b_thp, 5U, c30_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c30_b_thd, 6U, c30_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c30_b_th_dot, 7U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  c30_c_TISdet = c30_b_TISdet;
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 5);
  for (c30_i8 = 0; c30_i8 < 32; c30_i8++) {
    c30_b_th_dot[c30_i8] = c30_b_thd[c30_i8];
  }

  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 6);
  c30_i = 1.0;
  c30_b_i = 0;
  while (c30_b_i < 32) {
    c30_i = 1.0 + (real_T)c30_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 7);
    c30_d1 = c30_b_th[_SFD_EML_ARRAY_BOUNDS_CHECK("th", (int32_T)
      _SFD_INTEGER_CHECK("i", c30_i), 1, 32, 1, 0) - 1];
    guard1 = false;
    guard2 = false;
    guard3 = false;
    if (CV_EML_COND(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c30_d1, 0.0, -1, 0U,
          c30_d1 == 0.0))) {
      c30_d2 = c30_b_thp[_SFD_EML_ARRAY_BOUNDS_CHECK("thp", (int32_T)
        _SFD_INTEGER_CHECK("i", c30_i), 1, 32, 1, 0) - 1];
      if (CV_EML_COND(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c30_d2, 0.0, -1, 1U,
            c30_d2 != 0.0))) {
        guard2 = true;
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }

    if (guard3 == true) {
      c30_d3 = c30_b_th[_SFD_EML_ARRAY_BOUNDS_CHECK("th", (int32_T)
        _SFD_INTEGER_CHECK("i", c30_i), 1, 32, 1, 0) - 1];
      if (CV_EML_COND(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 2, c30_d3, 0.0, -1, 1U,
            c30_d3 != 0.0))) {
        c30_d4 = c30_b_thp[_SFD_EML_ARRAY_BOUNDS_CHECK("thp", (int32_T)
          _SFD_INTEGER_CHECK("i", c30_i), 1, 32, 1, 0) - 1];
        if (CV_EML_COND(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 3, c30_d4, 0.0, -1,
              0U, c30_d4 == 0.0))) {
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
      _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 8);
      c30_b_th_dot[_SFD_EML_ARRAY_BOUNDS_CHECK("th_dot", (int32_T)
        _SFD_INTEGER_CHECK("i", c30_i), 1, 32, 1, 0) - 1] = 0.0;
    }

    if (guard1 == true) {
      CV_EML_MCDC(0, 1, 0, false);
      CV_EML_IF(0, 1, 0, false);
    }

    c30_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, -8);
  _SFD_SYMBOL_SCOPE_POP();
  for (c30_i9 = 0; c30_i9 < 32; c30_i9++) {
    (*chartInstance->c30_th_dot)[c30_i9] = c30_b_th_dot[c30_i9];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 29U, chartInstance->c30_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_NewModuleTry_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c30_i10 = 0; c30_i10 < 32; c30_i10++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c30_th_dot)[c30_i10], 3U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c30_TISdet, 4U);
}

static void mdl_start_c30_NewModuleTry_cs(SFc30_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc30_NewModuleTry_cs
  (SFc30_NewModuleTry_csInstanceStruct *chartInstance)
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
  int32_T c30_i11;
  real_T c30_b_inData[32];
  int32_T c30_i12;
  real_T c30_u[32];
  const mxArray *c30_y = NULL;
  SFc30_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc30_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c30_mxArrayOutData = NULL;
  for (c30_i11 = 0; c30_i11 < 32; c30_i11++) {
    c30_b_inData[c30_i11] = (*(real_T (*)[32])c30_inData)[c30_i11];
  }

  for (c30_i12 = 0; c30_i12 < 32; c30_i12++) {
    c30_u[c30_i12] = c30_b_inData[c30_i12];
  }

  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", c30_u, 0, 0U, 1U, 0U, 1, 32), false);
  sf_mex_assign(&c30_mxArrayOutData, c30_y, false);
  return c30_mxArrayOutData;
}

static void c30_emlrt_marshallIn(SFc30_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c30_b_th_dot, const char_T *c30_identifier,
  real_T c30_y[32])
{
  emlrtMsgIdentifier c30_thisId;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_b_th_dot), &c30_thisId,
    c30_y);
  sf_mex_destroy(&c30_b_th_dot);
}

static void c30_b_emlrt_marshallIn(SFc30_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId,
  real_T c30_y[32])
{
  real_T c30_dv1[32];
  int32_T c30_i13;
  (void)chartInstance;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_u), c30_dv1, 1, 0, 0U, 1, 0U, 1, 32);
  for (c30_i13 = 0; c30_i13 < 32; c30_i13++) {
    c30_y[c30_i13] = c30_dv1[c30_i13];
  }

  sf_mex_destroy(&c30_u);
}

static void c30_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData)
{
  const mxArray *c30_b_th_dot;
  const char_T *c30_identifier;
  emlrtMsgIdentifier c30_thisId;
  real_T c30_y[32];
  int32_T c30_i14;
  SFc30_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc30_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c30_b_th_dot = sf_mex_dup(c30_mxArrayInData);
  c30_identifier = c30_varName;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_b_th_dot), &c30_thisId,
    c30_y);
  sf_mex_destroy(&c30_b_th_dot);
  for (c30_i14 = 0; c30_i14 < 32; c30_i14++) {
    (*(real_T (*)[32])c30_outData)[c30_i14] = c30_y[c30_i14];
  }

  sf_mex_destroy(&c30_mxArrayInData);
}

static const mxArray *c30_b_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData)
{
  const mxArray *c30_mxArrayOutData = NULL;
  real_T c30_u;
  const mxArray *c30_y = NULL;
  SFc30_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc30_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c30_mxArrayOutData = NULL;
  c30_u = *(real_T *)c30_inData;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", &c30_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c30_mxArrayOutData, c30_y, false);
  return c30_mxArrayOutData;
}

static real_T c30_c_emlrt_marshallIn(SFc30_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId)
{
  real_T c30_y;
  real_T c30_d5;
  (void)chartInstance;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_u), &c30_d5, 1, 0, 0U, 0, 0U, 0);
  c30_y = c30_d5;
  sf_mex_destroy(&c30_u);
  return c30_y;
}

static void c30_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData)
{
  const mxArray *c30_nargout;
  const char_T *c30_identifier;
  emlrtMsgIdentifier c30_thisId;
  real_T c30_y;
  SFc30_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc30_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c30_nargout = sf_mex_dup(c30_mxArrayInData);
  c30_identifier = c30_varName;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_y = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_nargout),
    &c30_thisId);
  sf_mex_destroy(&c30_nargout);
  *(real_T *)c30_outData = c30_y;
  sf_mex_destroy(&c30_mxArrayInData);
}

const mxArray *sf_c30_NewModuleTry_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c30_nameCaptureInfo = NULL;
  c30_nameCaptureInfo = NULL;
  sf_mex_assign(&c30_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c30_nameCaptureInfo;
}

static const mxArray *c30_c_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData)
{
  const mxArray *c30_mxArrayOutData = NULL;
  int32_T c30_u;
  const mxArray *c30_y = NULL;
  SFc30_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc30_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c30_mxArrayOutData = NULL;
  c30_u = *(int32_T *)c30_inData;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", &c30_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c30_mxArrayOutData, c30_y, false);
  return c30_mxArrayOutData;
}

static int32_T c30_d_emlrt_marshallIn(SFc30_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId)
{
  int32_T c30_y;
  int32_T c30_i15;
  (void)chartInstance;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_u), &c30_i15, 1, 6, 0U, 0, 0U, 0);
  c30_y = c30_i15;
  sf_mex_destroy(&c30_u);
  return c30_y;
}

static void c30_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData)
{
  const mxArray *c30_b_sfEvent;
  const char_T *c30_identifier;
  emlrtMsgIdentifier c30_thisId;
  int32_T c30_y;
  SFc30_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc30_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c30_b_sfEvent = sf_mex_dup(c30_mxArrayInData);
  c30_identifier = c30_varName;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_y = c30_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_b_sfEvent),
    &c30_thisId);
  sf_mex_destroy(&c30_b_sfEvent);
  *(int32_T *)c30_outData = c30_y;
  sf_mex_destroy(&c30_mxArrayInData);
}

static uint8_T c30_e_emlrt_marshallIn(SFc30_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c30_b_is_active_c30_NewModuleTry_cs, const
  char_T *c30_identifier)
{
  uint8_T c30_y;
  emlrtMsgIdentifier c30_thisId;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_y = c30_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c30_b_is_active_c30_NewModuleTry_cs), &c30_thisId);
  sf_mex_destroy(&c30_b_is_active_c30_NewModuleTry_cs);
  return c30_y;
}

static uint8_T c30_f_emlrt_marshallIn(SFc30_NewModuleTry_csInstanceStruct
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

static void init_dsm_address_info(SFc30_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc30_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  chartInstance->c30_th = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c30_thp = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c30_thd = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c30_th_dot = (real_T (*)[32])ssGetOutputPortSignal_wrapper
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

void sf_c30_NewModuleTry_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3922873876U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2265432277U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2461802642U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1818794977U);
}

mxArray* sf_c30_NewModuleTry_cs_get_post_codegen_info(void);
mxArray *sf_c30_NewModuleTry_cs_get_autoinheritance_info(void)
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
    mxArray* mxPostCodegenInfo = sf_c30_NewModuleTry_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c30_NewModuleTry_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c30_NewModuleTry_cs_jit_fallback_info(void)
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

mxArray *sf_c30_NewModuleTry_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c30_NewModuleTry_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c30_NewModuleTry_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"th_dot\",},{M[8],M[0],T\"is_active_c30_NewModuleTry_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c30_NewModuleTry_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc30_NewModuleTry_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc30_NewModuleTry_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _NewModuleTry_csMachineNumber_,
           30,
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
        init_script_number_translation(_NewModuleTry_csMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_NewModuleTry_csMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _NewModuleTry_csMachineNumber_,
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
            1.0,0,0,(MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)
            c30_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_b_sf_marshallOut,(MexInFcnForType)
          c30_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c30_th);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c30_thp);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c30_thd);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c30_th_dot);
        _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c30_TISdet);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _NewModuleTry_csMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "jIGMOZCgQ2HiOeP3Gv9ggE";
}

static void sf_opaque_initialize_c30_NewModuleTry_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc30_NewModuleTry_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c30_NewModuleTry_cs((SFc30_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
  initialize_c30_NewModuleTry_cs((SFc30_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c30_NewModuleTry_cs(void *chartInstanceVar)
{
  enable_c30_NewModuleTry_cs((SFc30_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c30_NewModuleTry_cs(void *chartInstanceVar)
{
  disable_c30_NewModuleTry_cs((SFc30_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c30_NewModuleTry_cs(void *chartInstanceVar)
{
  sf_gateway_c30_NewModuleTry_cs((SFc30_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c30_NewModuleTry_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c30_NewModuleTry_cs((SFc30_NewModuleTry_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c30_NewModuleTry_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c30_NewModuleTry_cs((SFc30_NewModuleTry_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c30_NewModuleTry_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc30_NewModuleTry_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_NewModuleTry_cs_optimization_info();
    }

    finalize_c30_NewModuleTry_cs((SFc30_NewModuleTry_csInstanceStruct*)
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
  initSimStructsc30_NewModuleTry_cs((SFc30_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c30_NewModuleTry_cs(SimStruct *S)
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
    initialize_params_c30_NewModuleTry_cs((SFc30_NewModuleTry_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c30_NewModuleTry_cs(SimStruct *S)
{
  /* Actual parameters from chart:
     TISdet
   */
  const char_T *rtParamNames[] = { "TISdet" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for TISdet*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_NewModuleTry_cs_optimization_info();
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
        infoStruct,30,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,30);
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

static void mdlRTW_c30_NewModuleTry_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c30_NewModuleTry_cs(SimStruct *S)
{
  SFc30_NewModuleTry_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc30_NewModuleTry_csInstanceStruct *)utMalloc(sizeof
    (SFc30_NewModuleTry_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc30_NewModuleTry_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c30_NewModuleTry_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c30_NewModuleTry_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c30_NewModuleTry_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c30_NewModuleTry_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c30_NewModuleTry_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c30_NewModuleTry_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c30_NewModuleTry_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c30_NewModuleTry_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c30_NewModuleTry_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c30_NewModuleTry_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c30_NewModuleTry_cs;
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

void c30_NewModuleTry_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c30_NewModuleTry_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c30_NewModuleTry_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c30_NewModuleTry_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c30_NewModuleTry_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
