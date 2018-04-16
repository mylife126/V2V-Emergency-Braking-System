#ifndef __c48_Experiment_3_cs_h__
#define __c48_Experiment_3_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc48_Experiment_3_csInstanceStruct
#define typedef_SFc48_Experiment_3_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c48_sfEvent;
  boolean_T c48_isStable;
  boolean_T c48_doneDoubleBufferReInit;
  uint8_T c48_is_active_c48_Experiment_3_cs;
  real_T c48_TISdet[2];
  real_T c48_TISMaxRange[2];
  real_T (*c48_r)[32];
  real_T (*c48_th1)[32];
  real_T (*c48_th2)[32];
  real_T (*c48_thd)[32];
  real_T *c48_time;
  real_T (*c48_K1)[640];
  real_T (*c48_K2)[640];
} SFc48_Experiment_3_csInstanceStruct;

#endif                                 /*typedef_SFc48_Experiment_3_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c48_Experiment_3_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c48_Experiment_3_cs_get_check_sum(mxArray *plhs[]);
extern void c48_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
