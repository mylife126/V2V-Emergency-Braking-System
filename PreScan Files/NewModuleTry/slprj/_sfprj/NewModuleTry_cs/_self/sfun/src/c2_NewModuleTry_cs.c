/* Include files */

#include <stddef.h>
#include "blas.h"
#include "NewModuleTry_cs_sfun.h"
#include "c2_NewModuleTry_cs.h"
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
static const char * c2_debug_family_names[5] = { "nargin", "nargout", "u", "z",
  "y" };

static const char * c2_b_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

static const char * c2_c_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

static const char * c2_d_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

static const char * c2_e_debug_family_names[5] = { "nargin", "nargout", "y", "z",
  "u" };

/* Function Declarations */
static void initialize_c2_NewModuleTry_cs(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance);
static void initialize_params_c2_NewModuleTry_cs
  (SFc2_NewModuleTry_csInstanceStruct *chartInstance);
static void enable_c2_NewModuleTry_cs(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance);
static void disable_c2_NewModuleTry_cs(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_NewModuleTry_cs
  (SFc2_NewModuleTry_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_NewModuleTry_cs
  (SFc2_NewModuleTry_csInstanceStruct *chartInstance);
static void set_sim_state_c2_NewModuleTry_cs(SFc2_NewModuleTry_csInstanceStruct *
  chartInstance, const mxArray *c2_st);
static void finalize_c2_NewModuleTry_cs(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance);
static void sf_gateway_c2_NewModuleTry_cs(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance);
static void mdl_start_c2_NewModuleTry_cs(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance);
static void initSimStructsc2_NewModuleTry_cs(SFc2_NewModuleTry_csInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_emlrt_marshallOut(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance, const c2_PRESCAN_V2X_USER_GENERIC_DATA *c2_b_u);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c2_b_y, const char_T *c2_identifier,
  c2_PRESCAN_V2X_USER_GENERIC_MESSAGE *c2_c_y);
static void c2_b_emlrt_marshallIn(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_PRESCAN_V2X_USER_GENERIC_MESSAGE *c2_b_y);
static PRESCAN_HEADER c2_c_emlrt_marshallIn(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static boolean_T c2_d_emlrt_marshallIn(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_e_emlrt_marshallIn(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_PRESCAN_V2X_USER_GENERIC_DATA *c2_b_y);
static int32_T c2_f_emlrt_marshallIn(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static real_T c2_g_emlrt_marshallIn(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_emlrt_marshallOut(SFc2_NewModuleTry_csInstanceStruct *
  chartInstance, const PRESCAN_V2X_FIXED_GENERIC_DATA *c2_b_u);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_h_emlrt_marshallIn(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  PRESCAN_V2X_FIXED_GENERIC_DATA *c2_b_y);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_i_emlrt_marshallIn(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE *c2_b_y);
static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(const mxArray **c2_info);
static const mxArray *c2_c_emlrt_marshallOut(const char * c2_b_u);
static const mxArray *c2_d_emlrt_marshallOut(const uint32_T c2_b_u);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_u_bus_io(void *chartInstanceVoid, void *c2_pData);
static const mxArray *c2_y_bus_io(void *chartInstanceVoid, void *c2_pData);
static uint8_T c2_j_emlrt_marshallIn(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_NewModuleTry_cs, const char_T
  *c2_identifier);
static uint8_T c2_k_emlrt_marshallIn(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_NewModuleTry_cs(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_is_active_c2_NewModuleTry_cs = 0U;
}

static void initialize_params_c2_NewModuleTry_cs
  (SFc2_NewModuleTry_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_NewModuleTry_cs(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_NewModuleTry_cs(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_NewModuleTry_cs
  (SFc2_NewModuleTry_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_NewModuleTry_cs
  (SFc2_NewModuleTry_csInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  PRESCAN_HEADER c2_b_u;
  const mxArray *c2_d_y = NULL;
  boolean_T c2_c_u;
  const mxArray *c2_e_y = NULL;
  c2_PRESCAN_V2X_USER_GENERIC_DATA c2_r0;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_d_u;
  const mxArray *c2_f_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createcellmatrix(2, 1), false);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c2_b_u.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    chartInstance->c2_y)[0])[0];
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c2_c_u = c2_b_u.valid;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_c_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_d_y, c2_e_y, "valid", "valid", 0);
  sf_mex_addfield(c2_c_y, c2_d_y, "HEADER", "HEADER", 0);
  c2_r0.messageID = *(int32_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)
    &((char_T *)chartInstance->c2_y)[8])[0];
  c2_r0.senderID = *(int32_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)
                                 &((char_T *)chartInstance->c2_y)[8])[4];
  c2_r0.signal_1 = *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)
                                &((char_T *)chartInstance->c2_y)[8])[8];
  c2_r0.signal_2 = *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)
                                &((char_T *)chartInstance->c2_y)[8])[16];
  c2_r0.signal_3 = *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)
                                &((char_T *)chartInstance->c2_y)[8])[24];
  c2_r0.signal_4 = *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)
                                &((char_T *)chartInstance->c2_y)[8])[32];
  c2_r0.signal_5 = *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)
                                &((char_T *)chartInstance->c2_y)[8])[40];
  c2_r0.signal_6 = *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)
                                &((char_T *)chartInstance->c2_y)[8])[48];
  c2_r0.signal_7 = *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)
                                &((char_T *)chartInstance->c2_y)[8])[56];
  c2_r0.signal_8 = *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)
                                &((char_T *)chartInstance->c2_y)[8])[64];
  c2_r0.signal_9 = *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)
                                &((char_T *)chartInstance->c2_y)[8])[72];
  c2_r0.signal_10 = *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)
                                 &((char_T *)chartInstance->c2_y)[8])[80];
  sf_mex_addfield(c2_c_y, c2_emlrt_marshallOut(chartInstance, &c2_r0), "DATA",
                  "DATA", 0);
  sf_mex_setcell(c2_b_y, 0, c2_c_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_NewModuleTry_cs;
  c2_d_u = c2_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_b_y, 1, c2_f_y);
  sf_mex_assign(&c2_st, c2_b_y, false);
  return c2_st;
}

