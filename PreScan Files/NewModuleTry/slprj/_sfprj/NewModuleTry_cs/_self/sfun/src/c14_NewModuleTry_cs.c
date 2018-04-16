/* Include files */

#include <stddef.h>
#include "blas.h"
#include "NewModuleTry_cs_sfun.h"
#include "c14_NewModuleTry_cs.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "NewModuleTry_cs_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c14_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

/* Function Declarations */
static void initialize_c14_NewModuleTry_cs(SFc14_NewModuleTry_csInstanceStruct
  *chartInstance);
static void initialize_params_c14_NewModuleTry_cs
  (SFc14_NewModuleTry_csInstanceStruct *chartInstance);
static void enable_c14_NewModuleTry_cs(SFc14_NewModuleTry_csInstanceStruct
  *chartInstance);
static void disable_c14_NewModuleTry_cs(SFc14_NewModuleTry_csInstanceStruct
  *chartInstance);
static void c14_update_debugger_state_c14_NewModuleTry_cs
  (SFc14_NewModuleTry_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c14_NewModuleTry_cs
  (SFc14_NewModuleTry_csInstanceStruct *chartInstance);
static void set_sim_state_c14_NewModuleTry_cs
  (SFc14_NewModuleTry_csInstanceStruct *chartInstance, const mxArray *c14_st);
static void finalize_c14_NewModuleTry_cs(SFc14_NewModuleTry_csInstanceStruct
  *chartInstance);
static void sf_gateway_c14_NewModuleTry_cs(SFc14_NewModuleTry_csInstanceStruct
  *chartInstance);
static void mdl_start_c14_NewModuleTry_cs(SFc14_NewModuleTry_csInstanceStruct
  *chartInstance);
static void initSimStructsc14_NewModuleTry_cs
  (SFc14_NewModuleTry_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber, uint32_T c14_instanceNumber);
static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static void c14_emlrt_marshallIn(SFc14_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c14_b_y, const char_T *c14_identifier, int32_T
  c14_c_y[200]);
static void c14_b_emlrt_marshallIn(SFc14_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c14_b_u, const emlrtMsgIdentifier *c14_parentId,
  int32_T c14_b_y[200]);
static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static const mxArray *c14_c_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static real_T c14_c_emlrt_marshallIn(SFc14_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c14_b_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_d_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static int32_T c14_d_emlrt_marshallIn(SFc14_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c14_b_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static uint8_T c14_e_emlrt_marshallIn(SFc14_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c14_b_is_active_c14_NewModuleTry_cs, const
  char_T *c14_identifier);
static uint8_T c14_f_emlrt_marshallIn(SFc14_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c14_b_u, const emlrtMsgIdentifier *c14_parentId);
static void init_dsm_address_info(SFc14_NewModuleTry_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc14_NewModuleTry_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c14_NewModuleTry_cs(SFc14_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  chartInstance->c14_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c14_is_active_c14_NewModuleTry_cs = 0U;
}

static void initialize_params_c14_NewModuleTry_cs
  (SFc14_NewModuleTry_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c14_NewModuleTry_cs(SFc14_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c14_NewModuleTry_cs(SFc14_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c14_update_debugger_state_c14_NewModuleTry_cs
  (SFc14_NewModuleTry_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c14_NewModuleTry_cs
  (SFc14_NewModuleTry_csInstanceStruct *chartInstance)
{
  const mxArray *c14_st;
  const mxArray *c14_b_y = NULL;
  int32_T c14_i0;
  int32_T c14_b_u[200];
  const mxArray *c14_c_y = NULL;
  uint8_T c14_hoistedGlobal;
  uint8_T c14_c_u;
  const mxArray *c14_d_y = NULL;
  c14_st = NULL;
  c14_st = NULL;
  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_createcellmatrix(2, 1), false);
  for (c14_i0 = 0; c14_i0 < 200; c14_i0++) {
    c14_b_u[c14_i0] = (*chartInstance->c14_y)[c14_i0];
  }

  c14_c_y = NULL;
  sf_mex_assign(&c14_c_y, sf_mex_create("y", c14_b_u, 6, 0U, 1U, 0U, 2, 2, 100),
                false);
  sf_mex_setcell(c14_b_y, 0, c14_c_y);
  c14_hoistedGlobal = chartInstance->c14_is_active_c14_NewModuleTry_cs;
  c14_c_u = c14_hoistedGlobal;
  c14_d_y = NULL;
  sf_mex_assign(&c14_d_y, sf_mex_create("y", &c14_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_b_y, 1, c14_d_y);
  sf_mex_assign(&c14_st, c14_b_y, false);
  return c14_st;
}

static void set_sim_state_c14_NewModuleTry_cs
  (SFc14_NewModuleTry_csInstanceStruct *chartInstance, const mxArray *c14_st)
{
  const mxArray *c14_b_u;
  int32_T c14_iv0[200];
  int32_T c14_i1;
  chartInstance->c14_doneDoubleBufferReInit = true;
  c14_b_u = sf_mex_dup(c14_st);
  c14_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c14_b_u, 0)),
                       "y", c14_iv0);
  for (c14_i1 = 0; c14_i1 < 200; c14_i1++) {
    (*chartInstance->c14_y)[c14_i1] = c14_iv0[c14_i1];
  }

  chartInstance->c14_is_active_c14_NewModuleTry_cs = c14_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c14_b_u, 1)),
     "is_active_c14_NewModuleTry_cs");
  sf_mex_destroy(&c14_b_u);
  c14_update_debugger_state_c14_NewModuleTry_cs(chartInstance);
  sf_mex_destroy(&c14_st);
}

static void finalize_c14_NewModuleTry_cs(SFc14_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c14_NewModuleTry_cs(SFc14_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  int32_T c14_i2;
  int32_T c14_i3;
  int32_T c14_b_u[400];
  uint32_T c14_debug_family_var_map[4];
  real_T c14_nargin = 1.0;
  real_T c14_nargout = 1.0;
  int32_T c14_b_y[200];
  int32_T c14_i4;
  int32_T c14_i5;
  int32_T c14_i6;
  int32_T c14_i7;
  int32_T c14_i8;
  int32_T c14_i9;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 13U, chartInstance->c14_sfEvent);
  for (c14_i2 = 0; c14_i2 < 400; c14_i2++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c14_u)[c14_i2], 0U);
  }

  chartInstance->c14_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 13U, chartInstance->c14_sfEvent);
  for (c14_i3 = 0; c14_i3 < 400; c14_i3++) {
    c14_b_u[c14_i3] = (*chartInstance->c14_u)[c14_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c14_debug_family_names,
    c14_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_nargin, 0U, c14_c_sf_marshallOut,
    c14_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_nargout, 1U, c14_c_sf_marshallOut,
    c14_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c14_b_u, 2U, c14_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c14_b_y, 3U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 4);
  c14_i4 = 0;
  c14_i5 = 0;
  for (c14_i6 = 0; c14_i6 < 100; c14_i6++) {
    for (c14_i7 = 0; c14_i7 < 2; c14_i7++) {
      c14_b_y[c14_i7 + c14_i4] = c14_b_u[c14_i7 + c14_i5];
    }

    c14_i4 += 2;
    c14_i5 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  for (c14_i8 = 0; c14_i8 < 200; c14_i8++) {
    (*chartInstance->c14_y)[c14_i8] = c14_b_y[c14_i8];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c14_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_NewModuleTry_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c14_i9 = 0; c14_i9 < 200; c14_i9++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c14_y)[c14_i9], 1U);
  }
}

