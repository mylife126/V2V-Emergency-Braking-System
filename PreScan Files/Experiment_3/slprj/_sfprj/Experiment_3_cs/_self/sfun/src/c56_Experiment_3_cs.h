#ifndef __c56_Experiment_3_cs_h__
#define __c56_Experiment_3_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc56_Experiment_3_csInstanceStruct
#define typedef_SFc56_Experiment_3_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c56_sfEvent;
  boolean_T c56_isStable;
  boolean_T c56_doneDoubleBufferReInit;
  uint8_T c56_is_active_c56_Experiment_3_cs;
  real_T c56_TISdet[2];
  real_T (*c56_indx)[32];
  real_T (*c56_THETA)[32];
  real_T (*c56_theta)[32];
} SFc56_Experiment_3_csInstanceStruct;

#endif                                 /*typedef_SFc56_Experiment_3_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c56_Experiment_3_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c56_Experiment_3_cs_get_check_sum(mxArray *plhs[]);
extern void c56_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
