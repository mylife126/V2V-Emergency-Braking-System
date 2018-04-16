/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_3_cs_sfun.h"
#include "c56_Experiment_3_cs.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Experiment_3_cs_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c56_debug_family_names[7] = { "i", "TISdet", "nargin",
  "nargout", "indx", "theta", "THETA" };

/* Function Declarations */
static void initialize_c56_Experiment_3_cs(SFc56_Experiment_3_csInstanceStruct
  *chartInstance);
static void initialize_params_c56_Experiment_3_cs
  (SFc56_Experiment_3_csInstanceStruct *chartInstance);
static void enable_c56_Experiment_3_cs(SFc56_Experiment_3_csInstanceStruct
  *chartInstance);
static void disable_c56_Experiment_3_cs(SFc56_Experiment_3_csInstanceStruct
  *chartInstance);
static void c56_update_debugger_state_c56_Experiment_3_cs
  (SFc56_Experiment_3_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c56_Experiment_3_cs
  (SFc56_Experiment_3_csInstanceStruct *chartInstance);
static void set_sim_state_c56_Experiment_3_cs
  (SFc56_Experiment_3_csInstanceStruct *chartInstance, const mxArray *c56_st);
static void finalize_c56_Experiment_3_cs(SFc56_Experiment_3_csInstanceStruct
  *chartInstance);
static void sf_gateway_c56_Experiment_3_cs(SFc56_Experiment_3_csInstanceStruct
  *chartInstance);
static void mdl_start_c56_Experiment_3_cs(SFc56_Experiment_3_csInstanceStruct
  *chartInstance);
static void initSimStructsc56_Experiment_3_cs
  (SFc56_Experiment_3_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c56_machineNumber, uint32_T
  c56_chartNumber, uint32_T c56_instanceNumber);
static const mxArray *c56_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData);
static void c56_emlrt_marshallIn(SFc56_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c56_b_THETA, const char_T *c56_identifier,
  real_T c56_y[32]);
static void c56_b_emlrt_marshallIn(SFc56_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c56_u, const emlrtMsgIdentifier *c56_parentId,
  real_T c56_y[32]);
static void c56_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c56_mxArrayInData, const char_T *c56_varName, void *c56_outData);
static const mxArray *c56_b_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData);
static real_T c56_c_emlrt_marshallIn(SFc56_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c56_u, const emlrtMsgIdentifier *c56_parentId);
static void c56_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c56_mxArrayInData, const char_T *c56_varName, void *c56_outData);
static const mxArray *c56_c_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData);
static void c56_info_helper(const mxArray **c56_info);
static const mxArray *c56_emlrt_marshallOut(const char * c56_u);
static const mxArray *c56_b_emlrt_marshallOut(const uint32_T c56_u);
static const mxArray *c56_d_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData);
static int32_T c56_d_emlrt_marshallIn(SFc56_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c56_u, const emlrtMsgIdentifier *c56_parentId);
static void c56_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c56_mxArrayInData, const char_T *c56_varName, void *c56_outData);
static void c56_e_emlrt_marshallIn(SFc56_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c56_u, const emlrtMsgIdentifier *c56_parentId,
  real_T c56_y[2]);
static void c56_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c56_mxArrayInData, const char_T *c56_varName, void *c56_outData);
static uint8_T c56_f_emlrt_marshallIn(SFc56_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c56_b_is_active_c56_Experiment_3_cs, const
  char_T *c56_identifier);
