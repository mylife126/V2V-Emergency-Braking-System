/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_3_cs_sfun.h"
#include "c38_Experiment_3_cs.h"
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
static const char * c38_debug_family_names[14] = { "rotMat", "carVelX",
  "carVelY", "carVelMat", "i", "Vdv", "nargin", "nargout", "carAngle",
  "carVelocity", "dopplerTX", "dopplerTY", "dTranslationX", "dTranslationY" };

/* Function Declarations */
static void initialize_c38_Experiment_3_cs(SFc38_Experiment_3_csInstanceStruct
  *chartInstance);
static void initialize_params_c38_Experiment_3_cs
  (SFc38_Experiment_3_csInstanceStruct *chartInstance);
static void enable_c38_Experiment_3_cs(SFc38_Experiment_3_csInstanceStruct
  *chartInstance);
static void disable_c38_Experiment_3_cs(SFc38_Experiment_3_csInstanceStruct
  *chartInstance);
static void c38_update_debugger_state_c38_Experiment_3_cs
  (SFc38_Experiment_3_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c38_Experiment_3_cs
  (SFc38_Experiment_3_csInstanceStruct *chartInstance);
static void set_sim_state_c38_Experiment_3_cs
  (SFc38_Experiment_3_csInstanceStruct *chartInstance, const mxArray *c38_st);
static void finalize_c38_Experiment_3_cs(SFc38_Experiment_3_csInstanceStruct
  *chartInstance);
static void sf_gateway_c38_Experiment_3_cs(SFc38_Experiment_3_csInstanceStruct
  *chartInstance);
static void mdl_start_c38_Experiment_3_cs(SFc38_Experiment_3_csInstanceStruct
  *chartInstance);
static void initSimStructsc38_Experiment_3_cs
  (SFc38_Experiment_3_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c38_machineNumber, uint32_T
  c38_chartNumber, uint32_T c38_instanceNumber);
static const mxArray *c38_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData);
static void c38_emlrt_marshallIn(SFc38_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c38_b_dTranslationY, const char_T
  *c38_identifier, real_T c38_y[5]);
static void c38_b_emlrt_marshallIn(SFc38_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId,
  real_T c38_y[5]);
static void c38_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData);
static const mxArray *c38_b_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData);
static real_T c38_c_emlrt_marshallIn(SFc38_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId);
static void c38_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData);
static const mxArray *c38_c_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData);
static void c38_d_emlrt_marshallIn(SFc38_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId,
  real_T c38_y[2]);
static void c38_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData);
static const mxArray *c38_d_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData);
static void c38_e_emlrt_marshallIn(SFc38_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId,
  real_T c38_y[4]);
static void c38_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData);
static void c38_info_helper(const mxArray **c38_info);
static const mxArray *c38_emlrt_marshallOut(const char * c38_u);
static const mxArray *c38_b_emlrt_marshallOut(const uint32_T c38_u);
static real_T c38_cosd(SFc38_Experiment_3_csInstanceStruct *chartInstance,
  real_T c38_x);
static boolean_T c38_isfinite(SFc38_Experiment_3_csInstanceStruct *chartInstance,
  real_T c38_x);
static real_T c38_sind(SFc38_Experiment_3_csInstanceStruct *chartInstance,
  real_T c38_x);
static void c38_eml_scalar_eg(SFc38_Experiment_3_csInstanceStruct *chartInstance);
static void c38_eml_xgemm(SFc38_Experiment_3_csInstanceStruct *chartInstance,
  real_T c38_A[4], real_T c38_B[2], real_T c38_C[2], real_T c38_b_C[2]);
static const mxArray *c38_e_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData);
static int32_T c38_f_emlrt_marshallIn(SFc38_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId);
static void c38_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData);
static uint8_T c38_g_emlrt_marshallIn(SFc38_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c38_b_is_active_c38_Experiment_3_cs, const
  char_T *c38_identifier);
static uint8_T c38_h_emlrt_marshallIn(SFc38_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId);
static void c38_b_cosd(SFc38_Experiment_3_csInstanceStruct *chartInstance,
  real_T *c38_x);
static void c38_b_sind(SFc38_Experiment_3_csInstanceStruct *chartInstance,
  real_T *c38_x);
static void c38_b_eml_xgemm(SFc38_Experiment_3_csInstanceStruct *chartInstance,
  real_T c38_A[4], real_T c38_B[2], real_T c38_C[2]);
static void init_dsm_address_info(SFc38_Experiment_3_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc38_Experiment_3_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c38_Experiment_3_cs(SFc38_Experiment_3_csInstanceStruct
  *chartInstance)
{
  chartInstance->c38_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c38_is_active_c38_Experiment_3_cs = 0U;
}

static void initialize_params_c38_Experiment_3_cs
  (SFc38_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c38_Experiment_3_cs(SFc38_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c38_Experiment_3_cs(SFc38_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c38_update_debugger_state_c38_Experiment_3_cs
  (SFc38_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c38_Experiment_3_cs
  (SFc38_Experiment_3_csInstanceStruct *chartInstance)
{
  const mxArray *c38_st;
  const mxArray *c38_y = NULL;
  int32_T c38_i0;
  real_T c38_u[5];
  const mxArray *c38_b_y = NULL;
  int32_T c38_i1;
  real_T c38_b_u[5];
  const mxArray *c38_c_y = NULL;
  uint8_T c38_hoistedGlobal;
  uint8_T c38_c_u;
  const mxArray *c38_d_y = NULL;
  c38_st = NULL;
  c38_st = NULL;
  c38_y = NULL;
  sf_mex_assign(&c38_y, sf_mex_createcellmatrix(3, 1), false);
  for (c38_i0 = 0; c38_i0 < 5; c38_i0++) {
    c38_u[c38_i0] = (*chartInstance->c38_dTranslationX)[c38_i0];
  }

  c38_b_y = NULL;
  sf_mex_assign(&c38_b_y, sf_mex_create("y", c38_u, 0, 0U, 1U, 0U, 1, 5), false);
  sf_mex_setcell(c38_y, 0, c38_b_y);
  for (c38_i1 = 0; c38_i1 < 5; c38_i1++) {
    c38_b_u[c38_i1] = (*chartInstance->c38_dTranslationY)[c38_i1];
  }

  c38_c_y = NULL;
  sf_mex_assign(&c38_c_y, sf_mex_create("y", c38_b_u, 0, 0U, 1U, 0U, 1, 5),
                false);
  sf_mex_setcell(c38_y, 1, c38_c_y);
  c38_hoistedGlobal = chartInstance->c38_is_active_c38_Experiment_3_cs;
  c38_c_u = c38_hoistedGlobal;
  c38_d_y = NULL;
  sf_mex_assign(&c38_d_y, sf_mex_create("y", &c38_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c38_y, 2, c38_d_y);
  sf_mex_assign(&c38_st, c38_y, false);
  return c38_st;
}

static void set_sim_state_c38_Experiment_3_cs
  (SFc38_Experiment_3_csInstanceStruct *chartInstance, const mxArray *c38_st)
{
  const mxArray *c38_u;
  real_T c38_dv0[5];
  int32_T c38_i2;
  real_T c38_dv1[5];
  int32_T c38_i3;
  chartInstance->c38_doneDoubleBufferReInit = true;
  c38_u = sf_mex_dup(c38_st);
  c38_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c38_u, 0)),
                       "dTranslationX", c38_dv0);
  for (c38_i2 = 0; c38_i2 < 5; c38_i2++) {
    (*chartInstance->c38_dTranslationX)[c38_i2] = c38_dv0[c38_i2];
  }

  c38_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c38_u, 1)),
                       "dTranslationY", c38_dv1);
  for (c38_i3 = 0; c38_i3 < 5; c38_i3++) {
    (*chartInstance->c38_dTranslationY)[c38_i3] = c38_dv1[c38_i3];
  }

  chartInstance->c38_is_active_c38_Experiment_3_cs = c38_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c38_u, 2)),
     "is_active_c38_Experiment_3_cs");
  sf_mex_destroy(&c38_u);
  c38_update_debugger_state_c38_Experiment_3_cs(chartInstance);
  sf_mex_destroy(&c38_st);
}

