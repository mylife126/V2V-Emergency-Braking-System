/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_3_cs_sfun.h"
#include "c18_Experiment_3_cs.h"
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
static const char * c18_debug_family_names[26] = { "a", "i", "touch", "or_val",
  "lr", "lh", "lc", "lw", "centroid", "nargin", "nargout", "bbox", "majoraxis",
  "minoraxis", "orientation", "eccentricity", "label", "im_x", "im_y",
  "posObj_subim", "liminf_x", "liminf_y", "centout", "bboxout", "label_out",
  "posObj_im" };

/* Function Declarations */
static void initialize_c18_Experiment_3_cs(SFc18_Experiment_3_csInstanceStruct
  *chartInstance);
static void initialize_params_c18_Experiment_3_cs
  (SFc18_Experiment_3_csInstanceStruct *chartInstance);
static void enable_c18_Experiment_3_cs(SFc18_Experiment_3_csInstanceStruct
  *chartInstance);
static void disable_c18_Experiment_3_cs(SFc18_Experiment_3_csInstanceStruct
  *chartInstance);
static void c18_update_debugger_state_c18_Experiment_3_cs
  (SFc18_Experiment_3_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c18_Experiment_3_cs
  (SFc18_Experiment_3_csInstanceStruct *chartInstance);
static void set_sim_state_c18_Experiment_3_cs
  (SFc18_Experiment_3_csInstanceStruct *chartInstance, const mxArray *c18_st);
static void finalize_c18_Experiment_3_cs(SFc18_Experiment_3_csInstanceStruct
  *chartInstance);
static void sf_gateway_c18_Experiment_3_cs(SFc18_Experiment_3_csInstanceStruct
  *chartInstance);
static void mdl_start_c18_Experiment_3_cs(SFc18_Experiment_3_csInstanceStruct
  *chartInstance);
static void c18_chartstep_c18_Experiment_3_cs
  (SFc18_Experiment_3_csInstanceStruct *chartInstance);
static void initSimStructsc18_Experiment_3_cs
  (SFc18_Experiment_3_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c18_machineNumber, uint32_T
  c18_chartNumber, uint32_T c18_instanceNumber);
static const mxArray *c18_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static void c18_emlrt_marshallIn(SFc18_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c18_b_posObj_im, const char_T *c18_identifier,
  real_T c18_y[64]);
static void c18_b_emlrt_marshallIn(SFc18_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId,
  real_T c18_y[64]);
static void c18_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static const mxArray *c18_b_sf_marshallOut(void *chartInstanceVoid, real_T
  c18_c_inData_data[], int32_T c18_inData_sizes[2]);
static void c18_c_emlrt_marshallIn(SFc18_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c18_label_out, const char_T *c18_identifier,
  real_T c18_b_y_data[], int32_T c18_y_sizes[2]);
static void c18_d_emlrt_marshallIn(SFc18_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId,
  real_T c18_b_y_data[], int32_T c18_y_sizes[2]);
static void c18_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, real_T c18_outData_data[],
  int32_T c18_outData_sizes[2]);
static const mxArray *c18_c_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static void c18_e_emlrt_marshallIn(SFc18_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c18_b_bboxout, const char_T *c18_identifier,
  int32_T c18_y[400]);
static void c18_f_emlrt_marshallIn(SFc18_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId,
  int32_T c18_y[400]);
static void c18_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static const mxArray *c18_d_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static void c18_g_emlrt_marshallIn(SFc18_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c18_b_centout, const char_T *c18_identifier,
  int32_T c18_y[200]);
static void c18_h_emlrt_marshallIn(SFc18_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId,
  int32_T c18_y[200]);
static void c18_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static const mxArray *c18_e_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static const mxArray *c18_f_sf_marshallOut(void *chartInstanceVoid, uint8_T
  c18_c_inData_data[], int32_T c18_inData_sizes[2]);
static const mxArray *c18_g_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static const mxArray *c18_h_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static const mxArray *c18_i_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static real_T c18_i_emlrt_marshallIn(SFc18_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void c18_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static const mxArray *c18_j_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static int32_T c18_j_emlrt_marshallIn(SFc18_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void c18_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static void c18_info_helper(const mxArray **c18_info);
static const mxArray *c18_emlrt_marshallOut(const char * c18_u);
static const mxArray *c18_b_emlrt_marshallOut(const uint32_T c18_u);
static real_T c18_abs(SFc18_Experiment_3_csInstanceStruct *chartInstance, real_T
                      c18_x);
static uint8_T c18_k_emlrt_marshallIn(SFc18_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c18_b_is_active_c18_Experiment_3_cs, const
  char_T *c18_identifier);
static uint8_T c18_l_emlrt_marshallIn(SFc18_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void init_dsm_address_info(SFc18_Experiment_3_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc18_Experiment_3_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c18_Experiment_3_cs(SFc18_Experiment_3_csInstanceStruct
  *chartInstance)
{
  chartInstance->c18_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c18_is_active_c18_Experiment_3_cs = 0U;
}

static void initialize_params_c18_Experiment_3_cs
  (SFc18_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c18_Experiment_3_cs(SFc18_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c18_Experiment_3_cs(SFc18_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c18_update_debugger_state_c18_Experiment_3_cs
  (SFc18_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c18_Experiment_3_cs
  (SFc18_Experiment_3_csInstanceStruct *chartInstance)
{
  const mxArray *c18_st;
  const mxArray *c18_y = NULL;
  int32_T c18_i0;
  int32_T c18_u[400];
  const mxArray *c18_b_y = NULL;
  int32_T c18_i1;
  int32_T c18_b_u[200];
  const mxArray *c18_c_y = NULL;
  int32_T c18_u_sizes[2];
  int32_T c18_c_u;
  int32_T c18_d_u;
  int32_T c18_loop_ub;
  int32_T c18_i2;
  const mxArray *c18_d_y = NULL;
  int32_T c18_i3;
  real_T c18_e_u[64];
  const mxArray *c18_e_y = NULL;
  uint8_T c18_hoistedGlobal;
  uint8_T c18_f_u;
  const mxArray *c18_f_y = NULL;
  c18_st = NULL;
  c18_st = NULL;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_createcellmatrix(5, 1), false);
  for (c18_i0 = 0; c18_i0 < 400; c18_i0++) {
    c18_u[c18_i0] = (*chartInstance->c18_bboxout)[c18_i0];
  }

  c18_b_y = NULL;
  sf_mex_assign(&c18_b_y, sf_mex_create("y", c18_u, 6, 0U, 1U, 0U, 2, 4, 100),
                false);
  sf_mex_setcell(c18_y, 0, c18_b_y);
  for (c18_i1 = 0; c18_i1 < 200; c18_i1++) {
    c18_b_u[c18_i1] = (*chartInstance->c18_centout)[c18_i1];
  }

  c18_c_y = NULL;
  sf_mex_assign(&c18_c_y, sf_mex_create("y", c18_b_u, 6, 0U, 1U, 0U, 2, 2, 100),
                false);
  sf_mex_setcell(c18_y, 1, c18_c_y);
  c18_u_sizes[0] = (*chartInstance->c18_label_out_sizes)[0];
  c18_u_sizes[1] = (*chartInstance->c18_label_out_sizes)[1];
  c18_c_u = c18_u_sizes[0];
  c18_d_u = c18_u_sizes[1];
  c18_loop_ub = (*chartInstance->c18_label_out_sizes)[0] *
    (*chartInstance->c18_label_out_sizes)[1] - 1;
  for (c18_i2 = 0; c18_i2 <= c18_loop_ub; c18_i2++) {
    chartInstance->c18_b_u_data[c18_i2] = (*chartInstance->c18_b_label_out_data)
      [c18_i2];
  }

  c18_d_y = NULL;
  sf_mex_assign(&c18_d_y, sf_mex_create("y", chartInstance->c18_b_u_data, 0, 0U,
    1U, 0U, 2, c18_u_sizes[0], c18_u_sizes[1]), false);
  sf_mex_setcell(c18_y, 2, c18_d_y);
  for (c18_i3 = 0; c18_i3 < 64; c18_i3++) {
    c18_e_u[c18_i3] = (*chartInstance->c18_posObj_im)[c18_i3];
  }

  c18_e_y = NULL;
  sf_mex_assign(&c18_e_y, sf_mex_create("y", c18_e_u, 0, 0U, 1U, 0U, 2, 2, 32),
                false);
  sf_mex_setcell(c18_y, 3, c18_e_y);
  c18_hoistedGlobal = chartInstance->c18_is_active_c18_Experiment_3_cs;
  c18_f_u = c18_hoistedGlobal;
  c18_f_y = NULL;
  sf_mex_assign(&c18_f_y, sf_mex_create("y", &c18_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c18_y, 4, c18_f_y);
  sf_mex_assign(&c18_st, c18_y, false);
  return c18_st;
}

static void set_sim_state_c18_Experiment_3_cs
  (SFc18_Experiment_3_csInstanceStruct *chartInstance, const mxArray *c18_st)
{
  const mxArray *c18_u;
  int32_T c18_iv0[400];
  int32_T c18_i4;
  int32_T c18_iv1[200];
  int32_T c18_i5;
  int32_T c18_tmp_sizes[2];
  int32_T c18_i6;
  int32_T c18_i7;
  int32_T c18_loop_ub;
  int32_T c18_i8;
  real_T c18_dv0[64];
  int32_T c18_i9;
  chartInstance->c18_doneDoubleBufferReInit = true;
  c18_u = sf_mex_dup(c18_st);
  c18_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c18_u, 0)),
    "bboxout", c18_iv0);
  for (c18_i4 = 0; c18_i4 < 400; c18_i4++) {
    (*chartInstance->c18_bboxout)[c18_i4] = c18_iv0[c18_i4];
  }

  c18_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c18_u, 1)),
    "centout", c18_iv1);
  for (c18_i5 = 0; c18_i5 < 200; c18_i5++) {
    (*chartInstance->c18_centout)[c18_i5] = c18_iv1[c18_i5];
  }

  c18_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c18_u, 2)),
    "label_out", chartInstance->c18_tmp_data, c18_tmp_sizes);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 3, 0,
    c18_tmp_sizes[0]);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 3, 1,
    c18_tmp_sizes[1]);
  c18_i6 = (*chartInstance->c18_label_out_sizes)[0];
  c18_i7 = (*chartInstance->c18_label_out_sizes)[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_i8 = 0; c18_i8 <= c18_loop_ub; c18_i8++) {
    (*chartInstance->c18_b_label_out_data)[c18_i8] = chartInstance->
      c18_tmp_data[c18_i8];
  }

  c18_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c18_u, 3)),
                       "posObj_im", c18_dv0);
  for (c18_i9 = 0; c18_i9 < 64; c18_i9++) {
    (*chartInstance->c18_posObj_im)[c18_i9] = c18_dv0[c18_i9];
  }

  chartInstance->c18_is_active_c18_Experiment_3_cs = c18_k_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c18_u, 4)),
     "is_active_c18_Experiment_3_cs");
  sf_mex_destroy(&c18_u);
  c18_update_debugger_state_c18_Experiment_3_cs(chartInstance);
  sf_mex_destroy(&c18_st);
}

