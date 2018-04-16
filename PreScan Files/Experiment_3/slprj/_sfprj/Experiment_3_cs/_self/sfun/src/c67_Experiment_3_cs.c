/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_3_cs_sfun.h"
#include "c67_Experiment_3_cs.h"
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
static const char * c67_debug_family_names[24] = { "TcarMat", "TsensorMat",
  "RcarMat", "i", "xPed", "yPed", "zPed", "TpedMat", "ResultMat", "nargin",
  "nargout", "carX", "carY", "carZ", "carRotZ", "pedR", "pedTheta", "pedPhi",
  "sensorCorrX", "sensorCorrY", "sensorCorrZ", "pedResultX", "pedResultY",
  "pedResultZ" };

/* Function Declarations */
static void initialize_c67_Experiment_3_cs(SFc67_Experiment_3_csInstanceStruct
  *chartInstance);
static void initialize_params_c67_Experiment_3_cs
  (SFc67_Experiment_3_csInstanceStruct *chartInstance);
static void enable_c67_Experiment_3_cs(SFc67_Experiment_3_csInstanceStruct
  *chartInstance);
static void disable_c67_Experiment_3_cs(SFc67_Experiment_3_csInstanceStruct
  *chartInstance);
static void c67_update_debugger_state_c67_Experiment_3_cs
  (SFc67_Experiment_3_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c67_Experiment_3_cs
  (SFc67_Experiment_3_csInstanceStruct *chartInstance);
static void set_sim_state_c67_Experiment_3_cs
  (SFc67_Experiment_3_csInstanceStruct *chartInstance, const mxArray *c67_st);
static void finalize_c67_Experiment_3_cs(SFc67_Experiment_3_csInstanceStruct
  *chartInstance);
static void sf_gateway_c67_Experiment_3_cs(SFc67_Experiment_3_csInstanceStruct
  *chartInstance);
static void mdl_start_c67_Experiment_3_cs(SFc67_Experiment_3_csInstanceStruct
  *chartInstance);
static void c67_chartstep_c67_Experiment_3_cs
  (SFc67_Experiment_3_csInstanceStruct *chartInstance);
static void initSimStructsc67_Experiment_3_cs
  (SFc67_Experiment_3_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c67_machineNumber, uint32_T
  c67_chartNumber, uint32_T c67_instanceNumber);
static const mxArray *c67_sf_marshallOut(void *chartInstanceVoid, void
  *c67_inData);
static void c67_emlrt_marshallIn(SFc67_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c67_b_pedResultZ, const char_T *c67_identifier,
  real_T c67_y[5]);
static void c67_b_emlrt_marshallIn(SFc67_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c67_u, const emlrtMsgIdentifier *c67_parentId,
  real_T c67_y[5]);
static void c67_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c67_mxArrayInData, const char_T *c67_varName, void *c67_outData);
static const mxArray *c67_b_sf_marshallOut(void *chartInstanceVoid, void
  *c67_inData);
static real_T c67_c_emlrt_marshallIn(SFc67_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c67_u, const emlrtMsgIdentifier *c67_parentId);
static void c67_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c67_mxArrayInData, const char_T *c67_varName, void *c67_outData);
static const mxArray *c67_c_sf_marshallOut(void *chartInstanceVoid, void
  *c67_inData);
static void c67_d_emlrt_marshallIn(SFc67_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c67_u, const emlrtMsgIdentifier *c67_parentId,
  real_T c67_y[4]);
static void c67_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c67_mxArrayInData, const char_T *c67_varName, void *c67_outData);
static const mxArray *c67_d_sf_marshallOut(void *chartInstanceVoid, void
  *c67_inData);
static void c67_e_emlrt_marshallIn(SFc67_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c67_u, const emlrtMsgIdentifier *c67_parentId,
  real_T c67_y[16]);
static void c67_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c67_mxArrayInData, const char_T *c67_varName, void *c67_outData);
static void c67_info_helper(const mxArray **c67_info);
static const mxArray *c67_emlrt_marshallOut(const char * c67_u);
static const mxArray *c67_b_emlrt_marshallOut(const uint32_T c67_u);
static real_T c67_cosd(SFc67_Experiment_3_csInstanceStruct *chartInstance,
  real_T c67_x);
static boolean_T c67_isfinite(SFc67_Experiment_3_csInstanceStruct *chartInstance,
  real_T c67_x);
static real_T c67_sind(SFc67_Experiment_3_csInstanceStruct *chartInstance,
  real_T c67_x);
static void c67_sph2cart(SFc67_Experiment_3_csInstanceStruct *chartInstance,
  real_T c67_az, real_T c67_elev, real_T c67_r, real_T *c67_x, real_T *c67_y,
  real_T *c67_z);
static void c67_eml_scalar_eg(SFc67_Experiment_3_csInstanceStruct *chartInstance);
static void c67_threshold(SFc67_Experiment_3_csInstanceStruct *chartInstance);
static void c67_b_eml_scalar_eg(SFc67_Experiment_3_csInstanceStruct
  *chartInstance);
static const mxArray *c67_e_sf_marshallOut(void *chartInstanceVoid, void
  *c67_inData);
static int32_T c67_f_emlrt_marshallIn(SFc67_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c67_u, const emlrtMsgIdentifier *c67_parentId);
static void c67_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c67_mxArrayInData, const char_T *c67_varName, void *c67_outData);
static uint8_T c67_g_emlrt_marshallIn(SFc67_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c67_b_is_active_c67_Experiment_3_cs, const
  char_T *c67_identifier);
static uint8_T c67_h_emlrt_marshallIn(SFc67_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c67_u, const emlrtMsgIdentifier *c67_parentId);
static void c67_b_cosd(SFc67_Experiment_3_csInstanceStruct *chartInstance,
  real_T *c67_x);
static void c67_b_sind(SFc67_Experiment_3_csInstanceStruct *chartInstance,
  real_T *c67_x);
static void init_dsm_address_info(SFc67_Experiment_3_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc67_Experiment_3_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c67_Experiment_3_cs(SFc67_Experiment_3_csInstanceStruct
  *chartInstance)
{
  chartInstance->c67_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c67_is_active_c67_Experiment_3_cs = 0U;
}

static void initialize_params_c67_Experiment_3_cs
  (SFc67_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c67_Experiment_3_cs(SFc67_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c67_Experiment_3_cs(SFc67_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c67_update_debugger_state_c67_Experiment_3_cs
  (SFc67_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c67_Experiment_3_cs
  (SFc67_Experiment_3_csInstanceStruct *chartInstance)
{
  const mxArray *c67_st;
  const mxArray *c67_y = NULL;
  int32_T c67_i0;
  real_T c67_u[5];
  const mxArray *c67_b_y = NULL;
  int32_T c67_i1;
  real_T c67_b_u[5];
  const mxArray *c67_c_y = NULL;
  int32_T c67_i2;
  real_T c67_c_u[5];
  const mxArray *c67_d_y = NULL;
  uint8_T c67_hoistedGlobal;
  uint8_T c67_d_u;
  const mxArray *c67_e_y = NULL;
  c67_st = NULL;
  c67_st = NULL;
  c67_y = NULL;
  sf_mex_assign(&c67_y, sf_mex_createcellmatrix(4, 1), false);
  for (c67_i0 = 0; c67_i0 < 5; c67_i0++) {
    c67_u[c67_i0] = (*chartInstance->c67_pedResultX)[c67_i0];
  }

  c67_b_y = NULL;
  sf_mex_assign(&c67_b_y, sf_mex_create("y", c67_u, 0, 0U, 1U, 0U, 1, 5), false);
  sf_mex_setcell(c67_y, 0, c67_b_y);
  for (c67_i1 = 0; c67_i1 < 5; c67_i1++) {
    c67_b_u[c67_i1] = (*chartInstance->c67_pedResultY)[c67_i1];
  }

  c67_c_y = NULL;
  sf_mex_assign(&c67_c_y, sf_mex_create("y", c67_b_u, 0, 0U, 1U, 0U, 1, 5),
                false);
  sf_mex_setcell(c67_y, 1, c67_c_y);
  for (c67_i2 = 0; c67_i2 < 5; c67_i2++) {
    c67_c_u[c67_i2] = (*chartInstance->c67_pedResultZ)[c67_i2];
  }

  c67_d_y = NULL;
  sf_mex_assign(&c67_d_y, sf_mex_create("y", c67_c_u, 0, 0U, 1U, 0U, 1, 5),
                false);
  sf_mex_setcell(c67_y, 2, c67_d_y);
  c67_hoistedGlobal = chartInstance->c67_is_active_c67_Experiment_3_cs;
  c67_d_u = c67_hoistedGlobal;
  c67_e_y = NULL;
  sf_mex_assign(&c67_e_y, sf_mex_create("y", &c67_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c67_y, 3, c67_e_y);
  sf_mex_assign(&c67_st, c67_y, false);
  return c67_st;
}

static void set_sim_state_c67_Experiment_3_cs
  (SFc67_Experiment_3_csInstanceStruct *chartInstance, const mxArray *c67_st)
{
  const mxArray *c67_u;
  real_T c67_dv0[5];
  int32_T c67_i3;
  real_T c67_dv1[5];
  int32_T c67_i4;
  real_T c67_dv2[5];
  int32_T c67_i5;
  chartInstance->c67_doneDoubleBufferReInit = true;
  c67_u = sf_mex_dup(c67_st);
  c67_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c67_u, 0)),
                       "pedResultX", c67_dv0);
  for (c67_i3 = 0; c67_i3 < 5; c67_i3++) {
    (*chartInstance->c67_pedResultX)[c67_i3] = c67_dv0[c67_i3];
  }

  c67_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c67_u, 1)),
                       "pedResultY", c67_dv1);
  for (c67_i4 = 0; c67_i4 < 5; c67_i4++) {
    (*chartInstance->c67_pedResultY)[c67_i4] = c67_dv1[c67_i4];
  }

  c67_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c67_u, 2)),
                       "pedResultZ", c67_dv2);
  for (c67_i5 = 0; c67_i5 < 5; c67_i5++) {
    (*chartInstance->c67_pedResultZ)[c67_i5] = c67_dv2[c67_i5];
  }

  chartInstance->c67_is_active_c67_Experiment_3_cs = c67_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c67_u, 3)),
     "is_active_c67_Experiment_3_cs");
  sf_mex_destroy(&c67_u);
  c67_update_debugger_state_c67_Experiment_3_cs(chartInstance);
  sf_mex_destroy(&c67_st);
}

