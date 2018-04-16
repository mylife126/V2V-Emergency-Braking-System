/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_1_cs_sfun.h"
#include "c6_Experiment_1_cs.h"
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
static const char * c6_debug_family_names[5] = { "i", "nargin", "nargout", "pts",
  "inpoints" };

/* Function Declarations */
static void initialize_c6_Experiment_1_cs(SFc6_Experiment_1_csInstanceStruct
  *chartInstance);
static void initialize_params_c6_Experiment_1_cs
  (SFc6_Experiment_1_csInstanceStruct *chartInstance);
static void enable_c6_Experiment_1_cs(SFc6_Experiment_1_csInstanceStruct
  *chartInstance);
static void disable_c6_Experiment_1_cs(SFc6_Experiment_1_csInstanceStruct
  *chartInstance);
static void c6_update_debugger_state_c6_Experiment_1_cs
  (SFc6_Experiment_1_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c6_Experiment_1_cs
  (SFc6_Experiment_1_csInstanceStruct *chartInstance);
static void set_sim_state_c6_Experiment_1_cs(SFc6_Experiment_1_csInstanceStruct *
  chartInstance, const mxArray *c6_st);
static void finalize_c6_Experiment_1_cs(SFc6_Experiment_1_csInstanceStruct
  *chartInstance);
static void sf_gateway_c6_Experiment_1_cs(SFc6_Experiment_1_csInstanceStruct
  *chartInstance);
static void mdl_start_c6_Experiment_1_cs(SFc6_Experiment_1_csInstanceStruct
  *chartInstance);
static void initSimStructsc6_Experiment_1_cs(SFc6_Experiment_1_csInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static void c6_emlrt_marshallIn(SFc6_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c6_b_inpoints, const char_T *c6_identifier,
  int32_T c6_y[400]);
static void c6_b_emlrt_marshallIn(SFc6_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  int32_T c6_y[400]);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_c_emlrt_marshallIn(SFc6_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_d_emlrt_marshallIn(SFc6_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint8_T c6_e_emlrt_marshallIn(SFc6_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_Experiment_1_cs, const char_T
  *c6_identifier);
static uint8_T c6_f_emlrt_marshallIn(SFc6_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void init_dsm_address_info(SFc6_Experiment_1_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc6_Experiment_1_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c6_Experiment_1_cs(SFc6_Experiment_1_csInstanceStruct
  *chartInstance)
{
  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c6_is_active_c6_Experiment_1_cs = 0U;
}

static void initialize_params_c6_Experiment_1_cs
  (SFc6_Experiment_1_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c6_Experiment_1_cs(SFc6_Experiment_1_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c6_Experiment_1_cs(SFc6_Experiment_1_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c6_update_debugger_state_c6_Experiment_1_cs
  (SFc6_Experiment_1_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c6_Experiment_1_cs
  (SFc6_Experiment_1_csInstanceStruct *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  int32_T c6_i0;
  int32_T c6_u[400];
  const mxArray *c6_b_y = NULL;
  uint8_T c6_hoistedGlobal;
  uint8_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellmatrix(2, 1), false);
  for (c6_i0 = 0; c6_i0 < 400; c6_i0++) {
    c6_u[c6_i0] = (*chartInstance->c6_inpoints)[c6_i0];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_u, 6, 0U, 1U, 0U, 2, 4, 100),
                false);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_hoistedGlobal = chartInstance->c6_is_active_c6_Experiment_1_cs;
  c6_b_u = c6_hoistedGlobal;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  sf_mex_assign(&c6_st, c6_y, false);
  return c6_st;
}

static void set_sim_state_c6_Experiment_1_cs(SFc6_Experiment_1_csInstanceStruct *
  chartInstance, const mxArray *c6_st)
{
  const mxArray *c6_u;
  int32_T c6_iv0[400];
  int32_T c6_i1;
  chartInstance->c6_doneDoubleBufferReInit = true;
  c6_u = sf_mex_dup(c6_st);
  c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 0)),
                      "inpoints", c6_iv0);
  for (c6_i1 = 0; c6_i1 < 400; c6_i1++) {
    (*chartInstance->c6_inpoints)[c6_i1] = c6_iv0[c6_i1];
  }

  chartInstance->c6_is_active_c6_Experiment_1_cs = c6_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 1)),
     "is_active_c6_Experiment_1_cs");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_Experiment_1_cs(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_Experiment_1_cs(SFc6_Experiment_1_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c6_Experiment_1_cs(SFc6_Experiment_1_csInstanceStruct
  *chartInstance)
{
  int32_T c6_i2;
  int32_T c6_b_pts[400];
  uint32_T c6_debug_family_var_map[5];
  real_T c6_i;
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  int32_T c6_b_inpoints[400];
  int32_T c6_i3;
  int32_T c6_i4;
  int32_T c6_i5;
  int32_T c6_i6;
  int32_T c6_i7;
  int32_T c6_i8;
  int32_T c6_i9;
  int32_T c6_i10;
  int32_T c6_i11;
  int32_T c6_b_i;
  real_T c6_d0;
  int64_T c6_i12;
  real_T c6_d1;
  int64_T c6_i13;
  int32_T c6_i14;
  int32_T c6_i15;
  int32_T c6_i16;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  chartInstance->c6_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  for (c6_i2 = 0; c6_i2 < 400; c6_i2++) {
    c6_b_pts[c6_i2] = (*chartInstance->c6_pts)[c6_i2];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c6_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_i, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 1U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 2U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_b_pts, 3U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_b_inpoints, 4U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 3);
  for (c6_i3 = 0; c6_i3 < 400; c6_i3++) {
    c6_b_inpoints[c6_i3] = c6_b_pts[c6_i3];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_i4 = 0;
  for (c6_i5 = 0; c6_i5 < 100; c6_i5++) {
    c6_b_inpoints[c6_i4] = c6_b_pts[c6_i4 + 1];
    c6_i4 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 5);
  c6_i6 = 0;
  for (c6_i7 = 0; c6_i7 < 100; c6_i7++) {
    c6_b_inpoints[c6_i6 + 1] = c6_b_pts[c6_i6];
    c6_i6 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 6);
  c6_i8 = 0;
  for (c6_i9 = 0; c6_i9 < 100; c6_i9++) {
    c6_b_inpoints[c6_i8 + 2] = c6_b_pts[c6_i8 + 3];
    c6_i8 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_i10 = 0;
  for (c6_i11 = 0; c6_i11 < 100; c6_i11++) {
    c6_b_inpoints[c6_i10 + 3] = c6_b_pts[c6_i10 + 2];
    c6_i10 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 9);
  c6_i = 1.0;
  c6_b_i = 0;
  while (c6_b_i < 100) {
    c6_i = 1.0 + (real_T)c6_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 10);
    c6_d0 = (real_T)c6_b_inpoints[(_SFD_EML_ARRAY_BOUNDS_CHECK("inpoints",
      (int32_T)_SFD_INTEGER_CHECK("i", c6_i), 1, 100, 2, 0) - 1) << 2];
    if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c6_d0, -1.0, -1, 1U,
          c6_d0 != -1.0))) {
      _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 11);
      c6_i12 = (int64_T)c6_b_inpoints[(_SFD_EML_ARRAY_BOUNDS_CHECK("inpoints",
        (int32_T)_SFD_INTEGER_CHECK("i", c6_i), 1, 100, 2, 0) - 1) << 2] - 1LL;
      if (c6_i12 > 2147483647LL) {
        CV_SATURATION_EVAL(4, 0, 0, 0, 1);
        c6_i12 = 2147483647LL;
      } else {
        if (CV_SATURATION_EVAL(4, 0, 0, 0, c6_i12 < -2147483648LL)) {
          c6_i12 = -2147483648LL;
        }
      }

      c6_b_inpoints[(_SFD_EML_ARRAY_BOUNDS_CHECK("inpoints", (int32_T)
        _SFD_INTEGER_CHECK("i", c6_i), 1, 100, 2, 0) - 1) << 2] = (int32_T)
        c6_i12;
    }

    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 13);
    c6_d1 = (real_T)c6_b_inpoints[1 + ((_SFD_EML_ARRAY_BOUNDS_CHECK("inpoints",
      (int32_T)_SFD_INTEGER_CHECK("i", c6_i), 1, 100, 2, 0) - 1) << 2)];
    if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c6_d1, -1.0, -1, 1U,
          c6_d1 != -1.0))) {
      _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 14);
      c6_i13 = (int64_T)c6_b_inpoints[1 + ((_SFD_EML_ARRAY_BOUNDS_CHECK(
        "inpoints", (int32_T)_SFD_INTEGER_CHECK("i", c6_i), 1, 100, 2, 0) - 1) <<
        2)] - 1LL;
      if (c6_i13 > 2147483647LL) {
        CV_SATURATION_EVAL(4, 0, 1, 0, 1);
        c6_i13 = 2147483647LL;
      } else {
        if (CV_SATURATION_EVAL(4, 0, 1, 0, c6_i13 < -2147483648LL)) {
          c6_i13 = -2147483648LL;
        }
      }

      c6_b_inpoints[1 + ((_SFD_EML_ARRAY_BOUNDS_CHECK("inpoints", (int32_T)
        _SFD_INTEGER_CHECK("i", c6_i), 1, 100, 2, 0) - 1) << 2)] = (int32_T)
        c6_i13;
    }

    c6_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -14);
  _SFD_SYMBOL_SCOPE_POP();
  for (c6_i14 = 0; c6_i14 < 400; c6_i14++) {
    (*chartInstance->c6_inpoints)[c6_i14] = c6_b_inpoints[c6_i14];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_1_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c6_i15 = 0; c6_i15 < 400; c6_i15++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c6_inpoints)[c6_i15], 0U);
  }

  for (c6_i16 = 0; c6_i16 < 400; c6_i16++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c6_pts)[c6_i16], 1U);
  }
}

