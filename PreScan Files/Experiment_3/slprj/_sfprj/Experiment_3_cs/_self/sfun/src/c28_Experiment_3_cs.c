/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_3_cs_sfun.h"
#include "c28_Experiment_3_cs.h"
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
static const char * c28_debug_family_names[24] = { "minPx", "minPy", "maxPx",
  "maxPy", "detected", "mino", "maxo", "i", "limsup_x", "limsup_y", "a",
  "nargin", "nargout", "im", "PosObj", "X", "Y", "sub_im", "posObj_subim",
  "im_x", "im_y", "liminf_x", "liminf_y", "rectangle" };

/* Function Declarations */
static void initialize_c28_Experiment_3_cs(SFc28_Experiment_3_csInstanceStruct
  *chartInstance);
static void initialize_params_c28_Experiment_3_cs
  (SFc28_Experiment_3_csInstanceStruct *chartInstance);
static void enable_c28_Experiment_3_cs(SFc28_Experiment_3_csInstanceStruct
  *chartInstance);
static void disable_c28_Experiment_3_cs(SFc28_Experiment_3_csInstanceStruct
  *chartInstance);
static void c28_update_debugger_state_c28_Experiment_3_cs
  (SFc28_Experiment_3_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c28_Experiment_3_cs
  (SFc28_Experiment_3_csInstanceStruct *chartInstance);
static void set_sim_state_c28_Experiment_3_cs
  (SFc28_Experiment_3_csInstanceStruct *chartInstance, const mxArray *c28_st);
static void finalize_c28_Experiment_3_cs(SFc28_Experiment_3_csInstanceStruct
  *chartInstance);
static void sf_gateway_c28_Experiment_3_cs(SFc28_Experiment_3_csInstanceStruct
  *chartInstance);
static void mdl_start_c28_Experiment_3_cs(SFc28_Experiment_3_csInstanceStruct
  *chartInstance);
static void c28_chartstep_c28_Experiment_3_cs
  (SFc28_Experiment_3_csInstanceStruct *chartInstance);
static void initSimStructsc28_Experiment_3_cs
  (SFc28_Experiment_3_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c28_machineNumber, uint32_T
  c28_chartNumber, uint32_T c28_instanceNumber);
static const mxArray *c28_sf_marshallOut(void *chartInstanceVoid, void
  *c28_b_inData);
static void c28_emlrt_marshallIn(SFc28_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c28_b_rectangle, const char_T *c28_identifier,
  real_T c28_y[4]);
static void c28_b_emlrt_marshallIn(SFc28_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId,
  real_T c28_y[4]);
static void c28_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData);
static const mxArray *c28_b_sf_marshallOut(void *chartInstanceVoid, void
  *c28_b_inData);
static real_T c28_c_emlrt_marshallIn(SFc28_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c28_b_liminf_y, const char_T *c28_identifier);
static real_T c28_d_emlrt_marshallIn(SFc28_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId);
static void c28_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData);
static const mxArray *c28_c_sf_marshallOut(void *chartInstanceVoid, void
  *c28_b_inData);
static void c28_e_emlrt_marshallIn(SFc28_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c28_b_posObj_subim, const char_T
  *c28_identifier, real_T c28_y[64]);
static void c28_f_emlrt_marshallIn(SFc28_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId,
  real_T c28_y[64]);
static void c28_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData);
static const mxArray *c28_d_sf_marshallOut(void *chartInstanceVoid, uint8_T
  c28_b_inData_data[], int32_T c28_inData_sizes[2]);
static void c28_g_emlrt_marshallIn(SFc28_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c28_sub_im, const char_T *c28_identifier,
  uint8_T c28_b_y_data[], int32_T c28_y_sizes[2]);
static void c28_h_emlrt_marshallIn(SFc28_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId,
  uint8_T c28_b_y_data[], int32_T c28_y_sizes[2]);
static void c28_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, uint8_T c28_outData_data[],
  int32_T c28_outData_sizes[2]);
static const mxArray *c28_e_sf_marshallOut(void *chartInstanceVoid, void
  *c28_b_inData);
static const mxArray *c28_f_sf_marshallOut(void *chartInstanceVoid, void
  *c28_b_inData);
static void c28_info_helper(const mxArray **c28_info);
static const mxArray *c28_emlrt_marshallOut(const char * c28_u);
static const mxArray *c28_b_emlrt_marshallOut(const uint32_T c28_u);
static real_T c28_round(SFc28_Experiment_3_csInstanceStruct *chartInstance,
  real_T c28_x);
static real_T c28_abs(SFc28_Experiment_3_csInstanceStruct *chartInstance, real_T
                      c28_x);
static int32_T c28_intlength(SFc28_Experiment_3_csInstanceStruct *chartInstance,
  uint8_T c28_b_x_data[], int32_T c28_x_sizes[2]);
static const mxArray *c28_g_sf_marshallOut(void *chartInstanceVoid, void
  *c28_b_inData);
static int32_T c28_i_emlrt_marshallIn(SFc28_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId);
static void c28_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData);
static uint8_T c28_j_emlrt_marshallIn(SFc28_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c28_b_is_active_c28_Experiment_3_cs, const
  char_T *c28_identifier);
static uint8_T c28_k_emlrt_marshallIn(SFc28_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId);
static void c28_b_round(SFc28_Experiment_3_csInstanceStruct *chartInstance,
  real_T *c28_x);