static void finalize_c38_Experiment_3_cs(SFc38_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c38_Experiment_3_cs(SFc38_Experiment_3_csInstanceStruct
  *chartInstance)
{
  real_T c38_hoistedGlobal;
  real_T c38_b_hoistedGlobal;
  real_T c38_b_carAngle;
  real_T c38_b_carVelocity;
  int32_T c38_i4;
  real_T c38_b_dopplerTX[5];
  int32_T c38_i5;
  real_T c38_b_dopplerTY[5];
  uint32_T c38_debug_family_var_map[14];
  real_T c38_rotMat[4];
  real_T c38_carVelX;
  real_T c38_carVelY;
  real_T c38_carVelMat[2];
  real_T c38_i;
  real_T c38_Vdv[2];
  real_T c38_nargin = 4.0;
  real_T c38_nargout = 2.0;
  real_T c38_b_dTranslationX[5];
  real_T c38_b_dTranslationY[5];
  real_T c38_d0;
  real_T c38_d1;
  real_T c38_d2;
  real_T c38_d3;
  real_T c38_d4;
  real_T c38_d5;
  int32_T c38_i6;
  int32_T c38_i7;
  int32_T c38_b_i;
  int32_T c38_i8;
  real_T c38_a[4];
  real_T c38_b[2];
  int32_T c38_i9;
  int32_T c38_i10;
  real_T c38_dv2[2];
  int32_T c38_i11;
  real_T c38_b_a[4];
  int32_T c38_i12;
  real_T c38_b_b[2];
  int32_T c38_i13;
  int32_T c38_i14;
  int32_T c38_i15;
  int32_T c38_i16;
  int32_T c38_i17;
  int32_T c38_i18;
  int32_T c38_i19;
  int32_T c38_i20;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 37U, chartInstance->c38_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c38_carAngle, 0U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c38_carVelocity, 1U);
  chartInstance->c38_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 37U, chartInstance->c38_sfEvent);
  c38_hoistedGlobal = *chartInstance->c38_carAngle;
  c38_b_hoistedGlobal = *chartInstance->c38_carVelocity;
  c38_b_carAngle = c38_hoistedGlobal;
  c38_b_carVelocity = c38_b_hoistedGlobal;
  for (c38_i4 = 0; c38_i4 < 5; c38_i4++) {
    c38_b_dopplerTX[c38_i4] = (*chartInstance->c38_dopplerTX)[c38_i4];
  }

  for (c38_i5 = 0; c38_i5 < 5; c38_i5++) {
    c38_b_dopplerTY[c38_i5] = (*chartInstance->c38_dopplerTY)[c38_i5];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 14U, c38_debug_family_names,
    c38_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c38_rotMat, 0U, c38_d_sf_marshallOut,
    c38_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c38_carVelX, 1U, c38_b_sf_marshallOut,
    c38_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c38_carVelY, 2U, c38_b_sf_marshallOut,
    c38_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c38_carVelMat, 3U, c38_c_sf_marshallOut,
    c38_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c38_i, 4U, c38_b_sf_marshallOut,
    c38_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c38_Vdv, 5U, c38_c_sf_marshallOut,
    c38_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c38_nargin, 6U, c38_b_sf_marshallOut,
    c38_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c38_nargout, 7U, c38_b_sf_marshallOut,
    c38_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c38_b_carAngle, 8U, c38_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c38_b_carVelocity, 9U, c38_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c38_b_dopplerTX, 10U, c38_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c38_b_dopplerTY, 11U, c38_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c38_b_dTranslationX, 12U,
    c38_sf_marshallOut, c38_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c38_b_dTranslationY, 13U,
    c38_sf_marshallOut, c38_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 3);
  c38_d0 = c38_b_carAngle;
  c38_b_cosd(chartInstance, &c38_d0);
  c38_d1 = c38_b_carAngle;
  c38_b_sind(chartInstance, &c38_d1);
  c38_d2 = c38_b_carAngle;
  c38_b_sind(chartInstance, &c38_d2);
  c38_d3 = c38_b_carAngle;
  c38_b_cosd(chartInstance, &c38_d3);
  c38_rotMat[0] = c38_d0;
  c38_rotMat[2] = -c38_d1;
  c38_rotMat[1] = c38_d2;
  c38_rotMat[3] = c38_d3;
  _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 6);
  c38_d4 = c38_b_carAngle;
  c38_b_cosd(chartInstance, &c38_d4);
  c38_carVelX = c38_b_carVelocity * c38_d4;
  _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 7);
  c38_d5 = c38_b_carAngle;
  c38_b_sind(chartInstance, &c38_d5);
  c38_carVelY = c38_b_carVelocity * c38_d5;
  _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 9);
  c38_carVelMat[0] = c38_carVelX;
  c38_carVelMat[1] = c38_carVelY;
  _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 11);
  for (c38_i6 = 0; c38_i6 < 5; c38_i6++) {
    c38_b_dTranslationX[c38_i6] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 12);
  for (c38_i7 = 0; c38_i7 < 5; c38_i7++) {
    c38_b_dTranslationY[c38_i7] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 14);
  c38_i = 1.0;
  c38_b_i = 0;
  while (c38_b_i < 5) {
    c38_i = 1.0 + (real_T)c38_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 16);
    for (c38_i8 = 0; c38_i8 < 4; c38_i8++) {
      c38_a[c38_i8] = c38_rotMat[c38_i8];
    }

    c38_b[0] = c38_b_dopplerTX[_SFD_EML_ARRAY_BOUNDS_CHECK("dopplerTX", (int32_T)
      _SFD_INTEGER_CHECK("i", c38_i), 1, 5, 1, 0) - 1];
    c38_b[1] = c38_b_dopplerTY[_SFD_EML_ARRAY_BOUNDS_CHECK("dopplerTY", (int32_T)
      _SFD_INTEGER_CHECK("i", c38_i), 1, 5, 1, 0) - 1];
    c38_eml_scalar_eg(chartInstance);
    c38_eml_scalar_eg(chartInstance);
    for (c38_i9 = 0; c38_i9 < 2; c38_i9++) {
      c38_Vdv[c38_i9] = 0.0;
    }

    for (c38_i10 = 0; c38_i10 < 2; c38_i10++) {
      c38_dv2[c38_i10] = 0.0;
    }

    for (c38_i11 = 0; c38_i11 < 4; c38_i11++) {
      c38_b_a[c38_i11] = c38_a[c38_i11];
    }

    for (c38_i12 = 0; c38_i12 < 2; c38_i12++) {
      c38_b_b[c38_i12] = c38_b[c38_i12];
    }

    c38_b_eml_xgemm(chartInstance, c38_b_a, c38_b_b, c38_dv2);
    for (c38_i13 = 0; c38_i13 < 2; c38_i13++) {
      c38_Vdv[c38_i13] = c38_dv2[c38_i13];
    }

    _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 18);
    for (c38_i14 = 0; c38_i14 < 2; c38_i14++) {
      c38_Vdv[c38_i14] += c38_carVelMat[c38_i14];
    }

    _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 20);
    c38_b_dTranslationX[_SFD_EML_ARRAY_BOUNDS_CHECK("dTranslationX", (int32_T)
      _SFD_INTEGER_CHECK("i", c38_i), 1, 5, 1, 0) - 1] = c38_Vdv[0];
    _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, 21);
    c38_b_dTranslationY[_SFD_EML_ARRAY_BOUNDS_CHECK("dTranslationY", (int32_T)
      _SFD_INTEGER_CHECK("i", c38_i), 1, 5, 1, 0) - 1] = c38_Vdv[1];
    c38_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c38_sfEvent, -21);
  _SFD_SYMBOL_SCOPE_POP();
  for (c38_i15 = 0; c38_i15 < 5; c38_i15++) {
    (*chartInstance->c38_dTranslationX)[c38_i15] = c38_b_dTranslationX[c38_i15];
  }

  for (c38_i16 = 0; c38_i16 < 5; c38_i16++) {
    (*chartInstance->c38_dTranslationY)[c38_i16] = c38_b_dTranslationY[c38_i16];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 37U, chartInstance->c38_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_3_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c38_i17 = 0; c38_i17 < 5; c38_i17++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c38_dTranslationX)[c38_i17], 2U);
  }

  for (c38_i18 = 0; c38_i18 < 5; c38_i18++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c38_dopplerTX)[c38_i18], 3U);
  }

  for (c38_i19 = 0; c38_i19 < 5; c38_i19++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c38_dopplerTY)[c38_i19], 4U);
  }

  for (c38_i20 = 0; c38_i20 < 5; c38_i20++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c38_dTranslationY)[c38_i20], 5U);
  }
}

