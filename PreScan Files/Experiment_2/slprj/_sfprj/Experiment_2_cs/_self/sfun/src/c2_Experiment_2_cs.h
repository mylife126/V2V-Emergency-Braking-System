#ifndef __c2_Experiment_2_cs_h__
#define __c2_Experiment_2_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_Experiment_2_csInstanceStruct
#define typedef_SFc2_Experiment_2_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint8_T c2_is_active_c2_Experiment_2_cs;
  real_T c2_Traj_x[1624];
  real_T c2_Traj_y[1624];
  real_T c2_Traj_t;
  real_T c2_Traj_v[1624];
  real_T c2_RefreshCounter;
  real_T c2_Counter;
  boolean_T c2_Counter_not_empty;
  real_T c2_dist_psvehicleOutput[10];
  boolean_T c2_dist_psvehicleOutput_not_empty;
  real_T c2_ActualTrajectoryIndex;
  boolean_T c2_ActualTrajectoryIndex_not_empty;
  real_T c2_s[10];
  boolean_T c2_s_not_empty;
  real_T c2_PreviewTrajIndex[10];
  boolean_T c2_PreviewTrajIndex_not_empty;
  real_T c2_deltaT[10];
  boolean_T c2_deltaT_not_empty;
  boolean_T c2_iiChangedFromOneToSomething;
  boolean_T c2_iiChangedFromOneToSomething_not_empty;
  real_T c2_DistanceInterpolatedPointOld;
  boolean_T c2_DistanceInterpolatedPointOld_not_empty;
  real_T c2_DistanceInterpolatedPoint_p3p2Old;
  boolean_T c2_DistanceInterpolatedPoint_p3p2Old_not_empty;
  real_T (*c2_pvp)[2];
  real_T (*c2_dist_psvehicle)[10];
  real_T (*c2_TrajOffset_x_y_Y)[3];
  real_T *c2_ActorOffset_Left_Right;
  real_T (*c2_p0)[2];
  real_T (*c2_PreviewDistance)[10];
} SFc2_Experiment_2_csInstanceStruct;

#endif                                 /*typedef_SFc2_Experiment_2_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_Experiment_2_cs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_Experiment_2_cs_get_check_sum(mxArray *plhs[]);
extern void c2_Experiment_2_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
