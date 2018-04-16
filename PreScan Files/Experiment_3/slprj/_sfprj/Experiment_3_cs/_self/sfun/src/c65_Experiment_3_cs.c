/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_3_cs_sfun.h"
#include "c65_Experiment_3_cs.h"
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
static const char * c65_debug_family_names[26] = { "rotMat", "sensorMat",
  "carVelX", "carVelY", "carVelMat", "carMat", "i", "Vcp", "Vdv", "nargin",
  "nargout", "carX", "carY", "carZ", "carAngle", "carVelocity", "pedX", "pedY",
  "pedZ", "dTranslationX", "dTranslationY", "dTranslationZ", "sensorX",
  "sensorY", "sensorZ", "dopplerVelocity" };

/* Function Declarations */
static void initialize_c65_Experiment_3_cs(SFc65_Experiment_3_csInstanceStruct
  *chartInstance);
static void initialize_params_c65_Experiment_3_cs
  (SFc65_Experiment_3_csInstanceStruct *chartInstance);
static void enable_c65_Experiment_3_cs(SFc65_Experiment_3_csInstanceStruct
  *chartInstance);
static void disable_c65_Experiment_3_cs(SFc65_Experiment_3_csInstanceStruct
  *chartInstance);
static void c65_update_debugger_state_c65_Experiment_3_cs
  (SFc65_Experiment_3_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c65_Experiment_3_cs
  (SFc65_Experiment_3_csInstanceStruct *chartInstance);
static void set_sim_state_c65_Experiment_3_cs
  (SFc65_Experiment_3_csInstanceStruct *chartInstance, const mxArray *c65_st);
static void finalize_c65_Experiment_3_cs(SFc65_Experiment_3_csInstanceStruct
  *chartInstance);
static void sf_gateway_c65_Experiment_3_cs(SFc65_Experiment_3_csInstanceStruct
  *chartInstance);
static void mdl_start_c65_Experiment_3_cs(SFc65_Experiment_3_csInstanceStruct
  *chartInstance);
static void c65_chartstep_c65_Experiment_3_cs
  (SFc65_Experiment_3_csInstanceStruct *chartInstance);
static void initSimStructsc65_Experiment_3_cs
  (SFc65_Experiment_3_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c65_machineNumber, uint32_T
  c65_chartNumber, uint32_T c65_instanceNumber);
static const mxArray *c65_sf_marshallOut(void *chartInstanceVoid, void
  *c65_inData);
static void c65_emlrt_marshallIn(SFc65_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c65_b_dopplerVelocity, const char_T
  *c65_identifier, real_T c65_y[5]);
static void c65_b_emlrt_marshallIn(SFc65_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c65_u, const emlrtMsgIdentifier *c65_parentId,
  real_T c65_y[5]);
static void c65_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c65_mxArrayInData, const char_T *c65_varName, void *c65_outData);
static const mxArray *c65_b_sf_marshallOut(void *chartInstanceVoid, void
  *c65_inData);
static real_T c65_c_emlrt_marshallIn(SFc65_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c65_u, const emlrtMsgIdentifier *c65_parentId);
static void c65_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c65_mxArrayInData, const char_T *c65_varName, void *c65_outData);
static const mxArray *c65_c_sf_marshallOut(void *chartInstanceVoid, void
  *c65_inData);
static void c65_d_emlrt_marshallIn(SFc65_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c65_u, const emlrtMsgIdentifier *c65_parentId,
  real_T c65_y[2]);
static void c65_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c65_mxArrayInData, const char_T *c65_varName, void *c65_outData);
static const mxArray *c65_d_sf_marshallOut(void *chartInstanceVoid, void
  *c65_inData);
static void c65_e_emlrt_marshallIn(SFc65_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c65_u, const emlrtMsgIdentifier *c65_parentId,
  real_T c65_y[4]);
static void c65_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c65_mxArrayInData, const char_T *c65_varName, void *c65_outData);
static void c65_info_helper(const mxArray **c65_info);
static const mxArray *c65_emlrt_marshallOut(const char * c65_u);
static const mxArray *c65_b_emlrt_marshallOut(const uint32_T c65_u);
static void c65_b_info_helper(const mxArray **c65_info);
static real_T c65_cosd(SFc65_Experiment_3_csInstanceStruct *chartInstance,
  real_T c65_x);
static boolean_T c65_isfinite(SFc65_Experiment_3_csInstanceStruct *chartInstance,
  real_T c65_x);
static real_T c65_rdivide(SFc65_Experiment_3_csInstanceStruct *chartInstance,
  real_T c65_x, real_T c65_y);
static real_T c65_sind(SFc65_Experiment_3_csInstanceStruct *chartInstance,
  real_T c65_x);
static void c65_eml_scalar_eg(SFc65_Experiment_3_csInstanceStruct *chartInstance);
static void c65_eml_xgemm(SFc65_Experiment_3_csInstanceStruct *chartInstance,
  real_T c65_A[4], real_T c65_B[2], real_T c65_C[2], real_T c65_b_C[2]);
static void c65_mldivide(SFc65_Experiment_3_csInstanceStruct *chartInstance,
  real_T c65_A[4], real_T c65_B[2], real_T c65_Y[2]);
static void c65_eml_warning(SFc65_Experiment_3_csInstanceStruct *chartInstance);
static real_T c65_eml_xdotc(SFc65_Experiment_3_csInstanceStruct *chartInstance,
  real_T c65_x[2], real_T c65_y[2]);
static real_T c65_eml_xnrm2(SFc65_Experiment_3_csInstanceStruct *chartInstance,
  real_T c65_x[2]);
static void c65_below_threshold(SFc65_Experiment_3_csInstanceStruct
  *chartInstance);
static const mxArray *c65_e_sf_marshallOut(void *chartInstanceVoid, void
  *c65_inData);
static int32_T c65_f_emlrt_marshallIn(SFc65_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c65_u, const emlrtMsgIdentifier *c65_parentId);
static void c65_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c65_mxArrayInData, const char_T *c65_varName, void *c65_outData);
static uint8_T c65_g_emlrt_marshallIn(SFc65_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c65_b_is_active_c65_Experiment_3_cs, const
  char_T *c65_identifier);
static uint8_T c65_h_emlrt_marshallIn(SFc65_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c65_u, const emlrtMsgIdentifier *c65_parentId);
static void c65_b_cosd(SFc65_Experiment_3_csInstanceStruct *chartInstance,
  real_T *c65_x);
static void c65_b_sind(SFc65_Experiment_3_csInstanceStruct *chartInstance,
  real_T *c65_x);
static void c65_b_eml_xgemm(SFc65_Experiment_3_csInstanceStruct *chartInstance,
  real_T c65_A[4], real_T c65_B[2], real_T c65_C[2]);
static void init_dsm_address_info(SFc65_Experiment_3_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc65_Experiment_3_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c65_Experiment_3_cs(SFc65_Experiment_3_csInstanceStruct
  *chartInstance)
{
  chartInstance->c65_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c65_is_active_c65_Experiment_3_cs = 0U;
}

static void initialize_params_c65_Experiment_3_cs
  (SFc65_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c65_Experiment_3_cs(SFc65_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c65_Experiment_3_cs(SFc65_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c65_update_debugger_state_c65_Experiment_3_cs
  (SFc65_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c65_Experiment_3_cs
  (SFc65_Experiment_3_csInstanceStruct *chartInstance)
{
  const mxArray *c65_st;
  const mxArray *c65_y = NULL;
  int32_T c65_i0;
  real_T c65_u[5];
  const mxArray *c65_b_y = NULL;
  uint8_T c65_hoistedGlobal;
  uint8_T c65_b_u;
  const mxArray *c65_c_y = NULL;
  c65_st = NULL;
  c65_st = NULL;
  c65_y = NULL;
  sf_mex_assign(&c65_y, sf_mex_createcellmatrix(2, 1), false);
  for (c65_i0 = 0; c65_i0 < 5; c65_i0++) {
    c65_u[c65_i0] = (*chartInstance->c65_dopplerVelocity)[c65_i0];
  }

  c65_b_y = NULL;
  sf_mex_assign(&c65_b_y, sf_mex_create("y", c65_u, 0, 0U, 1U, 0U, 1, 5), false);
  sf_mex_setcell(c65_y, 0, c65_b_y);
  c65_hoistedGlobal = chartInstance->c65_is_active_c65_Experiment_3_cs;
  c65_b_u = c65_hoistedGlobal;
  c65_c_y = NULL;
  sf_mex_assign(&c65_c_y, sf_mex_create("y", &c65_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c65_y, 1, c65_c_y);
  sf_mex_assign(&c65_st, c65_y, false);
  return c65_st;
}

static void set_sim_state_c65_Experiment_3_cs
  (SFc65_Experiment_3_csInstanceStruct *chartInstance, const mxArray *c65_st)
{
  const mxArray *c65_u;
  real_T c65_dv0[5];
  int32_T c65_i1;
  chartInstance->c65_doneDoubleBufferReInit = true;
  c65_u = sf_mex_dup(c65_st);
  c65_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c65_u, 0)),
                       "dopplerVelocity", c65_dv0);
  for (c65_i1 = 0; c65_i1 < 5; c65_i1++) {
    (*chartInstance->c65_dopplerVelocity)[c65_i1] = c65_dv0[c65_i1];
  }

  chartInstance->c65_is_active_c65_Experiment_3_cs = c65_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c65_u, 1)),
     "is_active_c65_Experiment_3_cs");
  sf_mex_destroy(&c65_u);
  c65_update_debugger_state_c65_Experiment_3_cs(chartInstance);
  sf_mex_destroy(&c65_st);
}

static void finalize_c65_Experiment_3_cs(SFc65_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c65_Experiment_3_cs(SFc65_Experiment_3_csInstanceStruct
  *chartInstance)
{
  int32_T c65_i2;
  int32_T c65_i3;
  int32_T c65_i4;
  int32_T c65_i5;
  int32_T c65_i6;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 39U, chartInstance->c65_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c65_carX, 0U);
  chartInstance->c65_sfEvent = CALL_EVENT;
  c65_chartstep_c65_Experiment_3_cs(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_3_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c65_i2 = 0; c65_i2 < 5; c65_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c65_dopplerVelocity)[c65_i2], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c65_carY, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c65_carZ, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c65_carAngle, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c65_carVelocity, 5U);
  for (c65_i3 = 0; c65_i3 < 5; c65_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c65_pedX)[c65_i3], 6U);
  }

  for (c65_i4 = 0; c65_i4 < 5; c65_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c65_pedY)[c65_i4], 7U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c65_pedZ, 8U);
  for (c65_i5 = 0; c65_i5 < 5; c65_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c65_dTranslationX)[c65_i5], 9U);
  }

  for (c65_i6 = 0; c65_i6 < 5; c65_i6++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c65_dTranslationY)[c65_i6], 10U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c65_dTranslationZ, 11U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c65_sensorX, 12U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c65_sensorY, 13U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c65_sensorZ, 14U);
}

