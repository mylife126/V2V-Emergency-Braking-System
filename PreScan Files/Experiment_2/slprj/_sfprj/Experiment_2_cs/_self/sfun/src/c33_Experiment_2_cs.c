/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_2_cs_sfun.h"
#include "c33_Experiment_2_cs.h"
#include "mwmathutil.h"
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
static const char * c33_debug_family_names[23] = { "TcarMat", "RcarMat",
  "TsensorMat", "FcarMat", "i", "pedThetaTemp", "pedPhiTemp", "pedRTemp",
  "nargin", "nargout", "carX", "carY", "carZ", "carRotZ", "pedX", "pedY", "pedZ",
  "sensorCorrX", "sensorCorrY", "sensorCorrZ", "pedR", "pedTheta", "pedPhi" };

/* Function Declarations */
static void initialize_c33_Experiment_2_cs(SFc33_Experiment_2_csInstanceStruct
  *chartInstance);
static void initialize_params_c33_Experiment_2_cs
  (SFc33_Experiment_2_csInstanceStruct *chartInstance);
static void enable_c33_Experiment_2_cs(SFc33_Experiment_2_csInstanceStruct
  *chartInstance);
static void disable_c33_Experiment_2_cs(SFc33_Experiment_2_csInstanceStruct
  *chartInstance);
static void c33_update_debugger_state_c33_Experiment_2_cs
  (SFc33_Experiment_2_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c33_Experiment_2_cs
  (SFc33_Experiment_2_csInstanceStruct *chartInstance);
static void set_sim_state_c33_Experiment_2_cs
  (SFc33_Experiment_2_csInstanceStruct *chartInstance, const mxArray *c33_st);
static void finalize_c33_Experiment_2_cs(SFc33_Experiment_2_csInstanceStruct
  *chartInstance);
static void sf_gateway_c33_Experiment_2_cs(SFc33_Experiment_2_csInstanceStruct
  *chartInstance);
static void mdl_start_c33_Experiment_2_cs(SFc33_Experiment_2_csInstanceStruct
  *chartInstance);
static void c33_chartstep_c33_Experiment_2_cs
  (SFc33_Experiment_2_csInstanceStruct *chartInstance);
static void initSimStructsc33_Experiment_2_cs
  (SFc33_Experiment_2_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c33_machineNumber, uint32_T
  c33_chartNumber, uint32_T c33_instanceNumber);
static const mxArray *c33_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData);
static void c33_emlrt_marshallIn(SFc33_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c33_b_pedPhi, const char_T *c33_identifier,
  real_T c33_y[3]);
static void c33_b_emlrt_marshallIn(SFc33_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId,
  real_T c33_y[3]);
static void c33_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData);
static const mxArray *c33_b_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData);
static real_T c33_c_emlrt_marshallIn(SFc33_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId);
static void c33_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData);
static const mxArray *c33_c_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData);
static void c33_d_emlrt_marshallIn(SFc33_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId,
  real_T c33_y[4]);
static void c33_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData);
static const mxArray *c33_d_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData);
static void c33_e_emlrt_marshallIn(SFc33_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId,
  real_T c33_y[16]);
static void c33_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData);
static void c33_info_helper(const mxArray **c33_info);
static const mxArray *c33_emlrt_marshallOut(const char * c33_u);
static const mxArray *c33_b_emlrt_marshallOut(const uint32_T c33_u);
static real_T c33_cosd(SFc33_Experiment_2_csInstanceStruct *chartInstance,
  real_T c33_x);
static boolean_T c33_isfinite(SFc33_Experiment_2_csInstanceStruct *chartInstance,
  real_T c33_x);
static void c33_eml_scalar_eg(SFc33_Experiment_2_csInstanceStruct *chartInstance);
static real_T c33_sind(SFc33_Experiment_2_csInstanceStruct *chartInstance,
  real_T c33_x);
static void c33_b_eml_scalar_eg(SFc33_Experiment_2_csInstanceStruct
  *chartInstance);
static void c33_threshold(SFc33_Experiment_2_csInstanceStruct *chartInstance);
static void c33_c_eml_scalar_eg(SFc33_Experiment_2_csInstanceStruct
  *chartInstance);
static real_T c33_hypot(SFc33_Experiment_2_csInstanceStruct *chartInstance,
  real_T c33_x, real_T c33_y);
static real_T c33_atan2(SFc33_Experiment_2_csInstanceStruct *chartInstance,
  real_T c33_y, real_T c33_x);
static const mxArray *c33_e_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData);
static int32_T c33_f_emlrt_marshallIn(SFc33_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId);
static void c33_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData);
static uint8_T c33_g_emlrt_marshallIn(SFc33_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c33_b_is_active_c33_Experiment_2_cs, const
  char_T *c33_identifier);
static uint8_T c33_h_emlrt_marshallIn(SFc33_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId);
static void c33_b_cosd(SFc33_Experiment_2_csInstanceStruct *chartInstance,
  real_T *c33_x);
static void c33_b_sind(SFc33_Experiment_2_csInstanceStruct *chartInstance,
  real_T *c33_x);
static void init_dsm_address_info(SFc33_Experiment_2_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc33_Experiment_2_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c33_Experiment_2_cs(SFc33_Experiment_2_csInstanceStruct
  *chartInstance)
{
  chartInstance->c33_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c33_is_active_c33_Experiment_2_cs = 0U;
}

static void initialize_params_c33_Experiment_2_cs
  (SFc33_Experiment_2_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c33_Experiment_2_cs(SFc33_Experiment_2_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c33_Experiment_2_cs(SFc33_Experiment_2_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c33_update_debugger_state_c33_Experiment_2_cs
  (SFc33_Experiment_2_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c33_Experiment_2_cs
  (SFc33_Experiment_2_csInstanceStruct *chartInstance)
{
  const mxArray *c33_st;
  const mxArray *c33_y = NULL;
  int32_T c33_i0;
  real_T c33_u[3];
  const mxArray *c33_b_y = NULL;
  int32_T c33_i1;
  real_T c33_b_u[3];
  const mxArray *c33_c_y = NULL;
  int32_T c33_i2;
  real_T c33_c_u[3];
  const mxArray *c33_d_y = NULL;
  uint8_T c33_hoistedGlobal;
  uint8_T c33_d_u;
  const mxArray *c33_e_y = NULL;
  c33_st = NULL;
  c33_st = NULL;
  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_createcellmatrix(4, 1), false);
  for (c33_i0 = 0; c33_i0 < 3; c33_i0++) {
    c33_u[c33_i0] = (*chartInstance->c33_pedPhi)[c33_i0];
  }

  c33_b_y = NULL;
  sf_mex_assign(&c33_b_y, sf_mex_create("y", c33_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c33_y, 0, c33_b_y);
  for (c33_i1 = 0; c33_i1 < 3; c33_i1++) {
    c33_b_u[c33_i1] = (*chartInstance->c33_pedR)[c33_i1];
  }

  c33_c_y = NULL;
  sf_mex_assign(&c33_c_y, sf_mex_create("y", c33_b_u, 0, 0U, 1U, 0U, 1, 3),
                false);
  sf_mex_setcell(c33_y, 1, c33_c_y);
  for (c33_i2 = 0; c33_i2 < 3; c33_i2++) {
    c33_c_u[c33_i2] = (*chartInstance->c33_pedTheta)[c33_i2];
  }

  c33_d_y = NULL;
  sf_mex_assign(&c33_d_y, sf_mex_create("y", c33_c_u, 0, 0U, 1U, 0U, 1, 3),
                false);
  sf_mex_setcell(c33_y, 2, c33_d_y);
  c33_hoistedGlobal = chartInstance->c33_is_active_c33_Experiment_2_cs;
  c33_d_u = c33_hoistedGlobal;
  c33_e_y = NULL;
  sf_mex_assign(&c33_e_y, sf_mex_create("y", &c33_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c33_y, 3, c33_e_y);
  sf_mex_assign(&c33_st, c33_y, false);
  return c33_st;
}

static void set_sim_state_c33_Experiment_2_cs
  (SFc33_Experiment_2_csInstanceStruct *chartInstance, const mxArray *c33_st)
{
  const mxArray *c33_u;
  real_T c33_dv0[3];
  int32_T c33_i3;
  real_T c33_dv1[3];
  int32_T c33_i4;
  real_T c33_dv2[3];
  int32_T c33_i5;
  chartInstance->c33_doneDoubleBufferReInit = true;
  c33_u = sf_mex_dup(c33_st);
  c33_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c33_u, 0)),
                       "pedPhi", c33_dv0);
  for (c33_i3 = 0; c33_i3 < 3; c33_i3++) {
    (*chartInstance->c33_pedPhi)[c33_i3] = c33_dv0[c33_i3];
  }

  c33_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c33_u, 1)),
                       "pedR", c33_dv1);
  for (c33_i4 = 0; c33_i4 < 3; c33_i4++) {
    (*chartInstance->c33_pedR)[c33_i4] = c33_dv1[c33_i4];
  }

  c33_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c33_u, 2)),
                       "pedTheta", c33_dv2);
  for (c33_i5 = 0; c33_i5 < 3; c33_i5++) {
    (*chartInstance->c33_pedTheta)[c33_i5] = c33_dv2[c33_i5];
  }

  chartInstance->c33_is_active_c33_Experiment_2_cs = c33_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c33_u, 3)),
     "is_active_c33_Experiment_2_cs");
  sf_mex_destroy(&c33_u);
  c33_update_debugger_state_c33_Experiment_2_cs(chartInstance);
  sf_mex_destroy(&c33_st);
}

