#ifndef __c48_Experiment_1_cs_h__
#define __c48_Experiment_1_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc48_Experiment_1_csInstanceStruct
#define typedef_SFc48_Experiment_1_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c48_sfEvent;
  boolean_T c48_isStable;
  boolean_T c48_doneDoubleBufferReInit;
  uint8_T c48_is_active_c48_Experiment_1_cs;
  real_T c48_Imout[562500];
  real_T c48_b[562500];
  real_T c48_y[562500];
  real_T c48_dv1[562500];
  real_T c48_inData[562500];
  real_T c48_u[562500];
  real_T c48_dv0[562500];
  real_T c48_b_u[562500];
  uint8_T c48_b_inData[187500];
  uint8_T (*c48_Im)[187500];
  real_T (*c48_b_Imout)[562500];
} SFc48_Experiment_1_csInstanceStruct;

#endif                                 /*typedef_SFc48_Experiment_1_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c48_Experiment_1_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c48_Experiment_1_cs_get_check_sum(mxArray *plhs[]);
extern void c48_Experiment_1_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
