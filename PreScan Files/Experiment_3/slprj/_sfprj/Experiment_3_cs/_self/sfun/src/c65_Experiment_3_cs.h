#ifndef __c65_Experiment_3_cs_h__
#define __c65_Experiment_3_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc65_Experiment_3_csInstanceStruct
#define typedef_SFc65_Experiment_3_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c65_sfEvent;
  boolean_T c65_isStable;
  boolean_T c65_doneDoubleBufferReInit;
  uint8_T c65_is_active_c65_Experiment_3_cs;
  real_T *c65_carX;
  real_T (*c65_dopplerVelocity)[5];
  real_T *c65_carY;
  real_T *c65_carZ;
  real_T *c65_carAngle;
  real_T *c65_carVelocity;
  real_T (*c65_pedX)[5];
  real_T (*c65_pedY)[5];
  real_T *c65_pedZ;
  real_T (*c65_dTranslationX)[5];
  real_T (*c65_dTranslationY)[5];
  real_T *c65_dTranslationZ;
  real_T *c65_sensorX;
  real_T *c65_sensorY;
  real_T *c65_sensorZ;
} SFc65_Experiment_3_csInstanceStruct;

#endif                                 /*typedef_SFc65_Experiment_3_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c65_Experiment_3_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c65_Experiment_3_cs_get_check_sum(mxArray *plhs[]);
extern void c65_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
