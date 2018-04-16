#ifndef __c32_Experiment_1_cs_h__
#define __c32_Experiment_1_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc32_Experiment_1_csInstanceStruct
#define typedef_SFc32_Experiment_1_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c32_sfEvent;
  boolean_T c32_isStable;
  boolean_T c32_doneDoubleBufferReInit;
  uint8_T c32_is_active_c32_Experiment_1_cs;
  real_T *c32_carX;
  real_T *c32_pedResultX;
  real_T *c32_carY;
  real_T *c32_carZ;
  real_T *c32_carRotZ;
  real_T *c32_pedR;
  real_T *c32_pedTheta;
  real_T *c32_pedPhi;
  real_T *c32_sensorCorrX;
  real_T *c32_sensorCorrY;
  real_T *c32_sensorCorrZ;
  real_T *c32_pedResultY;
  real_T *c32_pedResultZ;
} SFc32_Experiment_1_csInstanceStruct;

#endif                                 /*typedef_SFc32_Experiment_1_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c32_Experiment_1_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c32_Experiment_1_cs_get_check_sum(mxArray *plhs[]);
extern void c32_Experiment_1_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
