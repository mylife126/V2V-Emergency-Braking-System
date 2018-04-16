#ifndef __c18_Experiment_1_cs_h__
#define __c18_Experiment_1_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc18_Experiment_1_csInstanceStruct
#define typedef_SFc18_Experiment_1_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c18_sfEvent;
  boolean_T c18_isStable;
  boolean_T c18_doneDoubleBufferReInit;
  uint8_T c18_is_active_c18_Experiment_1_cs;
  real_T c18_tmp_data[220000];
  real_T c18_b_tmp_data[220000];
  real_T c18_inData_data[220000];
  real_T c18_u_data[220000];
  real_T c18_label_out_data[220000];
  real_T c18_c_tmp_data[187500];
  uint8_T c18_label_data[187500];
  real_T c18_b_u_data[220000];
  real_T c18_y_data[220000];
  uint8_T c18_b_inData_data[187500];
  real32_T (*c18_centroid)[200];
  int32_T (*c18_centout)[200];
  int32_T (*c18_bbox)[400];
  int32_T (*c18_bboxout)[400];
  real32_T (*c18_majoraxis)[100];
  real32_T (*c18_minoraxis)[100];
  real_T (*c18_orientation)[100];
  real32_T (*c18_eccentricity)[100];
  uint8_T (*c18_b_label_data)[187500];
  int32_T (*c18_label_sizes)[2];
  real_T (*c18_b_label_out_data)[220000];
  int32_T (*c18_label_out_sizes)[2];
  real_T *c18_im_x;
  real_T *c18_im_y;
  real_T (*c18_posObj_subim)[64];
  real_T *c18_liminf_x;
  real_T *c18_liminf_y;
  real_T (*c18_posObj_im)[64];
} SFc18_Experiment_1_csInstanceStruct;

#endif                                 /*typedef_SFc18_Experiment_1_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c18_Experiment_1_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c18_Experiment_1_cs_get_check_sum(mxArray *plhs[]);
extern void c18_Experiment_1_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
