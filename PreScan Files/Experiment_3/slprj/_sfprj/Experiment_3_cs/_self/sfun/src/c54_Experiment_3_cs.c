/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_3_cs_sfun.h"
#include "c54_Experiment_3_cs.h"
#include "mwmathutil.h"
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
static const char * c54_debug_family_names[9] = { "size", "i", "j", "TISdet",
  "nargin", "nargout", "indxp", "range", "indx" };

/* Function Declarations */
static void initialize_c54_Experiment_3_cs(SFc54_Experiment_3_csInstanceStruct
  *chartInstance);
static void initialize_params_c54_Experiment_3_cs
  (SFc54_Experiment_3_csInstanceStruct *chartInstance);
static void enable_c54_Experiment_3_cs(SFc54_Experiment_3_csInstanceStruct
  *chartInstance);
static void disable_c54_Experiment_3_cs(SFc54_Experiment_3_csInstanceStruct
  *chartInstance);
static void c54_update_debugger_state_c54_Experiment_3_cs
  (SFc54_Experiment_3_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c54_Experiment_3_cs
  (SFc54_Experiment_3_csInstanceStruct *chartInstance);
static void set_sim_state_c54_Experiment_3_cs
  (SFc54_Experiment_3_csInstanceStruct *chartInstance, const mxArray *c54_st);
static void finalize_c54_Experiment_3_cs(SFc54_Experiment_3_csInstanceStruct
  *chartInstance);
static void sf_gateway_c54_Experiment_3_cs(SFc54_Experiment_3_csInstanceStruct
  *chartInstance);
static void mdl_start_c54_Experiment_3_cs(SFc54_Experiment_3_csInstanceStruct
  *chartInstance);
static void initSimStructsc54_Experiment_3_cs
  (SFc54_Experiment_3_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c54_machineNumber, uint32_T
  c54_chartNumber, uint32_T c54_instanceNumber);
static const mxArray *c54_sf_marshallOut(void *chartInstanceVoid, void
  *c54_inData);
static void c54_emlrt_marshallIn(SFc54_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c54_b_indx, const char_T *c54_identifier,
  real_T c54_y[32]);
static void c54_b_emlrt_marshallIn(SFc54_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c54_u, const emlrtMsgIdentifier *c54_parentId,
  real_T c54_y[32]);
static void c54_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c54_mxArrayInData, const char_T *c54_varName, void *c54_outData);
static const mxArray *c54_b_sf_marshallOut(void *chartInstanceVoid, void
  *c54_inData);
static real_T c54_c_emlrt_marshallIn(SFc54_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c54_u, const emlrtMsgIdentifier *c54_parentId);
static void c54_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c54_mxArrayInData, const char_T *c54_varName, void *c54_outData);
static const mxArray *c54_c_sf_marshallOut(void *chartInstanceVoid, void
  *c54_inData);
static void c54_info_helper(const mxArray **c54_info);
static const mxArray *c54_emlrt_marshallOut(const char * c54_u);
static const mxArray *c54_b_emlrt_marshallOut(const uint32_T c54_u);
static const mxArray *c54_d_sf_marshallOut(void *chartInstanceVoid, void
  *c54_inData);
static int32_T c54_d_emlrt_marshallIn(SFc54_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c54_u, const emlrtMsgIdentifier *c54_parentId);
static void c54_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c54_mxArrayInData, const char_T *c54_varName, void *c54_outData);
static void c54_e_emlrt_marshallIn(SFc54_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c54_u, const emlrtMsgIdentifier *c54_parentId,
  real_T c54_y[2]);
static void c54_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c54_mxArrayInData, const char_T *c54_varName, void *c54_outData);
static uint8_T c54_f_emlrt_marshallIn(SFc54_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c54_b_is_active_c54_Experiment_3_cs, const
  char_T *c54_identifier);
