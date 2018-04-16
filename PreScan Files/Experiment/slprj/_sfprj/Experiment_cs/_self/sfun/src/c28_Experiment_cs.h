#ifndef __c28_Experiment_cs_h__
#define __c28_Experiment_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc28_Experiment_csInstanceStruct
#define typedef_SFc28_Experiment_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c28_sfEvent;
  boolean_T c28_isStable;
  boolean_T c28_doneDoubleBufferReInit;
  uint8_T c28_is_active_c28_Experiment_cs;
  real_T c28_TISdet;
  real_T c28_TISMaxRange;
  real_T (*c28_r)[32];
  real_T (*c28_th1)[32];
  real_T (*c28_th2)[32];
  real_T (*c28_thd)[32];
  real_T *c28_time;
  real_T (*c28_K1)[640];
  real_T (*c28_K2)[640];
} SFc28_Experiment_csInstanceStruct;

#endif                                 /*typedef_SFc28_Experiment_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c28_Experiment_cs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c28_Experiment_cs_get_check_sum(mxArray *plhs[]);
extern void c28_Experiment_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif