/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_cs_sfun.h"
#include "c15_Experiment_cs.h"
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(NULL,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c15_Experiment_cs(SFc15_Experiment_csInstanceStruct
  *chartInstance);
static void initialize_params_c15_Experiment_cs
  (SFc15_Experiment_csInstanceStruct *chartInstance);
static void enable_c15_Experiment_cs(SFc15_Experiment_csInstanceStruct
  *chartInstance);
static void disable_c15_Experiment_cs(SFc15_Experiment_csInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c15_Experiment_cs
  (SFc15_Experiment_csInstanceStruct *chartInstance);
static void set_sim_state_c15_Experiment_cs(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_st);
static void finalize_c15_Experiment_cs(SFc15_Experiment_csInstanceStruct
  *chartInstance);
static void sf_gateway_c15_Experiment_cs(SFc15_Experiment_csInstanceStruct
  *chartInstance);
static void mdl_start_c15_Experiment_cs(SFc15_Experiment_csInstanceStruct
  *chartInstance);
static void c15_chartstep_c15_Experiment_cs(SFc15_Experiment_csInstanceStruct
  *chartInstance);
static void initSimStructsc15_Experiment_cs(SFc15_Experiment_csInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber, uint32_T c15_instanceNumber);
static void c15_info_helper(const mxArray **c15_info);
static const mxArray *c15_emlrt_marshallOut(const char * c15_u);
static const mxArray *c15_b_emlrt_marshallOut(const uint32_T c15_u);
static void c15_b_info_helper(const mxArray **c15_info);
static void c15_localToGlobalCoordinates(SFc15_Experiment_csInstanceStruct
  *chartInstance, real_T c15_localX, real_T c15_localY, real_T c15_origin[3],
  real_T c15_sinOriginYaw, real_T c15_cosOriginYaw, real_T c15_offset, real_T
  c15_offsetSin, real_T c15_offsetCos, real_T *c15_globalX, real_T *c15_globalY);
static real_T c15_norm(SFc15_Experiment_csInstanceStruct *chartInstance, real_T
  c15_x[2]);
static void c15_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_b_Actor_traj_angle, const char_T
  *c15_identifier, real_T c15_y[2]);
static void c15_b_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[2]);
static void c15_c_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_b_pref, const char_T *c15_identifier,
  real_T c15_y[4]);
static void c15_d_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[4]);
static void c15_e_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_b_Actor_traj_anglePersist, const char_T
  *c15_identifier, real_T c15_y[2]);
static void c15_f_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[2]);
static void c15_g_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_b_Actor_traj_distancePersist, const char_T *
  c15_identifier, real_T c15_y[2]);
static void c15_h_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[2]);
static void c15_i_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_b_ActualTrajectoryIndex, const char_T
  *c15_identifier, real_T c15_y[2]);
static void c15_j_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[2]);
static real_T c15_k_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_b_Counter, const char_T *c15_identifier);
static real_T c15_l_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_m_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_b_prefPersist, const char_T *c15_identifier,
  real_T c15_y[4]);
static void c15_n_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[4]);
static uint8_T c15_o_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_b_is_active_c15_Experiment_cs, const char_T
  *c15_identifier);
static uint8_T c15_p_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void init_dsm_address_info(SFc15_Experiment_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc15_Experiment_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c15_Experiment_cs(SFc15_Experiment_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c15_Counter_not_empty = false;
  chartInstance->c15_Actor_traj_distancePersist_not_empty = false;
  chartInstance->c15_Actor_traj_anglePersist_not_empty = false;
  chartInstance->c15_ActualTrajectoryIndex_not_empty = false;
  chartInstance->c15_prefPersist_not_empty = false;
  chartInstance->c15_is_active_c15_Experiment_cs = 0U;
}

static void initialize_params_c15_Experiment_cs
  (SFc15_Experiment_csInstanceStruct *chartInstance)
{
  real_T c15_dv0[411];
  int32_T c15_i0;
  real_T c15_dv1[411];
  sf_mex_import_named("Traj_x", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c15_dv0, 0, 0, 0U, 1, 0U, 1, 411);
  for (c15_i0 = 0; c15_i0 < 411; c15_i0++) {
    chartInstance->c15_Traj_x[c15_i0] = c15_dv0[c15_i0];
  }

  sf_mex_import_named("Traj_y", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      c15_dv1, 0, 0, 0U, 1, 0U, 1, 411);
  for (c15_i0 = 0; c15_i0 < 411; c15_i0++) {
    chartInstance->c15_Traj_y[c15_i0] = c15_dv1[c15_i0];
  }
}

static void enable_c15_Experiment_cs(SFc15_Experiment_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c15_Experiment_cs(SFc15_Experiment_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static const mxArray *get_sim_state_c15_Experiment_cs
  (SFc15_Experiment_csInstanceStruct *chartInstance)
{
  const mxArray *c15_st;
  const mxArray *c15_y = NULL;
  int32_T c15_i1;
  real_T c15_u[2];
  const mxArray *c15_b_y = NULL;
  real_T c15_b_u[2];
  const mxArray *c15_c_y = NULL;
  real_T c15_c_u[4];
  const mxArray *c15_d_y = NULL;
  real_T c15_d_u[2];
  const mxArray *c15_e_y = NULL;
  real_T c15_e_u[2];
  const mxArray *c15_f_y = NULL;
  real_T c15_f_u[2];
  const mxArray *c15_g_y = NULL;
  real_T c15_g_u;
  const mxArray *c15_h_y = NULL;
  real_T c15_h_u[4];
  const mxArray *c15_i_y = NULL;
  uint8_T c15_i_u;
  const mxArray *c15_j_y = NULL;
  c15_st = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_createcellmatrix(9, 1), false);
  for (c15_i1 = 0; c15_i1 < 2; c15_i1++) {
    c15_u[c15_i1] = (*chartInstance->c15_Actor_traj_angle)[c15_i1];
  }

  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setcell(c15_y, 0, c15_b_y);
  for (c15_i1 = 0; c15_i1 < 2; c15_i1++) {
    c15_b_u[c15_i1] = (*chartInstance->c15_Actor_traj_distance)[c15_i1];
  }

  c15_c_y = NULL;
  sf_mex_assign(&c15_c_y, sf_mex_create("y", c15_b_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_setcell(c15_y, 1, c15_c_y);
  for (c15_i1 = 0; c15_i1 < 4; c15_i1++) {
    c15_c_u[c15_i1] = (*chartInstance->c15_pref)[c15_i1];
  }

  c15_d_y = NULL;
  sf_mex_assign(&c15_d_y, sf_mex_create("y", c15_c_u, 0, 0U, 1U, 0U, 1, 4),
                false);
  sf_mex_setcell(c15_y, 2, c15_d_y);
  for (c15_i1 = 0; c15_i1 < 2; c15_i1++) {
    c15_d_u[c15_i1] = chartInstance->c15_Actor_traj_anglePersist[c15_i1];
  }

  c15_e_y = NULL;
  if (!chartInstance->c15_Actor_traj_anglePersist_not_empty) {
    sf_mex_assign(&c15_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c15_e_y, sf_mex_create("y", c15_d_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  false);
  }

  sf_mex_setcell(c15_y, 3, c15_e_y);
  for (c15_i1 = 0; c15_i1 < 2; c15_i1++) {
    c15_e_u[c15_i1] = chartInstance->c15_Actor_traj_distancePersist[c15_i1];
  }

  c15_f_y = NULL;
  if (!chartInstance->c15_Actor_traj_distancePersist_not_empty) {
    sf_mex_assign(&c15_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c15_f_y, sf_mex_create("y", c15_e_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  false);
  }

  sf_mex_setcell(c15_y, 4, c15_f_y);
  for (c15_i1 = 0; c15_i1 < 2; c15_i1++) {
    c15_f_u[c15_i1] = chartInstance->c15_ActualTrajectoryIndex[c15_i1];
  }

  c15_g_y = NULL;
  if (!chartInstance->c15_ActualTrajectoryIndex_not_empty) {
    sf_mex_assign(&c15_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c15_g_y, sf_mex_create("y", c15_f_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  false);
  }

  sf_mex_setcell(c15_y, 5, c15_g_y);
  c15_g_u = chartInstance->c15_Counter;
  c15_h_y = NULL;
  if (!chartInstance->c15_Counter_not_empty) {
    sf_mex_assign(&c15_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c15_h_y, sf_mex_create("y", &c15_g_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c15_y, 6, c15_h_y);
  for (c15_i1 = 0; c15_i1 < 4; c15_i1++) {
    c15_h_u[c15_i1] = chartInstance->c15_prefPersist[c15_i1];
  }

  c15_i_y = NULL;
  if (!chartInstance->c15_prefPersist_not_empty) {
    sf_mex_assign(&c15_i_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c15_i_y, sf_mex_create("y", c15_h_u, 0, 0U, 1U, 0U, 2, 2, 2),
                  false);
  }

  sf_mex_setcell(c15_y, 7, c15_i_y);
  c15_i_u = chartInstance->c15_is_active_c15_Experiment_cs;
  c15_j_y = NULL;
  sf_mex_assign(&c15_j_y, sf_mex_create("y", &c15_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c15_y, 8, c15_j_y);
  sf_mex_assign(&c15_st, c15_y, false);
  return c15_st;
}

static void set_sim_state_c15_Experiment_cs(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_st)
{
  const mxArray *c15_u;
  c15_u = sf_mex_dup(c15_st);
  c15_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 0)),
                       "Actor_traj_angle", *chartInstance->c15_Actor_traj_angle);
  c15_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 1)),
                       "Actor_traj_distance",
                       *chartInstance->c15_Actor_traj_distance);
  c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 2)),
    "pref", *chartInstance->c15_pref);
  c15_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 3)),
    "Actor_traj_anglePersist", chartInstance->c15_Actor_traj_anglePersist);
  c15_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 4)),
    "Actor_traj_distancePersist", chartInstance->c15_Actor_traj_distancePersist);
  c15_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 5)),
    "ActualTrajectoryIndex", chartInstance->c15_ActualTrajectoryIndex);
  chartInstance->c15_Counter = c15_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c15_u, 6)), "Counter");
  c15_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 7)),
    "prefPersist", chartInstance->c15_prefPersist);
  chartInstance->c15_is_active_c15_Experiment_cs = c15_o_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 8)),
     "is_active_c15_Experiment_cs");
  sf_mex_destroy(&c15_u);
  sf_mex_destroy(&c15_st);
}

