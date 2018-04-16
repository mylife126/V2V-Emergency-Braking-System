/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_cs_sfun.h"
#include "c1_Experiment_cs.h"
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(NULL,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c1_Experiment_cs(SFc1_Experiment_csInstanceStruct
  *chartInstance);
static void initialize_params_c1_Experiment_cs(SFc1_Experiment_csInstanceStruct *
  chartInstance);
static void enable_c1_Experiment_cs(SFc1_Experiment_csInstanceStruct
  *chartInstance);
static void disable_c1_Experiment_cs(SFc1_Experiment_csInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_Experiment_cs
  (SFc1_Experiment_csInstanceStruct *chartInstance);
static void set_sim_state_c1_Experiment_cs(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_Experiment_cs(SFc1_Experiment_csInstanceStruct
  *chartInstance);
static void sf_gateway_c1_Experiment_cs(SFc1_Experiment_csInstanceStruct
  *chartInstance);
static void mdl_start_c1_Experiment_cs(SFc1_Experiment_csInstanceStruct
  *chartInstance);
static void c1_chartstep_c1_Experiment_cs(SFc1_Experiment_csInstanceStruct
  *chartInstance);
static void initSimStructsc1_Experiment_cs(SFc1_Experiment_csInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static void c1_info_helper(const mxArray **c1_info);
static const mxArray *c1_emlrt_marshallOut(const char * c1_u);
static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u);
static void c1_b_info_helper(const mxArray **c1_info);
static void c1_localToGlobalCoordinates(SFc1_Experiment_csInstanceStruct
  *chartInstance, real_T c1_localX, real_T c1_localY, real_T c1_origin[3],
  real_T c1_sinOriginYaw, real_T c1_cosOriginYaw, real_T c1_offset, real_T
  c1_offsetSin, real_T c1_offsetCos, real_T *c1_globalX, real_T *c1_globalY);
static real_T c1_norm(SFc1_Experiment_csInstanceStruct *chartInstance, real_T
                      c1_x[2]);
static void c1_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct *chartInstance,
  const mxArray *c1_b_Actor_traj_angle, const char_T *c1_identifier, real_T
  c1_y[2]);
static void c1_b_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[2]);
static void c1_c_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_b_pref, const char_T *c1_identifier, real_T
  c1_y[4]);
static void c1_d_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[4]);
static void c1_e_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_b_Actor_traj_anglePersist, const char_T
  *c1_identifier, real_T c1_y[2]);
static void c1_f_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[2]);
static void c1_g_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_b_Actor_traj_distancePersist, const char_T
  *c1_identifier, real_T c1_y[2]);
static void c1_h_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[2]);
static void c1_i_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_b_ActualTrajectoryIndex, const char_T
  *c1_identifier, real_T c1_y[2]);
static void c1_j_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[2]);
static real_T c1_k_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_b_Counter, const char_T *c1_identifier);
static real_T c1_l_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_m_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_b_prefPersist, const char_T *c1_identifier,
  real_T c1_y[4]);
static void c1_n_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[4]);
static uint8_T c1_o_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_Experiment_cs, const char_T
  *c1_identifier);
static uint8_T c1_p_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_Experiment_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc1_Experiment_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_Experiment_cs(SFc1_Experiment_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_Counter_not_empty = false;
  chartInstance->c1_Actor_traj_distancePersist_not_empty = false;
  chartInstance->c1_Actor_traj_anglePersist_not_empty = false;
  chartInstance->c1_ActualTrajectoryIndex_not_empty = false;
  chartInstance->c1_prefPersist_not_empty = false;
  chartInstance->c1_is_active_c1_Experiment_cs = 0U;
}

static void initialize_params_c1_Experiment_cs(SFc1_Experiment_csInstanceStruct *
  chartInstance)
{
  real_T c1_dv0[397];
  int32_T c1_i0;
  real_T c1_dv1[397];
  sf_mex_import_named("Traj_x", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c1_dv0, 0, 0, 0U, 1, 0U, 1, 397);
  for (c1_i0 = 0; c1_i0 < 397; c1_i0++) {
    chartInstance->c1_Traj_x[c1_i0] = c1_dv0[c1_i0];
  }

  sf_mex_import_named("Traj_y", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      c1_dv1, 0, 0, 0U, 1, 0U, 1, 397);
  for (c1_i0 = 0; c1_i0 < 397; c1_i0++) {
    chartInstance->c1_Traj_y[c1_i0] = c1_dv1[c1_i0];
  }
}

