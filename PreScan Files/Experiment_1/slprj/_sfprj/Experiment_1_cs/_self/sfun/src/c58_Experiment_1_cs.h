#ifndef __c58_Experiment_1_cs_h__
#define __c58_Experiment_1_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc58_Experiment_1_csInstanceStruct
#define typedef_SFc58_Experiment_1_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c58_sfEvent;
  boolean_T c58_isStable;
  boolean_T c58_doneDoubleBufferReInit;
  uint8_T c58_is_active_c58_Experiment_1_cs;
  real_T c58_TISdet;
  real_T c58_TISMaxRange;
  real_T (*c58_r)[32];
  real_T (*c58_yp2)[32];
  real_T (*c58_yp1)[32];
  real_T (*c58_K1)[1600];
  real_T (*c58_K2)[1600];
} SFc58_Experiment_1_csInstanceStruct;

#endif                                 /*typedef_SFc58_Experiment_1_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c58_Experiment_1_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c58_Experiment_1_cs_get_check_sum(mxArray *plhs[]);
extern void c58_Experiment_1_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