static void finalize_c18_Experiment_3_cs(SFc18_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c18_Experiment_3_cs(SFc18_Experiment_3_csInstanceStruct
  *chartInstance)
{
  int32_T c18_i10;
  int32_T c18_i11;
  int32_T c18_i12;
  int32_T c18_i13;
  int32_T c18_i14;
  int32_T c18_i15;
  int32_T c18_i16;
  int32_T c18_i17;
  int32_T c18_loop_ub;
  int32_T c18_i18;
  int32_T c18_b_loop_ub;
  int32_T c18_i19;
  int32_T c18_i20;
  int32_T c18_i21;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 17U, chartInstance->c18_sfEvent);
  for (c18_i10 = 0; c18_i10 < 200; c18_i10++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c18_centroid)[c18_i10], 0U);
  }

  chartInstance->c18_sfEvent = CALL_EVENT;
  c18_chartstep_c18_Experiment_3_cs(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_3_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c18_i11 = 0; c18_i11 < 200; c18_i11++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c18_centout)[c18_i11], 1U);
  }

  for (c18_i12 = 0; c18_i12 < 400; c18_i12++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c18_bbox)[c18_i12], 2U);
  }

  for (c18_i13 = 0; c18_i13 < 400; c18_i13++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c18_bboxout)[c18_i13], 3U);
  }

  for (c18_i14 = 0; c18_i14 < 100; c18_i14++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c18_majoraxis)[c18_i14], 4U);
  }

  for (c18_i15 = 0; c18_i15 < 100; c18_i15++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c18_minoraxis)[c18_i15], 5U);
  }

  for (c18_i16 = 0; c18_i16 < 100; c18_i16++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c18_orientation)[c18_i16], 6U);
  }

  for (c18_i17 = 0; c18_i17 < 100; c18_i17++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c18_eccentricity)[c18_i17],
                          7U);
  }

  c18_loop_ub = (*chartInstance->c18_label_sizes)[0] *
    (*chartInstance->c18_label_sizes)[1] - 1;
  for (c18_i18 = 0; c18_i18 <= c18_loop_ub; c18_i18++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c18_b_label_data)[c18_i18],
                          8U);
  }

  c18_b_loop_ub = (*chartInstance->c18_label_out_sizes)[0] *
    (*chartInstance->c18_label_out_sizes)[1] - 1;
  for (c18_i19 = 0; c18_i19 <= c18_b_loop_ub; c18_i19++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c18_b_label_out_data)[c18_i19], 9U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c18_im_x, 10U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c18_im_y, 11U);
  for (c18_i20 = 0; c18_i20 < 64; c18_i20++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c18_posObj_subim)[c18_i20], 12U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c18_liminf_x, 13U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c18_liminf_y, 14U);
  for (c18_i21 = 0; c18_i21 < 64; c18_i21++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c18_posObj_im)[c18_i21], 15U);
  }
}

