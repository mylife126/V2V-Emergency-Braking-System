/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_1_cs_sfun.h"
#include "c23_Experiment_1_cs.h"
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
static const char * c23_debug_family_names[6] = { "i", "j", "nargin", "nargout",
  "image", "im" };

/* Function Declarations */
static void initialize_c23_Experiment_1_cs(SFc23_Experiment_1_csInstanceStruct
  *chartInstance);
static void initialize_params_c23_Experiment_1_cs
  (SFc23_Experiment_1_csInstanceStruct *chartInstance);
static void enable_c23_Experiment_1_cs(SFc23_Experiment_1_csInstanceStruct
  *chartInstance);
static void disable_c23_Experiment_1_cs(SFc23_Experiment_1_csInstanceStruct
  *chartInstance);
static void c23_update_debugger_state_c23_Experiment_1_cs
  (SFc23_Experiment_1_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c23_Experiment_1_cs
  (SFc23_Experiment_1_csInstanceStruct *chartInstance);
static void set_sim_state_c23_Experiment_1_cs
  (SFc23_Experiment_1_csInstanceStruct *chartInstance, const mxArray *c23_st);
static void finalize_c23_Experiment_1_cs(SFc23_Experiment_1_csInstanceStruct
  *chartInstance);
static void sf_gateway_c23_Experiment_1_cs(SFc23_Experiment_1_csInstanceStruct
  *chartInstance);
static void mdl_start_c23_Experiment_1_cs(SFc23_Experiment_1_csInstanceStruct
  *chartInstance);
static void c23_chartstep_c23_Experiment_1_cs
  (SFc23_Experiment_1_csInstanceStruct *chartInstance);
static void initSimStructsc23_Experiment_1_cs
  (SFc23_Experiment_1_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber, uint32_T c23_instanceNumber);
static const mxArray *c23_sf_marshallOut(void *chartInstanceVoid, real_T
  c23_c_inData_data[], int32_T c23_inData_sizes[2]);
static void c23_emlrt_marshallIn(SFc23_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c23_im, const char_T *c23_identifier, real_T
  c23_b_y_data[], int32_T c23_y_sizes[2]);
static void c23_b_emlrt_marshallIn(SFc23_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  real_T c23_b_y_data[], int32_T c23_y_sizes[2]);
static void c23_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, real_T c23_outData_data[],
  int32_T c23_outData_sizes[2]);
static const mxArray *c23_b_sf_marshallOut(void *chartInstanceVoid, boolean_T
  c23_c_inData_data[], int32_T c23_inData_sizes[2]);