static void set_sim_state_c2_NewModuleTry_cs(SFc2_NewModuleTry_csInstanceStruct *
  chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_b_u;
  c2_PRESCAN_V2X_USER_GENERIC_MESSAGE c2_r1;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_b_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_b_u, 0)), "y",
                      &c2_r1);
  *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)chartInstance->c2_y)[0])
    [0] = c2_r1.HEADER.valid;
  *(int32_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    chartInstance->c2_y)[8])[0] = c2_r1.DATA.messageID;
  *(int32_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    chartInstance->c2_y)[8])[4] = c2_r1.DATA.senderID;
  *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    chartInstance->c2_y)[8])[8] = c2_r1.DATA.signal_1;
  *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    chartInstance->c2_y)[8])[16] = c2_r1.DATA.signal_2;
  *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    chartInstance->c2_y)[8])[24] = c2_r1.DATA.signal_3;
  *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    chartInstance->c2_y)[8])[32] = c2_r1.DATA.signal_4;
  *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    chartInstance->c2_y)[8])[40] = c2_r1.DATA.signal_5;
  *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    chartInstance->c2_y)[8])[48] = c2_r1.DATA.signal_6;
  *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    chartInstance->c2_y)[8])[56] = c2_r1.DATA.signal_7;
  *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    chartInstance->c2_y)[8])[64] = c2_r1.DATA.signal_8;
  *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    chartInstance->c2_y)[8])[72] = c2_r1.DATA.signal_9;
  *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    chartInstance->c2_y)[8])[80] = c2_r1.DATA.signal_10;
  chartInstance->c2_is_active_c2_NewModuleTry_cs = c2_j_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_b_u, 1)),
     "is_active_c2_NewModuleTry_cs");
  sf_mex_destroy(&c2_b_u);
  c2_update_debugger_state_c2_NewModuleTry_cs(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_NewModuleTry_cs(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c2_NewModuleTry_cs(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE c2_b_u;
  c2_PRESCAN_V2X_USER_GENERIC_MESSAGE c2_b_z;
  uint32_T c2_debug_family_var_map[5];
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 1.0;
  c2_PRESCAN_V2X_USER_GENERIC_MESSAGE c2_b_y;
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE c2_c_y;
  c2_PRESCAN_V2X_USER_GENERIC_MESSAGE c2_c_z;
  real_T c2_b_nargin = 2.0;
  real_T c2_b_nargout = 1.0;
  c2_PRESCAN_V2X_USER_GENERIC_MESSAGE c2_c_u;
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE c2_d_y;
  uint32_T c2_b_debug_family_var_map[4];
  real_T c2_c_nargin = 2.0;
  real_T c2_c_nargout = 1.0;
  PRESCAN_HEADER c2_d_u;
  PRESCAN_HEADER c2_e_y;
  real_T c2_d_nargin = 2.0;
  real_T c2_d_nargout = 1.0;
  c2_PRESCAN_V2X_USER_GENERIC_DATA c2_e_u;
  PRESCAN_V2X_FIXED_GENERIC_DATA c2_f_y;
  real_T c2_e_nargin = 2.0;
  real_T c2_e_nargout = 1.0;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_b_u.HEADER.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    chartInstance->c2_u)[0])[0];
  c2_b_u.DATA.messageID = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c2_u)[8])[0];
  c2_b_u.DATA.senderID = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA
    *)&((char_T *)chartInstance->c2_u)[8])[4];
  c2_b_u.DATA.signal_1 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c2_u)[8])[8];
  c2_b_u.DATA.signal_2 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c2_u)[8])[16];
  c2_b_u.DATA.signal_3 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c2_u)[8])[24];
  c2_b_u.DATA.signal_4 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c2_u)[8])[32];
  c2_b_u.DATA.signal_5 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c2_u)[8])[40];
  c2_b_u.DATA.signal_6 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c2_u)[8])[48];
  c2_b_u.DATA.signal_7 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c2_u)[8])[56];
  c2_b_u.DATA.signal_8 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c2_u)[8])[64];
  c2_b_u.DATA.signal_9 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c2_u)[8])[72];
  c2_b_u.DATA.signal_10 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA
    *)&((char_T *)chartInstance->c2_u)[8])[80];
  c2_b_u.DATA.discrete_signal_1 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c2_u)[8])[88];
  c2_b_u.DATA.discrete_signal_2 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c2_u)[8])[92];
  c2_b_u.DATA.discrete_signal_3 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c2_u)[8])[96];
  c2_b_u.DATA.discrete_signal_4 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c2_u)[8])[100];
  c2_b_u.DATA.discrete_signal_5 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c2_u)[8])[104];
  c2_b_u.DATA.discrete_signal_6 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c2_u)[8])[108];
  c2_b_u.DATA.discrete_signal_7 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c2_u)[8])[112];
  c2_b_u.DATA.discrete_signal_8 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c2_u)[8])[116];
  c2_b_u.DATA.discrete_signal_9 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c2_u)[8])[120];
  c2_b_u.DATA.discrete_signal_10 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c2_u)[8])[124];
  c2_b_z.HEADER.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    chartInstance->c2_z)[0])[0];
  c2_b_z.DATA.messageID = *(int32_T *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c2_z)[8])[0];
  c2_b_z.DATA.senderID = *(int32_T *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c2_z)[8])[4];
  c2_b_z.DATA.signal_1 = *(real_T *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c2_z)[8])[8];
  c2_b_z.DATA.signal_2 = *(real_T *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c2_z)[8])[16];
  c2_b_z.DATA.signal_3 = *(real_T *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c2_z)[8])[24];
  c2_b_z.DATA.signal_4 = *(real_T *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c2_z)[8])[32];
  c2_b_z.DATA.signal_5 = *(real_T *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c2_z)[8])[40];
  c2_b_z.DATA.signal_6 = *(real_T *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c2_z)[8])[48];
  c2_b_z.DATA.signal_7 = *(real_T *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c2_z)[8])[56];
  c2_b_z.DATA.signal_8 = *(real_T *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c2_z)[8])[64];
  c2_b_z.DATA.signal_9 = *(real_T *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c2_z)[8])[72];
  c2_b_z.DATA.signal_10 = *(real_T *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c2_z)[8])[80];
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_u, 2U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_z, 3U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_y, 4U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_c_y = c2_b_u;
  c2_c_z = c2_b_z;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c2_e_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_y, 2U, c2_b_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_z, 3U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_y, 4U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
  c2_b_y = c2_c_z;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_c_u = c2_b_y;
  c2_d_y = c2_c_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 5U, c2_d_debug_family_names,
    c2_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargin, 0U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargout, 1U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_u, 2U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_y, 3U, c2_b_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_y, MAX_uint32_T, c2_sf_marshallOut,
    c2_sf_marshallIn);
  c2_b_y = c2_c_u;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  CV_SCRIPT_FCN(0, 1);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_d_u = c2_b_y.HEADER;
  c2_e_y = c2_d_y.HEADER;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 5U, c2_b_debug_family_names,
    c2_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_nargin, 0U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_nargout, 1U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_u, 2U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_e_y, 3U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_y.HEADER, MAX_uint32_T,
    c2_d_sf_marshallOut, c2_c_sf_marshallIn);
  c2_b_y.HEADER = c2_d_u;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  CV_SCRIPT_FCN(0, 2);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 13);
  c2_b_y.HEADER.valid = c2_e_y.valid;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -13);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_e_u = c2_b_y.DATA;
  c2_f_y = c2_d_y.DATA;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 5U, c2_c_debug_family_names,
    c2_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_e_nargin, 0U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_e_nargout, 1U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_e_u, 2U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_f_y, 3U, c2_f_sf_marshallOut,
    c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_y.DATA, MAX_uint32_T,
    c2_e_sf_marshallOut, c2_d_sf_marshallIn);
  c2_b_y.DATA = c2_e_u;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  CV_SCRIPT_FCN(0, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 17);
  c2_b_y.DATA.messageID = c2_f_y.messageID;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 18);
  c2_b_y.DATA.senderID = c2_f_y.senderID;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 19);
  c2_b_y.DATA.signal_1 = c2_f_y.signal_1;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 20);
  c2_b_y.DATA.signal_2 = c2_f_y.signal_2;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 21);
  c2_b_y.DATA.signal_3 = c2_f_y.signal_3;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 22);
  c2_b_y.DATA.signal_4 = c2_f_y.signal_4;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 23);
  c2_b_y.DATA.signal_5 = c2_f_y.signal_5;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 24);
  c2_b_y.DATA.signal_6 = c2_f_y.signal_6;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 25);
  c2_b_y.DATA.signal_7 = c2_f_y.signal_7;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 26);
  c2_b_y.DATA.signal_8 = c2_f_y.signal_8;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 27);
  c2_b_y.DATA.signal_9 = c2_f_y.signal_9;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 28);
  c2_b_y.DATA.signal_10 = c2_f_y.signal_10;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -28);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -9);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)chartInstance->c2_y)[0])
    [0] = c2_b_y.HEADER.valid;
  *(int32_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    chartInstance->c2_y)[8])[0] = c2_b_y.DATA.messageID;
  *(int32_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    chartInstance->c2_y)[8])[4] = c2_b_y.DATA.senderID;
  *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    chartInstance->c2_y)[8])[8] = c2_b_y.DATA.signal_1;
  *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    chartInstance->c2_y)[8])[16] = c2_b_y.DATA.signal_2;
  *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    chartInstance->c2_y)[8])[24] = c2_b_y.DATA.signal_3;
  *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    chartInstance->c2_y)[8])[32] = c2_b_y.DATA.signal_4;
  *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    chartInstance->c2_y)[8])[40] = c2_b_y.DATA.signal_5;
  *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    chartInstance->c2_y)[8])[48] = c2_b_y.DATA.signal_6;
  *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    chartInstance->c2_y)[8])[56] = c2_b_y.DATA.signal_7;
  *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    chartInstance->c2_y)[8])[64] = c2_b_y.DATA.signal_8;
  *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    chartInstance->c2_y)[8])[72] = c2_b_y.DATA.signal_9;
  *(real_T *)&((char_T *)(c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    chartInstance->c2_y)[8])[80] = c2_b_y.DATA.signal_10;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_NewModuleTry_csMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c2_NewModuleTry_cs(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc2_NewModuleTry_cs(SFc2_NewModuleTry_csInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)c2_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c2_chartNumber, c2_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Workspace\\PreScan Files\\NewModuleTry\\V2X_GENERIC_filter.m"));
}