static void mdl_start_c18_Experiment_3_cs(SFc18_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c18_chartstep_c18_Experiment_3_cs
  (SFc18_Experiment_3_csInstanceStruct *chartInstance)
{
  real_T c18_hoistedGlobal;
  real_T c18_b_hoistedGlobal;
  real_T c18_c_hoistedGlobal;
  real_T c18_d_hoistedGlobal;
  int32_T c18_i22;
  real32_T c18_b_centroid[200];
  int32_T c18_i23;
  int32_T c18_b_bbox[400];
  int32_T c18_i24;
  real32_T c18_b_majoraxis[100];
  int32_T c18_i25;
  real32_T c18_b_minoraxis[100];
  int32_T c18_i26;
  real_T c18_b_orientation[100];
  int32_T c18_i27;
  real32_T c18_b_eccentricity[100];
  int32_T c18_b_label_sizes[2];
  int32_T c18_label;
  int32_T c18_b_label;
  int32_T c18_loop_ub;
  int32_T c18_i28;
  real_T c18_b_im_x;
  real_T c18_b_im_y;
  int32_T c18_i29;
  real_T c18_b_posObj_subim[64];
  real_T c18_b_liminf_x;
  real_T c18_b_liminf_y;
  uint32_T c18_debug_family_var_map[26];
  real_T c18_a;
  real_T c18_i;
  real_T c18_touch;
  real_T c18_or_val;
  int32_T c18_lr;
  int32_T c18_lh;
  int32_T c18_lc;
  int32_T c18_lw;
  int32_T c18_c_centroid[200];
  real_T c18_nargin = 12.0;
  real_T c18_nargout = 4.0;
  int32_T c18_b_centout[200];
  int32_T c18_b_bboxout[400];
  int32_T c18_b_label_out_sizes[2];
  real_T c18_b_posObj_im[64];
  int32_T c18_i30;
  real32_T c18_f0;
  int32_T c18_i31;
  int32_T c18_i32;
  int32_T c18_i33;
  int32_T c18_c_label[2];
  int32_T c18_tmp_sizes[2];
  int32_T c18_d_label[2];
  int32_T c18_i34;
  int32_T c18_i35;
  int32_T c18_b_loop_ub;
  int32_T c18_i36;
  int32_T c18_label_out;
  int32_T c18_b_label_out;
  int32_T c18_c_loop_ub;
  int32_T c18_i37;
  int32_T c18_i38;
  int32_T c18_b_i;
  int32_T c18_c_i;
  int32_T c18_d_i;
  real_T c18_c_liminf_y[2];
  int32_T c18_i39;
  int32_T c18_e_i;
  int64_T c18_i40;
  int64_T c18_i41;
  int64_T c18_i42;
  int64_T c18_i43;
  int64_T c18_i44;
  int64_T c18_i45;
  int32_T c18_A;
  int32_T c18_x;
  int32_T c18_b_x;
  int32_T c18_c_x;
  int32_T c18_d_x;
  int32_T c18_e_x;
  real_T c18_xk;
  real_T c18_d0;
  int32_T c18_i46;
  int32_T c18_y;
  real_T c18_d1;
  int32_T c18_i47;
  int64_T c18_i48;
  real_T c18_d2;
  int32_T c18_b_A;
  int32_T c18_f_x;
  int32_T c18_g_x;
  int32_T c18_h_x;
  int32_T c18_i_x;
  int32_T c18_j_x;
  real_T c18_b_xk;
  real_T c18_d3;
  int32_T c18_i49;
  int32_T c18_b_y;
  real_T c18_d4;
  int32_T c18_i50;
  int64_T c18_i51;
  real_T c18_d5;
  real_T c18_d6;
  real_T c18_d7;
  real32_T c18_c_A;
  real32_T c18_B;
  real32_T c18_k_x;
  real32_T c18_c_y;
  real32_T c18_l_x;
  real32_T c18_d_y;
  real32_T c18_m_x;
  real32_T c18_e_y;
  real32_T c18_f_y;
  real_T c18_d8;
  real32_T c18_d_A;
  real32_T c18_b_B;
  real32_T c18_n_x;
  real32_T c18_g_y;
  real32_T c18_o_x;
  real32_T c18_h_y;
  real32_T c18_p_x;
  real32_T c18_i_y;
  real32_T c18_j_y;
  real_T c18_d9;
  int32_T c18_b_a;
  int32_T c18_f_i;
  real_T c18_d10;
  int32_T c18_i52;
  int32_T c18_d_liminf_y[2];
  real_T c18_d11;
  int32_T c18_i53;
  int32_T c18_i54;
  int64_T c18_i55;
  int32_T c18_c_a;
  int32_T c18_g_i;
  int32_T c18_i56;
  int32_T c18_d_a;
  int32_T c18_h_i;
  real_T c18_d12;
  int32_T c18_i57;
  int32_T c18_e_liminf_y[2];
  real_T c18_d13;
  int32_T c18_i58;
  int32_T c18_i59;
  int64_T c18_i60;
  boolean_T c18_b0;
  boolean_T c18_b1;
  boolean_T c18_b2;
  int32_T c18_i61;
  int32_T c18_i62;
  boolean_T c18_b3;
  boolean_T c18_b4;
  boolean_T c18_b5;
  int32_T c18_i63;
  int32_T c18_i64;
  int32_T c18_b_tmp_sizes;
  int32_T c18_d_loop_ub;
  int32_T c18_i65;
  int32_T c18_d_tmp_data[376];
  int32_T c18_c_tmp_sizes;
  int32_T c18_e_loop_ub;
  int32_T c18_i66;
  int32_T c18_e_tmp_data[501];
  int32_T c18_iv2[2];
  int32_T c18_f_loop_ub;
  int32_T c18_i67;
  int32_T c18_g_loop_ub;
  int32_T c18_i68;
  boolean_T c18_b6;
  boolean_T c18_b7;
  boolean_T c18_b8;
  int32_T c18_i69;
  int32_T c18_i70;
  boolean_T c18_b9;
  boolean_T c18_b10;
  boolean_T c18_b11;
  int32_T c18_i71;
  int32_T c18_i72;
  int32_T c18_h_loop_ub;
  int32_T c18_i73;
  int32_T c18_i_loop_ub;
  int32_T c18_i74;
  int32_T c18_iv3[2];
  int32_T c18_j_loop_ub;
  int32_T c18_i75;
  int32_T c18_k_loop_ub;
  int32_T c18_i76;
  int32_T c18_i77;
  int32_T c18_i78;
  int32_T c18_i79;
  int32_T c18_i80;
  int32_T c18_l_loop_ub;
  int32_T c18_i81;
  int32_T c18_i82;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 17U, chartInstance->c18_sfEvent);
  c18_hoistedGlobal = *chartInstance->c18_im_x;
  c18_b_hoistedGlobal = *chartInstance->c18_im_y;
  c18_c_hoistedGlobal = *chartInstance->c18_liminf_x;
  c18_d_hoistedGlobal = *chartInstance->c18_liminf_y;
  for (c18_i22 = 0; c18_i22 < 200; c18_i22++) {
    c18_b_centroid[c18_i22] = (*chartInstance->c18_centroid)[c18_i22];
  }

  for (c18_i23 = 0; c18_i23 < 400; c18_i23++) {
    c18_b_bbox[c18_i23] = (*chartInstance->c18_bbox)[c18_i23];
  }

  for (c18_i24 = 0; c18_i24 < 100; c18_i24++) {
    c18_b_majoraxis[c18_i24] = (*chartInstance->c18_majoraxis)[c18_i24];
  }

  for (c18_i25 = 0; c18_i25 < 100; c18_i25++) {
    c18_b_minoraxis[c18_i25] = (*chartInstance->c18_minoraxis)[c18_i25];
  }

  for (c18_i26 = 0; c18_i26 < 100; c18_i26++) {
    c18_b_orientation[c18_i26] = (*chartInstance->c18_orientation)[c18_i26];
  }

  for (c18_i27 = 0; c18_i27 < 100; c18_i27++) {
    c18_b_eccentricity[c18_i27] = (*chartInstance->c18_eccentricity)[c18_i27];
  }

  c18_b_label_sizes[0] = (*chartInstance->c18_label_sizes)[0];
  c18_b_label_sizes[1] = (*chartInstance->c18_label_sizes)[1];
  c18_label = c18_b_label_sizes[0];
  c18_b_label = c18_b_label_sizes[1];
  c18_loop_ub = (*chartInstance->c18_label_sizes)[0] *
    (*chartInstance->c18_label_sizes)[1] - 1;
  for (c18_i28 = 0; c18_i28 <= c18_loop_ub; c18_i28++) {
    chartInstance->c18_label_data[c18_i28] = (*chartInstance->c18_b_label_data)
      [c18_i28];
  }

  c18_b_im_x = c18_hoistedGlobal;
  c18_b_im_y = c18_b_hoistedGlobal;
  for (c18_i29 = 0; c18_i29 < 64; c18_i29++) {
    c18_b_posObj_subim[c18_i29] = (*chartInstance->c18_posObj_subim)[c18_i29];
  }

  c18_b_liminf_x = c18_c_hoistedGlobal;
  c18_b_liminf_y = c18_d_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 26U, 27U, c18_debug_family_names,
    c18_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_a, 0U, c18_e_sf_marshallOut,
    c18_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_i, 1U, c18_e_sf_marshallOut,
    c18_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_touch, 2U, c18_e_sf_marshallOut,
    c18_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_or_val, 3U, c18_e_sf_marshallOut,
    c18_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_lr, 4U, c18_j_sf_marshallOut,
    c18_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_lh, 5U, c18_j_sf_marshallOut,
    c18_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_lc, 6U, c18_j_sf_marshallOut,
    c18_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_lw, 7U, c18_j_sf_marshallOut,
    c18_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c18_c_centroid, MAX_uint32_T,
    c18_d_sf_marshallOut, c18_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_nargin, 9U, c18_e_sf_marshallOut,
    c18_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_nargout, 10U, c18_e_sf_marshallOut,
    c18_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c18_b_centroid, 8U, c18_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c18_b_bbox, 11U, c18_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c18_b_majoraxis, 12U, c18_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c18_b_minoraxis, 13U, c18_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c18_b_orientation, 14U, c18_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c18_b_eccentricity, 15U, c18_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN(chartInstance->c18_label_data, (const int32_T *)
    &c18_b_label_sizes, NULL, 1, 16, (void *)c18_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c18_b_im_x, 17U, c18_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c18_b_im_y, 18U, c18_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c18_b_posObj_subim, 19U, c18_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c18_b_liminf_x, 20U, c18_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c18_b_liminf_y, 21U, c18_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c18_b_centout, 22U, c18_d_sf_marshallOut,
    c18_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c18_b_bboxout, 23U, c18_c_sf_marshallOut,
    c18_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(chartInstance->c18_label_out_data, (
    const int32_T *)&c18_b_label_out_sizes, NULL, 0, 24, (void *)
    c18_b_sf_marshallOut, (void *)c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c18_b_posObj_im, 25U, c18_sf_marshallOut,
    c18_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 3);
  c18_a = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 4);
  for (c18_i30 = 0; c18_i30 < 200; c18_i30++) {
    c18_f0 = muSingleScalarRound(c18_b_centroid[c18_i30]);
    if (c18_f0 < 2.14748365E+9F) {
      if (CV_SATURATION_EVAL(4, 0, 4, 1, c18_f0 >= -2.14748365E+9F)) {
        c18_i31 = (int32_T)c18_f0;
      } else {
        c18_i31 = MIN_int32_T;
      }
    } else if (CV_SATURATION_EVAL(4, 0, 4, 0, c18_f0 >= 2.14748365E+9F)) {
      c18_i31 = MAX_int32_T;
    } else {
      c18_i31 = 0;
    }

    c18_c_centroid[c18_i30] = c18_i31;
  }

  _SFD_SYMBOL_SWITCH(8U, 8U);
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 5);
  for (c18_i32 = 0; c18_i32 < 200; c18_i32++) {
    c18_b_centout[c18_i32] = 0;
  }

  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 6);
  for (c18_i33 = 0; c18_i33 < 400; c18_i33++) {
    c18_b_bboxout[c18_i33] = 0;
  }

  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 7);
  c18_c_label[0] = c18_b_label_sizes[0];
  c18_c_label[1] = c18_b_label_sizes[1];
  c18_tmp_sizes[0] = c18_c_label[0];
  c18_d_label[0] = c18_b_label_sizes[0];
  c18_d_label[1] = c18_b_label_sizes[1];
  c18_tmp_sizes[1] = c18_d_label[1];
  c18_i34 = c18_tmp_sizes[0];
  c18_i35 = c18_tmp_sizes[1];
  c18_b_loop_ub = c18_b_label_sizes[0] * c18_b_label_sizes[1] - 1;
  for (c18_i36 = 0; c18_i36 <= c18_b_loop_ub; c18_i36++) {
    chartInstance->c18_c_tmp_data[c18_i36] = 0.0;
  }

  _SFD_DIM_SIZE_GEQ_CHECK(400, c18_tmp_sizes[0], 1);
  _SFD_DIM_SIZE_GEQ_CHECK(550, c18_tmp_sizes[1], 2);
  c18_b_label_out_sizes[0] = c18_tmp_sizes[0];
  c18_b_label_out_sizes[1] = c18_tmp_sizes[1];
  c18_label_out = c18_b_label_out_sizes[0];
  c18_b_label_out = c18_b_label_out_sizes[1];
  c18_c_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_i37 = 0; c18_i37 <= c18_c_loop_ub; c18_i37++) {
    chartInstance->c18_label_out_data[c18_i37] = chartInstance->
      c18_c_tmp_data[c18_i37];
  }

  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 8);
  for (c18_i38 = 0; c18_i38 < 64; c18_i38++) {
    c18_b_posObj_im[c18_i38] = c18_b_posObj_subim[c18_i38];
  }

  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 9);
  c18_i = 1.0;
  c18_b_i = 0;
  while (c18_b_i < 32) {
    c18_i = 1.0 + (real_T)c18_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 10);
    c18_c_i = (int32_T)c18_i - 1;
    c18_d_i = (int32_T)c18_i - 1;
    c18_c_liminf_y[0] = c18_b_liminf_y;
    c18_c_liminf_y[1] = c18_b_liminf_x;
    for (c18_i39 = 0; c18_i39 < 2; c18_i39++) {
      c18_b_posObj_im[c18_i39 + (c18_c_i << 1)] = c18_b_posObj_subim[c18_i39 +
        (c18_d_i << 1)] + c18_c_liminf_y[c18_i39];
    }

    c18_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 13);
  c18_i = 1.0;
  c18_e_i = 0;
  while (c18_e_i < 100) {
    c18_i = 1.0 + (real_T)c18_e_i;
    CV_EML_FOR(0, 1, 1, 1);
    _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 14);
    c18_touch = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 15);
    if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c18_b_orientation
          [(int32_T)c18_i - 1], 180.0, -1, 5U, c18_b_orientation[(int32_T)c18_i
          - 1] >= 180.0))) {
      _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 16);
      c18_or_val = 360.0 - c18_b_orientation[(int32_T)c18_i - 1];
    } else {
      _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 18);
      c18_or_val = c18_b_orientation[(int32_T)c18_i - 1];
    }

    _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 20);
    c18_i40 = (int64_T)c18_b_bbox[((int32_T)c18_i - 1) << 2] + 1LL;
    if (c18_i40 > 2147483647LL) {
      CV_SATURATION_EVAL(4, 0, 5, 0, 1);
      c18_i40 = 2147483647LL;
    } else {
      if (CV_SATURATION_EVAL(4, 0, 5, 0, c18_i40 < -2147483648LL)) {
        c18_i40 = -2147483648LL;
      }
    }

    c18_lr = (int32_T)c18_i40;
    _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 21);
    c18_i41 = (int64_T)c18_lr + (int64_T)c18_b_bbox[2 + (((int32_T)c18_i - 1) <<
      2)];
    if (c18_i41 > 2147483647LL) {
      CV_SATURATION_EVAL(4, 0, 6, 0, 1);
      c18_i41 = 2147483647LL;
    } else {
      if (CV_SATURATION_EVAL(4, 0, 6, 0, c18_i41 < -2147483648LL)) {
        c18_i41 = -2147483648LL;
      }
    }

    c18_i42 = (int64_T)(int32_T)c18_i41 - 1LL;
    if (c18_i42 > 2147483647LL) {
      CV_SATURATION_EVAL(4, 0, 7, 0, 1);
      c18_i42 = 2147483647LL;
    } else {
      if (CV_SATURATION_EVAL(4, 0, 7, 0, c18_i42 < -2147483648LL)) {
        c18_i42 = -2147483648LL;
      }
    }

    c18_lh = (int32_T)c18_i42;
    _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 22);
    c18_i43 = (int64_T)c18_b_bbox[1 + (((int32_T)c18_i - 1) << 2)] + 1LL;
    if (c18_i43 > 2147483647LL) {
      CV_SATURATION_EVAL(4, 0, 8, 0, 1);
      c18_i43 = 2147483647LL;
    } else {
      if (CV_SATURATION_EVAL(4, 0, 8, 0, c18_i43 < -2147483648LL)) {
        c18_i43 = -2147483648LL;
      }
    }

    c18_lc = (int32_T)c18_i43;
    _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 23);
    c18_i44 = (int64_T)c18_lc + (int64_T)c18_b_bbox[3 + (((int32_T)c18_i - 1) <<
      2)];
    if (c18_i44 > 2147483647LL) {
      CV_SATURATION_EVAL(4, 0, 9, 0, 1);
      c18_i44 = 2147483647LL;
    } else {
      if (CV_SATURATION_EVAL(4, 0, 9, 0, c18_i44 < -2147483648LL)) {
        c18_i44 = -2147483648LL;
      }
    }

    c18_i45 = (int64_T)(int32_T)c18_i44 - 1LL;
    if (c18_i45 > 2147483647LL) {
      CV_SATURATION_EVAL(4, 0, 10, 0, 1);
      c18_i45 = 2147483647LL;
    } else {
      if (CV_SATURATION_EVAL(4, 0, 10, 0, c18_i45 < -2147483648LL)) {
        c18_i45 = -2147483648LL;
      }
    }

    c18_lw = (int32_T)c18_i45;
    _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 24);
    if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, (real_T)c18_b_bbox
          [((int32_T)c18_i - 1) << 2], 0.0, -1, 0U, (real_T)c18_b_bbox[((int32_T)
           c18_i - 1) << 2] == 0.0))) {
      _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 25);
      c18_touch = 1.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 27);
    if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 2, (real_T)c18_b_bbox[1 +
          (((int32_T)c18_i - 1) << 2)], 0.0, -1, 0U, (real_T)c18_b_bbox[1 +
          (((int32_T)c18_i - 1) << 2)] == 0.0))) {
      _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 28);
      c18_touch++;
    }

    _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 30);
    c18_A = c18_b_bbox[3 + (((int32_T)c18_i - 1) << 2)];
    c18_x = c18_A;
    c18_b_x = c18_x;
    c18_c_x = c18_b_x;
    c18_d_x = c18_c_x;
    c18_e_x = c18_d_x;
    c18_xk = (real_T)c18_e_x;
    c18_d0 = muDoubleScalarRound(c18_xk / 2.0);
    if (c18_d0 < 2.147483648E+9) {
      if (CV_SATURATION_EVAL(4, 0, 13, 1, c18_d0 >= -2.147483648E+9)) {
        c18_i46 = (int32_T)c18_d0;
      } else {
        c18_i46 = MIN_int32_T;
      }
    } else if (CV_SATURATION_EVAL(4, 0, 13, 0, c18_d0 >= 2.147483648E+9)) {
      c18_i46 = MAX_int32_T;
    } else {
      c18_i46 = 0;
    }

    c18_y = c18_i46;
    c18_d1 = muDoubleScalarRound(c18_b_im_y - (real_T)c18_c_centroid[((int32_T)
      c18_i - 1) << 1]);
    if (c18_d1 < 2.147483648E+9) {
      if (CV_SATURATION_EVAL(4, 0, 11, 1, c18_d1 >= -2.147483648E+9)) {
        c18_i47 = (int32_T)c18_d1;
      } else {
        c18_i47 = MIN_int32_T;
      }
    } else if (CV_SATURATION_EVAL(4, 0, 11, 0, c18_d1 >= 2.147483648E+9)) {
      c18_i47 = MAX_int32_T;
    } else {
      c18_i47 = 0;
    }

    c18_i48 = (int64_T)c18_i47 - (int64_T)c18_y;
    if (c18_i48 > 2147483647LL) {
      CV_SATURATION_EVAL(4, 0, 12, 0, 1);
      c18_i48 = 2147483647LL;
    } else {
      if (CV_SATURATION_EVAL(4, 0, 12, 0, c18_i48 < -2147483648LL)) {
        c18_i48 = -2147483648LL;
      }
    }

    c18_d2 = (real_T)(int32_T)c18_i48;
    if (CV_EML_IF(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 3, c18_d2, 2.0, -1, 2U,
          c18_d2 < 2.0))) {
      _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 31);
      c18_touch++;
    }

    _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 33);
    c18_b_A = c18_b_bbox[2 + (((int32_T)c18_i - 1) << 2)];
    c18_f_x = c18_b_A;
    c18_g_x = c18_f_x;
    c18_h_x = c18_g_x;
    c18_i_x = c18_h_x;
    c18_j_x = c18_i_x;
    c18_b_xk = (real_T)c18_j_x;
    c18_d3 = muDoubleScalarRound(c18_b_xk / 2.0);
    if (c18_d3 < 2.147483648E+9) {
      if (CV_SATURATION_EVAL(4, 0, 16, 1, c18_d3 >= -2.147483648E+9)) {
        c18_i49 = (int32_T)c18_d3;
      } else {
        c18_i49 = MIN_int32_T;
      }
    } else if (CV_SATURATION_EVAL(4, 0, 16, 0, c18_d3 >= 2.147483648E+9)) {
      c18_i49 = MAX_int32_T;
    } else {
      c18_i49 = 0;
    }

    c18_b_y = c18_i49;
    c18_d4 = muDoubleScalarRound(c18_b_im_x - (real_T)c18_c_centroid[1 +
      (((int32_T)c18_i - 1) << 1)]);
    if (c18_d4 < 2.147483648E+9) {
      if (CV_SATURATION_EVAL(4, 0, 14, 1, c18_d4 >= -2.147483648E+9)) {
        c18_i50 = (int32_T)c18_d4;
      } else {
        c18_i50 = MIN_int32_T;
      }
    } else if (CV_SATURATION_EVAL(4, 0, 14, 0, c18_d4 >= 2.147483648E+9)) {
      c18_i50 = MAX_int32_T;
    } else {
      c18_i50 = 0;
    }

    c18_i51 = (int64_T)c18_i50 - (int64_T)c18_b_y;
    if (c18_i51 > 2147483647LL) {
      CV_SATURATION_EVAL(4, 0, 15, 0, 1);
      c18_i51 = 2147483647LL;
    } else {
      if (CV_SATURATION_EVAL(4, 0, 15, 0, c18_i51 < -2147483648LL)) {
        c18_i51 = -2147483648LL;
      }
    }

    c18_d5 = (real_T)(int32_T)c18_i51;
    if (CV_EML_IF(0, 1, 4, CV_RELATIONAL_EVAL(4U, 0U, 4, c18_d5, 2.0, -1, 2U,
          c18_d5 < 2.0))) {
      _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 34);
      c18_touch++;
    }

    _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 37);
    c18_d6 = c18_abs(chartInstance, c18_or_val);
    guard1 = false;
    guard2 = false;
    guard3 = false;
    guard4 = false;
    guard5 = false;
    guard6 = false;
    if (CV_EML_COND(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 5, c18_d6, 55.0, -1, 4U,
          c18_d6 > 55.0))) {
      c18_d7 = c18_abs(chartInstance, c18_or_val);
      if (CV_EML_COND(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 6, c18_d7, 145.0, -1,
            2U, c18_d7 < 145.0))) {
        c18_c_A = c18_b_majoraxis[(int32_T)c18_i - 1];
        c18_B = c18_b_minoraxis[(int32_T)c18_i - 1];
        c18_k_x = c18_c_A;
        c18_c_y = c18_B;
        c18_l_x = c18_k_x;
        c18_d_y = c18_c_y;
        c18_m_x = c18_l_x;
        c18_e_y = c18_d_y;
        c18_f_y = c18_m_x / c18_e_y;
        c18_d8 = c18_f_y;
        if (CV_EML_COND(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 7, c18_d8, 1.5, -1,
              4U, c18_d8 > 1.5))) {
          c18_d_A = c18_b_majoraxis[(int32_T)c18_i - 1];
          c18_b_B = c18_b_minoraxis[(int32_T)c18_i - 1];
          c18_n_x = c18_d_A;
          c18_g_y = c18_b_B;
          c18_o_x = c18_n_x;
          c18_h_y = c18_g_y;
          c18_p_x = c18_o_x;
          c18_i_y = c18_h_y;
          c18_j_y = c18_p_x / c18_i_y;
          c18_d9 = c18_j_y;
          if (CV_EML_COND(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 8, c18_d9, 3.0, -1,
                2U, c18_d9 < 3.0))) {
            if (CV_EML_COND(0, 1, 4, CV_RELATIONAL_EVAL(4U, 0U, 9, (real_T)
                  c18_b_eccentricity[(int32_T)c18_i - 1], 0.0, -1, 4U,
                  c18_b_eccentricity[(int32_T)c18_i - 1] > 0.0F))) {
              if (CV_EML_COND(0, 1, 5, CV_RELATIONAL_EVAL(4U, 0U, 10, (real_T)
                    c18_b_eccentricity[(int32_T)c18_i - 1], 1.0, -1, 2U,
                    c18_b_eccentricity[(int32_T)c18_i - 1] < 1.0F))) {
                if (CV_EML_COND(0, 1, 6, CV_RELATIONAL_EVAL(4U, 0U, 11,
                      c18_touch, 2.0, -1, 2U, c18_touch < 2.0))) {
                  CV_EML_MCDC(0, 1, 0, true);
                  CV_EML_IF(0, 1, 5, true);
                  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 38);
                  c18_b_a = _SFD_EML_ARRAY_BOUNDS_CHECK("bboxout", (int32_T)
                    c18_a, 1, 100, 2, 0) - 1;
                  c18_f_i = (int32_T)c18_i - 1;
                  c18_d10 = muDoubleScalarRound(c18_b_liminf_y);
                  if (c18_d10 < 2.147483648E+9) {
                    if (CV_SATURATION_EVAL(4, 0, 1, 1, c18_d10 >=
                                           -2.147483648E+9)) {
                      c18_i52 = (int32_T)c18_d10;
                    } else {
                      c18_i52 = MIN_int32_T;
                    }
                  } else if (CV_SATURATION_EVAL(4, 0, 1, 0, c18_d10 >=
                              2.147483648E+9)) {
                    c18_i52 = MAX_int32_T;
                  } else {
                    c18_i52 = 0;
                  }

                  c18_d_liminf_y[0] = c18_i52;
                  c18_d11 = muDoubleScalarRound(c18_b_liminf_x);
                  if (c18_d11 < 2.147483648E+9) {
                    if (CV_SATURATION_EVAL(4, 0, 1, 1, c18_d11 >=
                                           -2.147483648E+9)) {
                      c18_i53 = (int32_T)c18_d11;
                    } else {
                      c18_i53 = MIN_int32_T;
                    }
                  } else if (CV_SATURATION_EVAL(4, 0, 1, 0, c18_d11 >=
                              2.147483648E+9)) {
                    c18_i53 = MAX_int32_T;
                  } else {
                    c18_i53 = 0;
                  }

                  c18_d_liminf_y[1] = c18_i53;
                  for (c18_i54 = 0; c18_i54 < 2; c18_i54++) {
                    c18_i55 = (int64_T)c18_b_bbox[c18_i54 + (c18_f_i << 2)] +
                      (int64_T)c18_d_liminf_y[c18_i54];
                    if (c18_i55 > 2147483647LL) {
                      CV_SATURATION_EVAL(4, 0, 0, 0, 1);
                      c18_i55 = 2147483647LL;
                    } else {
                      if (CV_SATURATION_EVAL(4, 0, 0, 0, c18_i55 < -2147483648LL))
                      {
                        c18_i55 = -2147483648LL;
                      }
                    }

                    c18_b_bboxout[c18_i54 + (c18_b_a << 2)] = (int32_T)c18_i55;
                  }

                  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 39);
                  c18_c_a = (int32_T)c18_a - 1;
                  c18_g_i = (int32_T)c18_i - 1;
                  for (c18_i56 = 0; c18_i56 < 2; c18_i56++) {
                    c18_b_bboxout[(c18_i56 + (c18_c_a << 2)) + 2] = c18_b_bbox
                      [(c18_i56 + (c18_g_i << 2)) + 2];
                  }

                  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 40);
                  c18_d_a = (int32_T)c18_a - 1;
                  c18_h_i = (int32_T)c18_i - 1;
                  c18_d12 = muDoubleScalarRound(c18_b_liminf_y);
                  if (c18_d12 < 2.147483648E+9) {
                    if (CV_SATURATION_EVAL(4, 0, 3, 1, c18_d12 >=
                                           -2.147483648E+9)) {
                      c18_i57 = (int32_T)c18_d12;
                    } else {
                      c18_i57 = MIN_int32_T;
                    }
                  } else if (CV_SATURATION_EVAL(4, 0, 3, 0, c18_d12 >=
                              2.147483648E+9)) {
                    c18_i57 = MAX_int32_T;
                  } else {
                    c18_i57 = 0;
                  }

                  c18_e_liminf_y[0] = c18_i57;
                  c18_d13 = muDoubleScalarRound(c18_b_liminf_x);
                  if (c18_d13 < 2.147483648E+9) {
                    if (CV_SATURATION_EVAL(4, 0, 3, 1, c18_d13 >=
                                           -2.147483648E+9)) {
                      c18_i58 = (int32_T)c18_d13;
                    } else {
                      c18_i58 = MIN_int32_T;
                    }
                  } else if (CV_SATURATION_EVAL(4, 0, 3, 0, c18_d13 >=
                              2.147483648E+9)) {
                    c18_i58 = MAX_int32_T;
                  } else {
                    c18_i58 = 0;
                  }

                  c18_e_liminf_y[1] = c18_i58;
                  for (c18_i59 = 0; c18_i59 < 2; c18_i59++) {
                    c18_i60 = (int64_T)c18_c_centroid[c18_i59 + (c18_h_i << 1)]
                      + (int64_T)c18_e_liminf_y[c18_i59];
                    if (c18_i60 > 2147483647LL) {
                      CV_SATURATION_EVAL(4, 0, 2, 0, 1);
                      c18_i60 = 2147483647LL;
                    } else {
                      if (CV_SATURATION_EVAL(4, 0, 2, 0, c18_i60 < -2147483648LL))
                      {
                        c18_i60 = -2147483648LL;
                      }
                    }

                    c18_b_centout[c18_i59 + (c18_d_a << 1)] = (int32_T)c18_i60;
                  }

                  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 41);
                  c18_b0 = (c18_lr > c18_lh);
                  c18_b1 = c18_b0;
                  c18_b2 = c18_b1;
                  if (c18_b2) {
                    c18_i61 = 1;
                    c18_i62 = 0;
                  } else {
                    c18_i61 = _SFD_EML_ARRAY_BOUNDS_CHECK("label_out", c18_lr, 1,
                      c18_b_label_out_sizes[0], 0, 0);
                    c18_i62 = _SFD_EML_ARRAY_BOUNDS_CHECK("label_out", c18_lh, 1,
                      c18_b_label_out_sizes[0], 0, 0);
                  }

                  c18_b3 = (c18_lc > c18_lw);
                  c18_b4 = c18_b3;
                  c18_b5 = c18_b4;
                  if (c18_b5) {
                    c18_i63 = 1;
                    c18_i64 = 0;
                  } else {
                    c18_i63 = _SFD_EML_ARRAY_BOUNDS_CHECK("label_out", c18_lc, 1,
                      c18_b_label_out_sizes[1], 0, 0);
                    c18_i64 = _SFD_EML_ARRAY_BOUNDS_CHECK("label_out", c18_lw, 1,
                      c18_b_label_out_sizes[1], 0, 0);
                  }

                  c18_b_tmp_sizes = (c18_i62 - c18_i61) + 1;
                  c18_d_loop_ub = c18_i62 - c18_i61;
                  for (c18_i65 = 0; c18_i65 <= c18_d_loop_ub; c18_i65++) {
                    c18_d_tmp_data[c18_i65] = c18_i61 + c18_i65;
                  }

                  c18_c_tmp_sizes = (c18_i64 - c18_i63) + 1;
                  c18_e_loop_ub = c18_i64 - c18_i63;
                  for (c18_i66 = 0; c18_i66 <= c18_e_loop_ub; c18_i66++) {
                    c18_e_tmp_data[c18_i66] = c18_i63 + c18_i66;
                  }

                  c18_iv2[0] = c18_b_tmp_sizes;
                  c18_iv2[1] = c18_c_tmp_sizes;
                  c18_f_loop_ub = c18_iv2[1] - 1;
                  for (c18_i67 = 0; c18_i67 <= c18_f_loop_ub; c18_i67++) {
                    c18_g_loop_ub = c18_iv2[0] - 1;
                    for (c18_i68 = 0; c18_i68 <= c18_g_loop_ub; c18_i68++) {
                      chartInstance->c18_label_out_data[(c18_d_tmp_data[c18_i68]
                        + c18_b_label_out_sizes[0] * (c18_e_tmp_data[c18_i67] -
                        1)) - 1] = c18_a;
                    }
                  }

                  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 42);
                  c18_a++;
                } else {
                  guard1 = true;
                }
              } else {
                guard2 = true;
              }
            } else {
              guard3 = true;
            }
          } else {
            guard4 = true;
          }
        } else {
          guard5 = true;
        }
      } else {
        guard6 = true;
      }
    } else {
      guard6 = true;
    }

    if (guard6 == true) {
      guard5 = true;
    }

    if (guard5 == true) {
      guard4 = true;
    }

    if (guard4 == true) {
      guard3 = true;
    }

    if (guard3 == true) {
      guard2 = true;
    }

    if (guard2 == true) {
      guard1 = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(0, 1, 0, false);
      CV_EML_IF(0, 1, 5, false);
      _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 44);
      c18_b6 = (c18_lr > c18_lh);
      c18_b7 = c18_b6;
      c18_b8 = c18_b7;
      if (c18_b8) {
        c18_i69 = 1;
        c18_i70 = 0;
      } else {
        c18_i69 = _SFD_EML_ARRAY_BOUNDS_CHECK("label_out", c18_lr, 1,
          c18_b_label_out_sizes[0], 0, 0);
        c18_i70 = _SFD_EML_ARRAY_BOUNDS_CHECK("label_out", c18_lh, 1,
          c18_b_label_out_sizes[0], 0, 0);
      }

      c18_b9 = (c18_lc > c18_lw);
      c18_b10 = c18_b9;
      c18_b11 = c18_b10;
      if (c18_b11) {
        c18_i71 = 1;
        c18_i72 = 0;
      } else {
        c18_i71 = _SFD_EML_ARRAY_BOUNDS_CHECK("label_out", c18_lc, 1,
          c18_b_label_out_sizes[1], 0, 0);
        c18_i72 = _SFD_EML_ARRAY_BOUNDS_CHECK("label_out", c18_lw, 1,
          c18_b_label_out_sizes[1], 0, 0);
      }

      c18_b_tmp_sizes = (c18_i70 - c18_i69) + 1;
      c18_h_loop_ub = c18_i70 - c18_i69;
      for (c18_i73 = 0; c18_i73 <= c18_h_loop_ub; c18_i73++) {
        c18_d_tmp_data[c18_i73] = c18_i69 + c18_i73;
      }

      c18_c_tmp_sizes = (c18_i72 - c18_i71) + 1;
      c18_i_loop_ub = c18_i72 - c18_i71;
      for (c18_i74 = 0; c18_i74 <= c18_i_loop_ub; c18_i74++) {
        c18_e_tmp_data[c18_i74] = c18_i71 + c18_i74;
      }

      c18_iv3[0] = c18_b_tmp_sizes;
      c18_iv3[1] = c18_c_tmp_sizes;
      c18_j_loop_ub = c18_iv3[1] - 1;
      for (c18_i75 = 0; c18_i75 <= c18_j_loop_ub; c18_i75++) {
        c18_k_loop_ub = c18_iv3[0] - 1;
        for (c18_i76 = 0; c18_i76 <= c18_k_loop_ub; c18_i76++) {
          chartInstance->c18_label_out_data[(c18_d_tmp_data[c18_i76] +
            c18_b_label_out_sizes[0] * (c18_e_tmp_data[c18_i75] - 1)) - 1] = 0.0;
        }
      }
    }

    c18_e_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 1, 0);
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, -44);
  _SFD_SYMBOL_SCOPE_POP();
  for (c18_i77 = 0; c18_i77 < 200; c18_i77++) {
    (*chartInstance->c18_centout)[c18_i77] = c18_b_centout[c18_i77];
  }

  for (c18_i78 = 0; c18_i78 < 400; c18_i78++) {
    (*chartInstance->c18_bboxout)[c18_i78] = c18_b_bboxout[c18_i78];
  }

  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 3, 0,
    c18_b_label_out_sizes[0]);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 3, 1,
    c18_b_label_out_sizes[1]);
  c18_i79 = (*chartInstance->c18_label_out_sizes)[0];
  c18_i80 = (*chartInstance->c18_label_out_sizes)[1];
  c18_l_loop_ub = c18_b_label_out_sizes[0] * c18_b_label_out_sizes[1] - 1;
  for (c18_i81 = 0; c18_i81 <= c18_l_loop_ub; c18_i81++) {
    (*chartInstance->c18_b_label_out_data)[c18_i81] =
      chartInstance->c18_label_out_data[c18_i81];
  }

  for (c18_i82 = 0; c18_i82 < 64; c18_i82++) {
    (*chartInstance->c18_posObj_im)[c18_i82] = c18_b_posObj_im[c18_i82];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c18_sfEvent);
}

