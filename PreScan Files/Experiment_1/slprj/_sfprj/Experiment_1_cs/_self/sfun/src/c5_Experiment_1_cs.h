#ifndef __c5_Experiment_1_cs_h__
#define __c5_Experiment_1_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc5_Experiment_1_csInstanceStruct
#define typedef_SFc5_Experiment_1_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c5_sfEvent;
  boolean_T c5_isStable;
  boolean_T c5_doneDoubleBufferReInit;
  uint8_T c5_is_active_c5_Experiment_1_cs;
  int32_T (*c5_inpoints)[200];
  int32_T (*c5_pts)[200];
} SFc5_Experiment_1_csInstanceStruct;

#endif                                 /*typedef_SFc5_Experiment_1_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_Experiment_1_cs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_Experiment_1_cs_get_check_sum(mxArray *plhs[]);
extern void c5_Experiment_1_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
