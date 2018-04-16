#ifndef __c26_Experiment_1_cs_h__
#define __c26_Experiment_1_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc26_Experiment_1_csInstanceStruct
#define typedef_SFc26_Experiment_1_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c26_sfEvent;
  boolean_T c26_isStable;
  boolean_T c26_doneDoubleBufferReInit;
  uint8_T c26_is_active_c26_Experiment_1_cs;
  real_T c26_Imout[562500];
  real_T c26_b[562500];
  real_T c26_y[562500];
  real_T c26_dv1[562500];
  real_T c26_inData[562500];
  real_T c26_u[562500];
  real_T c26_dv0[562500];
  real_T c26_b_u[562500];
  uint8_T c26_b_inData[187500];
  uint8_T (*c26_Im)[187500];
  real_T (*c26_b_Imout)[562500];
} SFc26_Experiment_1_csInstanceStruct;

#endif                                 /*typedef_SFc26_Experiment_1_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c26_Experiment_1_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c26_Experiment_1_cs_get_check_sum(mxArray *plhs[]);
extern void c26_Experiment_1_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
