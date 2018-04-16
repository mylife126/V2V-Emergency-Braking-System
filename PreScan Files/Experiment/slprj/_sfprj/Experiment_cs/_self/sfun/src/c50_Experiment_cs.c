/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_cs_sfun.h"
#include "c50_Experiment_cs.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Experiment_cs_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c50_debug_family_names[24] = { "minPx", "minPy", "maxPx",
  "maxPy", "detected", "mino", "maxo", "i", "limsup_x", "limsup_y", "a",
  "nargin", "nargout", "im", "PosObj", "X", "Y", "sub_im", "posObj_subim",
  "im_x", "im_y", "liminf_x", "liminf_y", "rectangle" };

/* Function Declarations */
static void initialize_c50_Experiment_cs(SFc50_Experiment_csInstanceStruct
  *chartInstance);
static void initialize_params_c50_Experiment_cs
  (SFc50_Experiment_csInstanceStruct *chartInstance);
static void enable_c50_Experiment_cs(SFc50_Experiment_csInstanceStruct
  *chartInstance);
static void disable_c50_Experiment_cs(SFc50_Experiment_csInstanceStruct
  *chartInstance);
static void c50_update_debugger_state_c50_Experiment_cs
  (SFc50_Experiment_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c50_Experiment_cs
  (SFc50_Experiment_csInstanceStruct *chartInstance);
static void set_sim_state_c50_Experiment_cs(SFc50_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c50_st);
static void finalize_c50_Experiment_cs(SFc50_Experiment_csInstanceStruct
  *chartInstance);
static void sf_gateway_c50_Experiment_cs(SFc50_Experiment_csInstanceStruct
  *chartInstance);
static void mdl_start_c50_Experiment_cs(SFc50_Experiment_csInstanceStruct
  *chartInstance);
static void c50_chartstep_c50_Experiment_cs(SFc50_Experiment_csInstanceStruct
  *chartInstance);
static void initSimStructsc50_Experiment_cs(SFc50_Experiment_csInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c50_machineNumber, uint32_T
  c50_chartNumber, uint32_T c50_instanceNumber);
static const mxArray *c50_sf_marshallOut(void *chartInstanceVoid, void
  *c50_b_inData);
static void c50_emlrt_marshallIn(SFc50_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c50_b_rectangle, const char_T *c50_identifier,
  real_T c50_y[4]);
static void c50_b_emlrt_marshallIn(SFc50_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y[4]);
static void c50_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_b_sf_marshallOut(void *chartInstanceVoid, void
  *c50_b_inData);
static real_T c50_c_emlrt_marshallIn(SFc50_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c50_b_liminf_y, const char_T *c50_identifier);
static real_T c50_d_emlrt_marshallIn(SFc50_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId);
static void c50_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_c_sf_marshallOut(void *chartInstanceVoid, void
  *c50_b_inData);
static void c50_e_emlrt_marshallIn(SFc50_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c50_b_posObj_subim, const char_T
  *c50_identifier, real_T c50_y[64]);
static void c50_f_emlrt_marshallIn(SFc50_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y[64]);
static void c50_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_d_sf_marshallOut(void *chartInstanceVoid, uint8_T
  c50_b_inData_data[], int32_T c50_inData_sizes[2]);
static void c50_g_emlrt_marshallIn(SFc50_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c50_sub_im, const char_T *c50_identifier,
  uint8_T c50_b_y_data[], int32_T c50_y_sizes[2]);
static void c50_h_emlrt_marshallIn(SFc50_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  uint8_T c50_b_y_data[], int32_T c50_y_sizes[2]);
static void c50_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, uint8_T c50_outData_data[],
  int32_T c50_outData_sizes[2]);
static const mxArray *c50_e_sf_marshallOut(void *chartInstanceVoid, void
  *c50_b_inData);
static const mxArray *c50_f_sf_marshallOut(void *chartInstanceVoid, void
  *c50_b_inData);
static void c50_info_helper(const mxArray **c50_info);
static const mxArray *c50_emlrt_marshallOut(const char * c50_u);
static const mxArray *c50_b_emlrt_marshallOut(const uint32_T c50_u);
static real_T c50_round(SFc50_Experiment_csInstanceStruct *chartInstance, real_T
  c50_x);
static real_T c50_abs(SFc50_Experiment_csInstanceStruct *chartInstance, real_T
                      c50_x);
static int32_T c50_intlength(SFc50_Experiment_csInstanceStruct *chartInstance,
  uint8_T c50_b_x_data[], int32_T c50_x_sizes[2]);
static const mxArray *c50_g_sf_marshallOut(void *chartInstanceVoid, void
  *c50_b_inData);
static int32_T c50_i_emlrt_marshallIn(SFc50_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId);
static void c50_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static uint8_T c50_j_emlrt_marshallIn(SFc50_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c50_b_is_active_c50_Experiment_cs, const char_T
  *c50_identifier);
static uint8_T c50_k_emlrt_marshallIn(SFc50_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId);
static void c50_b_round(SFc50_Experiment_csInstanceStruct *chartInstance, real_T
  *c50_x);
