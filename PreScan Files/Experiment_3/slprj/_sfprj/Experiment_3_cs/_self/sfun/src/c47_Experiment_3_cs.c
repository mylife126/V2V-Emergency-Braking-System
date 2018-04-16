/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_3_cs_sfun.h"
#include "c47_Experiment_3_cs.h"
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
static const char * c47_debug_family_names[8] = { "i", "TISdet", "nargin",
  "nargout", "th", "thp", "thd", "th_dot" };

/* Function Declarations */
static void initialize_c47_Experiment_3_cs(SFc47_Experiment_3_csInstanceStruct
  *chartInstance);
static void initialize_params_c47_Experiment_3_cs
  (SFc47_Experiment_3_csInstanceStruct *chartInstance);
static void enable_c47_Experiment_3_cs(SFc47_Experiment_3_csInstanceStruct
  *chartInstance);
static void disable_c47_Experiment_3_cs(SFc47_Experiment_3_csInstanceStruct
  *chartInstance);
static void c47_update_debugger_state_c47_Experiment_3_cs
  (SFc47_Experiment_3_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c47_Experiment_3_cs
  (SFc47_Experiment_3_csInstanceStruct *chartInstance);
static void set_sim_state_c47_Experiment_3_cs
  (SFc47_Experiment_3_csInstanceStruct *chartInstance, const mxArray *c47_st);
static void finalize_c47_Experiment_3_cs(SFc47_Experiment_3_csInstanceStruct
  *chartInstance);
static void sf_gateway_c47_Experiment_3_cs(SFc47_Experiment_3_csInstanceStruct
  *chartInstance);
static void mdl_start_c47_Experiment_3_cs(SFc47_Experiment_3_csInstanceStruct
  *chartInstance);
static void initSimStructsc47_Experiment_3_cs
  (SFc47_Experiment_3_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c47_machineNumber, uint32_T
  c47_chartNumber, uint32_T c47_instanceNumber);
static const mxArray *c47_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData);
static void c47_emlrt_marshallIn(SFc47_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c47_b_th_dot, const char_T *c47_identifier,
  real_T c47_y[32]);
static void c47_b_emlrt_marshallIn(SFc47_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId,
  real_T c47_y[32]);
static void c47_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData);
static const mxArray *c47_b_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData);
static real_T c47_c_emlrt_marshallIn(SFc47_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId);
static void c47_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData);
static const mxArray *c47_c_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData);
static const mxArray *c47_d_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData);
static int32_T c47_d_emlrt_marshallIn(SFc47_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId);
static void c47_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData);
static void c47_e_emlrt_marshallIn(SFc47_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId,
  real_T c47_y[2]);
static void c47_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData);
static uint8_T c47_f_emlrt_marshallIn(SFc47_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c47_b_is_active_c47_Experiment_3_cs, const
  char_T *c47_identifier);
