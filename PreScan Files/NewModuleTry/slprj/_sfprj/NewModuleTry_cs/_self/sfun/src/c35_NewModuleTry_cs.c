/* Include files */

#include <stddef.h>
#include "blas.h"
#include "NewModuleTry_cs_sfun.h"
#include "c35_NewModuleTry_cs.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "NewModuleTry_cs_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c35_debug_family_names[13] = { "rotMat", "carVelX",
  "carVelY", "carVelMat", "Vdv", "nargin", "nargout", "carAngle", "carVelocity",
  "dopplerTX", "dopplerTY", "dTranslationX", "dTranslationY" };

/* Function Declarations */
static void initialize_c35_NewModuleTry_cs(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance);
static void initialize_params_c35_NewModuleTry_cs
  (SFc35_NewModuleTry_csInstanceStruct *chartInstance);
static void enable_c35_NewModuleTry_cs(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance);
static void disable_c35_NewModuleTry_cs(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance);
static void c35_update_debugger_state_c35_NewModuleTry_cs
  (SFc35_NewModuleTry_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c35_NewModuleTry_cs
  (SFc35_NewModuleTry_csInstanceStruct *chartInstance);
static void set_sim_state_c35_NewModuleTry_cs
  (SFc35_NewModuleTry_csInstanceStruct *chartInstance, const mxArray *c35_st);
static void finalize_c35_NewModuleTry_cs(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance);
static void sf_gateway_c35_NewModuleTry_cs(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance);
static void mdl_start_c35_NewModuleTry_cs(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance);
static void initSimStructsc35_NewModuleTry_cs
  (SFc35_NewModuleTry_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c35_machineNumber, uint32_T
  c35_chartNumber, uint32_T c35_instanceNumber);
static const mxArray *c35_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static real_T c35_emlrt_marshallIn(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c35_b_dTranslationY, const char_T
  *c35_identifier);
static real_T c35_b_emlrt_marshallIn(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId);
static void c35_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static const mxArray *c35_b_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static void c35_c_emlrt_marshallIn(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId,
  real_T c35_y[2]);
static void c35_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static const mxArray *c35_c_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static void c35_d_emlrt_marshallIn(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId,
  real_T c35_y[4]);
static void c35_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static void c35_info_helper(const mxArray **c35_info);
static const mxArray *c35_emlrt_marshallOut(const char * c35_u);
static const mxArray *c35_b_emlrt_marshallOut(const uint32_T c35_u);
static real_T c35_cosd(SFc35_NewModuleTry_csInstanceStruct *chartInstance,
  real_T c35_x);
static boolean_T c35_isfinite(SFc35_NewModuleTry_csInstanceStruct *chartInstance,
  real_T c35_x);
static real_T c35_sind(SFc35_NewModuleTry_csInstanceStruct *chartInstance,
  real_T c35_x);
static void c35_eml_scalar_eg(SFc35_NewModuleTry_csInstanceStruct *chartInstance);
static void c35_eml_xgemm(SFc35_NewModuleTry_csInstanceStruct *chartInstance,
  real_T c35_A[4], real_T c35_B[2], real_T c35_C[2], real_T c35_b_C[2]);
static const mxArray *c35_d_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static int32_T c35_e_emlrt_marshallIn(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId);
static void c35_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static uint8_T c35_f_emlrt_marshallIn(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c35_b_is_active_c35_NewModuleTry_cs, const
  char_T *c35_identifier);
static uint8_T c35_g_emlrt_marshallIn(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId);
static void c35_b_cosd(SFc35_NewModuleTry_csInstanceStruct *chartInstance,
  real_T *c35_x);
static void c35_b_sind(SFc35_NewModuleTry_csInstanceStruct *chartInstance,
  real_T *c35_x);
static void c35_b_eml_xgemm(SFc35_NewModuleTry_csInstanceStruct *chartInstance,
  real_T c35_A[4], real_T c35_B[2], real_T c35_C[2]);
static void init_dsm_address_info(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c35_NewModuleTry_cs(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  chartInstance->c35_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c35_is_active_c35_NewModuleTry_cs = 0U;
}

static void initialize_params_c35_NewModuleTry_cs
  (SFc35_NewModuleTry_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c35_NewModuleTry_cs(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c35_NewModuleTry_cs(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c35_update_debugger_state_c35_NewModuleTry_cs
  (SFc35_NewModuleTry_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c35_NewModuleTry_cs
  (SFc35_NewModuleTry_csInstanceStruct *chartInstance)
{
  const mxArray *c35_st;
  const mxArray *c35_y = NULL;
  real_T c35_hoistedGlobal;
  real_T c35_u;
  const mxArray *c35_b_y = NULL;
  real_T c35_b_hoistedGlobal;
  real_T c35_b_u;
  const mxArray *c35_c_y = NULL;
  uint8_T c35_c_hoistedGlobal;
  uint8_T c35_c_u;
  const mxArray *c35_d_y = NULL;
  c35_st = NULL;
  c35_st = NULL;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_createcellmatrix(3, 1), false);
  c35_hoistedGlobal = *chartInstance->c35_dTranslationX;
  c35_u = c35_hoistedGlobal;
  c35_b_y = NULL;
  sf_mex_assign(&c35_b_y, sf_mex_create("y", &c35_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c35_y, 0, c35_b_y);
  c35_b_hoistedGlobal = *chartInstance->c35_dTranslationY;
  c35_b_u = c35_b_hoistedGlobal;
  c35_c_y = NULL;
  sf_mex_assign(&c35_c_y, sf_mex_create("y", &c35_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c35_y, 1, c35_c_y);
  c35_c_hoistedGlobal = chartInstance->c35_is_active_c35_NewModuleTry_cs;
  c35_c_u = c35_c_hoistedGlobal;
  c35_d_y = NULL;
  sf_mex_assign(&c35_d_y, sf_mex_create("y", &c35_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c35_y, 2, c35_d_y);
  sf_mex_assign(&c35_st, c35_y, false);
  return c35_st;
}

static void set_sim_state_c35_NewModuleTry_cs
  (SFc35_NewModuleTry_csInstanceStruct *chartInstance, const mxArray *c35_st)
{
  const mxArray *c35_u;
  chartInstance->c35_doneDoubleBufferReInit = true;
  c35_u = sf_mex_dup(c35_st);
  *chartInstance->c35_dTranslationX = c35_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c35_u, 0)), "dTranslationX");
  *chartInstance->c35_dTranslationY = c35_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c35_u, 1)), "dTranslationY");
  chartInstance->c35_is_active_c35_NewModuleTry_cs = c35_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c35_u, 2)),
     "is_active_c35_NewModuleTry_cs");
  sf_mex_destroy(&c35_u);
  c35_update_debugger_state_c35_NewModuleTry_cs(chartInstance);
  sf_mex_destroy(&c35_st);
}