static uint8_T c54_g_emlrt_marshallIn(SFc54_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c54_u, const emlrtMsgIdentifier *c54_parentId);
static void init_dsm_address_info(SFc54_Experiment_3_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc54_Experiment_3_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c54_Experiment_3_cs(SFc54_Experiment_3_csInstanceStruct
  *chartInstance)
{
  chartInstance->c54_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c54_is_active_c54_Experiment_3_cs = 0U;
}

static void initialize_params_c54_Experiment_3_cs
  (SFc54_Experiment_3_csInstanceStruct *chartInstance)
{
  real_T c54_dv0[2];
  int32_T c54_i0;
  sf_mex_import_named("TISdet", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c54_dv0, 0, 0, 0U, 1, 0U, 2, 1, 2);
  for (c54_i0 = 0; c54_i0 < 2; c54_i0++) {
    chartInstance->c54_TISdet[c54_i0] = c54_dv0[c54_i0];
  }
}

static void enable_c54_Experiment_3_cs(SFc54_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c54_Experiment_3_cs(SFc54_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c54_update_debugger_state_c54_Experiment_3_cs
  (SFc54_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c54_Experiment_3_cs
  (SFc54_Experiment_3_csInstanceStruct *chartInstance)
{
  const mxArray *c54_st;
  const mxArray *c54_y = NULL;
  int32_T c54_i1;
  real_T c54_u[32];
  const mxArray *c54_b_y = NULL;
  uint8_T c54_hoistedGlobal;
  uint8_T c54_b_u;
  const mxArray *c54_c_y = NULL;
  c54_st = NULL;
  c54_st = NULL;
  c54_y = NULL;
  sf_mex_assign(&c54_y, sf_mex_createcellmatrix(2, 1), false);
  for (c54_i1 = 0; c54_i1 < 32; c54_i1++) {
    c54_u[c54_i1] = (*chartInstance->c54_indx)[c54_i1];
  }

  c54_b_y = NULL;
  sf_mex_assign(&c54_b_y, sf_mex_create("y", c54_u, 0, 0U, 1U, 0U, 1, 32), false);
  sf_mex_setcell(c54_y, 0, c54_b_y);
  c54_hoistedGlobal = chartInstance->c54_is_active_c54_Experiment_3_cs;
  c54_b_u = c54_hoistedGlobal;
  c54_c_y = NULL;
  sf_mex_assign(&c54_c_y, sf_mex_create("y", &c54_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c54_y, 1, c54_c_y);
  sf_mex_assign(&c54_st, c54_y, false);
  return c54_st;
}

static void set_sim_state_c54_Experiment_3_cs
  (SFc54_Experiment_3_csInstanceStruct *chartInstance, const mxArray *c54_st)
{
  const mxArray *c54_u;
  real_T c54_dv1[32];
  int32_T c54_i2;
  chartInstance->c54_doneDoubleBufferReInit = true;
  c54_u = sf_mex_dup(c54_st);
  c54_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c54_u, 0)),
                       "indx", c54_dv1);
  for (c54_i2 = 0; c54_i2 < 32; c54_i2++) {
    (*chartInstance->c54_indx)[c54_i2] = c54_dv1[c54_i2];
  }

  chartInstance->c54_is_active_c54_Experiment_3_cs = c54_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c54_u, 1)),
     "is_active_c54_Experiment_3_cs");
  sf_mex_destroy(&c54_u);
  c54_update_debugger_state_c54_Experiment_3_cs(chartInstance);
  sf_mex_destroy(&c54_st);
}

