/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_3_cs_sfun.h"
#include "c1_Experiment_3_cs.h"
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
static const char * c1_debug_family_names[5] = { "nargin", "nargout", "u", "z",
  "y" };

static const char * c1_b_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

static const char * c1_c_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

static const char * c1_d_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

static const char * c1_e_debug_family_names[5] = { "nargin", "nargout", "y", "z",
  "u" };

/* Function Declarations */
static void initialize_c1_Experiment_3_cs(SFc1_Experiment_3_csInstanceStruct
  *chartInstance);
static void initialize_params_c1_Experiment_3_cs
  (SFc1_Experiment_3_csInstanceStruct *chartInstance);
static void enable_c1_Experiment_3_cs(SFc1_Experiment_3_csInstanceStruct
  *chartInstance);
static void disable_c1_Experiment_3_cs(SFc1_Experiment_3_csInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_Experiment_3_cs
  (SFc1_Experiment_3_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_Experiment_3_cs
  (SFc1_Experiment_3_csInstanceStruct *chartInstance);
static void set_sim_state_c1_Experiment_3_cs(SFc1_Experiment_3_csInstanceStruct *
  chartInstance, const mxArray *c1_st);
static void finalize_c1_Experiment_3_cs(SFc1_Experiment_3_csInstanceStruct
  *chartInstance);
static void sf_gateway_c1_Experiment_3_cs(SFc1_Experiment_3_csInstanceStruct
  *chartInstance);
static void mdl_start_c1_Experiment_3_cs(SFc1_Experiment_3_csInstanceStruct
  *chartInstance);
static void initSimStructsc1_Experiment_3_cs(SFc1_Experiment_3_csInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_emlrt_marshallOut(SFc1_Experiment_3_csInstanceStruct
  *chartInstance, const PRESCAN_V2X_FIXED_GENERIC_DATA *c1_b_u);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c1_b_y, const char_T *c1_identifier,
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE *c1_c_y);
static void c1_b_emlrt_marshallIn(SFc1_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE *c1_b_y);
static PRESCAN_HEADER c1_c_emlrt_marshallIn(SFc1_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId);
static boolean_T c1_d_emlrt_marshallIn(SFc1_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_emlrt_marshallIn(SFc1_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  PRESCAN_V2X_FIXED_GENERIC_DATA *c1_b_y);
static int32_T c1_f_emlrt_marshallIn(SFc1_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId);
static real_T c1_g_emlrt_marshallIn(SFc1_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_emlrt_marshallOut(SFc1_Experiment_3_csInstanceStruct *
  chartInstance, const c1_PRESCAN_V2X_USER_GENERIC_DATA *c1_b_u);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_h_emlrt_marshallIn(SFc1_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  c1_PRESCAN_V2X_USER_GENERIC_DATA *c1_b_y);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_i_emlrt_marshallIn(SFc1_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  c1_PRESCAN_V2X_USER_GENERIC_MESSAGE *c1_b_y);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(const mxArray **c1_info);
static const mxArray *c1_c_emlrt_marshallOut(const char * c1_b_u);
static const mxArray *c1_d_emlrt_marshallOut(const uint32_T c1_b_u);
static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_u_bus_io(void *chartInstanceVoid, void *c1_pData);
static const mxArray *c1_y_bus_io(void *chartInstanceVoid, void *c1_pData);
static uint8_T c1_j_emlrt_marshallIn(SFc1_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_Experiment_3_cs, const char_T
  *c1_identifier);
static uint8_T c1_k_emlrt_marshallIn(SFc1_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_Experiment_3_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc1_Experiment_3_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_Experiment_3_cs(SFc1_Experiment_3_csInstanceStruct
  *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_is_active_c1_Experiment_3_cs = 0U;
}

static void initialize_params_c1_Experiment_3_cs
  (SFc1_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_Experiment_3_cs(SFc1_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_Experiment_3_cs(SFc1_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_Experiment_3_cs
  (SFc1_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_Experiment_3_cs
  (SFc1_Experiment_3_csInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  PRESCAN_HEADER c1_b_u;
  const mxArray *c1_d_y = NULL;
  boolean_T c1_c_u;
  const mxArray *c1_e_y = NULL;
  PRESCAN_V2X_FIXED_GENERIC_DATA c1_r0;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_d_u;
  const mxArray *c1_f_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_createcellmatrix(2, 1), false);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c1_b_u.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    chartInstance->c1_y)[0])[0];
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c1_c_u = c1_b_u.valid;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_c_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_d_y, c1_e_y, "valid", "valid", 0);
  sf_mex_addfield(c1_c_y, c1_d_y, "HEADER", "HEADER", 0);
  c1_r0.messageID = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
                                  &((char_T *)chartInstance->c1_y)[8])[0];
  c1_r0.senderID = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[4];
  c1_r0.signal_1 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[8];
  c1_r0.signal_2 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[16];
  c1_r0.signal_3 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[24];
  c1_r0.signal_4 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[32];
  c1_r0.signal_5 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[40];
  c1_r0.signal_6 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[48];
  c1_r0.signal_7 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56];
  c1_r0.signal_8 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[64];
  c1_r0.signal_9 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[72];
  c1_r0.signal_10 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[80];
  c1_r0.discrete_signal_1 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c1_y)[8])[88];
  c1_r0.discrete_signal_2 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c1_y)[8])[92];
  c1_r0.discrete_signal_3 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c1_y)[8])[96];
  c1_r0.discrete_signal_4 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c1_y)[8])[100];
  c1_r0.discrete_signal_5 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c1_y)[8])[104];
  c1_r0.discrete_signal_6 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c1_y)[8])[108];
  c1_r0.discrete_signal_7 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c1_y)[8])[112];
  c1_r0.discrete_signal_8 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c1_y)[8])[116];
  c1_r0.discrete_signal_9 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c1_y)[8])[120];
  c1_r0.discrete_signal_10 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c1_y)[8])[124];
  sf_mex_addfield(c1_c_y, c1_emlrt_marshallOut(chartInstance, &c1_r0), "DATA",
                  "DATA", 0);
  sf_mex_setcell(c1_b_y, 0, c1_c_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_Experiment_3_cs;
  c1_d_u = c1_hoistedGlobal;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_b_y, 1, c1_f_y);
  sf_mex_assign(&c1_st, c1_b_y, false);
  return c1_st;
}