static void mdl_start_c6_Experiment_1_cs(SFc6_Experiment_1_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc6_Experiment_1_cs(SFc6_Experiment_1_csInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber)
{
  (void)c6_machineNumber;
  (void)c6_chartNumber;
  (void)c6_instanceNumber;
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i17;
  int32_T c6_i18;
  int32_T c6_i19;
  int32_T c6_b_inData[400];
  int32_T c6_i20;
  int32_T c6_i21;
  int32_T c6_i22;
  int32_T c6_u[400];
  const mxArray *c6_y = NULL;
  SFc6_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc6_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i17 = 0;
  for (c6_i18 = 0; c6_i18 < 100; c6_i18++) {
    for (c6_i19 = 0; c6_i19 < 4; c6_i19++) {
      c6_b_inData[c6_i19 + c6_i17] = (*(int32_T (*)[400])c6_inData)[c6_i19 +
        c6_i17];
    }

    c6_i17 += 4;
  }

  c6_i20 = 0;
  for (c6_i21 = 0; c6_i21 < 100; c6_i21++) {
    for (c6_i22 = 0; c6_i22 < 4; c6_i22++) {
      c6_u[c6_i22 + c6_i20] = c6_b_inData[c6_i22 + c6_i20];
    }

    c6_i20 += 4;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 6, 0U, 1U, 0U, 2, 4, 100), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static void c6_emlrt_marshallIn(SFc6_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c6_b_inpoints, const char_T *c6_identifier,
  int32_T c6_y[400])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_inpoints), &c6_thisId,
                        c6_y);
  sf_mex_destroy(&c6_b_inpoints);
}

