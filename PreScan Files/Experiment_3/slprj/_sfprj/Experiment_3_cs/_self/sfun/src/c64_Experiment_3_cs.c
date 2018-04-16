/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_3_cs_sfun.h"
#include "c64_Experiment_3_cs.h"
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
static const char * c64_debug_family_names[12] = { "i", "nargin", "nargout",
  "pedR_self", "pedTheta_self", "dVel_self", "pedR_rcvd", "pedTheta_rcvd",
  "dVel_rcvd", "pedR_Array", "pedTheta_Array", "dVel_Array" };

/* Function Declarations */
static void initialize_c64_Experiment_3_cs(SFc64_Experiment_3_csInstanceStruct
  *chartInstance);
static void initialize_params_c64_Experiment_3_cs
  (SFc64_Experiment_3_csInstanceStruct *chartInstance);
static void enable_c64_Experiment_3_cs(SFc64_Experiment_3_csInstanceStruct
  *chartInstance);
static void disable_c64_Experiment_3_cs(SFc64_Experiment_3_csInstanceStruct
  *chartInstance);
static void c64_update_debugger_state_c64_Experiment_3_cs
  (SFc64_Experiment_3_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c64_Experiment_3_cs
  (SFc64_Experiment_3_csInstanceStruct *chartInstance);
static void set_sim_state_c64_Experiment_3_cs
  (SFc64_Experiment_3_csInstanceStruct *chartInstance, const mxArray *c64_st);
static void finalize_c64_Experiment_3_cs(SFc64_Experiment_3_csInstanceStruct
  *chartInstance);
static void sf_gateway_c64_Experiment_3_cs(SFc64_Experiment_3_csInstanceStruct
  *chartInstance);
static void mdl_start_c64_Experiment_3_cs(SFc64_Experiment_3_csInstanceStruct
  *chartInstance);
static void initSimStructsc64_Experiment_3_cs
  (SFc64_Experiment_3_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c64_machineNumber, uint32_T
  c64_chartNumber, uint32_T c64_instanceNumber);
static const mxArray *c64_sf_marshallOut(void *chartInstanceVoid, void
  *c64_inData);
static void c64_emlrt_marshallIn(SFc64_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c64_b_dVel_Array, const char_T *c64_identifier,
  real_T c64_y[32]);
static void c64_b_emlrt_marshallIn(SFc64_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c64_u, const emlrtMsgIdentifier *c64_parentId,
  real_T c64_y[32]);
static void c64_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c64_mxArrayInData, const char_T *c64_varName, void *c64_outData);
static const mxArray *c64_b_sf_marshallOut(void *chartInstanceVoid, void
  *c64_inData);
static const mxArray *c64_c_sf_marshallOut(void *chartInstanceVoid, void
  *c64_inData);
static real_T c64_c_emlrt_marshallIn(SFc64_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c64_u, const emlrtMsgIdentifier *c64_parentId);
static void c64_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c64_mxArrayInData, const char_T *c64_varName, void *c64_outData);
static void c64_info_helper(const mxArray **c64_info);
static const mxArray *c64_emlrt_marshallOut(const char * c64_u);
static const mxArray *c64_b_emlrt_marshallOut(const uint32_T c64_u);
static const mxArray *c64_d_sf_marshallOut(void *chartInstanceVoid, void
  *c64_inData);
static int32_T c64_d_emlrt_marshallIn(SFc64_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c64_u, const emlrtMsgIdentifier *c64_parentId);
static void c64_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c64_mxArrayInData, const char_T *c64_varName, void *c64_outData);
static uint8_T c64_e_emlrt_marshallIn(SFc64_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c64_b_is_active_c64_Experiment_3_cs, const
  char_T *c64_identifier);
