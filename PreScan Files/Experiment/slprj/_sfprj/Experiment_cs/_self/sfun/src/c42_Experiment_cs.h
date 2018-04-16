#ifndef __c42_Experiment_cs_h__
#define __c42_Experiment_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc42_Experiment_csInstanceStruct
#define typedef_SFc42_Experiment_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c42_sfEvent;
  boolean_T c42_isStable;
  boolean_T c42_doneDoubleBufferReInit;
  uint8_T c42_is_active_c42_Experiment_cs;
  int32_T (*c42_inpoints)[400];
  int32_T (*c42_pts)[400];
} SFc42_Experiment_csInstanceStruct;

#endif                                 /*typedef_SFc42_Experiment_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c42_Experiment_cs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c42_Experiment_cs_get_check_sum(mxArray *plhs[]);
extern void c42_Experiment_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
