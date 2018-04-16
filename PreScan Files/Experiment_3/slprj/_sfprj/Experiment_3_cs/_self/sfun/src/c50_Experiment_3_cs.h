#ifndef __c50_Experiment_3_cs_h__
#define __c50_Experiment_3_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc50_Experiment_3_csInstanceStruct
#define typedef_SFc50_Experiment_3_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c50_sfEvent;
  boolean_T c50_isStable;
  boolean_T c50_doneDoubleBufferReInit;
  uint8_T c50_is_active_c50_Experiment_3_cs;
  real_T c50_TISdet[2];
  real_T c50_TISMaxRange[2];
  real_T (*c50_r)[32];
  real_T (*c50_th1)[32];
  real_T (*c50_th2)[32];
  real_T (*c50_thd)[32];
  real_T *c50_time;
  real_T (*c50_K1)[640];
  real_T (*c50_K2)[640];
} SFc50_Experiment_3_csInstanceStruct;

#endif                                 /*typedef_SFc50_Experiment_3_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c50_Experiment_3_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c50_Experiment_3_cs_get_check_sum(mxArray *plhs[]);
extern void c50_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
