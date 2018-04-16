#ifndef __c30_Experiment_cs_h__
#define __c30_Experiment_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc30_Experiment_csInstanceStruct
#define typedef_SFc30_Experiment_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c30_sfEvent;
  boolean_T c30_isStable;
  boolean_T c30_doneDoubleBufferReInit;
  uint8_T c30_is_active_c30_Experiment_cs;
  real_T c30_tmp_data[220000];
  real_T c30_b_tmp_data[220000];
  real_T c30_inData_data[220000];
  real_T c30_u_data[220000];
  real_T c30_label_out_data[220000];
  real_T c30_c_tmp_data[187500];
  uint8_T c30_label_data[187500];
  real_T c30_b_u_data[220000];
  real_T c30_y_data[220000];
  uint8_T c30_b_inData_data[187500];
  real32_T (*c30_centroid)[200];
  int32_T (*c30_centout)[200];
  int32_T (*c30_bbox)[400];
  int32_T (*c30_bboxout)[400];
  real32_T (*c30_majoraxis)[100];
  real32_T (*c30_minoraxis)[100];
  real_T (*c30_orientation)[100];
  real32_T (*c30_eccentricity)[100];
  uint8_T (*c30_b_label_data)[187500];
  int32_T (*c30_label_sizes)[2];
  real_T (*c30_b_label_out_data)[220000];
  int32_T (*c30_label_out_sizes)[2];
  real_T *c30_im_x;
  real_T *c30_im_y;
  real_T (*c30_posObj_subim)[64];
  real_T *c30_liminf_x;
  real_T *c30_liminf_y;
  real_T (*c30_posObj_im)[64];
} SFc30_Experiment_csInstanceStruct;

#endif                                 /*typedef_SFc30_Experiment_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c30_Experiment_cs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c30_Experiment_cs_get_check_sum(mxArray *plhs[]);
extern void c30_Experiment_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