static const mxArray *c23_c_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static real_T c23_c_emlrt_marshallIn(SFc23_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_d_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static int32_T c23_d_emlrt_marshallIn(SFc23_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static uint8_T c23_e_emlrt_marshallIn(SFc23_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c23_b_is_active_c23_Experiment_1_cs, const
  char_T *c23_identifier);
static uint8_T c23_f_emlrt_marshallIn(SFc23_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void init_dsm_address_info(SFc23_Experiment_1_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc23_Experiment_1_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c23_Experiment_1_cs(SFc23_Experiment_1_csInstanceStruct
  *chartInstance)
{
  chartInstance->c23_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c23_is_active_c23_Experiment_1_cs = 0U;
}

static void initialize_params_c23_Experiment_1_cs
  (SFc23_Experiment_1_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c23_Experiment_1_cs(SFc23_Experiment_1_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c23_Experiment_1_cs(SFc23_Experiment_1_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c23_update_debugger_state_c23_Experiment_1_cs
  (SFc23_Experiment_1_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c23_Experiment_1_cs
  (SFc23_Experiment_1_csInstanceStruct *chartInstance)
{
  const mxArray *c23_st;
  const mxArray *c23_y = NULL;
  int32_T c23_u_sizes[2];
  int32_T c23_u;
  int32_T c23_b_u;
  int32_T c23_loop_ub;
  int32_T c23_i0;
  const mxArray *c23_b_y = NULL;
  uint8_T c23_hoistedGlobal;
  uint8_T c23_c_u;
  const mxArray *c23_c_y = NULL;
  c23_st = NULL;
  c23_st = NULL;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_createcellmatrix(2, 1), false);
  c23_u_sizes[0] = (*chartInstance->c23_im_sizes)[0];
  c23_u_sizes[1] = (*chartInstance->c23_im_sizes)[1];
  c23_u = c23_u_sizes[0];
  c23_b_u = c23_u_sizes[1];
  c23_loop_ub = (*chartInstance->c23_im_sizes)[0] *
    (*chartInstance->c23_im_sizes)[1] - 1;
  for (c23_i0 = 0; c23_i0 <= c23_loop_ub; c23_i0++) {
    chartInstance->c23_b_u_data[c23_i0] = (*chartInstance->c23_b_im_data)[c23_i0];
  }

  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", chartInstance->c23_b_u_data, 0, 0U,
    1U, 0U, 2, c23_u_sizes[0], c23_u_sizes[1]), false);
  sf_mex_setcell(c23_y, 0, c23_b_y);
  c23_hoistedGlobal = chartInstance->c23_is_active_c23_Experiment_1_cs;
  c23_c_u = c23_hoistedGlobal;
  c23_c_y = NULL;
  sf_mex_assign(&c23_c_y, sf_mex_create("y", &c23_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c23_y, 1, c23_c_y);
  sf_mex_assign(&c23_st, c23_y, false);
  return c23_st;
}

static void set_sim_state_c23_Experiment_1_cs
  (SFc23_Experiment_1_csInstanceStruct *chartInstance, const mxArray *c23_st)
{
  const mxArray *c23_u;
  int32_T c23_tmp_sizes[2];
  int32_T c23_i1;
  int32_T c23_i2;
  int32_T c23_loop_ub;
  int32_T c23_i3;
  chartInstance->c23_doneDoubleBufferReInit = true;
  c23_u = sf_mex_dup(c23_st);
  c23_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c23_u, 0)), "im",
                       chartInstance->c23_c_tmp_data, c23_tmp_sizes);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1, 0,
    c23_tmp_sizes[0]);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1, 1,
    c23_tmp_sizes[1]);
  c23_i1 = (*chartInstance->c23_im_sizes)[0];
  c23_i2 = (*chartInstance->c23_im_sizes)[1];
  c23_loop_ub = c23_tmp_sizes[0] * c23_tmp_sizes[1] - 1;
  for (c23_i3 = 0; c23_i3 <= c23_loop_ub; c23_i3++) {
    (*chartInstance->c23_b_im_data)[c23_i3] = chartInstance->
      c23_c_tmp_data[c23_i3];
  }

  chartInstance->c23_is_active_c23_Experiment_1_cs = c23_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c23_u, 1)),
     "is_active_c23_Experiment_1_cs");
  sf_mex_destroy(&c23_u);
  c23_update_debugger_state_c23_Experiment_1_cs(chartInstance);
  sf_mex_destroy(&c23_st);
}

static void finalize_c23_Experiment_1_cs(SFc23_Experiment_1_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c23_Experiment_1_cs(SFc23_Experiment_1_csInstanceStruct
  *chartInstance)
{
  int32_T c23_loop_ub;
  int32_T c23_i4;
  int32_T c23_b_loop_ub;
  int32_T c23_i5;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 22U, chartInstance->c23_sfEvent);
  chartInstance->c23_sfEvent = CALL_EVENT;
  c23_chartstep_c23_Experiment_1_cs(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_1_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  c23_loop_ub = (*chartInstance->c23_im_sizes)[0] *
    (*chartInstance->c23_im_sizes)[1] - 1;
  for (c23_i4 = 0; c23_i4 <= c23_loop_ub; c23_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c23_b_im_data)[c23_i4], 0U);
  }

  c23_b_loop_ub = (*chartInstance->c23_image_sizes)[0] *
    (*chartInstance->c23_image_sizes)[1] - 1;
  for (c23_i5 = 0; c23_i5 <= c23_b_loop_ub; c23_i5++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c23_image_data)[c23_i5], 1U);
  }
}