static void enable_c1_Experiment_cs(SFc1_Experiment_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_Experiment_cs(SFc1_Experiment_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static const mxArray *get_sim_state_c1_Experiment_cs
  (SFc1_Experiment_csInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i1;
  real_T c1_u[2];
  const mxArray *c1_b_y = NULL;
  real_T c1_b_u[2];
  const mxArray *c1_c_y = NULL;
  real_T c1_c_u[4];
  const mxArray *c1_d_y = NULL;
  real_T c1_d_u[2];
  const mxArray *c1_e_y = NULL;
  real_T c1_e_u[2];
  const mxArray *c1_f_y = NULL;
  real_T c1_f_u[2];
  const mxArray *c1_g_y = NULL;
  real_T c1_g_u;
  const mxArray *c1_h_y = NULL;
  real_T c1_h_u[4];
  const mxArray *c1_i_y = NULL;
  uint8_T c1_i_u;
  const mxArray *c1_j_y = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(9, 1), false);
  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_u[c1_i1] = (*chartInstance->c1_Actor_traj_angle)[c1_i1];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_b_u[c1_i1] = (*chartInstance->c1_Actor_traj_distance)[c1_i1];
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  for (c1_i1 = 0; c1_i1 < 4; c1_i1++) {
    c1_c_u[c1_i1] = (*chartInstance->c1_pref)[c1_i1];
  }

  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_d_u[c1_i1] = chartInstance->c1_Actor_traj_anglePersist[c1_i1];
  }

  c1_e_y = NULL;
  if (!chartInstance->c1_Actor_traj_anglePersist_not_empty) {
    sf_mex_assign(&c1_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_d_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  false);
  }

  sf_mex_setcell(c1_y, 3, c1_e_y);
  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_e_u[c1_i1] = chartInstance->c1_Actor_traj_distancePersist[c1_i1];
  }

  c1_f_y = NULL;
  if (!chartInstance->c1_Actor_traj_distancePersist_not_empty) {
    sf_mex_assign(&c1_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_e_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  false);
  }

  sf_mex_setcell(c1_y, 4, c1_f_y);
  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_f_u[c1_i1] = chartInstance->c1_ActualTrajectoryIndex[c1_i1];
  }

  c1_g_y = NULL;
  if (!chartInstance->c1_ActualTrajectoryIndex_not_empty) {
    sf_mex_assign(&c1_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_f_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  false);
  }

  sf_mex_setcell(c1_y, 5, c1_g_y);
  c1_g_u = chartInstance->c1_Counter;
  c1_h_y = NULL;
  if (!chartInstance->c1_Counter_not_empty) {
    sf_mex_assign(&c1_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_g_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c1_y, 6, c1_h_y);
  for (c1_i1 = 0; c1_i1 < 4; c1_i1++) {
    c1_h_u[c1_i1] = chartInstance->c1_prefPersist[c1_i1];
  }

  c1_i_y = NULL;
  if (!chartInstance->c1_prefPersist_not_empty) {
    sf_mex_assign(&c1_i_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_i_y, sf_mex_create("y", c1_h_u, 0, 0U, 1U, 0U, 2, 2, 2),
                  false);
  }

  sf_mex_setcell(c1_y, 7, c1_i_y);
  c1_i_u = chartInstance->c1_is_active_c1_Experiment_cs;
  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", &c1_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 8, c1_j_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_Experiment_cs(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
                      "Actor_traj_angle", *chartInstance->c1_Actor_traj_angle);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
                      "Actor_traj_distance",
                      *chartInstance->c1_Actor_traj_distance);
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
                        "pref", *chartInstance->c1_pref);
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 3)),
                        "Actor_traj_anglePersist",
                        chartInstance->c1_Actor_traj_anglePersist);
  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 4)),
                        "Actor_traj_distancePersist",
                        chartInstance->c1_Actor_traj_distancePersist);
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 5)),
                        "ActualTrajectoryIndex",
                        chartInstance->c1_ActualTrajectoryIndex);
  chartInstance->c1_Counter = c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 6)), "Counter");
  c1_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 7)),
                        "prefPersist", chartInstance->c1_prefPersist);
  chartInstance->c1_is_active_c1_Experiment_cs = c1_o_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 8)),
     "is_active_c1_Experiment_cs");
  sf_mex_destroy(&c1_u);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_Experiment_cs(SFc1_Experiment_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c1_Experiment_cs(SFc1_Experiment_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  c1_chartstep_c1_Experiment_cs(chartInstance);
}

static void mdl_start_c1_Experiment_cs(SFc1_Experiment_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_chartstep_c1_Experiment_cs(SFc1_Experiment_csInstanceStruct
  *chartInstance)
{
  int32_T c1_k;
  real_T c1_b_pvp[4];
  real_T c1_b_ActorOffset_Left_Right;
  real_T c1_b_TrajOffset_x_y_Y[3];
  real_T c1_b_p0[3];
  real_T c1_Traj_xGlobal[794];
  real_T c1_Traj_yGlobal[794];
  real_T c1_ii[2];
  real_T c1_cosTrajOffset3;
  real_T c1_sinTrajOffset3;
  int32_T c1_j;
  static real_T c1_c_Traj_y[397] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0002025874200626E-9,
    1.0045795306723448E-9, 1.0089564739246271E-9, 1.0133405226042669E-9,
    1.0177245712839067E-9, 1.0221157253909041E-9, 1.0265068794979015E-9,
    1.0309051390322566E-9, 1.0353105039939692E-9, 1.0397158689556818E-9,
    1.044128339344752E-9, 1.0485408097338222E-9, 1.05296038555025E-9,
    1.0573799613666779E-9, 1.0617995371831057E-9, 1.0662333238542487E-9,
    1.0706671105253918E-9, 1.0751008971965348E-9, 1.079548894722393E-9,
    1.0839968922482512E-9, 1.0884448897741095E-9, 1.0928928872999677E-9,
    1.0973550956805411E-9, 1.1018173040611146E-9, 1.106279512441688E-9,
    1.1107417208222614E-9, 1.1152252454849076E-9, 1.1197016647201963E-9,
    1.1241709785281273E-9, 1.1286616086181311E-9, 1.1331451332807774E-9,
    1.1376428687981388E-9, 1.1421406043155002E-9, 1.1466312344055041E-9,
    1.1511431807775807E-9, 1.1556480217222997E-9, 1.1601599680943764E-9,
    1.1646861253211682E-9, 1.1691980716932449E-9, 1.1737242289200367E-9,
    1.1782574915741861E-9, 1.182783648800978E-9, 1.1873169114551274E-9,
    1.1918572795366345E-9, 1.1964047530454991E-9, 1.2009522265543637E-9,
    1.2054997000632284E-9, 1.2100542789994506E-9, 1.2146230687903881E-9,
    1.2191776477266103E-9, 1.2237464375175477E-9, 1.2283223327358428E-9,
    1.2328911225267802E-9, 1.2374812285997905E-9, 1.2420571238180855E-9,
    1.2466401244637382E-9, 1.251237335964106E-9, 1.2558274420371163E-9,
    1.2604246535374841E-9, 1.2650360758925672E-9, 1.2696403928202926E-9,
    1.2742447097480181E-9, 1.2788632375304587E-9, 1.283488870740257E-9,
    1.28810029309534E-9, 1.2927330317324959E-9, 1.2973586649422941E-9,
    1.3019985090068076E-9, 1.306638353071321E-9, 1.3112781971358345E-9,
    1.3159251466277055E-9, 1.3205720961195766E-9, 1.3252332564661629E-9,
    1.3298873113853915E-9, 1.3345484717319778E-9, 1.3392167375059216E-9,
    1.3438850032798655E-9, 1.3485532690538093E-9, 1.3532357456824684E-9,
    1.3579111168837699E-9, 1.3626078043671441E-9, 1.3672973864231608E-9,
    1.3719869684791774E-9, 1.3766836559625517E-9, 1.3813874488732836E-9,
    1.3860912417840154E-9, 1.3907950346947473E-9, 1.395520143887552E-9,
    1.4002310422256414E-9, 1.4049561514184461E-9, 1.4096812606112508E-9,
    1.4143992643766978E-9, 1.4191456898515753E-9, 1.4238779044717376E-9,
    1.4286172245192574E-9, 1.4333565445667773E-9, 1.4381100754690124E-9,
    1.4428636063712474E-9, 1.4476171372734825E-9, 1.4523777736030752E-9,
    1.4571384099326679E-9, 1.4619132571169757E-9, 1.4666881043012836E-9,
    1.4714629514855915E-9, 1.4762449040972569E-9, 1.4810268567089224E-9,
    1.4858230201753031E-9, 1.4906120782143262E-9, 1.4954011362533493E-9,
    1.5002044051470875E-9, 1.5050005686134682E-9, 1.5098180483619217E-9,
    1.5146284226830176E-9, 1.5194387970041134E-9, 1.5242633821799245E-9,
    1.5290879673557356E-9, 1.5339196579589043E-9, 1.5387442431347154E-9,
    1.5435830391652416E-9, 1.5484218351957679E-9, 1.5532606312262942E-9,
    1.5581065326841781E-9, 1.5629595395694196E-9, 1.5678196518820187E-9,
    1.5726797641946177E-9, 1.5775398765072168E-9, 1.5824070942471735E-9,
    1.5872743119871302E-9, 1.5921557405818021E-9, 1.5970300637491164E-9,
    1.6019185977711459E-9, 1.6068000263658178E-9, 1.6116885603878472E-9,
    1.6165841998372343E-9, 1.621486944713979E-9, 1.6263896895907237E-9,
    1.6312924344674684E-9, 1.6362022847715707E-9 };

  static real_T c1_c_Traj_x[397] = { 0.0, 0.15008999999999162,
    0.30034999999999457, 0.4507899999999978, 0.60141000000000133,
    0.75221000000000515, 0.90317999999999188, 1.05431999999999,
    1.2056499999999915, 1.35714999999999, 1.50882, 1.6606699999999961,
    1.8127000000000066, 1.9649100000000033, 2.1172899999999828,
    2.269849999999991, 2.4225799999999964, 2.5754900000000021, 2.728580000000008,
    2.88185, 3.0352899999999892, 3.1888999999999896, 3.3427000000000078,
    3.4966700000000088, 3.650810000000007, 3.8051400000000086,
    3.9596399999999932, 4.1143100000000032, 4.2691599999999994,
    4.4241899999999958, 4.5793999999999926, 4.7347800000000007,
    4.890340000000009, 5.04607, 5.2019799999999918, 5.3580699999999979,
    5.5143300000000011, 5.6707700000000045, 5.8273899999999941,
    5.9841799999999949, 6.1411499999999961, 6.2982899999999944,
    6.4556199999999961, 6.613119999999995, 6.770789999999991, 6.9286400000000015,
    7.086669999999998, 7.2448699999999917, 7.40325, 7.5618100000000084,
    7.7205499999999887, 7.8794599999999946, 8.0385399999999834, 8.1978,
    8.3572400000000044, 8.5168600000000083, 8.6766499999999951,
    8.8366199999999964, 8.9967699999999979, 9.1570899999999966,
    9.3175899999999956, 9.4782599999999917, 9.6391099999999881,
    9.800139999999999, 9.961340000000007, 10.122720000000001, 10.28428000000001,
    10.446009999999987, 10.607919999999993, 10.77001, 10.932270000000003,
    11.094710000000006, 11.257319999999993, 11.420109999999994,
    11.583079999999995, 11.746229999999997, 11.909549999999996,
    12.073049999999995, 12.236719999999991, 12.400570000000002,
    12.564599999999999, 12.728799999999993, 12.893180000000001,
    13.057729999999992, 13.222470000000001, 13.387379999999993,
    13.552459999999996, 13.71772, 13.88315999999999, 14.048779999999994,
    14.214569999999995, 14.380529999999993, 14.546679999999995,
    14.712999999999994, 14.879500000000007, 15.046170000000004, 15.21302,
    15.380039999999994, 15.547250000000005, 15.714630000000014,
    15.882180000000005, 16.049910000000011, 16.217819999999989,
    16.385909999999996, 16.55417, 16.722610000000003, 16.891220000000004,
    17.060009999999991, 17.228979999999993, 17.398119999999992,
    17.567440000000005, 17.73693999999999, 17.906609999999986,
    18.076459999999997, 18.246479999999991, 18.416690000000003,
    18.587060000000008, 18.757620000000003, 18.928349999999995, 19.09926,
    19.270340000000004, 19.441599999999994, 19.613039999999998, 19.78465,
    19.95644, 20.128410000000002, 20.30055, 20.472870000000015, 20.64537,
    20.818039999999982, 20.990890000000007, 21.163910000000016,
    21.337109999999996, 21.510490000000004, 21.68405, 21.857780000000005,
    22.031679999999994, 22.20577, 22.380030000000005, 22.554460000000006,
    22.729079999999996, 22.903869999999998, 23.078829999999996,
    23.253969999999995, 23.429290000000009, 23.604790000000008,
    23.780460000000005, 23.956310000000002, 24.132329999999996,
    24.308530000000005, 24.48491, 24.661460000000005, 24.838190000000012,
    25.015100000000004, 25.192179999999993, 25.369439999999997,
    25.546880000000016, 25.724490000000003, 25.90227999999999,
    26.080240000000003, 26.258389999999991, 26.436699999999988,
    26.615200000000016, 26.793870000000013, 26.97272000000001, 27.15173999999999,
    27.33094, 27.510320000000007, 27.68987, 27.869599999999991,
    28.049509999999998, 28.229589999999988, 28.409849999999992,
    28.590280000000007, 28.770890000000009, 28.95168000000001,
    29.132649999999998, 29.313789999999997, 29.495109999999997,
    29.676600000000008, 29.858270000000005, 30.04012, 30.22214000000001,
    30.404339999999991, 30.58672, 30.769269999999992, 30.952000000000012,
    31.134900000000002, 31.317980000000006, 31.50124000000001, 31.68468,
    31.868290000000002, 32.052080000000004, 32.236039999999988, 32.42018,
    32.604500000000016, 32.78899, 32.973659999999995, 33.158509999999993,
    33.34353, 33.52873, 33.7141, 33.89966, 34.085379999999994,
    34.271290000000008, 34.45737, 34.643630000000009, 34.83006, 35.01667,
    35.20346, 35.390420000000006, 35.57756, 35.764879999999991, 35.95237,
    36.14004, 36.327890000000004, 36.51591, 36.70411, 36.89248,
    37.081030000000005, 37.269760000000005, 37.45867, 37.64775, 37.837, 38.02644,
    38.216049999999996, 38.40583, 38.5958, 38.78594, 38.976250000000007,
    39.16674, 39.357410000000009, 39.54826, 39.739280000000008, 39.93048,
    40.12185, 40.3134, 40.50513, 40.69703, 40.88911, 41.081370000000007, 41.2738,
    41.46641, 41.6592, 41.85216, 42.0453, 42.23861, 42.432100000000005,
    42.62577000000001, 42.819620000000008, 43.01364, 43.20784, 43.40221,
    43.59676, 43.79149, 43.986390000000007, 44.18147, 44.376720000000006,
    44.57216, 44.76777, 44.96355, 45.15951, 45.355650000000004,
    45.551970000000004, 45.74846, 45.94512, 46.141970000000008, 46.33899,
    46.53618, 46.733560000000004, 46.93111, 47.12883, 47.32674,
    47.524810000000009, 47.72307, 47.921500000000009, 48.12011,
    48.31889000000001, 48.517860000000006, 48.71699000000001, 48.91631000000001,
    49.115800000000007, 49.315460000000009, 49.51531, 49.715330000000009,
    49.91552, 50.1159, 50.31645, 50.51717, 50.718070000000004, 50.91915,
    51.12041, 51.321840000000009, 51.52345, 51.72523000000001, 51.92719000000001,
    52.12933000000001, 52.331640000000007, 52.534130000000005,
    52.736800000000009, 52.93964, 53.142660000000014, 53.34585,
    53.549230000000009, 53.752770000000005, 53.956500000000005,
    54.16040000000001, 54.364480000000007, 54.56873, 54.773160000000004,
    54.97777, 55.182550000000006, 55.387510000000006, 55.59265,
    55.79796000000001, 56.00345, 56.209120000000006, 56.41496, 56.62098000000001,
    56.82717, 57.03355, 57.240090000000009, 57.44682000000001,
    57.653720000000007, 57.860800000000012, 58.068050000000007,
    58.275480000000009, 58.483090000000004, 58.690870000000004,
    58.898830000000004, 59.106960000000008, 59.315280000000008, 59.52376,
    59.732430000000008, 59.94127000000001, 60.150290000000005,
    60.359480000000005, 60.568850000000005, 60.7784, 60.988130000000012,
    61.19803000000001, 61.408100000000005, 61.61836000000001, 61.828780000000009,
    62.03939, 62.250170000000011, 62.461130000000004, 62.67227,
    62.883580000000009, 63.095070000000007, 63.306730000000009,
    63.518570000000004, 63.730590000000007, 63.942780000000006, 64.15515,
    64.367700000000013, 64.58042, 64.79332, 65.006400000000014, 65.21965,
    65.433080000000018, 65.646690000000021, 65.86047, 66.07443, 66.28856,
    66.50287, 66.717360000000014, 66.932020000000009, 67.14686,
    67.361880000000014, 67.57707000000002, 67.792440000000013, 68.00799,
    68.22371, 68.439610000000016, 68.655690000000021, 68.871940000000009,
    69.08837, 69.304970000000012, 69.52175, 69.73871, 69.95584,
    70.17316000000001, 70.390640000000019, 70.60831, 70.82615,
    71.044160000000019, 71.262350000000012, 71.480720000000019, 71.69927,
    71.91799, 72.13689, 72.35596000000001, 72.57522, 72.79464, 73.01425,
    73.234030000000018 };

  real_T c1_beta;
  real_T c1_sinBeta;
  real_T c1_cosBeta;
  real_T c1_dist_p3;
  real_T c1_b_Traj_xGlobal[2];
  real_T c1_p2[2];
  int32_T c1_exception;
  real_T c1_p1[2];
  real_T c1_c_Traj_xGlobal[2];
  real_T c1_c_pvp[2];
  real_T c1_b_p1[2];
  real_T c1_d_Traj_xGlobal[2];
  real_T c1_d_pvp[2];
  real_T c1_e_Traj_xGlobal[2];
  real_T c1_f_Traj_xGlobal[2];
  real_T c1_e_pvp[2];
  real_T c1_g_Traj_xGlobal[2];
  real_T c1_f_pvp[2];
  real_T c1_h_Traj_xGlobal[2];
  real_T c1_i_Traj_xGlobal[2];
  real_T c1_g_pvp[2];
  real_T c1_h_pvp[2];
  real_T c1_i_pvp[3];
  real_T c1_c_p0[3];
  real_T c1_b_p2[3];
  real_T c1_c_p1[3];
  real_T c1_vehiclevector[3];
  real_T c1_trajectoryvector[3];
  real_T c1_dv2[3];
  real_T c1_d_p0[3];
  real_T c1_e_p0[2];
  real_T c1_f_p0[2];
  for (c1_k = 0; c1_k < 4; c1_k++) {
    c1_b_pvp[c1_k] = (*chartInstance->c1_pvp)[c1_k];
  }

  c1_b_ActorOffset_Left_Right = *chartInstance->c1_ActorOffset_Left_Right;
  for (c1_k = 0; c1_k < 3; c1_k++) {
    c1_b_TrajOffset_x_y_Y[c1_k] = (*chartInstance->c1_TrajOffset_x_y_Y)[c1_k];
    c1_b_p0[c1_k] = (*chartInstance->c1_p0)[c1_k];
  }

  if (!chartInstance->c1_Counter_not_empty) {
    chartInstance->c1_Counter = 0.0;
    chartInstance->c1_Counter_not_empty = true;
  }

  if (!chartInstance->c1_Actor_traj_distancePersist_not_empty) {
    for (c1_k = 0; c1_k < 2; c1_k++) {
      chartInstance->c1_Actor_traj_distancePersist[c1_k] = 0.0;
    }

    chartInstance->c1_Actor_traj_distancePersist_not_empty = true;
  }

  if (!chartInstance->c1_Actor_traj_anglePersist_not_empty) {
    for (c1_k = 0; c1_k < 2; c1_k++) {
      chartInstance->c1_Actor_traj_anglePersist[c1_k] = 0.0;
    }

    chartInstance->c1_Actor_traj_anglePersist_not_empty = true;
  }

  if (!chartInstance->c1_ActualTrajectoryIndex_not_empty) {
    for (c1_k = 0; c1_k < 2; c1_k++) {
      chartInstance->c1_ActualTrajectoryIndex[c1_k] = 1.0;
    }

    chartInstance->c1_ActualTrajectoryIndex_not_empty = true;
  }

  if (!chartInstance->c1_prefPersist_not_empty) {
    for (c1_k = 0; c1_k < 4; c1_k++) {
      chartInstance->c1_prefPersist[c1_k] = 0.0;
    }

    chartInstance->c1_prefPersist_not_empty = true;
  }

  for (c1_k = 0; c1_k < 794; c1_k++) {
    c1_Traj_xGlobal[c1_k] = 0.0;
    c1_Traj_yGlobal[c1_k] = 0.0;
  }

  for (c1_k = 0; c1_k < 2; c1_k++) {
    c1_ii[c1_k] = chartInstance->c1_ActualTrajectoryIndex[c1_k];
  }

  c1_cosTrajOffset3 = muDoubleScalarCos((*chartInstance->c1_TrajOffset_x_y_Y)[2]);
  c1_sinTrajOffset3 = muDoubleScalarSin((*chartInstance->c1_TrajOffset_x_y_Y)[2]);
  if ((chartInstance->c1_Counter == 1.0) || (chartInstance->c1_Counter == 0.0))
  {
    chartInstance->c1_Counter = 0.0;
    for (c1_j = 0; c1_j < 2; c1_j++) {
      sf_mex_lw_bounds_check((int32_T)c1_ii[c1_j], 1, 397);
      sf_mex_lw_bounds_check((int32_T)c1_ii[c1_j], 1, 397);
      sf_mex_lw_bounds_check((int32_T)(c1_ii[c1_j] + 1.0), 1, 397);
      sf_mex_lw_bounds_check((int32_T)(c1_ii[c1_j] + 1.0), 1, 397);
      c1_beta = muDoubleScalarAtan2(((c1_c_Traj_x[(int32_T)(c1_ii[c1_j] + 1.0) -
        1] * c1_sinTrajOffset3 + c1_c_Traj_y[(int32_T)(c1_ii[c1_j] + 1.0) - 1] *
        c1_cosTrajOffset3) + c1_b_TrajOffset_x_y_Y[1]) - ((c1_c_Traj_x[(int32_T)
        c1_ii[c1_j] - 1] * c1_sinTrajOffset3 + c1_c_Traj_y[(int32_T)c1_ii[c1_j]
        - 1] * c1_cosTrajOffset3) + c1_b_TrajOffset_x_y_Y[1]), ((c1_c_Traj_x
        [(int32_T)(c1_ii[c1_j] + 1.0) - 1] * c1_cosTrajOffset3 - c1_c_Traj_y
        [(int32_T)(c1_ii[c1_j] + 1.0) - 1] * c1_sinTrajOffset3) +
        c1_b_TrajOffset_x_y_Y[0]) - ((c1_c_Traj_x[(int32_T)c1_ii[c1_j] - 1] *
        c1_cosTrajOffset3 - c1_c_Traj_y[(int32_T)c1_ii[c1_j] - 1] *
        c1_sinTrajOffset3) + c1_b_TrajOffset_x_y_Y[0]));
      c1_sinBeta = muDoubleScalarSin(c1_beta);
      c1_cosBeta = muDoubleScalarCos(c1_beta);
      c1_localToGlobalCoordinates(chartInstance,
        c1_c_Traj_x[sf_mex_lw_bounds_check((int32_T)c1_ii[c1_j], 1, 397) - 1],
        c1_c_Traj_y[sf_mex_lw_bounds_check((int32_T)c1_ii[c1_j], 1, 397) - 1],
        c1_b_TrajOffset_x_y_Y, c1_sinTrajOffset3, c1_cosTrajOffset3,
        c1_b_ActorOffset_Left_Right, c1_sinBeta, c1_cosBeta, &c1_beta,
        &c1_dist_p3);
      c1_Traj_xGlobal[(sf_mex_lw_bounds_check((int32_T)c1_ii[c1_j], 1, 397) +
                       397 * c1_j) - 1] = c1_beta;
      c1_Traj_yGlobal[(sf_mex_lw_bounds_check((int32_T)c1_ii[c1_j], 1, 397) +
                       397 * c1_j) - 1] = c1_dist_p3;
      c1_localToGlobalCoordinates(chartInstance,
        c1_c_Traj_x[sf_mex_lw_bounds_check((int32_T)(c1_ii[c1_j] + 1.0), 1, 397)
        - 1], c1_c_Traj_y[sf_mex_lw_bounds_check((int32_T)(c1_ii[c1_j] + 1.0), 1,
        397) - 1], c1_b_TrajOffset_x_y_Y, c1_sinTrajOffset3, c1_cosTrajOffset3,
        c1_b_ActorOffset_Left_Right, c1_sinBeta, c1_cosBeta, &c1_beta,
        &c1_dist_p3);
      c1_Traj_xGlobal[(sf_mex_lw_bounds_check((int32_T)(c1_ii[c1_j] + 1.0), 1,
        397) + 397 * c1_j) - 1] = c1_beta;
      c1_Traj_yGlobal[(sf_mex_lw_bounds_check((int32_T)(c1_ii[c1_j] + 1.0), 1,
        397) + 397 * c1_j) - 1] = c1_dist_p3;
      c1_b_Traj_xGlobal[0] = c1_Traj_xGlobal[(sf_mex_lw_bounds_check((int32_T)
        c1_ii[c1_j], 1, 397) + 397 * c1_j) - 1];
      c1_b_Traj_xGlobal[1] = c1_Traj_yGlobal[(sf_mex_lw_bounds_check((int32_T)
        c1_ii[c1_j], 1, 397) + 397 * c1_j) - 1];
      for (c1_k = 0; c1_k < 2; c1_k++) {
        c1_p2[c1_k] = c1_b_Traj_xGlobal[c1_k];
      }

      if (c1_ii[c1_j] == 1.0) {
        c1_exception = 1;
        for (c1_k = 0; c1_k < 2; c1_k++) {
          c1_p1[c1_k] = c1_p2[c1_k];
        }
      } else {
        c1_exception = 0;
        c1_localToGlobalCoordinates(chartInstance,
          c1_c_Traj_x[sf_mex_lw_bounds_check((int32_T)(c1_ii[c1_j] - 1.0), 1,
          397) - 1], c1_c_Traj_y[sf_mex_lw_bounds_check((int32_T)(c1_ii[c1_j] -
          1.0), 1, 397) - 1], c1_b_TrajOffset_x_y_Y, c1_sinTrajOffset3,
          c1_cosTrajOffset3, c1_b_ActorOffset_Left_Right, c1_sinBeta, c1_cosBeta,
          &c1_beta, &c1_dist_p3);
        c1_Traj_xGlobal[(sf_mex_lw_bounds_check((int32_T)(c1_ii[c1_j] - 1.0), 1,
          397) + 397 * c1_j) - 1] = c1_beta;
        c1_Traj_yGlobal[(sf_mex_lw_bounds_check((int32_T)(c1_ii[c1_j] - 1.0), 1,
          397) + 397 * c1_j) - 1] = c1_dist_p3;
        c1_c_Traj_xGlobal[0] = c1_Traj_xGlobal[(sf_mex_lw_bounds_check((int32_T)
          (c1_ii[c1_j] - 1.0), 1, 397) + 397 * c1_j) - 1];
        c1_c_Traj_xGlobal[1] = c1_Traj_yGlobal[(sf_mex_lw_bounds_check((int32_T)
          (c1_ii[c1_j] - 1.0), 1, 397) + 397 * c1_j) - 1];
        for (c1_k = 0; c1_k < 2; c1_k++) {
          c1_p1[c1_k] = c1_c_Traj_xGlobal[c1_k];
        }

        sf_mex_lw_bounds_check((int32_T)(c1_ii[c1_j] + 1.0), 1, 397);
        sf_mex_lw_bounds_check((int32_T)(c1_ii[c1_j] + 1.0), 1, 397);
        c1_c_pvp[0] = c1_b_pvp[c1_j << 1];
        c1_c_pvp[1] = c1_b_pvp[1 + (c1_j << 1)];
        for (c1_k = 0; c1_k < 2; c1_k++) {
          c1_b_p1[c1_k] = c1_p1[c1_k] - c1_c_pvp[c1_k];
        }

        c1_beta = c1_norm(chartInstance, c1_b_p1);
        c1_d_Traj_xGlobal[0] = c1_Traj_xGlobal[((int32_T)(c1_ii[c1_j] + 1.0) +
          397 * c1_j) - 1];
        c1_d_Traj_xGlobal[1] = c1_Traj_yGlobal[((int32_T)(c1_ii[c1_j] + 1.0) +
          397 * c1_j) - 1];
        c1_d_pvp[0] = c1_b_pvp[c1_j << 1];
        c1_d_pvp[1] = c1_b_pvp[1 + (c1_j << 1)];
        for (c1_k = 0; c1_k < 2; c1_k++) {
          c1_b_p1[c1_k] = c1_d_Traj_xGlobal[c1_k] - c1_d_pvp[c1_k];
        }

        c1_dist_p3 = c1_norm(chartInstance, c1_b_p1);
        while ((c1_beta >= c1_dist_p3) && (c1_ii[c1_j] < 396.0)) {
          c1_ii[c1_j]++;
          c1_localToGlobalCoordinates(chartInstance,
            c1_c_Traj_x[sf_mex_lw_bounds_check((int32_T)(c1_ii[c1_j] + 1.0), 1,
            397) - 1], c1_c_Traj_y[sf_mex_lw_bounds_check((int32_T)(c1_ii[c1_j]
            + 1.0), 1, 397) - 1], c1_b_TrajOffset_x_y_Y, c1_sinTrajOffset3,
            c1_cosTrajOffset3, c1_b_ActorOffset_Left_Right, c1_sinBeta,
            c1_cosBeta, &c1_beta, &c1_dist_p3);
          c1_Traj_xGlobal[(sf_mex_lw_bounds_check((int32_T)(c1_ii[c1_j] + 1.0),
            1, 397) + 397 * c1_j) - 1] = c1_beta;
          c1_Traj_yGlobal[(sf_mex_lw_bounds_check((int32_T)(c1_ii[c1_j] + 1.0),
            1, 397) + 397 * c1_j) - 1] = c1_dist_p3;
          c1_e_Traj_xGlobal[0] = c1_Traj_xGlobal[(sf_mex_lw_bounds_check
            ((int32_T)(c1_ii[c1_j] - 1.0), 1, 397) + 397 * c1_j) - 1];
          c1_e_Traj_xGlobal[1] = c1_Traj_yGlobal[(sf_mex_lw_bounds_check
            ((int32_T)(c1_ii[c1_j] - 1.0), 1, 397) + 397 * c1_j) - 1];
          for (c1_k = 0; c1_k < 2; c1_k++) {
            c1_p1[c1_k] = c1_e_Traj_xGlobal[c1_k];
          }

          c1_f_Traj_xGlobal[0] = c1_Traj_xGlobal[(sf_mex_lw_bounds_check
            ((int32_T)c1_ii[c1_j], 1, 397) + 397 * c1_j) - 1];
          c1_f_Traj_xGlobal[1] = c1_Traj_yGlobal[(sf_mex_lw_bounds_check
            ((int32_T)c1_ii[c1_j], 1, 397) + 397 * c1_j) - 1];
          for (c1_k = 0; c1_k < 2; c1_k++) {
            c1_p2[c1_k] = c1_f_Traj_xGlobal[c1_k];
          }

          sf_mex_lw_bounds_check((int32_T)(c1_ii[c1_j] + 1.0), 1, 397);
          sf_mex_lw_bounds_check((int32_T)(c1_ii[c1_j] + 1.0), 1, 397);
          c1_e_pvp[0] = c1_b_pvp[c1_j << 1];
          c1_e_pvp[1] = c1_b_pvp[1 + (c1_j << 1)];
          for (c1_k = 0; c1_k < 2; c1_k++) {
            c1_b_p1[c1_k] = c1_p1[c1_k] - c1_e_pvp[c1_k];
          }

          c1_beta = c1_norm(chartInstance, c1_b_p1);
          c1_g_Traj_xGlobal[0] = c1_Traj_xGlobal[((int32_T)(c1_ii[c1_j] + 1.0) +
            397 * c1_j) - 1];
          c1_g_Traj_xGlobal[1] = c1_Traj_yGlobal[((int32_T)(c1_ii[c1_j] + 1.0) +
            397 * c1_j) - 1];
          c1_f_pvp[0] = c1_b_pvp[c1_j << 1];
          c1_f_pvp[1] = c1_b_pvp[1 + (c1_j << 1)];
          for (c1_k = 0; c1_k < 2; c1_k++) {
            c1_b_p1[c1_k] = c1_g_Traj_xGlobal[c1_k] - c1_f_pvp[c1_k];
          }

          c1_dist_p3 = c1_norm(chartInstance, c1_b_p1);
          _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
        }

        chartInstance->c1_ActualTrajectoryIndex[c1_j] = c1_ii[c1_j];
        if (c1_ii[c1_j] >= 396.0) {
          c1_h_Traj_xGlobal[0] = c1_Traj_xGlobal[396 + 397 * c1_j];
          c1_h_Traj_xGlobal[1] = c1_Traj_yGlobal[396 + 397 * c1_j];
          c1_beta = muDoubleScalarAtan2(c1_Traj_yGlobal[396 + 397 * c1_j] -
            c1_Traj_yGlobal[395 + 397 * c1_j], c1_Traj_xGlobal[396 + 397 * c1_j]
            - c1_Traj_xGlobal[395 + 397 * c1_j]);
          c1_i_Traj_xGlobal[0] = c1_Traj_xGlobal[396 + 397 * c1_j] +
            muDoubleScalarCos(c1_beta);
          c1_i_Traj_xGlobal[1] = c1_Traj_yGlobal[396 + 397 * c1_j] +
            muDoubleScalarSin(c1_beta);
          for (c1_k = 0; c1_k < 2; c1_k++) {
            c1_p1[c1_k] = c1_h_Traj_xGlobal[c1_k];
            c1_p2[c1_k] = c1_i_Traj_xGlobal[c1_k];
          }
        }
      }

      if (c1_exception == 1) {
        c1_g_pvp[0] = c1_b_pvp[c1_j << 1];
        c1_g_pvp[1] = c1_b_pvp[1 + (c1_j << 1)];
        for (c1_k = 0; c1_k < 2; c1_k++) {
          chartInstance->c1_prefPersist[c1_k + (c1_j << 1)] = c1_g_pvp[c1_k];
        }

        c1_ii[c1_j] = 2.0;
        chartInstance->c1_ActualTrajectoryIndex[c1_j] = c1_ii[c1_j];
      } else {
        c1_h_pvp[0] = c1_b_pvp[c1_j << 1];
        c1_h_pvp[1] = c1_b_pvp[1 + (c1_j << 1)];
        c1_dist_p3 = 0.0;
        for (c1_k = 0; c1_k < 2; c1_k++) {
          c1_dist_p3 += (c1_p1[c1_k] - c1_h_pvp[c1_k]) * (c1_p2[c1_k] -
            c1_p1[c1_k]);
          c1_b_p1[c1_k] = c1_p2[c1_k] - c1_p1[c1_k];
        }

        c1_beta = c1_norm(chartInstance, c1_b_p1);
        c1_beta = -c1_dist_p3 / (c1_beta * c1_beta);
        if ((c1_beta < 0.0) && (c1_ii[c1_j] < 396.0)) {
          for (c1_k = 0; c1_k < 2; c1_k++) {
            chartInstance->c1_prefPersist[c1_k + (c1_j << 1)] = c1_p1[c1_k];
          }
        } else {
          for (c1_k = 0; c1_k < 2; c1_k++) {
            chartInstance->c1_prefPersist[c1_k + (c1_j << 1)] = c1_p1[c1_k] +
              c1_beta * (c1_p2[c1_k] - c1_p1[c1_k]);
          }
        }

        c1_i_pvp[0] = c1_b_pvp[2];
        c1_i_pvp[1] = c1_b_pvp[3];
        c1_i_pvp[2] = 0.0;
        c1_c_p0[0] = c1_b_p0[0];
        c1_c_p0[1] = c1_b_p0[1];
        c1_c_p0[2] = 0.0;
        c1_b_p2[0] = c1_p2[0];
        c1_b_p2[1] = c1_p2[1];
        c1_b_p2[2] = 0.0;
        c1_c_p1[0] = c1_p1[0];
        c1_c_p1[1] = c1_p1[1];
        c1_c_p1[2] = 0.0;
        for (c1_k = 0; c1_k < 3; c1_k++) {
          c1_vehiclevector[c1_k] = c1_i_pvp[c1_k] - c1_c_p0[c1_k];
          c1_trajectoryvector[c1_k] = c1_b_p2[c1_k] - c1_c_p1[c1_k];
        }

        c1_cosBeta = c1_trajectoryvector[0] * c1_vehiclevector[1] -
          c1_trajectoryvector[1] * c1_vehiclevector[0];
        c1_dist_p3 = 0.0;
        for (c1_k = 0; c1_k < 3; c1_k++) {
          c1_dist_p3 += c1_trajectoryvector[c1_k] * c1_vehiclevector[c1_k];
        }

        c1_beta = muDoubleScalarAtan2(muDoubleScalarAbs(c1_cosBeta), c1_dist_p3);
        if (c1_cosBeta == 0.0) {
          chartInstance->c1_Actor_traj_anglePersist[c1_j] = c1_beta * 180.0 /
            3.1415926535897931;
        } else {
          c1_beta *= muDoubleScalarSign(c1_cosBeta);
          chartInstance->c1_Actor_traj_anglePersist[c1_j] = c1_beta * 180.0 /
            3.1415926535897931;
        }

        c1_dv2[0] = chartInstance->c1_prefPersist[c1_j << 1];
        c1_dv2[1] = chartInstance->c1_prefPersist[1 + (c1_j << 1)];
        c1_dv2[2] = 0.0;
        c1_d_p0[0] = c1_b_p0[0];
        c1_d_p0[1] = c1_b_p0[1];
        c1_d_p0[2] = 0.0;
        for (c1_k = 0; c1_k < 3; c1_k++) {
          c1_trajectoryvector[c1_k] = c1_dv2[c1_k] - c1_d_p0[c1_k];
        }

        c1_cosBeta = c1_trajectoryvector[0] * c1_vehiclevector[1] -
          c1_trajectoryvector[1] * c1_vehiclevector[0];
        if (c1_cosBeta == 0.0) {
          c1_e_p0[0] = c1_b_p0[0];
          c1_e_p0[1] = c1_b_p0[1];
          for (c1_k = 0; c1_k < 2; c1_k++) {
            c1_b_p1[c1_k] = chartInstance->c1_prefPersist[c1_k + (c1_j << 1)] -
              c1_e_p0[c1_k];
          }

          chartInstance->c1_Actor_traj_distancePersist[c1_j] = c1_norm
            (chartInstance, c1_b_p1);
        } else {
          c1_f_p0[0] = c1_b_p0[0];
          c1_f_p0[1] = c1_b_p0[1];
          for (c1_k = 0; c1_k < 2; c1_k++) {
            c1_b_p1[c1_k] = chartInstance->c1_prefPersist[c1_k + (c1_j << 1)] -
              c1_f_p0[c1_k];
          }

          chartInstance->c1_Actor_traj_distancePersist[c1_j] = c1_norm
            (chartInstance, c1_b_p1) * muDoubleScalarSign(c1_cosBeta);
        }
      }

      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }
  }

  chartInstance->c1_Counter++;
  for (c1_k = 0; c1_k < 4; c1_k++) {
    (*chartInstance->c1_pref)[c1_k] = chartInstance->c1_prefPersist[c1_k];
  }

  for (c1_k = 0; c1_k < 2; c1_k++) {
    (*chartInstance->c1_Actor_traj_distance)[c1_k] =
      chartInstance->c1_Actor_traj_distancePersist[c1_k];
    (*chartInstance->c1_Actor_traj_angle)[c1_k] =
      chartInstance->c1_Actor_traj_anglePersist[c1_k];
  }
}

static void initSimStructsc1_Experiment_cs(SFc1_Experiment_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)c1_machineNumber;
  (void)c1_chartNumber;
  (void)c1_instanceNumber;
}