static void finalize_c15_Experiment_cs(SFc15_Experiment_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c15_Experiment_cs(SFc15_Experiment_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  c15_chartstep_c15_Experiment_cs(chartInstance);
}

static void mdl_start_c15_Experiment_cs(SFc15_Experiment_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c15_chartstep_c15_Experiment_cs(SFc15_Experiment_csInstanceStruct
  *chartInstance)
{
  int32_T c15_k;
  real_T c15_b_pvp[4];
  real_T c15_b_ActorOffset_Left_Right;
  real_T c15_b_TrajOffset_x_y_Y[3];
  real_T c15_b_p0[3];
  real_T c15_Traj_xGlobal[822];
  real_T c15_Traj_yGlobal[822];
  real_T c15_ii[2];
  real_T c15_cosTrajOffset3;
  real_T c15_sinTrajOffset3;
  int32_T c15_j;
  static real_T c15_c_Traj_y[411] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
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
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0003944339587179E-9,
    -1.0050698051600193E-9, -1.0097380709339632E-9, -1.0144276529899798E-9,
    -1.0191030241912813E-9, -1.023792606247298E-9, -1.0284821883033146E-9,
    -1.0331788757866889E-9, -1.0378826686974207E-9, -1.0425864616081526E-9,
    -1.0472902545188845E-9, -1.0520082582843315E-9, -1.056719156622421E-9,
    -1.0614371603878681E-9, -1.0661764804353879E-9, -1.0709015896281926E-9,
    -1.0756266988209973E-9, -1.0803660188685171E-9, -1.085105338916037E-9,
    -1.0898588698182721E-9, -1.0946052952931495E-9, -1.0993588261953846E-9,
    -1.1041194625249773E-9, -1.10888009885457E-9, -1.1136478406115202E-9,
    -1.1184226877958281E-9, -1.1231904295527784E-9, -1.1279723821644438E-9,
    -1.1327543347761093E-9, -1.1375433928151324E-9, -1.1423395562815131E-9,
    -1.1471357197478937E-9, -1.1519318832142744E-9, -1.1567422575353703E-9,
    -1.1615455264291086E-9, -1.1663559007502045E-9, -1.1711733804986579E-9,
    -1.175997965674469E-9, -1.18082255085028E-9, -1.1856471360260912E-9,
    -1.1904788266292599E-9, -1.1953247280871437E-9, -1.2001564186903124E-9,
    -1.2050094255755539E-9, -1.2098624324607954E-9, -1.2147083339186793E-9,
    -1.2195684462312784E-9, -1.224435663971235E-9, -1.2293028817111917E-9,
    -1.234177204878506E-9, -1.2390515280458203E-9, -1.2439258512131346E-9,
    -1.2488143852351641E-9, -1.253695813829836E-9, -1.2585843478518655E-9,
    -1.2634870927286102E-9, -1.2683898376053548E-9, -1.2732925824820995E-9,
    -1.2781953273588442E-9, -1.2831122830903041E-9, -1.288029238821764E-9,
    -1.2929532999805815E-9, -1.297877361139399E-9, -1.3028014222982165E-9,
    -1.3077396943117492E-9, -1.3126779663252819E-9, -1.3176162383388146E-9,
    -1.3225616157797049E-9, -1.3275140986479528E-9, -1.3324665815162007E-9,
    -1.3374332752391638E-9, -1.3423857581074117E-9, -1.3473524518303748E-9,
    -1.3523262509806955E-9, -1.3573071555583738E-9, -1.3622738492813369E-9,
    -1.3672689647137304E-9, -1.3722498692914087E-9, -1.3772520901511598E-9,
    -1.3822401001561957E-9, -1.3872423210159468E-9, -1.3922445418756979E-9,
    -1.3972538681628066E-9, -1.4022702998772729E-9, -1.4072867315917392E-9,
    -1.4123031633062055E-9, -1.4173267004480294E-9, -1.4223644484445686E-9,
    -1.42739509101375E-9, -1.4324328390102892E-9, -1.4374776924341859E-9,
    -1.442515440430725E-9, -1.4475745047093369E-9, -1.4526264635605912E-9,
    -1.4576784224118455E-9, -1.4627516975451726E-9, -1.4678178672511422E-9,
    -1.4728769315297541E-9, -1.4779644175177964E-9, -1.4830447980784811E-9,
    -1.4881180732118082E-9, -1.4932126646272081E-9, -1.4983072560426081E-9,
    -1.503401847458008E-9, -1.5085035443007655E-9, -1.513605241143523E-9,
    -1.5187140434136381E-9, -1.5238228456837533E-9, -1.528938753381226E-9,
    -1.5340617665060563E-9, -1.5391847796308866E-9, -1.5443220036104321E-9,
    -1.5494592275899777E-9, -1.5545964515695232E-9, -1.5597265701217111E-9,
    -1.5648780049559718E-9, -1.5700294397902326E-9, -1.5751808746244933E-9,
    -1.5803394148861116E-9, -1.5855050605750876E-9, -1.5906778116914211E-9,
    -1.595843457380397E-9, -1.6010162084967305E-9, -1.6061889596130641E-9,
    -1.6113830270114704E-9, -1.6165699889825191E-9, -1.6217569509535679E-9,
    -1.6269510183519742E-9, -1.6321592966050957E-9, -1.6373604694308597E-9,
    -1.6425687476839812E-9, -1.6477841313644603E-9, -1.6530066204722971E-9,
    -1.6582220041527762E-9, -1.6634515986879705E-9, -1.6686740877958073E-9,
    -1.6739107877583592E-9, -1.6791545931482688E-9, -1.6843912931108207E-9,
    -1.6896350985007302E-9, -1.6948860093179974E-9, -1.7001440255626221E-9,
    -1.7054020418072469E-9, -1.7106742689065868E-9, -1.7159322851512115E-9,
    -1.7212045122505515E-9, -1.7264767393498914E-9, -1.7317631773039466E-9,
    -1.7370425098306441E-9, -1.7423289477846993E-9, -1.7476295965934696E-9,
    -1.7529231399748824E-9, -1.7582237887836527E-9, -1.7635315430197807E-9,
    -1.7688392972559086E-9, -1.7741470514920366E-9, -1.7794690165828797E-9,
    -1.7847909816737229E-9, -1.790112946764566E-9, -1.7954420172827668E-9,
    -1.8007781932283251E-9, -1.8061143691738835E-9, -1.8114576505467994E-9,
    -1.8168009319197154E-9, -1.8221513187199889E-9, -1.82750881094762E-9,
    -1.8328734086026088E-9, -1.83823090083024E-9, -1.8436026039125863E-9,
    -1.8489672015675751E-9, -1.8543460100772791E-9 };

  static real_T c15_c_Traj_x[411] = { 0.0, 0.15009000000000228,
    0.30034000000000205, 0.45077000000000211, 0.60135999999999967,
    0.75213000000000463, 0.90307000000000315, 1.0541799999999988,
    1.2054599999999986, 1.3569100000000027, 1.5085299999999968,
    1.6603200000000022, 1.8122799999999977, 1.9644100000000044,
    2.1167100000000012, 2.2691899999999983, 2.4218300000000035,
    2.5746399999999987, 2.7276299999999942, 2.8807799999999979,
    3.0341100000000019, 3.1876099999999958, 3.3412700000000051,
    3.4951099999999933, 3.64912, 3.8033000000000037, 3.9576400000000014,
    4.1121600000000065, 4.2668500000000016, 4.421719999999997,
    4.5767499999999934, 4.7319500000000012, 4.8873200000000061,
    5.042860000000001, 5.1985799999999962, 5.3544599999999996, 5.51051,
    5.6667400000000008, 5.8231399999999987, 5.9796999999999976,
    6.1364399999999968, 6.2933499999999931, 6.4504200000000047,
    6.6076700000000024, 6.7650899999999972, 6.9226800000000033,
    7.0804399999999994, 7.23837, 7.3964700000000043, 7.5547399999999989,
    7.7131800000000048, 7.8718000000000039, 8.030580000000004,
    8.1895300000000013, 8.3486599999999989, 8.5079500000000046,
    8.6674199999999963, 8.8270500000000034, 8.9868600000000036,
    9.1468399999999939, 9.3069900000000025, 9.4672999999999981,
    9.6277899999999939, 9.788450000000001, 9.9492800000000052,
    10.110280000000007, 10.271449999999998, 10.43279, 10.594310000000004,
    10.75599, 10.917839999999995, 11.079870000000003, 11.242060000000006,
    11.404419999999998, 11.566960000000005, 11.729659999999999,
    11.892540000000007, 12.055590000000006, 12.218810000000001,
    12.382190000000005, 12.545750000000002, 12.709479999999996,
    12.873380000000001, 13.037450000000003, 13.201689999999996, 13.3661,
    13.53068, 13.695440000000001, 13.860360000000004, 14.025450000000003,
    14.190720000000002, 14.356149999999996, 14.521760000000004,
    14.687529999999999, 14.853480000000001, 15.0196, 15.185880000000001,
    15.352339999999995, 15.51897, 15.685770000000002, 15.85274,
    16.019879999999997, 16.187189999999998, 16.354669999999995,
    16.522320000000004, 16.690139999999996, 16.858139999999995,
    17.026300000000003, 17.19463, 17.363140000000005, 17.531810000000004,
    17.700659999999996, 17.86967000000001, 18.038860000000003, 18.20822,
    18.377750000000002, 18.547440000000005, 18.717310000000008, 18.88735,
    19.057560000000006, 19.22794, 19.398490000000006, 19.569220000000005,
    19.740110000000005, 19.911170000000002, 20.082399999999996,
    20.253810000000005, 20.42538, 20.597130000000003, 20.76904,
    20.941130000000005, 21.113379999999996, 21.28581, 21.458409999999997,
    21.631180000000004, 21.80412, 21.977219999999992, 22.150499999999997,
    22.32395, 22.497580000000003, 22.67137, 22.845330000000008, 23.01946,
    23.193760000000008, 23.368240000000004, 23.54288, 23.717700000000004,
    23.892679999999995, 24.06784, 24.24316, 24.41866, 24.594329999999996,
    24.770170000000004, 24.946170000000006, 25.12235, 25.2987,
    25.475220000000004, 25.651909999999997, 25.82878, 26.00581, 26.18301,
    26.360379999999996, 26.53793, 26.715639999999997, 26.89352, 27.07158,
    27.249810000000007, 27.4282, 27.60677, 27.78551, 27.964410000000004,
    28.143489999999996, 28.32274, 28.502160000000007, 28.681750000000005,
    28.86151, 29.041440000000005, 29.22154, 29.401819999999997,
    29.582259999999994, 29.762869999999996, 29.943659999999998, 30.12461,
    30.30573, 30.48703, 30.668500000000005, 30.850129999999996,
    31.031939999999995, 31.213920000000005, 31.396069999999998,
    31.578380000000006, 31.76087, 31.943529999999992, 32.126359999999991,
    32.30937, 32.492540000000005, 32.675879999999992, 32.859389999999976,
    33.04307, 33.226929999999996, 33.410949999999985, 33.59514999999999,
    33.77951, 33.96405, 34.148759999999996, 34.33363, 34.51868,
    34.703900000000004, 34.889290000000017, 35.07485, 35.260580000000004,
    35.446479999999994, 35.632549999999995, 35.818789999999993,
    36.005199999999988, 36.191780000000008, 36.378540000000015,
    36.565459999999987, 36.752549999999985, 36.93982, 37.127249999999989,
    37.314859999999996, 37.502639999999985, 37.69058, 37.878700000000009,
    38.066990000000004, 38.255449999999996, 38.44408, 38.63287,
    38.821840000000009, 39.010989999999993, 39.2003, 39.38978,
    39.579430000000016, 39.76925, 39.95925, 40.14941, 40.339750000000009,
    40.530249999999995, 40.720929999999996, 40.91176999999999, 41.10279,
    41.293980000000005, 41.48532999999999, 41.676860000000005, 41.86856,
    42.060429999999982, 42.25247, 42.444680000000005, 42.637060000000005,
    42.829610000000017, 43.022339999999986, 43.215230000000005,
    43.408289999999994, 43.60153, 43.794930000000008, 43.988509999999991,
    44.18225000000001, 44.37617, 44.57025, 44.76451, 44.95894,
    45.153540000000007, 45.348309999999984, 45.54324, 45.73835, 45.93364,
    46.129090000000005, 46.32471000000001, 46.5205, 46.71646, 46.9126,
    47.108899999999991, 47.305369999999996, 47.50202, 47.698829999999987,
    47.895819999999986, 48.09298, 48.2903, 48.487799999999993,
    48.685469999999995, 48.883310000000009, 49.081319999999991, 49.2795,
    49.477849999999989, 49.676369999999991, 49.875059999999991,
    50.073920000000015, 50.272949999999994, 50.47216, 50.67152999999999,
    50.87107, 51.07079, 51.27067000000001, 51.47073, 51.670959999999994,
    51.871349999999993, 52.071919999999992, 52.27266, 52.473570000000009,
    52.674650000000014, 52.87589, 53.07731, 53.27891000000001,
    53.480669999999989, 53.682599999999994, 53.884699999999995,
    54.086969999999994, 54.289419999999993, 54.49203, 54.694820000000007,
    54.897769999999994, 55.100899999999996, 55.304189999999991,
    55.507660000000016, 55.711299999999994, 55.915099999999995, 56.11908,
    56.323229999999995, 56.527549999999991, 56.73204, 56.9367,
    57.141529999999989, 57.346529999999987, 57.55171, 57.757050000000007,
    57.962560000000011, 58.16825, 58.3741, 58.580129999999983, 58.78632,
    58.99269000000001, 59.199220000000011, 59.40593, 59.61281000000001,
    59.819860000000006, 60.02708, 60.23446, 60.44202, 60.64975,
    60.857659999999996, 61.06573, 61.273970000000006, 61.482380000000006,
    61.69095999999999, 61.89972, 62.108639999999994, 62.31774,
    62.527000000000015, 62.73644, 62.94605, 63.155820000000006,
    63.365769999999983, 63.57589, 63.78618, 63.99664, 64.20727, 64.41807,
    64.629039999999989, 64.84018, 65.05149, 65.26297, 65.47462, 65.68645,
    65.89844, 66.11061, 66.32294, 66.53545, 66.748119999999986, 66.96097,
    67.17399, 67.387179999999987, 67.60054, 67.81406, 68.02776, 68.24163,
    68.455669999999984, 68.66989, 68.88427, 69.09882, 69.31354, 69.52844,
    69.7435, 69.958730000000017, 70.17414, 70.38972, 70.605459999999979,
    70.821379999999991, 71.03747, 71.25372, 71.47015, 71.68675, 71.90352,
    72.12046, 72.33757, 72.554849999999988, 72.7723, 72.98992, 73.20772,
    73.425679999999986, 73.643809999999988, 73.86211999999999, 74.08059,
    74.29924, 74.518059999999991, 74.73704, 74.956199999999981, 75.17553,
    75.39502, 75.61469, 75.834529999999987 };

  real_T c15_beta;
  real_T c15_sinBeta;
  real_T c15_cosBeta;
  real_T c15_dist_p3;
  real_T c15_b_Traj_xGlobal[2];
  real_T c15_p2[2];
  int32_T c15_exception;
  real_T c15_p1[2];
  real_T c15_c_Traj_xGlobal[2];
  real_T c15_c_pvp[2];
  real_T c15_b_p1[2];
  real_T c15_d_Traj_xGlobal[2];
  real_T c15_d_pvp[2];
  real_T c15_e_Traj_xGlobal[2];
  real_T c15_f_Traj_xGlobal[2];
  real_T c15_e_pvp[2];
  real_T c15_g_Traj_xGlobal[2];
  real_T c15_f_pvp[2];
  real_T c15_h_Traj_xGlobal[2];
  real_T c15_i_Traj_xGlobal[2];
  real_T c15_g_pvp[2];
  real_T c15_h_pvp[2];
  real_T c15_i_pvp[3];
  real_T c15_c_p0[3];
  real_T c15_b_p2[3];
  real_T c15_c_p1[3];
  real_T c15_vehiclevector[3];
  real_T c15_trajectoryvector[3];
  real_T c15_dv2[3];
  real_T c15_d_p0[3];
  real_T c15_e_p0[2];
  real_T c15_f_p0[2];
  for (c15_k = 0; c15_k < 4; c15_k++) {
    c15_b_pvp[c15_k] = (*chartInstance->c15_pvp)[c15_k];
  }

  c15_b_ActorOffset_Left_Right = *chartInstance->c15_ActorOffset_Left_Right;
  for (c15_k = 0; c15_k < 3; c15_k++) {
    c15_b_TrajOffset_x_y_Y[c15_k] = (*chartInstance->c15_TrajOffset_x_y_Y)[c15_k];
    c15_b_p0[c15_k] = (*chartInstance->c15_p0)[c15_k];
  }

  if (!chartInstance->c15_Counter_not_empty) {
    chartInstance->c15_Counter = 0.0;
    chartInstance->c15_Counter_not_empty = true;
  }

  if (!chartInstance->c15_Actor_traj_distancePersist_not_empty) {
    for (c15_k = 0; c15_k < 2; c15_k++) {
      chartInstance->c15_Actor_traj_distancePersist[c15_k] = 0.0;
    }

    chartInstance->c15_Actor_traj_distancePersist_not_empty = true;
  }

  if (!chartInstance->c15_Actor_traj_anglePersist_not_empty) {
    for (c15_k = 0; c15_k < 2; c15_k++) {
      chartInstance->c15_Actor_traj_anglePersist[c15_k] = 0.0;
    }

    chartInstance->c15_Actor_traj_anglePersist_not_empty = true;
  }

  if (!chartInstance->c15_ActualTrajectoryIndex_not_empty) {
    for (c15_k = 0; c15_k < 2; c15_k++) {
      chartInstance->c15_ActualTrajectoryIndex[c15_k] = 1.0;
    }

    chartInstance->c15_ActualTrajectoryIndex_not_empty = true;
  }

  if (!chartInstance->c15_prefPersist_not_empty) {
    for (c15_k = 0; c15_k < 4; c15_k++) {
      chartInstance->c15_prefPersist[c15_k] = 0.0;
    }

    chartInstance->c15_prefPersist_not_empty = true;
  }

  for (c15_k = 0; c15_k < 822; c15_k++) {
    c15_Traj_xGlobal[c15_k] = 0.0;
    c15_Traj_yGlobal[c15_k] = 0.0;
  }

  for (c15_k = 0; c15_k < 2; c15_k++) {
    c15_ii[c15_k] = chartInstance->c15_ActualTrajectoryIndex[c15_k];
  }

  c15_cosTrajOffset3 = muDoubleScalarCos((*chartInstance->c15_TrajOffset_x_y_Y)
    [2]);
  c15_sinTrajOffset3 = muDoubleScalarSin((*chartInstance->c15_TrajOffset_x_y_Y)
    [2]);
  if ((chartInstance->c15_Counter == 1.0) || (chartInstance->c15_Counter == 0.0))
  {
    chartInstance->c15_Counter = 0.0;
    for (c15_j = 0; c15_j < 2; c15_j++) {
      sf_mex_lw_bounds_check((int32_T)c15_ii[c15_j], 1, 411);
      sf_mex_lw_bounds_check((int32_T)c15_ii[c15_j], 1, 411);
      sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] + 1.0), 1, 411);
      sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] + 1.0), 1, 411);
      c15_beta = muDoubleScalarAtan2(((c15_c_Traj_x[(int32_T)(c15_ii[c15_j] +
        1.0) - 1] * c15_sinTrajOffset3 + c15_c_Traj_y[(int32_T)(c15_ii[c15_j] +
        1.0) - 1] * c15_cosTrajOffset3) + c15_b_TrajOffset_x_y_Y[1]) -
        ((c15_c_Traj_x[(int32_T)c15_ii[c15_j] - 1] * c15_sinTrajOffset3 +
          c15_c_Traj_y[(int32_T)c15_ii[c15_j] - 1] * c15_cosTrajOffset3) +
         c15_b_TrajOffset_x_y_Y[1]), ((c15_c_Traj_x[(int32_T)(c15_ii[c15_j] +
        1.0) - 1] * c15_cosTrajOffset3 - c15_c_Traj_y[(int32_T)(c15_ii[c15_j] +
        1.0) - 1] * c15_sinTrajOffset3) + c15_b_TrajOffset_x_y_Y[0]) -
        ((c15_c_Traj_x[(int32_T)c15_ii[c15_j] - 1] * c15_cosTrajOffset3 -
          c15_c_Traj_y[(int32_T)c15_ii[c15_j] - 1] * c15_sinTrajOffset3) +
         c15_b_TrajOffset_x_y_Y[0]));
      c15_sinBeta = muDoubleScalarSin(c15_beta);
      c15_cosBeta = muDoubleScalarCos(c15_beta);
      c15_localToGlobalCoordinates(chartInstance,
        c15_c_Traj_x[sf_mex_lw_bounds_check((int32_T)c15_ii[c15_j], 1, 411) - 1],
        c15_c_Traj_y[sf_mex_lw_bounds_check((int32_T)c15_ii[c15_j], 1, 411) - 1],
        c15_b_TrajOffset_x_y_Y, c15_sinTrajOffset3, c15_cosTrajOffset3,
        c15_b_ActorOffset_Left_Right, c15_sinBeta, c15_cosBeta, &c15_beta,
        &c15_dist_p3);
      c15_Traj_xGlobal[(sf_mex_lw_bounds_check((int32_T)c15_ii[c15_j], 1, 411) +
                        411 * c15_j) - 1] = c15_beta;
      c15_Traj_yGlobal[(sf_mex_lw_bounds_check((int32_T)c15_ii[c15_j], 1, 411) +
                        411 * c15_j) - 1] = c15_dist_p3;
      c15_localToGlobalCoordinates(chartInstance,
        c15_c_Traj_x[sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] + 1.0), 1,
        411) - 1], c15_c_Traj_y[sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] +
        1.0), 1, 411) - 1], c15_b_TrajOffset_x_y_Y, c15_sinTrajOffset3,
        c15_cosTrajOffset3, c15_b_ActorOffset_Left_Right, c15_sinBeta,
        c15_cosBeta, &c15_beta, &c15_dist_p3);
      c15_Traj_xGlobal[(sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] + 1.0), 1,
        411) + 411 * c15_j) - 1] = c15_beta;
      c15_Traj_yGlobal[(sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] + 1.0), 1,
        411) + 411 * c15_j) - 1] = c15_dist_p3;
      c15_b_Traj_xGlobal[0] = c15_Traj_xGlobal[(sf_mex_lw_bounds_check((int32_T)
        c15_ii[c15_j], 1, 411) + 411 * c15_j) - 1];
      c15_b_Traj_xGlobal[1] = c15_Traj_yGlobal[(sf_mex_lw_bounds_check((int32_T)
        c15_ii[c15_j], 1, 411) + 411 * c15_j) - 1];
      for (c15_k = 0; c15_k < 2; c15_k++) {
        c15_p2[c15_k] = c15_b_Traj_xGlobal[c15_k];
      }

      if (c15_ii[c15_j] == 1.0) {
        c15_exception = 1;
        for (c15_k = 0; c15_k < 2; c15_k++) {
          c15_p1[c15_k] = c15_p2[c15_k];
        }
      } else {
        c15_exception = 0;
        c15_localToGlobalCoordinates(chartInstance,
          c15_c_Traj_x[sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] - 1.0), 1,
          411) - 1], c15_c_Traj_y[sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j]
          - 1.0), 1, 411) - 1], c15_b_TrajOffset_x_y_Y, c15_sinTrajOffset3,
          c15_cosTrajOffset3, c15_b_ActorOffset_Left_Right, c15_sinBeta,
          c15_cosBeta, &c15_beta, &c15_dist_p3);
        c15_Traj_xGlobal[(sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] - 1.0),
          1, 411) + 411 * c15_j) - 1] = c15_beta;
        c15_Traj_yGlobal[(sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] - 1.0),
          1, 411) + 411 * c15_j) - 1] = c15_dist_p3;
        c15_c_Traj_xGlobal[0] = c15_Traj_xGlobal[(sf_mex_lw_bounds_check
          ((int32_T)(c15_ii[c15_j] - 1.0), 1, 411) + 411 * c15_j) - 1];
        c15_c_Traj_xGlobal[1] = c15_Traj_yGlobal[(sf_mex_lw_bounds_check
          ((int32_T)(c15_ii[c15_j] - 1.0), 1, 411) + 411 * c15_j) - 1];
        for (c15_k = 0; c15_k < 2; c15_k++) {
          c15_p1[c15_k] = c15_c_Traj_xGlobal[c15_k];
        }

        sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] + 1.0), 1, 411);
        sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] + 1.0), 1, 411);
        c15_c_pvp[0] = c15_b_pvp[c15_j << 1];
        c15_c_pvp[1] = c15_b_pvp[1 + (c15_j << 1)];
        for (c15_k = 0; c15_k < 2; c15_k++) {
          c15_b_p1[c15_k] = c15_p1[c15_k] - c15_c_pvp[c15_k];
        }

        c15_beta = c15_norm(chartInstance, c15_b_p1);
        c15_d_Traj_xGlobal[0] = c15_Traj_xGlobal[((int32_T)(c15_ii[c15_j] + 1.0)
          + 411 * c15_j) - 1];
        c15_d_Traj_xGlobal[1] = c15_Traj_yGlobal[((int32_T)(c15_ii[c15_j] + 1.0)
          + 411 * c15_j) - 1];
        c15_d_pvp[0] = c15_b_pvp[c15_j << 1];
        c15_d_pvp[1] = c15_b_pvp[1 + (c15_j << 1)];
        for (c15_k = 0; c15_k < 2; c15_k++) {
          c15_b_p1[c15_k] = c15_d_Traj_xGlobal[c15_k] - c15_d_pvp[c15_k];
        }

        c15_dist_p3 = c15_norm(chartInstance, c15_b_p1);
        while ((c15_beta >= c15_dist_p3) && (c15_ii[c15_j] < 410.0)) {
          c15_ii[c15_j]++;
          c15_localToGlobalCoordinates(chartInstance,
            c15_c_Traj_x[sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] + 1.0),
            1, 411) - 1], c15_c_Traj_y[sf_mex_lw_bounds_check((int32_T)
            (c15_ii[c15_j] + 1.0), 1, 411) - 1], c15_b_TrajOffset_x_y_Y,
            c15_sinTrajOffset3, c15_cosTrajOffset3, c15_b_ActorOffset_Left_Right,
            c15_sinBeta, c15_cosBeta, &c15_beta, &c15_dist_p3);
          c15_Traj_xGlobal[(sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] + 1.0),
            1, 411) + 411 * c15_j) - 1] = c15_beta;
          c15_Traj_yGlobal[(sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] + 1.0),
            1, 411) + 411 * c15_j) - 1] = c15_dist_p3;
          c15_e_Traj_xGlobal[0] = c15_Traj_xGlobal[(sf_mex_lw_bounds_check
            ((int32_T)(c15_ii[c15_j] - 1.0), 1, 411) + 411 * c15_j) - 1];
          c15_e_Traj_xGlobal[1] = c15_Traj_yGlobal[(sf_mex_lw_bounds_check
            ((int32_T)(c15_ii[c15_j] - 1.0), 1, 411) + 411 * c15_j) - 1];
          for (c15_k = 0; c15_k < 2; c15_k++) {
            c15_p1[c15_k] = c15_e_Traj_xGlobal[c15_k];
          }

          c15_f_Traj_xGlobal[0] = c15_Traj_xGlobal[(sf_mex_lw_bounds_check
            ((int32_T)c15_ii[c15_j], 1, 411) + 411 * c15_j) - 1];
          c15_f_Traj_xGlobal[1] = c15_Traj_yGlobal[(sf_mex_lw_bounds_check
            ((int32_T)c15_ii[c15_j], 1, 411) + 411 * c15_j) - 1];
          for (c15_k = 0; c15_k < 2; c15_k++) {
            c15_p2[c15_k] = c15_f_Traj_xGlobal[c15_k];
          }

          sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] + 1.0), 1, 411);
          sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] + 1.0), 1, 411);
          c15_e_pvp[0] = c15_b_pvp[c15_j << 1];
          c15_e_pvp[1] = c15_b_pvp[1 + (c15_j << 1)];
          for (c15_k = 0; c15_k < 2; c15_k++) {
            c15_b_p1[c15_k] = c15_p1[c15_k] - c15_e_pvp[c15_k];
          }

          c15_beta = c15_norm(chartInstance, c15_b_p1);
          c15_g_Traj_xGlobal[0] = c15_Traj_xGlobal[((int32_T)(c15_ii[c15_j] +
            1.0) + 411 * c15_j) - 1];
          c15_g_Traj_xGlobal[1] = c15_Traj_yGlobal[((int32_T)(c15_ii[c15_j] +
            1.0) + 411 * c15_j) - 1];
          c15_f_pvp[0] = c15_b_pvp[c15_j << 1];
          c15_f_pvp[1] = c15_b_pvp[1 + (c15_j << 1)];
          for (c15_k = 0; c15_k < 2; c15_k++) {
            c15_b_p1[c15_k] = c15_g_Traj_xGlobal[c15_k] - c15_f_pvp[c15_k];
          }

          c15_dist_p3 = c15_norm(chartInstance, c15_b_p1);
          _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
        }

        chartInstance->c15_ActualTrajectoryIndex[c15_j] = c15_ii[c15_j];
        if (c15_ii[c15_j] >= 410.0) {
          c15_h_Traj_xGlobal[0] = c15_Traj_xGlobal[410 + 411 * c15_j];
          c15_h_Traj_xGlobal[1] = c15_Traj_yGlobal[410 + 411 * c15_j];
          c15_beta = muDoubleScalarAtan2(c15_Traj_yGlobal[410 + 411 * c15_j] -
            c15_Traj_yGlobal[409 + 411 * c15_j], c15_Traj_xGlobal[410 + 411 *
            c15_j] - c15_Traj_xGlobal[409 + 411 * c15_j]);
          c15_i_Traj_xGlobal[0] = c15_Traj_xGlobal[410 + 411 * c15_j] +
            muDoubleScalarCos(c15_beta);
          c15_i_Traj_xGlobal[1] = c15_Traj_yGlobal[410 + 411 * c15_j] +
            muDoubleScalarSin(c15_beta);
          for (c15_k = 0; c15_k < 2; c15_k++) {
            c15_p1[c15_k] = c15_h_Traj_xGlobal[c15_k];
            c15_p2[c15_k] = c15_i_Traj_xGlobal[c15_k];
          }
        }
      }

      if (c15_exception == 1) {
        c15_g_pvp[0] = c15_b_pvp[c15_j << 1];
        c15_g_pvp[1] = c15_b_pvp[1 + (c15_j << 1)];
        for (c15_k = 0; c15_k < 2; c15_k++) {
          chartInstance->c15_prefPersist[c15_k + (c15_j << 1)] = c15_g_pvp[c15_k];
        }

        c15_ii[c15_j] = 2.0;
        chartInstance->c15_ActualTrajectoryIndex[c15_j] = c15_ii[c15_j];
      } else {
        c15_h_pvp[0] = c15_b_pvp[c15_j << 1];
        c15_h_pvp[1] = c15_b_pvp[1 + (c15_j << 1)];
        c15_dist_p3 = 0.0;
        for (c15_k = 0; c15_k < 2; c15_k++) {
          c15_dist_p3 += (c15_p1[c15_k] - c15_h_pvp[c15_k]) * (c15_p2[c15_k] -
            c15_p1[c15_k]);
          c15_b_p1[c15_k] = c15_p2[c15_k] - c15_p1[c15_k];
        }

        c15_beta = c15_norm(chartInstance, c15_b_p1);
        c15_beta = -c15_dist_p3 / (c15_beta * c15_beta);
        if ((c15_beta < 0.0) && (c15_ii[c15_j] < 410.0)) {
          for (c15_k = 0; c15_k < 2; c15_k++) {
            chartInstance->c15_prefPersist[c15_k + (c15_j << 1)] = c15_p1[c15_k];
          }
        } else {
          for (c15_k = 0; c15_k < 2; c15_k++) {
            chartInstance->c15_prefPersist[c15_k + (c15_j << 1)] = c15_p1[c15_k]
              + c15_beta * (c15_p2[c15_k] - c15_p1[c15_k]);
          }
        }

        c15_i_pvp[0] = c15_b_pvp[2];
        c15_i_pvp[1] = c15_b_pvp[3];
        c15_i_pvp[2] = 0.0;
        c15_c_p0[0] = c15_b_p0[0];
        c15_c_p0[1] = c15_b_p0[1];
        c15_c_p0[2] = 0.0;
        c15_b_p2[0] = c15_p2[0];
        c15_b_p2[1] = c15_p2[1];
        c15_b_p2[2] = 0.0;
        c15_c_p1[0] = c15_p1[0];
        c15_c_p1[1] = c15_p1[1];
        c15_c_p1[2] = 0.0;
        for (c15_k = 0; c15_k < 3; c15_k++) {
          c15_vehiclevector[c15_k] = c15_i_pvp[c15_k] - c15_c_p0[c15_k];
          c15_trajectoryvector[c15_k] = c15_b_p2[c15_k] - c15_c_p1[c15_k];
        }

        c15_cosBeta = c15_trajectoryvector[0] * c15_vehiclevector[1] -
          c15_trajectoryvector[1] * c15_vehiclevector[0];
        c15_dist_p3 = 0.0;
        for (c15_k = 0; c15_k < 3; c15_k++) {
          c15_dist_p3 += c15_trajectoryvector[c15_k] * c15_vehiclevector[c15_k];
        }

        c15_beta = muDoubleScalarAtan2(muDoubleScalarAbs(c15_cosBeta),
          c15_dist_p3);
        if (c15_cosBeta == 0.0) {
          chartInstance->c15_Actor_traj_anglePersist[c15_j] = c15_beta * 180.0 /
            3.1415926535897931;
        } else {
          c15_beta *= muDoubleScalarSign(c15_cosBeta);
          chartInstance->c15_Actor_traj_anglePersist[c15_j] = c15_beta * 180.0 /
            3.1415926535897931;
        }

        c15_dv2[0] = chartInstance->c15_prefPersist[c15_j << 1];
        c15_dv2[1] = chartInstance->c15_prefPersist[1 + (c15_j << 1)];
        c15_dv2[2] = 0.0;
        c15_d_p0[0] = c15_b_p0[0];
        c15_d_p0[1] = c15_b_p0[1];
        c15_d_p0[2] = 0.0;
        for (c15_k = 0; c15_k < 3; c15_k++) {
          c15_trajectoryvector[c15_k] = c15_dv2[c15_k] - c15_d_p0[c15_k];
        }

        c15_cosBeta = c15_trajectoryvector[0] * c15_vehiclevector[1] -
          c15_trajectoryvector[1] * c15_vehiclevector[0];
        if (c15_cosBeta == 0.0) {
          c15_e_p0[0] = c15_b_p0[0];
          c15_e_p0[1] = c15_b_p0[1];
          for (c15_k = 0; c15_k < 2; c15_k++) {
            c15_b_p1[c15_k] = chartInstance->c15_prefPersist[c15_k + (c15_j << 1)]
              - c15_e_p0[c15_k];
          }

          chartInstance->c15_Actor_traj_distancePersist[c15_j] = c15_norm
            (chartInstance, c15_b_p1);
        } else {
          c15_f_p0[0] = c15_b_p0[0];
          c15_f_p0[1] = c15_b_p0[1];
          for (c15_k = 0; c15_k < 2; c15_k++) {
            c15_b_p1[c15_k] = chartInstance->c15_prefPersist[c15_k + (c15_j << 1)]
              - c15_f_p0[c15_k];
          }

          chartInstance->c15_Actor_traj_distancePersist[c15_j] = c15_norm
            (chartInstance, c15_b_p1) * muDoubleScalarSign(c15_cosBeta);
        }
      }

      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }
  }

  chartInstance->c15_Counter++;
  for (c15_k = 0; c15_k < 4; c15_k++) {
    (*chartInstance->c15_pref)[c15_k] = chartInstance->c15_prefPersist[c15_k];
  }

  for (c15_k = 0; c15_k < 2; c15_k++) {
    (*chartInstance->c15_Actor_traj_distance)[c15_k] =
      chartInstance->c15_Actor_traj_distancePersist[c15_k];
    (*chartInstance->c15_Actor_traj_angle)[c15_k] =
      chartInstance->c15_Actor_traj_anglePersist[c15_k];
  }
}

