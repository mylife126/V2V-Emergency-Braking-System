/* Include files */

#include <stddef.h>
#include "blas.h"
#include "PreScanUsefulBlocks_sfun.h"
#include "c6_PreScanUsefulBlocks.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "PreScanUsefulBlocks_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c6_debug_family_names[8] = { "MAX_OUTPUTS", "i", "index",
  "nargin", "nargout", "in", "IDs", "Detections" };

/* Function Declarations */
static void initialize_c6_PreScanUsefulBlocks
  (SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance);
static void initialize_params_c6_PreScanUsefulBlocks
  (SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance);
static void enable_c6_PreScanUsefulBlocks(SFc6_PreScanUsefulBlocksInstanceStruct
  *chartInstance);
static void disable_c6_PreScanUsefulBlocks
  (SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance);
static void c6_update_debugger_state_c6_PreScanUsefulBlocks
  (SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c6_PreScanUsefulBlocks
  (SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance);
static void set_sim_state_c6_PreScanUsefulBlocks
  (SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance, const mxArray *c6_st);
static void finalize_c6_PreScanUsefulBlocks
  (SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance);
static void sf_gateway_c6_PreScanUsefulBlocks
  (SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance);
static void mdl_start_c6_PreScanUsefulBlocks
  (SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance);
static void initSimStructsc6_PreScanUsefulBlocks
  (SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static void c6_emlrt_marshallIn(SFc6_PreScanUsefulBlocksInstanceStruct
  *chartInstance, const mxArray *c6_b_Detections, const char_T *c6_identifier,
  boolean_T c6_y[5]);
static void c6_b_emlrt_marshallIn(SFc6_PreScanUsefulBlocksInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  boolean_T c6_y[5]);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_c_emlrt_marshallIn(SFc6_PreScanUsefulBlocksInstanceStruct
  *chartInstance, const mxArray *c6_b_IDs, const char_T *c6_identifier, real_T
  c6_y[10]);
static void c6_d_emlrt_marshallIn(SFc6_PreScanUsefulBlocksInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[10]);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_e_emlrt_marshallIn(SFc6_PreScanUsefulBlocksInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static void c6_info_helper(const mxArray **c6_info);
static const mxArray *c6_emlrt_marshallOut(const char * c6_u);
static const mxArray *c6_b_emlrt_marshallOut(const uint32_T c6_u);
static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_f_emlrt_marshallIn(SFc6_PreScanUsefulBlocksInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_in_bus_io(void *chartInstanceVoid, void *c6_pData);
static uint8_T c6_g_emlrt_marshallIn(SFc6_PreScanUsefulBlocksInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_PreScanUsefulBlocks, const
  char_T *c6_identifier);
static uint8_T c6_h_emlrt_marshallIn(SFc6_PreScanUsefulBlocksInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void init_dsm_address_info(SFc6_PreScanUsefulBlocksInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc6_PreScanUsefulBlocksInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c6_PreScanUsefulBlocks
  (SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance)
{
  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c6_is_active_c6_PreScanUsefulBlocks = 0U;
}

static void initialize_params_c6_PreScanUsefulBlocks
  (SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c6_PreScanUsefulBlocks(SFc6_PreScanUsefulBlocksInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c6_PreScanUsefulBlocks
  (SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c6_update_debugger_state_c6_PreScanUsefulBlocks
  (SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c6_PreScanUsefulBlocks
  (SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  int32_T c6_i0;
  boolean_T c6_u[5];
  const mxArray *c6_b_y = NULL;
  int32_T c6_i1;
  real_T c6_b_u[10];
  const mxArray *c6_c_y = NULL;
  uint8_T c6_hoistedGlobal;
  uint8_T c6_c_u;
  const mxArray *c6_d_y = NULL;
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellmatrix(3, 1), false);
  for (c6_i0 = 0; c6_i0 < 5; c6_i0++) {
    c6_u[c6_i0] = (*chartInstance->c6_Detections)[c6_i0];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_u, 11, 0U, 1U, 0U, 1, 5), false);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  for (c6_i1 = 0; c6_i1 < 10; c6_i1++) {
    c6_b_u[c6_i1] = (*chartInstance->c6_IDs)[c6_i1];
  }

  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", c6_b_u, 0, 0U, 1U, 0U, 1, 10), false);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  c6_hoistedGlobal = chartInstance->c6_is_active_c6_PreScanUsefulBlocks;
  c6_c_u = c6_hoistedGlobal;
  c6_d_y = NULL;
  sf_mex_assign(&c6_d_y, sf_mex_create("y", &c6_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 2, c6_d_y);
  sf_mex_assign(&c6_st, c6_y, false);
  return c6_st;
}

static void set_sim_state_c6_PreScanUsefulBlocks
  (SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance, const mxArray *c6_st)
{
  const mxArray *c6_u;
  boolean_T c6_bv0[5];
  int32_T c6_i2;
  real_T c6_dv0[10];
  int32_T c6_i3;
  chartInstance->c6_doneDoubleBufferReInit = true;
  c6_u = sf_mex_dup(c6_st);
  c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 0)),
                      "Detections", c6_bv0);
  for (c6_i2 = 0; c6_i2 < 5; c6_i2++) {
    (*chartInstance->c6_Detections)[c6_i2] = c6_bv0[c6_i2];
  }

  c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 1)),
                        "IDs", c6_dv0);
  for (c6_i3 = 0; c6_i3 < 10; c6_i3++) {
    (*chartInstance->c6_IDs)[c6_i3] = c6_dv0[c6_i3];
  }

  chartInstance->c6_is_active_c6_PreScanUsefulBlocks = c6_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 2)),
     "is_active_c6_PreScanUsefulBlocks");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_PreScanUsefulBlocks(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_PreScanUsefulBlocks
  (SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c6_PreScanUsefulBlocks
  (SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance)
{
  PRESCAN_COLLISIONDETECTION_MESSAGE c6_b_in;
  uint32_T c6_debug_family_var_map[8];
  real_T c6_MAX_OUTPUTS;
  real_T c6_i;
  real_T c6_index;
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 2.0;
  real_T c6_b_IDs[10];
  boolean_T c6_b_Detections[5];
  int32_T c6_i4;
  int32_T c6_i5;
  int32_T c6_i6;
  int32_T c6_i7;
  int32_T c6_i8;
  int32_T c6_i9;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c6_sfEvent);
  chartInstance->c6_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c6_sfEvent);
  c6_b_in.HEADER.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    chartInstance->c6_in)[0])[0];
  c6_b_in.DATA.ObjectID1 = *(uint32_T *)&((char_T *)
    (PRESCAN_COLLISIONDETECTION_DATA *)&((char_T *)chartInstance->c6_in)[8])[0];
  c6_b_in.DATA.ObjectID2 = *(uint32_T *)&((char_T *)
    (PRESCAN_COLLISIONDETECTION_DATA *)&((char_T *)chartInstance->c6_in)[8])[4];
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c6_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_MAX_OUTPUTS, 0U, c6_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_i, 1U, c6_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_index, 2U, c6_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 3U, c6_d_sf_marshallOut,
    c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 4U, c6_d_sf_marshallOut,
    c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_b_in, 5U, c6_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_b_IDs, 6U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_b_Detections, 7U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_MAX_OUTPUTS = 5.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 6);
  for (c6_i4 = 0; c6_i4 < 10; c6_i4++) {
    c6_b_IDs[c6_i4] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 7);
  for (c6_i5 = 0; c6_i5 < 5; c6_i5++) {
    c6_b_Detections[c6_i5] = false;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 9);
  c6_i = 1.0;
  CV_EML_FOR(0, 1, 0, 1);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 10);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, (real_T)
        c6_b_in.HEADER.valid, 1.0, -1, 0U, (real_T)c6_b_in.HEADER.valid == 1.0)))
  {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 12);
    c6_index = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 13);
    c6_b_IDs[0] = (real_T)c6_b_in.DATA.ObjectID1;
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 14);
    c6_b_IDs[1] = (real_T)c6_b_in.DATA.ObjectID2;
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 16);
    c6_b_Detections[0] = true;
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -16);
  _SFD_SYMBOL_SCOPE_POP();
  for (c6_i6 = 0; c6_i6 < 10; c6_i6++) {
    (*chartInstance->c6_IDs)[c6_i6] = c6_b_IDs[c6_i6];
  }

  for (c6_i7 = 0; c6_i7 < 5; c6_i7++) {
    (*chartInstance->c6_Detections)[c6_i7] = c6_b_Detections[c6_i7];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c6_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_PreScanUsefulBlocksMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c6_i8 = 0; c6_i8 < 10; c6_i8++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c6_IDs)[c6_i8], 1U);
  }

  for (c6_i9 = 0; c6_i9 < 5; c6_i9++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c6_Detections)[c6_i9], 2U);
  }
}

