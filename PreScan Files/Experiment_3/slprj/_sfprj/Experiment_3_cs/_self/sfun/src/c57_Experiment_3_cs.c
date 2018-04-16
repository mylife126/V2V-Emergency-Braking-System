/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_3_cs_sfun.h"
#include "c57_Experiment_3_cs.h"
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
static const char * c57_debug_family_names[7] = { "i", "TISdet", "nargin",
  "nargout", "indx", "rangedot", "RANGEDOT" };

/* Function Declarations */
static void initialize_c57_Experiment_3_cs(SFc57_Experiment_3_csInstanceStruct
  *chartInstance);
static void initialize_params_c57_Experiment_3_cs
  (SFc57_Experiment_3_csInstanceStruct *chartInstance);
static void enable_c57_Experiment_3_cs(SFc57_Experiment_3_csInstanceStruct
  *chartInstance);
static void disable_c57_Experiment_3_cs(SFc57_Experiment_3_csInstanceStruct
  *chartInstance);
static void c57_update_debugger_state_c57_Experiment_3_cs
  (SFc57_Experiment_3_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c57_Experiment_3_cs
  (SFc57_Experiment_3_csInstanceStruct *chartInstance);
static void set_sim_state_c57_Experiment_3_cs
  (SFc57_Experiment_3_csInstanceStruct *chartInstance, const mxArray *c57_st);
static void finalize_c57_Experiment_3_cs(SFc57_Experiment_3_csInstanceStruct
  *chartInstance);
static void sf_gateway_c57_Experiment_3_cs(SFc57_Experiment_3_csInstanceStruct
  *chartInstance);
static void mdl_start_c57_Experiment_3_cs(SFc57_Experiment_3_csInstanceStruct
  *chartInstance);
static void initSimStructsc57_Experiment_3_cs
  (SFc57_Experiment_3_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c57_machineNumber, uint32_T
  c57_chartNumber, uint32_T c57_instanceNumber);
static const mxArray *c57_sf_marshallOut(void *chartInstanceVoid, void
  *c57_inData);
static void c57_emlrt_marshallIn(SFc57_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c57_b_RANGEDOT, const char_T *c57_identifier,
  real_T c57_y[32]);
static void c57_b_emlrt_marshallIn(SFc57_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c57_u, const emlrtMsgIdentifier *c57_parentId,
  real_T c57_y[32]);
static void c57_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c57_mxArrayInData, const char_T *c57_varName, void *c57_outData);
static const mxArray *c57_b_sf_marshallOut(void *chartInstanceVoid, void
  *c57_inData);
static real_T c57_c_emlrt_marshallIn(SFc57_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c57_u, const emlrtMsgIdentifier *c57_parentId);
static void c57_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c57_mxArrayInData, const char_T *c57_varName, void *c57_outData);
static const mxArray *c57_c_sf_marshallOut(void *chartInstanceVoid, void
  *c57_inData);
static void c57_info_helper(const mxArray **c57_info);
static const mxArray *c57_emlrt_marshallOut(const char * c57_u);
static const mxArray *c57_b_emlrt_marshallOut(const uint32_T c57_u);
static const mxArray *c57_d_sf_marshallOut(void *chartInstanceVoid, void
  *c57_inData);
static int32_T c57_d_emlrt_marshallIn(SFc57_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c57_u, const emlrtMsgIdentifier *c57_parentId);
static void c57_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c57_mxArrayInData, const char_T *c57_varName, void *c57_outData);
static void c57_e_emlrt_marshallIn(SFc57_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c57_u, const emlrtMsgIdentifier *c57_parentId,
  real_T c57_y[2]);
static void c57_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c57_mxArrayInData, const char_T *c57_varName, void *c57_outData);
static uint8_T c57_f_emlrt_marshallIn(SFc57_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c57_b_is_active_c57_Experiment_3_cs, const
  char_T *c57_identifier);
