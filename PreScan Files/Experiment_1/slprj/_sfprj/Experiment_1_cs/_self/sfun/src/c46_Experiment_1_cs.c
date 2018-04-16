/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_1_cs_sfun.h"
#include "c46_Experiment_1_cs.h"
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
static const char * c46_debug_family_names[4] = { "nargin", "nargout", "Im",
  "Imout" };

/* Function Declarations */
static void initialize_c46_Experiment_1_cs(SFc46_Experiment_1_csInstanceStruct
  *chartInstance);
static void initialize_params_c46_Experiment_1_cs
  (SFc46_Experiment_1_csInstanceStruct *chartInstance);
static void enable_c46_Experiment_1_cs(SFc46_Experiment_1_csInstanceStruct
  *chartInstance);
static void disable_c46_Experiment_1_cs(SFc46_Experiment_1_csInstanceStruct
  *chartInstance);
static void c46_update_debugger_state_c46_Experiment_1_cs
  (SFc46_Experiment_1_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c46_Experiment_1_cs
  (SFc46_Experiment_1_csInstanceStruct *chartInstance);
static void set_sim_state_c46_Experiment_1_cs
  (SFc46_Experiment_1_csInstanceStruct *chartInstance, const mxArray *c46_st);
static void finalize_c46_Experiment_1_cs(SFc46_Experiment_1_csInstanceStruct
  *chartInstance);
static void sf_gateway_c46_Experiment_1_cs(SFc46_Experiment_1_csInstanceStruct
  *chartInstance);
static void mdl_start_c46_Experiment_1_cs(SFc46_Experiment_1_csInstanceStruct
  *chartInstance);
static void initSimStructsc46_Experiment_1_cs
  (SFc46_Experiment_1_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c46_machineNumber, uint32_T
  c46_chartNumber, uint32_T c46_instanceNumber);
static const mxArray *c46_sf_marshallOut(void *chartInstanceVoid, void
  *c46_c_inData);
static void c46_emlrt_marshallIn(SFc46_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c46_c_Imout, const char_T *c46_identifier,
  real_T c46_b_y[562500]);
static void c46_b_emlrt_marshallIn(SFc46_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c46_d_u, const emlrtMsgIdentifier *c46_parentId,
  real_T c46_b_y[562500]);
static void c46_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c46_mxArrayInData, const char_T *c46_varName, void *c46_outData);
static const mxArray *c46_b_sf_marshallOut(void *chartInstanceVoid, void
  *c46_c_inData);
static const mxArray *c46_c_sf_marshallOut(void *chartInstanceVoid, void
  *c46_c_inData);
static real_T c46_c_emlrt_marshallIn(SFc46_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c46_d_u, const emlrtMsgIdentifier *c46_parentId);
static void c46_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c46_mxArrayInData, const char_T *c46_varName, void *c46_outData);
static void c46_info_helper(const mxArray **c46_info);
static const mxArray *c46_emlrt_marshallOut(const char * c46_d_u);
static const mxArray *c46_b_emlrt_marshallOut(const uint32_T c46_d_u);
static const mxArray *c46_d_sf_marshallOut(void *chartInstanceVoid, void
  *c46_c_inData);
static int32_T c46_d_emlrt_marshallIn(SFc46_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c46_d_u, const emlrtMsgIdentifier *c46_parentId);
static void c46_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c46_mxArrayInData, const char_T *c46_varName, void *c46_outData);
static uint8_T c46_e_emlrt_marshallIn(SFc46_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c46_b_is_active_c46_Experiment_1_cs, const
  char_T *c46_identifier);