static void init_dsm_address_info(SFc28_Experiment_3_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc28_Experiment_3_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c28_Experiment_3_cs(SFc28_Experiment_3_csInstanceStruct
  *chartInstance)
{
  chartInstance->c28_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c28_is_active_c28_Experiment_3_cs = 0U;
}

static void initialize_params_c28_Experiment_3_cs
  (SFc28_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c28_Experiment_3_cs(SFc28_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c28_Experiment_3_cs(SFc28_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c28_update_debugger_state_c28_Experiment_3_cs
  (SFc28_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c28_Experiment_3_cs
  (SFc28_Experiment_3_csInstanceStruct *chartInstance)
{
  const mxArray *c28_st;
  const mxArray *c28_y = NULL;
  real_T c28_hoistedGlobal;
  real_T c28_u;
  const mxArray *c28_b_y = NULL;
  real_T c28_b_hoistedGlobal;
  real_T c28_b_u;
  const mxArray *c28_c_y = NULL;
  real_T c28_c_hoistedGlobal;
  real_T c28_c_u;
  const mxArray *c28_d_y = NULL;
  real_T c28_d_hoistedGlobal;
  real_T c28_d_u;
  const mxArray *c28_e_y = NULL;
  int32_T c28_i0;
  real_T c28_e_u[64];
  const mxArray *c28_f_y = NULL;
  int32_T c28_i1;
  real_T c28_f_u[4];
  const mxArray *c28_g_y = NULL;
  int32_T c28_u_sizes[2];
  int32_T c28_g_u;
  int32_T c28_h_u;
  int32_T c28_loop_ub;
  int32_T c28_i2;
  uint8_T c28_u_data[187500];
  const mxArray *c28_h_y = NULL;
  uint8_T c28_e_hoistedGlobal;
  uint8_T c28_i_u;
  const mxArray *c28_i_y = NULL;
  c28_st = NULL;
  c28_st = NULL;
  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_createcellmatrix(8, 1), false);
  c28_hoistedGlobal = *chartInstance->c28_im_x;
  c28_u = c28_hoistedGlobal;
  c28_b_y = NULL;
  sf_mex_assign(&c28_b_y, sf_mex_create("y", &c28_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c28_y, 0, c28_b_y);
  c28_b_hoistedGlobal = *chartInstance->c28_im_y;
  c28_b_u = c28_b_hoistedGlobal;
  c28_c_y = NULL;
  sf_mex_assign(&c28_c_y, sf_mex_create("y", &c28_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c28_y, 1, c28_c_y);
  c28_c_hoistedGlobal = *chartInstance->c28_liminf_x;
  c28_c_u = c28_c_hoistedGlobal;
  c28_d_y = NULL;
  sf_mex_assign(&c28_d_y, sf_mex_create("y", &c28_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c28_y, 2, c28_d_y);
  c28_d_hoistedGlobal = *chartInstance->c28_liminf_y;
  c28_d_u = c28_d_hoistedGlobal;
  c28_e_y = NULL;
  sf_mex_assign(&c28_e_y, sf_mex_create("y", &c28_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c28_y, 3, c28_e_y);
  for (c28_i0 = 0; c28_i0 < 64; c28_i0++) {
    c28_e_u[c28_i0] = (*chartInstance->c28_posObj_subim)[c28_i0];
  }

  c28_f_y = NULL;
  sf_mex_assign(&c28_f_y, sf_mex_create("y", c28_e_u, 0, 0U, 1U, 0U, 2, 2, 32),
                false);
  sf_mex_setcell(c28_y, 4, c28_f_y);
  for (c28_i1 = 0; c28_i1 < 4; c28_i1++) {
    c28_f_u[c28_i1] = (*chartInstance->c28_rectangle)[c28_i1];
  }

  c28_g_y = NULL;
  sf_mex_assign(&c28_g_y, sf_mex_create("y", c28_f_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_setcell(c28_y, 5, c28_g_y);
  c28_u_sizes[0] = (*chartInstance->c28_sub_im_sizes)[0];
  c28_u_sizes[1] = (*chartInstance->c28_sub_im_sizes)[1];
  c28_g_u = c28_u_sizes[0];
  c28_h_u = c28_u_sizes[1];
  c28_loop_ub = (*chartInstance->c28_sub_im_sizes)[0] *
    (*chartInstance->c28_sub_im_sizes)[1] - 1;
  for (c28_i2 = 0; c28_i2 <= c28_loop_ub; c28_i2++) {
    c28_u_data[c28_i2] = (*chartInstance->c28_b_sub_im_data)[c28_i2];
  }

  c28_h_y = NULL;
  sf_mex_assign(&c28_h_y, sf_mex_create("y", c28_u_data, 3, 0U, 1U, 0U, 2,
    c28_u_sizes[0], c28_u_sizes[1]), false);
  sf_mex_setcell(c28_y, 6, c28_h_y);
  c28_e_hoistedGlobal = chartInstance->c28_is_active_c28_Experiment_3_cs;
  c28_i_u = c28_e_hoistedGlobal;
  c28_i_y = NULL;
  sf_mex_assign(&c28_i_y, sf_mex_create("y", &c28_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c28_y, 7, c28_i_y);
  sf_mex_assign(&c28_st, c28_y, false);
  return c28_st;
}

static void set_sim_state_c28_Experiment_3_cs
  (SFc28_Experiment_3_csInstanceStruct *chartInstance, const mxArray *c28_st)
{
  const mxArray *c28_u;
  real_T c28_dv0[64];
  int32_T c28_i3;
  real_T c28_dv1[4];
  int32_T c28_i4;
  int32_T c28_tmp_sizes[2];
  int32_T c28_i5;
  int32_T c28_i6;
  int32_T c28_loop_ub;
  int32_T c28_i7;
  chartInstance->c28_doneDoubleBufferReInit = true;
  c28_u = sf_mex_dup(c28_st);
  *chartInstance->c28_im_x = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c28_u, 0)), "im_x");
  *chartInstance->c28_im_y = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c28_u, 1)), "im_y");
  *chartInstance->c28_liminf_x = c28_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c28_u, 2)), "liminf_x");
  *chartInstance->c28_liminf_y = c28_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c28_u, 3)), "liminf_y");
  c28_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c28_u, 4)),
    "posObj_subim", c28_dv0);
  for (c28_i3 = 0; c28_i3 < 64; c28_i3++) {
    (*chartInstance->c28_posObj_subim)[c28_i3] = c28_dv0[c28_i3];
  }

  c28_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c28_u, 5)),
                       "rectangle", c28_dv1);
  for (c28_i4 = 0; c28_i4 < 4; c28_i4++) {
    (*chartInstance->c28_rectangle)[c28_i4] = c28_dv1[c28_i4];
  }

  c28_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c28_u, 6)),
    "sub_im", chartInstance->c28_tmp_data, c28_tmp_sizes);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1, 0,
    c28_tmp_sizes[0]);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1, 1,
    c28_tmp_sizes[1]);
  c28_i5 = (*chartInstance->c28_sub_im_sizes)[0];
  c28_i6 = (*chartInstance->c28_sub_im_sizes)[1];
  c28_loop_ub = c28_tmp_sizes[0] * c28_tmp_sizes[1] - 1;
  for (c28_i7 = 0; c28_i7 <= c28_loop_ub; c28_i7++) {
    (*chartInstance->c28_b_sub_im_data)[c28_i7] = chartInstance->
      c28_tmp_data[c28_i7];
  }

  chartInstance->c28_is_active_c28_Experiment_3_cs = c28_j_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c28_u, 7)),
     "is_active_c28_Experiment_3_cs");
  sf_mex_destroy(&c28_u);
  c28_update_debugger_state_c28_Experiment_3_cs(chartInstance);
  sf_mex_destroy(&c28_st);
}

static void finalize_c28_Experiment_3_cs(SFc28_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c28_Experiment_3_cs(SFc28_Experiment_3_csInstanceStruct
  *chartInstance)
{
  int32_T c28_i8;
  int32_T c28_i9;
  int32_T c28_i10;
  int32_T c28_i11;
  int32_T c28_loop_ub;
  int32_T c28_i12;
  int32_T c28_i13;
  int32_T c28_i14;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 27U, chartInstance->c28_sfEvent);
  for (c28_i8 = 0; c28_i8 < 187500; c28_i8++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c28_b_im)[c28_i8], 0U);
  }

  for (c28_i9 = 0; c28_i9 < 64; c28_i9++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c28_PosObj)[c28_i9], 1U);
  }

  for (c28_i10 = 0; c28_i10 < 32; c28_i10++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c28_X)[c28_i10], 2U);
  }

  for (c28_i11 = 0; c28_i11 < 32; c28_i11++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c28_Y)[c28_i11], 3U);
  }

  chartInstance->c28_sfEvent = CALL_EVENT;
  c28_chartstep_c28_Experiment_3_cs(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_3_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  c28_loop_ub = (*chartInstance->c28_sub_im_sizes)[0] *
    (*chartInstance->c28_sub_im_sizes)[1] - 1;
  for (c28_i12 = 0; c28_i12 <= c28_loop_ub; c28_i12++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c28_b_sub_im_data)[c28_i12],
                          4U);
  }

  for (c28_i13 = 0; c28_i13 < 64; c28_i13++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c28_posObj_subim)[c28_i13], 5U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c28_im_x, 6U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c28_im_y, 7U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c28_liminf_x, 8U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c28_liminf_y, 9U);
  for (c28_i14 = 0; c28_i14 < 4; c28_i14++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c28_rectangle)[c28_i14], 10U);
  }
}

