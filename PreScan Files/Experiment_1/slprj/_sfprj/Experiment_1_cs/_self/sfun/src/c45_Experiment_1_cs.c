/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_1_cs_sfun.h"
#include "c45_Experiment_1_cs.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Experiment_1_cs_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c45_b_TISdet                   (32.0)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c45_debug_family_names[12] = { "a", "i", "j", "TISdet",
  "nargin", "nargout", "PosObj_subim", "Centroid_subim", "BBox", "CentAlarms",
  "alarms", "BBox_det" };

/* Function Declarations */
static void initialize_c45_Experiment_1_cs(SFc45_Experiment_1_csInstanceStruct
  *chartInstance);
static void initialize_params_c45_Experiment_1_cs
  (SFc45_Experiment_1_csInstanceStruct *chartInstance);
static void enable_c45_Experiment_1_cs(SFc45_Experiment_1_csInstanceStruct
  *chartInstance);
static void disable_c45_Experiment_1_cs(SFc45_Experiment_1_csInstanceStruct
  *chartInstance);
static void c45_update_debugger_state_c45_Experiment_1_cs
  (SFc45_Experiment_1_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c45_Experiment_1_cs
  (SFc45_Experiment_1_csInstanceStruct *chartInstance);
static void set_sim_state_c45_Experiment_1_cs
  (SFc45_Experiment_1_csInstanceStruct *chartInstance, const mxArray *c45_st);
static void finalize_c45_Experiment_1_cs(SFc45_Experiment_1_csInstanceStruct
  *chartInstance);
static void sf_gateway_c45_Experiment_1_cs(SFc45_Experiment_1_csInstanceStruct
  *chartInstance);
static void mdl_start_c45_Experiment_1_cs(SFc45_Experiment_1_csInstanceStruct
  *chartInstance);
static void initSimStructsc45_Experiment_1_cs
  (SFc45_Experiment_1_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c45_machineNumber, uint32_T
  c45_chartNumber, uint32_T c45_instanceNumber);
static const mxArray *c45_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData);
static void c45_emlrt_marshallIn(SFc45_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c45_b_BBox_det, const char_T *c45_identifier,
  int32_T c45_y[400]);
static void c45_b_emlrt_marshallIn(SFc45_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId,
  int32_T c45_y[400]);
static void c45_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData);
static const mxArray *c45_b_sf_marshallOut(void *chartInstanceVoid, real_T
  c45_inData_data[], int32_T *c45_inData_sizes);
static void c45_c_emlrt_marshallIn(SFc45_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c45_alarms, const char_T *c45_identifier,
  real_T c45_y_data[], int32_T *c45_y_sizes);
static void c45_d_emlrt_marshallIn(SFc45_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId,
  real_T c45_y_data[], int32_T *c45_y_sizes);
static void c45_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, real_T c45_outData_data[],
  int32_T *c45_outData_sizes);
static const mxArray *c45_c_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData);
static void c45_e_emlrt_marshallIn(SFc45_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c45_b_CentAlarms, const char_T *c45_identifier,
  int32_T c45_y[64]);
static void c45_f_emlrt_marshallIn(SFc45_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId,
  int32_T c45_y[64]);
static void c45_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData);
static const mxArray *c45_d_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData);
static const mxArray *c45_e_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData);
static const mxArray *c45_f_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData);
static real_T c45_g_emlrt_marshallIn(SFc45_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId);
static void c45_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData);
static void c45_info_helper(const mxArray **c45_info);
static const mxArray *c45_emlrt_marshallOut(const char * c45_u);
static const mxArray *c45_b_emlrt_marshallOut(const uint32_T c45_u);
static const mxArray *c45_g_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData);
static int32_T c45_h_emlrt_marshallIn(SFc45_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId);
static void c45_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData);
static uint8_T c45_i_emlrt_marshallIn(SFc45_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c45_b_is_active_c45_Experiment_1_cs, const
  char_T *c45_identifier);