static uint8_T c57_g_emlrt_marshallIn(SFc57_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c57_u, const emlrtMsgIdentifier *c57_parentId);
static void init_dsm_address_info(SFc57_Experiment_3_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc57_Experiment_3_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c57_Experiment_3_cs(SFc57_Experiment_3_csInstanceStruct
  *chartInstance)
{
  chartInstance->c57_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c57_is_active_c57_Experiment_3_cs = 0U;
}

static void initialize_params_c57_Experiment_3_cs
  (SFc57_Experiment_3_csInstanceStruct *chartInstance)
{
  real_T c57_dv0[2];
  int32_T c57_i0;
  sf_mex_import_named("TISdet", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c57_dv0, 0, 0, 0U, 1, 0U, 2, 1, 2);
  for (c57_i0 = 0; c57_i0 < 2; c57_i0++) {
    chartInstance->c57_TISdet[c57_i0] = c57_dv0[c57_i0];
  }
}

static void enable_c57_Experiment_3_cs(SFc57_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c57_Experiment_3_cs(SFc57_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c57_update_debugger_state_c57_Experiment_3_cs
  (SFc57_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c57_Experiment_3_cs
  (SFc57_Experiment_3_csInstanceStruct *chartInstance)
{
  const mxArray *c57_st;
  const mxArray *c57_y = NULL;
  int32_T c57_i1;
  real_T c57_u[32];
  const mxArray *c57_b_y = NULL;
  uint8_T c57_hoistedGlobal;
  uint8_T c57_b_u;
  const mxArray *c57_c_y = NULL;
  c57_st = NULL;
  c57_st = NULL;
  c57_y = NULL;
  sf_mex_assign(&c57_y, sf_mex_createcellmatrix(2, 1), false);
  for (c57_i1 = 0; c57_i1 < 32; c57_i1++) {
    c57_u[c57_i1] = (*chartInstance->c57_RANGEDOT)[c57_i1];
  }

  c57_b_y = NULL;
  sf_mex_assign(&c57_b_y, sf_mex_create("y", c57_u, 0, 0U, 1U, 0U, 1, 32), false);
  sf_mex_setcell(c57_y, 0, c57_b_y);
  c57_hoistedGlobal = chartInstance->c57_is_active_c57_Experiment_3_cs;
  c57_b_u = c57_hoistedGlobal;
  c57_c_y = NULL;
  sf_mex_assign(&c57_c_y, sf_mex_create("y", &c57_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c57_y, 1, c57_c_y);
  sf_mex_assign(&c57_st, c57_y, false);
  return c57_st;
}

static void set_sim_state_c57_Experiment_3_cs
  (SFc57_Experiment_3_csInstanceStruct *chartInstance, const mxArray *c57_st)
{
  const mxArray *c57_u;
  real_T c57_dv1[32];
  int32_T c57_i2;
  chartInstance->c57_doneDoubleBufferReInit = true;
  c57_u = sf_mex_dup(c57_st);
  c57_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c57_u, 0)),
                       "RANGEDOT", c57_dv1);
  for (c57_i2 = 0; c57_i2 < 32; c57_i2++) {
    (*chartInstance->c57_RANGEDOT)[c57_i2] = c57_dv1[c57_i2];
  }

  chartInstance->c57_is_active_c57_Experiment_3_cs = c57_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c57_u, 1)),
     "is_active_c57_Experiment_3_cs");
  sf_mex_destroy(&c57_u);
  c57_update_debugger_state_c57_Experiment_3_cs(chartInstance);
  sf_mex_destroy(&c57_st);
}

