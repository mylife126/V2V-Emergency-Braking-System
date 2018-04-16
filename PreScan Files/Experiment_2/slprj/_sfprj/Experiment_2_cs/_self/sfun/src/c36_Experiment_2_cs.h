#ifndef __c36_Experiment_2_cs_h__
#define __c36_Experiment_2_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc36_Experiment_2_csInstanceStruct
#define typedef_SFc36_Experiment_2_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c36_sfEvent;
  boolean_T c36_isStable;
  boolean_T c36_doneDoubleBufferReInit;
  uint8_T c36_is_active_c36_Experiment_2_cs;
  real_T *c36_carX;
  real_T (*c36_dopplerVelocity)[3];
  real_T *c36_carY;
  real_T *c36_carZ;
  real_T *c36_carAngle;
  real_T *c36_carVelocity;
  real_T (*c36_pedX)[3];
  real_T (*c36_pedY)[3];
  real_T *c36_pedZ;
  real_T (*c36_dTranslationX)[3];
  real_T (*c36_dTranslationY)[3];
  real_T *c36_dTranslationZ;
  real_T *c36_sensorX;
  real_T *c36_sensorY;
  real_T *c36_sensorZ;
} SFc36_Experiment_2_csInstanceStruct;

#endif                                 /*typedef_SFc36_Experiment_2_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c36_Experiment_2_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c36_Experiment_2_cs_get_check_sum(mxArray *plhs[]);
extern void c36_Experiment_2_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