static void c6_b_emlrt_marshallIn(SFc6_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  int32_T c6_y[400])
{
  int32_T c6_iv1[400];
  int32_T c6_i23;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_iv1, 1, 6, 0U, 1, 0U, 2, 4,
                100);
  for (c6_i23 = 0; c6_i23 < 400; c6_i23++) {
    c6_y[c6_i23] = c6_iv1[c6_i23];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_inpoints;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y[400];
  int32_T c6_i24;
  int32_T c6_i25;
  int32_T c6_i26;
  SFc6_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc6_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c6_b_inpoints = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_inpoints), &c6_thisId,
                        c6_y);
  sf_mex_destroy(&c6_b_inpoints);
  c6_i24 = 0;
  for (c6_i25 = 0; c6_i25 < 100; c6_i25++) {
    for (c6_i26 = 0; c6_i26 < 4; c6_i26++) {
      (*(int32_T (*)[400])c6_outData)[c6_i26 + c6_i24] = c6_y[c6_i26 + c6_i24];
    }

    c6_i24 += 4;
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc6_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static real_T c6_c_emlrt_marshallIn(SFc6_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d2;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d2, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d2;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_nargout;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc6_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c6_nargout = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_nargout), &c6_thisId);
  sf_mex_destroy(&c6_nargout);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

