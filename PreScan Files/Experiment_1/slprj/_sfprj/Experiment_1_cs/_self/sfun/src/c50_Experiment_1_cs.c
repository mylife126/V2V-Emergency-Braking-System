/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_1_cs_sfun.h"
#include "c50_Experiment_1_cs.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Experiment_1_cs_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c50_debug_family_names[6] = { "i", "j", "nargin", "nargout",
  "pts", "inpoints" };

/* Function Declarations */
static void initialize_c50_Experiment_1_cs(SFc50_Experiment_1_csInstanceStruct
  *chartInstance);
static void initialize_params_c50_Experiment_1_cs
  (SFc50_Experiment_1_csInstanceStruct *chartInstance);
static void enable_c50_Experiment_1_cs(SFc50_Experiment_1_csInstanceStruct
  *chartInstance);
static void disable_c50_Experiment_1_cs(SFc50_Experiment_1_csInstanceStruct
  *chartInstance);
static void c50_update_debugger_state_c50_Experiment_1_cs
  (SFc50_Experiment_1_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c50_Experiment_1_cs
  (SFc50_Experiment_1_csInstanceStruct *chartInstance);
static void set_sim_state_c50_Experiment_1_cs
  (SFc50_Experiment_1_csInstanceStruct *chartInstance, const mxArray *c50_st);
static void finalize_c50_Experiment_1_cs(SFc50_Experiment_1_csInstanceStruct
  *chartInstance);
static void sf_gateway_c50_Experiment_1_cs(SFc50_Experiment_1_csInstanceStruct
  *chartInstance);
static void mdl_start_c50_Experiment_1_cs(SFc50_Experiment_1_csInstanceStruct
  *chartInstance);
static void initSimStructsc50_Experiment_1_cs
  (SFc50_Experiment_1_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c50_machineNumber, uint32_T
  c50_chartNumber, uint32_T c50_instanceNumber);
static const mxArray *c50_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_emlrt_marshallIn(SFc50_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c50_b_inpoints, const char_T *c50_identifier,
  int32_T c50_y[4]);
static void c50_b_emlrt_marshallIn(SFc50_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  int32_T c50_y[4]);
static void c50_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_b_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static real_T c50_c_emlrt_marshallIn(SFc50_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId);
static void c50_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_c_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static int32_T c50_d_emlrt_marshallIn(SFc50_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId);
static void c50_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static uint8_T c50_e_emlrt_marshallIn(SFc50_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c50_b_is_active_c50_Experiment_1_cs, const
  char_T *c50_identifier);
static uint8_T c50_f_emlrt_marshallIn(SFc50_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId);
static void init_dsm_address_info(SFc50_Experiment_1_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc50_Experiment_1_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c50_Experiment_1_cs(SFc50_Experiment_1_csInstanceStruct
  *chartInstance)
{
  chartInstance->c50_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c50_is_active_c50_Experiment_1_cs = 0U;
}

static void initialize_params_c50_Experiment_1_cs
  (SFc50_Experiment_1_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c50_Experiment_1_cs(SFc50_Experiment_1_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c50_Experiment_1_cs(SFc50_Experiment_1_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c50_update_debugger_state_c50_Experiment_1_cs
  (SFc50_Experiment_1_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c50_Experiment_1_cs
  (SFc50_Experiment_1_csInstanceStruct *chartInstance)
{
  const mxArray *c50_st;
  const mxArray *c50_y = NULL;
  int32_T c50_i0;
  int32_T c50_u[4];
  const mxArray *c50_b_y = NULL;
  uint8_T c50_hoistedGlobal;
  uint8_T c50_b_u;
  const mxArray *c50_c_y = NULL;
  c50_st = NULL;
  c50_st = NULL;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_createcellmatrix(2, 1), false);
  for (c50_i0 = 0; c50_i0 < 4; c50_i0++) {
    c50_u[c50_i0] = (*chartInstance->c50_inpoints)[c50_i0];
  }

  c50_b_y = NULL;
  sf_mex_assign(&c50_b_y, sf_mex_create("y", c50_u, 6, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_setcell(c50_y, 0, c50_b_y);
  c50_hoistedGlobal = chartInstance->c50_is_active_c50_Experiment_1_cs;
  c50_b_u = c50_hoistedGlobal;
  c50_c_y = NULL;
  sf_mex_assign(&c50_c_y, sf_mex_create("y", &c50_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c50_y, 1, c50_c_y);
  sf_mex_assign(&c50_st, c50_y, false);
  return c50_st;
}

static void set_sim_state_c50_Experiment_1_cs
  (SFc50_Experiment_1_csInstanceStruct *chartInstance, const mxArray *c50_st)
{
  const mxArray *c50_u;
  int32_T c50_iv0[4];
  int32_T c50_i1;
  chartInstance->c50_doneDoubleBufferReInit = true;
  c50_u = sf_mex_dup(c50_st);
  c50_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c50_u, 0)),
                       "inpoints", c50_iv0);
  for (c50_i1 = 0; c50_i1 < 4; c50_i1++) {
    (*chartInstance->c50_inpoints)[c50_i1] = c50_iv0[c50_i1];
  }

  chartInstance->c50_is_active_c50_Experiment_1_cs = c50_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c50_u, 1)),
     "is_active_c50_Experiment_1_cs");
  sf_mex_destroy(&c50_u);
  c50_update_debugger_state_c50_Experiment_1_cs(chartInstance);
  sf_mex_destroy(&c50_st);
}

static void finalize_c50_Experiment_1_cs(SFc50_Experiment_1_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c50_Experiment_1_cs(SFc50_Experiment_1_csInstanceStruct
  *chartInstance)
{
  int32_T c50_i2;
  int32_T c50_b_pts[4];
  uint32_T c50_debug_family_var_map[6];
  real_T c50_i;
  real_T c50_j;
  real_T c50_nargin = 1.0;
  real_T c50_nargout = 1.0;
  int32_T c50_b_inpoints[4];
  int32_T c50_i3;
  int32_T c50_b_j;
  int64_T c50_i4;
  int32_T c50_c_j;
  int64_T c50_i5;
  int32_T c50_i6;
  int32_T c50_i7;
  int32_T c50_i8;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 24U, chartInstance->c50_sfEvent);
  chartInstance->c50_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 24U, chartInstance->c50_sfEvent);
  for (c50_i2 = 0; c50_i2 < 4; c50_i2++) {
    c50_b_pts[c50_i2] = (*chartInstance->c50_pts)[c50_i2];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c50_debug_family_names,
    c50_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c50_i, 0U, c50_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_j, 1U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargin, 2U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargout, 3U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c50_b_pts, 4U, c50_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_b_inpoints, 5U, c50_sf_marshallOut,
    c50_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 3);
  for (c50_i3 = 0; c50_i3 < 4; c50_i3++) {
    c50_b_inpoints[c50_i3] = c50_b_pts[c50_i3];
  }

  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 4);
  c50_i = 1.0;
  CV_EML_FOR(0, 1, 0, 1);
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 5);
  c50_j = 1.0;
  c50_b_j = 0;
  while (c50_b_j < 2) {
    c50_j = 1.0 + (real_T)c50_b_j;
    CV_EML_FOR(0, 1, 1, 1);
    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 6);
    c50_i4 = (int64_T)c50_b_pts[_SFD_EML_ARRAY_BOUNDS_CHECK("pts", (int32_T)
      _SFD_INTEGER_CHECK("j", c50_j), 1, 4, 2, 0) - 1] + 1LL;
    if (c50_i4 > 2147483647LL) {
      CV_SATURATION_EVAL(4, 0, 0, 0, 1);
      c50_i4 = 2147483647LL;
    } else {
      if (CV_SATURATION_EVAL(4, 0, 0, 0, c50_i4 < -2147483648LL)) {
        c50_i4 = -2147483648LL;
      }
    }

    c50_b_inpoints[_SFD_EML_ARRAY_BOUNDS_CHECK("inpoints", (int32_T)
      _SFD_INTEGER_CHECK("j", c50_j), 1, 4, 2, 0) - 1] = (int32_T)c50_i4;
    c50_b_j++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 1, 0);
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 8);
  c50_j = 3.0;
  c50_c_j = 0;
  while (c50_c_j < 2) {
    c50_j = 3.0 + (real_T)c50_c_j;
    CV_EML_FOR(0, 1, 2, 1);
    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 9);
    c50_i5 = (int64_T)c50_b_pts[_SFD_EML_ARRAY_BOUNDS_CHECK("pts", (int32_T)
      _SFD_INTEGER_CHECK("j", c50_j), 1, 4, 2, 0) - 1] - 1LL;
    if (c50_i5 > 2147483647LL) {
      CV_SATURATION_EVAL(4, 0, 1, 0, 1);
      c50_i5 = 2147483647LL;
    } else {
      if (CV_SATURATION_EVAL(4, 0, 1, 0, c50_i5 < -2147483648LL)) {
        c50_i5 = -2147483648LL;
      }
    }

    c50_b_inpoints[_SFD_EML_ARRAY_BOUNDS_CHECK("inpoints", (int32_T)
      _SFD_INTEGER_CHECK("j", c50_j), 1, 4, 2, 0) - 1] = (int32_T)c50_i5;
    c50_c_j++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 2, 0);
  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, -9);
  _SFD_SYMBOL_SCOPE_POP();
  for (c50_i6 = 0; c50_i6 < 4; c50_i6++) {
    (*chartInstance->c50_inpoints)[c50_i6] = c50_b_inpoints[c50_i6];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, chartInstance->c50_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_1_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c50_i7 = 0; c50_i7 < 4; c50_i7++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c50_inpoints)[c50_i7], 0U);
  }

  for (c50_i8 = 0; c50_i8 < 4; c50_i8++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c50_pts)[c50_i8], 1U);
  }
}