static void finalize_c57_Experiment_3_cs(SFc57_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c57_Experiment_3_cs(SFc57_Experiment_3_csInstanceStruct
  *chartInstance)
{
  int32_T c57_i3;
  int32_T c57_i4;
  real_T c57_b_indx[32];
  int32_T c57_i5;
  real_T c57_b_rangedot[32];
  uint32_T c57_debug_family_var_map[7];
  real_T c57_i;
  real_T c57_c_TISdet[2];
  real_T c57_nargin = 3.0;
  real_T c57_nargout = 1.0;
  real_T c57_b_RANGEDOT[32];
  int32_T c57_i6;
  int32_T c57_i7;
  int32_T c57_b_i;
  real_T c57_d0;
  int32_T c57_i8;
  int32_T c57_i9;
  int32_T c57_i10;
  int32_T c57_i11;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 56U, chartInstance->c57_sfEvent);
  for (c57_i3 = 0; c57_i3 < 32; c57_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c57_indx)[c57_i3], 0U);
  }

  chartInstance->c57_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 56U, chartInstance->c57_sfEvent);
  for (c57_i4 = 0; c57_i4 < 32; c57_i4++) {
    c57_b_indx[c57_i4] = (*chartInstance->c57_indx)[c57_i4];
  }

  for (c57_i5 = 0; c57_i5 < 32; c57_i5++) {
    c57_b_rangedot[c57_i5] = (*chartInstance->c57_rangedot)[c57_i5];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c57_debug_family_names,
    c57_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_i, 0U, c57_b_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c57_c_TISdet, 1U, c57_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_nargin, 2U, c57_b_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_nargout, 3U, c57_b_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c57_b_indx, 4U, c57_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c57_b_rangedot, 5U, c57_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_b_RANGEDOT, 6U, c57_sf_marshallOut,
    c57_sf_marshallIn);
  for (c57_i6 = 0; c57_i6 < 2; c57_i6++) {
    c57_c_TISdet[c57_i6] = 32.0;
  }

  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 4);
  for (c57_i7 = 0; c57_i7 < 32; c57_i7++) {
    c57_b_RANGEDOT[c57_i7] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 5);
  c57_i = 1.0;
  c57_b_i = 0;
  while (c57_b_i < 32) {
    c57_i = 1.0 + (real_T)c57_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 6);
    c57_d0 = c57_b_indx[_SFD_EML_ARRAY_BOUNDS_CHECK("indx", (int32_T)
      _SFD_INTEGER_CHECK("i", c57_i), 1, 32, 1, 0) - 1];
    if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c57_d0, 0.0, -1, 1U,
          c57_d0 != 0.0))) {
      _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 7);
      c57_b_RANGEDOT[_SFD_EML_ARRAY_BOUNDS_CHECK("RANGEDOT", (int32_T)
        _SFD_INTEGER_CHECK("i", c57_i), 1, 32, 1, 0) - 1] =
        c57_b_rangedot[_SFD_EML_ARRAY_BOUNDS_CHECK("rangedot", (int32_T)
        _SFD_INTEGER_CHECK("indx(i)", c57_b_indx[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "indx", (int32_T)_SFD_INTEGER_CHECK("i", c57_i), 1, 32, 1, 0) - 1]), 1,
        32, 1, 0) - 1];
    } else {
      _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 9);
      c57_b_RANGEDOT[_SFD_EML_ARRAY_BOUNDS_CHECK("RANGEDOT", (int32_T)
        _SFD_INTEGER_CHECK("i", c57_i), 1, 32, 1, 0) - 1] = 0.0;
    }

    c57_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, -9);
  _SFD_SYMBOL_SCOPE_POP();
  for (c57_i8 = 0; c57_i8 < 32; c57_i8++) {
    (*chartInstance->c57_RANGEDOT)[c57_i8] = c57_b_RANGEDOT[c57_i8];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 56U, chartInstance->c57_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_3_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c57_i9 = 0; c57_i9 < 32; c57_i9++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c57_RANGEDOT)[c57_i9], 1U);
  }

  for (c57_i10 = 0; c57_i10 < 32; c57_i10++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c57_rangedot)[c57_i10], 2U);
  }

  for (c57_i11 = 0; c57_i11 < 2; c57_i11++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c57_TISdet[c57_i11], 3U);
  }
}

