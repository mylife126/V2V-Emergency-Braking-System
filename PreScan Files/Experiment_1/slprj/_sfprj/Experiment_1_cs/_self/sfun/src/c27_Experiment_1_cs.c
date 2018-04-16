/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_1_cs_sfun.h"
#include "c27_Experiment_1_cs.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Experiment_1_cs_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c27_debug_family_names[24] = { "minPx", "minPy", "maxPx",
  "maxPy", "detected", "mino", "maxo", "i", "limsup_x", "limsup_y", "a",
  "nargin", "nargout", "im", "PosObj", "X", "Y", "sub_im", "posObj_subim",
  "im_x", "im_y", "liminf_x", "liminf_y", "rectangle" };

/* Function Declarations */
static void initialize_c27_Experiment_1_cs(SFc27_Experiment_1_csInstanceStruct
  *chartInstance);
static void initialize_params_c27_Experiment_1_cs
  (SFc27_Experiment_1_csInstanceStruct *chartInstance);
static void enable_c27_Experiment_1_cs(SFc27_Experiment_1_csInstanceStruct
  *chartInstance);
static void disable_c27_Experiment_1_cs(SFc27_Experiment_1_csInstanceStruct
  *chartInstance);
static void c27_update_debugger_state_c27_Experiment_1_cs
  (SFc27_Experiment_1_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c27_Experiment_1_cs
  (SFc27_Experiment_1_csInstanceStruct *chartInstance);
static void set_sim_state_c27_Experiment_1_cs
  (SFc27_Experiment_1_csInstanceStruct *chartInstance, const mxArray *c27_st);
static void finalize_c27_Experiment_1_cs(SFc27_Experiment_1_csInstanceStruct
  *chartInstance);
static void sf_gateway_c27_Experiment_1_cs(SFc27_Experiment_1_csInstanceStruct
  *chartInstance);
static void mdl_start_c27_Experiment_1_cs(SFc27_Experiment_1_csInstanceStruct
  *chartInstance);
static void c27_chartstep_c27_Experiment_1_cs
  (SFc27_Experiment_1_csInstanceStruct *chartInstance);
static void initSimStructsc27_Experiment_1_cs
  (SFc27_Experiment_1_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c27_machineNumber, uint32_T
  c27_chartNumber, uint32_T c27_instanceNumber);
static const mxArray *c27_sf_marshallOut(void *chartInstanceVoid, void
  *c27_b_inData);
static void c27_emlrt_marshallIn(SFc27_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c27_b_rectangle, const char_T *c27_identifier,
  real_T c27_y[4]);
static void c27_b_emlrt_marshallIn(SFc27_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
  real_T c27_y[4]);
static void c27_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static const mxArray *c27_b_sf_marshallOut(void *chartInstanceVoid, void
  *c27_b_inData);
static real_T c27_c_emlrt_marshallIn(SFc27_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c27_b_liminf_y, const char_T *c27_identifier);
static real_T c27_d_emlrt_marshallIn(SFc27_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void c27_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static const mxArray *c27_c_sf_marshallOut(void *chartInstanceVoid, void
  *c27_b_inData);
static void c27_e_emlrt_marshallIn(SFc27_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c27_b_posObj_subim, const char_T
  *c27_identifier, real_T c27_y[64]);
static void c27_f_emlrt_marshallIn(SFc27_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
  real_T c27_y[64]);
static void c27_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static const mxArray *c27_d_sf_marshallOut(void *chartInstanceVoid, uint8_T
  c27_b_inData_data[], int32_T c27_inData_sizes[2]);
static void c27_g_emlrt_marshallIn(SFc27_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c27_sub_im, const char_T *c27_identifier,
  uint8_T c27_b_y_data[], int32_T c27_y_sizes[2]);
static void c27_h_emlrt_marshallIn(SFc27_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
  uint8_T c27_b_y_data[], int32_T c27_y_sizes[2]);
static void c27_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, uint8_T c27_outData_data[],
  int32_T c27_outData_sizes[2]);
static const mxArray *c27_e_sf_marshallOut(void *chartInstanceVoid, void
  *c27_b_inData);
static const mxArray *c27_f_sf_marshallOut(void *chartInstanceVoid, void
  *c27_b_inData);
static void c27_info_helper(const mxArray **c27_info);
static const mxArray *c27_emlrt_marshallOut(const char * c27_u);
static const mxArray *c27_b_emlrt_marshallOut(const uint32_T c27_u);
static real_T c27_round(SFc27_Experiment_1_csInstanceStruct *chartInstance,
  real_T c27_x);
static real_T c27_abs(SFc27_Experiment_1_csInstanceStruct *chartInstance, real_T
                      c27_x);
static int32_T c27_intlength(SFc27_Experiment_1_csInstanceStruct *chartInstance,
  uint8_T c27_b_x_data[], int32_T c27_x_sizes[2]);
static const mxArray *c27_g_sf_marshallOut(void *chartInstanceVoid, void
  *c27_b_inData);
static int32_T c27_i_emlrt_marshallIn(SFc27_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void c27_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static uint8_T c27_j_emlrt_marshallIn(SFc27_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c27_b_is_active_c27_Experiment_1_cs, const
  char_T *c27_identifier);
static uint8_T c27_k_emlrt_marshallIn(SFc27_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void c27_b_round(SFc27_Experiment_1_csInstanceStruct *chartInstance,
  real_T *c27_x);
static void init_dsm_address_info(SFc27_Experiment_1_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc27_Experiment_1_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c27_Experiment_1_cs(SFc27_Experiment_1_csInstanceStruct
  *chartInstance)
{
  chartInstance->c27_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c27_is_active_c27_Experiment_1_cs = 0U;
}

static void initialize_params_c27_Experiment_1_cs
  (SFc27_Experiment_1_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c27_Experiment_1_cs(SFc27_Experiment_1_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c27_Experiment_1_cs(SFc27_Experiment_1_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c27_update_debugger_state_c27_Experiment_1_cs
  (SFc27_Experiment_1_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c27_Experiment_1_cs
  (SFc27_Experiment_1_csInstanceStruct *chartInstance)
{
  const mxArray *c27_st;
  const mxArray *c27_y = NULL;
  real_T c27_hoistedGlobal;
  real_T c27_u;
  const mxArray *c27_b_y = NULL;
  real_T c27_b_hoistedGlobal;
  real_T c27_b_u;
  const mxArray *c27_c_y = NULL;
  real_T c27_c_hoistedGlobal;
  real_T c27_c_u;
  const mxArray *c27_d_y = NULL;
  real_T c27_d_hoistedGlobal;
  real_T c27_d_u;
  const mxArray *c27_e_y = NULL;
  int32_T c27_i0;
  real_T c27_e_u[64];
  const mxArray *c27_f_y = NULL;
  int32_T c27_i1;
  real_T c27_f_u[4];
  const mxArray *c27_g_y = NULL;
  int32_T c27_u_sizes[2];
  int32_T c27_g_u;
  int32_T c27_h_u;
  int32_T c27_loop_ub;
  int32_T c27_i2;
  uint8_T c27_u_data[187500];
  const mxArray *c27_h_y = NULL;
  uint8_T c27_e_hoistedGlobal;
  uint8_T c27_i_u;
  const mxArray *c27_i_y = NULL;
  c27_st = NULL;
  c27_st = NULL;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_createcellmatrix(8, 1), false);
  c27_hoistedGlobal = *chartInstance->c27_im_x;
  c27_u = c27_hoistedGlobal;
  c27_b_y = NULL;
  sf_mex_assign(&c27_b_y, sf_mex_create("y", &c27_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c27_y, 0, c27_b_y);
  c27_b_hoistedGlobal = *chartInstance->c27_im_y;
  c27_b_u = c27_b_hoistedGlobal;
  c27_c_y = NULL;
  sf_mex_assign(&c27_c_y, sf_mex_create("y", &c27_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c27_y, 1, c27_c_y);
  c27_c_hoistedGlobal = *chartInstance->c27_liminf_x;
  c27_c_u = c27_c_hoistedGlobal;
  c27_d_y = NULL;
  sf_mex_assign(&c27_d_y, sf_mex_create("y", &c27_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c27_y, 2, c27_d_y);
  c27_d_hoistedGlobal = *chartInstance->c27_liminf_y;
  c27_d_u = c27_d_hoistedGlobal;
  c27_e_y = NULL;
  sf_mex_assign(&c27_e_y, sf_mex_create("y", &c27_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c27_y, 3, c27_e_y);
  for (c27_i0 = 0; c27_i0 < 64; c27_i0++) {
    c27_e_u[c27_i0] = (*chartInstance->c27_posObj_subim)[c27_i0];
  }

  c27_f_y = NULL;
  sf_mex_assign(&c27_f_y, sf_mex_create("y", c27_e_u, 0, 0U, 1U, 0U, 2, 2, 32),
                false);
  sf_mex_setcell(c27_y, 4, c27_f_y);
  for (c27_i1 = 0; c27_i1 < 4; c27_i1++) {
    c27_f_u[c27_i1] = (*chartInstance->c27_rectangle)[c27_i1];
  }

  c27_g_y = NULL;
  sf_mex_assign(&c27_g_y, sf_mex_create("y", c27_f_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_setcell(c27_y, 5, c27_g_y);
  c27_u_sizes[0] = (*chartInstance->c27_sub_im_sizes)[0];
  c27_u_sizes[1] = (*chartInstance->c27_sub_im_sizes)[1];
  c27_g_u = c27_u_sizes[0];
  c27_h_u = c27_u_sizes[1];
  c27_loop_ub = (*chartInstance->c27_sub_im_sizes)[0] *
    (*chartInstance->c27_sub_im_sizes)[1] - 1;
  for (c27_i2 = 0; c27_i2 <= c27_loop_ub; c27_i2++) {
    c27_u_data[c27_i2] = (*chartInstance->c27_b_sub_im_data)[c27_i2];
  }

  c27_h_y = NULL;
  sf_mex_assign(&c27_h_y, sf_mex_create("y", c27_u_data, 3, 0U, 1U, 0U, 2,
    c27_u_sizes[0], c27_u_sizes[1]), false);
  sf_mex_setcell(c27_y, 6, c27_h_y);
  c27_e_hoistedGlobal = chartInstance->c27_is_active_c27_Experiment_1_cs;
  c27_i_u = c27_e_hoistedGlobal;
  c27_i_y = NULL;
  sf_mex_assign(&c27_i_y, sf_mex_create("y", &c27_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c27_y, 7, c27_i_y);
  sf_mex_assign(&c27_st, c27_y, false);
  return c27_st;
}

static void set_sim_state_c27_Experiment_1_cs
  (SFc27_Experiment_1_csInstanceStruct *chartInstance, const mxArray *c27_st)
{
  const mxArray *c27_u;
  real_T c27_dv0[64];
  int32_T c27_i3;
  real_T c27_dv1[4];
  int32_T c27_i4;
  int32_T c27_tmp_sizes[2];
  int32_T c27_i5;
  int32_T c27_i6;
  int32_T c27_loop_ub;
  int32_T c27_i7;
  chartInstance->c27_doneDoubleBufferReInit = true;
  c27_u = sf_mex_dup(c27_st);
  *chartInstance->c27_im_x = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c27_u, 0)), "im_x");
  *chartInstance->c27_im_y = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c27_u, 1)), "im_y");
  *chartInstance->c27_liminf_x = c27_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c27_u, 2)), "liminf_x");
  *chartInstance->c27_liminf_y = c27_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c27_u, 3)), "liminf_y");
  c27_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c27_u, 4)),
    "posObj_subim", c27_dv0);
  for (c27_i3 = 0; c27_i3 < 64; c27_i3++) {
    (*chartInstance->c27_posObj_subim)[c27_i3] = c27_dv0[c27_i3];
  }

  c27_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c27_u, 5)),
                       "rectangle", c27_dv1);
  for (c27_i4 = 0; c27_i4 < 4; c27_i4++) {
    (*chartInstance->c27_rectangle)[c27_i4] = c27_dv1[c27_i4];
  }

  c27_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c27_u, 6)),
    "sub_im", chartInstance->c27_tmp_data, c27_tmp_sizes);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1, 0,
    c27_tmp_sizes[0]);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1, 1,
    c27_tmp_sizes[1]);
  c27_i5 = (*chartInstance->c27_sub_im_sizes)[0];
  c27_i6 = (*chartInstance->c27_sub_im_sizes)[1];
  c27_loop_ub = c27_tmp_sizes[0] * c27_tmp_sizes[1] - 1;
  for (c27_i7 = 0; c27_i7 <= c27_loop_ub; c27_i7++) {
    (*chartInstance->c27_b_sub_im_data)[c27_i7] = chartInstance->
      c27_tmp_data[c27_i7];
  }

  chartInstance->c27_is_active_c27_Experiment_1_cs = c27_j_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c27_u, 7)),
     "is_active_c27_Experiment_1_cs");
  sf_mex_destroy(&c27_u);
  c27_update_debugger_state_c27_Experiment_1_cs(chartInstance);
  sf_mex_destroy(&c27_st);
}