const mxArray *sf_c1_Experiment_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_createstruct("structure", 2, 79, 1),
                false);
  c1_info_helper(&c1_nameCaptureInfo);
  c1_b_info_helper(&c1_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(const mxArray **c1_info)
{
  const mxArray *c1_rhs0 = NULL;
  const mxArray *c1_lhs0 = NULL;
  const mxArray *c1_rhs1 = NULL;
  const mxArray *c1_lhs1 = NULL;
  const mxArray *c1_rhs2 = NULL;
  const mxArray *c1_lhs2 = NULL;
  const mxArray *c1_rhs3 = NULL;
  const mxArray *c1_lhs3 = NULL;
  const mxArray *c1_rhs4 = NULL;
  const mxArray *c1_lhs4 = NULL;
  const mxArray *c1_rhs5 = NULL;
  const mxArray *c1_lhs5 = NULL;
  const mxArray *c1_rhs6 = NULL;
  const mxArray *c1_lhs6 = NULL;
  const mxArray *c1_rhs7 = NULL;
  const mxArray *c1_lhs7 = NULL;
  const mxArray *c1_rhs8 = NULL;
  const mxArray *c1_lhs8 = NULL;
  const mxArray *c1_rhs9 = NULL;
  const mxArray *c1_lhs9 = NULL;
  const mxArray *c1_rhs10 = NULL;
  const mxArray *c1_lhs10 = NULL;
  const mxArray *c1_rhs11 = NULL;
  const mxArray *c1_lhs11 = NULL;
  const mxArray *c1_rhs12 = NULL;
  const mxArray *c1_lhs12 = NULL;
  const mxArray *c1_rhs13 = NULL;
  const mxArray *c1_lhs13 = NULL;
  const mxArray *c1_rhs14 = NULL;
  const mxArray *c1_lhs14 = NULL;
  const mxArray *c1_rhs15 = NULL;
  const mxArray *c1_lhs15 = NULL;
  const mxArray *c1_rhs16 = NULL;
  const mxArray *c1_lhs16 = NULL;
  const mxArray *c1_rhs17 = NULL;
  const mxArray *c1_lhs17 = NULL;
  const mxArray *c1_rhs18 = NULL;
  const mxArray *c1_lhs18 = NULL;
  const mxArray *c1_rhs19 = NULL;
  const mxArray *c1_lhs19 = NULL;
  const mxArray *c1_rhs20 = NULL;
  const mxArray *c1_lhs20 = NULL;
  const mxArray *c1_rhs21 = NULL;
  const mxArray *c1_lhs21 = NULL;
  const mxArray *c1_rhs22 = NULL;
  const mxArray *c1_lhs22 = NULL;
  const mxArray *c1_rhs23 = NULL;
  const mxArray *c1_lhs23 = NULL;
  const mxArray *c1_rhs24 = NULL;
  const mxArray *c1_lhs24 = NULL;
  const mxArray *c1_rhs25 = NULL;
  const mxArray *c1_lhs25 = NULL;
  const mxArray *c1_rhs26 = NULL;
  const mxArray *c1_lhs26 = NULL;
  const mxArray *c1_rhs27 = NULL;
  const mxArray *c1_lhs27 = NULL;
  const mxArray *c1_rhs28 = NULL;
  const mxArray *c1_lhs28 = NULL;
  const mxArray *c1_rhs29 = NULL;
  const mxArray *c1_lhs29 = NULL;
  const mxArray *c1_rhs30 = NULL;
  const mxArray *c1_lhs30 = NULL;
  const mxArray *c1_rhs31 = NULL;
  const mxArray *c1_lhs31 = NULL;
  const mxArray *c1_rhs32 = NULL;
  const mxArray *c1_lhs32 = NULL;
  const mxArray *c1_rhs33 = NULL;
  const mxArray *c1_lhs33 = NULL;
  const mxArray *c1_rhs34 = NULL;
  const mxArray *c1_lhs34 = NULL;
  const mxArray *c1_rhs35 = NULL;
  const mxArray *c1_lhs35 = NULL;
  const mxArray *c1_rhs36 = NULL;
  const mxArray *c1_lhs36 = NULL;
  const mxArray *c1_rhs37 = NULL;
  const mxArray *c1_lhs37 = NULL;
  const mxArray *c1_rhs38 = NULL;
  const mxArray *c1_lhs38 = NULL;
  const mxArray *c1_rhs39 = NULL;
  const mxArray *c1_lhs39 = NULL;
  const mxArray *c1_rhs40 = NULL;
  const mxArray *c1_lhs40 = NULL;
  const mxArray *c1_rhs41 = NULL;
  const mxArray *c1_lhs41 = NULL;
  const mxArray *c1_rhs42 = NULL;
  const mxArray *c1_lhs42 = NULL;
  const mxArray *c1_rhs43 = NULL;
  const mxArray *c1_lhs43 = NULL;
  const mxArray *c1_rhs44 = NULL;
  const mxArray *c1_lhs44 = NULL;
  const mxArray *c1_rhs45 = NULL;
  const mxArray *c1_lhs45 = NULL;
  const mxArray *c1_rhs46 = NULL;
  const mxArray *c1_lhs46 = NULL;
  const mxArray *c1_rhs47 = NULL;
  const mxArray *c1_lhs47 = NULL;
  const mxArray *c1_rhs48 = NULL;
  const mxArray *c1_lhs48 = NULL;
  const mxArray *c1_rhs49 = NULL;
  const mxArray *c1_lhs49 = NULL;
  const mxArray *c1_rhs50 = NULL;
  const mxArray *c1_lhs50 = NULL;
  const mxArray *c1_rhs51 = NULL;
  const mxArray *c1_lhs51 = NULL;
  const mxArray *c1_rhs52 = NULL;
  const mxArray *c1_lhs52 = NULL;
  const mxArray *c1_rhs53 = NULL;
  const mxArray *c1_lhs53 = NULL;
  const mxArray *c1_rhs54 = NULL;
  const mxArray *c1_lhs54 = NULL;
  const mxArray *c1_rhs55 = NULL;
  const mxArray *c1_lhs55 = NULL;
  const mxArray *c1_rhs56 = NULL;
  const mxArray *c1_lhs56 = NULL;
  const mxArray *c1_rhs57 = NULL;
  const mxArray *c1_lhs57 = NULL;
  const mxArray *c1_rhs58 = NULL;
  const mxArray *c1_lhs58 = NULL;
  const mxArray *c1_rhs59 = NULL;
  const mxArray *c1_lhs59 = NULL;
  const mxArray *c1_rhs60 = NULL;
  const mxArray *c1_lhs60 = NULL;
  const mxArray *c1_rhs61 = NULL;
  const mxArray *c1_lhs61 = NULL;
  const mxArray *c1_rhs62 = NULL;
  const mxArray *c1_lhs62 = NULL;
  const mxArray *c1_rhs63 = NULL;
  const mxArray *c1_lhs63 = NULL;
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "emlfcn_find_closest_trajectory_points"), "name", "name", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[E]C:/Program Files/PreScan/PreScan_8.1.0/SimulationCore/MatlabCode/CompilationSheet/emlfcn_find_closest_trajectory_points.p"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1497540868U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c1_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[E]C:/Program Files/PreScan/PreScan_8.1.0/SimulationCore/MatlabCode/CompilationSheet/emlfcn_find_closest_trajectory_points.p"),
                  "context", "context", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("length"), "name", "name", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1303167806U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c1_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[E]C:/Program Files/PreScan/PreScan_8.1.0/SimulationCore/MatlabCode/CompilationSheet/emlfcn_find_closest_trajectory_points.p"),
                  "context", "context", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("cos"), "name", "name", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395346496U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c1_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286840322U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c1_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[E]C:/Program Files/PreScan/PreScan_8.1.0/SimulationCore/MatlabCode/CompilationSheet/emlfcn_find_closest_trajectory_points.p"),
                  "context", "context", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("sin"), "name", "name", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395346504U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c1_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286840336U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c1_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[E]C:/Program Files/PreScan/PreScan_8.1.0/SimulationCore/MatlabCode/CompilationSheet/emlfcn_find_closest_trajectory_points.p!cal"
    "culateTrajHeading"), "context", "context", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("atan2"), "name", "name", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395346496U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c1_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c1_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c1_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c1_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c1_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_atan2"), "name",
                  "name", 11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286840320U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c1_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[E]C:/Program Files/PreScan/PreScan_8.1.0/SimulationCore/MatlabCode/CompilationSheet/emlfcn_find_closest_trajectory_points.p"),
                  "context", "context", 12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("norm"), "name", "name", 12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363731868U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c1_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c1_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c1_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_xnrm2"), "name", "name",
                  15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1376002292U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c1_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c1_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.blas.xnrm2"),
                  "name", "name", 17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c1_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "context", "context", 18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c1_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p!below_threshold"),
                  "context", "context", 19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c1_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c1_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "context", "context", 21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.refblas.xnrm2"),
                  "name", "name", 21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c1_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("realmin"), "name", "name", 22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1307672842U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c1_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_realmin"), "name", "name",
                  23);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1307672844U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c1_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 24);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c1_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 25);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 25);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c1_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 26);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 26);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 26);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c1_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 27);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 27);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 27);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c1_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 28);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 28);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c1_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 29);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("isfi"), "name", "name", 29);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 29);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1346531958U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c1_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 30);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1398897198U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c1_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 31);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("intmax"), "name", "name", 31);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c1_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 32);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c1_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 33);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("intmin"), "name", "name", 33);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c1_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 34);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c1_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 35);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("abs"), "name", "name", 35);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c1_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 36);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c1_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 37);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c1_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[E]C:/Program Files/PreScan/PreScan_8.1.0/SimulationCore/MatlabCode/CompilationSheet/emlfcn_find_closest_trajectory_points.p"),
                  "context", "context", 38);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("atan2"), "name", "name", 38);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395346496U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c1_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[E]C:/Program Files/PreScan/PreScan_8.1.0/SimulationCore/MatlabCode/CompilationSheet/emlfcn_find_closest_trajectory_points.p"),
                  "context", "context", 39);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 39);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c1_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 40);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 40);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c1_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 41);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 41);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c1_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 42);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 42);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c1_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 43);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 43);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c1_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 44);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_xdotu"), "name", "name",
                  44);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1376002290U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c1_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 45);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 45);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c1_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 46);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.blas.xdotu"),
                  "name", "name", 46);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotu.p"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c1_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotu.p"),
                  "context", "context", 47);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.blas.xdot"),
                  "name", "name", 47);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c1_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 48);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 48);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c1_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p!below_threshold"),
                  "context", "context", 49);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 49);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c1_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 50);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.refblas.xdot"),
                  "name", "name", 50);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "resolved", "resolved", 50);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c1_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "context", "context", 51);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.refblas.xdotx"),
                  "name", "name", 51);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c1_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 52);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 52);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 52);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c1_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 53);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 53);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 53);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c1_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 54);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 54);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 54);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 54);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c1_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 55);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 55);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 55);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 55);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c1_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 56);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 56);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 56);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c1_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[E]C:/Program Files/PreScan/PreScan_8.1.0/SimulationCore/MatlabCode/CompilationSheet/emlfcn_find_closest_trajectory_points.p"),
                  "context", "context", 57);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("mpower"), "name", "name", 57);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 57);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363731878U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c1_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 58);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 58);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 58);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c1_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 59);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("ismatrix"), "name", "name", 59);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 59);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1331326458U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c1_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 60);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("power"), "name", "name", 60);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 60);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395346506U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c1_rhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 61);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 61);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 61);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c1_rhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 62);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 62);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 62);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c1_rhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 63);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 63);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 63);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 63);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c1_rhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs63), "lhs", "lhs",
                  63);
  sf_mex_destroy(&c1_rhs0);
  sf_mex_destroy(&c1_lhs0);
  sf_mex_destroy(&c1_rhs1);
  sf_mex_destroy(&c1_lhs1);
  sf_mex_destroy(&c1_rhs2);
  sf_mex_destroy(&c1_lhs2);
  sf_mex_destroy(&c1_rhs3);
  sf_mex_destroy(&c1_lhs3);
  sf_mex_destroy(&c1_rhs4);
  sf_mex_destroy(&c1_lhs4);
  sf_mex_destroy(&c1_rhs5);
  sf_mex_destroy(&c1_lhs5);
  sf_mex_destroy(&c1_rhs6);
  sf_mex_destroy(&c1_lhs6);
  sf_mex_destroy(&c1_rhs7);
  sf_mex_destroy(&c1_lhs7);
  sf_mex_destroy(&c1_rhs8);
  sf_mex_destroy(&c1_lhs8);
  sf_mex_destroy(&c1_rhs9);
  sf_mex_destroy(&c1_lhs9);
  sf_mex_destroy(&c1_rhs10);
  sf_mex_destroy(&c1_lhs10);
  sf_mex_destroy(&c1_rhs11);
  sf_mex_destroy(&c1_lhs11);
  sf_mex_destroy(&c1_rhs12);
  sf_mex_destroy(&c1_lhs12);
  sf_mex_destroy(&c1_rhs13);
  sf_mex_destroy(&c1_lhs13);
  sf_mex_destroy(&c1_rhs14);
  sf_mex_destroy(&c1_lhs14);
  sf_mex_destroy(&c1_rhs15);
  sf_mex_destroy(&c1_lhs15);
  sf_mex_destroy(&c1_rhs16);
  sf_mex_destroy(&c1_lhs16);
  sf_mex_destroy(&c1_rhs17);
  sf_mex_destroy(&c1_lhs17);
  sf_mex_destroy(&c1_rhs18);
  sf_mex_destroy(&c1_lhs18);
  sf_mex_destroy(&c1_rhs19);
  sf_mex_destroy(&c1_lhs19);
  sf_mex_destroy(&c1_rhs20);
  sf_mex_destroy(&c1_lhs20);
  sf_mex_destroy(&c1_rhs21);
  sf_mex_destroy(&c1_lhs21);
  sf_mex_destroy(&c1_rhs22);
  sf_mex_destroy(&c1_lhs22);
  sf_mex_destroy(&c1_rhs23);
  sf_mex_destroy(&c1_lhs23);
  sf_mex_destroy(&c1_rhs24);
  sf_mex_destroy(&c1_lhs24);
  sf_mex_destroy(&c1_rhs25);
  sf_mex_destroy(&c1_lhs25);
  sf_mex_destroy(&c1_rhs26);
  sf_mex_destroy(&c1_lhs26);
  sf_mex_destroy(&c1_rhs27);
  sf_mex_destroy(&c1_lhs27);
  sf_mex_destroy(&c1_rhs28);
  sf_mex_destroy(&c1_lhs28);
  sf_mex_destroy(&c1_rhs29);
  sf_mex_destroy(&c1_lhs29);
  sf_mex_destroy(&c1_rhs30);
  sf_mex_destroy(&c1_lhs30);
  sf_mex_destroy(&c1_rhs31);
  sf_mex_destroy(&c1_lhs31);
  sf_mex_destroy(&c1_rhs32);
  sf_mex_destroy(&c1_lhs32);
  sf_mex_destroy(&c1_rhs33);
  sf_mex_destroy(&c1_lhs33);
  sf_mex_destroy(&c1_rhs34);
  sf_mex_destroy(&c1_lhs34);
  sf_mex_destroy(&c1_rhs35);
  sf_mex_destroy(&c1_lhs35);
  sf_mex_destroy(&c1_rhs36);
  sf_mex_destroy(&c1_lhs36);
  sf_mex_destroy(&c1_rhs37);
  sf_mex_destroy(&c1_lhs37);
  sf_mex_destroy(&c1_rhs38);
  sf_mex_destroy(&c1_lhs38);
  sf_mex_destroy(&c1_rhs39);
  sf_mex_destroy(&c1_lhs39);
  sf_mex_destroy(&c1_rhs40);
  sf_mex_destroy(&c1_lhs40);
  sf_mex_destroy(&c1_rhs41);
  sf_mex_destroy(&c1_lhs41);
  sf_mex_destroy(&c1_rhs42);
  sf_mex_destroy(&c1_lhs42);
  sf_mex_destroy(&c1_rhs43);
  sf_mex_destroy(&c1_lhs43);
  sf_mex_destroy(&c1_rhs44);
  sf_mex_destroy(&c1_lhs44);
  sf_mex_destroy(&c1_rhs45);
  sf_mex_destroy(&c1_lhs45);
  sf_mex_destroy(&c1_rhs46);
  sf_mex_destroy(&c1_lhs46);
  sf_mex_destroy(&c1_rhs47);
  sf_mex_destroy(&c1_lhs47);
  sf_mex_destroy(&c1_rhs48);
  sf_mex_destroy(&c1_lhs48);
  sf_mex_destroy(&c1_rhs49);
  sf_mex_destroy(&c1_lhs49);
  sf_mex_destroy(&c1_rhs50);
  sf_mex_destroy(&c1_lhs50);
  sf_mex_destroy(&c1_rhs51);
  sf_mex_destroy(&c1_lhs51);
  sf_mex_destroy(&c1_rhs52);
  sf_mex_destroy(&c1_lhs52);
  sf_mex_destroy(&c1_rhs53);
  sf_mex_destroy(&c1_lhs53);
  sf_mex_destroy(&c1_rhs54);
  sf_mex_destroy(&c1_lhs54);
  sf_mex_destroy(&c1_rhs55);
  sf_mex_destroy(&c1_lhs55);
  sf_mex_destroy(&c1_rhs56);
  sf_mex_destroy(&c1_lhs56);
  sf_mex_destroy(&c1_rhs57);
  sf_mex_destroy(&c1_lhs57);
  sf_mex_destroy(&c1_rhs58);
  sf_mex_destroy(&c1_lhs58);
  sf_mex_destroy(&c1_rhs59);
  sf_mex_destroy(&c1_lhs59);
  sf_mex_destroy(&c1_rhs60);
  sf_mex_destroy(&c1_lhs60);
  sf_mex_destroy(&c1_rhs61);
  sf_mex_destroy(&c1_lhs61);
  sf_mex_destroy(&c1_rhs62);
  sf_mex_destroy(&c1_lhs62);
  sf_mex_destroy(&c1_rhs63);
  sf_mex_destroy(&c1_lhs63);
}

