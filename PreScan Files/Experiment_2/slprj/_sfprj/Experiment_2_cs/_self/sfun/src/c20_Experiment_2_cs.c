/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_2_cs_sfun.h"
#include "c20_Experiment_2_cs.h"
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
static const char * c20_debug_family_names[12] = { "n", "not_before", "a", "i",
  "j", "h", "nargin", "nargout", "nbboxout", "label", "r_label", "color" };

/* Function Declarations */
static void initialize_c20_Experiment_2_cs(SFc20_Experiment_2_csInstanceStruct
  *chartInstance);
static void initialize_params_c20_Experiment_2_cs
  (SFc20_Experiment_2_csInstanceStruct *chartInstance);
static void enable_c20_Experiment_2_cs(SFc20_Experiment_2_csInstanceStruct
  *chartInstance);
static void disable_c20_Experiment_2_cs(SFc20_Experiment_2_csInstanceStruct
  *chartInstance);
static void c20_update_debugger_state_c20_Experiment_2_cs
  (SFc20_Experiment_2_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c20_Experiment_2_cs
  (SFc20_Experiment_2_csInstanceStruct *chartInstance);
static void set_sim_state_c20_Experiment_2_cs
  (SFc20_Experiment_2_csInstanceStruct *chartInstance, const mxArray *c20_st);
static void finalize_c20_Experiment_2_cs(SFc20_Experiment_2_csInstanceStruct
  *chartInstance);
static void sf_gateway_c20_Experiment_2_cs(SFc20_Experiment_2_csInstanceStruct
  *chartInstance);
static void mdl_start_c20_Experiment_2_cs(SFc20_Experiment_2_csInstanceStruct
  *chartInstance);
static void initSimStructsc20_Experiment_2_cs
  (SFc20_Experiment_2_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber, uint32_T c20_instanceNumber);
static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static void c20_emlrt_marshallIn(SFc20_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c20_b_color, const char_T *c20_identifier,
  real_T c20_y[100]);
static void c20_b_emlrt_marshallIn(SFc20_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[100]);
static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, real_T
  c20_b_inData_data[], int32_T c20_inData_sizes[2]);