static void mdl_start_c28_Experiment_3_cs(SFc28_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c28_chartstep_c28_Experiment_3_cs
  (SFc28_Experiment_3_csInstanceStruct *chartInstance)
{
  int32_T c28_i15;
  int32_T c28_i16;
  real_T c28_b_PosObj[64];
  int32_T c28_i17;
  real_T c28_b_X[32];
  int32_T c28_i18;
  real_T c28_b_Y[32];
  uint32_T c28_debug_family_var_map[24];
  real_T c28_minPx;
  real_T c28_minPy;
  real_T c28_maxPx;
  real_T c28_maxPy;
  real_T c28_detected;
  real_T c28_mino;
  real_T c28_maxo;
  real_T c28_i;
  real_T c28_limsup_x;
  real_T c28_limsup_y;
  real_T c28_a;
  real_T c28_nargin = 4.0;
  real_T c28_nargout = 7.0;
  int32_T c28_b_sub_im_sizes[2];
  real_T c28_b_posObj_subim[64];
  real_T c28_b_im_x;
  real_T c28_b_im_y;
  real_T c28_b_liminf_x;
  real_T c28_b_liminf_y;
  real_T c28_b_rectangle[4];
  int32_T c28_b_i;
  real_T c28_d0;
  real_T c28_d1;
  real_T c28_d2;
  real_T c28_d3;
  real_T c28_d4;
  real_T c28_d5;
  real_T c28_d6;
  real_T c28_d7;
  int32_T c28_i19;
  int32_T c28_c_i;
  int32_T c28_b_a;
  boolean_T c28_b0;
  boolean_T c28_b1;
  boolean_T c28_b2;
  int32_T c28_i20;
  int32_T c28_i21;
  boolean_T c28_b3;
  boolean_T c28_b4;
  boolean_T c28_b5;
  int32_T c28_i22;
  int32_T c28_i23;
  int32_T c28_x_sizes[2];
  int32_T c28_loop_ub;
  int32_T c28_i24;
  int32_T c28_b_loop_ub;
  int32_T c28_i25;
  int32_T c28_sub_im;
  int32_T c28_b_sub_im;
  int32_T c28_c_loop_ub;
  int32_T c28_i26;
  int32_T c28_x;
  int32_T c28_b_x;
  int32_T c28_d_loop_ub;
  int32_T c28_i27;
  int32_T c28_b_x_sizes[2];
  int32_T c28_c_x;
  int32_T c28_d_x;
  int32_T c28_e_loop_ub;
  int32_T c28_i28;
  uint8_T c28_b_x_data[187500];
  real_T c28_d8;
  int32_T c28_i29;
  uint8_T c28_uv0[9];
  int32_T c28_c_sub_im;
  int32_T c28_d_sub_im;
  int32_T c28_i30;
  int32_T c28_i31;
  int32_T c28_i32;
  int32_T c28_f_loop_ub;
  int32_T c28_i33;
  int32_T c28_i34;
  int32_T c28_i35;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 27U, chartInstance->c28_sfEvent);
  for (c28_i15 = 0; c28_i15 < 187500; c28_i15++) {
    chartInstance->c28_im[c28_i15] = (*chartInstance->c28_b_im)[c28_i15];
  }

  for (c28_i16 = 0; c28_i16 < 64; c28_i16++) {
    c28_b_PosObj[c28_i16] = (*chartInstance->c28_PosObj)[c28_i16];
  }

  for (c28_i17 = 0; c28_i17 < 32; c28_i17++) {
    c28_b_X[c28_i17] = (*chartInstance->c28_X)[c28_i17];
  }

  for (c28_i18 = 0; c28_i18 < 32; c28_i18++) {
    c28_b_Y[c28_i18] = (*chartInstance->c28_Y)[c28_i18];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 24U, 24U, c28_debug_family_names,
    c28_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_minPx, 0U, c28_b_sf_marshallOut,
    c28_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_minPy, 1U, c28_b_sf_marshallOut,
    c28_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_maxPx, 2U, c28_b_sf_marshallOut,
    c28_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_maxPy, 3U, c28_b_sf_marshallOut,
    c28_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_detected, 4U, c28_b_sf_marshallOut,
    c28_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_mino, 5U, c28_b_sf_marshallOut,
    c28_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_maxo, 6U, c28_b_sf_marshallOut,
    c28_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_i, 7U, c28_b_sf_marshallOut,
    c28_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_limsup_x, 8U, c28_b_sf_marshallOut,
    c28_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_limsup_y, 9U, c28_b_sf_marshallOut,
    c28_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_a, 10U, c28_b_sf_marshallOut,
    c28_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_nargin, 11U, c28_b_sf_marshallOut,
    c28_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_nargout, 12U, c28_b_sf_marshallOut,
    c28_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c28_im, 13U, c28_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c28_b_PosObj, 14U, c28_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c28_b_X, 15U, c28_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c28_b_Y, 16U, c28_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(chartInstance->c28_sub_im_data, (
    const int32_T *)&c28_b_sub_im_sizes, NULL, 0, 17, (void *)
    c28_d_sf_marshallOut, (void *)c28_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c28_b_posObj_subim, 18U,
    c28_c_sf_marshallOut, c28_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_b_im_x, 19U, c28_b_sf_marshallOut,
    c28_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_b_im_y, 20U, c28_b_sf_marshallOut,
    c28_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_b_liminf_x, 21U,
    c28_b_sf_marshallOut, c28_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c28_b_liminf_y, 22U,
    c28_b_sf_marshallOut, c28_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c28_b_rectangle, 23U, c28_sf_marshallOut,
    c28_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 3);
  c28_minPx = 500.0;
  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 4);
  c28_minPy = 375.0;
  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 5);
  c28_maxPx = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 6);
  c28_maxPy = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 7);
  c28_detected = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 8);
  c28_mino = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 9);
  c28_maxo = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 10);
  c28_i = 1.0;
  c28_b_i = 0;
  while (c28_b_i < 32) {
    c28_i = 1.0 + (real_T)c28_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 11);
    if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c28_b_PosObj[1 +
          (((int32_T)c28_i - 1) << 1)], 0.0, -1, 1U, c28_b_PosObj[1 + (((int32_T)
            c28_i - 1) << 1)] != 0.0))) {
      _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 12);
      if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c28_b_PosObj[1 +
            (((int32_T)c28_i - 1) << 1)], c28_minPx, -1, 2U, c28_b_PosObj[1 +
            (((int32_T)c28_i - 1) << 1)] < c28_minPx))) {
        _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 13);
        c28_minPx = c28_b_PosObj[1 + (((int32_T)c28_i - 1) << 1)];
        _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 14);
        c28_minPy = c28_b_PosObj[((int32_T)c28_i - 1) << 1];
        _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 15);
        c28_mino = c28_i;
      }

      _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 17);
      if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 2, c28_b_PosObj[1 +
            (((int32_T)c28_i - 1) << 1)], c28_maxPx, -1, 4U, c28_b_PosObj[1 +
            (((int32_T)c28_i - 1) << 1)] > c28_maxPx))) {
        _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 18);
        c28_maxPx = c28_b_PosObj[1 + (((int32_T)c28_i - 1) << 1)];
        _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 19);
        c28_maxPy = c28_b_PosObj[((int32_T)c28_i - 1) << 1];
        _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 20);
        c28_maxo = c28_i;
      }

      _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 22);
      c28_detected++;
    }

    c28_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 25);
  if (CV_EML_IF(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 3, c28_detected, 0.0, -1, 0U,
        c28_detected == 0.0))) {
    _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 26);
    c28_b_liminf_x = 500.0;
    _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 27);
    c28_limsup_x = 500.0;
    _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 28);
    c28_b_liminf_y = 375.0;
    _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 29);
    c28_limsup_y = 375.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 35);
    if (CV_EML_IF(0, 1, 4, CV_RELATIONAL_EVAL(4U, 0U, 4, c28_mino, 0.0, -1, 1U,
          c28_mino != 0.0))) {
      _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 36);
      c28_d0 = 1.6 * c28_b_Y[(int32_T)c28_mino - 1];
      c28_b_round(chartInstance, &c28_d0);
      c28_d1 = c28_minPx - (40.0 - c28_d0) * 2.0;
      c28_b_round(chartInstance, &c28_d1);
      c28_b_liminf_x = c28_d1;
      _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 37);
      c28_d2 = 4.5 * c28_b_Y[(int32_T)c28_mino - 1];
      c28_b_round(chartInstance, &c28_d2);
      c28_d3 = c28_minPy - (100.0 - c28_d2) * 2.0;
      c28_b_round(chartInstance, &c28_d3);
      c28_b_liminf_y = c28_d3;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 40);
      c28_b_liminf_x = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 41);
      c28_b_liminf_y = 1.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 43);
    if (CV_EML_IF(0, 1, 5, CV_RELATIONAL_EVAL(4U, 0U, 5, c28_maxo, 0.0, -1, 1U,
          c28_maxo != 0.0))) {
      _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 44);
      c28_d4 = 1.6 * c28_b_Y[(int32_T)c28_maxo - 1];
      c28_b_round(chartInstance, &c28_d4);
      c28_d5 = c28_maxPx + (40.0 - c28_d4) * 2.0;
      c28_b_round(chartInstance, &c28_d5);
      c28_limsup_x = c28_abs(chartInstance, c28_d5);
      _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 45);
      c28_d6 = 5.0 * c28_b_Y[(int32_T)c28_maxo - 1];
      c28_b_round(chartInstance, &c28_d6);
      c28_d7 = c28_maxPy + (100.0 - c28_d6) * 2.0;
      c28_b_round(chartInstance, &c28_d7);
      c28_limsup_y = c28_abs(chartInstance, c28_d7);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 47);
      c28_limsup_x = 500.0;
      _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 48);
      c28_limsup_y = 375.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 53);
  if (CV_EML_IF(0, 1, 6, CV_RELATIONAL_EVAL(4U, 0U, 6, c28_b_liminf_x, 1.0, -1,
        2U, c28_b_liminf_x < 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 54);
    c28_b_liminf_x = 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 57);
  if (CV_EML_IF(0, 1, 7, CV_RELATIONAL_EVAL(4U, 0U, 7, c28_limsup_x, 500.0, -1,
        4U, c28_limsup_x > 500.0))) {
    _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 58);
    c28_limsup_x = 500.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 61);
  if (CV_EML_IF(0, 1, 8, CV_RELATIONAL_EVAL(4U, 0U, 8, c28_b_liminf_y, 1.0, -1,
        2U, c28_b_liminf_y < 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 62);
    c28_b_liminf_y = 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 65);
  if (CV_EML_IF(0, 1, 9, CV_RELATIONAL_EVAL(4U, 0U, 9, c28_limsup_y, 375.0, -1,
        5U, c28_limsup_y >= 375.0))) {
    _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 66);
    c28_limsup_y = 375.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 69);
  if (CV_EML_IF(0, 1, 10, CV_RELATIONAL_EVAL(4U, 0U, 10, c28_b_liminf_y, 375.0,
        -1, 4U, c28_b_liminf_y > 375.0))) {
    _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 70);
    c28_b_liminf_y = 375.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 73);
  for (c28_i19 = 0; c28_i19 < 64; c28_i19++) {
    c28_b_posObj_subim[c28_i19] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 74);
  c28_a = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 76);
  c28_i = 1.0;
  c28_c_i = 0;
  while (c28_c_i < 32) {
    c28_i = 1.0 + (real_T)c28_c_i;
    CV_EML_FOR(0, 1, 1, 1);
    _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 77);
    if (CV_EML_IF(0, 1, 11, CV_RELATIONAL_EVAL(4U, 0U, 11, c28_b_PosObj[1 +
          (((int32_T)c28_i - 1) << 1)], 0.0, -1, 1U, c28_b_PosObj[1 + (((int32_T)
            c28_i - 1) << 1)] != 0.0))) {
      _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 78);
      c28_b_a = _SFD_EML_ARRAY_BOUNDS_CHECK("posObj_subim", (int32_T)c28_a, 1,
        32, 2, 0) - 1;
      c28_b_posObj_subim[c28_b_a << 1] = c28_b_PosObj[((int32_T)c28_i - 1) << 1]
        - c28_b_liminf_y;
      c28_b_posObj_subim[1 + (c28_b_a << 1)] = c28_b_PosObj[1 + (((int32_T)c28_i
        - 1) << 1)] - c28_b_liminf_x;
      _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 79);
      c28_a++;
    }

    c28_c_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 1, 0);
  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 83);
  c28_b0 = (c28_b_liminf_y > c28_limsup_y);
  c28_b1 = c28_b0;
  c28_b2 = c28_b1;
  if (c28_b2) {
    c28_i20 = 1;
    c28_i21 = 0;
  } else {
    c28_i20 = (int32_T)_SFD_INTEGER_CHECK("liminf_y", c28_b_liminf_y);
    c28_i21 = _SFD_EML_ARRAY_BOUNDS_CHECK("im", (int32_T)_SFD_INTEGER_CHECK(
      "limsup_y", c28_limsup_y), 1, 375, 0, 0);
  }

  c28_b3 = (c28_b_liminf_x > c28_limsup_x);
  c28_b4 = c28_b3;
  c28_b5 = c28_b4;
  if (c28_b5) {
    c28_i22 = 1;
    c28_i23 = 0;
  } else {
    c28_i22 = _SFD_EML_ARRAY_BOUNDS_CHECK("im", (int32_T)_SFD_INTEGER_CHECK(
      "liminf_x", c28_b_liminf_x), 1, 500, 0, 0);
    c28_i23 = _SFD_EML_ARRAY_BOUNDS_CHECK("im", (int32_T)_SFD_INTEGER_CHECK(
      "limsup_x", c28_limsup_x), 1, 500, 0, 0);
  }

  c28_x_sizes[0] = (c28_i21 - c28_i20) + 1;
  c28_x_sizes[1] = (c28_i23 - c28_i22) + 1;
  c28_loop_ub = c28_i23 - c28_i22;
  for (c28_i24 = 0; c28_i24 <= c28_loop_ub; c28_i24++) {
    c28_b_loop_ub = c28_i21 - c28_i20;
    for (c28_i25 = 0; c28_i25 <= c28_b_loop_ub; c28_i25++) {
      chartInstance->c28_x_data[c28_i25 + c28_x_sizes[0] * c28_i24] =
        chartInstance->c28_im[((c28_i20 + c28_i25) + 375 * ((c28_i22 + c28_i24)
        - 1)) - 1];
    }
  }

  _SFD_DIM_SIZE_GEQ_CHECK(375, c28_x_sizes[0], 1);
  _SFD_DIM_SIZE_GEQ_CHECK(500, c28_x_sizes[1], 2);
  c28_b_sub_im_sizes[0] = c28_x_sizes[0];
  c28_b_sub_im_sizes[1] = c28_x_sizes[1];
  c28_sub_im = c28_b_sub_im_sizes[0];
  c28_b_sub_im = c28_b_sub_im_sizes[1];
  c28_c_loop_ub = c28_x_sizes[0] * c28_x_sizes[1] - 1;
  for (c28_i26 = 0; c28_i26 <= c28_c_loop_ub; c28_i26++) {
    chartInstance->c28_sub_im_data[c28_i26] = chartInstance->c28_x_data[c28_i26];
  }

  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 85);
  c28_x_sizes[0] = c28_b_sub_im_sizes[0];
  c28_x_sizes[1] = c28_b_sub_im_sizes[1];
  c28_x = c28_x_sizes[0];
  c28_b_x = c28_x_sizes[1];
  c28_d_loop_ub = c28_b_sub_im_sizes[0] * c28_b_sub_im_sizes[1] - 1;
  for (c28_i27 = 0; c28_i27 <= c28_d_loop_ub; c28_i27++) {
    chartInstance->c28_x_data[c28_i27] = chartInstance->c28_sub_im_data[c28_i27];
  }

  c28_b_x_sizes[0] = c28_x_sizes[0];
  c28_b_x_sizes[1] = c28_x_sizes[1];
  c28_c_x = c28_b_x_sizes[0];
  c28_d_x = c28_b_x_sizes[1];
  c28_e_loop_ub = c28_x_sizes[0] * c28_x_sizes[1] - 1;
  for (c28_i28 = 0; c28_i28 <= c28_e_loop_ub; c28_i28++) {
    c28_b_x_data[c28_i28] = chartInstance->c28_x_data[c28_i28];
  }

  c28_d8 = (real_T)c28_intlength(chartInstance, c28_b_x_data, c28_b_x_sizes);
  if (CV_EML_IF(0, 1, 12, CV_RELATIONAL_EVAL(4U, 0U, 12, c28_d8, 3.0, -1, 2U,
        c28_d8 < 3.0))) {
    _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 86);
    _SFD_DIM_SIZE_GEQ_CHECK(375, 3, 1);
    _SFD_DIM_SIZE_GEQ_CHECK(500, 3, 2);
    for (c28_i29 = 0; c28_i29 < 9; c28_i29++) {
      c28_uv0[c28_i29] = 0U;
    }

    c28_b_sub_im_sizes[0] = 3;
    c28_b_sub_im_sizes[1] = 3;
    c28_c_sub_im = c28_b_sub_im_sizes[0];
    c28_d_sub_im = c28_b_sub_im_sizes[1];
    for (c28_i30 = 0; c28_i30 < 9; c28_i30++) {
      chartInstance->c28_sub_im_data[c28_i30] = c28_uv0[c28_i30];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 90);
  c28_b_im_x = c28_limsup_x - c28_b_liminf_x;
  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 91);
  c28_b_im_y = c28_limsup_y - c28_b_liminf_y;
  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, 92);
  c28_b_rectangle[0] = c28_b_liminf_y;
  c28_b_rectangle[1] = c28_b_liminf_x;
  c28_b_rectangle[2] = c28_b_im_y;
  c28_b_rectangle[3] = c28_b_im_x;
  _SFD_EML_CALL(0U, chartInstance->c28_sfEvent, -92);
  _SFD_SYMBOL_SCOPE_POP();
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1, 0,
    c28_b_sub_im_sizes[0]);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1, 1,
    c28_b_sub_im_sizes[1]);
  c28_i31 = (*chartInstance->c28_sub_im_sizes)[0];
  c28_i32 = (*chartInstance->c28_sub_im_sizes)[1];
  c28_f_loop_ub = c28_b_sub_im_sizes[0] * c28_b_sub_im_sizes[1] - 1;
  for (c28_i33 = 0; c28_i33 <= c28_f_loop_ub; c28_i33++) {
    (*chartInstance->c28_b_sub_im_data)[c28_i33] =
      chartInstance->c28_sub_im_data[c28_i33];
  }

  for (c28_i34 = 0; c28_i34 < 64; c28_i34++) {
    (*chartInstance->c28_posObj_subim)[c28_i34] = c28_b_posObj_subim[c28_i34];
  }

  *chartInstance->c28_im_x = c28_b_im_x;
  *chartInstance->c28_im_y = c28_b_im_y;
  *chartInstance->c28_liminf_x = c28_b_liminf_x;
  *chartInstance->c28_liminf_y = c28_b_liminf_y;
  for (c28_i35 = 0; c28_i35 < 4; c28_i35++) {
    (*chartInstance->c28_rectangle)[c28_i35] = c28_b_rectangle[c28_i35];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 27U, chartInstance->c28_sfEvent);
}

