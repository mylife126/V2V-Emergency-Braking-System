#ifndef __c50_Experiment_cs_h__
#define __c50_Experiment_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc50_Experiment_csInstanceStruct
#define typedef_SFc50_Experiment_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c50_sfEvent;
  boolean_T c50_isStable;
  boolean_T c50_doneDoubleBufferReInit;
  uint8_T c50_is_active_c50_Experiment_cs;
  uint8_T c50_im[187500];
  uint8_T c50_sub_im_data[187500];
  uint8_T c50_x_data[187500];
  uint8_T c50_tmp_data[187500];
  uint8_T c50_y_data[187500];
  uint8_T c50_inData_data[187500];
  uint8_T c50_inData[187500];
  uint8_T (*c50_b_im)[187500];
  real_T (*c50_PosObj)[64];
  real_T (*c50_X)[32];
  real_T (*c50_Y)[32];
  uint8_T (*c50_b_sub_im_data)[187500];
  int32_T (*c50_sub_im_sizes)[2];
  real_T (*c50_posObj_subim)[64];
  real_T *c50_im_x;
  real_T *c50_im_y;
  real_T *c50_liminf_x;
  real_T *c50_liminf_y;
  real_T (*c50_rectangle)[4];
} SFc50_Experiment_csInstanceStruct;

#endif                                 /*typedef_SFc50_Experiment_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c50_Experiment_cs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c50_Experiment_cs_get_check_sum(mxArray *plhs[]);
extern void c50_Experiment_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