static const mxArray *c20_c_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static const mxArray *c20_d_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static real_T c20_c_emlrt_marshallIn(SFc20_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_e_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static int32_T c20_d_emlrt_marshallIn(SFc20_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static uint8_T c20_e_emlrt_marshallIn(SFc20_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c20_b_is_active_c20_Experiment_2_cs, const
  char_T *c20_identifier);
static uint8_T c20_f_emlrt_marshallIn(SFc20_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void init_dsm_address_info(SFc20_Experiment_2_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc20_Experiment_2_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c20_Experiment_2_cs(SFc20_Experiment_2_csInstanceStruct
  *chartInstance)
{
  chartInstance->c20_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c20_is_active_c20_Experiment_2_cs = 0U;
}

static void initialize_params_c20_Experiment_2_cs
  (SFc20_Experiment_2_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c20_Experiment_2_cs(SFc20_Experiment_2_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c20_Experiment_2_cs(SFc20_Experiment_2_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c20_update_debugger_state_c20_Experiment_2_cs
  (SFc20_Experiment_2_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c20_Experiment_2_cs
  (SFc20_Experiment_2_csInstanceStruct *chartInstance)
{
  const mxArray *c20_st;
  const mxArray *c20_y = NULL;
  int32_T c20_i0;
  real_T c20_u[100];
  const mxArray *c20_b_y = NULL;
  int32_T c20_i1;
  real_T c20_b_u[100];
  const mxArray *c20_c_y = NULL;
  uint8_T c20_hoistedGlobal;
  uint8_T c20_c_u;
  const mxArray *c20_d_y = NULL;
  c20_st = NULL;
  c20_st = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_createcellmatrix(3, 1), false);
  for (c20_i0 = 0; c20_i0 < 100; c20_i0++) {
    c20_u[c20_i0] = (*chartInstance->c20_color)[c20_i0];
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 2, 1, 100),
                false);
  sf_mex_setcell(c20_y, 0, c20_b_y);
  for (c20_i1 = 0; c20_i1 < 100; c20_i1++) {
    c20_b_u[c20_i1] = (*chartInstance->c20_r_label)[c20_i1];
  }

  c20_c_y = NULL;
  sf_mex_assign(&c20_c_y, sf_mex_create("y", c20_b_u, 0, 0U, 1U, 0U, 2, 1, 100),
                false);
  sf_mex_setcell(c20_y, 1, c20_c_y);
  c20_hoistedGlobal = chartInstance->c20_is_active_c20_Experiment_2_cs;
  c20_c_u = c20_hoistedGlobal;
  c20_d_y = NULL;
  sf_mex_assign(&c20_d_y, sf_mex_create("y", &c20_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 2, c20_d_y);
  sf_mex_assign(&c20_st, c20_y, false);
  return c20_st;
}

static void set_sim_state_c20_Experiment_2_cs
  (SFc20_Experiment_2_csInstanceStruct *chartInstance, const mxArray *c20_st)
{
  const mxArray *c20_u;
  real_T c20_dv0[100];
  int32_T c20_i2;
  real_T c20_dv1[100];
  int32_T c20_i3;
  chartInstance->c20_doneDoubleBufferReInit = true;
  c20_u = sf_mex_dup(c20_st);
  c20_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 0)),
                       "color", c20_dv0);
  for (c20_i2 = 0; c20_i2 < 100; c20_i2++) {
    (*chartInstance->c20_color)[c20_i2] = c20_dv0[c20_i2];
  }

  c20_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 1)),
                       "r_label", c20_dv1);
  for (c20_i3 = 0; c20_i3 < 100; c20_i3++) {
    (*chartInstance->c20_r_label)[c20_i3] = c20_dv1[c20_i3];
  }

  chartInstance->c20_is_active_c20_Experiment_2_cs = c20_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 2)),
     "is_active_c20_Experiment_2_cs");
  sf_mex_destroy(&c20_u);
  c20_update_debugger_state_c20_Experiment_2_cs(chartInstance);
  sf_mex_destroy(&c20_st);
}