static void finalize_c35_NewModuleTry_cs(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c35_NewModuleTry_cs(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  real_T c35_hoistedGlobal;
  real_T c35_b_hoistedGlobal;
  real_T c35_c_hoistedGlobal;
  real_T c35_d_hoistedGlobal;
  real_T c35_b_carAngle;
  real_T c35_b_carVelocity;
  real_T c35_b_dopplerTX;
  real_T c35_b_dopplerTY;
  uint32_T c35_debug_family_var_map[13];
  real_T c35_rotMat[4];
  real_T c35_carVelX;
  real_T c35_carVelY;
  real_T c35_carVelMat[2];
  real_T c35_Vdv[2];
  real_T c35_nargin = 4.0;
  real_T c35_nargout = 2.0;
  real_T c35_b_dTranslationX;
  real_T c35_b_dTranslationY;
  real_T c35_d0;
  real_T c35_d1;
  real_T c35_d2;
  real_T c35_d3;
  real_T c35_d4;
  real_T c35_d5;
  int32_T c35_i0;
  real_T c35_a[4];
  real_T c35_b[2];
  int32_T c35_i1;
  int32_T c35_i2;
  real_T c35_dv0[2];
  int32_T c35_i3;
  real_T c35_b_a[4];
  int32_T c35_i4;
  real_T c35_b_b[2];
  int32_T c35_i5;
  int32_T c35_i6;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 34U, chartInstance->c35_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c35_carAngle, 0U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c35_carVelocity, 1U);
  chartInstance->c35_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 34U, chartInstance->c35_sfEvent);
  c35_hoistedGlobal = *chartInstance->c35_carAngle;
  c35_b_hoistedGlobal = *chartInstance->c35_carVelocity;
  c35_c_hoistedGlobal = *chartInstance->c35_dopplerTX;
  c35_d_hoistedGlobal = *chartInstance->c35_dopplerTY;
  c35_b_carAngle = c35_hoistedGlobal;
  c35_b_carVelocity = c35_b_hoistedGlobal;
  c35_b_dopplerTX = c35_c_hoistedGlobal;
  c35_b_dopplerTY = c35_d_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c35_debug_family_names,
    c35_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c35_rotMat, 0U, c35_c_sf_marshallOut,
    c35_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_carVelX, 1U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_carVelY, 2U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c35_carVelMat, 3U, c35_b_sf_marshallOut,
    c35_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c35_Vdv, 4U, c35_b_sf_marshallOut,
    c35_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_nargin, 5U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_nargout, 6U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c35_b_carAngle, 7U, c35_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c35_b_carVelocity, 8U, c35_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c35_b_dopplerTX, 9U, c35_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c35_b_dopplerTY, 10U, c35_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_b_dTranslationX, 11U,
    c35_sf_marshallOut, c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_b_dTranslationY, 12U,
    c35_sf_marshallOut, c35_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 3);
  c35_d0 = c35_b_carAngle;
  c35_b_cosd(chartInstance, &c35_d0);
  c35_d1 = c35_b_carAngle;
  c35_b_sind(chartInstance, &c35_d1);
  c35_d2 = c35_b_carAngle;
  c35_b_sind(chartInstance, &c35_d2);
  c35_d3 = c35_b_carAngle;
  c35_b_cosd(chartInstance, &c35_d3);
  c35_rotMat[0] = c35_d0;
  c35_rotMat[2] = -c35_d1;
  c35_rotMat[1] = c35_d2;
  c35_rotMat[3] = c35_d3;
  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 6);
  c35_d4 = c35_b_carAngle;
  c35_b_cosd(chartInstance, &c35_d4);
  c35_carVelX = c35_b_carVelocity * c35_d4;
  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 7);
  c35_d5 = c35_b_carAngle;
  c35_b_sind(chartInstance, &c35_d5);
  c35_carVelY = c35_b_carVelocity * c35_d5;
  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 9);
  c35_carVelMat[0] = c35_carVelX;
  c35_carVelMat[1] = c35_carVelY;
  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 11);
  for (c35_i0 = 0; c35_i0 < 4; c35_i0++) {
    c35_a[c35_i0] = c35_rotMat[c35_i0];
  }

  c35_b[0] = c35_b_dopplerTX;
  c35_b[1] = c35_b_dopplerTY;
  c35_eml_scalar_eg(chartInstance);
  c35_eml_scalar_eg(chartInstance);
  for (c35_i1 = 0; c35_i1 < 2; c35_i1++) {
    c35_Vdv[c35_i1] = 0.0;
  }

  for (c35_i2 = 0; c35_i2 < 2; c35_i2++) {
    c35_dv0[c35_i2] = 0.0;
  }

  for (c35_i3 = 0; c35_i3 < 4; c35_i3++) {
    c35_b_a[c35_i3] = c35_a[c35_i3];
  }

  for (c35_i4 = 0; c35_i4 < 2; c35_i4++) {
    c35_b_b[c35_i4] = c35_b[c35_i4];
  }

  c35_b_eml_xgemm(chartInstance, c35_b_a, c35_b_b, c35_dv0);
  for (c35_i5 = 0; c35_i5 < 2; c35_i5++) {
    c35_Vdv[c35_i5] = c35_dv0[c35_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 13);
  for (c35_i6 = 0; c35_i6 < 2; c35_i6++) {
    c35_Vdv[c35_i6] += c35_carVelMat[c35_i6];
  }

  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 15);
  c35_b_dTranslationX = c35_Vdv[0];
  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 16);
  c35_b_dTranslationY = c35_Vdv[1];
  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, -16);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c35_dTranslationX = c35_b_dTranslationX;
  *chartInstance->c35_dTranslationY = c35_b_dTranslationY;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 34U, chartInstance->c35_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_NewModuleTry_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c35_dTranslationX, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c35_dopplerTX, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c35_dopplerTY, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c35_dTranslationY, 5U);
}