static void initSimStructsc28_Experiment_3_cs
  (SFc28_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c28_machineNumber, uint32_T
  c28_chartNumber, uint32_T c28_instanceNumber)
{
  (void)c28_machineNumber;
  (void)c28_chartNumber;
  (void)c28_instanceNumber;
}

static const mxArray *c28_sf_marshallOut(void *chartInstanceVoid, void
  *c28_b_inData)
{
  const mxArray *c28_mxArrayOutData = NULL;
  int32_T c28_i36;
  real_T c28_c_inData[4];
  int32_T c28_i37;
  real_T c28_u[4];
  const mxArray *c28_y = NULL;
  SFc28_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc28_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c28_mxArrayOutData = NULL;
  for (c28_i36 = 0; c28_i36 < 4; c28_i36++) {
    c28_c_inData[c28_i36] = (*(real_T (*)[4])c28_b_inData)[c28_i36];
  }

  for (c28_i37 = 0; c28_i37 < 4; c28_i37++) {
    c28_u[c28_i37] = c28_c_inData[c28_i37];
  }

  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_create("y", c28_u, 0, 0U, 1U, 0U, 2, 1, 4), false);
  sf_mex_assign(&c28_mxArrayOutData, c28_y, false);
  return c28_mxArrayOutData;
}

