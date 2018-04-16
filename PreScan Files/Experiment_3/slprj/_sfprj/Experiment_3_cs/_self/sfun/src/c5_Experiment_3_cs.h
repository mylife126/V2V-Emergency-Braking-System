#ifndef __c5_Experiment_3_cs_h__
#define __c5_Experiment_3_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc5_Experiment_3_csInstanceStruct
#define typedef_SFc5_Experiment_3_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint8_T c5_is_active_c5_Experiment_3_cs;
  real_T (*c5_pvp)[2];
  real_T *c5_alpha;
  real_T (*c5_pref)[2];
  real_T (*c5_p0)[2];
} SFc5_Experiment_3_csInstanceStruct;

#endif                                 /*typedef_SFc5_Experiment_3_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_Experiment_3_cs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_Experiment_3_cs_get_check_sum(mxArray *plhs[]);
extern void c5_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