static void mdl_start_c38_Experiment_3_cs(SFc38_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc38_Experiment_3_cs
  (SFc38_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c38_machineNumber, uint32_T
  c38_chartNumber, uint32_T c38_instanceNumber)
{
  (void)c38_machineNumber;
  (void)c38_chartNumber;
  (void)c38_instanceNumber;
}

static const mxArray *c38_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData)
{
  const mxArray *c38_mxArrayOutData = NULL;
  int32_T c38_i21;
  real_T c38_b_inData[5];
  int32_T c38_i22;
  real_T c38_u[5];
  const mxArray *c38_y = NULL;
  SFc38_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc38_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c38_mxArrayOutData = NULL;
  for (c38_i21 = 0; c38_i21 < 5; c38_i21++) {
    c38_b_inData[c38_i21] = (*(real_T (*)[5])c38_inData)[c38_i21];
  }

  for (c38_i22 = 0; c38_i22 < 5; c38_i22++) {
    c38_u[c38_i22] = c38_b_inData[c38_i22];
  }

  c38_y = NULL;
  sf_mex_assign(&c38_y, sf_mex_create("y", c38_u, 0, 0U, 1U, 0U, 1, 5), false);
  sf_mex_assign(&c38_mxArrayOutData, c38_y, false);
  return c38_mxArrayOutData;
}

static void c38_emlrt_marshallIn(SFc38_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c38_b_dTranslationY, const char_T
  *c38_identifier, real_T c38_y[5])
{
  emlrtMsgIdentifier c38_thisId;
  c38_thisId.fIdentifier = c38_identifier;
  c38_thisId.fParent = NULL;
  c38_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c38_b_dTranslationY),
    &c38_thisId, c38_y);
  sf_mex_destroy(&c38_b_dTranslationY);
}

static void c38_b_emlrt_marshallIn(SFc38_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId,
  real_T c38_y[5])
{
  real_T c38_dv3[5];
  int32_T c38_i23;
  (void)chartInstance;
  sf_mex_import(c38_parentId, sf_mex_dup(c38_u), c38_dv3, 1, 0, 0U, 1, 0U, 1, 5);
  for (c38_i23 = 0; c38_i23 < 5; c38_i23++) {
    c38_y[c38_i23] = c38_dv3[c38_i23];
  }

  sf_mex_destroy(&c38_u);
}

static void c38_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData)
{
  const mxArray *c38_b_dTranslationY;
  const char_T *c38_identifier;
  emlrtMsgIdentifier c38_thisId;
  real_T c38_y[5];
  int32_T c38_i24;
  SFc38_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc38_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c38_b_dTranslationY = sf_mex_dup(c38_mxArrayInData);
  c38_identifier = c38_varName;
  c38_thisId.fIdentifier = c38_identifier;
  c38_thisId.fParent = NULL;
  c38_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c38_b_dTranslationY),
    &c38_thisId, c38_y);
  sf_mex_destroy(&c38_b_dTranslationY);
  for (c38_i24 = 0; c38_i24 < 5; c38_i24++) {
    (*(real_T (*)[5])c38_outData)[c38_i24] = c38_y[c38_i24];
  }

  sf_mex_destroy(&c38_mxArrayInData);
}

