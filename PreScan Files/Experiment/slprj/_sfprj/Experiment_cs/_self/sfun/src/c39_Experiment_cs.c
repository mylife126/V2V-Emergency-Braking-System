/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_cs_sfun.h"
#include "c39_Experiment_cs.h"
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
static const char * c39_debug_family_names[4] = { "nargin", "nargout", "Im",
  "Imout" };

/* Function Declarations */
static void initialize_c39_Experiment_cs(SFc39_Experiment_csInstanceStruct
  *chartInstance);
static void initialize_params_c39_Experiment_cs
  (SFc39_Experiment_csInstanceStruct *chartInstance);
static void enable_c39_Experiment_cs(SFc39_Experiment_csInstanceStruct
  *chartInstance);
static void disable_c39_Experiment_cs(SFc39_Experiment_csInstanceStruct
  *chartInstance);
static void c39_update_debugger_state_c39_Experiment_cs
  (SFc39_Experiment_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c39_Experiment_cs
  (SFc39_Experiment_csInstanceStruct *chartInstance);
static void set_sim_state_c39_Experiment_cs(SFc39_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c39_st);
static void finalize_c39_Experiment_cs(SFc39_Experiment_csInstanceStruct
  *chartInstance);
static void sf_gateway_c39_Experiment_cs(SFc39_Experiment_csInstanceStruct
  *chartInstance);
static void mdl_start_c39_Experiment_cs(SFc39_Experiment_csInstanceStruct
  *chartInstance);
static void initSimStructsc39_Experiment_cs(SFc39_Experiment_csInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c39_machineNumber, uint32_T
  c39_chartNumber, uint32_T c39_instanceNumber);
static const mxArray *c39_sf_marshallOut(void *chartInstanceVoid, void
  *c39_c_inData);
static void c39_emlrt_marshallIn(SFc39_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c39_c_Imout, const char_T *c39_identifier,
  real_T c39_b_y[562500]);
static void c39_b_emlrt_marshallIn(SFc39_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c39_d_u, const emlrtMsgIdentifier *c39_parentId,
  real_T c39_b_y[562500]);
static void c39_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c39_mxArrayInData, const char_T *c39_varName, void *c39_outData);
static const mxArray *c39_b_sf_marshallOut(void *chartInstanceVoid, void
  *c39_c_inData);
static const mxArray *c39_c_sf_marshallOut(void *chartInstanceVoid, void
  *c39_c_inData);
static real_T c39_c_emlrt_marshallIn(SFc39_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c39_d_u, const emlrtMsgIdentifier *c39_parentId);
static void c39_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c39_mxArrayInData, const char_T *c39_varName, void *c39_outData);
static void c39_info_helper(const mxArray **c39_info);
static const mxArray *c39_emlrt_marshallOut(const char * c39_d_u);
static const mxArray *c39_b_emlrt_marshallOut(const uint32_T c39_d_u);
static const mxArray *c39_d_sf_marshallOut(void *chartInstanceVoid, void
  *c39_c_inData);
static int32_T c39_d_emlrt_marshallIn(SFc39_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c39_d_u, const emlrtMsgIdentifier *c39_parentId);
static void c39_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c39_mxArrayInData, const char_T *c39_varName, void *c39_outData);
static uint8_T c39_e_emlrt_marshallIn(SFc39_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c39_b_is_active_c39_Experiment_cs, const char_T
  *c39_identifier);