static void finalize_c33_Experiment_2_cs(SFc33_Experiment_2_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c33_Experiment_2_cs(SFc33_Experiment_2_csInstanceStruct
  *chartInstance)
{
  int32_T c33_i6;
  int32_T c33_i7;
  int32_T c33_i8;
  int32_T c33_i9;
  int32_T c33_i10;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 32U, chartInstance->c33_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c33_carX, 0U);
  chartInstance->c33_sfEvent = CALL_EVENT;
  c33_chartstep_c33_Experiment_2_cs(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_2_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c33_i6 = 0; c33_i6 < 3; c33_i6++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c33_pedR)[c33_i6], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c33_carY, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c33_carZ, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c33_carRotZ, 4U);
  for (c33_i7 = 0; c33_i7 < 3; c33_i7++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c33_pedX)[c33_i7], 5U);
  }

  for (c33_i8 = 0; c33_i8 < 3; c33_i8++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c33_pedY)[c33_i8], 6U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c33_pedZ, 7U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c33_sensorCorrX, 8U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c33_sensorCorrY, 9U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c33_sensorCorrZ, 10U);
  for (c33_i9 = 0; c33_i9 < 3; c33_i9++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c33_pedTheta)[c33_i9], 11U);
  }

  for (c33_i10 = 0; c33_i10 < 3; c33_i10++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c33_pedPhi)[c33_i10], 12U);
  }
}