static uint8_T c64_f_emlrt_marshallIn(SFc64_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c64_u, const emlrtMsgIdentifier *c64_parentId);
static void init_dsm_address_info(SFc64_Experiment_3_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc64_Experiment_3_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c64_Experiment_3_cs(SFc64_Experiment_3_csInstanceStruct
  *chartInstance)
{
  chartInstance->c64_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c64_is_active_c64_Experiment_3_cs = 0U;
}

static void initialize_params_c64_Experiment_3_cs
  (SFc64_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c64_Experiment_3_cs(SFc64_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c64_Experiment_3_cs(SFc64_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c64_update_debugger_state_c64_Experiment_3_cs
  (SFc64_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c64_Experiment_3_cs
  (SFc64_Experiment_3_csInstanceStruct *chartInstance)
{
  const mxArray *c64_st;
  const mxArray *c64_y = NULL;
  int32_T c64_i0;
  real_T c64_u[32];
  const mxArray *c64_b_y = NULL;
  int32_T c64_i1;
  real_T c64_b_u[32];
  const mxArray *c64_c_y = NULL;
  int32_T c64_i2;
  real_T c64_c_u[32];
  const mxArray *c64_d_y = NULL;
  uint8_T c64_hoistedGlobal;
  uint8_T c64_d_u;
  const mxArray *c64_e_y = NULL;
  c64_st = NULL;
  c64_st = NULL;
  c64_y = NULL;
  sf_mex_assign(&c64_y, sf_mex_createcellmatrix(4, 1), false);
  for (c64_i0 = 0; c64_i0 < 32; c64_i0++) {
    c64_u[c64_i0] = (*chartInstance->c64_dVel_Array)[c64_i0];
  }

  c64_b_y = NULL;
  sf_mex_assign(&c64_b_y, sf_mex_create("y", c64_u, 0, 0U, 1U, 0U, 1, 32), false);
  sf_mex_setcell(c64_y, 0, c64_b_y);
  for (c64_i1 = 0; c64_i1 < 32; c64_i1++) {
    c64_b_u[c64_i1] = (*chartInstance->c64_pedR_Array)[c64_i1];
  }

  c64_c_y = NULL;
  sf_mex_assign(&c64_c_y, sf_mex_create("y", c64_b_u, 0, 0U, 1U, 0U, 1, 32),
                false);
  sf_mex_setcell(c64_y, 1, c64_c_y);
  for (c64_i2 = 0; c64_i2 < 32; c64_i2++) {
    c64_c_u[c64_i2] = (*chartInstance->c64_pedTheta_Array)[c64_i2];
  }

  c64_d_y = NULL;
  sf_mex_assign(&c64_d_y, sf_mex_create("y", c64_c_u, 0, 0U, 1U, 0U, 1, 32),
                false);
  sf_mex_setcell(c64_y, 2, c64_d_y);
  c64_hoistedGlobal = chartInstance->c64_is_active_c64_Experiment_3_cs;
  c64_d_u = c64_hoistedGlobal;
  c64_e_y = NULL;
  sf_mex_assign(&c64_e_y, sf_mex_create("y", &c64_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c64_y, 3, c64_e_y);
  sf_mex_assign(&c64_st, c64_y, false);
  return c64_st;
}

static void set_sim_state_c64_Experiment_3_cs
  (SFc64_Experiment_3_csInstanceStruct *chartInstance, const mxArray *c64_st)
{
  const mxArray *c64_u;
  real_T c64_dv0[32];
  int32_T c64_i3;
  real_T c64_dv1[32];
  int32_T c64_i4;
  real_T c64_dv2[32];
  int32_T c64_i5;
  chartInstance->c64_doneDoubleBufferReInit = true;
  c64_u = sf_mex_dup(c64_st);
  c64_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c64_u, 0)),
                       "dVel_Array", c64_dv0);
  for (c64_i3 = 0; c64_i3 < 32; c64_i3++) {
    (*chartInstance->c64_dVel_Array)[c64_i3] = c64_dv0[c64_i3];
  }

  c64_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c64_u, 1)),
                       "pedR_Array", c64_dv1);
  for (c64_i4 = 0; c64_i4 < 32; c64_i4++) {
    (*chartInstance->c64_pedR_Array)[c64_i4] = c64_dv1[c64_i4];
  }

  c64_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c64_u, 2)),
                       "pedTheta_Array", c64_dv2);
  for (c64_i5 = 0; c64_i5 < 32; c64_i5++) {
    (*chartInstance->c64_pedTheta_Array)[c64_i5] = c64_dv2[c64_i5];
  }

  chartInstance->c64_is_active_c64_Experiment_3_cs = c64_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c64_u, 3)),
     "is_active_c64_Experiment_3_cs");
  sf_mex_destroy(&c64_u);
  c64_update_debugger_state_c64_Experiment_3_cs(chartInstance);
  sf_mex_destroy(&c64_st);
}