static void mdl_start_c65_Experiment_3_cs(SFc65_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c65_chartstep_c65_Experiment_3_cs
  (SFc65_Experiment_3_csInstanceStruct *chartInstance)
{
  real_T c65_hoistedGlobal;
  real_T c65_b_hoistedGlobal;
  real_T c65_c_hoistedGlobal;
  real_T c65_d_hoistedGlobal;
  real_T c65_e_hoistedGlobal;
  real_T c65_f_hoistedGlobal;
  real_T c65_g_hoistedGlobal;
  real_T c65_h_hoistedGlobal;
  real_T c65_i_hoistedGlobal;
  real_T c65_j_hoistedGlobal;
  real_T c65_b_carX;
  real_T c65_b_carY;
  real_T c65_b_carZ;
  real_T c65_b_carAngle;
  real_T c65_b_carVelocity;
  int32_T c65_i7;
  real_T c65_b_pedX[5];
  int32_T c65_i8;
  real_T c65_b_pedY[5];
  real_T c65_b_pedZ;
  int32_T c65_i9;
  real_T c65_b_dTranslationX[5];
  int32_T c65_i10;
  real_T c65_b_dTranslationY[5];
  real_T c65_b_dTranslationZ;
  real_T c65_b_sensorX;
  real_T c65_b_sensorY;
  real_T c65_b_sensorZ;
  uint32_T c65_debug_family_var_map[26];
  real_T c65_rotMat[4];
  real_T c65_sensorMat[2];
  real_T c65_carVelX;
  real_T c65_carVelY;
  real_T c65_carVelMat[2];
  real_T c65_carMat[2];
  real_T c65_i;
  real_T c65_Vcp[2];
  real_T c65_Vdv[2];
  real_T c65_nargin = 14.0;
  real_T c65_nargout = 1.0;
  real_T c65_b_dopplerVelocity[5];
  real_T c65_d0;
  real_T c65_d1;
  real_T c65_d2;
  real_T c65_d3;
  int32_T c65_i11;
  real_T c65_a[4];
  real_T c65_b[2];
  int32_T c65_i12;
  int32_T c65_i13;
  real_T c65_b_a[2];
  int32_T c65_i14;
  real_T c65_c_a[4];
  int32_T c65_i15;
  real_T c65_b_b[2];
  int32_T c65_i16;
  real_T c65_d4;
  real_T c65_d5;
  int32_T c65_i17;
  real_T c65_b_rotMat[4];
  real_T c65_b_carVelX[2];
  real_T c65_dv1[2];
  int32_T c65_i18;
  int32_T c65_i19;
  int32_T c65_b_i;
  int32_T c65_i20;
  real_T c65_c_rotMat[4];
  real_T c65_c_dTranslationX[2];
  real_T c65_dv2[2];
  int32_T c65_i21;
  int32_T c65_i22;
  int32_T c65_i23;
  real_T c65_d_rotMat[4];
  int32_T c65_i24;
  real_T c65_b_Vcp[2];
  real_T c65_dv3[2];
  int32_T c65_i25;
  int32_T c65_i26;
  int32_T c65_i27;
  int32_T c65_i28;
  real_T c65_d_a[2];
  int32_T c65_i29;
  real_T c65_c_b[2];
  real_T c65_c;
  int32_T c65_i30;
  int32_T c65_i31;
  real_T c65_e_a[2];
  real_T c65_y;
  real_T c65_A;
  real_T c65_B;
  real_T c65_b_y;
  int32_T c65_i32;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 39U, chartInstance->c65_sfEvent);
  c65_hoistedGlobal = *chartInstance->c65_carX;
  c65_b_hoistedGlobal = *chartInstance->c65_carY;
  c65_c_hoistedGlobal = *chartInstance->c65_carZ;
  c65_d_hoistedGlobal = *chartInstance->c65_carAngle;
  c65_e_hoistedGlobal = *chartInstance->c65_carVelocity;
  c65_f_hoistedGlobal = *chartInstance->c65_pedZ;
  c65_g_hoistedGlobal = *chartInstance->c65_dTranslationZ;
  c65_h_hoistedGlobal = *chartInstance->c65_sensorX;
  c65_i_hoistedGlobal = *chartInstance->c65_sensorY;
  c65_j_hoistedGlobal = *chartInstance->c65_sensorZ;
  c65_b_carX = c65_hoistedGlobal;
  c65_b_carY = c65_b_hoistedGlobal;
  c65_b_carZ = c65_c_hoistedGlobal;
  c65_b_carAngle = c65_d_hoistedGlobal;
  c65_b_carVelocity = c65_e_hoistedGlobal;
  for (c65_i7 = 0; c65_i7 < 5; c65_i7++) {
    c65_b_pedX[c65_i7] = (*chartInstance->c65_pedX)[c65_i7];
  }

  for (c65_i8 = 0; c65_i8 < 5; c65_i8++) {
    c65_b_pedY[c65_i8] = (*chartInstance->c65_pedY)[c65_i8];
  }

  c65_b_pedZ = c65_f_hoistedGlobal;
  for (c65_i9 = 0; c65_i9 < 5; c65_i9++) {
    c65_b_dTranslationX[c65_i9] = (*chartInstance->c65_dTranslationX)[c65_i9];
  }

  for (c65_i10 = 0; c65_i10 < 5; c65_i10++) {
    c65_b_dTranslationY[c65_i10] = (*chartInstance->c65_dTranslationY)[c65_i10];
  }

  c65_b_dTranslationZ = c65_g_hoistedGlobal;
  c65_b_sensorX = c65_h_hoistedGlobal;
  c65_b_sensorY = c65_i_hoistedGlobal;
  c65_b_sensorZ = c65_j_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 26U, 26U, c65_debug_family_names,
    c65_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c65_rotMat, 0U, c65_d_sf_marshallOut,
    c65_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c65_sensorMat, 1U, c65_c_sf_marshallOut,
    c65_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c65_carVelX, 2U, c65_b_sf_marshallOut,
    c65_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c65_carVelY, 3U, c65_b_sf_marshallOut,
    c65_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c65_carVelMat, 4U, c65_c_sf_marshallOut,
    c65_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c65_carMat, 5U, c65_c_sf_marshallOut,
    c65_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c65_i, 6U, c65_b_sf_marshallOut,
    c65_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c65_Vcp, 7U, c65_c_sf_marshallOut,
    c65_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c65_Vdv, 8U, c65_c_sf_marshallOut,
    c65_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c65_nargin, 9U, c65_b_sf_marshallOut,
    c65_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c65_nargout, 10U, c65_b_sf_marshallOut,
    c65_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c65_b_carX, 11U, c65_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c65_b_carY, 12U, c65_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c65_b_carZ, 13U, c65_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c65_b_carAngle, 14U, c65_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c65_b_carVelocity, 15U, c65_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c65_b_pedX, 16U, c65_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c65_b_pedY, 17U, c65_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c65_b_pedZ, 18U, c65_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c65_b_dTranslationX, 19U, c65_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c65_b_dTranslationY, 20U, c65_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c65_b_dTranslationZ, 21U, c65_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c65_b_sensorX, 22U, c65_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c65_b_sensorY, 23U, c65_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c65_b_sensorZ, 24U, c65_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c65_b_dopplerVelocity, 25U,
    c65_sf_marshallOut, c65_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c65_sfEvent, 3);
  c65_d0 = c65_b_carAngle;
  c65_b_cosd(chartInstance, &c65_d0);
  c65_d1 = c65_b_carAngle;
  c65_b_sind(chartInstance, &c65_d1);
  c65_d2 = c65_b_carAngle;
  c65_b_sind(chartInstance, &c65_d2);
  c65_d3 = c65_b_carAngle;
  c65_b_cosd(chartInstance, &c65_d3);
  c65_rotMat[0] = c65_d0;
  c65_rotMat[2] = -c65_d1;
  c65_rotMat[1] = c65_d2;
  c65_rotMat[3] = c65_d3;
  _SFD_EML_CALL(0U, chartInstance->c65_sfEvent, 6);
  for (c65_i11 = 0; c65_i11 < 4; c65_i11++) {
    c65_a[c65_i11] = c65_rotMat[c65_i11];
  }

  c65_b[0] = c65_b_sensorX;
  c65_b[1] = c65_b_sensorY;
  c65_eml_scalar_eg(chartInstance);
  c65_eml_scalar_eg(chartInstance);
  for (c65_i12 = 0; c65_i12 < 2; c65_i12++) {
    c65_sensorMat[c65_i12] = 0.0;
  }

  for (c65_i13 = 0; c65_i13 < 2; c65_i13++) {
    c65_b_a[c65_i13] = 0.0;
  }

  for (c65_i14 = 0; c65_i14 < 4; c65_i14++) {
    c65_c_a[c65_i14] = c65_a[c65_i14];
  }

  for (c65_i15 = 0; c65_i15 < 2; c65_i15++) {
    c65_b_b[c65_i15] = c65_b[c65_i15];
  }

  c65_b_eml_xgemm(chartInstance, c65_c_a, c65_b_b, c65_b_a);
  for (c65_i16 = 0; c65_i16 < 2; c65_i16++) {
    c65_sensorMat[c65_i16] = c65_b_a[c65_i16];
  }

  _SFD_EML_CALL(0U, chartInstance->c65_sfEvent, 8);
  c65_d4 = c65_b_carAngle;
  c65_b_cosd(chartInstance, &c65_d4);
  c65_carVelX = c65_b_carVelocity * c65_d4;
  _SFD_EML_CALL(0U, chartInstance->c65_sfEvent, 9);
  c65_d5 = c65_b_carAngle;
  c65_b_sind(chartInstance, &c65_d5);
  c65_carVelY = c65_b_carVelocity * c65_d5;
  _SFD_EML_CALL(0U, chartInstance->c65_sfEvent, 11);
  for (c65_i17 = 0; c65_i17 < 4; c65_i17++) {
    c65_b_rotMat[c65_i17] = c65_rotMat[c65_i17];
  }

  c65_b_carVelX[0] = c65_carVelX;
  c65_b_carVelX[1] = c65_carVelY;
  c65_mldivide(chartInstance, c65_b_rotMat, c65_b_carVelX, c65_dv1);
  for (c65_i18 = 0; c65_i18 < 2; c65_i18++) {
    c65_carVelMat[c65_i18] = c65_dv1[c65_i18];
  }

  _SFD_EML_CALL(0U, chartInstance->c65_sfEvent, 13);
  c65_carMat[0] = c65_b_carX + c65_sensorMat[0];
  c65_carMat[1] = c65_b_carY + c65_sensorMat[1];
  _SFD_EML_CALL(0U, chartInstance->c65_sfEvent, 15);
  for (c65_i19 = 0; c65_i19 < 5; c65_i19++) {
    c65_b_dopplerVelocity[c65_i19] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c65_sfEvent, 17);
  c65_i = 1.0;
  c65_b_i = 0;
  while (c65_b_i < 5) {
    c65_i = 1.0 + (real_T)c65_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c65_sfEvent, 19);
    c65_Vcp[0] = c65_b_pedX[_SFD_EML_ARRAY_BOUNDS_CHECK("pedX", (int32_T)
      _SFD_INTEGER_CHECK("i", c65_i), 1, 5, 1, 0) - 1] - c65_carMat[0];
    c65_Vcp[1] = c65_b_pedY[_SFD_EML_ARRAY_BOUNDS_CHECK("pedY", (int32_T)
      _SFD_INTEGER_CHECK("i", c65_i), 1, 5, 1, 0) - 1] - c65_carMat[1];
    _SFD_EML_CALL(0U, chartInstance->c65_sfEvent, 21);
    for (c65_i20 = 0; c65_i20 < 4; c65_i20++) {
      c65_c_rotMat[c65_i20] = c65_rotMat[c65_i20];
    }

    c65_c_dTranslationX[0] = c65_b_dTranslationX[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "dTranslationX", (int32_T)_SFD_INTEGER_CHECK("i", c65_i), 1, 5, 1, 0) - 1];
    c65_c_dTranslationX[1] = c65_b_dTranslationY[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "dTranslationY", (int32_T)_SFD_INTEGER_CHECK("i", c65_i), 1, 5, 1, 0) - 1];
    c65_mldivide(chartInstance, c65_c_rotMat, c65_c_dTranslationX, c65_dv2);
    for (c65_i21 = 0; c65_i21 < 2; c65_i21++) {
      c65_Vdv[c65_i21] = c65_dv2[c65_i21];
    }

    _SFD_EML_CALL(0U, chartInstance->c65_sfEvent, 23);
    for (c65_i22 = 0; c65_i22 < 2; c65_i22++) {
      c65_Vdv[c65_i22] -= c65_carVelMat[c65_i22];
    }

    _SFD_EML_CALL(0U, chartInstance->c65_sfEvent, 25);
    for (c65_i23 = 0; c65_i23 < 4; c65_i23++) {
      c65_d_rotMat[c65_i23] = c65_rotMat[c65_i23];
    }

    for (c65_i24 = 0; c65_i24 < 2; c65_i24++) {
      c65_b_Vcp[c65_i24] = c65_Vcp[c65_i24];
    }

    c65_mldivide(chartInstance, c65_d_rotMat, c65_b_Vcp, c65_dv3);
    for (c65_i25 = 0; c65_i25 < 2; c65_i25++) {
      c65_Vcp[c65_i25] = c65_dv3[c65_i25];
    }

    _SFD_EML_CALL(0U, chartInstance->c65_sfEvent, 27);
    for (c65_i26 = 0; c65_i26 < 2; c65_i26++) {
      c65_b_a[c65_i26] = c65_Vdv[c65_i26];
    }

    for (c65_i27 = 0; c65_i27 < 2; c65_i27++) {
      c65_b[c65_i27] = c65_Vcp[c65_i27];
    }

    for (c65_i28 = 0; c65_i28 < 2; c65_i28++) {
      c65_d_a[c65_i28] = c65_b_a[c65_i28];
    }

    for (c65_i29 = 0; c65_i29 < 2; c65_i29++) {
      c65_c_b[c65_i29] = c65_b[c65_i29];
    }

    c65_c = c65_eml_xdotc(chartInstance, c65_d_a, c65_c_b);
    for (c65_i30 = 0; c65_i30 < 2; c65_i30++) {
      c65_b_a[c65_i30] = c65_Vcp[c65_i30];
    }

    for (c65_i31 = 0; c65_i31 < 2; c65_i31++) {
      c65_e_a[c65_i31] = c65_b_a[c65_i31];
    }

    c65_y = c65_eml_xnrm2(chartInstance, c65_e_a);
    c65_A = c65_c;
    c65_B = c65_y;
    c65_b_y = c65_rdivide(chartInstance, c65_A, c65_B);
    c65_b_dopplerVelocity[_SFD_EML_ARRAY_BOUNDS_CHECK("dopplerVelocity",
      (int32_T)_SFD_INTEGER_CHECK("i", c65_i), 1, 5, 1, 0) - 1] = c65_b_y;
    c65_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c65_sfEvent, -27);
  _SFD_SYMBOL_SCOPE_POP();
  for (c65_i32 = 0; c65_i32 < 5; c65_i32++) {
    (*chartInstance->c65_dopplerVelocity)[c65_i32] =
      c65_b_dopplerVelocity[c65_i32];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 39U, chartInstance->c65_sfEvent);
}