static uint8_T c47_g_emlrt_marshallIn(SFc47_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId);
static void init_dsm_address_info(SFc47_Experiment_3_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc47_Experiment_3_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c47_Experiment_3_cs(SFc47_Experiment_3_csInstanceStruct
  *chartInstance)
{
  chartInstance->c47_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c47_is_active_c47_Experiment_3_cs = 0U;
}

static void initialize_params_c47_Experiment_3_cs
  (SFc47_Experiment_3_csInstanceStruct *chartInstance)
{
  real_T c47_dv0[2];
  int32_T c47_i0;
  sf_mex_import_named("TISdet", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c47_dv0, 0, 0, 0U, 1, 0U, 2, 1, 2);
  for (c47_i0 = 0; c47_i0 < 2; c47_i0++) {
    chartInstance->c47_TISdet[c47_i0] = c47_dv0[c47_i0];
  }
}

static void enable_c47_Experiment_3_cs(SFc47_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c47_Experiment_3_cs(SFc47_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c47_update_debugger_state_c47_Experiment_3_cs
  (SFc47_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c47_Experiment_3_cs
  (SFc47_Experiment_3_csInstanceStruct *chartInstance)
{
  const mxArray *c47_st;
  const mxArray *c47_y = NULL;
  int32_T c47_i1;
  real_T c47_u[32];
  const mxArray *c47_b_y = NULL;
  uint8_T c47_hoistedGlobal;
  uint8_T c47_b_u;
  const mxArray *c47_c_y = NULL;
  c47_st = NULL;
  c47_st = NULL;
  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_createcellmatrix(2, 1), false);
  for (c47_i1 = 0; c47_i1 < 32; c47_i1++) {
    c47_u[c47_i1] = (*chartInstance->c47_th_dot)[c47_i1];
  }

  c47_b_y = NULL;
  sf_mex_assign(&c47_b_y, sf_mex_create("y", c47_u, 0, 0U, 1U, 0U, 1, 32), false);
  sf_mex_setcell(c47_y, 0, c47_b_y);
  c47_hoistedGlobal = chartInstance->c47_is_active_c47_Experiment_3_cs;
  c47_b_u = c47_hoistedGlobal;
  c47_c_y = NULL;
  sf_mex_assign(&c47_c_y, sf_mex_create("y", &c47_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c47_y, 1, c47_c_y);
  sf_mex_assign(&c47_st, c47_y, false);
  return c47_st;
}

static void set_sim_state_c47_Experiment_3_cs
  (SFc47_Experiment_3_csInstanceStruct *chartInstance, const mxArray *c47_st)
{
  const mxArray *c47_u;
  real_T c47_dv1[32];
  int32_T c47_i2;
  chartInstance->c47_doneDoubleBufferReInit = true;
  c47_u = sf_mex_dup(c47_st);
  c47_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c47_u, 0)),
                       "th_dot", c47_dv1);
  for (c47_i2 = 0; c47_i2 < 32; c47_i2++) {
    (*chartInstance->c47_th_dot)[c47_i2] = c47_dv1[c47_i2];
  }

  chartInstance->c47_is_active_c47_Experiment_3_cs = c47_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c47_u, 1)),
     "is_active_c47_Experiment_3_cs");
  sf_mex_destroy(&c47_u);
  c47_update_debugger_state_c47_Experiment_3_cs(chartInstance);
  sf_mex_destroy(&c47_st);
}

