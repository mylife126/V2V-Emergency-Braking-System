/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_2_cs_sfun.h"
#include "c34_Experiment_2_cs.h"
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
static const char * c34_debug_family_names[12] = { "i", "nargin", "nargout",
  "pedR_self", "pedTheta_self", "dVel_self", "pedR_rcvd", "pedTheta_rcvd",
  "dVel_rcvd", "pedR_Array", "pedTheta_Array", "dVel_Array" };

/* Function Declarations */
static void initialize_c34_Experiment_2_cs(SFc34_Experiment_2_csInstanceStruct
  *chartInstance);
static void initialize_params_c34_Experiment_2_cs
  (SFc34_Experiment_2_csInstanceStruct *chartInstance);
static void enable_c34_Experiment_2_cs(SFc34_Experiment_2_csInstanceStruct
  *chartInstance);
static void disable_c34_Experiment_2_cs(SFc34_Experiment_2_csInstanceStruct
  *chartInstance);
static void c34_update_debugger_state_c34_Experiment_2_cs
  (SFc34_Experiment_2_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c34_Experiment_2_cs
  (SFc34_Experiment_2_csInstanceStruct *chartInstance);
static void set_sim_state_c34_Experiment_2_cs
  (SFc34_Experiment_2_csInstanceStruct *chartInstance, const mxArray *c34_st);
static void finalize_c34_Experiment_2_cs(SFc34_Experiment_2_csInstanceStruct
  *chartInstance);
static void sf_gateway_c34_Experiment_2_cs(SFc34_Experiment_2_csInstanceStruct
  *chartInstance);
static void mdl_start_c34_Experiment_2_cs(SFc34_Experiment_2_csInstanceStruct
  *chartInstance);
static void initSimStructsc34_Experiment_2_cs
  (SFc34_Experiment_2_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c34_machineNumber, uint32_T
  c34_chartNumber, uint32_T c34_instanceNumber);
static const mxArray *c34_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData);
static void c34_emlrt_marshallIn(SFc34_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c34_b_dVel_Array, const char_T *c34_identifier,
  real_T c34_y[32]);
static void c34_b_emlrt_marshallIn(SFc34_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId,
  real_T c34_y[32]);
static void c34_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData);
static const mxArray *c34_b_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData);
static const mxArray *c34_c_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData);
static real_T c34_c_emlrt_marshallIn(SFc34_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId);
static void c34_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData);
static void c34_info_helper(const mxArray **c34_info);
static const mxArray *c34_emlrt_marshallOut(const char * c34_u);
static const mxArray *c34_b_emlrt_marshallOut(const uint32_T c34_u);
static const mxArray *c34_d_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData);
static int32_T c34_d_emlrt_marshallIn(SFc34_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId);
static void c34_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData);
static uint8_T c34_e_emlrt_marshallIn(SFc34_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c34_b_is_active_c34_Experiment_2_cs, const
  char_T *c34_identifier);
