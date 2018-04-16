#ifndef __c59_Experiment_1_cs_h__
#define __c59_Experiment_1_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc59_Experiment_1_csInstanceStruct
#define typedef_SFc59_Experiment_1_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c59_sfEvent;
  boolean_T c59_isStable;
  boolean_T c59_doneDoubleBufferReInit;
  uint8_T c59_is_active_c59_Experiment_1_cs;
  real_T c59_TISdet;
  real_T *c59_v;
  real_T (*c59_xpd)[32];
  real_T (*c59_xp_dot)[32];
} SFc59_Experiment_1_csInstanceStruct;

#endif                                 /*typedef_SFc59_Experiment_1_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c59_Experiment_1_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c59_Experiment_1_cs_get_check_sum(mxArray *plhs[]);
extern void c59_Experiment_1_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