static void mdl_start_c57_Experiment_3_cs(SFc57_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc57_Experiment_3_cs
  (SFc57_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c57_machineNumber, uint32_T
  c57_chartNumber, uint32_T c57_instanceNumber)
{
  (void)c57_machineNumber;
  (void)c57_chartNumber;
  (void)c57_instanceNumber;
}

static const mxArray *c57_sf_marshallOut(void *chartInstanceVoid, void
  *c57_inData)
{
  const mxArray *c57_mxArrayOutData = NULL;
  int32_T c57_i12;
  real_T c57_b_inData[32];
  int32_T c57_i13;
  real_T c57_u[32];
  const mxArray *c57_y = NULL;
  SFc57_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc57_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c57_mxArrayOutData = NULL;
  for (c57_i12 = 0; c57_i12 < 32; c57_i12++) {
    c57_b_inData[c57_i12] = (*(real_T (*)[32])c57_inData)[c57_i12];
  }

  for (c57_i13 = 0; c57_i13 < 32; c57_i13++) {
    c57_u[c57_i13] = c57_b_inData[c57_i13];
  }

  c57_y = NULL;
  sf_mex_assign(&c57_y, sf_mex_create("y", c57_u, 0, 0U, 1U, 0U, 1, 32), false);
  sf_mex_assign(&c57_mxArrayOutData, c57_y, false);
  return c57_mxArrayOutData;
}

static void c57_emlrt_marshallIn(SFc57_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c57_b_RANGEDOT, const char_T *c57_identifier,
  real_T c57_y[32])
{
  emlrtMsgIdentifier c57_thisId;
  c57_thisId.fIdentifier = c57_identifier;
  c57_thisId.fParent = NULL;
  c57_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c57_b_RANGEDOT), &c57_thisId,
    c57_y);
  sf_mex_destroy(&c57_b_RANGEDOT);
}

static void c57_b_emlrt_marshallIn(SFc57_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c57_u, const emlrtMsgIdentifier *c57_parentId,
  real_T c57_y[32])
{
  real_T c57_dv2[32];
  int32_T c57_i14;
  (void)chartInstance;
  sf_mex_import(c57_parentId, sf_mex_dup(c57_u), c57_dv2, 1, 0, 0U, 1, 0U, 1, 32);
  for (c57_i14 = 0; c57_i14 < 32; c57_i14++) {
    c57_y[c57_i14] = c57_dv2[c57_i14];
  }

  sf_mex_destroy(&c57_u);
}

static void c57_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c57_mxArrayInData, const char_T *c57_varName, void *c57_outData)
{
  const mxArray *c57_b_RANGEDOT;
  const char_T *c57_identifier;
  emlrtMsgIdentifier c57_thisId;
  real_T c57_y[32];
  int32_T c57_i15;
  SFc57_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc57_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c57_b_RANGEDOT = sf_mex_dup(c57_mxArrayInData);
  c57_identifier = c57_varName;
  c57_thisId.fIdentifier = c57_identifier;
  c57_thisId.fParent = NULL;
  c57_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c57_b_RANGEDOT), &c57_thisId,
    c57_y);
  sf_mex_destroy(&c57_b_RANGEDOT);
  for (c57_i15 = 0; c57_i15 < 32; c57_i15++) {
    (*(real_T (*)[32])c57_outData)[c57_i15] = c57_y[c57_i15];
  }

  sf_mex_destroy(&c57_mxArrayInData);
}

