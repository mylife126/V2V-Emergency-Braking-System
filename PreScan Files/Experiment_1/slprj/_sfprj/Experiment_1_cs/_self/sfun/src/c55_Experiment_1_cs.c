/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_1_cs_sfun.h"
#include "c55_Experiment_1_cs.h"
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
static const char * c55_debug_family_names[5] = { "i", "nargin", "nargout",
  "pts", "inpoints" };

/* Function Declarations */
static void initialize_c55_Experiment_1_cs(SFc55_Experiment_1_csInstanceStruct
  *chartInstance);
static void initialize_params_c55_Experiment_1_cs
  (SFc55_Experiment_1_csInstanceStruct *chartInstance);
static void enable_c55_Experiment_1_cs(SFc55_Experiment_1_csInstanceStruct
  *chartInstance);
static void disable_c55_Experiment_1_cs(SFc55_Experiment_1_csInstanceStruct
  *chartInstance);
static void c55_update_debugger_state_c55_Experiment_1_cs
  (SFc55_Experiment_1_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c55_Experiment_1_cs
  (SFc55_Experiment_1_csInstanceStruct *chartInstance);
static void set_sim_state_c55_Experiment_1_cs
  (SFc55_Experiment_1_csInstanceStruct *chartInstance, const mxArray *c55_st);
static void finalize_c55_Experiment_1_cs(SFc55_Experiment_1_csInstanceStruct
  *chartInstance);
static void sf_gateway_c55_Experiment_1_cs(SFc55_Experiment_1_csInstanceStruct
  *chartInstance);
static void mdl_start_c55_Experiment_1_cs(SFc55_Experiment_1_csInstanceStruct
  *chartInstance);
static void initSimStructsc55_Experiment_1_cs
  (SFc55_Experiment_1_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c55_machineNumber, uint32_T
  c55_chartNumber, uint32_T c55_instanceNumber);
static const mxArray *c55_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData);
static void c55_emlrt_marshallIn(SFc55_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c55_b_inpoints, const char_T *c55_identifier,
  int32_T c55_y[64]);
static void c55_b_emlrt_marshallIn(SFc55_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId,
  int32_T c55_y[64]);
static void c55_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c55_mxArrayInData, const char_T *c55_varName, void *c55_outData);
static const mxArray *c55_b_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData);
static real_T c55_c_emlrt_marshallIn(SFc55_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId);
static void c55_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c55_mxArrayInData, const char_T *c55_varName, void *c55_outData);
static void c55_info_helper(const mxArray **c55_info);
static const mxArray *c55_emlrt_marshallOut(const char * c55_u);
static const mxArray *c55_b_emlrt_marshallOut(const uint32_T c55_u);
static const mxArray *c55_c_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData);
static int32_T c55_d_emlrt_marshallIn(SFc55_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId);
static void c55_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c55_mxArrayInData, const char_T *c55_varName, void *c55_outData);
static uint8_T c55_e_emlrt_marshallIn(SFc55_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c55_b_is_active_c55_Experiment_1_cs, const
  char_T *c55_identifier);
static uint8_T c55_f_emlrt_marshallIn(SFc55_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId);
static void init_dsm_address_info(SFc55_Experiment_1_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc55_Experiment_1_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c55_Experiment_1_cs(SFc55_Experiment_1_csInstanceStruct
  *chartInstance)
{
  chartInstance->c55_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c55_is_active_c55_Experiment_1_cs = 0U;
}

static void initialize_params_c55_Experiment_1_cs
  (SFc55_Experiment_1_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c55_Experiment_1_cs(SFc55_Experiment_1_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c55_Experiment_1_cs(SFc55_Experiment_1_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c55_update_debugger_state_c55_Experiment_1_cs
  (SFc55_Experiment_1_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c55_Experiment_1_cs
  (SFc55_Experiment_1_csInstanceStruct *chartInstance)
{
  const mxArray *c55_st;
  const mxArray *c55_y = NULL;
  int32_T c55_i0;
  int32_T c55_u[64];
  const mxArray *c55_b_y = NULL;
  uint8_T c55_hoistedGlobal;
  uint8_T c55_b_u;
  const mxArray *c55_c_y = NULL;
  c55_st = NULL;
  c55_st = NULL;
  c55_y = NULL;
  sf_mex_assign(&c55_y, sf_mex_createcellmatrix(2, 1), false);
  for (c55_i0 = 0; c55_i0 < 64; c55_i0++) {
    c55_u[c55_i0] = (*chartInstance->c55_inpoints)[c55_i0];
  }

  c55_b_y = NULL;
  sf_mex_assign(&c55_b_y, sf_mex_create("y", c55_u, 6, 0U, 1U, 0U, 2, 2, 32),
                false);
  sf_mex_setcell(c55_y, 0, c55_b_y);
  c55_hoistedGlobal = chartInstance->c55_is_active_c55_Experiment_1_cs;
  c55_b_u = c55_hoistedGlobal;
  c55_c_y = NULL;
  sf_mex_assign(&c55_c_y, sf_mex_create("y", &c55_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c55_y, 1, c55_c_y);
  sf_mex_assign(&c55_st, c55_y, false);
  return c55_st;
}

static void set_sim_state_c55_Experiment_1_cs
  (SFc55_Experiment_1_csInstanceStruct *chartInstance, const mxArray *c55_st)
{
  const mxArray *c55_u;
  int32_T c55_iv0[64];
  int32_T c55_i1;
  chartInstance->c55_doneDoubleBufferReInit = true;
  c55_u = sf_mex_dup(c55_st);
  c55_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c55_u, 0)),
                       "inpoints", c55_iv0);
  for (c55_i1 = 0; c55_i1 < 64; c55_i1++) {
    (*chartInstance->c55_inpoints)[c55_i1] = c55_iv0[c55_i1];
  }

  chartInstance->c55_is_active_c55_Experiment_1_cs = c55_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c55_u, 1)),
     "is_active_c55_Experiment_1_cs");
  sf_mex_destroy(&c55_u);
  c55_update_debugger_state_c55_Experiment_1_cs(chartInstance);
  sf_mex_destroy(&c55_st);
}