static void mdl_start_c6_PreScanUsefulBlocks
  (SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc6_PreScanUsefulBlocks
  (SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber)
{
  (void)c6_machineNumber;
  (void)c6_chartNumber;
  (void)c6_instanceNumber;
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i10;
  boolean_T c6_b_inData[5];
  int32_T c6_i11;
  boolean_T c6_u[5];
  const mxArray *c6_y = NULL;
  SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance;
  chartInstance = (SFc6_PreScanUsefulBlocksInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i10 = 0; c6_i10 < 5; c6_i10++) {
    c6_b_inData[c6_i10] = (*(boolean_T (*)[5])c6_inData)[c6_i10];
  }

  for (c6_i11 = 0; c6_i11 < 5; c6_i11++) {
    c6_u[c6_i11] = c6_b_inData[c6_i11];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 11, 0U, 1U, 0U, 1, 5), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static void c6_emlrt_marshallIn(SFc6_PreScanUsefulBlocksInstanceStruct
  *chartInstance, const mxArray *c6_b_Detections, const char_T *c6_identifier,
  boolean_T c6_y[5])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_Detections), &c6_thisId,
                        c6_y);
  sf_mex_destroy(&c6_b_Detections);
}

static void c6_b_emlrt_marshallIn(SFc6_PreScanUsefulBlocksInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  boolean_T c6_y[5])
{
  boolean_T c6_bv1[5];
  int32_T c6_i12;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_bv1, 1, 11, 0U, 1, 0U, 1, 5);
  for (c6_i12 = 0; c6_i12 < 5; c6_i12++) {
    c6_y[c6_i12] = c6_bv1[c6_i12];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_Detections;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  boolean_T c6_y[5];
  int32_T c6_i13;
  SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance;
  chartInstance = (SFc6_PreScanUsefulBlocksInstanceStruct *)chartInstanceVoid;
  c6_b_Detections = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_Detections), &c6_thisId,
                        c6_y);
  sf_mex_destroy(&c6_b_Detections);
  for (c6_i13 = 0; c6_i13 < 5; c6_i13++) {
    (*(boolean_T (*)[5])c6_outData)[c6_i13] = c6_y[c6_i13];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i14;
  real_T c6_b_inData[10];
  int32_T c6_i15;
  real_T c6_u[10];
  const mxArray *c6_y = NULL;
  SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance;
  chartInstance = (SFc6_PreScanUsefulBlocksInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i14 = 0; c6_i14 < 10; c6_i14++) {
    c6_b_inData[c6_i14] = (*(real_T (*)[10])c6_inData)[c6_i14];
  }

  for (c6_i15 = 0; c6_i15 < 10; c6_i15++) {
    c6_u[c6_i15] = c6_b_inData[c6_i15];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 10), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static void c6_c_emlrt_marshallIn(SFc6_PreScanUsefulBlocksInstanceStruct
  *chartInstance, const mxArray *c6_b_IDs, const char_T *c6_identifier, real_T
  c6_y[10])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_IDs), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_b_IDs);
}

