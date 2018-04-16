#ifndef __c40_Experiment_1_cs_h__
#define __c40_Experiment_1_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc40_Experiment_1_csInstanceStruct
#define typedef_SFc40_Experiment_1_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c40_sfEvent;
  boolean_T c40_isStable;
  boolean_T c40_doneDoubleBufferReInit;
  uint8_T c40_is_active_c40_Experiment_1_cs;
  real_T c40_TISdet;
  real_T (*c40_th)[32];
  real_T (*c40_thp)[32];
  real_T (*c40_thd)[32];
  real_T (*c40_th_dot)[32];
} SFc40_Experiment_1_csInstanceStruct;

#endif                                 /*typedef_SFc40_Experiment_1_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c40_Experiment_1_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c40_Experiment_1_cs_get_check_sum(mxArray *plhs[]);
extern void c40_Experiment_1_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