static void finalize_c55_Experiment_1_cs(SFc55_Experiment_1_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c55_Experiment_1_cs(SFc55_Experiment_1_csInstanceStruct
  *chartInstance)
{
  int32_T c55_i2;
  int32_T c55_b_pts[64];
  uint32_T c55_debug_family_var_map[5];
  real_T c55_i;
  real_T c55_nargin = 1.0;
  real_T c55_nargout = 1.0;
  int32_T c55_b_inpoints[64];
  int32_T c55_i3;
  int32_T c55_i4;
  int32_T c55_i5;
  int32_T c55_i6;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 29U, chartInstance->c55_sfEvent);
  chartInstance->c55_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 29U, chartInstance->c55_sfEvent);
  for (c55_i2 = 0; c55_i2 < 64; c55_i2++) {
    c55_b_pts[c55_i2] = (*chartInstance->c55_pts)[c55_i2];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c55_debug_family_names,
    c55_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c55_i, 0U, c55_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c55_nargin, 1U, c55_b_sf_marshallOut,
    c55_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c55_nargout, 2U, c55_b_sf_marshallOut,
    c55_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c55_b_pts, 3U, c55_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c55_b_inpoints, 4U, c55_sf_marshallOut,
    c55_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, 3);
  for (c55_i3 = 0; c55_i3 < 64; c55_i3++) {
    c55_b_inpoints[c55_i3] = c55_b_pts[c55_i3];
  }

  _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, 4);
  c55_i = 0.0;
  CV_EML_FOR(0, 1, 0, 1);
  _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, 5);
  c55_b_inpoints[0] = c55_b_pts[1];
  _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, 6);
  c55_b_inpoints[1] = c55_b_pts[0];
  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, -6);
  _SFD_SYMBOL_SCOPE_POP();
  for (c55_i4 = 0; c55_i4 < 64; c55_i4++) {
    (*chartInstance->c55_inpoints)[c55_i4] = c55_b_inpoints[c55_i4];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 29U, chartInstance->c55_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_1_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c55_i5 = 0; c55_i5 < 64; c55_i5++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c55_inpoints)[c55_i5], 0U);
  }

  for (c55_i6 = 0; c55_i6 < 64; c55_i6++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c55_pts)[c55_i6], 1U);
  }
}