static void finalize_c64_Experiment_3_cs(SFc64_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c64_Experiment_3_cs(SFc64_Experiment_3_csInstanceStruct
  *chartInstance)
{
  int32_T c64_i6;
  int32_T c64_i7;
  real_T c64_b_pedR_self[5];
  int32_T c64_i8;
  real_T c64_b_pedTheta_self[5];
  int32_T c64_i9;
  real_T c64_b_dVel_self[5];
  int32_T c64_i10;
  real_T c64_b_pedR_rcvd[5];
  int32_T c64_i11;
  real_T c64_b_pedTheta_rcvd[5];
  int32_T c64_i12;
  real_T c64_b_dVel_rcvd[5];
  uint32_T c64_debug_family_var_map[12];
  real_T c64_i;
  real_T c64_nargin = 6.0;
  real_T c64_nargout = 3.0;
  real_T c64_b_pedR_Array[32];
  real_T c64_b_pedTheta_Array[32];
  real_T c64_b_dVel_Array[32];
  int32_T c64_i13;
  int32_T c64_i14;
  int32_T c64_i15;
  int32_T c64_b_i;
  int32_T c64_c_i;
  int32_T c64_i16;
  int32_T c64_i17;
  int32_T c64_i18;
  int32_T c64_i19;
  int32_T c64_i20;
  int32_T c64_i21;
  int32_T c64_i22;
  int32_T c64_i23;
  int32_T c64_i24;
  int32_T c64_i25;
  int32_T c64_i26;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 58U, chartInstance->c64_sfEvent);
  for (c64_i6 = 0; c64_i6 < 5; c64_i6++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c64_pedR_self)[c64_i6], 0U);
  }

  chartInstance->c64_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 58U, chartInstance->c64_sfEvent);
  for (c64_i7 = 0; c64_i7 < 5; c64_i7++) {
    c64_b_pedR_self[c64_i7] = (*chartInstance->c64_pedR_self)[c64_i7];
  }

  for (c64_i8 = 0; c64_i8 < 5; c64_i8++) {
    c64_b_pedTheta_self[c64_i8] = (*chartInstance->c64_pedTheta_self)[c64_i8];
  }

  for (c64_i9 = 0; c64_i9 < 5; c64_i9++) {
    c64_b_dVel_self[c64_i9] = (*chartInstance->c64_dVel_self)[c64_i9];
  }

  for (c64_i10 = 0; c64_i10 < 5; c64_i10++) {
    c64_b_pedR_rcvd[c64_i10] = (*chartInstance->c64_pedR_rcvd)[c64_i10];
  }

  for (c64_i11 = 0; c64_i11 < 5; c64_i11++) {
    c64_b_pedTheta_rcvd[c64_i11] = (*chartInstance->c64_pedTheta_rcvd)[c64_i11];
  }

  for (c64_i12 = 0; c64_i12 < 5; c64_i12++) {
    c64_b_dVel_rcvd[c64_i12] = (*chartInstance->c64_dVel_rcvd)[c64_i12];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c64_debug_family_names,
    c64_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c64_i, 0U, c64_c_sf_marshallOut,
    c64_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c64_nargin, 1U, c64_c_sf_marshallOut,
    c64_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c64_nargout, 2U, c64_c_sf_marshallOut,
    c64_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c64_b_pedR_self, 3U, c64_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c64_b_pedTheta_self, 4U, c64_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c64_b_dVel_self, 5U, c64_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c64_b_pedR_rcvd, 6U, c64_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c64_b_pedTheta_rcvd, 7U, c64_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c64_b_dVel_rcvd, 8U, c64_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c64_b_pedR_Array, 9U, c64_sf_marshallOut,
    c64_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c64_b_pedTheta_Array, 10U,
    c64_sf_marshallOut, c64_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c64_b_dVel_Array, 11U, c64_sf_marshallOut,
    c64_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c64_sfEvent, 3);
  for (c64_i13 = 0; c64_i13 < 32; c64_i13++) {
    c64_b_pedR_Array[c64_i13] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c64_sfEvent, 4);
  for (c64_i14 = 0; c64_i14 < 32; c64_i14++) {
    c64_b_pedTheta_Array[c64_i14] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c64_sfEvent, 5);
  for (c64_i15 = 0; c64_i15 < 32; c64_i15++) {
    c64_b_dVel_Array[c64_i15] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c64_sfEvent, 7);
  c64_i = 1.0;
  c64_b_i = 0;
  while (c64_b_i < 5) {
    c64_i = 1.0 + (real_T)c64_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c64_sfEvent, 8);
    c64_b_pedR_Array[_SFD_EML_ARRAY_BOUNDS_CHECK("pedR_Array", (int32_T)
      _SFD_INTEGER_CHECK("i", c64_i), 1, 32, 1, 0) - 1] =
      c64_b_pedR_self[_SFD_EML_ARRAY_BOUNDS_CHECK("pedR_self", (int32_T)
      _SFD_INTEGER_CHECK("i", c64_i), 1, 5, 1, 0) - 1];
    _SFD_EML_CALL(0U, chartInstance->c64_sfEvent, 9);
    c64_b_pedTheta_Array[_SFD_EML_ARRAY_BOUNDS_CHECK("pedTheta_Array", (int32_T)
      _SFD_INTEGER_CHECK("i", c64_i), 1, 32, 1, 0) - 1] =
      c64_b_pedTheta_self[_SFD_EML_ARRAY_BOUNDS_CHECK("pedTheta_self", (int32_T)
      _SFD_INTEGER_CHECK("i", c64_i), 1, 5, 1, 0) - 1];
    _SFD_EML_CALL(0U, chartInstance->c64_sfEvent, 10);
    c64_b_dVel_Array[_SFD_EML_ARRAY_BOUNDS_CHECK("dVel_Array", (int32_T)
      _SFD_INTEGER_CHECK("i", c64_i), 1, 32, 1, 0) - 1] =
      c64_b_dVel_self[_SFD_EML_ARRAY_BOUNDS_CHECK("dVel_self", (int32_T)
      _SFD_INTEGER_CHECK("i", c64_i), 1, 5, 1, 0) - 1];
    c64_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c64_sfEvent, 13);
  c64_i = 1.0;
  c64_c_i = 0;
  while (c64_c_i < 5) {
    c64_i = 1.0 + (real_T)c64_c_i;
    CV_EML_FOR(0, 1, 1, 1);
    _SFD_EML_CALL(0U, chartInstance->c64_sfEvent, 14);
    c64_b_pedR_Array[_SFD_EML_ARRAY_BOUNDS_CHECK("pedR_Array", (int32_T)
      _SFD_INTEGER_CHECK("i + length(pedR_self)", c64_i + 5.0), 1, 32, 1, 0) - 1]
      = c64_b_pedR_rcvd[_SFD_EML_ARRAY_BOUNDS_CHECK("pedR_rcvd", (int32_T)
      _SFD_INTEGER_CHECK("i", c64_i), 1, 5, 1, 0) - 1];
    _SFD_EML_CALL(0U, chartInstance->c64_sfEvent, 15);
    c64_b_pedTheta_Array[_SFD_EML_ARRAY_BOUNDS_CHECK("pedTheta_Array", (int32_T)
      _SFD_INTEGER_CHECK("i + length(pedR_self)", c64_i + 5.0), 1, 32, 1, 0) - 1]
      = c64_b_pedTheta_rcvd[_SFD_EML_ARRAY_BOUNDS_CHECK("pedTheta_rcvd",
      (int32_T)_SFD_INTEGER_CHECK("i", c64_i), 1, 5, 1, 0) - 1];
    _SFD_EML_CALL(0U, chartInstance->c64_sfEvent, 16);
    c64_b_dVel_Array[_SFD_EML_ARRAY_BOUNDS_CHECK("dVel_Array", (int32_T)
      _SFD_INTEGER_CHECK("i + length(pedR_self)", c64_i + 5.0), 1, 32, 1, 0) - 1]
      = c64_b_dVel_rcvd[_SFD_EML_ARRAY_BOUNDS_CHECK("dVel_rcvd", (int32_T)
      _SFD_INTEGER_CHECK("i", c64_i), 1, 5, 1, 0) - 1];
    c64_c_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 1, 0);
  _SFD_EML_CALL(0U, chartInstance->c64_sfEvent, -16);
  _SFD_SYMBOL_SCOPE_POP();
  for (c64_i16 = 0; c64_i16 < 32; c64_i16++) {
    (*chartInstance->c64_pedR_Array)[c64_i16] = c64_b_pedR_Array[c64_i16];
  }

  for (c64_i17 = 0; c64_i17 < 32; c64_i17++) {
    (*chartInstance->c64_pedTheta_Array)[c64_i17] = c64_b_pedTheta_Array[c64_i17];
  }

  for (c64_i18 = 0; c64_i18 < 32; c64_i18++) {
    (*chartInstance->c64_dVel_Array)[c64_i18] = c64_b_dVel_Array[c64_i18];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 58U, chartInstance->c64_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_3_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c64_i19 = 0; c64_i19 < 32; c64_i19++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c64_pedR_Array)[c64_i19], 1U);
  }

  for (c64_i20 = 0; c64_i20 < 5; c64_i20++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c64_pedTheta_self)[c64_i20], 2U);
  }

  for (c64_i21 = 0; c64_i21 < 5; c64_i21++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c64_dVel_self)[c64_i21], 3U);
  }

  for (c64_i22 = 0; c64_i22 < 32; c64_i22++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c64_pedTheta_Array)[c64_i22], 4U);
  }

  for (c64_i23 = 0; c64_i23 < 32; c64_i23++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c64_dVel_Array)[c64_i23], 5U);
  }

  for (c64_i24 = 0; c64_i24 < 5; c64_i24++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c64_pedR_rcvd)[c64_i24], 6U);
  }

  for (c64_i25 = 0; c64_i25 < 5; c64_i25++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c64_pedTheta_rcvd)[c64_i25], 7U);
  }

  for (c64_i26 = 0; c64_i26 < 5; c64_i26++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c64_dVel_rcvd)[c64_i26], 8U);
  }
}