static void initSimStructsc18_Experiment_3_cs
  (SFc18_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c18_machineNumber, uint32_T
  c18_chartNumber, uint32_T c18_instanceNumber)
{
  (void)c18_machineNumber;
  (void)c18_chartNumber;
  (void)c18_instanceNumber;
}

static const mxArray *c18_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_i83;
  int32_T c18_i84;
  int32_T c18_i85;
  real_T c18_b_inData[64];
  int32_T c18_i86;
  int32_T c18_i87;
  int32_T c18_i88;
  real_T c18_u[64];
  const mxArray *c18_y = NULL;
  SFc18_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc18_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_i83 = 0;
  for (c18_i84 = 0; c18_i84 < 32; c18_i84++) {
    for (c18_i85 = 0; c18_i85 < 2; c18_i85++) {
      c18_b_inData[c18_i85 + c18_i83] = (*(real_T (*)[64])c18_inData)[c18_i85 +
        c18_i83];
    }

    c18_i83 += 2;
  }

  c18_i86 = 0;
  for (c18_i87 = 0; c18_i87 < 32; c18_i87++) {
    for (c18_i88 = 0; c18_i88 < 2; c18_i88++) {
      c18_u[c18_i88 + c18_i86] = c18_b_inData[c18_i88 + c18_i86];
    }

    c18_i86 += 2;
  }

  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", c18_u, 0, 0U, 1U, 0U, 2, 2, 32),
                false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static void c18_emlrt_marshallIn(SFc18_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c18_b_posObj_im, const char_T *c18_identifier,
  real_T c18_y[64])
{
  emlrtMsgIdentifier c18_thisId;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_b_posObj_im), &c18_thisId,
    c18_y);
  sf_mex_destroy(&c18_b_posObj_im);
}

