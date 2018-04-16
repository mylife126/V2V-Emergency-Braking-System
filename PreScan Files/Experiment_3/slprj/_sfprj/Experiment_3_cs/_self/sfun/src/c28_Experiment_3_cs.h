#ifndef __c28_Experiment_3_cs_h__
#define __c28_Experiment_3_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc28_Experiment_3_csInstanceStruct
#define typedef_SFc28_Experiment_3_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c28_sfEvent;
  boolean_T c28_isStable;
  boolean_T c28_doneDoubleBufferReInit;
  uint8_T c28_is_active_c28_Experiment_3_cs;
  uint8_T c28_im[187500];
  uint8_T c28_sub_im_data[187500];
  uint8_T c28_x_data[187500];
  uint8_T c28_tmp_data[187500];
  uint8_T c28_y_data[187500];
  uint8_T c28_inData_data[187500];
  uint8_T c28_inData[187500];
  uint8_T (*c28_b_im)[187500];
  real_T (*c28_PosObj)[64];
  real_T (*c28_X)[32];
  real_T (*c28_Y)[32];
  uint8_T (*c28_b_sub_im_data)[187500];
  int32_T (*c28_sub_im_sizes)[2];
  real_T (*c28_posObj_subim)[64];
  real_T *c28_im_x;
  real_T *c28_im_y;
  real_T *c28_liminf_x;
  real_T *c28_liminf_y;
  real_T (*c28_rectangle)[4];
} SFc28_Experiment_3_csInstanceStruct;

#endif                                 /*typedef_SFc28_Experiment_3_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c28_Experiment_3_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c28_Experiment_3_cs_get_check_sum(mxArray *plhs[]);
extern void c28_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