static void mdl_start_c50_Experiment_1_cs(SFc50_Experiment_1_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc50_Experiment_1_cs
  (SFc50_Experiment_1_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c50_machineNumber, uint32_T
  c50_chartNumber, uint32_T c50_instanceNumber)
{
  (void)c50_machineNumber;
  (void)c50_chartNumber;
  (void)c50_instanceNumber;
}

static const mxArray *c50_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i9;
  int32_T c50_b_inData[4];
  int32_T c50_i10;
  int32_T c50_u[4];
  const mxArray *c50_y = NULL;
  SFc50_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc50_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i9 = 0; c50_i9 < 4; c50_i9++) {
    c50_b_inData[c50_i9] = (*(int32_T (*)[4])c50_inData)[c50_i9];
  }

  for (c50_i10 = 0; c50_i10 < 4; c50_i10++) {
    c50_u[c50_i10] = c50_b_inData[c50_i10];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 6, 0U, 1U, 0U, 2, 1, 4), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_emlrt_marshallIn(SFc50_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c50_b_inpoints, const char_T *c50_identifier,
  int32_T c50_y[4])
{
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_b_inpoints), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_b_inpoints);
}

static void c50_b_emlrt_marshallIn(SFc50_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  int32_T c50_y[4])
{
  int32_T c50_iv1[4];
  int32_T c50_i11;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_iv1, 1, 6, 0U, 1, 0U, 2, 1,
                4);
  for (c50_i11 = 0; c50_i11 < 4; c50_i11++) {
    c50_y[c50_i11] = c50_iv1[c50_i11];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_b_inpoints;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  int32_T c50_y[4];
  int32_T c50_i12;
  SFc50_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc50_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c50_b_inpoints = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_b_inpoints), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_b_inpoints);
  for (c50_i12 = 0; c50_i12 < 4; c50_i12++) {
    (*(int32_T (*)[4])c50_outData)[c50_i12] = c50_y[c50_i12];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_b_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  real_T c50_u;
  const mxArray *c50_y = NULL;
  SFc50_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc50_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_u = *(real_T *)c50_inData;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static real_T c50_c_emlrt_marshallIn(SFc50_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  real_T c50_y;
  real_T c50_d0;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), &c50_d0, 1, 0, 0U, 0, 0U, 0);
  c50_y = c50_d0;
  sf_mex_destroy(&c50_u);
  return c50_y;
}

