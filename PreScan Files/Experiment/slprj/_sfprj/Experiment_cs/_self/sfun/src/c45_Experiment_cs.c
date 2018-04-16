/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_cs_sfun.h"
#include "c45_Experiment_cs.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Experiment_cs_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c45_debug_family_names[5] = { "i", "nargin", "nargout",
  "pts", "inpoints" };

/* Function Declarations */
static void initialize_c45_Experiment_cs(SFc45_Experiment_csInstanceStruct
  *chartInstance);
static void initialize_params_c45_Experiment_cs
  (SFc45_Experiment_csInstanceStruct *chartInstance);
static void enable_c45_Experiment_cs(SFc45_Experiment_csInstanceStruct
  *chartInstance);
static void disable_c45_Experiment_cs(SFc45_Experiment_csInstanceStruct
  *chartInstance);
static void c45_update_debugger_state_c45_Experiment_cs
  (SFc45_Experiment_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c45_Experiment_cs
  (SFc45_Experiment_csInstanceStruct *chartInstance);
static void set_sim_state_c45_Experiment_cs(SFc45_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c45_st);
static void finalize_c45_Experiment_cs(SFc45_Experiment_csInstanceStruct
  *chartInstance);
static void sf_gateway_c45_Experiment_cs(SFc45_Experiment_csInstanceStruct
  *chartInstance);
static void mdl_start_c45_Experiment_cs(SFc45_Experiment_csInstanceStruct
  *chartInstance);
static void initSimStructsc45_Experiment_cs(SFc45_Experiment_csInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c45_machineNumber, uint32_T
  c45_chartNumber, uint32_T c45_instanceNumber);
static const mxArray *c45_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData);
static void c45_emlrt_marshallIn(SFc45_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c45_b_inpoints, const char_T *c45_identifier,
  int32_T c45_y[64]);
static void c45_b_emlrt_marshallIn(SFc45_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId,
  int32_T c45_y[64]);
static void c45_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData);
static const mxArray *c45_b_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData);
static real_T c45_c_emlrt_marshallIn(SFc45_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId);
static void c45_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData);
static const mxArray *c45_c_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData);
static int32_T c45_d_emlrt_marshallIn(SFc45_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId);
static void c45_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData);
static uint8_T c45_e_emlrt_marshallIn(SFc45_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c45_b_is_active_c45_Experiment_cs, const char_T
  *c45_identifier);
static uint8_T c45_f_emlrt_marshallIn(SFc45_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId);
static void init_dsm_address_info(SFc45_Experiment_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc45_Experiment_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c45_Experiment_cs(SFc45_Experiment_csInstanceStruct
  *chartInstance)
{
  chartInstance->c45_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c45_is_active_c45_Experiment_cs = 0U;
}

static void initialize_params_c45_Experiment_cs
  (SFc45_Experiment_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c45_Experiment_cs(SFc45_Experiment_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c45_Experiment_cs(SFc45_Experiment_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c45_update_debugger_state_c45_Experiment_cs
  (SFc45_Experiment_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c45_Experiment_cs
  (SFc45_Experiment_csInstanceStruct *chartInstance)
{
  const mxArray *c45_st;
  const mxArray *c45_y = NULL;
  int32_T c45_i0;
  int32_T c45_u[64];
  const mxArray *c45_b_y = NULL;
  uint8_T c45_hoistedGlobal;
  uint8_T c45_b_u;
  const mxArray *c45_c_y = NULL;
  c45_st = NULL;
  c45_st = NULL;
  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_createcellmatrix(2, 1), false);
  for (c45_i0 = 0; c45_i0 < 64; c45_i0++) {
    c45_u[c45_i0] = (*chartInstance->c45_inpoints)[c45_i0];
  }

  c45_b_y = NULL;
  sf_mex_assign(&c45_b_y, sf_mex_create("y", c45_u, 6, 0U, 1U, 0U, 2, 2, 32),
                false);
  sf_mex_setcell(c45_y, 0, c45_b_y);
  c45_hoistedGlobal = chartInstance->c45_is_active_c45_Experiment_cs;
  c45_b_u = c45_hoistedGlobal;
  c45_c_y = NULL;
  sf_mex_assign(&c45_c_y, sf_mex_create("y", &c45_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c45_y, 1, c45_c_y);
  sf_mex_assign(&c45_st, c45_y, false);
  return c45_st;
}

static void set_sim_state_c45_Experiment_cs(SFc45_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c45_st)
{
  const mxArray *c45_u;
  int32_T c45_iv0[64];
  int32_T c45_i1;
  chartInstance->c45_doneDoubleBufferReInit = true;
  c45_u = sf_mex_dup(c45_st);
  c45_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c45_u, 0)),
                       "inpoints", c45_iv0);
  for (c45_i1 = 0; c45_i1 < 64; c45_i1++) {
    (*chartInstance->c45_inpoints)[c45_i1] = c45_iv0[c45_i1];
  }

  chartInstance->c45_is_active_c45_Experiment_cs = c45_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c45_u, 1)),
     "is_active_c45_Experiment_cs");
  sf_mex_destroy(&c45_u);
  c45_update_debugger_state_c45_Experiment_cs(chartInstance);
  sf_mex_destroy(&c45_st);
}