static void finalize_c67_Experiment_3_cs(SFc67_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c67_Experiment_3_cs(SFc67_Experiment_3_csInstanceStruct
  *chartInstance)
{
  int32_T c67_i6;
  int32_T c67_i7;
  int32_T c67_i8;
  int32_T c67_i9;
  int32_T c67_i10;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 41U, chartInstance->c67_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c67_carX, 0U);
  chartInstance->c67_sfEvent = CALL_EVENT;
  c67_chartstep_c67_Experiment_3_cs(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_3_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c67_i6 = 0; c67_i6 < 5; c67_i6++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c67_pedResultX)[c67_i6], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c67_carY, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c67_carZ, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c67_carRotZ, 4U);
  for (c67_i7 = 0; c67_i7 < 5; c67_i7++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c67_pedR)[c67_i7], 5U);
  }

  for (c67_i8 = 0; c67_i8 < 5; c67_i8++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c67_pedTheta)[c67_i8], 6U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c67_pedPhi, 7U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c67_sensorCorrX, 8U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c67_sensorCorrY, 9U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c67_sensorCorrZ, 10U);
  for (c67_i9 = 0; c67_i9 < 5; c67_i9++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c67_pedResultY)[c67_i9], 11U);
  }

  for (c67_i10 = 0; c67_i10 < 5; c67_i10++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c67_pedResultZ)[c67_i10], 12U);
  }
}