static void finalize_c20_Experiment_2_cs(SFc20_Experiment_2_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c20_Experiment_2_cs(SFc20_Experiment_2_csInstanceStruct
  *chartInstance)
{
  int32_T c20_i4;
  int32_T c20_loop_ub;
  int32_T c20_i5;
  int32_T c20_i6;
  int32_T c20_b_nbboxout[400];
  int32_T c20_b_label_sizes[2];
  int32_T c20_label;
  int32_T c20_b_label;
  int32_T c20_b_loop_ub;
  int32_T c20_i7;
  uint32_T c20_debug_family_var_map[12];
  real_T c20_n;
  real_T c20_not_before;
  real_T c20_a;
  real_T c20_i;
  real_T c20_j;
  real_T c20_h;
  real_T c20_nargin = 2.0;
  real_T c20_nargout = 2.0;
  real_T c20_b_r_label[100];
  real_T c20_b_color[100];
  int32_T c20_i8;
  int32_T c20_i9;
  real_T c20_d0;
  int32_T c20_i10;
  int32_T c20_b_i;
  real_T c20_d1;
  int32_T c20_i11;
  int32_T c20_b_j;
  real_T c20_d2;
  real_T c20_d3;
  real_T c20_b_a;
  int32_T c20_i12;
  int32_T c20_b_h;
  real_T c20_d4;
  real_T c20_d5;
  int32_T c20_i13;
  int32_T c20_i14;
  int32_T c20_i15;
  int32_T c20_i16;
  int32_T c20_i17;
  int32_T exitg1;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 19U, chartInstance->c20_sfEvent);
  for (c20_i4 = 0; c20_i4 < 400; c20_i4++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c20_nbboxout)[c20_i4], 0U);
  }

  c20_loop_ub = (*chartInstance->c20_label_sizes)[0] *
    (*chartInstance->c20_label_sizes)[1] - 1;
  for (c20_i5 = 0; c20_i5 <= c20_loop_ub; c20_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c20_b_label_data)[c20_i5], 1U);
  }

  chartInstance->c20_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 19U, chartInstance->c20_sfEvent);
  for (c20_i6 = 0; c20_i6 < 400; c20_i6++) {
    c20_b_nbboxout[c20_i6] = (*chartInstance->c20_nbboxout)[c20_i6];
  }

  c20_b_label_sizes[0] = (*chartInstance->c20_label_sizes)[0];
  c20_b_label_sizes[1] = (*chartInstance->c20_label_sizes)[1];
  c20_label = c20_b_label_sizes[0];
  c20_b_label = c20_b_label_sizes[1];
  c20_b_loop_ub = (*chartInstance->c20_label_sizes)[0] *
    (*chartInstance->c20_label_sizes)[1] - 1;
  for (c20_i7 = 0; c20_i7 <= c20_b_loop_ub; c20_i7++) {
    chartInstance->c20_label_data[c20_i7] = (*chartInstance->c20_b_label_data)
      [c20_i7];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c20_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_n, 0U, c20_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_not_before, 1U, c20_d_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_a, 2U, c20_d_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_i, 3U, c20_d_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_j, 4U, c20_d_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_h, 5U, c20_d_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 6U, c20_d_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 7U, c20_d_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_b_nbboxout, 8U, c20_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN(chartInstance->c20_label_data, (const int32_T *)
    &c20_b_label_sizes, NULL, 1, 9, (void *)c20_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_b_r_label, 10U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_b_color, 11U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 3);
  c20_n = 100.0;
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 4);
  for (c20_i8 = 0; c20_i8 < 100; c20_i8++) {
    c20_b_r_label[c20_i8] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 5);
  for (c20_i9 = 0; c20_i9 < 100; c20_i9++) {
    c20_b_color[c20_i9] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 6);
  c20_not_before = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 7);
  c20_a = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 8);
  c20_d0 = (real_T)c20_b_label_sizes[0];
  c20_i10 = (int32_T)c20_d0 - 1;
  c20_i = 1.0;
  c20_b_i = 0;
  while (c20_b_i <= c20_i10) {
    c20_i = 1.0 + (real_T)c20_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 9);
    c20_d1 = (real_T)c20_b_label_sizes[1];
    c20_i11 = (int32_T)c20_d1 - 1;
    c20_j = 1.0;
    c20_b_j = 0;
    while (c20_b_j <= c20_i11) {
      c20_j = 1.0 + (real_T)c20_b_j;
      CV_EML_FOR(0, 1, 1, 1);
      _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 10);
      if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c20_a, 1.0, -1, 0U,
            c20_a == 1.0))) {
        _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 11);
        c20_d2 = chartInstance->c20_label_data[(_SFD_EML_ARRAY_BOUNDS_CHECK(
          "label", (int32_T)c20_i, 1, c20_b_label_sizes[0], 1, 0) +
          c20_b_label_sizes[0] * (_SFD_EML_ARRAY_BOUNDS_CHECK("label", (int32_T)
          c20_j, 1, c20_b_label_sizes[1], 2, 0) - 1)) - 1];
        if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c20_d2, 0.0, -1, 1U,
              c20_d2 != 0.0))) {
          _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 12);
          c20_b_r_label[0] = chartInstance->c20_label_data
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("label", (int32_T)c20_i, 1,
               c20_b_label_sizes[0], 1, 0) + c20_b_label_sizes[0] *
              (_SFD_EML_ARRAY_BOUNDS_CHECK("label", (int32_T)c20_j, 1,
                c20_b_label_sizes[1], 2, 0) - 1)) - 1];
          _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 13);
          c20_a = 2.0;
        }
      } else {
        _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 16);
        c20_d3 = chartInstance->c20_label_data[(_SFD_EML_ARRAY_BOUNDS_CHECK(
          "label", (int32_T)c20_i, 1, c20_b_label_sizes[0], 1, 0) +
          c20_b_label_sizes[0] * (_SFD_EML_ARRAY_BOUNDS_CHECK("label", (int32_T)
          c20_j, 1, c20_b_label_sizes[1], 2, 0) - 1)) - 1];
        if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 2, c20_d3, 0.0, -1, 1U,
              c20_d3 != 0.0))) {
          _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 17);
          c20_b_a = c20_a;
          c20_i12 = (int32_T)c20_b_a;
          _SFD_FOR_LOOP_VECTOR_CHECK(1.0, 1.0, c20_b_a, mxDOUBLE_CLASS, c20_i12);
          c20_h = 1.0;
          c20_b_h = 0;
          do {
            exitg1 = 0;
            if (c20_b_h <= c20_i12 - 1) {
              c20_h = 1.0 + (real_T)c20_b_h;
              CV_EML_FOR(0, 1, 2, 1);
              _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 18);
              c20_d4 = chartInstance->c20_label_data
                [(_SFD_EML_ARRAY_BOUNDS_CHECK("label", (int32_T)c20_i, 1,
                   c20_b_label_sizes[0], 1, 0) + c20_b_label_sizes[0] *
                  (_SFD_EML_ARRAY_BOUNDS_CHECK("label", (int32_T)c20_j, 1,
                    c20_b_label_sizes[1], 2, 0) - 1)) - 1];
              c20_d5 = c20_b_r_label[_SFD_EML_ARRAY_BOUNDS_CHECK("r_label",
                (int32_T)c20_h, 1, 100, 2, 0) - 1];
              if (CV_EML_IF(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 3, c20_d4,
                    c20_d5, -1, 1U, c20_d4 != c20_d5))) {
                _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 19);
                c20_not_before = 1.0;
                c20_b_h++;
                _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
              } else {
                _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 21);
                c20_not_before = 0.0;
                _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 22);
                exitg1 = 1;
              }
            } else {
              CV_EML_FOR(0, 1, 2, 0);
              exitg1 = 1;
            }
          } while (exitg1 == 0);

          _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 25);
          if (CV_EML_IF(0, 1, 4, CV_RELATIONAL_EVAL(4U, 0U, 4, c20_not_before,
                1.0, -1, 0U, c20_not_before == 1.0))) {
            _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 26);
            c20_b_r_label[_SFD_EML_ARRAY_BOUNDS_CHECK("r_label", (int32_T)c20_a,
              1, 100, 2, 0) - 1] = chartInstance->c20_label_data
              [(_SFD_EML_ARRAY_BOUNDS_CHECK("label", (int32_T)c20_i, 1,
                 c20_b_label_sizes[0], 1, 0) + c20_b_label_sizes[0] *
                (_SFD_EML_ARRAY_BOUNDS_CHECK("label", (int32_T)c20_j, 1,
                  c20_b_label_sizes[1], 2, 0) - 1)) - 1];
            _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 27);
            c20_a++;
          }
        }
      }

      c20_b_j++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    CV_EML_FOR(0, 1, 1, 0);
    c20_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 33);
  for (c20_i13 = 0; c20_i13 < 100; c20_i13++) {
    c20_b_color[c20_i13] = 2.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, -33);
  _SFD_SYMBOL_SCOPE_POP();
  for (c20_i14 = 0; c20_i14 < 100; c20_i14++) {
    (*chartInstance->c20_r_label)[c20_i14] = c20_b_r_label[c20_i14];
  }

  for (c20_i15 = 0; c20_i15 < 100; c20_i15++) {
    (*chartInstance->c20_color)[c20_i15] = c20_b_color[c20_i15];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c20_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_2_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c20_i16 = 0; c20_i16 < 100; c20_i16++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c20_r_label)[c20_i16], 2U);
  }

  for (c20_i17 = 0; c20_i17 < 100; c20_i17++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c20_color)[c20_i17], 3U);
  }
}