static const mxArray *c38_b_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData)
{
  const mxArray *c38_mxArrayOutData = NULL;
  real_T c38_u;
  const mxArray *c38_y = NULL;
  SFc38_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc38_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c38_mxArrayOutData = NULL;
  c38_u = *(real_T *)c38_inData;
  c38_y = NULL;
  sf_mex_assign(&c38_y, sf_mex_create("y", &c38_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c38_mxArrayOutData, c38_y, false);
  return c38_mxArrayOutData;
}

static real_T c38_c_emlrt_marshallIn(SFc38_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId)
{
  real_T c38_y;
  real_T c38_d6;
  (void)chartInstance;
  sf_mex_import(c38_parentId, sf_mex_dup(c38_u), &c38_d6, 1, 0, 0U, 0, 0U, 0);
  c38_y = c38_d6;
  sf_mex_destroy(&c38_u);
  return c38_y;
}

static void c38_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData)
{
  const mxArray *c38_nargout;
  const char_T *c38_identifier;
  emlrtMsgIdentifier c38_thisId;
  real_T c38_y;
  SFc38_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc38_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c38_nargout = sf_mex_dup(c38_mxArrayInData);
  c38_identifier = c38_varName;
  c38_thisId.fIdentifier = c38_identifier;
  c38_thisId.fParent = NULL;
  c38_y = c38_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c38_nargout),
    &c38_thisId);
  sf_mex_destroy(&c38_nargout);
  *(real_T *)c38_outData = c38_y;
  sf_mex_destroy(&c38_mxArrayInData);
}

static const mxArray *c38_c_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData)
{
  const mxArray *c38_mxArrayOutData = NULL;
  int32_T c38_i25;
  real_T c38_b_inData[2];
  int32_T c38_i26;
  real_T c38_u[2];
  const mxArray *c38_y = NULL;
  SFc38_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc38_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c38_mxArrayOutData = NULL;
  for (c38_i25 = 0; c38_i25 < 2; c38_i25++) {
    c38_b_inData[c38_i25] = (*(real_T (*)[2])c38_inData)[c38_i25];
  }

  for (c38_i26 = 0; c38_i26 < 2; c38_i26++) {
    c38_u[c38_i26] = c38_b_inData[c38_i26];
  }

  c38_y = NULL;
  sf_mex_assign(&c38_y, sf_mex_create("y", c38_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c38_mxArrayOutData, c38_y, false);
  return c38_mxArrayOutData;
}

static void c38_d_emlrt_marshallIn(SFc38_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId,
  real_T c38_y[2])
{
  real_T c38_dv4[2];
  int32_T c38_i27;
  (void)chartInstance;
  sf_mex_import(c38_parentId, sf_mex_dup(c38_u), c38_dv4, 1, 0, 0U, 1, 0U, 1, 2);
  for (c38_i27 = 0; c38_i27 < 2; c38_i27++) {
    c38_y[c38_i27] = c38_dv4[c38_i27];
  }

  sf_mex_destroy(&c38_u);
}

static void c38_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData)
{
  const mxArray *c38_Vdv;
  const char_T *c38_identifier;
  emlrtMsgIdentifier c38_thisId;
  real_T c38_y[2];
  int32_T c38_i28;
  SFc38_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc38_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c38_Vdv = sf_mex_dup(c38_mxArrayInData);
  c38_identifier = c38_varName;
  c38_thisId.fIdentifier = c38_identifier;
  c38_thisId.fParent = NULL;
  c38_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c38_Vdv), &c38_thisId, c38_y);
  sf_mex_destroy(&c38_Vdv);
  for (c38_i28 = 0; c38_i28 < 2; c38_i28++) {
    (*(real_T (*)[2])c38_outData)[c38_i28] = c38_y[c38_i28];
  }

  sf_mex_destroy(&c38_mxArrayInData);
}

static const mxArray *c38_d_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData)
{
  const mxArray *c38_mxArrayOutData = NULL;
  int32_T c38_i29;
  int32_T c38_i30;
  int32_T c38_i31;
  real_T c38_b_inData[4];
  int32_T c38_i32;
  int32_T c38_i33;
  int32_T c38_i34;
  real_T c38_u[4];
  const mxArray *c38_y = NULL;
  SFc38_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc38_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c38_mxArrayOutData = NULL;
  c38_i29 = 0;
  for (c38_i30 = 0; c38_i30 < 2; c38_i30++) {
    for (c38_i31 = 0; c38_i31 < 2; c38_i31++) {
      c38_b_inData[c38_i31 + c38_i29] = (*(real_T (*)[4])c38_inData)[c38_i31 +
        c38_i29];
    }

    c38_i29 += 2;
  }

  c38_i32 = 0;
  for (c38_i33 = 0; c38_i33 < 2; c38_i33++) {
    for (c38_i34 = 0; c38_i34 < 2; c38_i34++) {
      c38_u[c38_i34 + c38_i32] = c38_b_inData[c38_i34 + c38_i32];
    }

    c38_i32 += 2;
  }

  c38_y = NULL;
  sf_mex_assign(&c38_y, sf_mex_create("y", c38_u, 0, 0U, 1U, 0U, 2, 2, 2), false);
  sf_mex_assign(&c38_mxArrayOutData, c38_y, false);
  return c38_mxArrayOutData;
}

static void c38_e_emlrt_marshallIn(SFc38_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId,
  real_T c38_y[4])
{
  real_T c38_dv5[4];
  int32_T c38_i35;
  (void)chartInstance;
  sf_mex_import(c38_parentId, sf_mex_dup(c38_u), c38_dv5, 1, 0, 0U, 1, 0U, 2, 2,
                2);
  for (c38_i35 = 0; c38_i35 < 4; c38_i35++) {
    c38_y[c38_i35] = c38_dv5[c38_i35];
  }

  sf_mex_destroy(&c38_u);
}

static void c38_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData)
{
  const mxArray *c38_rotMat;
  const char_T *c38_identifier;
  emlrtMsgIdentifier c38_thisId;
  real_T c38_y[4];
  int32_T c38_i36;
  int32_T c38_i37;
  int32_T c38_i38;
  SFc38_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc38_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c38_rotMat = sf_mex_dup(c38_mxArrayInData);
  c38_identifier = c38_varName;
  c38_thisId.fIdentifier = c38_identifier;
  c38_thisId.fParent = NULL;
  c38_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c38_rotMat), &c38_thisId,
    c38_y);
  sf_mex_destroy(&c38_rotMat);
  c38_i36 = 0;
  for (c38_i37 = 0; c38_i37 < 2; c38_i37++) {
    for (c38_i38 = 0; c38_i38 < 2; c38_i38++) {
      (*(real_T (*)[4])c38_outData)[c38_i38 + c38_i36] = c38_y[c38_i38 + c38_i36];
    }

    c38_i36 += 2;
  }

  sf_mex_destroy(&c38_mxArrayInData);
}