static void set_sim_state_c1_Experiment_3_cs(SFc1_Experiment_3_csInstanceStruct *
  chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_b_u;
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE c1_r1;
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_b_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_b_u, 0)), "y",
                      &c1_r1);
  *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)chartInstance->c1_y)[0])
    [0] = c1_r1.HEADER.valid;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[0] = c1_r1.DATA.messageID;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[4] = c1_r1.DATA.senderID;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[8] = c1_r1.DATA.signal_1;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[16] = c1_r1.DATA.signal_2;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[24] = c1_r1.DATA.signal_3;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[32] = c1_r1.DATA.signal_4;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[40] = c1_r1.DATA.signal_5;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[48] = c1_r1.DATA.signal_6;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[56] = c1_r1.DATA.signal_7;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[64] = c1_r1.DATA.signal_8;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[72] = c1_r1.DATA.signal_9;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[80] = c1_r1.DATA.signal_10;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[88] = c1_r1.DATA.discrete_signal_1;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[92] = c1_r1.DATA.discrete_signal_2;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[96] = c1_r1.DATA.discrete_signal_3;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[100] = c1_r1.DATA.discrete_signal_4;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[104] = c1_r1.DATA.discrete_signal_5;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[108] = c1_r1.DATA.discrete_signal_6;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[112] = c1_r1.DATA.discrete_signal_7;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[116] = c1_r1.DATA.discrete_signal_8;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[120] = c1_r1.DATA.discrete_signal_9;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[124] = c1_r1.DATA.discrete_signal_10;
  chartInstance->c1_is_active_c1_Experiment_3_cs = c1_j_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_b_u, 1)),
     "is_active_c1_Experiment_3_cs");
  sf_mex_destroy(&c1_b_u);
  c1_update_debugger_state_c1_Experiment_3_cs(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_Experiment_3_cs(SFc1_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c1_Experiment_3_cs(SFc1_Experiment_3_csInstanceStruct
  *chartInstance)
{
  c1_PRESCAN_V2X_USER_GENERIC_MESSAGE c1_b_u;
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE c1_b_z;
  uint32_T c1_debug_family_var_map[5];
  real_T c1_nargin = 2.0;
  real_T c1_nargout = 1.0;
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE c1_b_y;
  c1_PRESCAN_V2X_USER_GENERIC_MESSAGE c1_c_y;
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE c1_c_z;
  real_T c1_b_nargin = 2.0;
  real_T c1_b_nargout = 1.0;
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE c1_c_u;
  c1_PRESCAN_V2X_USER_GENERIC_MESSAGE c1_d_y;
  uint32_T c1_b_debug_family_var_map[4];
  real_T c1_c_nargin = 2.0;
  real_T c1_c_nargout = 1.0;
  PRESCAN_HEADER c1_d_u;
  PRESCAN_HEADER c1_e_y;
  real_T c1_d_nargin = 2.0;
  real_T c1_d_nargout = 1.0;
  PRESCAN_V2X_FIXED_GENERIC_DATA c1_e_u;
  c1_PRESCAN_V2X_USER_GENERIC_DATA c1_f_y;
  real_T c1_e_nargin = 2.0;
  real_T c1_e_nargout = 1.0;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_b_u.HEADER.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    chartInstance->c1_u)[0])[0];
  c1_b_u.DATA.messageID = *(int32_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c1_u)[8])[0];
  c1_b_u.DATA.senderID = *(int32_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c1_u)[8])[4];
  c1_b_u.DATA.signal_1 = *(real_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c1_u)[8])[8];
  c1_b_u.DATA.signal_2 = *(real_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c1_u)[8])[16];
  c1_b_u.DATA.signal_3 = *(real_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c1_u)[8])[24];
  c1_b_u.DATA.signal_4 = *(real_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c1_u)[8])[32];
  c1_b_u.DATA.signal_5 = *(real_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c1_u)[8])[40];
  c1_b_u.DATA.signal_6 = *(real_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c1_u)[8])[48];
  c1_b_u.DATA.signal_7 = *(real_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c1_u)[8])[56];
  c1_b_u.DATA.signal_8 = *(real_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c1_u)[8])[64];
  c1_b_u.DATA.signal_9 = *(real_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c1_u)[8])[72];
  c1_b_u.DATA.signal_10 = *(real_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c1_u)[8])[80];
  c1_b_u.DATA.discrete_signal_1 = *(int32_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c1_u)[8])[88];
  c1_b_u.DATA.discrete_signal_2 = *(int32_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c1_u)[8])[92];
  c1_b_u.DATA.discrete_signal_3 = *(int32_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c1_u)[8])[96];
  c1_b_u.DATA.discrete_signal_4 = *(int32_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c1_u)[8])[100];
  c1_b_u.DATA.discrete_signal_5 = *(int32_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c1_u)[8])[104];
  c1_b_u.DATA.discrete_signal_6 = *(int32_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c1_u)[8])[108];
  c1_b_u.DATA.discrete_signal_7 = *(int32_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c1_u)[8])[112];
  c1_b_u.DATA.discrete_signal_8 = *(int32_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c1_u)[8])[116];
  c1_b_u.DATA.discrete_signal_9 = *(int32_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c1_u)[8])[120];
  c1_b_u.DATA.discrete_signal_10 = *(int32_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c1_u)[8])[124];
  c1_b_z.HEADER.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    chartInstance->c1_z)[0])[0];
  c1_b_z.DATA.messageID = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c1_z)[8])[0];
  c1_b_z.DATA.senderID = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA
    *)&((char_T *)chartInstance->c1_z)[8])[4];
  c1_b_z.DATA.signal_1 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[8];
  c1_b_z.DATA.signal_2 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[16];
  c1_b_z.DATA.signal_3 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[24];
  c1_b_z.DATA.signal_4 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[32];
  c1_b_z.DATA.signal_5 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[40];
  c1_b_z.DATA.signal_6 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[48];
  c1_b_z.DATA.signal_7 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[56];
  c1_b_z.DATA.signal_8 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[64];
  c1_b_z.DATA.signal_9 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[72];
  c1_b_z.DATA.signal_10 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA
    *)&((char_T *)chartInstance->c1_z)[8])[80];
  c1_b_z.DATA.discrete_signal_1 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c1_z)[8])[88];
  c1_b_z.DATA.discrete_signal_2 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c1_z)[8])[92];
  c1_b_z.DATA.discrete_signal_3 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c1_z)[8])[96];
  c1_b_z.DATA.discrete_signal_4 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c1_z)[8])[100];
  c1_b_z.DATA.discrete_signal_5 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c1_z)[8])[104];
  c1_b_z.DATA.discrete_signal_6 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c1_z)[8])[108];
  c1_b_z.DATA.discrete_signal_7 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c1_z)[8])[112];
  c1_b_z.DATA.discrete_signal_8 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c1_z)[8])[116];
  c1_b_z.DATA.discrete_signal_9 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c1_z)[8])[120];
  c1_b_z.DATA.discrete_signal_10 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c1_z)[8])[124];
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_u, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_z, 3U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_y, 4U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_c_y = c1_b_u;
  c1_c_z = c1_b_z;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c1_e_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_y, 2U, c1_b_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_z, 3U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_y, 4U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  c1_b_y = c1_c_z;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_c_u = c1_b_y;
  c1_d_y = c1_c_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 5U, c1_d_debug_family_names,
    c1_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_u, 2U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_y, 3U, c1_b_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_y, MAX_uint32_T, c1_sf_marshallOut,
    c1_sf_marshallIn);
  c1_b_y = c1_c_u;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  CV_SCRIPT_FCN(0, 1);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_d_u = c1_b_y.HEADER;
  c1_e_y = c1_d_y.HEADER;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 5U, c1_b_debug_family_names,
    c1_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_u, 2U, c1_d_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_y, 3U, c1_d_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_y.HEADER, MAX_uint32_T,
    c1_d_sf_marshallOut, c1_c_sf_marshallIn);
  c1_b_y.HEADER = c1_d_u;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  CV_SCRIPT_FCN(0, 2);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 13);
  c1_b_y.HEADER.valid = c1_e_y.valid;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -13);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  c1_e_u = c1_b_y.DATA;
  c1_f_y = c1_d_y.DATA;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 5U, c1_c_debug_family_names,
    c1_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_u, 2U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_y, 3U, c1_f_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_y.DATA, MAX_uint32_T,
    c1_e_sf_marshallOut, c1_d_sf_marshallIn);
  c1_b_y.DATA = c1_e_u;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  CV_SCRIPT_FCN(0, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 17);
  c1_b_y.DATA.messageID = c1_f_y.messageID;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 18);
  c1_b_y.DATA.senderID = c1_f_y.senderID;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 19);
  c1_b_y.DATA.signal_1 = c1_f_y.signal_1;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 20);
  c1_b_y.DATA.signal_2 = c1_f_y.signal_2;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 21);
  c1_b_y.DATA.signal_3 = c1_f_y.signal_3;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 22);
  c1_b_y.DATA.signal_4 = c1_f_y.signal_4;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 23);
  c1_b_y.DATA.signal_5 = c1_f_y.signal_5;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 24);
  c1_b_y.DATA.signal_6 = c1_f_y.signal_6;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 25);
  c1_b_y.DATA.signal_7 = c1_f_y.signal_7;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 26);
  c1_b_y.DATA.signal_8 = c1_f_y.signal_8;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 27);
  c1_b_y.DATA.signal_9 = c1_f_y.signal_9;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 28);
  c1_b_y.DATA.signal_10 = c1_f_y.signal_10;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 29);
  c1_b_y.DATA.discrete_signal_1 = c1_f_y.discrete_signal_1;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 30);
  c1_b_y.DATA.discrete_signal_2 = c1_f_y.discrete_signal_2;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 31);
  c1_b_y.DATA.discrete_signal_3 = c1_f_y.discrete_signal_3;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 32);
  c1_b_y.DATA.discrete_signal_4 = c1_f_y.discrete_signal_4;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 33);
  c1_b_y.DATA.discrete_signal_5 = c1_f_y.discrete_signal_5;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 34);
  c1_b_y.DATA.discrete_signal_6 = c1_f_y.discrete_signal_6;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 35);
  c1_b_y.DATA.discrete_signal_7 = c1_f_y.discrete_signal_7;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 36);
  c1_b_y.DATA.discrete_signal_8 = c1_f_y.discrete_signal_8;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 37);
  c1_b_y.DATA.discrete_signal_9 = c1_f_y.discrete_signal_9;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 38);
  c1_b_y.DATA.discrete_signal_10 = c1_f_y.discrete_signal_10;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -38);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -9);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)chartInstance->c1_y)[0])
    [0] = c1_b_y.HEADER.valid;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[0] = c1_b_y.DATA.messageID;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[4] = c1_b_y.DATA.senderID;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[8] = c1_b_y.DATA.signal_1;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[16] = c1_b_y.DATA.signal_2;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[24] = c1_b_y.DATA.signal_3;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[32] = c1_b_y.DATA.signal_4;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[40] = c1_b_y.DATA.signal_5;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[48] = c1_b_y.DATA.signal_6;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[56] = c1_b_y.DATA.signal_7;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[64] = c1_b_y.DATA.signal_8;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[72] = c1_b_y.DATA.signal_9;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[80] = c1_b_y.DATA.signal_10;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[88] = c1_b_y.DATA.discrete_signal_1;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[92] = c1_b_y.DATA.discrete_signal_2;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[96] = c1_b_y.DATA.discrete_signal_3;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[100] = c1_b_y.DATA.discrete_signal_4;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[104] = c1_b_y.DATA.discrete_signal_5;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[108] = c1_b_y.DATA.discrete_signal_6;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[112] = c1_b_y.DATA.discrete_signal_7;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[116] = c1_b_y.DATA.discrete_signal_8;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[120] = c1_b_y.DATA.discrete_signal_9;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[124] = c1_b_y.DATA.discrete_signal_10;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Experiment_3_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c1_Experiment_3_cs(SFc1_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc1_Experiment_3_cs(SFc1_Experiment_3_csInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)c1_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, c1_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Workspace\\PreScan Files\\Experiment_3\\V2X_GENERIC_expander.m"));
}

