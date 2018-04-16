/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_2_cs_sfun.h"
#include "c21_Experiment_2_cs.h"
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
static const char * c21_debug_family_names[5] = { "i", "nargin", "nargout",
  "pts", "inpoints" };

/* Function Declarations */
static void initialize_c21_Experiment_2_cs(SFc21_Experiment_2_csInstanceStruct
  *chartInstance);
static void initialize_params_c21_Experiment_2_cs
  (SFc21_Experiment_2_csInstanceStruct *chartInstance);
static void enable_c21_Experiment_2_cs(SFc21_Experiment_2_csInstanceStruct
  *chartInstance);
static void disable_c21_Experiment_2_cs(SFc21_Experiment_2_csInstanceStruct
  *chartInstance);
static void c21_update_debugger_state_c21_Experiment_2_cs
  (SFc21_Experiment_2_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c21_Experiment_2_cs
  (SFc21_Experiment_2_csInstanceStruct *chartInstance);
static void set_sim_state_c21_Experiment_2_cs
  (SFc21_Experiment_2_csInstanceStruct *chartInstance, const mxArray *c21_st);
static void finalize_c21_Experiment_2_cs(SFc21_Experiment_2_csInstanceStruct
  *chartInstance);
static void sf_gateway_c21_Experiment_2_cs(SFc21_Experiment_2_csInstanceStruct
  *chartInstance);
static void mdl_start_c21_Experiment_2_cs(SFc21_Experiment_2_csInstanceStruct
  *chartInstance);
static void initSimStructsc21_Experiment_2_cs
  (SFc21_Experiment_2_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c21_machineNumber, uint32_T
  c21_chartNumber, uint32_T c21_instanceNumber);
static const mxArray *c21_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static void c21_emlrt_marshallIn(SFc21_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c21_b_inpoints, const char_T *c21_identifier,
  int32_T c21_y[64]);
static void c21_b_emlrt_marshallIn(SFc21_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId,
  int32_T c21_y[64]);
static void c21_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static const mxArray *c21_b_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static real_T c21_c_emlrt_marshallIn(SFc21_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void c21_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static void c21_info_helper(const mxArray **c21_info);
static const mxArray *c21_emlrt_marshallOut(const char * c21_u);
static const mxArray *c21_b_emlrt_marshallOut(const uint32_T c21_u);
static const mxArray *c21_c_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static int32_T c21_d_emlrt_marshallIn(SFc21_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void c21_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static uint8_T c21_e_emlrt_marshallIn(SFc21_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c21_b_is_active_c21_Experiment_2_cs, const
  char_T *c21_identifier);
static uint8_T c21_f_emlrt_marshallIn(SFc21_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void init_dsm_address_info(SFc21_Experiment_2_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc21_Experiment_2_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c21_Experiment_2_cs(SFc21_Experiment_2_csInstanceStruct
  *chartInstance)
{
  chartInstance->c21_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c21_is_active_c21_Experiment_2_cs = 0U;
}

static void initialize_params_c21_Experiment_2_cs
  (SFc21_Experiment_2_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c21_Experiment_2_cs(SFc21_Experiment_2_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c21_Experiment_2_cs(SFc21_Experiment_2_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c21_update_debugger_state_c21_Experiment_2_cs
  (SFc21_Experiment_2_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c21_Experiment_2_cs
  (SFc21_Experiment_2_csInstanceStruct *chartInstance)
{
  const mxArray *c21_st;
  const mxArray *c21_y = NULL;
  int32_T c21_i0;
  int32_T c21_u[64];
  const mxArray *c21_b_y = NULL;
  uint8_T c21_hoistedGlobal;
  uint8_T c21_b_u;
  const mxArray *c21_c_y = NULL;
  c21_st = NULL;
  c21_st = NULL;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_createcellmatrix(2, 1), false);
  for (c21_i0 = 0; c21_i0 < 64; c21_i0++) {
    c21_u[c21_i0] = (*chartInstance->c21_inpoints)[c21_i0];
  }

  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", c21_u, 6, 0U, 1U, 0U, 2, 2, 32),
                false);
  sf_mex_setcell(c21_y, 0, c21_b_y);
  c21_hoistedGlobal = chartInstance->c21_is_active_c21_Experiment_2_cs;
  c21_b_u = c21_hoistedGlobal;
  c21_c_y = NULL;
  sf_mex_assign(&c21_c_y, sf_mex_create("y", &c21_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c21_y, 1, c21_c_y);
  sf_mex_assign(&c21_st, c21_y, false);
  return c21_st;
}

static void set_sim_state_c21_Experiment_2_cs
  (SFc21_Experiment_2_csInstanceStruct *chartInstance, const mxArray *c21_st)
{
  const mxArray *c21_u;
  int32_T c21_iv0[64];
  int32_T c21_i1;
  chartInstance->c21_doneDoubleBufferReInit = true;
  c21_u = sf_mex_dup(c21_st);
  c21_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c21_u, 0)),
                       "inpoints", c21_iv0);
  for (c21_i1 = 0; c21_i1 < 64; c21_i1++) {
    (*chartInstance->c21_inpoints)[c21_i1] = c21_iv0[c21_i1];
  }

  chartInstance->c21_is_active_c21_Experiment_2_cs = c21_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c21_u, 1)),
     "is_active_c21_Experiment_2_cs");
  sf_mex_destroy(&c21_u);
  c21_update_debugger_state_c21_Experiment_2_cs(chartInstance);
  sf_mex_destroy(&c21_st);
}

static void finalize_c21_Experiment_2_cs(SFc21_Experiment_2_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c21_Experiment_2_cs(SFc21_Experiment_2_csInstanceStruct
  *chartInstance)
{
  int32_T c21_i2;
  int32_T c21_b_pts[64];
  uint32_T c21_debug_family_var_map[5];
  real_T c21_i;
  real_T c21_nargin = 1.0;
  real_T c21_nargout = 1.0;
  int32_T c21_b_inpoints[64];
  int32_T c21_i3;
  int32_T c21_i4;
  int32_T c21_i5;
  int32_T c21_i6;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 20U, chartInstance->c21_sfEvent);
  chartInstance->c21_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 20U, chartInstance->c21_sfEvent);
  for (c21_i2 = 0; c21_i2 < 64; c21_i2++) {
    c21_b_pts[c21_i2] = (*chartInstance->c21_pts)[c21_i2];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c21_debug_family_names,
    c21_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c21_i, 0U, c21_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_nargin, 1U, c21_b_sf_marshallOut,
    c21_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_nargout, 2U, c21_b_sf_marshallOut,
    c21_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c21_b_pts, 3U, c21_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c21_b_inpoints, 4U, c21_sf_marshallOut,
    c21_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 3);
  for (c21_i3 = 0; c21_i3 < 64; c21_i3++) {
    c21_b_inpoints[c21_i3] = c21_b_pts[c21_i3];
  }

  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 4);
  c21_i = 0.0;
  CV_EML_FOR(0, 1, 0, 1);
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 5);
  c21_b_inpoints[0] = c21_b_pts[1];
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 6);
  c21_b_inpoints[1] = c21_b_pts[0];
  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, -6);
  _SFD_SYMBOL_SCOPE_POP();
  for (c21_i4 = 0; c21_i4 < 64; c21_i4++) {
    (*chartInstance->c21_inpoints)[c21_i4] = c21_b_inpoints[c21_i4];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, chartInstance->c21_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_2_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c21_i5 = 0; c21_i5 < 64; c21_i5++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c21_inpoints)[c21_i5], 0U);
  }

  for (c21_i6 = 0; c21_i6 < 64; c21_i6++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c21_pts)[c21_i6], 1U);
  }
}

