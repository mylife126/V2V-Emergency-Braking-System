/* Include files */

#include <stddef.h>
#include "blas.h"
#include "NewModuleTry_cs_sfun.h"
#include "c15_NewModuleTry_cs.h"
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(NULL,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c15_NewModuleTry_cs(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance);
static void initialize_params_c15_NewModuleTry_cs
  (SFc15_NewModuleTry_csInstanceStruct *chartInstance);
static void enable_c15_NewModuleTry_cs(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance);
static void disable_c15_NewModuleTry_cs(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c15_NewModuleTry_cs
  (SFc15_NewModuleTry_csInstanceStruct *chartInstance);
static void set_sim_state_c15_NewModuleTry_cs
  (SFc15_NewModuleTry_csInstanceStruct *chartInstance, const mxArray *c15_st);
static void finalize_c15_NewModuleTry_cs(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance);
static void sf_gateway_c15_NewModuleTry_cs(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance);
static void mdl_start_c15_NewModuleTry_cs(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance);
static void c15_chartstep_c15_NewModuleTry_cs
  (SFc15_NewModuleTry_csInstanceStruct *chartInstance);
static void initSimStructsc15_NewModuleTry_cs
  (SFc15_NewModuleTry_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber, uint32_T c15_instanceNumber);
static void c15_info_helper(const mxArray **c15_info);
static const mxArray *c15_emlrt_marshallOut(const char * c15_u);
static const mxArray *c15_b_emlrt_marshallOut(const uint32_T c15_u);
static void c15_b_info_helper(const mxArray **c15_info);
static void c15_localToGlobalCoordinates(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance, real_T c15_localX, real_T c15_localY, real_T c15_origin[3],
  real_T c15_sinOriginYaw, real_T c15_cosOriginYaw, real_T c15_offset, real_T
  c15_offsetSin, real_T c15_offsetCos, real_T *c15_globalX, real_T *c15_globalY);
static real_T c15_norm(SFc15_NewModuleTry_csInstanceStruct *chartInstance,
  real_T c15_x[2]);
static void c15_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c15_b_Actor_traj_angle, const char_T
  *c15_identifier, real_T c15_y[2]);
static void c15_b_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[2]);
static void c15_c_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c15_b_pref, const char_T *c15_identifier,
  real_T c15_y[4]);
static void c15_d_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[4]);
static void c15_e_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c15_b_Actor_traj_anglePersist, const char_T
  *c15_identifier, real_T c15_y[2]);
static void c15_f_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[2]);
static void c15_g_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c15_b_Actor_traj_distancePersist, const char_T *
  c15_identifier, real_T c15_y[2]);
static void c15_h_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[2]);
static void c15_i_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c15_b_ActualTrajectoryIndex, const char_T
  *c15_identifier, real_T c15_y[2]);
static void c15_j_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[2]);
static real_T c15_k_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c15_b_Counter, const char_T *c15_identifier);
static real_T c15_l_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_m_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c15_b_prefPersist, const char_T *c15_identifier,
  real_T c15_y[4]);
static void c15_n_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[4]);
static uint8_T c15_o_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c15_b_is_active_c15_NewModuleTry_cs, const
  char_T *c15_identifier);
static uint8_T c15_p_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void init_dsm_address_info(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c15_NewModuleTry_cs(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c15_Counter_not_empty = false;
  chartInstance->c15_Actor_traj_distancePersist_not_empty = false;
  chartInstance->c15_Actor_traj_anglePersist_not_empty = false;
  chartInstance->c15_ActualTrajectoryIndex_not_empty = false;
  chartInstance->c15_prefPersist_not_empty = false;
  chartInstance->c15_is_active_c15_NewModuleTry_cs = 0U;
}

static void initialize_params_c15_NewModuleTry_cs
  (SFc15_NewModuleTry_csInstanceStruct *chartInstance)
{
  real_T c15_dv0[531];
  int32_T c15_i0;
  real_T c15_dv1[531];
  sf_mex_import_named("Traj_x", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c15_dv0, 0, 0, 0U, 1, 0U, 1, 531);
  for (c15_i0 = 0; c15_i0 < 531; c15_i0++) {
    chartInstance->c15_Traj_x[c15_i0] = c15_dv0[c15_i0];
  }

  sf_mex_import_named("Traj_y", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      c15_dv1, 0, 0, 0U, 1, 0U, 1, 531);
  for (c15_i0 = 0; c15_i0 < 531; c15_i0++) {
    chartInstance->c15_Traj_y[c15_i0] = c15_dv1[c15_i0];
  }
}

static void enable_c15_NewModuleTry_cs(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c15_NewModuleTry_cs(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static const mxArray *get_sim_state_c15_NewModuleTry_cs
  (SFc15_NewModuleTry_csInstanceStruct *chartInstance)
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
  c15_i_u = chartInstance->c15_is_active_c15_NewModuleTry_cs;
  c15_j_y = NULL;
  sf_mex_assign(&c15_j_y, sf_mex_create("y", &c15_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c15_y, 8, c15_j_y);
  sf_mex_assign(&c15_st, c15_y, false);
  return c15_st;
}

static void set_sim_state_c15_NewModuleTry_cs
  (SFc15_NewModuleTry_csInstanceStruct *chartInstance, const mxArray *c15_st)
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
  chartInstance->c15_is_active_c15_NewModuleTry_cs = c15_o_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 8)),
     "is_active_c15_NewModuleTry_cs");
  sf_mex_destroy(&c15_u);
  sf_mex_destroy(&c15_st);
}