static void mdl_start_c33_Experiment_2_cs(SFc33_Experiment_2_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c33_chartstep_c33_Experiment_2_cs
  (SFc33_Experiment_2_csInstanceStruct *chartInstance)
{
  real_T c33_hoistedGlobal;
  real_T c33_b_hoistedGlobal;
  real_T c33_c_hoistedGlobal;
  real_T c33_d_hoistedGlobal;
  real_T c33_e_hoistedGlobal;
  real_T c33_f_hoistedGlobal;
  real_T c33_g_hoistedGlobal;
  real_T c33_h_hoistedGlobal;
  real_T c33_b_carX;
  real_T c33_b_carY;
  real_T c33_b_carZ;
  real_T c33_b_carRotZ;
  int32_T c33_i11;
  real_T c33_b_pedX[3];
  int32_T c33_i12;
  real_T c33_b_pedY[3];
  real_T c33_b_pedZ;
  real_T c33_b_sensorCorrX;
  real_T c33_b_sensorCorrY;
  real_T c33_b_sensorCorrZ;
  uint32_T c33_debug_family_var_map[23];
  real_T c33_TcarMat[16];
  real_T c33_RcarMat[16];
  real_T c33_TsensorMat[16];
  real_T c33_FcarMat[4];
  real_T c33_i;
  real_T c33_pedThetaTemp;
  real_T c33_pedPhiTemp;
  real_T c33_pedRTemp;
  real_T c33_nargin = 10.0;
  real_T c33_nargout = 3.0;
  real_T c33_b_pedR[3];
  real_T c33_b_pedTheta[3];
  real_T c33_b_pedPhi[3];
  int32_T c33_i13;
  int32_T c33_i14;
  static real_T c33_dv3[4] = { 0.0, 0.0, 0.0, 1.0 };

  real_T c33_d0;
  real_T c33_d1;
  real_T c33_d2;
  real_T c33_d3;
  int32_T c33_i15;
  int32_T c33_i16;
  static real_T c33_dv4[4] = { 0.0, 0.0, 1.0, 0.0 };

  int32_T c33_i17;
  int32_T c33_i18;
  int32_T c33_i19;
  int32_T c33_i20;
  int32_T c33_i21;
  real_T c33_a[16];
  int32_T c33_i22;
  real_T c33_b[16];
  int32_T c33_i23;
  int32_T c33_i24;
  int32_T c33_i25;
  real_T c33_y[16];
  int32_T c33_i26;
  int32_T c33_i27;
  int32_T c33_i28;
  int32_T c33_i29;
  int32_T c33_i30;
  int32_T c33_i31;
  int32_T c33_i32;
  int32_T c33_i33;
  int32_T c33_i34;
  int32_T c33_i35;
  int32_T c33_i36;
  real_T c33_C[4];
  int32_T c33_i37;
  int32_T c33_i38;
  int32_T c33_i39;
  int32_T c33_i40;
  int32_T c33_i41;
  int32_T c33_i42;
  static real_T c33_b_b[4] = { 0.0, 0.0, 0.0, 1.0 };

  int32_T c33_i43;
  int32_T c33_i44;
  int32_T c33_i45;
  int32_T c33_b_i;
  real_T c33_x;
  real_T c33_b_y;
  real_T c33_z;
  real_T c33_hypotxy;
  real_T c33_b_pedRTemp;
  real_T c33_b_pedPhiTemp;
  real_T c33_b_pedThetaTemp;
  real_T c33_A;
  real_T c33_b_x;
  real_T c33_c_x;
  real_T c33_d_x;
  real_T c33_c_y;
  real_T c33_b_A;
  real_T c33_e_x;
  real_T c33_f_x;
  real_T c33_g_x;
  real_T c33_d_y;
  int32_T c33_i46;
  int32_T c33_i47;
  int32_T c33_i48;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 32U, chartInstance->c33_sfEvent);
  c33_hoistedGlobal = *chartInstance->c33_carX;
  c33_b_hoistedGlobal = *chartInstance->c33_carY;
  c33_c_hoistedGlobal = *chartInstance->c33_carZ;
  c33_d_hoistedGlobal = *chartInstance->c33_carRotZ;
  c33_e_hoistedGlobal = *chartInstance->c33_pedZ;
  c33_f_hoistedGlobal = *chartInstance->c33_sensorCorrX;
  c33_g_hoistedGlobal = *chartInstance->c33_sensorCorrY;
  c33_h_hoistedGlobal = *chartInstance->c33_sensorCorrZ;
  c33_b_carX = c33_hoistedGlobal;
  c33_b_carY = c33_b_hoistedGlobal;
  c33_b_carZ = c33_c_hoistedGlobal;
  c33_b_carRotZ = c33_d_hoistedGlobal;
  for (c33_i11 = 0; c33_i11 < 3; c33_i11++) {
    c33_b_pedX[c33_i11] = (*chartInstance->c33_pedX)[c33_i11];
  }

  for (c33_i12 = 0; c33_i12 < 3; c33_i12++) {
    c33_b_pedY[c33_i12] = (*chartInstance->c33_pedY)[c33_i12];
  }

  c33_b_pedZ = c33_e_hoistedGlobal;
  c33_b_sensorCorrX = c33_f_hoistedGlobal;
  c33_b_sensorCorrY = c33_g_hoistedGlobal;
  c33_b_sensorCorrZ = c33_h_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 23U, 23U, c33_debug_family_names,
    c33_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c33_TcarMat, 0U, c33_d_sf_marshallOut,
    c33_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c33_RcarMat, 1U, c33_d_sf_marshallOut,
    c33_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c33_TsensorMat, 2U, c33_d_sf_marshallOut,
    c33_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c33_FcarMat, 3U, c33_c_sf_marshallOut,
    c33_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c33_i, 4U, c33_b_sf_marshallOut,
    c33_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c33_pedThetaTemp, 5U,
    c33_b_sf_marshallOut, c33_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c33_pedPhiTemp, 6U, c33_b_sf_marshallOut,
    c33_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c33_pedRTemp, 7U, c33_b_sf_marshallOut,
    c33_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c33_nargin, 8U, c33_b_sf_marshallOut,
    c33_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c33_nargout, 9U, c33_b_sf_marshallOut,
    c33_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c33_b_carX, 10U, c33_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c33_b_carY, 11U, c33_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c33_b_carZ, 12U, c33_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c33_b_carRotZ, 13U, c33_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c33_b_pedX, 14U, c33_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c33_b_pedY, 15U, c33_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c33_b_pedZ, 16U, c33_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c33_b_sensorCorrX, 17U, c33_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c33_b_sensorCorrY, 18U, c33_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c33_b_sensorCorrZ, 19U, c33_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c33_b_pedR, 20U, c33_sf_marshallOut,
    c33_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c33_b_pedTheta, 21U, c33_sf_marshallOut,
    c33_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c33_b_pedPhi, 22U, c33_sf_marshallOut,
    c33_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 3);
  c33_TcarMat[0] = 1.0;
  c33_TcarMat[4] = 0.0;
  c33_TcarMat[8] = 0.0;
  c33_TcarMat[12] = c33_b_carX;
  c33_TcarMat[1] = 0.0;
  c33_TcarMat[5] = 1.0;
  c33_TcarMat[9] = 0.0;
  c33_TcarMat[13] = c33_b_carY;
  c33_TcarMat[2] = 0.0;
  c33_TcarMat[6] = 0.0;
  c33_TcarMat[10] = 1.0;
  c33_TcarMat[14] = c33_b_carZ;
  c33_i13 = 0;
  for (c33_i14 = 0; c33_i14 < 4; c33_i14++) {
    c33_TcarMat[c33_i13 + 3] = c33_dv3[c33_i14];
    c33_i13 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 5);
  c33_d0 = c33_b_carRotZ;
  c33_b_cosd(chartInstance, &c33_d0);
  c33_d1 = c33_b_carRotZ;
  c33_b_sind(chartInstance, &c33_d1);
  c33_d2 = c33_b_carRotZ;
  c33_b_sind(chartInstance, &c33_d2);
  c33_d3 = c33_b_carRotZ;
  c33_b_cosd(chartInstance, &c33_d3);
  c33_RcarMat[0] = c33_d0;
  c33_RcarMat[4] = -c33_d1;
  c33_RcarMat[8] = 0.0;
  c33_RcarMat[12] = 0.0;
  c33_RcarMat[1] = c33_d2;
  c33_RcarMat[5] = c33_d3;
  c33_RcarMat[9] = 0.0;
  c33_RcarMat[13] = 0.0;
  c33_i15 = 0;
  for (c33_i16 = 0; c33_i16 < 4; c33_i16++) {
    c33_RcarMat[c33_i15 + 2] = c33_dv4[c33_i16];
    c33_i15 += 4;
  }

  c33_i17 = 0;
  for (c33_i18 = 0; c33_i18 < 4; c33_i18++) {
    c33_RcarMat[c33_i17 + 3] = c33_dv3[c33_i18];
    c33_i17 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 10);
  c33_TsensorMat[0] = 1.0;
  c33_TsensorMat[4] = 0.0;
  c33_TsensorMat[8] = 0.0;
  c33_TsensorMat[12] = c33_b_sensorCorrX;
  c33_TsensorMat[1] = 0.0;
  c33_TsensorMat[5] = 0.0;
  c33_TsensorMat[9] = 1.0;
  c33_TsensorMat[13] = c33_b_sensorCorrY;
  c33_TsensorMat[2] = 0.0;
  c33_TsensorMat[6] = 1.0;
  c33_TsensorMat[10] = 0.0;
  c33_TsensorMat[14] = c33_b_sensorCorrZ;
  c33_i19 = 0;
  for (c33_i20 = 0; c33_i20 < 4; c33_i20++) {
    c33_TsensorMat[c33_i19 + 3] = c33_dv3[c33_i20];
    c33_i19 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 12);
  for (c33_i21 = 0; c33_i21 < 16; c33_i21++) {
    c33_a[c33_i21] = c33_TcarMat[c33_i21];
  }

  for (c33_i22 = 0; c33_i22 < 16; c33_i22++) {
    c33_b[c33_i22] = c33_RcarMat[c33_i22];
  }

  c33_b_eml_scalar_eg(chartInstance);
  c33_b_eml_scalar_eg(chartInstance);
  c33_threshold(chartInstance);
  for (c33_i23 = 0; c33_i23 < 4; c33_i23++) {
    c33_i24 = 0;
    for (c33_i25 = 0; c33_i25 < 4; c33_i25++) {
      c33_y[c33_i24 + c33_i23] = 0.0;
      c33_i26 = 0;
      for (c33_i27 = 0; c33_i27 < 4; c33_i27++) {
        c33_y[c33_i24 + c33_i23] += c33_a[c33_i26 + c33_i23] * c33_b[c33_i27 +
          c33_i24];
        c33_i26 += 4;
      }

      c33_i24 += 4;
    }
  }

  for (c33_i28 = 0; c33_i28 < 16; c33_i28++) {
    c33_b[c33_i28] = c33_TsensorMat[c33_i28];
  }

  c33_b_eml_scalar_eg(chartInstance);
  c33_b_eml_scalar_eg(chartInstance);
  c33_threshold(chartInstance);
  for (c33_i29 = 0; c33_i29 < 4; c33_i29++) {
    c33_i30 = 0;
    for (c33_i31 = 0; c33_i31 < 4; c33_i31++) {
      c33_a[c33_i30 + c33_i29] = 0.0;
      c33_i32 = 0;
      for (c33_i33 = 0; c33_i33 < 4; c33_i33++) {
        c33_a[c33_i30 + c33_i29] += c33_y[c33_i32 + c33_i29] * c33_b[c33_i33 +
          c33_i30];
        c33_i32 += 4;
      }

      c33_i30 += 4;
    }
  }

  c33_c_eml_scalar_eg(chartInstance);
  c33_c_eml_scalar_eg(chartInstance);
  for (c33_i34 = 0; c33_i34 < 4; c33_i34++) {
    c33_FcarMat[c33_i34] = 0.0;
  }

  for (c33_i35 = 0; c33_i35 < 4; c33_i35++) {
    c33_FcarMat[c33_i35] = 0.0;
  }

  for (c33_i36 = 0; c33_i36 < 4; c33_i36++) {
    c33_C[c33_i36] = c33_FcarMat[c33_i36];
  }

  for (c33_i37 = 0; c33_i37 < 4; c33_i37++) {
    c33_FcarMat[c33_i37] = c33_C[c33_i37];
  }

  c33_threshold(chartInstance);
  for (c33_i38 = 0; c33_i38 < 4; c33_i38++) {
    c33_C[c33_i38] = c33_FcarMat[c33_i38];
  }

  for (c33_i39 = 0; c33_i39 < 4; c33_i39++) {
    c33_FcarMat[c33_i39] = c33_C[c33_i39];
  }

  for (c33_i40 = 0; c33_i40 < 4; c33_i40++) {
    c33_FcarMat[c33_i40] = 0.0;
    c33_i41 = 0;
    for (c33_i42 = 0; c33_i42 < 4; c33_i42++) {
      c33_FcarMat[c33_i40] += c33_a[c33_i41 + c33_i40] * c33_b_b[c33_i42];
      c33_i41 += 4;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 14);
  for (c33_i43 = 0; c33_i43 < 3; c33_i43++) {
    c33_b_pedR[c33_i43] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 15);
  for (c33_i44 = 0; c33_i44 < 3; c33_i44++) {
    c33_b_pedTheta[c33_i44] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 16);
  for (c33_i45 = 0; c33_i45 < 3; c33_i45++) {
    c33_b_pedPhi[c33_i45] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 18);
  c33_i = 1.0;
  c33_b_i = 0;
  while (c33_b_i < 3) {
    c33_i = 1.0 + (real_T)c33_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 20);
    c33_x = c33_b_pedX[_SFD_EML_ARRAY_BOUNDS_CHECK("pedX", (int32_T)
      _SFD_INTEGER_CHECK("i", c33_i), 1, 3, 1, 0) - 1] - c33_FcarMat[0];
    c33_b_y = c33_b_pedY[_SFD_EML_ARRAY_BOUNDS_CHECK("pedY", (int32_T)
      _SFD_INTEGER_CHECK("i", c33_i), 1, 3, 1, 0) - 1] - c33_FcarMat[1];
    c33_z = c33_b_pedZ - c33_FcarMat[2];
    c33_hypotxy = c33_hypot(chartInstance, c33_x, c33_b_y);
    c33_b_pedRTemp = c33_hypot(chartInstance, c33_hypotxy, c33_z);
    c33_b_pedPhiTemp = c33_atan2(chartInstance, c33_z, c33_hypotxy);
    c33_b_pedThetaTemp = c33_atan2(chartInstance, c33_b_y, c33_x);
    c33_pedThetaTemp = c33_b_pedThetaTemp;
    c33_pedPhiTemp = c33_b_pedPhiTemp;
    c33_pedRTemp = c33_b_pedRTemp;
    _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 22);
    c33_b_pedR[_SFD_EML_ARRAY_BOUNDS_CHECK("pedR", (int32_T)_SFD_INTEGER_CHECK(
      "i", c33_i), 1, 3, 1, 0) - 1] = c33_pedRTemp;
    _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 23);
    c33_A = c33_pedThetaTemp * 180.0;
    c33_b_x = c33_A;
    c33_c_x = c33_b_x;
    c33_d_x = c33_c_x;
    c33_c_y = c33_d_x / 3.1415926535897931;
    c33_b_pedTheta[_SFD_EML_ARRAY_BOUNDS_CHECK("pedTheta", (int32_T)
      _SFD_INTEGER_CHECK("i", c33_i), 1, 3, 1, 0) - 1] = -(c33_c_y -
      c33_b_carRotZ);
    _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 24);
    c33_b_A = c33_pedPhiTemp * 180.0;
    c33_e_x = c33_b_A;
    c33_f_x = c33_e_x;
    c33_g_x = c33_f_x;
    c33_d_y = c33_g_x / 3.1415926535897931;
    c33_b_pedPhi[_SFD_EML_ARRAY_BOUNDS_CHECK("pedPhi", (int32_T)
      _SFD_INTEGER_CHECK("i", c33_i), 1, 3, 1, 0) - 1] = c33_d_y;
    c33_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, -24);
  _SFD_SYMBOL_SCOPE_POP();
  for (c33_i46 = 0; c33_i46 < 3; c33_i46++) {
    (*chartInstance->c33_pedR)[c33_i46] = c33_b_pedR[c33_i46];
  }

  for (c33_i47 = 0; c33_i47 < 3; c33_i47++) {
    (*chartInstance->c33_pedTheta)[c33_i47] = c33_b_pedTheta[c33_i47];
  }

  for (c33_i48 = 0; c33_i48 < 3; c33_i48++) {
    (*chartInstance->c33_pedPhi)[c33_i48] = c33_b_pedPhi[c33_i48];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 32U, chartInstance->c33_sfEvent);
}