static void initSimStructsc65_Experiment_3_cs
  (SFc65_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c65_machineNumber, uint32_T
  c65_chartNumber, uint32_T c65_instanceNumber)
{
  (void)c65_machineNumber;
  (void)c65_chartNumber;
  (void)c65_instanceNumber;
}

static const mxArray *c65_sf_marshallOut(void *chartInstanceVoid, void
  *c65_inData)
{
  const mxArray *c65_mxArrayOutData = NULL;
  int32_T c65_i33;
  real_T c65_b_inData[5];
  int32_T c65_i34;
  real_T c65_u[5];
  const mxArray *c65_y = NULL;
  SFc65_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc65_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c65_mxArrayOutData = NULL;
  for (c65_i33 = 0; c65_i33 < 5; c65_i33++) {
    c65_b_inData[c65_i33] = (*(real_T (*)[5])c65_inData)[c65_i33];
  }

  for (c65_i34 = 0; c65_i34 < 5; c65_i34++) {
    c65_u[c65_i34] = c65_b_inData[c65_i34];
  }

  c65_y = NULL;
  sf_mex_assign(&c65_y, sf_mex_create("y", c65_u, 0, 0U, 1U, 0U, 1, 5), false);
  sf_mex_assign(&c65_mxArrayOutData, c65_y, false);
  return c65_mxArrayOutData;
}

static void c65_emlrt_marshallIn(SFc65_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c65_b_dopplerVelocity, const char_T
  *c65_identifier, real_T c65_y[5])
{
  emlrtMsgIdentifier c65_thisId;
  c65_thisId.fIdentifier = c65_identifier;
  c65_thisId.fParent = NULL;
  c65_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c65_b_dopplerVelocity),
    &c65_thisId, c65_y);
  sf_mex_destroy(&c65_b_dopplerVelocity);
}

static void c65_b_emlrt_marshallIn(SFc65_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c65_u, const emlrtMsgIdentifier *c65_parentId,
  real_T c65_y[5])
{
  real_T c65_dv4[5];
  int32_T c65_i35;
  (void)chartInstance;
  sf_mex_import(c65_parentId, sf_mex_dup(c65_u), c65_dv4, 1, 0, 0U, 1, 0U, 1, 5);
  for (c65_i35 = 0; c65_i35 < 5; c65_i35++) {
    c65_y[c65_i35] = c65_dv4[c65_i35];
  }

  sf_mex_destroy(&c65_u);
}

static void c65_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c65_mxArrayInData, const char_T *c65_varName, void *c65_outData)
{
  const mxArray *c65_b_dopplerVelocity;
  const char_T *c65_identifier;
  emlrtMsgIdentifier c65_thisId;
  real_T c65_y[5];
  int32_T c65_i36;
  SFc65_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc65_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c65_b_dopplerVelocity = sf_mex_dup(c65_mxArrayInData);
  c65_identifier = c65_varName;
  c65_thisId.fIdentifier = c65_identifier;
  c65_thisId.fParent = NULL;
  c65_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c65_b_dopplerVelocity),
    &c65_thisId, c65_y);
  sf_mex_destroy(&c65_b_dopplerVelocity);
  for (c65_i36 = 0; c65_i36 < 5; c65_i36++) {
    (*(real_T (*)[5])c65_outData)[c65_i36] = c65_y[c65_i36];
  }

  sf_mex_destroy(&c65_mxArrayInData);
}

static const mxArray *c65_b_sf_marshallOut(void *chartInstanceVoid, void
  *c65_inData)
{
  const mxArray *c65_mxArrayOutData = NULL;
  real_T c65_u;
  const mxArray *c65_y = NULL;
  SFc65_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc65_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c65_mxArrayOutData = NULL;
  c65_u = *(real_T *)c65_inData;
  c65_y = NULL;
  sf_mex_assign(&c65_y, sf_mex_create("y", &c65_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c65_mxArrayOutData, c65_y, false);
  return c65_mxArrayOutData;
}

static real_T c65_c_emlrt_marshallIn(SFc65_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c65_u, const emlrtMsgIdentifier *c65_parentId)
{
  real_T c65_y;
  real_T c65_d6;
  (void)chartInstance;
  sf_mex_import(c65_parentId, sf_mex_dup(c65_u), &c65_d6, 1, 0, 0U, 0, 0U, 0);
  c65_y = c65_d6;
  sf_mex_destroy(&c65_u);
  return c65_y;
}

static void c65_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c65_mxArrayInData, const char_T *c65_varName, void *c65_outData)
{
  const mxArray *c65_nargout;
  const char_T *c65_identifier;
  emlrtMsgIdentifier c65_thisId;
  real_T c65_y;
  SFc65_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc65_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c65_nargout = sf_mex_dup(c65_mxArrayInData);
  c65_identifier = c65_varName;
  c65_thisId.fIdentifier = c65_identifier;
  c65_thisId.fParent = NULL;
  c65_y = c65_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c65_nargout),
    &c65_thisId);
  sf_mex_destroy(&c65_nargout);
  *(real_T *)c65_outData = c65_y;
  sf_mex_destroy(&c65_mxArrayInData);
}

static const mxArray *c65_c_sf_marshallOut(void *chartInstanceVoid, void
  *c65_inData)
{
  const mxArray *c65_mxArrayOutData = NULL;
  int32_T c65_i37;
  real_T c65_b_inData[2];
  int32_T c65_i38;
  real_T c65_u[2];
  const mxArray *c65_y = NULL;
  SFc65_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc65_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c65_mxArrayOutData = NULL;
  for (c65_i37 = 0; c65_i37 < 2; c65_i37++) {
    c65_b_inData[c65_i37] = (*(real_T (*)[2])c65_inData)[c65_i37];
  }

  for (c65_i38 = 0; c65_i38 < 2; c65_i38++) {
    c65_u[c65_i38] = c65_b_inData[c65_i38];
  }

  c65_y = NULL;
  sf_mex_assign(&c65_y, sf_mex_create("y", c65_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c65_mxArrayOutData, c65_y, false);
  return c65_mxArrayOutData;
}

static void c65_d_emlrt_marshallIn(SFc65_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c65_u, const emlrtMsgIdentifier *c65_parentId,
  real_T c65_y[2])
{
  real_T c65_dv5[2];
  int32_T c65_i39;
  (void)chartInstance;
  sf_mex_import(c65_parentId, sf_mex_dup(c65_u), c65_dv5, 1, 0, 0U, 1, 0U, 1, 2);
  for (c65_i39 = 0; c65_i39 < 2; c65_i39++) {
    c65_y[c65_i39] = c65_dv5[c65_i39];
  }

  sf_mex_destroy(&c65_u);
}

static void c65_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c65_mxArrayInData, const char_T *c65_varName, void *c65_outData)
{
  const mxArray *c65_Vdv;
  const char_T *c65_identifier;
  emlrtMsgIdentifier c65_thisId;
  real_T c65_y[2];
  int32_T c65_i40;
  SFc65_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc65_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c65_Vdv = sf_mex_dup(c65_mxArrayInData);
  c65_identifier = c65_varName;
  c65_thisId.fIdentifier = c65_identifier;
  c65_thisId.fParent = NULL;
  c65_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c65_Vdv), &c65_thisId, c65_y);
  sf_mex_destroy(&c65_Vdv);
  for (c65_i40 = 0; c65_i40 < 2; c65_i40++) {
    (*(real_T (*)[2])c65_outData)[c65_i40] = c65_y[c65_i40];
  }

  sf_mex_destroy(&c65_mxArrayInData);
}