static uint8_T c34_f_emlrt_marshallIn(SFc34_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId);
static void init_dsm_address_info(SFc34_Experiment_2_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc34_Experiment_2_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c34_Experiment_2_cs(SFc34_Experiment_2_csInstanceStruct
  *chartInstance)
{
  chartInstance->c34_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c34_is_active_c34_Experiment_2_cs = 0U;
}

static void initialize_params_c34_Experiment_2_cs
  (SFc34_Experiment_2_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c34_Experiment_2_cs(SFc34_Experiment_2_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c34_Experiment_2_cs(SFc34_Experiment_2_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c34_update_debugger_state_c34_Experiment_2_cs
  (SFc34_Experiment_2_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c34_Experiment_2_cs
  (SFc34_Experiment_2_csInstanceStruct *chartInstance)
{
  const mxArray *c34_st;
  const mxArray *c34_y = NULL;
  int32_T c34_i0;
  real_T c34_u[32];
  const mxArray *c34_b_y = NULL;
  int32_T c34_i1;
  real_T c34_b_u[32];
  const mxArray *c34_c_y = NULL;
  int32_T c34_i2;
  real_T c34_c_u[32];
  const mxArray *c34_d_y = NULL;
  uint8_T c34_hoistedGlobal;
  uint8_T c34_d_u;
  const mxArray *c34_e_y = NULL;
  c34_st = NULL;
  c34_st = NULL;
  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_createcellmatrix(4, 1), false);
  for (c34_i0 = 0; c34_i0 < 32; c34_i0++) {
    c34_u[c34_i0] = (*chartInstance->c34_dVel_Array)[c34_i0];
  }

  c34_b_y = NULL;
  sf_mex_assign(&c34_b_y, sf_mex_create("y", c34_u, 0, 0U, 1U, 0U, 1, 32), false);
  sf_mex_setcell(c34_y, 0, c34_b_y);
  for (c34_i1 = 0; c34_i1 < 32; c34_i1++) {
    c34_b_u[c34_i1] = (*chartInstance->c34_pedR_Array)[c34_i1];
  }

  c34_c_y = NULL;
  sf_mex_assign(&c34_c_y, sf_mex_create("y", c34_b_u, 0, 0U, 1U, 0U, 1, 32),
                false);
  sf_mex_setcell(c34_y, 1, c34_c_y);
  for (c34_i2 = 0; c34_i2 < 32; c34_i2++) {
    c34_c_u[c34_i2] = (*chartInstance->c34_pedTheta_Array)[c34_i2];
  }

  c34_d_y = NULL;
  sf_mex_assign(&c34_d_y, sf_mex_create("y", c34_c_u, 0, 0U, 1U, 0U, 1, 32),
                false);
  sf_mex_setcell(c34_y, 2, c34_d_y);
  c34_hoistedGlobal = chartInstance->c34_is_active_c34_Experiment_2_cs;
  c34_d_u = c34_hoistedGlobal;
  c34_e_y = NULL;
  sf_mex_assign(&c34_e_y, sf_mex_create("y", &c34_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c34_y, 3, c34_e_y);
  sf_mex_assign(&c34_st, c34_y, false);
  return c34_st;
}

static void set_sim_state_c34_Experiment_2_cs
  (SFc34_Experiment_2_csInstanceStruct *chartInstance, const mxArray *c34_st)
{
  const mxArray *c34_u;
  real_T c34_dv0[32];
  int32_T c34_i3;
  real_T c34_dv1[32];
  int32_T c34_i4;
  real_T c34_dv2[32];
  int32_T c34_i5;
  chartInstance->c34_doneDoubleBufferReInit = true;
  c34_u = sf_mex_dup(c34_st);
  c34_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c34_u, 0)),
                       "dVel_Array", c34_dv0);
  for (c34_i3 = 0; c34_i3 < 32; c34_i3++) {
    (*chartInstance->c34_dVel_Array)[c34_i3] = c34_dv0[c34_i3];
  }

  c34_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c34_u, 1)),
                       "pedR_Array", c34_dv1);
  for (c34_i4 = 0; c34_i4 < 32; c34_i4++) {
    (*chartInstance->c34_pedR_Array)[c34_i4] = c34_dv1[c34_i4];
  }

  c34_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c34_u, 2)),
                       "pedTheta_Array", c34_dv2);
  for (c34_i5 = 0; c34_i5 < 32; c34_i5++) {
    (*chartInstance->c34_pedTheta_Array)[c34_i5] = c34_dv2[c34_i5];
  }

  chartInstance->c34_is_active_c34_Experiment_2_cs = c34_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c34_u, 3)),
     "is_active_c34_Experiment_2_cs");
  sf_mex_destroy(&c34_u);
  c34_update_debugger_state_c34_Experiment_2_cs(chartInstance);
  sf_mex_destroy(&c34_st);
}