static void mdl_start_c67_Experiment_3_cs(SFc67_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c67_chartstep_c67_Experiment_3_cs
  (SFc67_Experiment_3_csInstanceStruct *chartInstance)
{
  real_T c67_hoistedGlobal;
  real_T c67_b_hoistedGlobal;
  real_T c67_c_hoistedGlobal;
  real_T c67_d_hoistedGlobal;
  real_T c67_e_hoistedGlobal;
  real_T c67_f_hoistedGlobal;
  real_T c67_g_hoistedGlobal;
  real_T c67_h_hoistedGlobal;
  real_T c67_b_carX;
  real_T c67_b_carY;
  real_T c67_b_carZ;
  real_T c67_b_carRotZ;
  int32_T c67_i11;
  real_T c67_b_pedR[5];
  int32_T c67_i12;
  real_T c67_b_pedTheta[5];
  real_T c67_b_pedPhi;
  real_T c67_b_sensorCorrX;
  real_T c67_b_sensorCorrY;
  real_T c67_b_sensorCorrZ;
  uint32_T c67_debug_family_var_map[24];
  real_T c67_TcarMat[16];
  real_T c67_TsensorMat[16];
  real_T c67_RcarMat[16];
  real_T c67_i;
  real_T c67_xPed;
  real_T c67_yPed;
  real_T c67_zPed;
  real_T c67_TpedMat[16];
  real_T c67_ResultMat[4];
  real_T c67_nargin = 10.0;
  real_T c67_nargout = 3.0;
  real_T c67_b_pedResultX[5];
  real_T c67_b_pedResultY[5];
  real_T c67_b_pedResultZ[5];
  int32_T c67_i13;
  int32_T c67_i14;
  static real_T c67_dv3[4] = { 0.0, 0.0, 0.0, 1.0 };

  int32_T c67_i15;
  int32_T c67_i16;
  real_T c67_d0;
  real_T c67_d1;
  real_T c67_d2;
  real_T c67_d3;
  int32_T c67_i17;
  int32_T c67_i18;
  static real_T c67_dv4[4] = { 0.0, 0.0, 1.0, 0.0 };

  int32_T c67_i19;
  int32_T c67_i20;
  int32_T c67_i21;
  int32_T c67_i22;
  int32_T c67_i23;
  int32_T c67_b_i;
  real_T c67_A;
  real_T c67_x;
  real_T c67_b_x;
  real_T c67_c_x;
  real_T c67_y;
  real_T c67_b_A;
  real_T c67_d_x;
  real_T c67_e_x;
  real_T c67_f_x;
  real_T c67_b_y;
  real_T c67_b_zPed;
  real_T c67_b_yPed;
  real_T c67_b_xPed;
  int32_T c67_i24;
  int32_T c67_i25;
  int32_T c67_i26;
  real_T c67_a[16];
  int32_T c67_i27;
  real_T c67_b[16];
  int32_T c67_i28;
  int32_T c67_i29;
  int32_T c67_i30;
  real_T c67_c_y[16];
  int32_T c67_i31;
  int32_T c67_i32;
  int32_T c67_i33;
  int32_T c67_i34;
  int32_T c67_i35;
  int32_T c67_i36;
  int32_T c67_i37;
  int32_T c67_i38;
  int32_T c67_i39;
  int32_T c67_i40;
  int32_T c67_i41;
  int32_T c67_i42;
  int32_T c67_i43;
  int32_T c67_i44;
  int32_T c67_i45;
  int32_T c67_i46;
  int32_T c67_i47;
  real_T c67_C[4];
  int32_T c67_i48;
  int32_T c67_i49;
  int32_T c67_i50;
  int32_T c67_i51;
  int32_T c67_i52;
  int32_T c67_i53;
  static real_T c67_b_b[4] = { 0.0, 0.0, 0.0, 1.0 };

  int32_T c67_i54;
  int32_T c67_i55;
  int32_T c67_i56;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 41U, chartInstance->c67_sfEvent);
  c67_hoistedGlobal = *chartInstance->c67_carX;
  c67_b_hoistedGlobal = *chartInstance->c67_carY;
  c67_c_hoistedGlobal = *chartInstance->c67_carZ;
  c67_d_hoistedGlobal = *chartInstance->c67_carRotZ;
  c67_e_hoistedGlobal = *chartInstance->c67_pedPhi;
  c67_f_hoistedGlobal = *chartInstance->c67_sensorCorrX;
  c67_g_hoistedGlobal = *chartInstance->c67_sensorCorrY;
  c67_h_hoistedGlobal = *chartInstance->c67_sensorCorrZ;
  c67_b_carX = c67_hoistedGlobal;
  c67_b_carY = c67_b_hoistedGlobal;
  c67_b_carZ = c67_c_hoistedGlobal;
  c67_b_carRotZ = c67_d_hoistedGlobal;
  for (c67_i11 = 0; c67_i11 < 5; c67_i11++) {
    c67_b_pedR[c67_i11] = (*chartInstance->c67_pedR)[c67_i11];
  }

  for (c67_i12 = 0; c67_i12 < 5; c67_i12++) {
    c67_b_pedTheta[c67_i12] = (*chartInstance->c67_pedTheta)[c67_i12];
  }

  c67_b_pedPhi = c67_e_hoistedGlobal;
  c67_b_sensorCorrX = c67_f_hoistedGlobal;
  c67_b_sensorCorrY = c67_g_hoistedGlobal;
  c67_b_sensorCorrZ = c67_h_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 24U, 24U, c67_debug_family_names,
    c67_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_TcarMat, 0U, c67_d_sf_marshallOut,
    c67_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_TsensorMat, 1U, c67_d_sf_marshallOut,
    c67_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_RcarMat, 2U, c67_d_sf_marshallOut,
    c67_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_i, 3U, c67_b_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_xPed, 4U, c67_b_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_yPed, 5U, c67_b_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_zPed, 6U, c67_b_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_TpedMat, 7U, c67_d_sf_marshallOut,
    c67_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_ResultMat, 8U, c67_c_sf_marshallOut,
    c67_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_nargin, 9U, c67_b_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_nargout, 10U, c67_b_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c67_b_carX, 11U, c67_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c67_b_carY, 12U, c67_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c67_b_carZ, 13U, c67_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c67_b_carRotZ, 14U, c67_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c67_b_pedR, 15U, c67_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c67_b_pedTheta, 16U, c67_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c67_b_pedPhi, 17U, c67_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c67_b_sensorCorrX, 18U, c67_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c67_b_sensorCorrY, 19U, c67_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c67_b_sensorCorrZ, 20U, c67_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_b_pedResultX, 21U, c67_sf_marshallOut,
    c67_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_b_pedResultY, 22U, c67_sf_marshallOut,
    c67_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_b_pedResultZ, 23U, c67_sf_marshallOut,
    c67_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 3);
  c67_TcarMat[0] = 1.0;
  c67_TcarMat[4] = 0.0;
  c67_TcarMat[8] = 0.0;
  c67_TcarMat[12] = c67_b_carX;
  c67_TcarMat[1] = 0.0;
  c67_TcarMat[5] = 1.0;
  c67_TcarMat[9] = 0.0;
  c67_TcarMat[13] = c67_b_carY;
  c67_TcarMat[2] = 0.0;
  c67_TcarMat[6] = 0.0;
  c67_TcarMat[10] = 1.0;
  c67_TcarMat[14] = c67_b_carZ;
  c67_i13 = 0;
  for (c67_i14 = 0; c67_i14 < 4; c67_i14++) {
    c67_TcarMat[c67_i13 + 3] = c67_dv3[c67_i14];
    c67_i13 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 4);
  c67_TsensorMat[0] = 1.0;
  c67_TsensorMat[4] = 0.0;
  c67_TsensorMat[8] = 0.0;
  c67_TsensorMat[12] = c67_b_sensorCorrX;
  c67_TsensorMat[1] = 0.0;
  c67_TsensorMat[5] = 1.0;
  c67_TsensorMat[9] = 0.0;
  c67_TsensorMat[13] = c67_b_sensorCorrY;
  c67_TsensorMat[2] = 0.0;
  c67_TsensorMat[6] = 0.0;
  c67_TsensorMat[10] = 1.0;
  c67_TsensorMat[14] = c67_b_sensorCorrZ;
  c67_i15 = 0;
  for (c67_i16 = 0; c67_i16 < 4; c67_i16++) {
    c67_TsensorMat[c67_i15 + 3] = c67_dv3[c67_i16];
    c67_i15 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 5);
  c67_d0 = c67_b_carRotZ;
  c67_b_cosd(chartInstance, &c67_d0);
  c67_d1 = c67_b_carRotZ;
  c67_b_sind(chartInstance, &c67_d1);
  c67_d2 = c67_b_carRotZ;
  c67_b_sind(chartInstance, &c67_d2);
  c67_d3 = c67_b_carRotZ;
  c67_b_cosd(chartInstance, &c67_d3);
  c67_RcarMat[0] = c67_d0;
  c67_RcarMat[4] = -c67_d1;
  c67_RcarMat[8] = 0.0;
  c67_RcarMat[12] = 0.0;
  c67_RcarMat[1] = c67_d2;
  c67_RcarMat[5] = c67_d3;
  c67_RcarMat[9] = 0.0;
  c67_RcarMat[13] = 0.0;
  c67_i17 = 0;
  for (c67_i18 = 0; c67_i18 < 4; c67_i18++) {
    c67_RcarMat[c67_i17 + 2] = c67_dv4[c67_i18];
    c67_i17 += 4;
  }

  c67_i19 = 0;
  for (c67_i20 = 0; c67_i20 < 4; c67_i20++) {
    c67_RcarMat[c67_i19 + 3] = c67_dv3[c67_i20];
    c67_i19 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 10);
  for (c67_i21 = 0; c67_i21 < 5; c67_i21++) {
    c67_b_pedResultX[c67_i21] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 11);
  for (c67_i22 = 0; c67_i22 < 5; c67_i22++) {
    c67_b_pedResultY[c67_i22] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 12);
  for (c67_i23 = 0; c67_i23 < 5; c67_i23++) {
    c67_b_pedResultZ[c67_i23] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 14);
  c67_i = 1.0;
  c67_b_i = 0;
  while (c67_b_i < 5) {
    c67_i = 1.0 + (real_T)c67_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 16);
    c67_A = -c67_b_pedTheta[_SFD_EML_ARRAY_BOUNDS_CHECK("pedTheta", (int32_T)
      _SFD_INTEGER_CHECK("i", c67_i), 1, 5, 1, 0) - 1] * 3.1415926535897931;
    c67_x = c67_A;
    c67_b_x = c67_x;
    c67_c_x = c67_b_x;
    c67_y = c67_c_x / 180.0;
    c67_b_A = c67_b_pedPhi * 3.1415926535897931;
    c67_d_x = c67_b_A;
    c67_e_x = c67_d_x;
    c67_f_x = c67_e_x;
    c67_b_y = c67_f_x / 180.0;
    c67_sph2cart(chartInstance, c67_y, c67_b_y,
                 c67_b_pedR[_SFD_EML_ARRAY_BOUNDS_CHECK("pedR", (int32_T)
      _SFD_INTEGER_CHECK("i", c67_i), 1, 5, 1, 0) - 1], &c67_b_xPed, &c67_b_yPed,
                 &c67_b_zPed);
    c67_xPed = c67_b_xPed;
    c67_yPed = c67_b_yPed;
    c67_zPed = c67_b_zPed;
    _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 18);
    c67_TpedMat[0] = 1.0;
    c67_TpedMat[4] = 0.0;
    c67_TpedMat[8] = 0.0;
    c67_TpedMat[12] = c67_xPed;
    c67_TpedMat[1] = 0.0;
    c67_TpedMat[5] = 1.0;
    c67_TpedMat[9] = 0.0;
    c67_TpedMat[13] = c67_yPed;
    c67_TpedMat[2] = 0.0;
    c67_TpedMat[6] = 0.0;
    c67_TpedMat[10] = 1.0;
    c67_TpedMat[14] = c67_zPed;
    c67_i24 = 0;
    for (c67_i25 = 0; c67_i25 < 4; c67_i25++) {
      c67_TpedMat[c67_i24 + 3] = c67_dv3[c67_i25];
      c67_i24 += 4;
    }

    _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 20);
    for (c67_i26 = 0; c67_i26 < 16; c67_i26++) {
      c67_a[c67_i26] = c67_TcarMat[c67_i26];
    }

    for (c67_i27 = 0; c67_i27 < 16; c67_i27++) {
      c67_b[c67_i27] = c67_RcarMat[c67_i27];
    }

    c67_eml_scalar_eg(chartInstance);
    c67_eml_scalar_eg(chartInstance);
    c67_threshold(chartInstance);
    for (c67_i28 = 0; c67_i28 < 4; c67_i28++) {
      c67_i29 = 0;
      for (c67_i30 = 0; c67_i30 < 4; c67_i30++) {
        c67_c_y[c67_i29 + c67_i28] = 0.0;
        c67_i31 = 0;
        for (c67_i32 = 0; c67_i32 < 4; c67_i32++) {
          c67_c_y[c67_i29 + c67_i28] += c67_a[c67_i31 + c67_i28] * c67_b[c67_i32
            + c67_i29];
          c67_i31 += 4;
        }

        c67_i29 += 4;
      }
    }

    for (c67_i33 = 0; c67_i33 < 16; c67_i33++) {
      c67_b[c67_i33] = c67_TsensorMat[c67_i33];
    }

    c67_eml_scalar_eg(chartInstance);
    c67_eml_scalar_eg(chartInstance);
    c67_threshold(chartInstance);
    for (c67_i34 = 0; c67_i34 < 4; c67_i34++) {
      c67_i35 = 0;
      for (c67_i36 = 0; c67_i36 < 4; c67_i36++) {
        c67_a[c67_i35 + c67_i34] = 0.0;
        c67_i37 = 0;
        for (c67_i38 = 0; c67_i38 < 4; c67_i38++) {
          c67_a[c67_i35 + c67_i34] += c67_c_y[c67_i37 + c67_i34] * c67_b[c67_i38
            + c67_i35];
          c67_i37 += 4;
        }

        c67_i35 += 4;
      }
    }

    for (c67_i39 = 0; c67_i39 < 16; c67_i39++) {
      c67_b[c67_i39] = c67_TpedMat[c67_i39];
    }

    c67_eml_scalar_eg(chartInstance);
    c67_eml_scalar_eg(chartInstance);
    c67_threshold(chartInstance);
    for (c67_i40 = 0; c67_i40 < 4; c67_i40++) {
      c67_i41 = 0;
      for (c67_i42 = 0; c67_i42 < 4; c67_i42++) {
        c67_c_y[c67_i41 + c67_i40] = 0.0;
        c67_i43 = 0;
        for (c67_i44 = 0; c67_i44 < 4; c67_i44++) {
          c67_c_y[c67_i41 + c67_i40] += c67_a[c67_i43 + c67_i40] * c67_b[c67_i44
            + c67_i41];
          c67_i43 += 4;
        }

        c67_i41 += 4;
      }
    }

    c67_b_eml_scalar_eg(chartInstance);
    c67_b_eml_scalar_eg(chartInstance);
    for (c67_i45 = 0; c67_i45 < 4; c67_i45++) {
      c67_ResultMat[c67_i45] = 0.0;
    }

    for (c67_i46 = 0; c67_i46 < 4; c67_i46++) {
      c67_ResultMat[c67_i46] = 0.0;
    }

    for (c67_i47 = 0; c67_i47 < 4; c67_i47++) {
      c67_C[c67_i47] = c67_ResultMat[c67_i47];
    }

    for (c67_i48 = 0; c67_i48 < 4; c67_i48++) {
      c67_ResultMat[c67_i48] = c67_C[c67_i48];
    }

    c67_threshold(chartInstance);
    for (c67_i49 = 0; c67_i49 < 4; c67_i49++) {
      c67_C[c67_i49] = c67_ResultMat[c67_i49];
    }

    for (c67_i50 = 0; c67_i50 < 4; c67_i50++) {
      c67_ResultMat[c67_i50] = c67_C[c67_i50];
    }

    for (c67_i51 = 0; c67_i51 < 4; c67_i51++) {
      c67_ResultMat[c67_i51] = 0.0;
      c67_i52 = 0;
      for (c67_i53 = 0; c67_i53 < 4; c67_i53++) {
        c67_ResultMat[c67_i51] += c67_c_y[c67_i52 + c67_i51] * c67_b_b[c67_i53];
        c67_i52 += 4;
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 22);
    c67_b_pedResultX[_SFD_EML_ARRAY_BOUNDS_CHECK("pedResultX", (int32_T)
      _SFD_INTEGER_CHECK("i", c67_i), 1, 5, 1, 0) - 1] = c67_ResultMat[0];
    _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 23);
    c67_b_pedResultY[_SFD_EML_ARRAY_BOUNDS_CHECK("pedResultY", (int32_T)
      _SFD_INTEGER_CHECK("i", c67_i), 1, 5, 1, 0) - 1] = c67_ResultMat[1];
    _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 24);
    c67_b_pedResultZ[_SFD_EML_ARRAY_BOUNDS_CHECK("pedResultZ", (int32_T)
      _SFD_INTEGER_CHECK("i", c67_i), 1, 5, 1, 0) - 1] = c67_ResultMat[2];
    c67_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, -24);
  _SFD_SYMBOL_SCOPE_POP();
  for (c67_i54 = 0; c67_i54 < 5; c67_i54++) {
    (*chartInstance->c67_pedResultX)[c67_i54] = c67_b_pedResultX[c67_i54];
  }

  for (c67_i55 = 0; c67_i55 < 5; c67_i55++) {
    (*chartInstance->c67_pedResultY)[c67_i55] = c67_b_pedResultY[c67_i55];
  }

  for (c67_i56 = 0; c67_i56 < 5; c67_i56++) {
    (*chartInstance->c67_pedResultZ)[c67_i56] = c67_b_pedResultZ[c67_i56];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 41U, chartInstance->c67_sfEvent);
}