static void mdl_start_c64_Experiment_3_cs(SFc64_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc64_Experiment_3_cs
  (SFc64_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c64_machineNumber, uint32_T
  c64_chartNumber, uint32_T c64_instanceNumber)
{
  (void)c64_machineNumber;
  (void)c64_chartNumber;
  (void)c64_instanceNumber;
}

static const mxArray *c64_sf_marshallOut(void *chartInstanceVoid, void
  *c64_inData)
{
  const mxArray *c64_mxArrayOutData = NULL;
  int32_T c64_i27;
  real_T c64_b_inData[32];
  int32_T c64_i28;
  real_T c64_u[32];
  const mxArray *c64_y = NULL;
  SFc64_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc64_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c64_mxArrayOutData = NULL;
  for (c64_i27 = 0; c64_i27 < 32; c64_i27++) {
    c64_b_inData[c64_i27] = (*(real_T (*)[32])c64_inData)[c64_i27];
  }

  for (c64_i28 = 0; c64_i28 < 32; c64_i28++) {
    c64_u[c64_i28] = c64_b_inData[c64_i28];
  }

  c64_y = NULL;
  sf_mex_assign(&c64_y, sf_mex_create("y", c64_u, 0, 0U, 1U, 0U, 1, 32), false);
  sf_mex_assign(&c64_mxArrayOutData, c64_y, false);
  return c64_mxArrayOutData;
}

static void c64_emlrt_marshallIn(SFc64_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c64_b_dVel_Array, const char_T *c64_identifier,
  real_T c64_y[32])
{
  emlrtMsgIdentifier c64_thisId;
  c64_thisId.fIdentifier = c64_identifier;
  c64_thisId.fParent = NULL;
  c64_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c64_b_dVel_Array),
    &c64_thisId, c64_y);
  sf_mex_destroy(&c64_b_dVel_Array);
}