static void mdl_start_c35_NewModuleTry_cs(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc35_NewModuleTry_cs
  (SFc35_NewModuleTry_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c35_machineNumber, uint32_T
  c35_chartNumber, uint32_T c35_instanceNumber)
{
  (void)c35_machineNumber;
  (void)c35_chartNumber;
  (void)c35_instanceNumber;
}

static const mxArray *c35_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  real_T c35_u;
  const mxArray *c35_y = NULL;
  SFc35_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc35_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  c35_u = *(real_T *)c35_inData;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", &c35_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

static real_T c35_emlrt_marshallIn(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c35_b_dTranslationY, const char_T
  *c35_identifier)
{
  real_T c35_y;
  emlrtMsgIdentifier c35_thisId;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_b_dTranslationY),
    &c35_thisId);
  sf_mex_destroy(&c35_b_dTranslationY);
  return c35_y;
}

static real_T c35_b_emlrt_marshallIn(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId)
{
  real_T c35_y;
  real_T c35_d6;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), &c35_d6, 1, 0, 0U, 0, 0U, 0);
  c35_y = c35_d6;
  sf_mex_destroy(&c35_u);
  return c35_y;
}

static void c35_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_b_dTranslationY;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  real_T c35_y;
  SFc35_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc35_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c35_b_dTranslationY = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_b_dTranslationY),
    &c35_thisId);
  sf_mex_destroy(&c35_b_dTranslationY);
  *(real_T *)c35_outData = c35_y;
  sf_mex_destroy(&c35_mxArrayInData);
}

static const mxArray *c35_b_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  int32_T c35_i7;
  real_T c35_b_inData[2];
  int32_T c35_i8;
  real_T c35_u[2];
  const mxArray *c35_y = NULL;
  SFc35_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc35_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  for (c35_i7 = 0; c35_i7 < 2; c35_i7++) {
    c35_b_inData[c35_i7] = (*(real_T (*)[2])c35_inData)[c35_i7];
  }

  for (c35_i8 = 0; c35_i8 < 2; c35_i8++) {
    c35_u[c35_i8] = c35_b_inData[c35_i8];
  }

  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

static void c35_c_emlrt_marshallIn(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId,
  real_T c35_y[2])
{
  real_T c35_dv1[2];
  int32_T c35_i9;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), c35_dv1, 1, 0, 0U, 1, 0U, 1, 2);
  for (c35_i9 = 0; c35_i9 < 2; c35_i9++) {
    c35_y[c35_i9] = c35_dv1[c35_i9];
  }

  sf_mex_destroy(&c35_u);
}

static void c35_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_Vdv;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  real_T c35_y[2];
  int32_T c35_i10;
  SFc35_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc35_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c35_Vdv = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_Vdv), &c35_thisId, c35_y);
  sf_mex_destroy(&c35_Vdv);
  for (c35_i10 = 0; c35_i10 < 2; c35_i10++) {
    (*(real_T (*)[2])c35_outData)[c35_i10] = c35_y[c35_i10];
  }

  sf_mex_destroy(&c35_mxArrayInData);
}