static const mxArray *c65_d_sf_marshallOut(void *chartInstanceVoid, void
  *c65_inData)
{
  const mxArray *c65_mxArrayOutData = NULL;
  int32_T c65_i41;
  int32_T c65_i42;
  int32_T c65_i43;
  real_T c65_b_inData[4];
  int32_T c65_i44;
  int32_T c65_i45;
  int32_T c65_i46;
  real_T c65_u[4];
  const mxArray *c65_y = NULL;
  SFc65_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc65_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c65_mxArrayOutData = NULL;
  c65_i41 = 0;
  for (c65_i42 = 0; c65_i42 < 2; c65_i42++) {
    for (c65_i43 = 0; c65_i43 < 2; c65_i43++) {
      c65_b_inData[c65_i43 + c65_i41] = (*(real_T (*)[4])c65_inData)[c65_i43 +
        c65_i41];
    }

    c65_i41 += 2;
  }

  c65_i44 = 0;
  for (c65_i45 = 0; c65_i45 < 2; c65_i45++) {
    for (c65_i46 = 0; c65_i46 < 2; c65_i46++) {
      c65_u[c65_i46 + c65_i44] = c65_b_inData[c65_i46 + c65_i44];
    }

    c65_i44 += 2;
  }

  c65_y = NULL;
  sf_mex_assign(&c65_y, sf_mex_create("y", c65_u, 0, 0U, 1U, 0U, 2, 2, 2), false);
  sf_mex_assign(&c65_mxArrayOutData, c65_y, false);
  return c65_mxArrayOutData;
}

static void c65_e_emlrt_marshallIn(SFc65_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c65_u, const emlrtMsgIdentifier *c65_parentId,
  real_T c65_y[4])
{
  real_T c65_dv6[4];
  int32_T c65_i47;
  (void)chartInstance;
  sf_mex_import(c65_parentId, sf_mex_dup(c65_u), c65_dv6, 1, 0, 0U, 1, 0U, 2, 2,
                2);
  for (c65_i47 = 0; c65_i47 < 4; c65_i47++) {
    c65_y[c65_i47] = c65_dv6[c65_i47];
  }

  sf_mex_destroy(&c65_u);
}

static void c65_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c65_mxArrayInData, const char_T *c65_varName, void *c65_outData)
{
  const mxArray *c65_rotMat;
  const char_T *c65_identifier;
  emlrtMsgIdentifier c65_thisId;
  real_T c65_y[4];
  int32_T c65_i48;
  int32_T c65_i49;
  int32_T c65_i50;
  SFc65_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc65_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c65_rotMat = sf_mex_dup(c65_mxArrayInData);
  c65_identifier = c65_varName;
  c65_thisId.fIdentifier = c65_identifier;
  c65_thisId.fParent = NULL;
  c65_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c65_rotMat), &c65_thisId,
    c65_y);
  sf_mex_destroy(&c65_rotMat);
  c65_i48 = 0;
  for (c65_i49 = 0; c65_i49 < 2; c65_i49++) {
    for (c65_i50 = 0; c65_i50 < 2; c65_i50++) {
      (*(real_T (*)[4])c65_outData)[c65_i50 + c65_i48] = c65_y[c65_i50 + c65_i48];
    }

    c65_i48 += 2;
  }

  sf_mex_destroy(&c65_mxArrayInData);
}

const mxArray *sf_c65_Experiment_3_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c65_nameCaptureInfo = NULL;
  c65_nameCaptureInfo = NULL;
  sf_mex_assign(&c65_nameCaptureInfo, sf_mex_createstruct("structure", 2, 93, 1),
                false);
  c65_info_helper(&c65_nameCaptureInfo);
  c65_b_info_helper(&c65_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c65_nameCaptureInfo);
  return c65_nameCaptureInfo;
}