static void c50_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_nargout;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  real_T c50_y;
  SFc50_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc50_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c50_nargout = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_nargout),
    &c50_thisId);
  sf_mex_destroy(&c50_nargout);
  *(real_T *)c50_outData = c50_y;
  sf_mex_destroy(&c50_mxArrayInData);
}

const mxArray *sf_c50_Experiment_1_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c50_nameCaptureInfo = NULL;
  c50_nameCaptureInfo = NULL;
  sf_mex_assign(&c50_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c50_nameCaptureInfo;
}

static const mxArray *c50_c_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_u;
  const mxArray *c50_y = NULL;
  SFc50_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc50_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_u = *(int32_T *)c50_inData;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static int32_T c50_d_emlrt_marshallIn(SFc50_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  int32_T c50_y;
  int32_T c50_i13;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), &c50_i13, 1, 6, 0U, 0, 0U, 0);
  c50_y = c50_i13;
  sf_mex_destroy(&c50_u);
  return c50_y;
}

static void c50_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_b_sfEvent;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  int32_T c50_y;
  SFc50_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc50_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c50_b_sfEvent = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_b_sfEvent),
    &c50_thisId);
  sf_mex_destroy(&c50_b_sfEvent);
  *(int32_T *)c50_outData = c50_y;
  sf_mex_destroy(&c50_mxArrayInData);
}