static void initSimStructsc67_Experiment_3_cs
  (SFc67_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c67_machineNumber, uint32_T
  c67_chartNumber, uint32_T c67_instanceNumber)
{
  (void)c67_machineNumber;
  (void)c67_chartNumber;
  (void)c67_instanceNumber;
}

static const mxArray *c67_sf_marshallOut(void *chartInstanceVoid, void
  *c67_inData)
{
  const mxArray *c67_mxArrayOutData = NULL;
  int32_T c67_i57;
  real_T c67_b_inData[5];
  int32_T c67_i58;
  real_T c67_u[5];
  const mxArray *c67_y = NULL;
  SFc67_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc67_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c67_mxArrayOutData = NULL;
  for (c67_i57 = 0; c67_i57 < 5; c67_i57++) {
    c67_b_inData[c67_i57] = (*(real_T (*)[5])c67_inData)[c67_i57];
  }

  for (c67_i58 = 0; c67_i58 < 5; c67_i58++) {
    c67_u[c67_i58] = c67_b_inData[c67_i58];
  }

  c67_y = NULL;
  sf_mex_assign(&c67_y, sf_mex_create("y", c67_u, 0, 0U, 1U, 0U, 1, 5), false);
  sf_mex_assign(&c67_mxArrayOutData, c67_y, false);
  return c67_mxArrayOutData;
}

static void c67_emlrt_marshallIn(SFc67_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c67_b_pedResultZ, const char_T *c67_identifier,
  real_T c67_y[5])
{
  emlrtMsgIdentifier c67_thisId;
  c67_thisId.fIdentifier = c67_identifier;
  c67_thisId.fParent = NULL;
  c67_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c67_b_pedResultZ),
    &c67_thisId, c67_y);
  sf_mex_destroy(&c67_b_pedResultZ);
}

static void c67_b_emlrt_marshallIn(SFc67_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c67_u, const emlrtMsgIdentifier *c67_parentId,
  real_T c67_y[5])
{
  real_T c67_dv5[5];
  int32_T c67_i59;
  (void)chartInstance;
  sf_mex_import(c67_parentId, sf_mex_dup(c67_u), c67_dv5, 1, 0, 0U, 1, 0U, 1, 5);
  for (c67_i59 = 0; c67_i59 < 5; c67_i59++) {
    c67_y[c67_i59] = c67_dv5[c67_i59];
  }

  sf_mex_destroy(&c67_u);
}

static void c67_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c67_mxArrayInData, const char_T *c67_varName, void *c67_outData)
{
  const mxArray *c67_b_pedResultZ;
  const char_T *c67_identifier;
  emlrtMsgIdentifier c67_thisId;
  real_T c67_y[5];
  int32_T c67_i60;
  SFc67_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc67_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c67_b_pedResultZ = sf_mex_dup(c67_mxArrayInData);
  c67_identifier = c67_varName;
  c67_thisId.fIdentifier = c67_identifier;
  c67_thisId.fParent = NULL;
  c67_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c67_b_pedResultZ),
    &c67_thisId, c67_y);
  sf_mex_destroy(&c67_b_pedResultZ);
  for (c67_i60 = 0; c67_i60 < 5; c67_i60++) {
    (*(real_T (*)[5])c67_outData)[c67_i60] = c67_y[c67_i60];
  }

  sf_mex_destroy(&c67_mxArrayInData);
}

static const mxArray *c67_b_sf_marshallOut(void *chartInstanceVoid, void
  *c67_inData)
{
  const mxArray *c67_mxArrayOutData = NULL;
  real_T c67_u;
  const mxArray *c67_y = NULL;
  SFc67_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc67_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c67_mxArrayOutData = NULL;
  c67_u = *(real_T *)c67_inData;
  c67_y = NULL;
  sf_mex_assign(&c67_y, sf_mex_create("y", &c67_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c67_mxArrayOutData, c67_y, false);
  return c67_mxArrayOutData;
}

static real_T c67_c_emlrt_marshallIn(SFc67_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c67_u, const emlrtMsgIdentifier *c67_parentId)
{
  real_T c67_y;
  real_T c67_d4;
  (void)chartInstance;
  sf_mex_import(c67_parentId, sf_mex_dup(c67_u), &c67_d4, 1, 0, 0U, 0, 0U, 0);
  c67_y = c67_d4;
  sf_mex_destroy(&c67_u);
  return c67_y;
}

static void c67_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c67_mxArrayInData, const char_T *c67_varName, void *c67_outData)
{
  const mxArray *c67_nargout;
  const char_T *c67_identifier;
  emlrtMsgIdentifier c67_thisId;
  real_T c67_y;
  SFc67_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc67_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c67_nargout = sf_mex_dup(c67_mxArrayInData);
  c67_identifier = c67_varName;
  c67_thisId.fIdentifier = c67_identifier;
  c67_thisId.fParent = NULL;
  c67_y = c67_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c67_nargout),
    &c67_thisId);
  sf_mex_destroy(&c67_nargout);
  *(real_T *)c67_outData = c67_y;
  sf_mex_destroy(&c67_mxArrayInData);
}