static void finalize_c47_Experiment_3_cs(SFc47_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c47_Experiment_3_cs(SFc47_Experiment_3_csInstanceStruct
  *chartInstance)
{
  int32_T c47_i3;
  int32_T c47_i4;
  int32_T c47_i5;
  int32_T c47_i6;
  real_T c47_b_th[32];
  int32_T c47_i7;
  real_T c47_b_thp[32];
  int32_T c47_i8;
  real_T c47_b_thd[32];
  uint32_T c47_debug_family_var_map[8];
  real_T c47_i;
  real_T c47_c_TISdet[2];
  real_T c47_nargin = 4.0;
  real_T c47_nargout = 1.0;
  real_T c47_b_th_dot[32];
  int32_T c47_i9;
  int32_T c47_i10;
  int32_T c47_b_i;
  real_T c47_d0;
  real_T c47_d1;
  real_T c47_d2;
  real_T c47_d3;
  int32_T c47_i11;
  int32_T c47_i12;
  int32_T c47_i13;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 46U, chartInstance->c47_sfEvent);
  for (c47_i3 = 0; c47_i3 < 32; c47_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c47_th)[c47_i3], 0U);
  }

  for (c47_i4 = 0; c47_i4 < 32; c47_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c47_thp)[c47_i4], 1U);
  }

  for (c47_i5 = 0; c47_i5 < 32; c47_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c47_thd)[c47_i5], 2U);
  }

  chartInstance->c47_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 46U, chartInstance->c47_sfEvent);
  for (c47_i6 = 0; c47_i6 < 32; c47_i6++) {
    c47_b_th[c47_i6] = (*chartInstance->c47_th)[c47_i6];
  }

  for (c47_i7 = 0; c47_i7 < 32; c47_i7++) {
    c47_b_thp[c47_i7] = (*chartInstance->c47_thp)[c47_i7];
  }

  for (c47_i8 = 0; c47_i8 < 32; c47_i8++) {
    c47_b_thd[c47_i8] = (*chartInstance->c47_thd)[c47_i8];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c47_debug_family_names,
    c47_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_i, 0U, c47_b_sf_marshallOut,
    c47_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c47_c_TISdet, 1U, c47_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_nargin, 2U, c47_b_sf_marshallOut,
    c47_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_nargout, 3U, c47_b_sf_marshallOut,
    c47_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c47_b_th, 4U, c47_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c47_b_thp, 5U, c47_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c47_b_thd, 6U, c47_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c47_b_th_dot, 7U, c47_sf_marshallOut,
    c47_sf_marshallIn);
  for (c47_i9 = 0; c47_i9 < 2; c47_i9++) {
    c47_c_TISdet[c47_i9] = 32.0;
  }

  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 5);
  for (c47_i10 = 0; c47_i10 < 32; c47_i10++) {
    c47_b_th_dot[c47_i10] = c47_b_thd[c47_i10];
  }

  _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 6);
  c47_i = 1.0;
  c47_b_i = 0;
  while (c47_b_i < 32) {
    c47_i = 1.0 + (real_T)c47_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 7);
    c47_d0 = c47_b_th[_SFD_EML_ARRAY_BOUNDS_CHECK("th", (int32_T)
      _SFD_INTEGER_CHECK("i", c47_i), 1, 32, 1, 0) - 1];
    guard1 = false;
    guard2 = false;
    guard3 = false;
    if (CV_EML_COND(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c47_d0, 0.0, -1, 0U,
          c47_d0 == 0.0))) {
      c47_d1 = c47_b_thp[_SFD_EML_ARRAY_BOUNDS_CHECK("thp", (int32_T)
        _SFD_INTEGER_CHECK("i", c47_i), 1, 32, 1, 0) - 1];
      if (CV_EML_COND(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c47_d1, 0.0, -1, 1U,
            c47_d1 != 0.0))) {
        guard2 = true;
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }

    if (guard3 == true) {
      c47_d2 = c47_b_th[_SFD_EML_ARRAY_BOUNDS_CHECK("th", (int32_T)
        _SFD_INTEGER_CHECK("i", c47_i), 1, 32, 1, 0) - 1];
      if (CV_EML_COND(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 2, c47_d2, 0.0, -1, 1U,
            c47_d2 != 0.0))) {
        c47_d3 = c47_b_thp[_SFD_EML_ARRAY_BOUNDS_CHECK("thp", (int32_T)
          _SFD_INTEGER_CHECK("i", c47_i), 1, 32, 1, 0) - 1];
        if (CV_EML_COND(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 3, c47_d3, 0.0, -1,
              0U, c47_d3 == 0.0))) {
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
      _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 8);
      c47_b_th_dot[_SFD_EML_ARRAY_BOUNDS_CHECK("th_dot", (int32_T)
        _SFD_INTEGER_CHECK("i", c47_i), 1, 32, 1, 0) - 1] = 0.0;
    }

    if (guard1 == true) {
      CV_EML_MCDC(0, 1, 0, false);
      CV_EML_IF(0, 1, 0, false);
    }

    c47_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, -8);
  _SFD_SYMBOL_SCOPE_POP();
  for (c47_i11 = 0; c47_i11 < 32; c47_i11++) {
    (*chartInstance->c47_th_dot)[c47_i11] = c47_b_th_dot[c47_i11];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 46U, chartInstance->c47_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_3_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c47_i12 = 0; c47_i12 < 32; c47_i12++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c47_th_dot)[c47_i12], 3U);
  }

  for (c47_i13 = 0; c47_i13 < 2; c47_i13++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c47_TISdet[c47_i13], 4U);
  }
}

static void mdl_start_c47_Experiment_3_cs(SFc47_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc47_Experiment_3_cs
  (SFc47_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c47_machineNumber, uint32_T
  c47_chartNumber, uint32_T c47_instanceNumber)
{
  (void)c47_machineNumber;
  (void)c47_chartNumber;
  (void)c47_instanceNumber;
}

static const mxArray *c47_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData)
{
  const mxArray *c47_mxArrayOutData = NULL;
  int32_T c47_i14;
  real_T c47_b_inData[32];
  int32_T c47_i15;
  real_T c47_u[32];
  const mxArray *c47_y = NULL;
  SFc47_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc47_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c47_mxArrayOutData = NULL;
  for (c47_i14 = 0; c47_i14 < 32; c47_i14++) {
    c47_b_inData[c47_i14] = (*(real_T (*)[32])c47_inData)[c47_i14];
  }

  for (c47_i15 = 0; c47_i15 < 32; c47_i15++) {
    c47_u[c47_i15] = c47_b_inData[c47_i15];
  }

  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_create("y", c47_u, 0, 0U, 1U, 0U, 1, 32), false);
  sf_mex_assign(&c47_mxArrayOutData, c47_y, false);
  return c47_mxArrayOutData;
}