static void c28_emlrt_marshallIn(SFc28_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c28_b_rectangle, const char_T *c28_identifier,
  real_T c28_y[4])
{
  emlrtMsgIdentifier c28_thisId;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c28_b_rectangle), &c28_thisId,
    c28_y);
  sf_mex_destroy(&c28_b_rectangle);
}

static void c28_b_emlrt_marshallIn(SFc28_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId,
  real_T c28_y[4])
{
  real_T c28_dv2[4];
  int32_T c28_i38;
  (void)chartInstance;
  sf_mex_import(c28_parentId, sf_mex_dup(c28_u), c28_dv2, 1, 0, 0U, 1, 0U, 2, 1,
                4);
  for (c28_i38 = 0; c28_i38 < 4; c28_i38++) {
    c28_y[c28_i38] = c28_dv2[c28_i38];
  }

  sf_mex_destroy(&c28_u);
}

static void c28_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData)
{
  const mxArray *c28_b_rectangle;
  const char_T *c28_identifier;
  emlrtMsgIdentifier c28_thisId;
  real_T c28_y[4];
  int32_T c28_i39;
  SFc28_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc28_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c28_b_rectangle = sf_mex_dup(c28_mxArrayInData);
  c28_identifier = c28_varName;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c28_b_rectangle), &c28_thisId,
    c28_y);
  sf_mex_destroy(&c28_b_rectangle);
  for (c28_i39 = 0; c28_i39 < 4; c28_i39++) {
    (*(real_T (*)[4])c28_outData)[c28_i39] = c28_y[c28_i39];
  }

  sf_mex_destroy(&c28_mxArrayInData);
}

static const mxArray *c28_b_sf_marshallOut(void *chartInstanceVoid, void
  *c28_b_inData)
{
  const mxArray *c28_mxArrayOutData = NULL;
  real_T c28_u;
  const mxArray *c28_y = NULL;
  SFc28_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc28_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c28_mxArrayOutData = NULL;
  c28_u = *(real_T *)c28_b_inData;
  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_create("y", &c28_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c28_mxArrayOutData, c28_y, false);
  return c28_mxArrayOutData;
}

static real_T c28_c_emlrt_marshallIn(SFc28_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c28_b_liminf_y, const char_T *c28_identifier)
{
  real_T c28_y;
  emlrtMsgIdentifier c28_thisId;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_y = c28_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c28_b_liminf_y),
    &c28_thisId);
  sf_mex_destroy(&c28_b_liminf_y);
  return c28_y;
}

static real_T c28_d_emlrt_marshallIn(SFc28_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId)
{
  real_T c28_y;
  real_T c28_d9;
  (void)chartInstance;
  sf_mex_import(c28_parentId, sf_mex_dup(c28_u), &c28_d9, 1, 0, 0U, 0, 0U, 0);
  c28_y = c28_d9;
  sf_mex_destroy(&c28_u);
  return c28_y;
}

static void c28_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData)
{
  const mxArray *c28_b_liminf_y;
  const char_T *c28_identifier;
  emlrtMsgIdentifier c28_thisId;
  real_T c28_y;
  SFc28_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc28_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c28_b_liminf_y = sf_mex_dup(c28_mxArrayInData);
  c28_identifier = c28_varName;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_y = c28_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c28_b_liminf_y),
    &c28_thisId);
  sf_mex_destroy(&c28_b_liminf_y);
  *(real_T *)c28_outData = c28_y;
  sf_mex_destroy(&c28_mxArrayInData);
}

static const mxArray *c28_c_sf_marshallOut(void *chartInstanceVoid, void
  *c28_b_inData)
{
  const mxArray *c28_mxArrayOutData = NULL;
  int32_T c28_i40;
  int32_T c28_i41;
  int32_T c28_i42;
  real_T c28_c_inData[64];
  int32_T c28_i43;
  int32_T c28_i44;
  int32_T c28_i45;
  real_T c28_u[64];
  const mxArray *c28_y = NULL;
  SFc28_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc28_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c28_mxArrayOutData = NULL;
  c28_i40 = 0;
  for (c28_i41 = 0; c28_i41 < 32; c28_i41++) {
    for (c28_i42 = 0; c28_i42 < 2; c28_i42++) {
      c28_c_inData[c28_i42 + c28_i40] = (*(real_T (*)[64])c28_b_inData)[c28_i42
        + c28_i40];
    }

    c28_i40 += 2;
  }

  c28_i43 = 0;
  for (c28_i44 = 0; c28_i44 < 32; c28_i44++) {
    for (c28_i45 = 0; c28_i45 < 2; c28_i45++) {
      c28_u[c28_i45 + c28_i43] = c28_c_inData[c28_i45 + c28_i43];
    }

    c28_i43 += 2;
  }

  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_create("y", c28_u, 0, 0U, 1U, 0U, 2, 2, 32),
                false);
  sf_mex_assign(&c28_mxArrayOutData, c28_y, false);
  return c28_mxArrayOutData;
}

