#ifndef __c38_Experiment_1_cs_h__
#define __c38_Experiment_1_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc38_Experiment_1_csInstanceStruct
#define typedef_SFc38_Experiment_1_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c38_sfEvent;
  boolean_T c38_isStable;
  boolean_T c38_doneDoubleBufferReInit;
  uint8_T c38_is_active_c38_Experiment_1_cs;
  real_T c38_TISdet;
  real_T c38_TISMaxRange;
  real_T (*c38_r)[32];
  real_T (*c38_yp2)[32];
  real_T (*c38_yp1)[32];
  real_T (*c38_K1)[1600];
  real_T (*c38_K2)[1600];
} SFc38_Experiment_1_csInstanceStruct;

#endif                                 /*typedef_SFc38_Experiment_1_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c38_Experiment_1_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c38_Experiment_1_cs_get_check_sum(mxArray *plhs[]);
extern void c38_Experiment_1_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