static const mxArray *c1_emlrt_marshallOut(SFc1_Experiment_3_csInstanceStruct
  *chartInstance, const PRESCAN_V2X_FIXED_GENERIC_DATA *c1_b_u)
{
  const mxArray *c1_b_y = NULL;
  int32_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  int32_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_e_u;
  const mxArray *c1_e_y = NULL;
  real_T c1_f_u;
  const mxArray *c1_f_y = NULL;
  real_T c1_g_u;
  const mxArray *c1_g_y = NULL;
  real_T c1_h_u;
  const mxArray *c1_h_y = NULL;
  real_T c1_i_u;
  const mxArray *c1_i_y = NULL;
  real_T c1_j_u;
  const mxArray *c1_j_y = NULL;
  real_T c1_k_u;
  const mxArray *c1_k_y = NULL;
  real_T c1_l_u;
  const mxArray *c1_l_y = NULL;
  real_T c1_m_u;
  const mxArray *c1_m_y = NULL;
  real_T c1_n_u;
  const mxArray *c1_n_y = NULL;
  int32_T c1_o_u;
  const mxArray *c1_o_y = NULL;
  int32_T c1_p_u;
  const mxArray *c1_p_y = NULL;
  int32_T c1_q_u;
  const mxArray *c1_q_y = NULL;
  int32_T c1_r_u;
  const mxArray *c1_r_y = NULL;
  int32_T c1_s_u;
  const mxArray *c1_s_y = NULL;
  int32_T c1_t_u;
  const mxArray *c1_t_y = NULL;
  int32_T c1_u_u;
  const mxArray *c1_u_y = NULL;
  int32_T c1_v_u;
  const mxArray *c1_v_y = NULL;
  int32_T c1_w_u;
  const mxArray *c1_w_y = NULL;
  int32_T c1_x_u;
  const mxArray *c1_x_y = NULL;
  (void)chartInstance;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c1_c_u = c1_b_u->messageID;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_c_y, "messageID", "messageID", 0);
  c1_d_u = c1_b_u->senderID;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_d_y, "senderID", "senderID", 0);
  c1_e_u = c1_b_u->signal_1;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_e_y, "signal_1", "signal_1", 0);
  c1_f_u = c1_b_u->signal_2;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_f_y, "signal_2", "signal_2", 0);
  c1_g_u = c1_b_u->signal_3;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_g_y, "signal_3", "signal_3", 0);
  c1_h_u = c1_b_u->signal_4;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_h_y, "signal_4", "signal_4", 0);
  c1_i_u = c1_b_u->signal_5;
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_i_y, "signal_5", "signal_5", 0);
  c1_j_u = c1_b_u->signal_6;
  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", &c1_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_j_y, "signal_6", "signal_6", 0);
  c1_k_u = c1_b_u->signal_7;
  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_k_y, "signal_7", "signal_7", 0);
  c1_l_u = c1_b_u->signal_8;
  c1_l_y = NULL;
  sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_l_y, "signal_8", "signal_8", 0);
  c1_m_u = c1_b_u->signal_9;
  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_m_y, "signal_9", "signal_9", 0);
  c1_n_u = c1_b_u->signal_10;
  c1_n_y = NULL;
  sf_mex_assign(&c1_n_y, sf_mex_create("y", &c1_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_n_y, "signal_10", "signal_10", 0);
  c1_o_u = c1_b_u->discrete_signal_1;
  c1_o_y = NULL;
  sf_mex_assign(&c1_o_y, sf_mex_create("y", &c1_o_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_o_y, "discrete_signal_1", "discrete_signal_1", 0);
  c1_p_u = c1_b_u->discrete_signal_2;
  c1_p_y = NULL;
  sf_mex_assign(&c1_p_y, sf_mex_create("y", &c1_p_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_p_y, "discrete_signal_2", "discrete_signal_2", 0);
  c1_q_u = c1_b_u->discrete_signal_3;
  c1_q_y = NULL;
  sf_mex_assign(&c1_q_y, sf_mex_create("y", &c1_q_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_q_y, "discrete_signal_3", "discrete_signal_3", 0);
  c1_r_u = c1_b_u->discrete_signal_4;
  c1_r_y = NULL;
  sf_mex_assign(&c1_r_y, sf_mex_create("y", &c1_r_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_r_y, "discrete_signal_4", "discrete_signal_4", 0);
  c1_s_u = c1_b_u->discrete_signal_5;
  c1_s_y = NULL;
  sf_mex_assign(&c1_s_y, sf_mex_create("y", &c1_s_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_s_y, "discrete_signal_5", "discrete_signal_5", 0);
  c1_t_u = c1_b_u->discrete_signal_6;
  c1_t_y = NULL;
  sf_mex_assign(&c1_t_y, sf_mex_create("y", &c1_t_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_t_y, "discrete_signal_6", "discrete_signal_6", 0);
  c1_u_u = c1_b_u->discrete_signal_7;
  c1_u_y = NULL;
  sf_mex_assign(&c1_u_y, sf_mex_create("y", &c1_u_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_u_y, "discrete_signal_7", "discrete_signal_7", 0);
  c1_v_u = c1_b_u->discrete_signal_8;
  c1_v_y = NULL;
  sf_mex_assign(&c1_v_y, sf_mex_create("y", &c1_v_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_v_y, "discrete_signal_8", "discrete_signal_8", 0);
  c1_w_u = c1_b_u->discrete_signal_9;
  c1_w_y = NULL;
  sf_mex_assign(&c1_w_y, sf_mex_create("y", &c1_w_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_w_y, "discrete_signal_9", "discrete_signal_9", 0);
  c1_x_u = c1_b_u->discrete_signal_10;
  c1_x_y = NULL;
  sf_mex_assign(&c1_x_y, sf_mex_create("y", &c1_x_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_x_y, "discrete_signal_10", "discrete_signal_10", 0);
  return c1_b_y;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE c1_b_u;
  const mxArray *c1_b_y = NULL;
  PRESCAN_HEADER c1_c_u;
  const mxArray *c1_c_y = NULL;
  boolean_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  SFc1_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_b_u = *(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c1_inData;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c1_c_u = c1_b_u.HEADER;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c1_d_u = c1_c_u.valid;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_c_y, c1_d_y, "valid", "valid", 0);
  sf_mex_addfield(c1_b_y, c1_c_y, "HEADER", "HEADER", 0);
  sf_mex_addfield(c1_b_y, c1_emlrt_marshallOut(chartInstance, &c1_b_u.DATA),
                  "DATA", "DATA", 0);
  sf_mex_assign(&c1_mxArrayOutData, c1_b_y, false);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c1_b_y, const char_T *c1_identifier,
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE *c1_c_y)
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_y), &c1_thisId, c1_c_y);
  sf_mex_destroy(&c1_b_y);
}

static void c1_b_emlrt_marshallIn(SFc1_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE *c1_b_y)
{
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[2] = { "HEADER", "DATA" };

  c1_thisId.fParent = c1_parentId;
  sf_mex_check_struct(c1_parentId, c1_b_u, 2, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "HEADER";
  c1_b_y->HEADER = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "HEADER", "HEADER", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "DATA";
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u, "DATA",
    "DATA", 0)), &c1_thisId, &c1_b_y->DATA);
  sf_mex_destroy(&c1_b_u);
}

static PRESCAN_HEADER c1_c_emlrt_marshallIn(SFc1_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId)
{
  PRESCAN_HEADER c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[1] = { "valid" };

  c1_thisId.fParent = c1_parentId;
  sf_mex_check_struct(c1_parentId, c1_b_u, 1, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "valid";
  c1_b_y.valid = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c1_b_u, "valid", "valid", 0)),
    &c1_thisId);
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static boolean_T c1_d_emlrt_marshallIn(SFc1_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_b_y;
  boolean_T c1_b0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), &c1_b0, 1, 11, 0U, 0, 0U, 0);
  c1_b_y = c1_b0;
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static void c1_e_emlrt_marshallIn(SFc1_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  PRESCAN_V2X_FIXED_GENERIC_DATA *c1_b_y)
{
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[22] = { "messageID", "senderID", "signal_1",
    "signal_2", "signal_3", "signal_4", "signal_5", "signal_6", "signal_7",
    "signal_8", "signal_9", "signal_10", "discrete_signal_1",
    "discrete_signal_2", "discrete_signal_3", "discrete_signal_4",
    "discrete_signal_5", "discrete_signal_6", "discrete_signal_7",
    "discrete_signal_8", "discrete_signal_9", "discrete_signal_10" };

  c1_thisId.fParent = c1_parentId;
  sf_mex_check_struct(c1_parentId, c1_b_u, 22, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "messageID";
  c1_b_y->messageID = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "messageID", "messageID", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "senderID";
  c1_b_y->senderID = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "senderID", "senderID", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "signal_1";
  c1_b_y->signal_1 = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "signal_1", "signal_1", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "signal_2";
  c1_b_y->signal_2 = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "signal_2", "signal_2", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "signal_3";
  c1_b_y->signal_3 = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "signal_3", "signal_3", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "signal_4";
  c1_b_y->signal_4 = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "signal_4", "signal_4", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "signal_5";
  c1_b_y->signal_5 = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "signal_5", "signal_5", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "signal_6";
  c1_b_y->signal_6 = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "signal_6", "signal_6", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "signal_7";
  c1_b_y->signal_7 = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "signal_7", "signal_7", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "signal_8";
  c1_b_y->signal_8 = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "signal_8", "signal_8", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "signal_9";
  c1_b_y->signal_9 = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "signal_9", "signal_9", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "signal_10";
  c1_b_y->signal_10 = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "signal_10", "signal_10", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "discrete_signal_1";
  c1_b_y->discrete_signal_1 = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "discrete_signal_1", "discrete_signal_1", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "discrete_signal_2";
  c1_b_y->discrete_signal_2 = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "discrete_signal_2", "discrete_signal_2", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "discrete_signal_3";
  c1_b_y->discrete_signal_3 = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "discrete_signal_3", "discrete_signal_3", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "discrete_signal_4";
  c1_b_y->discrete_signal_4 = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "discrete_signal_4", "discrete_signal_4", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "discrete_signal_5";
  c1_b_y->discrete_signal_5 = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "discrete_signal_5", "discrete_signal_5", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "discrete_signal_6";
  c1_b_y->discrete_signal_6 = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "discrete_signal_6", "discrete_signal_6", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "discrete_signal_7";
  c1_b_y->discrete_signal_7 = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "discrete_signal_7", "discrete_signal_7", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "discrete_signal_8";
  c1_b_y->discrete_signal_8 = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "discrete_signal_8", "discrete_signal_8", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "discrete_signal_9";
  c1_b_y->discrete_signal_9 = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "discrete_signal_9", "discrete_signal_9", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "discrete_signal_10";
  c1_b_y->discrete_signal_10 = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "discrete_signal_10", "discrete_signal_10", 0)),
    &c1_thisId);
  sf_mex_destroy(&c1_b_u);
}

static int32_T c1_f_emlrt_marshallIn(SFc1_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_b_y;
  int32_T c1_i0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), &c1_i0, 1, 6, 0U, 0, 0U, 0);
  c1_b_y = c1_i0;
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static real_T c1_g_emlrt_marshallIn(SFc1_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_b_y;
  real_T c1_d0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_b_y = c1_d0;
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_y;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE c1_c_y;
  SFc1_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c1_b_y = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_y), &c1_thisId, &c1_c_y);
  sf_mex_destroy(&c1_b_y);
  *(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c1_outData = c1_c_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_emlrt_marshallOut(SFc1_Experiment_3_csInstanceStruct *
  chartInstance, const c1_PRESCAN_V2X_USER_GENERIC_DATA *c1_b_u)
{
  const mxArray *c1_b_y = NULL;
  int32_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  int32_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_e_u;
  const mxArray *c1_e_y = NULL;
  real_T c1_f_u;
  const mxArray *c1_f_y = NULL;
  real_T c1_g_u;
  const mxArray *c1_g_y = NULL;
  real_T c1_h_u;
  const mxArray *c1_h_y = NULL;
  real_T c1_i_u;
  const mxArray *c1_i_y = NULL;
  real_T c1_j_u;
  const mxArray *c1_j_y = NULL;
  real_T c1_k_u;
  const mxArray *c1_k_y = NULL;
  real_T c1_l_u;
  const mxArray *c1_l_y = NULL;
  real_T c1_m_u;
  const mxArray *c1_m_y = NULL;
  real_T c1_n_u;
  const mxArray *c1_n_y = NULL;
  int32_T c1_o_u;
  const mxArray *c1_o_y = NULL;
  int32_T c1_p_u;
  const mxArray *c1_p_y = NULL;
  int32_T c1_q_u;
  const mxArray *c1_q_y = NULL;
  int32_T c1_r_u;
  const mxArray *c1_r_y = NULL;
  int32_T c1_s_u;
  const mxArray *c1_s_y = NULL;
  int32_T c1_t_u;
  const mxArray *c1_t_y = NULL;
  int32_T c1_u_u;
  const mxArray *c1_u_y = NULL;
  int32_T c1_v_u;
  const mxArray *c1_v_y = NULL;
  int32_T c1_w_u;
  const mxArray *c1_w_y = NULL;
  int32_T c1_x_u;
  const mxArray *c1_x_y = NULL;
  (void)chartInstance;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c1_c_u = c1_b_u->messageID;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_c_y, "messageID", "messageID", 0);
  c1_d_u = c1_b_u->senderID;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_d_y, "senderID", "senderID", 0);
  c1_e_u = c1_b_u->signal_1;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_e_y, "signal_1", "signal_1", 0);
  c1_f_u = c1_b_u->signal_2;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_f_y, "signal_2", "signal_2", 0);
  c1_g_u = c1_b_u->signal_3;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_g_y, "signal_3", "signal_3", 0);
  c1_h_u = c1_b_u->signal_4;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_h_y, "signal_4", "signal_4", 0);
  c1_i_u = c1_b_u->signal_5;
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_i_y, "signal_5", "signal_5", 0);
  c1_j_u = c1_b_u->signal_6;
  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", &c1_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_j_y, "signal_6", "signal_6", 0);
  c1_k_u = c1_b_u->signal_7;
  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_k_y, "signal_7", "signal_7", 0);
  c1_l_u = c1_b_u->signal_8;
  c1_l_y = NULL;
  sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_l_y, "signal_8", "signal_8", 0);
  c1_m_u = c1_b_u->signal_9;
  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_m_y, "signal_9", "signal_9", 0);
  c1_n_u = c1_b_u->signal_10;
  c1_n_y = NULL;
  sf_mex_assign(&c1_n_y, sf_mex_create("y", &c1_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_n_y, "signal_10", "signal_10", 0);
  c1_o_u = c1_b_u->discrete_signal_1;
  c1_o_y = NULL;
  sf_mex_assign(&c1_o_y, sf_mex_create("y", &c1_o_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_o_y, "discrete_signal_1", "discrete_signal_1", 0);
  c1_p_u = c1_b_u->discrete_signal_2;
  c1_p_y = NULL;
  sf_mex_assign(&c1_p_y, sf_mex_create("y", &c1_p_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_p_y, "discrete_signal_2", "discrete_signal_2", 0);
  c1_q_u = c1_b_u->discrete_signal_3;
  c1_q_y = NULL;
  sf_mex_assign(&c1_q_y, sf_mex_create("y", &c1_q_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_q_y, "discrete_signal_3", "discrete_signal_3", 0);
  c1_r_u = c1_b_u->discrete_signal_4;
  c1_r_y = NULL;
  sf_mex_assign(&c1_r_y, sf_mex_create("y", &c1_r_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_r_y, "discrete_signal_4", "discrete_signal_4", 0);
  c1_s_u = c1_b_u->discrete_signal_5;
  c1_s_y = NULL;
  sf_mex_assign(&c1_s_y, sf_mex_create("y", &c1_s_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_s_y, "discrete_signal_5", "discrete_signal_5", 0);
  c1_t_u = c1_b_u->discrete_signal_6;
  c1_t_y = NULL;
  sf_mex_assign(&c1_t_y, sf_mex_create("y", &c1_t_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_t_y, "discrete_signal_6", "discrete_signal_6", 0);
  c1_u_u = c1_b_u->discrete_signal_7;
  c1_u_y = NULL;
  sf_mex_assign(&c1_u_y, sf_mex_create("y", &c1_u_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_u_y, "discrete_signal_7", "discrete_signal_7", 0);
  c1_v_u = c1_b_u->discrete_signal_8;
  c1_v_y = NULL;
  sf_mex_assign(&c1_v_y, sf_mex_create("y", &c1_v_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_v_y, "discrete_signal_8", "discrete_signal_8", 0);
  c1_w_u = c1_b_u->discrete_signal_9;
  c1_w_y = NULL;
  sf_mex_assign(&c1_w_y, sf_mex_create("y", &c1_w_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_w_y, "discrete_signal_9", "discrete_signal_9", 0);
  c1_x_u = c1_b_u->discrete_signal_10;
  c1_x_y = NULL;
  sf_mex_assign(&c1_x_y, sf_mex_create("y", &c1_x_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_x_y, "discrete_signal_10", "discrete_signal_10", 0);
  return c1_b_y;
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  c1_PRESCAN_V2X_USER_GENERIC_MESSAGE c1_b_u;
  const mxArray *c1_b_y = NULL;
  PRESCAN_HEADER c1_c_u;
  const mxArray *c1_c_y = NULL;
  boolean_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  SFc1_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_b_u = *(c1_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c1_inData;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c1_c_u = c1_b_u.HEADER;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c1_d_u = c1_c_u.valid;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_c_y, c1_d_y, "valid", "valid", 0);
  sf_mex_addfield(c1_b_y, c1_c_y, "HEADER", "HEADER", 0);
  sf_mex_addfield(c1_b_y, c1_b_emlrt_marshallOut(chartInstance, &c1_b_u.DATA),
                  "DATA", "DATA", 0);
  sf_mex_assign(&c1_mxArrayOutData, c1_b_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_b_u = *(real_T *)c1_inData;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_b_y, false);
  return c1_mxArrayOutData;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_b_y;
  SFc1_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout),
    &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_b_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  PRESCAN_HEADER c1_b_u;
  const mxArray *c1_b_y = NULL;
  boolean_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  SFc1_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_b_u = *(PRESCAN_HEADER *)c1_inData;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c1_c_u = c1_b_u.valid;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_b_y, c1_c_y, "valid", "valid", 0);
  sf_mex_assign(&c1_mxArrayOutData, c1_b_y, false);
  return c1_mxArrayOutData;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_u;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  PRESCAN_HEADER c1_b_y;
  SFc1_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c1_b_u = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_u), &c1_thisId);
  sf_mex_destroy(&c1_b_u);
  *(PRESCAN_HEADER *)c1_outData = c1_b_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  SFc1_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  sf_mex_assign(&c1_mxArrayOutData, c1_emlrt_marshallOut(chartInstance,
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)c1_inData), false);
  return c1_mxArrayOutData;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_u;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  PRESCAN_V2X_FIXED_GENERIC_DATA c1_b_y;
  SFc1_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c1_b_u = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_u), &c1_thisId, &c1_b_y);
  sf_mex_destroy(&c1_b_u);
  *(PRESCAN_V2X_FIXED_GENERIC_DATA *)c1_outData = c1_b_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  SFc1_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  sf_mex_assign(&c1_mxArrayOutData, c1_b_emlrt_marshallOut(chartInstance,
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)c1_inData), false);
  return c1_mxArrayOutData;
}

static void c1_h_emlrt_marshallIn(SFc1_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  c1_PRESCAN_V2X_USER_GENERIC_DATA *c1_b_y)
{
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[22] = { "messageID", "senderID", "signal_1",
    "signal_2", "signal_3", "signal_4", "signal_5", "signal_6", "signal_7",
    "signal_8", "signal_9", "signal_10", "discrete_signal_1",
    "discrete_signal_2", "discrete_signal_3", "discrete_signal_4",
    "discrete_signal_5", "discrete_signal_6", "discrete_signal_7",
    "discrete_signal_8", "discrete_signal_9", "discrete_signal_10" };

  c1_thisId.fParent = c1_parentId;
  sf_mex_check_struct(c1_parentId, c1_b_u, 22, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "messageID";
  c1_b_y->messageID = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "messageID", "messageID", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "senderID";
  c1_b_y->senderID = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "senderID", "senderID", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "signal_1";
  c1_b_y->signal_1 = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "signal_1", "signal_1", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "signal_2";
  c1_b_y->signal_2 = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "signal_2", "signal_2", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "signal_3";
  c1_b_y->signal_3 = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "signal_3", "signal_3", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "signal_4";
  c1_b_y->signal_4 = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "signal_4", "signal_4", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "signal_5";
  c1_b_y->signal_5 = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "signal_5", "signal_5", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "signal_6";
  c1_b_y->signal_6 = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "signal_6", "signal_6", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "signal_7";
  c1_b_y->signal_7 = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "signal_7", "signal_7", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "signal_8";
  c1_b_y->signal_8 = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "signal_8", "signal_8", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "signal_9";
  c1_b_y->signal_9 = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "signal_9", "signal_9", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "signal_10";
  c1_b_y->signal_10 = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "signal_10", "signal_10", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "discrete_signal_1";
  c1_b_y->discrete_signal_1 = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "discrete_signal_1", "discrete_signal_1", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "discrete_signal_2";
  c1_b_y->discrete_signal_2 = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "discrete_signal_2", "discrete_signal_2", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "discrete_signal_3";
  c1_b_y->discrete_signal_3 = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "discrete_signal_3", "discrete_signal_3", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "discrete_signal_4";
  c1_b_y->discrete_signal_4 = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "discrete_signal_4", "discrete_signal_4", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "discrete_signal_5";
  c1_b_y->discrete_signal_5 = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "discrete_signal_5", "discrete_signal_5", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "discrete_signal_6";
  c1_b_y->discrete_signal_6 = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "discrete_signal_6", "discrete_signal_6", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "discrete_signal_7";
  c1_b_y->discrete_signal_7 = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "discrete_signal_7", "discrete_signal_7", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "discrete_signal_8";
  c1_b_y->discrete_signal_8 = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "discrete_signal_8", "discrete_signal_8", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "discrete_signal_9";
  c1_b_y->discrete_signal_9 = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "discrete_signal_9", "discrete_signal_9", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "discrete_signal_10";
  c1_b_y->discrete_signal_10 = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "discrete_signal_10", "discrete_signal_10", 0)),
    &c1_thisId);
  sf_mex_destroy(&c1_b_u);
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_y;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  c1_PRESCAN_V2X_USER_GENERIC_DATA c1_c_y;
  SFc1_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c1_b_y = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_y), &c1_thisId, &c1_c_y);
  sf_mex_destroy(&c1_b_y);
  *(c1_PRESCAN_V2X_USER_GENERIC_DATA *)c1_outData = c1_c_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static void c1_i_emlrt_marshallIn(SFc1_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  c1_PRESCAN_V2X_USER_GENERIC_MESSAGE *c1_b_y)
{
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[2] = { "HEADER", "DATA" };

  c1_thisId.fParent = c1_parentId;
  sf_mex_check_struct(c1_parentId, c1_b_u, 2, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "HEADER";
  c1_b_y->HEADER = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "HEADER", "HEADER", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "DATA";
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u, "DATA",
    "DATA", 0)), &c1_thisId, &c1_b_y->DATA);
  sf_mex_destroy(&c1_b_u);
}

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_y;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  c1_PRESCAN_V2X_USER_GENERIC_MESSAGE c1_c_y;
  SFc1_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c1_b_y = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_y), &c1_thisId, &c1_c_y);
  sf_mex_destroy(&c1_b_y);
  *(c1_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c1_outData = c1_c_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_Experiment_3_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_createstruct("structure", 2, 1, 1),
                false);
  c1_info_helper(&c1_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(const mxArray **c1_info)
{
  const mxArray *c1_rhs0 = NULL;
  const mxArray *c1_lhs0 = NULL;
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("V2X_GENERIC_expander"),
                  "name", "name", 0);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut("struct"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c1_info, c1_c_emlrt_marshallOut(
    "[E]C:/Workspace/PreScan Files/Experiment_3/V2X_GENERIC_expander.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(1522436928U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c1_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs0), "lhs", "lhs", 0);
  sf_mex_destroy(&c1_rhs0);
  sf_mex_destroy(&c1_lhs0);
}

static const mxArray *c1_c_emlrt_marshallOut(const char * c1_b_u)
{
  const mxArray *c1_b_y = NULL;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 15, 0U, 0U, 0U, 2, 1, strlen
                 (c1_b_u)), false);
  return c1_b_y;
}