static void c18_b_emlrt_marshallIn(SFc18_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId,
  real_T c18_y[64])
{
  real_T c18_dv1[64];
  int32_T c18_i89;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), c18_dv1, 1, 0, 0U, 1, 0U, 2, 2,
                32);
  for (c18_i89 = 0; c18_i89 < 64; c18_i89++) {
    c18_y[c18_i89] = c18_dv1[c18_i89];
  }

  sf_mex_destroy(&c18_u);
}

static void c18_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_b_posObj_im;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  real_T c18_y[64];
  int32_T c18_i90;
  int32_T c18_i91;
  int32_T c18_i92;
  SFc18_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc18_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c18_b_posObj_im = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_b_posObj_im), &c18_thisId,
    c18_y);
  sf_mex_destroy(&c18_b_posObj_im);
  c18_i90 = 0;
  for (c18_i91 = 0; c18_i91 < 32; c18_i91++) {
    for (c18_i92 = 0; c18_i92 < 2; c18_i92++) {
      (*(real_T (*)[64])c18_outData)[c18_i92 + c18_i90] = c18_y[c18_i92 +
        c18_i90];
    }

    c18_i90 += 2;
  }

  sf_mex_destroy(&c18_mxArrayInData);
}

static const mxArray *c18_b_sf_marshallOut(void *chartInstanceVoid, real_T
  c18_c_inData_data[], int32_T c18_inData_sizes[2])
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_u_sizes[2];
  int32_T c18_u;
  int32_T c18_b_u;
  int32_T c18_inData;
  int32_T c18_b_inData;
  int32_T c18_b_inData_sizes;
  int32_T c18_loop_ub;
  int32_T c18_i93;
  int32_T c18_b_loop_ub;
  int32_T c18_i94;
  const mxArray *c18_y = NULL;
  SFc18_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc18_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u_sizes[0] = c18_inData_sizes[0];
  c18_u_sizes[1] = c18_inData_sizes[1];
  c18_u = c18_u_sizes[0];
  c18_b_u = c18_u_sizes[1];
  c18_inData = c18_inData_sizes[0];
  c18_b_inData = c18_inData_sizes[1];
  c18_b_inData_sizes = c18_inData * c18_b_inData;
  c18_loop_ub = c18_inData * c18_b_inData - 1;
  for (c18_i93 = 0; c18_i93 <= c18_loop_ub; c18_i93++) {
    chartInstance->c18_inData_data[c18_i93] = c18_c_inData_data[c18_i93];
  }

  c18_b_loop_ub = c18_b_inData_sizes - 1;
  for (c18_i94 = 0; c18_i94 <= c18_b_loop_ub; c18_i94++) {
    chartInstance->c18_u_data[c18_i94] = chartInstance->c18_inData_data[c18_i94];
  }

  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", chartInstance->c18_u_data, 0, 0U, 1U,
    0U, 2, c18_u_sizes[0], c18_u_sizes[1]), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static void c18_c_emlrt_marshallIn(SFc18_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c18_label_out, const char_T *c18_identifier,
  real_T c18_b_y_data[], int32_T c18_y_sizes[2])
{
  emlrtMsgIdentifier c18_thisId;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_label_out), &c18_thisId,
    c18_b_y_data, c18_y_sizes);
  sf_mex_destroy(&c18_label_out);
}

