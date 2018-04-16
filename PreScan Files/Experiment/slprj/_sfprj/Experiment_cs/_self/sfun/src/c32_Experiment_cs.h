#ifndef __c32_Experiment_cs_h__
#define __c32_Experiment_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc32_Experiment_csInstanceStruct
#define typedef_SFc32_Experiment_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c32_sfEvent;
  boolean_T c32_isStable;
  boolean_T c32_doneDoubleBufferReInit;
  uint8_T c32_is_active_c32_Experiment_cs;
  int32_T (*c32_u)[400];
  int32_T (*c32_y)[200];
} SFc32_Experiment_csInstanceStruct;

#endif                                 /*typedef_SFc32_Experiment_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c32_Experiment_cs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c32_Experiment_cs_get_check_sum(mxArray *plhs[]);
extern void c32_Experiment_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
