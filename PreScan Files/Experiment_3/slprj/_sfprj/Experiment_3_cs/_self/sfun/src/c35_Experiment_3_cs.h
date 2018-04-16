#ifndef __c35_Experiment_3_cs_h__
#define __c35_Experiment_3_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc35_Experiment_3_csInstanceStruct
#define typedef_SFc35_Experiment_3_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c35_sfEvent;
  boolean_T c35_isStable;
  boolean_T c35_doneDoubleBufferReInit;
  uint8_T c35_is_active_c35_Experiment_3_cs;
  real_T c35_TISdet;
  real_T c35_TISMaxRange;
  real_T (*c35_r)[32];
  real_T (*c35_th1)[32];
  real_T (*c35_th2)[32];
  real_T (*c35_thd)[32];
  real_T *c35_time;
  real_T (*c35_K1)[640];
  real_T (*c35_K2)[640];
} SFc35_Experiment_3_csInstanceStruct;

#endif                                 /*typedef_SFc35_Experiment_3_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c35_Experiment_3_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c35_Experiment_3_cs_get_check_sum(mxArray *plhs[]);
extern void c35_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
