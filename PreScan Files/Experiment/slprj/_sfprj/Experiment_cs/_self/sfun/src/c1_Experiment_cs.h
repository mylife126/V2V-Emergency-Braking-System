#ifndef __c1_Experiment_cs_h__
#define __c1_Experiment_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_Experiment_csInstanceStruct
#define typedef_SFc1_Experiment_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint8_T c1_is_active_c1_Experiment_cs;
  real_T c1_Traj_x[397];
  real_T c1_Traj_y[397];
  real_T c1_Counter;
  boolean_T c1_Counter_not_empty;
  real_T c1_Actor_traj_distancePersist[2];
  boolean_T c1_Actor_traj_distancePersist_not_empty;
  real_T c1_Actor_traj_anglePersist[2];
  boolean_T c1_Actor_traj_anglePersist_not_empty;
  real_T c1_ActualTrajectoryIndex[2];
  boolean_T c1_ActualTrajectoryIndex_not_empty;
  real_T c1_prefPersist[4];
  boolean_T c1_prefPersist_not_empty;
  real_T (*c1_pref)[4];
  real_T (*c1_Actor_traj_distance)[2];
  real_T (*c1_Actor_traj_angle)[2];
  real_T (*c1_pvp)[4];
  real_T (*c1_TrajOffset_x_y_Y)[3];
  real_T *c1_ActorOffset_Left_Right;
  real_T (*c1_p0)[3];
} SFc1_Experiment_csInstanceStruct;

#endif                                 /*typedef_SFc1_Experiment_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_Experiment_cs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_Experiment_cs_get_check_sum(mxArray *plhs[]);
extern void c1_Experiment_cs_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