static void c65_info_helper(const mxArray **c65_info)
{
  const mxArray *c65_rhs0 = NULL;
  const mxArray *c65_lhs0 = NULL;
  const mxArray *c65_rhs1 = NULL;
  const mxArray *c65_lhs1 = NULL;
  const mxArray *c65_rhs2 = NULL;
  const mxArray *c65_lhs2 = NULL;
  const mxArray *c65_rhs3 = NULL;
  const mxArray *c65_lhs3 = NULL;
  const mxArray *c65_rhs4 = NULL;
  const mxArray *c65_lhs4 = NULL;
  const mxArray *c65_rhs5 = NULL;
  const mxArray *c65_lhs5 = NULL;
  const mxArray *c65_rhs6 = NULL;
  const mxArray *c65_lhs6 = NULL;
  const mxArray *c65_rhs7 = NULL;
  const mxArray *c65_lhs7 = NULL;
  const mxArray *c65_rhs8 = NULL;
  const mxArray *c65_lhs8 = NULL;
  const mxArray *c65_rhs9 = NULL;
  const mxArray *c65_lhs9 = NULL;
  const mxArray *c65_rhs10 = NULL;
  const mxArray *c65_lhs10 = NULL;
  const mxArray *c65_rhs11 = NULL;
  const mxArray *c65_lhs11 = NULL;
  const mxArray *c65_rhs12 = NULL;
  const mxArray *c65_lhs12 = NULL;
  const mxArray *c65_rhs13 = NULL;
  const mxArray *c65_lhs13 = NULL;
  const mxArray *c65_rhs14 = NULL;
  const mxArray *c65_lhs14 = NULL;
  const mxArray *c65_rhs15 = NULL;
  const mxArray *c65_lhs15 = NULL;
  const mxArray *c65_rhs16 = NULL;
  const mxArray *c65_lhs16 = NULL;
  const mxArray *c65_rhs17 = NULL;
  const mxArray *c65_lhs17 = NULL;
  const mxArray *c65_rhs18 = NULL;
  const mxArray *c65_lhs18 = NULL;
  const mxArray *c65_rhs19 = NULL;
  const mxArray *c65_lhs19 = NULL;
  const mxArray *c65_rhs20 = NULL;
  const mxArray *c65_lhs20 = NULL;
  const mxArray *c65_rhs21 = NULL;
  const mxArray *c65_lhs21 = NULL;
  const mxArray *c65_rhs22 = NULL;
  const mxArray *c65_lhs22 = NULL;
  const mxArray *c65_rhs23 = NULL;
  const mxArray *c65_lhs23 = NULL;
  const mxArray *c65_rhs24 = NULL;
  const mxArray *c65_lhs24 = NULL;
  const mxArray *c65_rhs25 = NULL;
  const mxArray *c65_lhs25 = NULL;
  const mxArray *c65_rhs26 = NULL;
  const mxArray *c65_lhs26 = NULL;
  const mxArray *c65_rhs27 = NULL;
  const mxArray *c65_lhs27 = NULL;
  const mxArray *c65_rhs28 = NULL;
  const mxArray *c65_lhs28 = NULL;
  const mxArray *c65_rhs29 = NULL;
  const mxArray *c65_lhs29 = NULL;
  const mxArray *c65_rhs30 = NULL;
  const mxArray *c65_lhs30 = NULL;
  const mxArray *c65_rhs31 = NULL;
  const mxArray *c65_lhs31 = NULL;
  const mxArray *c65_rhs32 = NULL;
  const mxArray *c65_lhs32 = NULL;
  const mxArray *c65_rhs33 = NULL;
  const mxArray *c65_lhs33 = NULL;
  const mxArray *c65_rhs34 = NULL;
  const mxArray *c65_lhs34 = NULL;
  const mxArray *c65_rhs35 = NULL;
  const mxArray *c65_lhs35 = NULL;
  const mxArray *c65_rhs36 = NULL;
  const mxArray *c65_lhs36 = NULL;
  const mxArray *c65_rhs37 = NULL;
  const mxArray *c65_lhs37 = NULL;
  const mxArray *c65_rhs38 = NULL;
  const mxArray *c65_lhs38 = NULL;
  const mxArray *c65_rhs39 = NULL;
  const mxArray *c65_lhs39 = NULL;
  const mxArray *c65_rhs40 = NULL;
  const mxArray *c65_lhs40 = NULL;
  const mxArray *c65_rhs41 = NULL;
  const mxArray *c65_lhs41 = NULL;
  const mxArray *c65_rhs42 = NULL;
  const mxArray *c65_lhs42 = NULL;
  const mxArray *c65_rhs43 = NULL;
  const mxArray *c65_lhs43 = NULL;
  const mxArray *c65_rhs44 = NULL;
  const mxArray *c65_lhs44 = NULL;
  const mxArray *c65_rhs45 = NULL;
  const mxArray *c65_lhs45 = NULL;
  const mxArray *c65_rhs46 = NULL;
  const mxArray *c65_lhs46 = NULL;
  const mxArray *c65_rhs47 = NULL;
  const mxArray *c65_lhs47 = NULL;
  const mxArray *c65_rhs48 = NULL;
  const mxArray *c65_lhs48 = NULL;
  const mxArray *c65_rhs49 = NULL;
  const mxArray *c65_lhs49 = NULL;
  const mxArray *c65_rhs50 = NULL;
  const mxArray *c65_lhs50 = NULL;
  const mxArray *c65_rhs51 = NULL;
  const mxArray *c65_lhs51 = NULL;
  const mxArray *c65_rhs52 = NULL;
  const mxArray *c65_lhs52 = NULL;
  const mxArray *c65_rhs53 = NULL;
  const mxArray *c65_lhs53 = NULL;
  const mxArray *c65_rhs54 = NULL;
  const mxArray *c65_lhs54 = NULL;
  const mxArray *c65_rhs55 = NULL;
  const mxArray *c65_lhs55 = NULL;
  const mxArray *c65_rhs56 = NULL;
  const mxArray *c65_lhs56 = NULL;
  const mxArray *c65_rhs57 = NULL;
  const mxArray *c65_lhs57 = NULL;
  const mxArray *c65_rhs58 = NULL;
  const mxArray *c65_lhs58 = NULL;
  const mxArray *c65_rhs59 = NULL;
  const mxArray *c65_lhs59 = NULL;
  const mxArray *c65_rhs60 = NULL;
  const mxArray *c65_lhs60 = NULL;
  const mxArray *c65_rhs61 = NULL;
  const mxArray *c65_lhs61 = NULL;
  const mxArray *c65_rhs62 = NULL;
  const mxArray *c65_lhs62 = NULL;
  const mxArray *c65_rhs63 = NULL;
  const mxArray *c65_lhs63 = NULL;
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("cosd"), "name", "name", 0);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1395346498U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c65_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_scalar_cosd_and_sind"),
                  "name", "name", 1);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1343851978U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c65_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("isfinite"), "name", "name",
                  2);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c65_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c65_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("isinf"), "name", "name", 4);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c65_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c65_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("isnan"), "name", "name", 6);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c65_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 7);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c65_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 8);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1286840376U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c65_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 9);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1286840382U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c65_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_scalar_rem90"), "name",
                  "name", 10);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1343851978U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c65_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "context", "context", 11);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("mrdivide"), "name", "name",
                  11);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c65_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 12);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 12);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c65_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 13);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("rdivide"), "name", "name",
                  13);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c65_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 14);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c65_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 15);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c65_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_div"), "name", "name",
                  16);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c65_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 17);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c65_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "context", "context", 18);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("rem"), "name", "name", 18);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c65_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 19);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c65_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 20);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c65_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 21);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c65_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 22);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c65_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 23);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 23);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c65_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "context", "context", 24);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("abs"), "name", "name", 24);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c65_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 25);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c65_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 26);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c65_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(""), "context", "context", 27);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("sind"), "name", "name", 27);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sind.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1395346504U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c65_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sind.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_scalar_cosd_and_sind"),
                  "name", "name", 28);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1343851978U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c65_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(""), "context", "context", 29);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 29);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c65_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 30);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 30);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c65_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 31);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 31);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c65_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 32);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 32);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c65_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 33);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  33);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1376002290U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c65_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 34);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c65_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 35);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c65_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 36);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 36);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c65_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 37);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 37);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c65_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 38);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 38);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c65_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 39);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 39);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c65_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 40);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 40);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c65_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(""), "context", "context", 41);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("mldivide"), "name", "name",
                  41);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p"), "resolved",
                  "resolved", 41);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1319751566U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c65_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p"), "context",
                  "context", 42);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_lusolve"), "name",
                  "name", 42);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1370031486U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c65_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolve2x2"),
                  "context", "context", 43);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_xcabs1"), "name", "name",
                  43);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c65_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m"),
                  "context", "context", 44);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "coder.internal.refblas.xcabs1"), "name", "name", 44);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xcabs1.p"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c65_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xcabs1.p"),
                  "context", "context", 45);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("abs"), "name", "name", 45);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 45);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c65_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolve2x2"),
                  "context", "context", 46);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("rdivide"), "name", "name",
                  46);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 46);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c65_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!warn_singular"),
                  "context", "context", 47);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_warning"), "name",
                  "name", 47);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m"), "resolved",
                  "resolved", 47);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1286840402U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c65_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolve2x2"),
                  "context", "context", 48);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 48);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 48);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c65_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(""), "context", "context", 49);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("length"), "name", "name", 49);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 49);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1303167806U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c65_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(""), "context", "context", 50);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("dot"), "name", "name", 50);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m"), "resolved",
                  "resolved", 50);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1360303954U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c65_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m"), "context",
                  "context", 51);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("isequal"), "name", "name",
                  51);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 51);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1286840358U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c65_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 52);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 52);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 52);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1286840386U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c65_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 53);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("isnan"), "name", "name", 53);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 53);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c65_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m"), "context",
                  "context", 54);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 54);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 54);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c65_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m"), "context",
                  "context", 55);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 55);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 55);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c65_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m!vdot"), "context",
                  "context", 56);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_xdotc"), "name", "name",
                  56);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m"),
                  "resolved", "resolved", 56);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1376002290U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c65_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m"), "context",
                  "context", 57);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 57);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 57);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c65_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m"), "context",
                  "context", 58);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.blas.xdotc"),
                  "name", "name", 58);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotc.p"),
                  "resolved", "resolved", 58);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c65_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotc.p"),
                  "context", "context", 59);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.blas.xdot"),
                  "name", "name", 59);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "resolved", "resolved", 59);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c65_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 60);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 60);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 60);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c65_rhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p!below_threshold"),
                  "context", "context", 61);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 61);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 61);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c65_rhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 62);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.refblas.xdot"),
                  "name", "name", 62);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "resolved", "resolved", 62);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c65_rhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "context", "context", 63);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "coder.internal.refblas.xdotx"), "name", "name", 63);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 63);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "resolved", "resolved", 63);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c65_rhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs63), "lhs", "lhs",
                  63);
  sf_mex_destroy(&c65_rhs0);
  sf_mex_destroy(&c65_lhs0);
  sf_mex_destroy(&c65_rhs1);
  sf_mex_destroy(&c65_lhs1);
  sf_mex_destroy(&c65_rhs2);
  sf_mex_destroy(&c65_lhs2);
  sf_mex_destroy(&c65_rhs3);
  sf_mex_destroy(&c65_lhs3);
  sf_mex_destroy(&c65_rhs4);
  sf_mex_destroy(&c65_lhs4);
  sf_mex_destroy(&c65_rhs5);
  sf_mex_destroy(&c65_lhs5);
  sf_mex_destroy(&c65_rhs6);
  sf_mex_destroy(&c65_lhs6);
  sf_mex_destroy(&c65_rhs7);
  sf_mex_destroy(&c65_lhs7);
  sf_mex_destroy(&c65_rhs8);
  sf_mex_destroy(&c65_lhs8);
  sf_mex_destroy(&c65_rhs9);
  sf_mex_destroy(&c65_lhs9);
  sf_mex_destroy(&c65_rhs10);
  sf_mex_destroy(&c65_lhs10);
  sf_mex_destroy(&c65_rhs11);
  sf_mex_destroy(&c65_lhs11);
  sf_mex_destroy(&c65_rhs12);
  sf_mex_destroy(&c65_lhs12);
  sf_mex_destroy(&c65_rhs13);
  sf_mex_destroy(&c65_lhs13);
  sf_mex_destroy(&c65_rhs14);
  sf_mex_destroy(&c65_lhs14);
  sf_mex_destroy(&c65_rhs15);
  sf_mex_destroy(&c65_lhs15);
  sf_mex_destroy(&c65_rhs16);
  sf_mex_destroy(&c65_lhs16);
  sf_mex_destroy(&c65_rhs17);
  sf_mex_destroy(&c65_lhs17);
  sf_mex_destroy(&c65_rhs18);
  sf_mex_destroy(&c65_lhs18);
  sf_mex_destroy(&c65_rhs19);
  sf_mex_destroy(&c65_lhs19);
  sf_mex_destroy(&c65_rhs20);
  sf_mex_destroy(&c65_lhs20);
  sf_mex_destroy(&c65_rhs21);
  sf_mex_destroy(&c65_lhs21);
  sf_mex_destroy(&c65_rhs22);
  sf_mex_destroy(&c65_lhs22);
  sf_mex_destroy(&c65_rhs23);
  sf_mex_destroy(&c65_lhs23);
  sf_mex_destroy(&c65_rhs24);
  sf_mex_destroy(&c65_lhs24);
  sf_mex_destroy(&c65_rhs25);
  sf_mex_destroy(&c65_lhs25);
  sf_mex_destroy(&c65_rhs26);
  sf_mex_destroy(&c65_lhs26);
  sf_mex_destroy(&c65_rhs27);
  sf_mex_destroy(&c65_lhs27);
  sf_mex_destroy(&c65_rhs28);
  sf_mex_destroy(&c65_lhs28);
  sf_mex_destroy(&c65_rhs29);
  sf_mex_destroy(&c65_lhs29);
  sf_mex_destroy(&c65_rhs30);
  sf_mex_destroy(&c65_lhs30);
  sf_mex_destroy(&c65_rhs31);
  sf_mex_destroy(&c65_lhs31);
  sf_mex_destroy(&c65_rhs32);
  sf_mex_destroy(&c65_lhs32);
  sf_mex_destroy(&c65_rhs33);
  sf_mex_destroy(&c65_lhs33);
  sf_mex_destroy(&c65_rhs34);
  sf_mex_destroy(&c65_lhs34);
  sf_mex_destroy(&c65_rhs35);
  sf_mex_destroy(&c65_lhs35);
  sf_mex_destroy(&c65_rhs36);
  sf_mex_destroy(&c65_lhs36);
  sf_mex_destroy(&c65_rhs37);
  sf_mex_destroy(&c65_lhs37);
  sf_mex_destroy(&c65_rhs38);
  sf_mex_destroy(&c65_lhs38);
  sf_mex_destroy(&c65_rhs39);
  sf_mex_destroy(&c65_lhs39);
  sf_mex_destroy(&c65_rhs40);
  sf_mex_destroy(&c65_lhs40);
  sf_mex_destroy(&c65_rhs41);
  sf_mex_destroy(&c65_lhs41);
  sf_mex_destroy(&c65_rhs42);
  sf_mex_destroy(&c65_lhs42);
  sf_mex_destroy(&c65_rhs43);
  sf_mex_destroy(&c65_lhs43);
  sf_mex_destroy(&c65_rhs44);
  sf_mex_destroy(&c65_lhs44);
  sf_mex_destroy(&c65_rhs45);
  sf_mex_destroy(&c65_lhs45);
  sf_mex_destroy(&c65_rhs46);
  sf_mex_destroy(&c65_lhs46);
  sf_mex_destroy(&c65_rhs47);
  sf_mex_destroy(&c65_lhs47);
  sf_mex_destroy(&c65_rhs48);
  sf_mex_destroy(&c65_lhs48);
  sf_mex_destroy(&c65_rhs49);
  sf_mex_destroy(&c65_lhs49);
  sf_mex_destroy(&c65_rhs50);
  sf_mex_destroy(&c65_lhs50);
  sf_mex_destroy(&c65_rhs51);
  sf_mex_destroy(&c65_lhs51);
  sf_mex_destroy(&c65_rhs52);
  sf_mex_destroy(&c65_lhs52);
  sf_mex_destroy(&c65_rhs53);
  sf_mex_destroy(&c65_lhs53);
  sf_mex_destroy(&c65_rhs54);
  sf_mex_destroy(&c65_lhs54);
  sf_mex_destroy(&c65_rhs55);
  sf_mex_destroy(&c65_lhs55);
  sf_mex_destroy(&c65_rhs56);
  sf_mex_destroy(&c65_lhs56);
  sf_mex_destroy(&c65_rhs57);
  sf_mex_destroy(&c65_lhs57);
  sf_mex_destroy(&c65_rhs58);
  sf_mex_destroy(&c65_lhs58);
  sf_mex_destroy(&c65_rhs59);
  sf_mex_destroy(&c65_lhs59);
  sf_mex_destroy(&c65_rhs60);
  sf_mex_destroy(&c65_lhs60);
  sf_mex_destroy(&c65_rhs61);
  sf_mex_destroy(&c65_lhs61);
  sf_mex_destroy(&c65_rhs62);
  sf_mex_destroy(&c65_lhs62);
  sf_mex_destroy(&c65_rhs63);
  sf_mex_destroy(&c65_lhs63);
}

static const mxArray *c65_emlrt_marshallOut(const char * c65_u)
{
  const mxArray *c65_y = NULL;
  c65_y = NULL;
  sf_mex_assign(&c65_y, sf_mex_create("y", c65_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c65_u)), false);
  return c65_y;
}

static const mxArray *c65_b_emlrt_marshallOut(const uint32_T c65_u)
{
  const mxArray *c65_y = NULL;
  c65_y = NULL;
  sf_mex_assign(&c65_y, sf_mex_create("y", &c65_u, 7, 0U, 0U, 0U, 0), false);
  return c65_y;
}