static const mxArray *c2_emlrt_marshallOut(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance, const c2_PRESCAN_V2X_USER_GENERIC_DATA *c2_b_u)
{
  const mxArray *c2_b_y = NULL;
  int32_T c2_c_u;
  const mxArray *c2_c_y = NULL;
  int32_T c2_d_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_e_u;
  const mxArray *c2_e_y = NULL;
  real_T c2_f_u;
  const mxArray *c2_f_y = NULL;
  real_T c2_g_u;
  const mxArray *c2_g_y = NULL;
  real_T c2_h_u;
  const mxArray *c2_h_y = NULL;
  real_T c2_i_u;
  const mxArray *c2_i_y = NULL;
  real_T c2_j_u;
  const mxArray *c2_j_y = NULL;
  real_T c2_k_u;
  const mxArray *c2_k_y = NULL;
  real_T c2_l_u;
  const mxArray *c2_l_y = NULL;
  real_T c2_m_u;
  const mxArray *c2_m_y = NULL;
  real_T c2_n_u;
  const mxArray *c2_n_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c2_c_u = c2_b_u->messageID;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_c_y, "messageID", "messageID", 0);
  c2_d_u = c2_b_u->senderID;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_d_y, "senderID", "senderID", 0);
  c2_e_u = c2_b_u->signal_1;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_e_y, "signal_1", "signal_1", 0);
  c2_f_u = c2_b_u->signal_2;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_f_y, "signal_2", "signal_2", 0);
  c2_g_u = c2_b_u->signal_3;
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_g_y, "signal_3", "signal_3", 0);
  c2_h_u = c2_b_u->signal_4;
  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_h_y, "signal_4", "signal_4", 0);
  c2_i_u = c2_b_u->signal_5;
  c2_i_y = NULL;
  sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_i_y, "signal_5", "signal_5", 0);
  c2_j_u = c2_b_u->signal_6;
  c2_j_y = NULL;
  sf_mex_assign(&c2_j_y, sf_mex_create("y", &c2_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_j_y, "signal_6", "signal_6", 0);
  c2_k_u = c2_b_u->signal_7;
  c2_k_y = NULL;
  sf_mex_assign(&c2_k_y, sf_mex_create("y", &c2_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_k_y, "signal_7", "signal_7", 0);
  c2_l_u = c2_b_u->signal_8;
  c2_l_y = NULL;
  sf_mex_assign(&c2_l_y, sf_mex_create("y", &c2_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_l_y, "signal_8", "signal_8", 0);
  c2_m_u = c2_b_u->signal_9;
  c2_m_y = NULL;
  sf_mex_assign(&c2_m_y, sf_mex_create("y", &c2_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_m_y, "signal_9", "signal_9", 0);
  c2_n_u = c2_b_u->signal_10;
  c2_n_y = NULL;
  sf_mex_assign(&c2_n_y, sf_mex_create("y", &c2_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_n_y, "signal_10", "signal_10", 0);
  return c2_b_y;
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_PRESCAN_V2X_USER_GENERIC_MESSAGE c2_b_u;
  const mxArray *c2_b_y = NULL;
  PRESCAN_HEADER c2_c_u;
  const mxArray *c2_c_y = NULL;
  boolean_T c2_d_u;
  const mxArray *c2_d_y = NULL;
  SFc2_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc2_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(c2_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c2_c_u = c2_b_u.HEADER;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c2_d_u = c2_c_u.valid;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_d_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_c_y, c2_d_y, "valid", "valid", 0);
  sf_mex_addfield(c2_b_y, c2_c_y, "HEADER", "HEADER", 0);
  sf_mex_addfield(c2_b_y, c2_emlrt_marshallOut(chartInstance, &c2_b_u.DATA),
                  "DATA", "DATA", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c2_b_y, const char_T *c2_identifier,
  c2_PRESCAN_V2X_USER_GENERIC_MESSAGE *c2_c_y)
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_y), &c2_thisId, c2_c_y);
  sf_mex_destroy(&c2_b_y);
}

static void c2_b_emlrt_marshallIn(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_PRESCAN_V2X_USER_GENERIC_MESSAGE *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[2] = { "HEADER", "DATA" };

  c2_thisId.fParent = c2_parentId;
  sf_mex_check_struct(c2_parentId, c2_b_u, 2, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "HEADER";
  c2_b_y->HEADER = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "HEADER", "HEADER", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "DATA";
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_b_u, "DATA",
    "DATA", 0)), &c2_thisId, &c2_b_y->DATA);
  sf_mex_destroy(&c2_b_u);
}

