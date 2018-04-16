#ifndef __c3_Experiment_cs_h__
#define __c3_Experiment_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_Experiment_csInstanceStruct
#define typedef_SFc3_Experiment_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  boolean_T c3_isStable;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_Experiment_cs;
  int32_T (*c3_inpoints)[400];
  int32_T (*c3_pts)[400];
} SFc3_Experiment_csInstanceStruct;

#endif                                 /*typedef_SFc3_Experiment_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_Experiment_cs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_Experiment_cs_get_check_sum(mxArray *plhs[]);
extern void c3_Experiment_cs_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