static const mxArray *c35_c_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  int32_T c35_i11;
  int32_T c35_i12;
  int32_T c35_i13;
  real_T c35_b_inData[4];
  int32_T c35_i14;
  int32_T c35_i15;
  int32_T c35_i16;
  real_T c35_u[4];
  const mxArray *c35_y = NULL;
  SFc35_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc35_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  c35_i11 = 0;
  for (c35_i12 = 0; c35_i12 < 2; c35_i12++) {
    for (c35_i13 = 0; c35_i13 < 2; c35_i13++) {
      c35_b_inData[c35_i13 + c35_i11] = (*(real_T (*)[4])c35_inData)[c35_i13 +
        c35_i11];
    }

    c35_i11 += 2;
  }

  c35_i14 = 0;
  for (c35_i15 = 0; c35_i15 < 2; c35_i15++) {
    for (c35_i16 = 0; c35_i16 < 2; c35_i16++) {
      c35_u[c35_i16 + c35_i14] = c35_b_inData[c35_i16 + c35_i14];
    }

    c35_i14 += 2;
  }

  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 0, 0U, 1U, 0U, 2, 2, 2), false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

static void c35_d_emlrt_marshallIn(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId,
  real_T c35_y[4])
{
  real_T c35_dv2[4];
  int32_T c35_i17;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), c35_dv2, 1, 0, 0U, 1, 0U, 2, 2,
                2);
  for (c35_i17 = 0; c35_i17 < 4; c35_i17++) {
    c35_y[c35_i17] = c35_dv2[c35_i17];
  }

  sf_mex_destroy(&c35_u);
}

static void c35_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_rotMat;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  real_T c35_y[4];
  int32_T c35_i18;
  int32_T c35_i19;
  int32_T c35_i20;
  SFc35_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc35_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c35_rotMat = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_rotMat), &c35_thisId,
    c35_y);
  sf_mex_destroy(&c35_rotMat);
  c35_i18 = 0;
  for (c35_i19 = 0; c35_i19 < 2; c35_i19++) {
    for (c35_i20 = 0; c35_i20 < 2; c35_i20++) {
      (*(real_T (*)[4])c35_outData)[c35_i20 + c35_i18] = c35_y[c35_i20 + c35_i18];
    }

    c35_i18 += 2;
  }

  sf_mex_destroy(&c35_mxArrayInData);
}

const mxArray *sf_c35_NewModuleTry_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c35_nameCaptureInfo = NULL;
  c35_nameCaptureInfo = NULL;
  sf_mex_assign(&c35_nameCaptureInfo, sf_mex_createstruct("structure", 2, 41, 1),
                false);
  c35_info_helper(&c35_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c35_nameCaptureInfo);
  return c35_nameCaptureInfo;
}