static void finalize_c45_Experiment_cs(SFc45_Experiment_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c45_Experiment_cs(SFc45_Experiment_csInstanceStruct
  *chartInstance)
{
  int32_T c45_i2;
  int32_T c45_b_pts[64];
  uint32_T c45_debug_family_var_map[5];
  real_T c45_i;
  real_T c45_nargin = 1.0;
  real_T c45_nargout = 1.0;
  int32_T c45_b_inpoints[64];
  int32_T c45_i3;
  int32_T c45_i4;
  int32_T c45_i5;
  int32_T c45_i6;
  int32_T c45_i7;
  int32_T c45_b_i;
  real_T c45_d0;
  int64_T c45_i8;
  real_T c45_d1;
  int64_T c45_i9;
  int32_T c45_i10;
  int32_T c45_i11;
  int32_T c45_i12;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 44U, chartInstance->c45_sfEvent);
  chartInstance->c45_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 44U, chartInstance->c45_sfEvent);
  for (c45_i2 = 0; c45_i2 < 64; c45_i2++) {
    c45_b_pts[c45_i2] = (*chartInstance->c45_pts)[c45_i2];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c45_debug_family_names,
    c45_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_i, 0U, c45_b_sf_marshallOut,
    c45_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_nargin, 1U, c45_b_sf_marshallOut,
    c45_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_nargout, 2U, c45_b_sf_marshallOut,
    c45_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c45_b_pts, 3U, c45_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c45_b_inpoints, 4U, c45_sf_marshallOut,
    c45_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 3);
  for (c45_i3 = 0; c45_i3 < 64; c45_i3++) {
    c45_b_inpoints[c45_i3] = c45_b_pts[c45_i3];
  }

  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 4);
  c45_i4 = 0;
  for (c45_i5 = 0; c45_i5 < 32; c45_i5++) {
    c45_b_inpoints[c45_i4] = c45_b_pts[c45_i4 + 1];
    c45_i4 += 2;
  }

  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 5);
  c45_i6 = 0;
  for (c45_i7 = 0; c45_i7 < 32; c45_i7++) {
    c45_b_inpoints[c45_i6 + 1] = c45_b_pts[c45_i6];
    c45_i6 += 2;
  }

  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 7);
  c45_i = 1.0;
  c45_b_i = 0;
  while (c45_b_i < 32) {
    c45_i = 1.0 + (real_T)c45_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 8);
    c45_d0 = (real_T)c45_b_inpoints[(_SFD_EML_ARRAY_BOUNDS_CHECK("inpoints",
      (int32_T)_SFD_INTEGER_CHECK("i", c45_i), 1, 32, 2, 0) - 1) << 1];
    if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c45_d0, -1.0, -1, 1U,
          c45_d0 != -1.0))) {
      _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 9);
      c45_i8 = (int64_T)c45_b_inpoints[(_SFD_EML_ARRAY_BOUNDS_CHECK("inpoints",
        (int32_T)_SFD_INTEGER_CHECK("i", c45_i), 1, 32, 2, 0) - 1) << 1] + 1LL;
      if (c45_i8 > 2147483647LL) {
        CV_SATURATION_EVAL(4, 0, 0, 0, 1);
        c45_i8 = 2147483647LL;
      } else {
        if (CV_SATURATION_EVAL(4, 0, 0, 0, c45_i8 < -2147483648LL)) {
          c45_i8 = -2147483648LL;
        }
      }

      c45_b_inpoints[(_SFD_EML_ARRAY_BOUNDS_CHECK("inpoints", (int32_T)
        _SFD_INTEGER_CHECK("i", c45_i), 1, 32, 2, 0) - 1) << 1] = (int32_T)
        c45_i8;
    }

    _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 11);
    c45_d1 = (real_T)c45_b_inpoints[1 + ((_SFD_EML_ARRAY_BOUNDS_CHECK("inpoints",
      (int32_T)_SFD_INTEGER_CHECK("i", c45_i), 1, 32, 2, 0) - 1) << 1)];
    if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c45_d1, -1.0, -1, 1U,
          c45_d1 != -1.0))) {
      _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 12);
      c45_i9 = (int64_T)c45_b_inpoints[1 + ((_SFD_EML_ARRAY_BOUNDS_CHECK(
        "inpoints", (int32_T)_SFD_INTEGER_CHECK("i", c45_i), 1, 32, 2, 0) - 1) <<
        1)] + 1LL;
      if (c45_i9 > 2147483647LL) {
        CV_SATURATION_EVAL(4, 0, 1, 0, 1);
        c45_i9 = 2147483647LL;
      } else {
        if (CV_SATURATION_EVAL(4, 0, 1, 0, c45_i9 < -2147483648LL)) {
          c45_i9 = -2147483648LL;
        }
      }

      c45_b_inpoints[1 + ((_SFD_EML_ARRAY_BOUNDS_CHECK("inpoints", (int32_T)
        _SFD_INTEGER_CHECK("i", c45_i), 1, 32, 2, 0) - 1) << 1)] = (int32_T)
        c45_i9;
    }

    c45_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, -12);
  _SFD_SYMBOL_SCOPE_POP();
  for (c45_i10 = 0; c45_i10 < 64; c45_i10++) {
    (*chartInstance->c45_inpoints)[c45_i10] = c45_b_inpoints[c45_i10];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 44U, chartInstance->c45_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c45_i11 = 0; c45_i11 < 64; c45_i11++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c45_inpoints)[c45_i11], 0U);
  }

  for (c45_i12 = 0; c45_i12 < 64; c45_i12++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c45_pts)[c45_i12], 1U);
  }
}

