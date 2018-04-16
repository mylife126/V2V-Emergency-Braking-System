#ifndef __c30_NewModuleTry_cs_h__
#define __c30_NewModuleTry_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc30_NewModuleTry_csInstanceStruct
#define typedef_SFc30_NewModuleTry_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c30_sfEvent;
  boolean_T c30_isStable;
  boolean_T c30_doneDoubleBufferReInit;
  uint8_T c30_is_active_c30_NewModuleTry_cs;
  real_T c30_TISdet;
  real_T (*c30_th)[32];
  real_T (*c30_thp)[32];
  real_T (*c30_thd)[32];
  real_T (*c30_th_dot)[32];
} SFc30_NewModuleTry_csInstanceStruct;

#endif                                 /*typedef_SFc30_NewModuleTry_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c30_NewModuleTry_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c30_NewModuleTry_cs_get_check_sum(mxArray *plhs[]);
extern void c30_NewModuleTry_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