static uint8_T c45_j_emlrt_marshallIn(SFc45_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId);
static void init_dsm_address_info(SFc45_Experiment_1_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc45_Experiment_1_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c45_Experiment_1_cs(SFc45_Experiment_1_csInstanceStruct
  *chartInstance)
{
  chartInstance->c45_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c45_is_active_c45_Experiment_1_cs = 0U;
}

static void initialize_params_c45_Experiment_1_cs
  (SFc45_Experiment_1_csInstanceStruct *chartInstance)
{
  real_T c45_d0;
  sf_mex_import_named("TISdet", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c45_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c45_TISdet = c45_d0;
}

static void enable_c45_Experiment_1_cs(SFc45_Experiment_1_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c45_Experiment_1_cs(SFc45_Experiment_1_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c45_update_debugger_state_c45_Experiment_1_cs
  (SFc45_Experiment_1_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c45_Experiment_1_cs
  (SFc45_Experiment_1_csInstanceStruct *chartInstance)
{
  const mxArray *c45_st;
  const mxArray *c45_y = NULL;
  int32_T c45_i0;
  int32_T c45_u[400];
  const mxArray *c45_b_y = NULL;
  int32_T c45_i1;
  int32_T c45_b_u[64];
  const mxArray *c45_c_y = NULL;
  int32_T c45_u_sizes;
  int32_T c45_loop_ub;
  int32_T c45_i2;
  real_T c45_u_data[32];
  const mxArray *c45_d_y = NULL;
  uint8_T c45_hoistedGlobal;
  uint8_T c45_c_u;
  const mxArray *c45_e_y = NULL;
  c45_st = NULL;
  c45_st = NULL;
  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_createcellmatrix(4, 1), false);
  for (c45_i0 = 0; c45_i0 < 400; c45_i0++) {
    c45_u[c45_i0] = (*chartInstance->c45_BBox_det)[c45_i0];
  }

  c45_b_y = NULL;
  sf_mex_assign(&c45_b_y, sf_mex_create("y", c45_u, 6, 0U, 1U, 0U, 2, 4, 100),
                false);
  sf_mex_setcell(c45_y, 0, c45_b_y);
  for (c45_i1 = 0; c45_i1 < 64; c45_i1++) {
    c45_b_u[c45_i1] = (*chartInstance->c45_CentAlarms)[c45_i1];
  }

  c45_c_y = NULL;
  sf_mex_assign(&c45_c_y, sf_mex_create("y", c45_b_u, 6, 0U, 1U, 0U, 2, 2, 32),
                false);
  sf_mex_setcell(c45_y, 1, c45_c_y);
  c45_u_sizes = *chartInstance->c45_alarms_sizes;
  c45_loop_ub = *chartInstance->c45_alarms_sizes - 1;
  for (c45_i2 = 0; c45_i2 <= c45_loop_ub; c45_i2++) {
    c45_u_data[c45_i2] = (*chartInstance->c45_alarms_data)[c45_i2];
  }

  c45_d_y = NULL;
  sf_mex_assign(&c45_d_y, sf_mex_create("y", c45_u_data, 0, 0U, 1U, 0U, 1,
    c45_u_sizes), false);
  sf_mex_setcell(c45_y, 2, c45_d_y);
  c45_hoistedGlobal = chartInstance->c45_is_active_c45_Experiment_1_cs;
  c45_c_u = c45_hoistedGlobal;
  c45_e_y = NULL;
  sf_mex_assign(&c45_e_y, sf_mex_create("y", &c45_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c45_y, 3, c45_e_y);
  sf_mex_assign(&c45_st, c45_y, false);
  return c45_st;
}

static void set_sim_state_c45_Experiment_1_cs
  (SFc45_Experiment_1_csInstanceStruct *chartInstance, const mxArray *c45_st)
{
  const mxArray *c45_u;
  int32_T c45_iv0[400];
  int32_T c45_i3;
  int32_T c45_iv1[64];
  int32_T c45_i4;
  int32_T c45_tmp_sizes;
  real_T c45_tmp_data[32];
  int32_T c45_loop_ub;
  int32_T c45_i5;
  chartInstance->c45_doneDoubleBufferReInit = true;
  c45_u = sf_mex_dup(c45_st);
  c45_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c45_u, 0)),
                       "BBox_det", c45_iv0);
  for (c45_i3 = 0; c45_i3 < 400; c45_i3++) {
    (*chartInstance->c45_BBox_det)[c45_i3] = c45_iv0[c45_i3];
  }

  c45_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c45_u, 1)),
    "CentAlarms", c45_iv1);
  for (c45_i4 = 0; c45_i4 < 64; c45_i4++) {
    (*chartInstance->c45_CentAlarms)[c45_i4] = c45_iv1[c45_i4];
  }

  c45_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c45_u, 2)),
    "alarms", c45_tmp_data, &c45_tmp_sizes);
  *chartInstance->c45_alarms_sizes = c45_tmp_sizes;
  c45_loop_ub = c45_tmp_sizes - 1;
  for (c45_i5 = 0; c45_i5 <= c45_loop_ub; c45_i5++) {
    (*chartInstance->c45_alarms_data)[c45_i5] = c45_tmp_data[c45_i5];
  }

  chartInstance->c45_is_active_c45_Experiment_1_cs = c45_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c45_u, 3)),
     "is_active_c45_Experiment_1_cs");
  sf_mex_destroy(&c45_u);
  c45_update_debugger_state_c45_Experiment_1_cs(chartInstance);
  sf_mex_destroy(&c45_st);
}

