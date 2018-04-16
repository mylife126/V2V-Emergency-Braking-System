/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_cs_sfun.h"
#include "c34_Experiment_cs.h"
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
static const char * c34_debug_family_names[5] = { "i", "nargin", "nargout",
  "pts", "inpoints" };

/* Function Declarations */
static void initialize_c34_Experiment_cs(SFc34_Experiment_csInstanceStruct
  *chartInstance);
static void initialize_params_c34_Experiment_cs
  (SFc34_Experiment_csInstanceStruct *chartInstance);
static void enable_c34_Experiment_cs(SFc34_Experiment_csInstanceStruct
  *chartInstance);
static void disable_c34_Experiment_cs(SFc34_Experiment_csInstanceStruct
  *chartInstance);
static void c34_update_debugger_state_c34_Experiment_cs
  (SFc34_Experiment_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c34_Experiment_cs
  (SFc34_Experiment_csInstanceStruct *chartInstance);
static void set_sim_state_c34_Experiment_cs(SFc34_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c34_st);
static void finalize_c34_Experiment_cs(SFc34_Experiment_csInstanceStruct
  *chartInstance);
static void sf_gateway_c34_Experiment_cs(SFc34_Experiment_csInstanceStruct
  *chartInstance);
static void mdl_start_c34_Experiment_cs(SFc34_Experiment_csInstanceStruct
  *chartInstance);
static void initSimStructsc34_Experiment_cs(SFc34_Experiment_csInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c34_machineNumber, uint32_T
  c34_chartNumber, uint32_T c34_instanceNumber);
static const mxArray *c34_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData);
static void c34_emlrt_marshallIn(SFc34_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c34_b_inpoints, const char_T *c34_identifier,
  int32_T c34_y[400]);
static void c34_b_emlrt_marshallIn(SFc34_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId,
  int32_T c34_y[400]);
static void c34_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData);
static const mxArray *c34_b_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData);
static real_T c34_c_emlrt_marshallIn(SFc34_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId);
static void c34_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData);
static const mxArray *c34_c_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData);
static int32_T c34_d_emlrt_marshallIn(SFc34_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId);
static void c34_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData);
static uint8_T c34_e_emlrt_marshallIn(SFc34_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c34_b_is_active_c34_Experiment_cs, const char_T
  *c34_identifier);
static uint8_T c34_f_emlrt_marshallIn(SFc34_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId);
static void init_dsm_address_info(SFc34_Experiment_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc34_Experiment_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c34_Experiment_cs(SFc34_Experiment_csInstanceStruct
  *chartInstance)
{
  chartInstance->c34_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c34_is_active_c34_Experiment_cs = 0U;
}

static void initialize_params_c34_Experiment_cs
  (SFc34_Experiment_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c34_Experiment_cs(SFc34_Experiment_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c34_Experiment_cs(SFc34_Experiment_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c34_update_debugger_state_c34_Experiment_cs
  (SFc34_Experiment_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c34_Experiment_cs
  (SFc34_Experiment_csInstanceStruct *chartInstance)
{
  const mxArray *c34_st;
  const mxArray *c34_y = NULL;
  int32_T c34_i0;
  int32_T c34_u[400];
  const mxArray *c34_b_y = NULL;
  uint8_T c34_hoistedGlobal;
  uint8_T c34_b_u;
  const mxArray *c34_c_y = NULL;
  c34_st = NULL;
  c34_st = NULL;
  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_createcellmatrix(2, 1), false);
  for (c34_i0 = 0; c34_i0 < 400; c34_i0++) {
    c34_u[c34_i0] = (*chartInstance->c34_inpoints)[c34_i0];
  }

  c34_b_y = NULL;
  sf_mex_assign(&c34_b_y, sf_mex_create("y", c34_u, 6, 0U, 1U, 0U, 2, 4, 100),
                false);
  sf_mex_setcell(c34_y, 0, c34_b_y);
  c34_hoistedGlobal = chartInstance->c34_is_active_c34_Experiment_cs;
  c34_b_u = c34_hoistedGlobal;
  c34_c_y = NULL;
  sf_mex_assign(&c34_c_y, sf_mex_create("y", &c34_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c34_y, 1, c34_c_y);
  sf_mex_assign(&c34_st, c34_y, false);
  return c34_st;
}

static void set_sim_state_c34_Experiment_cs(SFc34_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c34_st)
{
  const mxArray *c34_u;
  int32_T c34_iv0[400];
  int32_T c34_i1;
  chartInstance->c34_doneDoubleBufferReInit = true;
  c34_u = sf_mex_dup(c34_st);
  c34_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c34_u, 0)),
                       "inpoints", c34_iv0);
  for (c34_i1 = 0; c34_i1 < 400; c34_i1++) {
    (*chartInstance->c34_inpoints)[c34_i1] = c34_iv0[c34_i1];
  }

  chartInstance->c34_is_active_c34_Experiment_cs = c34_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c34_u, 1)),
     "is_active_c34_Experiment_cs");
  sf_mex_destroy(&c34_u);
  c34_update_debugger_state_c34_Experiment_cs(chartInstance);
  sf_mex_destroy(&c34_st);
}

