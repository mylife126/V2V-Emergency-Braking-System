#ifndef __c46_Experiment_1_cs_h__
#define __c46_Experiment_1_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc46_Experiment_1_csInstanceStruct
#define typedef_SFc46_Experiment_1_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c46_sfEvent;
  boolean_T c46_isStable;
  boolean_T c46_doneDoubleBufferReInit;
  uint8_T c46_is_active_c46_Experiment_1_cs;
  real_T c46_Imout[562500];
  real_T c46_b[562500];
  real_T c46_Im[187500];
  real_T c46_y[562500];
  real_T c46_dv1[562500];
  real_T c46_inData[562500];
  real_T c46_u[562500];
  real_T c46_dv0[562500];
  real_T c46_b_u[562500];
  real_T c46_b_inData[187500];
  real_T c46_c_u[187500];
  real_T (*c46_b_Im)[187500];
  real_T (*c46_b_Imout)[562500];
} SFc46_Experiment_1_csInstanceStruct;

#endif                                 /*typedef_SFc46_Experiment_1_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c46_Experiment_1_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c46_Experiment_1_cs_get_check_sum(mxArray *plhs[]);
extern void c46_Experiment_1_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
