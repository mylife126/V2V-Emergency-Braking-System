#ifndef __c37_Experiment_3_cs_h__
#define __c37_Experiment_3_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc37_Experiment_3_csInstanceStruct
#define typedef_SFc37_Experiment_3_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c37_sfEvent;
  boolean_T c37_isStable;
  boolean_T c37_doneDoubleBufferReInit;
  uint8_T c37_is_active_c37_Experiment_3_cs;
  real_T *c37_carX;
  real_T (*c37_pedResultX)[5];
  real_T *c37_carY;
  real_T *c37_carZ;
  real_T *c37_carRotZ;
  real_T (*c37_pedR)[5];
  real_T (*c37_pedTheta)[5];
  real_T *c37_pedPhi;
  real_T *c37_sensorCorrX;
  real_T *c37_sensorCorrY;
  real_T *c37_sensorCorrZ;
  real_T (*c37_pedResultY)[5];
  real_T (*c37_pedResultZ)[5];
} SFc37_Experiment_3_csInstanceStruct;

#endif                                 /*typedef_SFc37_Experiment_3_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c37_Experiment_3_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c37_Experiment_3_cs_get_check_sum(mxArray *plhs[]);
extern void c37_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