static void initSimStructsc15_Experiment_cs(SFc15_Experiment_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber, uint32_T c15_instanceNumber)
{
  (void)c15_machineNumber;
  (void)c15_chartNumber;
  (void)c15_instanceNumber;
}

const mxArray *sf_c15_Experiment_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c15_nameCaptureInfo = NULL;
  c15_nameCaptureInfo = NULL;
  sf_mex_assign(&c15_nameCaptureInfo, sf_mex_createstruct("structure", 2, 79, 1),
                false);
  c15_info_helper(&c15_nameCaptureInfo);
  c15_b_info_helper(&c15_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c15_nameCaptureInfo);
  return c15_nameCaptureInfo;
}

static void c15_info_helper(const mxArray **c15_info)
{
  const mxArray *c15_rhs0 = NULL;
  const mxArray *c15_lhs0 = NULL;
  const mxArray *c15_rhs1 = NULL;
  const mxArray *c15_lhs1 = NULL;
  const mxArray *c15_rhs2 = NULL;
  const mxArray *c15_lhs2 = NULL;
  const mxArray *c15_rhs3 = NULL;
  const mxArray *c15_lhs3 = NULL;
  const mxArray *c15_rhs4 = NULL;
  const mxArray *c15_lhs4 = NULL;
  const mxArray *c15_rhs5 = NULL;
  const mxArray *c15_lhs5 = NULL;
  const mxArray *c15_rhs6 = NULL;
  const mxArray *c15_lhs6 = NULL;
  const mxArray *c15_rhs7 = NULL;
  const mxArray *c15_lhs7 = NULL;
  const mxArray *c15_rhs8 = NULL;
  const mxArray *c15_lhs8 = NULL;
  const mxArray *c15_rhs9 = NULL;
  const mxArray *c15_lhs9 = NULL;
  const mxArray *c15_rhs10 = NULL;
  const mxArray *c15_lhs10 = NULL;
  const mxArray *c15_rhs11 = NULL;
  const mxArray *c15_lhs11 = NULL;
  const mxArray *c15_rhs12 = NULL;
  const mxArray *c15_lhs12 = NULL;
  const mxArray *c15_rhs13 = NULL;
  const mxArray *c15_lhs13 = NULL;
  const mxArray *c15_rhs14 = NULL;
  const mxArray *c15_lhs14 = NULL;
  const mxArray *c15_rhs15 = NULL;
  const mxArray *c15_lhs15 = NULL;
  const mxArray *c15_rhs16 = NULL;
  const mxArray *c15_lhs16 = NULL;
  const mxArray *c15_rhs17 = NULL;
  const mxArray *c15_lhs17 = NULL;
  const mxArray *c15_rhs18 = NULL;
  const mxArray *c15_lhs18 = NULL;
  const mxArray *c15_rhs19 = NULL;
  const mxArray *c15_lhs19 = NULL;
  const mxArray *c15_rhs20 = NULL;
  const mxArray *c15_lhs20 = NULL;
  const mxArray *c15_rhs21 = NULL;
  const mxArray *c15_lhs21 = NULL;
  const mxArray *c15_rhs22 = NULL;
  const mxArray *c15_lhs22 = NULL;
  const mxArray *c15_rhs23 = NULL;
  const mxArray *c15_lhs23 = NULL;
  const mxArray *c15_rhs24 = NULL;
  const mxArray *c15_lhs24 = NULL;
  const mxArray *c15_rhs25 = NULL;
  const mxArray *c15_lhs25 = NULL;
  const mxArray *c15_rhs26 = NULL;
  const mxArray *c15_lhs26 = NULL;
  const mxArray *c15_rhs27 = NULL;
  const mxArray *c15_lhs27 = NULL;
  const mxArray *c15_rhs28 = NULL;
  const mxArray *c15_lhs28 = NULL;
  const mxArray *c15_rhs29 = NULL;
  const mxArray *c15_lhs29 = NULL;
  const mxArray *c15_rhs30 = NULL;
  const mxArray *c15_lhs30 = NULL;
  const mxArray *c15_rhs31 = NULL;
  const mxArray *c15_lhs31 = NULL;
  const mxArray *c15_rhs32 = NULL;
  const mxArray *c15_lhs32 = NULL;
  const mxArray *c15_rhs33 = NULL;
  const mxArray *c15_lhs33 = NULL;
  const mxArray *c15_rhs34 = NULL;
  const mxArray *c15_lhs34 = NULL;
  const mxArray *c15_rhs35 = NULL;
  const mxArray *c15_lhs35 = NULL;
  const mxArray *c15_rhs36 = NULL;
  const mxArray *c15_lhs36 = NULL;
  const mxArray *c15_rhs37 = NULL;
  const mxArray *c15_lhs37 = NULL;
  const mxArray *c15_rhs38 = NULL;
  const mxArray *c15_lhs38 = NULL;
  const mxArray *c15_rhs39 = NULL;
  const mxArray *c15_lhs39 = NULL;
  const mxArray *c15_rhs40 = NULL;
  const mxArray *c15_lhs40 = NULL;
  const mxArray *c15_rhs41 = NULL;
  const mxArray *c15_lhs41 = NULL;
  const mxArray *c15_rhs42 = NULL;
  const mxArray *c15_lhs42 = NULL;
  const mxArray *c15_rhs43 = NULL;
  const mxArray *c15_lhs43 = NULL;
  const mxArray *c15_rhs44 = NULL;
  const mxArray *c15_lhs44 = NULL;
  const mxArray *c15_rhs45 = NULL;
  const mxArray *c15_lhs45 = NULL;
  const mxArray *c15_rhs46 = NULL;
  const mxArray *c15_lhs46 = NULL;
  const mxArray *c15_rhs47 = NULL;
  const mxArray *c15_lhs47 = NULL;
  const mxArray *c15_rhs48 = NULL;
  const mxArray *c15_lhs48 = NULL;
  const mxArray *c15_rhs49 = NULL;
  const mxArray *c15_lhs49 = NULL;
  const mxArray *c15_rhs50 = NULL;
  const mxArray *c15_lhs50 = NULL;
  const mxArray *c15_rhs51 = NULL;
  const mxArray *c15_lhs51 = NULL;
  const mxArray *c15_rhs52 = NULL;
  const mxArray *c15_lhs52 = NULL;
  const mxArray *c15_rhs53 = NULL;
  const mxArray *c15_lhs53 = NULL;
  const mxArray *c15_rhs54 = NULL;
  const mxArray *c15_lhs54 = NULL;
  const mxArray *c15_rhs55 = NULL;
  const mxArray *c15_lhs55 = NULL;
  const mxArray *c15_rhs56 = NULL;
  const mxArray *c15_lhs56 = NULL;
  const mxArray *c15_rhs57 = NULL;
  const mxArray *c15_lhs57 = NULL;
  const mxArray *c15_rhs58 = NULL;
  const mxArray *c15_lhs58 = NULL;
  const mxArray *c15_rhs59 = NULL;
  const mxArray *c15_lhs59 = NULL;
  const mxArray *c15_rhs60 = NULL;
  const mxArray *c15_lhs60 = NULL;
  const mxArray *c15_rhs61 = NULL;
  const mxArray *c15_lhs61 = NULL;
  const mxArray *c15_rhs62 = NULL;
  const mxArray *c15_lhs62 = NULL;
  const mxArray *c15_rhs63 = NULL;
  const mxArray *c15_lhs63 = NULL;
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "emlfcn_find_closest_trajectory_points"), "name", "name", 0);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[E]C:/Program Files/PreScan/PreScan_8.1.0/SimulationCore/MatlabCode/CompilationSheet/emlfcn_find_closest_trajectory_points.p"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1497540868U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c15_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[E]C:/Program Files/PreScan/PreScan_8.1.0/SimulationCore/MatlabCode/CompilationSheet/emlfcn_find_closest_trajectory_points.p"),
                  "context", "context", 1);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("length"), "name", "name", 1);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1303167806U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c15_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[E]C:/Program Files/PreScan/PreScan_8.1.0/SimulationCore/MatlabCode/CompilationSheet/emlfcn_find_closest_trajectory_points.p"),
                  "context", "context", 2);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("cos"), "name", "name", 2);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1395346496U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c15_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 3);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1286840322U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c15_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[E]C:/Program Files/PreScan/PreScan_8.1.0/SimulationCore/MatlabCode/CompilationSheet/emlfcn_find_closest_trajectory_points.p"),
                  "context", "context", 4);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("sin"), "name", "name", 4);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1395346504U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c15_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 5);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1286840336U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c15_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[E]C:/Program Files/PreScan/PreScan_8.1.0/SimulationCore/MatlabCode/CompilationSheet/emlfcn_find_closest_trajectory_points.p!cal"
    "culateTrajHeading"), "context", "context", 6);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("atan2"), "name", "name", 6);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1395346496U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c15_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 7);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c15_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 8);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c15_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 9);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c15_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 10);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c15_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_scalar_atan2"), "name",
                  "name", 11);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1286840320U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c15_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[E]C:/Program Files/PreScan/PreScan_8.1.0/SimulationCore/MatlabCode/CompilationSheet/emlfcn_find_closest_trajectory_points.p"),
                  "context", "context", 12);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("norm"), "name", "name", 12);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1363731868U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c15_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 13);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 13);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c15_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 14);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 14);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c15_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 15);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_xnrm2"), "name", "name",
                  15);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1376002292U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c15_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 16);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c15_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.blas.xnrm2"),
                  "name", "name", 17);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c15_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "context", "context", 18);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 18);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c15_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p!below_threshold"),
                  "context", "context", 19);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 19);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c15_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 20);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 20);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c15_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "context", "context", 21);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "coder.internal.refblas.xnrm2"), "name", "name", 21);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c15_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 22);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("realmin"), "name", "name",
                  22);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1307672842U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c15_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_realmin"), "name",
                  "name", 23);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1307672844U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c15_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 24);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c15_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 25);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 25);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c15_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 26);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 26);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 26);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c15_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 27);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 27);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 27);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c15_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 28);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 28);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c15_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 29);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("isfi"), "name", "name", 29);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 29);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1346531958U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c15_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 30);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1398897198U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c15_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 31);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("intmax"), "name", "name", 31);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c15_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 32);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c15_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 33);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("intmin"), "name", "name", 33);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c15_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 34);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c15_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 35);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("abs"), "name", "name", 35);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c15_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 36);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c15_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 37);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c15_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[E]C:/Program Files/PreScan/PreScan_8.1.0/SimulationCore/MatlabCode/CompilationSheet/emlfcn_find_closest_trajectory_points.p"),
                  "context", "context", 38);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("atan2"), "name", "name", 38);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1395346496U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c15_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[E]C:/Program Files/PreScan/PreScan_8.1.0/SimulationCore/MatlabCode/CompilationSheet/emlfcn_find_closest_trajectory_points.p"),
                  "context", "context", 39);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 39);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c15_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 40);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 40);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c15_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 41);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 41);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c15_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 42);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 42);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c15_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 43);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 43);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c15_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 44);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_xdotu"), "name", "name",
                  44);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1376002290U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c15_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 45);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 45);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c15_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 46);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.blas.xdotu"),
                  "name", "name", 46);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotu.p"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c15_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotu.p"),
                  "context", "context", 47);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.blas.xdot"),
                  "name", "name", 47);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c15_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 48);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 48);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c15_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p!below_threshold"),
                  "context", "context", 49);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 49);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c15_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 50);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.refblas.xdot"),
                  "name", "name", 50);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "resolved", "resolved", 50);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c15_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "context", "context", 51);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "coder.internal.refblas.xdotx"), "name", "name", 51);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c15_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 52);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 52);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 52);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c15_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 53);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 53);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 53);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c15_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 54);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 54);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 54);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 54);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c15_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 55);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 55);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 55);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 55);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c15_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 56);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 56);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 56);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c15_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[E]C:/Program Files/PreScan/PreScan_8.1.0/SimulationCore/MatlabCode/CompilationSheet/emlfcn_find_closest_trajectory_points.p"),
                  "context", "context", 57);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("mpower"), "name", "name", 57);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 57);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1363731878U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c15_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 58);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 58);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 58);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c15_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 59);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("ismatrix"), "name", "name",
                  59);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 59);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1331326458U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c15_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 60);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("power"), "name", "name", 60);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 60);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1395346506U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c15_rhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 61);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 61);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 61);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c15_rhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 62);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 62);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 62);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c15_rhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 63);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 63);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 63);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 63);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c15_rhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs63), "lhs", "lhs",
                  63);
  sf_mex_destroy(&c15_rhs0);
  sf_mex_destroy(&c15_lhs0);
  sf_mex_destroy(&c15_rhs1);
  sf_mex_destroy(&c15_lhs1);
  sf_mex_destroy(&c15_rhs2);
  sf_mex_destroy(&c15_lhs2);
  sf_mex_destroy(&c15_rhs3);
  sf_mex_destroy(&c15_lhs3);
  sf_mex_destroy(&c15_rhs4);
  sf_mex_destroy(&c15_lhs4);
  sf_mex_destroy(&c15_rhs5);
  sf_mex_destroy(&c15_lhs5);
  sf_mex_destroy(&c15_rhs6);
  sf_mex_destroy(&c15_lhs6);
  sf_mex_destroy(&c15_rhs7);
  sf_mex_destroy(&c15_lhs7);
  sf_mex_destroy(&c15_rhs8);
  sf_mex_destroy(&c15_lhs8);
  sf_mex_destroy(&c15_rhs9);
  sf_mex_destroy(&c15_lhs9);
  sf_mex_destroy(&c15_rhs10);
  sf_mex_destroy(&c15_lhs10);
  sf_mex_destroy(&c15_rhs11);
  sf_mex_destroy(&c15_lhs11);
  sf_mex_destroy(&c15_rhs12);
  sf_mex_destroy(&c15_lhs12);
  sf_mex_destroy(&c15_rhs13);
  sf_mex_destroy(&c15_lhs13);
  sf_mex_destroy(&c15_rhs14);
  sf_mex_destroy(&c15_lhs14);
  sf_mex_destroy(&c15_rhs15);
  sf_mex_destroy(&c15_lhs15);
  sf_mex_destroy(&c15_rhs16);
  sf_mex_destroy(&c15_lhs16);
  sf_mex_destroy(&c15_rhs17);
  sf_mex_destroy(&c15_lhs17);
  sf_mex_destroy(&c15_rhs18);
  sf_mex_destroy(&c15_lhs18);
  sf_mex_destroy(&c15_rhs19);
  sf_mex_destroy(&c15_lhs19);
  sf_mex_destroy(&c15_rhs20);
  sf_mex_destroy(&c15_lhs20);
  sf_mex_destroy(&c15_rhs21);
  sf_mex_destroy(&c15_lhs21);
  sf_mex_destroy(&c15_rhs22);
  sf_mex_destroy(&c15_lhs22);
  sf_mex_destroy(&c15_rhs23);
  sf_mex_destroy(&c15_lhs23);
  sf_mex_destroy(&c15_rhs24);
  sf_mex_destroy(&c15_lhs24);
  sf_mex_destroy(&c15_rhs25);
  sf_mex_destroy(&c15_lhs25);
  sf_mex_destroy(&c15_rhs26);
  sf_mex_destroy(&c15_lhs26);
  sf_mex_destroy(&c15_rhs27);
  sf_mex_destroy(&c15_lhs27);
  sf_mex_destroy(&c15_rhs28);
  sf_mex_destroy(&c15_lhs28);
  sf_mex_destroy(&c15_rhs29);
  sf_mex_destroy(&c15_lhs29);
  sf_mex_destroy(&c15_rhs30);
  sf_mex_destroy(&c15_lhs30);
  sf_mex_destroy(&c15_rhs31);
  sf_mex_destroy(&c15_lhs31);
  sf_mex_destroy(&c15_rhs32);
  sf_mex_destroy(&c15_lhs32);
  sf_mex_destroy(&c15_rhs33);
  sf_mex_destroy(&c15_lhs33);
  sf_mex_destroy(&c15_rhs34);
  sf_mex_destroy(&c15_lhs34);
  sf_mex_destroy(&c15_rhs35);
  sf_mex_destroy(&c15_lhs35);
  sf_mex_destroy(&c15_rhs36);
  sf_mex_destroy(&c15_lhs36);
  sf_mex_destroy(&c15_rhs37);
  sf_mex_destroy(&c15_lhs37);
  sf_mex_destroy(&c15_rhs38);
  sf_mex_destroy(&c15_lhs38);
  sf_mex_destroy(&c15_rhs39);
  sf_mex_destroy(&c15_lhs39);
  sf_mex_destroy(&c15_rhs40);
  sf_mex_destroy(&c15_lhs40);
  sf_mex_destroy(&c15_rhs41);
  sf_mex_destroy(&c15_lhs41);
  sf_mex_destroy(&c15_rhs42);
  sf_mex_destroy(&c15_lhs42);
  sf_mex_destroy(&c15_rhs43);
  sf_mex_destroy(&c15_lhs43);
  sf_mex_destroy(&c15_rhs44);
  sf_mex_destroy(&c15_lhs44);
  sf_mex_destroy(&c15_rhs45);
  sf_mex_destroy(&c15_lhs45);
  sf_mex_destroy(&c15_rhs46);
  sf_mex_destroy(&c15_lhs46);
  sf_mex_destroy(&c15_rhs47);
  sf_mex_destroy(&c15_lhs47);
  sf_mex_destroy(&c15_rhs48);
  sf_mex_destroy(&c15_lhs48);
  sf_mex_destroy(&c15_rhs49);
  sf_mex_destroy(&c15_lhs49);
  sf_mex_destroy(&c15_rhs50);
  sf_mex_destroy(&c15_lhs50);
  sf_mex_destroy(&c15_rhs51);
  sf_mex_destroy(&c15_lhs51);
  sf_mex_destroy(&c15_rhs52);
  sf_mex_destroy(&c15_lhs52);
  sf_mex_destroy(&c15_rhs53);
  sf_mex_destroy(&c15_lhs53);
  sf_mex_destroy(&c15_rhs54);
  sf_mex_destroy(&c15_lhs54);
  sf_mex_destroy(&c15_rhs55);
  sf_mex_destroy(&c15_lhs55);
  sf_mex_destroy(&c15_rhs56);
  sf_mex_destroy(&c15_lhs56);
  sf_mex_destroy(&c15_rhs57);
  sf_mex_destroy(&c15_lhs57);
  sf_mex_destroy(&c15_rhs58);
  sf_mex_destroy(&c15_lhs58);
  sf_mex_destroy(&c15_rhs59);
  sf_mex_destroy(&c15_lhs59);
  sf_mex_destroy(&c15_rhs60);
  sf_mex_destroy(&c15_lhs60);
  sf_mex_destroy(&c15_rhs61);
  sf_mex_destroy(&c15_lhs61);
  sf_mex_destroy(&c15_rhs62);
  sf_mex_destroy(&c15_lhs62);
  sf_mex_destroy(&c15_rhs63);
  sf_mex_destroy(&c15_lhs63);
}