static void finalize_c45_Experiment_1_cs(SFc45_Experiment_1_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c45_Experiment_1_cs(SFc45_Experiment_1_csInstanceStruct
  *chartInstance)
{
  int32_T c45_i6;
  real_T c45_b_PosObj_subim[64];
  int32_T c45_i7;
  int32_T c45_b_Centroid_subim[200];
  int32_T c45_i8;
  int32_T c45_b_BBox[400];
  uint32_T c45_debug_family_var_map[12];
  real_T c45_a;
  real_T c45_i;
  real_T c45_j;
  real_T c45_c_TISdet;
  real_T c45_nargin = 4.0;
  real_T c45_nargout = 3.0;
  int32_T c45_b_CentAlarms[64];
  int32_T c45_b_alarms_sizes;
  real_T c45_b_alarms_data[32];
  int32_T c45_b_BBox_det[400];
  int32_T c45_i9;
  int32_T c45_i10;
  real_T c45_dv0[32];
  int32_T c45_i11;
  int32_T c45_i12;
  int32_T c45_b_i;
  int32_T c45_b_j;
  real_T c45_d1;
  int32_T c45_i13;
  int32_T c45_x;
  int32_T c45_b_x;
  int32_T c45_i14;
  int32_T c45_saturatedUnaryMinus;
  int32_T c45_y;
  real_T c45_d2;
  real_T c45_d3;
  int32_T c45_i15;
  int32_T c45_c_x;
  int32_T c45_d_x;
  int32_T c45_i16;
  int32_T c45_b_saturatedUnaryMinus;
  int32_T c45_b_y;
  real_T c45_d4;
  int32_T c45_tmp_sizes[2];
  int32_T c45_b_a;
  int32_T c45_c_i;
  int32_T c45_i17;
  real_T c45_d5;
  int32_T c45_i18;
  int32_T c45_c_a;
  int32_T c45_d_i;
  int32_T c45_i19;
  int32_T c45_i20;
  int32_T c45_loop_ub;
  int32_T c45_i21;
  int32_T c45_i22;
  int32_T c45_i23;
  int32_T c45_i24;
  int32_T c45_i25;
  int32_T c45_b_loop_ub;
  int32_T c45_i26;
  int32_T c45_i27;
  int32_T c45_i28;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 19U, chartInstance->c45_sfEvent);
  chartInstance->c45_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 19U, chartInstance->c45_sfEvent);
  for (c45_i6 = 0; c45_i6 < 64; c45_i6++) {
    c45_b_PosObj_subim[c45_i6] = (*chartInstance->c45_PosObj_subim)[c45_i6];
  }

  for (c45_i7 = 0; c45_i7 < 200; c45_i7++) {
    c45_b_Centroid_subim[c45_i7] = (*chartInstance->c45_Centroid_subim)[c45_i7];
  }

  for (c45_i8 = 0; c45_i8 < 400; c45_i8++) {
    c45_b_BBox[c45_i8] = (*chartInstance->c45_BBox)[c45_i8];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c45_debug_family_names,
    c45_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_a, 0U, c45_f_sf_marshallOut,
    c45_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_i, 1U, c45_f_sf_marshallOut,
    c45_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_j, 2U, c45_f_sf_marshallOut,
    c45_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_c_TISdet, 3U, c45_f_sf_marshallOut,
    c45_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_nargin, 4U, c45_f_sf_marshallOut,
    c45_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_nargout, 5U, c45_f_sf_marshallOut,
    c45_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c45_b_PosObj_subim, 6U, c45_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c45_b_Centroid_subim, 7U, c45_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c45_b_BBox, 8U, c45_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c45_b_CentAlarms, 9U,
    c45_c_sf_marshallOut, c45_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c45_b_alarms_data, (const int32_T *)
    &c45_b_alarms_sizes, NULL, 0, 10, (void *)c45_b_sf_marshallOut, (void *)
    c45_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c45_b_BBox_det, 11U, c45_sf_marshallOut,
    c45_sf_marshallIn);
  c45_c_TISdet = 32.0;
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 3);
  for (c45_i9 = 0; c45_i9 < 64; c45_i9++) {
    c45_b_CentAlarms[c45_i9] = 0;
  }

  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 4);
  for (c45_i10 = 0; c45_i10 < 32; c45_i10++) {
    c45_dv0[c45_i10] = 0.0;
  }

  c45_b_alarms_sizes = 32;
  for (c45_i11 = 0; c45_i11 < 32; c45_i11++) {
    c45_b_alarms_data[c45_i11] = c45_dv0[c45_i11];
  }

  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 5);
  for (c45_i12 = 0; c45_i12 < 400; c45_i12++) {
    c45_b_BBox_det[c45_i12] = 0;
  }

  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 6);
  c45_a = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 7);
  c45_i = 1.0;
  c45_b_i = 0;
  while (c45_b_i < 32) {
    c45_i = 1.0 + (real_T)c45_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 8);
    c45_j = 1.0;
    c45_b_j = 0;
    while (c45_b_j < 100) {
      c45_j = 1.0 + (real_T)c45_b_j;
      CV_EML_FOR(0, 1, 1, 1);
      _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 9);
      guard1 = false;
      if (CV_EML_COND(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, (real_T)
            c45_b_Centroid_subim[((int32_T)c45_j - 1) << 1], 0.0, -1, 1U,
            (real_T)c45_b_Centroid_subim[((int32_T)c45_j - 1) << 1] != 0.0))) {
        guard1 = true;
      } else if (CV_EML_COND(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, (real_T)
                   c45_b_Centroid_subim[1 + (((int32_T)c45_j - 1) << 1)], 0.0,
                   -1, 1U, (real_T)c45_b_Centroid_subim[1 + (((int32_T)c45_j - 1)
        << 1)] != 0.0))) {
        guard1 = true;
      } else {
        CV_EML_MCDC(0, 1, 0, false);
        CV_EML_IF(0, 1, 0, false);
      }

      if (guard1 == true) {
        CV_EML_MCDC(0, 1, 0, true);
        CV_EML_IF(0, 1, 0, true);
        _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 10);
        c45_d1 = muDoubleScalarRound((real_T)c45_b_Centroid_subim[1 + (((int32_T)
          c45_j - 1) << 1)] - c45_b_PosObj_subim[1 + (((int32_T)c45_i - 1) << 1)]);
        if (c45_d1 < 2.147483648E+9) {
          if (CV_SATURATION_EVAL(4, 0, 1, 1, c45_d1 >= -2.147483648E+9)) {
            c45_i13 = (int32_T)c45_d1;
          } else {
            c45_i13 = MIN_int32_T;
          }
        } else if (CV_SATURATION_EVAL(4, 0, 1, 0, c45_d1 >= 2.147483648E+9)) {
          c45_i13 = MAX_int32_T;
        } else {
          c45_i13 = 0;
        }

        c45_x = c45_i13;
        c45_b_x = c45_x;
        c45_i14 = c45_b_x;
        if (CV_SATURATION_EVAL(4, 0, 0, 0, c45_i14 <= MIN_int32_T)) {
          c45_saturatedUnaryMinus = MAX_int32_T;
        } else {
          c45_saturatedUnaryMinus = -c45_i14;
        }

        if ((real_T)c45_b_x < 0.0) {
          c45_y = c45_saturatedUnaryMinus;
        } else {
          c45_y = c45_b_x;
        }

        c45_d2 = (real_T)c45_y;
        guard2 = false;
        if (CV_EML_COND(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 2, c45_d2, 15.0, -1,
              2U, c45_d2 < 15.0))) {
          guard2 = true;
        } else {
          c45_d3 = muDoubleScalarRound((real_T)c45_b_Centroid_subim[((int32_T)
            c45_j - 1) << 1] - c45_b_PosObj_subim[((int32_T)c45_i - 1) << 1]);
          if (c45_d3 < 2.147483648E+9) {
            if (CV_SATURATION_EVAL(4, 0, 3, 1, c45_d3 >= -2.147483648E+9)) {
              c45_i15 = (int32_T)c45_d3;
            } else {
              c45_i15 = MIN_int32_T;
            }
          } else if (CV_SATURATION_EVAL(4, 0, 3, 0, c45_d3 >= 2.147483648E+9)) {
            c45_i15 = MAX_int32_T;
          } else {
            c45_i15 = 0;
          }

          c45_c_x = c45_i15;
          c45_d_x = c45_c_x;
          c45_i16 = c45_d_x;
          if (CV_SATURATION_EVAL(4, 0, 2, 0, c45_i16 <= MIN_int32_T)) {
            c45_b_saturatedUnaryMinus = MAX_int32_T;
          } else {
            c45_b_saturatedUnaryMinus = -c45_i16;
          }

          if ((real_T)c45_d_x < 0.0) {
            c45_b_y = c45_b_saturatedUnaryMinus;
          } else {
            c45_b_y = c45_d_x;
          }

          c45_d4 = (real_T)c45_b_y;
          if (CV_EML_COND(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 3, c45_d4, 15.0,
                -1, 2U, c45_d4 < 15.0))) {
            guard2 = true;
          } else {
            CV_EML_MCDC(0, 1, 1, false);
            CV_EML_IF(0, 1, 1, false);
          }
        }

        if (guard2 == true) {
          CV_EML_MCDC(0, 1, 1, true);
          CV_EML_IF(0, 1, 1, true);
          _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 11);
          c45_tmp_sizes[0] = 32;
          c45_tmp_sizes[1] = 1;
          c45_b_alarms_data[_SFD_EML_ARRAY_BOUNDS_CHECK("alarms", (int32_T)c45_a,
            1, 32, 1, 0) - 1] = 1.0;
          _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 12);
          c45_b_a = (int32_T)c45_a - 1;
          c45_c_i = (int32_T)c45_i - 1;
          for (c45_i17 = 0; c45_i17 < 2; c45_i17++) {
            c45_d5 = muDoubleScalarRound(c45_b_PosObj_subim[c45_i17 + (c45_c_i <<
              1)]);
            if (c45_d5 < 2.147483648E+9) {
              if (CV_SATURATION_EVAL(4, 0, 4, 1, c45_d5 >= -2.147483648E+9)) {
                c45_i18 = (int32_T)c45_d5;
              } else {
                c45_i18 = MIN_int32_T;
              }
            } else if (CV_SATURATION_EVAL(4, 0, 4, 0, c45_d5 >= 2.147483648E+9))
            {
              c45_i18 = MAX_int32_T;
            } else {
              c45_i18 = 0;
            }

            c45_b_CentAlarms[c45_i17 + (c45_b_a << 1)] = c45_i18;
          }

          _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 13);
          c45_c_a = (int32_T)c45_a - 1;
          c45_d_i = (int32_T)c45_i - 1;
          for (c45_i19 = 0; c45_i19 < 4; c45_i19++) {
            c45_b_BBox_det[c45_i19 + (c45_c_a << 2)] = c45_b_BBox[c45_i19 +
              (c45_d_i << 2)];
          }
        }
      }

      c45_b_j++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    CV_EML_FOR(0, 1, 1, 0);
    _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 17);
    c45_a++;
    c45_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, -17);
  _SFD_SYMBOL_SCOPE_POP();
  for (c45_i20 = 0; c45_i20 < 64; c45_i20++) {
    (*chartInstance->c45_CentAlarms)[c45_i20] = c45_b_CentAlarms[c45_i20];
  }

  *chartInstance->c45_alarms_sizes = c45_b_alarms_sizes;
  c45_loop_ub = c45_b_alarms_sizes - 1;
  for (c45_i21 = 0; c45_i21 <= c45_loop_ub; c45_i21++) {
    (*chartInstance->c45_alarms_data)[c45_i21] = c45_b_alarms_data[c45_i21];
  }

  for (c45_i22 = 0; c45_i22 < 400; c45_i22++) {
    (*chartInstance->c45_BBox_det)[c45_i22] = c45_b_BBox_det[c45_i22];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c45_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_1_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c45_i23 = 0; c45_i23 < 64; c45_i23++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c45_CentAlarms)[c45_i23], 0U);
  }

  for (c45_i24 = 0; c45_i24 < 64; c45_i24++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c45_PosObj_subim)[c45_i24], 1U);
  }

  for (c45_i25 = 0; c45_i25 < 200; c45_i25++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c45_Centroid_subim)[c45_i25],
                          2U);
  }

  c45_b_loop_ub = *chartInstance->c45_alarms_sizes - 1;
  for (c45_i26 = 0; c45_i26 <= c45_b_loop_ub; c45_i26++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c45_alarms_data)[c45_i26], 3U);
  }

  for (c45_i27 = 0; c45_i27 < 400; c45_i27++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c45_BBox)[c45_i27], 4U);
  }

  for (c45_i28 = 0; c45_i28 < 400; c45_i28++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c45_BBox_det)[c45_i28], 5U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c45_TISdet, 6U);
}