static void init_dsm_address_info(SFc50_Experiment_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc50_Experiment_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c50_Experiment_cs(SFc50_Experiment_csInstanceStruct
  *chartInstance)
{
  chartInstance->c50_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c50_is_active_c50_Experiment_cs = 0U;
}

static void initialize_params_c50_Experiment_cs
  (SFc50_Experiment_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c50_Experiment_cs(SFc50_Experiment_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c50_Experiment_cs(SFc50_Experiment_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c50_update_debugger_state_c50_Experiment_cs
  (SFc50_Experiment_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c50_Experiment_cs
  (SFc50_Experiment_csInstanceStruct *chartInstance)
{
  const mxArray *c50_st;
  const mxArray *c50_y = NULL;
  real_T c50_hoistedGlobal;
  real_T c50_u;
  const mxArray *c50_b_y = NULL;
  real_T c50_b_hoistedGlobal;
  real_T c50_b_u;
  const mxArray *c50_c_y = NULL;
  real_T c50_c_hoistedGlobal;
  real_T c50_c_u;
  const mxArray *c50_d_y = NULL;
  real_T c50_d_hoistedGlobal;
  real_T c50_d_u;
  const mxArray *c50_e_y = NULL;
  int32_T c50_i0;
  real_T c50_e_u[64];
  const mxArray *c50_f_y = NULL;
  int32_T c50_i1;
  real_T c50_f_u[4];
  const mxArray *c50_g_y = NULL;
  int32_T c50_u_sizes[2];
  int32_T c50_g_u;
  int32_T c50_h_u;
  int32_T c50_loop_ub;
  int32_T c50_i2;
  uint8_T c50_u_data[187500];
  const mxArray *c50_h_y = NULL;
  uint8_T c50_e_hoistedGlobal;
  uint8_T c50_i_u;
  const mxArray *c50_i_y = NULL;
  c50_st = NULL;
  c50_st = NULL;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_createcellmatrix(8, 1), false);
  c50_hoistedGlobal = *chartInstance->c50_im_x;
  c50_u = c50_hoistedGlobal;
  c50_b_y = NULL;
  sf_mex_assign(&c50_b_y, sf_mex_create("y", &c50_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c50_y, 0, c50_b_y);
  c50_b_hoistedGlobal = *chartInstance->c50_im_y;
  c50_b_u = c50_b_hoistedGlobal;
  c50_c_y = NULL;
  sf_mex_assign(&c50_c_y, sf_mex_create("y", &c50_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c50_y, 1, c50_c_y);
  c50_c_hoistedGlobal = *chartInstance->c50_liminf_x;
  c50_c_u = c50_c_hoistedGlobal;
  c50_d_y = NULL;
  sf_mex_assign(&c50_d_y, sf_mex_create("y", &c50_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c50_y, 2, c50_d_y);
  c50_d_hoistedGlobal = *chartInstance->c50_liminf_y;
  c50_d_u = c50_d_hoistedGlobal;
  c50_e_y = NULL;
  sf_mex_assign(&c50_e_y, sf_mex_create("y", &c50_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c50_y, 3, c50_e_y);
  for (c50_i0 = 0; c50_i0 < 64; c50_i0++) {
    c50_e_u[c50_i0] = (*chartInstance->c50_posObj_subim)[c50_i0];
  }

  c50_f_y = NULL;
  sf_mex_assign(&c50_f_y, sf_mex_create("y", c50_e_u, 0, 0U, 1U, 0U, 2, 2, 32),
                false);
  sf_mex_setcell(c50_y, 4, c50_f_y);
  for (c50_i1 = 0; c50_i1 < 4; c50_i1++) {
    c50_f_u[c50_i1] = (*chartInstance->c50_rectangle)[c50_i1];
  }

  c50_g_y = NULL;
  sf_mex_assign(&c50_g_y, sf_mex_create("y", c50_f_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_setcell(c50_y, 5, c50_g_y);
  c50_u_sizes[0] = (*chartInstance->c50_sub_im_sizes)[0];
  c50_u_sizes[1] = (*chartInstance->c50_sub_im_sizes)[1];
  c50_g_u = c50_u_sizes[0];
  c50_h_u = c50_u_sizes[1];
  c50_loop_ub = (*chartInstance->c50_sub_im_sizes)[0] *
    (*chartInstance->c50_sub_im_sizes)[1] - 1;
  for (c50_i2 = 0; c50_i2 <= c50_loop_ub; c50_i2++) {
    c50_u_data[c50_i2] = (*chartInstance->c50_b_sub_im_data)[c50_i2];
  }

  c50_h_y = NULL;
  sf_mex_assign(&c50_h_y, sf_mex_create("y", c50_u_data, 3, 0U, 1U, 0U, 2,
    c50_u_sizes[0], c50_u_sizes[1]), false);
  sf_mex_setcell(c50_y, 6, c50_h_y);
  c50_e_hoistedGlobal = chartInstance->c50_is_active_c50_Experiment_cs;
  c50_i_u = c50_e_hoistedGlobal;
  c50_i_y = NULL;
  sf_mex_assign(&c50_i_y, sf_mex_create("y", &c50_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c50_y, 7, c50_i_y);
  sf_mex_assign(&c50_st, c50_y, false);
  return c50_st;
}

static void set_sim_state_c50_Experiment_cs(SFc50_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c50_st)
{
  const mxArray *c50_u;
  real_T c50_dv0[64];
  int32_T c50_i3;
  real_T c50_dv1[4];
  int32_T c50_i4;
  int32_T c50_tmp_sizes[2];
  int32_T c50_i5;
  int32_T c50_i6;
  int32_T c50_loop_ub;
  int32_T c50_i7;
  chartInstance->c50_doneDoubleBufferReInit = true;
  c50_u = sf_mex_dup(c50_st);
  *chartInstance->c50_im_x = c50_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c50_u, 0)), "im_x");
  *chartInstance->c50_im_y = c50_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c50_u, 1)), "im_y");
  *chartInstance->c50_liminf_x = c50_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c50_u, 2)), "liminf_x");
  *chartInstance->c50_liminf_y = c50_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c50_u, 3)), "liminf_y");
  c50_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c50_u, 4)),
    "posObj_subim", c50_dv0);
  for (c50_i3 = 0; c50_i3 < 64; c50_i3++) {
    (*chartInstance->c50_posObj_subim)[c50_i3] = c50_dv0[c50_i3];
  }

  c50_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c50_u, 5)),
                       "rectangle", c50_dv1);
  for (c50_i4 = 0; c50_i4 < 4; c50_i4++) {
    (*chartInstance->c50_rectangle)[c50_i4] = c50_dv1[c50_i4];
  }

  c50_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c50_u, 6)),
    "sub_im", chartInstance->c50_tmp_data, c50_tmp_sizes);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1, 0,
    c50_tmp_sizes[0]);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1, 1,
    c50_tmp_sizes[1]);
  c50_i5 = (*chartInstance->c50_sub_im_sizes)[0];
  c50_i6 = (*chartInstance->c50_sub_im_sizes)[1];
  c50_loop_ub = c50_tmp_sizes[0] * c50_tmp_sizes[1] - 1;
  for (c50_i7 = 0; c50_i7 <= c50_loop_ub; c50_i7++) {
    (*chartInstance->c50_b_sub_im_data)[c50_i7] = chartInstance->
      c50_tmp_data[c50_i7];
  }

  chartInstance->c50_is_active_c50_Experiment_cs = c50_j_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c50_u, 7)),
     "is_active_c50_Experiment_cs");
  sf_mex_destroy(&c50_u);
  c50_update_debugger_state_c50_Experiment_cs(chartInstance);
  sf_mex_destroy(&c50_st);
}

static void finalize_c50_Experiment_cs(SFc50_Experiment_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c50_Experiment_cs(SFc50_Experiment_csInstanceStruct
  *chartInstance)
{
  int32_T c50_i8;
  int32_T c50_i9;
  int32_T c50_i10;
  int32_T c50_i11;
  int32_T c50_loop_ub;
  int32_T c50_i12;
  int32_T c50_i13;
  int32_T c50_i14;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 49U, chartInstance->c50_sfEvent);
  for (c50_i8 = 0; c50_i8 < 187500; c50_i8++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c50_b_im)[c50_i8], 0U);
  }

  for (c50_i9 = 0; c50_i9 < 64; c50_i9++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c50_PosObj)[c50_i9], 1U);
  }

  for (c50_i10 = 0; c50_i10 < 32; c50_i10++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c50_X)[c50_i10], 2U);
  }

  for (c50_i11 = 0; c50_i11 < 32; c50_i11++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c50_Y)[c50_i11], 3U);
  }

  chartInstance->c50_sfEvent = CALL_EVENT;
  c50_chartstep_c50_Experiment_cs(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  c50_loop_ub = (*chartInstance->c50_sub_im_sizes)[0] *
    (*chartInstance->c50_sub_im_sizes)[1] - 1;
  for (c50_i12 = 0; c50_i12 <= c50_loop_ub; c50_i12++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c50_b_sub_im_data)[c50_i12],
                          4U);
  }

  for (c50_i13 = 0; c50_i13 < 64; c50_i13++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c50_posObj_subim)[c50_i13], 5U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c50_im_x, 6U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c50_im_y, 7U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c50_liminf_x, 8U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c50_liminf_y, 9U);
  for (c50_i14 = 0; c50_i14 < 4; c50_i14++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c50_rectangle)[c50_i14], 10U);
  }
}