static void finalize_c34_Experiment_cs(SFc34_Experiment_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c34_Experiment_cs(SFc34_Experiment_csInstanceStruct
  *chartInstance)
{
  int32_T c34_i2;
  int32_T c34_b_pts[400];
  uint32_T c34_debug_family_var_map[5];
  real_T c34_i;
  real_T c34_nargin = 1.0;
  real_T c34_nargout = 1.0;
  int32_T c34_b_inpoints[400];
  int32_T c34_i3;
  int32_T c34_i4;
  int32_T c34_i5;
  int32_T c34_i6;
  int32_T c34_i7;
  int32_T c34_i8;
  int32_T c34_i9;
  int32_T c34_i10;
  int32_T c34_i11;
  int32_T c34_b_i;
  real_T c34_d0;
  int64_T c34_i12;
  real_T c34_d1;
  int64_T c34_i13;
  int32_T c34_i14;
  int32_T c34_i15;
  int32_T c34_i16;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 33U, chartInstance->c34_sfEvent);
  chartInstance->c34_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 33U, chartInstance->c34_sfEvent);
  for (c34_i2 = 0; c34_i2 < 400; c34_i2++) {
    c34_b_pts[c34_i2] = (*chartInstance->c34_pts)[c34_i2];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c34_debug_family_names,
    c34_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c34_i, 0U, c34_b_sf_marshallOut,
    c34_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c34_nargin, 1U, c34_b_sf_marshallOut,
    c34_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c34_nargout, 2U, c34_b_sf_marshallOut,
    c34_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c34_b_pts, 3U, c34_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c34_b_inpoints, 4U, c34_sf_marshallOut,
    c34_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 3);
  for (c34_i3 = 0; c34_i3 < 400; c34_i3++) {
    c34_b_inpoints[c34_i3] = c34_b_pts[c34_i3];
  }

  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 4);
  c34_i4 = 0;
  for (c34_i5 = 0; c34_i5 < 100; c34_i5++) {
    c34_b_inpoints[c34_i4] = c34_b_pts[c34_i4 + 1];
    c34_i4 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 5);
  c34_i6 = 0;
  for (c34_i7 = 0; c34_i7 < 100; c34_i7++) {
    c34_b_inpoints[c34_i6 + 1] = c34_b_pts[c34_i6];
    c34_i6 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 6);
  c34_i8 = 0;
  for (c34_i9 = 0; c34_i9 < 100; c34_i9++) {
    c34_b_inpoints[c34_i8 + 2] = c34_b_pts[c34_i8 + 3];
    c34_i8 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 7);
  c34_i10 = 0;
  for (c34_i11 = 0; c34_i11 < 100; c34_i11++) {
    c34_b_inpoints[c34_i10 + 3] = c34_b_pts[c34_i10 + 2];
    c34_i10 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 9);
  c34_i = 1.0;
  c34_b_i = 0;
  while (c34_b_i < 100) {
    c34_i = 1.0 + (real_T)c34_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 10);
    c34_d0 = (real_T)c34_b_inpoints[(_SFD_EML_ARRAY_BOUNDS_CHECK("inpoints",
      (int32_T)_SFD_INTEGER_CHECK("i", c34_i), 1, 100, 2, 0) - 1) << 2];
    if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c34_d0, -1.0, -1, 1U,
          c34_d0 != -1.0))) {
      _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 11);
      c34_i12 = (int64_T)c34_b_inpoints[(_SFD_EML_ARRAY_BOUNDS_CHECK("inpoints",
        (int32_T)_SFD_INTEGER_CHECK("i", c34_i), 1, 100, 2, 0) - 1) << 2] - 1LL;
      if (c34_i12 > 2147483647LL) {
        CV_SATURATION_EVAL(4, 0, 0, 0, 1);
        c34_i12 = 2147483647LL;
      } else {
        if (CV_SATURATION_EVAL(4, 0, 0, 0, c34_i12 < -2147483648LL)) {
          c34_i12 = -2147483648LL;
        }
      }

      c34_b_inpoints[(_SFD_EML_ARRAY_BOUNDS_CHECK("inpoints", (int32_T)
        _SFD_INTEGER_CHECK("i", c34_i), 1, 100, 2, 0) - 1) << 2] = (int32_T)
        c34_i12;
    }

    _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 13);
    c34_d1 = (real_T)c34_b_inpoints[1 + ((_SFD_EML_ARRAY_BOUNDS_CHECK("inpoints",
      (int32_T)_SFD_INTEGER_CHECK("i", c34_i), 1, 100, 2, 0) - 1) << 2)];
    if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c34_d1, -1.0, -1, 1U,
          c34_d1 != -1.0))) {
      _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 14);
      c34_i13 = (int64_T)c34_b_inpoints[1 + ((_SFD_EML_ARRAY_BOUNDS_CHECK(
        "inpoints", (int32_T)_SFD_INTEGER_CHECK("i", c34_i), 1, 100, 2, 0) - 1) <<
        2)] - 1LL;
      if (c34_i13 > 2147483647LL) {
        CV_SATURATION_EVAL(4, 0, 1, 0, 1);
        c34_i13 = 2147483647LL;
      } else {
        if (CV_SATURATION_EVAL(4, 0, 1, 0, c34_i13 < -2147483648LL)) {
          c34_i13 = -2147483648LL;
        }
      }

      c34_b_inpoints[1 + ((_SFD_EML_ARRAY_BOUNDS_CHECK("inpoints", (int32_T)
        _SFD_INTEGER_CHECK("i", c34_i), 1, 100, 2, 0) - 1) << 2)] = (int32_T)
        c34_i13;
    }

    c34_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, -14);
  _SFD_SYMBOL_SCOPE_POP();
  for (c34_i14 = 0; c34_i14 < 400; c34_i14++) {
    (*chartInstance->c34_inpoints)[c34_i14] = c34_b_inpoints[c34_i14];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 33U, chartInstance->c34_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c34_i15 = 0; c34_i15 < 400; c34_i15++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c34_inpoints)[c34_i15], 0U);
  }

  for (c34_i16 = 0; c34_i16 < 400; c34_i16++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c34_pts)[c34_i16], 1U);
  }
}