static void finalize_c54_Experiment_3_cs(SFc54_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c54_Experiment_3_cs(SFc54_Experiment_3_csInstanceStruct
  *chartInstance)
{
  int32_T c54_i3;
  int32_T c54_i4;
  real_T c54_b_indxp[32];
  int32_T c54_i5;
  real_T c54_b_range[32];
  uint32_T c54_debug_family_var_map[9];
  real_T c54_size;
  real_T c54_i;
  real_T c54_j;
  real_T c54_c_TISdet[2];
  real_T c54_nargin = 3.0;
  real_T c54_nargout = 1.0;
  real_T c54_b_indx[32];
  int32_T c54_i6;
  int32_T c54_i7;
  int32_T c54_b_i;
  real_T c54_d0;
  real_T c54_d1;
  int32_T c54_c_i;
  real_T c54_d2;
  int32_T c54_d_i;
  real_T c54_d3;
  int32_T c54_i8;
  real_T c54_x[32];
  int32_T c54_i9;
  int32_T c54_k;
  real_T c54_b_k;
  real_T c54_b_x;
  real_T c54_c_x;
  int32_T c54_i10;
  int32_T c54_i11;
  int32_T c54_i12;
  int32_T c54_i13;
  boolean_T guard1 = false;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 53U, chartInstance->c54_sfEvent);
  for (c54_i3 = 0; c54_i3 < 32; c54_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c54_indxp)[c54_i3], 0U);
  }

  chartInstance->c54_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 53U, chartInstance->c54_sfEvent);
  for (c54_i4 = 0; c54_i4 < 32; c54_i4++) {
    c54_b_indxp[c54_i4] = (*chartInstance->c54_indxp)[c54_i4];
  }

  for (c54_i5 = 0; c54_i5 < 32; c54_i5++) {
    c54_b_range[c54_i5] = (*chartInstance->c54_range)[c54_i5];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c54_debug_family_names,
    c54_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c54_size, 0U, c54_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c54_i, 1U, c54_b_sf_marshallOut,
    c54_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c54_j, 2U, c54_b_sf_marshallOut,
    c54_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c54_c_TISdet, 3U, c54_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c54_nargin, 4U, c54_b_sf_marshallOut,
    c54_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c54_nargout, 5U, c54_b_sf_marshallOut,
    c54_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c54_b_indxp, 6U, c54_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c54_b_range, 7U, c54_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c54_b_indx, 8U, c54_sf_marshallOut,
    c54_sf_marshallIn);
  for (c54_i6 = 0; c54_i6 < 2; c54_i6++) {
    c54_c_TISdet[c54_i6] = 32.0;
  }

  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c54_sfEvent, 4);
  c54_size = 32.0;
  _SFD_EML_CALL(0U, chartInstance->c54_sfEvent, 6);
  for (c54_i7 = 0; c54_i7 < 32; c54_i7++) {
    c54_b_indx[c54_i7] = c54_b_indxp[c54_i7];
  }

  _SFD_EML_CALL(0U, chartInstance->c54_sfEvent, 8);
  c54_i = 1.0;
  c54_b_i = 0;
  while (c54_b_i < 32) {
    c54_i = 1.0 + (real_T)c54_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c54_sfEvent, 9);
    c54_d0 = c54_b_indx[_SFD_EML_ARRAY_BOUNDS_CHECK("indx", (int32_T)
      _SFD_INTEGER_CHECK("i", c54_i), 1, 32, 1, 0) - 1];
    guard1 = false;
    if (CV_EML_COND(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c54_d0, 0.0, -1, 1U,
          c54_d0 != 0.0))) {
      c54_d1 = c54_b_range[_SFD_EML_ARRAY_BOUNDS_CHECK("range", (int32_T)
        _SFD_INTEGER_CHECK("i", c54_i), 1, 32, 1, 0) - 1];
      if (CV_EML_COND(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c54_d1, 0.0, -1, 0U,
            c54_d1 == 0.0))) {
        CV_EML_MCDC(0, 1, 0, true);
        CV_EML_IF(0, 1, 0, true);
        _SFD_EML_CALL(0U, chartInstance->c54_sfEvent, 10);
        c54_b_indx[_SFD_EML_ARRAY_BOUNDS_CHECK("indx", (int32_T)
          _SFD_INTEGER_CHECK("i", c54_i), 1, 32, 1, 0) - 1] = 0.0;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(0, 1, 0, false);
      CV_EML_IF(0, 1, 0, false);
    }

    c54_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c54_sfEvent, 14);
  c54_i = 1.0;
  c54_c_i = 0;
  while (c54_c_i < 32) {
    c54_i = 1.0 + (real_T)c54_c_i;
    CV_EML_FOR(0, 1, 1, 1);
    _SFD_EML_CALL(0U, chartInstance->c54_sfEvent, 15);
    c54_d2 = c54_b_indx[_SFD_EML_ARRAY_BOUNDS_CHECK("indx", (int32_T)
      _SFD_INTEGER_CHECK("i", c54_i), 1, 32, 1, 0) - 1];
    if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 2, c54_d2, 0.0, -1, 1U,
          c54_d2 != 0.0))) {
      _SFD_EML_CALL(0U, chartInstance->c54_sfEvent, 16);
      c54_b_range[_SFD_EML_ARRAY_BOUNDS_CHECK("range", (int32_T)
        _SFD_INTEGER_CHECK("i", c54_i), 1, 32, 1, 0) - 1] = 0.0;
    }

    c54_c_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 1, 0);
  _SFD_EML_CALL(0U, chartInstance->c54_sfEvent, 20);
  c54_i = 1.0;
  c54_d_i = 0;
  while (c54_d_i < 32) {
    c54_i = 1.0 + (real_T)c54_d_i;
    CV_EML_FOR(0, 1, 2, 1);
    _SFD_EML_CALL(0U, chartInstance->c54_sfEvent, 21);
    c54_d3 = c54_b_range[_SFD_EML_ARRAY_BOUNDS_CHECK("range", (int32_T)
      _SFD_INTEGER_CHECK("i", c54_i), 1, 32, 1, 0) - 1];
    if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 3, c54_d3, 0.0, -1, 1U,
          c54_d3 != 0.0))) {
      _SFD_EML_CALL(0U, chartInstance->c54_sfEvent, 22);
      c54_j = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c54_sfEvent, 23);
      while (CV_EML_WHILE(0, 1, 0, c54_b_indx[_SFD_EML_ARRAY_BOUNDS_CHECK("indx",
               (int32_T)_SFD_INTEGER_CHECK("j", c54_j), 1, 32, 1, 0) - 1] != 0.0)
             != 0.0) {
        _SFD_EML_CALL(0U, chartInstance->c54_sfEvent, 24);
        c54_j++;
        _SFD_EML_CALL(0U, chartInstance->c54_sfEvent, 23);
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      _SFD_EML_CALL(0U, chartInstance->c54_sfEvent, 26);
      if (CV_EML_IF(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 4, c54_j, c54_size, -1,
            1U, c54_j != c54_size))) {
        _SFD_EML_CALL(0U, chartInstance->c54_sfEvent, 27);
        c54_b_indx[_SFD_EML_ARRAY_BOUNDS_CHECK("indx", (int32_T)
          _SFD_INTEGER_CHECK("j", c54_j), 1, 32, 1, 0) - 1] = c54_i;
      }
    }

    c54_d_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 2, 0);
  _SFD_EML_CALL(0U, chartInstance->c54_sfEvent, 31);
  for (c54_i8 = 0; c54_i8 < 32; c54_i8++) {
    c54_x[c54_i8] = c54_b_indx[c54_i8];
  }

  for (c54_i9 = 0; c54_i9 < 32; c54_i9++) {
    c54_b_indx[c54_i9] = c54_x[c54_i9];
  }

  for (c54_k = 0; c54_k < 32; c54_k++) {
    c54_b_k = 1.0 + (real_T)c54_k;
    c54_b_x = c54_b_indx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c54_b_k), 1, 32, 1, 0) - 1];
    c54_c_x = c54_b_x;
    c54_c_x = muDoubleScalarRound(c54_c_x);
    c54_b_indx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c54_b_k), 1, 32, 1, 0) - 1] = c54_c_x;
  }

  _SFD_EML_CALL(0U, chartInstance->c54_sfEvent, -31);
  _SFD_SYMBOL_SCOPE_POP();
  for (c54_i10 = 0; c54_i10 < 32; c54_i10++) {
    (*chartInstance->c54_indx)[c54_i10] = c54_b_indx[c54_i10];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 53U, chartInstance->c54_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_3_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c54_i11 = 0; c54_i11 < 32; c54_i11++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c54_indx)[c54_i11], 1U);
  }

  for (c54_i12 = 0; c54_i12 < 32; c54_i12++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c54_range)[c54_i12], 2U);
  }

  for (c54_i13 = 0; c54_i13 < 2; c54_i13++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c54_TISdet[c54_i13], 3U);
  }
}