static const mxArray *c1_emlrt_marshallOut(const char * c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c1_u)), false);
  return c1_y;
}

static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 7, 0U, 0U, 0U, 0), false);
  return c1_y;
}

static void c1_b_info_helper(const mxArray **c1_info)
{
  const mxArray *c1_rhs64 = NULL;
  const mxArray *c1_lhs64 = NULL;
  const mxArray *c1_rhs65 = NULL;
  const mxArray *c1_lhs65 = NULL;
  const mxArray *c1_rhs66 = NULL;
  const mxArray *c1_lhs66 = NULL;
  const mxArray *c1_rhs67 = NULL;
  const mxArray *c1_lhs67 = NULL;
  const mxArray *c1_rhs68 = NULL;
  const mxArray *c1_lhs68 = NULL;
  const mxArray *c1_rhs69 = NULL;
  const mxArray *c1_lhs69 = NULL;
  const mxArray *c1_rhs70 = NULL;
  const mxArray *c1_lhs70 = NULL;
  const mxArray *c1_rhs71 = NULL;
  const mxArray *c1_lhs71 = NULL;
  const mxArray *c1_rhs72 = NULL;
  const mxArray *c1_lhs72 = NULL;
  const mxArray *c1_rhs73 = NULL;
  const mxArray *c1_lhs73 = NULL;
  const mxArray *c1_rhs74 = NULL;
  const mxArray *c1_lhs74 = NULL;
  const mxArray *c1_rhs75 = NULL;
  const mxArray *c1_lhs75 = NULL;
  const mxArray *c1_rhs76 = NULL;
  const mxArray *c1_lhs76 = NULL;
  const mxArray *c1_rhs77 = NULL;
  const mxArray *c1_lhs77 = NULL;
  const mxArray *c1_rhs78 = NULL;
  const mxArray *c1_lhs78 = NULL;
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 64);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("floor"), "name", "name", 64);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 64);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 64);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 64);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 64);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 64);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 64);
  sf_mex_assign(&c1_rhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs64), "rhs", "rhs",
                  64);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs64), "lhs", "lhs",
                  64);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 65);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 65);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 65);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 65);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 65);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 65);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 65);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 65);
  sf_mex_assign(&c1_rhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs65), "rhs", "rhs",
                  65);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs65), "lhs", "lhs",
                  65);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 66);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 66);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 66);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 66);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286840326U), "fileTimeLo",
                  "fileTimeLo", 66);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 66);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 66);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 66);
  sf_mex_assign(&c1_rhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs66), "rhs", "rhs",
                  66);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs66), "lhs", "lhs",
                  66);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 67);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 67);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 67);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 67);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 67);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 67);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 67);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 67);
  sf_mex_assign(&c1_rhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs67), "rhs", "rhs",
                  67);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs67), "lhs", "lhs",
                  67);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[E]C:/Program Files/PreScan/PreScan_8.1.0/SimulationCore/MatlabCode/CompilationSheet/emlfcn_find_closest_trajectory_points.p"),
                  "context", "context", 68);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("mrdivide"), "name", "name", 68);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 68);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 68);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 68);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 68);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 68);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 68);
  sf_mex_assign(&c1_rhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs68), "rhs", "rhs",
                  68);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs68), "lhs", "lhs",
                  68);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 69);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 69);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 69);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 69);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 69);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 69);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 69);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 69);
  sf_mex_assign(&c1_rhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs69), "rhs", "rhs",
                  69);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs69), "lhs", "lhs",
                  69);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 70);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("rdivide"), "name", "name", 70);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 70);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 70);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 70);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 70);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 70);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 70);
  sf_mex_assign(&c1_rhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs70), "rhs", "rhs",
                  70);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs70), "lhs", "lhs",
                  70);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 71);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 71);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 71);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 71);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 71);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 71);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 71);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 71);
  sf_mex_assign(&c1_rhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs71), "rhs", "rhs",
                  71);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs71), "lhs", "lhs",
                  71);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 72);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 72);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 72);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 72);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 72);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 72);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 72);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 72);
  sf_mex_assign(&c1_rhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs72), "rhs", "rhs",
                  72);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs72), "lhs", "lhs",
                  72);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 73);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_div"), "name", "name", 73);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 73);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 73);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 73);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 73);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 73);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 73);
  sf_mex_assign(&c1_rhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs73), "rhs", "rhs",
                  73);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs73), "lhs", "lhs",
                  73);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 74);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 74);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 74);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 74);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 74);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 74);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 74);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 74);
  sf_mex_assign(&c1_rhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs74), "rhs", "rhs",
                  74);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs74), "lhs", "lhs",
                  74);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "context",
                  "context", 75);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("abs"), "name", "name", 75);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 75);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 75);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 75);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 75);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 75);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 75);
  sf_mex_assign(&c1_rhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs75), "rhs", "rhs",
                  75);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs75), "lhs", "lhs",
                  75);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[E]C:/Program Files/PreScan/PreScan_8.1.0/SimulationCore/MatlabCode/CompilationSheet/emlfcn_find_closest_trajectory_points.p"),
                  "context", "context", 76);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("sign"), "name", "name", 76);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 76);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "resolved",
                  "resolved", 76);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 76);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 76);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 76);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 76);
  sf_mex_assign(&c1_rhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs76), "rhs", "rhs",
                  76);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs76), "lhs", "lhs",
                  76);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 77);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 77);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 77);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 77);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 77);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 77);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 77);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 77);
  sf_mex_assign(&c1_rhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs77), "rhs", "rhs",
                  77);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs77), "lhs", "lhs",
                  77);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 78);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_sign"), "name",
                  "name", 78);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 78);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m"),
                  "resolved", "resolved", 78);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1356563094U), "fileTimeLo",
                  "fileTimeLo", 78);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 78);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 78);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 78);
  sf_mex_assign(&c1_rhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs78), "rhs", "rhs",
                  78);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs78), "lhs", "lhs",
                  78);
  sf_mex_destroy(&c1_rhs64);
  sf_mex_destroy(&c1_lhs64);
  sf_mex_destroy(&c1_rhs65);
  sf_mex_destroy(&c1_lhs65);
  sf_mex_destroy(&c1_rhs66);
  sf_mex_destroy(&c1_lhs66);
  sf_mex_destroy(&c1_rhs67);
  sf_mex_destroy(&c1_lhs67);
  sf_mex_destroy(&c1_rhs68);
  sf_mex_destroy(&c1_lhs68);
  sf_mex_destroy(&c1_rhs69);
  sf_mex_destroy(&c1_lhs69);
  sf_mex_destroy(&c1_rhs70);
  sf_mex_destroy(&c1_lhs70);
  sf_mex_destroy(&c1_rhs71);
  sf_mex_destroy(&c1_lhs71);
  sf_mex_destroy(&c1_rhs72);
  sf_mex_destroy(&c1_lhs72);
  sf_mex_destroy(&c1_rhs73);
  sf_mex_destroy(&c1_lhs73);
  sf_mex_destroy(&c1_rhs74);
  sf_mex_destroy(&c1_lhs74);
  sf_mex_destroy(&c1_rhs75);
  sf_mex_destroy(&c1_lhs75);
  sf_mex_destroy(&c1_rhs76);
  sf_mex_destroy(&c1_lhs76);
  sf_mex_destroy(&c1_rhs77);
  sf_mex_destroy(&c1_lhs77);
  sf_mex_destroy(&c1_rhs78);
  sf_mex_destroy(&c1_lhs78);
}

