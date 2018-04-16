#ifndef __c38_Experiment_cs_h__
#define __c38_Experiment_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc38_Experiment_csInstanceStruct
#define typedef_SFc38_Experiment_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c38_sfEvent;
  boolean_T c38_isStable;
  boolean_T c38_doneDoubleBufferReInit;
  uint8_T c38_is_active_c38_Experiment_cs;
  real_T c38_TISdet;
  int32_T (*c38_CentAlarms)[64];
  real_T (*c38_PosObj_subim)[64];
  int32_T (*c38_Centroid_subim)[200];
  real_T (*c38_alarms_data)[32];
  int32_T *c38_alarms_sizes;
  int32_T (*c38_BBox)[400];
  int32_T (*c38_BBox_det)[400];
} SFc38_Experiment_csInstanceStruct;

#endif                                 /*typedef_SFc38_Experiment_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c38_Experiment_cs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c38_Experiment_cs_get_check_sum(mxArray *plhs[]);
extern void c38_Experiment_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