static void mdl_start_c23_Experiment_1_cs(SFc23_Experiment_1_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c23_chartstep_c23_Experiment_1_cs
  (SFc23_Experiment_1_csInstanceStruct *chartInstance)
{
  int32_T c23_b_image_sizes[2];
  int32_T c23_image;
  int32_T c23_b_image;
  int32_T c23_loop_ub;
  int32_T c23_i6;
  boolean_T c23_b_image_data[187500];
  uint32_T c23_debug_family_var_map[6];
  real_T c23_i;
  real_T c23_j;
  real_T c23_nargin = 1.0;
  real_T c23_nargout = 1.0;
  int32_T c23_b_im_sizes[2];
  int32_T c23_c_image[2];
  int32_T c23_tmp_sizes[2];
  int32_T c23_d_image[2];
  int32_T c23_i7;
  int32_T c23_i8;
  int32_T c23_b_loop_ub;
  int32_T c23_i9;
  int32_T c23_im;
  int32_T c23_b_im;
  int32_T c23_c_loop_ub;
  int32_T c23_i10;
  real_T c23_d0;
  int32_T c23_i11;
  int32_T c23_b_i;
  real_T c23_d1;
  int32_T c23_i12;
  int32_T c23_b_j;
  real_T c23_d2;
  int32_T c23_i13;
  int32_T c23_i14;
  int32_T c23_d_loop_ub;
  int32_T c23_i15;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 22U, chartInstance->c23_sfEvent);
  c23_b_image_sizes[0] = (*chartInstance->c23_image_sizes)[0];
  c23_b_image_sizes[1] = (*chartInstance->c23_image_sizes)[1];
  c23_image = c23_b_image_sizes[0];
  c23_b_image = c23_b_image_sizes[1];
  c23_loop_ub = (*chartInstance->c23_image_sizes)[0] *
    (*chartInstance->c23_image_sizes)[1] - 1;
  for (c23_i6 = 0; c23_i6 <= c23_loop_ub; c23_i6++) {
    c23_b_image_data[c23_i6] = (*chartInstance->c23_image_data)[c23_i6];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c23_debug_family_names,
    c23_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_i, 0U, c23_c_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_j, 1U, c23_c_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargin, 2U, c23_c_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargout, 3U, c23_c_sf_marshallOut,
    c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN(c23_b_image_data, (const int32_T *)
    &c23_b_image_sizes, NULL, 1, 4, (void *)c23_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(chartInstance->c23_im_data, (const
    int32_T *)&c23_b_im_sizes, NULL, 0, 5, (void *)c23_sf_marshallOut, (void *)
    c23_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 3);
  c23_c_image[0] = c23_b_image_sizes[0];
  c23_c_image[1] = c23_b_image_sizes[1];
  c23_tmp_sizes[0] = c23_c_image[0];
  c23_d_image[0] = c23_b_image_sizes[0];
  c23_d_image[1] = c23_b_image_sizes[1];
  c23_tmp_sizes[1] = c23_d_image[1];
  c23_i7 = c23_tmp_sizes[0];
  c23_i8 = c23_tmp_sizes[1];
  c23_b_loop_ub = c23_b_image_sizes[0] * c23_b_image_sizes[1] - 1;
  for (c23_i9 = 0; c23_i9 <= c23_b_loop_ub; c23_i9++) {
    chartInstance->c23_tmp_data[c23_i9] = 0.0;
  }

  _SFD_DIM_SIZE_GEQ_CHECK(375, c23_tmp_sizes[0], 1);
  _SFD_DIM_SIZE_GEQ_CHECK(500, c23_tmp_sizes[1], 2);
  c23_b_im_sizes[0] = c23_tmp_sizes[0];
  c23_b_im_sizes[1] = c23_tmp_sizes[1];
  c23_im = c23_b_im_sizes[0];
  c23_b_im = c23_b_im_sizes[1];
  c23_c_loop_ub = c23_tmp_sizes[0] * c23_tmp_sizes[1] - 1;
  for (c23_i10 = 0; c23_i10 <= c23_c_loop_ub; c23_i10++) {
    chartInstance->c23_im_data[c23_i10] = chartInstance->c23_tmp_data[c23_i10];
  }

  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 4);
  c23_d0 = (real_T)c23_b_image_sizes[0];
  c23_i11 = (int32_T)c23_d0 - 1;
  c23_i = 1.0;
  c23_b_i = 0;
  while (c23_b_i <= c23_i11) {
    c23_i = 1.0 + (real_T)c23_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 5);
    c23_d1 = (real_T)c23_b_image_sizes[1];
    c23_i12 = (int32_T)c23_d1 - 1;
    c23_j = 1.0;
    c23_b_j = 0;
    while (c23_b_j <= c23_i12) {
      c23_j = 1.0 + (real_T)c23_b_j;
      CV_EML_FOR(0, 1, 1, 1);
      _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 6);
      c23_d2 = (real_T)c23_b_image_data[(_SFD_EML_ARRAY_BOUNDS_CHECK("image",
        (int32_T)c23_i, 1, c23_b_image_sizes[0], 1, 0) + c23_b_image_sizes[0] *
        (_SFD_EML_ARRAY_BOUNDS_CHECK("image", (int32_T)c23_j, 1,
        c23_b_image_sizes[1], 2, 0) - 1)) - 1];
      if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c23_d2, 0.0, -1, 0U,
            c23_d2 == 0.0))) {
        _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 7);
        chartInstance->c23_im_data[(_SFD_EML_ARRAY_BOUNDS_CHECK("im", (int32_T)
          c23_i, 1, c23_b_im_sizes[0], 1, 0) + c23_b_im_sizes[0] *
          (_SFD_EML_ARRAY_BOUNDS_CHECK("im", (int32_T)c23_j, 1, c23_b_im_sizes[1],
          2, 0) - 1)) - 1] = 1.0;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 9);
        chartInstance->c23_im_data[(_SFD_EML_ARRAY_BOUNDS_CHECK("im", (int32_T)
          c23_i, 1, c23_b_im_sizes[0], 1, 0) + c23_b_im_sizes[0] *
          (_SFD_EML_ARRAY_BOUNDS_CHECK("im", (int32_T)c23_j, 1, c23_b_im_sizes[1],
          2, 0) - 1)) - 1] = 0.0;
      }

      c23_b_j++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    CV_EML_FOR(0, 1, 1, 0);
    c23_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, -9);
  _SFD_SYMBOL_SCOPE_POP();
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1, 0,
    c23_b_im_sizes[0]);
  ssSetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1, 1,
    c23_b_im_sizes[1]);
  c23_i13 = (*chartInstance->c23_im_sizes)[0];
  c23_i14 = (*chartInstance->c23_im_sizes)[1];
  c23_d_loop_ub = c23_b_im_sizes[0] * c23_b_im_sizes[1] - 1;
  for (c23_i15 = 0; c23_i15 <= c23_d_loop_ub; c23_i15++) {
    (*chartInstance->c23_b_im_data)[c23_i15] = chartInstance->
      c23_im_data[c23_i15];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, chartInstance->c23_sfEvent);
}