static void finalize_c15_NewModuleTry_cs(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c15_NewModuleTry_cs(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  c15_chartstep_c15_NewModuleTry_cs(chartInstance);
}

static void mdl_start_c15_NewModuleTry_cs(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c15_chartstep_c15_NewModuleTry_cs
  (SFc15_NewModuleTry_csInstanceStruct *chartInstance)
{
  int32_T c15_k;
  real_T c15_b_pvp[4];
  real_T c15_b_ActorOffset_Left_Right;
  real_T c15_b_TrajOffset_x_y_Y[3];
  real_T c15_b_p0[3];
  real_T c15_Traj_xGlobal[1062];
  real_T c15_Traj_yGlobal[1062];
  real_T c15_ii[2];
  real_T c15_cosTrajOffset3;
  real_T c15_sinTrajOffset3;
  int32_T c15_j;
  static real_T c15_c_Traj_x[531] = { 0.0, 0.18999999999999773,
    0.37999999999999545, 0.56999999999999318, 0.76000000000000512,
    0.95000000000000284, 1.1400000000000006, 1.3299999999999983,
    1.519999999999996, 1.7099999999999937, 1.9000000000000057,
    2.0900000000000034, 2.2800000000000011, 2.4699999999999989,
    2.6599999999999966, 2.8499999999999943, 3.0400000000000063,
    3.230000000000004, 3.4200000000000017, 3.6099999999999994,
    3.7999999999999972, 3.9899999999999949, 4.1800000000000068,
    4.3700000000000045, 4.5600000000000023, 4.75, 4.9399999999999977,
    5.1299999999999955, 5.3199999999999932, 5.5100000000000051,
    5.7000000000000028, 5.8900000000000006, 6.0799999999999983,
    6.269999999999996, 6.4599999999999937, 6.6500000000000057,
    6.8400000000000034, 7.0300000000000011, 7.2199999999999989,
    7.4099999999999966, 7.5999999999999943, 7.7900000000000063,
    7.980000000000004, 8.1700000000000017, 8.36, 8.5499999999999972,
    8.7399999999999949, 8.9300000000000068, 9.1200000000000045,
    9.3100000000000023, 9.5, 9.6899999999999977, 9.8799999999999955,
    10.069999999999993, 10.260000000000005, 10.450000000000003, 10.64,
    10.829999999999998, 11.019999999999996, 11.210000000000008,
    11.400000000000006, 11.590000000000003, 11.780000000000001,
    11.969999999999999, 12.159999999999997, 12.349999999999994,
    12.539999999999992, 12.730000000000004, 12.920000000000002, 13.11,
    13.299999999999997, 13.489999999999995, 13.680000000000007,
    13.870000000000005, 14.060000000000002, 14.25, 14.439999999999998,
    14.629999999999995, 14.819999999999993, 15.010000000000005,
    15.200000000000003, 15.39, 15.579999999999998, 15.769999999999996,
    15.960000000000008, 16.150000000000006, 16.340000000000003, 16.53, 16.72,
    16.909999999999997, 17.099999999999994, 17.289999999999992,
    17.480000000000004, 17.67, 17.86, 18.049999999999997, 18.239999999999995,
    18.430000000000007, 18.620000000000005, 18.810000000000002, 19.0,
    19.189999999999998, 19.379999999999995, 19.569999999999993,
    19.760000000000005, 19.950000000000003, 20.14, 20.33, 20.519999999999996,
    20.710000000000008, 20.900000000000006, 21.090000000000003, 21.28, 21.47,
    21.659999999999997, 21.849999999999994, 22.039999999999992,
    22.230000000000004, 22.42, 22.61, 22.799999999999997, 22.989999999999995,
    23.180000000000007, 23.370000000000005, 23.560000000000002, 23.75,
    23.939999999999998, 24.129999999999995, 24.319999999999993,
    24.510000000000005, 24.700000000000003, 24.89, 25.08, 25.269999999999996,
    25.460000000000008, 25.650000000000006, 25.840000000000003, 26.03, 26.22,
    26.409999999999997, 26.599999999999994, 26.789999999999992,
    26.980000000000004, 27.17, 27.36, 27.549999999999997, 27.739999999999995,
    27.930000000000007, 28.120000000000005, 28.310000000000002, 28.5,
    28.689999999999998, 28.879999999999995, 29.069999999999993,
    29.260000000000005, 29.450000000000003, 29.64, 29.83, 30.019999999999996,
    30.210000000000008, 30.400000000000006, 30.590000000000003, 30.78, 30.97,
    31.159999999999997, 31.349999999999994, 31.539999999999992,
    31.730000000000004, 31.92, 32.11, 32.3, 32.490000000000009,
    32.680000000000007, 32.870000000000005, 33.06, 33.25, 33.44,
    33.629999999999995, 33.819999999999993, 34.009999999999991, 34.2, 34.39,
    34.58, 34.77000000000001, 34.960000000000008, 35.150000000000006, 35.34,
    35.53, 35.72, 35.91, 36.099999999999994, 36.289999999999992,
    36.47999999999999, 36.67, 36.86, 37.05, 37.240000000000009,
    37.430000000000007, 37.620000000000005, 37.81, 38.0, 38.19,
    38.379999999999995, 38.569999999999993, 38.759999999999991, 38.95, 39.14,
    39.33, 39.52000000000001, 39.710000000000008, 39.900000000000006, 40.09,
    40.28, 40.47, 40.66, 40.849999999999994, 41.039999999999992,
    41.22999999999999, 41.42, 41.61, 41.8, 41.990000000000009,
    42.180000000000007, 42.370000000000005, 42.56, 42.75, 42.94,
    43.129999999999995, 43.319999999999993, 43.509999999999991, 43.7, 43.89,
    44.08, 44.27000000000001, 44.460000000000008, 44.650000000000006, 44.84,
    45.03, 45.22, 45.41, 45.599999999999994, 45.789999999999992,
    45.97999999999999, 46.17, 46.36, 46.55, 46.740000000000009,
    46.930000000000007, 47.120000000000005, 47.31, 47.5, 47.69,
    47.879999999999995, 48.069999999999993, 48.259999999999991, 48.45, 48.64,
    48.83, 49.02000000000001, 49.210000000000008, 49.400000000000006, 49.59,
    49.78, 49.97, 50.16, 50.349999999999994, 50.539999999999992,
    50.72999999999999, 50.92, 51.11, 51.3, 51.490000000000009,
    51.680000000000007, 51.86999999999999, 52.059999999999988,
    52.249999999999986, 52.439999999999984, 52.629999999999981,
    52.819999999999979, 53.009999999999977, 53.199999999999974,
    53.389999999999972, 53.57999999999997, 53.769999999999996,
    53.959999999999994, 54.149999999999991, 54.339999999999989,
    54.529999999999987, 54.719999999999985, 54.909999999999982,
    55.09999999999998, 55.289999999999978, 55.479999999999976, 55.67, 55.86,
    56.05, 56.239999999999995, 56.429999999999993, 56.61999999999999,
    56.809999999999988, 56.999999999999986, 57.189999999999984,
    57.379999999999981, 57.569999999999979, 57.759999999999977,
    57.949999999999974, 58.139999999999972, 58.32999999999997,
    58.519999999999996, 58.709999999999994, 58.899999999999991,
    59.089999999999989, 59.279999999999987, 59.469999999999985,
    59.659999999999982, 59.84999999999998, 60.039999999999978,
    60.229999999999976, 60.42, 60.61, 60.8, 60.989999999999995,
    61.179999999999993, 61.36999999999999, 61.559999999999988,
    61.749999999999986, 61.939999999999984, 62.129999999999981,
    62.319999999999979, 62.509999999999977, 62.699999999999974,
    62.889999999999972, 63.07999999999997, 63.269999999999996,
    63.459999999999994, 63.649999999999991, 63.839999999999989,
    64.029999999999987, 64.219999999999985, 64.409999999999982,
    64.59999999999998, 64.79, 64.98, 65.17, 65.36, 65.55, 65.74,
    65.929999999999993, 66.11999999999999, 66.309999999999988,
    66.499999999999986, 66.689999999999984, 66.879999999999981,
    67.069999999999979, 67.259999999999977, 67.449999999999974,
    67.639999999999972, 67.82999999999997, 68.019999999999968,
    68.209999999999965, 68.399999999999991, 68.589999999999989,
    68.779999999999987, 68.969999999999985, 69.159999999999982,
    69.34999999999998, 69.54, 69.73, 69.92, 70.11, 70.3, 70.49,
    70.679999999999993, 70.86999999999999, 71.059999999999988,
    71.249999999999986, 71.439999999999984, 71.629999999999981,
    71.819999999999979, 72.009999999999977, 72.199999999999974,
    72.389999999999972, 72.57999999999997, 72.769999999999968,
    72.959999999999965, 73.149999999999991, 73.339999999999989,
    73.529999999999987, 73.719999999999985, 73.909999999999982,
    74.09999999999998, 74.29, 74.48, 74.67, 74.86, 75.05, 75.24,
    75.429999999999993, 75.61999999999999, 75.809999999999988,
    75.999999999999986, 76.189999999999984, 76.379999999999981,
    76.569999999999979, 76.759999999999977, 76.949999999999974,
    77.139999999999972, 77.32999999999997, 77.519999999999968,
    77.709999999999965, 77.899999999999991, 78.089999999999989,
    78.279999999999987, 78.469999999999985, 78.659999999999982,
    78.84999999999998, 79.04, 79.23, 79.42, 79.61, 79.8, 79.99,
    80.179999999999993, 80.36999999999999, 80.559999999999988,
    80.749999999999986, 80.939999999999984, 81.129999999999981,
    81.319999999999979, 81.509999999999977, 81.699999999999974,
    81.889999999999972, 82.07999999999997, 82.269999999999968,
    82.459999999999965, 82.649999999999991, 82.839999999999989,
    83.029999999999987, 83.219999999999985, 83.409999999999982,
    83.59999999999998, 83.79, 83.98, 84.17, 84.36, 84.55, 84.74,
    84.929999999999993, 85.11999999999999, 85.309999999999988,
    85.499999999999986, 85.689999999999984, 85.879999999999981,
    86.069999999999979, 86.259999999999977, 86.449999999999974,
    86.639999999999972, 86.82999999999997, 87.019999999999968,
    87.209999999999965, 87.399999999999991, 87.589999999999989,
    87.779999999999987, 87.969999999999985, 88.159999999999982,
    88.34999999999998, 88.54, 88.73, 88.92, 89.11, 89.3, 89.49,
    89.679999999999993, 89.86999999999999, 90.059999999999988,
    90.249999999999986, 90.439999999999984, 90.629999999999981,
    90.819999999999979, 91.009999999999977, 91.199999999999974,
    91.389999999999972, 91.57999999999997, 91.769999999999968,
    91.959999999999965, 92.149999999999991, 92.339999999999989,
    92.529999999999987, 92.719999999999985, 92.909999999999982,
    93.09999999999998, 93.29, 93.48, 93.67, 93.86, 94.05, 94.24,
    94.429999999999993, 94.61999999999999, 94.809999999999988,
    94.999999999999986, 95.189999999999984, 95.379999999999981,
    95.569999999999979, 95.759999999999977, 95.949999999999974,
    96.139999999999972, 96.32999999999997, 96.519999999999968,
    96.709999999999965, 96.899999999999991, 97.089999999999989,
    97.279999999999987, 97.469999999999985, 97.659999999999982,
    97.84999999999998, 98.04, 98.23, 98.42, 98.61, 98.8, 98.99,
    99.179999999999993, 99.36999999999999, 99.559999999999988,
    99.749999999999986, 99.939999999999984, 100.12999999999998,
    100.31999999999998, 100.50999999999998, 100.69999999999997 };

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

  for (c15_k = 0; c15_k < 1062; c15_k++) {
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
      sf_mex_lw_bounds_check((int32_T)c15_ii[c15_j], 1, 531);
      sf_mex_lw_bounds_check((int32_T)c15_ii[c15_j], 1, 531);
      sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] + 1.0), 1, 531);
      sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] + 1.0), 1, 531);
      c15_beta = muDoubleScalarAtan2(((c15_c_Traj_x[(int32_T)(c15_ii[c15_j] +
        1.0) - 1] * c15_sinTrajOffset3 + 0.0 * c15_cosTrajOffset3) +
        c15_b_TrajOffset_x_y_Y[1]) - ((c15_c_Traj_x[(int32_T)c15_ii[c15_j] - 1] *
        c15_sinTrajOffset3 + 0.0 * c15_cosTrajOffset3) + c15_b_TrajOffset_x_y_Y
        [1]), ((c15_c_Traj_x[(int32_T)(c15_ii[c15_j] + 1.0) - 1] *
                c15_cosTrajOffset3 - 0.0 * c15_sinTrajOffset3) +
               c15_b_TrajOffset_x_y_Y[0]) - ((c15_c_Traj_x[(int32_T)c15_ii[c15_j]
        - 1] * c15_cosTrajOffset3 - 0.0 * c15_sinTrajOffset3) +
        c15_b_TrajOffset_x_y_Y[0]));
      c15_sinBeta = muDoubleScalarSin(c15_beta);
      c15_cosBeta = muDoubleScalarCos(c15_beta);
      sf_mex_lw_bounds_check((int32_T)c15_ii[c15_j], 1, 531);
      c15_localToGlobalCoordinates(chartInstance,
        c15_c_Traj_x[sf_mex_lw_bounds_check((int32_T)c15_ii[c15_j], 1, 531) - 1],
        0.0, c15_b_TrajOffset_x_y_Y, c15_sinTrajOffset3, c15_cosTrajOffset3,
        c15_b_ActorOffset_Left_Right, c15_sinBeta, c15_cosBeta, &c15_beta,
        &c15_dist_p3);
      c15_Traj_xGlobal[(sf_mex_lw_bounds_check((int32_T)c15_ii[c15_j], 1, 531) +
                        531 * c15_j) - 1] = c15_beta;
      c15_Traj_yGlobal[(sf_mex_lw_bounds_check((int32_T)c15_ii[c15_j], 1, 531) +
                        531 * c15_j) - 1] = c15_dist_p3;
      sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] + 1.0), 1, 531);
      c15_localToGlobalCoordinates(chartInstance,
        c15_c_Traj_x[sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] + 1.0), 1,
        531) - 1], 0.0, c15_b_TrajOffset_x_y_Y, c15_sinTrajOffset3,
        c15_cosTrajOffset3, c15_b_ActorOffset_Left_Right, c15_sinBeta,
        c15_cosBeta, &c15_beta, &c15_dist_p3);
      c15_Traj_xGlobal[(sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] + 1.0), 1,
        531) + 531 * c15_j) - 1] = c15_beta;
      c15_Traj_yGlobal[(sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] + 1.0), 1,
        531) + 531 * c15_j) - 1] = c15_dist_p3;
      c15_b_Traj_xGlobal[0] = c15_Traj_xGlobal[(sf_mex_lw_bounds_check((int32_T)
        c15_ii[c15_j], 1, 531) + 531 * c15_j) - 1];
      c15_b_Traj_xGlobal[1] = c15_Traj_yGlobal[(sf_mex_lw_bounds_check((int32_T)
        c15_ii[c15_j], 1, 531) + 531 * c15_j) - 1];
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
        sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] - 1.0), 1, 531);
        c15_localToGlobalCoordinates(chartInstance,
          c15_c_Traj_x[sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] - 1.0), 1,
          531) - 1], 0.0, c15_b_TrajOffset_x_y_Y, c15_sinTrajOffset3,
          c15_cosTrajOffset3, c15_b_ActorOffset_Left_Right, c15_sinBeta,
          c15_cosBeta, &c15_beta, &c15_dist_p3);
        c15_Traj_xGlobal[(sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] - 1.0),
          1, 531) + 531 * c15_j) - 1] = c15_beta;
        c15_Traj_yGlobal[(sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] - 1.0),
          1, 531) + 531 * c15_j) - 1] = c15_dist_p3;
        c15_c_Traj_xGlobal[0] = c15_Traj_xGlobal[(sf_mex_lw_bounds_check
          ((int32_T)(c15_ii[c15_j] - 1.0), 1, 531) + 531 * c15_j) - 1];
        c15_c_Traj_xGlobal[1] = c15_Traj_yGlobal[(sf_mex_lw_bounds_check
          ((int32_T)(c15_ii[c15_j] - 1.0), 1, 531) + 531 * c15_j) - 1];
        for (c15_k = 0; c15_k < 2; c15_k++) {
          c15_p1[c15_k] = c15_c_Traj_xGlobal[c15_k];
        }

        sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] + 1.0), 1, 531);
        sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] + 1.0), 1, 531);
        c15_c_pvp[0] = c15_b_pvp[c15_j << 1];
        c15_c_pvp[1] = c15_b_pvp[1 + (c15_j << 1)];
        for (c15_k = 0; c15_k < 2; c15_k++) {
          c15_b_p1[c15_k] = c15_p1[c15_k] - c15_c_pvp[c15_k];
        }

        c15_beta = c15_norm(chartInstance, c15_b_p1);
        c15_d_Traj_xGlobal[0] = c15_Traj_xGlobal[((int32_T)(c15_ii[c15_j] + 1.0)
          + 531 * c15_j) - 1];
        c15_d_Traj_xGlobal[1] = c15_Traj_yGlobal[((int32_T)(c15_ii[c15_j] + 1.0)
          + 531 * c15_j) - 1];
        c15_d_pvp[0] = c15_b_pvp[c15_j << 1];
        c15_d_pvp[1] = c15_b_pvp[1 + (c15_j << 1)];
        for (c15_k = 0; c15_k < 2; c15_k++) {
          c15_b_p1[c15_k] = c15_d_Traj_xGlobal[c15_k] - c15_d_pvp[c15_k];
        }

        c15_dist_p3 = c15_norm(chartInstance, c15_b_p1);
        while ((c15_beta >= c15_dist_p3) && (c15_ii[c15_j] < 530.0)) {
          c15_ii[c15_j]++;
          sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] + 1.0), 1, 531);
          c15_localToGlobalCoordinates(chartInstance,
            c15_c_Traj_x[sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] + 1.0),
            1, 531) - 1], 0.0, c15_b_TrajOffset_x_y_Y, c15_sinTrajOffset3,
            c15_cosTrajOffset3, c15_b_ActorOffset_Left_Right, c15_sinBeta,
            c15_cosBeta, &c15_beta, &c15_dist_p3);
          c15_Traj_xGlobal[(sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] + 1.0),
            1, 531) + 531 * c15_j) - 1] = c15_beta;
          c15_Traj_yGlobal[(sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] + 1.0),
            1, 531) + 531 * c15_j) - 1] = c15_dist_p3;
          c15_e_Traj_xGlobal[0] = c15_Traj_xGlobal[(sf_mex_lw_bounds_check
            ((int32_T)(c15_ii[c15_j] - 1.0), 1, 531) + 531 * c15_j) - 1];
          c15_e_Traj_xGlobal[1] = c15_Traj_yGlobal[(sf_mex_lw_bounds_check
            ((int32_T)(c15_ii[c15_j] - 1.0), 1, 531) + 531 * c15_j) - 1];
          for (c15_k = 0; c15_k < 2; c15_k++) {
            c15_p1[c15_k] = c15_e_Traj_xGlobal[c15_k];
          }

          c15_f_Traj_xGlobal[0] = c15_Traj_xGlobal[(sf_mex_lw_bounds_check
            ((int32_T)c15_ii[c15_j], 1, 531) + 531 * c15_j) - 1];
          c15_f_Traj_xGlobal[1] = c15_Traj_yGlobal[(sf_mex_lw_bounds_check
            ((int32_T)c15_ii[c15_j], 1, 531) + 531 * c15_j) - 1];
          for (c15_k = 0; c15_k < 2; c15_k++) {
            c15_p2[c15_k] = c15_f_Traj_xGlobal[c15_k];
          }

          sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] + 1.0), 1, 531);
          sf_mex_lw_bounds_check((int32_T)(c15_ii[c15_j] + 1.0), 1, 531);
          c15_e_pvp[0] = c15_b_pvp[c15_j << 1];
          c15_e_pvp[1] = c15_b_pvp[1 + (c15_j << 1)];
          for (c15_k = 0; c15_k < 2; c15_k++) {
            c15_b_p1[c15_k] = c15_p1[c15_k] - c15_e_pvp[c15_k];
          }

          c15_beta = c15_norm(chartInstance, c15_b_p1);
          c15_g_Traj_xGlobal[0] = c15_Traj_xGlobal[((int32_T)(c15_ii[c15_j] +
            1.0) + 531 * c15_j) - 1];
          c15_g_Traj_xGlobal[1] = c15_Traj_yGlobal[((int32_T)(c15_ii[c15_j] +
            1.0) + 531 * c15_j) - 1];
          c15_f_pvp[0] = c15_b_pvp[c15_j << 1];
          c15_f_pvp[1] = c15_b_pvp[1 + (c15_j << 1)];
          for (c15_k = 0; c15_k < 2; c15_k++) {
            c15_b_p1[c15_k] = c15_g_Traj_xGlobal[c15_k] - c15_f_pvp[c15_k];
          }

          c15_dist_p3 = c15_norm(chartInstance, c15_b_p1);
          _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
        }

        chartInstance->c15_ActualTrajectoryIndex[c15_j] = c15_ii[c15_j];
        if (c15_ii[c15_j] >= 530.0) {
          c15_h_Traj_xGlobal[0] = c15_Traj_xGlobal[530 + 531 * c15_j];
          c15_h_Traj_xGlobal[1] = c15_Traj_yGlobal[530 + 531 * c15_j];
          c15_beta = muDoubleScalarAtan2(c15_Traj_yGlobal[530 + 531 * c15_j] -
            c15_Traj_yGlobal[529 + 531 * c15_j], c15_Traj_xGlobal[530 + 531 *
            c15_j] - c15_Traj_xGlobal[529 + 531 * c15_j]);
          c15_i_Traj_xGlobal[0] = c15_Traj_xGlobal[530 + 531 * c15_j] +
            muDoubleScalarCos(c15_beta);
          c15_i_Traj_xGlobal[1] = c15_Traj_yGlobal[530 + 531 * c15_j] +
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
        if ((c15_beta < 0.0) && (c15_ii[c15_j] < 530.0)) {
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

static void initSimStructsc15_NewModuleTry_cs
  (SFc15_NewModuleTry_csInstanceStruct *chartInstance)
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

const mxArray *sf_c15_NewModuleTry_cs_get_eml_resolved_functions_info(void)
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

static void c15_localToGlobalCoordinates(SFc15_NewModuleTry_csInstanceStruct
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

static real_T c15_norm(SFc15_NewModuleTry_csInstanceStruct *chartInstance,
  real_T c15_x[2])
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

static void c15_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
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

static void c15_b_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
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

static void c15_c_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
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

static void c15_d_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
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

static void c15_e_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
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

static void c15_f_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
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

static void c15_g_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
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

static void c15_h_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
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

static void c15_i_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
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

static void c15_j_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
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

static real_T c15_k_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
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

static real_T c15_l_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
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

static void c15_m_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
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

static void c15_n_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
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

static uint8_T c15_o_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance, const mxArray *c15_b_is_active_c15_NewModuleTry_cs, const
  char_T *c15_identifier)
{
  uint8_T c15_y;
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c15_b_is_active_c15_NewModuleTry_cs), &c15_thisId);
  sf_mex_destroy(&c15_b_is_active_c15_NewModuleTry_cs);
  return c15_y;
}