static void finalize_c27_Experiment_1_cs(SFc27_Experiment_1_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c27_Experiment_1_cs(SFc27_Experiment_1_csInstanceStruct
  *chartInstance)
{
  int32_T c27_i8;
  int32_T c27_i9;
  int32_T c27_i10;
  int32_T c27_i11;
  int32_T c27_loop_ub;
  int32_T c27_i12;
  int32_T c27_i13;
  int32_T c27_i14;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 26U, chartInstance->c27_sfEvent);
  for (c27_i8 = 0; c27_i8 < 187500; c27_i8++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c27_b_im)[c27_i8], 0U);
  }

  for (c27_i9 = 0; c27_i9 < 64; c27_i9++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c27_PosObj)[c27_i9], 1U);
  }

  for (c27_i10 = 0; c27_i10 < 32; c27_i10++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c27_X)[c27_i10], 2U);
  }

  for (c27_i11 = 0; c27_i11 < 32; c27_i11++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c27_Y)[c27_i11], 3U);
  }

  chartInstance->c27_sfEvent = CALL_EVENT;
  c27_chartstep_c27_Experiment_1_cs(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_1_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  c27_loop_ub = (*chartInstance->c27_sub_im_sizes)[0] *
    (*chartInstance->c27_sub_im_sizes)[1] - 1;
  for (c27_i12 = 0; c27_i12 <= c27_loop_ub; c27_i12++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c27_b_sub_im_data)[c27_i12],
                          4U);
  }

  for (c27_i13 = 0; c27_i13 < 64; c27_i13++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c27_posObj_subim)[c27_i13], 5U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c27_im_x, 6U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c27_im_y, 7U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c27_liminf_x, 8U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c27_liminf_y, 9U);
  for (c27_i14 = 0; c27_i14 < 4; c27_i14++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c27_rectangle)[c27_i14], 10U);
  }
}