static void mdl_start_c14_NewModuleTry_cs(SFc14_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc14_NewModuleTry_cs
  (SFc14_NewModuleTry_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber, uint32_T c14_instanceNumber)
{
  (void)c14_machineNumber;
  (void)c14_chartNumber;
  (void)c14_instanceNumber;
}

static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_i10;
  int32_T c14_i11;
  int32_T c14_i12;
  int32_T c14_b_inData[200];
  int32_T c14_i13;
  int32_T c14_i14;
  int32_T c14_i15;
  int32_T c14_b_u[200];
  const mxArray *c14_b_y = NULL;
  SFc14_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc14_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_i10 = 0;
  for (c14_i11 = 0; c14_i11 < 100; c14_i11++) {
    for (c14_i12 = 0; c14_i12 < 2; c14_i12++) {
      c14_b_inData[c14_i12 + c14_i10] = (*(int32_T (*)[200])c14_inData)[c14_i12
        + c14_i10];
    }

    c14_i10 += 2;
  }

  c14_i13 = 0;
  for (c14_i14 = 0; c14_i14 < 100; c14_i14++) {
    for (c14_i15 = 0; c14_i15 < 2; c14_i15++) {
      c14_b_u[c14_i15 + c14_i13] = c14_b_inData[c14_i15 + c14_i13];
    }

    c14_i13 += 2;
  }

  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", c14_b_u, 6, 0U, 1U, 0U, 2, 2, 100),
                false);
  sf_mex_assign(&c14_mxArrayOutData, c14_b_y, false);
  return c14_mxArrayOutData;
}

