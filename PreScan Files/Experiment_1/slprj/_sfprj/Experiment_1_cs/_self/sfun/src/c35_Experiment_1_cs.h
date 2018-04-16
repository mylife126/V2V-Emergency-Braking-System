#ifndef __c35_Experiment_1_cs_h__
#define __c35_Experiment_1_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc35_Experiment_1_csInstanceStruct
#define typedef_SFc35_Experiment_1_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c35_sfEvent;
  boolean_T c35_isStable;
  boolean_T c35_doneDoubleBufferReInit;
  uint8_T c35_is_active_c35_Experiment_1_cs;
  real_T *c35_carAngle;
  real_T *c35_carVelocity;
  real_T *c35_dTranslationX;
  real_T *c35_dopplerTX;
  real_T *c35_dopplerTY;
  real_T *c35_dTranslationY;
} SFc35_Experiment_1_csInstanceStruct;

#endif                                 /*typedef_SFc35_Experiment_1_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c35_Experiment_1_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c35_Experiment_1_cs_get_check_sum(mxArray *plhs[]);
extern void c35_Experiment_1_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