static void mdl_start_c34_Experiment_cs(SFc34_Experiment_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc34_Experiment_cs(SFc34_Experiment_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c34_machineNumber, uint32_T
  c34_chartNumber, uint32_T c34_instanceNumber)
{
  (void)c34_machineNumber;
  (void)c34_chartNumber;
  (void)c34_instanceNumber;
}

static const mxArray *c34_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData)
{
  const mxArray *c34_mxArrayOutData = NULL;
  int32_T c34_i17;
  int32_T c34_i18;
  int32_T c34_i19;
  int32_T c34_b_inData[400];
  int32_T c34_i20;
  int32_T c34_i21;
  int32_T c34_i22;
  int32_T c34_u[400];
  const mxArray *c34_y = NULL;
  SFc34_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc34_Experiment_csInstanceStruct *)chartInstanceVoid;
  c34_mxArrayOutData = NULL;
  c34_i17 = 0;
  for (c34_i18 = 0; c34_i18 < 100; c34_i18++) {
    for (c34_i19 = 0; c34_i19 < 4; c34_i19++) {
      c34_b_inData[c34_i19 + c34_i17] = (*(int32_T (*)[400])c34_inData)[c34_i19
        + c34_i17];
    }

    c34_i17 += 4;
  }

  c34_i20 = 0;
  for (c34_i21 = 0; c34_i21 < 100; c34_i21++) {
    for (c34_i22 = 0; c34_i22 < 4; c34_i22++) {
      c34_u[c34_i22 + c34_i20] = c34_b_inData[c34_i22 + c34_i20];
    }

    c34_i20 += 4;
  }

  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_create("y", c34_u, 6, 0U, 1U, 0U, 2, 4, 100),
                false);
  sf_mex_assign(&c34_mxArrayOutData, c34_y, false);
  return c34_mxArrayOutData;
}