static void mdl_start_c27_Experiment_1_cs(SFc27_Experiment_1_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c27_chartstep_c27_Experiment_1_cs
  (SFc27_Experiment_1_csInstanceStruct *chartInstance)
{
  int32_T c27_i15;
  int32_T c27_i16;
  real_T c27_b_PosObj[64];
  int32_T c27_i17;
  real_T c27_b_X[32];
  int32_T c27_i18;
  real_T c27_b_Y[32];
  uint32_T c27_debug_family_var_map[24];
  real_T c27_minPx;
  real_T c27_minPy;
  real_T c27_maxPx;
  real_T c27_maxPy;
  real_T c27_detected;
  real_T c27_mino;
  real_T c27_maxo;
  real_T c27_i;
  real_T c27_limsup_x;
  real_T c27_limsup_y;
  real_T c27_a;
  real_T c27_nargin = 4.0;
  real_T c27_nargout = 7.0;
  int32_T c27_b_sub_im_sizes[2];
  real_T c27_b_posObj_subim[64];
  real_T c27_b_im_x;
  real_T c27_b_im_y;
  real_T c27_b_liminf_x;
  real_T c27_b_liminf_y;
  real_T c27_b_rectangle[4];
  int32_T c27_b_i;
  real_T c27_d0;
  real_T c27_d1;
  real_T c27_d2;
  real_T c27_d3;
  real_T c27_d4;
  real_T c27_d5;
  real_T c27_d6;
  real_T c27_d7;
  int32_T c27_i19;
  int32_T c27_c_i;
  int32_T c27_b_a;
  boolean_T c27_b0;
  boolean_T c27_b1;
  boolean_T c27_b2;
  int32_T c27_i20;
  int32_T c27_i21;
  boolean_T c27_b3;
  boolean_T c27_b4;
  boolean_T c27_b5;
  int32_T c27_i22;
  int32_T c27_i23;
  int32_T c27_x_sizes[2];
  int32_T c27_loop_ub;
  int32_T c27_i24;
  int32_T c27_b_loop_ub;
  int32_T c27_i25;
  int32_T c27_sub_im;
  int32_T c27_b_sub_im;
  int32_T c27_c_loop_ub;
  int32_T c27_i26;
  int32_T c27_x;
  int32_T c27_b_x;
  int32_T c27_d_loop_ub;
  int32_T c27_i27;
  int32_T c27_b_x_sizes[2];
  int32_T c27_c_x;
  int32_T c27_d_x;
  int32_T c27_e_loop_ub;
  int32_T c27_i28;
  uint8_T c27_b_x_data[187500];
  real_T c27_d8;
  int32_T c27_i29;
  uint8_T c27_uv0[9];
  int32_T c27_c_sub_im;
  int32_T c27_d_sub_im;
  int32_T c27_i30;
  int32_T c27_i31;
  int32_T c27_i32;
  int32_T c27_f_loop_ub;
  int32_T c27_i33;
  int32_T c27_i34;
  int32_T c27_i35;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 26U, chartInstance->c27_sfEvent);
  for (c27_i15 = 0; c27_i15 < 187500; c27_i15++) {
    chartInstance->c27_im[c27_i15] = (*chartInstance->c27_b_im)[c27_i15];
  }

  for (c27_i16 = 0; c27_i16 < 64; c27_i16++) {
    c27_b_PosObj[c27_i16] = (*chartInstance->c27_PosObj)[c27_i16];
  }

  for (c27_i17 = 0; c27_i17 < 32; c27_i17++) {
    c27_b_X[c27_i17] = (*chartInstance->c27_X)[c27_i17];
  }

  for (c27_i18 = 0; c27_i18 < 32; c27_i18++) {
    c27_b_Y[c27_i18] = (*chartInstance->c27_Y)[c27_i18];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 24U, 24U, c27_debug_family_names,
    c27_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_minPx, 0U, c27_b_sf_marshallOut,
    c27_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_minPy, 1U, c27_b_sf_marshallOut,
    c27_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_maxPx, 2U, c27_b_sf_marshallOut,
    c27_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_maxPy, 3U, c27_b_sf_marshallOut,
    c27_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_detected, 4U, c27_b_sf_marshallOut,
    c27_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_mino, 5U, c27_b_sf_marshallOut,
    c27_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_maxo, 6U, c27_b_sf_marshallOut,
    c27_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_i, 7U, c27_b_sf_marshallOut,
    c27_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_limsup_x, 8U, c27_b_sf_marshallOut,
    c27_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_limsup_y, 9U, c27_b_sf_marshallOut,
    c27_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_a, 10U, c27_b_sf_marshallOut,
    c27_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_nargin, 11U, c27_b_sf_marshallOut,
    c27_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_nargout, 12U, c27_b_sf_marshallOut,
    c27_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c27_im, 13U, c27_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c27_b_PosObj, 14U, c27_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c27_b_X, 15U, c27_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c27_b_Y, 16U, c27_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(chartInstance->c27_sub_im_data, (
    const int32_T *)&c27_b_sub_im_sizes, NULL, 0, 17, (void *)
    c27_d_sf_marshallOut, (void *)c27_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c27_b_posObj_subim, 18U,
    c27_c_sf_marshallOut, c27_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_b_im_x, 19U, c27_b_sf_marshallOut,
    c27_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_b_im_y, 20U, c27_b_sf_marshallOut,
    c27_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_b_liminf_x, 21U,
    c27_b_sf_marshallOut, c27_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_b_liminf_y, 22U,
    c27_b_sf_marshallOut, c27_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c27_b_rectangle, 23U, c27_sf_marshallOut,
    c27_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 3);
  c27_minPx = 500.0;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 4);
  c27_minPy = 375.0;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 5);
  c27_maxPx = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 6);
  c27_maxPy = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 7);
  c27_detected = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 8);
  c27_mino = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 9);
  c27_maxo = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 10);
  c27_i = 1.0;
  c27_b_i = 0;
  while (c27_b_i < 32) {
    c27_i = 1.0 + (real_T)c27_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 11);
    if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c27_b_PosObj[1 +
          (((int32_T)c27_i - 1) << 1)], 0.0, -1, 1U, c27_b_PosObj[1 + (((int32_T)
            c27_i - 1) << 1)] != 0.0))) {
      _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 12);
      if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c27_b_PosObj[1 +
            (((int32_T)c27_i - 1) << 1)], c27_minPx, -1, 2U, c27_b_PosObj[1 +
            (((int32_T)c27_i - 1) << 1)] < c27_minPx))) {
        _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 13);
        c27_minPx = c27_b_PosObj[1 + (((int32_T)c27_i - 1) << 1)];
        _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 14);
        c27_minPy = c27_b_PosObj[((int32_T)c27_i - 1) << 1];
        _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 15);
        c27_mino = c27_i;
      }

      _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 17);
      if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 2, c27_b_PosObj[1 +
            (((int32_T)c27_i - 1) << 1)], c27_maxPx, -1, 4U, c27_b_PosObj[1 +
            (((int32_T)c27_i - 1) << 1)] > c27_maxPx))) {
        _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 18);
        c27_maxPx = c27_b_PosObj[1 + (((int32_T)c27_i - 1) << 1)];
        _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 19);
        c27_maxPy = c27_b_PosObj[((int32_T)c27_i - 1) << 1];
        _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 20);
        c27_maxo = c27_i;
      }

      _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 22);
      c27_detected++;
    }

    c27_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 25);
  if (CV_EML_IF(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 3, c27_detected, 0.0, -1, 0U,
        c27_detected == 0.0))) {
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 26);
    c27_b_liminf_x = 500.0;
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 27);
    c27_limsup_x = 500.0;
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 28);
    c27_b_liminf_y = 375.0;
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 29);
    c27_limsup_y = 375.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 35);
    if (CV_EML_IF(0, 1, 4, CV_RELATIONAL_EVAL(4U, 0U, 4, c27_mino, 0.0, -1, 1U,
          c27_mino != 0.0))) {
      _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 36);
      c27_d0 = 1.6 * c27_b_Y[(int32_T)c27_mino - 1];
      c27_b_round(chartInstance, &c27_d0);
      c27_d1 = c27_minPx - (40.0 - c27_d0) * 2.0;
      c27_b_round(chartInstance, &c27_d1);
      c27_b_liminf_x = c27_d1;
      _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 37);
      c27_d2 = 4.5 * c27_b_Y[(int32_T)c27_mino - 1];
      c27_b_round(chartInstance, &c27_d2);
      c27_d3 = c27_minPy - (100.0 - c27_d2) * 2.0;
      c27_b_round(chartInstance, &c27_d3);
      c27_b_liminf_y = c27_d3;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 40);
      c27_b_liminf_x = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 41);
      c27_b_liminf_y = 1.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 43);
    if (CV_EML_IF(0, 1, 5, CV_RELATIONAL_EVAL(4U, 0U, 5, c27_maxo, 0.0, -1, 1U,
          c27_maxo != 0.0))) {
      _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 44);
      c27_d4 = 1.6 * c27_b_Y[(int32_T)c27_maxo - 1];
      c27_b_round(chartInstance, &c27_d4);
      c27_d5 = c27_maxPx + (40.0 - c27_d4) * 2.0;
      c27_b_round(chartInstance, &c27_d5);
      c27_limsup_x = c27_abs(chartInstance, c27_d5);
      _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 45);
      c27_d6 = 5.0 * c27_b_Y[(int32_T)c27_maxo - 1];
      c27_b_round(chartInstance, &c27_d6);
      c27_d7 = c27_maxPy + (100.0 - c27_d6) * 2.0;
      c27_b_round(chartInstance, &c27_d7);
      c27_limsup_y = c27_abs(chartInstance, c27_d7);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 47);
      c27_limsup_x = 500.0;
      _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 48);
      c27_limsup_y = 375.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 53);
  if (CV_EML_IF(0, 1, 6, CV_RELATIONAL_EVAL(4U, 0U, 6, c27_b_liminf_x, 1.0, -1,
        2U, c27_b_liminf_x < 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 54);
    c27_b_liminf_x = 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 57);
  if (CV_EML_IF(0, 1, 7, CV_RELATIONAL_EVAL(4U, 0U, 7, c27_limsup_x, 500.0, -1,
        4U, c27_limsup_x > 500.0))) {
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 58);
    c27_limsup_x = 500.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 61);
  if (CV_EML_IF(0, 1, 8, CV_RELATIONAL_EVAL(4U, 0U, 8, c27_b_liminf_y, 1.0, -1,
        2U, c27_b_liminf_y < 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 62);
    c27_b_liminf_y = 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 65);
  if (CV_EML_IF(0, 1, 9, CV_RELATIONAL_EVAL(4U, 0U, 9, c27_limsup_y, 375.0, -1,
        5U, c27_limsup_y >= 375.0))) {
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 66);
    c27_limsup_y = 375.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 69);
  if (CV_EML_IF(0, 1, 10, CV_RELATIONAL_EVAL(4U, 0U, 10, c27_b_liminf_y, 375.0,
        -1, 4U, c27_b_liminf_y > 375.0))) {
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 70);
    c27_b_liminf_y = 375.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 73);
  for (c27_i19 = 0; c27_i19 < 64; c27_i19++) {
    c27_b_posObj_subim[c27_i19] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 74);
  c27_a = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 76);
  c27_i = 1.0;
  c27_c_i = 0;
  while (c27_c_i < 32) {
    c27_i = 1.0 + (real_T)c27_c_i;
    CV_EML_FOR(0, 1, 1, 1);
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 77);
    if (CV_EML_IF(0, 1, 11, CV_RELATIONAL_EVAL(4U, 0U, 11, c27_b_PosObj[1 +
          (((int32_T)c27_i - 1) << 1)], 0.0, -1, 1U, c27_b_PosObj[1 + (((int32_T)
            c27_i - 1) << 1)] != 0.0))) {
      _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 78);
      c27_b_a = _SFD_EML_ARRAY_BOUNDS_CHECK("posObj_subim", (int32_T)c27_a, 1,
        32, 2, 0) - 1;
      c27_b_posObj_subim[c27_b_a << 1] = c27_b_PosObj[((int32_T)c27_i - 1) << 1]
        - c27_b_liminf_y;
      c27_b_posObj_subim[1 + (c27_b_a << 1)] = c27_b_PosObj[1 + (((int32_T)c27_i
        - 1) << 1)] - c27_b_liminf_x;
      _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 79);
      c27_a++;
    }

    c27_c_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 1, 0);
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 83);
  c27_b0 = (c27_b_liminf_y > c27_limsup_y);
  c27_b1 = c27_b0;
  c27_b2 = c27_b1;
  if (c27_b2) {
    c27_i20 = 1;
    c27_i21 = 0;
  } else {
    c27_i20 = (int32_T)_SFD_INTEGER_CHECK("liminf_y", c27_b_liminf_y);
    c27_i21 = _SFD_EML_ARRAY_BOUNDS_CHECK("im", (int32_T)_SFD_INTEGER_CHECK(
      "limsup_y", c27_limsup_y), 1, 375, 0, 0);
  }

  c27_b3 = (c27_b_liminf_x > c27_limsup_x);
  c27_b4 = c27_b3;
  c27_b5 = c27_b4;
  if (c27_b5) {
    c27_i22 = 1;
    c27_i23 = 0;
  } else {
    c27_i22 = _SFD_EML_ARRAY_BOUNDS_CHECK("im", (int32_T)_SFD_INTEGER_CHECK(
      "liminf_x", c27_b_liminf_x), 1, 500, 0, 0);
    c27_i23 = _SFD_EML_ARRAY_BOUNDS_CHECK("im", (int32_T)_SFD_INTEGER_CHECK(
      "limsup_x", c27_limsup_x), 1, 500, 0, 0);
  }

  c27_x_sizes[0] = (c27_i21 - c27_i20) + 1;
  c27_x_sizes[1] = (c27_i23 - c27_i22) + 1;
  c27_loop_ub = c27_i23 - c27_i22;
  for (c27_i24 = 0; c27_i24 <= c27_loop_ub; c27_i24++) {
    c27_b_loop_ub = c27_i21 - c27_i20;
    for (c27_i25 = 0; c27_i25 <= c27_b_loop_ub; c27_i25++) {
      chartInstance->c27_x_data[c27_i25 + c27_x_sizes[0] * c27_i24] =
        chartInstance->c27_im[((c27_i20 + c27_i25) + 375 * ((c27_i22 + c27_i24)
        - 1)) - 1];
    }
  }

  _SFD_DIM_SIZE_GEQ_CHECK(375, c27_x_sizes[0], 1);
  _SFD_DIM_SIZE_GEQ_CHECK(500, c27_x_sizes[1], 2);
  c27_b_sub_im_sizes[0] = c27_x_sizes[0];
  c27_b_sub_im_sizes[1] = c27_x_sizes[1];
  c27_sub_im = c27_b_sub_im_sizes[0];
  c27_b_sub_im = c27_b_sub_im_sizes[1];
  c27_c_loop_ub = c27_x_sizes[0] * c27_x_sizes[1] - 1;
  for (c27_i26 = 0; c27_i26 <= c27_c_loop_ub; c27_i26++) {
    chartInstance->c27_sub_im_data[c27_i26] = chartInstance->c27_x_data[c27_i26];
  }

  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 85);
  c27_x_sizes[0] = c27_b_sub_im_sizes[0];
  c27_x_sizes[1] = c27_b_sub_im_sizes[1];
  c27_x = c27_x_sizes[0];
  c27_b_x = c27_x_sizes[1];
  c27_d_loop_ub = c27_b_sub_im_sizes[0] * c27_b_sub_im_sizes[1] - 1;
  for (c27_i27 = 0; c27_i27 <= c27_d_loop_ub; c27_i27++) {
    chartInstance->c27_x_data[c27_i27] = chartInstance->c27_sub_im_data[c27_i27];
  }

  c27_b_x_sizes[0] = c27_x_sizes[0];
  c27_b_x_sizes[1] = c27_x_sizes[1];
  c27_c_x = c27_b_x_sizes[0];
  c27_d_x = c27_b_x_sizes[1];
  c27_e_loop_ub = c27_x_sizes[0] * c27_x_sizes[1] - 1;
  for (c27_i28 = 0; c27_i28 <= c27_e_loop_ub; c27_i28++) {
    c27_b_x_data[c27_i28] = chartInstance->c27_x_data[c27_i28];
  }

  c27_d8 = (real_T)c27_intlength(chartInstance, c27_b_x_data, c27_b_x_sizes);
  if (CV_EML_IF(0, 1, 12, CV_RELATIONAL_EVAL(4U, 0U, 12, c27_d8, 3.0, -1, 2U,
        c27_d8 < 3.0))) {
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 86);
    _SFD_DIM_SIZE_GEQ_CHECK(375, 3, 1);
    _SFD_DIM_SIZE_GEQ_CHECK(500, 3, 2);
    for (c27_i29 = 0; c27_i29 < 9; c27_i29++) {
      c27_uv0[c27_i29] = 0U;
    }

    c27_b_sub_im_sizes[0] = 3;
    c27_b_sub_im_sizes[1] = 3;
    c27_c_sub_im = c27_b_sub_im_sizes[0];
    c27_d_sub_im = c27_b_sub_im_sizes[1];
    for (c27_i30 = 0; c27_i30 < 9; c27_i30++) {
      chartInstance->c27_sub_im_data[c27_i30] = c27_uv0[c27_i30];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 90);
  c27_b_im_x = c27_limsup_x - c27_b_liminf_x;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 91);
  c27_b_im_y = c27_limsup_y - c27_b_liminf_y;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 92);
  c27_b_rectangle[0] = c27_b_liminf_y;
  c27_b_rectangle[1] = c27_b_liminf_x;
  c27_b_rectangle[2] = c27_b_im_y;
  c27_b_rectangle[3] = c27_b_im_x;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, -92);
  _SFD_SYMBOL_SCOPE_POP();
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1, 0,
    c27_b_sub_im_sizes[0]);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1, 1,
    c27_b_sub_im_sizes[1]);
  c27_i31 = (*chartInstance->c27_sub_im_sizes)[0];
  c27_i32 = (*chartInstance->c27_sub_im_sizes)[1];
  c27_f_loop_ub = c27_b_sub_im_sizes[0] * c27_b_sub_im_sizes[1] - 1;
  for (c27_i33 = 0; c27_i33 <= c27_f_loop_ub; c27_i33++) {
    (*chartInstance->c27_b_sub_im_data)[c27_i33] =
      chartInstance->c27_sub_im_data[c27_i33];
  }

  for (c27_i34 = 0; c27_i34 < 64; c27_i34++) {
    (*chartInstance->c27_posObj_subim)[c27_i34] = c27_b_posObj_subim[c27_i34];
  }

  *chartInstance->c27_im_x = c27_b_im_x;
  *chartInstance->c27_im_y = c27_b_im_y;
  *chartInstance->c27_liminf_x = c27_b_liminf_x;
  *chartInstance->c27_liminf_y = c27_b_liminf_y;
  for (c27_i35 = 0; c27_i35 < 4; c27_i35++) {
    (*chartInstance->c27_rectangle)[c27_i35] = c27_b_rectangle[c27_i35];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 26U, chartInstance->c27_sfEvent);
}

