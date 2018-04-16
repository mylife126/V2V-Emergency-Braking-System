#ifndef __c37_Experiment_1_cs_h__
#define __c37_Experiment_1_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc37_Experiment_1_csInstanceStruct
#define typedef_SFc37_Experiment_1_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c37_sfEvent;
  boolean_T c37_isStable;
  boolean_T c37_doneDoubleBufferReInit;
  uint8_T c37_is_active_c37_Experiment_1_cs;
  uint8_T c37_im[187500];
  uint8_T c37_sub_im_data[187500];
  uint8_T c37_x_data[187500];
  uint8_T c37_tmp_data[187500];
  uint8_T c37_y_data[187500];
  uint8_T c37_inData_data[187500];
  uint8_T c37_inData[187500];
  uint8_T (*c37_b_im)[187500];
  real_T (*c37_PosObj)[64];
  real_T (*c37_X)[32];
  real_T (*c37_Y)[32];
  uint8_T (*c37_b_sub_im_data)[187500];
  int32_T (*c37_sub_im_sizes)[2];
  real_T (*c37_posObj_subim)[64];
  real_T *c37_im_x;
  real_T *c37_im_y;
  real_T *c37_liminf_x;
  real_T *c37_liminf_y;
  real_T (*c37_rectangle)[4];
} SFc37_Experiment_1_csInstanceStruct;

#endif                                 /*typedef_SFc37_Experiment_1_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c37_Experiment_1_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c37_Experiment_1_cs_get_check_sum(mxArray *plhs[]);
extern void c37_Experiment_1_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