static uint8_T c46_f_emlrt_marshallIn(SFc46_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c46_d_u, const emlrtMsgIdentifier *c46_parentId);
static void init_dsm_address_info(SFc46_Experiment_1_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc46_Experiment_1_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c46_Experiment_1_cs(SFc46_Experiment_1_csInstanceStruct
  *chartInstance)
{
  chartInstance->c46_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c46_is_active_c46_Experiment_1_cs = 0U;
}

static void initialize_params_c46_Experiment_1_cs
  (SFc46_Experiment_1_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c46_Experiment_1_cs(SFc46_Experiment_1_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c46_Experiment_1_cs(SFc46_Experiment_1_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c46_update_debugger_state_c46_Experiment_1_cs
  (SFc46_Experiment_1_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c46_Experiment_1_cs
  (SFc46_Experiment_1_csInstanceStruct *chartInstance)
{
  const mxArray *c46_st;
  const mxArray *c46_b_y = NULL;
  int32_T c46_i0;
  const mxArray *c46_c_y = NULL;
  uint8_T c46_hoistedGlobal;
  uint8_T c46_d_u;
  const mxArray *c46_d_y = NULL;
  c46_st = NULL;
  c46_st = NULL;
  c46_b_y = NULL;
  sf_mex_assign(&c46_b_y, sf_mex_createcellmatrix(2, 1), false);
  for (c46_i0 = 0; c46_i0 < 562500; c46_i0++) {
    chartInstance->c46_b_u[c46_i0] = (*chartInstance->c46_b_Imout)[c46_i0];
  }

  c46_c_y = NULL;
  sf_mex_assign(&c46_c_y, sf_mex_create("y", chartInstance->c46_b_u, 0, 0U, 1U,
    0U, 3, 375, 500, 3), false);
  sf_mex_setcell(c46_b_y, 0, c46_c_y);
  c46_hoistedGlobal = chartInstance->c46_is_active_c46_Experiment_1_cs;
  c46_d_u = c46_hoistedGlobal;
  c46_d_y = NULL;
  sf_mex_assign(&c46_d_y, sf_mex_create("y", &c46_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c46_b_y, 1, c46_d_y);
  sf_mex_assign(&c46_st, c46_b_y, false);
  return c46_st;
}

static void set_sim_state_c46_Experiment_1_cs
  (SFc46_Experiment_1_csInstanceStruct *chartInstance, const mxArray *c46_st)
{
  const mxArray *c46_d_u;
  int32_T c46_i1;
  chartInstance->c46_doneDoubleBufferReInit = true;
  c46_d_u = sf_mex_dup(c46_st);
  c46_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c46_d_u, 0)),
                       "Imout", chartInstance->c46_dv0);
  for (c46_i1 = 0; c46_i1 < 562500; c46_i1++) {
    (*chartInstance->c46_b_Imout)[c46_i1] = chartInstance->c46_dv0[c46_i1];
  }

  chartInstance->c46_is_active_c46_Experiment_1_cs = c46_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c46_d_u, 1)),
     "is_active_c46_Experiment_1_cs");
  sf_mex_destroy(&c46_d_u);
  c46_update_debugger_state_c46_Experiment_1_cs(chartInstance);
  sf_mex_destroy(&c46_st);
}

static void finalize_c46_Experiment_1_cs(SFc46_Experiment_1_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c46_Experiment_1_cs(SFc46_Experiment_1_csInstanceStruct
  *chartInstance)
{
  int32_T c46_i2;
  int32_T c46_i3;
  uint32_T c46_debug_family_var_map[4];
  real_T c46_nargin = 1.0;
  real_T c46_nargout = 1.0;
  int32_T c46_i4;
  int32_T c46_i5;
  int32_T c46_i6;
  int32_T c46_i7;
  int32_T c46_i8;
  int32_T c46_i9;
  int32_T c46_i10;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 20U, chartInstance->c46_sfEvent);
  for (c46_i2 = 0; c46_i2 < 187500; c46_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c46_b_Im)[c46_i2], 0U);
  }

  chartInstance->c46_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 20U, chartInstance->c46_sfEvent);
  for (c46_i3 = 0; c46_i3 < 187500; c46_i3++) {
    chartInstance->c46_Im[c46_i3] = (*chartInstance->c46_b_Im)[c46_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c46_debug_family_names,
    c46_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_nargin, 0U, c46_c_sf_marshallOut,
    c46_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_nargout, 1U, c46_c_sf_marshallOut,
    c46_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c46_Im, 2U, c46_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c46_Imout, 3U,
    c46_sf_marshallOut, c46_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 3);
  for (c46_i4 = 0; c46_i4 < 562500; c46_i4++) {
    chartInstance->c46_b[c46_i4] = 1.0;
  }

  for (c46_i5 = 0; c46_i5 < 562500; c46_i5++) {
    chartInstance->c46_Imout[c46_i5] = 128.0 * chartInstance->c46_b[c46_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 4);
  c46_i6 = 0;
  for (c46_i7 = 0; c46_i7 < 500; c46_i7++) {
    for (c46_i8 = 0; c46_i8 < 375; c46_i8++) {
      chartInstance->c46_Imout[c46_i8 + c46_i6] = chartInstance->c46_Im[c46_i8 +
        c46_i6];
    }

    c46_i6 += 375;
  }

  _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  for (c46_i9 = 0; c46_i9 < 562500; c46_i9++) {
    (*chartInstance->c46_b_Imout)[c46_i9] = chartInstance->c46_Imout[c46_i9];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, chartInstance->c46_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_1_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c46_i10 = 0; c46_i10 < 562500; c46_i10++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c46_b_Imout)[c46_i10], 1U);
  }
}