static const mxArray *c67_c_sf_marshallOut(void *chartInstanceVoid, void
  *c67_inData)
{
  const mxArray *c67_mxArrayOutData = NULL;
  int32_T c67_i61;
  real_T c67_b_inData[4];
  int32_T c67_i62;
  real_T c67_u[4];
  const mxArray *c67_y = NULL;
  SFc67_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc67_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c67_mxArrayOutData = NULL;
  for (c67_i61 = 0; c67_i61 < 4; c67_i61++) {
    c67_b_inData[c67_i61] = (*(real_T (*)[4])c67_inData)[c67_i61];
  }

  for (c67_i62 = 0; c67_i62 < 4; c67_i62++) {
    c67_u[c67_i62] = c67_b_inData[c67_i62];
  }

  c67_y = NULL;
  sf_mex_assign(&c67_y, sf_mex_create("y", c67_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c67_mxArrayOutData, c67_y, false);
  return c67_mxArrayOutData;
}

static void c67_d_emlrt_marshallIn(SFc67_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c67_u, const emlrtMsgIdentifier *c67_parentId,
  real_T c67_y[4])
{
  real_T c67_dv6[4];
  int32_T c67_i63;
  (void)chartInstance;
  sf_mex_import(c67_parentId, sf_mex_dup(c67_u), c67_dv6, 1, 0, 0U, 1, 0U, 1, 4);
  for (c67_i63 = 0; c67_i63 < 4; c67_i63++) {
    c67_y[c67_i63] = c67_dv6[c67_i63];
  }

  sf_mex_destroy(&c67_u);
}

static void c67_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c67_mxArrayInData, const char_T *c67_varName, void *c67_outData)
{
  const mxArray *c67_ResultMat;
  const char_T *c67_identifier;
  emlrtMsgIdentifier c67_thisId;
  real_T c67_y[4];
  int32_T c67_i64;
  SFc67_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc67_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c67_ResultMat = sf_mex_dup(c67_mxArrayInData);
  c67_identifier = c67_varName;
  c67_thisId.fIdentifier = c67_identifier;
  c67_thisId.fParent = NULL;
  c67_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c67_ResultMat), &c67_thisId,
    c67_y);
  sf_mex_destroy(&c67_ResultMat);
  for (c67_i64 = 0; c67_i64 < 4; c67_i64++) {
    (*(real_T (*)[4])c67_outData)[c67_i64] = c67_y[c67_i64];
  }

  sf_mex_destroy(&c67_mxArrayInData);
}

static const mxArray *c67_d_sf_marshallOut(void *chartInstanceVoid, void
  *c67_inData)
{
  const mxArray *c67_mxArrayOutData = NULL;
  int32_T c67_i65;
  int32_T c67_i66;
  int32_T c67_i67;
  real_T c67_b_inData[16];
  int32_T c67_i68;
  int32_T c67_i69;
  int32_T c67_i70;
  real_T c67_u[16];
  const mxArray *c67_y = NULL;
  SFc67_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc67_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c67_mxArrayOutData = NULL;
  c67_i65 = 0;
  for (c67_i66 = 0; c67_i66 < 4; c67_i66++) {
    for (c67_i67 = 0; c67_i67 < 4; c67_i67++) {
      c67_b_inData[c67_i67 + c67_i65] = (*(real_T (*)[16])c67_inData)[c67_i67 +
        c67_i65];
    }

    c67_i65 += 4;
  }

  c67_i68 = 0;
  for (c67_i69 = 0; c67_i69 < 4; c67_i69++) {
    for (c67_i70 = 0; c67_i70 < 4; c67_i70++) {
      c67_u[c67_i70 + c67_i68] = c67_b_inData[c67_i70 + c67_i68];
    }

    c67_i68 += 4;
  }

  c67_y = NULL;
  sf_mex_assign(&c67_y, sf_mex_create("y", c67_u, 0, 0U, 1U, 0U, 2, 4, 4), false);
  sf_mex_assign(&c67_mxArrayOutData, c67_y, false);
  return c67_mxArrayOutData;
}

static void c67_e_emlrt_marshallIn(SFc67_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c67_u, const emlrtMsgIdentifier *c67_parentId,
  real_T c67_y[16])
{
  real_T c67_dv7[16];
  int32_T c67_i71;
  (void)chartInstance;
  sf_mex_import(c67_parentId, sf_mex_dup(c67_u), c67_dv7, 1, 0, 0U, 1, 0U, 2, 4,
                4);
  for (c67_i71 = 0; c67_i71 < 16; c67_i71++) {
    c67_y[c67_i71] = c67_dv7[c67_i71];
  }

  sf_mex_destroy(&c67_u);
}

static void c67_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c67_mxArrayInData, const char_T *c67_varName, void *c67_outData)
{
  const mxArray *c67_TpedMat;
  const char_T *c67_identifier;
  emlrtMsgIdentifier c67_thisId;
  real_T c67_y[16];
  int32_T c67_i72;
  int32_T c67_i73;
  int32_T c67_i74;
  SFc67_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc67_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c67_TpedMat = sf_mex_dup(c67_mxArrayInData);
  c67_identifier = c67_varName;
  c67_thisId.fIdentifier = c67_identifier;
  c67_thisId.fParent = NULL;
  c67_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c67_TpedMat), &c67_thisId,
    c67_y);
  sf_mex_destroy(&c67_TpedMat);
  c67_i72 = 0;
  for (c67_i73 = 0; c67_i73 < 4; c67_i73++) {
    for (c67_i74 = 0; c67_i74 < 4; c67_i74++) {
      (*(real_T (*)[16])c67_outData)[c67_i74 + c67_i72] = c67_y[c67_i74 +
        c67_i72];
    }

    c67_i72 += 4;
  }

  sf_mex_destroy(&c67_mxArrayInData);
}

const mxArray *sf_c67_Experiment_3_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c67_nameCaptureInfo = NULL;
  c67_nameCaptureInfo = NULL;
  sf_mex_assign(&c67_nameCaptureInfo, sf_mex_createstruct("structure", 2, 48, 1),
                false);
  c67_info_helper(&c67_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c67_nameCaptureInfo);
  return c67_nameCaptureInfo;
}

