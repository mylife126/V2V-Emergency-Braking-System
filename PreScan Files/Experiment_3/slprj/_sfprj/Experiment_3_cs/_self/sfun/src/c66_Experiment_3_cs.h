#ifndef __c66_Experiment_3_cs_h__
#define __c66_Experiment_3_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc66_Experiment_3_csInstanceStruct
#define typedef_SFc66_Experiment_3_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c66_sfEvent;
  boolean_T c66_isStable;
  boolean_T c66_doneDoubleBufferReInit;
  uint8_T c66_is_active_c66_Experiment_3_cs;
  real_T *c66_carX;
  real_T (*c66_pedR)[5];
  real_T *c66_carY;
  real_T *c66_carZ;
  real_T *c66_carRotZ;
  real_T (*c66_pedX)[5];
  real_T (*c66_pedY)[5];
  real_T *c66_pedZ;
  real_T *c66_sensorCorrX;
  real_T *c66_sensorCorrY;
  real_T *c66_sensorCorrZ;
  real_T (*c66_pedTheta)[5];
  real_T (*c66_pedPhi)[5];
} SFc66_Experiment_3_csInstanceStruct;

#endif                                 /*typedef_SFc66_Experiment_3_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c66_Experiment_3_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c66_Experiment_3_cs_get_check_sum(mxArray *plhs[]);
extern void c66_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