static PRESCAN_HEADER c2_c_emlrt_marshallIn(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  PRESCAN_HEADER c2_b_y;
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[1] = { "valid" };

  c2_thisId.fParent = c2_parentId;
  sf_mex_check_struct(c2_parentId, c2_b_u, 1, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "valid";
  c2_b_y.valid = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c2_b_u, "valid", "valid", 0)),
    &c2_thisId);
  sf_mex_destroy(&c2_b_u);
  return c2_b_y;
}

static boolean_T c2_d_emlrt_marshallIn(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  boolean_T c2_b_y;
  boolean_T c2_b0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_b0, 1, 11, 0U, 0, 0U, 0);
  c2_b_y = c2_b0;
  sf_mex_destroy(&c2_b_u);
  return c2_b_y;
}

static void c2_e_emlrt_marshallIn(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  c2_PRESCAN_V2X_USER_GENERIC_DATA *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[12] = { "messageID", "senderID", "signal_1",
    "signal_2", "signal_3", "signal_4", "signal_5", "signal_6", "signal_7",
    "signal_8", "signal_9", "signal_10" };

  c2_thisId.fParent = c2_parentId;
  sf_mex_check_struct(c2_parentId, c2_b_u, 12, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "messageID";
  c2_b_y->messageID = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "messageID", "messageID", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "senderID";
  c2_b_y->senderID = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "senderID", "senderID", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "signal_1";
  c2_b_y->signal_1 = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "signal_1", "signal_1", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "signal_2";
  c2_b_y->signal_2 = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "signal_2", "signal_2", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "signal_3";
  c2_b_y->signal_3 = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "signal_3", "signal_3", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "signal_4";
  c2_b_y->signal_4 = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "signal_4", "signal_4", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "signal_5";
  c2_b_y->signal_5 = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "signal_5", "signal_5", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "signal_6";
  c2_b_y->signal_6 = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "signal_6", "signal_6", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "signal_7";
  c2_b_y->signal_7 = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "signal_7", "signal_7", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "signal_8";
  c2_b_y->signal_8 = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "signal_8", "signal_8", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "signal_9";
  c2_b_y->signal_9 = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "signal_9", "signal_9", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "signal_10";
  c2_b_y->signal_10 = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "signal_10", "signal_10", 0)), &c2_thisId);
  sf_mex_destroy(&c2_b_u);
}

static int32_T c2_f_emlrt_marshallIn(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_b_y;
  int32_T c2_i0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_i0, 1, 6, 0U, 0, 0U, 0);
  c2_b_y = c2_i0;
  sf_mex_destroy(&c2_b_u);
  return c2_b_y;
}