static void c67_info_helper(const mxArray **c67_info)
{
  const mxArray *c67_rhs0 = NULL;
  const mxArray *c67_lhs0 = NULL;
  const mxArray *c67_rhs1 = NULL;
  const mxArray *c67_lhs1 = NULL;
  const mxArray *c67_rhs2 = NULL;
  const mxArray *c67_lhs2 = NULL;
  const mxArray *c67_rhs3 = NULL;
  const mxArray *c67_lhs3 = NULL;
  const mxArray *c67_rhs4 = NULL;
  const mxArray *c67_lhs4 = NULL;
  const mxArray *c67_rhs5 = NULL;
  const mxArray *c67_lhs5 = NULL;
  const mxArray *c67_rhs6 = NULL;
  const mxArray *c67_lhs6 = NULL;
  const mxArray *c67_rhs7 = NULL;
  const mxArray *c67_lhs7 = NULL;
  const mxArray *c67_rhs8 = NULL;
  const mxArray *c67_lhs8 = NULL;
  const mxArray *c67_rhs9 = NULL;
  const mxArray *c67_lhs9 = NULL;
  const mxArray *c67_rhs10 = NULL;
  const mxArray *c67_lhs10 = NULL;
  const mxArray *c67_rhs11 = NULL;
  const mxArray *c67_lhs11 = NULL;
  const mxArray *c67_rhs12 = NULL;
  const mxArray *c67_lhs12 = NULL;
  const mxArray *c67_rhs13 = NULL;
  const mxArray *c67_lhs13 = NULL;
  const mxArray *c67_rhs14 = NULL;
  const mxArray *c67_lhs14 = NULL;
  const mxArray *c67_rhs15 = NULL;
  const mxArray *c67_lhs15 = NULL;
  const mxArray *c67_rhs16 = NULL;
  const mxArray *c67_lhs16 = NULL;
  const mxArray *c67_rhs17 = NULL;
  const mxArray *c67_lhs17 = NULL;
  const mxArray *c67_rhs18 = NULL;
  const mxArray *c67_lhs18 = NULL;
  const mxArray *c67_rhs19 = NULL;
  const mxArray *c67_lhs19 = NULL;
  const mxArray *c67_rhs20 = NULL;
  const mxArray *c67_lhs20 = NULL;
  const mxArray *c67_rhs21 = NULL;
  const mxArray *c67_lhs21 = NULL;
  const mxArray *c67_rhs22 = NULL;
  const mxArray *c67_lhs22 = NULL;
  const mxArray *c67_rhs23 = NULL;
  const mxArray *c67_lhs23 = NULL;
  const mxArray *c67_rhs24 = NULL;
  const mxArray *c67_lhs24 = NULL;
  const mxArray *c67_rhs25 = NULL;
  const mxArray *c67_lhs25 = NULL;
  const mxArray *c67_rhs26 = NULL;
  const mxArray *c67_lhs26 = NULL;
  const mxArray *c67_rhs27 = NULL;
  const mxArray *c67_lhs27 = NULL;
  const mxArray *c67_rhs28 = NULL;
  const mxArray *c67_lhs28 = NULL;
  const mxArray *c67_rhs29 = NULL;
  const mxArray *c67_lhs29 = NULL;
  const mxArray *c67_rhs30 = NULL;
  const mxArray *c67_lhs30 = NULL;
  const mxArray *c67_rhs31 = NULL;
  const mxArray *c67_lhs31 = NULL;
  const mxArray *c67_rhs32 = NULL;
  const mxArray *c67_lhs32 = NULL;
  const mxArray *c67_rhs33 = NULL;
  const mxArray *c67_lhs33 = NULL;
  const mxArray *c67_rhs34 = NULL;
  const mxArray *c67_lhs34 = NULL;
  const mxArray *c67_rhs35 = NULL;
  const mxArray *c67_lhs35 = NULL;
  const mxArray *c67_rhs36 = NULL;
  const mxArray *c67_lhs36 = NULL;
  const mxArray *c67_rhs37 = NULL;
  const mxArray *c67_lhs37 = NULL;
  const mxArray *c67_rhs38 = NULL;
  const mxArray *c67_lhs38 = NULL;
  const mxArray *c67_rhs39 = NULL;
  const mxArray *c67_lhs39 = NULL;
  const mxArray *c67_rhs40 = NULL;
  const mxArray *c67_lhs40 = NULL;
  const mxArray *c67_rhs41 = NULL;
  const mxArray *c67_lhs41 = NULL;
  const mxArray *c67_rhs42 = NULL;
  const mxArray *c67_lhs42 = NULL;
  const mxArray *c67_rhs43 = NULL;
  const mxArray *c67_lhs43 = NULL;
  const mxArray *c67_rhs44 = NULL;
  const mxArray *c67_lhs44 = NULL;
  const mxArray *c67_rhs45 = NULL;
  const mxArray *c67_lhs45 = NULL;
  const mxArray *c67_rhs46 = NULL;
  const mxArray *c67_lhs46 = NULL;
  const mxArray *c67_rhs47 = NULL;
  const mxArray *c67_lhs47 = NULL;
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("cosd"), "name", "name", 0);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1395346498U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c67_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_scalar_cosd_and_sind"),
                  "name", "name", 1);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1343851978U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c67_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("isfinite"), "name", "name",
                  2);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c67_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c67_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("isinf"), "name", "name", 4);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c67_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c67_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("isnan"), "name", "name", 6);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c67_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 7);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c67_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 8);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1286840376U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c67_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 9);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1286840382U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c67_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_scalar_rem90"), "name",
                  "name", 10);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1343851978U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c67_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "context", "context", 11);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("mrdivide"), "name", "name",
                  11);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c67_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 12);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 12);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c67_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 13);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("rdivide"), "name", "name",
                  13);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c67_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 14);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c67_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 15);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c67_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_div"), "name", "name",
                  16);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c67_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 17);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c67_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "context", "context", 18);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("rem"), "name", "name", 18);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c67_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 19);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c67_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 20);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c67_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 21);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c67_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 22);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c67_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 23);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 23);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c67_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "context", "context", 24);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("abs"), "name", "name", 24);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c67_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 25);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c67_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 26);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c67_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "context", "context", 27);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("sind"), "name", "name", 27);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sind.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1395346504U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c67_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sind.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_scalar_cosd_and_sind"),
                  "name", "name", 28);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1343851978U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c67_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "context", "context", 29);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("length"), "name", "name", 29);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1303167806U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c67_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "context", "context", 30);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("mrdivide"), "name", "name",
                  30);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c67_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "context", "context", 31);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("sph2cart"), "name", "name",
                  31);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/sph2cart.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1286840456U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c67_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/sph2cart.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("sin"), "name", "name", 32);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1395346504U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c67_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 33);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1286840336U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c67_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/sph2cart.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("cos"), "name", "name", 34);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1395346496U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c67_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 35);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1286840322U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c67_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "context", "context", 36);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 36);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c67_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 37);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 37);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c67_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 38);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 38);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c67_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 39);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 39);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 39);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c67_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 40);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  40);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1376002290U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c67_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 41);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 41);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c67_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 42);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 42);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c67_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 43);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 43);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c67_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 44);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 44);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c67_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 45);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 45);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c67_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 46);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 46);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c67_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 47);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 47);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c67_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs47), "lhs", "lhs",
                  47);
  sf_mex_destroy(&c67_rhs0);
  sf_mex_destroy(&c67_lhs0);
  sf_mex_destroy(&c67_rhs1);
  sf_mex_destroy(&c67_lhs1);
  sf_mex_destroy(&c67_rhs2);
  sf_mex_destroy(&c67_lhs2);
  sf_mex_destroy(&c67_rhs3);
  sf_mex_destroy(&c67_lhs3);
  sf_mex_destroy(&c67_rhs4);
  sf_mex_destroy(&c67_lhs4);
  sf_mex_destroy(&c67_rhs5);
  sf_mex_destroy(&c67_lhs5);
  sf_mex_destroy(&c67_rhs6);
  sf_mex_destroy(&c67_lhs6);
  sf_mex_destroy(&c67_rhs7);
  sf_mex_destroy(&c67_lhs7);
  sf_mex_destroy(&c67_rhs8);
  sf_mex_destroy(&c67_lhs8);
  sf_mex_destroy(&c67_rhs9);
  sf_mex_destroy(&c67_lhs9);
  sf_mex_destroy(&c67_rhs10);
  sf_mex_destroy(&c67_lhs10);
  sf_mex_destroy(&c67_rhs11);
  sf_mex_destroy(&c67_lhs11);
  sf_mex_destroy(&c67_rhs12);
  sf_mex_destroy(&c67_lhs12);
  sf_mex_destroy(&c67_rhs13);
  sf_mex_destroy(&c67_lhs13);
  sf_mex_destroy(&c67_rhs14);
  sf_mex_destroy(&c67_lhs14);
  sf_mex_destroy(&c67_rhs15);
  sf_mex_destroy(&c67_lhs15);
  sf_mex_destroy(&c67_rhs16);
  sf_mex_destroy(&c67_lhs16);
  sf_mex_destroy(&c67_rhs17);
  sf_mex_destroy(&c67_lhs17);
  sf_mex_destroy(&c67_rhs18);
  sf_mex_destroy(&c67_lhs18);
  sf_mex_destroy(&c67_rhs19);
  sf_mex_destroy(&c67_lhs19);
  sf_mex_destroy(&c67_rhs20);
  sf_mex_destroy(&c67_lhs20);
  sf_mex_destroy(&c67_rhs21);
  sf_mex_destroy(&c67_lhs21);
  sf_mex_destroy(&c67_rhs22);
  sf_mex_destroy(&c67_lhs22);
  sf_mex_destroy(&c67_rhs23);
  sf_mex_destroy(&c67_lhs23);
  sf_mex_destroy(&c67_rhs24);
  sf_mex_destroy(&c67_lhs24);
  sf_mex_destroy(&c67_rhs25);
  sf_mex_destroy(&c67_lhs25);
  sf_mex_destroy(&c67_rhs26);
  sf_mex_destroy(&c67_lhs26);
  sf_mex_destroy(&c67_rhs27);
  sf_mex_destroy(&c67_lhs27);
  sf_mex_destroy(&c67_rhs28);
  sf_mex_destroy(&c67_lhs28);
  sf_mex_destroy(&c67_rhs29);
  sf_mex_destroy(&c67_lhs29);
  sf_mex_destroy(&c67_rhs30);
  sf_mex_destroy(&c67_lhs30);
  sf_mex_destroy(&c67_rhs31);
  sf_mex_destroy(&c67_lhs31);
  sf_mex_destroy(&c67_rhs32);
  sf_mex_destroy(&c67_lhs32);
  sf_mex_destroy(&c67_rhs33);
  sf_mex_destroy(&c67_lhs33);
  sf_mex_destroy(&c67_rhs34);
  sf_mex_destroy(&c67_lhs34);
  sf_mex_destroy(&c67_rhs35);
  sf_mex_destroy(&c67_lhs35);
  sf_mex_destroy(&c67_rhs36);
  sf_mex_destroy(&c67_lhs36);
  sf_mex_destroy(&c67_rhs37);
  sf_mex_destroy(&c67_lhs37);
  sf_mex_destroy(&c67_rhs38);
  sf_mex_destroy(&c67_lhs38);
  sf_mex_destroy(&c67_rhs39);
  sf_mex_destroy(&c67_lhs39);
  sf_mex_destroy(&c67_rhs40);
  sf_mex_destroy(&c67_lhs40);
  sf_mex_destroy(&c67_rhs41);
  sf_mex_destroy(&c67_lhs41);
  sf_mex_destroy(&c67_rhs42);
  sf_mex_destroy(&c67_lhs42);
  sf_mex_destroy(&c67_rhs43);
  sf_mex_destroy(&c67_lhs43);
  sf_mex_destroy(&c67_rhs44);
  sf_mex_destroy(&c67_lhs44);
  sf_mex_destroy(&c67_rhs45);
  sf_mex_destroy(&c67_lhs45);
  sf_mex_destroy(&c67_rhs46);
  sf_mex_destroy(&c67_lhs46);
  sf_mex_destroy(&c67_rhs47);
  sf_mex_destroy(&c67_lhs47);
}