static void c64_b_emlrt_marshallIn(SFc64_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c64_u, const emlrtMsgIdentifier *c64_parentId,
  real_T c64_y[32])
{
  real_T c64_dv3[32];
  int32_T c64_i29;
  (void)chartInstance;
  sf_mex_import(c64_parentId, sf_mex_dup(c64_u), c64_dv3, 1, 0, 0U, 1, 0U, 1, 32);
  for (c64_i29 = 0; c64_i29 < 32; c64_i29++) {
    c64_y[c64_i29] = c64_dv3[c64_i29];
  }

  sf_mex_destroy(&c64_u);
}

static void c64_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c64_mxArrayInData, const char_T *c64_varName, void *c64_outData)
{
  const mxArray *c64_b_dVel_Array;
  const char_T *c64_identifier;
  emlrtMsgIdentifier c64_thisId;
  real_T c64_y[32];
  int32_T c64_i30;
  SFc64_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc64_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c64_b_dVel_Array = sf_mex_dup(c64_mxArrayInData);
  c64_identifier = c64_varName;
  c64_thisId.fIdentifier = c64_identifier;
  c64_thisId.fParent = NULL;
  c64_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c64_b_dVel_Array),
    &c64_thisId, c64_y);
  sf_mex_destroy(&c64_b_dVel_Array);
  for (c64_i30 = 0; c64_i30 < 32; c64_i30++) {
    (*(real_T (*)[32])c64_outData)[c64_i30] = c64_y[c64_i30];
  }

  sf_mex_destroy(&c64_mxArrayInData);
}

