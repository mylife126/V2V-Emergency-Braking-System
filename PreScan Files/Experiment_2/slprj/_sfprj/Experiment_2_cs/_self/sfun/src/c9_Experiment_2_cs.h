#ifndef __c9_Experiment_2_cs_h__
#define __c9_Experiment_2_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc9_Experiment_2_csInstanceStruct
#define typedef_SFc9_Experiment_2_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint8_T c9_is_active_c9_Experiment_2_cs;
  real_T c9_RefreshCounter;
  real_T c9_Counter;
  boolean_T c9_Counter_not_empty;
  real_T c9_delta_steeringwheeltotalOutput;
  boolean_T c9_delta_steeringwheeltotalOutput_not_empty;
  real_T *c9_v_x_vehicle;
  real_T *c9_v_x_vehicle_Min;
  real_T *c9_t_Preview_LatCtrl;
  real_T *c9_delta_steeringwheeltotal;
  real_T *c9_v_y_vehicle;
  real_T *c9_yawrate_vehicle;
  real_T *c9_CorneringStiffness_Tyres_Front;
  real_T *c9_CorneringStiffness_Tyres_Rear;
  real_T *c9_m_vehicle_total;
  real_T *c9_inertia_z_vehicle_total;
  real_T (*c9_e_Lat)[10];
  real_T *c9_Pos_x_CoG_Vehicle;
  real_T *c9_wheelbase;
} SFc9_Experiment_2_csInstanceStruct;

#endif                                 /*typedef_SFc9_Experiment_2_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c9_Experiment_2_cs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c9_Experiment_2_cs_get_check_sum(mxArray *plhs[]);
extern void c9_Experiment_2_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