static uint8_T c39_f_emlrt_marshallIn(SFc39_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c39_d_u, const emlrtMsgIdentifier *c39_parentId);
static void init_dsm_address_info(SFc39_Experiment_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc39_Experiment_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c39_Experiment_cs(SFc39_Experiment_csInstanceStruct
  *chartInstance)
{
  chartInstance->c39_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c39_is_active_c39_Experiment_cs = 0U;
}

static void initialize_params_c39_Experiment_cs
  (SFc39_Experiment_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c39_Experiment_cs(SFc39_Experiment_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c39_Experiment_cs(SFc39_Experiment_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c39_update_debugger_state_c39_Experiment_cs
  (SFc39_Experiment_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c39_Experiment_cs
  (SFc39_Experiment_csInstanceStruct *chartInstance)
{
  const mxArray *c39_st;
  const mxArray *c39_b_y = NULL;
  int32_T c39_i0;
  const mxArray *c39_c_y = NULL;
  uint8_T c39_hoistedGlobal;
  uint8_T c39_d_u;
  const mxArray *c39_d_y = NULL;
  c39_st = NULL;
  c39_st = NULL;
  c39_b_y = NULL;
  sf_mex_assign(&c39_b_y, sf_mex_createcellmatrix(2, 1), false);
  for (c39_i0 = 0; c39_i0 < 562500; c39_i0++) {
    chartInstance->c39_b_u[c39_i0] = (*chartInstance->c39_b_Imout)[c39_i0];
  }

  c39_c_y = NULL;
  sf_mex_assign(&c39_c_y, sf_mex_create("y", chartInstance->c39_b_u, 0, 0U, 1U,
    0U, 3, 375, 500, 3), false);
  sf_mex_setcell(c39_b_y, 0, c39_c_y);
  c39_hoistedGlobal = chartInstance->c39_is_active_c39_Experiment_cs;
  c39_d_u = c39_hoistedGlobal;
  c39_d_y = NULL;
  sf_mex_assign(&c39_d_y, sf_mex_create("y", &c39_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c39_b_y, 1, c39_d_y);
  sf_mex_assign(&c39_st, c39_b_y, false);
  return c39_st;
}

static void set_sim_state_c39_Experiment_cs(SFc39_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c39_st)
{
  const mxArray *c39_d_u;
  int32_T c39_i1;
  chartInstance->c39_doneDoubleBufferReInit = true;
  c39_d_u = sf_mex_dup(c39_st);
  c39_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c39_d_u, 0)),
                       "Imout", chartInstance->c39_dv0);
  for (c39_i1 = 0; c39_i1 < 562500; c39_i1++) {
    (*chartInstance->c39_b_Imout)[c39_i1] = chartInstance->c39_dv0[c39_i1];
  }

  chartInstance->c39_is_active_c39_Experiment_cs = c39_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c39_d_u, 1)),
     "is_active_c39_Experiment_cs");
  sf_mex_destroy(&c39_d_u);
  c39_update_debugger_state_c39_Experiment_cs(chartInstance);
  sf_mex_destroy(&c39_st);
}

static void finalize_c39_Experiment_cs(SFc39_Experiment_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c39_Experiment_cs(SFc39_Experiment_csInstanceStruct
  *chartInstance)
{
  int32_T c39_i2;
  int32_T c39_i3;
  uint32_T c39_debug_family_var_map[4];
  real_T c39_nargin = 1.0;
  real_T c39_nargout = 1.0;
  int32_T c39_i4;
  int32_T c39_i5;
  int32_T c39_i6;
  int32_T c39_i7;
  int32_T c39_i8;
  int32_T c39_i9;
  int32_T c39_i10;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 38U, chartInstance->c39_sfEvent);
  for (c39_i2 = 0; c39_i2 < 187500; c39_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c39_b_Im)[c39_i2], 0U);
  }

  chartInstance->c39_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 38U, chartInstance->c39_sfEvent);
  for (c39_i3 = 0; c39_i3 < 187500; c39_i3++) {
    chartInstance->c39_Im[c39_i3] = (*chartInstance->c39_b_Im)[c39_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c39_debug_family_names,
    c39_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c39_nargin, 0U, c39_c_sf_marshallOut,
    c39_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c39_nargout, 1U, c39_c_sf_marshallOut,
    c39_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c39_Im, 2U, c39_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c39_Imout, 3U,
    c39_sf_marshallOut, c39_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c39_sfEvent, 3);
  for (c39_i4 = 0; c39_i4 < 562500; c39_i4++) {
    chartInstance->c39_b[c39_i4] = 1.0;
  }

  for (c39_i5 = 0; c39_i5 < 562500; c39_i5++) {
    chartInstance->c39_Imout[c39_i5] = 128.0 * chartInstance->c39_b[c39_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c39_sfEvent, 4);
  c39_i6 = 0;
  for (c39_i7 = 0; c39_i7 < 500; c39_i7++) {
    for (c39_i8 = 0; c39_i8 < 375; c39_i8++) {
      chartInstance->c39_Imout[c39_i8 + c39_i6] = chartInstance->c39_Im[c39_i8 +
        c39_i6];
    }

    c39_i6 += 375;
  }

  _SFD_EML_CALL(0U, chartInstance->c39_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  for (c39_i9 = 0; c39_i9 < 562500; c39_i9++) {
    (*chartInstance->c39_b_Imout)[c39_i9] = chartInstance->c39_Imout[c39_i9];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 38U, chartInstance->c39_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c39_i10 = 0; c39_i10 < 562500; c39_i10++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c39_b_Imout)[c39_i10], 1U);
  }
}