static uint8_T c56_g_emlrt_marshallIn(SFc56_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c56_u, const emlrtMsgIdentifier *c56_parentId);
static void init_dsm_address_info(SFc56_Experiment_3_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc56_Experiment_3_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c56_Experiment_3_cs(SFc56_Experiment_3_csInstanceStruct
  *chartInstance)
{
  chartInstance->c56_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c56_is_active_c56_Experiment_3_cs = 0U;
}

static void initialize_params_c56_Experiment_3_cs
  (SFc56_Experiment_3_csInstanceStruct *chartInstance)
{
  real_T c56_dv0[2];
  int32_T c56_i0;
  sf_mex_import_named("TISdet", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c56_dv0, 0, 0, 0U, 1, 0U, 2, 1, 2);
  for (c56_i0 = 0; c56_i0 < 2; c56_i0++) {
    chartInstance->c56_TISdet[c56_i0] = c56_dv0[c56_i0];
  }
}

static void enable_c56_Experiment_3_cs(SFc56_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c56_Experiment_3_cs(SFc56_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c56_update_debugger_state_c56_Experiment_3_cs
  (SFc56_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c56_Experiment_3_cs
  (SFc56_Experiment_3_csInstanceStruct *chartInstance)
{
  const mxArray *c56_st;
  const mxArray *c56_y = NULL;
  int32_T c56_i1;
  real_T c56_u[32];
  const mxArray *c56_b_y = NULL;
  uint8_T c56_hoistedGlobal;
  uint8_T c56_b_u;
  const mxArray *c56_c_y = NULL;
  c56_st = NULL;
  c56_st = NULL;
  c56_y = NULL;
  sf_mex_assign(&c56_y, sf_mex_createcellmatrix(2, 1), false);
  for (c56_i1 = 0; c56_i1 < 32; c56_i1++) {
    c56_u[c56_i1] = (*chartInstance->c56_THETA)[c56_i1];
  }

  c56_b_y = NULL;
  sf_mex_assign(&c56_b_y, sf_mex_create("y", c56_u, 0, 0U, 1U, 0U, 1, 32), false);
  sf_mex_setcell(c56_y, 0, c56_b_y);
  c56_hoistedGlobal = chartInstance->c56_is_active_c56_Experiment_3_cs;
  c56_b_u = c56_hoistedGlobal;
  c56_c_y = NULL;
  sf_mex_assign(&c56_c_y, sf_mex_create("y", &c56_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c56_y, 1, c56_c_y);
  sf_mex_assign(&c56_st, c56_y, false);
  return c56_st;
}

static void set_sim_state_c56_Experiment_3_cs
  (SFc56_Experiment_3_csInstanceStruct *chartInstance, const mxArray *c56_st)
{
  const mxArray *c56_u;
  real_T c56_dv1[32];
  int32_T c56_i2;
  chartInstance->c56_doneDoubleBufferReInit = true;
  c56_u = sf_mex_dup(c56_st);
  c56_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c56_u, 0)),
                       "THETA", c56_dv1);
  for (c56_i2 = 0; c56_i2 < 32; c56_i2++) {
    (*chartInstance->c56_THETA)[c56_i2] = c56_dv1[c56_i2];
  }

  chartInstance->c56_is_active_c56_Experiment_3_cs = c56_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c56_u, 1)),
     "is_active_c56_Experiment_3_cs");
  sf_mex_destroy(&c56_u);
  c56_update_debugger_state_c56_Experiment_3_cs(chartInstance);
  sf_mex_destroy(&c56_st);
}