static const mxArray *c64_b_sf_marshallOut(void *chartInstanceVoid, void
  *c64_inData)
{
  const mxArray *c64_mxArrayOutData = NULL;
  int32_T c64_i31;
  real_T c64_b_inData[5];
  int32_T c64_i32;
  real_T c64_u[5];
  const mxArray *c64_y = NULL;
  SFc64_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc64_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c64_mxArrayOutData = NULL;
  for (c64_i31 = 0; c64_i31 < 5; c64_i31++) {
    c64_b_inData[c64_i31] = (*(real_T (*)[5])c64_inData)[c64_i31];
  }

  for (c64_i32 = 0; c64_i32 < 5; c64_i32++) {
    c64_u[c64_i32] = c64_b_inData[c64_i32];
  }

  c64_y = NULL;
  sf_mex_assign(&c64_y, sf_mex_create("y", c64_u, 0, 0U, 1U, 0U, 1, 5), false);
  sf_mex_assign(&c64_mxArrayOutData, c64_y, false);
  return c64_mxArrayOutData;
}

static const mxArray *c64_c_sf_marshallOut(void *chartInstanceVoid, void
  *c64_inData)
{
  const mxArray *c64_mxArrayOutData = NULL;
  real_T c64_u;
  const mxArray *c64_y = NULL;
  SFc64_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc64_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c64_mxArrayOutData = NULL;
  c64_u = *(real_T *)c64_inData;
  c64_y = NULL;
  sf_mex_assign(&c64_y, sf_mex_create("y", &c64_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c64_mxArrayOutData, c64_y, false);
  return c64_mxArrayOutData;
}

static real_T c64_c_emlrt_marshallIn(SFc64_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c64_u, const emlrtMsgIdentifier *c64_parentId)
{
  real_T c64_y;
  real_T c64_d0;
  (void)chartInstance;
  sf_mex_import(c64_parentId, sf_mex_dup(c64_u), &c64_d0, 1, 0, 0U, 0, 0U, 0);
  c64_y = c64_d0;
  sf_mex_destroy(&c64_u);
  return c64_y;
}

static void c64_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c64_mxArrayInData, const char_T *c64_varName, void *c64_outData)
{
  const mxArray *c64_nargout;
  const char_T *c64_identifier;
  emlrtMsgIdentifier c64_thisId;
  real_T c64_y;
  SFc64_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc64_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c64_nargout = sf_mex_dup(c64_mxArrayInData);
  c64_identifier = c64_varName;
  c64_thisId.fIdentifier = c64_identifier;
  c64_thisId.fParent = NULL;
  c64_y = c64_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c64_nargout),
    &c64_thisId);
  sf_mex_destroy(&c64_nargout);
  *(real_T *)c64_outData = c64_y;
  sf_mex_destroy(&c64_mxArrayInData);
}

const mxArray *sf_c64_Experiment_3_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c64_nameCaptureInfo = NULL;
  c64_nameCaptureInfo = NULL;
  sf_mex_assign(&c64_nameCaptureInfo, sf_mex_createstruct("structure", 2, 1, 1),
                false);
  c64_info_helper(&c64_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c64_nameCaptureInfo);
  return c64_nameCaptureInfo;
}