static void c6_d_emlrt_marshallIn(SFc6_PreScanUsefulBlocksInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[10])
{
  real_T c6_dv1[10];
  int32_T c6_i16;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv1, 1, 0, 0U, 1, 0U, 1, 10);
  for (c6_i16 = 0; c6_i16 < 10; c6_i16++) {
    c6_y[c6_i16] = c6_dv1[c6_i16];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_IDs;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[10];
  int32_T c6_i17;
  SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance;
  chartInstance = (SFc6_PreScanUsefulBlocksInstanceStruct *)chartInstanceVoid;
  c6_b_IDs = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_IDs), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_b_IDs);
  for (c6_i17 = 0; c6_i17 < 10; c6_i17++) {
    (*(real_T (*)[10])c6_outData)[c6_i17] = c6_y[c6_i17];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData;
  PRESCAN_COLLISIONDETECTION_MESSAGE c6_u;
  const mxArray *c6_y = NULL;
  PRESCAN_HEADER c6_b_u;
  const mxArray *c6_b_y = NULL;
  boolean_T c6_c_u;
  const mxArray *c6_c_y = NULL;
  PRESCAN_COLLISIONDETECTION_DATA c6_d_u;
  const mxArray *c6_d_y = NULL;
  uint32_T c6_e_u;
  const mxArray *c6_e_y = NULL;
  uint32_T c6_f_u;
  const mxArray *c6_f_y = NULL;
  SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance;
  chartInstance = (SFc6_PreScanUsefulBlocksInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_mxArrayOutData = NULL;
  c6_u = *(PRESCAN_COLLISIONDETECTION_MESSAGE *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c6_b_u = c6_u.HEADER;
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c6_c_u = c6_b_u.valid;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_c_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_b_y, c6_c_y, "valid", "valid", 0);
  sf_mex_addfield(c6_y, c6_b_y, "HEADER", "HEADER", 0);
  c6_d_u = c6_u.DATA;
  c6_d_y = NULL;
  sf_mex_assign(&c6_d_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c6_e_u = c6_d_u.ObjectID1;
  c6_e_y = NULL;
  sf_mex_assign(&c6_e_y, sf_mex_create("y", &c6_e_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_d_y, c6_e_y, "ObjectID1", "ObjectID1", 0);
  c6_f_u = c6_d_u.ObjectID2;
  c6_f_y = NULL;
  sf_mex_assign(&c6_f_y, sf_mex_create("y", &c6_f_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c6_d_y, c6_f_y, "ObjectID2", "ObjectID2", 0);
  sf_mex_addfield(c6_y, c6_d_y, "DATA", "DATA", 0);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance;
  chartInstance = (SFc6_PreScanUsefulBlocksInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static real_T c6_e_emlrt_marshallIn(SFc6_PreScanUsefulBlocksInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d0, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_nargout;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance;
  chartInstance = (SFc6_PreScanUsefulBlocksInstanceStruct *)chartInstanceVoid;
  c6_nargout = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_nargout), &c6_thisId);
  sf_mex_destroy(&c6_nargout);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

const mxArray *sf_c6_PreScanUsefulBlocks_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  sf_mex_assign(&c6_nameCaptureInfo, sf_mex_createstruct("structure", 2, 10, 1),
                false);
  c6_info_helper(&c6_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c6_nameCaptureInfo);
  return c6_nameCaptureInfo;
}

static void c6_info_helper(const mxArray **c6_info)
{
  const mxArray *c6_rhs0 = NULL;
  const mxArray *c6_lhs0 = NULL;
  const mxArray *c6_rhs1 = NULL;
  const mxArray *c6_lhs1 = NULL;
  const mxArray *c6_rhs2 = NULL;
  const mxArray *c6_lhs2 = NULL;
  const mxArray *c6_rhs3 = NULL;
  const mxArray *c6_lhs3 = NULL;
  const mxArray *c6_rhs4 = NULL;
  const mxArray *c6_lhs4 = NULL;
  const mxArray *c6_rhs5 = NULL;
  const mxArray *c6_lhs5 = NULL;
  const mxArray *c6_rhs6 = NULL;
  const mxArray *c6_lhs6 = NULL;
  const mxArray *c6_rhs7 = NULL;
  const mxArray *c6_lhs7 = NULL;
  const mxArray *c6_rhs8 = NULL;
  const mxArray *c6_lhs8 = NULL;
  const mxArray *c6_rhs9 = NULL;
  const mxArray *c6_lhs9 = NULL;
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("length"), "name", "name", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("struct"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1303167806U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c6_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("min"), "name", "name", 1);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1311276918U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c6_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 2);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1378317584U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c6_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 3);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c6_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 4);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c6_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 5);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 5);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c6_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 6);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c6_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 7);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 7);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c6_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 8);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 8);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c6_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 9);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 9);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c6_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs9), "lhs", "lhs", 9);
  sf_mex_destroy(&c6_rhs0);
  sf_mex_destroy(&c6_lhs0);
  sf_mex_destroy(&c6_rhs1);
  sf_mex_destroy(&c6_lhs1);
  sf_mex_destroy(&c6_rhs2);
  sf_mex_destroy(&c6_lhs2);
  sf_mex_destroy(&c6_rhs3);
  sf_mex_destroy(&c6_lhs3);
  sf_mex_destroy(&c6_rhs4);
  sf_mex_destroy(&c6_lhs4);
  sf_mex_destroy(&c6_rhs5);
  sf_mex_destroy(&c6_lhs5);
  sf_mex_destroy(&c6_rhs6);
  sf_mex_destroy(&c6_lhs6);
  sf_mex_destroy(&c6_rhs7);
  sf_mex_destroy(&c6_lhs7);
  sf_mex_destroy(&c6_rhs8);
  sf_mex_destroy(&c6_lhs8);
  sf_mex_destroy(&c6_rhs9);
  sf_mex_destroy(&c6_lhs9);
}

