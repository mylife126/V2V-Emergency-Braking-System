#ifndef __c37_Experiment_2_cs_h__
#define __c37_Experiment_2_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc37_Experiment_2_csInstanceStruct
#define typedef_SFc37_Experiment_2_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c37_sfEvent;
  boolean_T c37_isStable;
  boolean_T c37_doneDoubleBufferReInit;
  uint8_T c37_is_active_c37_Experiment_2_cs;
  real_T *c37_carAngle;
  real_T *c37_carVelocity;
  real_T (*c37_dTranslationX)[3];
  real_T (*c37_dopplerTX)[3];
  real_T (*c37_dopplerTY)[3];
  real_T (*c37_dTranslationY)[3];
} SFc37_Experiment_2_csInstanceStruct;

#endif                                 /*typedef_SFc37_Experiment_2_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c37_Experiment_2_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c37_Experiment_2_cs_get_check_sum(mxArray *plhs[]);
extern void c37_Experiment_2_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