static void c18_d_emlrt_marshallIn(SFc18_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId,
  real_T c18_b_y_data[], int32_T c18_y_sizes[2])
{
  int32_T c18_i95;
  uint32_T c18_uv0[2];
  int32_T c18_i96;
  boolean_T c18_bv0[2];
  int32_T c18_tmp_sizes[2];
  int32_T c18_y;
  int32_T c18_b_y;
  int32_T c18_loop_ub;
  int32_T c18_i97;
  for (c18_i95 = 0; c18_i95 < 2; c18_i95++) {
    c18_uv0[c18_i95] = 400U + 150U * (uint32_T)c18_i95;
  }

  for (c18_i96 = 0; c18_i96 < 2; c18_i96++) {
    c18_bv0[c18_i96] = true;
  }

  sf_mex_import_vs(c18_parentId, sf_mex_dup(c18_u),
                   chartInstance->c18_b_tmp_data, 1, 0, 0U, 1, 0U, 2, c18_bv0,
                   c18_uv0, c18_tmp_sizes);
  c18_y_sizes[0] = c18_tmp_sizes[0];
  c18_y_sizes[1] = c18_tmp_sizes[1];
  c18_y = c18_y_sizes[0];
  c18_b_y = c18_y_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_i97 = 0; c18_i97 <= c18_loop_ub; c18_i97++) {
    c18_b_y_data[c18_i97] = chartInstance->c18_b_tmp_data[c18_i97];
  }

  sf_mex_destroy(&c18_u);
}

static void c18_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, real_T c18_outData_data[],
  int32_T c18_outData_sizes[2])
{
  const mxArray *c18_label_out;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  int32_T c18_y_sizes[2];
  int32_T c18_loop_ub;
  int32_T c18_i98;
  int32_T c18_b_loop_ub;
  int32_T c18_i99;
  SFc18_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc18_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c18_label_out = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_label_out), &c18_thisId,
    chartInstance->c18_y_data, c18_y_sizes);
  sf_mex_destroy(&c18_label_out);
  c18_outData_sizes[0] = c18_y_sizes[0];
  c18_outData_sizes[1] = c18_y_sizes[1];
  c18_loop_ub = c18_y_sizes[1] - 1;
  for (c18_i98 = 0; c18_i98 <= c18_loop_ub; c18_i98++) {
    c18_b_loop_ub = c18_y_sizes[0] - 1;
    for (c18_i99 = 0; c18_i99 <= c18_b_loop_ub; c18_i99++) {
      c18_outData_data[c18_i99 + c18_outData_sizes[0] * c18_i98] =
        chartInstance->c18_y_data[c18_i99 + c18_y_sizes[0] * c18_i98];
    }
  }

  sf_mex_destroy(&c18_mxArrayInData);
}

static const mxArray *c18_c_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_i100;
  int32_T c18_i101;
  int32_T c18_i102;
  int32_T c18_b_inData[400];
  int32_T c18_i103;
  int32_T c18_i104;
  int32_T c18_i105;
  int32_T c18_u[400];
  const mxArray *c18_y = NULL;
  SFc18_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc18_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_i100 = 0;
  for (c18_i101 = 0; c18_i101 < 100; c18_i101++) {
    for (c18_i102 = 0; c18_i102 < 4; c18_i102++) {
      c18_b_inData[c18_i102 + c18_i100] = (*(int32_T (*)[400])c18_inData)
        [c18_i102 + c18_i100];
    }

    c18_i100 += 4;
  }

  c18_i103 = 0;
  for (c18_i104 = 0; c18_i104 < 100; c18_i104++) {
    for (c18_i105 = 0; c18_i105 < 4; c18_i105++) {
      c18_u[c18_i105 + c18_i103] = c18_b_inData[c18_i105 + c18_i103];
    }

    c18_i103 += 4;
  }

  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", c18_u, 6, 0U, 1U, 0U, 2, 4, 100),
                false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static void c18_e_emlrt_marshallIn(SFc18_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c18_b_bboxout, const char_T *c18_identifier,
  int32_T c18_y[400])
{
  emlrtMsgIdentifier c18_thisId;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_b_bboxout), &c18_thisId,
    c18_y);
  sf_mex_destroy(&c18_b_bboxout);
}

static void c18_f_emlrt_marshallIn(SFc18_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId,
  int32_T c18_y[400])
{
  int32_T c18_iv4[400];
  int32_T c18_i106;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), c18_iv4, 1, 6, 0U, 1, 0U, 2, 4,
                100);
  for (c18_i106 = 0; c18_i106 < 400; c18_i106++) {
    c18_y[c18_i106] = c18_iv4[c18_i106];
  }

  sf_mex_destroy(&c18_u);
}

static void c18_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_b_bboxout;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  int32_T c18_y[400];
  int32_T c18_i107;
  int32_T c18_i108;
  int32_T c18_i109;
  SFc18_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc18_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c18_b_bboxout = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_b_bboxout), &c18_thisId,
    c18_y);
  sf_mex_destroy(&c18_b_bboxout);
  c18_i107 = 0;
  for (c18_i108 = 0; c18_i108 < 100; c18_i108++) {
    for (c18_i109 = 0; c18_i109 < 4; c18_i109++) {
      (*(int32_T (*)[400])c18_outData)[c18_i109 + c18_i107] = c18_y[c18_i109 +
        c18_i107];
    }

    c18_i107 += 4;
  }

  sf_mex_destroy(&c18_mxArrayInData);
}

static const mxArray *c18_d_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_i110;
  int32_T c18_i111;
  int32_T c18_i112;
  int32_T c18_b_inData[200];
  int32_T c18_i113;
  int32_T c18_i114;
  int32_T c18_i115;
  int32_T c18_u[200];
  const mxArray *c18_y = NULL;
  SFc18_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc18_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_i110 = 0;
  for (c18_i111 = 0; c18_i111 < 100; c18_i111++) {
    for (c18_i112 = 0; c18_i112 < 2; c18_i112++) {
      c18_b_inData[c18_i112 + c18_i110] = (*(int32_T (*)[200])c18_inData)
        [c18_i112 + c18_i110];
    }

    c18_i110 += 2;
  }

  c18_i113 = 0;
  for (c18_i114 = 0; c18_i114 < 100; c18_i114++) {
    for (c18_i115 = 0; c18_i115 < 2; c18_i115++) {
      c18_u[c18_i115 + c18_i113] = c18_b_inData[c18_i115 + c18_i113];
    }

    c18_i113 += 2;
  }

  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", c18_u, 6, 0U, 1U, 0U, 2, 2, 100),
                false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static void c18_g_emlrt_marshallIn(SFc18_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c18_b_centout, const char_T *c18_identifier,
  int32_T c18_y[200])
{
  emlrtMsgIdentifier c18_thisId;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_b_centout), &c18_thisId,
    c18_y);
  sf_mex_destroy(&c18_b_centout);
}

static void c18_h_emlrt_marshallIn(SFc18_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId,
  int32_T c18_y[200])
{
  int32_T c18_iv5[200];
  int32_T c18_i116;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), c18_iv5, 1, 6, 0U, 1, 0U, 2, 2,
                100);
  for (c18_i116 = 0; c18_i116 < 200; c18_i116++) {
    c18_y[c18_i116] = c18_iv5[c18_i116];
  }

  sf_mex_destroy(&c18_u);
}

static void c18_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_b_centout;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  int32_T c18_y[200];
  int32_T c18_i117;
  int32_T c18_i118;
  int32_T c18_i119;
  SFc18_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc18_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c18_b_centout = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_b_centout), &c18_thisId,
    c18_y);
  sf_mex_destroy(&c18_b_centout);
  c18_i117 = 0;
  for (c18_i118 = 0; c18_i118 < 100; c18_i118++) {
    for (c18_i119 = 0; c18_i119 < 2; c18_i119++) {
      (*(int32_T (*)[200])c18_outData)[c18_i119 + c18_i117] = c18_y[c18_i119 +
        c18_i117];
    }

    c18_i117 += 2;
  }

  sf_mex_destroy(&c18_mxArrayInData);
}