static void finalize_c34_Experiment_2_cs(SFc34_Experiment_2_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c34_Experiment_2_cs(SFc34_Experiment_2_csInstanceStruct
  *chartInstance)
{
  int32_T c34_i6;
  int32_T c34_i7;
  real_T c34_b_pedR_self[3];
  int32_T c34_i8;
  real_T c34_b_pedTheta_self[3];
  int32_T c34_i9;
  real_T c34_b_dVel_self[3];
  int32_T c34_i10;
  real_T c34_b_pedR_rcvd[3];
  int32_T c34_i11;
  real_T c34_b_pedTheta_rcvd[3];
  int32_T c34_i12;
  real_T c34_b_dVel_rcvd[3];
  uint32_T c34_debug_family_var_map[12];
  real_T c34_i;
  real_T c34_nargin = 6.0;
  real_T c34_nargout = 3.0;
  real_T c34_b_pedR_Array[32];
  real_T c34_b_pedTheta_Array[32];
  real_T c34_b_dVel_Array[32];
  int32_T c34_i13;
  int32_T c34_i14;
  int32_T c34_i15;
  int32_T c34_b_i;
  int32_T c34_c_i;
  int32_T c34_i16;
  int32_T c34_i17;
  int32_T c34_i18;
  int32_T c34_i19;
  int32_T c34_i20;
  int32_T c34_i21;
  int32_T c34_i22;
  int32_T c34_i23;
  int32_T c34_i24;
  int32_T c34_i25;
  int32_T c34_i26;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 33U, chartInstance->c34_sfEvent);
  for (c34_i6 = 0; c34_i6 < 3; c34_i6++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c34_pedR_self)[c34_i6], 0U);
  }

  chartInstance->c34_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 33U, chartInstance->c34_sfEvent);
  for (c34_i7 = 0; c34_i7 < 3; c34_i7++) {
    c34_b_pedR_self[c34_i7] = (*chartInstance->c34_pedR_self)[c34_i7];
  }

  for (c34_i8 = 0; c34_i8 < 3; c34_i8++) {
    c34_b_pedTheta_self[c34_i8] = (*chartInstance->c34_pedTheta_self)[c34_i8];
  }

  for (c34_i9 = 0; c34_i9 < 3; c34_i9++) {
    c34_b_dVel_self[c34_i9] = (*chartInstance->c34_dVel_self)[c34_i9];
  }

  for (c34_i10 = 0; c34_i10 < 3; c34_i10++) {
    c34_b_pedR_rcvd[c34_i10] = (*chartInstance->c34_pedR_rcvd)[c34_i10];
  }

  for (c34_i11 = 0; c34_i11 < 3; c34_i11++) {
    c34_b_pedTheta_rcvd[c34_i11] = (*chartInstance->c34_pedTheta_rcvd)[c34_i11];
  }

  for (c34_i12 = 0; c34_i12 < 3; c34_i12++) {
    c34_b_dVel_rcvd[c34_i12] = (*chartInstance->c34_dVel_rcvd)[c34_i12];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c34_debug_family_names,
    c34_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c34_i, 0U, c34_c_sf_marshallOut,
    c34_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c34_nargin, 1U, c34_c_sf_marshallOut,
    c34_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c34_nargout, 2U, c34_c_sf_marshallOut,
    c34_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c34_b_pedR_self, 3U, c34_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c34_b_pedTheta_self, 4U, c34_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c34_b_dVel_self, 5U, c34_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c34_b_pedR_rcvd, 6U, c34_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c34_b_pedTheta_rcvd, 7U, c34_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c34_b_dVel_rcvd, 8U, c34_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c34_b_pedR_Array, 9U, c34_sf_marshallOut,
    c34_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c34_b_pedTheta_Array, 10U,
    c34_sf_marshallOut, c34_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c34_b_dVel_Array, 11U, c34_sf_marshallOut,
    c34_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 3);
  for (c34_i13 = 0; c34_i13 < 32; c34_i13++) {
    c34_b_pedR_Array[c34_i13] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 4);
  for (c34_i14 = 0; c34_i14 < 32; c34_i14++) {
    c34_b_pedTheta_Array[c34_i14] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 5);
  for (c34_i15 = 0; c34_i15 < 32; c34_i15++) {
    c34_b_dVel_Array[c34_i15] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 7);
  c34_i = 1.0;
  c34_b_i = 0;
  while (c34_b_i < 3) {
    c34_i = 1.0 + (real_T)c34_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 8);
    c34_b_pedR_Array[_SFD_EML_ARRAY_BOUNDS_CHECK("pedR_Array", (int32_T)
      _SFD_INTEGER_CHECK("i", c34_i), 1, 32, 1, 0) - 1] =
      c34_b_pedR_self[_SFD_EML_ARRAY_BOUNDS_CHECK("pedR_self", (int32_T)
      _SFD_INTEGER_CHECK("i", c34_i), 1, 3, 1, 0) - 1];
    _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 9);
    c34_b_pedTheta_Array[_SFD_EML_ARRAY_BOUNDS_CHECK("pedTheta_Array", (int32_T)
      _SFD_INTEGER_CHECK("i", c34_i), 1, 32, 1, 0) - 1] =
      c34_b_pedTheta_self[_SFD_EML_ARRAY_BOUNDS_CHECK("pedTheta_self", (int32_T)
      _SFD_INTEGER_CHECK("i", c34_i), 1, 3, 1, 0) - 1];
    _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 10);
    c34_b_dVel_Array[_SFD_EML_ARRAY_BOUNDS_CHECK("dVel_Array", (int32_T)
      _SFD_INTEGER_CHECK("i", c34_i), 1, 32, 1, 0) - 1] =
      c34_b_dVel_self[_SFD_EML_ARRAY_BOUNDS_CHECK("dVel_self", (int32_T)
      _SFD_INTEGER_CHECK("i", c34_i), 1, 3, 1, 0) - 1];
    c34_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 13);
  c34_i = 1.0;
  c34_c_i = 0;
  while (c34_c_i < 3) {
    c34_i = 1.0 + (real_T)c34_c_i;
    CV_EML_FOR(0, 1, 1, 1);
    _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 14);
    c34_b_pedR_Array[_SFD_EML_ARRAY_BOUNDS_CHECK("pedR_Array", (int32_T)
      _SFD_INTEGER_CHECK("i + length(pedR_self)", c34_i + 3.0), 1, 32, 1, 0) - 1]
      = c34_b_pedR_rcvd[_SFD_EML_ARRAY_BOUNDS_CHECK("pedR_rcvd", (int32_T)
      _SFD_INTEGER_CHECK("i", c34_i), 1, 3, 1, 0) - 1];
    _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 15);
    c34_b_pedTheta_Array[_SFD_EML_ARRAY_BOUNDS_CHECK("pedTheta_Array", (int32_T)
      _SFD_INTEGER_CHECK("i + length(pedR_self)", c34_i + 3.0), 1, 32, 1, 0) - 1]
      = c34_b_pedTheta_rcvd[_SFD_EML_ARRAY_BOUNDS_CHECK("pedTheta_rcvd",
      (int32_T)_SFD_INTEGER_CHECK("i", c34_i), 1, 3, 1, 0) - 1];
    _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 16);
    c34_b_dVel_Array[_SFD_EML_ARRAY_BOUNDS_CHECK("dVel_Array", (int32_T)
      _SFD_INTEGER_CHECK("i + length(pedR_self)", c34_i + 3.0), 1, 32, 1, 0) - 1]
      = c34_b_dVel_rcvd[_SFD_EML_ARRAY_BOUNDS_CHECK("dVel_rcvd", (int32_T)
      _SFD_INTEGER_CHECK("i", c34_i), 1, 3, 1, 0) - 1];
    c34_c_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 1, 0);
  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, -16);
  _SFD_SYMBOL_SCOPE_POP();
  for (c34_i16 = 0; c34_i16 < 32; c34_i16++) {
    (*chartInstance->c34_pedR_Array)[c34_i16] = c34_b_pedR_Array[c34_i16];
  }

  for (c34_i17 = 0; c34_i17 < 32; c34_i17++) {
    (*chartInstance->c34_pedTheta_Array)[c34_i17] = c34_b_pedTheta_Array[c34_i17];
  }

  for (c34_i18 = 0; c34_i18 < 32; c34_i18++) {
    (*chartInstance->c34_dVel_Array)[c34_i18] = c34_b_dVel_Array[c34_i18];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 33U, chartInstance->c34_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_2_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c34_i19 = 0; c34_i19 < 32; c34_i19++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c34_pedR_Array)[c34_i19], 1U);
  }

  for (c34_i20 = 0; c34_i20 < 3; c34_i20++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c34_pedTheta_self)[c34_i20], 2U);
  }

  for (c34_i21 = 0; c34_i21 < 3; c34_i21++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c34_dVel_self)[c34_i21], 3U);
  }

  for (c34_i22 = 0; c34_i22 < 32; c34_i22++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c34_pedTheta_Array)[c34_i22], 4U);
  }

  for (c34_i23 = 0; c34_i23 < 32; c34_i23++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c34_dVel_Array)[c34_i23], 5U);
  }

  for (c34_i24 = 0; c34_i24 < 3; c34_i24++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c34_pedR_rcvd)[c34_i24], 6U);
  }

  for (c34_i25 = 0; c34_i25 < 3; c34_i25++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c34_pedTheta_rcvd)[c34_i25], 7U);
  }

  for (c34_i26 = 0; c34_i26 < 3; c34_i26++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c34_dVel_rcvd)[c34_i26], 8U);
  }
}