static const mxArray *c67_emlrt_marshallOut(const char * c67_u)
{
  const mxArray *c67_y = NULL;
  c67_y = NULL;
  sf_mex_assign(&c67_y, sf_mex_create("y", c67_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c67_u)), false);
  return c67_y;
}

static const mxArray *c67_b_emlrt_marshallOut(const uint32_T c67_u)
{
  const mxArray *c67_y = NULL;
  c67_y = NULL;
  sf_mex_assign(&c67_y, sf_mex_create("y", &c67_u, 7, 0U, 0U, 0U, 0), false);
  return c67_y;
}

static real_T c67_cosd(SFc67_Experiment_3_csInstanceStruct *chartInstance,
  real_T c67_x)
{
  real_T c67_b_x;
  c67_b_x = c67_x;
  c67_b_cosd(chartInstance, &c67_b_x);
  return c67_b_x;
}

static boolean_T c67_isfinite(SFc67_Experiment_3_csInstanceStruct *chartInstance,
  real_T c67_x)
{
  real_T c67_b_x;
  boolean_T c67_b_b;
  boolean_T c67_b0;
  real_T c67_c_x;
  boolean_T c67_c_b;
  boolean_T c67_b1;
  (void)chartInstance;
  c67_b_x = c67_x;
  c67_b_b = muDoubleScalarIsInf(c67_b_x);
  c67_b0 = !c67_b_b;
  c67_c_x = c67_x;
  c67_c_b = muDoubleScalarIsNaN(c67_c_x);
  c67_b1 = !c67_c_b;
  return c67_b0 && c67_b1;
}

static real_T c67_sind(SFc67_Experiment_3_csInstanceStruct *chartInstance,
  real_T c67_x)
{
  real_T c67_b_x;
  c67_b_x = c67_x;
  c67_b_sind(chartInstance, &c67_b_x);
  return c67_b_x;
}

static void c67_sph2cart(SFc67_Experiment_3_csInstanceStruct *chartInstance,
  real_T c67_az, real_T c67_elev, real_T c67_r, real_T *c67_x, real_T *c67_y,
  real_T *c67_z)
{
  real_T c67_b_x;
  real_T c67_c_x;
  real_T c67_d_x;
  real_T c67_e_x;
  real_T c67_rcoselev;
  real_T c67_f_x;
  real_T c67_g_x;
  real_T c67_h_x;
  real_T c67_i_x;
  (void)chartInstance;
  c67_b_x = c67_elev;
  c67_c_x = c67_b_x;
  c67_c_x = muDoubleScalarSin(c67_c_x);
  *c67_z = c67_r * c67_c_x;
  c67_d_x = c67_elev;
  c67_e_x = c67_d_x;
  c67_e_x = muDoubleScalarCos(c67_e_x);
  c67_rcoselev = c67_r * c67_e_x;
  c67_f_x = c67_az;
  c67_g_x = c67_f_x;
  c67_g_x = muDoubleScalarCos(c67_g_x);
  *c67_x = c67_rcoselev * c67_g_x;
  c67_h_x = c67_az;
  c67_i_x = c67_h_x;
  c67_i_x = muDoubleScalarSin(c67_i_x);
  *c67_y = c67_rcoselev * c67_i_x;
}

static void c67_eml_scalar_eg(SFc67_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c67_threshold(SFc67_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c67_b_eml_scalar_eg(SFc67_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c67_e_sf_marshallOut(void *chartInstanceVoid, void
  *c67_inData)
{
  const mxArray *c67_mxArrayOutData = NULL;
  int32_T c67_u;
  const mxArray *c67_y = NULL;
  SFc67_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc67_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c67_mxArrayOutData = NULL;
  c67_u = *(int32_T *)c67_inData;
  c67_y = NULL;
  sf_mex_assign(&c67_y, sf_mex_create("y", &c67_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c67_mxArrayOutData, c67_y, false);
  return c67_mxArrayOutData;
}

static int32_T c67_f_emlrt_marshallIn(SFc67_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c67_u, const emlrtMsgIdentifier *c67_parentId)
{
  int32_T c67_y;
  int32_T c67_i75;
  (void)chartInstance;
  sf_mex_import(c67_parentId, sf_mex_dup(c67_u), &c67_i75, 1, 6, 0U, 0, 0U, 0);
  c67_y = c67_i75;
  sf_mex_destroy(&c67_u);
  return c67_y;
}

static void c67_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c67_mxArrayInData, const char_T *c67_varName, void *c67_outData)
{
  const mxArray *c67_b_sfEvent;
  const char_T *c67_identifier;
  emlrtMsgIdentifier c67_thisId;
  int32_T c67_y;
  SFc67_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc67_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c67_b_sfEvent = sf_mex_dup(c67_mxArrayInData);
  c67_identifier = c67_varName;
  c67_thisId.fIdentifier = c67_identifier;
  c67_thisId.fParent = NULL;
  c67_y = c67_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c67_b_sfEvent),
    &c67_thisId);
  sf_mex_destroy(&c67_b_sfEvent);
  *(int32_T *)c67_outData = c67_y;
  sf_mex_destroy(&c67_mxArrayInData);
}

static uint8_T c67_g_emlrt_marshallIn(SFc67_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c67_b_is_active_c67_Experiment_3_cs, const
  char_T *c67_identifier)
{
  uint8_T c67_y;
  emlrtMsgIdentifier c67_thisId;
  c67_thisId.fIdentifier = c67_identifier;
  c67_thisId.fParent = NULL;
  c67_y = c67_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c67_b_is_active_c67_Experiment_3_cs), &c67_thisId);
  sf_mex_destroy(&c67_b_is_active_c67_Experiment_3_cs);
  return c67_y;
}

static uint8_T c67_h_emlrt_marshallIn(SFc67_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c67_u, const emlrtMsgIdentifier *c67_parentId)
{
  uint8_T c67_y;
  uint8_T c67_u0;
  (void)chartInstance;
  sf_mex_import(c67_parentId, sf_mex_dup(c67_u), &c67_u0, 1, 3, 0U, 0, 0U, 0);
  c67_y = c67_u0;
  sf_mex_destroy(&c67_u);
  return c67_y;
}

static void c67_b_cosd(SFc67_Experiment_3_csInstanceStruct *chartInstance,
  real_T *c67_x)
{
  real_T c67_b_x;
  real_T c67_c_x;
  real_T c67_d_x;
  real_T c67_e_x;
  real_T c67_xk;
  real_T c67_f_x;
  real_T c67_g_x;
  real_T c67_absx;
  real_T c67_h_x;
  real_T c67_i_x;
  int8_T c67_n;
  int8_T c67_b_n;
  c67_b_x = *c67_x;
  if (!c67_isfinite(chartInstance, c67_b_x)) {
    *c67_x = rtNaN;
  } else {
    c67_c_x = c67_b_x;
    c67_d_x = c67_c_x;
    c67_e_x = c67_d_x;
    c67_xk = c67_e_x;
    c67_d_x = muDoubleScalarRem(c67_xk, 360.0);
    c67_f_x = c67_d_x;
    c67_g_x = c67_f_x;
    c67_absx = muDoubleScalarAbs(c67_g_x);
    if (c67_absx > 180.0) {
      if (c67_d_x > 0.0) {
        c67_d_x -= 360.0;
      } else {
        c67_d_x += 360.0;
      }

      c67_h_x = c67_d_x;
      c67_i_x = c67_h_x;
      c67_absx = muDoubleScalarAbs(c67_i_x);
    }

    if (c67_absx <= 45.0) {
      c67_d_x *= 0.017453292519943295;
      c67_n = 0;
    } else if (c67_absx <= 135.0) {
      if (c67_d_x > 0.0) {
        c67_d_x = 0.017453292519943295 * (c67_d_x - 90.0);
        c67_n = 1;
      } else {
        c67_d_x = 0.017453292519943295 * (c67_d_x + 90.0);
        c67_n = -1;
      }
    } else if (c67_d_x > 0.0) {
      c67_d_x = 0.017453292519943295 * (c67_d_x - 180.0);
      c67_n = 2;
    } else {
      c67_d_x = 0.017453292519943295 * (c67_d_x + 180.0);
      c67_n = -2;
    }

    c67_b_n = c67_n;
    c67_b_x = c67_d_x;
    if ((real_T)c67_b_n == 0.0) {
      *c67_x = muDoubleScalarCos(c67_b_x);
    } else if ((real_T)c67_b_n == 1.0) {
      *c67_x = -muDoubleScalarSin(c67_b_x);
    } else if ((real_T)c67_b_n == -1.0) {
      *c67_x = muDoubleScalarSin(c67_b_x);
    } else {
      *c67_x = -muDoubleScalarCos(c67_b_x);
    }
  }
}