static void c1_localToGlobalCoordinates(SFc1_Experiment_csInstanceStruct
  *chartInstance, real_T c1_localX, real_T c1_localY, real_T c1_origin[3],
  real_T c1_sinOriginYaw, real_T c1_cosOriginYaw, real_T c1_offset, real_T
  c1_offsetSin, real_T c1_offsetCos, real_T *c1_globalX, real_T *c1_globalY)
{
  (void)chartInstance;
  *c1_globalX = ((c1_localX * c1_cosOriginYaw - c1_localY * c1_sinOriginYaw) +
                 c1_origin[0]) - c1_offset * c1_offsetSin;
  *c1_globalY = ((c1_localX * c1_sinOriginYaw + c1_localY * c1_cosOriginYaw) +
                 c1_origin[1]) + c1_offset * c1_offsetCos;
}

static real_T c1_norm(SFc1_Experiment_csInstanceStruct *chartInstance, real_T
                      c1_x[2])
{
  real_T c1_y;
  real_T c1_scale;
  int32_T c1_k;
  real_T c1_absxk;
  real_T c1_t;
  (void)chartInstance;
  c1_y = 0.0;
  c1_scale = 2.2250738585072014E-308;
  for (c1_k = 0; c1_k < 2; c1_k++) {
    c1_absxk = muDoubleScalarAbs(c1_x[c1_k]);
    if (c1_absxk > c1_scale) {
      c1_t = c1_scale / c1_absxk;
      c1_y = 1.0 + c1_y * c1_t * c1_t;
      c1_scale = c1_absxk;
    } else {
      c1_t = c1_absxk / c1_scale;
      c1_y += c1_t * c1_t;
    }
  }

  return c1_scale * muDoubleScalarSqrt(c1_y);
}