static void initSimStructsc27_Experiment_1_cs
  (SFc27_Experiment_1_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c27_machineNumber, uint32_T
  c27_chartNumber, uint32_T c27_instanceNumber)
{
  (void)c27_machineNumber;
  (void)c27_chartNumber;
  (void)c27_instanceNumber;
}

static const mxArray *c27_sf_marshallOut(void *chartInstanceVoid, void
  *c27_b_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_i36;
  real_T c27_c_inData[4];
  int32_T c27_i37;
  real_T c27_u[4];
  const mxArray *c27_y = NULL;
  SFc27_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc27_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  for (c27_i36 = 0; c27_i36 < 4; c27_i36++) {
    c27_c_inData[c27_i36] = (*(real_T (*)[4])c27_b_inData)[c27_i36];
  }

  for (c27_i37 = 0; c27_i37 < 4; c27_i37++) {
    c27_u[c27_i37] = c27_c_inData[c27_i37];
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 0, 0U, 1U, 0U, 2, 1, 4), false);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

static void c27_emlrt_marshallIn(SFc27_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c27_b_rectangle, const char_T *c27_identifier,
  real_T c27_y[4])
{
  emlrtMsgIdentifier c27_thisId;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_b_rectangle), &c27_thisId,
    c27_y);
  sf_mex_destroy(&c27_b_rectangle);
}

