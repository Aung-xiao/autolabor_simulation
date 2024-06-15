//
// File: ros_code_private.h
//
// Code generated for Simulink model 'ros_code'.
//
// Model version                  : 1.5985
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sat Jun 15 16:21:52 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ros_code_private_h_
#define RTW_HEADER_ros_code_private_h_
#include "rtwtypes.h"
#include "ros_code.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T rt_hypotd_snf(real_T u0, real_T u1);
extern int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator);

#endif                                 // RTW_HEADER_ros_code_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