static void c1_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct *chartInstance,
  const mxArray *c1_b_Actor_traj_angle, const char_T *c1_identifier, real_T
  c1_y[2])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_Actor_traj_angle),
                        &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_Actor_traj_angle);
}

static void c1_b_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[2])
{
  real_T c1_dv3[2];
  int32_T c1_i2;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv3, 1, 0, 0U, 1, 0U, 1, 2);
  for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
    c1_y[c1_i2] = c1_dv3[c1_i2];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_b_pref, const char_T *c1_identifier, real_T
  c1_y[4])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_pref), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_pref);
}

static void c1_d_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[4])
{
  real_T c1_dv4[4];
  int32_T c1_i3;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv4, 1, 0, 0U, 1, 0U, 1, 4);
  for (c1_i3 = 0; c1_i3 < 4; c1_i3++) {
    c1_y[c1_i3] = c1_dv4[c1_i3];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_e_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_b_Actor_traj_anglePersist, const char_T
  *c1_identifier, real_T c1_y[2])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_Actor_traj_anglePersist),
                        &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_Actor_traj_anglePersist);
}

static void c1_f_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[2])
{
  real_T c1_dv5[2];
  int32_T c1_i4;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_Actor_traj_anglePersist_not_empty = false;
  } else {
    chartInstance->c1_Actor_traj_anglePersist_not_empty = true;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv5, 1, 0, 0U, 1, 0U, 2, 1,
                  2);
    for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
      c1_y[c1_i4] = c1_dv5[c1_i4];
    }
  }

  sf_mex_destroy(&c1_u);
}