static void c27_b_emlrt_marshallIn(SFc27_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
  real_T c27_y[4])
{
  real_T c27_dv2[4];
  int32_T c27_i38;
  (void)chartInstance;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), c27_dv2, 1, 0, 0U, 1, 0U, 2, 1,
                4);
  for (c27_i38 = 0; c27_i38 < 4; c27_i38++) {
    c27_y[c27_i38] = c27_dv2[c27_i38];
  }

  sf_mex_destroy(&c27_u);
}

static void c27_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_b_rectangle;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  real_T c27_y[4];
  int32_T c27_i39;
  SFc27_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc27_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c27_b_rectangle = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_b_rectangle), &c27_thisId,
    c27_y);
  sf_mex_destroy(&c27_b_rectangle);
  for (c27_i39 = 0; c27_i39 < 4; c27_i39++) {
    (*(real_T (*)[4])c27_outData)[c27_i39] = c27_y[c27_i39];
  }

  sf_mex_destroy(&c27_mxArrayInData);
}

static const mxArray *c27_b_sf_marshallOut(void *chartInstanceVoid, void
  *c27_b_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  real_T c27_u;
  const mxArray *c27_y = NULL;
  SFc27_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc27_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_u = *(real_T *)c27_b_inData;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", &c27_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

static real_T c27_c_emlrt_marshallIn(SFc27_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c27_b_liminf_y, const char_T *c27_identifier)
{
  real_T c27_y;
  emlrtMsgIdentifier c27_thisId;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_b_liminf_y),
    &c27_thisId);
  sf_mex_destroy(&c27_b_liminf_y);
  return c27_y;
}

static real_T c27_d_emlrt_marshallIn(SFc27_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  real_T c27_y;
  real_T c27_d9;
  (void)chartInstance;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_d9, 1, 0, 0U, 0, 0U, 0);
  c27_y = c27_d9;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void c27_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_b_liminf_y;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  real_T c27_y;
  SFc27_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc27_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c27_b_liminf_y = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_b_liminf_y),
    &c27_thisId);
  sf_mex_destroy(&c27_b_liminf_y);
  *(real_T *)c27_outData = c27_y;
  sf_mex_destroy(&c27_mxArrayInData);
}