static void mdl_start_c20_Experiment_2_cs(SFc20_Experiment_2_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc20_Experiment_2_cs
  (SFc20_Experiment_2_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber, uint32_T c20_instanceNumber)
{
  (void)c20_machineNumber;
  (void)c20_chartNumber;
  (void)c20_instanceNumber;
}

static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i18;
  real_T c20_b_inData[100];
  int32_T c20_i19;
  real_T c20_u[100];
  const mxArray *c20_y = NULL;
  SFc20_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc20_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i18 = 0; c20_i18 < 100; c20_i18++) {
    c20_b_inData[c20_i18] = (*(real_T (*)[100])c20_inData)[c20_i18];
  }

  for (c20_i19 = 0; c20_i19 < 100; c20_i19++) {
    c20_u[c20_i19] = c20_b_inData[c20_i19];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 2, 1, 100),
                false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static void c20_emlrt_marshallIn(SFc20_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c20_b_color, const char_T *c20_identifier,
  real_T c20_y[100])
{
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_color), &c20_thisId,
    c20_y);
  sf_mex_destroy(&c20_b_color);
}

static void c20_b_emlrt_marshallIn(SFc20_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[100])
{
  real_T c20_dv2[100];
  int32_T c20_i20;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), c20_dv2, 1, 0, 0U, 1, 0U, 2, 1,
                100);
  for (c20_i20 = 0; c20_i20 < 100; c20_i20++) {
    c20_y[c20_i20] = c20_dv2[c20_i20];
  }

  sf_mex_destroy(&c20_u);
}