static void mdl_start_c45_Experiment_1_cs(SFc45_Experiment_1_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc45_Experiment_1_cs
  (SFc45_Experiment_1_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c45_machineNumber, uint32_T
  c45_chartNumber, uint32_T c45_instanceNumber)
{
  (void)c45_machineNumber;
  (void)c45_chartNumber;
  (void)c45_instanceNumber;
}

static const mxArray *c45_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData)
{
  const mxArray *c45_mxArrayOutData = NULL;
  int32_T c45_i29;
  int32_T c45_i30;
  int32_T c45_i31;
  int32_T c45_b_inData[400];
  int32_T c45_i32;
  int32_T c45_i33;
  int32_T c45_i34;
  int32_T c45_u[400];
  const mxArray *c45_y = NULL;
  SFc45_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc45_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c45_mxArrayOutData = NULL;
  c45_i29 = 0;
  for (c45_i30 = 0; c45_i30 < 100; c45_i30++) {
    for (c45_i31 = 0; c45_i31 < 4; c45_i31++) {
      c45_b_inData[c45_i31 + c45_i29] = (*(int32_T (*)[400])c45_inData)[c45_i31
        + c45_i29];
    }

    c45_i29 += 4;
  }

  c45_i32 = 0;
  for (c45_i33 = 0; c45_i33 < 100; c45_i33++) {
    for (c45_i34 = 0; c45_i34 < 4; c45_i34++) {
      c45_u[c45_i34 + c45_i32] = c45_b_inData[c45_i34 + c45_i32];
    }

    c45_i32 += 4;
  }

  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_create("y", c45_u, 6, 0U, 1U, 0U, 2, 4, 100),
                false);
  sf_mex_assign(&c45_mxArrayOutData, c45_y, false);
  return c45_mxArrayOutData;
}

static void c45_emlrt_marshallIn(SFc45_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c45_b_BBox_det, const char_T *c45_identifier,
  int32_T c45_y[400])
{
  emlrtMsgIdentifier c45_thisId;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c45_b_BBox_det), &c45_thisId,
    c45_y);
  sf_mex_destroy(&c45_b_BBox_det);
}

