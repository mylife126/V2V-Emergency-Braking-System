#ifndef __c67_Experiment_3_cs_h__
#define __c67_Experiment_3_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc67_Experiment_3_csInstanceStruct
#define typedef_SFc67_Experiment_3_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c67_sfEvent;
  boolean_T c67_isStable;
  boolean_T c67_doneDoubleBufferReInit;
  uint8_T c67_is_active_c67_Experiment_3_cs;
  real_T *c67_carX;
  real_T (*c67_pedResultX)[5];
  real_T *c67_carY;
  real_T *c67_carZ;
  real_T *c67_carRotZ;
  real_T (*c67_pedR)[5];
  real_T (*c67_pedTheta)[5];
  real_T *c67_pedPhi;
  real_T *c67_sensorCorrX;
  real_T *c67_sensorCorrY;
  real_T *c67_sensorCorrZ;
  real_T (*c67_pedResultY)[5];
  real_T (*c67_pedResultZ)[5];
} SFc67_Experiment_3_csInstanceStruct;

#endif                                 /*typedef_SFc67_Experiment_3_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c67_Experiment_3_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c67_Experiment_3_cs_get_check_sum(mxArray *plhs[]);
extern void c67_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
