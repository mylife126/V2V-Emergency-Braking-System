#ifndef __c51_Experiment_1_cs_h__
#define __c51_Experiment_1_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc51_Experiment_1_csInstanceStruct
#define typedef_SFc51_Experiment_1_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c51_sfEvent;
  boolean_T c51_isStable;
  boolean_T c51_doneDoubleBufferReInit;
  uint8_T c51_is_active_c51_Experiment_1_cs;
  real_T c51_tmp_data[1002001];
  real_T c51_sub_im_data[187500];
  real32_T c51_blob_subim_proces[187500];
  real32_T c51_b_sub_im_data[187500];
  real_T c51_inData_data[187500];
  real_T c51_u_data[187500];
  real32_T c51_y[187500];
  real32_T c51_fv1[187500];
  real32_T c51_inData[187500];
  real32_T c51_u[187500];
  real32_T c51_fv0[187500];
  real32_T c51_b_u[187500];
  real32_T (*c51_b_blob_subim_proces)[187500];
  real_T (*c51_c_sub_im_data)[187500];
  int32_T (*c51_sub_im_sizes)[2];
  real_T *c51_limx_inf;
  real_T *c51_limy_inf;
  real_T *c51_im_x;
  real_T *c51_im_y;
} SFc51_Experiment_1_csInstanceStruct;

#endif                                 /*typedef_SFc51_Experiment_1_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c51_Experiment_1_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c51_Experiment_1_cs_get_check_sum(mxArray *plhs[]);
extern void c51_Experiment_1_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