static void mdl_start_c55_Experiment_1_cs(SFc55_Experiment_1_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc55_Experiment_1_cs
  (SFc55_Experiment_1_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c55_machineNumber, uint32_T
  c55_chartNumber, uint32_T c55_instanceNumber)
{
  (void)c55_machineNumber;
  (void)c55_chartNumber;
  (void)c55_instanceNumber;
}

static const mxArray *c55_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData)
{
  const mxArray *c55_mxArrayOutData = NULL;
  int32_T c55_i7;
  int32_T c55_i8;
  int32_T c55_i9;
  int32_T c55_b_inData[64];
  int32_T c55_i10;
  int32_T c55_i11;
  int32_T c55_i12;
  int32_T c55_u[64];
  const mxArray *c55_y = NULL;
  SFc55_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc55_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c55_mxArrayOutData = NULL;
  c55_i7 = 0;
  for (c55_i8 = 0; c55_i8 < 32; c55_i8++) {
    for (c55_i9 = 0; c55_i9 < 2; c55_i9++) {
      c55_b_inData[c55_i9 + c55_i7] = (*(int32_T (*)[64])c55_inData)[c55_i9 +
        c55_i7];
    }

    c55_i7 += 2;
  }

  c55_i10 = 0;
  for (c55_i11 = 0; c55_i11 < 32; c55_i11++) {
    for (c55_i12 = 0; c55_i12 < 2; c55_i12++) {
      c55_u[c55_i12 + c55_i10] = c55_b_inData[c55_i12 + c55_i10];
    }

    c55_i10 += 2;
  }

  c55_y = NULL;
  sf_mex_assign(&c55_y, sf_mex_create("y", c55_u, 6, 0U, 1U, 0U, 2, 2, 32),
                false);
  sf_mex_assign(&c55_mxArrayOutData, c55_y, false);
  return c55_mxArrayOutData;
}

static void c55_emlrt_marshallIn(SFc55_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c55_b_inpoints, const char_T *c55_identifier,
  int32_T c55_y[64])
{
  emlrtMsgIdentifier c55_thisId;
  c55_thisId.fIdentifier = c55_identifier;
  c55_thisId.fParent = NULL;
  c55_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c55_b_inpoints), &c55_thisId,
    c55_y);
  sf_mex_destroy(&c55_b_inpoints);
}

static void c55_b_emlrt_marshallIn(SFc55_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId,
  int32_T c55_y[64])
{
  int32_T c55_iv1[64];
  int32_T c55_i13;
  (void)chartInstance;
  sf_mex_import(c55_parentId, sf_mex_dup(c55_u), c55_iv1, 1, 6, 0U, 1, 0U, 2, 2,
                32);
  for (c55_i13 = 0; c55_i13 < 64; c55_i13++) {
    c55_y[c55_i13] = c55_iv1[c55_i13];
  }

  sf_mex_destroy(&c55_u);
}

static void c55_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c55_mxArrayInData, const char_T *c55_varName, void *c55_outData)
{
  const mxArray *c55_b_inpoints;
  const char_T *c55_identifier;
  emlrtMsgIdentifier c55_thisId;
  int32_T c55_y[64];
  int32_T c55_i14;
  int32_T c55_i15;
  int32_T c55_i16;
  SFc55_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc55_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c55_b_inpoints = sf_mex_dup(c55_mxArrayInData);
  c55_identifier = c55_varName;
  c55_thisId.fIdentifier = c55_identifier;
  c55_thisId.fParent = NULL;
  c55_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c55_b_inpoints), &c55_thisId,
    c55_y);
  sf_mex_destroy(&c55_b_inpoints);
  c55_i14 = 0;
  for (c55_i15 = 0; c55_i15 < 32; c55_i15++) {
    for (c55_i16 = 0; c55_i16 < 2; c55_i16++) {
      (*(int32_T (*)[64])c55_outData)[c55_i16 + c55_i14] = c55_y[c55_i16 +
        c55_i14];
    }

    c55_i14 += 2;
  }

  sf_mex_destroy(&c55_mxArrayInData);
}

static const mxArray *c55_b_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData)
{
  const mxArray *c55_mxArrayOutData = NULL;
  real_T c55_u;
  const mxArray *c55_y = NULL;
  SFc55_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc55_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c55_mxArrayOutData = NULL;
  c55_u = *(real_T *)c55_inData;
  c55_y = NULL;
  sf_mex_assign(&c55_y, sf_mex_create("y", &c55_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c55_mxArrayOutData, c55_y, false);
  return c55_mxArrayOutData;
}

static real_T c55_c_emlrt_marshallIn(SFc55_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId)
{
  real_T c55_y;
  real_T c55_d0;
  (void)chartInstance;
  sf_mex_import(c55_parentId, sf_mex_dup(c55_u), &c55_d0, 1, 0, 0U, 0, 0U, 0);
  c55_y = c55_d0;
  sf_mex_destroy(&c55_u);
  return c55_y;
}

static void c55_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c55_mxArrayInData, const char_T *c55_varName, void *c55_outData)
{
  const mxArray *c55_nargout;
  const char_T *c55_identifier;
  emlrtMsgIdentifier c55_thisId;
  real_T c55_y;
  SFc55_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc55_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c55_nargout = sf_mex_dup(c55_mxArrayInData);
  c55_identifier = c55_varName;
  c55_thisId.fIdentifier = c55_identifier;
  c55_thisId.fParent = NULL;
  c55_y = c55_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c55_nargout),
    &c55_thisId);
  sf_mex_destroy(&c55_nargout);
  *(real_T *)c55_outData = c55_y;
  sf_mex_destroy(&c55_mxArrayInData);
}