static uint8_T c15_p_emlrt_marshallIn(SFc15_NewModuleTry_csInstanceStruct
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

static void init_dsm_address_info(SFc15_NewModuleTry_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc15_NewModuleTry_csInstanceStruct
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

void sf_c15_NewModuleTry_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2808633994U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1287148134U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2365724263U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(628863608U);
}

mxArray* sf_c15_NewModuleTry_cs_get_post_codegen_info(void);
mxArray *sf_c15_NewModuleTry_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("m2d54Q2RWqVdmcWnoAjdWG");
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
      pr[0] = (double)(531);
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
      pr[0] = (double)(531);
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
    mxArray* mxPostCodegenInfo = sf_c15_NewModuleTry_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c15_NewModuleTry_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c15_NewModuleTry_cs_jit_fallback_info(void)
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

mxArray *sf_c15_NewModuleTry_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c15_NewModuleTry_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c15_NewModuleTry_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x9'type','srcId','name','auxInfo'{{M[1],M[11],T\"Actor_traj_angle\",},{M[1],M[5],T\"Actor_traj_distance\",},{M[1],M[13],T\"pref\",},{M[4],M[0],T\"Actor_traj_anglePersist\",S'l','i','p'{{M1x2[-1 -2],M[1],T\"C:\\Program Files\\PreScan\\PreScan_8.1.0\\SimulationCore\\MatlabCode\\CompilationSheet\\emlfcn_find_closest_trajectory_points.p\"}}},{M[4],M[0],T\"Actor_traj_distancePersist\",S'l','i','p'{{M1x2[-1 -2],M[1],T\"C:\\Program Files\\PreScan\\PreScan_8.1.0\\SimulationCore\\MatlabCode\\CompilationSheet\\emlfcn_find_closest_trajectory_points.p\"}}},{M[4],M[0],T\"ActualTrajectoryIndex\",S'l','i','p'{{M1x2[-1 -2],M[1],T\"C:\\Program Files\\PreScan\\PreScan_8.1.0\\SimulationCore\\MatlabCode\\CompilationSheet\\emlfcn_find_closest_trajectory_points.p\"}}},{M[4],M[0],T\"Counter\",S'l','i','p'{{M1x2[-1 -2],M[1],T\"C:\\Program Files\\PreScan\\PreScan_8.1.0\\SimulationCore\\MatlabCode\\CompilationSheet\\emlfcn_find_closest_trajectory_points.p\"}}},{M[4],M[0],T\"prefPersist\",S'l','i','p'{{M1x2[-1 -2],M[1],T\"C:\\Program Files\\PreScan\\PreScan_8.1.0\\SimulationCore\\MatlabCode\\CompilationSheet\\emlfcn_find_closest_trajectory_points.p\"}}},{M[8],M[0],T\"is_active_c15_NewModuleTry_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 9, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c15_NewModuleTry_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "PRrxACDhgRuI75UOt8NbeC";
}

static void sf_opaque_initialize_c15_NewModuleTry_cs(void *chartInstanceVar)
{
  initialize_params_c15_NewModuleTry_cs((SFc15_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
  initialize_c15_NewModuleTry_cs((SFc15_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c15_NewModuleTry_cs(void *chartInstanceVar)
{
  enable_c15_NewModuleTry_cs((SFc15_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c15_NewModuleTry_cs(void *chartInstanceVar)
{
  disable_c15_NewModuleTry_cs((SFc15_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c15_NewModuleTry_cs(void *chartInstanceVar)
{
  sf_gateway_c15_NewModuleTry_cs((SFc15_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c15_NewModuleTry_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c15_NewModuleTry_cs((SFc15_NewModuleTry_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c15_NewModuleTry_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c15_NewModuleTry_cs((SFc15_NewModuleTry_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c15_NewModuleTry_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc15_NewModuleTry_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_NewModuleTry_cs_optimization_info();
    }

    finalize_c15_NewModuleTry_cs((SFc15_NewModuleTry_csInstanceStruct*)
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
  initSimStructsc15_NewModuleTry_cs((SFc15_NewModuleTry_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c15_NewModuleTry_cs(SimStruct *S)
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
    initialize_params_c15_NewModuleTry_cs((SFc15_NewModuleTry_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c15_NewModuleTry_cs(SimStruct *S)
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
    mxArray *infoStruct = load_NewModuleTry_cs_optimization_info();
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
  ssSetChecksum0(S,(1906108776U));
  ssSetChecksum1(S,(59693255U));
  ssSetChecksum2(S,(2395614219U));
  ssSetChecksum3(S,(907201754U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c15_NewModuleTry_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c15_NewModuleTry_cs(SimStruct *S)
{
  SFc15_NewModuleTry_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc15_NewModuleTry_csInstanceStruct *)utMalloc(sizeof
    (SFc15_NewModuleTry_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc15_NewModuleTry_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c15_NewModuleTry_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c15_NewModuleTry_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c15_NewModuleTry_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c15_NewModuleTry_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c15_NewModuleTry_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c15_NewModuleTry_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c15_NewModuleTry_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c15_NewModuleTry_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c15_NewModuleTry_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c15_NewModuleTry_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c15_NewModuleTry_cs;
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

void c15_NewModuleTry_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c15_NewModuleTry_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c15_NewModuleTry_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c15_NewModuleTry_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c15_NewModuleTry_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