static const mxArray *c6_emlrt_marshallOut(const char * c6_u)
{
  const mxArray *c6_y = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c6_u)), false);
  return c6_y;
}

static const mxArray *c6_b_emlrt_marshallOut(const uint32_T c6_u)
{
  const mxArray *c6_y = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 7, 0U, 0U, 0U, 0), false);
  return c6_y;
}

static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance;
  chartInstance = (SFc6_PreScanUsefulBlocksInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static int32_T c6_f_emlrt_marshallIn(SFc6_PreScanUsefulBlocksInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i18;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i18, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i18;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance;
  chartInstance = (SFc6_PreScanUsefulBlocksInstanceStruct *)chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_in_bus_io(void *chartInstanceVoid, void *c6_pData)
{
  const mxArray *c6_mxVal = NULL;
  PRESCAN_COLLISIONDETECTION_MESSAGE c6_tmp;
  SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance;
  chartInstance = (SFc6_PreScanUsefulBlocksInstanceStruct *)chartInstanceVoid;
  c6_mxVal = NULL;
  c6_tmp.HEADER.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    (PRESCAN_COLLISIONDETECTION_MESSAGE *)c6_pData)[0])[0];
  c6_tmp.DATA.ObjectID1 = *(uint32_T *)&((char_T *)
    (PRESCAN_COLLISIONDETECTION_DATA *)&((char_T *)
    (PRESCAN_COLLISIONDETECTION_MESSAGE *)c6_pData)[8])[0];
  c6_tmp.DATA.ObjectID2 = *(uint32_T *)&((char_T *)
    (PRESCAN_COLLISIONDETECTION_DATA *)&((char_T *)
    (PRESCAN_COLLISIONDETECTION_MESSAGE *)c6_pData)[8])[4];
  sf_mex_assign(&c6_mxVal, c6_c_sf_marshallOut(chartInstance, &c6_tmp), false);
  return c6_mxVal;
}

