#ifndef __c22_Experiment_2_cs_h__
#define __c22_Experiment_2_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc22_Experiment_2_csInstanceStruct
#define typedef_SFc22_Experiment_2_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c22_sfEvent;
  boolean_T c22_isStable;
  boolean_T c22_doneDoubleBufferReInit;
  uint8_T c22_is_active_c22_Experiment_2_cs;
  real_T c22_TISdet;
  real_T c22_TISMaxRange;
  boolean_T (*c22_flag)[32];
  real_T (*c22_theta)[32];
  real_T (*c22_posit)[64];
  real_T (*c22_range)[32];
  real_T (*c22_xs_m)[32];
  real_T (*c22_ys_m)[32];
} SFc22_Experiment_2_csInstanceStruct;

#endif                                 /*typedef_SFc22_Experiment_2_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c22_Experiment_2_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c22_Experiment_2_cs_get_check_sum(mxArray *plhs[]);
extern void c22_Experiment_2_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