static void c1_g_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_b_Actor_traj_distancePersist, const char_T
  *c1_identifier, real_T c1_y[2])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup
                        (c1_b_Actor_traj_distancePersist), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_Actor_traj_distancePersist);
}

static void c1_h_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[2])
{
  real_T c1_dv6[2];
  int32_T c1_i5;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_Actor_traj_distancePersist_not_empty = false;
  } else {
    chartInstance->c1_Actor_traj_distancePersist_not_empty = true;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv6, 1, 0, 0U, 1, 0U, 2, 1,
                  2);
    for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
      c1_y[c1_i5] = c1_dv6[c1_i5];
    }
  }

  sf_mex_destroy(&c1_u);
}

static void c1_i_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_b_ActualTrajectoryIndex, const char_T
  *c1_identifier, real_T c1_y[2])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_ActualTrajectoryIndex),
                        &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_ActualTrajectoryIndex);
}

static void c1_j_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[2])
{
  real_T c1_dv7[2];
  int32_T c1_i6;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_ActualTrajectoryIndex_not_empty = false;
  } else {
    chartInstance->c1_ActualTrajectoryIndex_not_empty = true;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv7, 1, 0, 0U, 1, 0U, 2, 1,
                  2);
    for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
      c1_y[c1_i6] = c1_dv7[c1_i6];
    }
  }

  sf_mex_destroy(&c1_u);
}

