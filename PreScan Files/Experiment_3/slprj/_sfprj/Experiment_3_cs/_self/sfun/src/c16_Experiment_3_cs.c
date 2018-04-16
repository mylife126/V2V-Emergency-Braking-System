/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Experiment_3_cs_sfun.h"
#include "c16_Experiment_3_cs.h"
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(NULL,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c16_Experiment_3_cs(SFc16_Experiment_3_csInstanceStruct
  *chartInstance);
static void initialize_params_c16_Experiment_3_cs
  (SFc16_Experiment_3_csInstanceStruct *chartInstance);
static void enable_c16_Experiment_3_cs(SFc16_Experiment_3_csInstanceStruct
  *chartInstance);
static void disable_c16_Experiment_3_cs(SFc16_Experiment_3_csInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c16_Experiment_3_cs
  (SFc16_Experiment_3_csInstanceStruct *chartInstance);
static void set_sim_state_c16_Experiment_3_cs
  (SFc16_Experiment_3_csInstanceStruct *chartInstance, const mxArray *c16_st);
static void finalize_c16_Experiment_3_cs(SFc16_Experiment_3_csInstanceStruct
  *chartInstance);
static void sf_gateway_c16_Experiment_3_cs(SFc16_Experiment_3_csInstanceStruct
  *chartInstance);
static void mdl_start_c16_Experiment_3_cs(SFc16_Experiment_3_csInstanceStruct
  *chartInstance);
static void initSimStructsc16_Experiment_3_cs
  (SFc16_Experiment_3_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber, uint32_T c16_instanceNumber);
static void c16_info_helper(const mxArray **c16_info);
static const mxArray *c16_emlrt_marshallOut(const char * c16_u);
static const mxArray *c16_b_emlrt_marshallOut(const uint32_T c16_u);
static real_T c16_norm(SFc16_Experiment_3_csInstanceStruct *chartInstance,
  real_T c16_x[2]);
static real_T c16_emlrt_marshallIn(SFc16_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c16_b_alpha, const char_T *c16_identifier);
static real_T c16_b_emlrt_marshallIn(SFc16_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static uint8_T c16_c_emlrt_marshallIn(SFc16_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c16_b_is_active_c16_Experiment_3_cs, const
  char_T *c16_identifier);
static uint8_T c16_d_emlrt_marshallIn(SFc16_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void init_dsm_address_info(SFc16_Experiment_3_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc16_Experiment_3_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c16_Experiment_3_cs(SFc16_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c16_is_active_c16_Experiment_3_cs = 0U;
}

static void initialize_params_c16_Experiment_3_cs
  (SFc16_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c16_Experiment_3_cs(SFc16_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c16_Experiment_3_cs(SFc16_Experiment_3_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static const mxArray *get_sim_state_c16_Experiment_3_cs
  (SFc16_Experiment_3_csInstanceStruct *chartInstance)
{
  const mxArray *c16_st;
  const mxArray *c16_y = NULL;
  real_T c16_u;
  const mxArray *c16_b_y = NULL;
  uint8_T c16_b_u;
  const mxArray *c16_c_y = NULL;
  c16_st = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_createcellmatrix(2, 1), false);
  c16_u = *chartInstance->c16_alpha;
  c16_b_y = NULL;
  sf_mex_assign(&c16_b_y, sf_mex_create("y", &c16_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c16_y, 0, c16_b_y);
  c16_b_u = chartInstance->c16_is_active_c16_Experiment_3_cs;
  c16_c_y = NULL;
  sf_mex_assign(&c16_c_y, sf_mex_create("y", &c16_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c16_y, 1, c16_c_y);
  sf_mex_assign(&c16_st, c16_y, false);
  return c16_st;
}

static void set_sim_state_c16_Experiment_3_cs
  (SFc16_Experiment_3_csInstanceStruct *chartInstance, const mxArray *c16_st)
{
  const mxArray *c16_u;
  c16_u = sf_mex_dup(c16_st);
  *chartInstance->c16_alpha = c16_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c16_u, 0)), "alpha");
  chartInstance->c16_is_active_c16_Experiment_3_cs = c16_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c16_u, 1)),
     "is_active_c16_Experiment_3_cs");
  sf_mex_destroy(&c16_u);
  sf_mex_destroy(&c16_st);
}

static void finalize_c16_Experiment_3_cs(SFc16_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c16_Experiment_3_cs(SFc16_Experiment_3_csInstanceStruct
  *chartInstance)
{
  int32_T c16_k;
  real_T c16_v_p02pref[2];
  real_T c16_y;
  real_T c16_v_p02pvp[2];
  real_T c16_VectorSign;
  _sfTime_ = sf_get_time(chartInstance->S);
  for (c16_k = 0; c16_k < 2; c16_k++) {
    c16_v_p02pref[c16_k] = (*chartInstance->c16_pvp)[c16_k] -
      (*chartInstance->c16_p0)[c16_k];
  }

  c16_y = c16_norm(chartInstance, c16_v_p02pref);
  for (c16_k = 0; c16_k < 2; c16_k++) {
    c16_v_p02pvp[c16_k] = ((*chartInstance->c16_pvp)[c16_k] -
      (*chartInstance->c16_p0)[c16_k]) / c16_y;
    c16_v_p02pref[c16_k] = (*chartInstance->c16_pref)[c16_k] -
      (*chartInstance->c16_p0)[c16_k];
  }

  c16_y = c16_norm(chartInstance, c16_v_p02pref);
  for (c16_k = 0; c16_k < 2; c16_k++) {
    c16_v_p02pref[c16_k] = ((*chartInstance->c16_pref)[c16_k] -
      (*chartInstance->c16_p0)[c16_k]) / c16_y;
  }

  c16_VectorSign = c16_v_p02pvp[0] * c16_v_p02pref[1] - c16_v_p02pvp[1] *
    c16_v_p02pref[0];
  c16_y = 0.0;
  for (c16_k = 0; c16_k < 2; c16_k++) {
    c16_y += c16_v_p02pvp[c16_k] * c16_v_p02pref[c16_k];
  }

  *chartInstance->c16_alpha = muDoubleScalarAtan2(muDoubleScalarAbs
    (c16_VectorSign), c16_y) * muDoubleScalarSign(c16_VectorSign);
}

static void mdl_start_c16_Experiment_3_cs(SFc16_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc16_Experiment_3_cs
  (SFc16_Experiment_3_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber, uint32_T c16_instanceNumber)
{
  (void)c16_machineNumber;
  (void)c16_chartNumber;
  (void)c16_instanceNumber;
}

const mxArray *sf_c16_Experiment_3_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c16_nameCaptureInfo = NULL;
  c16_nameCaptureInfo = NULL;
  sf_mex_assign(&c16_nameCaptureInfo, sf_mex_createstruct("structure", 2, 60, 1),
                false);
  c16_info_helper(&c16_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c16_nameCaptureInfo);
  return c16_nameCaptureInfo;
}

static void c16_info_helper(const mxArray **c16_info)
{
  const mxArray *c16_rhs0 = NULL;
  const mxArray *c16_lhs0 = NULL;
  const mxArray *c16_rhs1 = NULL;
  const mxArray *c16_lhs1 = NULL;
  const mxArray *c16_rhs2 = NULL;
  const mxArray *c16_lhs2 = NULL;
  const mxArray *c16_rhs3 = NULL;
  const mxArray *c16_lhs3 = NULL;
  const mxArray *c16_rhs4 = NULL;
  const mxArray *c16_lhs4 = NULL;
  const mxArray *c16_rhs5 = NULL;
  const mxArray *c16_lhs5 = NULL;
  const mxArray *c16_rhs6 = NULL;
  const mxArray *c16_lhs6 = NULL;
  const mxArray *c16_rhs7 = NULL;
  const mxArray *c16_lhs7 = NULL;
  const mxArray *c16_rhs8 = NULL;
  const mxArray *c16_lhs8 = NULL;
  const mxArray *c16_rhs9 = NULL;
  const mxArray *c16_lhs9 = NULL;
  const mxArray *c16_rhs10 = NULL;
  const mxArray *c16_lhs10 = NULL;
  const mxArray *c16_rhs11 = NULL;
  const mxArray *c16_lhs11 = NULL;
  const mxArray *c16_rhs12 = NULL;
  const mxArray *c16_lhs12 = NULL;
  const mxArray *c16_rhs13 = NULL;
  const mxArray *c16_lhs13 = NULL;
  const mxArray *c16_rhs14 = NULL;
  const mxArray *c16_lhs14 = NULL;
  const mxArray *c16_rhs15 = NULL;
  const mxArray *c16_lhs15 = NULL;
  const mxArray *c16_rhs16 = NULL;
  const mxArray *c16_lhs16 = NULL;
  const mxArray *c16_rhs17 = NULL;
  const mxArray *c16_lhs17 = NULL;
  const mxArray *c16_rhs18 = NULL;
  const mxArray *c16_lhs18 = NULL;
  const mxArray *c16_rhs19 = NULL;
  const mxArray *c16_lhs19 = NULL;
  const mxArray *c16_rhs20 = NULL;
  const mxArray *c16_lhs20 = NULL;
  const mxArray *c16_rhs21 = NULL;
  const mxArray *c16_lhs21 = NULL;
  const mxArray *c16_rhs22 = NULL;
  const mxArray *c16_lhs22 = NULL;
  const mxArray *c16_rhs23 = NULL;
  const mxArray *c16_lhs23 = NULL;
  const mxArray *c16_rhs24 = NULL;
  const mxArray *c16_lhs24 = NULL;
  const mxArray *c16_rhs25 = NULL;
  const mxArray *c16_lhs25 = NULL;
  const mxArray *c16_rhs26 = NULL;
  const mxArray *c16_lhs26 = NULL;
  const mxArray *c16_rhs27 = NULL;
  const mxArray *c16_lhs27 = NULL;
  const mxArray *c16_rhs28 = NULL;
  const mxArray *c16_lhs28 = NULL;
  const mxArray *c16_rhs29 = NULL;
  const mxArray *c16_lhs29 = NULL;
  const mxArray *c16_rhs30 = NULL;
  const mxArray *c16_lhs30 = NULL;
  const mxArray *c16_rhs31 = NULL;
  const mxArray *c16_lhs31 = NULL;
  const mxArray *c16_rhs32 = NULL;
  const mxArray *c16_lhs32 = NULL;
  const mxArray *c16_rhs33 = NULL;
  const mxArray *c16_lhs33 = NULL;
  const mxArray *c16_rhs34 = NULL;
  const mxArray *c16_lhs34 = NULL;
  const mxArray *c16_rhs35 = NULL;
  const mxArray *c16_lhs35 = NULL;
  const mxArray *c16_rhs36 = NULL;
  const mxArray *c16_lhs36 = NULL;
  const mxArray *c16_rhs37 = NULL;
  const mxArray *c16_lhs37 = NULL;
  const mxArray *c16_rhs38 = NULL;
  const mxArray *c16_lhs38 = NULL;
  const mxArray *c16_rhs39 = NULL;
  const mxArray *c16_lhs39 = NULL;
  const mxArray *c16_rhs40 = NULL;
  const mxArray *c16_lhs40 = NULL;
  const mxArray *c16_rhs41 = NULL;
  const mxArray *c16_lhs41 = NULL;
  const mxArray *c16_rhs42 = NULL;
  const mxArray *c16_lhs42 = NULL;
  const mxArray *c16_rhs43 = NULL;
  const mxArray *c16_lhs43 = NULL;
  const mxArray *c16_rhs44 = NULL;
  const mxArray *c16_lhs44 = NULL;
  const mxArray *c16_rhs45 = NULL;
  const mxArray *c16_lhs45 = NULL;
  const mxArray *c16_rhs46 = NULL;
  const mxArray *c16_lhs46 = NULL;
  const mxArray *c16_rhs47 = NULL;
  const mxArray *c16_lhs47 = NULL;
  const mxArray *c16_rhs48 = NULL;
  const mxArray *c16_lhs48 = NULL;
  const mxArray *c16_rhs49 = NULL;
  const mxArray *c16_lhs49 = NULL;
  const mxArray *c16_rhs50 = NULL;
  const mxArray *c16_lhs50 = NULL;
  const mxArray *c16_rhs51 = NULL;
  const mxArray *c16_lhs51 = NULL;
  const mxArray *c16_rhs52 = NULL;
  const mxArray *c16_lhs52 = NULL;
  const mxArray *c16_rhs53 = NULL;
  const mxArray *c16_lhs53 = NULL;
  const mxArray *c16_rhs54 = NULL;
  const mxArray *c16_lhs54 = NULL;
  const mxArray *c16_rhs55 = NULL;
  const mxArray *c16_lhs55 = NULL;
  const mxArray *c16_rhs56 = NULL;
  const mxArray *c16_lhs56 = NULL;
  const mxArray *c16_rhs57 = NULL;
  const mxArray *c16_lhs57 = NULL;
  const mxArray *c16_rhs58 = NULL;
  const mxArray *c16_lhs58 = NULL;
  const mxArray *c16_rhs59 = NULL;
  const mxArray *c16_lhs59 = NULL;
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "emlfcn_preview_angle_and_distance"), "name", "name", 0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[E]C:/Program Files/PreScan/PreScan_8.1.0/SimulationCore/MatlabCode/CompilationSheet/emlfcn_preview_angle_and_distance.p"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1497540868U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c16_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[E]C:/Program Files/PreScan/PreScan_8.1.0/SimulationCore/MatlabCode/CompilationSheet/emlfcn_preview_angle_and_distance.p"),
                  "context", "context", 1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("norm"), "name", "name", 1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1363731868U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c16_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c16_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 3);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c16_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 4);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_xnrm2"), "name", "name",
                  4);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1376002292U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c16_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 5);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c16_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.blas.xnrm2"),
                  "name", "name", 6);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c16_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "context", "context", 7);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 7);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c16_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p!below_threshold"),
                  "context", "context", 8);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 8);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c16_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 9);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 9);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c16_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "context", "context", 10);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "coder.internal.refblas.xnrm2"), "name", "name", 10);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c16_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 11);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("realmin"), "name", "name",
                  11);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1307672842U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c16_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_realmin"), "name",
                  "name", 12);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1307672844U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c16_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 13);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c16_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 14);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 14);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c16_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 15);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 15);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 15);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c16_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 16);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 16);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 16);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c16_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 17);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 17);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c16_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 18);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("isfi"), "name", "name", 18);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 18);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1346531958U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c16_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 19);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1398897198U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c16_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 20);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("intmax"), "name", "name", 20);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c16_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 21);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c16_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 22);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("intmin"), "name", "name", 22);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c16_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 23);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c16_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 24);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("abs"), "name", "name", 24);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c16_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 25);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c16_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 26);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c16_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[E]C:/Program Files/PreScan/PreScan_8.1.0/SimulationCore/MatlabCode/CompilationSheet/emlfcn_preview_angle_and_distance.p"),
                  "context", "context", 27);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("rdivide"), "name", "name",
                  27);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c16_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 28);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c16_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 29);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c16_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_div"), "name", "name",
                  30);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c16_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 31);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c16_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("abs"), "name", "name", 32);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c16_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[E]C:/Program Files/PreScan/PreScan_8.1.0/SimulationCore/MatlabCode/CompilationSheet/emlfcn_preview_angle_and_distance.p"),
                  "context", "context", 33);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 33);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c16_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 34);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 34);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c16_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 35);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 35);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c16_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 36);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 36);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c16_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 37);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c16_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 38);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 38);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c16_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 39);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_xdotu"), "name", "name",
                  39);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1376002290U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c16_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 40);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 40);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c16_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 41);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.blas.xdotu"),
                  "name", "name", 41);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotu.p"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c16_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotu.p"),
                  "context", "context", 42);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.blas.xdot"),
                  "name", "name", 42);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c16_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 43);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 43);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c16_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p!below_threshold"),
                  "context", "context", 44);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 44);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c16_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 45);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.refblas.xdot"),
                  "name", "name", 45);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c16_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "context", "context", 46);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "coder.internal.refblas.xdotx"), "name", "name", 46);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c16_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 47);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 47);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c16_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 48);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 48);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c16_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 49);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 49);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 49);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c16_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 50);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 50);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 50);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 50);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c16_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 51);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 51);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c16_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[E]C:/Program Files/PreScan/PreScan_8.1.0/SimulationCore/MatlabCode/CompilationSheet/emlfcn_preview_angle_and_distance.p"),
                  "context", "context", 52);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("atan2"), "name", "name", 52);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "resolved",
                  "resolved", 52);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1395346496U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c16_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 53);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 53);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 53);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c16_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 54);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 54);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 54);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c16_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 55);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 55);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 55);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c16_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 56);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_scalar_atan2"), "name",
                  "name", 56);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m"),
                  "resolved", "resolved", 56);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1286840320U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c16_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[E]C:/Program Files/PreScan/PreScan_8.1.0/SimulationCore/MatlabCode/CompilationSheet/emlfcn_preview_angle_and_distance.p"),
                  "context", "context", 57);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("sign"), "name", "name", 57);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "resolved",
                  "resolved", 57);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c16_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 58);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 58);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 58);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c16_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 59);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_scalar_sign"), "name",
                  "name", 59);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m"),
                  "resolved", "resolved", 59);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1356563094U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c16_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs59), "lhs", "lhs",
                  59);
  sf_mex_destroy(&c16_rhs0);
  sf_mex_destroy(&c16_lhs0);
  sf_mex_destroy(&c16_rhs1);
  sf_mex_destroy(&c16_lhs1);
  sf_mex_destroy(&c16_rhs2);
  sf_mex_destroy(&c16_lhs2);
  sf_mex_destroy(&c16_rhs3);
  sf_mex_destroy(&c16_lhs3);
  sf_mex_destroy(&c16_rhs4);
  sf_mex_destroy(&c16_lhs4);
  sf_mex_destroy(&c16_rhs5);
  sf_mex_destroy(&c16_lhs5);
  sf_mex_destroy(&c16_rhs6);
  sf_mex_destroy(&c16_lhs6);
  sf_mex_destroy(&c16_rhs7);
  sf_mex_destroy(&c16_lhs7);
  sf_mex_destroy(&c16_rhs8);
  sf_mex_destroy(&c16_lhs8);
  sf_mex_destroy(&c16_rhs9);
  sf_mex_destroy(&c16_lhs9);
  sf_mex_destroy(&c16_rhs10);
  sf_mex_destroy(&c16_lhs10);
  sf_mex_destroy(&c16_rhs11);
  sf_mex_destroy(&c16_lhs11);
  sf_mex_destroy(&c16_rhs12);
  sf_mex_destroy(&c16_lhs12);
  sf_mex_destroy(&c16_rhs13);
  sf_mex_destroy(&c16_lhs13);
  sf_mex_destroy(&c16_rhs14);
  sf_mex_destroy(&c16_lhs14);
  sf_mex_destroy(&c16_rhs15);
  sf_mex_destroy(&c16_lhs15);
  sf_mex_destroy(&c16_rhs16);
  sf_mex_destroy(&c16_lhs16);
  sf_mex_destroy(&c16_rhs17);
  sf_mex_destroy(&c16_lhs17);
  sf_mex_destroy(&c16_rhs18);
  sf_mex_destroy(&c16_lhs18);
  sf_mex_destroy(&c16_rhs19);
  sf_mex_destroy(&c16_lhs19);
  sf_mex_destroy(&c16_rhs20);
  sf_mex_destroy(&c16_lhs20);
  sf_mex_destroy(&c16_rhs21);
  sf_mex_destroy(&c16_lhs21);
  sf_mex_destroy(&c16_rhs22);
  sf_mex_destroy(&c16_lhs22);
  sf_mex_destroy(&c16_rhs23);
  sf_mex_destroy(&c16_lhs23);
  sf_mex_destroy(&c16_rhs24);
  sf_mex_destroy(&c16_lhs24);
  sf_mex_destroy(&c16_rhs25);
  sf_mex_destroy(&c16_lhs25);
  sf_mex_destroy(&c16_rhs26);
  sf_mex_destroy(&c16_lhs26);
  sf_mex_destroy(&c16_rhs27);
  sf_mex_destroy(&c16_lhs27);
  sf_mex_destroy(&c16_rhs28);
  sf_mex_destroy(&c16_lhs28);
  sf_mex_destroy(&c16_rhs29);
  sf_mex_destroy(&c16_lhs29);
  sf_mex_destroy(&c16_rhs30);
  sf_mex_destroy(&c16_lhs30);
  sf_mex_destroy(&c16_rhs31);
  sf_mex_destroy(&c16_lhs31);
  sf_mex_destroy(&c16_rhs32);
  sf_mex_destroy(&c16_lhs32);
  sf_mex_destroy(&c16_rhs33);
  sf_mex_destroy(&c16_lhs33);
  sf_mex_destroy(&c16_rhs34);
  sf_mex_destroy(&c16_lhs34);
  sf_mex_destroy(&c16_rhs35);
  sf_mex_destroy(&c16_lhs35);
  sf_mex_destroy(&c16_rhs36);
  sf_mex_destroy(&c16_lhs36);
  sf_mex_destroy(&c16_rhs37);
  sf_mex_destroy(&c16_lhs37);
  sf_mex_destroy(&c16_rhs38);
  sf_mex_destroy(&c16_lhs38);
  sf_mex_destroy(&c16_rhs39);
  sf_mex_destroy(&c16_lhs39);
  sf_mex_destroy(&c16_rhs40);
  sf_mex_destroy(&c16_lhs40);
  sf_mex_destroy(&c16_rhs41);
  sf_mex_destroy(&c16_lhs41);
  sf_mex_destroy(&c16_rhs42);
  sf_mex_destroy(&c16_lhs42);
  sf_mex_destroy(&c16_rhs43);
  sf_mex_destroy(&c16_lhs43);
  sf_mex_destroy(&c16_rhs44);
  sf_mex_destroy(&c16_lhs44);
  sf_mex_destroy(&c16_rhs45);
  sf_mex_destroy(&c16_lhs45);
  sf_mex_destroy(&c16_rhs46);
  sf_mex_destroy(&c16_lhs46);
  sf_mex_destroy(&c16_rhs47);
  sf_mex_destroy(&c16_lhs47);
  sf_mex_destroy(&c16_rhs48);
  sf_mex_destroy(&c16_lhs48);
  sf_mex_destroy(&c16_rhs49);
  sf_mex_destroy(&c16_lhs49);
  sf_mex_destroy(&c16_rhs50);
  sf_mex_destroy(&c16_lhs50);
  sf_mex_destroy(&c16_rhs51);
  sf_mex_destroy(&c16_lhs51);
  sf_mex_destroy(&c16_rhs52);
  sf_mex_destroy(&c16_lhs52);
  sf_mex_destroy(&c16_rhs53);
  sf_mex_destroy(&c16_lhs53);
  sf_mex_destroy(&c16_rhs54);
  sf_mex_destroy(&c16_lhs54);
  sf_mex_destroy(&c16_rhs55);
  sf_mex_destroy(&c16_lhs55);
  sf_mex_destroy(&c16_rhs56);
  sf_mex_destroy(&c16_lhs56);
  sf_mex_destroy(&c16_rhs57);
  sf_mex_destroy(&c16_lhs57);
  sf_mex_destroy(&c16_rhs58);
  sf_mex_destroy(&c16_lhs58);
  sf_mex_destroy(&c16_rhs59);
  sf_mex_destroy(&c16_lhs59);
}