static void initSimStructsc33_Experiment_2_cs
  (SFc33_Experiment_2_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c33_machineNumber, uint32_T
  c33_chartNumber, uint32_T c33_instanceNumber)
{
  (void)c33_machineNumber;
  (void)c33_chartNumber;
  (void)c33_instanceNumber;
}

static const mxArray *c33_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData)
{
  const mxArray *c33_mxArrayOutData = NULL;
  int32_T c33_i49;
  real_T c33_b_inData[3];
  int32_T c33_i50;
  real_T c33_u[3];
  const mxArray *c33_y = NULL;
  SFc33_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc33_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c33_mxArrayOutData = NULL;
  for (c33_i49 = 0; c33_i49 < 3; c33_i49++) {
    c33_b_inData[c33_i49] = (*(real_T (*)[3])c33_inData)[c33_i49];
  }

  for (c33_i50 = 0; c33_i50 < 3; c33_i50++) {
    c33_u[c33_i50] = c33_b_inData[c33_i50];
  }

  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_create("y", c33_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c33_mxArrayOutData, c33_y, false);
  return c33_mxArrayOutData;
}

static void c33_emlrt_marshallIn(SFc33_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c33_b_pedPhi, const char_T *c33_identifier,
  real_T c33_y[3])
{
  emlrtMsgIdentifier c33_thisId;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_b_pedPhi), &c33_thisId,
    c33_y);
  sf_mex_destroy(&c33_b_pedPhi);
}

static void c33_b_emlrt_marshallIn(SFc33_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId,
  real_T c33_y[3])
{
  real_T c33_dv5[3];
  int32_T c33_i51;
  (void)chartInstance;
  sf_mex_import(c33_parentId, sf_mex_dup(c33_u), c33_dv5, 1, 0, 0U, 1, 0U, 1, 3);
  for (c33_i51 = 0; c33_i51 < 3; c33_i51++) {
    c33_y[c33_i51] = c33_dv5[c33_i51];
  }

  sf_mex_destroy(&c33_u);
}

static void c33_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData)
{
  const mxArray *c33_b_pedPhi;
  const char_T *c33_identifier;
  emlrtMsgIdentifier c33_thisId;
  real_T c33_y[3];
  int32_T c33_i52;
  SFc33_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc33_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c33_b_pedPhi = sf_mex_dup(c33_mxArrayInData);
  c33_identifier = c33_varName;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_b_pedPhi), &c33_thisId,
    c33_y);
  sf_mex_destroy(&c33_b_pedPhi);
  for (c33_i52 = 0; c33_i52 < 3; c33_i52++) {
    (*(real_T (*)[3])c33_outData)[c33_i52] = c33_y[c33_i52];
  }

  sf_mex_destroy(&c33_mxArrayInData);
}

static const mxArray *c33_b_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData)
{
  const mxArray *c33_mxArrayOutData = NULL;
  real_T c33_u;
  const mxArray *c33_y = NULL;
  SFc33_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc33_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c33_mxArrayOutData = NULL;
  c33_u = *(real_T *)c33_inData;
  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_create("y", &c33_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c33_mxArrayOutData, c33_y, false);
  return c33_mxArrayOutData;
}

static real_T c33_c_emlrt_marshallIn(SFc33_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId)
{
  real_T c33_y;
  real_T c33_d4;
  (void)chartInstance;
  sf_mex_import(c33_parentId, sf_mex_dup(c33_u), &c33_d4, 1, 0, 0U, 0, 0U, 0);
  c33_y = c33_d4;
  sf_mex_destroy(&c33_u);
  return c33_y;
}

static void c33_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData)
{
  const mxArray *c33_nargout;
  const char_T *c33_identifier;
  emlrtMsgIdentifier c33_thisId;
  real_T c33_y;
  SFc33_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc33_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c33_nargout = sf_mex_dup(c33_mxArrayInData);
  c33_identifier = c33_varName;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_y = c33_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_nargout),
    &c33_thisId);
  sf_mex_destroy(&c33_nargout);
  *(real_T *)c33_outData = c33_y;
  sf_mex_destroy(&c33_mxArrayInData);
}

static const mxArray *c33_c_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData)
{
  const mxArray *c33_mxArrayOutData = NULL;
  int32_T c33_i53;
  real_T c33_b_inData[4];
  int32_T c33_i54;
  real_T c33_u[4];
  const mxArray *c33_y = NULL;
  SFc33_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc33_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c33_mxArrayOutData = NULL;
  for (c33_i53 = 0; c33_i53 < 4; c33_i53++) {
    c33_b_inData[c33_i53] = (*(real_T (*)[4])c33_inData)[c33_i53];
  }

  for (c33_i54 = 0; c33_i54 < 4; c33_i54++) {
    c33_u[c33_i54] = c33_b_inData[c33_i54];
  }

  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_create("y", c33_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c33_mxArrayOutData, c33_y, false);
  return c33_mxArrayOutData;
}

static void c33_d_emlrt_marshallIn(SFc33_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId,
  real_T c33_y[4])
{
  real_T c33_dv6[4];
  int32_T c33_i55;
  (void)chartInstance;
  sf_mex_import(c33_parentId, sf_mex_dup(c33_u), c33_dv6, 1, 0, 0U, 1, 0U, 1, 4);
  for (c33_i55 = 0; c33_i55 < 4; c33_i55++) {
    c33_y[c33_i55] = c33_dv6[c33_i55];
  }

  sf_mex_destroy(&c33_u);
}

static void c33_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData)
{
  const mxArray *c33_FcarMat;
  const char_T *c33_identifier;
  emlrtMsgIdentifier c33_thisId;
  real_T c33_y[4];
  int32_T c33_i56;
  SFc33_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc33_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c33_FcarMat = sf_mex_dup(c33_mxArrayInData);
  c33_identifier = c33_varName;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_FcarMat), &c33_thisId,
    c33_y);
  sf_mex_destroy(&c33_FcarMat);
  for (c33_i56 = 0; c33_i56 < 4; c33_i56++) {
    (*(real_T (*)[4])c33_outData)[c33_i56] = c33_y[c33_i56];
  }

  sf_mex_destroy(&c33_mxArrayInData);
}