static void c28_e_emlrt_marshallIn(SFc28_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c28_b_posObj_subim, const char_T
  *c28_identifier, real_T c28_y[64])
{
  emlrtMsgIdentifier c28_thisId;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c28_b_posObj_subim),
    &c28_thisId, c28_y);
  sf_mex_destroy(&c28_b_posObj_subim);
}

static void c28_f_emlrt_marshallIn(SFc28_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId,
  real_T c28_y[64])
{
  real_T c28_dv3[64];
  int32_T c28_i46;
  (void)chartInstance;
  sf_mex_import(c28_parentId, sf_mex_dup(c28_u), c28_dv3, 1, 0, 0U, 1, 0U, 2, 2,
                32);
  for (c28_i46 = 0; c28_i46 < 64; c28_i46++) {
    c28_y[c28_i46] = c28_dv3[c28_i46];
  }

  sf_mex_destroy(&c28_u);
}

static void c28_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData)
{
  const mxArray *c28_b_posObj_subim;
  const char_T *c28_identifier;
  emlrtMsgIdentifier c28_thisId;
  real_T c28_y[64];
  int32_T c28_i47;
  int32_T c28_i48;
  int32_T c28_i49;
  SFc28_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc28_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c28_b_posObj_subim = sf_mex_dup(c28_mxArrayInData);
  c28_identifier = c28_varName;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c28_b_posObj_subim),
    &c28_thisId, c28_y);
  sf_mex_destroy(&c28_b_posObj_subim);
  c28_i47 = 0;
  for (c28_i48 = 0; c28_i48 < 32; c28_i48++) {
    for (c28_i49 = 0; c28_i49 < 2; c28_i49++) {
      (*(real_T (*)[64])c28_outData)[c28_i49 + c28_i47] = c28_y[c28_i49 +
        c28_i47];
    }

    c28_i47 += 2;
  }

  sf_mex_destroy(&c28_mxArrayInData);
}

static const mxArray *c28_d_sf_marshallOut(void *chartInstanceVoid, uint8_T
  c28_b_inData_data[], int32_T c28_inData_sizes[2])
{
  const mxArray *c28_mxArrayOutData = NULL;
  int32_T c28_u_sizes[2];
  int32_T c28_u;
  int32_T c28_b_u;
  int32_T c28_b_inData;
  int32_T c28_c_inData;
  int32_T c28_b_inData_sizes;
  int32_T c28_loop_ub;
  int32_T c28_i50;
  int32_T c28_b_loop_ub;
  int32_T c28_i51;
  uint8_T c28_u_data[187500];
  const mxArray *c28_y = NULL;
  SFc28_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc28_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c28_mxArrayOutData = NULL;
  c28_u_sizes[0] = c28_inData_sizes[0];
  c28_u_sizes[1] = c28_inData_sizes[1];
  c28_u = c28_u_sizes[0];
  c28_b_u = c28_u_sizes[1];
  c28_b_inData = c28_inData_sizes[0];
  c28_c_inData = c28_inData_sizes[1];
  c28_b_inData_sizes = c28_b_inData * c28_c_inData;
  c28_loop_ub = c28_b_inData * c28_c_inData - 1;
  for (c28_i50 = 0; c28_i50 <= c28_loop_ub; c28_i50++) {
    chartInstance->c28_inData_data[c28_i50] = c28_b_inData_data[c28_i50];
  }

  c28_b_loop_ub = c28_b_inData_sizes - 1;
  for (c28_i51 = 0; c28_i51 <= c28_b_loop_ub; c28_i51++) {
    c28_u_data[c28_i51] = chartInstance->c28_inData_data[c28_i51];
  }

  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_create("y", c28_u_data, 3, 0U, 1U, 0U, 2,
    c28_u_sizes[0], c28_u_sizes[1]), false);
  sf_mex_assign(&c28_mxArrayOutData, c28_y, false);
  return c28_mxArrayOutData;
}

static void c28_g_emlrt_marshallIn(SFc28_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c28_sub_im, const char_T *c28_identifier,
  uint8_T c28_b_y_data[], int32_T c28_y_sizes[2])
{
  emlrtMsgIdentifier c28_thisId;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c28_sub_im), &c28_thisId,
    c28_b_y_data, c28_y_sizes);
  sf_mex_destroy(&c28_sub_im);
}

static void c28_h_emlrt_marshallIn(SFc28_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId,
  uint8_T c28_b_y_data[], int32_T c28_y_sizes[2])
{
  int32_T c28_i52;
  uint32_T c28_uv1[2];
  int32_T c28_i53;
  boolean_T c28_bv0[2];
  int32_T c28_tmp_sizes[2];
  uint8_T c28_b_tmp_data[187500];
  int32_T c28_y;
  int32_T c28_b_y;
  int32_T c28_loop_ub;
  int32_T c28_i54;
  (void)chartInstance;
  for (c28_i52 = 0; c28_i52 < 2; c28_i52++) {
    c28_uv1[c28_i52] = 375U + 125U * (uint32_T)c28_i52;
  }

  for (c28_i53 = 0; c28_i53 < 2; c28_i53++) {
    c28_bv0[c28_i53] = true;
  }

  sf_mex_import_vs(c28_parentId, sf_mex_dup(c28_u), c28_b_tmp_data, 1, 3, 0U, 1,
                   0U, 2, c28_bv0, c28_uv1, c28_tmp_sizes);
  c28_y_sizes[0] = c28_tmp_sizes[0];
  c28_y_sizes[1] = c28_tmp_sizes[1];
  c28_y = c28_y_sizes[0];
  c28_b_y = c28_y_sizes[1];
  c28_loop_ub = c28_tmp_sizes[0] * c28_tmp_sizes[1] - 1;
  for (c28_i54 = 0; c28_i54 <= c28_loop_ub; c28_i54++) {
    c28_b_y_data[c28_i54] = c28_b_tmp_data[c28_i54];
  }

  sf_mex_destroy(&c28_u);
}

static void c28_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, uint8_T c28_outData_data[],
  int32_T c28_outData_sizes[2])
{
  const mxArray *c28_sub_im;
  const char_T *c28_identifier;
  emlrtMsgIdentifier c28_thisId;
  int32_T c28_y_sizes[2];
  int32_T c28_loop_ub;
  int32_T c28_i55;
  int32_T c28_b_loop_ub;
  int32_T c28_i56;
  SFc28_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc28_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c28_sub_im = sf_mex_dup(c28_mxArrayInData);
  c28_identifier = c28_varName;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c28_sub_im), &c28_thisId,
    chartInstance->c28_y_data, c28_y_sizes);
  sf_mex_destroy(&c28_sub_im);
  c28_outData_sizes[0] = c28_y_sizes[0];
  c28_outData_sizes[1] = c28_y_sizes[1];
  c28_loop_ub = c28_y_sizes[1] - 1;
  for (c28_i55 = 0; c28_i55 <= c28_loop_ub; c28_i55++) {
    c28_b_loop_ub = c28_y_sizes[0] - 1;
    for (c28_i56 = 0; c28_i56 <= c28_b_loop_ub; c28_i56++) {
      c28_outData_data[c28_i56 + c28_outData_sizes[0] * c28_i55] =
        chartInstance->c28_y_data[c28_i56 + c28_y_sizes[0] * c28_i55];
    }
  }

  sf_mex_destroy(&c28_mxArrayInData);
}

