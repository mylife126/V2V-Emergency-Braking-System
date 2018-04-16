#ifndef __c27_Experiment_3_cs_h__
#define __c27_Experiment_3_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc27_Experiment_3_csInstanceStruct
#define typedef_SFc27_Experiment_3_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c27_sfEvent;
  boolean_T c27_isStable;
  boolean_T c27_doneDoubleBufferReInit;
  uint8_T c27_is_active_c27_Experiment_3_cs;
  real_T c27_TISdet;
  real_T c27_TISMaxRange;
  boolean_T (*c27_flag)[32];
  real_T (*c27_theta)[32];
  real_T (*c27_posit)[64];
  real_T (*c27_range)[32];
  real_T (*c27_xs_m)[32];
  real_T (*c27_ys_m)[32];
} SFc27_Experiment_3_csInstanceStruct;

#endif                                 /*typedef_SFc27_Experiment_3_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c27_Experiment_3_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c27_Experiment_3_cs_get_check_sum(mxArray *plhs[]);
extern void c27_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