static void c45_b_emlrt_marshallIn(SFc45_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId,
  int32_T c45_y[400])
{
  int32_T c45_iv2[400];
  int32_T c45_i35;
  (void)chartInstance;
  sf_mex_import(c45_parentId, sf_mex_dup(c45_u), c45_iv2, 1, 6, 0U, 1, 0U, 2, 4,
                100);
  for (c45_i35 = 0; c45_i35 < 400; c45_i35++) {
    c45_y[c45_i35] = c45_iv2[c45_i35];
  }

  sf_mex_destroy(&c45_u);
}

static void c45_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData)
{
  const mxArray *c45_b_BBox_det;
  const char_T *c45_identifier;
  emlrtMsgIdentifier c45_thisId;
  int32_T c45_y[400];
  int32_T c45_i36;
  int32_T c45_i37;
  int32_T c45_i38;
  SFc45_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc45_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c45_b_BBox_det = sf_mex_dup(c45_mxArrayInData);
  c45_identifier = c45_varName;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c45_b_BBox_det), &c45_thisId,
    c45_y);
  sf_mex_destroy(&c45_b_BBox_det);
  c45_i36 = 0;
  for (c45_i37 = 0; c45_i37 < 100; c45_i37++) {
    for (c45_i38 = 0; c45_i38 < 4; c45_i38++) {
      (*(int32_T (*)[400])c45_outData)[c45_i38 + c45_i36] = c45_y[c45_i38 +
        c45_i36];
    }

    c45_i36 += 4;
  }

  sf_mex_destroy(&c45_mxArrayInData);
}

static const mxArray *c45_b_sf_marshallOut(void *chartInstanceVoid, real_T
  c45_inData_data[], int32_T *c45_inData_sizes)
{
  const mxArray *c45_mxArrayOutData = NULL;
  int32_T c45_b_inData_sizes;
  int32_T c45_loop_ub;
  int32_T c45_i39;
  real_T c45_b_inData_data[32];
  int32_T c45_u_sizes;
  int32_T c45_b_loop_ub;
  int32_T c45_i40;
  real_T c45_u_data[32];
  const mxArray *c45_y = NULL;
  SFc45_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc45_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c45_mxArrayOutData = NULL;
  c45_b_inData_sizes = *c45_inData_sizes;
  c45_loop_ub = *c45_inData_sizes - 1;
  for (c45_i39 = 0; c45_i39 <= c45_loop_ub; c45_i39++) {
    c45_b_inData_data[c45_i39] = c45_inData_data[c45_i39];
  }

  c45_u_sizes = c45_b_inData_sizes;
  c45_b_loop_ub = c45_b_inData_sizes - 1;
  for (c45_i40 = 0; c45_i40 <= c45_b_loop_ub; c45_i40++) {
    c45_u_data[c45_i40] = c45_b_inData_data[c45_i40];
  }

  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_create("y", c45_u_data, 0, 0U, 1U, 0U, 1,
    c45_u_sizes), false);
  sf_mex_assign(&c45_mxArrayOutData, c45_y, false);
  return c45_mxArrayOutData;
}

static void c45_c_emlrt_marshallIn(SFc45_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c45_alarms, const char_T *c45_identifier,
  real_T c45_y_data[], int32_T *c45_y_sizes)
{
  emlrtMsgIdentifier c45_thisId;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c45_alarms), &c45_thisId,
    c45_y_data, c45_y_sizes);
  sf_mex_destroy(&c45_alarms);
}

static void c45_d_emlrt_marshallIn(SFc45_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId,
  real_T c45_y_data[], int32_T *c45_y_sizes)
{
  static uint32_T c45_uv0[1] = { 32U };

  uint32_T c45_uv1[1];
  static boolean_T c45_bv0[1] = { true };

  boolean_T c45_bv1[1];
  int32_T c45_tmp_sizes;
  real_T c45_tmp_data[32];
  int32_T c45_loop_ub;
  int32_T c45_i41;
  (void)chartInstance;
  c45_uv1[0] = c45_uv0[0];
  c45_bv1[0] = c45_bv0[0];
  sf_mex_import_vs(c45_parentId, sf_mex_dup(c45_u), c45_tmp_data, 1, 0, 0U, 1,
                   0U, 1, c45_bv1, c45_uv1, &c45_tmp_sizes);
  *c45_y_sizes = c45_tmp_sizes;
  c45_loop_ub = c45_tmp_sizes - 1;
  for (c45_i41 = 0; c45_i41 <= c45_loop_ub; c45_i41++) {
    c45_y_data[c45_i41] = c45_tmp_data[c45_i41];
  }

  sf_mex_destroy(&c45_u);
}

static void c45_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, real_T c45_outData_data[],
  int32_T *c45_outData_sizes)
{
  const mxArray *c45_alarms;
  const char_T *c45_identifier;
  emlrtMsgIdentifier c45_thisId;
  int32_T c45_y_sizes;
  real_T c45_y_data[32];
  int32_T c45_loop_ub;
  int32_T c45_i42;
  SFc45_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc45_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c45_alarms = sf_mex_dup(c45_mxArrayInData);
  c45_identifier = c45_varName;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c45_alarms), &c45_thisId,
    c45_y_data, &c45_y_sizes);
  sf_mex_destroy(&c45_alarms);
  *c45_outData_sizes = c45_y_sizes;
  c45_loop_ub = c45_y_sizes - 1;
  for (c45_i42 = 0; c45_i42 <= c45_loop_ub; c45_i42++) {
    c45_outData_data[c45_i42] = c45_y_data[c45_i42];
  }

  sf_mex_destroy(&c45_mxArrayInData);
}