static void mdl_start_c54_Experiment_3_cs(SFc54_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc54_Experiment_3_cs
  (SFc54_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c54_machineNumber, uint32_T
  c54_chartNumber, uint32_T c54_instanceNumber)
{
  (void)c54_machineNumber;
  (void)c54_chartNumber;
  (void)c54_instanceNumber;
}

static const mxArray *c54_sf_marshallOut(void *chartInstanceVoid, void
  *c54_inData)
{
  const mxArray *c54_mxArrayOutData = NULL;
  int32_T c54_i14;
  real_T c54_b_inData[32];
  int32_T c54_i15;
  real_T c54_u[32];
  const mxArray *c54_y = NULL;
  SFc54_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc54_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c54_mxArrayOutData = NULL;
  for (c54_i14 = 0; c54_i14 < 32; c54_i14++) {
    c54_b_inData[c54_i14] = (*(real_T (*)[32])c54_inData)[c54_i14];
  }

  for (c54_i15 = 0; c54_i15 < 32; c54_i15++) {
    c54_u[c54_i15] = c54_b_inData[c54_i15];
  }

  c54_y = NULL;
  sf_mex_assign(&c54_y, sf_mex_create("y", c54_u, 0, 0U, 1U, 0U, 1, 32), false);
  sf_mex_assign(&c54_mxArrayOutData, c54_y, false);
  return c54_mxArrayOutData;
}

static void c54_emlrt_marshallIn(SFc54_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c54_b_indx, const char_T *c54_identifier,
  real_T c54_y[32])
{
  emlrtMsgIdentifier c54_thisId;
  c54_thisId.fIdentifier = c54_identifier;
  c54_thisId.fParent = NULL;
  c54_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c54_b_indx), &c54_thisId,
    c54_y);
  sf_mex_destroy(&c54_b_indx);
}