static void c65_b_info_helper(const mxArray **c65_info)
{
  const mxArray *c65_rhs64 = NULL;
  const mxArray *c65_lhs64 = NULL;
  const mxArray *c65_rhs65 = NULL;
  const mxArray *c65_lhs65 = NULL;
  const mxArray *c65_rhs66 = NULL;
  const mxArray *c65_lhs66 = NULL;
  const mxArray *c65_rhs67 = NULL;
  const mxArray *c65_lhs67 = NULL;
  const mxArray *c65_rhs68 = NULL;
  const mxArray *c65_lhs68 = NULL;
  const mxArray *c65_rhs69 = NULL;
  const mxArray *c65_lhs69 = NULL;
  const mxArray *c65_rhs70 = NULL;
  const mxArray *c65_lhs70 = NULL;
  const mxArray *c65_rhs71 = NULL;
  const mxArray *c65_lhs71 = NULL;
  const mxArray *c65_rhs72 = NULL;
  const mxArray *c65_lhs72 = NULL;
  const mxArray *c65_rhs73 = NULL;
  const mxArray *c65_lhs73 = NULL;
  const mxArray *c65_rhs74 = NULL;
  const mxArray *c65_lhs74 = NULL;
  const mxArray *c65_rhs75 = NULL;
  const mxArray *c65_lhs75 = NULL;
  const mxArray *c65_rhs76 = NULL;
  const mxArray *c65_lhs76 = NULL;
  const mxArray *c65_rhs77 = NULL;
  const mxArray *c65_lhs77 = NULL;
  const mxArray *c65_rhs78 = NULL;
  const mxArray *c65_lhs78 = NULL;
  const mxArray *c65_rhs79 = NULL;
  const mxArray *c65_lhs79 = NULL;
  const mxArray *c65_rhs80 = NULL;
  const mxArray *c65_lhs80 = NULL;
  const mxArray *c65_rhs81 = NULL;
  const mxArray *c65_lhs81 = NULL;
  const mxArray *c65_rhs82 = NULL;
  const mxArray *c65_lhs82 = NULL;
  const mxArray *c65_rhs83 = NULL;
  const mxArray *c65_lhs83 = NULL;
  const mxArray *c65_rhs84 = NULL;
  const mxArray *c65_lhs84 = NULL;
  const mxArray *c65_rhs85 = NULL;
  const mxArray *c65_lhs85 = NULL;
  const mxArray *c65_rhs86 = NULL;
  const mxArray *c65_lhs86 = NULL;
  const mxArray *c65_rhs87 = NULL;
  const mxArray *c65_lhs87 = NULL;
  const mxArray *c65_rhs88 = NULL;
  const mxArray *c65_lhs88 = NULL;
  const mxArray *c65_rhs89 = NULL;
  const mxArray *c65_lhs89 = NULL;
  const mxArray *c65_rhs90 = NULL;
  const mxArray *c65_lhs90 = NULL;
  const mxArray *c65_rhs91 = NULL;
  const mxArray *c65_lhs91 = NULL;
  const mxArray *c65_rhs92 = NULL;
  const mxArray *c65_lhs92 = NULL;
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 64);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 64);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 64);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 64);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 64);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 64);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 64);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 64);
  sf_mex_assign(&c65_rhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs64), "rhs", "rhs",
                  64);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs64), "lhs", "lhs",
                  64);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 65);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 65);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 65);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 65);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 65);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 65);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 65);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 65);
  sf_mex_assign(&c65_rhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs65), "rhs", "rhs",
                  65);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs65), "lhs", "lhs",
                  65);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 66);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 66);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 66);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 66);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 66);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 66);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 66);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 66);
  sf_mex_assign(&c65_rhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs66), "rhs", "rhs",
                  66);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs66), "lhs", "lhs",
                  66);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 67);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 67);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 67);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 67);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 67);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 67);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 67);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 67);
  sf_mex_assign(&c65_rhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs67), "rhs", "rhs",
                  67);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs67), "lhs", "lhs",
                  67);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 68);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 68);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 68);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 68);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 68);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 68);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 68);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 68);
  sf_mex_assign(&c65_rhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs68), "rhs", "rhs",
                  68);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs68), "lhs", "lhs",
                  68);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 69);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("isfi"), "name", "name", 69);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 69);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 69);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1346531958U), "fileTimeLo",
                  "fileTimeLo", 69);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 69);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 69);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 69);
  sf_mex_assign(&c65_rhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs69), "rhs", "rhs",
                  69);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs69), "lhs", "lhs",
                  69);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 70);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 70);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 70);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 70);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1398897198U), "fileTimeLo",
                  "fileTimeLo", 70);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 70);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 70);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 70);
  sf_mex_assign(&c65_rhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs70), "rhs", "rhs",
                  70);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs70), "lhs", "lhs",
                  70);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 71);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("intmax"), "name", "name", 71);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 71);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 71);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 71);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 71);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 71);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 71);
  sf_mex_assign(&c65_rhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs71), "rhs", "rhs",
                  71);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs71), "lhs", "lhs",
                  71);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 72);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 72);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 72);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 72);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 72);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 72);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 72);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 72);
  sf_mex_assign(&c65_rhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs72), "rhs", "rhs",
                  72);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs72), "lhs", "lhs",
                  72);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 73);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("intmin"), "name", "name", 73);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 73);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 73);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 73);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 73);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 73);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 73);
  sf_mex_assign(&c65_rhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs73), "rhs", "rhs",
                  73);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs73), "lhs", "lhs",
                  73);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 74);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 74);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 74);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 74);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 74);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 74);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 74);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 74);
  sf_mex_assign(&c65_rhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs74), "rhs", "rhs",
                  74);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs74), "lhs", "lhs",
                  74);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(""), "context", "context", 75);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("norm"), "name", "name", 75);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 75);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "resolved",
                  "resolved", 75);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1363731868U), "fileTimeLo",
                  "fileTimeLo", 75);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 75);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 75);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 75);
  sf_mex_assign(&c65_rhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs75), "rhs", "rhs",
                  75);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs75), "lhs", "lhs",
                  75);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 76);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 76);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 76);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 76);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 76);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 76);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 76);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 76);
  sf_mex_assign(&c65_rhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs76), "rhs", "rhs",
                  76);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs76), "lhs", "lhs",
                  76);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 77);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 77);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 77);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 77);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 77);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 77);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 77);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 77);
  sf_mex_assign(&c65_rhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs77), "rhs", "rhs",
                  77);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs77), "lhs", "lhs",
                  77);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 78);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_xnrm2"), "name", "name",
                  78);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 78);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"),
                  "resolved", "resolved", 78);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1376002292U), "fileTimeLo",
                  "fileTimeLo", 78);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 78);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 78);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 78);
  sf_mex_assign(&c65_rhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs78), "rhs", "rhs",
                  78);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs78), "lhs", "lhs",
                  78);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 79);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 79);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 79);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 79);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 79);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 79);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 79);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 79);
  sf_mex_assign(&c65_rhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs79), "rhs", "rhs",
                  79);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs79), "lhs", "lhs",
                  79);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 80);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.blas.xnrm2"),
                  "name", "name", 80);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 80);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "resolved", "resolved", 80);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 80);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 80);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 80);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 80);
  sf_mex_assign(&c65_rhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs80), "rhs", "rhs",
                  80);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs80), "lhs", "lhs",
                  80);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "context", "context", 81);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 81);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 81);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 81);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 81);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 81);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 81);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 81);
  sf_mex_assign(&c65_rhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs81), "rhs", "rhs",
                  81);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs81), "lhs", "lhs",
                  81);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p!below_threshold"),
                  "context", "context", 82);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 82);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 82);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 82);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 82);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 82);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 82);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 82);
  sf_mex_assign(&c65_rhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs82), "rhs", "rhs",
                  82);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs82), "lhs", "lhs",
                  82);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "context", "context", 83);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "coder.internal.refblas.xnrm2"), "name", "name", 83);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 83);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "resolved", "resolved", 83);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 83);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 83);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 83);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 83);
  sf_mex_assign(&c65_rhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs83), "rhs", "rhs",
                  83);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs83), "lhs", "lhs",
                  83);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 84);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("realmin"), "name", "name",
                  84);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 84);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 84);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1307672842U), "fileTimeLo",
                  "fileTimeLo", 84);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 84);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 84);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 84);
  sf_mex_assign(&c65_rhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs84), "rhs", "rhs",
                  84);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs84), "lhs", "lhs",
                  84);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "context",
                  "context", 85);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_realmin"), "name",
                  "name", 85);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 85);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "resolved",
                  "resolved", 85);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1307672844U), "fileTimeLo",
                  "fileTimeLo", 85);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 85);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 85);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 85);
  sf_mex_assign(&c65_rhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs85), "rhs", "rhs",
                  85);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs85), "lhs", "lhs",
                  85);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "context",
                  "context", 86);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 86);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 86);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 86);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 86);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 86);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 86);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 86);
  sf_mex_assign(&c65_rhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs86), "rhs", "rhs",
                  86);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs86), "lhs", "lhs",
                  86);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 87);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 87);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 87);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 87);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 87);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 87);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 87);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 87);
  sf_mex_assign(&c65_rhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs87), "rhs", "rhs",
                  87);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs87), "lhs", "lhs",
                  87);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 88);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 88);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 88);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 88);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 88);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 88);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 88);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 88);
  sf_mex_assign(&c65_rhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs88), "rhs", "rhs",
                  88);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs88), "lhs", "lhs",
                  88);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 89);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 89);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 89);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 89);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 89);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 89);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 89);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 89);
  sf_mex_assign(&c65_rhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs89), "rhs", "rhs",
                  89);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs89), "lhs", "lhs",
                  89);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 90);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 90);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 90);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 90);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 90);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 90);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 90);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 90);
  sf_mex_assign(&c65_rhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs90), "rhs", "rhs",
                  90);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs90), "lhs", "lhs",
                  90);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 91);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("abs"), "name", "name", 91);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 91);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 91);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 91);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 91);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 91);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 91);
  sf_mex_assign(&c65_rhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs91), "rhs", "rhs",
                  91);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs91), "lhs", "lhs",
                  91);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(""), "context", "context", 92);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("mrdivide"), "name", "name",
                  92);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 92);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 92);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 92);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 92);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 92);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 92);
  sf_mex_assign(&c65_rhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs92), "rhs", "rhs",
                  92);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs92), "lhs", "lhs",
                  92);
  sf_mex_destroy(&c65_rhs64);
  sf_mex_destroy(&c65_lhs64);
  sf_mex_destroy(&c65_rhs65);
  sf_mex_destroy(&c65_lhs65);
  sf_mex_destroy(&c65_rhs66);
  sf_mex_destroy(&c65_lhs66);
  sf_mex_destroy(&c65_rhs67);
  sf_mex_destroy(&c65_lhs67);
  sf_mex_destroy(&c65_rhs68);
  sf_mex_destroy(&c65_lhs68);
  sf_mex_destroy(&c65_rhs69);
  sf_mex_destroy(&c65_lhs69);
  sf_mex_destroy(&c65_rhs70);
  sf_mex_destroy(&c65_lhs70);
  sf_mex_destroy(&c65_rhs71);
  sf_mex_destroy(&c65_lhs71);
  sf_mex_destroy(&c65_rhs72);
  sf_mex_destroy(&c65_lhs72);
  sf_mex_destroy(&c65_rhs73);
  sf_mex_destroy(&c65_lhs73);
  sf_mex_destroy(&c65_rhs74);
  sf_mex_destroy(&c65_lhs74);
  sf_mex_destroy(&c65_rhs75);
  sf_mex_destroy(&c65_lhs75);
  sf_mex_destroy(&c65_rhs76);
  sf_mex_destroy(&c65_lhs76);
  sf_mex_destroy(&c65_rhs77);
  sf_mex_destroy(&c65_lhs77);
  sf_mex_destroy(&c65_rhs78);
  sf_mex_destroy(&c65_lhs78);
  sf_mex_destroy(&c65_rhs79);
  sf_mex_destroy(&c65_lhs79);
  sf_mex_destroy(&c65_rhs80);
  sf_mex_destroy(&c65_lhs80);
  sf_mex_destroy(&c65_rhs81);
  sf_mex_destroy(&c65_lhs81);
  sf_mex_destroy(&c65_rhs82);
  sf_mex_destroy(&c65_lhs82);
  sf_mex_destroy(&c65_rhs83);
  sf_mex_destroy(&c65_lhs83);
  sf_mex_destroy(&c65_rhs84);
  sf_mex_destroy(&c65_lhs84);
  sf_mex_destroy(&c65_rhs85);
  sf_mex_destroy(&c65_lhs85);
  sf_mex_destroy(&c65_rhs86);
  sf_mex_destroy(&c65_lhs86);
  sf_mex_destroy(&c65_rhs87);
  sf_mex_destroy(&c65_lhs87);
  sf_mex_destroy(&c65_rhs88);
  sf_mex_destroy(&c65_lhs88);
  sf_mex_destroy(&c65_rhs89);
  sf_mex_destroy(&c65_lhs89);
  sf_mex_destroy(&c65_rhs90);
  sf_mex_destroy(&c65_lhs90);
  sf_mex_destroy(&c65_rhs91);
  sf_mex_destroy(&c65_lhs91);
  sf_mex_destroy(&c65_rhs92);
  sf_mex_destroy(&c65_lhs92);
}