static const mxArray *c16_emlrt_marshallOut(const char * c16_u)
{
  const mxArray *c16_y = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c16_u)), false);
  return c16_y;
}

static const mxArray *c16_b_emlrt_marshallOut(const uint32_T c16_u)
{
  const mxArray *c16_y = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 7, 0U, 0U, 0U, 0), false);
  return c16_y;
}

static real_T c16_norm(SFc16_Experiment_3_csInstanceStruct *chartInstance,
  real_T c16_x[2])
{
  real_T c16_y;
  real_T c16_scale;
  int32_T c16_k;
  real_T c16_absxk;
  real_T c16_t;
  (void)chartInstance;
  c16_y = 0.0;
  c16_scale = 2.2250738585072014E-308;
  for (c16_k = 0; c16_k < 2; c16_k++) {
    c16_absxk = muDoubleScalarAbs(c16_x[c16_k]);
    if (c16_absxk > c16_scale) {
      c16_t = c16_scale / c16_absxk;
      c16_y = 1.0 + c16_y * c16_t * c16_t;
      c16_scale = c16_absxk;
    } else {
      c16_t = c16_absxk / c16_scale;
      c16_y += c16_t * c16_t;
    }
  }

  return c16_scale * muDoubleScalarSqrt(c16_y);
}