static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_b_color;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y[100];
  int32_T c20_i21;
  SFc20_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc20_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c20_b_color = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_color), &c20_thisId,
    c20_y);
  sf_mex_destroy(&c20_b_color);
  for (c20_i21 = 0; c20_i21 < 100; c20_i21++) {
    (*(real_T (*)[100])c20_outData)[c20_i21] = c20_y[c20_i21];
  }

  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, real_T
  c20_b_inData_data[], int32_T c20_inData_sizes[2])
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_u_sizes[2];
  int32_T c20_u;
  int32_T c20_b_u;
  int32_T c20_inData;
  int32_T c20_b_inData;
  int32_T c20_b_inData_sizes;
  int32_T c20_loop_ub;
  int32_T c20_i22;
  int32_T c20_b_loop_ub;
  int32_T c20_i23;
  const mxArray *c20_y = NULL;
  SFc20_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc20_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u_sizes[0] = c20_inData_sizes[0];
  c20_u_sizes[1] = c20_inData_sizes[1];
  c20_u = c20_u_sizes[0];
  c20_b_u = c20_u_sizes[1];
  c20_inData = c20_inData_sizes[0];
  c20_b_inData = c20_inData_sizes[1];
  c20_b_inData_sizes = c20_inData * c20_b_inData;
  c20_loop_ub = c20_inData * c20_b_inData - 1;
  for (c20_i22 = 0; c20_i22 <= c20_loop_ub; c20_i22++) {
    chartInstance->c20_inData_data[c20_i22] = c20_b_inData_data[c20_i22];
  }

  c20_b_loop_ub = c20_b_inData_sizes - 1;
  for (c20_i23 = 0; c20_i23 <= c20_b_loop_ub; c20_i23++) {
    chartInstance->c20_u_data[c20_i23] = chartInstance->c20_inData_data[c20_i23];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", chartInstance->c20_u_data, 0, 0U, 1U,
    0U, 2, c20_u_sizes[0], c20_u_sizes[1]), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static const mxArray *c20_c_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i24;
  int32_T c20_i25;
  int32_T c20_i26;
  int32_T c20_b_inData[400];
  int32_T c20_i27;
  int32_T c20_i28;
  int32_T c20_i29;
  int32_T c20_u[400];
  const mxArray *c20_y = NULL;
  SFc20_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc20_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_i24 = 0;
  for (c20_i25 = 0; c20_i25 < 100; c20_i25++) {
    for (c20_i26 = 0; c20_i26 < 4; c20_i26++) {
      c20_b_inData[c20_i26 + c20_i24] = (*(int32_T (*)[400])c20_inData)[c20_i26
        + c20_i24];
    }

    c20_i24 += 4;
  }

  c20_i27 = 0;
  for (c20_i28 = 0; c20_i28 < 100; c20_i28++) {
    for (c20_i29 = 0; c20_i29 < 4; c20_i29++) {
      c20_u[c20_i29 + c20_i27] = c20_b_inData[c20_i29 + c20_i27];
    }

    c20_i27 += 4;
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 6, 0U, 1U, 0U, 2, 4, 100),
                false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static const mxArray *c20_d_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  real_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc20_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(real_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static real_T c20_c_emlrt_marshallIn(SFc20_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  real_T c20_y;
  real_T c20_d6;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_d6, 1, 0, 0U, 0, 0U, 0);
  c20_y = c20_d6;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_nargout;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y;
  SFc20_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc20_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c20_nargout = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_nargout),
    &c20_thisId);
  sf_mex_destroy(&c20_nargout);
  *(real_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

const mxArray *sf_c20_Experiment_2_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c20_nameCaptureInfo = NULL;
  c20_nameCaptureInfo = NULL;
  sf_mex_assign(&c20_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c20_nameCaptureInfo;
}

static const mxArray *c20_e_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc20_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(int32_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static int32_T c20_d_emlrt_marshallIn(SFc20_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  int32_T c20_y;
  int32_T c20_i30;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_i30, 1, 6, 0U, 0, 0U, 0);
  c20_y = c20_i30;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_b_sfEvent;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  int32_T c20_y;
  SFc20_Experiment_2_csInstanceStruct *chartInstance;
  chartInstance = (SFc20_Experiment_2_csInstanceStruct *)chartInstanceVoid;
  c20_b_sfEvent = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_sfEvent),
    &c20_thisId);
  sf_mex_destroy(&c20_b_sfEvent);
  *(int32_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static uint8_T c20_e_emlrt_marshallIn(SFc20_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c20_b_is_active_c20_Experiment_2_cs, const
  char_T *c20_identifier)
{
  uint8_T c20_y;
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c20_b_is_active_c20_Experiment_2_cs), &c20_thisId);
  sf_mex_destroy(&c20_b_is_active_c20_Experiment_2_cs);
  return c20_y;
}