static void c34_emlrt_marshallIn(SFc34_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c34_b_inpoints, const char_T *c34_identifier,
  int32_T c34_y[400])
{
  emlrtMsgIdentifier c34_thisId;
  c34_thisId.fIdentifier = c34_identifier;
  c34_thisId.fParent = NULL;
  c34_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c34_b_inpoints), &c34_thisId,
    c34_y);
  sf_mex_destroy(&c34_b_inpoints);
}

static void c34_b_emlrt_marshallIn(SFc34_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId,
  int32_T c34_y[400])
{
  int32_T c34_iv1[400];
  int32_T c34_i23;
  (void)chartInstance;
  sf_mex_import(c34_parentId, sf_mex_dup(c34_u), c34_iv1, 1, 6, 0U, 1, 0U, 2, 4,
                100);
  for (c34_i23 = 0; c34_i23 < 400; c34_i23++) {
    c34_y[c34_i23] = c34_iv1[c34_i23];
  }

  sf_mex_destroy(&c34_u);
}

static void c34_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData)
{
  const mxArray *c34_b_inpoints;
  const char_T *c34_identifier;
  emlrtMsgIdentifier c34_thisId;
  int32_T c34_y[400];
  int32_T c34_i24;
  int32_T c34_i25;
  int32_T c34_i26;
  SFc34_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc34_Experiment_csInstanceStruct *)chartInstanceVoid;
  c34_b_inpoints = sf_mex_dup(c34_mxArrayInData);
  c34_identifier = c34_varName;
  c34_thisId.fIdentifier = c34_identifier;
  c34_thisId.fParent = NULL;
  c34_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c34_b_inpoints), &c34_thisId,
    c34_y);
  sf_mex_destroy(&c34_b_inpoints);
  c34_i24 = 0;
  for (c34_i25 = 0; c34_i25 < 100; c34_i25++) {
    for (c34_i26 = 0; c34_i26 < 4; c34_i26++) {
      (*(int32_T (*)[400])c34_outData)[c34_i26 + c34_i24] = c34_y[c34_i26 +
        c34_i24];
    }

    c34_i24 += 4;
  }

  sf_mex_destroy(&c34_mxArrayInData);
}

static const mxArray *c34_b_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData)
{
  const mxArray *c34_mxArrayOutData = NULL;
  real_T c34_u;
  const mxArray *c34_y = NULL;
  SFc34_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc34_Experiment_csInstanceStruct *)chartInstanceVoid;
  c34_mxArrayOutData = NULL;
  c34_u = *(real_T *)c34_inData;
  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_create("y", &c34_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c34_mxArrayOutData, c34_y, false);
  return c34_mxArrayOutData;
}