static real_T c65_cosd(SFc65_Experiment_3_csInstanceStruct *chartInstance,
  real_T c65_x)
{
  real_T c65_b_x;
  c65_b_x = c65_x;
  c65_b_cosd(chartInstance, &c65_b_x);
  return c65_b_x;
}

static boolean_T c65_isfinite(SFc65_Experiment_3_csInstanceStruct *chartInstance,
  real_T c65_x)
{
  real_T c65_b_x;
  boolean_T c65_b_b;
  boolean_T c65_b0;
  real_T c65_c_x;
  boolean_T c65_c_b;
  boolean_T c65_b1;
  (void)chartInstance;
  c65_b_x = c65_x;
  c65_b_b = muDoubleScalarIsInf(c65_b_x);
  c65_b0 = !c65_b_b;
  c65_c_x = c65_x;
  c65_c_b = muDoubleScalarIsNaN(c65_c_x);
  c65_b1 = !c65_c_b;
  return c65_b0 && c65_b1;
}

static real_T c65_rdivide(SFc65_Experiment_3_csInstanceStruct *chartInstance,
  real_T c65_x, real_T c65_y)
{
  real_T c65_b_x;
  real_T c65_b_y;
  real_T c65_c_x;
  real_T c65_c_y;
  (void)chartInstance;
  c65_b_x = c65_x;
  c65_b_y = c65_y;
  c65_c_x = c65_b_x;
  c65_c_y = c65_b_y;
  return c65_c_x / c65_c_y;
}

static real_T c65_sind(SFc65_Experiment_3_csInstanceStruct *chartInstance,
  real_T c65_x)
{
  real_T c65_b_x;
  c65_b_x = c65_x;
  c65_b_sind(chartInstance, &c65_b_x);
  return c65_b_x;
}

static void c65_eml_scalar_eg(SFc65_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c65_eml_xgemm(SFc65_Experiment_3_csInstanceStruct *chartInstance,
  real_T c65_A[4], real_T c65_B[2], real_T c65_C[2], real_T c65_b_C[2])
{
  int32_T c65_i51;
  int32_T c65_i52;
  real_T c65_b_A[4];
  int32_T c65_i53;
  real_T c65_b_B[2];
  for (c65_i51 = 0; c65_i51 < 2; c65_i51++) {
    c65_b_C[c65_i51] = c65_C[c65_i51];
  }

  for (c65_i52 = 0; c65_i52 < 4; c65_i52++) {
    c65_b_A[c65_i52] = c65_A[c65_i52];
  }

  for (c65_i53 = 0; c65_i53 < 2; c65_i53++) {
    c65_b_B[c65_i53] = c65_B[c65_i53];
  }

  c65_b_eml_xgemm(chartInstance, c65_b_A, c65_b_B, c65_b_C);
}

static void c65_mldivide(SFc65_Experiment_3_csInstanceStruct *chartInstance,
  real_T c65_A[4], real_T c65_B[2], real_T c65_Y[2])
{
  real_T c65_x;
  real_T c65_b_x;
  real_T c65_c_x;
  real_T c65_d_x;
  real_T c65_y;
  real_T c65_e_x;
  real_T c65_f_x;
  real_T c65_b_y;
  real_T c65_d;
  real_T c65_g_x;
  real_T c65_h_x;
  real_T c65_i_x;
  real_T c65_j_x;
  real_T c65_c_y;
  real_T c65_k_x;
  real_T c65_l_x;
  real_T c65_d_y;
  real_T c65_b_d;
  int32_T c65_r1;
  int32_T c65_r2;
  real_T c65_a21;
  real_T c65_a22;
  boolean_T guard1 = false;
  c65_x = c65_A[1];
  c65_b_x = c65_x;
  c65_c_x = c65_b_x;
  c65_d_x = c65_c_x;
  c65_y = muDoubleScalarAbs(c65_d_x);
  c65_e_x = 0.0;
  c65_f_x = c65_e_x;
  c65_b_y = muDoubleScalarAbs(c65_f_x);
  c65_d = c65_y + c65_b_y;
  c65_g_x = c65_A[0];
  c65_h_x = c65_g_x;
  c65_i_x = c65_h_x;
  c65_j_x = c65_i_x;
  c65_c_y = muDoubleScalarAbs(c65_j_x);
  c65_k_x = 0.0;
  c65_l_x = c65_k_x;
  c65_d_y = muDoubleScalarAbs(c65_l_x);
  c65_b_d = c65_c_y + c65_d_y;
  if (c65_d > c65_b_d) {
    c65_r1 = 2;
    c65_r2 = 1;
  } else {
    c65_r1 = 1;
    c65_r2 = 2;
  }

  c65_a21 = c65_rdivide(chartInstance, c65_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c65_r2), 1, 2, 1, 0) - 1],
                        c65_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c65_r1), 1, 2, 1, 0) - 1]);
  c65_a22 = c65_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c65_r2), 1, 2, 1, 0) + 1] - c65_a21 *
    c65_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c65_r1), 1, 2, 1, 0) + 1];
  guard1 = false;
  if (c65_a22 == 0.0) {
    guard1 = true;
  } else {
    if (c65_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c65_r1), 1, 2, 1, 0) - 1] == 0.0) {
      guard1 = true;
    }
  }

  if (guard1 == true) {
    c65_eml_warning(chartInstance);
  }

  c65_eml_scalar_eg(chartInstance);
  c65_Y[1] = c65_rdivide(chartInstance, c65_B[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c65_r2), 1, 2, 1, 0) - 1] -
    c65_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c65_r1), 1, 2, 1, 0) - 1] * c65_a21, c65_a22);
  c65_Y[0] = c65_rdivide(chartInstance, c65_B[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c65_r1), 1, 2, 1, 0) - 1] - c65_Y[1]
    * c65_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c65_r1), 1, 2, 1, 0) + 1], c65_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c65_r1), 1, 2, 1, 0) - 1]);
}

static void c65_eml_warning(SFc65_Experiment_3_csInstanceStruct *chartInstance)
{
  int32_T c65_i54;
  static char_T c65_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c65_u[27];
  const mxArray *c65_y = NULL;
  (void)chartInstance;
  for (c65_i54 = 0; c65_i54 < 27; c65_i54++) {
    c65_u[c65_i54] = c65_varargin_1[c65_i54];
  }

  c65_y = NULL;
  sf_mex_assign(&c65_y, sf_mex_create("y", c65_u, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "warning", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c65_y));
}

static real_T c65_eml_xdotc(SFc65_Experiment_3_csInstanceStruct *chartInstance,
  real_T c65_x[2], real_T c65_y[2])
{
  real_T c65_d;
  int32_T c65_k;
  int32_T c65_b_k;
  (void)chartInstance;
  c65_d = 0.0;
  for (c65_k = 1; c65_k < 3; c65_k++) {
    c65_b_k = c65_k;
    c65_d += c65_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c65_b_k), 1, 2, 1, 0) - 1] * c65_y[_SFD_EML_ARRAY_BOUNDS_CHECK
      ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c65_b_k), 1, 2, 1, 0) - 1];
  }

  return c65_d;
}

static real_T c65_eml_xnrm2(SFc65_Experiment_3_csInstanceStruct *chartInstance,
  real_T c65_x[2])
{
  real_T c65_y;
  real_T c65_scale;
  int32_T c65_k;
  int32_T c65_b_k;
  real_T c65_b_x;
  real_T c65_c_x;
  real_T c65_absxk;
  real_T c65_t;
  c65_below_threshold(chartInstance);
  c65_y = 0.0;
  c65_scale = 2.2250738585072014E-308;
  for (c65_k = 1; c65_k < 3; c65_k++) {
    c65_b_k = c65_k;
    c65_b_x = c65_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c65_b_k), 1, 2, 1, 0) - 1];
    c65_c_x = c65_b_x;
    c65_absxk = muDoubleScalarAbs(c65_c_x);
    if (c65_absxk > c65_scale) {
      c65_t = c65_scale / c65_absxk;
      c65_y = 1.0 + c65_y * c65_t * c65_t;
      c65_scale = c65_absxk;
    } else {
      c65_t = c65_absxk / c65_scale;
      c65_y += c65_t * c65_t;
    }
  }

  return c65_scale * muDoubleScalarSqrt(c65_y);
}

static void c65_below_threshold(SFc65_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c65_e_sf_marshallOut(void *chartInstanceVoid, void
  *c65_inData)
{
  const mxArray *c65_mxArrayOutData = NULL;
  int32_T c65_u;
  const mxArray *c65_y = NULL;
  SFc65_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc65_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c65_mxArrayOutData = NULL;
  c65_u = *(int32_T *)c65_inData;
  c65_y = NULL;
  sf_mex_assign(&c65_y, sf_mex_create("y", &c65_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c65_mxArrayOutData, c65_y, false);
  return c65_mxArrayOutData;
}

static int32_T c65_f_emlrt_marshallIn(SFc65_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c65_u, const emlrtMsgIdentifier *c65_parentId)
{
  int32_T c65_y;
  int32_T c65_i55;
  (void)chartInstance;
  sf_mex_import(c65_parentId, sf_mex_dup(c65_u), &c65_i55, 1, 6, 0U, 0, 0U, 0);
  c65_y = c65_i55;
  sf_mex_destroy(&c65_u);
  return c65_y;
}

static void c65_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c65_mxArrayInData, const char_T *c65_varName, void *c65_outData)
{
  const mxArray *c65_b_sfEvent;
  const char_T *c65_identifier;
  emlrtMsgIdentifier c65_thisId;
  int32_T c65_y;
  SFc65_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc65_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c65_b_sfEvent = sf_mex_dup(c65_mxArrayInData);
  c65_identifier = c65_varName;
  c65_thisId.fIdentifier = c65_identifier;
  c65_thisId.fParent = NULL;
  c65_y = c65_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c65_b_sfEvent),
    &c65_thisId);
  sf_mex_destroy(&c65_b_sfEvent);
  *(int32_T *)c65_outData = c65_y;
  sf_mex_destroy(&c65_mxArrayInData);
}

static uint8_T c65_g_emlrt_marshallIn(SFc65_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c65_b_is_active_c65_Experiment_3_cs, const
  char_T *c65_identifier)
{
  uint8_T c65_y;
  emlrtMsgIdentifier c65_thisId;
  c65_thisId.fIdentifier = c65_identifier;
  c65_thisId.fParent = NULL;
  c65_y = c65_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c65_b_is_active_c65_Experiment_3_cs), &c65_thisId);
  sf_mex_destroy(&c65_b_is_active_c65_Experiment_3_cs);
  return c65_y;
}

static uint8_T c65_h_emlrt_marshallIn(SFc65_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c65_u, const emlrtMsgIdentifier *c65_parentId)
{
  uint8_T c65_y;
  uint8_T c65_u0;
  (void)chartInstance;
  sf_mex_import(c65_parentId, sf_mex_dup(c65_u), &c65_u0, 1, 3, 0U, 0, 0U, 0);
  c65_y = c65_u0;
  sf_mex_destroy(&c65_u);
  return c65_y;
}