static void mdl_start_c46_Experiment_1_cs(SFc46_Experiment_1_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc46_Experiment_1_cs
  (SFc46_Experiment_1_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c46_machineNumber, uint32_T
  c46_chartNumber, uint32_T c46_instanceNumber)
{
  (void)c46_machineNumber;
  (void)c46_chartNumber;
  (void)c46_instanceNumber;
}

static const mxArray *c46_sf_marshallOut(void *chartInstanceVoid, void
  *c46_c_inData)
{
  const mxArray *c46_mxArrayOutData = NULL;
  int32_T c46_i11;
  int32_T c46_i12;
  int32_T c46_i13;
  int32_T c46_i14;
  int32_T c46_i15;
  int32_T c46_i16;
  int32_T c46_i17;
  int32_T c46_i18;
  int32_T c46_i19;
  int32_T c46_i20;
  const mxArray *c46_b_y = NULL;
  SFc46_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc46_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c46_mxArrayOutData = NULL;
  c46_i11 = 0;
  for (c46_i12 = 0; c46_i12 < 3; c46_i12++) {
    c46_i13 = 0;
    for (c46_i14 = 0; c46_i14 < 500; c46_i14++) {
      for (c46_i15 = 0; c46_i15 < 375; c46_i15++) {
        chartInstance->c46_inData[(c46_i15 + c46_i13) + c46_i11] = (*(real_T (*)
          [562500])c46_c_inData)[(c46_i15 + c46_i13) + c46_i11];
      }

      c46_i13 += 375;
    }

    c46_i11 += 187500;
  }

  c46_i16 = 0;
  for (c46_i17 = 0; c46_i17 < 3; c46_i17++) {
    c46_i18 = 0;
    for (c46_i19 = 0; c46_i19 < 500; c46_i19++) {
      for (c46_i20 = 0; c46_i20 < 375; c46_i20++) {
        chartInstance->c46_u[(c46_i20 + c46_i18) + c46_i16] =
          chartInstance->c46_inData[(c46_i20 + c46_i18) + c46_i16];
      }

      c46_i18 += 375;
    }

    c46_i16 += 187500;
  }

  c46_b_y = NULL;
  sf_mex_assign(&c46_b_y, sf_mex_create("y", chartInstance->c46_u, 0, 0U, 1U, 0U,
    3, 375, 500, 3), false);
  sf_mex_assign(&c46_mxArrayOutData, c46_b_y, false);
  return c46_mxArrayOutData;
}

static void c46_emlrt_marshallIn(SFc46_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c46_c_Imout, const char_T *c46_identifier,
  real_T c46_b_y[562500])
{
  emlrtMsgIdentifier c46_thisId;
  c46_thisId.fIdentifier = c46_identifier;
  c46_thisId.fParent = NULL;
  c46_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c46_c_Imout), &c46_thisId,
    c46_b_y);
  sf_mex_destroy(&c46_c_Imout);
}

static void c46_b_emlrt_marshallIn(SFc46_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c46_d_u, const emlrtMsgIdentifier *c46_parentId,
  real_T c46_b_y[562500])
{
  int32_T c46_i21;
  sf_mex_import(c46_parentId, sf_mex_dup(c46_d_u), chartInstance->c46_dv1, 1, 0,
                0U, 1, 0U, 3, 375, 500, 3);
  for (c46_i21 = 0; c46_i21 < 562500; c46_i21++) {
    c46_b_y[c46_i21] = chartInstance->c46_dv1[c46_i21];
  }

  sf_mex_destroy(&c46_d_u);
}