const mxArray *sf_c6_Experiment_1_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  sf_mex_assign(&c6_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c6_nameCaptureInfo;
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc6_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static int32_T c6_d_emlrt_marshallIn(SFc6_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i27;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i27, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i27;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc6_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static uint8_T c6_e_emlrt_marshallIn(SFc6_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_Experiment_1_cs, const char_T
  *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_Experiment_1_cs), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_Experiment_1_cs);
  return c6_y;
}

static uint8_T c6_f_emlrt_marshallIn(SFc6_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void init_dsm_address_info(SFc6_Experiment_1_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc6_Experiment_1_csInstanceStruct
  *chartInstance)
{
  chartInstance->c6_inpoints = (int32_T (*)[400])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c6_pts = (int32_T (*)[400])ssGetInputPortSignal_wrapper
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

void sf_c6_Experiment_1_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3194481617U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2047528477U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3842352902U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3700066588U);
}

mxArray* sf_c6_Experiment_1_cs_get_post_codegen_info(void);
mxArray *sf_c6_Experiment_1_cs_get_autoinheritance_info(void)
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
    mxArray* mxPostCodegenInfo = sf_c6_Experiment_1_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c6_Experiment_1_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c6_Experiment_1_cs_jit_fallback_info(void)
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

mxArray *sf_c6_Experiment_1_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c6_Experiment_1_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c6_Experiment_1_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[14],T\"inpoints\",},{M[8],M[0],T\"is_active_c6_Experiment_1_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_Experiment_1_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_Experiment_1_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc6_Experiment_1_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_1_csMachineNumber_,
           6,
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
            1.0,0,0,(MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)
            c6_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 100;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c6_inpoints);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c6_pts);
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
  return "ZR7ZiHf0Rxi1Cuv6NaOQ8G";
}

static void sf_opaque_initialize_c6_Experiment_1_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_Experiment_1_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c6_Experiment_1_cs((SFc6_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
  initialize_c6_Experiment_1_cs((SFc6_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c6_Experiment_1_cs(void *chartInstanceVar)
{
  enable_c6_Experiment_1_cs((SFc6_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c6_Experiment_1_cs(void *chartInstanceVar)
{
  disable_c6_Experiment_1_cs((SFc6_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c6_Experiment_1_cs(void *chartInstanceVar)
{
  sf_gateway_c6_Experiment_1_cs((SFc6_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c6_Experiment_1_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c6_Experiment_1_cs((SFc6_Experiment_1_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c6_Experiment_1_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c6_Experiment_1_cs((SFc6_Experiment_1_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c6_Experiment_1_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_Experiment_1_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_1_cs_optimization_info();
    }

    finalize_c6_Experiment_1_cs((SFc6_Experiment_1_csInstanceStruct*)
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
  initSimStructsc6_Experiment_1_cs((SFc6_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_Experiment_1_cs(SimStruct *S)
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
    initialize_params_c6_Experiment_1_cs((SFc6_Experiment_1_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_Experiment_1_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Experiment_1_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,6,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,6);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,6,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
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

static void mdlRTW_c6_Experiment_1_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_Experiment_1_cs(SimStruct *S)
{
  SFc6_Experiment_1_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc6_Experiment_1_csInstanceStruct *)utMalloc(sizeof
    (SFc6_Experiment_1_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_Experiment_1_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c6_Experiment_1_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c6_Experiment_1_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c6_Experiment_1_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_Experiment_1_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_Experiment_1_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_Experiment_1_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_Experiment_1_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_Experiment_1_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_Experiment_1_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_Experiment_1_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c6_Experiment_1_cs;
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

void c6_Experiment_1_cs_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_Experiment_1_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_Experiment_1_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_Experiment_1_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_Experiment_1_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