static void mdl_start_c21_Experiment_2_cs(SFc21_Experiment_2_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc21_Experiment_2_cs
  (SFc21_Experiment_2_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c21_machineNumber, uint32_T
  c21_chartNumber, uint32_T c21_instanceNumber)
{
  (void)c21_machineNumber;
  (void)c21_chartNumber;
  (void)c21_instanceNumber;
}

static const mxArray *c21_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  int32_T c21_i7;
  int32_T c21_i8;
  int32_T c21_i9;
  int32_T c21_b_inData[64];
  int32_T c21_i10;
  int32_T c21_i11;
  int32_T c21_i12;
  int32_T c21_u[64];
  const mxArray *c21_y = NULL;
  SFc21_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc21_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  c21_i7 = 0;
  for (c21_i8 = 0; c21_i8 < 32; c21_i8++) {
    for (c21_i9 = 0; c21_i9 < 2; c21_i9++) {
      c21_b_inData[c21_i9 + c21_i7] = (*(int32_T (*)[64])c21_inData)[c21_i9 +
        c21_i7];
    }

    c21_i7 += 2;
  }

  c21_i10 = 0;
  for (c21_i11 = 0; c21_i11 < 32; c21_i11++) {
    for (c21_i12 = 0; c21_i12 < 2; c21_i12++) {
      c21_u[c21_i12 + c21_i10] = c21_b_inData[c21_i12 + c21_i10];
    }

    c21_i10 += 2;
  }

  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", c21_u, 6, 0U, 1U, 0U, 2, 2, 32),
                false);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, false);
  return c21_mxArrayOutData;
}

static void c21_emlrt_marshallIn(SFc21_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c21_b_inpoints, const char_T *c21_identifier,
  int32_T c21_y[64])
{
  emlrtMsgIdentifier c21_thisId;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_inpoints), &c21_thisId,
    c21_y);
  sf_mex_destroy(&c21_b_inpoints);
}