static void c46_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c46_mxArrayInData, const char_T *c46_varName, void *c46_outData)
{
  const mxArray *c46_c_Imout;
  const char_T *c46_identifier;
  emlrtMsgIdentifier c46_thisId;
  int32_T c46_i22;
  int32_T c46_i23;
  int32_T c46_i24;
  int32_T c46_i25;
  int32_T c46_i26;
  SFc46_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc46_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c46_c_Imout = sf_mex_dup(c46_mxArrayInData);
  c46_identifier = c46_varName;
  c46_thisId.fIdentifier = c46_identifier;
  c46_thisId.fParent = NULL;
  c46_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c46_c_Imout), &c46_thisId,
    chartInstance->c46_y);
  sf_mex_destroy(&c46_c_Imout);
  c46_i22 = 0;
  for (c46_i23 = 0; c46_i23 < 3; c46_i23++) {
    c46_i24 = 0;
    for (c46_i25 = 0; c46_i25 < 500; c46_i25++) {
      for (c46_i26 = 0; c46_i26 < 375; c46_i26++) {
        (*(real_T (*)[562500])c46_outData)[(c46_i26 + c46_i24) + c46_i22] =
          chartInstance->c46_y[(c46_i26 + c46_i24) + c46_i22];
      }

      c46_i24 += 375;
    }

    c46_i22 += 187500;
  }

  sf_mex_destroy(&c46_mxArrayInData);
}

static const mxArray *c46_b_sf_marshallOut(void *chartInstanceVoid, void
  *c46_c_inData)
{
  const mxArray *c46_mxArrayOutData = NULL;
  int32_T c46_i27;
  int32_T c46_i28;
  int32_T c46_i29;
  int32_T c46_i30;
  int32_T c46_i31;
  int32_T c46_i32;
  const mxArray *c46_b_y = NULL;
  SFc46_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc46_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c46_mxArrayOutData = NULL;
  c46_i27 = 0;
  for (c46_i28 = 0; c46_i28 < 500; c46_i28++) {
    for (c46_i29 = 0; c46_i29 < 375; c46_i29++) {
      chartInstance->c46_b_inData[c46_i29 + c46_i27] = (*(real_T (*)[187500])
        c46_c_inData)[c46_i29 + c46_i27];
    }

    c46_i27 += 375;
  }

  c46_i30 = 0;
  for (c46_i31 = 0; c46_i31 < 500; c46_i31++) {
    for (c46_i32 = 0; c46_i32 < 375; c46_i32++) {
      chartInstance->c46_c_u[c46_i32 + c46_i30] = chartInstance->
        c46_b_inData[c46_i32 + c46_i30];
    }

    c46_i30 += 375;
  }

  c46_b_y = NULL;
  sf_mex_assign(&c46_b_y, sf_mex_create("y", chartInstance->c46_c_u, 0, 0U, 1U,
    0U, 2, 375, 500), false);
  sf_mex_assign(&c46_mxArrayOutData, c46_b_y, false);
  return c46_mxArrayOutData;
}

static const mxArray *c46_c_sf_marshallOut(void *chartInstanceVoid, void
  *c46_c_inData)
{
  const mxArray *c46_mxArrayOutData = NULL;
  real_T c46_d_u;
  const mxArray *c46_b_y = NULL;
  SFc46_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc46_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c46_mxArrayOutData = NULL;
  c46_d_u = *(real_T *)c46_c_inData;
  c46_b_y = NULL;
  sf_mex_assign(&c46_b_y, sf_mex_create("y", &c46_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c46_mxArrayOutData, c46_b_y, false);
  return c46_mxArrayOutData;
}

static real_T c46_c_emlrt_marshallIn(SFc46_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c46_d_u, const emlrtMsgIdentifier *c46_parentId)
{
  real_T c46_b_y;
  real_T c46_d0;
  (void)chartInstance;
  sf_mex_import(c46_parentId, sf_mex_dup(c46_d_u), &c46_d0, 1, 0, 0U, 0, 0U, 0);
  c46_b_y = c46_d0;
  sf_mex_destroy(&c46_d_u);
  return c46_b_y;
}

static void c46_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c46_mxArrayInData, const char_T *c46_varName, void *c46_outData)
{
  const mxArray *c46_nargout;
  const char_T *c46_identifier;
  emlrtMsgIdentifier c46_thisId;
  real_T c46_b_y;
  SFc46_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc46_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c46_nargout = sf_mex_dup(c46_mxArrayInData);
  c46_identifier = c46_varName;
  c46_thisId.fIdentifier = c46_identifier;
  c46_thisId.fParent = NULL;
  c46_b_y = c46_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c46_nargout),
    &c46_thisId);
  sf_mex_destroy(&c46_nargout);
  *(real_T *)c46_outData = c46_b_y;
  sf_mex_destroy(&c46_mxArrayInData);
}