static void c14_emlrt_marshallIn(SFc14_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c14_b_y, const char_T *c14_identifier, int32_T
  c14_c_y[200])
{
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_y), &c14_thisId,
    c14_c_y);
  sf_mex_destroy(&c14_b_y);
}

static void c14_b_emlrt_marshallIn(SFc14_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c14_b_u, const emlrtMsgIdentifier *c14_parentId,
  int32_T c14_b_y[200])
{
  int32_T c14_iv1[200];
  int32_T c14_i16;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_b_u), c14_iv1, 1, 6, 0U, 1, 0U, 2,
                2, 100);
  for (c14_i16 = 0; c14_i16 < 200; c14_i16++) {
    c14_b_y[c14_i16] = c14_iv1[c14_i16];
  }

  sf_mex_destroy(&c14_b_u);
}

static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_b_y;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  int32_T c14_c_y[200];
  int32_T c14_i17;
  int32_T c14_i18;
  int32_T c14_i19;
  SFc14_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc14_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c14_b_y = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_y), &c14_thisId,
    c14_c_y);
  sf_mex_destroy(&c14_b_y);
  c14_i17 = 0;
  for (c14_i18 = 0; c14_i18 < 100; c14_i18++) {
    for (c14_i19 = 0; c14_i19 < 2; c14_i19++) {
      (*(int32_T (*)[200])c14_outData)[c14_i19 + c14_i17] = c14_c_y[c14_i19 +
        c14_i17];
    }

    c14_i17 += 2;
  }

  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_i20;
  int32_T c14_i21;
  int32_T c14_i22;
  int32_T c14_b_inData[400];
  int32_T c14_i23;
  int32_T c14_i24;
  int32_T c14_i25;
  int32_T c14_b_u[400];
  const mxArray *c14_b_y = NULL;
  SFc14_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc14_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_i20 = 0;
  for (c14_i21 = 0; c14_i21 < 100; c14_i21++) {
    for (c14_i22 = 0; c14_i22 < 4; c14_i22++) {
      c14_b_inData[c14_i22 + c14_i20] = (*(int32_T (*)[400])c14_inData)[c14_i22
        + c14_i20];
    }

    c14_i20 += 4;
  }

  c14_i23 = 0;
  for (c14_i24 = 0; c14_i24 < 100; c14_i24++) {
    for (c14_i25 = 0; c14_i25 < 4; c14_i25++) {
      c14_b_u[c14_i25 + c14_i23] = c14_b_inData[c14_i25 + c14_i23];
    }

    c14_i23 += 4;
  }

  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", c14_b_u, 6, 0U, 1U, 0U, 2, 4, 100),
                false);
  sf_mex_assign(&c14_mxArrayOutData, c14_b_y, false);
  return c14_mxArrayOutData;
}

static const mxArray *c14_c_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  real_T c14_b_u;
  const mxArray *c14_b_y = NULL;
  SFc14_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc14_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_b_u = *(real_T *)c14_inData;
  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", &c14_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_b_y, false);
  return c14_mxArrayOutData;
}

static real_T c14_c_emlrt_marshallIn(SFc14_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c14_b_u, const emlrtMsgIdentifier *c14_parentId)
{
  real_T c14_b_y;
  real_T c14_d0;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_b_u), &c14_d0, 1, 0, 0U, 0, 0U, 0);
  c14_b_y = c14_d0;
  sf_mex_destroy(&c14_b_u);
  return c14_b_y;
}

static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_nargout;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_b_y;
  SFc14_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc14_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c14_nargout = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_b_y = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_nargout),
    &c14_thisId);
  sf_mex_destroy(&c14_nargout);
  *(real_T *)c14_outData = c14_b_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

const mxArray *sf_c14_NewModuleTry_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c14_nameCaptureInfo = NULL;
  c14_nameCaptureInfo = NULL;
  sf_mex_assign(&c14_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c14_nameCaptureInfo;
}

static const mxArray *c14_d_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_b_u;
  const mxArray *c14_b_y = NULL;
  SFc14_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc14_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_b_u = *(int32_T *)c14_inData;
  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", &c14_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_b_y, false);
  return c14_mxArrayOutData;
}

static int32_T c14_d_emlrt_marshallIn(SFc14_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c14_b_u, const emlrtMsgIdentifier *c14_parentId)
{
  int32_T c14_b_y;
  int32_T c14_i26;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_b_u), &c14_i26, 1, 6, 0U, 0, 0U, 0);
  c14_b_y = c14_i26;
  sf_mex_destroy(&c14_b_u);
  return c14_b_y;
}

