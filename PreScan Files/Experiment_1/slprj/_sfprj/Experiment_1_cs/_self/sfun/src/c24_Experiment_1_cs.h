#ifndef __c24_Experiment_1_cs_h__
#define __c24_Experiment_1_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc24_Experiment_1_csInstanceStruct
#define typedef_SFc24_Experiment_1_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c24_sfEvent;
  boolean_T c24_isStable;
  boolean_T c24_doneDoubleBufferReInit;
  uint8_T c24_is_active_c24_Experiment_1_cs;
  real_T c24_TISdet;
  int32_T (*c24_CentAlarms)[64];
  real_T (*c24_PosObj_subim)[64];
  int32_T (*c24_Centroid_subim)[200];
  real_T (*c24_alarms_data)[32];
  int32_T *c24_alarms_sizes;
  int32_T (*c24_BBox)[400];
  int32_T (*c24_BBox_det)[400];
} SFc24_Experiment_1_csInstanceStruct;

#endif                                 /*typedef_SFc24_Experiment_1_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c24_Experiment_1_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c24_Experiment_1_cs_get_check_sum(mxArray *plhs[]);
extern void c24_Experiment_1_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
