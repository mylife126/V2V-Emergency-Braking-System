#ifndef __c41_Experiment_1_cs_h__
#define __c41_Experiment_1_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc41_Experiment_1_csInstanceStruct
#define typedef_SFc41_Experiment_1_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c41_sfEvent;
  boolean_T c41_isStable;
  boolean_T c41_doneDoubleBufferReInit;
  uint8_T c41_is_active_c41_Experiment_1_cs;
  real_T c41_TISdet;
  real_T c41_TISMaxRange;
  real_T (*c41_r)[32];
  real_T (*c41_th1)[32];
  real_T (*c41_th2)[32];
  real_T (*c41_thd)[32];
  real_T *c41_time;
  real_T (*c41_K1)[640];
  real_T (*c41_K2)[640];
} SFc41_Experiment_1_csInstanceStruct;

#endif                                 /*typedef_SFc41_Experiment_1_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c41_Experiment_1_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c41_Experiment_1_cs_get_check_sum(mxArray *plhs[]);
extern void c41_Experiment_1_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