static void mdl_start_c45_Experiment_cs(SFc45_Experiment_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc45_Experiment_cs(SFc45_Experiment_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c45_machineNumber, uint32_T
  c45_chartNumber, uint32_T c45_instanceNumber)
{
  (void)c45_machineNumber;
  (void)c45_chartNumber;
  (void)c45_instanceNumber;
}

static const mxArray *c45_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData)
{
  const mxArray *c45_mxArrayOutData = NULL;
  int32_T c45_i13;
  int32_T c45_i14;
  int32_T c45_i15;
  int32_T c45_b_inData[64];
  int32_T c45_i16;
  int32_T c45_i17;
  int32_T c45_i18;
  int32_T c45_u[64];
  const mxArray *c45_y = NULL;
  SFc45_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc45_Experiment_csInstanceStruct *)chartInstanceVoid;
  c45_mxArrayOutData = NULL;
  c45_i13 = 0;
  for (c45_i14 = 0; c45_i14 < 32; c45_i14++) {
    for (c45_i15 = 0; c45_i15 < 2; c45_i15++) {
      c45_b_inData[c45_i15 + c45_i13] = (*(int32_T (*)[64])c45_inData)[c45_i15 +
        c45_i13];
    }

    c45_i13 += 2;
  }

  c45_i16 = 0;
  for (c45_i17 = 0; c45_i17 < 32; c45_i17++) {
    for (c45_i18 = 0; c45_i18 < 2; c45_i18++) {
      c45_u[c45_i18 + c45_i16] = c45_b_inData[c45_i18 + c45_i16];
    }

    c45_i16 += 2;
  }

  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_create("y", c45_u, 6, 0U, 1U, 0U, 2, 2, 32),
                false);
  sf_mex_assign(&c45_mxArrayOutData, c45_y, false);
  return c45_mxArrayOutData;
}

static void c45_emlrt_marshallIn(SFc45_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c45_b_inpoints, const char_T *c45_identifier,
  int32_T c45_y[64])
{
  emlrtMsgIdentifier c45_thisId;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c45_b_inpoints), &c45_thisId,
    c45_y);
  sf_mex_destroy(&c45_b_inpoints);
}

static void c45_b_emlrt_marshallIn(SFc45_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId,
  int32_T c45_y[64])
{
  int32_T c45_iv1[64];
  int32_T c45_i19;
  (void)chartInstance;
  sf_mex_import(c45_parentId, sf_mex_dup(c45_u), c45_iv1, 1, 6, 0U, 1, 0U, 2, 2,
                32);
  for (c45_i19 = 0; c45_i19 < 64; c45_i19++) {
    c45_y[c45_i19] = c45_iv1[c45_i19];
  }

  sf_mex_destroy(&c45_u);
}