static void c35_info_helper(const mxArray **c35_info)
{
  const mxArray *c35_rhs0 = NULL;
  const mxArray *c35_lhs0 = NULL;
  const mxArray *c35_rhs1 = NULL;
  const mxArray *c35_lhs1 = NULL;
  const mxArray *c35_rhs2 = NULL;
  const mxArray *c35_lhs2 = NULL;
  const mxArray *c35_rhs3 = NULL;
  const mxArray *c35_lhs3 = NULL;
  const mxArray *c35_rhs4 = NULL;
  const mxArray *c35_lhs4 = NULL;
  const mxArray *c35_rhs5 = NULL;
  const mxArray *c35_lhs5 = NULL;
  const mxArray *c35_rhs6 = NULL;
  const mxArray *c35_lhs6 = NULL;
  const mxArray *c35_rhs7 = NULL;
  const mxArray *c35_lhs7 = NULL;
  const mxArray *c35_rhs8 = NULL;
  const mxArray *c35_lhs8 = NULL;
  const mxArray *c35_rhs9 = NULL;
  const mxArray *c35_lhs9 = NULL;
  const mxArray *c35_rhs10 = NULL;
  const mxArray *c35_lhs10 = NULL;
  const mxArray *c35_rhs11 = NULL;
  const mxArray *c35_lhs11 = NULL;
  const mxArray *c35_rhs12 = NULL;
  const mxArray *c35_lhs12 = NULL;
  const mxArray *c35_rhs13 = NULL;
  const mxArray *c35_lhs13 = NULL;
  const mxArray *c35_rhs14 = NULL;
  const mxArray *c35_lhs14 = NULL;
  const mxArray *c35_rhs15 = NULL;
  const mxArray *c35_lhs15 = NULL;
  const mxArray *c35_rhs16 = NULL;
  const mxArray *c35_lhs16 = NULL;
  const mxArray *c35_rhs17 = NULL;
  const mxArray *c35_lhs17 = NULL;
  const mxArray *c35_rhs18 = NULL;
  const mxArray *c35_lhs18 = NULL;
  const mxArray *c35_rhs19 = NULL;
  const mxArray *c35_lhs19 = NULL;
  const mxArray *c35_rhs20 = NULL;
  const mxArray *c35_lhs20 = NULL;
  const mxArray *c35_rhs21 = NULL;
  const mxArray *c35_lhs21 = NULL;
  const mxArray *c35_rhs22 = NULL;
  const mxArray *c35_lhs22 = NULL;
  const mxArray *c35_rhs23 = NULL;
  const mxArray *c35_lhs23 = NULL;
  const mxArray *c35_rhs24 = NULL;
  const mxArray *c35_lhs24 = NULL;
  const mxArray *c35_rhs25 = NULL;
  const mxArray *c35_lhs25 = NULL;
  const mxArray *c35_rhs26 = NULL;
  const mxArray *c35_lhs26 = NULL;
  const mxArray *c35_rhs27 = NULL;
  const mxArray *c35_lhs27 = NULL;
  const mxArray *c35_rhs28 = NULL;
  const mxArray *c35_lhs28 = NULL;
  const mxArray *c35_rhs29 = NULL;
  const mxArray *c35_lhs29 = NULL;
  const mxArray *c35_rhs30 = NULL;
  const mxArray *c35_lhs30 = NULL;
  const mxArray *c35_rhs31 = NULL;
  const mxArray *c35_lhs31 = NULL;
  const mxArray *c35_rhs32 = NULL;
  const mxArray *c35_lhs32 = NULL;
  const mxArray *c35_rhs33 = NULL;
  const mxArray *c35_lhs33 = NULL;
  const mxArray *c35_rhs34 = NULL;
  const mxArray *c35_lhs34 = NULL;
  const mxArray *c35_rhs35 = NULL;
  const mxArray *c35_lhs35 = NULL;
  const mxArray *c35_rhs36 = NULL;
  const mxArray *c35_lhs36 = NULL;
  const mxArray *c35_rhs37 = NULL;
  const mxArray *c35_lhs37 = NULL;
  const mxArray *c35_rhs38 = NULL;
  const mxArray *c35_lhs38 = NULL;
  const mxArray *c35_rhs39 = NULL;
  const mxArray *c35_lhs39 = NULL;
  const mxArray *c35_rhs40 = NULL;
  const mxArray *c35_lhs40 = NULL;
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("cosd"), "name", "name", 0);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1395346498U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c35_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_scalar_cosd_and_sind"),
                  "name", "name", 1);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1343851978U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c35_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("isfinite"), "name", "name",
                  2);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c35_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c35_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("isinf"), "name", "name", 4);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c35_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c35_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("isnan"), "name", "name", 6);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c35_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 7);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c35_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 8);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1286840376U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c35_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 9);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1286840382U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c35_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_scalar_rem90"), "name",
                  "name", 10);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1343851978U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c35_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "context", "context", 11);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("mrdivide"), "name", "name",
                  11);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c35_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 12);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 12);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c35_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 13);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("rdivide"), "name", "name",
                  13);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c35_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 14);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c35_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 15);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c35_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_div"), "name", "name",
                  16);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c35_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 17);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c35_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "context", "context", 18);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("rem"), "name", "name", 18);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c35_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 19);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c35_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 20);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c35_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 21);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c35_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 22);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c35_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 23);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 23);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c35_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "context", "context", 24);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("abs"), "name", "name", 24);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c35_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 25);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c35_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 26);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c35_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "context", "context", 27);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("sind"), "name", "name", 27);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sind.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1395346504U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c35_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sind.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_scalar_cosd_and_sind"),
                  "name", "name", 28);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1343851978U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c35_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "context", "context", 29);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 29);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c35_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 30);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 30);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c35_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 31);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 31);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c35_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 32);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 32);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c35_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 33);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  33);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1376002290U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c35_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 34);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c35_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 35);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c35_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 36);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 36);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c35_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 37);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 37);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c35_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 38);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 38);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c35_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 39);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 39);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c35_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 40);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 40);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c35_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs40), "lhs", "lhs",
                  40);
  sf_mex_destroy(&c35_rhs0);
  sf_mex_destroy(&c35_lhs0);
  sf_mex_destroy(&c35_rhs1);
  sf_mex_destroy(&c35_lhs1);
  sf_mex_destroy(&c35_rhs2);
  sf_mex_destroy(&c35_lhs2);
  sf_mex_destroy(&c35_rhs3);
  sf_mex_destroy(&c35_lhs3);
  sf_mex_destroy(&c35_rhs4);
  sf_mex_destroy(&c35_lhs4);
  sf_mex_destroy(&c35_rhs5);
  sf_mex_destroy(&c35_lhs5);
  sf_mex_destroy(&c35_rhs6);
  sf_mex_destroy(&c35_lhs6);
  sf_mex_destroy(&c35_rhs7);
  sf_mex_destroy(&c35_lhs7);
  sf_mex_destroy(&c35_rhs8);
  sf_mex_destroy(&c35_lhs8);
  sf_mex_destroy(&c35_rhs9);
  sf_mex_destroy(&c35_lhs9);
  sf_mex_destroy(&c35_rhs10);
  sf_mex_destroy(&c35_lhs10);
  sf_mex_destroy(&c35_rhs11);
  sf_mex_destroy(&c35_lhs11);
  sf_mex_destroy(&c35_rhs12);
  sf_mex_destroy(&c35_lhs12);
  sf_mex_destroy(&c35_rhs13);
  sf_mex_destroy(&c35_lhs13);
  sf_mex_destroy(&c35_rhs14);
  sf_mex_destroy(&c35_lhs14);
  sf_mex_destroy(&c35_rhs15);
  sf_mex_destroy(&c35_lhs15);
  sf_mex_destroy(&c35_rhs16);
  sf_mex_destroy(&c35_lhs16);
  sf_mex_destroy(&c35_rhs17);
  sf_mex_destroy(&c35_lhs17);
  sf_mex_destroy(&c35_rhs18);
  sf_mex_destroy(&c35_lhs18);
  sf_mex_destroy(&c35_rhs19);
  sf_mex_destroy(&c35_lhs19);
  sf_mex_destroy(&c35_rhs20);
  sf_mex_destroy(&c35_lhs20);
  sf_mex_destroy(&c35_rhs21);
  sf_mex_destroy(&c35_lhs21);
  sf_mex_destroy(&c35_rhs22);
  sf_mex_destroy(&c35_lhs22);
  sf_mex_destroy(&c35_rhs23);
  sf_mex_destroy(&c35_lhs23);
  sf_mex_destroy(&c35_rhs24);
  sf_mex_destroy(&c35_lhs24);
  sf_mex_destroy(&c35_rhs25);
  sf_mex_destroy(&c35_lhs25);
  sf_mex_destroy(&c35_rhs26);
  sf_mex_destroy(&c35_lhs26);
  sf_mex_destroy(&c35_rhs27);
  sf_mex_destroy(&c35_lhs27);
  sf_mex_destroy(&c35_rhs28);
  sf_mex_destroy(&c35_lhs28);
  sf_mex_destroy(&c35_rhs29);
  sf_mex_destroy(&c35_lhs29);
  sf_mex_destroy(&c35_rhs30);
  sf_mex_destroy(&c35_lhs30);
  sf_mex_destroy(&c35_rhs31);
  sf_mex_destroy(&c35_lhs31);
  sf_mex_destroy(&c35_rhs32);
  sf_mex_destroy(&c35_lhs32);
  sf_mex_destroy(&c35_rhs33);
  sf_mex_destroy(&c35_lhs33);
  sf_mex_destroy(&c35_rhs34);
  sf_mex_destroy(&c35_lhs34);
  sf_mex_destroy(&c35_rhs35);
  sf_mex_destroy(&c35_lhs35);
  sf_mex_destroy(&c35_rhs36);
  sf_mex_destroy(&c35_lhs36);
  sf_mex_destroy(&c35_rhs37);
  sf_mex_destroy(&c35_lhs37);
  sf_mex_destroy(&c35_rhs38);
  sf_mex_destroy(&c35_lhs38);
  sf_mex_destroy(&c35_rhs39);
  sf_mex_destroy(&c35_lhs39);
  sf_mex_destroy(&c35_rhs40);
  sf_mex_destroy(&c35_lhs40);
}