static const mxArray *c1_d_emlrt_marshallOut(const uint32_T c1_b_u)
{
  const mxArray *c1_b_y = NULL;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 7, 0U, 0U, 0U, 0), false);
  return c1_b_y;
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_b_u = *(int32_T *)c1_inData;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_b_y, false);
  return c1_mxArrayOutData;
}

static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_b_y;
  SFc1_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_b_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_u_bus_io(void *chartInstanceVoid, void *c1_pData)
{
  const mxArray *c1_mxVal = NULL;
  c1_PRESCAN_V2X_USER_GENERIC_MESSAGE c1_tmp;
  SFc1_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c1_mxVal = NULL;
  c1_tmp.HEADER.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c1_pData)[0])[0];
  c1_tmp.DATA.messageID = *(int32_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c1_pData)[8])[0];
  c1_tmp.DATA.senderID = *(int32_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c1_pData)[8])[4];
  c1_tmp.DATA.signal_1 = *(real_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c1_pData)[8])[8];
  c1_tmp.DATA.signal_2 = *(real_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c1_pData)[8])[16];
  c1_tmp.DATA.signal_3 = *(real_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c1_pData)[8])[24];
  c1_tmp.DATA.signal_4 = *(real_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c1_pData)[8])[32];
  c1_tmp.DATA.signal_5 = *(real_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c1_pData)[8])[40];
  c1_tmp.DATA.signal_6 = *(real_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c1_pData)[8])[48];
  c1_tmp.DATA.signal_7 = *(real_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c1_pData)[8])[56];
  c1_tmp.DATA.signal_8 = *(real_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c1_pData)[8])[64];
  c1_tmp.DATA.signal_9 = *(real_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c1_pData)[8])[72];
  c1_tmp.DATA.signal_10 = *(real_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c1_pData)[8])[80];
  c1_tmp.DATA.discrete_signal_1 = *(int32_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c1_pData)[8])[88];
  c1_tmp.DATA.discrete_signal_2 = *(int32_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c1_pData)[8])[92];
  c1_tmp.DATA.discrete_signal_3 = *(int32_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c1_pData)[8])[96];
  c1_tmp.DATA.discrete_signal_4 = *(int32_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c1_pData)[8])[100];
  c1_tmp.DATA.discrete_signal_5 = *(int32_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c1_pData)[8])[104];
  c1_tmp.DATA.discrete_signal_6 = *(int32_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c1_pData)[8])[108];
  c1_tmp.DATA.discrete_signal_7 = *(int32_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c1_pData)[8])[112];
  c1_tmp.DATA.discrete_signal_8 = *(int32_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c1_pData)[8])[116];
  c1_tmp.DATA.discrete_signal_9 = *(int32_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c1_pData)[8])[120];
  c1_tmp.DATA.discrete_signal_10 = *(int32_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c1_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c1_pData)[8])[124];
  sf_mex_assign(&c1_mxVal, c1_b_sf_marshallOut(chartInstance, &c1_tmp), false);
  return c1_mxVal;
}

