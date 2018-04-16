#ifndef __c21_NewModuleTry_cs_h__
#define __c21_NewModuleTry_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc21_NewModuleTry_csInstanceStruct
#define typedef_SFc21_NewModuleTry_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c21_sfEvent;
  boolean_T c21_isStable;
  boolean_T c21_doneDoubleBufferReInit;
  uint8_T c21_is_active_c21_NewModuleTry_cs;
  real_T c21_TISdet;
  real_T c21_TISMaxRange;
  boolean_T (*c21_flag)[32];
  real_T (*c21_theta)[32];
  real_T (*c21_posit)[64];
  real_T (*c21_range)[32];
  real_T (*c21_xs_m)[32];
  real_T (*c21_ys_m)[32];
} SFc21_NewModuleTry_csInstanceStruct;

#endif                                 /*typedef_SFc21_NewModuleTry_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c21_NewModuleTry_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c21_NewModuleTry_cs_get_check_sum(mxArray *plhs[]);
extern void c21_NewModuleTry_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
