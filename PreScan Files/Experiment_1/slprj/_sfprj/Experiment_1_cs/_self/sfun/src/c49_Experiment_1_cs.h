#ifndef __c49_Experiment_1_cs_h__
#define __c49_Experiment_1_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc49_Experiment_1_csInstanceStruct
#define typedef_SFc49_Experiment_1_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c49_sfEvent;
  boolean_T c49_isStable;
  boolean_T c49_doneDoubleBufferReInit;
  uint8_T c49_is_active_c49_Experiment_1_cs;
  int32_T (*c49_inpoints)[400];
  int32_T (*c49_pts)[400];
} SFc49_Experiment_1_csInstanceStruct;

#endif                                 /*typedef_SFc49_Experiment_1_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c49_Experiment_1_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c49_Experiment_1_cs_get_check_sum(mxArray *plhs[]);
extern void c49_Experiment_1_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