const mxArray *sf_c46_Experiment_1_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c46_nameCaptureInfo = NULL;
  c46_nameCaptureInfo = NULL;
  sf_mex_assign(&c46_nameCaptureInfo, sf_mex_createstruct("structure", 2, 2, 1),
                false);
  c46_info_helper(&c46_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c46_nameCaptureInfo);
  return c46_nameCaptureInfo;
}

static void c46_info_helper(const mxArray **c46_info)
{
  const mxArray *c46_rhs0 = NULL;
  const mxArray *c46_lhs0 = NULL;
  const mxArray *c46_rhs1 = NULL;
  const mxArray *c46_lhs1 = NULL;
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 0);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c46_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c46_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c46_info, c46_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c46_info, c46_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c46_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c46_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c46_info, sf_mex_duplicatearraysafe(&c46_lhs1), "lhs", "lhs",
                  1);
  sf_mex_destroy(&c46_rhs0);
  sf_mex_destroy(&c46_lhs0);
  sf_mex_destroy(&c46_rhs1);
  sf_mex_destroy(&c46_lhs1);
}

static const mxArray *c46_emlrt_marshallOut(const char * c46_d_u)
{
  const mxArray *c46_b_y = NULL;
  c46_b_y = NULL;
  sf_mex_assign(&c46_b_y, sf_mex_create("y", c46_d_u, 15, 0U, 0U, 0U, 2, 1,
    strlen(c46_d_u)), false);
  return c46_b_y;
}

static const mxArray *c46_b_emlrt_marshallOut(const uint32_T c46_d_u)
{
  const mxArray *c46_b_y = NULL;
  c46_b_y = NULL;
  sf_mex_assign(&c46_b_y, sf_mex_create("y", &c46_d_u, 7, 0U, 0U, 0U, 0), false);
  return c46_b_y;
}

static const mxArray *c46_d_sf_marshallOut(void *chartInstanceVoid, void
  *c46_c_inData)
{
  const mxArray *c46_mxArrayOutData = NULL;
  int32_T c46_d_u;
  const mxArray *c46_b_y = NULL;
  SFc46_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc46_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c46_mxArrayOutData = NULL;
  c46_d_u = *(int32_T *)c46_c_inData;
  c46_b_y = NULL;
  sf_mex_assign(&c46_b_y, sf_mex_create("y", &c46_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c46_mxArrayOutData, c46_b_y, false);
  return c46_mxArrayOutData;
}

static int32_T c46_d_emlrt_marshallIn(SFc46_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c46_d_u, const emlrtMsgIdentifier *c46_parentId)
{
  int32_T c46_b_y;
  int32_T c46_i33;
  (void)chartInstance;
  sf_mex_import(c46_parentId, sf_mex_dup(c46_d_u), &c46_i33, 1, 6, 0U, 0, 0U, 0);
  c46_b_y = c46_i33;
  sf_mex_destroy(&c46_d_u);
  return c46_b_y;
}

static void c46_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c46_mxArrayInData, const char_T *c46_varName, void *c46_outData)
{
  const mxArray *c46_b_sfEvent;
  const char_T *c46_identifier;
  emlrtMsgIdentifier c46_thisId;
  int32_T c46_b_y;
  SFc46_Experiment_1_csInstanceStruct *chartInstance;
  chartInstance = (SFc46_Experiment_1_csInstanceStruct *)chartInstanceVoid;
  c46_b_sfEvent = sf_mex_dup(c46_mxArrayInData);
  c46_identifier = c46_varName;
  c46_thisId.fIdentifier = c46_identifier;
  c46_thisId.fParent = NULL;
  c46_b_y = c46_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c46_b_sfEvent),
    &c46_thisId);
  sf_mex_destroy(&c46_b_sfEvent);
  *(int32_T *)c46_outData = c46_b_y;
  sf_mex_destroy(&c46_mxArrayInData);
}

static uint8_T c46_e_emlrt_marshallIn(SFc46_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c46_b_is_active_c46_Experiment_1_cs, const
  char_T *c46_identifier)
{
  uint8_T c46_b_y;
  emlrtMsgIdentifier c46_thisId;
  c46_thisId.fIdentifier = c46_identifier;
  c46_thisId.fParent = NULL;
  c46_b_y = c46_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c46_b_is_active_c46_Experiment_1_cs), &c46_thisId);
  sf_mex_destroy(&c46_b_is_active_c46_Experiment_1_cs);
  return c46_b_y;
}