static const mxArray *c15_emlrt_marshallOut(const char * c15_u)
{
  const mxArray *c15_y = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c15_u)), false);
  return c15_y;
}

static const mxArray *c15_b_emlrt_marshallOut(const uint32_T c15_u)
{
  const mxArray *c15_y = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 7, 0U, 0U, 0U, 0), false);
  return c15_y;
}

static void c15_b_info_helper(const mxArray **c15_info)
{
  const mxArray *c15_rhs64 = NULL;
  const mxArray *c15_lhs64 = NULL;
  const mxArray *c15_rhs65 = NULL;
  const mxArray *c15_lhs65 = NULL;
  const mxArray *c15_rhs66 = NULL;
  const mxArray *c15_lhs66 = NULL;
  const mxArray *c15_rhs67 = NULL;
  const mxArray *c15_lhs67 = NULL;
  const mxArray *c15_rhs68 = NULL;
  const mxArray *c15_lhs68 = NULL;
  const mxArray *c15_rhs69 = NULL;
  const mxArray *c15_lhs69 = NULL;
  const mxArray *c15_rhs70 = NULL;
  const mxArray *c15_lhs70 = NULL;
  const mxArray *c15_rhs71 = NULL;
  const mxArray *c15_lhs71 = NULL;
  const mxArray *c15_rhs72 = NULL;
  const mxArray *c15_lhs72 = NULL;
  const mxArray *c15_rhs73 = NULL;
  const mxArray *c15_lhs73 = NULL;
  const mxArray *c15_rhs74 = NULL;
  const mxArray *c15_lhs74 = NULL;
  const mxArray *c15_rhs75 = NULL;
  const mxArray *c15_lhs75 = NULL;
  const mxArray *c15_rhs76 = NULL;
  const mxArray *c15_lhs76 = NULL;
  const mxArray *c15_rhs77 = NULL;
  const mxArray *c15_lhs77 = NULL;
  const mxArray *c15_rhs78 = NULL;
  const mxArray *c15_lhs78 = NULL;
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 64);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("floor"), "name", "name", 64);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 64);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 64);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 64);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 64);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 64);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 64);
  sf_mex_assign(&c15_rhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs64), "rhs", "rhs",
                  64);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs64), "lhs", "lhs",
                  64);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 65);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 65);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 65);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 65);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 65);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 65);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 65);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 65);
  sf_mex_assign(&c15_rhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs65), "rhs", "rhs",
                  65);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs65), "lhs", "lhs",
                  65);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 66);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 66);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 66);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 66);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1286840326U), "fileTimeLo",
                  "fileTimeLo", 66);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 66);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 66);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 66);
  sf_mex_assign(&c15_rhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs66), "rhs", "rhs",
                  66);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs66), "lhs", "lhs",
                  66);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 67);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 67);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 67);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 67);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 67);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 67);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 67);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 67);
  sf_mex_assign(&c15_rhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs67), "rhs", "rhs",
                  67);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs67), "lhs", "lhs",
                  67);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[E]C:/Program Files/PreScan/PreScan_8.1.0/SimulationCore/MatlabCode/CompilationSheet/emlfcn_find_closest_trajectory_points.p"),
                  "context", "context", 68);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("mrdivide"), "name", "name",
                  68);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 68);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 68);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 68);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 68);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 68);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 68);
  sf_mex_assign(&c15_rhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs68), "rhs", "rhs",
                  68);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs68), "lhs", "lhs",
                  68);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 69);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 69);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 69);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 69);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 69);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 69);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 69);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 69);
  sf_mex_assign(&c15_rhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs69), "rhs", "rhs",
                  69);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs69), "lhs", "lhs",
                  69);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 70);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("rdivide"), "name", "name",
                  70);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 70);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 70);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 70);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 70);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 70);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 70);
  sf_mex_assign(&c15_rhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs70), "rhs", "rhs",
                  70);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs70), "lhs", "lhs",
                  70);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 71);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 71);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 71);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 71);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 71);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 71);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 71);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 71);
  sf_mex_assign(&c15_rhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs71), "rhs", "rhs",
                  71);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs71), "lhs", "lhs",
                  71);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 72);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 72);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 72);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 72);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 72);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 72);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 72);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 72);
  sf_mex_assign(&c15_rhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs72), "rhs", "rhs",
                  72);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs72), "lhs", "lhs",
                  72);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 73);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_div"), "name", "name",
                  73);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 73);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 73);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 73);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 73);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 73);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 73);
  sf_mex_assign(&c15_rhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs73), "rhs", "rhs",
                  73);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs73), "lhs", "lhs",
                  73);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 74);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 74);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 74);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 74);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 74);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 74);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 74);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 74);
  sf_mex_assign(&c15_rhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs74), "rhs", "rhs",
                  74);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs74), "lhs", "lhs",
                  74);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "context",
                  "context", 75);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("abs"), "name", "name", 75);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 75);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 75);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 75);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 75);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 75);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 75);
  sf_mex_assign(&c15_rhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs75), "rhs", "rhs",
                  75);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs75), "lhs", "lhs",
                  75);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[E]C:/Program Files/PreScan/PreScan_8.1.0/SimulationCore/MatlabCode/CompilationSheet/emlfcn_find_closest_trajectory_points.p"),
                  "context", "context", 76);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("sign"), "name", "name", 76);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 76);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "resolved",
                  "resolved", 76);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 76);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 76);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 76);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 76);
  sf_mex_assign(&c15_rhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs76), "rhs", "rhs",
                  76);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs76), "lhs", "lhs",
                  76);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 77);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 77);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 77);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 77);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 77);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 77);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 77);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 77);
  sf_mex_assign(&c15_rhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs77), "rhs", "rhs",
                  77);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs77), "lhs", "lhs",
                  77);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 78);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_scalar_sign"), "name",
                  "name", 78);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 78);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m"),
                  "resolved", "resolved", 78);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1356563094U), "fileTimeLo",
                  "fileTimeLo", 78);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 78);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 78);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 78);
  sf_mex_assign(&c15_rhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs78), "rhs", "rhs",
                  78);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs78), "lhs", "lhs",
                  78);
  sf_mex_destroy(&c15_rhs64);
  sf_mex_destroy(&c15_lhs64);
  sf_mex_destroy(&c15_rhs65);
  sf_mex_destroy(&c15_lhs65);
  sf_mex_destroy(&c15_rhs66);
  sf_mex_destroy(&c15_lhs66);
  sf_mex_destroy(&c15_rhs67);
  sf_mex_destroy(&c15_lhs67);
  sf_mex_destroy(&c15_rhs68);
  sf_mex_destroy(&c15_lhs68);
  sf_mex_destroy(&c15_rhs69);
  sf_mex_destroy(&c15_lhs69);
  sf_mex_destroy(&c15_rhs70);
  sf_mex_destroy(&c15_lhs70);
  sf_mex_destroy(&c15_rhs71);
  sf_mex_destroy(&c15_lhs71);
  sf_mex_destroy(&c15_rhs72);
  sf_mex_destroy(&c15_lhs72);
  sf_mex_destroy(&c15_rhs73);
  sf_mex_destroy(&c15_lhs73);
  sf_mex_destroy(&c15_rhs74);
  sf_mex_destroy(&c15_lhs74);
  sf_mex_destroy(&c15_rhs75);
  sf_mex_destroy(&c15_lhs75);
  sf_mex_destroy(&c15_rhs76);
  sf_mex_destroy(&c15_lhs76);
  sf_mex_destroy(&c15_rhs77);
  sf_mex_destroy(&c15_lhs77);
  sf_mex_destroy(&c15_rhs78);
  sf_mex_destroy(&c15_lhs78);
}