const mxArray *sf_c38_Experiment_3_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c38_nameCaptureInfo = NULL;
  c38_nameCaptureInfo = NULL;
  sf_mex_assign(&c38_nameCaptureInfo, sf_mex_createstruct("structure", 2, 42, 1),
                false);
  c38_info_helper(&c38_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c38_nameCaptureInfo);
  return c38_nameCaptureInfo;
}

static void c38_info_helper(const mxArray **c38_info)
{
  const mxArray *c38_rhs0 = NULL;
  const mxArray *c38_lhs0 = NULL;
  const mxArray *c38_rhs1 = NULL;
  const mxArray *c38_lhs1 = NULL;
  const mxArray *c38_rhs2 = NULL;
  const mxArray *c38_lhs2 = NULL;
  const mxArray *c38_rhs3 = NULL;
  const mxArray *c38_lhs3 = NULL;
  const mxArray *c38_rhs4 = NULL;
  const mxArray *c38_lhs4 = NULL;
  const mxArray *c38_rhs5 = NULL;
  const mxArray *c38_lhs5 = NULL;
  const mxArray *c38_rhs6 = NULL;
  const mxArray *c38_lhs6 = NULL;
  const mxArray *c38_rhs7 = NULL;
  const mxArray *c38_lhs7 = NULL;
  const mxArray *c38_rhs8 = NULL;
  const mxArray *c38_lhs8 = NULL;
  const mxArray *c38_rhs9 = NULL;
  const mxArray *c38_lhs9 = NULL;
  const mxArray *c38_rhs10 = NULL;
  const mxArray *c38_lhs10 = NULL;
  const mxArray *c38_rhs11 = NULL;
  const mxArray *c38_lhs11 = NULL;
  const mxArray *c38_rhs12 = NULL;
  const mxArray *c38_lhs12 = NULL;
  const mxArray *c38_rhs13 = NULL;
  const mxArray *c38_lhs13 = NULL;
  const mxArray *c38_rhs14 = NULL;
  const mxArray *c38_lhs14 = NULL;
  const mxArray *c38_rhs15 = NULL;
  const mxArray *c38_lhs15 = NULL;
  const mxArray *c38_rhs16 = NULL;
  const mxArray *c38_lhs16 = NULL;
  const mxArray *c38_rhs17 = NULL;
  const mxArray *c38_lhs17 = NULL;
  const mxArray *c38_rhs18 = NULL;
  const mxArray *c38_lhs18 = NULL;
  const mxArray *c38_rhs19 = NULL;
  const mxArray *c38_lhs19 = NULL;
  const mxArray *c38_rhs20 = NULL;
  const mxArray *c38_lhs20 = NULL;
  const mxArray *c38_rhs21 = NULL;
  const mxArray *c38_lhs21 = NULL;
  const mxArray *c38_rhs22 = NULL;
  const mxArray *c38_lhs22 = NULL;
  const mxArray *c38_rhs23 = NULL;
  const mxArray *c38_lhs23 = NULL;
  const mxArray *c38_rhs24 = NULL;
  const mxArray *c38_lhs24 = NULL;
  const mxArray *c38_rhs25 = NULL;
  const mxArray *c38_lhs25 = NULL;
  const mxArray *c38_rhs26 = NULL;
  const mxArray *c38_lhs26 = NULL;
  const mxArray *c38_rhs27 = NULL;
  const mxArray *c38_lhs27 = NULL;
  const mxArray *c38_rhs28 = NULL;
  const mxArray *c38_lhs28 = NULL;
  const mxArray *c38_rhs29 = NULL;
  const mxArray *c38_lhs29 = NULL;
  const mxArray *c38_rhs30 = NULL;
  const mxArray *c38_lhs30 = NULL;
  const mxArray *c38_rhs31 = NULL;
  const mxArray *c38_lhs31 = NULL;
  const mxArray *c38_rhs32 = NULL;
  const mxArray *c38_lhs32 = NULL;
  const mxArray *c38_rhs33 = NULL;
  const mxArray *c38_lhs33 = NULL;
  const mxArray *c38_rhs34 = NULL;
  const mxArray *c38_lhs34 = NULL;
  const mxArray *c38_rhs35 = NULL;
  const mxArray *c38_lhs35 = NULL;
  const mxArray *c38_rhs36 = NULL;
  const mxArray *c38_lhs36 = NULL;
  const mxArray *c38_rhs37 = NULL;
  const mxArray *c38_lhs37 = NULL;
  const mxArray *c38_rhs38 = NULL;
  const mxArray *c38_lhs38 = NULL;
  const mxArray *c38_rhs39 = NULL;
  const mxArray *c38_lhs39 = NULL;
  const mxArray *c38_rhs40 = NULL;
  const mxArray *c38_lhs40 = NULL;
  const mxArray *c38_rhs41 = NULL;
  const mxArray *c38_lhs41 = NULL;
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("cosd"), "name", "name", 0);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1395346498U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c38_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("eml_scalar_cosd_and_sind"),
                  "name", "name", 1);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1343851978U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c38_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("isfinite"), "name", "name",
                  2);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c38_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c38_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("isinf"), "name", "name", 4);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c38_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c38_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("isnan"), "name", "name", 6);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c38_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 7);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c38_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 8);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1286840376U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c38_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 9);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1286840382U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c38_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("eml_scalar_rem90"), "name",
                  "name", 10);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1343851978U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c38_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "context", "context", 11);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("mrdivide"), "name", "name",
                  11);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c38_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 12);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 12);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c38_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 13);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("rdivide"), "name", "name",
                  13);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c38_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 14);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c38_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 15);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c38_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("eml_div"), "name", "name",
                  16);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c38_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 17);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c38_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "context", "context", 18);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("rem"), "name", "name", 18);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c38_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 19);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c38_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 20);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c38_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 21);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c38_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 22);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c38_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 23);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 23);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c38_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_rem90.m"),
                  "context", "context", 24);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("abs"), "name", "name", 24);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c38_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 25);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c38_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 26);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c38_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(""), "context", "context", 27);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("sind"), "name", "name", 27);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sind.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1395346504U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c38_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sind.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("eml_scalar_cosd_and_sind"),
                  "name", "name", 28);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd_and_sind.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1343851978U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c38_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(""), "context", "context", 29);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("length"), "name", "name", 29);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1303167806U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c38_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(""), "context", "context", 30);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 30);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c38_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 31);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 31);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c38_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 32);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 32);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c38_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 33);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 33);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c38_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 34);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  34);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1376002290U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c38_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 35);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c38_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 36);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c38_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 37);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 37);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c38_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 38);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 38);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c38_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 39);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 39);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c38_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 40);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 40);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c38_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 41);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 41);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c38_info, c38_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c38_info, c38_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c38_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c38_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c38_info, sf_mex_duplicatearraysafe(&c38_lhs41), "lhs", "lhs",
                  41);
  sf_mex_destroy(&c38_rhs0);
  sf_mex_destroy(&c38_lhs0);
  sf_mex_destroy(&c38_rhs1);
  sf_mex_destroy(&c38_lhs1);
  sf_mex_destroy(&c38_rhs2);
  sf_mex_destroy(&c38_lhs2);
  sf_mex_destroy(&c38_rhs3);
  sf_mex_destroy(&c38_lhs3);
  sf_mex_destroy(&c38_rhs4);
  sf_mex_destroy(&c38_lhs4);
  sf_mex_destroy(&c38_rhs5);
  sf_mex_destroy(&c38_lhs5);
  sf_mex_destroy(&c38_rhs6);
  sf_mex_destroy(&c38_lhs6);
  sf_mex_destroy(&c38_rhs7);
  sf_mex_destroy(&c38_lhs7);
  sf_mex_destroy(&c38_rhs8);
  sf_mex_destroy(&c38_lhs8);
  sf_mex_destroy(&c38_rhs9);
  sf_mex_destroy(&c38_lhs9);
  sf_mex_destroy(&c38_rhs10);
  sf_mex_destroy(&c38_lhs10);
  sf_mex_destroy(&c38_rhs11);
  sf_mex_destroy(&c38_lhs11);
  sf_mex_destroy(&c38_rhs12);
  sf_mex_destroy(&c38_lhs12);
  sf_mex_destroy(&c38_rhs13);
  sf_mex_destroy(&c38_lhs13);
  sf_mex_destroy(&c38_rhs14);
  sf_mex_destroy(&c38_lhs14);
  sf_mex_destroy(&c38_rhs15);
  sf_mex_destroy(&c38_lhs15);
  sf_mex_destroy(&c38_rhs16);
  sf_mex_destroy(&c38_lhs16);
  sf_mex_destroy(&c38_rhs17);
  sf_mex_destroy(&c38_lhs17);
  sf_mex_destroy(&c38_rhs18);
  sf_mex_destroy(&c38_lhs18);
  sf_mex_destroy(&c38_rhs19);
  sf_mex_destroy(&c38_lhs19);
  sf_mex_destroy(&c38_rhs20);
  sf_mex_destroy(&c38_lhs20);
  sf_mex_destroy(&c38_rhs21);
  sf_mex_destroy(&c38_lhs21);
  sf_mex_destroy(&c38_rhs22);
  sf_mex_destroy(&c38_lhs22);
  sf_mex_destroy(&c38_rhs23);
  sf_mex_destroy(&c38_lhs23);
  sf_mex_destroy(&c38_rhs24);
  sf_mex_destroy(&c38_lhs24);
  sf_mex_destroy(&c38_rhs25);
  sf_mex_destroy(&c38_lhs25);
  sf_mex_destroy(&c38_rhs26);
  sf_mex_destroy(&c38_lhs26);
  sf_mex_destroy(&c38_rhs27);
  sf_mex_destroy(&c38_lhs27);
  sf_mex_destroy(&c38_rhs28);
  sf_mex_destroy(&c38_lhs28);
  sf_mex_destroy(&c38_rhs29);
  sf_mex_destroy(&c38_lhs29);
  sf_mex_destroy(&c38_rhs30);
  sf_mex_destroy(&c38_lhs30);
  sf_mex_destroy(&c38_rhs31);
  sf_mex_destroy(&c38_lhs31);
  sf_mex_destroy(&c38_rhs32);
  sf_mex_destroy(&c38_lhs32);
  sf_mex_destroy(&c38_rhs33);
  sf_mex_destroy(&c38_lhs33);
  sf_mex_destroy(&c38_rhs34);
  sf_mex_destroy(&c38_lhs34);
  sf_mex_destroy(&c38_rhs35);
  sf_mex_destroy(&c38_lhs35);
  sf_mex_destroy(&c38_rhs36);
  sf_mex_destroy(&c38_lhs36);
  sf_mex_destroy(&c38_rhs37);
  sf_mex_destroy(&c38_lhs37);
  sf_mex_destroy(&c38_rhs38);
  sf_mex_destroy(&c38_lhs38);
  sf_mex_destroy(&c38_rhs39);
  sf_mex_destroy(&c38_lhs39);
  sf_mex_destroy(&c38_rhs40);
  sf_mex_destroy(&c38_lhs40);
  sf_mex_destroy(&c38_rhs41);
  sf_mex_destroy(&c38_lhs41);
}