static void finalize_c56_Experiment_3_cs(SFc56_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c56_Experiment_3_cs(SFc56_Experiment_3_csInstanceStruct
  *chartInstance)
{
  int32_T c56_i3;
  int32_T c56_i4;
  real_T c56_b_indx[32];
  int32_T c56_i5;
  real_T c56_b_theta[32];
  uint32_T c56_debug_family_var_map[7];
  real_T c56_i;
  real_T c56_c_TISdet[2];
  real_T c56_nargin = 3.0;
  real_T c56_nargout = 1.0;
  real_T c56_b_THETA[32];
  int32_T c56_i6;
  int32_T c56_i7;
  int32_T c56_b_i;
  real_T c56_d0;
  int32_T c56_i8;
  int32_T c56_i9;
  int32_T c56_i10;
  int32_T c56_i11;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 55U, chartInstance->c56_sfEvent);
  for (c56_i3 = 0; c56_i3 < 32; c56_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c56_indx)[c56_i3], 0U);
  }

  chartInstance->c56_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 55U, chartInstance->c56_sfEvent);
  for (c56_i4 = 0; c56_i4 < 32; c56_i4++) {
    c56_b_indx[c56_i4] = (*chartInstance->c56_indx)[c56_i4];
  }

  for (c56_i5 = 0; c56_i5 < 32; c56_i5++) {
    c56_b_theta[c56_i5] = (*chartInstance->c56_theta)[c56_i5];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c56_debug_family_names,
    c56_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c56_i, 0U, c56_b_sf_marshallOut,
    c56_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c56_c_TISdet, 1U, c56_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c56_nargin, 2U, c56_b_sf_marshallOut,
    c56_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c56_nargout, 3U, c56_b_sf_marshallOut,
    c56_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c56_b_indx, 4U, c56_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c56_b_theta, 5U, c56_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c56_b_THETA, 6U, c56_sf_marshallOut,
    c56_sf_marshallIn);
  for (c56_i6 = 0; c56_i6 < 2; c56_i6++) {
    c56_c_TISdet[c56_i6] = 32.0;
  }

  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 4);
  for (c56_i7 = 0; c56_i7 < 32; c56_i7++) {
    c56_b_THETA[c56_i7] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 5);
  c56_i = 1.0;
  c56_b_i = 0;
  while (c56_b_i < 32) {
    c56_i = 1.0 + (real_T)c56_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 6);
    c56_d0 = c56_b_indx[_SFD_EML_ARRAY_BOUNDS_CHECK("indx", (int32_T)
      _SFD_INTEGER_CHECK("i", c56_i), 1, 32, 1, 0) - 1];
    if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c56_d0, 0.0, -1, 1U,
          c56_d0 != 0.0))) {
      _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 7);
      c56_b_THETA[_SFD_EML_ARRAY_BOUNDS_CHECK("THETA", (int32_T)
        _SFD_INTEGER_CHECK("i", c56_i), 1, 32, 1, 0) - 1] =
        c56_b_theta[_SFD_EML_ARRAY_BOUNDS_CHECK("theta", (int32_T)
        _SFD_INTEGER_CHECK("indx(i)", c56_b_indx[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "indx", (int32_T)_SFD_INTEGER_CHECK("i", c56_i), 1, 32, 1, 0) - 1]), 1,
        32, 1, 0) - 1];
    } else {
      _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 9);
      c56_b_THETA[_SFD_EML_ARRAY_BOUNDS_CHECK("THETA", (int32_T)
        _SFD_INTEGER_CHECK("i", c56_i), 1, 32, 1, 0) - 1] = 0.0;
    }

    c56_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, -9);
  _SFD_SYMBOL_SCOPE_POP();
  for (c56_i8 = 0; c56_i8 < 32; c56_i8++) {
    (*chartInstance->c56_THETA)[c56_i8] = c56_b_THETA[c56_i8];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 55U, chartInstance->c56_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_3_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c56_i9 = 0; c56_i9 < 32; c56_i9++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c56_THETA)[c56_i9], 1U);
  }

  for (c56_i10 = 0; c56_i10 < 32; c56_i10++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c56_theta)[c56_i10], 2U);
  }

  for (c56_i11 = 0; c56_i11 < 2; c56_i11++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c56_TISdet[c56_i11], 3U);
  }
}

static void mdl_start_c56_Experiment_3_cs(SFc56_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc56_Experiment_3_cs
  (SFc56_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c56_machineNumber, uint32_T
  c56_chartNumber, uint32_T c56_instanceNumber)
{
  (void)c56_machineNumber;
  (void)c56_chartNumber;
  (void)c56_instanceNumber;
}

static const mxArray *c56_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData)
{
  const mxArray *c56_mxArrayOutData = NULL;
  int32_T c56_i12;
  real_T c56_b_inData[32];
  int32_T c56_i13;
  real_T c56_u[32];
  const mxArray *c56_y = NULL;
  SFc56_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc56_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c56_mxArrayOutData = NULL;
  for (c56_i12 = 0; c56_i12 < 32; c56_i12++) {
    c56_b_inData[c56_i12] = (*(real_T (*)[32])c56_inData)[c56_i12];
  }

  for (c56_i13 = 0; c56_i13 < 32; c56_i13++) {
    c56_u[c56_i13] = c56_b_inData[c56_i13];
  }

  c56_y = NULL;
  sf_mex_assign(&c56_y, sf_mex_create("y", c56_u, 0, 0U, 1U, 0U, 1, 32), false);
  sf_mex_assign(&c56_mxArrayOutData, c56_y, false);
  return c56_mxArrayOutData;
}

static void c56_emlrt_marshallIn(SFc56_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c56_b_THETA, const char_T *c56_identifier,
  real_T c56_y[32])
{
  emlrtMsgIdentifier c56_thisId;
  c56_thisId.fIdentifier = c56_identifier;
  c56_thisId.fParent = NULL;
  c56_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c56_b_THETA), &c56_thisId,
    c56_y);
  sf_mex_destroy(&c56_b_THETA);
}

static void c56_b_emlrt_marshallIn(SFc56_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c56_u, const emlrtMsgIdentifier *c56_parentId,
  real_T c56_y[32])
{
  real_T c56_dv2[32];
  int32_T c56_i14;
  (void)chartInstance;
  sf_mex_import(c56_parentId, sf_mex_dup(c56_u), c56_dv2, 1, 0, 0U, 1, 0U, 1, 32);
  for (c56_i14 = 0; c56_i14 < 32; c56_i14++) {
    c56_y[c56_i14] = c56_dv2[c56_i14];
  }

  sf_mex_destroy(&c56_u);
}

