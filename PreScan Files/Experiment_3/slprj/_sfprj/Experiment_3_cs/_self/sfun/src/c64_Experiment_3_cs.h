#ifndef __c64_Experiment_3_cs_h__
#define __c64_Experiment_3_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc64_Experiment_3_csInstanceStruct
#define typedef_SFc64_Experiment_3_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c64_sfEvent;
  boolean_T c64_isStable;
  boolean_T c64_doneDoubleBufferReInit;
  uint8_T c64_is_active_c64_Experiment_3_cs;
  real_T (*c64_pedR_self)[5];
  real_T (*c64_pedR_Array)[32];
  real_T (*c64_pedTheta_self)[5];
  real_T (*c64_dVel_self)[5];
  real_T (*c64_pedTheta_Array)[32];
  real_T (*c64_dVel_Array)[32];
  real_T (*c64_pedR_rcvd)[5];
  real_T (*c64_pedTheta_rcvd)[5];
  real_T (*c64_dVel_rcvd)[5];
} SFc64_Experiment_3_csInstanceStruct;

#endif                                 /*typedef_SFc64_Experiment_3_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c64_Experiment_3_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c64_Experiment_3_cs_get_check_sum(mxArray *plhs[]);
extern void c64_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
