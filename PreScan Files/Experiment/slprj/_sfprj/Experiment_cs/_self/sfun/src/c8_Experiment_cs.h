#ifndef __c8_Experiment_cs_h__
#define __c8_Experiment_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc8_Experiment_csInstanceStruct
#define typedef_SFc8_Experiment_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c8_sfEvent;
  boolean_T c8_isStable;
  boolean_T c8_doneDoubleBufferReInit;
  uint8_T c8_is_active_c8_Experiment_cs;
  real_T c8_TISdet;
  real_T c8_TISMaxRange;
  boolean_T (*c8_flag)[32];
  real_T (*c8_theta)[32];
  real_T (*c8_posit)[64];
  real_T (*c8_range)[32];
  real_T (*c8_xs_m)[32];
  real_T (*c8_ys_m)[32];
} SFc8_Experiment_csInstanceStruct;

#endif                                 /*typedef_SFc8_Experiment_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c8_Experiment_cs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c8_Experiment_cs_get_check_sum(mxArray *plhs[]);
extern void c8_Experiment_cs_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