static real_T c2_g_emlrt_marshallIn(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_b_y;
  real_T c2_d0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_b_y = c2_d0;
  sf_mex_destroy(&c2_b_u);
  return c2_b_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_y;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_PRESCAN_V2X_USER_GENERIC_MESSAGE c2_c_y;
  SFc2_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc2_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c2_b_y = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_y), &c2_thisId, &c2_c_y);
  sf_mex_destroy(&c2_b_y);
  *(c2_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c2_outData = c2_c_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_emlrt_marshallOut(SFc2_NewModuleTry_csInstanceStruct *
  chartInstance, const PRESCAN_V2X_FIXED_GENERIC_DATA *c2_b_u)
{
  const mxArray *c2_b_y = NULL;
  int32_T c2_c_u;
  const mxArray *c2_c_y = NULL;
  int32_T c2_d_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_e_u;
  const mxArray *c2_e_y = NULL;
  real_T c2_f_u;
  const mxArray *c2_f_y = NULL;
  real_T c2_g_u;
  const mxArray *c2_g_y = NULL;
  real_T c2_h_u;
  const mxArray *c2_h_y = NULL;
  real_T c2_i_u;
  const mxArray *c2_i_y = NULL;
  real_T c2_j_u;
  const mxArray *c2_j_y = NULL;
  real_T c2_k_u;
  const mxArray *c2_k_y = NULL;
  real_T c2_l_u;
  const mxArray *c2_l_y = NULL;
  real_T c2_m_u;
  const mxArray *c2_m_y = NULL;
  real_T c2_n_u;
  const mxArray *c2_n_y = NULL;
  int32_T c2_o_u;
  const mxArray *c2_o_y = NULL;
  int32_T c2_p_u;
  const mxArray *c2_p_y = NULL;
  int32_T c2_q_u;
  const mxArray *c2_q_y = NULL;
  int32_T c2_r_u;
  const mxArray *c2_r_y = NULL;
  int32_T c2_s_u;
  const mxArray *c2_s_y = NULL;
  int32_T c2_t_u;
  const mxArray *c2_t_y = NULL;
  int32_T c2_u_u;
  const mxArray *c2_u_y = NULL;
  int32_T c2_v_u;
  const mxArray *c2_v_y = NULL;
  int32_T c2_w_u;
  const mxArray *c2_w_y = NULL;
  int32_T c2_x_u;
  const mxArray *c2_x_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c2_c_u = c2_b_u->messageID;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_c_y, "messageID", "messageID", 0);
  c2_d_u = c2_b_u->senderID;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_d_y, "senderID", "senderID", 0);
  c2_e_u = c2_b_u->signal_1;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_e_y, "signal_1", "signal_1", 0);
  c2_f_u = c2_b_u->signal_2;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_f_y, "signal_2", "signal_2", 0);
  c2_g_u = c2_b_u->signal_3;
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_g_y, "signal_3", "signal_3", 0);
  c2_h_u = c2_b_u->signal_4;
  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_h_y, "signal_4", "signal_4", 0);
  c2_i_u = c2_b_u->signal_5;
  c2_i_y = NULL;
  sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_i_y, "signal_5", "signal_5", 0);
  c2_j_u = c2_b_u->signal_6;
  c2_j_y = NULL;
  sf_mex_assign(&c2_j_y, sf_mex_create("y", &c2_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_j_y, "signal_6", "signal_6", 0);
  c2_k_u = c2_b_u->signal_7;
  c2_k_y = NULL;
  sf_mex_assign(&c2_k_y, sf_mex_create("y", &c2_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_k_y, "signal_7", "signal_7", 0);
  c2_l_u = c2_b_u->signal_8;
  c2_l_y = NULL;
  sf_mex_assign(&c2_l_y, sf_mex_create("y", &c2_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_l_y, "signal_8", "signal_8", 0);
  c2_m_u = c2_b_u->signal_9;
  c2_m_y = NULL;
  sf_mex_assign(&c2_m_y, sf_mex_create("y", &c2_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_m_y, "signal_9", "signal_9", 0);
  c2_n_u = c2_b_u->signal_10;
  c2_n_y = NULL;
  sf_mex_assign(&c2_n_y, sf_mex_create("y", &c2_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_n_y, "signal_10", "signal_10", 0);
  c2_o_u = c2_b_u->discrete_signal_1;
  c2_o_y = NULL;
  sf_mex_assign(&c2_o_y, sf_mex_create("y", &c2_o_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_o_y, "discrete_signal_1", "discrete_signal_1", 0);
  c2_p_u = c2_b_u->discrete_signal_2;
  c2_p_y = NULL;
  sf_mex_assign(&c2_p_y, sf_mex_create("y", &c2_p_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_p_y, "discrete_signal_2", "discrete_signal_2", 0);
  c2_q_u = c2_b_u->discrete_signal_3;
  c2_q_y = NULL;
  sf_mex_assign(&c2_q_y, sf_mex_create("y", &c2_q_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_q_y, "discrete_signal_3", "discrete_signal_3", 0);
  c2_r_u = c2_b_u->discrete_signal_4;
  c2_r_y = NULL;
  sf_mex_assign(&c2_r_y, sf_mex_create("y", &c2_r_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_r_y, "discrete_signal_4", "discrete_signal_4", 0);
  c2_s_u = c2_b_u->discrete_signal_5;
  c2_s_y = NULL;
  sf_mex_assign(&c2_s_y, sf_mex_create("y", &c2_s_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_s_y, "discrete_signal_5", "discrete_signal_5", 0);
  c2_t_u = c2_b_u->discrete_signal_6;
  c2_t_y = NULL;
  sf_mex_assign(&c2_t_y, sf_mex_create("y", &c2_t_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_t_y, "discrete_signal_6", "discrete_signal_6", 0);
  c2_u_u = c2_b_u->discrete_signal_7;
  c2_u_y = NULL;
  sf_mex_assign(&c2_u_y, sf_mex_create("y", &c2_u_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_u_y, "discrete_signal_7", "discrete_signal_7", 0);
  c2_v_u = c2_b_u->discrete_signal_8;
  c2_v_y = NULL;
  sf_mex_assign(&c2_v_y, sf_mex_create("y", &c2_v_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_v_y, "discrete_signal_8", "discrete_signal_8", 0);
  c2_w_u = c2_b_u->discrete_signal_9;
  c2_w_y = NULL;
  sf_mex_assign(&c2_w_y, sf_mex_create("y", &c2_w_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_w_y, "discrete_signal_9", "discrete_signal_9", 0);
  c2_x_u = c2_b_u->discrete_signal_10;
  c2_x_y = NULL;
  sf_mex_assign(&c2_x_y, sf_mex_create("y", &c2_x_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_x_y, "discrete_signal_10", "discrete_signal_10", 0);
  return c2_b_y;
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE c2_b_u;
  const mxArray *c2_b_y = NULL;
  PRESCAN_HEADER c2_c_u;
  const mxArray *c2_c_y = NULL;
  boolean_T c2_d_u;
  const mxArray *c2_d_y = NULL;
  SFc2_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc2_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c2_c_u = c2_b_u.HEADER;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c2_d_u = c2_c_u.valid;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_d_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_c_y, c2_d_y, "valid", "valid", 0);
  sf_mex_addfield(c2_b_y, c2_c_y, "HEADER", "HEADER", 0);
  sf_mex_addfield(c2_b_y, c2_b_emlrt_marshallOut(chartInstance, &c2_b_u.DATA),
                  "DATA", "DATA", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc2_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(real_T *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y;
  SFc2_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc2_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout),
    &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  PRESCAN_HEADER c2_b_u;
  const mxArray *c2_b_y = NULL;
  boolean_T c2_c_u;
  const mxArray *c2_c_y = NULL;
  SFc2_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc2_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(PRESCAN_HEADER *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c2_c_u = c2_b_u.valid;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_c_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_b_y, c2_c_y, "valid", "valid", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_u;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  PRESCAN_HEADER c2_b_y;
  SFc2_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc2_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c2_b_u = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_u), &c2_thisId);
  sf_mex_destroy(&c2_b_u);
  *(PRESCAN_HEADER *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  SFc2_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc2_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  sf_mex_assign(&c2_mxArrayOutData, c2_emlrt_marshallOut(chartInstance,
    (c2_PRESCAN_V2X_USER_GENERIC_DATA *)c2_inData), false);
  return c2_mxArrayOutData;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_u;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_PRESCAN_V2X_USER_GENERIC_DATA c2_b_y;
  SFc2_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc2_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c2_b_u = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_u), &c2_thisId, &c2_b_y);
  sf_mex_destroy(&c2_b_u);
  *(c2_PRESCAN_V2X_USER_GENERIC_DATA *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  SFc2_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc2_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  sf_mex_assign(&c2_mxArrayOutData, c2_b_emlrt_marshallOut(chartInstance,
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)c2_inData), false);
  return c2_mxArrayOutData;
}

static void c2_h_emlrt_marshallIn(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  PRESCAN_V2X_FIXED_GENERIC_DATA *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[22] = { "messageID", "senderID", "signal_1",
    "signal_2", "signal_3", "signal_4", "signal_5", "signal_6", "signal_7",
    "signal_8", "signal_9", "signal_10", "discrete_signal_1",
    "discrete_signal_2", "discrete_signal_3", "discrete_signal_4",
    "discrete_signal_5", "discrete_signal_6", "discrete_signal_7",
    "discrete_signal_8", "discrete_signal_9", "discrete_signal_10" };

  c2_thisId.fParent = c2_parentId;
  sf_mex_check_struct(c2_parentId, c2_b_u, 22, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "messageID";
  c2_b_y->messageID = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "messageID", "messageID", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "senderID";
  c2_b_y->senderID = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "senderID", "senderID", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "signal_1";
  c2_b_y->signal_1 = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "signal_1", "signal_1", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "signal_2";
  c2_b_y->signal_2 = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "signal_2", "signal_2", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "signal_3";
  c2_b_y->signal_3 = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "signal_3", "signal_3", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "signal_4";
  c2_b_y->signal_4 = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "signal_4", "signal_4", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "signal_5";
  c2_b_y->signal_5 = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "signal_5", "signal_5", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "signal_6";
  c2_b_y->signal_6 = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "signal_6", "signal_6", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "signal_7";
  c2_b_y->signal_7 = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "signal_7", "signal_7", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "signal_8";
  c2_b_y->signal_8 = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "signal_8", "signal_8", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "signal_9";
  c2_b_y->signal_9 = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "signal_9", "signal_9", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "signal_10";
  c2_b_y->signal_10 = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "signal_10", "signal_10", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "discrete_signal_1";
  c2_b_y->discrete_signal_1 = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "discrete_signal_1", "discrete_signal_1", 0)),
    &c2_thisId);
  c2_thisId.fIdentifier = "discrete_signal_2";
  c2_b_y->discrete_signal_2 = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "discrete_signal_2", "discrete_signal_2", 0)),
    &c2_thisId);
  c2_thisId.fIdentifier = "discrete_signal_3";
  c2_b_y->discrete_signal_3 = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "discrete_signal_3", "discrete_signal_3", 0)),
    &c2_thisId);
  c2_thisId.fIdentifier = "discrete_signal_4";
  c2_b_y->discrete_signal_4 = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "discrete_signal_4", "discrete_signal_4", 0)),
    &c2_thisId);
  c2_thisId.fIdentifier = "discrete_signal_5";
  c2_b_y->discrete_signal_5 = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "discrete_signal_5", "discrete_signal_5", 0)),
    &c2_thisId);
  c2_thisId.fIdentifier = "discrete_signal_6";
  c2_b_y->discrete_signal_6 = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "discrete_signal_6", "discrete_signal_6", 0)),
    &c2_thisId);
  c2_thisId.fIdentifier = "discrete_signal_7";
  c2_b_y->discrete_signal_7 = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "discrete_signal_7", "discrete_signal_7", 0)),
    &c2_thisId);
  c2_thisId.fIdentifier = "discrete_signal_8";
  c2_b_y->discrete_signal_8 = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "discrete_signal_8", "discrete_signal_8", 0)),
    &c2_thisId);
  c2_thisId.fIdentifier = "discrete_signal_9";
  c2_b_y->discrete_signal_9 = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "discrete_signal_9", "discrete_signal_9", 0)),
    &c2_thisId);
  c2_thisId.fIdentifier = "discrete_signal_10";
  c2_b_y->discrete_signal_10 = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "discrete_signal_10", "discrete_signal_10", 0)),
    &c2_thisId);
  sf_mex_destroy(&c2_b_u);
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_y;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  PRESCAN_V2X_FIXED_GENERIC_DATA c2_c_y;
  SFc2_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc2_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c2_b_y = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_y), &c2_thisId, &c2_c_y);
  sf_mex_destroy(&c2_b_y);
  *(PRESCAN_V2X_FIXED_GENERIC_DATA *)c2_outData = c2_c_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static void c2_i_emlrt_marshallIn(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE *c2_b_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[2] = { "HEADER", "DATA" };

  c2_thisId.fParent = c2_parentId;
  sf_mex_check_struct(c2_parentId, c2_b_u, 2, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "HEADER";
  c2_b_y->HEADER = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_b_u, "HEADER", "HEADER", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "DATA";
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_b_u, "DATA",
    "DATA", 0)), &c2_thisId, &c2_b_y->DATA);
  sf_mex_destroy(&c2_b_u);
}