static const mxArray *c1_y_bus_io(void *chartInstanceVoid, void *c1_pData)
{
  const mxArray *c1_mxVal = NULL;
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE c1_tmp;
  SFc1_Experiment_3_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Experiment_3_csInstanceStruct *)chartInstanceVoid;
  c1_mxVal = NULL;
  c1_tmp.HEADER.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c1_pData)[0])[0];
  c1_tmp.DATA.messageID = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c1_pData)[8])[0];
  c1_tmp.DATA.senderID = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA
    *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c1_pData)[8])[4];
  c1_tmp.DATA.signal_1 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c1_pData)[8])[8];
  c1_tmp.DATA.signal_2 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c1_pData)[8])[16];
  c1_tmp.DATA.signal_3 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c1_pData)[8])[24];
  c1_tmp.DATA.signal_4 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c1_pData)[8])[32];
  c1_tmp.DATA.signal_5 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c1_pData)[8])[40];
  c1_tmp.DATA.signal_6 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c1_pData)[8])[48];
  c1_tmp.DATA.signal_7 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c1_pData)[8])[56];
  c1_tmp.DATA.signal_8 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c1_pData)[8])[64];
  c1_tmp.DATA.signal_9 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c1_pData)[8])[72];
  c1_tmp.DATA.signal_10 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA
    *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c1_pData)[8])[80];
  c1_tmp.DATA.discrete_signal_1 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c1_pData)[8])[88];
  c1_tmp.DATA.discrete_signal_2 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c1_pData)[8])[92];
  c1_tmp.DATA.discrete_signal_3 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c1_pData)[8])[96];
  c1_tmp.DATA.discrete_signal_4 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c1_pData)[8])[100];
  c1_tmp.DATA.discrete_signal_5 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c1_pData)[8])[104];
  c1_tmp.DATA.discrete_signal_6 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c1_pData)[8])[108];
  c1_tmp.DATA.discrete_signal_7 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c1_pData)[8])[112];
  c1_tmp.DATA.discrete_signal_8 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c1_pData)[8])[116];
  c1_tmp.DATA.discrete_signal_9 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c1_pData)[8])[120];
  c1_tmp.DATA.discrete_signal_10 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c1_pData)[8])[124];
  sf_mex_assign(&c1_mxVal, c1_sf_marshallOut(chartInstance, &c1_tmp), false);
  return c1_mxVal;
}