static void c67_b_sind(SFc67_Experiment_3_csInstanceStruct *chartInstance,
  real_T *c67_x)
{
  real_T c67_b_x;
  real_T c67_d5;
  real_T c67_c_x;
  real_T c67_d_x;
  real_T c67_e_x;
  real_T c67_xk;
  real_T c67_f_x;
  real_T c67_g_x;
  real_T c67_absx;
  real_T c67_h_x;
  real_T c67_i_x;
  int8_T c67_n;
  int8_T c67_b_n;
  c67_b_x = *c67_x;
  if (!c67_isfinite(chartInstance, c67_b_x)) {
    c67_d5 = rtNaN;
  } else {
    c67_c_x = c67_b_x;
    c67_d_x = c67_c_x;
    c67_e_x = c67_d_x;
    c67_xk = c67_e_x;
    c67_d_x = muDoubleScalarRem(c67_xk, 360.0);
    c67_f_x = c67_d_x;
    c67_g_x = c67_f_x;
    c67_absx = muDoubleScalarAbs(c67_g_x);
    if (c67_absx > 180.0) {
      if (c67_d_x > 0.0) {
        c67_d_x -= 360.0;
      } else {
        c67_d_x += 360.0;
      }

      c67_h_x = c67_d_x;
      c67_i_x = c67_h_x;
      c67_absx = muDoubleScalarAbs(c67_i_x);
    }

    if (c67_absx <= 45.0) {
      c67_d_x *= 0.017453292519943295;
      c67_n = 0;
    } else if (c67_absx <= 135.0) {
      if (c67_d_x > 0.0) {
        c67_d_x = 0.017453292519943295 * (c67_d_x - 90.0);
        c67_n = 1;
      } else {
        c67_d_x = 0.017453292519943295 * (c67_d_x + 90.0);
        c67_n = -1;
      }
    } else if (c67_d_x > 0.0) {
      c67_d_x = 0.017453292519943295 * (c67_d_x - 180.0);
      c67_n = 2;
    } else {
      c67_d_x = 0.017453292519943295 * (c67_d_x + 180.0);
      c67_n = -2;
    }

    c67_b_n = c67_n;
    c67_b_x = c67_d_x;
    if ((real_T)c67_b_n == 0.0) {
      c67_d5 = muDoubleScalarSin(c67_b_x);
    } else if ((real_T)c67_b_n == 1.0) {
      c67_d5 = muDoubleScalarCos(c67_b_x);
    } else if ((real_T)c67_b_n == -1.0) {
      c67_d5 = -muDoubleScalarCos(c67_b_x);
    } else {
      c67_d5 = -muDoubleScalarSin(c67_b_x);
    }
  }

  *c67_x = c67_d5;
}

static void init_dsm_address_info(SFc67_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc67_Experiment_3_csInstanceStruct
  *chartInstance)
{
  chartInstance->c67_carX = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c67_pedResultX = (real_T (*)[5])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c67_carY = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c67_carZ = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c67_carRotZ = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c67_pedR = (real_T (*)[5])ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c67_pedTheta = (real_T (*)[5])ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c67_pedPhi = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c67_sensorCorrX = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c67_sensorCorrY = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c67_sensorCorrZ = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 9);
  chartInstance->c67_pedResultY = (real_T (*)[5])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c67_pedResultZ = (real_T (*)[5])ssGetOutputPortSignal_wrapper
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

void sf_c67_Experiment_3_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(433210368U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3081099664U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1761976436U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3624208822U);
}

mxArray* sf_c67_Experiment_3_cs_get_post_codegen_info(void);
mxArray *sf_c67_Experiment_3_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("BVCdI9xOQ3G0AK8u8H9I3B");
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c67_Experiment_3_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c67_Experiment_3_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c67_Experiment_3_cs_jit_fallback_info(void)
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

mxArray *sf_c67_Experiment_3_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c67_Experiment_3_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c67_Experiment_3_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[5],T\"pedResultX\",},{M[1],M[15],T\"pedResultY\",},{M[1],M[16],T\"pedResultZ\",},{M[8],M[0],T\"is_active_c67_Experiment_3_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c67_Experiment_3_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc67_Experiment_3_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc67_Experiment_3_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_3_csMachineNumber_,
           67,
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
          _SFD_SET_DATA_PROPS(1,2,0,1,"pedResultX");
          _SFD_SET_DATA_PROPS(2,1,1,0,"carY");
          _SFD_SET_DATA_PROPS(3,1,1,0,"carZ");
          _SFD_SET_DATA_PROPS(4,1,1,0,"carRotZ");
          _SFD_SET_DATA_PROPS(5,1,1,0,"pedR");
          _SFD_SET_DATA_PROPS(6,1,1,0,"pedTheta");
          _SFD_SET_DATA_PROPS(7,1,1,0,"pedPhi");
          _SFD_SET_DATA_PROPS(8,1,1,0,"sensorCorrX");
          _SFD_SET_DATA_PROPS(9,1,1,0,"sensorCorrY");
          _SFD_SET_DATA_PROPS(10,1,1,0,"sensorCorrZ");
          _SFD_SET_DATA_PROPS(11,2,0,1,"pedResultY");
          _SFD_SET_DATA_PROPS(12,2,0,1,"pedResultZ");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,873);
        _SFD_CV_INIT_EML_FOR(0,1,0,530,553,873);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c67_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c67_sf_marshallOut,(MexInFcnForType)
            c67_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c67_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c67_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c67_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c67_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c67_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c67_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c67_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c67_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c67_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c67_sf_marshallOut,(MexInFcnForType)
            c67_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c67_sf_marshallOut,(MexInFcnForType)
            c67_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c67_carX);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c67_pedResultX);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c67_carY);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c67_carZ);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c67_carRotZ);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c67_pedR);
        _SFD_SET_DATA_VALUE_PTR(6U, *chartInstance->c67_pedTheta);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c67_pedPhi);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c67_sensorCorrX);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c67_sensorCorrY);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c67_sensorCorrZ);
        _SFD_SET_DATA_VALUE_PTR(11U, *chartInstance->c67_pedResultY);
        _SFD_SET_DATA_VALUE_PTR(12U, *chartInstance->c67_pedResultZ);
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
  return "MsLeTxb3lMHMJyYx7lFWgG";
}

static void sf_opaque_initialize_c67_Experiment_3_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc67_Experiment_3_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c67_Experiment_3_cs((SFc67_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
  initialize_c67_Experiment_3_cs((SFc67_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c67_Experiment_3_cs(void *chartInstanceVar)
{
  enable_c67_Experiment_3_cs((SFc67_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c67_Experiment_3_cs(void *chartInstanceVar)
{
  disable_c67_Experiment_3_cs((SFc67_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c67_Experiment_3_cs(void *chartInstanceVar)
{
  sf_gateway_c67_Experiment_3_cs((SFc67_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c67_Experiment_3_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c67_Experiment_3_cs((SFc67_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c67_Experiment_3_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c67_Experiment_3_cs((SFc67_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c67_Experiment_3_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc67_Experiment_3_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_3_cs_optimization_info();
    }

    finalize_c67_Experiment_3_cs((SFc67_Experiment_3_csInstanceStruct*)
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
  initSimStructsc67_Experiment_3_cs((SFc67_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c67_Experiment_3_cs(SimStruct *S)
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
    initialize_params_c67_Experiment_3_cs((SFc67_Experiment_3_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c67_Experiment_3_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Experiment_3_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      67);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,67,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,67,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,67);
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
        infoStruct,67,10);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,67,3);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,67);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1978628514U));
  ssSetChecksum1(S,(2349904317U));
  ssSetChecksum2(S,(148829049U));
  ssSetChecksum3(S,(3837661946U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c67_Experiment_3_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c67_Experiment_3_cs(SimStruct *S)
{
  SFc67_Experiment_3_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc67_Experiment_3_csInstanceStruct *)utMalloc(sizeof
    (SFc67_Experiment_3_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc67_Experiment_3_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c67_Experiment_3_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c67_Experiment_3_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c67_Experiment_3_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c67_Experiment_3_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c67_Experiment_3_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c67_Experiment_3_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c67_Experiment_3_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c67_Experiment_3_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c67_Experiment_3_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c67_Experiment_3_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c67_Experiment_3_cs;
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

void c67_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c67_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c67_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c67_Experiment_3_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c67_Experiment_3_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