static const mxArray *c57_b_sf_marshallOut(void *chartInstanceVoid, void
  *c57_inData)
{
  const mxArray *c57_mxArrayOutData = NULL;
  real_T c57_u;
  const mxArray *c57_y = NULL;
  SFc57_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc57_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c57_mxArrayOutData = NULL;
  c57_u = *(real_T *)c57_inData;
  c57_y = NULL;
  sf_mex_assign(&c57_y, sf_mex_create("y", &c57_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c57_mxArrayOutData, c57_y, false);
  return c57_mxArrayOutData;
}

static real_T c57_c_emlrt_marshallIn(SFc57_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c57_u, const emlrtMsgIdentifier *c57_parentId)
{
  real_T c57_y;
  real_T c57_d1;
  (void)chartInstance;
  sf_mex_import(c57_parentId, sf_mex_dup(c57_u), &c57_d1, 1, 0, 0U, 0, 0U, 0);
  c57_y = c57_d1;
  sf_mex_destroy(&c57_u);
  return c57_y;
}

static void c57_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c57_mxArrayInData, const char_T *c57_varName, void *c57_outData)
{
  const mxArray *c57_nargout;
  const char_T *c57_identifier;
  emlrtMsgIdentifier c57_thisId;
  real_T c57_y;
  SFc57_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc57_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c57_nargout = sf_mex_dup(c57_mxArrayInData);
  c57_identifier = c57_varName;
  c57_thisId.fIdentifier = c57_identifier;
  c57_thisId.fParent = NULL;
  c57_y = c57_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c57_nargout),
    &c57_thisId);
  sf_mex_destroy(&c57_nargout);
  *(real_T *)c57_outData = c57_y;
  sf_mex_destroy(&c57_mxArrayInData);
}

static const mxArray *c57_c_sf_marshallOut(void *chartInstanceVoid, void
  *c57_inData)
{
  const mxArray *c57_mxArrayOutData = NULL;
  int32_T c57_i16;
  real_T c57_b_inData[2];
  int32_T c57_i17;
  real_T c57_u[2];
  const mxArray *c57_y = NULL;
  SFc57_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc57_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c57_mxArrayOutData = NULL;
  for (c57_i16 = 0; c57_i16 < 2; c57_i16++) {
    c57_b_inData[c57_i16] = (*(real_T (*)[2])c57_inData)[c57_i16];
  }

  for (c57_i17 = 0; c57_i17 < 2; c57_i17++) {
    c57_u[c57_i17] = c57_b_inData[c57_i17];
  }

  c57_y = NULL;
  sf_mex_assign(&c57_y, sf_mex_create("y", c57_u, 0, 0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_assign(&c57_mxArrayOutData, c57_y, false);
  return c57_mxArrayOutData;
}

const mxArray *sf_c57_Experiment_3_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c57_nameCaptureInfo = NULL;
  c57_nameCaptureInfo = NULL;
  sf_mex_assign(&c57_nameCaptureInfo, sf_mex_createstruct("structure", 2, 1, 1),
                false);
  c57_info_helper(&c57_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c57_nameCaptureInfo);
  return c57_nameCaptureInfo;
}

static void c57_info_helper(const mxArray **c57_info)
{
  const mxArray *c57_rhs0 = NULL;
  const mxArray *c57_lhs0 = NULL;
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("length"), "name", "name", 0);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1303167806U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c57_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs0), "lhs", "lhs",
                  0);
  sf_mex_destroy(&c57_rhs0);
  sf_mex_destroy(&c57_lhs0);
}

static const mxArray *c57_emlrt_marshallOut(const char * c57_u)
{
  const mxArray *c57_y = NULL;
  c57_y = NULL;
  sf_mex_assign(&c57_y, sf_mex_create("y", c57_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c57_u)), false);
  return c57_y;
}

static const mxArray *c57_b_emlrt_marshallOut(const uint32_T c57_u)
{
  const mxArray *c57_y = NULL;
  c57_y = NULL;
  sf_mex_assign(&c57_y, sf_mex_create("y", &c57_u, 7, 0U, 0U, 0U, 0), false);
  return c57_y;
}