static void c21_b_emlrt_marshallIn(SFc21_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId,
  int32_T c21_y[64])
{
  int32_T c21_iv1[64];
  int32_T c21_i13;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), c21_iv1, 1, 6, 0U, 1, 0U, 2, 2,
                32);
  for (c21_i13 = 0; c21_i13 < 64; c21_i13++) {
    c21_y[c21_i13] = c21_iv1[c21_i13];
  }

  sf_mex_destroy(&c21_u);
}

static void c21_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_b_inpoints;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  int32_T c21_y[64];
  int32_T c21_i14;
  int32_T c21_i15;
  int32_T c21_i16;
  SFc21_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc21_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c21_b_inpoints = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_inpoints), &c21_thisId,
    c21_y);
  sf_mex_destroy(&c21_b_inpoints);
  c21_i14 = 0;
  for (c21_i15 = 0; c21_i15 < 32; c21_i15++) {
    for (c21_i16 = 0; c21_i16 < 2; c21_i16++) {
      (*(int32_T (*)[64])c21_outData)[c21_i16 + c21_i14] = c21_y[c21_i16 +
        c21_i14];
    }

    c21_i14 += 2;
  }

  sf_mex_destroy(&c21_mxArrayInData);
}

static const mxArray *c21_b_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  real_T c21_u;
  const mxArray *c21_y = NULL;
  SFc21_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc21_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  c21_u = *(real_T *)c21_inData;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", &c21_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, false);
  return c21_mxArrayOutData;
}

static real_T c21_c_emlrt_marshallIn(SFc21_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  real_T c21_y;
  real_T c21_d0;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_d0, 1, 0, 0U, 0, 0U, 0);
  c21_y = c21_d0;
  sf_mex_destroy(&c21_u);
  return c21_y;
}

static void c21_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_nargout;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  real_T c21_y;
  SFc21_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc21_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c21_nargout = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_y = c21_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_nargout),
    &c21_thisId);
  sf_mex_destroy(&c21_nargout);
  *(real_T *)c21_outData = c21_y;
  sf_mex_destroy(&c21_mxArrayInData);
}

const mxArray *sf_c21_Experiment_2_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c21_nameCaptureInfo = NULL;
  c21_nameCaptureInfo = NULL;
  sf_mex_assign(&c21_nameCaptureInfo, sf_mex_createstruct("structure", 2, 7, 1),
                false);
  c21_info_helper(&c21_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c21_nameCaptureInfo);
  return c21_nameCaptureInfo;
}

static void c21_info_helper(const mxArray **c21_info)
{
  const mxArray *c21_rhs0 = NULL;
  const mxArray *c21_lhs0 = NULL;
  const mxArray *c21_rhs1 = NULL;
  const mxArray *c21_lhs1 = NULL;
  const mxArray *c21_rhs2 = NULL;
  const mxArray *c21_lhs2 = NULL;
  const mxArray *c21_rhs3 = NULL;
  const mxArray *c21_lhs3 = NULL;
  const mxArray *c21_rhs4 = NULL;
  const mxArray *c21_lhs4 = NULL;
  const mxArray *c21_rhs5 = NULL;
  const mxArray *c21_lhs5 = NULL;
  const mxArray *c21_rhs6 = NULL;
  const mxArray *c21_lhs6 = NULL;
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c21_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c21_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c21_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c21_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c21_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c21_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c21_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs6), "lhs", "lhs",
                  6);
  sf_mex_destroy(&c21_rhs0);
  sf_mex_destroy(&c21_lhs0);
  sf_mex_destroy(&c21_rhs1);
  sf_mex_destroy(&c21_lhs1);
  sf_mex_destroy(&c21_rhs2);
  sf_mex_destroy(&c21_lhs2);
  sf_mex_destroy(&c21_rhs3);
  sf_mex_destroy(&c21_lhs3);
  sf_mex_destroy(&c21_rhs4);
  sf_mex_destroy(&c21_lhs4);
  sf_mex_destroy(&c21_rhs5);
  sf_mex_destroy(&c21_lhs5);
  sf_mex_destroy(&c21_rhs6);
  sf_mex_destroy(&c21_lhs6);
}

static const mxArray *c21_emlrt_marshallOut(const char * c21_u)
{
  const mxArray *c21_y = NULL;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", c21_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c21_u)), false);
  return c21_y;
}

static const mxArray *c21_b_emlrt_marshallOut(const uint32_T c21_u)
{
  const mxArray *c21_y = NULL;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", &c21_u, 7, 0U, 0U, 0U, 0), false);
  return c21_y;
}

static const mxArray *c21_c_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  int32_T c21_u;
  const mxArray *c21_y = NULL;
  SFc21_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc21_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  c21_u = *(int32_T *)c21_inData;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", &c21_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, false);
  return c21_mxArrayOutData;
}