static void mdl_start_c50_Experiment_cs(SFc50_Experiment_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c50_chartstep_c50_Experiment_cs(SFc50_Experiment_csInstanceStruct
  *chartInstance)
{
  int32_T c50_i15;
  int32_T c50_i16;
  real_T c50_b_PosObj[64];
  int32_T c50_i17;
  real_T c50_b_X[32];
  int32_T c50_i18;
  real_T c50_b_Y[32];
  uint32_T c50_debug_family_var_map[24];
  real_T c50_minPx;
  real_T c50_minPy;
  real_T c50_maxPx;
  real_T c50_maxPy;
  real_T c50_detected;
  real_T c50_mino;
  real_T c50_maxo;
  real_T c50_i;
  real_T c50_limsup_x;
  real_T c50_limsup_y;
  real_T c50_a;
  real_T c50_nargin = 4.0;
  real_T c50_nargout = 7.0;
  int32_T c50_b_sub_im_sizes[2];
  real_T c50_b_posObj_subim[64];
  real_T c50_b_im_x;
  real_T c50_b_im_y;
  real_T c50_b_liminf_x;
  real_T c50_b_liminf_y;
  real_T c50_b_rectangle[4];
  int32_T c50_b_i;
  real_T c50_d0;
  real_T c50_d1;
  real_T c50_d2;
  real_T c50_d3;
  real_T c50_d4;
  real_T c50_d5;
  real_T c50_d6;
  real_T c50_d7;
  int32_T c50_i19;
  int32_T c50_c_i;
  int32_T c50_b_a;
  boolean_T c50_b0;
  boolean_T c50_b1;
  boolean_T c50_b2;
  int32_T c50_i20;
  int32_T c50_i21;
  boolean_T c50_b3;
  boolean_T c50_b4;
  boolean_T c50_b5;
  int32_T c50_i22;
  int32_T c50_i23;
  int32_T c50_x_sizes[2];
  int32_T c50_loop_ub;
  int32_T c50_i24;
  int32_T c50_b_loop_ub;
  int32_T c50_i25;
  int32_T c50_sub_im;
  int32_T c50_b_sub_im;
  int32_T c50_c_loop_ub;
  int32_T c50_i26;
  int32_T c50_x;
  int32_T c50_b_x;
  int32_T c50_d_loop_ub;
  int32_T c50_i27;
  int32_T c50_b_x_sizes[2];
  int32_T c50_c_x;
  int32_T c50_d_x;
  int32_T c50_e_loop_ub;
  int32_T c50_i28;
  uint8_T c50_b_x_data[187500];
  real_T c50_d8;
  int32_T c50_i29;
  uint8_T c50_uv0[9];
  int32_T c50_c_sub_im;
  int32_T c50_d_sub_im;
  int32_T c50_i30;
  int32_T c50_i31;
  int32_T c50_i32;
  int32_T c50_f_loop_ub;
  int32_T c50_i33;
  int32_T c50_i34;
  int32_T c50_i35;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 49U, chartInstance->c50_sfEvent);
  for (c50_i15 = 0; c50_i15 < 187500; c50_i15++) {
    chartInstance->c50_im[c50_i15] = (*chartInstance->c50_b_im)[c50_i15];
  }

  for (c50_i16 = 0; c50_i16 < 64; c50_i16++) {
    c50_b_PosObj[c50_i16] = (*chartInstance->c50_PosObj)[c50_i16];
  }

  for (c50_i17 = 0; c50_i17 < 32; c50_i17++) {
    c50_b_X[c50_i17] = (*chartInstance->c50_X)[c50_i17];
  }

  for (c50_i18 = 0; c50_i18 < 32; c50_i18++) {
    c50_b_Y[c50_i18] = (*chartInstance->c50_Y)[c50_i18];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 24U, 24U, c50_debug_family_names,
    c50_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_minPx, 0U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_minPy, 1U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_maxPx, 2U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_maxPy, 3U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_detected, 4U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_mino, 5U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_maxo, 6U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_i, 7U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_limsup_x, 8U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_limsup_y, 9U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_a, 10U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargin, 11U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargout, 12U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c50_im, 13U, c50_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c50_b_PosObj, 14U, c50_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c50_b_X, 15U, c50_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c50_b_Y, 16U, c50_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(chartInstance->c50_sub_im_data, (
    const int32_T *)&c50_b_sub_im_sizes, NULL, 0, 17, (void *)
    c50_d_sf_marshallOut, (void *)c50_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_b_posObj_subim, 18U,
    c50_c_sf_marshallOut, c50_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_b_im_x, 19U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_b_im_y, 20U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_b_liminf_x, 21U,
    c50_b_sf_marshallOut, c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_b_liminf_y, 22U,
    c50_b_sf_marshallOut, c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_b_rectangle, 23U, c50_sf_marshallOut,
    c50_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 3);
  c50_minPx = 500.0;
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 4);
  c50_minPy = 375.0;
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 5);
  c50_maxPx = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 6);
  c50_maxPy = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 7);
  c50_detected = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 8);
  c50_mino = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 9);
  c50_maxo = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 10);
  c50_i = 1.0;
  c50_b_i = 0;
  while (c50_b_i < 32) {
    c50_i = 1.0 + (real_T)c50_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 11);
    if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c50_b_PosObj[1 +
          (((int32_T)c50_i - 1) << 1)], 0.0, -1, 1U, c50_b_PosObj[1 + (((int32_T)
            c50_i - 1) << 1)] != 0.0))) {
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 12);
      if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c50_b_PosObj[1 +
            (((int32_T)c50_i - 1) << 1)], c50_minPx, -1, 2U, c50_b_PosObj[1 +
            (((int32_T)c50_i - 1) << 1)] < c50_minPx))) {
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 13);
        c50_minPx = c50_b_PosObj[1 + (((int32_T)c50_i - 1) << 1)];
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 14);
        c50_minPy = c50_b_PosObj[((int32_T)c50_i - 1) << 1];
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 15);
        c50_mino = c50_i;
      }

      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 17);
      if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 2, c50_b_PosObj[1 +
            (((int32_T)c50_i - 1) << 1)], c50_maxPx, -1, 4U, c50_b_PosObj[1 +
            (((int32_T)c50_i - 1) << 1)] > c50_maxPx))) {
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 18);
        c50_maxPx = c50_b_PosObj[1 + (((int32_T)c50_i - 1) << 1)];
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 19);
        c50_maxPy = c50_b_PosObj[((int32_T)c50_i - 1) << 1];
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 20);
        c50_maxo = c50_i;
      }

      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 22);
      c50_detected++;
    }

    c50_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 25);
  if (CV_EML_IF(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 3, c50_detected, 0.0, -1, 0U,
        c50_detected == 0.0))) {
    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 26);
    c50_b_liminf_x = 500.0;
    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 27);
    c50_limsup_x = 500.0;
    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 28);
    c50_b_liminf_y = 375.0;
    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 29);
    c50_limsup_y = 375.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 35);
    if (CV_EML_IF(0, 1, 4, CV_RELATIONAL_EVAL(4U, 0U, 4, c50_mino, 0.0, -1, 1U,
          c50_mino != 0.0))) {
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 36);
      c50_d0 = 1.6 * c50_b_Y[(int32_T)c50_mino - 1];
      c50_b_round(chartInstance, &c50_d0);
      c50_d1 = c50_minPx - (40.0 - c50_d0) * 2.0;
      c50_b_round(chartInstance, &c50_d1);
      c50_b_liminf_x = c50_d1;
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 37);
      c50_d2 = 4.5 * c50_b_Y[(int32_T)c50_mino - 1];
      c50_b_round(chartInstance, &c50_d2);
      c50_d3 = c50_minPy - (100.0 - c50_d2) * 2.0;
      c50_b_round(chartInstance, &c50_d3);
      c50_b_liminf_y = c50_d3;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 40);
      c50_b_liminf_x = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 41);
      c50_b_liminf_y = 1.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 43);
    if (CV_EML_IF(0, 1, 5, CV_RELATIONAL_EVAL(4U, 0U, 5, c50_maxo, 0.0, -1, 1U,
          c50_maxo != 0.0))) {
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 44);
      c50_d4 = 1.6 * c50_b_Y[(int32_T)c50_maxo - 1];
      c50_b_round(chartInstance, &c50_d4);
      c50_d5 = c50_maxPx + (40.0 - c50_d4) * 2.0;
      c50_b_round(chartInstance, &c50_d5);
      c50_limsup_x = c50_abs(chartInstance, c50_d5);
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 45);
      c50_d6 = 5.0 * c50_b_Y[(int32_T)c50_maxo - 1];
      c50_b_round(chartInstance, &c50_d6);
      c50_d7 = c50_maxPy + (100.0 - c50_d6) * 2.0;
      c50_b_round(chartInstance, &c50_d7);
      c50_limsup_y = c50_abs(chartInstance, c50_d7);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 47);
      c50_limsup_x = 500.0;
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 48);
      c50_limsup_y = 375.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 53);
  if (CV_EML_IF(0, 1, 6, CV_RELATIONAL_EVAL(4U, 0U, 6, c50_b_liminf_x, 1.0, -1,
        2U, c50_b_liminf_x < 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 54);
    c50_b_liminf_x = 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 57);
  if (CV_EML_IF(0, 1, 7, CV_RELATIONAL_EVAL(4U, 0U, 7, c50_limsup_x, 500.0, -1,
        4U, c50_limsup_x > 500.0))) {
    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 58);
    c50_limsup_x = 500.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 61);
  if (CV_EML_IF(0, 1, 8, CV_RELATIONAL_EVAL(4U, 0U, 8, c50_b_liminf_y, 1.0, -1,
        2U, c50_b_liminf_y < 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 62);
    c50_b_liminf_y = 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 65);
  if (CV_EML_IF(0, 1, 9, CV_RELATIONAL_EVAL(4U, 0U, 9, c50_limsup_y, 375.0, -1,
        5U, c50_limsup_y >= 375.0))) {
    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 66);
    c50_limsup_y = 375.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 69);
  if (CV_EML_IF(0, 1, 10, CV_RELATIONAL_EVAL(4U, 0U, 10, c50_b_liminf_y, 375.0,
        -1, 4U, c50_b_liminf_y > 375.0))) {
    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 70);
    c50_b_liminf_y = 375.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 73);
  for (c50_i19 = 0; c50_i19 < 64; c50_i19++) {
    c50_b_posObj_subim[c50_i19] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 74);
  c50_a = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 76);
  c50_i = 1.0;
  c50_c_i = 0;
  while (c50_c_i < 32) {
    c50_i = 1.0 + (real_T)c50_c_i;
    CV_EML_FOR(0, 1, 1, 1);
    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 77);
    if (CV_EML_IF(0, 1, 11, CV_RELATIONAL_EVAL(4U, 0U, 11, c50_b_PosObj[1 +
          (((int32_T)c50_i - 1) << 1)], 0.0, -1, 1U, c50_b_PosObj[1 + (((int32_T)
            c50_i - 1) << 1)] != 0.0))) {
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 78);
      c50_b_a = _SFD_EML_ARRAY_BOUNDS_CHECK("posObj_subim", (int32_T)c50_a, 1,
        32, 2, 0) - 1;
      c50_b_posObj_subim[c50_b_a << 1] = c50_b_PosObj[((int32_T)c50_i - 1) << 1]
        - c50_b_liminf_y;
      c50_b_posObj_subim[1 + (c50_b_a << 1)] = c50_b_PosObj[1 + (((int32_T)c50_i
        - 1) << 1)] - c50_b_liminf_x;
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 79);
      c50_a++;
    }

    c50_c_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 1, 0);
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 83);
  c50_b0 = (c50_b_liminf_y > c50_limsup_y);
  c50_b1 = c50_b0;
  c50_b2 = c50_b1;
  if (c50_b2) {
    c50_i20 = 1;
    c50_i21 = 0;
  } else {
    c50_i20 = (int32_T)_SFD_INTEGER_CHECK("liminf_y", c50_b_liminf_y);
    c50_i21 = _SFD_EML_ARRAY_BOUNDS_CHECK("im", (int32_T)_SFD_INTEGER_CHECK(
      "limsup_y", c50_limsup_y), 1, 375, 0, 0);
  }

  c50_b3 = (c50_b_liminf_x > c50_limsup_x);
  c50_b4 = c50_b3;
  c50_b5 = c50_b4;
  if (c50_b5) {
    c50_i22 = 1;
    c50_i23 = 0;
  } else {
    c50_i22 = _SFD_EML_ARRAY_BOUNDS_CHECK("im", (int32_T)_SFD_INTEGER_CHECK(
      "liminf_x", c50_b_liminf_x), 1, 500, 0, 0);
    c50_i23 = _SFD_EML_ARRAY_BOUNDS_CHECK("im", (int32_T)_SFD_INTEGER_CHECK(
      "limsup_x", c50_limsup_x), 1, 500, 0, 0);
  }

  c50_x_sizes[0] = (c50_i21 - c50_i20) + 1;
  c50_x_sizes[1] = (c50_i23 - c50_i22) + 1;
  c50_loop_ub = c50_i23 - c50_i22;
  for (c50_i24 = 0; c50_i24 <= c50_loop_ub; c50_i24++) {
    c50_b_loop_ub = c50_i21 - c50_i20;
    for (c50_i25 = 0; c50_i25 <= c50_b_loop_ub; c50_i25++) {
      chartInstance->c50_x_data[c50_i25 + c50_x_sizes[0] * c50_i24] =
        chartInstance->c50_im[((c50_i20 + c50_i25) + 375 * ((c50_i22 + c50_i24)
        - 1)) - 1];
    }
  }

  _SFD_DIM_SIZE_GEQ_CHECK(375, c50_x_sizes[0], 1);
  _SFD_DIM_SIZE_GEQ_CHECK(500, c50_x_sizes[1], 2);
  c50_b_sub_im_sizes[0] = c50_x_sizes[0];
  c50_b_sub_im_sizes[1] = c50_x_sizes[1];
  c50_sub_im = c50_b_sub_im_sizes[0];
  c50_b_sub_im = c50_b_sub_im_sizes[1];
  c50_c_loop_ub = c50_x_sizes[0] * c50_x_sizes[1] - 1;
  for (c50_i26 = 0; c50_i26 <= c50_c_loop_ub; c50_i26++) {
    chartInstance->c50_sub_im_data[c50_i26] = chartInstance->c50_x_data[c50_i26];
  }

  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 85);
  c50_x_sizes[0] = c50_b_sub_im_sizes[0];
  c50_x_sizes[1] = c50_b_sub_im_sizes[1];
  c50_x = c50_x_sizes[0];
  c50_b_x = c50_x_sizes[1];
  c50_d_loop_ub = c50_b_sub_im_sizes[0] * c50_b_sub_im_sizes[1] - 1;
  for (c50_i27 = 0; c50_i27 <= c50_d_loop_ub; c50_i27++) {
    chartInstance->c50_x_data[c50_i27] = chartInstance->c50_sub_im_data[c50_i27];
  }

  c50_b_x_sizes[0] = c50_x_sizes[0];
  c50_b_x_sizes[1] = c50_x_sizes[1];
  c50_c_x = c50_b_x_sizes[0];
  c50_d_x = c50_b_x_sizes[1];
  c50_e_loop_ub = c50_x_sizes[0] * c50_x_sizes[1] - 1;
  for (c50_i28 = 0; c50_i28 <= c50_e_loop_ub; c50_i28++) {
    c50_b_x_data[c50_i28] = chartInstance->c50_x_data[c50_i28];
  }

  c50_d8 = (real_T)c50_intlength(chartInstance, c50_b_x_data, c50_b_x_sizes);
  if (CV_EML_IF(0, 1, 12, CV_RELATIONAL_EVAL(4U, 0U, 12, c50_d8, 3.0, -1, 2U,
        c50_d8 < 3.0))) {
    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 86);
    _SFD_DIM_SIZE_GEQ_CHECK(375, 3, 1);
    _SFD_DIM_SIZE_GEQ_CHECK(500, 3, 2);
    for (c50_i29 = 0; c50_i29 < 9; c50_i29++) {
      c50_uv0[c50_i29] = 0U;
    }

    c50_b_sub_im_sizes[0] = 3;
    c50_b_sub_im_sizes[1] = 3;
    c50_c_sub_im = c50_b_sub_im_sizes[0];
    c50_d_sub_im = c50_b_sub_im_sizes[1];
    for (c50_i30 = 0; c50_i30 < 9; c50_i30++) {
      chartInstance->c50_sub_im_data[c50_i30] = c50_uv0[c50_i30];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 90);
  c50_b_im_x = c50_limsup_x - c50_b_liminf_x;
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 91);
  c50_b_im_y = c50_limsup_y - c50_b_liminf_y;
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 92);
  c50_b_rectangle[0] = c50_b_liminf_y;
  c50_b_rectangle[1] = c50_b_liminf_x;
  c50_b_rectangle[2] = c50_b_im_y;
  c50_b_rectangle[3] = c50_b_im_x;
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, -92);
  _SFD_SYMBOL_SCOPE_POP();
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1, 0,
    c50_b_sub_im_sizes[0]);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1, 1,
    c50_b_sub_im_sizes[1]);
  c50_i31 = (*chartInstance->c50_sub_im_sizes)[0];
  c50_i32 = (*chartInstance->c50_sub_im_sizes)[1];
  c50_f_loop_ub = c50_b_sub_im_sizes[0] * c50_b_sub_im_sizes[1] - 1;
  for (c50_i33 = 0; c50_i33 <= c50_f_loop_ub; c50_i33++) {
    (*chartInstance->c50_b_sub_im_data)[c50_i33] =
      chartInstance->c50_sub_im_data[c50_i33];
  }

  for (c50_i34 = 0; c50_i34 < 64; c50_i34++) {
    (*chartInstance->c50_posObj_subim)[c50_i34] = c50_b_posObj_subim[c50_i34];
  }

  *chartInstance->c50_im_x = c50_b_im_x;
  *chartInstance->c50_im_y = c50_b_im_y;
  *chartInstance->c50_liminf_x = c50_b_liminf_x;
  *chartInstance->c50_liminf_y = c50_b_liminf_y;
  for (c50_i35 = 0; c50_i35 < 4; c50_i35++) {
    (*chartInstance->c50_rectangle)[c50_i35] = c50_b_rectangle[c50_i35];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 49U, chartInstance->c50_sfEvent);
}

