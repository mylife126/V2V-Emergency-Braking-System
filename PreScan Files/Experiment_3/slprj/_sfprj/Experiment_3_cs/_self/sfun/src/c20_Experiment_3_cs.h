#ifndef __c20_Experiment_3_cs_h__
#define __c20_Experiment_3_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc20_Experiment_3_csInstanceStruct
#define typedef_SFc20_Experiment_3_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c20_sfEvent;
  boolean_T c20_isStable;
  boolean_T c20_doneDoubleBufferReInit;
  uint8_T c20_is_active_c20_Experiment_3_cs;
  real_T c20_inData_data[220000];
  real_T c20_u_data[220000];
  real_T c20_label_data[220000];
  int32_T (*c20_nbboxout)[400];
  real_T (*c20_b_label_data)[220000];
  int32_T (*c20_label_sizes)[2];
  real_T (*c20_r_label)[100];
  real_T (*c20_color)[100];
} SFc20_Experiment_3_csInstanceStruct;

#endif                                 /*typedef_SFc20_Experiment_3_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c20_Experiment_3_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c20_Experiment_3_cs_get_check_sum(mxArray *plhs[]);
extern void c20_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