static const mxArray *c35_emlrt_marshallOut(const char * c35_u)
{
  const mxArray *c35_y = NULL;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c35_u)), false);
  return c35_y;
}

static const mxArray *c35_b_emlrt_marshallOut(const uint32_T c35_u)
{
  const mxArray *c35_y = NULL;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", &c35_u, 7, 0U, 0U, 0U, 0), false);
  return c35_y;
}

static real_T c35_cosd(SFc35_NewModuleTry_csInstanceStruct *chartInstance,
  real_T c35_x)
{
  real_T c35_b_x;
  c35_b_x = c35_x;
  c35_b_cosd(chartInstance, &c35_b_x);
  return c35_b_x;
}

static boolean_T c35_isfinite(SFc35_NewModuleTry_csInstanceStruct *chartInstance,
  real_T c35_x)
{
  real_T c35_b_x;
  boolean_T c35_b_b;
  boolean_T c35_b0;
  real_T c35_c_x;
  boolean_T c35_c_b;
  boolean_T c35_b1;
  (void)chartInstance;
  c35_b_x = c35_x;
  c35_b_b = muDoubleScalarIsInf(c35_b_x);
  c35_b0 = !c35_b_b;
  c35_c_x = c35_x;
  c35_c_b = muDoubleScalarIsNaN(c35_c_x);
  c35_b1 = !c35_c_b;
  return c35_b0 && c35_b1;
}

static real_T c35_sind(SFc35_NewModuleTry_csInstanceStruct *chartInstance,
  real_T c35_x)
{
  real_T c35_b_x;
  c35_b_x = c35_x;
  c35_b_sind(chartInstance, &c35_b_x);
  return c35_b_x;
}

static void c35_eml_scalar_eg(SFc35_NewModuleTry_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c35_eml_xgemm(SFc35_NewModuleTry_csInstanceStruct *chartInstance,
  real_T c35_A[4], real_T c35_B[2], real_T c35_C[2], real_T c35_b_C[2])
{
  int32_T c35_i21;
  int32_T c35_i22;
  real_T c35_b_A[4];
  int32_T c35_i23;
  real_T c35_b_B[2];
  for (c35_i21 = 0; c35_i21 < 2; c35_i21++) {
    c35_b_C[c35_i21] = c35_C[c35_i21];
  }

  for (c35_i22 = 0; c35_i22 < 4; c35_i22++) {
    c35_b_A[c35_i22] = c35_A[c35_i22];
  }

  for (c35_i23 = 0; c35_i23 < 2; c35_i23++) {
    c35_b_B[c35_i23] = c35_B[c35_i23];
  }

  c35_b_eml_xgemm(chartInstance, c35_b_A, c35_b_B, c35_b_C);
}

static const mxArray *c35_d_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  int32_T c35_u;
  const mxArray *c35_y = NULL;
  SFc35_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc35_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  c35_u = *(int32_T *)c35_inData;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", &c35_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

static int32_T c35_e_emlrt_marshallIn(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId)
{
  int32_T c35_y;
  int32_T c35_i24;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), &c35_i24, 1, 6, 0U, 0, 0U, 0);
  c35_y = c35_i24;
  sf_mex_destroy(&c35_u);
  return c35_y;
}

static void c35_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_b_sfEvent;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  int32_T c35_y;
  SFc35_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc35_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c35_b_sfEvent = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_b_sfEvent),
    &c35_thisId);
  sf_mex_destroy(&c35_b_sfEvent);
  *(int32_T *)c35_outData = c35_y;
  sf_mex_destroy(&c35_mxArrayInData);
}