static void mdl_start_c39_Experiment_cs(SFc39_Experiment_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc39_Experiment_cs(SFc39_Experiment_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c39_machineNumber, uint32_T
  c39_chartNumber, uint32_T c39_instanceNumber)
{
  (void)c39_machineNumber;
  (void)c39_chartNumber;
  (void)c39_instanceNumber;
}

static const mxArray *c39_sf_marshallOut(void *chartInstanceVoid, void
  *c39_c_inData)
{
  const mxArray *c39_mxArrayOutData = NULL;
  int32_T c39_i11;
  int32_T c39_i12;
  int32_T c39_i13;
  int32_T c39_i14;
  int32_T c39_i15;
  int32_T c39_i16;
  int32_T c39_i17;
  int32_T c39_i18;
  int32_T c39_i19;
  int32_T c39_i20;
  const mxArray *c39_b_y = NULL;
  SFc39_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc39_Experiment_csInstanceStruct *)chartInstanceVoid;
  c39_mxArrayOutData = NULL;
  c39_i11 = 0;
  for (c39_i12 = 0; c39_i12 < 3; c39_i12++) {
    c39_i13 = 0;
    for (c39_i14 = 0; c39_i14 < 500; c39_i14++) {
      for (c39_i15 = 0; c39_i15 < 375; c39_i15++) {
        chartInstance->c39_inData[(c39_i15 + c39_i13) + c39_i11] = (*(real_T (*)
          [562500])c39_c_inData)[(c39_i15 + c39_i13) + c39_i11];
      }

      c39_i13 += 375;
    }

    c39_i11 += 187500;
  }

  c39_i16 = 0;
  for (c39_i17 = 0; c39_i17 < 3; c39_i17++) {
    c39_i18 = 0;
    for (c39_i19 = 0; c39_i19 < 500; c39_i19++) {
      for (c39_i20 = 0; c39_i20 < 375; c39_i20++) {
        chartInstance->c39_u[(c39_i20 + c39_i18) + c39_i16] =
          chartInstance->c39_inData[(c39_i20 + c39_i18) + c39_i16];
      }

      c39_i18 += 375;
    }

    c39_i16 += 187500;
  }

  c39_b_y = NULL;
  sf_mex_assign(&c39_b_y, sf_mex_create("y", chartInstance->c39_u, 0, 0U, 1U, 0U,
    3, 375, 500, 3), false);
  sf_mex_assign(&c39_mxArrayOutData, c39_b_y, false);
  return c39_mxArrayOutData;
}

static void c39_emlrt_marshallIn(SFc39_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c39_c_Imout, const char_T *c39_identifier,
  real_T c39_b_y[562500])
{
  emlrtMsgIdentifier c39_thisId;
  c39_thisId.fIdentifier = c39_identifier;
  c39_thisId.fParent = NULL;
  c39_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c39_c_Imout), &c39_thisId,
    c39_b_y);
  sf_mex_destroy(&c39_c_Imout);
}

static void c39_b_emlrt_marshallIn(SFc39_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c39_d_u, const emlrtMsgIdentifier *c39_parentId,
  real_T c39_b_y[562500])
{
  int32_T c39_i21;
  sf_mex_import(c39_parentId, sf_mex_dup(c39_d_u), chartInstance->c39_dv1, 1, 0,
                0U, 1, 0U, 3, 375, 500, 3);
  for (c39_i21 = 0; c39_i21 < 562500; c39_i21++) {
    c39_b_y[c39_i21] = chartInstance->c39_dv1[c39_i21];
  }

  sf_mex_destroy(&c39_d_u);
}