static void c15_localToGlobalCoordinates(SFc15_Experiment_csInstanceStruct
  *chartInstance, real_T c15_localX, real_T c15_localY, real_T c15_origin[3],
  real_T c15_sinOriginYaw, real_T c15_cosOriginYaw, real_T c15_offset, real_T
  c15_offsetSin, real_T c15_offsetCos, real_T *c15_globalX, real_T *c15_globalY)
{
  (void)chartInstance;
  *c15_globalX = ((c15_localX * c15_cosOriginYaw - c15_localY * c15_sinOriginYaw)
                  + c15_origin[0]) - c15_offset * c15_offsetSin;
  *c15_globalY = ((c15_localX * c15_sinOriginYaw + c15_localY * c15_cosOriginYaw)
                  + c15_origin[1]) + c15_offset * c15_offsetCos;
}

static real_T c15_norm(SFc15_Experiment_csInstanceStruct *chartInstance, real_T
  c15_x[2])
{
  real_T c15_y;
  real_T c15_scale;
  int32_T c15_k;
  real_T c15_absxk;
  real_T c15_t;
  (void)chartInstance;
  c15_y = 0.0;
  c15_scale = 2.2250738585072014E-308;
  for (c15_k = 0; c15_k < 2; c15_k++) {
    c15_absxk = muDoubleScalarAbs(c15_x[c15_k]);
    if (c15_absxk > c15_scale) {
      c15_t = c15_scale / c15_absxk;
      c15_y = 1.0 + c15_y * c15_t * c15_t;
      c15_scale = c15_absxk;
    } else {
      c15_t = c15_absxk / c15_scale;
      c15_y += c15_t * c15_t;
    }
  }

  return c15_scale * muDoubleScalarSqrt(c15_y);
}

