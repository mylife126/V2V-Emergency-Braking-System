#ifndef __c39_Experiment_1_cs_h__
#define __c39_Experiment_1_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc39_Experiment_1_csInstanceStruct
#define typedef_SFc39_Experiment_1_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c39_sfEvent;
  boolean_T c39_isStable;
  boolean_T c39_doneDoubleBufferReInit;
  uint8_T c39_is_active_c39_Experiment_1_cs;
  real_T c39_TISdet;
  real_T *c39_v;
  real_T (*c39_xpd)[32];
  real_T (*c39_xp_dot)[32];
} SFc39_Experiment_1_csInstanceStruct;

#endif                                 /*typedef_SFc39_Experiment_1_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c39_Experiment_1_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c39_Experiment_1_cs_get_check_sum(mxArray *plhs[]);
extern void c39_Experiment_1_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