const mxArray *sf_c55_Experiment_1_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c55_nameCaptureInfo = NULL;
  c55_nameCaptureInfo = NULL;
  sf_mex_assign(&c55_nameCaptureInfo, sf_mex_createstruct("structure", 2, 7, 1),
                false);
  c55_info_helper(&c55_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c55_nameCaptureInfo);
  return c55_nameCaptureInfo;
}

static void c55_info_helper(const mxArray **c55_info)
{
  const mxArray *c55_rhs0 = NULL;
  const mxArray *c55_lhs0 = NULL;
  const mxArray *c55_rhs1 = NULL;
  const mxArray *c55_lhs1 = NULL;
  const mxArray *c55_rhs2 = NULL;
  const mxArray *c55_lhs2 = NULL;
  const mxArray *c55_rhs3 = NULL;
  const mxArray *c55_lhs3 = NULL;
  const mxArray *c55_rhs4 = NULL;
  const mxArray *c55_lhs4 = NULL;
  const mxArray *c55_rhs5 = NULL;
  const mxArray *c55_lhs5 = NULL;
  const mxArray *c55_rhs6 = NULL;
  const mxArray *c55_lhs6 = NULL;
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c55_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c55_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c55_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c55_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c55_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c55_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c55_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs6), "lhs", "lhs",
                  6);
  sf_mex_destroy(&c55_rhs0);
  sf_mex_destroy(&c55_lhs0);
  sf_mex_destroy(&c55_rhs1);
  sf_mex_destroy(&c55_lhs1);
  sf_mex_destroy(&c55_rhs2);
  sf_mex_destroy(&c55_lhs2);
  sf_mex_destroy(&c55_rhs3);
  sf_mex_destroy(&c55_lhs3);
  sf_mex_destroy(&c55_rhs4);
  sf_mex_destroy(&c55_lhs4);
  sf_mex_destroy(&c55_rhs5);
  sf_mex_destroy(&c55_lhs5);
  sf_mex_destroy(&c55_rhs6);
  sf_mex_destroy(&c55_lhs6);
}

static const mxArray *c55_emlrt_marshallOut(const char * c55_u)
{
  const mxArray *c55_y = NULL;
  c55_y = NULL;
  sf_mex_assign(&c55_y, sf_mex_create("y", c55_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c55_u)), false);
  return c55_y;
}

static const mxArray *c55_b_emlrt_marshallOut(const uint32_T c55_u)
{
  const mxArray *c55_y = NULL;
  c55_y = NULL;
  sf_mex_assign(&c55_y, sf_mex_create("y", &c55_u, 7, 0U, 0U, 0U, 0), false);
  return c55_y;
}

static const mxArray *c55_c_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData)
{
  const mxArray *c55_mxArrayOutData = NULL;
  int32_T c55_u;
  const mxArray *c55_y = NULL;
  SFc55_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc55_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c55_mxArrayOutData = NULL;
  c55_u = *(int32_T *)c55_inData;
  c55_y = NULL;
  sf_mex_assign(&c55_y, sf_mex_create("y", &c55_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c55_mxArrayOutData, c55_y, false);
  return c55_mxArrayOutData;
}

static int32_T c55_d_emlrt_marshallIn(SFc55_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId)
{
  int32_T c55_y;
  int32_T c55_i17;
  (void)chartInstance;
  sf_mex_import(c55_parentId, sf_mex_dup(c55_u), &c55_i17, 1, 6, 0U, 0, 0U, 0);
  c55_y = c55_i17;
  sf_mex_destroy(&c55_u);
  return c55_y;
}

static void c55_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c55_mxArrayInData, const char_T *c55_varName, void *c55_outData)
{
  const mxArray *c55_b_sfEvent;
  const char_T *c55_identifier;
  emlrtMsgIdentifier c55_thisId;
  int32_T c55_y;
  SFc55_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc55_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c55_b_sfEvent = sf_mex_dup(c55_mxArrayInData);
  c55_identifier = c55_varName;
  c55_thisId.fIdentifier = c55_identifier;
  c55_thisId.fParent = NULL;
  c55_y = c55_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c55_b_sfEvent),
    &c55_thisId);
  sf_mex_destroy(&c55_b_sfEvent);
  *(int32_T *)c55_outData = c55_y;
  sf_mex_destroy(&c55_mxArrayInData);
}