static uint8_T c50_e_emlrt_marshallIn(SFc50_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c50_b_is_active_c50_Experiment_1_cs, const
  char_T *c50_identifier)
{
  uint8_T c50_y;
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c50_b_is_active_c50_Experiment_1_cs), &c50_thisId);
  sf_mex_destroy(&c50_b_is_active_c50_Experiment_1_cs);
  return c50_y;
}

static uint8_T c50_f_emlrt_marshallIn(SFc50_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  uint8_T c50_y;
  uint8_T c50_u0;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), &c50_u0, 1, 3, 0U, 0, 0U, 0);
  c50_y = c50_u0;
  sf_mex_destroy(&c50_u);
  return c50_y;
}

static void init_dsm_address_info(SFc50_Experiment_1_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc50_Experiment_1_csInstanceStruct
  *chartInstance)
{
  chartInstance->c50_inpoints = (int32_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c50_pts = (int32_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
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

void sf_c50_Experiment_1_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1398306177U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4044150009U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3710370413U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4047310008U);
}

mxArray* sf_c50_Experiment_1_cs_get_post_codegen_info(void);
mxArray *sf_c50_Experiment_1_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("5fzoXJdPrBfzTZltPb1WfG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(4);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
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
      pr[0] = (double)(1);
      pr[1] = (double)(4);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
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
    mxArray* mxPostCodegenInfo = sf_c50_Experiment_1_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c50_Experiment_1_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c50_Experiment_1_cs_jit_fallback_info(void)
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

mxArray *sf_c50_Experiment_1_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c50_Experiment_1_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c50_Experiment_1_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[14],T\"inpoints\",},{M[8],M[0],T\"is_active_c50_Experiment_1_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c50_Experiment_1_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc50_Experiment_1_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc50_Experiment_1_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_1_csMachineNumber_,
           50,
           1,
           1,
           0,
           2,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"inpoints");
          _SFD_SET_DATA_PROPS(1,1,1,0,"pts");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,2,0,3,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,191);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,110,-1,120);
        _SFD_CV_INIT_EML_SATURATION(0,1,1,168,-1,178);
        _SFD_CV_INIT_EML_FOR(0,1,0,53,73,191);
        _SFD_CV_INIT_EML_FOR(0,1,1,77,87,129);
        _SFD_CV_INIT_EML_FOR(0,1,2,135,145,187);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)
            c50_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c50_inpoints);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c50_pts);
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
  return "BUfITRAp6bdRrcSpgoUK1D";
}

static void sf_opaque_initialize_c50_Experiment_1_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc50_Experiment_1_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c50_Experiment_1_cs((SFc50_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
  initialize_c50_Experiment_1_cs((SFc50_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c50_Experiment_1_cs(void *chartInstanceVar)
{
  enable_c50_Experiment_1_cs((SFc50_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c50_Experiment_1_cs(void *chartInstanceVar)
{
  disable_c50_Experiment_1_cs((SFc50_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c50_Experiment_1_cs(void *chartInstanceVar)
{
  sf_gateway_c50_Experiment_1_cs((SFc50_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c50_Experiment_1_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c50_Experiment_1_cs((SFc50_Experiment_1_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c50_Experiment_1_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c50_Experiment_1_cs((SFc50_Experiment_1_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c50_Experiment_1_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc50_Experiment_1_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_1_cs_optimization_info();
    }

    finalize_c50_Experiment_1_cs((SFc50_Experiment_1_csInstanceStruct*)
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
  initSimStructsc50_Experiment_1_cs((SFc50_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c50_Experiment_1_cs(SimStruct *S)
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
    initialize_params_c50_Experiment_1_cs((SFc50_Experiment_1_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c50_Experiment_1_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Experiment_1_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      50);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,50,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,50,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,50);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,50,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,50,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,50);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1041408403U));
  ssSetChecksum1(S,(1996763071U));
  ssSetChecksum2(S,(3641507047U));
  ssSetChecksum3(S,(1520467277U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c50_Experiment_1_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c50_Experiment_1_cs(SimStruct *S)
{
  SFc50_Experiment_1_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc50_Experiment_1_csInstanceStruct *)utMalloc(sizeof
    (SFc50_Experiment_1_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc50_Experiment_1_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c50_Experiment_1_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c50_Experiment_1_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c50_Experiment_1_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c50_Experiment_1_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c50_Experiment_1_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c50_Experiment_1_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c50_Experiment_1_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c50_Experiment_1_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c50_Experiment_1_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c50_Experiment_1_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c50_Experiment_1_cs;
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

void c50_Experiment_1_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c50_Experiment_1_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c50_Experiment_1_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c50_Experiment_1_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c50_Experiment_1_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