static real_T c16_emlrt_marshallIn(SFc16_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c16_b_alpha, const char_T *c16_identifier)
{
  real_T c16_y;
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_alpha),
    &c16_thisId);
  sf_mex_destroy(&c16_b_alpha);
  return c16_y;
}

static real_T c16_b_emlrt_marshallIn(SFc16_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  real_T c16_y;
  real_T c16_d0;
  (void)chartInstance;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_d0, 1, 0, 0U, 0, 0U, 0);
  c16_y = c16_d0;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static uint8_T c16_c_emlrt_marshallIn(SFc16_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c16_b_is_active_c16_Experiment_3_cs, const
  char_T *c16_identifier)
{
  uint8_T c16_y;
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c16_b_is_active_c16_Experiment_3_cs), &c16_thisId);
  sf_mex_destroy(&c16_b_is_active_c16_Experiment_3_cs);
  return c16_y;
}

static uint8_T c16_d_emlrt_marshallIn(SFc16_Experiment_3_csInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  uint8_T c16_y;
  uint8_T c16_u0;
  (void)chartInstance;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_u0, 1, 3, 0U, 0, 0U, 0);
  c16_y = c16_u0;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void init_dsm_address_info(SFc16_Experiment_3_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc16_Experiment_3_csInstanceStruct
  *chartInstance)
{
  chartInstance->c16_pvp = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c16_alpha = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c16_pref = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c16_p0 = (real_T (*)[2])ssGetInputPortSignal_wrapper
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

void sf_c16_Experiment_3_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3984957043U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3141026749U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2507607866U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2297332833U);
}