static uint8_T c20_f_emlrt_marshallIn(SFc20_Experiment_2_csInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  uint8_T c20_y;
  uint8_T c20_u0;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_u0, 1, 3, 0U, 0, 0U, 0);
  c20_y = c20_u0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void init_dsm_address_info(SFc20_Experiment_2_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc20_Experiment_2_csInstanceStruct
  *chartInstance)
{
  chartInstance->c20_nbboxout = (int32_T (*)[400])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c20_b_label_data = (real_T (*)[220000])
    ssGetInputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c20_label_sizes = (int32_T (*)[2])
    ssGetCurrentInputPortDimensions_wrapper(chartInstance->S, 1);
  chartInstance->c20_r_label = (real_T (*)[100])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c20_color = (real_T (*)[100])ssGetOutputPortSignal_wrapper
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

void sf_c20_Experiment_2_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4035617574U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1739987500U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1104817469U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3215849692U);
}

mxArray* sf_c20_Experiment_2_cs_get_post_codegen_info(void);
mxArray *sf_c20_Experiment_2_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("fd0nsKhd84VFfZsIBZwfVD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
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
      pr[0] = (double)(400);
      pr[1] = (double)(550);
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
      pr[1] = (double)(100);
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
      pr[1] = (double)(100);
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
    mxArray* mxPostCodegenInfo = sf_c20_Experiment_2_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c20_Experiment_2_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c20_Experiment_2_cs_jit_fallback_info(void)
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

mxArray *sf_c20_Experiment_2_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c20_Experiment_2_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c20_Experiment_2_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[8],T\"color\",},{M[1],M[5],T\"r_label\",},{M[8],M[0],T\"is_active_c20_Experiment_2_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c20_Experiment_2_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc20_Experiment_2_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc20_Experiment_2_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_2_csMachineNumber_,
           20,
           1,
           1,
           0,
           4,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"nbboxout");
          _SFD_SET_DATA_PROPS(1,1,1,0,"label");
          _SFD_SET_DATA_PROPS(2,2,0,1,"r_label");
          _SFD_SET_DATA_PROPS(3,2,0,1,"color");
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
        _SFD_CV_INIT_EML(0,1,1,5,0,0,0,3,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,800);
        _SFD_CV_INIT_EML_IF(0,1,0,191,200,320,772);
        _SFD_CV_INIT_EML_IF(0,1,1,213,231,-1,311);
        _SFD_CV_INIT_EML_IF(0,1,2,338,356,-1,760);
        _SFD_CV_INIT_EML_IF(0,1,3,405,433,494,593);
        _SFD_CV_INIT_EML_IF(0,1,4,632,648,-1,743);
        _SFD_CV_INIT_EML_FOR(0,1,0,135,157,786);
        _SFD_CV_INIT_EML_FOR(0,1,1,161,183,781);
        _SFD_CV_INIT_EML_FOR(0,1,2,374,384,614);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,195,199,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,217,230,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,342,355,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,408,432,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,4,635,648,-1,0);

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 100;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 400;
          dimVector[1]= 550;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 100;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)
            c20_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 100;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)
            c20_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c20_nbboxout);
        _SFD_SET_DATA_VALUE_PTR_VAR_DIM(1U, *chartInstance->c20_b_label_data,
          (void *)chartInstance->c20_label_sizes);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c20_r_label);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c20_color);
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
  return "EJHDT1wA42B7cghCqu02VC";
}