static const mxArray *c38_emlrt_marshallOut(const char * c38_u)
{
  const mxArray *c38_y = NULL;
  c38_y = NULL;
  sf_mex_assign(&c38_y, sf_mex_create("y", c38_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c38_u)), false);
  return c38_y;
}

static const mxArray *c38_b_emlrt_marshallOut(const uint32_T c38_u)
{
  const mxArray *c38_y = NULL;
  c38_y = NULL;
  sf_mex_assign(&c38_y, sf_mex_create("y", &c38_u, 7, 0U, 0U, 0U, 0), false);
  return c38_y;
}

static real_T c38_cosd(SFc38_Experiment_3_csInstanceStruct *chartInstance,
  real_T c38_x)
{
  real_T c38_b_x;
  c38_b_x = c38_x;
  c38_b_cosd(chartInstance, &c38_b_x);
  return c38_b_x;
}

static boolean_T c38_isfinite(SFc38_Experiment_3_csInstanceStruct *chartInstance,
  real_T c38_x)
{
  real_T c38_b_x;
  boolean_T c38_b_b;
  boolean_T c38_b0;
  real_T c38_c_x;
  boolean_T c38_c_b;
  boolean_T c38_b1;
  (void)chartInstance;
  c38_b_x = c38_x;
  c38_b_b = muDoubleScalarIsInf(c38_b_x);
  c38_b0 = !c38_b_b;
  c38_c_x = c38_x;
  c38_c_b = muDoubleScalarIsNaN(c38_c_x);
  c38_b1 = !c38_c_b;
  return c38_b0 && c38_b1;
}

static real_T c38_sind(SFc38_Experiment_3_csInstanceStruct *chartInstance,
  real_T c38_x)
{
  real_T c38_b_x;
  c38_b_x = c38_x;
  c38_b_sind(chartInstance, &c38_b_x);
  return c38_b_x;
}