static real_T c34_c_emlrt_marshallIn(SFc34_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId)
{
  real_T c34_y;
  real_T c34_d2;
  (void)chartInstance;
  sf_mex_import(c34_parentId, sf_mex_dup(c34_u), &c34_d2, 1, 0, 0U, 0, 0U, 0);
  c34_y = c34_d2;
  sf_mex_destroy(&c34_u);
  return c34_y;
}

static void c34_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData)
{
  const mxArray *c34_nargout;
  const char_T *c34_identifier;
  emlrtMsgIdentifier c34_thisId;
  real_T c34_y;
  SFc34_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc34_Experiment_csInstanceStruct *)chartInstanceVoid;
  c34_nargout = sf_mex_dup(c34_mxArrayInData);
  c34_identifier = c34_varName;
  c34_thisId.fIdentifier = c34_identifier;
  c34_thisId.fParent = NULL;
  c34_y = c34_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c34_nargout),
    &c34_thisId);
  sf_mex_destroy(&c34_nargout);
  *(real_T *)c34_outData = c34_y;
  sf_mex_destroy(&c34_mxArrayInData);
}

const mxArray *sf_c34_Experiment_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c34_nameCaptureInfo = NULL;
  c34_nameCaptureInfo = NULL;
  sf_mex_assign(&c34_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c34_nameCaptureInfo;
}

static const mxArray *c34_c_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData)
{
  const mxArray *c34_mxArrayOutData = NULL;
  int32_T c34_u;
  const mxArray *c34_y = NULL;
  SFc34_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc34_Experiment_csInstanceStruct *)chartInstanceVoid;
  c34_mxArrayOutData = NULL;
  c34_u = *(int32_T *)c34_inData;
  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_create("y", &c34_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c34_mxArrayOutData, c34_y, false);
  return c34_mxArrayOutData;
}

static int32_T c34_d_emlrt_marshallIn(SFc34_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId)
{
  int32_T c34_y;
  int32_T c34_i27;
  (void)chartInstance;
  sf_mex_import(c34_parentId, sf_mex_dup(c34_u), &c34_i27, 1, 6, 0U, 0, 0U, 0);
  c34_y = c34_i27;
  sf_mex_destroy(&c34_u);
  return c34_y;
}

static void c34_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData)
{
  const mxArray *c34_b_sfEvent;
  const char_T *c34_identifier;
  emlrtMsgIdentifier c34_thisId;
  int32_T c34_y;
  SFc34_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc34_Experiment_csInstanceStruct *)chartInstanceVoid;
  c34_b_sfEvent = sf_mex_dup(c34_mxArrayInData);
  c34_identifier = c34_varName;
  c34_thisId.fIdentifier = c34_identifier;
  c34_thisId.fParent = NULL;
  c34_y = c34_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c34_b_sfEvent),
    &c34_thisId);
  sf_mex_destroy(&c34_b_sfEvent);
  *(int32_T *)c34_outData = c34_y;
  sf_mex_destroy(&c34_mxArrayInData);
}

static uint8_T c34_e_emlrt_marshallIn(SFc34_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c34_b_is_active_c34_Experiment_cs, const char_T
  *c34_identifier)
{
  uint8_T c34_y;
  emlrtMsgIdentifier c34_thisId;
  c34_thisId.fIdentifier = c34_identifier;
  c34_thisId.fParent = NULL;
  c34_y = c34_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c34_b_is_active_c34_Experiment_cs), &c34_thisId);
  sf_mex_destroy(&c34_b_is_active_c34_Experiment_cs);
  return c34_y;
}

static uint8_T c34_f_emlrt_marshallIn(SFc34_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId)
{
  uint8_T c34_y;
  uint8_T c34_u0;
  (void)chartInstance;
  sf_mex_import(c34_parentId, sf_mex_dup(c34_u), &c34_u0, 1, 3, 0U, 0, 0U, 0);
  c34_y = c34_u0;
  sf_mex_destroy(&c34_u);
  return c34_y;
}