static void c54_b_emlrt_marshallIn(SFc54_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c54_u, const emlrtMsgIdentifier *c54_parentId,
  real_T c54_y[32])
{
  real_T c54_dv2[32];
  int32_T c54_i16;
  (void)chartInstance;
  sf_mex_import(c54_parentId, sf_mex_dup(c54_u), c54_dv2, 1, 0, 0U, 1, 0U, 1, 32);
  for (c54_i16 = 0; c54_i16 < 32; c54_i16++) {
    c54_y[c54_i16] = c54_dv2[c54_i16];
  }

  sf_mex_destroy(&c54_u);
}

static void c54_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c54_mxArrayInData, const char_T *c54_varName, void *c54_outData)
{
  const mxArray *c54_b_indx;
  const char_T *c54_identifier;
  emlrtMsgIdentifier c54_thisId;
  real_T c54_y[32];
  int32_T c54_i17;
  SFc54_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc54_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c54_b_indx = sf_mex_dup(c54_mxArrayInData);
  c54_identifier = c54_varName;
  c54_thisId.fIdentifier = c54_identifier;
  c54_thisId.fParent = NULL;
  c54_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c54_b_indx), &c54_thisId,
    c54_y);
  sf_mex_destroy(&c54_b_indx);
  for (c54_i17 = 0; c54_i17 < 32; c54_i17++) {
    (*(real_T (*)[32])c54_outData)[c54_i17] = c54_y[c54_i17];
  }

  sf_mex_destroy(&c54_mxArrayInData);
}

static const mxArray *c54_b_sf_marshallOut(void *chartInstanceVoid, void
  *c54_inData)
{
  const mxArray *c54_mxArrayOutData = NULL;
  real_T c54_u;
  const mxArray *c54_y = NULL;
  SFc54_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc54_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c54_mxArrayOutData = NULL;
  c54_u = *(real_T *)c54_inData;
  c54_y = NULL;
  sf_mex_assign(&c54_y, sf_mex_create("y", &c54_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c54_mxArrayOutData, c54_y, false);
  return c54_mxArrayOutData;
}

static real_T c54_c_emlrt_marshallIn(SFc54_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c54_u, const emlrtMsgIdentifier *c54_parentId)
{
  real_T c54_y;
  real_T c54_d4;
  (void)chartInstance;
  sf_mex_import(c54_parentId, sf_mex_dup(c54_u), &c54_d4, 1, 0, 0U, 0, 0U, 0);
  c54_y = c54_d4;
  sf_mex_destroy(&c54_u);
  return c54_y;
}

static void c54_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c54_mxArrayInData, const char_T *c54_varName, void *c54_outData)
{
  const mxArray *c54_nargout;
  const char_T *c54_identifier;
  emlrtMsgIdentifier c54_thisId;
  real_T c54_y;
  SFc54_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc54_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c54_nargout = sf_mex_dup(c54_mxArrayInData);
  c54_identifier = c54_varName;
  c54_thisId.fIdentifier = c54_identifier;
  c54_thisId.fParent = NULL;
  c54_y = c54_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c54_nargout),
    &c54_thisId);
  sf_mex_destroy(&c54_nargout);
  *(real_T *)c54_outData = c54_y;
  sf_mex_destroy(&c54_mxArrayInData);
}