static uint8_T c46_f_emlrt_marshallIn(SFc46_Experiment_1_csInstanceStruct
  *chartInstance, const mxArray *c46_d_u, const emlrtMsgIdentifier *c46_parentId)
{
  uint8_T c46_b_y;
  uint8_T c46_u0;
  (void)chartInstance;
  sf_mex_import(c46_parentId, sf_mex_dup(c46_d_u), &c46_u0, 1, 3, 0U, 0, 0U, 0);
  c46_b_y = c46_u0;
  sf_mex_destroy(&c46_d_u);
  return c46_b_y;
}

static void init_dsm_address_info(SFc46_Experiment_1_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc46_Experiment_1_csInstanceStruct
  *chartInstance)
{
  chartInstance->c46_b_Im = (real_T (*)[187500])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c46_b_Imout = (real_T (*)[562500])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
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

void sf_c46_Experiment_1_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1592139221U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(612990478U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3531237099U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(80902040U);
}

mxArray* sf_c46_Experiment_1_cs_get_post_codegen_info(void);
mxArray *sf_c46_Experiment_1_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("2SF4GFhEKzcKBM0HyrqCk");
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,3,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(375);
      pr[1] = (double)(500);
      pr[2] = (double)(3);
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
    mxArray* mxPostCodegenInfo = sf_c46_Experiment_1_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c46_Experiment_1_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c46_Experiment_1_cs_jit_fallback_info(void)
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

mxArray *sf_c46_Experiment_1_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c46_Experiment_1_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c46_Experiment_1_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Imout\",},{M[8],M[0],T\"is_active_c46_Experiment_1_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c46_Experiment_1_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc46_Experiment_1_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc46_Experiment_1_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_1_csMachineNumber_,
           46,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"Im");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Imout");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,91);

        {
          unsigned int dimVector[2];
          dimVector[0]= 375;
          dimVector[1]= 500;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c46_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[3];
          dimVector[0]= 375;
          dimVector[1]= 500;
          dimVector[2]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,3,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c46_sf_marshallOut,(MexInFcnForType)
            c46_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c46_b_Im);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c46_b_Imout);
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
  return "9tNtf84lyIkmaPeTe03iNG";
}

static void sf_opaque_initialize_c46_Experiment_1_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc46_Experiment_1_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c46_Experiment_1_cs((SFc46_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
  initialize_c46_Experiment_1_cs((SFc46_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c46_Experiment_1_cs(void *chartInstanceVar)
{
  enable_c46_Experiment_1_cs((SFc46_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c46_Experiment_1_cs(void *chartInstanceVar)
{
  disable_c46_Experiment_1_cs((SFc46_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c46_Experiment_1_cs(void *chartInstanceVar)
{
  sf_gateway_c46_Experiment_1_cs((SFc46_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c46_Experiment_1_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c46_Experiment_1_cs((SFc46_Experiment_1_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c46_Experiment_1_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c46_Experiment_1_cs((SFc46_Experiment_1_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c46_Experiment_1_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc46_Experiment_1_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_1_cs_optimization_info();
    }

    finalize_c46_Experiment_1_cs((SFc46_Experiment_1_csInstanceStruct*)
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
  initSimStructsc46_Experiment_1_cs((SFc46_Experiment_1_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c46_Experiment_1_cs(SimStruct *S)
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
    initialize_params_c46_Experiment_1_cs((SFc46_Experiment_1_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c46_Experiment_1_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Experiment_1_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      46);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,46,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,46,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,46);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,46,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,46,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,46);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1760677044U));
  ssSetChecksum1(S,(1724920135U));
  ssSetChecksum2(S,(2764468386U));
  ssSetChecksum3(S,(1944987740U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c46_Experiment_1_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c46_Experiment_1_cs(SimStruct *S)
{
  SFc46_Experiment_1_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc46_Experiment_1_csInstanceStruct *)utMalloc(sizeof
    (SFc46_Experiment_1_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc46_Experiment_1_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c46_Experiment_1_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c46_Experiment_1_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c46_Experiment_1_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c46_Experiment_1_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c46_Experiment_1_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c46_Experiment_1_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c46_Experiment_1_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c46_Experiment_1_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c46_Experiment_1_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c46_Experiment_1_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c46_Experiment_1_cs;
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

void c46_Experiment_1_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c46_Experiment_1_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c46_Experiment_1_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c46_Experiment_1_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c46_Experiment_1_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