static const mxArray *c45_c_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData)
{
  const mxArray *c45_mxArrayOutData = NULL;
  int32_T c45_i43;
  int32_T c45_i44;
  int32_T c45_i45;
  int32_T c45_b_inData[64];
  int32_T c45_i46;
  int32_T c45_i47;
  int32_T c45_i48;
  int32_T c45_u[64];
  const mxArray *c45_y = NULL;
  SFc45_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc45_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c45_mxArrayOutData = NULL;
  c45_i43 = 0;
  for (c45_i44 = 0; c45_i44 < 32; c45_i44++) {
    for (c45_i45 = 0; c45_i45 < 2; c45_i45++) {
      c45_b_inData[c45_i45 + c45_i43] = (*(int32_T (*)[64])c45_inData)[c45_i45 +
        c45_i43];
    }

    c45_i43 += 2;
  }

  c45_i46 = 0;
  for (c45_i47 = 0; c45_i47 < 32; c45_i47++) {
    for (c45_i48 = 0; c45_i48 < 2; c45_i48++) {
      c45_u[c45_i48 + c45_i46] = c45_b_inData[c45_i48 + c45_i46];
    }

    c45_i46 += 2;
  }

  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_create("y", c45_u, 6, 0U, 1U, 0U, 2, 2, 32),
                false);
  sf_mex_assign(&c45_mxArrayOutData, c45_y, false);
  return c45_mxArrayOutData;
}

static void c45_e_emlrt_marshallIn(SFc45_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c45_b_CentAlarms, const char_T *c45_identifier,
  int32_T c45_y[64])
{
  emlrtMsgIdentifier c45_thisId;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c45_b_CentAlarms),
    &c45_thisId, c45_y);
  sf_mex_destroy(&c45_b_CentAlarms);
}

static void c45_f_emlrt_marshallIn(SFc45_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId,
  int32_T c45_y[64])
{
  int32_T c45_iv3[64];
  int32_T c45_i49;
  (void)chartInstance;
  sf_mex_import(c45_parentId, sf_mex_dup(c45_u), c45_iv3, 1, 6, 0U, 1, 0U, 2, 2,
                32);
  for (c45_i49 = 0; c45_i49 < 64; c45_i49++) {
    c45_y[c45_i49] = c45_iv3[c45_i49];
  }

  sf_mex_destroy(&c45_u);
}

static void c45_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData)
{
  const mxArray *c45_b_CentAlarms;
  const char_T *c45_identifier;
  emlrtMsgIdentifier c45_thisId;
  int32_T c45_y[64];
  int32_T c45_i50;
  int32_T c45_i51;
  int32_T c45_i52;
  SFc45_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc45_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c45_b_CentAlarms = sf_mex_dup(c45_mxArrayInData);
  c45_identifier = c45_varName;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c45_b_CentAlarms),
    &c45_thisId, c45_y);
  sf_mex_destroy(&c45_b_CentAlarms);
  c45_i50 = 0;
  for (c45_i51 = 0; c45_i51 < 32; c45_i51++) {
    for (c45_i52 = 0; c45_i52 < 2; c45_i52++) {
      (*(int32_T (*)[64])c45_outData)[c45_i52 + c45_i50] = c45_y[c45_i52 +
        c45_i50];
    }

    c45_i50 += 2;
  }

  sf_mex_destroy(&c45_mxArrayInData);
}

static const mxArray *c45_d_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData)
{
  const mxArray *c45_mxArrayOutData = NULL;
  int32_T c45_i53;
  int32_T c45_i54;
  int32_T c45_i55;
  int32_T c45_b_inData[200];
  int32_T c45_i56;
  int32_T c45_i57;
  int32_T c45_i58;
  int32_T c45_u[200];
  const mxArray *c45_y = NULL;
  SFc45_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc45_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c45_mxArrayOutData = NULL;
  c45_i53 = 0;
  for (c45_i54 = 0; c45_i54 < 100; c45_i54++) {
    for (c45_i55 = 0; c45_i55 < 2; c45_i55++) {
      c45_b_inData[c45_i55 + c45_i53] = (*(int32_T (*)[200])c45_inData)[c45_i55
        + c45_i53];
    }

    c45_i53 += 2;
  }

  c45_i56 = 0;
  for (c45_i57 = 0; c45_i57 < 100; c45_i57++) {
    for (c45_i58 = 0; c45_i58 < 2; c45_i58++) {
      c45_u[c45_i58 + c45_i56] = c45_b_inData[c45_i58 + c45_i56];
    }

    c45_i56 += 2;
  }

  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_create("y", c45_u, 6, 0U, 1U, 0U, 2, 2, 100),
                false);
  sf_mex_assign(&c45_mxArrayOutData, c45_y, false);
  return c45_mxArrayOutData;
}

static const mxArray *c45_e_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData)
{
  const mxArray *c45_mxArrayOutData = NULL;
  int32_T c45_i59;
  int32_T c45_i60;
  int32_T c45_i61;
  real_T c45_b_inData[64];
  int32_T c45_i62;
  int32_T c45_i63;
  int32_T c45_i64;
  real_T c45_u[64];
  const mxArray *c45_y = NULL;
  SFc45_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc45_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c45_mxArrayOutData = NULL;
  c45_i59 = 0;
  for (c45_i60 = 0; c45_i60 < 32; c45_i60++) {
    for (c45_i61 = 0; c45_i61 < 2; c45_i61++) {
      c45_b_inData[c45_i61 + c45_i59] = (*(real_T (*)[64])c45_inData)[c45_i61 +
        c45_i59];
    }

    c45_i59 += 2;
  }

  c45_i62 = 0;
  for (c45_i63 = 0; c45_i63 < 32; c45_i63++) {
    for (c45_i64 = 0; c45_i64 < 2; c45_i64++) {
      c45_u[c45_i64 + c45_i62] = c45_b_inData[c45_i64 + c45_i62];
    }

    c45_i62 += 2;
  }

  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_create("y", c45_u, 0, 0U, 1U, 0U, 2, 2, 32),
                false);
  sf_mex_assign(&c45_mxArrayOutData, c45_y, false);
  return c45_mxArrayOutData;
}

static const mxArray *c45_f_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData)
{
  const mxArray *c45_mxArrayOutData = NULL;
  real_T c45_u;
  const mxArray *c45_y = NULL;
  SFc45_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc45_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c45_mxArrayOutData = NULL;
  c45_u = *(real_T *)c45_inData;
  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_create("y", &c45_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c45_mxArrayOutData, c45_y, false);
  return c45_mxArrayOutData;
}

static real_T c45_g_emlrt_marshallIn(SFc45_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId)
{
  real_T c45_y;
  real_T c45_d6;
  (void)chartInstance;
  sf_mex_import(c45_parentId, sf_mex_dup(c45_u), &c45_d6, 1, 0, 0U, 0, 0U, 0);
  c45_y = c45_d6;
  sf_mex_destroy(&c45_u);
  return c45_y;
}