static void initSimStructsc50_Experiment_cs(SFc50_Experiment_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c50_machineNumber, uint32_T
  c50_chartNumber, uint32_T c50_instanceNumber)
{
  (void)c50_machineNumber;
  (void)c50_chartNumber;
  (void)c50_instanceNumber;
}

static const mxArray *c50_sf_marshallOut(void *chartInstanceVoid, void
  *c50_b_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i36;
  real_T c50_c_inData[4];
  int32_T c50_i37;
  real_T c50_u[4];
  const mxArray *c50_y = NULL;
  SFc50_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc50_Experiment_csInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i36 = 0; c50_i36 < 4; c50_i36++) {
    c50_c_inData[c50_i36] = (*(real_T (*)[4])c50_b_inData)[c50_i36];
  }

  for (c50_i37 = 0; c50_i37 < 4; c50_i37++) {
    c50_u[c50_i37] = c50_c_inData[c50_i37];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 0, 0U, 1U, 0U, 2, 1, 4), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_emlrt_marshallIn(SFc50_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c50_b_rectangle, const char_T *c50_identifier,
  real_T c50_y[4])
{
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_b_rectangle), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_b_rectangle);
}

static void c50_b_emlrt_marshallIn(SFc50_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y[4])
{
  real_T c50_dv2[4];
  int32_T c50_i38;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_dv2, 1, 0, 0U, 1, 0U, 2, 1,
                4);
  for (c50_i38 = 0; c50_i38 < 4; c50_i38++) {
    c50_y[c50_i38] = c50_dv2[c50_i38];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_b_rectangle;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  real_T c50_y[4];
  int32_T c50_i39;
  SFc50_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc50_Experiment_csInstanceStruct *)chartInstanceVoid;
  c50_b_rectangle = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_b_rectangle), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_b_rectangle);
  for (c50_i39 = 0; c50_i39 < 4; c50_i39++) {
    (*(real_T (*)[4])c50_outData)[c50_i39] = c50_y[c50_i39];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_b_sf_marshallOut(void *chartInstanceVoid, void
  *c50_b_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  real_T c50_u;
  const mxArray *c50_y = NULL;
  SFc50_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc50_Experiment_csInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_u = *(real_T *)c50_b_inData;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static real_T c50_c_emlrt_marshallIn(SFc50_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c50_b_liminf_y, const char_T *c50_identifier)
{
  real_T c50_y;
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_b_liminf_y),
    &c50_thisId);
  sf_mex_destroy(&c50_b_liminf_y);
  return c50_y;
}

