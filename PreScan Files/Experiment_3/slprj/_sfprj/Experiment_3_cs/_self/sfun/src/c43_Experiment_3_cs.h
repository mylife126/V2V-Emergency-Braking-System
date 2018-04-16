#ifndef __c43_Experiment_3_cs_h__
#define __c43_Experiment_3_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc43_Experiment_3_csInstanceStruct
#define typedef_SFc43_Experiment_3_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c43_sfEvent;
  boolean_T c43_isStable;
  boolean_T c43_doneDoubleBufferReInit;
  uint8_T c43_is_active_c43_Experiment_3_cs;
  real_T c43_TISdet[2];
  real_T c43_TISMaxRange[2];
  real_T (*c43_r)[32];
  real_T (*c43_yp2)[32];
  real_T (*c43_yp1)[32];
  real_T (*c43_K1)[1600];
  real_T (*c43_K2)[1600];
} SFc43_Experiment_3_csInstanceStruct;

#endif                                 /*typedef_SFc43_Experiment_3_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c43_Experiment_3_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c43_Experiment_3_cs_get_check_sum(mxArray *plhs[]);
extern void c43_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
