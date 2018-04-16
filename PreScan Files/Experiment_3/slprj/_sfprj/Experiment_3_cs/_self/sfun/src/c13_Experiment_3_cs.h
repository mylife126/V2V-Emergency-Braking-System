#ifndef __c13_Experiment_3_cs_h__
#define __c13_Experiment_3_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc13_Experiment_3_csInstanceStruct
#define typedef_SFc13_Experiment_3_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c13_sfEvent;
  boolean_T c13_isStable;
  boolean_T c13_doneDoubleBufferReInit;
  uint8_T c13_is_active_c13_Experiment_3_cs;
  int32_T (*c13_inpoints)[4];
  int32_T (*c13_pts)[4];
} SFc13_Experiment_3_csInstanceStruct;

#endif                                 /*typedef_SFc13_Experiment_3_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c13_Experiment_3_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c13_Experiment_3_cs_get_check_sum(mxArray *plhs[]);
extern void c13_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
