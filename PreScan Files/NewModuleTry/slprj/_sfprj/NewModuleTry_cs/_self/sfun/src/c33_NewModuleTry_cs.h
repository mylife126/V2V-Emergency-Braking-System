#ifndef __c33_NewModuleTry_cs_h__
#define __c33_NewModuleTry_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc33_NewModuleTry_csInstanceStruct
#define typedef_SFc33_NewModuleTry_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c33_sfEvent;
  boolean_T c33_isStable;
  boolean_T c33_doneDoubleBufferReInit;
  uint8_T c33_is_active_c33_NewModuleTry_cs;
  real_T *c33_carX;
  real_T *c33_pedR;
  real_T *c33_carY;
  real_T *c33_carZ;
  real_T *c33_carRotZ;
  real_T *c33_pedX;
  real_T *c33_pedY;
  real_T *c33_pedZ;
  real_T *c33_sensorCorrX;
  real_T *c33_sensorCorrY;
  real_T *c33_sensorCorrZ;
  real_T *c33_pedTheta;
  real_T *c33_pedPhi;
} SFc33_NewModuleTry_csInstanceStruct;

#endif                                 /*typedef_SFc33_NewModuleTry_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c33_NewModuleTry_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c33_NewModuleTry_cs_get_check_sum(mxArray *plhs[]);
extern void c33_NewModuleTry_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