static const mxArray *c27_c_sf_marshallOut(void *chartInstanceVoid, void
  *c27_b_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_i40;
  int32_T c27_i41;
  int32_T c27_i42;
  real_T c27_c_inData[64];
  int32_T c27_i43;
  int32_T c27_i44;
  int32_T c27_i45;
  real_T c27_u[64];
  const mxArray *c27_y = NULL;
  SFc27_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc27_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_i40 = 0;
  for (c27_i41 = 0; c27_i41 < 32; c27_i41++) {
    for (c27_i42 = 0; c27_i42 < 2; c27_i42++) {
      c27_c_inData[c27_i42 + c27_i40] = (*(real_T (*)[64])c27_b_inData)[c27_i42
        + c27_i40];
    }

    c27_i40 += 2;
  }

  c27_i43 = 0;
  for (c27_i44 = 0; c27_i44 < 32; c27_i44++) {
    for (c27_i45 = 0; c27_i45 < 2; c27_i45++) {
      c27_u[c27_i45 + c27_i43] = c27_c_inData[c27_i45 + c27_i43];
    }

    c27_i43 += 2;
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 0, 0U, 1U, 0U, 2, 2, 32),
                false);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

static void c27_e_emlrt_marshallIn(SFc27_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c27_b_posObj_subim, const char_T
  *c27_identifier, real_T c27_y[64])
{
  emlrtMsgIdentifier c27_thisId;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_b_posObj_subim),
    &c27_thisId, c27_y);
  sf_mex_destroy(&c27_b_posObj_subim);
}

static void c27_f_emlrt_marshallIn(SFc27_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
  real_T c27_y[64])
{
  real_T c27_dv3[64];
  int32_T c27_i46;
  (void)chartInstance;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), c27_dv3, 1, 0, 0U, 1, 0U, 2, 2,
                32);
  for (c27_i46 = 0; c27_i46 < 64; c27_i46++) {
    c27_y[c27_i46] = c27_dv3[c27_i46];
  }

  sf_mex_destroy(&c27_u);
}

static void c27_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_b_posObj_subim;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  real_T c27_y[64];
  int32_T c27_i47;
  int32_T c27_i48;
  int32_T c27_i49;
  SFc27_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc27_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c27_b_posObj_subim = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_b_posObj_subim),
    &c27_thisId, c27_y);
  sf_mex_destroy(&c27_b_posObj_subim);
  c27_i47 = 0;
  for (c27_i48 = 0; c27_i48 < 32; c27_i48++) {
    for (c27_i49 = 0; c27_i49 < 2; c27_i49++) {
      (*(real_T (*)[64])c27_outData)[c27_i49 + c27_i47] = c27_y[c27_i49 +
        c27_i47];
    }

    c27_i47 += 2;
  }

  sf_mex_destroy(&c27_mxArrayInData);
}

static const mxArray *c27_d_sf_marshallOut(void *chartInstanceVoid, uint8_T
  c27_b_inData_data[], int32_T c27_inData_sizes[2])
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_u_sizes[2];
  int32_T c27_u;
  int32_T c27_b_u;
  int32_T c27_b_inData;
  int32_T c27_c_inData;
  int32_T c27_b_inData_sizes;
  int32_T c27_loop_ub;
  int32_T c27_i50;
  int32_T c27_b_loop_ub;
  int32_T c27_i51;
  uint8_T c27_u_data[187500];
  const mxArray *c27_y = NULL;
  SFc27_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc27_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_u_sizes[0] = c27_inData_sizes[0];
  c27_u_sizes[1] = c27_inData_sizes[1];
  c27_u = c27_u_sizes[0];
  c27_b_u = c27_u_sizes[1];
  c27_b_inData = c27_inData_sizes[0];
  c27_c_inData = c27_inData_sizes[1];
  c27_b_inData_sizes = c27_b_inData * c27_c_inData;
  c27_loop_ub = c27_b_inData * c27_c_inData - 1;
  for (c27_i50 = 0; c27_i50 <= c27_loop_ub; c27_i50++) {
    chartInstance->c27_inData_data[c27_i50] = c27_b_inData_data[c27_i50];
  }

  c27_b_loop_ub = c27_b_inData_sizes - 1;
  for (c27_i51 = 0; c27_i51 <= c27_b_loop_ub; c27_i51++) {
    c27_u_data[c27_i51] = chartInstance->c27_inData_data[c27_i51];
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u_data, 3, 0U, 1U, 0U, 2,
    c27_u_sizes[0], c27_u_sizes[1]), false);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

static void c27_g_emlrt_marshallIn(SFc27_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c27_sub_im, const char_T *c27_identifier,
  uint8_T c27_b_y_data[], int32_T c27_y_sizes[2])
{
  emlrtMsgIdentifier c27_thisId;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_sub_im), &c27_thisId,
    c27_b_y_data, c27_y_sizes);
  sf_mex_destroy(&c27_sub_im);
}

static void c27_h_emlrt_marshallIn(SFc27_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
  uint8_T c27_b_y_data[], int32_T c27_y_sizes[2])
{
  int32_T c27_i52;
  uint32_T c27_uv1[2];
  int32_T c27_i53;
  boolean_T c27_bv0[2];
  int32_T c27_tmp_sizes[2];
  uint8_T c27_b_tmp_data[187500];
  int32_T c27_y;
  int32_T c27_b_y;
  int32_T c27_loop_ub;
  int32_T c27_i54;
  (void)chartInstance;
  for (c27_i52 = 0; c27_i52 < 2; c27_i52++) {
    c27_uv1[c27_i52] = 375U + 125U * (uint32_T)c27_i52;
  }

  for (c27_i53 = 0; c27_i53 < 2; c27_i53++) {
    c27_bv0[c27_i53] = true;
  }

  sf_mex_import_vs(c27_parentId, sf_mex_dup(c27_u), c27_b_tmp_data, 1, 3, 0U, 1,
                   0U, 2, c27_bv0, c27_uv1, c27_tmp_sizes);
  c27_y_sizes[0] = c27_tmp_sizes[0];
  c27_y_sizes[1] = c27_tmp_sizes[1];
  c27_y = c27_y_sizes[0];
  c27_b_y = c27_y_sizes[1];
  c27_loop_ub = c27_tmp_sizes[0] * c27_tmp_sizes[1] - 1;
  for (c27_i54 = 0; c27_i54 <= c27_loop_ub; c27_i54++) {
    c27_b_y_data[c27_i54] = c27_b_tmp_data[c27_i54];
  }

  sf_mex_destroy(&c27_u);
}

static void c27_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, uint8_T c27_outData_data[],
  int32_T c27_outData_sizes[2])
{
  const mxArray *c27_sub_im;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  int32_T c27_y_sizes[2];
  int32_T c27_loop_ub;
  int32_T c27_i55;
  int32_T c27_b_loop_ub;
  int32_T c27_i56;
  SFc27_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc27_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c27_sub_im = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_sub_im), &c27_thisId,
    chartInstance->c27_y_data, c27_y_sizes);
  sf_mex_destroy(&c27_sub_im);
  c27_outData_sizes[0] = c27_y_sizes[0];
  c27_outData_sizes[1] = c27_y_sizes[1];
  c27_loop_ub = c27_y_sizes[1] - 1;
  for (c27_i55 = 0; c27_i55 <= c27_loop_ub; c27_i55++) {
    c27_b_loop_ub = c27_y_sizes[0] - 1;
    for (c27_i56 = 0; c27_i56 <= c27_b_loop_ub; c27_i56++) {
      c27_outData_data[c27_i56 + c27_outData_sizes[0] * c27_i55] =
        chartInstance->c27_y_data[c27_i56 + c27_y_sizes[0] * c27_i55];
    }
  }

  sf_mex_destroy(&c27_mxArrayInData);
}

