#ifndef __c27_Experiment_1_cs_h__
#define __c27_Experiment_1_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc27_Experiment_1_csInstanceStruct
#define typedef_SFc27_Experiment_1_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c27_sfEvent;
  boolean_T c27_isStable;
  boolean_T c27_doneDoubleBufferReInit;
  uint8_T c27_is_active_c27_Experiment_1_cs;
  uint8_T c27_im[187500];
  uint8_T c27_sub_im_data[187500];
  uint8_T c27_x_data[187500];
  uint8_T c27_tmp_data[187500];
  uint8_T c27_y_data[187500];
  uint8_T c27_inData_data[187500];
  uint8_T c27_inData[187500];
  uint8_T (*c27_b_im)[187500];
  real_T (*c27_PosObj)[64];
  real_T (*c27_X)[32];
  real_T (*c27_Y)[32];
  uint8_T (*c27_b_sub_im_data)[187500];
  int32_T (*c27_sub_im_sizes)[2];
  real_T (*c27_posObj_subim)[64];
  real_T *c27_im_x;
  real_T *c27_im_y;
  real_T *c27_liminf_x;
  real_T *c27_liminf_y;
  real_T (*c27_rectangle)[4];
} SFc27_Experiment_1_csInstanceStruct;

#endif                                 /*typedef_SFc27_Experiment_1_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c27_Experiment_1_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c27_Experiment_1_cs_get_check_sum(mxArray *plhs[]);
extern void c27_Experiment_1_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