static void c15_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_b_Actor_traj_angle, const char_T
  *c15_identifier, real_T c15_y[2])
{
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_Actor_traj_angle),
    &c15_thisId, c15_y);
  sf_mex_destroy(&c15_b_Actor_traj_angle);
}

static void c15_b_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[2])
{
  real_T c15_dv3[2];
  int32_T c15_i2;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv3, 1, 0, 0U, 1, 0U, 1, 2);
  for (c15_i2 = 0; c15_i2 < 2; c15_i2++) {
    c15_y[c15_i2] = c15_dv3[c15_i2];
  }

  sf_mex_destroy(&c15_u);
}

static void c15_c_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_b_pref, const char_T *c15_identifier,
  real_T c15_y[4])
{
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_pref), &c15_thisId,
    c15_y);
  sf_mex_destroy(&c15_b_pref);
}

static void c15_d_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[4])
{
  real_T c15_dv4[4];
  int32_T c15_i3;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv4, 1, 0, 0U, 1, 0U, 1, 4);
  for (c15_i3 = 0; c15_i3 < 4; c15_i3++) {
    c15_y[c15_i3] = c15_dv4[c15_i3];
  }

  sf_mex_destroy(&c15_u);
}

static void c15_e_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_b_Actor_traj_anglePersist, const char_T
  *c15_identifier, real_T c15_y[2])
{
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_Actor_traj_anglePersist),
    &c15_thisId, c15_y);
  sf_mex_destroy(&c15_b_Actor_traj_anglePersist);
}