static void mdl_start_c34_Experiment_2_cs(SFc34_Experiment_2_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc34_Experiment_2_cs
  (SFc34_Experiment_2_csInstanceStruct *chartInstance)
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
  int32_T c34_i27;
  real_T c34_b_inData[32];
  int32_T c34_i28;
  real_T c34_u[32];
  const mxArray *c34_y = NULL;
  SFc34_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc34_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c34_mxArrayOutData = NULL;
  for (c34_i27 = 0; c34_i27 < 32; c34_i27++) {
    c34_b_inData[c34_i27] = (*(real_T (*)[32])c34_inData)[c34_i27];
  }

  for (c34_i28 = 0; c34_i28 < 32; c34_i28++) {
    c34_u[c34_i28] = c34_b_inData[c34_i28];
  }

  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_create("y", c34_u, 0, 0U, 1U, 0U, 1, 32), false);
  sf_mex_assign(&c34_mxArrayOutData, c34_y, false);
  return c34_mxArrayOutData;
}

static void c34_emlrt_marshallIn(SFc34_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c34_b_dVel_Array, const char_T *c34_identifier,
  real_T c34_y[32])
{
  emlrtMsgIdentifier c34_thisId;
  c34_thisId.fIdentifier = c34_identifier;
  c34_thisId.fParent = NULL;
  c34_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c34_b_dVel_Array),
    &c34_thisId, c34_y);
  sf_mex_destroy(&c34_b_dVel_Array);
}