static uint8_T c35_f_emlrt_marshallIn(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c35_b_is_active_c35_NewModuleTry_cs, const
  char_T *c35_identifier)
{
  uint8_T c35_y;
  emlrtMsgIdentifier c35_thisId;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c35_b_is_active_c35_NewModuleTry_cs), &c35_thisId);
  sf_mex_destroy(&c35_b_is_active_c35_NewModuleTry_cs);
  return c35_y;
}

static uint8_T c35_g_emlrt_marshallIn(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId)
{
  uint8_T c35_y;
  uint8_T c35_u0;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), &c35_u0, 1, 3, 0U, 0, 0U, 0);
  c35_y = c35_u0;
  sf_mex_destroy(&c35_u);
  return c35_y;
}

static void c35_b_cosd(SFc35_NewModuleTry_csInstanceStruct *chartInstance,
  real_T *c35_x)
{
  real_T c35_b_x;
  real_T c35_c_x;
  real_T c35_d_x;
  real_T c35_e_x;
  real_T c35_xk;
  real_T c35_f_x;
  real_T c35_g_x;
  real_T c35_absx;
  real_T c35_h_x;
  real_T c35_i_x;
  int8_T c35_n;
  int8_T c35_b_n;
  c35_b_x = *c35_x;
  if (!c35_isfinite(chartInstance, c35_b_x)) {
    *c35_x = rtNaN;
  } else {
    c35_c_x = c35_b_x;
    c35_d_x = c35_c_x;
    c35_e_x = c35_d_x;
    c35_xk = c35_e_x;
    c35_d_x = muDoubleScalarRem(c35_xk, 360.0);
    c35_f_x = c35_d_x;
    c35_g_x = c35_f_x;
    c35_absx = muDoubleScalarAbs(c35_g_x);
    if (c35_absx > 180.0) {
      if (c35_d_x > 0.0) {
        c35_d_x -= 360.0;
      } else {
        c35_d_x += 360.0;
      }

      c35_h_x = c35_d_x;
      c35_i_x = c35_h_x;
      c35_absx = muDoubleScalarAbs(c35_i_x);
    }

    if (c35_absx <= 45.0) {
      c35_d_x *= 0.017453292519943295;
      c35_n = 0;
    } else if (c35_absx <= 135.0) {
      if (c35_d_x > 0.0) {
        c35_d_x = 0.017453292519943295 * (c35_d_x - 90.0);
        c35_n = 1;
      } else {
        c35_d_x = 0.017453292519943295 * (c35_d_x + 90.0);
        c35_n = -1;
      }
    } else if (c35_d_x > 0.0) {
      c35_d_x = 0.017453292519943295 * (c35_d_x - 180.0);
      c35_n = 2;
    } else {
      c35_d_x = 0.017453292519943295 * (c35_d_x + 180.0);
      c35_n = -2;
    }

    c35_b_n = c35_n;
    c35_b_x = c35_d_x;
    if ((real_T)c35_b_n == 0.0) {
      *c35_x = muDoubleScalarCos(c35_b_x);
    } else if ((real_T)c35_b_n == 1.0) {
      *c35_x = -muDoubleScalarSin(c35_b_x);
    } else if ((real_T)c35_b_n == -1.0) {
      *c35_x = muDoubleScalarSin(c35_b_x);
    } else {
      *c35_x = -muDoubleScalarCos(c35_b_x);
    }
  }
}

static void c35_b_sind(SFc35_NewModuleTry_csInstanceStruct *chartInstance,
  real_T *c35_x)
{
  real_T c35_b_x;
  real_T c35_d7;
  real_T c35_c_x;
  real_T c35_d_x;
  real_T c35_e_x;
  real_T c35_xk;
  real_T c35_f_x;
  real_T c35_g_x;
  real_T c35_absx;
  real_T c35_h_x;
  real_T c35_i_x;
  int8_T c35_n;
  int8_T c35_b_n;
  c35_b_x = *c35_x;
  if (!c35_isfinite(chartInstance, c35_b_x)) {
    c35_d7 = rtNaN;
  } else {
    c35_c_x = c35_b_x;
    c35_d_x = c35_c_x;
    c35_e_x = c35_d_x;
    c35_xk = c35_e_x;
    c35_d_x = muDoubleScalarRem(c35_xk, 360.0);
    c35_f_x = c35_d_x;
    c35_g_x = c35_f_x;
    c35_absx = muDoubleScalarAbs(c35_g_x);
    if (c35_absx > 180.0) {
      if (c35_d_x > 0.0) {
        c35_d_x -= 360.0;
      } else {
        c35_d_x += 360.0;
      }

      c35_h_x = c35_d_x;
      c35_i_x = c35_h_x;
      c35_absx = muDoubleScalarAbs(c35_i_x);
    }

    if (c35_absx <= 45.0) {
      c35_d_x *= 0.017453292519943295;
      c35_n = 0;
    } else if (c35_absx <= 135.0) {
      if (c35_d_x > 0.0) {
        c35_d_x = 0.017453292519943295 * (c35_d_x - 90.0);
        c35_n = 1;
      } else {
        c35_d_x = 0.017453292519943295 * (c35_d_x + 90.0);
        c35_n = -1;
      }
    } else if (c35_d_x > 0.0) {
      c35_d_x = 0.017453292519943295 * (c35_d_x - 180.0);
      c35_n = 2;
    } else {
      c35_d_x = 0.017453292519943295 * (c35_d_x + 180.0);
      c35_n = -2;
    }

    c35_b_n = c35_n;
    c35_b_x = c35_d_x;
    if ((real_T)c35_b_n == 0.0) {
      c35_d7 = muDoubleScalarSin(c35_b_x);
    } else if ((real_T)c35_b_n == 1.0) {
      c35_d7 = muDoubleScalarCos(c35_b_x);
    } else if ((real_T)c35_b_n == -1.0) {
      c35_d7 = -muDoubleScalarCos(c35_b_x);
    } else {
      c35_d7 = -muDoubleScalarSin(c35_b_x);
    }
  }

  *c35_x = c35_d7;
}