static void initSimStructsc23_Experiment_1_cs
  (SFc23_Experiment_1_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber, uint32_T c23_instanceNumber)
{
  (void)c23_machineNumber;
  (void)c23_chartNumber;
  (void)c23_instanceNumber;
}

static const mxArray *c23_sf_marshallOut(void *chartInstanceVoid, real_T
  c23_c_inData_data[], int32_T c23_inData_sizes[2])
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_u_sizes[2];
  int32_T c23_u;
  int32_T c23_b_u;
  int32_T c23_inData;
  int32_T c23_b_inData;
  int32_T c23_b_inData_sizes;
  int32_T c23_loop_ub;
  int32_T c23_i16;
  int32_T c23_b_loop_ub;
  int32_T c23_i17;
  const mxArray *c23_y = NULL;
  SFc23_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc23_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u_sizes[0] = c23_inData_sizes[0];
  c23_u_sizes[1] = c23_inData_sizes[1];
  c23_u = c23_u_sizes[0];
  c23_b_u = c23_u_sizes[1];
  c23_inData = c23_inData_sizes[0];
  c23_b_inData = c23_inData_sizes[1];
  c23_b_inData_sizes = c23_inData * c23_b_inData;
  c23_loop_ub = c23_inData * c23_b_inData - 1;
  for (c23_i16 = 0; c23_i16 <= c23_loop_ub; c23_i16++) {
    chartInstance->c23_inData_data[c23_i16] = c23_c_inData_data[c23_i16];
  }

  c23_b_loop_ub = c23_b_inData_sizes - 1;
  for (c23_i17 = 0; c23_i17 <= c23_b_loop_ub; c23_i17++) {
    chartInstance->c23_u_data[c23_i17] = chartInstance->c23_inData_data[c23_i17];
  }

  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", chartInstance->c23_u_data, 0, 0U, 1U,
    0U, 2, c23_u_sizes[0], c23_u_sizes[1]), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static void c23_emlrt_marshallIn(SFc23_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c23_im, const char_T *c23_identifier, real_T
  c23_b_y_data[], int32_T c23_y_sizes[2])
{
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_im), &c23_thisId,
    c23_b_y_data, c23_y_sizes);
  sf_mex_destroy(&c23_im);
}

