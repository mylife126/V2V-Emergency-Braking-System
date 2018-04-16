#ifndef __c16_NewModuleTry_cs_h__
#define __c16_NewModuleTry_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc16_NewModuleTry_csInstanceStruct
#define typedef_SFc16_NewModuleTry_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint8_T c16_is_active_c16_NewModuleTry_cs;
  real_T (*c16_pvp)[2];
  real_T *c16_alpha;
  real_T (*c16_pref)[2];
  real_T (*c16_p0)[2];
} SFc16_NewModuleTry_csInstanceStruct;

#endif                                 /*typedef_SFc16_NewModuleTry_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c16_NewModuleTry_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c16_NewModuleTry_cs_get_check_sum(mxArray *plhs[]);
extern void c16_NewModuleTry_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