static uint8_T c55_e_emlrt_marshallIn(SFc55_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c55_b_is_active_c55_Experiment_1_cs, const
  char_T *c55_identifier)
{
  uint8_T c55_y;
  emlrtMsgIdentifier c55_thisId;
  c55_thisId.fIdentifier = c55_identifier;
  c55_thisId.fParent = NULL;
  c55_y = c55_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c55_b_is_active_c55_Experiment_1_cs), &c55_thisId);
  sf_mex_destroy(&c55_b_is_active_c55_Experiment_1_cs);
  return c55_y;
}

static uint8_T c55_f_emlrt_marshallIn(SFc55_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId)
{
  uint8_T c55_y;
  uint8_T c55_u0;
  (void)chartInstance;
  sf_mex_import(c55_parentId, sf_mex_dup(c55_u), &c55_u0, 1, 3, 0U, 0, 0U, 0);
  c55_y = c55_u0;
  sf_mex_destroy(&c55_u);
  return c55_y;
}

static void init_dsm_address_info(SFc55_Experiment_1_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc55_Experiment_1_csInstanceStruct
  *chartInstance)
{
  chartInstance->c55_inpoints = (int32_T (*)[64])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c55_pts = (int32_T (*)[64])ssGetInputPortSignal_wrapper
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

void sf_c55_Experiment_1_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2194315090U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1081497345U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3662714297U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3324212700U);
}

mxArray* sf_c55_Experiment_1_cs_get_post_codegen_info(void);
mxArray *sf_c55_Experiment_1_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("qPm77Xx4TH3Cu1IPkbytxB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
      pr[0] = (double)(2);
      pr[1] = (double)(32);
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
    mxArray* mxPostCodegenInfo = sf_c55_Experiment_1_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c55_Experiment_1_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c55_Experiment_1_cs_jit_fallback_info(void)
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

mxArray *sf_c55_Experiment_1_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c55_Experiment_1_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c55_Experiment_1_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[14],T\"inpoints\",},{M[8],M[0],T\"is_active_c55_Experiment_1_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c55_Experiment_1_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc55_Experiment_1_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc55_Experiment_1_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_1_csMachineNumber_,
           55,
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,150);
        _SFD_CV_INIT_EML_FOR(0,1,0,53,79,150);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c55_sf_marshallOut,(MexInFcnForType)
            c55_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c55_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c55_inpoints);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c55_pts);
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
  return "J3EeFNrqrI5Ub1j3wFCYVC";
}

static void sf_opaque_initialize_c55_Experiment_1_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc55_Experiment_1_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c55_Experiment_1_cs((SFc55_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
  initialize_c55_Experiment_1_cs((SFc55_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c55_Experiment_1_cs(void *chartInstanceVar)
{
  enable_c55_Experiment_1_cs((SFc55_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c55_Experiment_1_cs(void *chartInstanceVar)
{
  disable_c55_Experiment_1_cs((SFc55_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c55_Experiment_1_cs(void *chartInstanceVar)
{
  sf_gateway_c55_Experiment_1_cs((SFc55_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c55_Experiment_1_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c55_Experiment_1_cs((SFc55_Experiment_1_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c55_Experiment_1_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c55_Experiment_1_cs((SFc55_Experiment_1_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c55_Experiment_1_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc55_Experiment_1_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_1_cs_optimization_info();
    }

    finalize_c55_Experiment_1_cs((SFc55_Experiment_1_csInstanceStruct*)
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
  initSimStructsc55_Experiment_1_cs((SFc55_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c55_Experiment_1_cs(SimStruct *S)
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
    initialize_params_c55_Experiment_1_cs((SFc55_Experiment_1_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c55_Experiment_1_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Experiment_1_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      55);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,55,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,55,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,55);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,55,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,55,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,55);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4209198173U));
  ssSetChecksum1(S,(689891341U));
  ssSetChecksum2(S,(3424779822U));
  ssSetChecksum3(S,(3690652762U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c55_Experiment_1_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c55_Experiment_1_cs(SimStruct *S)
{
  SFc55_Experiment_1_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc55_Experiment_1_csInstanceStruct *)utMalloc(sizeof
    (SFc55_Experiment_1_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc55_Experiment_1_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c55_Experiment_1_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c55_Experiment_1_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c55_Experiment_1_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c55_Experiment_1_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c55_Experiment_1_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c55_Experiment_1_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c55_Experiment_1_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c55_Experiment_1_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c55_Experiment_1_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c55_Experiment_1_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c55_Experiment_1_cs;
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

void c55_Experiment_1_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c55_Experiment_1_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c55_Experiment_1_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c55_Experiment_1_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c55_Experiment_1_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