static void c23_b_emlrt_marshallIn(SFc23_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  real_T c23_b_y_data[], int32_T c23_y_sizes[2])
{
  int32_T c23_i18;
  uint32_T c23_uv0[2];
  int32_T c23_i19;
  boolean_T c23_bv0[2];
  int32_T c23_tmp_sizes[2];
  int32_T c23_y;
  int32_T c23_b_y;
  int32_T c23_loop_ub;
  int32_T c23_i20;
  for (c23_i18 = 0; c23_i18 < 2; c23_i18++) {
    c23_uv0[c23_i18] = 375U + 125U * (uint32_T)c23_i18;
  }

  for (c23_i19 = 0; c23_i19 < 2; c23_i19++) {
    c23_bv0[c23_i19] = true;
  }

  sf_mex_import_vs(c23_parentId, sf_mex_dup(c23_u),
                   chartInstance->c23_b_tmp_data, 1, 0, 0U, 1, 0U, 2, c23_bv0,
                   c23_uv0, c23_tmp_sizes);
  c23_y_sizes[0] = c23_tmp_sizes[0];
  c23_y_sizes[1] = c23_tmp_sizes[1];
  c23_y = c23_y_sizes[0];
  c23_b_y = c23_y_sizes[1];
  c23_loop_ub = c23_tmp_sizes[0] * c23_tmp_sizes[1] - 1;
  for (c23_i20 = 0; c23_i20 <= c23_loop_ub; c23_i20++) {
    c23_b_y_data[c23_i20] = chartInstance->c23_b_tmp_data[c23_i20];
  }

  sf_mex_destroy(&c23_u);
}