static const mxArray *c28_e_sf_marshallOut(void *chartInstanceVoid, void
  *c28_b_inData)
{
  const mxArray *c28_mxArrayOutData = NULL;
  int32_T c28_i57;
  real_T c28_c_inData[32];
  int32_T c28_i58;
  real_T c28_u[32];
  const mxArray *c28_y = NULL;
  SFc28_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc28_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c28_mxArrayOutData = NULL;
  for (c28_i57 = 0; c28_i57 < 32; c28_i57++) {
    c28_c_inData[c28_i57] = (*(real_T (*)[32])c28_b_inData)[c28_i57];
  }

  for (c28_i58 = 0; c28_i58 < 32; c28_i58++) {
    c28_u[c28_i58] = c28_c_inData[c28_i58];
  }

  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_create("y", c28_u, 0, 0U, 1U, 0U, 2, 1, 32),
                false);
  sf_mex_assign(&c28_mxArrayOutData, c28_y, false);
  return c28_mxArrayOutData;
}

static const mxArray *c28_f_sf_marshallOut(void *chartInstanceVoid, void
  *c28_b_inData)
{
  const mxArray *c28_mxArrayOutData = NULL;
  int32_T c28_i59;
  int32_T c28_i60;
  int32_T c28_i61;
  int32_T c28_i62;
  int32_T c28_i63;
  int32_T c28_i64;
  uint8_T c28_u[187500];
  const mxArray *c28_y = NULL;
  SFc28_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc28_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c28_mxArrayOutData = NULL;
  c28_i59 = 0;
  for (c28_i60 = 0; c28_i60 < 500; c28_i60++) {
    for (c28_i61 = 0; c28_i61 < 375; c28_i61++) {
      chartInstance->c28_inData[c28_i61 + c28_i59] = (*(uint8_T (*)[187500])
        c28_b_inData)[c28_i61 + c28_i59];
    }

    c28_i59 += 375;
  }

  c28_i62 = 0;
  for (c28_i63 = 0; c28_i63 < 500; c28_i63++) {
    for (c28_i64 = 0; c28_i64 < 375; c28_i64++) {
      c28_u[c28_i64 + c28_i62] = chartInstance->c28_inData[c28_i64 + c28_i62];
    }

    c28_i62 += 375;
  }

  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_create("y", c28_u, 3, 0U, 1U, 0U, 2, 375, 500),
                false);
  sf_mex_assign(&c28_mxArrayOutData, c28_y, false);
  return c28_mxArrayOutData;
}

const mxArray *sf_c28_Experiment_3_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c28_nameCaptureInfo = NULL;
  c28_nameCaptureInfo = NULL;
  sf_mex_assign(&c28_nameCaptureInfo, sf_mex_createstruct("structure", 2, 13, 1),
                false);
  c28_info_helper(&c28_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c28_nameCaptureInfo);
  return c28_nameCaptureInfo;
}

static void c28_info_helper(const mxArray **c28_info)
{
  const mxArray *c28_rhs0 = NULL;
  const mxArray *c28_lhs0 = NULL;
  const mxArray *c28_rhs1 = NULL;
  const mxArray *c28_lhs1 = NULL;
  const mxArray *c28_rhs2 = NULL;
  const mxArray *c28_lhs2 = NULL;
  const mxArray *c28_rhs3 = NULL;
  const mxArray *c28_lhs3 = NULL;
  const mxArray *c28_rhs4 = NULL;
  const mxArray *c28_lhs4 = NULL;
  const mxArray *c28_rhs5 = NULL;
  const mxArray *c28_lhs5 = NULL;
  const mxArray *c28_rhs6 = NULL;
  const mxArray *c28_lhs6 = NULL;
  const mxArray *c28_rhs7 = NULL;
  const mxArray *c28_lhs7 = NULL;
  const mxArray *c28_rhs8 = NULL;
  const mxArray *c28_lhs8 = NULL;
  const mxArray *c28_rhs9 = NULL;
  const mxArray *c28_lhs9 = NULL;
  const mxArray *c28_rhs10 = NULL;
  const mxArray *c28_lhs10 = NULL;
  const mxArray *c28_rhs11 = NULL;
  const mxArray *c28_lhs11 = NULL;
  const mxArray *c28_rhs12 = NULL;
  const mxArray *c28_lhs12 = NULL;
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("round"), "name", "name", 0);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c28_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c28_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_scalar_round"), "name",
                  "name", 2);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1307672838U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c28_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(""), "context", "context", 3);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("abs"), "name", "name", 3);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c28_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c28_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 5);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c28_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(""), "context", "context", 6);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("length"), "name", "name", 6);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("uint8"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1303167806U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c28_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength"),
                  "context", "context", 7);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 7);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c28_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength"),
                  "context", "context", 8);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "coder.internal.indexIntRelop"), "name", "name", 8);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1326749922U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c28_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!apply_float_relop"),
                  "context", "context", 9);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 9);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c28_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass"),
                  "context", "context", 10);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 10);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c28_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass"),
                  "context", "context", 11);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("intmin"), "name", "name", 11);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c28_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 12);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c28_info, c28_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c28_info, c28_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c28_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c28_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c28_info, sf_mex_duplicatearraysafe(&c28_lhs12), "lhs", "lhs",
                  12);
  sf_mex_destroy(&c28_rhs0);
  sf_mex_destroy(&c28_lhs0);
  sf_mex_destroy(&c28_rhs1);
  sf_mex_destroy(&c28_lhs1);
  sf_mex_destroy(&c28_rhs2);
  sf_mex_destroy(&c28_lhs2);
  sf_mex_destroy(&c28_rhs3);
  sf_mex_destroy(&c28_lhs3);
  sf_mex_destroy(&c28_rhs4);
  sf_mex_destroy(&c28_lhs4);
  sf_mex_destroy(&c28_rhs5);
  sf_mex_destroy(&c28_lhs5);
  sf_mex_destroy(&c28_rhs6);
  sf_mex_destroy(&c28_lhs6);
  sf_mex_destroy(&c28_rhs7);
  sf_mex_destroy(&c28_lhs7);
  sf_mex_destroy(&c28_rhs8);
  sf_mex_destroy(&c28_lhs8);
  sf_mex_destroy(&c28_rhs9);
  sf_mex_destroy(&c28_lhs9);
  sf_mex_destroy(&c28_rhs10);
  sf_mex_destroy(&c28_lhs10);
  sf_mex_destroy(&c28_rhs11);
  sf_mex_destroy(&c28_lhs11);
  sf_mex_destroy(&c28_rhs12);
  sf_mex_destroy(&c28_lhs12);
}

static const mxArray *c28_emlrt_marshallOut(const char * c28_u)
{
  const mxArray *c28_y = NULL;
  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_create("y", c28_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c28_u)), false);
  return c28_y;
}

static const mxArray *c28_b_emlrt_marshallOut(const uint32_T c28_u)
{
  const mxArray *c28_y = NULL;
  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_create("y", &c28_u, 7, 0U, 0U, 0U, 0), false);
  return c28_y;
}

static real_T c28_round(SFc28_Experiment_3_csInstanceStruct *chartInstance,
  real_T c28_x)
{
  real_T c28_b_x;
  c28_b_x = c28_x;
  c28_b_round(chartInstance, &c28_b_x);
  return c28_b_x;
}

static real_T c28_abs(SFc28_Experiment_3_csInstanceStruct *chartInstance, real_T
                      c28_x)
{
  real_T c28_b_x;
  (void)chartInstance;
  c28_b_x = c28_x;
  return muDoubleScalarAbs(c28_b_x);
}

static int32_T c28_intlength(SFc28_Experiment_3_csInstanceStruct *chartInstance,
  uint8_T c28_b_x_data[], int32_T c28_x_sizes[2])
{
  int32_T c28_n;
  real_T c28_a;
  real_T c28_b_a;
  real_T c28_flt;
  boolean_T c28_p;
  real_T c28_c_a;
  real_T c28_d_a;
  real_T c28_b_flt;
  boolean_T c28_b_p;
  boolean_T guard1 = false;
  (void)chartInstance;
  (void)c28_b_x_data;
  c28_a = (real_T)c28_x_sizes[0];
  c28_b_a = c28_a;
  c28_flt = c28_b_a;
  c28_p = (0.0 == c28_flt);
  guard1 = false;
  if (c28_p) {
    guard1 = true;
  } else {
    c28_c_a = (real_T)c28_x_sizes[1];
    c28_d_a = c28_c_a;
    c28_b_flt = c28_d_a;
    c28_b_p = (0.0 == c28_b_flt);
    if (c28_b_p) {
      guard1 = true;
    } else if ((real_T)c28_x_sizes[0] > (real_T)c28_x_sizes[1]) {
      c28_n = c28_x_sizes[0];
    } else {
      c28_n = c28_x_sizes[1];
    }
  }

  if (guard1 == true) {
    c28_n = 0;
  }

  return c28_n;
}