static void c34_b_emlrt_marshallIn(SFc34_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId,
  real_T c34_y[32])
{
  real_T c34_dv3[32];
  int32_T c34_i29;
  (void)chartInstance;
  sf_mex_import(c34_parentId, sf_mex_dup(c34_u), c34_dv3, 1, 0, 0U, 1, 0U, 1, 32);
  for (c34_i29 = 0; c34_i29 < 32; c34_i29++) {
    c34_y[c34_i29] = c34_dv3[c34_i29];
  }

  sf_mex_destroy(&c34_u);
}

static void c34_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData)
{
  const mxArray *c34_b_dVel_Array;
  const char_T *c34_identifier;
  emlrtMsgIdentifier c34_thisId;
  real_T c34_y[32];
  int32_T c34_i30;
  SFc34_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc34_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c34_b_dVel_Array = sf_mex_dup(c34_mxArrayInData);
  c34_identifier = c34_varName;
  c34_thisId.fIdentifier = c34_identifier;
  c34_thisId.fParent = NULL;
  c34_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c34_b_dVel_Array),
    &c34_thisId, c34_y);
  sf_mex_destroy(&c34_b_dVel_Array);
  for (c34_i30 = 0; c34_i30 < 32; c34_i30++) {
    (*(real_T (*)[32])c34_outData)[c34_i30] = c34_y[c34_i30];
  }

  sf_mex_destroy(&c34_mxArrayInData);
}

static const mxArray *c34_b_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData)
{
  const mxArray *c34_mxArrayOutData = NULL;
  int32_T c34_i31;
  real_T c34_b_inData[3];
  int32_T c34_i32;
  real_T c34_u[3];
  const mxArray *c34_y = NULL;
  SFc34_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc34_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c34_mxArrayOutData = NULL;
  for (c34_i31 = 0; c34_i31 < 3; c34_i31++) {
    c34_b_inData[c34_i31] = (*(real_T (*)[3])c34_inData)[c34_i31];
  }

  for (c34_i32 = 0; c34_i32 < 3; c34_i32++) {
    c34_u[c34_i32] = c34_b_inData[c34_i32];
  }

  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_create("y", c34_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c34_mxArrayOutData, c34_y, false);
  return c34_mxArrayOutData;
}