static void c23_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, real_T c23_outData_data[],
  int32_T c23_outData_sizes[2])
{
  const mxArray *c23_im;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  int32_T c23_y_sizes[2];
  int32_T c23_loop_ub;
  int32_T c23_i21;
  int32_T c23_b_loop_ub;
  int32_T c23_i22;
  SFc23_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc23_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c23_im = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_im), &c23_thisId,
    chartInstance->c23_y_data, c23_y_sizes);
  sf_mex_destroy(&c23_im);
  c23_outData_sizes[0] = c23_y_sizes[0];
  c23_outData_sizes[1] = c23_y_sizes[1];
  c23_loop_ub = c23_y_sizes[1] - 1;
  for (c23_i21 = 0; c23_i21 <= c23_loop_ub; c23_i21++) {
    c23_b_loop_ub = c23_y_sizes[0] - 1;
    for (c23_i22 = 0; c23_i22 <= c23_b_loop_ub; c23_i22++) {
      c23_outData_data[c23_i22 + c23_outData_sizes[0] * c23_i21] =
        chartInstance->c23_y_data[c23_i22 + c23_y_sizes[0] * c23_i21];
    }
  }

  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_b_sf_marshallOut(void *chartInstanceVoid, boolean_T
  c23_c_inData_data[], int32_T c23_inData_sizes[2])
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_u_sizes[2];
  int32_T c23_u;
  int32_T c23_b_u;
  int32_T c23_inData;
  int32_T c23_b_inData;
  int32_T c23_b_inData_sizes;
  int32_T c23_loop_ub;
  int32_T c23_i23;
  int32_T c23_b_loop_ub;
  int32_T c23_i24;
  boolean_T c23_c_u_data[187500];
  const mxArray *c23_y = NULL;
  SFc23_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc23_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u_sizes[0] = c23_inData_sizes[0];
  c23_u_sizes[1] = c23_inData_sizes[1];
  c23_u = c23_u_sizes[0];
  c23_b_u = c23_u_sizes[1];
  c23_inData = c23_inData_sizes[0];
  c23_b_inData = c23_inData_sizes[1];
  c23_b_inData_sizes = c23_inData * c23_b_inData;
  c23_loop_ub = c23_inData * c23_b_inData - 1;
  for (c23_i23 = 0; c23_i23 <= c23_loop_ub; c23_i23++) {
    chartInstance->c23_b_inData_data[c23_i23] = c23_c_inData_data[c23_i23];
  }

  c23_b_loop_ub = c23_b_inData_sizes - 1;
  for (c23_i24 = 0; c23_i24 <= c23_b_loop_ub; c23_i24++) {
    c23_c_u_data[c23_i24] = chartInstance->c23_b_inData_data[c23_i24];
  }

  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", c23_c_u_data, 11, 0U, 1U, 0U, 2,
    c23_u_sizes[0], c23_u_sizes[1]), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static const mxArray *c23_c_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  real_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc23_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(real_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static real_T c23_c_emlrt_marshallIn(SFc23_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  real_T c23_y;
  real_T c23_d3;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_d3, 1, 0, 0U, 0, 0U, 0);
  c23_y = c23_d3;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_nargout;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_y;
  SFc23_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc23_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c23_nargout = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_nargout),
    &c23_thisId);
  sf_mex_destroy(&c23_nargout);
  *(real_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

const mxArray *sf_c23_Experiment_1_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c23_nameCaptureInfo = NULL;
  c23_nameCaptureInfo = NULL;
  sf_mex_assign(&c23_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c23_nameCaptureInfo;
}

static const mxArray *c23_d_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc23_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(int32_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static int32_T c23_d_emlrt_marshallIn(SFc23_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  int32_T c23_y;
  int32_T c23_i25;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_i25, 1, 6, 0U, 0, 0U, 0);
  c23_y = c23_i25;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_sfEvent;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  int32_T c23_y;
  SFc23_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc23_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c23_b_sfEvent = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_sfEvent),
    &c23_thisId);
  sf_mex_destroy(&c23_b_sfEvent);
  *(int32_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static uint8_T c23_e_emlrt_marshallIn(SFc23_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c23_b_is_active_c23_Experiment_1_cs, const
  char_T *c23_identifier)
{
  uint8_T c23_y;
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c23_b_is_active_c23_Experiment_1_cs), &c23_thisId);
  sf_mex_destroy(&c23_b_is_active_c23_Experiment_1_cs);
  return c23_y;
}

static uint8_T c23_f_emlrt_marshallIn(SFc23_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  uint8_T c23_y;
  uint8_T c23_u0;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_u0, 1, 3, 0U, 0, 0U, 0);
  c23_y = c23_u0;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void init_dsm_address_info(SFc23_Experiment_1_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc23_Experiment_1_csInstanceStruct
  *chartInstance)
{
  chartInstance->c23_b_im_data = (real_T (*)[187500])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c23_im_sizes = (int32_T (*)[2])
    ssGetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1);
  chartInstance->c23_image_data = (boolean_T (*)[187500])
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c23_image_sizes = (int32_T (*)[2])
    ssGetCurrentInputPortDimensions_wrapper(chartInstance->S, 0);
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