static const mxArray *c54_c_sf_marshallOut(void *chartInstanceVoid, void
  *c54_inData)
{
  const mxArray *c54_mxArrayOutData = NULL;
  int32_T c54_i18;
  real_T c54_b_inData[2];
  int32_T c54_i19;
  real_T c54_u[2];
  const mxArray *c54_y = NULL;
  SFc54_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc54_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c54_mxArrayOutData = NULL;
  for (c54_i18 = 0; c54_i18 < 2; c54_i18++) {
    c54_b_inData[c54_i18] = (*(real_T (*)[2])c54_inData)[c54_i18];
  }

  for (c54_i19 = 0; c54_i19 < 2; c54_i19++) {
    c54_u[c54_i19] = c54_b_inData[c54_i19];
  }

  c54_y = NULL;
  sf_mex_assign(&c54_y, sf_mex_create("y", c54_u, 0, 0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_assign(&c54_mxArrayOutData, c54_y, false);
  return c54_mxArrayOutData;
}

const mxArray *sf_c54_Experiment_3_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c54_nameCaptureInfo = NULL;
  c54_nameCaptureInfo = NULL;
  sf_mex_assign(&c54_nameCaptureInfo, sf_mex_createstruct("structure", 2, 3, 1),
                false);
  c54_info_helper(&c54_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c54_nameCaptureInfo);
  return c54_nameCaptureInfo;
}

static void c54_info_helper(const mxArray **c54_info)
{
  const mxArray *c54_rhs0 = NULL;
  const mxArray *c54_lhs0 = NULL;
  const mxArray *c54_rhs1 = NULL;
  const mxArray *c54_lhs1 = NULL;
  const mxArray *c54_rhs2 = NULL;
  const mxArray *c54_lhs2 = NULL;
  sf_mex_addfield(*c54_info, c54_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c54_info, c54_emlrt_marshallOut("round"), "name", "name", 0);
  sf_mex_addfield(*c54_info, c54_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c54_info, c54_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c54_info, c54_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c54_info, c54_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c54_info, c54_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c54_info, c54_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c54_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c54_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c54_info, sf_mex_duplicatearraysafe(&c54_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c54_info, sf_mex_duplicatearraysafe(&c54_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c54_info, c54_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c54_info, c54_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c54_info, c54_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c54_info, c54_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c54_info, c54_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c54_info, c54_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c54_info, c54_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c54_info, c54_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c54_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c54_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c54_info, sf_mex_duplicatearraysafe(&c54_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c54_info, sf_mex_duplicatearraysafe(&c54_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c54_info, c54_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c54_info, c54_emlrt_marshallOut("eml_scalar_round"), "name",
                  "name", 2);
  sf_mex_addfield(*c54_info, c54_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c54_info, c54_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c54_info, c54_b_emlrt_marshallOut(1307672838U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c54_info, c54_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c54_info, c54_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c54_info, c54_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c54_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c54_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c54_info, sf_mex_duplicatearraysafe(&c54_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c54_info, sf_mex_duplicatearraysafe(&c54_lhs2), "lhs", "lhs",
                  2);
  sf_mex_destroy(&c54_rhs0);
  sf_mex_destroy(&c54_lhs0);
  sf_mex_destroy(&c54_rhs1);
  sf_mex_destroy(&c54_lhs1);
  sf_mex_destroy(&c54_rhs2);
  sf_mex_destroy(&c54_lhs2);
}

static const mxArray *c54_emlrt_marshallOut(const char * c54_u)
{
  const mxArray *c54_y = NULL;
  c54_y = NULL;
  sf_mex_assign(&c54_y, sf_mex_create("y", c54_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c54_u)), false);
  return c54_y;
}

static const mxArray *c54_b_emlrt_marshallOut(const uint32_T c54_u)
{
  const mxArray *c54_y = NULL;
  c54_y = NULL;
  sf_mex_assign(&c54_y, sf_mex_create("y", &c54_u, 7, 0U, 0U, 0U, 0), false);
  return c54_y;
}

static const mxArray *c54_d_sf_marshallOut(void *chartInstanceVoid, void
  *c54_inData)
{
  const mxArray *c54_mxArrayOutData = NULL;
  int32_T c54_u;
  const mxArray *c54_y = NULL;
  SFc54_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc54_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c54_mxArrayOutData = NULL;
  c54_u = *(int32_T *)c54_inData;
  c54_y = NULL;
  sf_mex_assign(&c54_y, sf_mex_create("y", &c54_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c54_mxArrayOutData, c54_y, false);
  return c54_mxArrayOutData;
}

static int32_T c54_d_emlrt_marshallIn(SFc54_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c54_u, const emlrtMsgIdentifier *c54_parentId)
{
  int32_T c54_y;
  int32_T c54_i20;
  (void)chartInstance;
  sf_mex_import(c54_parentId, sf_mex_dup(c54_u), &c54_i20, 1, 6, 0U, 0, 0U, 0);
  c54_y = c54_i20;
  sf_mex_destroy(&c54_u);
  return c54_y;
}

static void c54_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c54_mxArrayInData, const char_T *c54_varName, void *c54_outData)
{
  const mxArray *c54_b_sfEvent;
  const char_T *c54_identifier;
  emlrtMsgIdentifier c54_thisId;
  int32_T c54_y;
  SFc54_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc54_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c54_b_sfEvent = sf_mex_dup(c54_mxArrayInData);
  c54_identifier = c54_varName;
  c54_thisId.fIdentifier = c54_identifier;
  c54_thisId.fParent = NULL;
  c54_y = c54_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c54_b_sfEvent),
    &c54_thisId);
  sf_mex_destroy(&c54_b_sfEvent);
  *(int32_T *)c54_outData = c54_y;
  sf_mex_destroy(&c54_mxArrayInData);
}

static void c54_e_emlrt_marshallIn(SFc54_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c54_u, const emlrtMsgIdentifier *c54_parentId,
  real_T c54_y[2])
{
  real_T c54_dv3[2];
  int32_T c54_i21;
  (void)chartInstance;
  sf_mex_import(c54_parentId, sf_mex_dup(c54_u), c54_dv3, 1, 0, 0U, 1, 0U, 2, 1,
                2);
  for (c54_i21 = 0; c54_i21 < 2; c54_i21++) {
    c54_y[c54_i21] = c54_dv3[c54_i21];
  }

  sf_mex_destroy(&c54_u);
}

static void c54_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c54_mxArrayInData, const char_T *c54_varName, void *c54_outData)
{
  const mxArray *c54_c_TISdet;
  const char_T *c54_identifier;
  emlrtMsgIdentifier c54_thisId;
  real_T c54_y[2];
  int32_T c54_i22;
  SFc54_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc54_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c54_c_TISdet = sf_mex_dup(c54_mxArrayInData);
  c54_identifier = c54_varName;
  c54_thisId.fIdentifier = c54_identifier;
  c54_thisId.fParent = NULL;
  c54_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c54_c_TISdet), &c54_thisId,
    c54_y);
  sf_mex_destroy(&c54_c_TISdet);
  for (c54_i22 = 0; c54_i22 < 2; c54_i22++) {
    (*(real_T (*)[2])c54_outData)[c54_i22] = c54_y[c54_i22];
  }

  sf_mex_destroy(&c54_mxArrayInData);
}

static uint8_T c54_f_emlrt_marshallIn(SFc54_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c54_b_is_active_c54_Experiment_3_cs, const
  char_T *c54_identifier)
{
  uint8_T c54_y;
  emlrtMsgIdentifier c54_thisId;
  c54_thisId.fIdentifier = c54_identifier;
  c54_thisId.fParent = NULL;
  c54_y = c54_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c54_b_is_active_c54_Experiment_3_cs), &c54_thisId);
  sf_mex_destroy(&c54_b_is_active_c54_Experiment_3_cs);
  return c54_y;
}