static const mxArray *c57_d_sf_marshallOut(void *chartInstanceVoid, void
  *c57_inData)
{
  const mxArray *c57_mxArrayOutData = NULL;
  int32_T c57_u;
  const mxArray *c57_y = NULL;
  SFc57_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc57_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c57_mxArrayOutData = NULL;
  c57_u = *(int32_T *)c57_inData;
  c57_y = NULL;
  sf_mex_assign(&c57_y, sf_mex_create("y", &c57_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c57_mxArrayOutData, c57_y, false);
  return c57_mxArrayOutData;
}

static int32_T c57_d_emlrt_marshallIn(SFc57_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c57_u, const emlrtMsgIdentifier *c57_parentId)
{
  int32_T c57_y;
  int32_T c57_i18;
  (void)chartInstance;
  sf_mex_import(c57_parentId, sf_mex_dup(c57_u), &c57_i18, 1, 6, 0U, 0, 0U, 0);
  c57_y = c57_i18;
  sf_mex_destroy(&c57_u);
  return c57_y;
}

static void c57_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c57_mxArrayInData, const char_T *c57_varName, void *c57_outData)
{
  const mxArray *c57_b_sfEvent;
  const char_T *c57_identifier;
  emlrtMsgIdentifier c57_thisId;
  int32_T c57_y;
  SFc57_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc57_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c57_b_sfEvent = sf_mex_dup(c57_mxArrayInData);
  c57_identifier = c57_varName;
  c57_thisId.fIdentifier = c57_identifier;
  c57_thisId.fParent = NULL;
  c57_y = c57_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c57_b_sfEvent),
    &c57_thisId);
  sf_mex_destroy(&c57_b_sfEvent);
  *(int32_T *)c57_outData = c57_y;
  sf_mex_destroy(&c57_mxArrayInData);
}

static void c57_e_emlrt_marshallIn(SFc57_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c57_u, const emlrtMsgIdentifier *c57_parentId,
  real_T c57_y[2])
{
  real_T c57_dv3[2];
  int32_T c57_i19;
  (void)chartInstance;
  sf_mex_import(c57_parentId, sf_mex_dup(c57_u), c57_dv3, 1, 0, 0U, 1, 0U, 2, 1,
                2);
  for (c57_i19 = 0; c57_i19 < 2; c57_i19++) {
    c57_y[c57_i19] = c57_dv3[c57_i19];
  }

  sf_mex_destroy(&c57_u);
}

static void c57_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c57_mxArrayInData, const char_T *c57_varName, void *c57_outData)
{
  const mxArray *c57_c_TISdet;
  const char_T *c57_identifier;
  emlrtMsgIdentifier c57_thisId;
  real_T c57_y[2];
  int32_T c57_i20;
  SFc57_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc57_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c57_c_TISdet = sf_mex_dup(c57_mxArrayInData);
  c57_identifier = c57_varName;
  c57_thisId.fIdentifier = c57_identifier;
  c57_thisId.fParent = NULL;
  c57_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c57_c_TISdet), &c57_thisId,
    c57_y);
  sf_mex_destroy(&c57_c_TISdet);
  for (c57_i20 = 0; c57_i20 < 2; c57_i20++) {
    (*(real_T (*)[2])c57_outData)[c57_i20] = c57_y[c57_i20];
  }

  sf_mex_destroy(&c57_mxArrayInData);
}

static uint8_T c57_f_emlrt_marshallIn(SFc57_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c57_b_is_active_c57_Experiment_3_cs, const
  char_T *c57_identifier)
{
  uint8_T c57_y;
  emlrtMsgIdentifier c57_thisId;
  c57_thisId.fIdentifier = c57_identifier;
  c57_thisId.fParent = NULL;
  c57_y = c57_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c57_b_is_active_c57_Experiment_3_cs), &c57_thisId);
  sf_mex_destroy(&c57_b_is_active_c57_Experiment_3_cs);
  return c57_y;
}

static uint8_T c57_g_emlrt_marshallIn(SFc57_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c57_u, const emlrtMsgIdentifier *c57_parentId)
{
  uint8_T c57_y;
  uint8_T c57_u0;
  (void)chartInstance;
  sf_mex_import(c57_parentId, sf_mex_dup(c57_u), &c57_u0, 1, 3, 0U, 0, 0U, 0);
  c57_y = c57_u0;
  sf_mex_destroy(&c57_u);
  return c57_y;
}