static void c56_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c56_mxArrayInData, const char_T *c56_varName, void *c56_outData)
{
  const mxArray *c56_b_THETA;
  const char_T *c56_identifier;
  emlrtMsgIdentifier c56_thisId;
  real_T c56_y[32];
  int32_T c56_i15;
  SFc56_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc56_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c56_b_THETA = sf_mex_dup(c56_mxArrayInData);
  c56_identifier = c56_varName;
  c56_thisId.fIdentifier = c56_identifier;
  c56_thisId.fParent = NULL;
  c56_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c56_b_THETA), &c56_thisId,
    c56_y);
  sf_mex_destroy(&c56_b_THETA);
  for (c56_i15 = 0; c56_i15 < 32; c56_i15++) {
    (*(real_T (*)[32])c56_outData)[c56_i15] = c56_y[c56_i15];
  }

  sf_mex_destroy(&c56_mxArrayInData);
}

static const mxArray *c56_b_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData)
{
  const mxArray *c56_mxArrayOutData = NULL;
  real_T c56_u;
  const mxArray *c56_y = NULL;
  SFc56_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc56_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c56_mxArrayOutData = NULL;
  c56_u = *(real_T *)c56_inData;
  c56_y = NULL;
  sf_mex_assign(&c56_y, sf_mex_create("y", &c56_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c56_mxArrayOutData, c56_y, false);
  return c56_mxArrayOutData;
}

static real_T c56_c_emlrt_marshallIn(SFc56_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c56_u, const emlrtMsgIdentifier *c56_parentId)
{
  real_T c56_y;
  real_T c56_d1;
  (void)chartInstance;
  sf_mex_import(c56_parentId, sf_mex_dup(c56_u), &c56_d1, 1, 0, 0U, 0, 0U, 0);
  c56_y = c56_d1;
  sf_mex_destroy(&c56_u);
  return c56_y;
}

static void c56_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c56_mxArrayInData, const char_T *c56_varName, void *c56_outData)
{
  const mxArray *c56_nargout;
  const char_T *c56_identifier;
  emlrtMsgIdentifier c56_thisId;
  real_T c56_y;
  SFc56_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc56_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c56_nargout = sf_mex_dup(c56_mxArrayInData);
  c56_identifier = c56_varName;
  c56_thisId.fIdentifier = c56_identifier;
  c56_thisId.fParent = NULL;
  c56_y = c56_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c56_nargout),
    &c56_thisId);
  sf_mex_destroy(&c56_nargout);
  *(real_T *)c56_outData = c56_y;
  sf_mex_destroy(&c56_mxArrayInData);
}

static const mxArray *c56_c_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData)
{
  const mxArray *c56_mxArrayOutData = NULL;
  int32_T c56_i16;
  real_T c56_b_inData[2];
  int32_T c56_i17;
  real_T c56_u[2];
  const mxArray *c56_y = NULL;
  SFc56_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc56_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c56_mxArrayOutData = NULL;
  for (c56_i16 = 0; c56_i16 < 2; c56_i16++) {
    c56_b_inData[c56_i16] = (*(real_T (*)[2])c56_inData)[c56_i16];
  }

  for (c56_i17 = 0; c56_i17 < 2; c56_i17++) {
    c56_u[c56_i17] = c56_b_inData[c56_i17];
  }

  c56_y = NULL;
  sf_mex_assign(&c56_y, sf_mex_create("y", c56_u, 0, 0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_assign(&c56_mxArrayOutData, c56_y, false);
  return c56_mxArrayOutData;
}

const mxArray *sf_c56_Experiment_3_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c56_nameCaptureInfo = NULL;
  c56_nameCaptureInfo = NULL;
  sf_mex_assign(&c56_nameCaptureInfo, sf_mex_createstruct("structure", 2, 1, 1),
                false);
  c56_info_helper(&c56_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c56_nameCaptureInfo);
  return c56_nameCaptureInfo;
}

static void c56_info_helper(const mxArray **c56_info)
{
  const mxArray *c56_rhs0 = NULL;
  const mxArray *c56_lhs0 = NULL;
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("length"), "name", "name", 0);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1303167806U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c56_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs0), "lhs", "lhs",
                  0);
  sf_mex_destroy(&c56_rhs0);
  sf_mex_destroy(&c56_lhs0);
}

