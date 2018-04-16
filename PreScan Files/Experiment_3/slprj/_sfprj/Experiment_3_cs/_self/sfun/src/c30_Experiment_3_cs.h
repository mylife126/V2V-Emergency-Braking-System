#ifndef __c30_Experiment_3_cs_h__
#define __c30_Experiment_3_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc30_Experiment_3_csInstanceStruct
#define typedef_SFc30_Experiment_3_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c30_sfEvent;
  boolean_T c30_isStable;
  boolean_T c30_doneDoubleBufferReInit;
  uint8_T c30_is_active_c30_Experiment_3_cs;
  real_T c30_TISdet;
  real_T c30_TISMaxRange;
  real_T (*c30_r)[32];
  real_T (*c30_yp2)[32];
  real_T (*c30_yp1)[32];
  real_T (*c30_K1)[1600];
  real_T (*c30_K2)[1600];
} SFc30_Experiment_3_csInstanceStruct;

#endif                                 /*typedef_SFc30_Experiment_3_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c30_Experiment_3_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c30_Experiment_3_cs_get_check_sum(mxArray *plhs[]);
extern void c30_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
