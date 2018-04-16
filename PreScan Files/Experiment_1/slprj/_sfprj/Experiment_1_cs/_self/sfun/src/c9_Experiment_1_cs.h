#ifndef __c9_Experiment_1_cs_h__
#define __c9_Experiment_1_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc9_Experiment_1_csInstanceStruct
#define typedef_SFc9_Experiment_1_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c9_sfEvent;
  boolean_T c9_isStable;
  boolean_T c9_doneDoubleBufferReInit;
  uint8_T c9_is_active_c9_Experiment_1_cs;
  real_T c9_TISdet;
  real_T c9_TISMaxRange;
  real_T (*c9_r)[32];
  real_T (*c9_th1)[32];
  real_T (*c9_th2)[32];
  real_T (*c9_thd)[32];
  real_T *c9_time;
  real_T (*c9_K1)[640];
  real_T (*c9_K2)[640];
} SFc9_Experiment_1_csInstanceStruct;

#endif                                 /*typedef_SFc9_Experiment_1_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c9_Experiment_1_cs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c9_Experiment_1_cs_get_check_sum(mxArray *plhs[]);
extern void c9_Experiment_1_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