static const mxArray *c27_e_sf_marshallOut(void *chartInstanceVoid, void
  *c27_b_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_i57;
  real_T c27_c_inData[32];
  int32_T c27_i58;
  real_T c27_u[32];
  const mxArray *c27_y = NULL;
  SFc27_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc27_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  for (c27_i57 = 0; c27_i57 < 32; c27_i57++) {
    c27_c_inData[c27_i57] = (*(real_T (*)[32])c27_b_inData)[c27_i57];
  }

  for (c27_i58 = 0; c27_i58 < 32; c27_i58++) {
    c27_u[c27_i58] = c27_c_inData[c27_i58];
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 0, 0U, 1U, 0U, 2, 1, 32),
                false);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

static const mxArray *c27_f_sf_marshallOut(void *chartInstanceVoid, void
  *c27_b_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_i59;
  int32_T c27_i60;
  int32_T c27_i61;
  int32_T c27_i62;
  int32_T c27_i63;
  int32_T c27_i64;
  uint8_T c27_u[187500];
  const mxArray *c27_y = NULL;
  SFc27_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc27_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_i59 = 0;
  for (c27_i60 = 0; c27_i60 < 500; c27_i60++) {
    for (c27_i61 = 0; c27_i61 < 375; c27_i61++) {
      chartInstance->c27_inData[c27_i61 + c27_i59] = (*(uint8_T (*)[187500])
        c27_b_inData)[c27_i61 + c27_i59];
    }

    c27_i59 += 375;
  }

  c27_i62 = 0;
  for (c27_i63 = 0; c27_i63 < 500; c27_i63++) {
    for (c27_i64 = 0; c27_i64 < 375; c27_i64++) {
      c27_u[c27_i64 + c27_i62] = chartInstance->c27_inData[c27_i64 + c27_i62];
    }

    c27_i62 += 375;
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 3, 0U, 1U, 0U, 2, 375, 500),
                false);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

const mxArray *sf_c27_Experiment_1_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c27_nameCaptureInfo = NULL;
  c27_nameCaptureInfo = NULL;
  sf_mex_assign(&c27_nameCaptureInfo, sf_mex_createstruct("structure", 2, 13, 1),
                false);
  c27_info_helper(&c27_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c27_nameCaptureInfo);
  return c27_nameCaptureInfo;
}

static void c27_info_helper(const mxArray **c27_info)
{
  const mxArray *c27_rhs0 = NULL;
  const mxArray *c27_lhs0 = NULL;
  const mxArray *c27_rhs1 = NULL;
  const mxArray *c27_lhs1 = NULL;
  const mxArray *c27_rhs2 = NULL;
  const mxArray *c27_lhs2 = NULL;
  const mxArray *c27_rhs3 = NULL;
  const mxArray *c27_lhs3 = NULL;
  const mxArray *c27_rhs4 = NULL;
  const mxArray *c27_lhs4 = NULL;
  const mxArray *c27_rhs5 = NULL;
  const mxArray *c27_lhs5 = NULL;
  const mxArray *c27_rhs6 = NULL;
  const mxArray *c27_lhs6 = NULL;
  const mxArray *c27_rhs7 = NULL;
  const mxArray *c27_lhs7 = NULL;
  const mxArray *c27_rhs8 = NULL;
  const mxArray *c27_lhs8 = NULL;
  const mxArray *c27_rhs9 = NULL;
  const mxArray *c27_lhs9 = NULL;
  const mxArray *c27_rhs10 = NULL;
  const mxArray *c27_lhs10 = NULL;
  const mxArray *c27_rhs11 = NULL;
  const mxArray *c27_lhs11 = NULL;
  const mxArray *c27_rhs12 = NULL;
  const mxArray *c27_lhs12 = NULL;
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("round"), "name", "name", 0);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c27_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c27_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalar_round"), "name",
                  "name", 2);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1307672838U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c27_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "context", "context", 3);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("abs"), "name", "name", 3);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c27_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c27_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 5);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c27_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "context", "context", 6);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("length"), "name", "name", 6);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("uint8"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1303167806U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c27_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength"),
                  "context", "context", 7);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 7);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c27_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength"),
                  "context", "context", 8);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.indexIntRelop"), "name", "name", 8);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1326749922U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c27_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!apply_float_relop"),
                  "context", "context", 9);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 9);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c27_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass"),
                  "context", "context", 10);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 10);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c27_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass"),
                  "context", "context", 11);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("intmin"), "name", "name", 11);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c27_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 12);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c27_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs12), "lhs", "lhs",
                  12);
  sf_mex_destroy(&c27_rhs0);
  sf_mex_destroy(&c27_lhs0);
  sf_mex_destroy(&c27_rhs1);
  sf_mex_destroy(&c27_lhs1);
  sf_mex_destroy(&c27_rhs2);
  sf_mex_destroy(&c27_lhs2);
  sf_mex_destroy(&c27_rhs3);
  sf_mex_destroy(&c27_lhs3);
  sf_mex_destroy(&c27_rhs4);
  sf_mex_destroy(&c27_lhs4);
  sf_mex_destroy(&c27_rhs5);
  sf_mex_destroy(&c27_lhs5);
  sf_mex_destroy(&c27_rhs6);
  sf_mex_destroy(&c27_lhs6);
  sf_mex_destroy(&c27_rhs7);
  sf_mex_destroy(&c27_lhs7);
  sf_mex_destroy(&c27_rhs8);
  sf_mex_destroy(&c27_lhs8);
  sf_mex_destroy(&c27_rhs9);
  sf_mex_destroy(&c27_lhs9);
  sf_mex_destroy(&c27_rhs10);
  sf_mex_destroy(&c27_lhs10);
  sf_mex_destroy(&c27_rhs11);
  sf_mex_destroy(&c27_lhs11);
  sf_mex_destroy(&c27_rhs12);
  sf_mex_destroy(&c27_lhs12);
}

static const mxArray *c27_emlrt_marshallOut(const char * c27_u)
{
  const mxArray *c27_y = NULL;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c27_u)), false);
  return c27_y;
}

static const mxArray *c27_b_emlrt_marshallOut(const uint32_T c27_u)
{
  const mxArray *c27_y = NULL;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", &c27_u, 7, 0U, 0U, 0U, 0), false);
  return c27_y;
}

static real_T c27_round(SFc27_Experiment_1_csInstanceStruct *chartInstance,
  real_T c27_x)
{
  real_T c27_b_x;
  c27_b_x = c27_x;
  c27_b_round(chartInstance, &c27_b_x);
  return c27_b_x;
}

static real_T c27_abs(SFc27_Experiment_1_csInstanceStruct *chartInstance, real_T
                      c27_x)
{
  real_T c27_b_x;
  (void)chartInstance;
  c27_b_x = c27_x;
  return muDoubleScalarAbs(c27_b_x);
}