static void c38_eml_scalar_eg(SFc38_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c38_eml_xgemm(SFc38_Experiment_3_csInstanceStruct *chartInstance,
  real_T c38_A[4], real_T c38_B[2], real_T c38_C[2], real_T c38_b_C[2])
{
  int32_T c38_i39;
  int32_T c38_i40;
  real_T c38_b_A[4];
  int32_T c38_i41;
  real_T c38_b_B[2];
  for (c38_i39 = 0; c38_i39 < 2; c38_i39++) {
    c38_b_C[c38_i39] = c38_C[c38_i39];
  }

  for (c38_i40 = 0; c38_i40 < 4; c38_i40++) {
    c38_b_A[c38_i40] = c38_A[c38_i40];
  }

  for (c38_i41 = 0; c38_i41 < 2; c38_i41++) {
    c38_b_B[c38_i41] = c38_B[c38_i41];
  }

  c38_b_eml_xgemm(chartInstance, c38_b_A, c38_b_B, c38_b_C);
}

static const mxArray *c38_e_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData)
{
  const mxArray *c38_mxArrayOutData = NULL;
  int32_T c38_u;
  const mxArray *c38_y = NULL;
  SFc38_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc38_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c38_mxArrayOutData = NULL;
  c38_u = *(int32_T *)c38_inData;
  c38_y = NULL;
  sf_mex_assign(&c38_y, sf_mex_create("y", &c38_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c38_mxArrayOutData, c38_y, false);
  return c38_mxArrayOutData;
}

static int32_T c38_f_emlrt_marshallIn(SFc38_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId)
{
  int32_T c38_y;
  int32_T c38_i42;
  (void)chartInstance;
  sf_mex_import(c38_parentId, sf_mex_dup(c38_u), &c38_i42, 1, 6, 0U, 0, 0U, 0);
  c38_y = c38_i42;
  sf_mex_destroy(&c38_u);
  return c38_y;
}

static void c38_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData)
{
  const mxArray *c38_b_sfEvent;
  const char_T *c38_identifier;
  emlrtMsgIdentifier c38_thisId;
  int32_T c38_y;
  SFc38_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc38_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c38_b_sfEvent = sf_mex_dup(c38_mxArrayInData);
  c38_identifier = c38_varName;
  c38_thisId.fIdentifier = c38_identifier;
  c38_thisId.fParent = NULL;
  c38_y = c38_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c38_b_sfEvent),
    &c38_thisId);
  sf_mex_destroy(&c38_b_sfEvent);
  *(int32_T *)c38_outData = c38_y;
  sf_mex_destroy(&c38_mxArrayInData);
}

static uint8_T c38_g_emlrt_marshallIn(SFc38_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c38_b_is_active_c38_Experiment_3_cs, const
  char_T *c38_identifier)
{
  uint8_T c38_y;
  emlrtMsgIdentifier c38_thisId;
  c38_thisId.fIdentifier = c38_identifier;
  c38_thisId.fParent = NULL;
  c38_y = c38_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c38_b_is_active_c38_Experiment_3_cs), &c38_thisId);
  sf_mex_destroy(&c38_b_is_active_c38_Experiment_3_cs);
  return c38_y;
}

static uint8_T c38_h_emlrt_marshallIn(SFc38_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId)
{
  uint8_T c38_y;
  uint8_T c38_u0;
  (void)chartInstance;
  sf_mex_import(c38_parentId, sf_mex_dup(c38_u), &c38_u0, 1, 3, 0U, 0, 0U, 0);
  c38_y = c38_u0;
  sf_mex_destroy(&c38_u);
  return c38_y;
}

static void c38_b_cosd(SFc38_Experiment_3_csInstanceStruct *chartInstance,
  real_T *c38_x)
{
  real_T c38_b_x;
  real_T c38_c_x;
  real_T c38_d_x;
  real_T c38_e_x;
  real_T c38_xk;
  real_T c38_f_x;
  real_T c38_g_x;
  real_T c38_absx;
  real_T c38_h_x;
  real_T c38_i_x;
  int8_T c38_n;
  int8_T c38_b_n;
  c38_b_x = *c38_x;
  if (!c38_isfinite(chartInstance, c38_b_x)) {
    *c38_x = rtNaN;
  } else {
    c38_c_x = c38_b_x;
    c38_d_x = c38_c_x;
    c38_e_x = c38_d_x;
    c38_xk = c38_e_x;
    c38_d_x = muDoubleScalarRem(c38_xk, 360.0);
    c38_f_x = c38_d_x;
    c38_g_x = c38_f_x;
    c38_absx = muDoubleScalarAbs(c38_g_x);
    if (c38_absx > 180.0) {
      if (c38_d_x > 0.0) {
        c38_d_x -= 360.0;
      } else {
        c38_d_x += 360.0;
      }

      c38_h_x = c38_d_x;
      c38_i_x = c38_h_x;
      c38_absx = muDoubleScalarAbs(c38_i_x);
    }

    if (c38_absx <= 45.0) {
      c38_d_x *= 0.017453292519943295;
      c38_n = 0;
    } else if (c38_absx <= 135.0) {
      if (c38_d_x > 0.0) {
        c38_d_x = 0.017453292519943295 * (c38_d_x - 90.0);
        c38_n = 1;
      } else {
        c38_d_x = 0.017453292519943295 * (c38_d_x + 90.0);
        c38_n = -1;
      }
    } else if (c38_d_x > 0.0) {
      c38_d_x = 0.017453292519943295 * (c38_d_x - 180.0);
      c38_n = 2;
    } else {
      c38_d_x = 0.017453292519943295 * (c38_d_x + 180.0);
      c38_n = -2;
    }

    c38_b_n = c38_n;
    c38_b_x = c38_d_x;
    if ((real_T)c38_b_n == 0.0) {
      *c38_x = muDoubleScalarCos(c38_b_x);
    } else if ((real_T)c38_b_n == 1.0) {
      *c38_x = -muDoubleScalarSin(c38_b_x);
    } else if ((real_T)c38_b_n == -1.0) {
      *c38_x = muDoubleScalarSin(c38_b_x);
    } else {
      *c38_x = -muDoubleScalarCos(c38_b_x);
    }
  }
}