static real_T c50_d_emlrt_marshallIn(SFc50_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  real_T c50_y;
  real_T c50_d9;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), &c50_d9, 1, 0, 0U, 0, 0U, 0);
  c50_y = c50_d9;
  sf_mex_destroy(&c50_u);
  return c50_y;
}

static void c50_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_b_liminf_y;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  real_T c50_y;
  SFc50_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc50_Experiment_csInstanceStruct *)chartInstanceVoid;
  c50_b_liminf_y = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_b_liminf_y),
    &c50_thisId);
  sf_mex_destroy(&c50_b_liminf_y);
  *(real_T *)c50_outData = c50_y;
  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_c_sf_marshallOut(void *chartInstanceVoid, void
  *c50_b_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i40;
  int32_T c50_i41;
  int32_T c50_i42;
  real_T c50_c_inData[64];
  int32_T c50_i43;
  int32_T c50_i44;
  int32_T c50_i45;
  real_T c50_u[64];
  const mxArray *c50_y = NULL;
  SFc50_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc50_Experiment_csInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_i40 = 0;
  for (c50_i41 = 0; c50_i41 < 32; c50_i41++) {
    for (c50_i42 = 0; c50_i42 < 2; c50_i42++) {
      c50_c_inData[c50_i42 + c50_i40] = (*(real_T (*)[64])c50_b_inData)[c50_i42
        + c50_i40];
    }

    c50_i40 += 2;
  }

  c50_i43 = 0;
  for (c50_i44 = 0; c50_i44 < 32; c50_i44++) {
    for (c50_i45 = 0; c50_i45 < 2; c50_i45++) {
      c50_u[c50_i45 + c50_i43] = c50_c_inData[c50_i45 + c50_i43];
    }

    c50_i43 += 2;
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 0, 0U, 1U, 0U, 2, 2, 32),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_e_emlrt_marshallIn(SFc50_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c50_b_posObj_subim, const char_T
  *c50_identifier, real_T c50_y[64])
{
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_b_posObj_subim),
    &c50_thisId, c50_y);
  sf_mex_destroy(&c50_b_posObj_subim);
}