static int32_T c27_intlength(SFc27_Experiment_1_csInstanceStruct *chartInstance,
  uint8_T c27_b_x_data[], int32_T c27_x_sizes[2])
{
  int32_T c27_n;
  real_T c27_a;
  real_T c27_b_a;
  real_T c27_flt;
  boolean_T c27_p;
  real_T c27_c_a;
  real_T c27_d_a;
  real_T c27_b_flt;
  boolean_T c27_b_p;
  boolean_T guard1 = false;
  (void)chartInstance;
  (void)c27_b_x_data;
  c27_a = (real_T)c27_x_sizes[0];
  c27_b_a = c27_a;
  c27_flt = c27_b_a;
  c27_p = (0.0 == c27_flt);
  guard1 = false;
  if (c27_p) {
    guard1 = true;
  } else {
    c27_c_a = (real_T)c27_x_sizes[1];
    c27_d_a = c27_c_a;
    c27_b_flt = c27_d_a;
    c27_b_p = (0.0 == c27_b_flt);
    if (c27_b_p) {
      guard1 = true;
    } else if ((real_T)c27_x_sizes[0] > (real_T)c27_x_sizes[1]) {
      c27_n = c27_x_sizes[0];
    } else {
      c27_n = c27_x_sizes[1];
    }
  }

  if (guard1 == true) {
    c27_n = 0;
  }

  return c27_n;
}

static const mxArray *c27_g_sf_marshallOut(void *chartInstanceVoid, void
  *c27_b_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_u;
  const mxArray *c27_y = NULL;
  SFc27_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc27_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_u = *(int32_T *)c27_b_inData;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", &c27_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

static int32_T c27_i_emlrt_marshallIn(SFc27_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  int32_T c27_y;
  int32_T c27_i65;
  (void)chartInstance;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_i65, 1, 6, 0U, 0, 0U, 0);
  c27_y = c27_i65;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void c27_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_b_sfEvent;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  int32_T c27_y;
  SFc27_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc27_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c27_b_sfEvent = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_b_sfEvent),
    &c27_thisId);
  sf_mex_destroy(&c27_b_sfEvent);
  *(int32_T *)c27_outData = c27_y;
  sf_mex_destroy(&c27_mxArrayInData);
}

static uint8_T c27_j_emlrt_marshallIn(SFc27_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c27_b_is_active_c27_Experiment_1_cs, const
  char_T *c27_identifier)
{
  uint8_T c27_y;
  emlrtMsgIdentifier c27_thisId;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c27_b_is_active_c27_Experiment_1_cs), &c27_thisId);
  sf_mex_destroy(&c27_b_is_active_c27_Experiment_1_cs);
  return c27_y;
}

static uint8_T c27_k_emlrt_marshallIn(SFc27_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  uint8_T c27_y;
  uint8_T c27_u0;
  (void)chartInstance;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_u0, 1, 3, 0U, 0, 0U, 0);
  c27_y = c27_u0;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void c27_b_round(SFc27_Experiment_1_csInstanceStruct *chartInstance,
  real_T *c27_x)
{
  (void)chartInstance;
  *c27_x = muDoubleScalarRound(*c27_x);
}

static void init_dsm_address_info(SFc27_Experiment_1_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc27_Experiment_1_csInstanceStruct
  *chartInstance)
{
  chartInstance->c27_b_im = (uint8_T (*)[187500])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c27_PosObj = (real_T (*)[64])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c27_X = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c27_Y = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c27_b_sub_im_data = (uint8_T (*)[187500])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c27_sub_im_sizes = (int32_T (*)[2])
    ssGetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1);
  chartInstance->c27_posObj_subim = (real_T (*)[64])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c27_im_x = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c27_im_y = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c27_liminf_x = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c27_liminf_y = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c27_rectangle = (real_T (*)[4])ssGetOutputPortSignal_wrapper
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

void sf_c27_Experiment_1_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(928763364U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3021481460U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1804990352U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1296217343U);
}

mxArray* sf_c27_Experiment_1_cs_get_post_codegen_info(void);
mxArray *sf_c27_Experiment_1_cs_get_autoinheritance_info(void)
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
    mxArray* mxPostCodegenInfo = sf_c27_Experiment_1_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c27_Experiment_1_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c27_Experiment_1_cs_jit_fallback_info(void)
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

mxArray *sf_c27_Experiment_1_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c27_Experiment_1_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c27_Experiment_1_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[16],T\"im_x\",},{M[1],M[17],T\"im_y\",},{M[1],M[18],T\"liminf_x\",},{M[1],M[19],T\"liminf_y\",},{M[1],M[15],T\"posObj_subim\",},{M[1],M[20],T\"rectangle\",},{M[1],M[14],T\"sub_im\",},{M[8],M[0],T\"is_active_c27_Experiment_1_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c27_Experiment_1_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc27_Experiment_1_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc27_Experiment_1_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_1_csMachineNumber_,
           27,
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
            1.0,0,0,(MexFcnForType)c27_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c27_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c27_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c27_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 375;
          dimVector[1]= 500;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c27_d_sf_marshallOut,(MexInFcnForType)
            c27_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c27_c_sf_marshallOut,(MexInFcnForType)
            c27_c_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_b_sf_marshallOut,(MexInFcnForType)
          c27_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_b_sf_marshallOut,(MexInFcnForType)
          c27_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_b_sf_marshallOut,(MexInFcnForType)
          c27_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_b_sf_marshallOut,(MexInFcnForType)
          c27_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c27_sf_marshallOut,(MexInFcnForType)
            c27_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c27_b_im);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c27_PosObj);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c27_X);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c27_Y);
        _SFD_SET_DATA_VALUE_PTR_VAR_DIM(4U, *chartInstance->c27_b_sub_im_data,
          (void *)chartInstance->c27_sub_im_sizes);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c27_posObj_subim);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c27_im_x);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c27_im_y);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c27_liminf_x);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c27_liminf_y);
        _SFD_SET_DATA_VALUE_PTR(10U, *chartInstance->c27_rectangle);
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
  return "RlznJxzpa5Wmk1dcipe7PG";
}

static void sf_opaque_initialize_c27_Experiment_1_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc27_Experiment_1_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c27_Experiment_1_cs((SFc27_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
  initialize_c27_Experiment_1_cs((SFc27_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c27_Experiment_1_cs(void *chartInstanceVar)
{
  enable_c27_Experiment_1_cs((SFc27_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c27_Experiment_1_cs(void *chartInstanceVar)
{
  disable_c27_Experiment_1_cs((SFc27_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c27_Experiment_1_cs(void *chartInstanceVar)
{
  sf_gateway_c27_Experiment_1_cs((SFc27_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c27_Experiment_1_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c27_Experiment_1_cs((SFc27_Experiment_1_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c27_Experiment_1_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c27_Experiment_1_cs((SFc27_Experiment_1_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c27_Experiment_1_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc27_Experiment_1_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_1_cs_optimization_info();
    }

    finalize_c27_Experiment_1_cs((SFc27_Experiment_1_csInstanceStruct*)
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
  initSimStructsc27_Experiment_1_cs((SFc27_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c27_Experiment_1_cs(SimStruct *S)
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
    initialize_params_c27_Experiment_1_cs((SFc27_Experiment_1_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c27_Experiment_1_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Experiment_1_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      27);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,27,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,27,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,27);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,27,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,27,7);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,27);
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

static void mdlRTW_c27_Experiment_1_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c27_Experiment_1_cs(SimStruct *S)
{
  SFc27_Experiment_1_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc27_Experiment_1_csInstanceStruct *)utMalloc(sizeof
    (SFc27_Experiment_1_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc27_Experiment_1_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c27_Experiment_1_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c27_Experiment_1_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c27_Experiment_1_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c27_Experiment_1_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c27_Experiment_1_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c27_Experiment_1_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c27_Experiment_1_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c27_Experiment_1_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c27_Experiment_1_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c27_Experiment_1_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c27_Experiment_1_cs;
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

void c27_Experiment_1_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c27_Experiment_1_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c27_Experiment_1_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c27_Experiment_1_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c27_Experiment_1_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
