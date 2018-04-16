#ifndef __c31_NewModuleTry_cs_h__
#define __c31_NewModuleTry_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc31_NewModuleTry_csInstanceStruct
#define typedef_SFc31_NewModuleTry_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c31_sfEvent;
  boolean_T c31_isStable;
  boolean_T c31_doneDoubleBufferReInit;
  uint8_T c31_is_active_c31_NewModuleTry_cs;
  real_T c31_TISdet;
  real_T c31_TISMaxRange;
  real_T (*c31_r)[32];
  real_T (*c31_th1)[32];
  real_T (*c31_th2)[32];
  real_T (*c31_thd)[32];
  real_T *c31_time;
  real_T (*c31_K1)[640];
  real_T (*c31_K2)[640];
} SFc31_NewModuleTry_csInstanceStruct;

#endif                                 /*typedef_SFc31_NewModuleTry_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c31_NewModuleTry_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c31_NewModuleTry_cs_get_check_sum(mxArray *plhs[]);
extern void c31_NewModuleTry_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
