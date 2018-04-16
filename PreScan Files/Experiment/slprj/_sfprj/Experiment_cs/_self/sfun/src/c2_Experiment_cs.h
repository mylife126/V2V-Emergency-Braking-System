#ifndef __c2_Experiment_cs_h__
#define __c2_Experiment_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_Experiment_csInstanceStruct
#define typedef_SFc2_Experiment_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint8_T c2_is_active_c2_Experiment_cs;
  real_T (*c2_pvp)[2];
  real_T *c2_alpha;
  real_T (*c2_pref)[2];
  real_T (*c2_p0)[2];
} SFc2_Experiment_csInstanceStruct;

#endif                                 /*typedef_SFc2_Experiment_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_Experiment_cs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_Experiment_cs_get_check_sum(mxArray *plhs[]);
extern void c2_Experiment_cs_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