static void c38_b_sind(SFc38_Experiment_3_csInstanceStruct *chartInstance,
  real_T *c38_x)
{
  real_T c38_b_x;
  real_T c38_d7;
  real_T c38_c_x;
  real_T c38_d_x;
  real_T c38_e_x;
  real_T c38_xk;
  real_T c38_f_x;
  real_T c38_g_x;
  real_T c38_absx;
  real_T c38_h_x;
  real_T c38_i_x;
  int8_T c38_n;
  int8_T c38_b_n;
  c38_b_x = *c38_x;
  if (!c38_isfinite(chartInstance, c38_b_x)) {
    c38_d7 = rtNaN;
  } else {
    c38_c_x = c38_b_x;
    c38_d_x = c38_c_x;
    c38_e_x = c38_d_x;
    c38_xk = c38_e_x;
    c38_d_x = muDoubleScalarRem(c38_xk, 360.0);
    c38_f_x = c38_d_x;
    c38_g_x = c38_f_x;
    c38_absx = muDoubleScalarAbs(c38_g_x);
    if (c38_absx > 180.0) {
      if (c38_d_x > 0.0) {
        c38_d_x -= 360.0;
      } else {
        c38_d_x += 360.0;
      }

      c38_h_x = c38_d_x;
      c38_i_x = c38_h_x;
      c38_absx = muDoubleScalarAbs(c38_i_x);
    }

    if (c38_absx <= 45.0) {
      c38_d_x *= 0.017453292519943295;
      c38_n = 0;
    } else if (c38_absx <= 135.0) {
      if (c38_d_x > 0.0) {
        c38_d_x = 0.017453292519943295 * (c38_d_x - 90.0);
        c38_n = 1;
      } else {
        c38_d_x = 0.017453292519943295 * (c38_d_x + 90.0);
        c38_n = -1;
      }
    } else if (c38_d_x > 0.0) {
      c38_d_x = 0.017453292519943295 * (c38_d_x - 180.0);
      c38_n = 2;
    } else {
      c38_d_x = 0.017453292519943295 * (c38_d_x + 180.0);
      c38_n = -2;
    }

    c38_b_n = c38_n;
    c38_b_x = c38_d_x;
    if ((real_T)c38_b_n == 0.0) {
      c38_d7 = muDoubleScalarSin(c38_b_x);
    } else if ((real_T)c38_b_n == 1.0) {
      c38_d7 = muDoubleScalarCos(c38_b_x);
    } else if ((real_T)c38_b_n == -1.0) {
      c38_d7 = -muDoubleScalarCos(c38_b_x);
    } else {
      c38_d7 = -muDoubleScalarSin(c38_b_x);
    }
  }

  *c38_x = c38_d7;
}

static void c38_b_eml_xgemm(SFc38_Experiment_3_csInstanceStruct *chartInstance,
  real_T c38_A[4], real_T c38_B[2], real_T c38_C[2])
{
  int32_T c38_i43;
  int32_T c38_i44;
  int32_T c38_i45;
  (void)chartInstance;
  for (c38_i43 = 0; c38_i43 < 2; c38_i43++) {
    c38_C[c38_i43] = 0.0;
    c38_i44 = 0;
    for (c38_i45 = 0; c38_i45 < 2; c38_i45++) {
      c38_C[c38_i43] += c38_A[c38_i44 + c38_i43] * c38_B[c38_i45];
      c38_i44 += 2;
    }
  }
}

static void init_dsm_address_info(SFc38_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc38_Experiment_3_csInstanceStruct
  *chartInstance)
{
  chartInstance->c38_carAngle = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c38_carVelocity = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c38_dTranslationX = (real_T (*)[5])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c38_dopplerTX = (real_T (*)[5])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c38_dopplerTY = (real_T (*)[5])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c38_dTranslationY = (real_T (*)[5])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 2);
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

void sf_c38_Experiment_3_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2383740784U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2272804787U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3341600387U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1636001605U);
}

mxArray* sf_c38_Experiment_3_cs_get_post_codegen_info(void);
mxArray *sf_c38_Experiment_3_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("KmgsANRob3yzyyhxwv88NE");
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c38_Experiment_3_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c38_Experiment_3_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c38_Experiment_3_cs_jit_fallback_info(void)
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

mxArray *sf_c38_Experiment_3_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c38_Experiment_3_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c38_Experiment_3_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"dTranslationX\",},{M[1],M[8],T\"dTranslationY\",},{M[8],M[0],T\"is_active_c38_Experiment_3_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c38_Experiment_3_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc38_Experiment_3_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc38_Experiment_3_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_3_csMachineNumber_,
           38,
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,566);
        _SFD_CV_INIT_EML_FOR(0,1,0,384,412,566);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c38_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c38_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c38_sf_marshallOut,(MexInFcnForType)
            c38_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c38_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c38_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c38_sf_marshallOut,(MexInFcnForType)
            c38_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c38_carAngle);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c38_carVelocity);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c38_dTranslationX);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c38_dopplerTX);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c38_dopplerTY);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c38_dTranslationY);
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
  return "nEsgHMOD9crvkR8S0DghPF";
}

static void sf_opaque_initialize_c38_Experiment_3_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc38_Experiment_3_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c38_Experiment_3_cs((SFc38_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
  initialize_c38_Experiment_3_cs((SFc38_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c38_Experiment_3_cs(void *chartInstanceVar)
{
  enable_c38_Experiment_3_cs((SFc38_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c38_Experiment_3_cs(void *chartInstanceVar)
{
  disable_c38_Experiment_3_cs((SFc38_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c38_Experiment_3_cs(void *chartInstanceVar)
{
  sf_gateway_c38_Experiment_3_cs((SFc38_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c38_Experiment_3_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c38_Experiment_3_cs((SFc38_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c38_Experiment_3_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c38_Experiment_3_cs((SFc38_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c38_Experiment_3_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc38_Experiment_3_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_3_cs_optimization_info();
    }

    finalize_c38_Experiment_3_cs((SFc38_Experiment_3_csInstanceStruct*)
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
  initSimStructsc38_Experiment_3_cs((SFc38_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c38_Experiment_3_cs(SimStruct *S)
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
    initialize_params_c38_Experiment_3_cs((SFc38_Experiment_3_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c38_Experiment_3_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Experiment_3_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      38);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,38,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,38,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,38);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,38,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,38,2);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,38);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1761705019U));
  ssSetChecksum1(S,(274799255U));
  ssSetChecksum2(S,(1355525808U));
  ssSetChecksum3(S,(3000852090U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c38_Experiment_3_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c38_Experiment_3_cs(SimStruct *S)
{
  SFc38_Experiment_3_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc38_Experiment_3_csInstanceStruct *)utMalloc(sizeof
    (SFc38_Experiment_3_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc38_Experiment_3_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c38_Experiment_3_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c38_Experiment_3_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c38_Experiment_3_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c38_Experiment_3_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c38_Experiment_3_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c38_Experiment_3_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c38_Experiment_3_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c38_Experiment_3_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c38_Experiment_3_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c38_Experiment_3_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c38_Experiment_3_cs;
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

void c38_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c38_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c38_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c38_Experiment_3_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c38_Experiment_3_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