void sf_c23_Experiment_1_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1620945865U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3903826384U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3409445818U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2814580644U);
}

mxArray* sf_c23_Experiment_1_cs_get_post_codegen_info(void);
mxArray *sf_c23_Experiment_1_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("vwRtlhuauKRWchwJ0fzG3C");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
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
      pr[0] = (double)(375);
      pr[1] = (double)(500);
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
    mxArray* mxPostCodegenInfo = sf_c23_Experiment_1_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c23_Experiment_1_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c23_Experiment_1_cs_jit_fallback_info(void)
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

mxArray *sf_c23_Experiment_1_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c23_Experiment_1_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c23_Experiment_1_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[4],T\"im\",},{M[8],M[0],T\"is_active_c23_Experiment_1_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c23_Experiment_1_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc23_Experiment_1_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc23_Experiment_1_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_1_csMachineNumber_,
           23,
           1,
           1,
           0,
           2,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"im");
          _SFD_SET_DATA_PROPS(1,1,1,0,"image");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,2,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,233);
        _SFD_CV_INIT_EML_IF(0,1,0,132,150,182,221);
        _SFD_CV_INIT_EML_FOR(0,1,0,76,98,233);
        _SFD_CV_INIT_EML_FOR(0,1,1,102,124,229);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,136,149,-1,0);

        {
          unsigned int dimVector[2];
          dimVector[0]= 375;
          dimVector[1]= 500;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c23_sf_marshallOut,(MexInFcnForType)
            c23_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 375;
          dimVector[1]= 500;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c23_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR_VAR_DIM(0U, *chartInstance->c23_b_im_data, (void
          *)chartInstance->c23_im_sizes);
        _SFD_SET_DATA_VALUE_PTR_VAR_DIM(1U, *chartInstance->c23_image_data,
          (void *)chartInstance->c23_image_sizes);
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
  return "XWUeCWHgCzo7v1HSzSL4OC";
}

static void sf_opaque_initialize_c23_Experiment_1_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc23_Experiment_1_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c23_Experiment_1_cs((SFc23_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
  initialize_c23_Experiment_1_cs((SFc23_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c23_Experiment_1_cs(void *chartInstanceVar)
{
  enable_c23_Experiment_1_cs((SFc23_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c23_Experiment_1_cs(void *chartInstanceVar)
{
  disable_c23_Experiment_1_cs((SFc23_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c23_Experiment_1_cs(void *chartInstanceVar)
{
  sf_gateway_c23_Experiment_1_cs((SFc23_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c23_Experiment_1_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c23_Experiment_1_cs((SFc23_Experiment_1_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c23_Experiment_1_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c23_Experiment_1_cs((SFc23_Experiment_1_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c23_Experiment_1_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc23_Experiment_1_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_1_cs_optimization_info();
    }

    finalize_c23_Experiment_1_cs((SFc23_Experiment_1_csInstanceStruct*)
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
  initSimStructsc23_Experiment_1_cs((SFc23_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c23_Experiment_1_cs(SimStruct *S)
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
    initialize_params_c23_Experiment_1_cs((SFc23_Experiment_1_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c23_Experiment_1_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Experiment_1_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      23);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,23,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,23,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,23);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,23,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,23,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,23);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(459035515U));
  ssSetChecksum1(S,(2085129281U));
  ssSetChecksum2(S,(2016877893U));
  ssSetChecksum3(S,(3545720292U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c23_Experiment_1_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c23_Experiment_1_cs(SimStruct *S)
{
  SFc23_Experiment_1_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc23_Experiment_1_csInstanceStruct *)utMalloc(sizeof
    (SFc23_Experiment_1_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc23_Experiment_1_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c23_Experiment_1_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c23_Experiment_1_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c23_Experiment_1_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c23_Experiment_1_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c23_Experiment_1_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c23_Experiment_1_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c23_Experiment_1_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c23_Experiment_1_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c23_Experiment_1_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c23_Experiment_1_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c23_Experiment_1_cs;
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

void c23_Experiment_1_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c23_Experiment_1_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c23_Experiment_1_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c23_Experiment_1_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c23_Experiment_1_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
