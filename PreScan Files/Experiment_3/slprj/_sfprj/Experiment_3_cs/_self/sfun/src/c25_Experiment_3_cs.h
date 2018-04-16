#ifndef __c25_Experiment_3_cs_h__
#define __c25_Experiment_3_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc25_Experiment_3_csInstanceStruct
#define typedef_SFc25_Experiment_3_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c25_sfEvent;
  boolean_T c25_isStable;
  boolean_T c25_doneDoubleBufferReInit;
  uint8_T c25_is_active_c25_Experiment_3_cs;
  real_T c25_Imout[562500];
  real_T c25_b[562500];
  real_T c25_Im[187500];
  real_T c25_y[562500];
  real_T c25_dv1[562500];
  real_T c25_inData[562500];
  real_T c25_u[562500];
  real_T c25_dv0[562500];
  real_T c25_b_u[562500];
  real_T c25_b_inData[187500];
  real_T c25_c_u[187500];
  real_T (*c25_b_Im)[187500];
  real_T (*c25_b_Imout)[562500];
} SFc25_Experiment_3_csInstanceStruct;

#endif                                 /*typedef_SFc25_Experiment_3_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c25_Experiment_3_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c25_Experiment_3_cs_get_check_sum(mxArray *plhs[]);
extern void c25_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
