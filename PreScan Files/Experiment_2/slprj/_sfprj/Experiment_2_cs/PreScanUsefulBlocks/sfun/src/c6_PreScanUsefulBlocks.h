#ifndef __c6_PreScanUsefulBlocks_h__
#define __c6_PreScanUsefulBlocks_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc6_PreScanUsefulBlocksInstanceStruct
#define typedef_SFc6_PreScanUsefulBlocksInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c6_sfEvent;
  boolean_T c6_isStable;
  boolean_T c6_doneDoubleBufferReInit;
  uint8_T c6_is_active_c6_PreScanUsefulBlocks;
  PRESCAN_COLLISIONDETECTION_MESSAGE (*c6_in)[5];
  real_T (*c6_IDs)[10];
  boolean_T (*c6_Detections)[5];
} SFc6_PreScanUsefulBlocksInstanceStruct;

#endif                                 /*typedef_SFc6_PreScanUsefulBlocksInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c6_PreScanUsefulBlocks_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c6_PreScanUsefulBlocks_get_check_sum(mxArray *plhs[]);
extern void c6_PreScanUsefulBlocks_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