static const mxArray *c18_e_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  real_T c18_u;
  const mxArray *c18_y = NULL;
  SFc18_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc18_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u = *(real_T *)c18_inData;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static const mxArray *c18_f_sf_marshallOut(void *chartInstanceVoid, uint8_T
  c18_c_inData_data[], int32_T c18_inData_sizes[2])
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_u_sizes[2];
  int32_T c18_u;
  int32_T c18_b_u;
  int32_T c18_inData;
  int32_T c18_b_inData;
  int32_T c18_b_inData_sizes;
  int32_T c18_loop_ub;
  int32_T c18_i120;
  int32_T c18_b_loop_ub;
  int32_T c18_i121;
  uint8_T c18_c_u_data[187500];
  const mxArray *c18_y = NULL;
  SFc18_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc18_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u_sizes[0] = c18_inData_sizes[0];
  c18_u_sizes[1] = c18_inData_sizes[1];
  c18_u = c18_u_sizes[0];
  c18_b_u = c18_u_sizes[1];
  c18_inData = c18_inData_sizes[0];
  c18_b_inData = c18_inData_sizes[1];
  c18_b_inData_sizes = c18_inData * c18_b_inData;
  c18_loop_ub = c18_inData * c18_b_inData - 1;
  for (c18_i120 = 0; c18_i120 <= c18_loop_ub; c18_i120++) {
    chartInstance->c18_b_inData_data[c18_i120] = c18_c_inData_data[c18_i120];
  }

  c18_b_loop_ub = c18_b_inData_sizes - 1;
  for (c18_i121 = 0; c18_i121 <= c18_b_loop_ub; c18_i121++) {
    c18_c_u_data[c18_i121] = chartInstance->c18_b_inData_data[c18_i121];
  }

  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", c18_c_u_data, 3, 0U, 1U, 0U, 2,
    c18_u_sizes[0], c18_u_sizes[1]), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static const mxArray *c18_g_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_i122;
  real32_T c18_b_inData[100];
  int32_T c18_i123;
  real32_T c18_u[100];
  const mxArray *c18_y = NULL;
  SFc18_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc18_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  for (c18_i122 = 0; c18_i122 < 100; c18_i122++) {
    c18_b_inData[c18_i122] = (*(real32_T (*)[100])c18_inData)[c18_i122];
  }

  for (c18_i123 = 0; c18_i123 < 100; c18_i123++) {
    c18_u[c18_i123] = c18_b_inData[c18_i123];
  }

  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", c18_u, 1, 0U, 1U, 0U, 2, 1, 100),
                false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static const mxArray *c18_h_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_i124;
  real_T c18_b_inData[100];
  int32_T c18_i125;
  real_T c18_u[100];
  const mxArray *c18_y = NULL;
  SFc18_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc18_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  for (c18_i124 = 0; c18_i124 < 100; c18_i124++) {
    c18_b_inData[c18_i124] = (*(real_T (*)[100])c18_inData)[c18_i124];
  }

  for (c18_i125 = 0; c18_i125 < 100; c18_i125++) {
    c18_u[c18_i125] = c18_b_inData[c18_i125];
  }

  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", c18_u, 0, 0U, 1U, 0U, 2, 1, 100),
                false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static const mxArray *c18_i_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_i126;
  int32_T c18_i127;
  int32_T c18_i128;
  real32_T c18_b_inData[200];
  int32_T c18_i129;
  int32_T c18_i130;
  int32_T c18_i131;
  real32_T c18_u[200];
  const mxArray *c18_y = NULL;
  SFc18_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc18_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_i126 = 0;
  for (c18_i127 = 0; c18_i127 < 100; c18_i127++) {
    for (c18_i128 = 0; c18_i128 < 2; c18_i128++) {
      c18_b_inData[c18_i128 + c18_i126] = (*(real32_T (*)[200])c18_inData)
        [c18_i128 + c18_i126];
    }

    c18_i126 += 2;
  }

  c18_i129 = 0;
  for (c18_i130 = 0; c18_i130 < 100; c18_i130++) {
    for (c18_i131 = 0; c18_i131 < 2; c18_i131++) {
      c18_u[c18_i131 + c18_i129] = c18_b_inData[c18_i131 + c18_i129];
    }

    c18_i129 += 2;
  }

  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", c18_u, 1, 0U, 1U, 0U, 2, 2, 100),
                false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static real_T c18_i_emlrt_marshallIn(SFc18_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  real_T c18_y;
  real_T c18_d14;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_d14, 1, 0, 0U, 0, 0U, 0);
  c18_y = c18_d14;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void c18_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_nargout;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  real_T c18_y;
  SFc18_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc18_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c18_nargout = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_nargout),
    &c18_thisId);
  sf_mex_destroy(&c18_nargout);
  *(real_T *)c18_outData = c18_y;
  sf_mex_destroy(&c18_mxArrayInData);
}

static const mxArray *c18_j_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_u;
  const mxArray *c18_y = NULL;
  SFc18_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc18_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u = *(int32_T *)c18_inData;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static int32_T c18_j_emlrt_marshallIn(SFc18_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  int32_T c18_y;
  int32_T c18_i132;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_i132, 1, 6, 0U, 0, 0U, 0);
  c18_y = c18_i132;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void c18_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_lw;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  int32_T c18_y;
  SFc18_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc18_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c18_lw = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_lw), &c18_thisId);
  sf_mex_destroy(&c18_lw);
  *(int32_T *)c18_outData = c18_y;
  sf_mex_destroy(&c18_mxArrayInData);
}

const mxArray *sf_c18_Experiment_3_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c18_nameCaptureInfo = NULL;
  c18_nameCaptureInfo = NULL;
  sf_mex_assign(&c18_nameCaptureInfo, sf_mex_createstruct("structure", 2, 21, 1),
                false);
  c18_info_helper(&c18_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c18_nameCaptureInfo);
  return c18_nameCaptureInfo;
}

static void c18_info_helper(const mxArray **c18_info)
{
  const mxArray *c18_rhs0 = NULL;
  const mxArray *c18_lhs0 = NULL;
  const mxArray *c18_rhs1 = NULL;
  const mxArray *c18_lhs1 = NULL;
  const mxArray *c18_rhs2 = NULL;
  const mxArray *c18_lhs2 = NULL;
  const mxArray *c18_rhs3 = NULL;
  const mxArray *c18_lhs3 = NULL;
  const mxArray *c18_rhs4 = NULL;
  const mxArray *c18_lhs4 = NULL;
  const mxArray *c18_rhs5 = NULL;
  const mxArray *c18_lhs5 = NULL;
  const mxArray *c18_rhs6 = NULL;
  const mxArray *c18_lhs6 = NULL;
  const mxArray *c18_rhs7 = NULL;
  const mxArray *c18_lhs7 = NULL;
  const mxArray *c18_rhs8 = NULL;
  const mxArray *c18_lhs8 = NULL;
  const mxArray *c18_rhs9 = NULL;
  const mxArray *c18_lhs9 = NULL;
  const mxArray *c18_rhs10 = NULL;
  const mxArray *c18_lhs10 = NULL;
  const mxArray *c18_rhs11 = NULL;
  const mxArray *c18_lhs11 = NULL;
  const mxArray *c18_rhs12 = NULL;
  const mxArray *c18_lhs12 = NULL;
  const mxArray *c18_rhs13 = NULL;
  const mxArray *c18_lhs13 = NULL;
  const mxArray *c18_rhs14 = NULL;
  const mxArray *c18_lhs14 = NULL;
  const mxArray *c18_rhs15 = NULL;
  const mxArray *c18_lhs15 = NULL;
  const mxArray *c18_rhs16 = NULL;
  const mxArray *c18_lhs16 = NULL;
  const mxArray *c18_rhs17 = NULL;
  const mxArray *c18_lhs17 = NULL;
  const mxArray *c18_rhs18 = NULL;
  const mxArray *c18_lhs18 = NULL;
  const mxArray *c18_rhs19 = NULL;
  const mxArray *c18_lhs19 = NULL;
  const mxArray *c18_rhs20 = NULL;
  const mxArray *c18_lhs20 = NULL;
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c18_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c18_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c18_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c18_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c18_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 5);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c18_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_div"), "name", "name", 6);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c18_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 7);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c18_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p!eml_mixed_integer_rdivide"),
                  "context", "context", 8);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "coder.internal.is64BitInteger"), "name", "name", 8);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/is64BitInteger.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1368205894U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c18_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p!eml_mixed_integer_rdivide"),
                  "context", "context", 9);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "coder.internal.is64BitInteger"), "name", "name", 9);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/is64BitInteger.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1368205894U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c18_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p!eml_mixed_integer_rdivide"),
                  "context", "context", 10);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 10);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c18_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p!eml_mixed_integer_rdivide"),
                  "context", "context", 11);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 11);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c18_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(""), "context", "context", 12);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("abs"), "name", "name", 12);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c18_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 13);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c18_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 14);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c18_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(""), "context", "context", 15);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("mrdivide"), "name", "name",
                  15);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c18_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 16);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("rdivide"), "name", "name",
                  16);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c18_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 17);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c18_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 18);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c18_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_div"), "name", "name",
                  19);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c18_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 20);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c18_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs20), "lhs", "lhs",
                  20);
  sf_mex_destroy(&c18_rhs0);
  sf_mex_destroy(&c18_lhs0);
  sf_mex_destroy(&c18_rhs1);
  sf_mex_destroy(&c18_lhs1);
  sf_mex_destroy(&c18_rhs2);
  sf_mex_destroy(&c18_lhs2);
  sf_mex_destroy(&c18_rhs3);
  sf_mex_destroy(&c18_lhs3);
  sf_mex_destroy(&c18_rhs4);
  sf_mex_destroy(&c18_lhs4);
  sf_mex_destroy(&c18_rhs5);
  sf_mex_destroy(&c18_lhs5);
  sf_mex_destroy(&c18_rhs6);
  sf_mex_destroy(&c18_lhs6);
  sf_mex_destroy(&c18_rhs7);
  sf_mex_destroy(&c18_lhs7);
  sf_mex_destroy(&c18_rhs8);
  sf_mex_destroy(&c18_lhs8);
  sf_mex_destroy(&c18_rhs9);
  sf_mex_destroy(&c18_lhs9);
  sf_mex_destroy(&c18_rhs10);
  sf_mex_destroy(&c18_lhs10);
  sf_mex_destroy(&c18_rhs11);
  sf_mex_destroy(&c18_lhs11);
  sf_mex_destroy(&c18_rhs12);
  sf_mex_destroy(&c18_lhs12);
  sf_mex_destroy(&c18_rhs13);
  sf_mex_destroy(&c18_lhs13);
  sf_mex_destroy(&c18_rhs14);
  sf_mex_destroy(&c18_lhs14);
  sf_mex_destroy(&c18_rhs15);
  sf_mex_destroy(&c18_lhs15);
  sf_mex_destroy(&c18_rhs16);
  sf_mex_destroy(&c18_lhs16);
  sf_mex_destroy(&c18_rhs17);
  sf_mex_destroy(&c18_lhs17);
  sf_mex_destroy(&c18_rhs18);
  sf_mex_destroy(&c18_lhs18);
  sf_mex_destroy(&c18_rhs19);
  sf_mex_destroy(&c18_lhs19);
  sf_mex_destroy(&c18_rhs20);
  sf_mex_destroy(&c18_lhs20);
}

static const mxArray *c18_emlrt_marshallOut(const char * c18_u)
{
  const mxArray *c18_y = NULL;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", c18_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c18_u)), false);
  return c18_y;
}

static const mxArray *c18_b_emlrt_marshallOut(const uint32_T c18_u)
{
  const mxArray *c18_y = NULL;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 7, 0U, 0U, 0U, 0), false);
  return c18_y;
}

static real_T c18_abs(SFc18_Experiment_3_csInstanceStruct *chartInstance, real_T
                      c18_x)
{
  real_T c18_b_x;
  (void)chartInstance;
  c18_b_x = c18_x;
  return muDoubleScalarAbs(c18_b_x);
}

static uint8_T c18_k_emlrt_marshallIn(SFc18_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c18_b_is_active_c18_Experiment_3_cs, const
  char_T *c18_identifier)
{
  uint8_T c18_y;
  emlrtMsgIdentifier c18_thisId;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c18_b_is_active_c18_Experiment_3_cs), &c18_thisId);
  sf_mex_destroy(&c18_b_is_active_c18_Experiment_3_cs);
  return c18_y;
}

