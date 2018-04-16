#ifndef __c23_NewModuleTry_cs_h__
#define __c23_NewModuleTry_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc23_NewModuleTry_csInstanceStruct
#define typedef_SFc23_NewModuleTry_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c23_sfEvent;
  boolean_T c23_isStable;
  boolean_T c23_doneDoubleBufferReInit;
  uint8_T c23_is_active_c23_NewModuleTry_cs;
  real_T c23_im_data[187500];
  real_T c23_tmp_data[187500];
  real_T c23_y_data[187500];
  real_T c23_b_tmp_data[187500];
  real_T c23_inData_data[187500];
  real_T c23_u_data[187500];
  real_T c23_c_tmp_data[187500];
  real_T c23_b_u_data[187500];
  boolean_T c23_b_inData_data[187500];
  real_T (*c23_b_im_data)[187500];
  int32_T (*c23_im_sizes)[2];
  boolean_T (*c23_image_data)[187500];
  int32_T (*c23_image_sizes)[2];
} SFc23_NewModuleTry_csInstanceStruct;

#endif                                 /*typedef_SFc23_NewModuleTry_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c23_NewModuleTry_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c23_NewModuleTry_cs_get_check_sum(mxArray *plhs[]);
extern void c23_NewModuleTry_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