static void init_dsm_address_info(SFc57_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc57_Experiment_3_csInstanceStruct
  *chartInstance)
{
  chartInstance->c57_indx = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c57_RANGEDOT = (real_T (*)[32])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c57_rangedot = (real_T (*)[32])ssGetInputPortSignal_wrapper
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

void sf_c57_Experiment_3_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1857277007U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2980728768U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2611967458U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3189820665U);
}

mxArray* sf_c57_Experiment_3_cs_get_post_codegen_info(void);
mxArray *sf_c57_Experiment_3_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("z2G6OpbokIXCMjU7r4SO1B");
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
    mxArray* mxPostCodegenInfo = sf_c57_Experiment_3_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c57_Experiment_3_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c57_Experiment_3_cs_jit_fallback_info(void)
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

mxArray *sf_c57_Experiment_3_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c57_Experiment_3_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c57_Experiment_3_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"RANGEDOT\",},{M[8],M[0],T\"is_active_c57_Experiment_3_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c57_Experiment_3_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc57_Experiment_3_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc57_Experiment_3_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_3_csMachineNumber_,
           57,
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
          _SFD_SET_DATA_PROPS(1,2,0,1,"RANGEDOT");
          _SFD_SET_DATA_PROPS(2,1,1,0,"rangedot");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,221);
        _SFD_CV_INIT_EML_IF(0,1,0,119,134,180,217);
        _SFD_CV_INIT_EML_FOR(0,1,0,90,115,221);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,122,134,-1,1);

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c57_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c57_sf_marshallOut,(MexInFcnForType)
            c57_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c57_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c57_c_sf_marshallOut,(MexInFcnForType)
            c57_d_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c57_indx);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c57_RANGEDOT);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c57_rangedot);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c57_TISdet);
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
  return "82ag9eZWOWrFPv6tEdhF6C";
}

static void sf_opaque_initialize_c57_Experiment_3_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc57_Experiment_3_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c57_Experiment_3_cs((SFc57_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
  initialize_c57_Experiment_3_cs((SFc57_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c57_Experiment_3_cs(void *chartInstanceVar)
{
  enable_c57_Experiment_3_cs((SFc57_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c57_Experiment_3_cs(void *chartInstanceVar)
{
  disable_c57_Experiment_3_cs((SFc57_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c57_Experiment_3_cs(void *chartInstanceVar)
{
  sf_gateway_c57_Experiment_3_cs((SFc57_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c57_Experiment_3_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c57_Experiment_3_cs((SFc57_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c57_Experiment_3_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c57_Experiment_3_cs((SFc57_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c57_Experiment_3_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc57_Experiment_3_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_3_cs_optimization_info();
    }

    finalize_c57_Experiment_3_cs((SFc57_Experiment_3_csInstanceStruct*)
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
  initSimStructsc57_Experiment_3_cs((SFc57_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c57_Experiment_3_cs(SimStruct *S)
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
    initialize_params_c57_Experiment_3_cs((SFc57_Experiment_3_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c57_Experiment_3_cs(SimStruct *S)
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
      57);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,57,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,57,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,57);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,57,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,57,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,57);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1494747717U));
  ssSetChecksum1(S,(4131872670U));
  ssSetChecksum2(S,(2458805663U));
  ssSetChecksum3(S,(1600844854U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c57_Experiment_3_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c57_Experiment_3_cs(SimStruct *S)
{
  SFc57_Experiment_3_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc57_Experiment_3_csInstanceStruct *)utMalloc(sizeof
    (SFc57_Experiment_3_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc57_Experiment_3_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c57_Experiment_3_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c57_Experiment_3_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c57_Experiment_3_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c57_Experiment_3_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c57_Experiment_3_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c57_Experiment_3_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c57_Experiment_3_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c57_Experiment_3_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c57_Experiment_3_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c57_Experiment_3_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c57_Experiment_3_cs;
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

void c57_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c57_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c57_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c57_Experiment_3_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c57_Experiment_3_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