static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_y;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE c2_c_y;
  SFc2_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc2_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c2_b_y = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_y), &c2_thisId, &c2_c_y);
  sf_mex_destroy(&c2_b_y);
  *(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c2_outData = c2_c_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_NewModuleTry_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_createstruct("structure", 2, 1, 1),
                false);
  c2_info_helper(&c2_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(const mxArray **c2_info)
{
  const mxArray *c2_rhs0 = NULL;
  const mxArray *c2_lhs0 = NULL;
  sf_mex_addfield(*c2_info, c2_c_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c2_info, c2_c_emlrt_marshallOut("V2X_GENERIC_filter"), "name",
                  "name", 0);
  sf_mex_addfield(*c2_info, c2_c_emlrt_marshallOut("struct"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c2_info, c2_c_emlrt_marshallOut(
    "[E]C:/Workspace/PreScan Files/NewModuleTry/V2X_GENERIC_filter.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c2_info, c2_d_emlrt_marshallOut(1520539881U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c2_info, c2_d_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c2_info, c2_d_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c2_info, c2_d_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c2_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs0), "lhs", "lhs", 0);
  sf_mex_destroy(&c2_rhs0);
  sf_mex_destroy(&c2_lhs0);
}

static const mxArray *c2_c_emlrt_marshallOut(const char * c2_b_u)
{
  const mxArray *c2_b_y = NULL;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 15, 0U, 0U, 0U, 2, 1, strlen
                 (c2_b_u)), false);
  return c2_b_y;
}

static const mxArray *c2_d_emlrt_marshallOut(const uint32_T c2_b_u)
{
  const mxArray *c2_b_y = NULL;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 7, 0U, 0U, 0U, 0), false);
  return c2_b_y;
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc2_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(int32_T *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_b_y;
  SFc2_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc2_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_u_bus_io(void *chartInstanceVoid, void *c2_pData)
{
  const mxArray *c2_mxVal = NULL;
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE c2_tmp;
  SFc2_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc2_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c2_mxVal = NULL;
  c2_tmp.HEADER.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c2_pData)[0])[0];
  c2_tmp.DATA.messageID = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c2_pData)[8])[0];
  c2_tmp.DATA.senderID = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA
    *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c2_pData)[8])[4];
  c2_tmp.DATA.signal_1 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c2_pData)[8])[8];
  c2_tmp.DATA.signal_2 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c2_pData)[8])[16];
  c2_tmp.DATA.signal_3 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c2_pData)[8])[24];
  c2_tmp.DATA.signal_4 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c2_pData)[8])[32];
  c2_tmp.DATA.signal_5 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c2_pData)[8])[40];
  c2_tmp.DATA.signal_6 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c2_pData)[8])[48];
  c2_tmp.DATA.signal_7 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c2_pData)[8])[56];
  c2_tmp.DATA.signal_8 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c2_pData)[8])[64];
  c2_tmp.DATA.signal_9 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c2_pData)[8])[72];
  c2_tmp.DATA.signal_10 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA
    *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c2_pData)[8])[80];
  c2_tmp.DATA.discrete_signal_1 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c2_pData)[8])[88];
  c2_tmp.DATA.discrete_signal_2 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c2_pData)[8])[92];
  c2_tmp.DATA.discrete_signal_3 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c2_pData)[8])[96];
  c2_tmp.DATA.discrete_signal_4 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c2_pData)[8])[100];
  c2_tmp.DATA.discrete_signal_5 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c2_pData)[8])[104];
  c2_tmp.DATA.discrete_signal_6 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c2_pData)[8])[108];
  c2_tmp.DATA.discrete_signal_7 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c2_pData)[8])[112];
  c2_tmp.DATA.discrete_signal_8 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c2_pData)[8])[116];
  c2_tmp.DATA.discrete_signal_9 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c2_pData)[8])[120];
  c2_tmp.DATA.discrete_signal_10 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c2_pData)[8])[124];
  sf_mex_assign(&c2_mxVal, c2_b_sf_marshallOut(chartInstance, &c2_tmp), false);
  return c2_mxVal;
}

