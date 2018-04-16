#ifndef __c53_Experiment_cs_h__
#define __c53_Experiment_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc53_Experiment_csInstanceStruct
#define typedef_SFc53_Experiment_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c53_sfEvent;
  boolean_T c53_isStable;
  boolean_T c53_doneDoubleBufferReInit;
  uint8_T c53_is_active_c53_Experiment_cs;
  real_T c53_TISdet;
  real_T (*c53_th)[32];
  real_T (*c53_thp)[32];
  real_T (*c53_thd)[32];
  real_T (*c53_th_dot)[32];
} SFc53_Experiment_csInstanceStruct;

#endif                                 /*typedef_SFc53_Experiment_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c53_Experiment_cs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c53_Experiment_cs_get_check_sum(mxArray *plhs[]);
extern void c53_Experiment_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