static int32_T c21_d_emlrt_marshallIn(SFc21_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  int32_T c21_y;
  int32_T c21_i17;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_i17, 1, 6, 0U, 0, 0U, 0);
  c21_y = c21_i17;
  sf_mex_destroy(&c21_u);
  return c21_y;
}

static void c21_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_b_sfEvent;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  int32_T c21_y;
  SFc21_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc21_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c21_b_sfEvent = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_y = c21_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_sfEvent),
    &c21_thisId);
  sf_mex_destroy(&c21_b_sfEvent);
  *(int32_T *)c21_outData = c21_y;
  sf_mex_destroy(&c21_mxArrayInData);
}

static uint8_T c21_e_emlrt_marshallIn(SFc21_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c21_b_is_active_c21_Experiment_2_cs, const
  char_T *c21_identifier)
{
  uint8_T c21_y;
  emlrtMsgIdentifier c21_thisId;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_y = c21_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c21_b_is_active_c21_Experiment_2_cs), &c21_thisId);
  sf_mex_destroy(&c21_b_is_active_c21_Experiment_2_cs);
  return c21_y;
}

static uint8_T c21_f_emlrt_marshallIn(SFc21_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  uint8_T c21_y;
  uint8_T c21_u0;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_u0, 1, 3, 0U, 0, 0U, 0);
  c21_y = c21_u0;
  sf_mex_destroy(&c21_u);
  return c21_y;
}

static void init_dsm_address_info(SFc21_Experiment_2_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc21_Experiment_2_csInstanceStruct
  *chartInstance)
{
  chartInstance->c21_inpoints = (int32_T (*)[64])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c21_pts = (int32_T (*)[64])ssGetInputPortSignal_wrapper
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

void sf_c21_Experiment_2_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2194315090U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1081497345U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3662714297U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3324212700U);
}

mxArray* sf_c21_Experiment_2_cs_get_post_codegen_info(void);
mxArray *sf_c21_Experiment_2_cs_get_autoinheritance_info(void)
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
    mxArray* mxPostCodegenInfo = sf_c21_Experiment_2_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c21_Experiment_2_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c21_Experiment_2_cs_jit_fallback_info(void)
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

mxArray *sf_c21_Experiment_2_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c21_Experiment_2_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c21_Experiment_2_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[14],T\"inpoints\",},{M[8],M[0],T\"is_active_c21_Experiment_2_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c21_Experiment_2_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc21_Experiment_2_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc21_Experiment_2_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_2_csMachineNumber_,
           21,
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
            1.0,0,0,(MexFcnForType)c21_sf_marshallOut,(MexInFcnForType)
            c21_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c21_inpoints);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c21_pts);
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
  return "J3EeFNrqrI5Ub1j3wFCYVC";
}

static void sf_opaque_initialize_c21_Experiment_2_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc21_Experiment_2_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c21_Experiment_2_cs((SFc21_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
  initialize_c21_Experiment_2_cs((SFc21_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c21_Experiment_2_cs(void *chartInstanceVar)
{
  enable_c21_Experiment_2_cs((SFc21_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c21_Experiment_2_cs(void *chartInstanceVar)
{
  disable_c21_Experiment_2_cs((SFc21_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c21_Experiment_2_cs(void *chartInstanceVar)
{
  sf_gateway_c21_Experiment_2_cs((SFc21_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c21_Experiment_2_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c21_Experiment_2_cs((SFc21_Experiment_2_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c21_Experiment_2_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c21_Experiment_2_cs((SFc21_Experiment_2_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c21_Experiment_2_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc21_Experiment_2_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_2_cs_optimization_info();
    }

    finalize_c21_Experiment_2_cs((SFc21_Experiment_2_csInstanceStruct*)
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
  initSimStructsc21_Experiment_2_cs((SFc21_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c21_Experiment_2_cs(SimStruct *S)
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
    initialize_params_c21_Experiment_2_cs((SFc21_Experiment_2_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c21_Experiment_2_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Experiment_2_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      21);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,21,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,21,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,21);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,21,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,21,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,21);
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

static void mdlRTW_c21_Experiment_2_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c21_Experiment_2_cs(SimStruct *S)
{
  SFc21_Experiment_2_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc21_Experiment_2_csInstanceStruct *)utMalloc(sizeof
    (SFc21_Experiment_2_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc21_Experiment_2_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c21_Experiment_2_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c21_Experiment_2_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c21_Experiment_2_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c21_Experiment_2_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c21_Experiment_2_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c21_Experiment_2_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c21_Experiment_2_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c21_Experiment_2_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c21_Experiment_2_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c21_Experiment_2_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c21_Experiment_2_cs;
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

void c21_Experiment_2_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c21_Experiment_2_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c21_Experiment_2_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c21_Experiment_2_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c21_Experiment_2_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