static const mxArray *c28_g_sf_marshallOut(void *chartInstanceVoid, void
  *c28_b_inData)
{
  const mxArray *c28_mxArrayOutData = NULL;
  int32_T c28_u;
  const mxArray *c28_y = NULL;
  SFc28_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc28_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c28_mxArrayOutData = NULL;
  c28_u = *(int32_T *)c28_b_inData;
  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_create("y", &c28_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c28_mxArrayOutData, c28_y, false);
  return c28_mxArrayOutData;
}

static int32_T c28_i_emlrt_marshallIn(SFc28_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId)
{
  int32_T c28_y;
  int32_T c28_i65;
  (void)chartInstance;
  sf_mex_import(c28_parentId, sf_mex_dup(c28_u), &c28_i65, 1, 6, 0U, 0, 0U, 0);
  c28_y = c28_i65;
  sf_mex_destroy(&c28_u);
  return c28_y;
}

static void c28_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData)
{
  const mxArray *c28_b_sfEvent;
  const char_T *c28_identifier;
  emlrtMsgIdentifier c28_thisId;
  int32_T c28_y;
  SFc28_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc28_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c28_b_sfEvent = sf_mex_dup(c28_mxArrayInData);
  c28_identifier = c28_varName;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_y = c28_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c28_b_sfEvent),
    &c28_thisId);
  sf_mex_destroy(&c28_b_sfEvent);
  *(int32_T *)c28_outData = c28_y;
  sf_mex_destroy(&c28_mxArrayInData);
}

static uint8_T c28_j_emlrt_marshallIn(SFc28_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c28_b_is_active_c28_Experiment_3_cs, const
  char_T *c28_identifier)
{
  uint8_T c28_y;
  emlrtMsgIdentifier c28_thisId;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_y = c28_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c28_b_is_active_c28_Experiment_3_cs), &c28_thisId);
  sf_mex_destroy(&c28_b_is_active_c28_Experiment_3_cs);
  return c28_y;
}

static uint8_T c28_k_emlrt_marshallIn(SFc28_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId)
{
  uint8_T c28_y;
  uint8_T c28_u0;
  (void)chartInstance;
  sf_mex_import(c28_parentId, sf_mex_dup(c28_u), &c28_u0, 1, 3, 0U, 0, 0U, 0);
  c28_y = c28_u0;
  sf_mex_destroy(&c28_u);
  return c28_y;
}

static void c28_b_round(SFc28_Experiment_3_csInstanceStruct *chartInstance,
  real_T *c28_x)
{
  (void)chartInstance;
  *c28_x = muDoubleScalarRound(*c28_x);
}

static void init_dsm_address_info(SFc28_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc28_Experiment_3_csInstanceStruct
  *chartInstance)
{
  chartInstance->c28_b_im = (uint8_T (*)[187500])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c28_PosObj = (real_T (*)[64])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c28_X = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c28_Y = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c28_b_sub_im_data = (uint8_T (*)[187500])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c28_sub_im_sizes = (int32_T (*)[2])
    ssGetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1);
  chartInstance->c28_posObj_subim = (real_T (*)[64])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c28_im_x = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c28_im_y = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c28_liminf_x = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c28_liminf_y = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c28_rectangle = (real_T (*)[4])ssGetOutputPortSignal_wrapper
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

void sf_c28_Experiment_3_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(928763364U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3021481460U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1804990352U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1296217343U);
}

mxArray* sf_c28_Experiment_3_cs_get_post_codegen_info(void);
mxArray *sf_c28_Experiment_3_cs_get_autoinheritance_info(void)
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
    mxArray* mxPostCodegenInfo = sf_c28_Experiment_3_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c28_Experiment_3_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c28_Experiment_3_cs_jit_fallback_info(void)
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

mxArray *sf_c28_Experiment_3_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c28_Experiment_3_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c28_Experiment_3_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[16],T\"im_x\",},{M[1],M[17],T\"im_y\",},{M[1],M[18],T\"liminf_x\",},{M[1],M[19],T\"liminf_y\",},{M[1],M[15],T\"posObj_subim\",},{M[1],M[20],T\"rectangle\",},{M[1],M[14],T\"sub_im\",},{M[8],M[0],T\"is_active_c28_Experiment_3_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c28_Experiment_3_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc28_Experiment_3_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc28_Experiment_3_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_3_csMachineNumber_,
           28,
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
            1.0,0,0,(MexFcnForType)c28_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c28_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c28_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c28_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 375;
          dimVector[1]= 500;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c28_d_sf_marshallOut,(MexInFcnForType)
            c28_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c28_c_sf_marshallOut,(MexInFcnForType)
            c28_c_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c28_b_sf_marshallOut,(MexInFcnForType)
          c28_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c28_b_sf_marshallOut,(MexInFcnForType)
          c28_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c28_b_sf_marshallOut,(MexInFcnForType)
          c28_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c28_b_sf_marshallOut,(MexInFcnForType)
          c28_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c28_sf_marshallOut,(MexInFcnForType)
            c28_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c28_b_im);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c28_PosObj);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c28_X);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c28_Y);
        _SFD_SET_DATA_VALUE_PTR_VAR_DIM(4U, *chartInstance->c28_b_sub_im_data,
          (void *)chartInstance->c28_sub_im_sizes);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c28_posObj_subim);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c28_im_x);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c28_im_y);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c28_liminf_x);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c28_liminf_y);
        _SFD_SET_DATA_VALUE_PTR(10U, *chartInstance->c28_rectangle);
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
  return "RlznJxzpa5Wmk1dcipe7PG";
}

static void sf_opaque_initialize_c28_Experiment_3_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc28_Experiment_3_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c28_Experiment_3_cs((SFc28_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
  initialize_c28_Experiment_3_cs((SFc28_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c28_Experiment_3_cs(void *chartInstanceVar)
{
  enable_c28_Experiment_3_cs((SFc28_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c28_Experiment_3_cs(void *chartInstanceVar)
{
  disable_c28_Experiment_3_cs((SFc28_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c28_Experiment_3_cs(void *chartInstanceVar)
{
  sf_gateway_c28_Experiment_3_cs((SFc28_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c28_Experiment_3_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c28_Experiment_3_cs((SFc28_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c28_Experiment_3_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c28_Experiment_3_cs((SFc28_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c28_Experiment_3_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc28_Experiment_3_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_3_cs_optimization_info();
    }

    finalize_c28_Experiment_3_cs((SFc28_Experiment_3_csInstanceStruct*)
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
  initSimStructsc28_Experiment_3_cs((SFc28_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c28_Experiment_3_cs(SimStruct *S)
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
    initialize_params_c28_Experiment_3_cs((SFc28_Experiment_3_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c28_Experiment_3_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Experiment_3_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      28);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,28,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,28,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,28);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,28,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,28,7);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,28);
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

static void mdlRTW_c28_Experiment_3_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c28_Experiment_3_cs(SimStruct *S)
{
  SFc28_Experiment_3_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc28_Experiment_3_csInstanceStruct *)utMalloc(sizeof
    (SFc28_Experiment_3_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc28_Experiment_3_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c28_Experiment_3_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c28_Experiment_3_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c28_Experiment_3_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c28_Experiment_3_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c28_Experiment_3_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c28_Experiment_3_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c28_Experiment_3_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c28_Experiment_3_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c28_Experiment_3_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c28_Experiment_3_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c28_Experiment_3_cs;
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

void c28_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c28_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c28_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c28_Experiment_3_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c28_Experiment_3_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