static const mxArray *c33_d_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData)
{
  const mxArray *c33_mxArrayOutData = NULL;
  int32_T c33_i57;
  int32_T c33_i58;
  int32_T c33_i59;
  real_T c33_b_inData[16];
  int32_T c33_i60;
  int32_T c33_i61;
  int32_T c33_i62;
  real_T c33_u[16];
  const mxArray *c33_y = NULL;
  SFc33_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc33_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c33_mxArrayOutData = NULL;
  c33_i57 = 0;
  for (c33_i58 = 0; c33_i58 < 4; c33_i58++) {
    for (c33_i59 = 0; c33_i59 < 4; c33_i59++) {
      c33_b_inData[c33_i59 + c33_i57] = (*(real_T (*)[16])c33_inData)[c33_i59 +
        c33_i57];
    }

    c33_i57 += 4;
  }

  c33_i60 = 0;
  for (c33_i61 = 0; c33_i61 < 4; c33_i61++) {
    for (c33_i62 = 0; c33_i62 < 4; c33_i62++) {
      c33_u[c33_i62 + c33_i60] = c33_b_inData[c33_i62 + c33_i60];
    }

    c33_i60 += 4;
  }

  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_create("y", c33_u, 0, 0U, 1U, 0U, 2, 4, 4), false);
  sf_mex_assign(&c33_mxArrayOutData, c33_y, false);
  return c33_mxArrayOutData;
}

static void c33_e_emlrt_marshallIn(SFc33_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId,
  real_T c33_y[16])
{
  real_T c33_dv7[16];
  int32_T c33_i63;
  (void)chartInstance;
  sf_mex_import(c33_parentId, sf_mex_dup(c33_u), c33_dv7, 1, 0, 0U, 1, 0U, 2, 4,
                4);
  for (c33_i63 = 0; c33_i63 < 16; c33_i63++) {
    c33_y[c33_i63] = c33_dv7[c33_i63];
  }

  sf_mex_destroy(&c33_u);
}

static void c33_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData)
{
  const mxArray *c33_TsensorMat;
  const char_T *c33_identifier;
  emlrtMsgIdentifier c33_thisId;
  real_T c33_y[16];
  int32_T c33_i64;
  int32_T c33_i65;
  int32_T c33_i66;
  SFc33_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc33_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c33_TsensorMat = sf_mex_dup(c33_mxArrayInData);
  c33_identifier = c33_varName;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_TsensorMat), &c33_thisId,
    c33_y);
  sf_mex_destroy(&c33_TsensorMat);
  c33_i64 = 0;
  for (c33_i65 = 0; c33_i65 < 4; c33_i65++) {
    for (c33_i66 = 0; c33_i66 < 4; c33_i66++) {
      (*(real_T (*)[16])c33_outData)[c33_i66 + c33_i64] = c33_y[c33_i66 +
        c33_i64];
    }

    c33_i64 += 4;
  }

  sf_mex_destroy(&c33_mxArrayInData);
}

const mxArray *sf_c33_Experiment_2_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c33_nameCaptureInfo = NULL;
  c33_nameCaptureInfo = NULL;
  sf_mex_assign(&c33_nameCaptureInfo, sf_mex_createstruct("structure", 2, 54, 1),
                false);
  c33_info_helper(&c33_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c33_nameCaptureInfo);
  return c33_nameCaptureInfo;
}