static uint8_T c6_g_emlrt_marshallIn(SFc6_PreScanUsefulBlocksInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_PreScanUsefulBlocks, const
  char_T *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_PreScanUsefulBlocks), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_PreScanUsefulBlocks);
  return c6_y;
}

static uint8_T c6_h_emlrt_marshallIn(SFc6_PreScanUsefulBlocksInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void init_dsm_address_info(SFc6_PreScanUsefulBlocksInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc6_PreScanUsefulBlocksInstanceStruct
  *chartInstance)
{
  chartInstance->c6_in = (PRESCAN_COLLISIONDETECTION_MESSAGE *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c6_IDs = (real_T (*)[10])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c6_Detections = (boolean_T (*)[5])ssGetOutputPortSignal_wrapper
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

void sf_c6_PreScanUsefulBlocks_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2439945322U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2101226006U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1718426632U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2099734381U);
}

mxArray* sf_c6_PreScanUsefulBlocks_get_post_codegen_info(void);
mxArray *sf_c6_PreScanUsefulBlocks_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("YFrGgbUNXnkmNnfgqZ1RlD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
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

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(10);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(5);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
    mxArray* mxPostCodegenInfo = sf_c6_PreScanUsefulBlocks_get_post_codegen_info
      ();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c6_PreScanUsefulBlocks_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c6_PreScanUsefulBlocks_jit_fallback_info(void)
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

mxArray *sf_c6_PreScanUsefulBlocks_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c6_PreScanUsefulBlocks_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c6_PreScanUsefulBlocks(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[6],T\"Detections\",},{M[1],M[5],T\"IDs\",},{M[8],M[0],T\"is_active_c6_PreScanUsefulBlocks\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_PreScanUsefulBlocks_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc6_PreScanUsefulBlocksInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _PreScanUsefulBlocksMachineNumber_,
           6,
           1,
           1,
           0,
           3,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_PreScanUsefulBlocksMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_PreScanUsefulBlocksMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _PreScanUsefulBlocksMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"in");
          _SFD_SET_DATA_PROPS(1,2,0,1,"IDs");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Detections");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,407);
        _SFD_CV_INIT_EML_IF(0,1,0,193,219,-1,403);
        _SFD_CV_INIT_EML_FOR(0,1,0,148,189,407);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,196,219,-1,0);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_in_bus_io,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)
            c6_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)
            c6_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c6_in);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c6_IDs);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c6_Detections);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _PreScanUsefulBlocksMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "Pd5lmys3Ngo73ohclsxjED";
}