static void c14_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_b_sfEvent;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  int32_T c14_b_y;
  SFc14_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc14_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c14_b_sfEvent = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_b_y = c14_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_sfEvent),
    &c14_thisId);
  sf_mex_destroy(&c14_b_sfEvent);
  *(int32_T *)c14_outData = c14_b_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static uint8_T c14_e_emlrt_marshallIn(SFc14_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c14_b_is_active_c14_NewModuleTry_cs, const
  char_T *c14_identifier)
{
  uint8_T c14_b_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_b_y = c14_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c14_b_is_active_c14_NewModuleTry_cs), &c14_thisId);
  sf_mex_destroy(&c14_b_is_active_c14_NewModuleTry_cs);
  return c14_b_y;
}

static uint8_T c14_f_emlrt_marshallIn(SFc14_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c14_b_u, const emlrtMsgIdentifier *c14_parentId)
{
  uint8_T c14_b_y;
  uint8_T c14_u0;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_b_u), &c14_u0, 1, 3, 0U, 0, 0U, 0);
  c14_b_y = c14_u0;
  sf_mex_destroy(&c14_b_u);
  return c14_b_y;
}

static void init_dsm_address_info(SFc14_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc14_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  chartInstance->c14_u = (int32_T (*)[400])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c14_y = (int32_T (*)[200])ssGetOutputPortSignal_wrapper
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

void sf_c14_NewModuleTry_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(61254500U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(645872721U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1557291692U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3486020108U);
}

mxArray* sf_c14_NewModuleTry_cs_get_post_codegen_info(void);
mxArray *sf_c14_NewModuleTry_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("7aw7HQge2b4moJtxRIqVSD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c14_NewModuleTry_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c14_NewModuleTry_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c14_NewModuleTry_cs_jit_fallback_info(void)
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

mxArray *sf_c14_NewModuleTry_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c14_NewModuleTry_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c14_NewModuleTry_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c14_NewModuleTry_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c14_NewModuleTry_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc14_NewModuleTry_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc14_NewModuleTry_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _NewModuleTry_csMachineNumber_,
           14,
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
        init_script_number_translation(_NewModuleTry_csMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_NewModuleTry_csMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _NewModuleTry_csMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,45);

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 100;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c14_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 100;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c14_sf_marshallOut,(MexInFcnForType)
            c14_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c14_u);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c14_y);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _NewModuleTry_csMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "en4u5SC2JsFFhR6WdpyaqF";
}

static void sf_opaque_initialize_c14_NewModuleTry_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc14_NewModuleTry_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c14_NewModuleTry_cs((SFc14_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
  initialize_c14_NewModuleTry_cs((SFc14_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c14_NewModuleTry_cs(void *chartInstanceVar)
{
  enable_c14_NewModuleTry_cs((SFc14_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c14_NewModuleTry_cs(void *chartInstanceVar)
{
  disable_c14_NewModuleTry_cs((SFc14_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c14_NewModuleTry_cs(void *chartInstanceVar)
{
  sf_gateway_c14_NewModuleTry_cs((SFc14_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c14_NewModuleTry_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c14_NewModuleTry_cs((SFc14_NewModuleTry_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c14_NewModuleTry_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c14_NewModuleTry_cs((SFc14_NewModuleTry_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c14_NewModuleTry_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc14_NewModuleTry_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_NewModuleTry_cs_optimization_info();
    }

    finalize_c14_NewModuleTry_cs((SFc14_NewModuleTry_csInstanceStruct*)
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
  initSimStructsc14_NewModuleTry_cs((SFc14_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c14_NewModuleTry_cs(SimStruct *S)
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
    initialize_params_c14_NewModuleTry_cs((SFc14_NewModuleTry_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c14_NewModuleTry_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_NewModuleTry_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      14);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,14,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,14,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,14);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,14,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,14,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,14);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(992351787U));
  ssSetChecksum1(S,(3930284762U));
  ssSetChecksum2(S,(3699185625U));
  ssSetChecksum3(S,(1847008428U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c14_NewModuleTry_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c14_NewModuleTry_cs(SimStruct *S)
{
  SFc14_NewModuleTry_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc14_NewModuleTry_csInstanceStruct *)utMalloc(sizeof
    (SFc14_NewModuleTry_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc14_NewModuleTry_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c14_NewModuleTry_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c14_NewModuleTry_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c14_NewModuleTry_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c14_NewModuleTry_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c14_NewModuleTry_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c14_NewModuleTry_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c14_NewModuleTry_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c14_NewModuleTry_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c14_NewModuleTry_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c14_NewModuleTry_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c14_NewModuleTry_cs;
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

void c14_NewModuleTry_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c14_NewModuleTry_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c14_NewModuleTry_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c14_NewModuleTry_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c14_NewModuleTry_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