static const mxArray *c34_c_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData)
{
  const mxArray *c34_mxArrayOutData = NULL;
  real_T c34_u;
  const mxArray *c34_y = NULL;
  SFc34_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc34_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c34_mxArrayOutData = NULL;
  c34_u = *(real_T *)c34_inData;
  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_create("y", &c34_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c34_mxArrayOutData, c34_y, false);
  return c34_mxArrayOutData;
}

static real_T c34_c_emlrt_marshallIn(SFc34_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId)
{
  real_T c34_y;
  real_T c34_d0;
  (void)chartInstance;
  sf_mex_import(c34_parentId, sf_mex_dup(c34_u), &c34_d0, 1, 0, 0U, 0, 0U, 0);
  c34_y = c34_d0;
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
  SFc34_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc34_Experiment_2_csInstanceStruct *)chartInstanceVoid;
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

const mxArray *sf_c34_Experiment_2_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c34_nameCaptureInfo = NULL;
  c34_nameCaptureInfo = NULL;
  sf_mex_assign(&c34_nameCaptureInfo, sf_mex_createstruct("structure", 2, 1, 1),
                false);
  c34_info_helper(&c34_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c34_nameCaptureInfo);
  return c34_nameCaptureInfo;
}

static void c34_info_helper(const mxArray **c34_info)
{
  const mxArray *c34_rhs0 = NULL;
  const mxArray *c34_lhs0 = NULL;
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("length"), "name", "name", 0);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1303167806U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c34_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs0), "lhs", "lhs",
                  0);
  sf_mex_destroy(&c34_rhs0);
  sf_mex_destroy(&c34_lhs0);
}

static const mxArray *c34_emlrt_marshallOut(const char * c34_u)
{
  const mxArray *c34_y = NULL;
  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_create("y", c34_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c34_u)), false);
  return c34_y;
}

static const mxArray *c34_b_emlrt_marshallOut(const uint32_T c34_u)
{
  const mxArray *c34_y = NULL;
  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_create("y", &c34_u, 7, 0U, 0U, 0U, 0), false);
  return c34_y;
}

static const mxArray *c34_d_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData)
{
  const mxArray *c34_mxArrayOutData = NULL;
  int32_T c34_u;
  const mxArray *c34_y = NULL;
  SFc34_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc34_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c34_mxArrayOutData = NULL;
  c34_u = *(int32_T *)c34_inData;
  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_create("y", &c34_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c34_mxArrayOutData, c34_y, false);
  return c34_mxArrayOutData;
}

static int32_T c34_d_emlrt_marshallIn(SFc34_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId)
{
  int32_T c34_y;
  int32_T c34_i33;
  (void)chartInstance;
  sf_mex_import(c34_parentId, sf_mex_dup(c34_u), &c34_i33, 1, 6, 0U, 0, 0U, 0);
  c34_y = c34_i33;
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
  SFc34_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc34_Experiment_2_csInstanceStruct *)chartInstanceVoid;
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

static uint8_T c34_e_emlrt_marshallIn(SFc34_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c34_b_is_active_c34_Experiment_2_cs, const
  char_T *c34_identifier)
{
  uint8_T c34_y;
  emlrtMsgIdentifier c34_thisId;
  c34_thisId.fIdentifier = c34_identifier;
  c34_thisId.fParent = NULL;
  c34_y = c34_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c34_b_is_active_c34_Experiment_2_cs), &c34_thisId);
  sf_mex_destroy(&c34_b_is_active_c34_Experiment_2_cs);
  return c34_y;
}

static uint8_T c34_f_emlrt_marshallIn(SFc34_Experiment_2_csInstanceStruct
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

static void init_dsm_address_info(SFc34_Experiment_2_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc34_Experiment_2_csInstanceStruct
  *chartInstance)
{
  chartInstance->c34_pedR_self = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c34_pedR_Array = (real_T (*)[32])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c34_pedTheta_self = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c34_dVel_self = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c34_pedTheta_Array = (real_T (*)[32])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c34_dVel_Array = (real_T (*)[32])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c34_pedR_rcvd = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c34_pedTheta_rcvd = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c34_dVel_rcvd = (real_T (*)[3])ssGetInputPortSignal_wrapper
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

void sf_c34_Experiment_2_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1404404892U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2582846159U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2621133154U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1290575615U);
}