static uint8_T c18_l_emlrt_marshallIn(SFc18_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  uint8_T c18_y;
  uint8_T c18_u0;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_u0, 1, 3, 0U, 0, 0U, 0);
  c18_y = c18_u0;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void init_dsm_address_info(SFc18_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc18_Experiment_3_csInstanceStruct
  *chartInstance)
{
  chartInstance->c18_centroid = (real32_T (*)[200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c18_centout = (int32_T (*)[200])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c18_bbox = (int32_T (*)[400])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c18_bboxout = (int32_T (*)[400])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c18_majoraxis = (real32_T (*)[100])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c18_minoraxis = (real32_T (*)[100])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c18_orientation = (real_T (*)[100])ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c18_eccentricity = (real32_T (*)[100])
    ssGetInputPortSignal_wrapper(chartInstance->S, 5);
  chartInstance->c18_b_label_data = (uint8_T (*)[187500])
    ssGetInputPortSignal_wrapper(chartInstance->S, 6);
  chartInstance->c18_label_sizes = (int32_T (*)[2])
    ssGetCurrentInputPortDimensions_wrapper(chartInstance->S, 6);
  chartInstance->c18_b_label_out_data = (real_T (*)[220000])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 3);
  chartInstance->c18_label_out_sizes = (int32_T (*)[2])
    ssGetCurrentOutputPortDimensions_wrapper(chartInstance->S, 3);
  chartInstance->c18_im_x = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c18_im_y = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c18_posObj_subim = (real_T (*)[64])ssGetInputPortSignal_wrapper
    (chartInstance->S, 9);
  chartInstance->c18_liminf_x = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 10);
  chartInstance->c18_liminf_y = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 11);
  chartInstance->c18_posObj_im = (real_T (*)[64])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
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

void sf_c18_Experiment_3_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1843077773U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1281529357U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1532170690U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3444487266U);
}

mxArray* sf_c18_Experiment_3_cs_get_post_codegen_info(void);
mxArray *sf_c18_Experiment_3_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("NyteGx7U0N4fkRjmOY7JiD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,12,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(100);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
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
      pr[0] = (double)(1);
      pr[1] = (double)(100);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(100);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(100);
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
      pr[1] = (double)(100);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(375);
      pr[1] = (double)(500);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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
      pr[0] = (double)(2);
      pr[1] = (double)(32);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(100);
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
      pr[0] = (double)(4);
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
      pr[0] = (double)(400);
      pr[1] = (double)(550);
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
      pr[0] = (double)(2);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c18_Experiment_3_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c18_Experiment_3_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c18_Experiment_3_cs_jit_fallback_info(void)
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

mxArray *sf_c18_Experiment_3_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c18_Experiment_3_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c18_Experiment_3_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[5],T\"bboxout\",},{M[1],M[21],T\"centout\",},{M[1],M[19],T\"label_out\",},{M[1],M[27],T\"posObj_im\",},{M[8],M[0],T\"is_active_c18_Experiment_3_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c18_Experiment_3_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc18_Experiment_3_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc18_Experiment_3_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_3_csMachineNumber_,
           18,
           1,
           1,
           0,
           16,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"centroid");
          _SFD_SET_DATA_PROPS(1,2,0,1,"centout");
          _SFD_SET_DATA_PROPS(2,1,1,0,"bbox");
          _SFD_SET_DATA_PROPS(3,2,0,1,"bboxout");
          _SFD_SET_DATA_PROPS(4,1,1,0,"majoraxis");
          _SFD_SET_DATA_PROPS(5,1,1,0,"minoraxis");
          _SFD_SET_DATA_PROPS(6,1,1,0,"orientation");
          _SFD_SET_DATA_PROPS(7,1,1,0,"eccentricity");
          _SFD_SET_DATA_PROPS(8,1,1,0,"label");
          _SFD_SET_DATA_PROPS(9,2,0,1,"label_out");
          _SFD_SET_DATA_PROPS(10,1,1,0,"im_x");
          _SFD_SET_DATA_PROPS(11,1,1,0,"im_y");
          _SFD_SET_DATA_PROPS(12,1,1,0,"posObj_subim");
          _SFD_SET_DATA_PROPS(13,1,1,0,"liminf_x");
          _SFD_SET_DATA_PROPS(14,1,1,0,"liminf_y");
          _SFD_SET_DATA_PROPS(15,2,0,1,"posObj_im");
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
        _SFD_CV_INIT_EML(0,1,1,6,0,17,0,2,0,7,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1429);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,1175,-1,1213);
        _SFD_CV_INIT_EML_SATURATION(0,1,1,1187,-1,1213);
        _SFD_CV_INIT_EML_SATURATION(0,1,2,1276,-1,1316);
        _SFD_CV_INIT_EML_SATURATION(0,1,3,1290,-1,1316);
        _SFD_CV_INIT_EML_SATURATION(0,1,4,190,-1,205);
        _SFD_CV_INIT_EML_SATURATION(0,1,5,618,-1,629);
        _SFD_CV_INIT_EML_SATURATION(0,1,6,639,-1,651);
        _SFD_CV_INIT_EML_SATURATION(0,1,7,639,-1,653);
        _SFD_CV_INIT_EML_SATURATION(0,1,8,663,-1,674);
        _SFD_CV_INIT_EML_SATURATION(0,1,9,684,-1,696);
        _SFD_CV_INIT_EML_SATURATION(0,1,10,684,-1,698);
        _SFD_CV_INIT_EML_SATURATION(0,1,11,827,-1,845);
        _SFD_CV_INIT_EML_SATURATION(0,1,12,827,-1,859);
        _SFD_CV_INIT_EML_SATURATION(0,1,13,847,-1,858);
        _SFD_CV_INIT_EML_SATURATION(0,1,14,908,-1,926);
        _SFD_CV_INIT_EML_SATURATION(0,1,15,908,-1,940);
        _SFD_CV_INIT_EML_SATURATION(0,1,16,928,-1,939);
        _SFD_CV_INIT_EML_IF(0,1,0,494,518,562,609);
        _SFD_CV_INIT_EML_IF(0,1,1,706,723,-1,758);
        _SFD_CV_INIT_EML_IF(0,1,2,765,782,-1,817);
        _SFD_CV_INIT_EML_IF(0,1,3,824,862,-1,897);
        _SFD_CV_INIT_EML_IF(0,1,4,904,943,-1,978);
        _SFD_CV_INIT_EML_IF(0,1,5,990,1149,1374,1421);
        _SFD_CV_INIT_EML_FOR(0,1,0,357,386,447);
        _SFD_CV_INIT_EML_FOR(0,1,1,449,477,1425);

        {
          static int condStart[] = { 994, 1012, 1031, 1066, 1099, 1120, 1141 };

          static int condEnd[] = { 1008, 1027, 1062, 1095, 1116, 1137, 1148 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3, 3, -3, 4, -3, 5, -3, 6, -3
          };

          _SFD_CV_INIT_EML_MCDC(0,1,0,993,1149,7,0,&(condStart[0]),&(condEnd[0]),
                                13,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,497,518,-1,5);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,710,722,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,769,781,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,827,861,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,4,908,942,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,5,994,1008,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,6,1012,1027,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,7,1031,1062,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,8,1066,1095,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,9,1099,1116,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,10,1120,1137,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,11,1141,1148,-1,2);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 100;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_SINGLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c18_i_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 100;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c18_d_sf_marshallOut,(MexInFcnForType)
            c18_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 100;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c18_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 100;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c18_c_sf_marshallOut,(MexInFcnForType)
            c18_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 100;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_SINGLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c18_g_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 100;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_SINGLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c18_g_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 100;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c18_h_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 100;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_SINGLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c18_g_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 375;
          dimVector[1]= 500;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c18_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 400;
          dimVector[1]= 550;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c18_b_sf_marshallOut,(MexInFcnForType)
            c18_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c18_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c18_e_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c18_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c18_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c18_e_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c18_sf_marshallOut,(MexInFcnForType)
            c18_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c18_centroid);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c18_centout);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c18_bbox);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c18_bboxout);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c18_majoraxis);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c18_minoraxis);
        _SFD_SET_DATA_VALUE_PTR(6U, *chartInstance->c18_orientation);
        _SFD_SET_DATA_VALUE_PTR(7U, *chartInstance->c18_eccentricity);
        _SFD_SET_DATA_VALUE_PTR_VAR_DIM(8U, *chartInstance->c18_b_label_data,
          (void *)chartInstance->c18_label_sizes);
        _SFD_SET_DATA_VALUE_PTR_VAR_DIM(9U, *chartInstance->c18_b_label_out_data,
                                        (void *)
          chartInstance->c18_label_out_sizes);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c18_im_x);
        _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c18_im_y);
        _SFD_SET_DATA_VALUE_PTR(12U, *chartInstance->c18_posObj_subim);
        _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c18_liminf_x);
        _SFD_SET_DATA_VALUE_PTR(14U, chartInstance->c18_liminf_y);
        _SFD_SET_DATA_VALUE_PTR(15U, *chartInstance->c18_posObj_im);
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
  return "P9BkYmhClo6sjwKJjHaAvE";
}

static void sf_opaque_initialize_c18_Experiment_3_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc18_Experiment_3_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c18_Experiment_3_cs((SFc18_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
  initialize_c18_Experiment_3_cs((SFc18_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c18_Experiment_3_cs(void *chartInstanceVar)
{
  enable_c18_Experiment_3_cs((SFc18_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c18_Experiment_3_cs(void *chartInstanceVar)
{
  disable_c18_Experiment_3_cs((SFc18_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c18_Experiment_3_cs(void *chartInstanceVar)
{
  sf_gateway_c18_Experiment_3_cs((SFc18_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c18_Experiment_3_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c18_Experiment_3_cs((SFc18_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c18_Experiment_3_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c18_Experiment_3_cs((SFc18_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c18_Experiment_3_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc18_Experiment_3_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_3_cs_optimization_info();
    }

    finalize_c18_Experiment_3_cs((SFc18_Experiment_3_csInstanceStruct*)
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
  initSimStructsc18_Experiment_3_cs((SFc18_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c18_Experiment_3_cs(SimStruct *S)
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
    initialize_params_c18_Experiment_3_cs((SFc18_Experiment_3_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c18_Experiment_3_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Experiment_3_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      18);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,18,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,18,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,18);
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,18,12);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,18,4);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=4; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 12; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,18);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2720172993U));
  ssSetChecksum1(S,(133099623U));
  ssSetChecksum2(S,(1219973964U));
  ssSetChecksum3(S,(2287958187U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c18_Experiment_3_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c18_Experiment_3_cs(SimStruct *S)
{
  SFc18_Experiment_3_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc18_Experiment_3_csInstanceStruct *)utMalloc(sizeof
    (SFc18_Experiment_3_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc18_Experiment_3_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c18_Experiment_3_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c18_Experiment_3_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c18_Experiment_3_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c18_Experiment_3_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c18_Experiment_3_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c18_Experiment_3_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c18_Experiment_3_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c18_Experiment_3_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c18_Experiment_3_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c18_Experiment_3_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c18_Experiment_3_cs;
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

void c18_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c18_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c18_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c18_Experiment_3_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c18_Experiment_3_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