static void sf_opaque_initialize_c20_Experiment_2_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc20_Experiment_2_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c20_Experiment_2_cs((SFc20_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
  initialize_c20_Experiment_2_cs((SFc20_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c20_Experiment_2_cs(void *chartInstanceVar)
{
  enable_c20_Experiment_2_cs((SFc20_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c20_Experiment_2_cs(void *chartInstanceVar)
{
  disable_c20_Experiment_2_cs((SFc20_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c20_Experiment_2_cs(void *chartInstanceVar)
{
  sf_gateway_c20_Experiment_2_cs((SFc20_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c20_Experiment_2_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c20_Experiment_2_cs((SFc20_Experiment_2_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c20_Experiment_2_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c20_Experiment_2_cs((SFc20_Experiment_2_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c20_Experiment_2_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc20_Experiment_2_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_2_cs_optimization_info();
    }

    finalize_c20_Experiment_2_cs((SFc20_Experiment_2_csInstanceStruct*)
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
  initSimStructsc20_Experiment_2_cs((SFc20_Experiment_2_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c20_Experiment_2_cs(SimStruct *S)
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
    initialize_params_c20_Experiment_2_cs((SFc20_Experiment_2_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c20_Experiment_2_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Experiment_2_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      20);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,20,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,20,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,20);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,20,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,20,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,20);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3891242621U));
  ssSetChecksum1(S,(546526072U));
  ssSetChecksum2(S,(31749533U));
  ssSetChecksum3(S,(353508775U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c20_Experiment_2_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c20_Experiment_2_cs(SimStruct *S)
{
  SFc20_Experiment_2_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc20_Experiment_2_csInstanceStruct *)utMalloc(sizeof
    (SFc20_Experiment_2_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc20_Experiment_2_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c20_Experiment_2_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c20_Experiment_2_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c20_Experiment_2_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c20_Experiment_2_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c20_Experiment_2_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c20_Experiment_2_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c20_Experiment_2_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c20_Experiment_2_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c20_Experiment_2_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c20_Experiment_2_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c20_Experiment_2_cs;
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

void c20_Experiment_2_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c20_Experiment_2_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c20_Experiment_2_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c20_Experiment_2_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c20_Experiment_2_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