static uint8_T c54_g_emlrt_marshallIn(SFc54_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c54_u, const emlrtMsgIdentifier *c54_parentId)
{
  uint8_T c54_y;
  uint8_T c54_u0;
  (void)chartInstance;
  sf_mex_import(c54_parentId, sf_mex_dup(c54_u), &c54_u0, 1, 3, 0U, 0, 0U, 0);
  c54_y = c54_u0;
  sf_mex_destroy(&c54_u);
  return c54_y;
}

static void init_dsm_address_info(SFc54_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc54_Experiment_3_csInstanceStruct
  *chartInstance)
{
  chartInstance->c54_indxp = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c54_indx = (real_T (*)[32])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c54_range = (real_T (*)[32])ssGetInputPortSignal_wrapper
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

void sf_c54_Experiment_3_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4262247074U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2424708295U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3744868935U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3858030446U);
}

mxArray* sf_c54_Experiment_3_cs_get_post_codegen_info(void);
mxArray *sf_c54_Experiment_3_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("rI3Ob186RYpCLTQKrfQTgH");
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
    mxArray* mxPostCodegenInfo = sf_c54_Experiment_3_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c54_Experiment_3_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c54_Experiment_3_cs_jit_fallback_info(void)
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

mxArray *sf_c54_Experiment_3_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c54_Experiment_3_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c54_Experiment_3_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"indx\",},{M[8],M[0],T\"is_active_c54_Experiment_3_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c54_Experiment_3_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc54_Experiment_3_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc54_Experiment_3_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_3_csMachineNumber_,
           54,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"indxp");
          _SFD_SET_DATA_PROPS(1,2,0,1,"indx");
          _SFD_SET_DATA_PROPS(2,1,1,0,"range");
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
        _SFD_CV_INIT_EML(0,1,1,4,0,0,0,3,1,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,455);
        _SFD_CV_INIT_EML_IF(0,1,0,110,149,-1,178);
        _SFD_CV_INIT_EML_IF(0,1,1,205,220,-1,250);
        _SFD_CV_INIT_EML_IF(0,1,2,277,293,-1,427);
        _SFD_CV_INIT_EML_IF(0,1,3,372,384,-1,419);
        _SFD_CV_INIT_EML_FOR(0,1,0,89,106,182);
        _SFD_CV_INIT_EML_FOR(0,1,1,184,201,254);
        _SFD_CV_INIT_EML_FOR(0,1,2,256,273,431);
        _SFD_CV_INIT_EML_WHILE(0,1,0,315,330,364);

        {
          static int condStart[] = { 115, 135 };

          static int condEnd[] = { 127, 148 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,113,149,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,115,127,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,135,148,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,208,220,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,280,293,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,4,375,384,-1,1);

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c54_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c54_sf_marshallOut,(MexInFcnForType)
            c54_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c54_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c54_c_sf_marshallOut,(MexInFcnForType)
            c54_d_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c54_indxp);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c54_indx);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c54_range);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c54_TISdet);
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
  return "ON8alw89hymIwU7W9zoFcD";
}