static void sf_opaque_initialize_c6_PreScanUsefulBlocks(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_PreScanUsefulBlocksInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c6_PreScanUsefulBlocks
    ((SFc6_PreScanUsefulBlocksInstanceStruct*) chartInstanceVar);
  initialize_c6_PreScanUsefulBlocks((SFc6_PreScanUsefulBlocksInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c6_PreScanUsefulBlocks(void *chartInstanceVar)
{
  enable_c6_PreScanUsefulBlocks((SFc6_PreScanUsefulBlocksInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c6_PreScanUsefulBlocks(void *chartInstanceVar)
{
  disable_c6_PreScanUsefulBlocks((SFc6_PreScanUsefulBlocksInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c6_PreScanUsefulBlocks(void *chartInstanceVar)
{
  sf_gateway_c6_PreScanUsefulBlocks((SFc6_PreScanUsefulBlocksInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c6_PreScanUsefulBlocks(SimStruct*
  S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c6_PreScanUsefulBlocks
    ((SFc6_PreScanUsefulBlocksInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c6_PreScanUsefulBlocks(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c6_PreScanUsefulBlocks((SFc6_PreScanUsefulBlocksInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c6_PreScanUsefulBlocks(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_PreScanUsefulBlocksInstanceStruct*) chartInstanceVar
      )->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_PreScanUsefulBlocks_optimization_info();
    }

    finalize_c6_PreScanUsefulBlocks((SFc6_PreScanUsefulBlocksInstanceStruct*)
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
  initSimStructsc6_PreScanUsefulBlocks((SFc6_PreScanUsefulBlocksInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_PreScanUsefulBlocks(SimStruct *S)
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
    initialize_params_c6_PreScanUsefulBlocks
      ((SFc6_PreScanUsefulBlocksInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_PreScanUsefulBlocks(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_PreScanUsefulBlocks_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,6,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,6);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,6,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2453875447U));
  ssSetChecksum1(S,(2642442449U));
  ssSetChecksum2(S,(1393637568U));
  ssSetChecksum3(S,(1287447902U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c6_PreScanUsefulBlocks(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_PreScanUsefulBlocks(SimStruct *S)
{
  SFc6_PreScanUsefulBlocksInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc6_PreScanUsefulBlocksInstanceStruct *)utMalloc(sizeof
    (SFc6_PreScanUsefulBlocksInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_PreScanUsefulBlocksInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c6_PreScanUsefulBlocks;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c6_PreScanUsefulBlocks;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c6_PreScanUsefulBlocks;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_PreScanUsefulBlocks;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c6_PreScanUsefulBlocks;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_PreScanUsefulBlocks;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_PreScanUsefulBlocks;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_PreScanUsefulBlocks;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_PreScanUsefulBlocks;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_PreScanUsefulBlocks;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c6_PreScanUsefulBlocks;
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

void c6_PreScanUsefulBlocks_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_PreScanUsefulBlocks(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_PreScanUsefulBlocks(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_PreScanUsefulBlocks(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_PreScanUsefulBlocks_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