static void c45_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData)
{
  const mxArray *c45_b_inpoints;
  const char_T *c45_identifier;
  emlrtMsgIdentifier c45_thisId;
  int32_T c45_y[64];
  int32_T c45_i20;
  int32_T c45_i21;
  int32_T c45_i22;
  SFc45_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc45_Experiment_csInstanceStruct *)chartInstanceVoid;
  c45_b_inpoints = sf_mex_dup(c45_mxArrayInData);
  c45_identifier = c45_varName;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c45_b_inpoints), &c45_thisId,
    c45_y);
  sf_mex_destroy(&c45_b_inpoints);
  c45_i20 = 0;
  for (c45_i21 = 0; c45_i21 < 32; c45_i21++) {
    for (c45_i22 = 0; c45_i22 < 2; c45_i22++) {
      (*(int32_T (*)[64])c45_outData)[c45_i22 + c45_i20] = c45_y[c45_i22 +
        c45_i20];
    }

    c45_i20 += 2;
  }

  sf_mex_destroy(&c45_mxArrayInData);
}

static const mxArray *c45_b_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData)
{
  const mxArray *c45_mxArrayOutData = NULL;
  real_T c45_u;
  const mxArray *c45_y = NULL;
  SFc45_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc45_Experiment_csInstanceStruct *)chartInstanceVoid;
  c45_mxArrayOutData = NULL;
  c45_u = *(real_T *)c45_inData;
  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_create("y", &c45_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c45_mxArrayOutData, c45_y, false);
  return c45_mxArrayOutData;
}

static real_T c45_c_emlrt_marshallIn(SFc45_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId)
{
  real_T c45_y;
  real_T c45_d2;
  (void)chartInstance;
  sf_mex_import(c45_parentId, sf_mex_dup(c45_u), &c45_d2, 1, 0, 0U, 0, 0U, 0);
  c45_y = c45_d2;
  sf_mex_destroy(&c45_u);
  return c45_y;
}

static void c45_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData)
{
  const mxArray *c45_nargout;
  const char_T *c45_identifier;
  emlrtMsgIdentifier c45_thisId;
  real_T c45_y;
  SFc45_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc45_Experiment_csInstanceStruct *)chartInstanceVoid;
  c45_nargout = sf_mex_dup(c45_mxArrayInData);
  c45_identifier = c45_varName;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_y = c45_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c45_nargout),
    &c45_thisId);
  sf_mex_destroy(&c45_nargout);
  *(real_T *)c45_outData = c45_y;
  sf_mex_destroy(&c45_mxArrayInData);
}

const mxArray *sf_c45_Experiment_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c45_nameCaptureInfo = NULL;
  c45_nameCaptureInfo = NULL;
  sf_mex_assign(&c45_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c45_nameCaptureInfo;
}

static const mxArray *c45_c_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData)
{
  const mxArray *c45_mxArrayOutData = NULL;
  int32_T c45_u;
  const mxArray *c45_y = NULL;
  SFc45_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc45_Experiment_csInstanceStruct *)chartInstanceVoid;
  c45_mxArrayOutData = NULL;
  c45_u = *(int32_T *)c45_inData;
  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_create("y", &c45_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c45_mxArrayOutData, c45_y, false);
  return c45_mxArrayOutData;
}

static int32_T c45_d_emlrt_marshallIn(SFc45_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId)
{
  int32_T c45_y;
  int32_T c45_i23;
  (void)chartInstance;
  sf_mex_import(c45_parentId, sf_mex_dup(c45_u), &c45_i23, 1, 6, 0U, 0, 0U, 0);
  c45_y = c45_i23;
  sf_mex_destroy(&c45_u);
  return c45_y;
}

static void c45_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData)
{
  const mxArray *c45_b_sfEvent;
  const char_T *c45_identifier;
  emlrtMsgIdentifier c45_thisId;
  int32_T c45_y;
  SFc45_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc45_Experiment_csInstanceStruct *)chartInstanceVoid;
  c45_b_sfEvent = sf_mex_dup(c45_mxArrayInData);
  c45_identifier = c45_varName;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_y = c45_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c45_b_sfEvent),
    &c45_thisId);
  sf_mex_destroy(&c45_b_sfEvent);
  *(int32_T *)c45_outData = c45_y;
  sf_mex_destroy(&c45_mxArrayInData);
}

