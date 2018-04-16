#ifndef __c29_Experiment_3_cs_h__
#define __c29_Experiment_3_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc29_Experiment_3_csInstanceStruct
#define typedef_SFc29_Experiment_3_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c29_sfEvent;
  boolean_T c29_isStable;
  boolean_T c29_doneDoubleBufferReInit;
  uint8_T c29_is_active_c29_Experiment_3_cs;
  real_T c29_tmp_data[1002001];
  real_T c29_sub_im_data[187500];
  real32_T c29_blob_subim_proces[187500];
  real32_T c29_b_sub_im_data[187500];
  real_T c29_inData_data[187500];
  real_T c29_u_data[187500];
  real32_T c29_y[187500];
  real32_T c29_fv1[187500];
  real32_T c29_inData[187500];
  real32_T c29_u[187500];
  real32_T c29_fv0[187500];
  real32_T c29_b_u[187500];
  real32_T (*c29_b_blob_subim_proces)[187500];
  real_T (*c29_c_sub_im_data)[187500];
  int32_T (*c29_sub_im_sizes)[2];
  real_T *c29_limx_inf;
  real_T *c29_limy_inf;
  real_T *c29_im_x;
  real_T *c29_im_y;
} SFc29_Experiment_3_csInstanceStruct;

#endif                                 /*typedef_SFc29_Experiment_3_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c29_Experiment_3_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c29_Experiment_3_cs_get_check_sum(mxArray *plhs[]);
extern void c29_Experiment_3_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