static void c15_f_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[2])
{
  real_T c15_dv5[2];
  int32_T c15_i4;
  if (mxIsEmpty(c15_u)) {
    chartInstance->c15_Actor_traj_anglePersist_not_empty = false;
  } else {
    chartInstance->c15_Actor_traj_anglePersist_not_empty = true;
    sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv5, 1, 0, 0U, 1, 0U, 2,
                  1, 2);
    for (c15_i4 = 0; c15_i4 < 2; c15_i4++) {
      c15_y[c15_i4] = c15_dv5[c15_i4];
    }
  }

  sf_mex_destroy(&c15_u);
}

static void c15_g_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_b_Actor_traj_distancePersist, const char_T *
  c15_identifier, real_T c15_y[2])
{
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c15_b_Actor_traj_distancePersist), &c15_thisId, c15_y);
  sf_mex_destroy(&c15_b_Actor_traj_distancePersist);
}

static void c15_h_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[2])
{
  real_T c15_dv6[2];
  int32_T c15_i5;
  if (mxIsEmpty(c15_u)) {
    chartInstance->c15_Actor_traj_distancePersist_not_empty = false;
  } else {
    chartInstance->c15_Actor_traj_distancePersist_not_empty = true;
    sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv6, 1, 0, 0U, 1, 0U, 2,
                  1, 2);
    for (c15_i5 = 0; c15_i5 < 2; c15_i5++) {
      c15_y[c15_i5] = c15_dv6[c15_i5];
    }
  }

  sf_mex_destroy(&c15_u);
}