static void c45_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData)
{
  const mxArray *c45_nargout;
  const char_T *c45_identifier;
  emlrtMsgIdentifier c45_thisId;
  real_T c45_y;
  SFc45_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc45_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c45_nargout = sf_mex_dup(c45_mxArrayInData);
  c45_identifier = c45_varName;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_y = c45_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c45_nargout),
    &c45_thisId);
  sf_mex_destroy(&c45_nargout);
  *(real_T *)c45_outData = c45_y;
  sf_mex_destroy(&c45_mxArrayInData);
}

const mxArray *sf_c45_Experiment_1_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c45_nameCaptureInfo = NULL;
  c45_nameCaptureInfo = NULL;
  sf_mex_assign(&c45_nameCaptureInfo, sf_mex_createstruct("structure", 2, 3, 1),
                false);
  c45_info_helper(&c45_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c45_nameCaptureInfo);
  return c45_nameCaptureInfo;
}

static void c45_info_helper(const mxArray **c45_info)
{
  const mxArray *c45_rhs0 = NULL;
  const mxArray *c45_lhs0 = NULL;
  const mxArray *c45_rhs1 = NULL;
  const mxArray *c45_lhs1 = NULL;
  const mxArray *c45_rhs2 = NULL;
  const mxArray *c45_lhs2 = NULL;
  sf_mex_addfield(*c45_info, c45_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c45_info, c45_emlrt_marshallOut("abs"), "name", "name", 0);
  sf_mex_addfield(*c45_info, c45_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c45_info, c45_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c45_info, c45_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c45_info, c45_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c45_info, c45_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c45_info, c45_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c45_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c45_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c45_info, sf_mex_duplicatearraysafe(&c45_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c45_info, sf_mex_duplicatearraysafe(&c45_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c45_info, c45_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c45_info, c45_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c45_info, c45_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c45_info, c45_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c45_info, c45_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c45_info, c45_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c45_info, c45_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c45_info, c45_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c45_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c45_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c45_info, sf_mex_duplicatearraysafe(&c45_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c45_info, sf_mex_duplicatearraysafe(&c45_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c45_info, c45_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c45_info, c45_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 2);
  sf_mex_addfield(*c45_info, c45_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c45_info, c45_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c45_info, c45_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c45_info, c45_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c45_info, c45_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c45_info, c45_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c45_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c45_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c45_info, sf_mex_duplicatearraysafe(&c45_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c45_info, sf_mex_duplicatearraysafe(&c45_lhs2), "lhs", "lhs",
                  2);
  sf_mex_destroy(&c45_rhs0);
  sf_mex_destroy(&c45_lhs0);
  sf_mex_destroy(&c45_rhs1);
  sf_mex_destroy(&c45_lhs1);
  sf_mex_destroy(&c45_rhs2);
  sf_mex_destroy(&c45_lhs2);
}

static const mxArray *c45_emlrt_marshallOut(const char * c45_u)
{
  const mxArray *c45_y = NULL;
  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_create("y", c45_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c45_u)), false);
  return c45_y;
}

static const mxArray *c45_b_emlrt_marshallOut(const uint32_T c45_u)
{
  const mxArray *c45_y = NULL;
  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_create("y", &c45_u, 7, 0U, 0U, 0U, 0), false);
  return c45_y;
}

static const mxArray *c45_g_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData)
{
  const mxArray *c45_mxArrayOutData = NULL;
  int32_T c45_u;
  const mxArray *c45_y = NULL;
  SFc45_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc45_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c45_mxArrayOutData = NULL;
  c45_u = *(int32_T *)c45_inData;
  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_create("y", &c45_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c45_mxArrayOutData, c45_y, false);
  return c45_mxArrayOutData;
}

static int32_T c45_h_emlrt_marshallIn(SFc45_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId)
{
  int32_T c45_y;
  int32_T c45_i65;
  (void)chartInstance;
  sf_mex_import(c45_parentId, sf_mex_dup(c45_u), &c45_i65, 1, 6, 0U, 0, 0U, 0);
  c45_y = c45_i65;
  sf_mex_destroy(&c45_u);
  return c45_y;
}

static void c45_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData)
{
  const mxArray *c45_b_sfEvent;
  const char_T *c45_identifier;
  emlrtMsgIdentifier c45_thisId;
  int32_T c45_y;
  SFc45_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc45_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c45_b_sfEvent = sf_mex_dup(c45_mxArrayInData);
  c45_identifier = c45_varName;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_y = c45_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c45_b_sfEvent),
    &c45_thisId);
  sf_mex_destroy(&c45_b_sfEvent);
  *(int32_T *)c45_outData = c45_y;
  sf_mex_destroy(&c45_mxArrayInData);
}

static uint8_T c45_i_emlrt_marshallIn(SFc45_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c45_b_is_active_c45_Experiment_1_cs, const
  char_T *c45_identifier)
{
  uint8_T c45_y;
  emlrtMsgIdentifier c45_thisId;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_y = c45_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c45_b_is_active_c45_Experiment_1_cs), &c45_thisId);
  sf_mex_destroy(&c45_b_is_active_c45_Experiment_1_cs);
  return c45_y;
}

static uint8_T c45_j_emlrt_marshallIn(SFc45_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId)
{
  uint8_T c45_y;
  uint8_T c45_u0;
  (void)chartInstance;
  sf_mex_import(c45_parentId, sf_mex_dup(c45_u), &c45_u0, 1, 3, 0U, 0, 0U, 0);
  c45_y = c45_u0;
  sf_mex_destroy(&c45_u);
  return c45_y;
}

