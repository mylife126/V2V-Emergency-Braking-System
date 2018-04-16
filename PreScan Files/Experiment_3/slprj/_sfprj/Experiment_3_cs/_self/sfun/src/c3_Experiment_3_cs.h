#ifndef __c3_Experiment_3_cs_h__
#define __c3_Experiment_3_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_Experiment_3_csInstanceStruct
#define typedef_SFc3_Experiment_3_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint8_T c3_is_active_c3_Experiment_3_cs;
  real_T c3_Traj_x[990];
  real_T c3_Traj_y[990];
  real_T c3_Counter;
  boolean_T c3_Counter_not_empty;
  real_T c3_Actor_traj_distancePersist[2];
  boolean_T c3_Actor_traj_distancePersist_not_empty;
  real_T c3_Actor_traj_anglePersist[2];
  boolean_T c3_Actor_traj_anglePersist_not_empty;
  real_T c3_ActualTrajectoryIndex[2];
  boolean_T c3_ActualTrajectoryIndex_not_empty;
  real_T c3_prefPersist[4];
  boolean_T c3_prefPersist_not_empty;
  real_T (*c3_pref)[4];
  real_T (*c3_Actor_traj_distance)[2];
  real_T (*c3_Actor_traj_angle)[2];
  real_T (*c3_pvp)[4];
  real_T (*c3_TrajOffset_x_y_Y)[3];
  real_T *c3_ActorOffset_Left_Right;
  real_T (*c3_p0)[3];
} SFc3_Experiment_3_csInstanceStruct;

#endif                                 /*typedef_SFc3_Experiment_3_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_Experiment_3_cs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_Experiment_3_cs_get_check_sum(mxArray *plhs[]);
extern void c3_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