static void init_dsm_address_info(SFc34_Experiment_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc34_Experiment_csInstanceStruct
  *chartInstance)
{
  chartInstance->c34_inpoints = (int32_T (*)[400])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c34_pts = (int32_T (*)[400])ssGetInputPortSignal_wrapper
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

void sf_c34_Experiment_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3194481617U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2047528477U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3842352902U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3700066588U);
}

mxArray* sf_c34_Experiment_cs_get_post_codegen_info(void);
mxArray *sf_c34_Experiment_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("6TgFbwCYbfTKfccOMOZs2B");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(100);
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
      pr[0] = (double)(4);
      pr[1] = (double)(100);
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
    mxArray* mxPostCodegenInfo = sf_c34_Experiment_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c34_Experiment_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c34_Experiment_cs_jit_fallback_info(void)
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

mxArray *sf_c34_Experiment_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c34_Experiment_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c34_Experiment_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[14],T\"inpoints\",},{M[8],M[0],T\"is_active_c34_Experiment_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c34_Experiment_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc34_Experiment_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc34_Experiment_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_csMachineNumber_,
           34,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,349);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,239,-1,256);
        _SFD_CV_INIT_EML_SATURATION(0,1,1,317,-1,334);
        _SFD_CV_INIT_EML_IF(0,1,0,192,215,-1,265);
        _SFD_CV_INIT_EML_IF(0,1,1,270,293,-1,343);
        _SFD_CV_INIT_EML_FOR(0,1,0,158,188,347);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,195,215,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,273,293,-1,1);

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 100;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c34_sf_marshallOut,(MexInFcnForType)
            c34_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 100;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c34_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c34_inpoints);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c34_pts);
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
  return "ZR7ZiHf0Rxi1Cuv6NaOQ8G";
}

static void sf_opaque_initialize_c34_Experiment_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc34_Experiment_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c34_Experiment_cs((SFc34_Experiment_csInstanceStruct*)
    chartInstanceVar);
  initialize_c34_Experiment_cs((SFc34_Experiment_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c34_Experiment_cs(void *chartInstanceVar)
{
  enable_c34_Experiment_cs((SFc34_Experiment_csInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c34_Experiment_cs(void *chartInstanceVar)
{
  disable_c34_Experiment_cs((SFc34_Experiment_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c34_Experiment_cs(void *chartInstanceVar)
{
  sf_gateway_c34_Experiment_cs((SFc34_Experiment_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c34_Experiment_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c34_Experiment_cs((SFc34_Experiment_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c34_Experiment_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c34_Experiment_cs((SFc34_Experiment_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c34_Experiment_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc34_Experiment_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_cs_optimization_info();
    }

    finalize_c34_Experiment_cs((SFc34_Experiment_csInstanceStruct*)
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
  initSimStructsc34_Experiment_cs((SFc34_Experiment_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c34_Experiment_cs(SimStruct *S)
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
    initialize_params_c34_Experiment_cs((SFc34_Experiment_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c34_Experiment_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Experiment_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      34);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,34,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,34,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,34);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,34,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,34,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,34);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2491332108U));
  ssSetChecksum1(S,(3660216570U));
  ssSetChecksum2(S,(1109773185U));
  ssSetChecksum3(S,(2876110939U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c34_Experiment_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c34_Experiment_cs(SimStruct *S)
{
  SFc34_Experiment_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc34_Experiment_csInstanceStruct *)utMalloc(sizeof
    (SFc34_Experiment_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc34_Experiment_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c34_Experiment_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c34_Experiment_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c34_Experiment_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c34_Experiment_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c34_Experiment_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c34_Experiment_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c34_Experiment_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c34_Experiment_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c34_Experiment_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c34_Experiment_cs;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c34_Experiment_cs;
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

void c34_Experiment_cs_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c34_Experiment_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c34_Experiment_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c34_Experiment_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c34_Experiment_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
