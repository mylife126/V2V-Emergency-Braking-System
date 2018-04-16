#ifndef __c44_Experiment_cs_h__
#define __c44_Experiment_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc44_Experiment_csInstanceStruct
#define typedef_SFc44_Experiment_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c44_sfEvent;
  boolean_T c44_isStable;
  boolean_T c44_doneDoubleBufferReInit;
  uint8_T c44_is_active_c44_Experiment_cs;
  real_T c44_tmp_data[1002001];
  real_T c44_sub_im_data[187500];
  real32_T c44_blob_subim_proces[187500];
  real32_T c44_b_sub_im_data[187500];
  real_T c44_inData_data[187500];
  real_T c44_u_data[187500];
  real32_T c44_y[187500];
  real32_T c44_fv1[187500];
  real32_T c44_inData[187500];
  real32_T c44_u[187500];
  real32_T c44_fv0[187500];
  real32_T c44_b_u[187500];
  real32_T (*c44_b_blob_subim_proces)[187500];
  real_T (*c44_c_sub_im_data)[187500];
  int32_T (*c44_sub_im_sizes)[2];
  real_T *c44_limx_inf;
  real_T *c44_limy_inf;
  real_T *c44_im_x;
  real_T *c44_im_y;
} SFc44_Experiment_csInstanceStruct;

#endif                                 /*typedef_SFc44_Experiment_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c44_Experiment_cs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c44_Experiment_cs_get_check_sum(mxArray *plhs[]);
extern void c44_Experiment_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