mxArray* sf_c34_Experiment_2_cs_get_post_codegen_info(void);
mxArray *sf_c34_Experiment_2_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("3zfgzZNcjUxZWQjhZSfhyB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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
    mxArray* mxPostCodegenInfo = sf_c34_Experiment_2_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c34_Experiment_2_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c34_Experiment_2_cs_jit_fallback_info(void)
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

mxArray *sf_c34_Experiment_2_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c34_Experiment_2_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c34_Experiment_2_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[9],T\"dVel_Array\",},{M[1],M[5],T\"pedR_Array\",},{M[1],M[8],T\"pedTheta_Array\",},{M[8],M[0],T\"is_active_c34_Experiment_2_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c34_Experiment_2_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc34_Experiment_2_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc34_Experiment_2_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_2_csMachineNumber_,
           34,
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
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c34_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c34_sf_marshallOut,(MexInFcnForType)
            c34_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c34_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c34_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c34_sf_marshallOut,(MexInFcnForType)
            c34_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c34_sf_marshallOut,(MexInFcnForType)
            c34_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c34_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c34_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c34_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c34_pedR_self);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c34_pedR_Array);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c34_pedTheta_self);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c34_dVel_self);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c34_pedTheta_Array);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c34_dVel_Array);
        _SFD_SET_DATA_VALUE_PTR(6U, *chartInstance->c34_pedR_rcvd);
        _SFD_SET_DATA_VALUE_PTR(7U, *chartInstance->c34_pedTheta_rcvd);
        _SFD_SET_DATA_VALUE_PTR(8U, *chartInstance->c34_dVel_rcvd);
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
  return "ph1BRMFnYbOwNGiOJ5CxpG";
}

static void sf_opaque_initialize_c34_Experiment_2_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc34_Experiment_2_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c34_Experiment_2_cs((SFc34_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
  initialize_c34_Experiment_2_cs((SFc34_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c34_Experiment_2_cs(void *chartInstanceVar)
{
  enable_c34_Experiment_2_cs((SFc34_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c34_Experiment_2_cs(void *chartInstanceVar)
{
  disable_c34_Experiment_2_cs((SFc34_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c34_Experiment_2_cs(void *chartInstanceVar)
{
  sf_gateway_c34_Experiment_2_cs((SFc34_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c34_Experiment_2_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c34_Experiment_2_cs((SFc34_Experiment_2_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c34_Experiment_2_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c34_Experiment_2_cs((SFc34_Experiment_2_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c34_Experiment_2_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc34_Experiment_2_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_2_cs_optimization_info();
    }

    finalize_c34_Experiment_2_cs((SFc34_Experiment_2_csInstanceStruct*)
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
  initSimStructsc34_Experiment_2_cs((SFc34_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c34_Experiment_2_cs(SimStruct *S)
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
    initialize_params_c34_Experiment_2_cs((SFc34_Experiment_2_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c34_Experiment_2_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Experiment_2_cs_optimization_info();
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
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,34,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,34,3);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,34);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4117919875U));
  ssSetChecksum1(S,(4292177558U));
  ssSetChecksum2(S,(915358400U));
  ssSetChecksum3(S,(3100665399U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c34_Experiment_2_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c34_Experiment_2_cs(SimStruct *S)
{
  SFc34_Experiment_2_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc34_Experiment_2_csInstanceStruct *)utMalloc(sizeof
    (SFc34_Experiment_2_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc34_Experiment_2_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c34_Experiment_2_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c34_Experiment_2_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c34_Experiment_2_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c34_Experiment_2_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c34_Experiment_2_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c34_Experiment_2_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c34_Experiment_2_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c34_Experiment_2_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c34_Experiment_2_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c34_Experiment_2_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c34_Experiment_2_cs;
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

void c34_Experiment_2_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c34_Experiment_2_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c34_Experiment_2_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c34_Experiment_2_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c34_Experiment_2_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
