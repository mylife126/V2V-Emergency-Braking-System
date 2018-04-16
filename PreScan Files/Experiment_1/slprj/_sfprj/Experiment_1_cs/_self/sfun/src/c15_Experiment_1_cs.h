#ifndef __c15_Experiment_1_cs_h__
#define __c15_Experiment_1_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc15_Experiment_1_csInstanceStruct
#define typedef_SFc15_Experiment_1_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint8_T c15_is_active_c15_Experiment_1_cs;
  real_T c15_Traj_x[609];
  real_T c15_Traj_y[609];
  real_T c15_Counter;
  boolean_T c15_Counter_not_empty;
  real_T c15_Actor_traj_distancePersist[2];
  boolean_T c15_Actor_traj_distancePersist_not_empty;
  real_T c15_Actor_traj_anglePersist[2];
  boolean_T c15_Actor_traj_anglePersist_not_empty;
  real_T c15_ActualTrajectoryIndex[2];
  boolean_T c15_ActualTrajectoryIndex_not_empty;
  real_T c15_prefPersist[4];
  boolean_T c15_prefPersist_not_empty;
  real_T (*c15_pref)[4];
  real_T (*c15_Actor_traj_distance)[2];
  real_T (*c15_Actor_traj_angle)[2];
  real_T (*c15_pvp)[4];
  real_T (*c15_TrajOffset_x_y_Y)[3];
  real_T *c15_ActorOffset_Left_Right;
  real_T (*c15_p0)[3];
} SFc15_Experiment_1_csInstanceStruct;

#endif                                 /*typedef_SFc15_Experiment_1_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c15_Experiment_1_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c15_Experiment_1_cs_get_check_sum(mxArray *plhs[]);
extern void c15_Experiment_1_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