static void c47_emlrt_marshallIn(SFc47_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c47_b_th_dot, const char_T *c47_identifier,
  real_T c47_y[32])
{
  emlrtMsgIdentifier c47_thisId;
  c47_thisId.fIdentifier = c47_identifier;
  c47_thisId.fParent = NULL;
  c47_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c47_b_th_dot), &c47_thisId,
    c47_y);
  sf_mex_destroy(&c47_b_th_dot);
}

static void c47_b_emlrt_marshallIn(SFc47_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId,
  real_T c47_y[32])
{
  real_T c47_dv2[32];
  int32_T c47_i16;
  (void)chartInstance;
  sf_mex_import(c47_parentId, sf_mex_dup(c47_u), c47_dv2, 1, 0, 0U, 1, 0U, 1, 32);
  for (c47_i16 = 0; c47_i16 < 32; c47_i16++) {
    c47_y[c47_i16] = c47_dv2[c47_i16];
  }

  sf_mex_destroy(&c47_u);
}

static void c47_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData)
{
  const mxArray *c47_b_th_dot;
  const char_T *c47_identifier;
  emlrtMsgIdentifier c47_thisId;
  real_T c47_y[32];
  int32_T c47_i17;
  SFc47_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc47_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c47_b_th_dot = sf_mex_dup(c47_mxArrayInData);
  c47_identifier = c47_varName;
  c47_thisId.fIdentifier = c47_identifier;
  c47_thisId.fParent = NULL;
  c47_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c47_b_th_dot), &c47_thisId,
    c47_y);
  sf_mex_destroy(&c47_b_th_dot);
  for (c47_i17 = 0; c47_i17 < 32; c47_i17++) {
    (*(real_T (*)[32])c47_outData)[c47_i17] = c47_y[c47_i17];
  }

  sf_mex_destroy(&c47_mxArrayInData);
}

static const mxArray *c47_b_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData)
{
  const mxArray *c47_mxArrayOutData = NULL;
  real_T c47_u;
  const mxArray *c47_y = NULL;
  SFc47_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc47_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c47_mxArrayOutData = NULL;
  c47_u = *(real_T *)c47_inData;
  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_create("y", &c47_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c47_mxArrayOutData, c47_y, false);
  return c47_mxArrayOutData;
}

static real_T c47_c_emlrt_marshallIn(SFc47_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId)
{
  real_T c47_y;
  real_T c47_d4;
  (void)chartInstance;
  sf_mex_import(c47_parentId, sf_mex_dup(c47_u), &c47_d4, 1, 0, 0U, 0, 0U, 0);
  c47_y = c47_d4;
  sf_mex_destroy(&c47_u);
  return c47_y;
}

static void c47_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData)
{
  const mxArray *c47_nargout;
  const char_T *c47_identifier;
  emlrtMsgIdentifier c47_thisId;
  real_T c47_y;
  SFc47_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc47_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c47_nargout = sf_mex_dup(c47_mxArrayInData);
  c47_identifier = c47_varName;
  c47_thisId.fIdentifier = c47_identifier;
  c47_thisId.fParent = NULL;
  c47_y = c47_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c47_nargout),
    &c47_thisId);
  sf_mex_destroy(&c47_nargout);
  *(real_T *)c47_outData = c47_y;
  sf_mex_destroy(&c47_mxArrayInData);
}