static void c64_info_helper(const mxArray **c64_info)
{
  const mxArray *c64_rhs0 = NULL;
  const mxArray *c64_lhs0 = NULL;
  sf_mex_addfield(*c64_info, c64_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c64_info, c64_emlrt_marshallOut("length"), "name", "name", 0);
  sf_mex_addfield(*c64_info, c64_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c64_info, c64_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c64_info, c64_b_emlrt_marshallOut(1303167806U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c64_info, c64_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c64_info, c64_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c64_info, c64_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c64_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c64_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c64_info, sf_mex_duplicatearraysafe(&c64_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c64_info, sf_mex_duplicatearraysafe(&c64_lhs0), "lhs", "lhs",
                  0);
  sf_mex_destroy(&c64_rhs0);
  sf_mex_destroy(&c64_lhs0);
}

static const mxArray *c64_emlrt_marshallOut(const char * c64_u)
{
  const mxArray *c64_y = NULL;
  c64_y = NULL;
  sf_mex_assign(&c64_y, sf_mex_create("y", c64_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c64_u)), false);
  return c64_y;
}

static const mxArray *c64_b_emlrt_marshallOut(const uint32_T c64_u)
{
  const mxArray *c64_y = NULL;
  c64_y = NULL;
  sf_mex_assign(&c64_y, sf_mex_create("y", &c64_u, 7, 0U, 0U, 0U, 0), false);
  return c64_y;
}

static const mxArray *c64_d_sf_marshallOut(void *chartInstanceVoid, void
  *c64_inData)
{
  const mxArray *c64_mxArrayOutData = NULL;
  int32_T c64_u;
  const mxArray *c64_y = NULL;
  SFc64_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc64_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c64_mxArrayOutData = NULL;
  c64_u = *(int32_T *)c64_inData;
  c64_y = NULL;
  sf_mex_assign(&c64_y, sf_mex_create("y", &c64_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c64_mxArrayOutData, c64_y, false);
  return c64_mxArrayOutData;
}

static int32_T c64_d_emlrt_marshallIn(SFc64_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c64_u, const emlrtMsgIdentifier *c64_parentId)
{
  int32_T c64_y;
  int32_T c64_i33;
  (void)chartInstance;
  sf_mex_import(c64_parentId, sf_mex_dup(c64_u), &c64_i33, 1, 6, 0U, 0, 0U, 0);
  c64_y = c64_i33;
  sf_mex_destroy(&c64_u);
  return c64_y;
}

static void c64_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c64_mxArrayInData, const char_T *c64_varName, void *c64_outData)
{
  const mxArray *c64_b_sfEvent;
  const char_T *c64_identifier;
  emlrtMsgIdentifier c64_thisId;
  int32_T c64_y;
  SFc64_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc64_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c64_b_sfEvent = sf_mex_dup(c64_mxArrayInData);
  c64_identifier = c64_varName;
  c64_thisId.fIdentifier = c64_identifier;
  c64_thisId.fParent = NULL;
  c64_y = c64_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c64_b_sfEvent),
    &c64_thisId);
  sf_mex_destroy(&c64_b_sfEvent);
  *(int32_T *)c64_outData = c64_y;
  sf_mex_destroy(&c64_mxArrayInData);
}

static uint8_T c64_e_emlrt_marshallIn(SFc64_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c64_b_is_active_c64_Experiment_3_cs, const
  char_T *c64_identifier)
{
  uint8_T c64_y;
  emlrtMsgIdentifier c64_thisId;
  c64_thisId.fIdentifier = c64_identifier;
  c64_thisId.fParent = NULL;
  c64_y = c64_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c64_b_is_active_c64_Experiment_3_cs), &c64_thisId);
  sf_mex_destroy(&c64_b_is_active_c64_Experiment_3_cs);
  return c64_y;
}

static uint8_T c64_f_emlrt_marshallIn(SFc64_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c64_u, const emlrtMsgIdentifier *c64_parentId)
{
  uint8_T c64_y;
  uint8_T c64_u0;
  (void)chartInstance;
  sf_mex_import(c64_parentId, sf_mex_dup(c64_u), &c64_u0, 1, 3, 0U, 0, 0U, 0);
  c64_y = c64_u0;
  sf_mex_destroy(&c64_u);
  return c64_y;
}

static void init_dsm_address_info(SFc64_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc64_Experiment_3_csInstanceStruct
  *chartInstance)
{
  chartInstance->c64_pedR_self = (real_T (*)[5])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c64_pedR_Array = (real_T (*)[32])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c64_pedTheta_self = (real_T (*)[5])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c64_dVel_self = (real_T (*)[5])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c64_pedTheta_Array = (real_T (*)[32])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c64_dVel_Array = (real_T (*)[32])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c64_pedR_rcvd = (real_T (*)[5])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c64_pedTheta_rcvd = (real_T (*)[5])ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c64_dVel_rcvd = (real_T (*)[5])ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
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

void sf_c64_Experiment_3_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(944066725U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1159324729U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2936024738U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3630353878U);
}

mxArray* sf_c64_Experiment_3_cs_get_post_codegen_info(void);
mxArray *sf_c64_Experiment_3_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Zv4v1iQeOaOwMwBAe0La8G");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(5);
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
      pr[0] = (double)(5);
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
      pr[0] = (double)(5);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(5);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(5);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(5);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c64_Experiment_3_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c64_Experiment_3_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c64_Experiment_3_cs_jit_fallback_info(void)
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

