#ifndef __c51_Experiment_cs_h__
#define __c51_Experiment_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc51_Experiment_csInstanceStruct
#define typedef_SFc51_Experiment_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c51_sfEvent;
  boolean_T c51_isStable;
  boolean_T c51_doneDoubleBufferReInit;
  uint8_T c51_is_active_c51_Experiment_cs;
  real_T c51_TISdet;
  real_T c51_TISMaxRange;
  real_T (*c51_r)[32];
  real_T (*c51_yp2)[32];
  real_T (*c51_yp1)[32];
  real_T (*c51_K1)[1600];
  real_T (*c51_K2)[1600];
} SFc51_Experiment_csInstanceStruct;

#endif                                 /*typedef_SFc51_Experiment_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c51_Experiment_cs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c51_Experiment_cs_get_check_sum(mxArray *plhs[]);
extern void c51_Experiment_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
