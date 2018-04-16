#ifndef __c22_NewModuleTry_cs_h__
#define __c22_NewModuleTry_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc22_NewModuleTry_csInstanceStruct
#define typedef_SFc22_NewModuleTry_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c22_sfEvent;
  boolean_T c22_isStable;
  boolean_T c22_doneDoubleBufferReInit;
  uint8_T c22_is_active_c22_NewModuleTry_cs;
  uint8_T c22_im[187500];
  uint8_T c22_sub_im_data[187500];
  uint8_T c22_x_data[187500];
  uint8_T c22_tmp_data[187500];
  uint8_T c22_y_data[187500];
  uint8_T c22_inData_data[187500];
  uint8_T c22_inData[187500];
  uint8_T (*c22_b_im)[187500];
  real_T (*c22_PosObj)[64];
  real_T (*c22_X)[32];
  real_T (*c22_Y)[32];
  uint8_T (*c22_b_sub_im_data)[187500];
  int32_T (*c22_sub_im_sizes)[2];
  real_T (*c22_posObj_subim)[64];
  real_T *c22_im_x;
  real_T *c22_im_y;
  real_T *c22_liminf_x;
  real_T *c22_liminf_y;
  real_T (*c22_rectangle)[4];
} SFc22_NewModuleTry_csInstanceStruct;

#endif                                 /*typedef_SFc22_NewModuleTry_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c22_NewModuleTry_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c22_NewModuleTry_cs_get_check_sum(mxArray *plhs[]);
extern void c22_NewModuleTry_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
