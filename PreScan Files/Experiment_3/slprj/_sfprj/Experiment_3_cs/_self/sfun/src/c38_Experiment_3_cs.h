#ifndef __c38_Experiment_3_cs_h__
#define __c38_Experiment_3_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc38_Experiment_3_csInstanceStruct
#define typedef_SFc38_Experiment_3_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c38_sfEvent;
  boolean_T c38_isStable;
  boolean_T c38_doneDoubleBufferReInit;
  uint8_T c38_is_active_c38_Experiment_3_cs;
  real_T *c38_carAngle;
  real_T *c38_carVelocity;
  real_T (*c38_dTranslationX)[5];
  real_T (*c38_dopplerTX)[5];
  real_T (*c38_dopplerTY)[5];
  real_T (*c38_dTranslationY)[5];
} SFc38_Experiment_3_csInstanceStruct;

#endif                                 /*typedef_SFc38_Experiment_3_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c38_Experiment_3_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c38_Experiment_3_cs_get_check_sum(mxArray *plhs[]);
extern void c38_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