static void init_dsm_address_info(SFc45_Experiment_1_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc45_Experiment_1_csInstanceStruct
  *chartInstance)
{
  chartInstance->c45_CentAlarms = (int32_T (*)[64])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c45_PosObj_subim = (real_T (*)[64])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c45_Centroid_subim = (int32_T (*)[200])
    ssGetInputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c45_alarms_data = (real_T (*)[32])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c45_alarms_sizes = (int32_T *)
    ssGetCurrentOutputPortDimensions_wrapper(chartInstance->S, 2);
  chartInstance->c45_BBox = (int32_T (*)[400])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c45_BBox_det = (int32_T (*)[400])ssGetOutputPortSignal_wrapper
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

void sf_c45_Experiment_1_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(478159838U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2721892586U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(411898310U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(288113442U);
}

mxArray* sf_c45_Experiment_1_cs_get_post_codegen_info(void);
mxArray *sf_c45_Experiment_1_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("qJTf6L4VErWmhGDcg8VtdB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(32);
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
      pr[0] = (double)(2);
      pr[1] = (double)(100);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(100);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(32);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
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
      pr[0] = (double)(4);
      pr[1] = (double)(100);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
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
    mxArray* mxPostCodegenInfo = sf_c45_Experiment_1_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c45_Experiment_1_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c45_Experiment_1_cs_jit_fallback_info(void)
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

mxArray *sf_c45_Experiment_1_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c45_Experiment_1_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c45_Experiment_1_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[16],T\"BBox_det\",},{M[1],M[14],T\"CentAlarms\",},{M[1],M[5],T\"alarms\",},{M[8],M[0],T\"is_active_c45_Experiment_1_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c45_Experiment_1_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc45_Experiment_1_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc45_Experiment_1_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_1_csMachineNumber_,
           45,
           1,
           1,
           0,
           7,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_Experiment_1_csMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Experiment_1_csMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Experiment_1_csMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"CentAlarms");
          _SFD_SET_DATA_PROPS(1,1,1,0,"PosObj_subim");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Centroid_subim");
          _SFD_SET_DATA_PROPS(3,2,0,1,"alarms");
          _SFD_SET_DATA_PROPS(4,1,1,0,"BBox");
          _SFD_SET_DATA_PROPS(5,2,0,1,"BBox_det");
          _SFD_SET_DATA_PROPS(6,10,0,0,"TISdet");
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
        _SFD_CV_INIT_EML(0,1,1,2,0,5,0,2,0,4,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,730);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,366,-1,408);
        _SFD_CV_INIT_EML_SATURATION(0,1,1,370,-1,407);
        _SFD_CV_INIT_EML_SATURATION(0,1,2,415,-1,457);
        _SFD_CV_INIT_EML_SATURATION(0,1,3,419,-1,456);
        _SFD_CV_INIT_EML_SATURATION(0,1,4,582,-1,615);
        _SFD_CV_INIT_EML_IF(0,1,0,296,349,-1,706);
        _SFD_CV_INIT_EML_IF(0,1,1,362,461,-1,694);
        _SFD_CV_INIT_EML_FOR(0,1,0,224,253,729);
        _SFD_CV_INIT_EML_FOR(0,1,1,257,288,714);

        {
          static int condStart[] = { 300, 326 };

          static int condEnd[] = { 322, 348 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,299,349,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 366, 415 };

          static int condEnd[] = { 411, 460 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,365,461,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,300,322,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,326,348,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,366,411,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,415,460,-1,2);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c45_c_sf_marshallOut,(MexInFcnForType)
            c45_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c45_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 100;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c45_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c45_b_sf_marshallOut,(MexInFcnForType)
            c45_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 100;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c45_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 100;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c45_sf_marshallOut,(MexInFcnForType)
            c45_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c45_f_sf_marshallOut,(MexInFcnForType)
          c45_d_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c45_CentAlarms);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c45_PosObj_subim);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c45_Centroid_subim);
        _SFD_SET_DATA_VALUE_PTR_VAR_DIM(3U, *chartInstance->c45_alarms_data,
          (void *)chartInstance->c45_alarms_sizes);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c45_BBox);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c45_BBox_det);
        _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c45_TISdet);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Experiment_1_csMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "X0StvFlWaiA2CwhciyGa9";
}

static void sf_opaque_initialize_c45_Experiment_1_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc45_Experiment_1_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c45_Experiment_1_cs((SFc45_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
  initialize_c45_Experiment_1_cs((SFc45_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c45_Experiment_1_cs(void *chartInstanceVar)
{
  enable_c45_Experiment_1_cs((SFc45_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c45_Experiment_1_cs(void *chartInstanceVar)
{
  disable_c45_Experiment_1_cs((SFc45_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c45_Experiment_1_cs(void *chartInstanceVar)
{
  sf_gateway_c45_Experiment_1_cs((SFc45_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c45_Experiment_1_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c45_Experiment_1_cs((SFc45_Experiment_1_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c45_Experiment_1_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c45_Experiment_1_cs((SFc45_Experiment_1_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c45_Experiment_1_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc45_Experiment_1_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_1_cs_optimization_info();
    }

    finalize_c45_Experiment_1_cs((SFc45_Experiment_1_csInstanceStruct*)
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
  initSimStructsc45_Experiment_1_cs((SFc45_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c45_Experiment_1_cs(SimStruct *S)
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
    initialize_params_c45_Experiment_1_cs((SFc45_Experiment_1_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c45_Experiment_1_cs(SimStruct *S)
{
  /* Actual parameters from chart:
     TISdet
   */
  const char_T *rtParamNames[] = { "TISdet" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for TISdet*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Experiment_1_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      45);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,45,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,45,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,45);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,45,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,45,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,45);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4214347503U));
  ssSetChecksum1(S,(1885712757U));
  ssSetChecksum2(S,(114308062U));
  ssSetChecksum3(S,(1906879464U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c45_Experiment_1_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c45_Experiment_1_cs(SimStruct *S)
{
  SFc45_Experiment_1_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc45_Experiment_1_csInstanceStruct *)utMalloc(sizeof
    (SFc45_Experiment_1_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc45_Experiment_1_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c45_Experiment_1_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c45_Experiment_1_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c45_Experiment_1_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c45_Experiment_1_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c45_Experiment_1_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c45_Experiment_1_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c45_Experiment_1_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c45_Experiment_1_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c45_Experiment_1_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c45_Experiment_1_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c45_Experiment_1_cs;
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

void c45_Experiment_1_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c45_Experiment_1_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c45_Experiment_1_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c45_Experiment_1_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c45_Experiment_1_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