static void c50_f_emlrt_marshallIn(SFc50_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y[64])
{
  real_T c50_dv3[64];
  int32_T c50_i46;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_dv3, 1, 0, 0U, 1, 0U, 2, 2,
                32);
  for (c50_i46 = 0; c50_i46 < 64; c50_i46++) {
    c50_y[c50_i46] = c50_dv3[c50_i46];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_b_posObj_subim;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  real_T c50_y[64];
  int32_T c50_i47;
  int32_T c50_i48;
  int32_T c50_i49;
  SFc50_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc50_Experiment_csInstanceStruct *)chartInstanceVoid;
  c50_b_posObj_subim = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_b_posObj_subim),
    &c50_thisId, c50_y);
  sf_mex_destroy(&c50_b_posObj_subim);
  c50_i47 = 0;
  for (c50_i48 = 0; c50_i48 < 32; c50_i48++) {
    for (c50_i49 = 0; c50_i49 < 2; c50_i49++) {
      (*(real_T (*)[64])c50_outData)[c50_i49 + c50_i47] = c50_y[c50_i49 +
        c50_i47];
    }

    c50_i47 += 2;
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_d_sf_marshallOut(void *chartInstanceVoid, uint8_T
  c50_b_inData_data[], int32_T c50_inData_sizes[2])
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_u_sizes[2];
  int32_T c50_u;
  int32_T c50_b_u;
  int32_T c50_b_inData;
  int32_T c50_c_inData;
  int32_T c50_b_inData_sizes;
  int32_T c50_loop_ub;
  int32_T c50_i50;
  int32_T c50_b_loop_ub;
  int32_T c50_i51;
  uint8_T c50_u_data[187500];
  const mxArray *c50_y = NULL;
  SFc50_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc50_Experiment_csInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_u_sizes[0] = c50_inData_sizes[0];
  c50_u_sizes[1] = c50_inData_sizes[1];
  c50_u = c50_u_sizes[0];
  c50_b_u = c50_u_sizes[1];
  c50_b_inData = c50_inData_sizes[0];
  c50_c_inData = c50_inData_sizes[1];
  c50_b_inData_sizes = c50_b_inData * c50_c_inData;
  c50_loop_ub = c50_b_inData * c50_c_inData - 1;
  for (c50_i50 = 0; c50_i50 <= c50_loop_ub; c50_i50++) {
    chartInstance->c50_inData_data[c50_i50] = c50_b_inData_data[c50_i50];
  }

  c50_b_loop_ub = c50_b_inData_sizes - 1;
  for (c50_i51 = 0; c50_i51 <= c50_b_loop_ub; c50_i51++) {
    c50_u_data[c50_i51] = chartInstance->c50_inData_data[c50_i51];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u_data, 3, 0U, 1U, 0U, 2,
    c50_u_sizes[0], c50_u_sizes[1]), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_g_emlrt_marshallIn(SFc50_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c50_sub_im, const char_T *c50_identifier,
  uint8_T c50_b_y_data[], int32_T c50_y_sizes[2])
{
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_sub_im), &c50_thisId,
    c50_b_y_data, c50_y_sizes);
  sf_mex_destroy(&c50_sub_im);
}

static void c50_h_emlrt_marshallIn(SFc50_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  uint8_T c50_b_y_data[], int32_T c50_y_sizes[2])
{
  int32_T c50_i52;
  uint32_T c50_uv1[2];
  int32_T c50_i53;
  boolean_T c50_bv0[2];
  int32_T c50_tmp_sizes[2];
  uint8_T c50_b_tmp_data[187500];
  int32_T c50_y;
  int32_T c50_b_y;
  int32_T c50_loop_ub;
  int32_T c50_i54;
  (void)chartInstance;
  for (c50_i52 = 0; c50_i52 < 2; c50_i52++) {
    c50_uv1[c50_i52] = 375U + 125U * (uint32_T)c50_i52;
  }

  for (c50_i53 = 0; c50_i53 < 2; c50_i53++) {
    c50_bv0[c50_i53] = true;
  }

  sf_mex_import_vs(c50_parentId, sf_mex_dup(c50_u), c50_b_tmp_data, 1, 3, 0U, 1,
                   0U, 2, c50_bv0, c50_uv1, c50_tmp_sizes);
  c50_y_sizes[0] = c50_tmp_sizes[0];
  c50_y_sizes[1] = c50_tmp_sizes[1];
  c50_y = c50_y_sizes[0];
  c50_b_y = c50_y_sizes[1];
  c50_loop_ub = c50_tmp_sizes[0] * c50_tmp_sizes[1] - 1;
  for (c50_i54 = 0; c50_i54 <= c50_loop_ub; c50_i54++) {
    c50_b_y_data[c50_i54] = c50_b_tmp_data[c50_i54];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, uint8_T c50_outData_data[],
  int32_T c50_outData_sizes[2])
{
  const mxArray *c50_sub_im;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  int32_T c50_y_sizes[2];
  int32_T c50_loop_ub;
  int32_T c50_i55;
  int32_T c50_b_loop_ub;
  int32_T c50_i56;
  SFc50_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc50_Experiment_csInstanceStruct *)chartInstanceVoid;
  c50_sub_im = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_sub_im), &c50_thisId,
    chartInstance->c50_y_data, c50_y_sizes);
  sf_mex_destroy(&c50_sub_im);
  c50_outData_sizes[0] = c50_y_sizes[0];
  c50_outData_sizes[1] = c50_y_sizes[1];
  c50_loop_ub = c50_y_sizes[1] - 1;
  for (c50_i55 = 0; c50_i55 <= c50_loop_ub; c50_i55++) {
    c50_b_loop_ub = c50_y_sizes[0] - 1;
    for (c50_i56 = 0; c50_i56 <= c50_b_loop_ub; c50_i56++) {
      c50_outData_data[c50_i56 + c50_outData_sizes[0] * c50_i55] =
        chartInstance->c50_y_data[c50_i56 + c50_y_sizes[0] * c50_i55];
    }
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_e_sf_marshallOut(void *chartInstanceVoid, void
  *c50_b_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i57;
  real_T c50_c_inData[32];
  int32_T c50_i58;
  real_T c50_u[32];
  const mxArray *c50_y = NULL;
  SFc50_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc50_Experiment_csInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i57 = 0; c50_i57 < 32; c50_i57++) {
    c50_c_inData[c50_i57] = (*(real_T (*)[32])c50_b_inData)[c50_i57];
  }

  for (c50_i58 = 0; c50_i58 < 32; c50_i58++) {
    c50_u[c50_i58] = c50_c_inData[c50_i58];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 0, 0U, 1U, 0U, 2, 1, 32),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static const mxArray *c50_f_sf_marshallOut(void *chartInstanceVoid, void
  *c50_b_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i59;
  int32_T c50_i60;
  int32_T c50_i61;
  int32_T c50_i62;
  int32_T c50_i63;
  int32_T c50_i64;
  uint8_T c50_u[187500];
  const mxArray *c50_y = NULL;
  SFc50_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc50_Experiment_csInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_i59 = 0;
  for (c50_i60 = 0; c50_i60 < 500; c50_i60++) {
    for (c50_i61 = 0; c50_i61 < 375; c50_i61++) {
      chartInstance->c50_inData[c50_i61 + c50_i59] = (*(uint8_T (*)[187500])
        c50_b_inData)[c50_i61 + c50_i59];
    }

    c50_i59 += 375;
  }

  c50_i62 = 0;
  for (c50_i63 = 0; c50_i63 < 500; c50_i63++) {
    for (c50_i64 = 0; c50_i64 < 375; c50_i64++) {
      c50_u[c50_i64 + c50_i62] = chartInstance->c50_inData[c50_i64 + c50_i62];
    }

    c50_i62 += 375;
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 3, 0U, 1U, 0U, 2, 375, 500),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

const mxArray *sf_c50_Experiment_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c50_nameCaptureInfo = NULL;
  c50_nameCaptureInfo = NULL;
  sf_mex_assign(&c50_nameCaptureInfo, sf_mex_createstruct("structure", 2, 13, 1),
                false);
  c50_info_helper(&c50_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c50_nameCaptureInfo);
  return c50_nameCaptureInfo;
}

static void c50_info_helper(const mxArray **c50_info)
{
  const mxArray *c50_rhs0 = NULL;
  const mxArray *c50_lhs0 = NULL;
  const mxArray *c50_rhs1 = NULL;
  const mxArray *c50_lhs1 = NULL;
  const mxArray *c50_rhs2 = NULL;
  const mxArray *c50_lhs2 = NULL;
  const mxArray *c50_rhs3 = NULL;
  const mxArray *c50_lhs3 = NULL;
  const mxArray *c50_rhs4 = NULL;
  const mxArray *c50_lhs4 = NULL;
  const mxArray *c50_rhs5 = NULL;
  const mxArray *c50_lhs5 = NULL;
  const mxArray *c50_rhs6 = NULL;
  const mxArray *c50_lhs6 = NULL;
  const mxArray *c50_rhs7 = NULL;
  const mxArray *c50_lhs7 = NULL;
  const mxArray *c50_rhs8 = NULL;
  const mxArray *c50_lhs8 = NULL;
  const mxArray *c50_rhs9 = NULL;
  const mxArray *c50_lhs9 = NULL;
  const mxArray *c50_rhs10 = NULL;
  const mxArray *c50_lhs10 = NULL;
  const mxArray *c50_rhs11 = NULL;
  const mxArray *c50_lhs11 = NULL;
  const mxArray *c50_rhs12 = NULL;
  const mxArray *c50_lhs12 = NULL;
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("round"), "name", "name", 0);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c50_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c50_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_scalar_round"), "name",
                  "name", 2);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1307672838U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c50_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "context", "context", 3);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("abs"), "name", "name", 3);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c50_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c50_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 5);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c50_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "context", "context", 6);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("length"), "name", "name", 6);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("uint8"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1303167806U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c50_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength"),
                  "context", "context", 7);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 7);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c50_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength"),
                  "context", "context", 8);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.indexIntRelop"), "name", "name", 8);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1326749922U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c50_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!apply_float_relop"),
                  "context", "context", 9);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 9);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c50_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass"),
                  "context", "context", 10);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 10);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c50_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass"),
                  "context", "context", 11);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("intmin"), "name", "name", 11);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c50_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 12);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c50_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs12), "lhs", "lhs",
                  12);
  sf_mex_destroy(&c50_rhs0);
  sf_mex_destroy(&c50_lhs0);
  sf_mex_destroy(&c50_rhs1);
  sf_mex_destroy(&c50_lhs1);
  sf_mex_destroy(&c50_rhs2);
  sf_mex_destroy(&c50_lhs2);
  sf_mex_destroy(&c50_rhs3);
  sf_mex_destroy(&c50_lhs3);
  sf_mex_destroy(&c50_rhs4);
  sf_mex_destroy(&c50_lhs4);
  sf_mex_destroy(&c50_rhs5);
  sf_mex_destroy(&c50_lhs5);
  sf_mex_destroy(&c50_rhs6);
  sf_mex_destroy(&c50_lhs6);
  sf_mex_destroy(&c50_rhs7);
  sf_mex_destroy(&c50_lhs7);
  sf_mex_destroy(&c50_rhs8);
  sf_mex_destroy(&c50_lhs8);
  sf_mex_destroy(&c50_rhs9);
  sf_mex_destroy(&c50_lhs9);
  sf_mex_destroy(&c50_rhs10);
  sf_mex_destroy(&c50_lhs10);
  sf_mex_destroy(&c50_rhs11);
  sf_mex_destroy(&c50_lhs11);
  sf_mex_destroy(&c50_rhs12);
  sf_mex_destroy(&c50_lhs12);
}

