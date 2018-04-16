#ifndef __c31_Experiment_cs_h__
#define __c31_Experiment_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc31_Experiment_csInstanceStruct
#define typedef_SFc31_Experiment_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c31_sfEvent;
  boolean_T c31_isStable;
  boolean_T c31_doneDoubleBufferReInit;
  uint8_T c31_is_active_c31_Experiment_cs;
  real_T c31_inData_data[220000];
  real_T c31_u_data[220000];
  real_T c31_label_data[220000];
  int32_T (*c31_nbboxout)[400];
  real_T (*c31_b_label_data)[220000];
  int32_T (*c31_label_sizes)[2];
  real_T (*c31_r_label)[100];
  real_T (*c31_color)[100];
} SFc31_Experiment_csInstanceStruct;

#endif                                 /*typedef_SFc31_Experiment_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c31_Experiment_cs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c31_Experiment_cs_get_check_sum(mxArray *plhs[]);
extern void c31_Experiment_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