static const mxArray *c2_y_bus_io(void *chartInstanceVoid, void *c2_pData)
{
  const mxArray *c2_mxVal = NULL;
  c2_PRESCAN_V2X_USER_GENERIC_MESSAGE c2_tmp;
  SFc2_NewModuleTry_csInstanceStruct *chartInstance;
  chartInstance = (SFc2_NewModuleTry_csInstanceStruct *)chartInstanceVoid;
  c2_mxVal = NULL;
  c2_tmp.HEADER.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c2_pData)[0])[0];
  c2_tmp.DATA.messageID = *(int32_T *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c2_pData)[8])[0];
  c2_tmp.DATA.senderID = *(int32_T *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c2_pData)[8])[4];
  c2_tmp.DATA.signal_1 = *(real_T *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c2_pData)[8])[8];
  c2_tmp.DATA.signal_2 = *(real_T *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c2_pData)[8])[16];
  c2_tmp.DATA.signal_3 = *(real_T *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c2_pData)[8])[24];
  c2_tmp.DATA.signal_4 = *(real_T *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c2_pData)[8])[32];
  c2_tmp.DATA.signal_5 = *(real_T *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c2_pData)[8])[40];
  c2_tmp.DATA.signal_6 = *(real_T *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c2_pData)[8])[48];
  c2_tmp.DATA.signal_7 = *(real_T *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c2_pData)[8])[56];
  c2_tmp.DATA.signal_8 = *(real_T *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c2_pData)[8])[64];
  c2_tmp.DATA.signal_9 = *(real_T *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c2_pData)[8])[72];
  c2_tmp.DATA.signal_10 = *(real_T *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c2_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c2_pData)[8])[80];
  sf_mex_assign(&c2_mxVal, c2_sf_marshallOut(chartInstance, &c2_tmp), false);
  return c2_mxVal;
}

