#ifndef __c35_Experiment_2_cs_h__
#define __c35_Experiment_2_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc35_Experiment_2_csInstanceStruct
#define typedef_SFc35_Experiment_2_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c35_sfEvent;
  boolean_T c35_isStable;
  boolean_T c35_doneDoubleBufferReInit;
  uint8_T c35_is_active_c35_Experiment_2_cs;
  real_T *c35_carX;
  real_T (*c35_pedResultX)[3];
  real_T *c35_carY;
  real_T *c35_carZ;
  real_T *c35_carRotZ;
  real_T (*c35_pedR)[3];
  real_T (*c35_pedTheta)[3];
  real_T *c35_pedPhi;
  real_T *c35_sensorCorrX;
  real_T *c35_sensorCorrY;
  real_T *c35_sensorCorrZ;
  real_T (*c35_pedResultY)[3];
  real_T (*c35_pedResultZ)[3];
} SFc35_Experiment_2_csInstanceStruct;

#endif                                 /*typedef_SFc35_Experiment_2_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c35_Experiment_2_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c35_Experiment_2_cs_get_check_sum(mxArray *plhs[]);
extern void c35_Experiment_2_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