static void c33_info_helper(const mxArray **c33_info)
{
  const mxArray *c33_rhs0 = NULL;
  const mxArray *c33_lhs0 = NULL;
  const mxArray *c33_rhs1 = NULL;
  const mxArray *c33_lhs1 = NULL;
  const mxArray *c33_rhs2 = NULL;
  const mxArray *c33_lhs2 = NULL;
  const mxArray *c33_rhs3 = NULL;
  const mxArray *c33_lhs3 = NULL;
  const mxArray *c33_rhs4 = NULL;
  const mxArray *c33_lhs4 = NULL;
  const mxArray *c33_rhs5 = NULL;
  const mxArray *c33_lhs5 = NULL;
  const mxArray *c33_rhs6 = NULL;
  const mxArray *c33_lhs6 = NULL;
  const mxArray *c33_rhs7 = NULL;
  const mxArray *c33_lhs7 = NULL;
  const mxArray *c33_rhs8 = NULL;
  const mxArray *c33_lhs8 = NULL;
  const mxArray *c33_rhs9 = NULL;
  const mxArray *c33_lhs9 = NULL;
  const mxArray *c33_rhs10 = NULL;
  const mxArray *c33_lhs10 = NULL;
  const mxArray *c33_rhs11 = NULL;
  const mxArray *c33_lhs11 = NULL;
  const mxArray *c33_rhs12 = NULL;
  const mxArray *c33_lhs12 = NULL;
  const mxArray *c33_rhs13 = NULL;
  const mxArray *c33_lhs13 = NULL;
  const mxArray *c33_rhs14 = NULL;
  const mxArray *c33_lhs14 = NULL;
  const mxArray *c33_rhs15 = NULL;
  const mxArray *c33_lhs15 = NULL;
  const mxArray *c33_rhs16 = NULL;
  const mxArray *c33_lhs16 = NULL;
  const mxArray *c33_rhs17 = NULL;
  const mxArray *c33_lhs17 = NULL;
  const mxArray *c33_rhs18 = NULL;
  const mxArray *c33_lhs18 = NULL;
  const mxArray *c33_rhs19 = NULL;
  const mxArray *c33_lhs19 = NULL;
  const mxArray *c33_rhs20 = NULL;
  const mxArray *c33_lhs20 = NULL;
  const mxArray *c33_rhs21 = NULL;
  const mxArray *c33_lhs21 = NULL;
  const mxArray *c33_rhs22 = NULL;
  const mxArray *c33_lhs22 = NULL;
  const mxArray *c33_rhs23 = NULL;
  const mxArray *c33_lhs23 = NULL;
  const mxArray *c33_rhs24 = NULL;
  const mxArray *c33_lhs24 = NULL;
  const mxArray *c33_rhs25 = NULL;
  const mxArray *c33_lhs25 = NULL;
  const mxArray *c33_rhs26 = NULL;
  const mxArray *c33_lhs26 = NULL;
  const mxArray *c33_rhs27 = NULL;
  const mxArray *c33_lhs27 = NULL;
  const mxArray *c33_rhs28 = NULL;
  const mxArray *c33_lhs28 = NULL;
  const mxArray *c33_rhs29 = NULL;
  const mxArray *c33_lhs29 = NULL;
  const mxArray *c33_rhs30 = NULL;
  const mxArray *c33_lhs30 = NULL;
  const mxArray *c33_rhs31 = NULL;
  const mxArray *c33_lhs31 = NULL;
  const mxArray *c33_rhs32 = NULL;
  const mxArray *c33_lhs32 = NULL;
  const mxArray *c33_rhs33 = NULL;
  const mxArray *c33_lhs33 = NULL;
  const mxArray *c33_rhs34 = NULL;
  const mxArray *c33_lhs34 = NULL;
  const mxArray *c33_rhs35 = NULL;
  const mxArray *c33_lhs35 = NULL;
  const mxArray *c33_rhs36 = NULL;
  const mxArray *c33_lhs36 = NULL;
  const mxArray *c33_rhs37 = NULL;
  const mxArray *c33_lhs37 = NULL;
  const mxArray *c33_rhs38 = NULL;
  const mxArray *c33_lhs38 = NULL;
  const mxArray *c33_rhs39 = NULL;
  const mxArray *c33_lhs39 = NULL;
  const mxArray *c33_rhs40 = NULL;
  const mxArray *c33_lhs40 = NULL;
  const mxArray *c33_rhs41 = NULL;
  const mxArray *c33_lhs41 = NULL;
  const mxArray *c33_rhs42 = NULL;
  const mxArray *c33_lhs42 = NULL;
  const mxArray *c33_rhs43 = NULL;
  const mxArray *c33_lhs43 = NULL;
  const mxArray *c33_rhs44 = NULL;
  const mxArray *c33_lhs44 = NULL;
  const mxArray *c33_rhs45 = NULL;
  const mxArray *c33_lhs45 = NULL;
  const mxArray *c33_rhs46 = NULL;
  const mxArray *c33_lhs46 = NULL;
  const mxArray *c33_rhs47 = NULL;
  const mxArray *c33_lhs47 = NULL;
  const mxArray *c33_rhs48 = NULL;
  const mxArray *c33_lhs48 = NULL;
  const mxArray *c33_rhs49 = NULL;
  const mxArray *c33_lhs49 = NULL;
  const mxArray *c33_rhs50 = NULL;
  const mxArray *c33_lhs50 = NULL;
  const mxArray *c33_rhs51 = NULL;
  const mxArray *c33_lhs51 = NULL;
  const mxArray *c33_rhs52 = NULL;
  const mxArray *c33_lhs52 = NULL;
  const mxArray *c33_rhs53 = NULL;
  const mxArray *c33_lhs53 = NULL;
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("cosd"), "name", "name", 0);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1395346498U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c33_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_scalar_cosd_and_sind"),
                  "name", "name", 1);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1343851978U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c33_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("isfinite"), "name", "name",
                  2);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c33_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c33_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("isinf"), "name", "name", 4);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c33_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c33_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("isnan"), "name", "name", 6);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c33_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 7);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c33_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 8);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1286840376U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c33_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 9);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1286840382U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c33_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_scalar_rem90"), "name",
                  "name", 10);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1343851978U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c33_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "context", "context", 11);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("mrdivide"), "name", "name",
                  11);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c33_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 12);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 12);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c33_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 13);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("rdivide"), "name", "name",
                  13);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c33_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 14);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c33_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 15);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c33_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_div"), "name", "name",
                  16);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c33_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 17);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c33_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "context", "context", 18);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("rem"), "name", "name", 18);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c33_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 19);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c33_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 20);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c33_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 21);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c33_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 22);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c33_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 23);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 23);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c33_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "context", "context", 24);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("abs"), "name", "name", 24);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c33_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 25);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c33_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 26);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c33_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "context", "context", 27);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("sind"), "name", "name", 27);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sind.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1395346504U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c33_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sind.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_scalar_cosd_and_sind"),
                  "name", "name", 28);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1343851978U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c33_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "context", "context", 29);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 29);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c33_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 30);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 30);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c33_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 31);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 31);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c33_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 32);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 32);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c33_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 33);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  33);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1376002290U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c33_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 34);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c33_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 35);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c33_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 36);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 36);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c33_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 37);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 37);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c33_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 38);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 38);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c33_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 39);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 39);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c33_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 40);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 40);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c33_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "context", "context", 41);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("length"), "name", "name", 41);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 41);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1303167806U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c33_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "context", "context", 42);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("cart2sph"), "name", "name",
                  42);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cart2sph.m"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1286840442U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c33_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cart2sph.m"), "context",
                  "context", 43);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("hypot"), "name", "name", 43);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/hypot.m"), "resolved",
                  "resolved", 43);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1395346500U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c33_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/hypot.m"), "context",
                  "context", 44);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 44);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 44);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c33_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/hypot.m"), "context",
                  "context", 45);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 45);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c33_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/hypot.m"), "context",
                  "context", 46);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_scalar_hypot"), "name",
                  "name", 46);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_hypot.m"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1286840326U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c33_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_hypot.m"),
                  "context", "context", 47);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 47);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 47);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c33_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_hypot.m"),
                  "context", "context", 48);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_dlapy2"), "name", "name",
                  48);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlapy2.m"), "resolved",
                  "resolved", 48);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1350432254U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c33_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cart2sph.m"), "context",
                  "context", 49);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("atan2"), "name", "name", 49);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "resolved",
                  "resolved", 49);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1395346496U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c33_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 50);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 50);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 50);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c33_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 51);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 51);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c33_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 52);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_scalar_atan2"), "name",
                  "name", 52);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m"),
                  "resolved", "resolved", 52);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1286840320U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c33_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "context", "context", 53);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("mrdivide"), "name", "name",
                  53);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 53);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c33_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs53), "lhs", "lhs",
                  53);
  sf_mex_destroy(&c33_rhs0);
  sf_mex_destroy(&c33_lhs0);
  sf_mex_destroy(&c33_rhs1);
  sf_mex_destroy(&c33_lhs1);
  sf_mex_destroy(&c33_rhs2);
  sf_mex_destroy(&c33_lhs2);
  sf_mex_destroy(&c33_rhs3);
  sf_mex_destroy(&c33_lhs3);
  sf_mex_destroy(&c33_rhs4);
  sf_mex_destroy(&c33_lhs4);
  sf_mex_destroy(&c33_rhs5);
  sf_mex_destroy(&c33_lhs5);
  sf_mex_destroy(&c33_rhs6);
  sf_mex_destroy(&c33_lhs6);
  sf_mex_destroy(&c33_rhs7);
  sf_mex_destroy(&c33_lhs7);
  sf_mex_destroy(&c33_rhs8);
  sf_mex_destroy(&c33_lhs8);
  sf_mex_destroy(&c33_rhs9);
  sf_mex_destroy(&c33_lhs9);
  sf_mex_destroy(&c33_rhs10);
  sf_mex_destroy(&c33_lhs10);
  sf_mex_destroy(&c33_rhs11);
  sf_mex_destroy(&c33_lhs11);
  sf_mex_destroy(&c33_rhs12);
  sf_mex_destroy(&c33_lhs12);
  sf_mex_destroy(&c33_rhs13);
  sf_mex_destroy(&c33_lhs13);
  sf_mex_destroy(&c33_rhs14);
  sf_mex_destroy(&c33_lhs14);
  sf_mex_destroy(&c33_rhs15);
  sf_mex_destroy(&c33_lhs15);
  sf_mex_destroy(&c33_rhs16);
  sf_mex_destroy(&c33_lhs16);
  sf_mex_destroy(&c33_rhs17);
  sf_mex_destroy(&c33_lhs17);
  sf_mex_destroy(&c33_rhs18);
  sf_mex_destroy(&c33_lhs18);
  sf_mex_destroy(&c33_rhs19);
  sf_mex_destroy(&c33_lhs19);
  sf_mex_destroy(&c33_rhs20);
  sf_mex_destroy(&c33_lhs20);
  sf_mex_destroy(&c33_rhs21);
  sf_mex_destroy(&c33_lhs21);
  sf_mex_destroy(&c33_rhs22);
  sf_mex_destroy(&c33_lhs22);
  sf_mex_destroy(&c33_rhs23);
  sf_mex_destroy(&c33_lhs23);
  sf_mex_destroy(&c33_rhs24);
  sf_mex_destroy(&c33_lhs24);
  sf_mex_destroy(&c33_rhs25);
  sf_mex_destroy(&c33_lhs25);
  sf_mex_destroy(&c33_rhs26);
  sf_mex_destroy(&c33_lhs26);
  sf_mex_destroy(&c33_rhs27);
  sf_mex_destroy(&c33_lhs27);
  sf_mex_destroy(&c33_rhs28);
  sf_mex_destroy(&c33_lhs28);
  sf_mex_destroy(&c33_rhs29);
  sf_mex_destroy(&c33_lhs29);
  sf_mex_destroy(&c33_rhs30);
  sf_mex_destroy(&c33_lhs30);
  sf_mex_destroy(&c33_rhs31);
  sf_mex_destroy(&c33_lhs31);
  sf_mex_destroy(&c33_rhs32);
  sf_mex_destroy(&c33_lhs32);
  sf_mex_destroy(&c33_rhs33);
  sf_mex_destroy(&c33_lhs33);
  sf_mex_destroy(&c33_rhs34);
  sf_mex_destroy(&c33_lhs34);
  sf_mex_destroy(&c33_rhs35);
  sf_mex_destroy(&c33_lhs35);
  sf_mex_destroy(&c33_rhs36);
  sf_mex_destroy(&c33_lhs36);
  sf_mex_destroy(&c33_rhs37);
  sf_mex_destroy(&c33_lhs37);
  sf_mex_destroy(&c33_rhs38);
  sf_mex_destroy(&c33_lhs38);
  sf_mex_destroy(&c33_rhs39);
  sf_mex_destroy(&c33_lhs39);
  sf_mex_destroy(&c33_rhs40);
  sf_mex_destroy(&c33_lhs40);
  sf_mex_destroy(&c33_rhs41);
  sf_mex_destroy(&c33_lhs41);
  sf_mex_destroy(&c33_rhs42);
  sf_mex_destroy(&c33_lhs42);
  sf_mex_destroy(&c33_rhs43);
  sf_mex_destroy(&c33_lhs43);
  sf_mex_destroy(&c33_rhs44);
  sf_mex_destroy(&c33_lhs44);
  sf_mex_destroy(&c33_rhs45);
  sf_mex_destroy(&c33_lhs45);
  sf_mex_destroy(&c33_rhs46);
  sf_mex_destroy(&c33_lhs46);
  sf_mex_destroy(&c33_rhs47);
  sf_mex_destroy(&c33_lhs47);
  sf_mex_destroy(&c33_rhs48);
  sf_mex_destroy(&c33_lhs48);
  sf_mex_destroy(&c33_rhs49);
  sf_mex_destroy(&c33_lhs49);
  sf_mex_destroy(&c33_rhs50);
  sf_mex_destroy(&c33_lhs50);
  sf_mex_destroy(&c33_rhs51);
  sf_mex_destroy(&c33_lhs51);
  sf_mex_destroy(&c33_rhs52);
  sf_mex_destroy(&c33_lhs52);
  sf_mex_destroy(&c33_rhs53);
  sf_mex_destroy(&c33_lhs53);
}