static void c65_b_cosd(SFc65_Experiment_3_csInstanceStruct *chartInstance,
  real_T *c65_x)
{
  real_T c65_b_x;
  real_T c65_c_x;
  real_T c65_d_x;
  real_T c65_e_x;
  real_T c65_xk;
  real_T c65_f_x;
  real_T c65_g_x;
  real_T c65_absx;
  real_T c65_h_x;
  real_T c65_i_x;
  int8_T c65_n;
  int8_T c65_b_n;
  c65_b_x = *c65_x;
  if (!c65_isfinite(chartInstance, c65_b_x)) {
    *c65_x = rtNaN;
  } else {
    c65_c_x = c65_b_x;
    c65_d_x = c65_c_x;
    c65_e_x = c65_d_x;
    c65_xk = c65_e_x;
    c65_d_x = muDoubleScalarRem(c65_xk, 360.0);
    c65_f_x = c65_d_x;
    c65_g_x = c65_f_x;
    c65_absx = muDoubleScalarAbs(c65_g_x);
    if (c65_absx > 180.0) {
      if (c65_d_x > 0.0) {
        c65_d_x -= 360.0;
      } else {
        c65_d_x += 360.0;
      }

      c65_h_x = c65_d_x;
      c65_i_x = c65_h_x;
      c65_absx = muDoubleScalarAbs(c65_i_x);
    }

    if (c65_absx <= 45.0) {
      c65_d_x *= 0.017453292519943295;
      c65_n = 0;
    } else if (c65_absx <= 135.0) {
      if (c65_d_x > 0.0) {
        c65_d_x = 0.017453292519943295 * (c65_d_x - 90.0);
        c65_n = 1;
      } else {
        c65_d_x = 0.017453292519943295 * (c65_d_x + 90.0);
        c65_n = -1;
      }
    } else if (c65_d_x > 0.0) {
      c65_d_x = 0.017453292519943295 * (c65_d_x - 180.0);
      c65_n = 2;
    } else {
      c65_d_x = 0.017453292519943295 * (c65_d_x + 180.0);
      c65_n = -2;
    }

    c65_b_n = c65_n;
    c65_b_x = c65_d_x;
    if ((real_T)c65_b_n == 0.0) {
      *c65_x = muDoubleScalarCos(c65_b_x);
    } else if ((real_T)c65_b_n == 1.0) {
      *c65_x = -muDoubleScalarSin(c65_b_x);
    } else if ((real_T)c65_b_n == -1.0) {
      *c65_x = muDoubleScalarSin(c65_b_x);
    } else {
      *c65_x = -muDoubleScalarCos(c65_b_x);
    }
  }
}

static void c65_b_sind(SFc65_Experiment_3_csInstanceStruct *chartInstance,
  real_T *c65_x)
{
  real_T c65_b_x;
  real_T c65_d7;
  real_T c65_c_x;
  real_T c65_d_x;
  real_T c65_e_x;
  real_T c65_xk;
  real_T c65_f_x;
  real_T c65_g_x;
  real_T c65_absx;
  real_T c65_h_x;
  real_T c65_i_x;
  int8_T c65_n;
  int8_T c65_b_n;
  c65_b_x = *c65_x;
  if (!c65_isfinite(chartInstance, c65_b_x)) {
    c65_d7 = rtNaN;
  } else {
    c65_c_x = c65_b_x;
    c65_d_x = c65_c_x;
    c65_e_x = c65_d_x;
    c65_xk = c65_e_x;
    c65_d_x = muDoubleScalarRem(c65_xk, 360.0);
    c65_f_x = c65_d_x;
    c65_g_x = c65_f_x;
    c65_absx = muDoubleScalarAbs(c65_g_x);
    if (c65_absx > 180.0) {
      if (c65_d_x > 0.0) {
        c65_d_x -= 360.0;
      } else {
        c65_d_x += 360.0;
      }

      c65_h_x = c65_d_x;
      c65_i_x = c65_h_x;
      c65_absx = muDoubleScalarAbs(c65_i_x);
    }

    if (c65_absx <= 45.0) {
      c65_d_x *= 0.017453292519943295;
      c65_n = 0;
    } else if (c65_absx <= 135.0) {
      if (c65_d_x > 0.0) {
        c65_d_x = 0.017453292519943295 * (c65_d_x - 90.0);
        c65_n = 1;
      } else {
        c65_d_x = 0.017453292519943295 * (c65_d_x + 90.0);
        c65_n = -1;
      }
    } else if (c65_d_x > 0.0) {
      c65_d_x = 0.017453292519943295 * (c65_d_x - 180.0);
      c65_n = 2;
    } else {
      c65_d_x = 0.017453292519943295 * (c65_d_x + 180.0);
      c65_n = -2;
    }

    c65_b_n = c65_n;
    c65_b_x = c65_d_x;
    if ((real_T)c65_b_n == 0.0) {
      c65_d7 = muDoubleScalarSin(c65_b_x);
    } else if ((real_T)c65_b_n == 1.0) {
      c65_d7 = muDoubleScalarCos(c65_b_x);
    } else if ((real_T)c65_b_n == -1.0) {
      c65_d7 = -muDoubleScalarCos(c65_b_x);
    } else {
      c65_d7 = -muDoubleScalarSin(c65_b_x);
    }
  }

  *c65_x = c65_d7;
}

static void c65_b_eml_xgemm(SFc65_Experiment_3_csInstanceStruct *chartInstance,
  real_T c65_A[4], real_T c65_B[2], real_T c65_C[2])
{
  int32_T c65_i56;
  int32_T c65_i57;
  int32_T c65_i58;
  (void)chartInstance;
  for (c65_i56 = 0; c65_i56 < 2; c65_i56++) {
    c65_C[c65_i56] = 0.0;
    c65_i57 = 0;
    for (c65_i58 = 0; c65_i58 < 2; c65_i58++) {
      c65_C[c65_i56] += c65_A[c65_i57 + c65_i56] * c65_B[c65_i58];
      c65_i57 += 2;
    }
  }
}

static void init_dsm_address_info(SFc65_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc65_Experiment_3_csInstanceStruct
  *chartInstance)
{
  chartInstance->c65_carX = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c65_dopplerVelocity = (real_T (*)[5])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c65_carY = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c65_carZ = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c65_carAngle = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c65_carVelocity = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c65_pedX = (real_T (*)[5])ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c65_pedY = (real_T (*)[5])ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c65_pedZ = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c65_dTranslationX = (real_T (*)[5])ssGetInputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c65_dTranslationY = (real_T (*)[5])ssGetInputPortSignal_wrapper
    (chartInstance->S, 9);
  chartInstance->c65_dTranslationZ = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 10);
  chartInstance->c65_sensorX = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 11);
  chartInstance->c65_sensorY = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 12);
  chartInstance->c65_sensorZ = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 13);
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

void sf_c65_Experiment_3_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3385374550U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2731130230U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2942072747U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1156655782U);
}

mxArray* sf_c65_Experiment_3_cs_get_post_codegen_info(void);
mxArray *sf_c65_Experiment_3_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Ypq7CU1Rt78eS0f0TWIVD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,14,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(5);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(5);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(5);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c65_Experiment_3_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c65_Experiment_3_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c65_Experiment_3_cs_jit_fallback_info(void)
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

mxArray *sf_c65_Experiment_3_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c65_Experiment_3_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c65_Experiment_3_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"dopplerVelocity\",},{M[8],M[0],T\"is_active_c65_Experiment_3_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c65_Experiment_3_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc65_Experiment_3_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc65_Experiment_3_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_3_csMachineNumber_,
           65,
           1,
           1,
           0,
           15,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"carX");
          _SFD_SET_DATA_PROPS(1,2,0,1,"dopplerVelocity");
          _SFD_SET_DATA_PROPS(2,1,1,0,"carY");
          _SFD_SET_DATA_PROPS(3,1,1,0,"carZ");
          _SFD_SET_DATA_PROPS(4,1,1,0,"carAngle");
          _SFD_SET_DATA_PROPS(5,1,1,0,"carVelocity");
          _SFD_SET_DATA_PROPS(6,1,1,0,"pedX");
          _SFD_SET_DATA_PROPS(7,1,1,0,"pedY");
          _SFD_SET_DATA_PROPS(8,1,1,0,"pedZ");
          _SFD_SET_DATA_PROPS(9,1,1,0,"dTranslationX");
          _SFD_SET_DATA_PROPS(10,1,1,0,"dTranslationY");
          _SFD_SET_DATA_PROPS(11,1,1,0,"dTranslationZ");
          _SFD_SET_DATA_PROPS(12,1,1,0,"sensorX");
          _SFD_SET_DATA_PROPS(13,1,1,0,"sensorY");
          _SFD_SET_DATA_PROPS(14,1,1,0,"sensorZ");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,760);
        _SFD_CV_INIT_EML_FOR(0,1,0,498,521,758);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c65_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c65_sf_marshallOut,(MexInFcnForType)
            c65_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c65_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c65_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c65_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c65_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c65_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c65_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c65_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c65_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c65_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c65_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c65_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c65_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c65_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c65_carX);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c65_dopplerVelocity);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c65_carY);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c65_carZ);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c65_carAngle);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c65_carVelocity);
        _SFD_SET_DATA_VALUE_PTR(6U, *chartInstance->c65_pedX);
        _SFD_SET_DATA_VALUE_PTR(7U, *chartInstance->c65_pedY);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c65_pedZ);
        _SFD_SET_DATA_VALUE_PTR(9U, *chartInstance->c65_dTranslationX);
        _SFD_SET_DATA_VALUE_PTR(10U, *chartInstance->c65_dTranslationY);
        _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c65_dTranslationZ);
        _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c65_sensorX);
        _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c65_sensorY);
        _SFD_SET_DATA_VALUE_PTR(14U, chartInstance->c65_sensorZ);
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
  return "5UpZIbSxQVidwt7pSCTmXH";
}

static void sf_opaque_initialize_c65_Experiment_3_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc65_Experiment_3_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c65_Experiment_3_cs((SFc65_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
  initialize_c65_Experiment_3_cs((SFc65_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c65_Experiment_3_cs(void *chartInstanceVar)
{
  enable_c65_Experiment_3_cs((SFc65_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c65_Experiment_3_cs(void *chartInstanceVar)
{
  disable_c65_Experiment_3_cs((SFc65_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c65_Experiment_3_cs(void *chartInstanceVar)
{
  sf_gateway_c65_Experiment_3_cs((SFc65_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c65_Experiment_3_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c65_Experiment_3_cs((SFc65_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c65_Experiment_3_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c65_Experiment_3_cs((SFc65_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c65_Experiment_3_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc65_Experiment_3_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_3_cs_optimization_info();
    }

    finalize_c65_Experiment_3_cs((SFc65_Experiment_3_csInstanceStruct*)
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
  initSimStructsc65_Experiment_3_cs((SFc65_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c65_Experiment_3_cs(SimStruct *S)
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
    initialize_params_c65_Experiment_3_cs((SFc65_Experiment_3_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c65_Experiment_3_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Experiment_3_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      65);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,65,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,65,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,65);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 11, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 12, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 13, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,65,14);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,65,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 14; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,65);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3106050636U));
  ssSetChecksum1(S,(3036644781U));
  ssSetChecksum2(S,(2159851196U));
  ssSetChecksum3(S,(780961104U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c65_Experiment_3_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c65_Experiment_3_cs(SimStruct *S)
{
  SFc65_Experiment_3_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc65_Experiment_3_csInstanceStruct *)utMalloc(sizeof
    (SFc65_Experiment_3_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc65_Experiment_3_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c65_Experiment_3_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c65_Experiment_3_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c65_Experiment_3_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c65_Experiment_3_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c65_Experiment_3_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c65_Experiment_3_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c65_Experiment_3_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c65_Experiment_3_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c65_Experiment_3_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c65_Experiment_3_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c65_Experiment_3_cs;
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

void c65_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c65_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c65_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c65_Experiment_3_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c65_Experiment_3_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