static const mxArray *c50_emlrt_marshallOut(const char * c50_u)
{
  const mxArray *c50_y = NULL;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c50_u)), false);
  return c50_y;
}

static const mxArray *c50_b_emlrt_marshallOut(const uint32_T c50_u)
{
  const mxArray *c50_y = NULL;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 7, 0U, 0U, 0U, 0), false);
  return c50_y;
}

static real_T c50_round(SFc50_Experiment_csInstanceStruct *chartInstance, real_T
  c50_x)
{
  real_T c50_b_x;
  c50_b_x = c50_x;
  c50_b_round(chartInstance, &c50_b_x);
  return c50_b_x;
}

static real_T c50_abs(SFc50_Experiment_csInstanceStruct *chartInstance, real_T
                      c50_x)
{
  real_T c50_b_x;
  (void)chartInstance;
  c50_b_x = c50_x;
  return muDoubleScalarAbs(c50_b_x);
}

static int32_T c50_intlength(SFc50_Experiment_csInstanceStruct *chartInstance,
  uint8_T c50_b_x_data[], int32_T c50_x_sizes[2])
{
  int32_T c50_n;
  real_T c50_a;
  real_T c50_b_a;
  real_T c50_flt;
  boolean_T c50_p;
  real_T c50_c_a;
  real_T c50_d_a;
  real_T c50_b_flt;
  boolean_T c50_b_p;
  boolean_T guard1 = false;
  (void)chartInstance;
  (void)c50_b_x_data;
  c50_a = (real_T)c50_x_sizes[0];
  c50_b_a = c50_a;
  c50_flt = c50_b_a;
  c50_p = (0.0 == c50_flt);
  guard1 = false;
  if (c50_p) {
    guard1 = true;
  } else {
    c50_c_a = (real_T)c50_x_sizes[1];
    c50_d_a = c50_c_a;
    c50_b_flt = c50_d_a;
    c50_b_p = (0.0 == c50_b_flt);
    if (c50_b_p) {
      guard1 = true;
    } else if ((real_T)c50_x_sizes[0] > (real_T)c50_x_sizes[1]) {
      c50_n = c50_x_sizes[0];
    } else {
      c50_n = c50_x_sizes[1];
    }
  }

  if (guard1 == true) {
    c50_n = 0;
  }

  return c50_n;
}

static const mxArray *c50_g_sf_marshallOut(void *chartInstanceVoid, void
  *c50_b_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_u;
  const mxArray *c50_y = NULL;
  SFc50_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc50_Experiment_csInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_u = *(int32_T *)c50_b_inData;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static int32_T c50_i_emlrt_marshallIn(SFc50_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  int32_T c50_y;
  int32_T c50_i65;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), &c50_i65, 1, 6, 0U, 0, 0U, 0);
  c50_y = c50_i65;
  sf_mex_destroy(&c50_u);
  return c50_y;
}

static void c50_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_b_sfEvent;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  int32_T c50_y;
  SFc50_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc50_Experiment_csInstanceStruct *)chartInstanceVoid;
  c50_b_sfEvent = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_b_sfEvent),
    &c50_thisId);
  sf_mex_destroy(&c50_b_sfEvent);
  *(int32_T *)c50_outData = c50_y;
  sf_mex_destroy(&c50_mxArrayInData);
}

static uint8_T c50_j_emlrt_marshallIn(SFc50_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c50_b_is_active_c50_Experiment_cs, const char_T
  *c50_identifier)
{
  uint8_T c50_y;
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c50_b_is_active_c50_Experiment_cs), &c50_thisId);
  sf_mex_destroy(&c50_b_is_active_c50_Experiment_cs);
  return c50_y;
}

static uint8_T c50_k_emlrt_marshallIn(SFc50_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  uint8_T c50_y;
  uint8_T c50_u0;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), &c50_u0, 1, 3, 0U, 0, 0U, 0);
  c50_y = c50_u0;
  sf_mex_destroy(&c50_u);
  return c50_y;
}

static void c50_b_round(SFc50_Experiment_csInstanceStruct *chartInstance, real_T
  *c50_x)
{
  (void)chartInstance;
  *c50_x = muDoubleScalarRound(*c50_x);
}