static const mxArray *c56_emlrt_marshallOut(const char * c56_u)
{
  const mxArray *c56_y = NULL;
  c56_y = NULL;
  sf_mex_assign(&c56_y, sf_mex_create("y", c56_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c56_u)), false);
  return c56_y;
}

static const mxArray *c56_b_emlrt_marshallOut(const uint32_T c56_u)
{
  const mxArray *c56_y = NULL;
  c56_y = NULL;
  sf_mex_assign(&c56_y, sf_mex_create("y", &c56_u, 7, 0U, 0U, 0U, 0), false);
  return c56_y;
}

static const mxArray *c56_d_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData)
{
  const mxArray *c56_mxArrayOutData = NULL;
  int32_T c56_u;
  const mxArray *c56_y = NULL;
  SFc56_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc56_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c56_mxArrayOutData = NULL;
  c56_u = *(int32_T *)c56_inData;
  c56_y = NULL;
  sf_mex_assign(&c56_y, sf_mex_create("y", &c56_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c56_mxArrayOutData, c56_y, false);
  return c56_mxArrayOutData;
}

static int32_T c56_d_emlrt_marshallIn(SFc56_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c56_u, const emlrtMsgIdentifier *c56_parentId)
{
  int32_T c56_y;
  int32_T c56_i18;
  (void)chartInstance;
  sf_mex_import(c56_parentId, sf_mex_dup(c56_u), &c56_i18, 1, 6, 0U, 0, 0U, 0);
  c56_y = c56_i18;
  sf_mex_destroy(&c56_u);
  return c56_y;
}

static void c56_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c56_mxArrayInData, const char_T *c56_varName, void *c56_outData)
{
  const mxArray *c56_b_sfEvent;
  const char_T *c56_identifier;
  emlrtMsgIdentifier c56_thisId;
  int32_T c56_y;
  SFc56_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc56_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c56_b_sfEvent = sf_mex_dup(c56_mxArrayInData);
  c56_identifier = c56_varName;
  c56_thisId.fIdentifier = c56_identifier;
  c56_thisId.fParent = NULL;
  c56_y = c56_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c56_b_sfEvent),
    &c56_thisId);
  sf_mex_destroy(&c56_b_sfEvent);
  *(int32_T *)c56_outData = c56_y;
  sf_mex_destroy(&c56_mxArrayInData);
}

static void c56_e_emlrt_marshallIn(SFc56_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c56_u, const emlrtMsgIdentifier *c56_parentId,
  real_T c56_y[2])
{
  real_T c56_dv3[2];
  int32_T c56_i19;
  (void)chartInstance;
  sf_mex_import(c56_parentId, sf_mex_dup(c56_u), c56_dv3, 1, 0, 0U, 1, 0U, 2, 1,
                2);
  for (c56_i19 = 0; c56_i19 < 2; c56_i19++) {
    c56_y[c56_i19] = c56_dv3[c56_i19];
  }

  sf_mex_destroy(&c56_u);
}

static void c56_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c56_mxArrayInData, const char_T *c56_varName, void *c56_outData)
{
  const mxArray *c56_c_TISdet;
  const char_T *c56_identifier;
  emlrtMsgIdentifier c56_thisId;
  real_T c56_y[2];
  int32_T c56_i20;
  SFc56_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc56_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c56_c_TISdet = sf_mex_dup(c56_mxArrayInData);
  c56_identifier = c56_varName;
  c56_thisId.fIdentifier = c56_identifier;
  c56_thisId.fParent = NULL;
  c56_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c56_c_TISdet), &c56_thisId,
    c56_y);
  sf_mex_destroy(&c56_c_TISdet);
  for (c56_i20 = 0; c56_i20 < 2; c56_i20++) {
    (*(real_T (*)[2])c56_outData)[c56_i20] = c56_y[c56_i20];
  }

  sf_mex_destroy(&c56_mxArrayInData);
}

static uint8_T c56_f_emlrt_marshallIn(SFc56_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c56_b_is_active_c56_Experiment_3_cs, const
  char_T *c56_identifier)
{
  uint8_T c56_y;
  emlrtMsgIdentifier c56_thisId;
  c56_thisId.fIdentifier = c56_identifier;
  c56_thisId.fParent = NULL;
  c56_y = c56_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c56_b_is_active_c56_Experiment_3_cs), &c56_thisId);
  sf_mex_destroy(&c56_b_is_active_c56_Experiment_3_cs);
  return c56_y;
}