static void c15_i_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_b_ActualTrajectoryIndex, const char_T
  *c15_identifier, real_T c15_y[2])
{
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_ActualTrajectoryIndex),
    &c15_thisId, c15_y);
  sf_mex_destroy(&c15_b_ActualTrajectoryIndex);
}

static void c15_j_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[2])
{
  real_T c15_dv7[2];
  int32_T c15_i6;
  if (mxIsEmpty(c15_u)) {
    chartInstance->c15_ActualTrajectoryIndex_not_empty = false;
  } else {
    chartInstance->c15_ActualTrajectoryIndex_not_empty = true;
    sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv7, 1, 0, 0U, 1, 0U, 2,
                  1, 2);
    for (c15_i6 = 0; c15_i6 < 2; c15_i6++) {
      c15_y[c15_i6] = c15_dv7[c15_i6];
    }
  }

  sf_mex_destroy(&c15_u);
}

static real_T c15_k_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_b_Counter, const char_T *c15_identifier)
{
  real_T c15_y;
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_Counter),
    &c15_thisId);
  sf_mex_destroy(&c15_b_Counter);
  return c15_y;
}

static real_T c15_l_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  real_T c15_y;
  real_T c15_d0;
  if (mxIsEmpty(c15_u)) {
    chartInstance->c15_Counter_not_empty = false;
  } else {
    chartInstance->c15_Counter_not_empty = true;
    sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_d0, 1, 0, 0U, 0, 0U, 0);
    c15_y = c15_d0;
  }

  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_m_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_b_prefPersist, const char_T *c15_identifier,
  real_T c15_y[4])
{
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_prefPersist),
    &c15_thisId, c15_y);
  sf_mex_destroy(&c15_b_prefPersist);
}

static void c15_n_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[4])
{
  real_T c15_dv8[4];
  int32_T c15_i7;
  if (mxIsEmpty(c15_u)) {
    chartInstance->c15_prefPersist_not_empty = false;
  } else {
    chartInstance->c15_prefPersist_not_empty = true;
    sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv8, 1, 0, 0U, 1, 0U, 2,
                  2, 2);
    for (c15_i7 = 0; c15_i7 < 4; c15_i7++) {
      c15_y[c15_i7] = c15_dv8[c15_i7];
    }
  }

  sf_mex_destroy(&c15_u);
}

static uint8_T c15_o_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_b_is_active_c15_Experiment_cs, const char_T
  *c15_identifier)
{
  uint8_T c15_y;
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c15_b_is_active_c15_Experiment_cs), &c15_thisId);
  sf_mex_destroy(&c15_b_is_active_c15_Experiment_cs);
  return c15_y;
}

static uint8_T c15_p_emlrt_marshallIn(SFc15_Experiment_csInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  uint8_T c15_y;
  uint8_T c15_u0;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_u0, 1, 3, 0U, 0, 0U, 0);
  c15_y = c15_u0;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void init_dsm_address_info(SFc15_Experiment_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc15_Experiment_csInstanceStruct
  *chartInstance)
{
  chartInstance->c15_pref = (real_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c15_Actor_traj_distance = (real_T (*)[2])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c15_Actor_traj_angle = (real_T (*)[2])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 3);
  chartInstance->c15_pvp = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c15_TrajOffset_x_y_Y = (real_T (*)[3])
    ssGetInputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c15_ActorOffset_Left_Right = (real_T *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c15_p0 = (real_T (*)[3])ssGetInputPortSignal_wrapper
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

void sf_c15_Experiment_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(846672518U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3028403871U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(738118927U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1677967497U);
}

mxArray* sf_c15_Experiment_cs_get_post_codegen_info(void);
mxArray *sf_c15_Experiment_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("V79V0tXmwyx5kaASjvFhyF");
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
      pr[0] = (double)(411);
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
      pr[0] = (double)(411);
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
    mxArray* mxPostCodegenInfo = sf_c15_Experiment_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c15_Experiment_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c15_Experiment_cs_jit_fallback_info(void)
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

mxArray *sf_c15_Experiment_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c15_Experiment_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c15_Experiment_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x9'type','srcId','name','auxInfo'{{M[1],M[11],T\"Actor_traj_angle\",},{M[1],M[5],T\"Actor_traj_distance\",},{M[1],M[13],T\"pref\",},{M[4],M[0],T\"Actor_traj_anglePersist\",S'l','i','p'{{M1x2[-1 -2],M[1],T\"C:\\Program Files\\PreScan\\PreScan_8.1.0\\SimulationCore\\MatlabCode\\CompilationSheet\\emlfcn_find_closest_trajectory_points.p\"}}},{M[4],M[0],T\"Actor_traj_distancePersist\",S'l','i','p'{{M1x2[-1 -2],M[1],T\"C:\\Program Files\\PreScan\\PreScan_8.1.0\\SimulationCore\\MatlabCode\\CompilationSheet\\emlfcn_find_closest_trajectory_points.p\"}}},{M[4],M[0],T\"ActualTrajectoryIndex\",S'l','i','p'{{M1x2[-1 -2],M[1],T\"C:\\Program Files\\PreScan\\PreScan_8.1.0\\SimulationCore\\MatlabCode\\CompilationSheet\\emlfcn_find_closest_trajectory_points.p\"}}},{M[4],M[0],T\"Counter\",S'l','i','p'{{M1x2[-1 -2],M[1],T\"C:\\Program Files\\PreScan\\PreScan_8.1.0\\SimulationCore\\MatlabCode\\CompilationSheet\\emlfcn_find_closest_trajectory_points.p\"}}},{M[4],M[0],T\"prefPersist\",S'l','i','p'{{M1x2[-1 -2],M[1],T\"C:\\Program Files\\PreScan\\PreScan_8.1.0\\SimulationCore\\MatlabCode\\CompilationSheet\\emlfcn_find_closest_trajectory_points.p\"}}},{M[8],M[0],T\"is_active_c15_Experiment_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 9, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c15_Experiment_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "xcNPuVUmonGnsQjXE7iAW";
}

static void sf_opaque_initialize_c15_Experiment_cs(void *chartInstanceVar)
{
  initialize_params_c15_Experiment_cs((SFc15_Experiment_csInstanceStruct*)
    chartInstanceVar);
  initialize_c15_Experiment_cs((SFc15_Experiment_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c15_Experiment_cs(void *chartInstanceVar)
{
  enable_c15_Experiment_cs((SFc15_Experiment_csInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c15_Experiment_cs(void *chartInstanceVar)
{
  disable_c15_Experiment_cs((SFc15_Experiment_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c15_Experiment_cs(void *chartInstanceVar)
{
  sf_gateway_c15_Experiment_cs((SFc15_Experiment_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c15_Experiment_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c15_Experiment_cs((SFc15_Experiment_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c15_Experiment_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c15_Experiment_cs((SFc15_Experiment_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c15_Experiment_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc15_Experiment_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_cs_optimization_info();
    }

    finalize_c15_Experiment_cs((SFc15_Experiment_csInstanceStruct*)
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
  initSimStructsc15_Experiment_cs((SFc15_Experiment_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c15_Experiment_cs(SimStruct *S)
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
    initialize_params_c15_Experiment_cs((SFc15_Experiment_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c15_Experiment_cs(SimStruct *S)
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
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      15);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,15,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,15,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,15);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,15,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,15,3);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,15);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1402572488U));
  ssSetChecksum1(S,(824943471U));
  ssSetChecksum2(S,(2553448086U));
  ssSetChecksum3(S,(1936460614U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c15_Experiment_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c15_Experiment_cs(SimStruct *S)
{
  SFc15_Experiment_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc15_Experiment_csInstanceStruct *)utMalloc(sizeof
    (SFc15_Experiment_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc15_Experiment_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c15_Experiment_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c15_Experiment_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c15_Experiment_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c15_Experiment_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c15_Experiment_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c15_Experiment_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c15_Experiment_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c15_Experiment_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c15_Experiment_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c15_Experiment_cs;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c15_Experiment_cs;
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

void c15_Experiment_cs_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c15_Experiment_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c15_Experiment_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c15_Experiment_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c15_Experiment_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
