#ifndef __c28_NewModuleTry_cs_h__
#define __c28_NewModuleTry_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc28_NewModuleTry_csInstanceStruct
#define typedef_SFc28_NewModuleTry_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c28_sfEvent;
  boolean_T c28_isStable;
  boolean_T c28_doneDoubleBufferReInit;
  uint8_T c28_is_active_c28_NewModuleTry_cs;
  real_T c28_TISdet;
  real_T *c28_v;
  real_T (*c28_xpd)[32];
  real_T (*c28_xp_dot)[32];
} SFc28_NewModuleTry_csInstanceStruct;

#endif                                 /*typedef_SFc28_NewModuleTry_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c28_NewModuleTry_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c28_NewModuleTry_cs_get_check_sum(mxArray *plhs[]);
extern void c28_NewModuleTry_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
