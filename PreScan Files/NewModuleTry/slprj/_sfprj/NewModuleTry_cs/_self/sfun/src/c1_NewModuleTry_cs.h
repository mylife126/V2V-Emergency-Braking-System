#ifndef __c1_NewModuleTry_cs_h__
#define __c1_NewModuleTry_cs_h__

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
};

#endif                                 /*struct_PRESCAN_V2X_USER_GENERIC_DATA_tag*/

#ifndef typedef_c1_PRESCAN_V2X_USER_GENERIC_DATA
#define typedef_c1_PRESCAN_V2X_USER_GENERIC_DATA

typedef struct PRESCAN_V2X_USER_GENERIC_DATA_tag
  c1_PRESCAN_V2X_USER_GENERIC_DATA;

#endif                                 /*typedef_c1_PRESCAN_V2X_USER_GENERIC_DATA*/

#ifndef struct_PRESCAN_V2X_USER_GENERIC_MESSAGE_tag
#define struct_PRESCAN_V2X_USER_GENERIC_MESSAGE_tag

struct PRESCAN_V2X_USER_GENERIC_MESSAGE_tag
{
  PRESCAN_HEADER HEADER;
  c1_PRESCAN_V2X_USER_GENERIC_DATA DATA;
};

#endif                                 /*struct_PRESCAN_V2X_USER_GENERIC_MESSAGE_tag*/

#ifndef typedef_c1_PRESCAN_V2X_USER_GENERIC_MESSAGE
#define typedef_c1_PRESCAN_V2X_USER_GENERIC_MESSAGE

typedef struct PRESCAN_V2X_USER_GENERIC_MESSAGE_tag
  c1_PRESCAN_V2X_USER_GENERIC_MESSAGE;

#endif                                 /*typedef_c1_PRESCAN_V2X_USER_GENERIC_MESSAGE*/

#ifndef typedef_SFc1_NewModuleTry_csInstanceStruct
#define typedef_SFc1_NewModuleTry_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_isStable;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_NewModuleTry_cs;
  c1_PRESCAN_V2X_USER_GENERIC_MESSAGE *c1_u;
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE *c1_y;
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE *c1_z;
} SFc1_NewModuleTry_csInstanceStruct;

#endif                                 /*typedef_SFc1_NewModuleTry_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_NewModuleTry_cs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_NewModuleTry_cs_get_check_sum(mxArray *plhs[]);
extern void c1_NewModuleTry_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