static uint8_T c1_j_emlrt_marshallIn(SFc1_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_Experiment_3_cs, const char_T
  *c1_identifier)
{
  uint8_T c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_y = c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_Experiment_3_cs), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_Experiment_3_cs);
  return c1_b_y;
}

static uint8_T c1_k_emlrt_marshallIn(SFc1_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_b_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_b_y = c1_u0;
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static void init_dsm_address_info(SFc1_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_Experiment_3_csInstanceStruct
  *chartInstance)
{
  chartInstance->c1_u = (c1_PRESCAN_V2X_USER_GENERIC_MESSAGE *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c1_y = (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c1_z = (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 1);
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

void sf_c1_Experiment_3_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(929423465U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1422806264U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1951569235U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(946112406U);
}

mxArray* sf_c1_Experiment_3_cs_get_post_codegen_info(void);
mxArray *sf_c1_Experiment_3_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("fSh42xunrfxQft236QdKZH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c1_Experiment_3_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_Experiment_3_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_Experiment_3_cs_jit_fallback_info(void)
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

mxArray *sf_c1_Experiment_3_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c1_Experiment_3_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c1_Experiment_3_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c1_Experiment_3_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_Experiment_3_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_Experiment_3_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc1_Experiment_3_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Experiment_3_csMachineNumber_,
           1,
           1,
           1,
           0,
           3,
           0,
           0,
           0,
           0,
           1,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"z");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,61);
        _SFD_CV_INIT_SCRIPT(0,4,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"V2X_GENERIC_expander",0,-1,114);
        _SFD_CV_INIT_SCRIPT_FCN(0,1,"FILTER_PRESCAN_V2X_FIXED_GENERIC_MESSAGE",
          116,-1,303);
        _SFD_CV_INIT_SCRIPT_FCN(0,2,"FILTER_PRESCAN_HEADER",305,-1,372);
        _SFD_CV_INIT_SCRIPT_FCN(0,3,"FILTER_PRESCAN_V2X_FIXED_GENERIC_DATA",374,
          -1,1216);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_u_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_y_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_y_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c1_u);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c1_y);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c1_z);
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
  return "tVgmwB8rekw5e7p2xTR4WC";
}