static real_T c1_k_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_b_Counter, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_Counter),
    &c1_thisId);
  sf_mex_destroy(&c1_b_Counter);
  return c1_y;
}

static real_T c1_l_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_Counter_not_empty = false;
  } else {
    chartInstance->c1_Counter_not_empty = true;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
    c1_y = c1_d0;
  }

  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_m_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_b_prefPersist, const char_T *c1_identifier,
  real_T c1_y[4])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_prefPersist), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_b_prefPersist);
}

static void c1_n_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[4])
{
  real_T c1_dv8[4];
  int32_T c1_i7;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_prefPersist_not_empty = false;
  } else {
    chartInstance->c1_prefPersist_not_empty = true;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv8, 1, 0, 0U, 1, 0U, 2, 2,
                  2);
    for (c1_i7 = 0; c1_i7 < 4; c1_i7++) {
      c1_y[c1_i7] = c1_dv8[c1_i7];
    }
  }

  sf_mex_destroy(&c1_u);
}

static uint8_T c1_o_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_Experiment_cs, const char_T
  *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_Experiment_cs), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_Experiment_cs);
  return c1_y;
}

static uint8_T c1_p_emlrt_marshallIn(SFc1_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_Experiment_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_Experiment_csInstanceStruct
  *chartInstance)
{
  chartInstance->c1_pref = (real_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_Actor_traj_distance = (real_T (*)[2])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c1_Actor_traj_angle = (real_T (*)[2])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 3);
  chartInstance->c1_pvp = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c1_TrajOffset_x_y_Y = (real_T (*)[3])
    ssGetInputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c1_ActorOffset_Left_Right = (real_T *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c1_p0 = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
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

void sf_c1_Experiment_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(544229674U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(528914101U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(381212306U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1286216022U);
}

mxArray* sf_c1_Experiment_cs_get_post_codegen_info(void);
mxArray *sf_c1_Experiment_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("lf9GUCLCkpoFNGq3JjbmNB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(2);
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
      pr[0] = (double)(3);
      pr[1] = (double)(1);
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
      pr[0] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(397);
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
      pr[0] = (double)(397);
      pr[1] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
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
      pr[0] = (double)(2);
      pr[1] = (double)(1);
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
      pr[0] = (double)(2);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c1_Experiment_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_Experiment_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_Experiment_cs_jit_fallback_info(void)
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

mxArray *sf_c1_Experiment_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c1_Experiment_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c1_Experiment_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x9'type','srcId','name','auxInfo'{{M[1],M[11],T\"Actor_traj_angle\",},{M[1],M[5],T\"Actor_traj_distance\",},{M[1],M[13],T\"pref\",},{M[4],M[0],T\"Actor_traj_anglePersist\",S'l','i','p'{{M1x2[-1 -2],M[1],T\"C:\\Program Files\\PreScan\\PreScan_8.1.0\\SimulationCore\\MatlabCode\\CompilationSheet\\emlfcn_find_closest_trajectory_points.p\"}}},{M[4],M[0],T\"Actor_traj_distancePersist\",S'l','i','p'{{M1x2[-1 -2],M[1],T\"C:\\Program Files\\PreScan\\PreScan_8.1.0\\SimulationCore\\MatlabCode\\CompilationSheet\\emlfcn_find_closest_trajectory_points.p\"}}},{M[4],M[0],T\"ActualTrajectoryIndex\",S'l','i','p'{{M1x2[-1 -2],M[1],T\"C:\\Program Files\\PreScan\\PreScan_8.1.0\\SimulationCore\\MatlabCode\\CompilationSheet\\emlfcn_find_closest_trajectory_points.p\"}}},{M[4],M[0],T\"Counter\",S'l','i','p'{{M1x2[-1 -2],M[1],T\"C:\\Program Files\\PreScan\\PreScan_8.1.0\\SimulationCore\\MatlabCode\\CompilationSheet\\emlfcn_find_closest_trajectory_points.p\"}}},{M[4],M[0],T\"prefPersist\",S'l','i','p'{{M1x2[-1 -2],M[1],T\"C:\\Program Files\\PreScan\\PreScan_8.1.0\\SimulationCore\\MatlabCode\\CompilationSheet\\emlfcn_find_closest_trajectory_points.p\"}}},{M[8],M[0],T\"is_active_c1_Experiment_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 9, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_Experiment_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "6iXjj0VIk2tXbrOyscKMXH";
}

static void sf_opaque_initialize_c1_Experiment_cs(void *chartInstanceVar)
{
  initialize_params_c1_Experiment_cs((SFc1_Experiment_csInstanceStruct*)
    chartInstanceVar);
  initialize_c1_Experiment_cs((SFc1_Experiment_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_Experiment_cs(void *chartInstanceVar)
{
  enable_c1_Experiment_cs((SFc1_Experiment_csInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_Experiment_cs(void *chartInstanceVar)
{
  disable_c1_Experiment_cs((SFc1_Experiment_csInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_Experiment_cs(void *chartInstanceVar)
{
  sf_gateway_c1_Experiment_cs((SFc1_Experiment_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_Experiment_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c1_Experiment_cs((SFc1_Experiment_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_Experiment_cs(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c1_Experiment_cs((SFc1_Experiment_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c1_Experiment_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_Experiment_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_cs_optimization_info();
    }

    finalize_c1_Experiment_cs((SFc1_Experiment_csInstanceStruct*)
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
  initSimStructsc1_Experiment_cs((SFc1_Experiment_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_Experiment_cs(SimStruct *S)
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
    initialize_params_c1_Experiment_cs((SFc1_Experiment_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_Experiment_cs(SimStruct *S)
{
  /* Actual parameters from chart:
     Traj_x Traj_y
   */
  const char_T *rtParamNames[] = { "Traj_x", "Traj_y" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for Traj_x*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for Traj_y*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Experiment_cs_optimization_info();
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
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1283300755U));
  ssSetChecksum1(S,(3484431309U));
  ssSetChecksum2(S,(467355603U));
  ssSetChecksum3(S,(2944854421U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_Experiment_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_Experiment_cs(SimStruct *S)
{
  SFc1_Experiment_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc1_Experiment_csInstanceStruct *)utMalloc(sizeof
    (SFc1_Experiment_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_Experiment_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_Experiment_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_Experiment_cs;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_Experiment_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_Experiment_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_Experiment_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_Experiment_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_Experiment_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_Experiment_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_Experiment_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_Experiment_cs;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_Experiment_cs;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
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
}

void c1_Experiment_cs_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_Experiment_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_Experiment_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_Experiment_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_Experiment_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