static uint8_T c45_e_emlrt_marshallIn(SFc45_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c45_b_is_active_c45_Experiment_cs, const char_T
  *c45_identifier)
{
  uint8_T c45_y;
  emlrtMsgIdentifier c45_thisId;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_y = c45_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c45_b_is_active_c45_Experiment_cs), &c45_thisId);
  sf_mex_destroy(&c45_b_is_active_c45_Experiment_cs);
  return c45_y;
}

static uint8_T c45_f_emlrt_marshallIn(SFc45_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId)
{
  uint8_T c45_y;
  uint8_T c45_u0;
  (void)chartInstance;
  sf_mex_import(c45_parentId, sf_mex_dup(c45_u), &c45_u0, 1, 3, 0U, 0, 0U, 0);
  c45_y = c45_u0;
  sf_mex_destroy(&c45_u);
  return c45_y;
}

static void init_dsm_address_info(SFc45_Experiment_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc45_Experiment_csInstanceStruct
  *chartInstance)
{
  chartInstance->c45_inpoints = (int32_T (*)[64])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c45_pts = (int32_T (*)[64])ssGetInputPortSignal_wrapper
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

void sf_c45_Experiment_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(44008698U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(455150679U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1858991398U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1782570697U);
}

mxArray* sf_c45_Experiment_cs_get_post_codegen_info(void);
mxArray *sf_c45_Experiment_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("OMaCKgxpARCE2axhuRwslD");
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
    mxArray* mxPostCodegenInfo = sf_c45_Experiment_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c45_Experiment_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c45_Experiment_cs_jit_fallback_info(void)
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

mxArray *sf_c45_Experiment_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c45_Experiment_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c45_Experiment_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[14],T\"inpoints\",},{M[8],M[0],T\"is_active_c45_Experiment_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c45_Experiment_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc45_Experiment_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc45_Experiment_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_csMachineNumber_,
           45,
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
        _SFD_CV_INIT_EML(0,1,1,2,0,2,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,295);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,187,-1,204);
        _SFD_CV_INIT_EML_SATURATION(0,1,1,265,-1,282);
        _SFD_CV_INIT_EML_IF(0,1,0,140,163,-1,213);
        _SFD_CV_INIT_EML_IF(0,1,1,218,241,-1,291);
        _SFD_CV_INIT_EML_FOR(0,1,0,106,136,295);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,143,163,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,221,241,-1,1);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c45_sf_marshallOut,(MexInFcnForType)
            c45_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c45_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c45_inpoints);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c45_pts);
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
  return "ZoW1L8YNLeGjNd1rZATKZF";
}

static void sf_opaque_initialize_c45_Experiment_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc45_Experiment_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c45_Experiment_cs((SFc45_Experiment_csInstanceStruct*)
    chartInstanceVar);
  initialize_c45_Experiment_cs((SFc45_Experiment_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c45_Experiment_cs(void *chartInstanceVar)
{
  enable_c45_Experiment_cs((SFc45_Experiment_csInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c45_Experiment_cs(void *chartInstanceVar)
{
  disable_c45_Experiment_cs((SFc45_Experiment_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c45_Experiment_cs(void *chartInstanceVar)
{
  sf_gateway_c45_Experiment_cs((SFc45_Experiment_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c45_Experiment_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c45_Experiment_cs((SFc45_Experiment_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c45_Experiment_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c45_Experiment_cs((SFc45_Experiment_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c45_Experiment_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc45_Experiment_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_cs_optimization_info();
    }

    finalize_c45_Experiment_cs((SFc45_Experiment_csInstanceStruct*)
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
  initSimStructsc45_Experiment_cs((SFc45_Experiment_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c45_Experiment_cs(SimStruct *S)
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
    initialize_params_c45_Experiment_cs((SFc45_Experiment_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c45_Experiment_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Experiment_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      45);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,45,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,45,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,45);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,45,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,45,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,45);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2025409077U));
  ssSetChecksum1(S,(54156863U));
  ssSetChecksum2(S,(1779528542U));
  ssSetChecksum3(S,(1674462709U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c45_Experiment_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c45_Experiment_cs(SimStruct *S)
{
  SFc45_Experiment_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc45_Experiment_csInstanceStruct *)utMalloc(sizeof
    (SFc45_Experiment_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc45_Experiment_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c45_Experiment_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c45_Experiment_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c45_Experiment_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c45_Experiment_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c45_Experiment_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c45_Experiment_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c45_Experiment_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c45_Experiment_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c45_Experiment_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c45_Experiment_cs;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c45_Experiment_cs;
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

void c45_Experiment_cs_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c45_Experiment_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c45_Experiment_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c45_Experiment_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c45_Experiment_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