static void c39_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c39_mxArrayInData, const char_T *c39_varName, void *c39_outData)
{
  const mxArray *c39_c_Imout;
  const char_T *c39_identifier;
  emlrtMsgIdentifier c39_thisId;
  int32_T c39_i22;
  int32_T c39_i23;
  int32_T c39_i24;
  int32_T c39_i25;
  int32_T c39_i26;
  SFc39_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc39_Experiment_csInstanceStruct *)chartInstanceVoid;
  c39_c_Imout = sf_mex_dup(c39_mxArrayInData);
  c39_identifier = c39_varName;
  c39_thisId.fIdentifier = c39_identifier;
  c39_thisId.fParent = NULL;
  c39_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c39_c_Imout), &c39_thisId,
    chartInstance->c39_y);
  sf_mex_destroy(&c39_c_Imout);
  c39_i22 = 0;
  for (c39_i23 = 0; c39_i23 < 3; c39_i23++) {
    c39_i24 = 0;
    for (c39_i25 = 0; c39_i25 < 500; c39_i25++) {
      for (c39_i26 = 0; c39_i26 < 375; c39_i26++) {
        (*(real_T (*)[562500])c39_outData)[(c39_i26 + c39_i24) + c39_i22] =
          chartInstance->c39_y[(c39_i26 + c39_i24) + c39_i22];
      }

      c39_i24 += 375;
    }

    c39_i22 += 187500;
  }

  sf_mex_destroy(&c39_mxArrayInData);
}

static const mxArray *c39_b_sf_marshallOut(void *chartInstanceVoid, void
  *c39_c_inData)
{
  const mxArray *c39_mxArrayOutData = NULL;
  int32_T c39_i27;
  int32_T c39_i28;
  int32_T c39_i29;
  int32_T c39_i30;
  int32_T c39_i31;
  int32_T c39_i32;
  const mxArray *c39_b_y = NULL;
  SFc39_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc39_Experiment_csInstanceStruct *)chartInstanceVoid;
  c39_mxArrayOutData = NULL;
  c39_i27 = 0;
  for (c39_i28 = 0; c39_i28 < 500; c39_i28++) {
    for (c39_i29 = 0; c39_i29 < 375; c39_i29++) {
      chartInstance->c39_b_inData[c39_i29 + c39_i27] = (*(real_T (*)[187500])
        c39_c_inData)[c39_i29 + c39_i27];
    }

    c39_i27 += 375;
  }

  c39_i30 = 0;
  for (c39_i31 = 0; c39_i31 < 500; c39_i31++) {
    for (c39_i32 = 0; c39_i32 < 375; c39_i32++) {
      chartInstance->c39_c_u[c39_i32 + c39_i30] = chartInstance->
        c39_b_inData[c39_i32 + c39_i30];
    }

    c39_i30 += 375;
  }

  c39_b_y = NULL;
  sf_mex_assign(&c39_b_y, sf_mex_create("y", chartInstance->c39_c_u, 0, 0U, 1U,
    0U, 2, 375, 500), false);
  sf_mex_assign(&c39_mxArrayOutData, c39_b_y, false);
  return c39_mxArrayOutData;
}

static const mxArray *c39_c_sf_marshallOut(void *chartInstanceVoid, void
  *c39_c_inData)
{
  const mxArray *c39_mxArrayOutData = NULL;
  real_T c39_d_u;
  const mxArray *c39_b_y = NULL;
  SFc39_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc39_Experiment_csInstanceStruct *)chartInstanceVoid;
  c39_mxArrayOutData = NULL;
  c39_d_u = *(real_T *)c39_c_inData;
  c39_b_y = NULL;
  sf_mex_assign(&c39_b_y, sf_mex_create("y", &c39_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c39_mxArrayOutData, c39_b_y, false);
  return c39_mxArrayOutData;
}

static real_T c39_c_emlrt_marshallIn(SFc39_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c39_d_u, const emlrtMsgIdentifier *c39_parentId)
{
  real_T c39_b_y;
  real_T c39_d0;
  (void)chartInstance;
  sf_mex_import(c39_parentId, sf_mex_dup(c39_d_u), &c39_d0, 1, 0, 0U, 0, 0U, 0);
  c39_b_y = c39_d0;
  sf_mex_destroy(&c39_d_u);
  return c39_b_y;
}