static void c35_b_eml_xgemm(SFc35_NewModuleTry_csInstanceStruct *chartInstance,
  real_T c35_A[4], real_T c35_B[2], real_T c35_C[2])
{
  int32_T c35_i25;
  int32_T c35_i26;
  int32_T c35_i27;
  (void)chartInstance;
  for (c35_i25 = 0; c35_i25 < 2; c35_i25++) {
    c35_C[c35_i25] = 0.0;
    c35_i26 = 0;
    for (c35_i27 = 0; c35_i27 < 2; c35_i27++) {
      c35_C[c35_i25] += c35_A[c35_i26 + c35_i25] * c35_B[c35_i27];
      c35_i26 += 2;
    }
  }
}

static void init_dsm_address_info(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc35_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  chartInstance->c35_carAngle = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c35_carVelocity = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c35_dTranslationX = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c35_dopplerTX = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c35_dopplerTY = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c35_dTranslationY = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
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

void sf_c35_NewModuleTry_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2904488787U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(77846290U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(305427333U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(571165683U);
}

mxArray* sf_c35_NewModuleTry_cs_get_post_codegen_info(void);
mxArray *sf_c35_NewModuleTry_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("MpCqQyY42hgLel6modLfVE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c35_NewModuleTry_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c35_NewModuleTry_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c35_NewModuleTry_cs_jit_fallback_info(void)
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

mxArray *sf_c35_NewModuleTry_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c35_NewModuleTry_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c35_NewModuleTry_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"dTranslationX\",},{M[1],M[8],T\"dTranslationY\",},{M[8],M[0],T\"is_active_c35_NewModuleTry_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c35_NewModuleTry_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc35_NewModuleTry_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc35_NewModuleTry_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _NewModuleTry_csMachineNumber_,
           35,
           1,
           1,
           0,
           6,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_NewModuleTry_csMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_NewModuleTry_csMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _NewModuleTry_csMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"carAngle");
          _SFD_SET_DATA_PROPS(1,1,1,0,"carVelocity");
          _SFD_SET_DATA_PROPS(2,2,0,1,"dTranslationX");
          _SFD_SET_DATA_PROPS(3,1,1,0,"dopplerTX");
          _SFD_SET_DATA_PROPS(4,1,1,0,"dopplerTY");
          _SFD_SET_DATA_PROPS(5,2,0,1,"dTranslationY");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,403);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)c35_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)c35_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c35_carAngle);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c35_carVelocity);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c35_dTranslationX);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c35_dopplerTX);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c35_dopplerTY);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c35_dTranslationY);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _NewModuleTry_csMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "Xn7Xe8DJebD23xOHDtqcIE";
}

static void sf_opaque_initialize_c35_NewModuleTry_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc35_NewModuleTry_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c35_NewModuleTry_cs((SFc35_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
  initialize_c35_NewModuleTry_cs((SFc35_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c35_NewModuleTry_cs(void *chartInstanceVar)
{
  enable_c35_NewModuleTry_cs((SFc35_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c35_NewModuleTry_cs(void *chartInstanceVar)
{
  disable_c35_NewModuleTry_cs((SFc35_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c35_NewModuleTry_cs(void *chartInstanceVar)
{
  sf_gateway_c35_NewModuleTry_cs((SFc35_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c35_NewModuleTry_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c35_NewModuleTry_cs((SFc35_NewModuleTry_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c35_NewModuleTry_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c35_NewModuleTry_cs((SFc35_NewModuleTry_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c35_NewModuleTry_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc35_NewModuleTry_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_NewModuleTry_cs_optimization_info();
    }

    finalize_c35_NewModuleTry_cs((SFc35_NewModuleTry_csInstanceStruct*)
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
  initSimStructsc35_NewModuleTry_cs((SFc35_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c35_NewModuleTry_cs(SimStruct *S)
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
    initialize_params_c35_NewModuleTry_cs((SFc35_NewModuleTry_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c35_NewModuleTry_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_NewModuleTry_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      35);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,35,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,35,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,35);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,35,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,35,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,35);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4264303994U));
  ssSetChecksum1(S,(1948427552U));
  ssSetChecksum2(S,(2790600158U));
  ssSetChecksum3(S,(3890767913U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c35_NewModuleTry_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c35_NewModuleTry_cs(SimStruct *S)
{
  SFc35_NewModuleTry_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc35_NewModuleTry_csInstanceStruct *)utMalloc(sizeof
    (SFc35_NewModuleTry_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc35_NewModuleTry_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c35_NewModuleTry_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c35_NewModuleTry_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c35_NewModuleTry_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c35_NewModuleTry_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c35_NewModuleTry_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c35_NewModuleTry_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c35_NewModuleTry_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c35_NewModuleTry_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c35_NewModuleTry_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c35_NewModuleTry_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c35_NewModuleTry_cs;
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

void c35_NewModuleTry_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c35_NewModuleTry_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c35_NewModuleTry_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c35_NewModuleTry_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c35_NewModuleTry_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