static const mxArray *c47_c_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData)
{
  const mxArray *c47_mxArrayOutData = NULL;
  int32_T c47_i18;
  real_T c47_b_inData[2];
  int32_T c47_i19;
  real_T c47_u[2];
  const mxArray *c47_y = NULL;
  SFc47_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc47_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c47_mxArrayOutData = NULL;
  for (c47_i18 = 0; c47_i18 < 2; c47_i18++) {
    c47_b_inData[c47_i18] = (*(real_T (*)[2])c47_inData)[c47_i18];
  }

  for (c47_i19 = 0; c47_i19 < 2; c47_i19++) {
    c47_u[c47_i19] = c47_b_inData[c47_i19];
  }

  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_create("y", c47_u, 0, 0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_assign(&c47_mxArrayOutData, c47_y, false);
  return c47_mxArrayOutData;
}

const mxArray *sf_c47_Experiment_3_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c47_nameCaptureInfo = NULL;
  c47_nameCaptureInfo = NULL;
  sf_mex_assign(&c47_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c47_nameCaptureInfo;
}

static const mxArray *c47_d_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData)
{
  const mxArray *c47_mxArrayOutData = NULL;
  int32_T c47_u;
  const mxArray *c47_y = NULL;
  SFc47_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc47_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c47_mxArrayOutData = NULL;
  c47_u = *(int32_T *)c47_inData;
  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_create("y", &c47_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c47_mxArrayOutData, c47_y, false);
  return c47_mxArrayOutData;
}

static int32_T c47_d_emlrt_marshallIn(SFc47_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId)
{
  int32_T c47_y;
  int32_T c47_i20;
  (void)chartInstance;
  sf_mex_import(c47_parentId, sf_mex_dup(c47_u), &c47_i20, 1, 6, 0U, 0, 0U, 0);
  c47_y = c47_i20;
  sf_mex_destroy(&c47_u);
  return c47_y;
}

static void c47_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData)
{
  const mxArray *c47_b_sfEvent;
  const char_T *c47_identifier;
  emlrtMsgIdentifier c47_thisId;
  int32_T c47_y;
  SFc47_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc47_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c47_b_sfEvent = sf_mex_dup(c47_mxArrayInData);
  c47_identifier = c47_varName;
  c47_thisId.fIdentifier = c47_identifier;
  c47_thisId.fParent = NULL;
  c47_y = c47_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c47_b_sfEvent),
    &c47_thisId);
  sf_mex_destroy(&c47_b_sfEvent);
  *(int32_T *)c47_outData = c47_y;
  sf_mex_destroy(&c47_mxArrayInData);
}

static void c47_e_emlrt_marshallIn(SFc47_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId,
  real_T c47_y[2])
{
  real_T c47_dv3[2];
  int32_T c47_i21;
  (void)chartInstance;
  sf_mex_import(c47_parentId, sf_mex_dup(c47_u), c47_dv3, 1, 0, 0U, 1, 0U, 2, 1,
                2);
  for (c47_i21 = 0; c47_i21 < 2; c47_i21++) {
    c47_y[c47_i21] = c47_dv3[c47_i21];
  }

  sf_mex_destroy(&c47_u);
}

static void c47_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData)
{
  const mxArray *c47_c_TISdet;
  const char_T *c47_identifier;
  emlrtMsgIdentifier c47_thisId;
  real_T c47_y[2];
  int32_T c47_i22;
  SFc47_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc47_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c47_c_TISdet = sf_mex_dup(c47_mxArrayInData);
  c47_identifier = c47_varName;
  c47_thisId.fIdentifier = c47_identifier;
  c47_thisId.fParent = NULL;
  c47_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c47_c_TISdet), &c47_thisId,
    c47_y);
  sf_mex_destroy(&c47_c_TISdet);
  for (c47_i22 = 0; c47_i22 < 2; c47_i22++) {
    (*(real_T (*)[2])c47_outData)[c47_i22] = c47_y[c47_i22];
  }

  sf_mex_destroy(&c47_mxArrayInData);
}

static uint8_T c47_f_emlrt_marshallIn(SFc47_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c47_b_is_active_c47_Experiment_3_cs, const
  char_T *c47_identifier)
{
  uint8_T c47_y;
  emlrtMsgIdentifier c47_thisId;
  c47_thisId.fIdentifier = c47_identifier;
  c47_thisId.fParent = NULL;
  c47_y = c47_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c47_b_is_active_c47_Experiment_3_cs), &c47_thisId);
  sf_mex_destroy(&c47_b_is_active_c47_Experiment_3_cs);
  return c47_y;
}

