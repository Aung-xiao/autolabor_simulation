//
// File: current_state_convert.h
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
#ifndef RTW_HEADER_current_state_convert_h_
#define RTW_HEADER_current_state_convert_h_
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "ros_code_types.h"

// Block signals for system '<Root>/current_state_convert'
struct B_current_state_convert_ros_c_T {
  real_T eulZYX[3];
  real_T aSinInput;
  real_T d_data;
  real_T x_data;
  real_T b_b;
  real_T y_idx_0;
  real_T y_idx_1;
  real_T y_idx_2;
};

extern void ros_code_current_state_convert(const
  SL_Bus_ros_code_nav_msgs_Odometry *rtu_current_odom, real_T
  rty_current_state_C[5], B_current_state_convert_ros_c_T *localB);

#endif                                 // RTW_HEADER_current_state_convert_h_

//
// File trailer for generated code.
//
// [EOF]
//