static const mxArray *c33_emlrt_marshallOut(const char * c33_u)
{
  const mxArray *c33_y = NULL;
  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_create("y", c33_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c33_u)), false);
  return c33_y;
}

static const mxArray *c33_b_emlrt_marshallOut(const uint32_T c33_u)
{
  const mxArray *c33_y = NULL;
  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_create("y", &c33_u, 7, 0U, 0U, 0U, 0), false);
  return c33_y;
}

static real_T c33_cosd(SFc33_Experiment_2_csInstanceStruct *chartInstance,
  real_T c33_x)
{
  real_T c33_b_x;
  c33_b_x = c33_x;
  c33_b_cosd(chartInstance, &c33_b_x);
  return c33_b_x;
}

static boolean_T c33_isfinite(SFc33_Experiment_2_csInstanceStruct *chartInstance,
  real_T c33_x)
{
  real_T c33_b_x;
  boolean_T c33_b_b;
  boolean_T c33_b0;
  real_T c33_c_x;
  boolean_T c33_c_b;
  boolean_T c33_b1;
  (void)chartInstance;
  c33_b_x = c33_x;
  c33_b_b = muDoubleScalarIsInf(c33_b_x);
  c33_b0 = !c33_b_b;
  c33_c_x = c33_x;
  c33_c_b = muDoubleScalarIsNaN(c33_c_x);
  c33_b1 = !c33_c_b;
  return c33_b0 && c33_b1;
}

static void c33_eml_scalar_eg(SFc33_Experiment_2_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c33_sind(SFc33_Experiment_2_csInstanceStruct *chartInstance,
  real_T c33_x)
{
  real_T c33_b_x;
  c33_b_x = c33_x;
  c33_b_sind(chartInstance, &c33_b_x);
  return c33_b_x;
}

static void c33_b_eml_scalar_eg(SFc33_Experiment_2_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c33_threshold(SFc33_Experiment_2_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c33_c_eml_scalar_eg(SFc33_Experiment_2_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static real_T c33_hypot(SFc33_Experiment_2_csInstanceStruct *chartInstance,
  real_T c33_x, real_T c33_y)
{
  real_T c33_b_x;
  real_T c33_b_y;
  real_T c33_x1;
  real_T c33_x2;
  real_T c33_a;
  real_T c33_b;
  c33_eml_scalar_eg(chartInstance);
  c33_b_x = c33_x;
  c33_b_y = c33_y;
  c33_eml_scalar_eg(chartInstance);
  c33_x1 = c33_b_x;
  c33_x2 = c33_b_y;
  c33_a = c33_x1;
  c33_b = c33_x2;
  return muDoubleScalarHypot(c33_a, c33_b);
}

static real_T c33_atan2(SFc33_Experiment_2_csInstanceStruct *chartInstance,
  real_T c33_y, real_T c33_x)
{
  real_T c33_b_y;
  real_T c33_b_x;
  c33_eml_scalar_eg(chartInstance);
  c33_b_y = c33_y;
  c33_b_x = c33_x;
  return muDoubleScalarAtan2(c33_b_y, c33_b_x);
}

static const mxArray *c33_e_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData)
{
  const mxArray *c33_mxArrayOutData = NULL;
  int32_T c33_u;
  const mxArray *c33_y = NULL;
  SFc33_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc33_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c33_mxArrayOutData = NULL;
  c33_u = *(int32_T *)c33_inData;
  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_create("y", &c33_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c33_mxArrayOutData, c33_y, false);
  return c33_mxArrayOutData;
}

static int32_T c33_f_emlrt_marshallIn(SFc33_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId)
{
  int32_T c33_y;
  int32_T c33_i67;
  (void)chartInstance;
  sf_mex_import(c33_parentId, sf_mex_dup(c33_u), &c33_i67, 1, 6, 0U, 0, 0U, 0);
  c33_y = c33_i67;
  sf_mex_destroy(&c33_u);
  return c33_y;
}

static void c33_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData)
{
  const mxArray *c33_b_sfEvent;
  const char_T *c33_identifier;
  emlrtMsgIdentifier c33_thisId;
  int32_T c33_y;
  SFc33_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc33_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c33_b_sfEvent = sf_mex_dup(c33_mxArrayInData);
  c33_identifier = c33_varName;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_y = c33_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_b_sfEvent),
    &c33_thisId);
  sf_mex_destroy(&c33_b_sfEvent);
  *(int32_T *)c33_outData = c33_y;
  sf_mex_destroy(&c33_mxArrayInData);
}

static uint8_T c33_g_emlrt_marshallIn(SFc33_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c33_b_is_active_c33_Experiment_2_cs, const
  char_T *c33_identifier)
{
  uint8_T c33_y;
  emlrtMsgIdentifier c33_thisId;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_y = c33_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c33_b_is_active_c33_Experiment_2_cs), &c33_thisId);
  sf_mex_destroy(&c33_b_is_active_c33_Experiment_2_cs);
  return c33_y;
}

static uint8_T c33_h_emlrt_marshallIn(SFc33_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId)
{
  uint8_T c33_y;
  uint8_T c33_u0;
  (void)chartInstance;
  sf_mex_import(c33_parentId, sf_mex_dup(c33_u), &c33_u0, 1, 3, 0U, 0, 0U, 0);
  c33_y = c33_u0;
  sf_mex_destroy(&c33_u);
  return c33_y;
}

static void c33_b_cosd(SFc33_Experiment_2_csInstanceStruct *chartInstance,
  real_T *c33_x)
{
  real_T c33_b_x;
  real_T c33_c_x;
  real_T c33_d_x;
  real_T c33_e_x;
  real_T c33_xk;
  real_T c33_f_x;
  real_T c33_g_x;
  real_T c33_absx;
  real_T c33_h_x;
  real_T c33_i_x;
  int8_T c33_n;
  int8_T c33_b_n;
  c33_b_x = *c33_x;
  if (!c33_isfinite(chartInstance, c33_b_x)) {
    *c33_x = rtNaN;
  } else {
    c33_c_x = c33_b_x;
    c33_d_x = c33_c_x;
    c33_e_x = c33_d_x;
    c33_eml_scalar_eg(chartInstance);
    c33_xk = c33_e_x;
    c33_d_x = muDoubleScalarRem(c33_xk, 360.0);
    c33_f_x = c33_d_x;
    c33_g_x = c33_f_x;
    c33_absx = muDoubleScalarAbs(c33_g_x);
    if (c33_absx > 180.0) {
      if (c33_d_x > 0.0) {
        c33_d_x -= 360.0;
      } else {
        c33_d_x += 360.0;
      }

      c33_h_x = c33_d_x;
      c33_i_x = c33_h_x;
      c33_absx = muDoubleScalarAbs(c33_i_x);
    }

    if (c33_absx <= 45.0) {
      c33_d_x *= 0.017453292519943295;
      c33_n = 0;
    } else if (c33_absx <= 135.0) {
      if (c33_d_x > 0.0) {
        c33_d_x = 0.017453292519943295 * (c33_d_x - 90.0);
        c33_n = 1;
      } else {
        c33_d_x = 0.017453292519943295 * (c33_d_x + 90.0);
        c33_n = -1;
      }
    } else if (c33_d_x > 0.0) {
      c33_d_x = 0.017453292519943295 * (c33_d_x - 180.0);
      c33_n = 2;
    } else {
      c33_d_x = 0.017453292519943295 * (c33_d_x + 180.0);
      c33_n = -2;
    }

    c33_b_n = c33_n;
    c33_b_x = c33_d_x;
    if ((real_T)c33_b_n == 0.0) {
      *c33_x = muDoubleScalarCos(c33_b_x);
    } else if ((real_T)c33_b_n == 1.0) {
      *c33_x = -muDoubleScalarSin(c33_b_x);
    } else if ((real_T)c33_b_n == -1.0) {
      *c33_x = muDoubleScalarSin(c33_b_x);
    } else {
      *c33_x = -muDoubleScalarCos(c33_b_x);
    }
  }
}