static uint8_T c47_g_emlrt_marshallIn(SFc47_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId)
{
  uint8_T c47_y;
  uint8_T c47_u0;
  (void)chartInstance;
  sf_mex_import(c47_parentId, sf_mex_dup(c47_u), &c47_u0, 1, 3, 0U, 0, 0U, 0);
  c47_y = c47_u0;
  sf_mex_destroy(&c47_u);
  return c47_y;
}

static void init_dsm_address_info(SFc47_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc47_Experiment_3_csInstanceStruct
  *chartInstance)
{
  chartInstance->c47_th = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c47_thp = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c47_thd = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c47_th_dot = (real_T (*)[32])ssGetOutputPortSignal_wrapper
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

void sf_c47_Experiment_3_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1952934539U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2193303464U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3624894572U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2980648698U);
}

mxArray* sf_c47_Experiment_3_cs_get_post_codegen_info(void);
mxArray *sf_c47_Experiment_3_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("YKiDtM2flIYkUOX03jsbTH");
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
    mxArray* mxPostCodegenInfo = sf_c47_Experiment_3_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c47_Experiment_3_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c47_Experiment_3_cs_jit_fallback_info(void)
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

mxArray *sf_c47_Experiment_3_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c47_Experiment_3_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c47_Experiment_3_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"th_dot\",},{M[8],M[0],T\"is_active_c47_Experiment_3_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c47_Experiment_3_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc47_Experiment_3_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc47_Experiment_3_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_3_csMachineNumber_,
           47,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,227);
        _SFD_CV_INIT_EML_IF(0,1,0,135,188,-1,219);
        _SFD_CV_INIT_EML_FOR(0,1,0,109,131,223);

        {
          static int condStart[] = { 139, 151, 166, 178 };

          static int condEnd[] = { 147, 160, 174, 187 };

          static int pfixExpr[] = { 0, 1, -3, 2, 3, -3, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,138,188,4,0,&(condStart[0]),&(condEnd[0]),
                                7,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,139,147,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,151,160,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,166,174,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,178,187,-1,0);

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)
            c47_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c47_c_sf_marshallOut,(MexInFcnForType)
            c47_d_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c47_th);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c47_thp);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c47_thd);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c47_th_dot);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c47_TISdet);
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
  return "mbxzSPGpytzAEntsC5EprD";
}

static void sf_opaque_initialize_c47_Experiment_3_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc47_Experiment_3_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c47_Experiment_3_cs((SFc47_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
  initialize_c47_Experiment_3_cs((SFc47_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c47_Experiment_3_cs(void *chartInstanceVar)
{
  enable_c47_Experiment_3_cs((SFc47_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c47_Experiment_3_cs(void *chartInstanceVar)
{
  disable_c47_Experiment_3_cs((SFc47_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c47_Experiment_3_cs(void *chartInstanceVar)
{
  sf_gateway_c47_Experiment_3_cs((SFc47_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c47_Experiment_3_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c47_Experiment_3_cs((SFc47_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c47_Experiment_3_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c47_Experiment_3_cs((SFc47_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c47_Experiment_3_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc47_Experiment_3_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_3_cs_optimization_info();
    }

    finalize_c47_Experiment_3_cs((SFc47_Experiment_3_csInstanceStruct*)
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
  initSimStructsc47_Experiment_3_cs((SFc47_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c47_Experiment_3_cs(SimStruct *S)
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
    initialize_params_c47_Experiment_3_cs((SFc47_Experiment_3_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c47_Experiment_3_cs(SimStruct *S)
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
      47);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,47,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,47,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,47);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,47,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,47,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,47);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1058031198U));
  ssSetChecksum1(S,(1032238966U));
  ssSetChecksum2(S,(3495681797U));
  ssSetChecksum3(S,(371548065U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c47_Experiment_3_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c47_Experiment_3_cs(SimStruct *S)
{
  SFc47_Experiment_3_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc47_Experiment_3_csInstanceStruct *)utMalloc(sizeof
    (SFc47_Experiment_3_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc47_Experiment_3_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c47_Experiment_3_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c47_Experiment_3_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c47_Experiment_3_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c47_Experiment_3_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c47_Experiment_3_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c47_Experiment_3_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c47_Experiment_3_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c47_Experiment_3_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c47_Experiment_3_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c47_Experiment_3_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c47_Experiment_3_cs;
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

void c47_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c47_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c47_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c47_Experiment_3_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c47_Experiment_3_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
