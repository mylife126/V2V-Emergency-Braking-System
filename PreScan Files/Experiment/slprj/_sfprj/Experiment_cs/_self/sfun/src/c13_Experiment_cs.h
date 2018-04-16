#ifndef __c13_Experiment_cs_h__
#define __c13_Experiment_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc13_Experiment_csInstanceStruct
#define typedef_SFc13_Experiment_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c13_sfEvent;
  boolean_T c13_isStable;
  boolean_T c13_doneDoubleBufferReInit;
  uint8_T c13_is_active_c13_Experiment_cs;
  uint8_T c13_im[187500];
  uint8_T c13_sub_im_data[187500];
  uint8_T c13_x_data[187500];
  uint8_T c13_tmp_data[187500];
  uint8_T c13_y_data[187500];
  uint8_T c13_inData_data[187500];
  uint8_T c13_inData[187500];
  uint8_T (*c13_b_im)[187500];
  real_T (*c13_PosObj)[64];
  real_T (*c13_X)[32];
  real_T (*c13_Y)[32];
  uint8_T (*c13_b_sub_im_data)[187500];
  int32_T (*c13_sub_im_sizes)[2];
  real_T (*c13_posObj_subim)[64];
  real_T *c13_im_x;
  real_T *c13_im_y;
  real_T *c13_liminf_x;
  real_T *c13_liminf_y;
  real_T (*c13_rectangle)[4];
} SFc13_Experiment_csInstanceStruct;

#endif                                 /*typedef_SFc13_Experiment_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c13_Experiment_cs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c13_Experiment_cs_get_check_sum(mxArray *plhs[]);
extern void c13_Experiment_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
