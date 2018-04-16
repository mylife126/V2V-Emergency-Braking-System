#ifndef __c5_Experiment_2_cs_h__
#define __c5_Experiment_2_cs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_PRESCAN_V2X_USER_GENERIC_DATA_tag
#define struct_PRESCAN_V2X_USER_GENERIC_DATA_tag

struct PRESCAN_V2X_USER_GENERIC_DATA_tag
{
  int32_T messageID;
  int32_T senderID;
  real_T signal_1;
  real_T signal_2;
  real_T signal_3;
  real_T signal_4;
  real_T signal_5;
  real_T signal_6;
  real_T signal_7;
  real_T signal_8;
  real_T signal_9;
  real_T signal_10;
  int32_T discrete_signal_1;
  int32_T discrete_signal_2;
};

#endif                                 /*struct_PRESCAN_V2X_USER_GENERIC_DATA_tag*/

#ifndef typedef_c5_PRESCAN_V2X_USER_GENERIC_DATA
#define typedef_c5_PRESCAN_V2X_USER_GENERIC_DATA

typedef struct PRESCAN_V2X_USER_GENERIC_DATA_tag
  c5_PRESCAN_V2X_USER_GENERIC_DATA;

#endif                                 /*typedef_c5_PRESCAN_V2X_USER_GENERIC_DATA*/

#ifndef struct_PRESCAN_V2X_USER_GENERIC_MESSAGE_tag
#define struct_PRESCAN_V2X_USER_GENERIC_MESSAGE_tag

struct PRESCAN_V2X_USER_GENERIC_MESSAGE_tag
{
  PRESCAN_HEADER HEADER;
  c5_PRESCAN_V2X_USER_GENERIC_DATA DATA;
};

#endif                                 /*struct_PRESCAN_V2X_USER_GENERIC_MESSAGE_tag*/

#ifndef typedef_c5_PRESCAN_V2X_USER_GENERIC_MESSAGE
#define typedef_c5_PRESCAN_V2X_USER_GENERIC_MESSAGE

typedef struct PRESCAN_V2X_USER_GENERIC_MESSAGE_tag
  c5_PRESCAN_V2X_USER_GENERIC_MESSAGE;

#endif                                 /*typedef_c5_PRESCAN_V2X_USER_GENERIC_MESSAGE*/

#ifndef typedef_SFc5_Experiment_2_csInstanceStruct
#define typedef_SFc5_Experiment_2_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c5_sfEvent;
  boolean_T c5_isStable;
  boolean_T c5_doneDoubleBufferReInit;
  uint8_T c5_is_active_c5_Experiment_2_cs;
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE *c5_u;
  c5_PRESCAN_V2X_USER_GENERIC_MESSAGE *c5_y;
  c5_PRESCAN_V2X_USER_GENERIC_MESSAGE *c5_z;
} SFc5_Experiment_2_csInstanceStruct;

#endif                                 /*typedef_SFc5_Experiment_2_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_Experiment_2_cs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_Experiment_2_cs_get_check_sum(mxArray *plhs[]);
extern void c5_Experiment_2_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
