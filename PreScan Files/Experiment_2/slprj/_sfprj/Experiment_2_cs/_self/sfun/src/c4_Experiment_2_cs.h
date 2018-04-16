#ifndef __c4_Experiment_2_cs_h__
#define __c4_Experiment_2_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc4_Experiment_2_csInstanceStruct
#define typedef_SFc4_Experiment_2_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint8_T c4_is_active_c4_Experiment_2_cs;
  real_T c4_Traj_x[1624];
  real_T c4_Traj_y[1624];
  real_T c4_RefreshCounter;
  real_T c4_Counter;
  boolean_T c4_Counter_not_empty;
  real_T c4_Actor_traj_distanceOutput;
  boolean_T c4_Actor_traj_distanceOutput_not_empty;
  real_T c4_Actor_traj_angleOutput;
  boolean_T c4_Actor_traj_angleOutput_not_empty;
  real_T c4_ActualTrajectoryIndex;
  boolean_T c4_ActualTrajectoryIndex_not_empty;
  real_T (*c4_pvp)[2];
  real_T *c4_Actor_traj_distance;
  real_T (*c4_TrajOffset_x_y_Y)[3];
  real_T *c4_ActorOffset_Left_Right;
  real_T (*c4_p0)[3];
  real_T *c4_Actor_traj_angle;
} SFc4_Experiment_2_csInstanceStruct;

#endif                                 /*typedef_SFc4_Experiment_2_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_Experiment_2_cs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_Experiment_2_cs_get_check_sum(mxArray *plhs[]);
extern void c4_Experiment_2_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