static void init_dsm_address_info(SFc50_Experiment_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc50_Experiment_csInstanceStruct
  *chartInstance)
{
  chartInstance->c50_b_im = (uint8_T (*)[187500])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c50_PosObj = (real_T (*)[64])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c50_X = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c50_Y = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c50_b_sub_im_data = (uint8_T (*)[187500])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c50_sub_im_sizes = (int32_T (*)[2])
    ssGetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1);
  chartInstance->c50_posObj_subim = (real_T (*)[64])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c50_im_x = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c50_im_y = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c50_liminf_x = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c50_liminf_y = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c50_rectangle = (real_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 7);
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

void sf_c50_Experiment_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(928763364U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3021481460U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1804990352U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1296217343U);
}

mxArray* sf_c50_Experiment_cs_get_post_codegen_info(void);
mxArray *sf_c50_Experiment_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("QbOVimdLD6biFcW1j7F4q");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(375);
      pr[1] = (double)(500);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(32);
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
      pr[1] = (double)(32);
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
      pr[1] = (double)(32);
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

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(375);
      pr[1] = (double)(500);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(32);
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
      pr[0] = (double)(1);
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
      pr[1] = (double)(4);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c50_Experiment_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c50_Experiment_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c50_Experiment_cs_jit_fallback_info(void)
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

mxArray *sf_c50_Experiment_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c50_Experiment_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c50_Experiment_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[16],T\"im_x\",},{M[1],M[17],T\"im_y\",},{M[1],M[18],T\"liminf_x\",},{M[1],M[19],T\"liminf_y\",},{M[1],M[15],T\"posObj_subim\",},{M[1],M[20],T\"rectangle\",},{M[1],M[14],T\"sub_im\",},{M[8],M[0],T\"is_active_c50_Experiment_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c50_Experiment_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc50_Experiment_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc50_Experiment_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_csMachineNumber_,
           50,
           1,
           1,
           0,
           11,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_Experiment_csMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Experiment_csMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Experiment_csMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"im");
          _SFD_SET_DATA_PROPS(1,1,1,0,"PosObj");
          _SFD_SET_DATA_PROPS(2,1,1,0,"X");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Y");
          _SFD_SET_DATA_PROPS(4,2,0,1,"sub_im");
          _SFD_SET_DATA_PROPS(5,2,0,1,"posObj_subim");
          _SFD_SET_DATA_PROPS(6,2,0,1,"im_x");
          _SFD_SET_DATA_PROPS(7,2,0,1,"im_y");
          _SFD_SET_DATA_PROPS(8,2,0,1,"liminf_x");
          _SFD_SET_DATA_PROPS(9,2,0,1,"liminf_y");
          _SFD_SET_DATA_PROPS(10,2,0,1,"rectangle");
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
        _SFD_CV_INIT_EML(0,1,1,13,0,0,0,2,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1809);
        _SFD_CV_INIT_EML_IF(0,1,0,204,221,-1,507);
        _SFD_CV_INIT_EML_IF(0,1,1,230,251,-1,345);
        _SFD_CV_INIT_EML_IF(0,1,2,354,376,-1,470);
        _SFD_CV_INIT_EML_IF(0,1,3,512,528,632,1082);
        _SFD_CV_INIT_EML_IF(0,1,4,688,700,822,866);
        _SFD_CV_INIT_EML_IF(0,1,5,870,882,1010,1077);
        _SFD_CV_INIT_EML_IF(0,1,6,1086,1101,-1,1128);
        _SFD_CV_INIT_EML_IF(0,1,7,1136,1160,-1,1195);
        _SFD_CV_INIT_EML_IF(0,1,8,1203,1218,-1,1243);
        _SFD_CV_INIT_EML_IF(0,1,9,1251,1276,-1,1310);
        _SFD_CV_INIT_EML_IF(0,1,10,1316,1342,-1,1379);
        _SFD_CV_INIT_EML_IF(0,1,11,1474,1493,-1,1599);
        _SFD_CV_INIT_EML_IF(0,1,12,1658,1681,-1,1718);
        _SFD_CV_INIT_EML_FOR(0,1,0,177,200,511);
        _SFD_CV_INIT_EML_FOR(0,1,1,1443,1466,1607);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,207,221,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,233,250,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,358,375,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,516,527,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,4,692,699,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,5,874,881,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,6,1090,1100,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,7,1140,1159,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,8,1207,1217,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,9,1255,1275,-1,5);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,10,1320,1341,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,11,1478,1492,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,12,1661,1681,-1,2);

        {
          unsigned int dimVector[2];
          dimVector[0]= 375;
          dimVector[1]= 500;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 375;
          dimVector[1]= 500;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_d_sf_marshallOut,(MexInFcnForType)
            c50_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_c_sf_marshallOut,(MexInFcnForType)
            c50_c_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_b_sf_marshallOut,(MexInFcnForType)
          c50_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_b_sf_marshallOut,(MexInFcnForType)
          c50_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_b_sf_marshallOut,(MexInFcnForType)
          c50_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_b_sf_marshallOut,(MexInFcnForType)
          c50_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)
            c50_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c50_b_im);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c50_PosObj);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c50_X);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c50_Y);
        _SFD_SET_DATA_VALUE_PTR_VAR_DIM(4U, *chartInstance->c50_b_sub_im_data,
          (void *)chartInstance->c50_sub_im_sizes);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c50_posObj_subim);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c50_im_x);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c50_im_y);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c50_liminf_x);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c50_liminf_y);
        _SFD_SET_DATA_VALUE_PTR(10U, *chartInstance->c50_rectangle);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Experiment_csMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "RlznJxzpa5Wmk1dcipe7PG";
}

static void sf_opaque_initialize_c50_Experiment_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc50_Experiment_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c50_Experiment_cs((SFc50_Experiment_csInstanceStruct*)
    chartInstanceVar);
  initialize_c50_Experiment_cs((SFc50_Experiment_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c50_Experiment_cs(void *chartInstanceVar)
{
  enable_c50_Experiment_cs((SFc50_Experiment_csInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c50_Experiment_cs(void *chartInstanceVar)
{
  disable_c50_Experiment_cs((SFc50_Experiment_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c50_Experiment_cs(void *chartInstanceVar)
{
  sf_gateway_c50_Experiment_cs((SFc50_Experiment_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c50_Experiment_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c50_Experiment_cs((SFc50_Experiment_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c50_Experiment_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c50_Experiment_cs((SFc50_Experiment_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c50_Experiment_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc50_Experiment_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_cs_optimization_info();
    }

    finalize_c50_Experiment_cs((SFc50_Experiment_csInstanceStruct*)
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
  initSimStructsc50_Experiment_cs((SFc50_Experiment_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c50_Experiment_cs(SimStruct *S)
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
    initialize_params_c50_Experiment_cs((SFc50_Experiment_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c50_Experiment_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Experiment_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      50);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,50,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,50,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,50);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,50,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,50,7);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=7; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,50);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1932760878U));
  ssSetChecksum1(S,(3278357735U));
  ssSetChecksum2(S,(2883240903U));
  ssSetChecksum3(S,(695034528U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c50_Experiment_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c50_Experiment_cs(SimStruct *S)
{
  SFc50_Experiment_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc50_Experiment_csInstanceStruct *)utMalloc(sizeof
    (SFc50_Experiment_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc50_Experiment_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c50_Experiment_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c50_Experiment_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c50_Experiment_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c50_Experiment_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c50_Experiment_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c50_Experiment_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c50_Experiment_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c50_Experiment_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c50_Experiment_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c50_Experiment_cs;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c50_Experiment_cs;
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

void c50_Experiment_cs_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c50_Experiment_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c50_Experiment_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c50_Experiment_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c50_Experiment_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