static void c33_b_sind(SFc33_Experiment_2_csInstanceStruct *chartInstance,
  real_T *c33_x)
{
  real_T c33_b_x;
  real_T c33_d5;
  real_T c33_c_x;
  real_T c33_d_x;
  real_T c33_e_x;
  real_T c33_xk;
  real_T c33_f_x;
  real_T c33_g_x;
  real_T c33_absx;
  real_T c33_h_x;
  real_T c33_i_x;
  int8_T c33_n;
  int8_T c33_b_n;
  c33_b_x = *c33_x;
  if (!c33_isfinite(chartInstance, c33_b_x)) {
    c33_d5 = rtNaN;
  } else {
    c33_c_x = c33_b_x;
    c33_d_x = c33_c_x;
    c33_e_x = c33_d_x;
    c33_eml_scalar_eg(chartInstance);
    c33_xk = c33_e_x;
    c33_d_x = muDoubleScalarRem(c33_xk, 360.0);
    c33_f_x = c33_d_x;
    c33_g_x = c33_f_x;
    c33_absx = muDoubleScalarAbs(c33_g_x);
    if (c33_absx > 180.0) {
      if (c33_d_x > 0.0) {
        c33_d_x -= 360.0;
      } else {
        c33_d_x += 360.0;
      }

      c33_h_x = c33_d_x;
      c33_i_x = c33_h_x;
      c33_absx = muDoubleScalarAbs(c33_i_x);
    }

    if (c33_absx <= 45.0) {
      c33_d_x *= 0.017453292519943295;
      c33_n = 0;
    } else if (c33_absx <= 135.0) {
      if (c33_d_x > 0.0) {
        c33_d_x = 0.017453292519943295 * (c33_d_x - 90.0);
        c33_n = 1;
      } else {
        c33_d_x = 0.017453292519943295 * (c33_d_x + 90.0);
        c33_n = -1;
      }
    } else if (c33_d_x > 0.0) {
      c33_d_x = 0.017453292519943295 * (c33_d_x - 180.0);
      c33_n = 2;
    } else {
      c33_d_x = 0.017453292519943295 * (c33_d_x + 180.0);
      c33_n = -2;
    }

    c33_b_n = c33_n;
    c33_b_x = c33_d_x;
    if ((real_T)c33_b_n == 0.0) {
      c33_d5 = muDoubleScalarSin(c33_b_x);
    } else if ((real_T)c33_b_n == 1.0) {
      c33_d5 = muDoubleScalarCos(c33_b_x);
    } else if ((real_T)c33_b_n == -1.0) {
      c33_d5 = -muDoubleScalarCos(c33_b_x);
    } else {
      c33_d5 = -muDoubleScalarSin(c33_b_x);
    }
  }

  *c33_x = c33_d5;
}

static void init_dsm_address_info(SFc33_Experiment_2_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc33_Experiment_2_csInstanceStruct
  *chartInstance)
{
  chartInstance->c33_carX = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c33_pedR = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c33_carY = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c33_carZ = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c33_carRotZ = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c33_pedX = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c33_pedY = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c33_pedZ = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c33_sensorCorrX = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c33_sensorCorrY = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c33_sensorCorrZ = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 9);
  chartInstance->c33_pedTheta = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c33_pedPhi = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
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

void sf_c33_Experiment_2_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(47750498U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(754455844U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1872893476U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3668953918U);
}

mxArray* sf_c33_Experiment_2_cs_get_post_codegen_info(void);
mxArray *sf_c33_Experiment_2_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("LancJwwJnYXFAAtpzTDKb");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,10,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c33_Experiment_2_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c33_Experiment_2_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c33_Experiment_2_cs_jit_fallback_info(void)
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

mxArray *sf_c33_Experiment_2_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c33_Experiment_2_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c33_Experiment_2_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[16],T\"pedPhi\",},{M[1],M[5],T\"pedR\",},{M[1],M[15],T\"pedTheta\",},{M[8],M[0],T\"is_active_c33_Experiment_2_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c33_Experiment_2_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc33_Experiment_2_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc33_Experiment_2_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_2_csMachineNumber_,
           33,
           1,
           1,
           0,
           13,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"carX");
          _SFD_SET_DATA_PROPS(1,2,0,1,"pedR");
          _SFD_SET_DATA_PROPS(2,1,1,0,"carY");
          _SFD_SET_DATA_PROPS(3,1,1,0,"carZ");
          _SFD_SET_DATA_PROPS(4,1,1,0,"carRotZ");
          _SFD_SET_DATA_PROPS(5,1,1,0,"pedX");
          _SFD_SET_DATA_PROPS(6,1,1,0,"pedY");
          _SFD_SET_DATA_PROPS(7,1,1,0,"pedZ");
          _SFD_SET_DATA_PROPS(8,1,1,0,"sensorCorrX");
          _SFD_SET_DATA_PROPS(9,1,1,0,"sensorCorrY");
          _SFD_SET_DATA_PROPS(10,1,1,0,"sensorCorrZ");
          _SFD_SET_DATA_PROPS(11,2,0,1,"pedTheta");
          _SFD_SET_DATA_PROPS(12,2,0,1,"pedPhi");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,778);
        _SFD_CV_INIT_EML_FOR(0,1,0,542,565,778);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c33_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c33_sf_marshallOut,(MexInFcnForType)
            c33_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c33_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c33_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c33_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c33_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c33_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c33_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c33_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c33_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c33_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c33_sf_marshallOut,(MexInFcnForType)
            c33_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c33_sf_marshallOut,(MexInFcnForType)
            c33_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c33_carX);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c33_pedR);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c33_carY);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c33_carZ);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c33_carRotZ);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c33_pedX);
        _SFD_SET_DATA_VALUE_PTR(6U, *chartInstance->c33_pedY);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c33_pedZ);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c33_sensorCorrX);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c33_sensorCorrY);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c33_sensorCorrZ);
        _SFD_SET_DATA_VALUE_PTR(11U, *chartInstance->c33_pedTheta);
        _SFD_SET_DATA_VALUE_PTR(12U, *chartInstance->c33_pedPhi);
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
  return "UZ1HrqFzU1CPyH07PwC2ZH";
}

static void sf_opaque_initialize_c33_Experiment_2_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc33_Experiment_2_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c33_Experiment_2_cs((SFc33_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
  initialize_c33_Experiment_2_cs((SFc33_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c33_Experiment_2_cs(void *chartInstanceVar)
{
  enable_c33_Experiment_2_cs((SFc33_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c33_Experiment_2_cs(void *chartInstanceVar)
{
  disable_c33_Experiment_2_cs((SFc33_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c33_Experiment_2_cs(void *chartInstanceVar)
{
  sf_gateway_c33_Experiment_2_cs((SFc33_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c33_Experiment_2_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c33_Experiment_2_cs((SFc33_Experiment_2_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c33_Experiment_2_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c33_Experiment_2_cs((SFc33_Experiment_2_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c33_Experiment_2_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc33_Experiment_2_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_2_cs_optimization_info();
    }

    finalize_c33_Experiment_2_cs((SFc33_Experiment_2_csInstanceStruct*)
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
  initSimStructsc33_Experiment_2_cs((SFc33_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c33_Experiment_2_cs(SimStruct *S)
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
    initialize_params_c33_Experiment_2_cs((SFc33_Experiment_2_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c33_Experiment_2_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Experiment_2_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      33);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,33,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,33,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,33);
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,33,10);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,33,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 10; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,33);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3612945746U));
  ssSetChecksum1(S,(993091475U));
  ssSetChecksum2(S,(913416480U));
  ssSetChecksum3(S,(1100800757U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c33_Experiment_2_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c33_Experiment_2_cs(SimStruct *S)
{
  SFc33_Experiment_2_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc33_Experiment_2_csInstanceStruct *)utMalloc(sizeof
    (SFc33_Experiment_2_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc33_Experiment_2_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c33_Experiment_2_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c33_Experiment_2_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c33_Experiment_2_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c33_Experiment_2_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c33_Experiment_2_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c33_Experiment_2_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c33_Experiment_2_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c33_Experiment_2_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c33_Experiment_2_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c33_Experiment_2_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c33_Experiment_2_cs;
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

void c33_Experiment_2_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c33_Experiment_2_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c33_Experiment_2_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c33_Experiment_2_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c33_Experiment_2_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