static uint8_T c56_g_emlrt_marshallIn(SFc56_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c56_u, const emlrtMsgIdentifier *c56_parentId)
{
  uint8_T c56_y;
  uint8_T c56_u0;
  (void)chartInstance;
  sf_mex_import(c56_parentId, sf_mex_dup(c56_u), &c56_u0, 1, 3, 0U, 0, 0U, 0);
  c56_y = c56_u0;
  sf_mex_destroy(&c56_u);
  return c56_y;
}

static void init_dsm_address_info(SFc56_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc56_Experiment_3_csInstanceStruct
  *chartInstance)
{
  chartInstance->c56_indx = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c56_THETA = (real_T (*)[32])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c56_theta = (real_T (*)[32])ssGetInputPortSignal_wrapper
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

void sf_c56_Experiment_3_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(200481619U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3648806228U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1319829336U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(420274104U);
}

mxArray* sf_c56_Experiment_3_cs_get_post_codegen_info(void);
mxArray *sf_c56_Experiment_3_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("YQ7AiKZg7SqDNCWNqUnvSC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
      pr[1] = (double)(2);
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
    mxArray* mxPostCodegenInfo = sf_c56_Experiment_3_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c56_Experiment_3_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c56_Experiment_3_cs_jit_fallback_info(void)
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

mxArray *sf_c56_Experiment_3_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c56_Experiment_3_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c56_Experiment_3_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"THETA\",},{M[8],M[0],T\"is_active_c56_Experiment_3_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c56_Experiment_3_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc56_Experiment_3_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc56_Experiment_3_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_3_csMachineNumber_,
           56,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"indx");
          _SFD_SET_DATA_PROPS(1,2,0,1,"THETA");
          _SFD_SET_DATA_PROPS(2,1,1,0,"theta");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,203);
        _SFD_CV_INIT_EML_IF(0,1,0,110,125,165,199);
        _SFD_CV_INIT_EML_FOR(0,1,0,81,106,203);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,113,125,-1,1);

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c56_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c56_sf_marshallOut,(MexInFcnForType)
            c56_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c56_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c56_c_sf_marshallOut,(MexInFcnForType)
            c56_d_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c56_indx);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c56_THETA);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c56_theta);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c56_TISdet);
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
  return "xZ6AitUX1s6eGAKqHILE2D";
}

static void sf_opaque_initialize_c56_Experiment_3_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc56_Experiment_3_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c56_Experiment_3_cs((SFc56_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
  initialize_c56_Experiment_3_cs((SFc56_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c56_Experiment_3_cs(void *chartInstanceVar)
{
  enable_c56_Experiment_3_cs((SFc56_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c56_Experiment_3_cs(void *chartInstanceVar)
{
  disable_c56_Experiment_3_cs((SFc56_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c56_Experiment_3_cs(void *chartInstanceVar)
{
  sf_gateway_c56_Experiment_3_cs((SFc56_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c56_Experiment_3_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c56_Experiment_3_cs((SFc56_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c56_Experiment_3_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c56_Experiment_3_cs((SFc56_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c56_Experiment_3_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc56_Experiment_3_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_3_cs_optimization_info();
    }

    finalize_c56_Experiment_3_cs((SFc56_Experiment_3_csInstanceStruct*)
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
  initSimStructsc56_Experiment_3_cs((SFc56_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c56_Experiment_3_cs(SimStruct *S)
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
    initialize_params_c56_Experiment_3_cs((SFc56_Experiment_3_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c56_Experiment_3_cs(SimStruct *S)
{
  /* Actual parameters from chart:
     TISdet
   */
  const char_T *rtParamNames[] = { "TISdet" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for TISdet*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Experiment_3_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      56);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,56,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,56,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,56);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,56,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,56,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,56);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3197745010U));
  ssSetChecksum1(S,(470529177U));
  ssSetChecksum2(S,(3797850865U));
  ssSetChecksum3(S,(3602684004U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c56_Experiment_3_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c56_Experiment_3_cs(SimStruct *S)
{
  SFc56_Experiment_3_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc56_Experiment_3_csInstanceStruct *)utMalloc(sizeof
    (SFc56_Experiment_3_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc56_Experiment_3_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c56_Experiment_3_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c56_Experiment_3_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c56_Experiment_3_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c56_Experiment_3_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c56_Experiment_3_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c56_Experiment_3_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c56_Experiment_3_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c56_Experiment_3_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c56_Experiment_3_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c56_Experiment_3_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c56_Experiment_3_cs;
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

void c56_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c56_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c56_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c56_Experiment_3_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c56_Experiment_3_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
