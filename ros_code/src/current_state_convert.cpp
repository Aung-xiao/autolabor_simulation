//
// File: current_state_convert.cpp
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
#include "ros_code_types.h"
#include "rtwtypes.h"
#include "current_state_convert.h"
#include <cmath>
#include "ros_code_private.h"
#include "ros_code.h"

// Forward declaration for local functions
static void ros_code_binary_expand_op_fd(real_T in1[3], const int8_T in2_data[],
  const real_T in3_data[], const int32_T *in3_size, const real_T in4_data[],
  const int32_T *in4_size);
static void ros_code_binary_expand_op_fd(real_T in1[3], const int8_T in2_data[],
  const real_T in3_data[], const int32_T *in3_size, const real_T in4_data[],
  const int32_T *in4_size)
{
  int32_T loop_ub;

  // MATLAB Function: '<S7>/MATLAB Function'
  loop_ub = *in4_size == 1 ? *in3_size : *in4_size;
  for (int32_T i{0}; i < loop_ub; i++) {
    in1[in2_data[0] - 1] = -in3_data[0] * 2.0 * in4_data[0];
  }

  // End of MATLAB Function: '<S7>/MATLAB Function'
}

// Output and update for atomic system: '<Root>/current_state_convert'
void ros_code_current_state_convert(const SL_Bus_ros_code_nav_msgs_Odometry
  *rtu_current_odom, real_T rty_current_state_C[5],
  B_current_state_convert_ros_c_T *localB)
{
  real_T eulZYX_tmp;
  real_T eulZYX_tmp_0;
  real_T eulZYX_tmp_1;
  real_T eulZYX_tmp_2;
  int32_T d_size;
  int32_T k;
  int32_T trueCount;
  int8_T g_data;
  boolean_T mask1;
  boolean_T mask2;

  // MATLAB Function: '<S7>/MATLAB Function'
  localB->b_b = 1.0 / std::sqrt(((rtu_current_odom->Pose.Pose.Orientation.X *
    rtu_current_odom->Pose.Pose.Orientation.X +
    rtu_current_odom->Pose.Pose.Orientation.Y *
    rtu_current_odom->Pose.Pose.Orientation.Y) +
    rtu_current_odom->Pose.Pose.Orientation.Z *
    rtu_current_odom->Pose.Pose.Orientation.Z) +
    rtu_current_odom->Pose.Pose.Orientation.W *
    rtu_current_odom->Pose.Pose.Orientation.W);
  localB->y_idx_0 = rtu_current_odom->Pose.Pose.Orientation.X * localB->b_b;
  localB->y_idx_1 = rtu_current_odom->Pose.Pose.Orientation.Y * localB->b_b;
  localB->y_idx_2 = rtu_current_odom->Pose.Pose.Orientation.Z * localB->b_b;
  localB->b_b *= rtu_current_odom->Pose.Pose.Orientation.W;
  localB->aSinInput = (localB->y_idx_1 * localB->b_b - localB->y_idx_0 *
                       localB->y_idx_2) * -2.0;
  mask1 = (localB->aSinInput >= 0.99999999999999778);
  mask2 = (localB->aSinInput <= -0.99999999999999778);
  if (localB->aSinInput >= 0.99999999999999778) {
    localB->aSinInput = 1.0;
  }

  if (mask2) {
    localB->aSinInput = -1.0;
  }

  eulZYX_tmp = localB->y_idx_0 * localB->y_idx_0;
  eulZYX_tmp_0 = localB->y_idx_1 * localB->y_idx_1;
  eulZYX_tmp_1 = localB->y_idx_2 * localB->y_idx_2;
  eulZYX_tmp_2 = localB->b_b * localB->b_b;
  localB->eulZYX[0] = rt_atan2d_snf((localB->y_idx_1 * localB->y_idx_2 +
    localB->y_idx_0 * localB->b_b) * 2.0, ((eulZYX_tmp + eulZYX_tmp_0) -
    eulZYX_tmp_1) - eulZYX_tmp_2);
  localB->eulZYX[1] = std::asin(localB->aSinInput);
  localB->eulZYX[2] = rt_atan2d_snf((localB->y_idx_2 * localB->b_b +
    localB->y_idx_0 * localB->y_idx_1) * 2.0, ((eulZYX_tmp - eulZYX_tmp_0) -
    eulZYX_tmp_1) + eulZYX_tmp_2);
  trueCount = 0;
  if (mask1 || mask2) {
    trueCount = 1;
  }

  if (trueCount - 1 >= 0) {
    localB->x_data = localB->aSinInput;
  }

  k = 0;
  while (k <= trueCount - 1) {
    if (!std::isnan(localB->x_data)) {
      if (localB->x_data < 0.0) {
        localB->x_data = -1.0;
      } else {
        localB->x_data = (localB->x_data > 0.0);
      }
    }

    k = 1;
  }

  k = 0;
  if (mask1 || mask2) {
    k = 1;
  }

  d_size = static_cast<int8_T>(k);
  if (static_cast<int8_T>(k) - 1 >= 0) {
    localB->d_data = rt_atan2d_snf(localB->y_idx_1, localB->y_idx_0);
  }

  if (mask1 || mask2) {
    g_data = 1;
  }

  if (trueCount != static_cast<int8_T>(k)) {
    ros_code_binary_expand_op_fd(localB->eulZYX, &g_data, &localB->x_data,
      &trueCount, &localB->d_data, &d_size);
  }

  trueCount = 0;
  if (mask1 || mask2) {
    trueCount = 1;
  }

  if (trueCount - 1 >= 0) {
    localB->eulZYX[2] = 0.0;
  }

  rty_current_state_C[0] = rtu_current_odom->Pose.Pose.Position.X;
  rty_current_state_C[1] = rtu_current_odom->Pose.Pose.Position.Y;
  rty_current_state_C[2] = localB->eulZYX[2];
  rty_current_state_C[3] = std::sqrt(rtu_current_odom->Twist.Twist.Linear.X *
    rtu_current_odom->Twist.Twist.Linear.X +
    rtu_current_odom->Twist.Twist.Linear.Y *
    rtu_current_odom->Twist.Twist.Linear.Y);
  rty_current_state_C[4] = rtu_current_odom->Twist.Twist.Angular.Z;

  // End of MATLAB Function: '<S7>/MATLAB Function'
}

//
// File trailer for generated code.
//
// [EOF]
//