static void c39_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c39_mxArrayInData, const char_T *c39_varName, void *c39_outData)
{
  const mxArray *c39_nargout;
  const char_T *c39_identifier;
  emlrtMsgIdentifier c39_thisId;
  real_T c39_b_y;
  SFc39_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc39_Experiment_csInstanceStruct *)chartInstanceVoid;
  c39_nargout = sf_mex_dup(c39_mxArrayInData);
  c39_identifier = c39_varName;
  c39_thisId.fIdentifier = c39_identifier;
  c39_thisId.fParent = NULL;
  c39_b_y = c39_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c39_nargout),
    &c39_thisId);
  sf_mex_destroy(&c39_nargout);
  *(real_T *)c39_outData = c39_b_y;
  sf_mex_destroy(&c39_mxArrayInData);
}

const mxArray *sf_c39_Experiment_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c39_nameCaptureInfo = NULL;
  c39_nameCaptureInfo = NULL;
  sf_mex_assign(&c39_nameCaptureInfo, sf_mex_createstruct("structure", 2, 2, 1),
                false);
  c39_info_helper(&c39_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c39_nameCaptureInfo);
  return c39_nameCaptureInfo;
}

static void c39_info_helper(const mxArray **c39_info)
{
  const mxArray *c39_rhs0 = NULL;
  const mxArray *c39_lhs0 = NULL;
  const mxArray *c39_rhs1 = NULL;
  const mxArray *c39_lhs1 = NULL;
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 0);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c39_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c39_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c39_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c39_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_lhs1), "lhs", "lhs",
                  1);
  sf_mex_destroy(&c39_rhs0);
  sf_mex_destroy(&c39_lhs0);
  sf_mex_destroy(&c39_rhs1);
  sf_mex_destroy(&c39_lhs1);
}

static const mxArray *c39_emlrt_marshallOut(const char * c39_d_u)
{
  const mxArray *c39_b_y = NULL;
  c39_b_y = NULL;
  sf_mex_assign(&c39_b_y, sf_mex_create("y", c39_d_u, 15, 0U, 0U, 0U, 2, 1,
    strlen(c39_d_u)), false);
  return c39_b_y;
}

static const mxArray *c39_b_emlrt_marshallOut(const uint32_T c39_d_u)
{
  const mxArray *c39_b_y = NULL;
  c39_b_y = NULL;
  sf_mex_assign(&c39_b_y, sf_mex_create("y", &c39_d_u, 7, 0U, 0U, 0U, 0), false);
  return c39_b_y;
}

static const mxArray *c39_d_sf_marshallOut(void *chartInstanceVoid, void
  *c39_c_inData)
{
  const mxArray *c39_mxArrayOutData = NULL;
  int32_T c39_d_u;
  const mxArray *c39_b_y = NULL;
  SFc39_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc39_Experiment_csInstanceStruct *)chartInstanceVoid;
  c39_mxArrayOutData = NULL;
  c39_d_u = *(int32_T *)c39_c_inData;
  c39_b_y = NULL;
  sf_mex_assign(&c39_b_y, sf_mex_create("y", &c39_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c39_mxArrayOutData, c39_b_y, false);
  return c39_mxArrayOutData;
}

static int32_T c39_d_emlrt_marshallIn(SFc39_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c39_d_u, const emlrtMsgIdentifier *c39_parentId)
{
  int32_T c39_b_y;
  int32_T c39_i33;
  (void)chartInstance;
  sf_mex_import(c39_parentId, sf_mex_dup(c39_d_u), &c39_i33, 1, 6, 0U, 0, 0U, 0);
  c39_b_y = c39_i33;
  sf_mex_destroy(&c39_d_u);
  return c39_b_y;
}

static void c39_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c39_mxArrayInData, const char_T *c39_varName, void *c39_outData)
{
  const mxArray *c39_b_sfEvent;
  const char_T *c39_identifier;
  emlrtMsgIdentifier c39_thisId;
  int32_T c39_b_y;
  SFc39_Experiment_csInstanceStruct *chartInstance;
  chartInstance = (SFc39_Experiment_csInstanceStruct *)chartInstanceVoid;
  c39_b_sfEvent = sf_mex_dup(c39_mxArrayInData);
  c39_identifier = c39_varName;
  c39_thisId.fIdentifier = c39_identifier;
  c39_thisId.fParent = NULL;
  c39_b_y = c39_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c39_b_sfEvent),
    &c39_thisId);
  sf_mex_destroy(&c39_b_sfEvent);
  *(int32_T *)c39_outData = c39_b_y;
  sf_mex_destroy(&c39_mxArrayInData);
}