mxArray* sf_c16_Experiment_3_cs_get_post_codegen_info(void);
mxArray *sf_c16_Experiment_3_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("yWChiudngNtZnS9hf52q4F");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
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
    mxArray* mxPostCodegenInfo = sf_c16_Experiment_3_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c16_Experiment_3_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c16_Experiment_3_cs_jit_fallback_info(void)
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

mxArray *sf_c16_Experiment_3_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c16_Experiment_3_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c16_Experiment_3_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"alpha\",},{M[8],M[0],T\"is_active_c16_Experiment_3_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c16_Experiment_3_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "HQHn4eIeWs1TXBhmlC7T0E";
}

static void sf_opaque_initialize_c16_Experiment_3_cs(void *chartInstanceVar)
{
  initialize_params_c16_Experiment_3_cs((SFc16_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
  initialize_c16_Experiment_3_cs((SFc16_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c16_Experiment_3_cs(void *chartInstanceVar)
{
  enable_c16_Experiment_3_cs((SFc16_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c16_Experiment_3_cs(void *chartInstanceVar)
{
  disable_c16_Experiment_3_cs((SFc16_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c16_Experiment_3_cs(void *chartInstanceVar)
{
  sf_gateway_c16_Experiment_3_cs((SFc16_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c16_Experiment_3_cs(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c16_Experiment_3_cs((SFc16_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c16_Experiment_3_cs(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c16_Experiment_3_cs((SFc16_Experiment_3_csInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c16_Experiment_3_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc16_Experiment_3_csInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Experiment_3_cs_optimization_info();
    }

    finalize_c16_Experiment_3_cs((SFc16_Experiment_3_csInstanceStruct*)
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
  initSimStructsc16_Experiment_3_cs((SFc16_Experiment_3_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c16_Experiment_3_cs(SimStruct *S)
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
    initialize_params_c16_Experiment_3_cs((SFc16_Experiment_3_csInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c16_Experiment_3_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Experiment_3_cs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      16);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,16,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,16,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,16);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,16,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,16,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,16);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1176374538U));
  ssSetChecksum1(S,(3763876112U));
  ssSetChecksum2(S,(4277192942U));
  ssSetChecksum3(S,(4069287365U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c16_Experiment_3_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c16_Experiment_3_cs(SimStruct *S)
{
  SFc16_Experiment_3_csInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc16_Experiment_3_csInstanceStruct *)utMalloc(sizeof
    (SFc16_Experiment_3_csInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc16_Experiment_3_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c16_Experiment_3_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c16_Experiment_3_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c16_Experiment_3_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c16_Experiment_3_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c16_Experiment_3_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c16_Experiment_3_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c16_Experiment_3_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c16_Experiment_3_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c16_Experiment_3_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c16_Experiment_3_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c16_Experiment_3_cs;
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

void c16_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c16_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c16_Experiment_3_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c16_Experiment_3_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c16_Experiment_3_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