static void sf_opaque_initialize_c1_Experiment_3_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_Experiment_3_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_Experiment_3_cs((SFc1_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
  initialize_c1_Experiment_3_cs((SFc1_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_Experiment_3_cs(void *chartInstanceVar)
{
  enable_c1_Experiment_3_cs((SFc1_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_Experiment_3_cs(void *chartInstanceVar)
{
  disable_c1_Experiment_3_cs((SFc1_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_Experiment_3_cs(void *chartInstanceVar)
{
  sf_gateway_c1_Experiment_3_cs((SFc1_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_Experiment_3_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c1_Experiment_3_cs((SFc1_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_Experiment_3_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c1_Experiment_3_cs((SFc1_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c1_Experiment_3_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_Experiment_3_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_3_cs_optimization_info();
    }

    finalize_c1_Experiment_3_cs((SFc1_Experiment_3_csInstanceStruct*)
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
  initSimStructsc1_Experiment_3_cs((SFc1_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_Experiment_3_cs(SimStruct *S)
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
    initialize_params_c1_Experiment_3_cs((SFc1_Experiment_3_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_Experiment_3_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Experiment_3_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3177528462U));
  ssSetChecksum1(S,(3206233881U));
  ssSetChecksum2(S,(1278450199U));
  ssSetChecksum3(S,(865252058U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_Experiment_3_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_Experiment_3_cs(SimStruct *S)
{
  SFc1_Experiment_3_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc1_Experiment_3_csInstanceStruct *)utMalloc(sizeof
    (SFc1_Experiment_3_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_Experiment_3_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_Experiment_3_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_Experiment_3_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_Experiment_3_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_Experiment_3_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_Experiment_3_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_Experiment_3_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_Experiment_3_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_Experiment_3_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_Experiment_3_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_Experiment_3_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_Experiment_3_cs;
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

void c1_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_Experiment_3_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_Experiment_3_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