static void sf_opaque_initialize_c54_Experiment_3_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc54_Experiment_3_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c54_Experiment_3_cs((SFc54_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
  initialize_c54_Experiment_3_cs((SFc54_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c54_Experiment_3_cs(void *chartInstanceVar)
{
  enable_c54_Experiment_3_cs((SFc54_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c54_Experiment_3_cs(void *chartInstanceVar)
{
  disable_c54_Experiment_3_cs((SFc54_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c54_Experiment_3_cs(void *chartInstanceVar)
{
  sf_gateway_c54_Experiment_3_cs((SFc54_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c54_Experiment_3_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c54_Experiment_3_cs((SFc54_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c54_Experiment_3_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c54_Experiment_3_cs((SFc54_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c54_Experiment_3_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc54_Experiment_3_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_3_cs_optimization_info();
    }

    finalize_c54_Experiment_3_cs((SFc54_Experiment_3_csInstanceStruct*)
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
  initSimStructsc54_Experiment_3_cs((SFc54_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c54_Experiment_3_cs(SimStruct *S)
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
    initialize_params_c54_Experiment_3_cs((SFc54_Experiment_3_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c54_Experiment_3_cs(SimStruct *S)
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
      54);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,54,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,54,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,54);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,54,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,54,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,54);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3569211130U));
  ssSetChecksum1(S,(778716129U));
  ssSetChecksum2(S,(3979737153U));
  ssSetChecksum3(S,(3540115417U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c54_Experiment_3_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c54_Experiment_3_cs(SimStruct *S)
{
  SFc54_Experiment_3_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc54_Experiment_3_csInstanceStruct *)utMalloc(sizeof
    (SFc54_Experiment_3_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc54_Experiment_3_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c54_Experiment_3_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c54_Experiment_3_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c54_Experiment_3_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c54_Experiment_3_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c54_Experiment_3_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c54_Experiment_3_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c54_Experiment_3_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c54_Experiment_3_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c54_Experiment_3_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c54_Experiment_3_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c54_Experiment_3_cs;
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

void c54_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c54_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c54_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c54_Experiment_3_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c54_Experiment_3_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