static uint8_T c39_e_emlrt_marshallIn(SFc39_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c39_b_is_active_c39_Experiment_cs, const char_T
  *c39_identifier)
{
  uint8_T c39_b_y;
  emlrtMsgIdentifier c39_thisId;
  c39_thisId.fIdentifier = c39_identifier;
  c39_thisId.fParent = NULL;
  c39_b_y = c39_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c39_b_is_active_c39_Experiment_cs), &c39_thisId);
  sf_mex_destroy(&c39_b_is_active_c39_Experiment_cs);
  return c39_b_y;
}

static uint8_T c39_f_emlrt_marshallIn(SFc39_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c39_d_u, const emlrtMsgIdentifier *c39_parentId)
{
  uint8_T c39_b_y;
  uint8_T c39_u0;
  (void)chartInstance;
  sf_mex_import(c39_parentId, sf_mex_dup(c39_d_u), &c39_u0, 1, 3, 0U, 0, 0U, 0);
  c39_b_y = c39_u0;
  sf_mex_destroy(&c39_d_u);
  return c39_b_y;
}

static void init_dsm_address_info(SFc39_Experiment_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc39_Experiment_csInstanceStruct
  *chartInstance)
{
  chartInstance->c39_b_Im = (real_T (*)[187500])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c39_b_Imout = (real_T (*)[562500])ssGetOutputPortSignal_wrapper
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

void sf_c39_Experiment_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1592139221U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(612990478U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3531237099U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(80902040U);
}

mxArray* sf_c39_Experiment_cs_get_post_codegen_info(void);
mxArray *sf_c39_Experiment_cs_get_autoinheritance_info(void)
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
    mxArray* mxPostCodegenInfo = sf_c39_Experiment_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c39_Experiment_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c39_Experiment_cs_jit_fallback_info(void)
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

mxArray *sf_c39_Experiment_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c39_Experiment_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c39_Experiment_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Imout\",},{M[8],M[0],T\"is_active_c39_Experiment_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c39_Experiment_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc39_Experiment_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc39_Experiment_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_csMachineNumber_,
           39,
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
            1.0,0,0,(MexFcnForType)c39_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[3];
          dimVector[0]= 375;
          dimVector[1]= 500;
          dimVector[2]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,3,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c39_sf_marshallOut,(MexInFcnForType)
            c39_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c39_b_Im);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c39_b_Imout);
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
  return "9tNtf84lyIkmaPeTe03iNG";
}

static void sf_opaque_initialize_c39_Experiment_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc39_Experiment_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c39_Experiment_cs((SFc39_Experiment_csInstanceStruct*)
    chartInstanceVar);
  initialize_c39_Experiment_cs((SFc39_Experiment_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c39_Experiment_cs(void *chartInstanceVar)
{
  enable_c39_Experiment_cs((SFc39_Experiment_csInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c39_Experiment_cs(void *chartInstanceVar)
{
  disable_c39_Experiment_cs((SFc39_Experiment_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c39_Experiment_cs(void *chartInstanceVar)
{
  sf_gateway_c39_Experiment_cs((SFc39_Experiment_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c39_Experiment_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c39_Experiment_cs((SFc39_Experiment_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c39_Experiment_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c39_Experiment_cs((SFc39_Experiment_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c39_Experiment_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc39_Experiment_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_cs_optimization_info();
    }

    finalize_c39_Experiment_cs((SFc39_Experiment_csInstanceStruct*)
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
  initSimStructsc39_Experiment_cs((SFc39_Experiment_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c39_Experiment_cs(SimStruct *S)
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
    initialize_params_c39_Experiment_cs((SFc39_Experiment_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c39_Experiment_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Experiment_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      39);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,39,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,39,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,39);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,39,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,39,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,39);
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

static void mdlRTW_c39_Experiment_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c39_Experiment_cs(SimStruct *S)
{
  SFc39_Experiment_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc39_Experiment_csInstanceStruct *)utMalloc(sizeof
    (SFc39_Experiment_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc39_Experiment_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c39_Experiment_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c39_Experiment_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c39_Experiment_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c39_Experiment_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c39_Experiment_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c39_Experiment_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c39_Experiment_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c39_Experiment_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c39_Experiment_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c39_Experiment_cs;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c39_Experiment_cs;
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

void c39_Experiment_cs_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c39_Experiment_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c39_Experiment_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c39_Experiment_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c39_Experiment_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
