#ifndef __c41_Experiment_cs_h__
#define __c41_Experiment_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc41_Experiment_csInstanceStruct
#define typedef_SFc41_Experiment_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c41_sfEvent;
  boolean_T c41_isStable;
  boolean_T c41_doneDoubleBufferReInit;
  uint8_T c41_is_active_c41_Experiment_cs;
  real_T c41_Imout[562500];
  real_T c41_b[562500];
  real_T c41_y[562500];
  real_T c41_dv1[562500];
  real_T c41_inData[562500];
  real_T c41_u[562500];
  real_T c41_dv0[562500];
  real_T c41_b_u[562500];
  uint8_T c41_b_inData[187500];
  uint8_T (*c41_Im)[187500];
  real_T (*c41_b_Imout)[562500];
} SFc41_Experiment_csInstanceStruct;

#endif                                 /*typedef_SFc41_Experiment_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c41_Experiment_cs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c41_Experiment_cs_get_check_sum(mxArray *plhs[]);
extern void c41_Experiment_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