mxArray *sf_c64_Experiment_3_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c64_Experiment_3_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c64_Experiment_3_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[9],T\"dVel_Array\",},{M[1],M[5],T\"pedR_Array\",},{M[1],M[8],T\"pedTheta_Array\",},{M[8],M[0],T\"is_active_c64_Experiment_3_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c64_Experiment_3_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc64_Experiment_3_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc64_Experiment_3_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_3_csMachineNumber_,
           64,
           1,
           1,
           0,
           9,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"pedR_self");
          _SFD_SET_DATA_PROPS(1,2,0,1,"pedR_Array");
          _SFD_SET_DATA_PROPS(2,1,1,0,"pedTheta_self");
          _SFD_SET_DATA_PROPS(3,1,1,0,"dVel_self");
          _SFD_SET_DATA_PROPS(4,2,0,1,"pedTheta_Array");
          _SFD_SET_DATA_PROPS(5,2,0,1,"dVel_Array");
          _SFD_SET_DATA_PROPS(6,1,1,0,"pedR_rcvd");
          _SFD_SET_DATA_PROPS(7,1,1,0,"pedTheta_rcvd");
          _SFD_SET_DATA_PROPS(8,1,1,0,"dVel_rcvd");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,2,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,547);
        _SFD_CV_INIT_EML_FOR(0,1,0,207,233,346);
        _SFD_CV_INIT_EML_FOR(0,1,1,348,374,547);

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c64_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c64_sf_marshallOut,(MexInFcnForType)
            c64_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c64_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c64_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c64_sf_marshallOut,(MexInFcnForType)
            c64_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c64_sf_marshallOut,(MexInFcnForType)
            c64_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c64_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c64_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c64_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c64_pedR_self);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c64_pedR_Array);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c64_pedTheta_self);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c64_dVel_self);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c64_pedTheta_Array);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c64_dVel_Array);
        _SFD_SET_DATA_VALUE_PTR(6U, *chartInstance->c64_pedR_rcvd);
        _SFD_SET_DATA_VALUE_PTR(7U, *chartInstance->c64_pedTheta_rcvd);
        _SFD_SET_DATA_VALUE_PTR(8U, *chartInstance->c64_dVel_rcvd);
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
  return "6ACZwPDAnXkjG0kTzKaknB";
}

static void sf_opaque_initialize_c64_Experiment_3_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc64_Experiment_3_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c64_Experiment_3_cs((SFc64_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
  initialize_c64_Experiment_3_cs((SFc64_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c64_Experiment_3_cs(void *chartInstanceVar)
{
  enable_c64_Experiment_3_cs((SFc64_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c64_Experiment_3_cs(void *chartInstanceVar)
{
  disable_c64_Experiment_3_cs((SFc64_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c64_Experiment_3_cs(void *chartInstanceVar)
{
  sf_gateway_c64_Experiment_3_cs((SFc64_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c64_Experiment_3_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c64_Experiment_3_cs((SFc64_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c64_Experiment_3_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c64_Experiment_3_cs((SFc64_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c64_Experiment_3_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc64_Experiment_3_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_3_cs_optimization_info();
    }

    finalize_c64_Experiment_3_cs((SFc64_Experiment_3_csInstanceStruct*)
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
  initSimStructsc64_Experiment_3_cs((SFc64_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c64_Experiment_3_cs(SimStruct *S)
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
    initialize_params_c64_Experiment_3_cs((SFc64_Experiment_3_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c64_Experiment_3_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Experiment_3_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      64);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,64,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,64,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,64);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,64,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,64,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,64);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2507906282U));
  ssSetChecksum1(S,(4290924402U));
  ssSetChecksum2(S,(3086807729U));
  ssSetChecksum3(S,(489827961U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c64_Experiment_3_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c64_Experiment_3_cs(SimStruct *S)
{
  SFc64_Experiment_3_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc64_Experiment_3_csInstanceStruct *)utMalloc(sizeof
    (SFc64_Experiment_3_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc64_Experiment_3_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c64_Experiment_3_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c64_Experiment_3_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c64_Experiment_3_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c64_Experiment_3_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c64_Experiment_3_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c64_Experiment_3_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c64_Experiment_3_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c64_Experiment_3_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c64_Experiment_3_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c64_Experiment_3_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c64_Experiment_3_cs;
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

void c64_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c64_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c64_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c64_Experiment_3_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c64_Experiment_3_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