static uint8_T c2_j_emlrt_marshallIn(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_NewModuleTry_cs, const char_T
  *c2_identifier)
{
  uint8_T c2_b_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_y = c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_NewModuleTry_cs), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_NewModuleTry_cs);
  return c2_b_y;
}

static uint8_T c2_k_emlrt_marshallIn(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_b_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_b_y = c2_u0;
  sf_mex_destroy(&c2_b_u);
  return c2_b_y;
}

static void init_dsm_address_info(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  chartInstance->c2_u = (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c2_y = (c2_PRESCAN_V2X_USER_GENERIC_MESSAGE *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c2_z = (c2_PRESCAN_V2X_USER_GENERIC_MESSAGE *)
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

void sf_c2_NewModuleTry_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(303539243U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2056086776U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3492210724U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4022039605U);
}

mxArray* sf_c2_NewModuleTry_cs_get_post_codegen_info(void);
mxArray *sf_c2_NewModuleTry_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("266KwvHuk1XjBREeeQFteD");
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
    mxArray* mxPostCodegenInfo = sf_c2_NewModuleTry_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_NewModuleTry_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_NewModuleTry_cs_jit_fallback_info(void)
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

mxArray *sf_c2_NewModuleTry_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c2_NewModuleTry_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c2_NewModuleTry_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c2_NewModuleTry_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_NewModuleTry_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_NewModuleTry_csInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc2_NewModuleTry_csInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _NewModuleTry_csMachineNumber_,
           2,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,59);
        _SFD_CV_INIT_SCRIPT(0,4,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"V2X_GENERIC_filter",0,-1,111);
        _SFD_CV_INIT_SCRIPT_FCN(0,1,"FILTER_PRESCAN_V2X_USER_GENERIC_MESSAGE",
          113,-1,298);
        _SFD_CV_INIT_SCRIPT_FCN(0,2,"FILTER_PRESCAN_HEADER",300,-1,367);
        _SFD_CV_INIT_SCRIPT_FCN(0,3,"FILTER_PRESCAN_V2X_USER_GENERIC_DATA",369,
          -1,758);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_u_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_y_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_y_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c2_u);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c2_y);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c2_z);
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
  return "Z6Nl4HTZlUPOTU58lXMsGF";
}

static void sf_opaque_initialize_c2_NewModuleTry_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_NewModuleTry_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_NewModuleTry_cs((SFc2_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
  initialize_c2_NewModuleTry_cs((SFc2_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_NewModuleTry_cs(void *chartInstanceVar)
{
  enable_c2_NewModuleTry_cs((SFc2_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_NewModuleTry_cs(void *chartInstanceVar)
{
  disable_c2_NewModuleTry_cs((SFc2_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_NewModuleTry_cs(void *chartInstanceVar)
{
  sf_gateway_c2_NewModuleTry_cs((SFc2_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_NewModuleTry_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c2_NewModuleTry_cs((SFc2_NewModuleTry_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_NewModuleTry_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c2_NewModuleTry_cs((SFc2_NewModuleTry_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c2_NewModuleTry_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_NewModuleTry_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_NewModuleTry_cs_optimization_info();
    }

    finalize_c2_NewModuleTry_cs((SFc2_NewModuleTry_csInstanceStruct*)
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
  initSimStructsc2_NewModuleTry_cs((SFc2_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_NewModuleTry_cs(SimStruct *S)
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
    initialize_params_c2_NewModuleTry_cs((SFc2_NewModuleTry_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_NewModuleTry_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_NewModuleTry_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3137292531U));
  ssSetChecksum1(S,(3532509019U));
  ssSetChecksum2(S,(2725201343U));
  ssSetChecksum3(S,(4260382591U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_NewModuleTry_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_NewModuleTry_cs(SimStruct *S)
{
  SFc2_NewModuleTry_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc2_NewModuleTry_csInstanceStruct *)utMalloc(sizeof
    (SFc2_NewModuleTry_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_NewModuleTry_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_NewModuleTry_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_NewModuleTry_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_NewModuleTry_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_NewModuleTry_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_NewModuleTry_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_NewModuleTry_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_NewModuleTry_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_NewModuleTry_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_NewModuleTry_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_NewModuleTry_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_NewModuleTry_cs;
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

void c2_NewModuleTry_cs_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_NewModuleTry_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_NewModuleTry_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_NewModuleTry_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_NewModuleTry_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
