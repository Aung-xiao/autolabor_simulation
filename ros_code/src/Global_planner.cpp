//
// File: Global_planner.cpp
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
#include "rtwtypes.h"
#include "Global_planner.h"
#include <cstring>
#include <cmath>
#include <emmintrin.h>
#include "ros_code_private.h"
#include "ros_code.h"
#include "rt_defines.h"

// Forward declaration for local functions
static void ros_code_linspace(real_T d2, real_T n, real_T y_data[], int32_T
  y_size[2]);
static void ros_code_binary_expand_op_g(real_T in1[3], const int8_T in2_data[],
  const real_T in3_data[], const int32_T *in3_size, const real_T in4_data[],
  const int32_T *in4_size);
static void ros_code_quat2eul(real_T q[4], real_T eul[3],
  B_Global_planner_ros_code_T *localB);
static void ros_code_spline(const real_T x_data[], const int32_T x_size[2],
  const real_T y_data[], const int32_T y_size[2], real_T output_breaks_data[],
  int32_T output_breaks_size[2], real_T output_coefs_data[], int32_T
  output_coefs_size[2], B_Global_planner_ros_code_T *localB);
static void ros_code_interp1(const real_T varargin_1_data[], const int32_T
  varargin_1_size[2], const real_T varargin_2_data[], const int32_T
  *varargin_2_size, const real_T varargin_3_data[], const int32_T
  varargin_3_size[2], real_T Vq_data[], int32_T Vq_size[2],
  B_Global_planner_ros_code_T *localB);
static void ros_code_binary_expand_op(real_T in1[3], const int32_T in2_data[],
  const real_T in3_data[], const int32_T *in3_size, const real_T in4_data[],
  const int32_T *in4_size);
static void ros_code_minimum2(const real_T y_data[], const int32_T y_size[2],
  real_T ex_data[], int32_T ex_size[2]);
static void ros_code_maximum2(const real_T y_data[], const int32_T y_size[2],
  real_T ex_data[], int32_T ex_size[2]);
static void ros_code_gradient(const real_T x_data[], const int32_T x_size[2],
  real_T varargout_1_data[], int32_T varargout_1_size[2]);

// Function for MATLAB Function: '<S11>/getGlobalPathData'
static void ros_code_linspace(real_T d2, real_T n, real_T y_data[], int32_T
  y_size[2])
{
  if (!(n >= 0.0)) {
    y_size[0] = 1;
    y_size[1] = 0;
  } else {
    y_size[0] = 1;
    y_size[1] = static_cast<int32_T>(n);
    if (static_cast<int32_T>(n) >= 1) {
      y_data[static_cast<int32_T>(n) - 1] = d2;
      if (static_cast<int32_T>(n) >= 2) {
        y_data[0] = 1.0;
        if (static_cast<int32_T>(n) >= 3) {
          real_T delta1;
          delta1 = (d2 - 1.0) / (static_cast<real_T>(static_cast<int32_T>(n)) -
            1.0);
          for (int32_T k{0}; k <= static_cast<int32_T>(n) - 3; k++) {
            y_data[k + 1] = (static_cast<real_T>(k) + 1.0) * delta1 + 1.0;
          }
        }
      }
    }
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = (rtNaN);
  } else if (std::isinf(u0) && std::isinf(u1)) {
    int32_T u0_0;
    int32_T u1_0;
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = std::atan2(static_cast<real_T>(u0_0), static_cast<real_T>(u1_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = std::atan2(u0, u1);
  }

  return y;
}

static void ros_code_binary_expand_op_g(real_T in1[3], const int8_T in2_data[],
  const real_T in3_data[], const int32_T *in3_size, const real_T in4_data[],
  const int32_T *in4_size)
{
  int32_T loop_ub;
  loop_ub = *in4_size == 1 ? *in3_size : *in4_size;
  for (int32_T i{0}; i < loop_ub; i++) {
    in1[in2_data[0] - 1] = -in3_data[0] * 2.0 * in4_data[0];
  }
}

// Function for MATLAB Function: '<S11>/getGlobalPathData'
static void ros_code_quat2eul(real_T q[4], real_T eul[3],
  B_Global_planner_ros_code_T *localB)
{
  int32_T d_size;
  int32_T k;
  int32_T trueCount;
  int8_T g_data;
  boolean_T mask1;
  boolean_T mask2;
  localB->b_b = 1.0 / std::sqrt(((q[0] * q[0] + q[1] * q[1]) + q[2] * q[2]) + q
    [3] * q[3]);
  q[0] *= localB->b_b;
  q[1] *= localB->b_b;
  q[2] *= localB->b_b;
  localB->b_b *= q[3];
  localB->aSinInput_f = (q[1] * localB->b_b - q[0] * q[2]) * -2.0;
  mask1 = (localB->aSinInput_f >= 0.99999999999999778);
  mask2 = (localB->aSinInput_f <= -0.99999999999999778);
  if (localB->aSinInput_f >= 0.99999999999999778) {
    localB->aSinInput_f = 1.0;
  }

  if (mask2) {
    localB->aSinInput_f = -1.0;
  }

  localB->eul_tmp = q[0] * q[0];
  localB->eul_tmp_m = q[1] * q[1];
  localB->eul_tmp_n = q[2] * q[2];
  localB->eul_tmp_p = localB->b_b * localB->b_b;
  eul[0] = rt_atan2d_snf((q[1] * q[2] + q[0] * localB->b_b) * 2.0,
    ((localB->eul_tmp + localB->eul_tmp_m) - localB->eul_tmp_n) -
    localB->eul_tmp_p);
  eul[1] = std::asin(localB->aSinInput_f);
  eul[2] = rt_atan2d_snf((q[2] * localB->b_b + q[0] * q[1]) * 2.0,
    ((localB->eul_tmp - localB->eul_tmp_m) - localB->eul_tmp_n) +
    localB->eul_tmp_p);
  trueCount = 0;
  if (mask1 || mask2) {
    trueCount = 1;
  }

  if (trueCount - 1 >= 0) {
    localB->x_data_g = localB->aSinInput_f;
  }

  k = 0;
  while (k <= trueCount - 1) {
    if (!std::isnan(localB->x_data_g)) {
      if (localB->x_data_g < 0.0) {
        localB->x_data_g = -1.0;
      } else {
        localB->x_data_g = (localB->x_data_g > 0.0);
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
    localB->d_data_g = rt_atan2d_snf(q[1], q[0]);
  }

  if (mask1 || mask2) {
    g_data = 1;
  }

  if (trueCount == static_cast<int8_T>(k)) {
    if (trueCount - 1 >= 0) {
      eul[0] = -localB->x_data_g * 2.0 * localB->d_data_g;
    }
  } else {
    ros_code_binary_expand_op_g(eul, &g_data, &localB->x_data_g, &trueCount,
      &localB->d_data_g, &d_size);
  }

  trueCount = 0;
  if (mask1 || mask2) {
    trueCount = 1;
  }

  if (trueCount - 1 >= 0) {
    eul[2] = 0.0;
  }
}

// Function for MATLAB Function: '<S11>/getGlobalPathData'
static void ros_code_spline(const real_T x_data[], const int32_T x_size[2],
  const real_T y_data[], const int32_T y_size[2], real_T output_breaks_data[],
  int32_T output_breaks_size[2], real_T output_coefs_data[], int32_T
  output_coefs_size[2], B_Global_planner_ros_code_T *localB)
{
  boolean_T has_endslopes;
  localB->nx_d = x_size[1] - 1;
  has_endslopes = (x_size[1] + 2 == y_size[1]);
  if ((x_size[1] <= 2) || ((x_size[1] <= 3) && (!has_endslopes))) {
    int32_T k;
    if (x_size[1] <= 2) {
      if (x_size[1] + 2 == y_size[1]) {
        localB->d31 = y_data[0];
        if (x_size[1] - 2 >= 0) {
          localB->dnnm2 = x_data[1] - x_data[0];
          localB->divdifij = (y_data[2] - y_data[1]) / localB->dnnm2;
          localB->r = (localB->divdifij - localB->d31) / localB->dnnm2;
          localB->divdifij = (y_data[y_size[1] - 1] - localB->divdifij) /
            localB->dnnm2;
          localB->b_coefs_data[0] = (localB->divdifij - localB->r) /
            localB->dnnm2;
          localB->b_coefs_data[1] = 2.0 * localB->r - localB->divdifij;
          localB->b_coefs_data[2] = localB->d31;
          localB->b_coefs_data[3] = y_data[1];
        }

        k = 4;
        for (int32_T yoffset{0}; yoffset < 4; yoffset++) {
          localB->b_c_data[yoffset] = localB->b_coefs_data[yoffset];
        }
      } else {
        k = 2;
        localB->nx_d = 0;
        localB->b_c_data[localB->nx_d] = (y_data[1] - y_data[localB->nx_d]) /
          (x_data[1] - x_data[localB->nx_d]);
        localB->b_c_data[1] = y_data[localB->nx_d];
      }

      localB->nx_d = k - 1;
      std::memcpy(&localB->b_coefs_data[0], &localB->b_c_data[0], (localB->nx_d
        + 1) * sizeof(real_T));
      localB->nx_d = x_size[1];
      output_breaks_size[0] = 1;
      output_breaks_size[1] = x_size[1];
      if (localB->nx_d - 1 >= 0) {
        std::memcpy(&output_breaks_data[0], &x_data[0], localB->nx_d * sizeof
                    (real_T));
      }
    } else {
      localB->nx_d = 0;
      localB->divdifij = x_data[1];
      localB->r = x_data[localB->nx_d];
      localB->d31 = localB->divdifij - localB->r;
      localB->d31_tmp = y_data[1];
      localB->dnnm2_tmp = y_data[localB->nx_d];
      localB->dnnm2 = (localB->d31_tmp - localB->dnnm2_tmp) / localB->d31;
      localB->b_c_data_tmp = x_data[2];
      localB->b_c_data[localB->nx_d] = ((y_data[2] - localB->d31_tmp) /
        (localB->b_c_data_tmp - localB->divdifij) - localB->dnnm2) /
        (localB->b_c_data_tmp - localB->r);
      localB->b_c_data[1] = localB->dnnm2 - localB->b_c_data[localB->nx_d] *
        localB->d31;
      localB->b_c_data[2] = localB->dnnm2_tmp;
      output_breaks_size[0] = 1;
      output_breaks_size[1] = 2;
      output_breaks_data[localB->nx_d] = localB->r;
      output_breaks_data[1] = localB->b_c_data_tmp;
      k = 3;
      for (int32_T yoffset{0}; yoffset < 3; yoffset++) {
        localB->nx_d = yoffset;
        localB->b_coefs_data[localB->nx_d] = localB->b_c_data[localB->nx_d];
      }
    }

    output_coefs_size[0] = 1;
    output_coefs_size[1] = k;
    localB->nx_d = k - 1;
    std::memcpy(&output_coefs_data[0], &localB->b_coefs_data[0], (localB->nx_d +
      1) * sizeof(real_T));
  } else {
    int32_T k;
    int32_T s_data_tmp;
    int32_T yoffset;
    int8_T szs_idx_1;
    if (has_endslopes) {
      szs_idx_1 = static_cast<int8_T>(y_size[1] - 2);
      yoffset = 0;
    } else {
      szs_idx_1 = static_cast<int8_T>(y_size[1]);
      yoffset = -1;
    }

    for (k = 0; k < localB->nx_d; k++) {
      localB->dx_data[k] = x_data[k + 1] - x_data[k];
      s_data_tmp = yoffset + k;
      localB->dvdf_data[k] = (y_data[s_data_tmp + 2] - y_data[s_data_tmp + 1]) /
        localB->dx_data[k];
    }

    for (k = 1; k < localB->nx_d; k++) {
      localB->s_data[k] = (localB->dvdf_data[k - 1] * localB->dx_data[k] +
                           localB->dx_data[k - 1] * localB->dvdf_data[k]) * 3.0;
    }

    if (has_endslopes) {
      localB->d31 = 0.0;
      localB->dnnm2 = 0.0;
      localB->s_data[0] = y_data[0] * localB->dx_data[1];
      localB->s_data[x_size[1] - 1] = localB->dx_data[x_size[1] - 3] *
        y_data[x_size[1] + 1];
    } else {
      int32_T dnnm2_tmp;
      localB->d31 = x_data[2] - x_data[0];
      k = x_size[1] - 3;
      dnnm2_tmp = x_size[1] - 1;
      localB->dnnm2 = x_data[dnnm2_tmp] - x_data[k];
      localB->divdifij = localB->dx_data[0];
      localB->s_data[0] = ((2.0 * localB->d31 + localB->divdifij) *
                           localB->dx_data[1] * localB->dvdf_data[0] +
                           localB->divdifij * localB->divdifij *
                           localB->dvdf_data[1]) / localB->d31;
      s_data_tmp = x_size[1] - 2;
      localB->divdifij = localB->dx_data[s_data_tmp];
      localB->s_data[dnnm2_tmp] = ((2.0 * localB->dnnm2 + localB->divdifij) *
        localB->dx_data[k] * localB->dvdf_data[s_data_tmp] + localB->divdifij *
        localB->divdifij * localB->dvdf_data[k]) / localB->dnnm2;
    }

    localB->r = localB->dx_data[1];
    localB->md_data[0] = localB->r;
    s_data_tmp = x_size[1] - 1;
    localB->divdifij = localB->dx_data[x_size[1] - 3];
    localB->md_data[s_data_tmp] = localB->divdifij;
    for (k = 1; k < localB->nx_d; k++) {
      localB->md_data[k] = (localB->dx_data[k - 1] + localB->dx_data[k]) * 2.0;
    }

    localB->r /= localB->md_data[0];
    localB->md_data[1] -= localB->r * localB->d31;
    localB->s_data[1] -= localB->r * localB->s_data[0];
    for (k = 2; k < localB->nx_d; k++) {
      localB->r = localB->dx_data[k] / localB->md_data[k - 1];
      localB->md_data[k] -= localB->dx_data[k - 2] * localB->r;
      localB->s_data[k] -= localB->s_data[k - 1] * localB->r;
    }

    k = x_size[1] - 2;
    localB->r = localB->dnnm2 / localB->md_data[k];
    localB->md_data[s_data_tmp] -= localB->divdifij * localB->r;
    localB->s_data[s_data_tmp] -= localB->s_data[k] * localB->r;
    localB->s_data[s_data_tmp] /= localB->md_data[s_data_tmp];
    localB->nx_d = x_size[1] - 2;
    while (localB->nx_d + 1 > 1) {
      s_data_tmp = localB->nx_d;
      localB->s_data[s_data_tmp] = (localB->s_data[s_data_tmp] - localB->
        dx_data[localB->nx_d - 1] * localB->s_data[localB->nx_d + 1]) /
        localB->md_data[s_data_tmp];
      localB->nx_d--;
    }

    localB->s_data[0] = (localB->s_data[0] - localB->d31 * localB->s_data[1]) /
      localB->md_data[0];
    for (k = 0; k <= x_size[1] - 2; k++) {
      localB->divdifij = localB->dvdf_data[k];
      localB->r = localB->dx_data[k];
      localB->d31_tmp = localB->s_data[k];
      localB->d31 = (localB->divdifij - localB->d31_tmp) / localB->r;
      localB->dnnm2 = (localB->s_data[k + 1] - localB->divdifij) / localB->r;
      localB->c_coefs_data[k] = (localB->dnnm2 - localB->d31) / localB->r;
      localB->c_coefs_data[(szs_idx_1 + k) - 1] = 2.0 * localB->d31 -
        localB->dnnm2;
      localB->c_coefs_data[((szs_idx_1 - 1) << 1) + k] = localB->d31_tmp;
      localB->c_coefs_data[3 * (szs_idx_1 - 1) + k] = y_data[(yoffset + k) + 1];
    }

    localB->nx_d = x_size[1];
    output_breaks_size[0] = 1;
    output_breaks_size[1] = x_size[1];
    std::memcpy(&output_breaks_data[0], &x_data[0], localB->nx_d * sizeof(real_T));
    output_coefs_size[0] = szs_idx_1 - 1;
    output_coefs_size[1] = 4;
    localB->nx_d = (szs_idx_1 - 1) << 2;
    if (localB->nx_d - 1 >= 0) {
      std::memcpy(&output_coefs_data[0], &localB->c_coefs_data[0], localB->nx_d *
                  sizeof(real_T));
    }
  }
}

// Function for MATLAB Function: '<S11>/getGlobalPathData'
static void ros_code_interp1(const real_T varargin_1_data[], const int32_T
  varargin_1_size[2], const real_T varargin_2_data[], const int32_T
  *varargin_2_size, const real_T varargin_3_data[], const int32_T
  varargin_3_size[2], real_T Vq_data[], int32_T Vq_size[2],
  B_Global_planner_ros_code_T *localB)
{
  localB->y_size_idx_0 = *varargin_2_size;
  localB->nd2 = *varargin_2_size;
  if (localB->nd2 - 1 >= 0) {
    std::memcpy(&localB->y_data[0], &varargin_2_data[0], localB->nd2 * sizeof
                (real_T));
  }

  localB->x_size[0] = 1;
  localB->x_size[1] = varargin_1_size[1];
  localB->nd2 = varargin_1_size[1] - 1;
  if (localB->nd2 >= 0) {
    std::memcpy(&localB->x_data[0], &varargin_1_data[0], (localB->nd2 + 1) *
                sizeof(real_T));
  }

  localB->nx = varargin_1_size[1];
  Vq_size[0] = 1;
  Vq_size[1] = varargin_3_size[1];
  localB->nd2 = varargin_3_size[1] - 1;
  if (localB->nd2 >= 0) {
    std::memset(&Vq_data[0], 0, (localB->nd2 + 1) * sizeof(real_T));
  }

  if (varargin_3_size[1] != 0) {
    localB->nd2 = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (localB->nd2 <= localB->nx - 1) {
        if (std::isnan(varargin_1_data[localB->nd2])) {
          exitg1 = 1;
        } else {
          localB->nd2++;
        }
      } else {
        if (varargin_1_data[1] < varargin_1_data[0]) {
          localB->nd2 = localB->nx >> 1;
          localB->high_i = 0;
          while (localB->high_i <= localB->nd2 - 1) {
            localB->low_ip1 = localB->high_i;
            localB->xloc = localB->x_data[localB->low_ip1];
            localB->mid_i = (localB->nx - localB->high_i) - 1;
            localB->x_data[localB->low_ip1] = localB->x_data[localB->mid_i];
            localB->x_data[localB->mid_i] = localB->xloc;
            localB->high_i++;
          }

          if (*varargin_2_size > 1) {
            localB->nx = *varargin_2_size;
            localB->nd2 = *varargin_2_size >> 1;
            localB->high_i = 0;
            while (localB->high_i <= localB->nd2 - 1) {
              localB->xloc = localB->y_data[localB->high_i];
              localB->low_ip1 = (localB->nx - localB->high_i) - 1;
              localB->y_data[localB->high_i] = localB->y_data[localB->low_ip1];
              localB->y_data[localB->low_ip1] = localB->xloc;
              localB->high_i++;
            }
          }
        }

        localB->y_size[0] = 1;
        localB->y_size[1] = localB->y_size_idx_0;
        if (localB->y_size_idx_0 - 1 >= 0) {
          std::memcpy(&localB->y_data_k[0], &localB->y_data[0],
                      localB->y_size_idx_0 * sizeof(real_T));
        }

        ros_code_spline(localB->x_data, localB->x_size, localB->y_data_k,
                        localB->y_size, localB->y_data, localB->pp_breaks_size,
                        localB->pp_coefs_data, localB->pp_coefs_size, localB);
        localB->nx = 0;
        while (localB->nx <= varargin_3_size[1] - 1) {
          localB->y_size_idx_0 = localB->nx;
          localB->yit = varargin_3_data[localB->y_size_idx_0];
          if (std::isnan(localB->yit)) {
            Vq_data[localB->y_size_idx_0] = (rtNaN);
          } else {
            if (std::isnan(localB->yit)) {
            } else {
              localB->high_i = localB->pp_breaks_size[1];
              localB->nd2 = 1;
              localB->low_ip1 = 2;
              while (localB->high_i > localB->low_ip1) {
                localB->mid_i = (localB->nd2 >> 1) + (localB->high_i >> 1);
                if (((localB->nd2 & 1) == 1) && ((localB->high_i & 1) == 1)) {
                  localB->mid_i++;
                }

                if (localB->yit >= localB->y_data[localB->mid_i - 1]) {
                  localB->nd2 = localB->mid_i;
                  localB->low_ip1 = localB->mid_i + 1;
                } else {
                  localB->high_i = localB->mid_i;
                }
              }

              localB->xloc = localB->yit - localB->y_data[localB->nd2 - 1];
              localB->yit = localB->pp_coefs_data[localB->nd2 - 1];
              localB->high_i = 2;
              while (localB->high_i <= localB->pp_coefs_size[1]) {
                localB->yit = localB->pp_coefs_data[((localB->high_i - 1) *
                  (localB->pp_breaks_size[1] - 1) + localB->nd2) - 1] +
                  localB->xloc * localB->yit;
                localB->high_i++;
              }
            }

            Vq_data[localB->y_size_idx_0] = localB->yit;
          }

          localB->nx++;
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
}

static void ros_code_binary_expand_op(real_T in1[3], const int32_T in2_data[],
  const real_T in3_data[], const int32_T *in3_size, const real_T in4_data[],
  const int32_T *in4_size)
{
  int32_T loop_ub;

  // MATLAB Function: '<S2>/getObjectData'
  loop_ub = *in4_size == 1 ? *in3_size : *in4_size;
  for (int32_T i{0}; i < loop_ub; i++) {
    in1[in2_data[0] - 1] = -in3_data[0] * 2.0 * in4_data[0];
  }

  // End of MATLAB Function: '<S2>/getObjectData'
}

// Function for MATLAB Function: '<S11>/getGlobalPathData'
static void ros_code_minimum2(const real_T y_data[], const int32_T y_size[2],
  real_T ex_data[], int32_T ex_size[2])
{
  int32_T nx;
  ex_size[0] = y_size[0];
  ex_size[1] = 2;
  nx = y_size[0] << 1;
  for (int32_T k{0}; k < nx; k++) {
    ex_data[k] = std::fmin(1.0, y_data[k]);
  }
}

// Function for MATLAB Function: '<S11>/getGlobalPathData'
static void ros_code_maximum2(const real_T y_data[], const int32_T y_size[2],
  real_T ex_data[], int32_T ex_size[2])
{
  int32_T nx;
  ex_size[0] = y_size[0];
  ex_size[1] = 2;
  nx = y_size[0] << 1;
  for (int32_T k{0}; k < nx; k++) {
    ex_data[k] = std::fmax(-1.0, y_data[k]);
  }
}

// Function for MATLAB Function: '<S11>/getGlobalPathData'
static void ros_code_gradient(const real_T x_data[], const int32_T x_size[2],
  real_T varargout_1_data[], int32_T varargout_1_size[2])
{
  if (x_size[1] == 1) {
    varargout_1_size[0] = 1;
    varargout_1_size[1] = 1;
    varargout_1_data[0] = 0.0;
  } else if (x_size[1] < 2) {
    varargout_1_size[0] = 1;
    varargout_1_size[1] = static_cast<int8_T>(x_size[1]);
    if (static_cast<int8_T>(x_size[1]) - 1 >= 0) {
      varargout_1_data[0] = 0.0;
    }
  } else {
    int32_T varargout_1_data_tmp;
    varargout_1_size[0] = 1;
    varargout_1_size[1] = x_size[1];
    varargout_1_data[0] = x_data[1] - x_data[0];
    for (varargout_1_data_tmp = 2; varargout_1_data_tmp < x_size[1];
         varargout_1_data_tmp++) {
      varargout_1_data[varargout_1_data_tmp - 1] = (x_data[varargout_1_data_tmp]
        - x_data[varargout_1_data_tmp - 2]) / 2.0;
    }

    varargout_1_data_tmp = x_size[1] - 1;
    varargout_1_data[varargout_1_data_tmp] = x_data[varargout_1_data_tmp] -
      x_data[x_size[1] - 2];
  }
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = std::abs(u0);
    tmp_0 = std::abs(u1);
    if (std::isinf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = (rtNaN);
    } else {
      y = std::pow(u0, u1);
    }
  }

  return y;
}

// System initialize for atomic system: '<Root>/Global_planner'
void ros_code_Global_planner_Init(real_T *rty_get_global_pose, real_T
  rty_preprocess_global_path_arra[10000], real_T rty_global_path_array[60],
  B_Global_planner_ros_code_T *localB, DW_Global_planner_ros_code_T *localDW,
  P_Global_planner_ros_code_T *localP)
{
  static const char_T tmp_0[51]{ '/', 'f', 'a', 'k', 'e', '_', 'o', 'b', 's',
    't', 'a', 'c', 'l', 'e', '_', 'p', 'u', 'b', 'l', 'i', 's', 'h', 'e', 'r',
    '/', 'v', 'i', 's', 'u', 'a', 'l', 'i', 'z', 'a', 't', 'i', 'o', 'n', '_',
    'm', 'a', 'r', 'k', 'e', 'r', '_', 'a', 'r', 'r', 'a', 'y' };

  static const char_T tmp[12]{ '/', 'g', 'l', 'o', 'b', 'a', 'l', '_', 'p', 'a',
    't', 'h' };

  char_T b_zeroDelimTopic[13];

  // SystemInitialize for Atomic SubSystem: '<S2>/Subscribe1'
  // Start for MATLABSystem: '<S9>/SourceBlock'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->obj.isInitialized = 1;
  for (int32_T i{0}; i < 12; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[12] = '\x00';
  Sub_ros_code_1818.createSubscriber(&b_zeroDelimTopic[0], 1000);
  localDW->obj.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S9>/SourceBlock'
  // End of SystemInitialize for SubSystem: '<S2>/Subscribe1'

  // SystemInitialize for Enabled SubSystem: '<S2>/get_global_path'
  // SystemInitialize for Outport: '<S11>/preprocess_global_path_array'
  for (int32_T i{0}; i < 10000; i++) {
    rty_preprocess_global_path_arra[i] = localP->preprocess_global_path_array_Y0;
  }

  // End of SystemInitialize for Outport: '<S11>/preprocess_global_path_array'

  // SystemInitialize for Outport: '<S11>/get_global_pose'
  *rty_get_global_pose = localP->get_global_pose_Y0;

  // SystemInitialize for Outport: '<S11>/global_path_array'
  for (int32_T i{0}; i < 60; i++) {
    rty_global_path_array[i] = localP->global_path_array_Y0;
  }

  // End of SystemInitialize for Outport: '<S11>/global_path_array'
  // End of SystemInitialize for SubSystem: '<S2>/get_global_path'

  // SystemInitialize for Atomic SubSystem: '<S2>/Subscribe'
  // SystemInitialize for Enabled SubSystem: '<S8>/Enabled Subsystem'
  // SystemInitialize for SignalConversion generated from: '<S13>/In1' incorporates:
  //   Outport: '<S13>/Out1'

  localB->In1_f = localP->Out1_Y0_j;

  // End of SystemInitialize for SubSystem: '<S8>/Enabled Subsystem'

  // Start for MATLABSystem: '<S8>/SourceBlock'
  localDW->obj_o.matlabCodegenIsDeleted = false;
  localDW->obj_o.isInitialized = 1;
  for (int32_T i{0}; i < 51; i++) {
    localB->b_zeroDelimTopic[i] = tmp_0[i];
  }

  localB->b_zeroDelimTopic[51] = '\x00';
  Sub_ros_code_1817.createSubscriber(&localB->b_zeroDelimTopic[0], 1);
  localDW->obj_o.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S8>/SourceBlock'
  // End of SystemInitialize for SubSystem: '<S2>/Subscribe'
}

// Output and update for atomic system: '<Root>/Global_planner'
void ros_code_Global_planner(real_T *rty_get_global_pose, real_T
  rty_preprocess_global_path_arra[10000], real_T rty_global_path_array[60],
  real_T rty_object_array_F[30], real_T rty_object_array_C[50],
  B_Global_planner_ros_code_T *localB)
{
  boolean_T mask1;

  // Outputs for Atomic SubSystem: '<S2>/Subscribe1'
  // MATLABSystem: '<S9>/SourceBlock' incorporates:
  //   MATLAB Function: '<S11>/getGlobalPathData'

  mask1 = Sub_ros_code_1818.getLatestMessage(&localB->b_varargout_2);

  // Outputs for Enabled SubSystem: '<S2>/get_global_path' incorporates:
  //   EnablePort: '<S11>/Enable'

  // Outputs for Enabled SubSystem: '<S9>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S14>/Enable'

  if (mask1) {
    // MATLAB Function: '<S11>/getGlobalPathData'
    std::memset(&rty_global_path_array[0], 0, 60U * sizeof(real_T));
    std::memset(&rty_preprocess_global_path_arra[0], 0, 10000U * sizeof(real_T));
    localB->global_path_num = 0.0;
    for (localB->i = 0; localB->i < 1000; localB->i++) {
      if ((localB->b_varargout_2.Poses[localB->i].Pose.Orientation.X != 0.0) ||
          (localB->b_varargout_2.Poses[localB->i].Pose.Orientation.Y != 0.0) ||
          (localB->b_varargout_2.Poses[localB->i].Pose.Orientation.Z != 0.0) ||
          (localB->b_varargout_2.Poses[localB->i].Pose.Orientation.W != 0.0)) {
        localB->global_path_num++;
        rty_global_path_array[static_cast<int32_T>(localB->global_path_num) - 1]
          = localB->b_varargout_2.Poses[localB->i].Pose.Position.X;
        rty_global_path_array[static_cast<int32_T>(localB->global_path_num) + 19]
          = localB->b_varargout_2.Poses[localB->i].Pose.Position.Y;
        localB->dv[0] = localB->b_varargout_2.Poses[localB->i].
          Pose.Orientation.X;
        localB->dv[1] = localB->b_varargout_2.Poses[localB->i].
          Pose.Orientation.Y;
        localB->dv[2] = localB->b_varargout_2.Poses[localB->i].
          Pose.Orientation.Z;
        localB->dv[3] = localB->b_varargout_2.Poses[localB->i].
          Pose.Orientation.W;
        ros_code_quat2eul(localB->dv, localB->eulZYX, localB);
        rty_global_path_array[static_cast<int32_T>(localB->global_path_num) + 39]
          = localB->eulZYX[2];
      }
    }

    rty_global_path_array[19] = localB->global_path_num;
    localB->new_point_num = rty_global_path_array[static_cast<int32_T>
      (localB->global_path_num - 1.0) - 1] - rty_global_path_array
      [static_cast<int32_T>(localB->global_path_num) - 1];
    localB->b_a = rty_global_path_array[static_cast<int32_T>
      (localB->global_path_num - 1.0) + 19] - rty_global_path_array[static_cast<
      int32_T>(localB->global_path_num) + 19];
    localB->new_point_num = std::fmin(std::round((std::sqrt
      (localB->new_point_num * localB->new_point_num + localB->b_a * localB->b_a)
      + localB->global_path_num) * 100.0), 99999.0);
    ros_code_linspace(localB->global_path_num, localB->new_point_num,
                      localB->param_new_data, localB->param_new_size);
    localB->tmp_size[0] = 1;
    localB->tmp_size[1] = static_cast<int32_T>(localB->global_path_num - 1.0) +
      1;
    localB->loop_ub = static_cast<int32_T>(localB->global_path_num - 1.0);
    for (localB->i = 0; localB->i <= localB->loop_ub; localB->i++) {
      localB->tmp_data_c[localB->i] = static_cast<real_T>(localB->i) + 1.0;
    }

    localB->loop_ub = static_cast<int32_T>(localB->global_path_num);
    localB->rty_global_path_array_size = static_cast<int32_T>
      (localB->global_path_num);
    if (localB->loop_ub - 1 >= 0) {
      std::memcpy(&localB->rty_global_path_array_data[0],
                  &rty_global_path_array[0], localB->loop_ub * sizeof(real_T));
    }

    // MATLAB Function: '<S11>/getGlobalPathData'
    ros_code_interp1(localB->tmp_data_c, localB->tmp_size,
                     localB->rty_global_path_array_data,
                     &localB->rty_global_path_array_size, localB->param_new_data,
                     localB->param_new_size, localB->X_interp_data,
                     localB->X_interp_size, localB);
    localB->tmp_size[0] = 1;
    localB->tmp_size[1] = static_cast<int32_T>(localB->global_path_num - 1.0) +
      1;
    localB->loop_ub = static_cast<int32_T>(localB->global_path_num - 1.0);
    for (localB->i = 0; localB->i <= localB->loop_ub; localB->i++) {
      localB->tmp_data_c[localB->i] = static_cast<real_T>(localB->i) + 1.0;
    }

    localB->loop_ub = static_cast<int32_T>(localB->global_path_num);
    localB->rty_global_path_array_size = static_cast<int32_T>
      (localB->global_path_num);
    if (localB->loop_ub - 1 >= 0) {
      std::memcpy(&localB->rty_global_path_array_data[0],
                  &rty_global_path_array[20], localB->loop_ub * sizeof(real_T));
    }

    // MATLAB Function: '<S11>/getGlobalPathData'
    ros_code_interp1(localB->tmp_data_c, localB->tmp_size,
                     localB->rty_global_path_array_data,
                     &localB->rty_global_path_array_size, localB->param_new_data,
                     localB->param_new_size, localB->Y_interp_data,
                     localB->Y_interp_size, localB);
    localB->loop_ub = static_cast<int32_T>(localB->global_path_num);
    localB->rty_global_path_array_size = static_cast<int32_T>
      (localB->global_path_num);
    if (localB->loop_ub - 1 >= 0) {
      std::memcpy(&localB->rty_global_path_array_data[0],
                  &rty_global_path_array[40], localB->loop_ub * sizeof(real_T));
    }

    // MATLAB Function: '<S11>/getGlobalPathData'
    localB->loop_ub = 0;
    while (localB->loop_ub <= static_cast<int32_T>(localB->global_path_num) - 1)
    {
      localB->rty_global_path_array_data[localB->loop_ub] = std::cos
        (localB->rty_global_path_array_data[localB->loop_ub]);
      localB->loop_ub++;
    }

    localB->tmp_size[0] = 1;
    localB->tmp_size[1] = static_cast<int32_T>(localB->global_path_num - 1.0) +
      1;
    localB->loop_ub = static_cast<int32_T>(localB->global_path_num - 1.0);
    for (localB->i = 0; localB->i <= localB->loop_ub; localB->i++) {
      localB->tmp_data_c[localB->i] = static_cast<real_T>(localB->i) + 1.0;
    }

    ros_code_interp1(localB->tmp_data_c, localB->tmp_size,
                     localB->rty_global_path_array_data,
                     &localB->rty_global_path_array_size, localB->param_new_data,
                     localB->param_new_size, localB->cos_interp_data,
                     localB->cos_interp_size, localB);
    localB->loop_ub = static_cast<int32_T>(localB->global_path_num);
    localB->rty_global_path_array_size = static_cast<int32_T>
      (localB->global_path_num);
    if (localB->loop_ub - 1 >= 0) {
      std::memcpy(&localB->rty_global_path_array_data[0],
                  &rty_global_path_array[40], localB->loop_ub * sizeof(real_T));
    }

    // MATLAB Function: '<S11>/getGlobalPathData'
    localB->i = 0;
    while (localB->i <= static_cast<int32_T>(localB->global_path_num) - 1) {
      localB->rty_global_path_array_data[localB->i] = std::sin
        (localB->rty_global_path_array_data[localB->i]);
      localB->i++;
    }

    localB->tmp_size[0] = 1;
    localB->tmp_size[1] = static_cast<int32_T>(localB->global_path_num - 1.0) +
      1;
    localB->loop_ub = static_cast<int32_T>(localB->global_path_num - 1.0);
    for (localB->i = 0; localB->i <= localB->loop_ub; localB->i++) {
      localB->tmp_data_c[localB->i] = static_cast<real_T>(localB->i) + 1.0;
    }

    ros_code_interp1(localB->tmp_data_c, localB->tmp_size,
                     localB->rty_global_path_array_data,
                     &localB->rty_global_path_array_size, localB->param_new_data,
                     localB->param_new_size, localB->new_Theta_interp_data,
                     localB->new_Theta_interp_size, localB);
    localB->tmp_size_l[0] = localB->new_Theta_interp_size[1];
    localB->tmp_size_l[1] = 2;
    localB->loop_ub = localB->new_Theta_interp_size[1];
    if (localB->loop_ub - 1 >= 0) {
      std::memcpy(&localB->trigo_interp_data[0], &localB->new_Theta_interp_data
                  [0], localB->loop_ub * sizeof(real_T));
    }

    // MATLAB Function: '<S11>/getGlobalPathData'
    localB->loop_ub = localB->cos_interp_size[1];
    for (localB->i = 0; localB->i < localB->loop_ub; localB->i++) {
      localB->trigo_interp_data[localB->i + localB->tmp_size_l[0]] =
        localB->cos_interp_data[localB->i];
    }

    ros_code_minimum2(localB->trigo_interp_data, localB->tmp_size_l,
                      localB->tmp_data, localB->tmp_size);
    ros_code_maximum2(localB->tmp_data, localB->tmp_size,
                      localB->trigo_interp_data, localB->cos_interp_size);
    localB->new_Theta_interp_size_tmp = static_cast<int32_T>
      (localB->new_point_num);
    localB->loop_ub_tmp = static_cast<int32_T>(localB->new_point_num) - 1;
    if (localB->loop_ub_tmp >= 0) {
      std::memset(&localB->new_Theta_interp_data[0], 0, (localB->loop_ub_tmp + 1)
                  * sizeof(real_T));
    }

    // MATLAB Function: '<S11>/getGlobalPathData'
    localB->i = 0;
    while (localB->i <= static_cast<int32_T>(localB->new_point_num) - 1) {
      if (localB->trigo_interp_data[localB->i] >= 0.0) {
        localB->new_Theta_interp_data[localB->i] = std::acos
          (localB->trigo_interp_data[localB->i + localB->cos_interp_size[0]]);
      } else {
        localB->new_Theta_interp_data[localB->i] = -std::acos
          (localB->trigo_interp_data[localB->i + localB->cos_interp_size[0]]);
      }

      localB->i++;
    }

    ros_code_gradient(localB->X_interp_data, localB->X_interp_size,
                      localB->param_new_data, localB->param_new_size);
    ros_code_gradient(localB->Y_interp_data, localB->Y_interp_size,
                      localB->cos_interp_data, localB->cos_interp_size);
    ros_code_gradient(localB->param_new_data, localB->param_new_size,
                      localB->sin_interp_data, localB->tmp_size);
    ros_code_gradient(localB->cos_interp_data, localB->cos_interp_size,
                      localB->ddy_data, localB->param_new_size);
    localB->i = 0;
    while (localB->i <= static_cast<int32_T>(localB->new_point_num) - 1) {
      localB->loop_ub = localB->i;
      localB->b_a = localB->param_new_data[localB->loop_ub];
      localB->matrix_idx_2 = localB->cos_interp_data[localB->loop_ub];
      localB->global_path_num = rt_powd_snf(localB->b_a * localB->b_a +
        localB->matrix_idx_2 * localB->matrix_idx_2, 1.5);
      if (localB->global_path_num != 0.0) {
        localB->curvature_data[localB->loop_ub] = (localB->b_a *
          localB->ddy_data[localB->loop_ub] - localB->matrix_idx_2 *
          localB->sin_interp_data[localB->loop_ub]) / localB->global_path_num;
      } else {
        localB->curvature_data[localB->loop_ub] = 0.0;
      }

      localB->i++;
    }

    if (localB->loop_ub_tmp >= 0) {
      std::memset(&localB->param_new_data[0], 0, (localB->loop_ub_tmp + 1) *
                  sizeof(real_T));
    }

    // MATLAB Function: '<S11>/getGlobalPathData'
    localB->param_new_data[0] = 0.0;
    localB->i = 0;
    while (localB->i <= static_cast<int32_T>(localB->new_point_num + -1.0) - 1)
    {
      localB->loop_ub = localB->i + 1;
      localB->loop_ub_tmp = localB->i;
      localB->global_path_num = localB->X_interp_data[localB->loop_ub] -
        localB->X_interp_data[localB->loop_ub_tmp];
      localB->b_a = localB->Y_interp_data[localB->loop_ub] -
        localB->Y_interp_data[localB->loop_ub_tmp];
      localB->param_new_data[localB->loop_ub] = std::sqrt
        (localB->global_path_num * localB->global_path_num + localB->b_a *
         localB->b_a) + localB->param_new_data[localB->loop_ub_tmp];
      localB->i++;
    }

    rty_preprocess_global_path_arra[1999] = localB->new_point_num;
    localB->loop_ub = localB->X_interp_size[1];
    if (localB->loop_ub - 1 >= 0) {
      std::memcpy(&rty_preprocess_global_path_arra[0], &localB->X_interp_data[0],
                  localB->loop_ub * sizeof(real_T));
    }

    // MATLAB Function: '<S11>/getGlobalPathData'
    localB->loop_ub = localB->Y_interp_size[1];
    if (localB->loop_ub - 1 >= 0) {
      std::memcpy(&rty_preprocess_global_path_arra[2000], &localB->
                  Y_interp_data[0], localB->loop_ub * sizeof(real_T));
    }

    // MATLAB Function: '<S11>/getGlobalPathData'
    localB->loop_ub = static_cast<int32_T>(localB->new_point_num);
    if (localB->loop_ub - 1 >= 0) {
      std::memcpy(&rty_preprocess_global_path_arra[4000],
                  &localB->new_Theta_interp_data[0], localB->loop_ub * sizeof
                  (real_T));
    }

    if (localB->new_Theta_interp_size_tmp - 1 >= 0) {
      std::memcpy(&rty_preprocess_global_path_arra[6000],
                  &localB->curvature_data[0], localB->new_Theta_interp_size_tmp *
                  sizeof(real_T));
    }

    // MATLAB Function: '<S11>/getGlobalPathData'
    localB->loop_ub = static_cast<int32_T>(localB->new_point_num);
    if (localB->loop_ub - 1 >= 0) {
      std::memcpy(&rty_preprocess_global_path_arra[8000],
                  &localB->param_new_data[0], localB->loop_ub * sizeof(real_T));
    }

    // MATLAB Function: '<S11>/getGlobalPathData'
    *rty_get_global_pose = 1.0;
  }

  // End of MATLABSystem: '<S9>/SourceBlock'
  // End of Outputs for SubSystem: '<S9>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<S2>/get_global_path'
  // End of Outputs for SubSystem: '<S2>/Subscribe1'

  // Outputs for Atomic SubSystem: '<S2>/Subscribe'
  // MATLABSystem: '<S8>/SourceBlock'
  mask1 = Sub_ros_code_1817.getLatestMessage(&localB->b_varargout_2_m);

  // Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S13>/Enable'

  if (mask1) {
    // SignalConversion generated from: '<S13>/In1'
    localB->In1_f = localB->b_varargout_2_m;
  }

  // End of MATLABSystem: '<S8>/SourceBlock'
  // End of Outputs for SubSystem: '<S8>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<S2>/Subscribe'

  // MATLAB Function: '<S2>/getObjectData'
  std::memset(&rty_object_array_C[0], 0, 50U * sizeof(real_T));
  localB->new_point_num = 0.0;
  while (localB->In1_f.Markers[static_cast<int32_T>(localB->new_point_num + 1.0)
         - 1].Id != 0) {
    localB->new_point_num++;
  }

  rty_object_array_C[9] = localB->new_point_num;
  localB->i = 0;
  while (localB->i <= static_cast<int32_T>(localB->new_point_num) - 1) {
    boolean_T mask2;
    localB->global_path_num = localB->In1_f.Markers[localB->i].
      Pose.Orientation.X;
    localB->b_a = localB->In1_f.Markers[localB->i].Pose.Orientation.Y;
    localB->matrix_idx_2 = localB->In1_f.Markers[localB->i].Pose.Orientation.Z;
    localB->matrix_idx_3 = localB->In1_f.Markers[localB->i].Pose.Orientation.W;
    localB->aSinInput = 1.0 / std::sqrt(((localB->global_path_num *
      localB->global_path_num + localB->b_a * localB->b_a) +
      localB->matrix_idx_2 * localB->matrix_idx_2) + localB->matrix_idx_3 *
      localB->matrix_idx_3);
    localB->global_path_num *= localB->aSinInput;
    localB->b_a *= localB->aSinInput;
    localB->matrix_idx_2 *= localB->aSinInput;
    localB->matrix_idx_3 *= localB->aSinInput;
    localB->aSinInput = (localB->b_a * localB->matrix_idx_3 -
                         localB->global_path_num * localB->matrix_idx_2) * -2.0;
    mask1 = (localB->aSinInput >= 0.99999999999999778);
    mask2 = (localB->aSinInput <= -0.99999999999999778);
    if (localB->aSinInput >= 0.99999999999999778) {
      localB->aSinInput = 1.0;
    }

    if (mask2) {
      localB->aSinInput = -1.0;
    }

    localB->eulZYX_tmp_c = localB->global_path_num * localB->global_path_num;
    localB->eulZYX_tmp = localB->b_a * localB->b_a;
    localB->eulZYX_tmp_b = localB->matrix_idx_2 * localB->matrix_idx_2;
    localB->eulZYX_tmp_p = localB->matrix_idx_3 * localB->matrix_idx_3;
    localB->eulZYX[0] = rt_atan2d_snf((localB->b_a * localB->matrix_idx_2 +
      localB->global_path_num * localB->matrix_idx_3) * 2.0,
      ((localB->eulZYX_tmp_c + localB->eulZYX_tmp) - localB->eulZYX_tmp_b) -
      localB->eulZYX_tmp_p);
    localB->eulZYX[1] = std::asin(localB->aSinInput);
    localB->eulZYX[2] = rt_atan2d_snf((localB->matrix_idx_2 *
      localB->matrix_idx_3 + localB->global_path_num * localB->b_a) * 2.0,
      ((localB->eulZYX_tmp_c - localB->eulZYX_tmp) - localB->eulZYX_tmp_b) +
      localB->eulZYX_tmp_p);
    localB->new_Theta_interp_size_tmp = 0;
    if (mask1 || mask2) {
      localB->new_Theta_interp_size_tmp = 1;
    }

    localB->x_size_j = localB->new_Theta_interp_size_tmp;
    if (localB->new_Theta_interp_size_tmp - 1 >= 0) {
      localB->x_data_c = localB->aSinInput;
    }

    localB->loop_ub = 0;
    while (localB->loop_ub <= localB->new_Theta_interp_size_tmp - 1) {
      if (!std::isnan(localB->x_data_c)) {
        if (localB->x_data_c < 0.0) {
          localB->x_data_c = -1.0;
        } else {
          localB->x_data_c = (localB->x_data_c > 0.0);
        }
      }

      localB->loop_ub = 1;
    }

    localB->loop_ub = 0;
    if (mask1 || mask2) {
      localB->loop_ub = 1;
    }

    localB->d_size = static_cast<int8_T>(localB->loop_ub);
    if (static_cast<int8_T>(localB->loop_ub) - 1 >= 0) {
      localB->d_data = rt_atan2d_snf(localB->b_a, localB->global_path_num);
    }

    if (mask1 || mask2) {
      localB->g_data = 1;
    }

    if (localB->new_Theta_interp_size_tmp == static_cast<int8_T>(localB->loop_ub))
    {
      if (localB->new_Theta_interp_size_tmp - 1 >= 0) {
        localB->eulZYX[localB->g_data - 1] = -localB->x_data_c * 2.0 *
          localB->d_data;
      }
    } else {
      ros_code_binary_expand_op(localB->eulZYX, &localB->g_data,
        &localB->x_data_c, &localB->x_size_j, &localB->d_data, &localB->d_size);
    }

    localB->loop_ub = 0;
    if (mask1 || mask2) {
      localB->loop_ub = 1;
    }

    if (mask1 || mask2) {
      localB->h_data = 1;
    }

    if (localB->loop_ub - 1 >= 0) {
      localB->eulZYX[localB->h_data + 1] = 0.0;
    }

    rty_object_array_C[localB->i] = localB->In1_f.Markers[localB->i].
      Pose.Position.X;
    rty_object_array_C[localB->i + 10] = localB->In1_f.Markers[localB->i].
      Pose.Position.Y;
    rty_object_array_C[localB->i + 20] = localB->eulZYX[2];
    rty_object_array_C[localB->i + 30] = localB->In1_f.Markers[localB->i].
      Scale.X;
    rty_object_array_C[localB->i + 40] = localB->In1_f.Markers[localB->i].
      Scale.Y;
    localB->i++;
  }

  // End of MATLAB Function: '<S2>/getObjectData'

  // MATLAB Function: '<S2>/objectConvert'
  std::memset(&rty_object_array_F[0], 0, 30U * sizeof(real_T));
  if (*rty_get_global_pose != 0.0) {
    localB->i = 0;
    while (localB->i <= static_cast<int32_T>(rty_object_array_C[9]) - 1) {
      localB->new_point_num = rty_object_array_C[localB->i];
      localB->global_path_num = rty_object_array_C[localB->i + 10];
      for (localB->loop_ub = 0; localB->loop_ub <= 1998; localB->loop_ub += 2) {
        __m128d tmp;
        __m128d tmp_0;
        tmp = _mm_loadu_pd(&rty_preprocess_global_path_arra[localB->loop_ub]);
        tmp = _mm_sub_pd(tmp, _mm_set1_pd(localB->new_point_num));
        tmp_0 = _mm_loadu_pd(&rty_preprocess_global_path_arra[localB->loop_ub +
                             2000]);
        tmp_0 = _mm_sub_pd(tmp_0, _mm_set1_pd(localB->global_path_num));
        _mm_storeu_pd(&localB->distances[localB->loop_ub], _mm_sqrt_pd
                      (_mm_add_pd(_mm_mul_pd(tmp_0, tmp_0), _mm_mul_pd(tmp, tmp))));
      }

      if (!std::isnan(localB->distances[0])) {
        localB->loop_ub = 1;
      } else {
        boolean_T exitg1;
        localB->loop_ub = 0;
        localB->new_Theta_interp_size_tmp = 2;
        exitg1 = false;
        while ((!exitg1) && (localB->new_Theta_interp_size_tmp < 2001)) {
          if (!std::isnan(localB->distances[localB->new_Theta_interp_size_tmp -
                          1])) {
            localB->loop_ub = localB->new_Theta_interp_size_tmp;
            exitg1 = true;
          } else {
            localB->new_Theta_interp_size_tmp++;
          }
        }
      }

      if (localB->loop_ub == 0) {
        localB->new_Theta_interp_size_tmp = 0;
      } else {
        localB->new_point_num = localB->distances[localB->loop_ub - 1];
        localB->new_Theta_interp_size_tmp = localB->loop_ub - 1;
        while (localB->loop_ub + 1 <= 2000) {
          if (localB->new_point_num > localB->distances[localB->loop_ub]) {
            localB->new_point_num = localB->distances[localB->loop_ub];
            localB->new_Theta_interp_size_tmp = localB->loop_ub;
          }

          localB->loop_ub++;
        }
      }

      localB->new_point_num = rty_object_array_C[localB->i] -
        rty_preprocess_global_path_arra[localB->new_Theta_interp_size_tmp];
      localB->global_path_num -= rty_preprocess_global_path_arra
        [localB->new_Theta_interp_size_tmp + 2000];
      localB->b_a = rty_preprocess_global_path_arra
        [localB->new_Theta_interp_size_tmp + 4000];
      localB->b_a = localB->global_path_num * std::cos(localB->b_a) -
        (rty_object_array_C[localB->i] - localB->b_a) * std::sin(localB->b_a);
      rty_object_array_F[localB->i] = rty_preprocess_global_path_arra
        [localB->new_Theta_interp_size_tmp + 8000];
      if (!std::isnan(localB->b_a)) {
        if (localB->b_a < 0.0) {
          localB->b_a = -1.0;
        } else {
          localB->b_a = (localB->b_a > 0.0);
        }
      }

      rty_object_array_F[localB->i + 10] = std::sqrt(localB->new_point_num *
        localB->new_point_num + localB->global_path_num *
        localB->global_path_num) * localB->b_a;
      rty_object_array_F[localB->i + 20] = localB->new_Theta_interp_size_tmp + 1;
      localB->i++;
    }

    rty_object_array_F[9] = rty_object_array_C[9];
  }

  // End of MATLAB Function: '<S2>/objectConvert'
}

// Termination for atomic system: '<Root>/Global_planner'
void ros_code_Global_planner_Term(DW_Global_planner_ros_code_T *localDW)
{
  // Terminate for Atomic SubSystem: '<S2>/Subscribe1'
  // Terminate for MATLABSystem: '<S9>/SourceBlock'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/SourceBlock'
  // End of Terminate for SubSystem: '<S2>/Subscribe1'

  // Terminate for Atomic SubSystem: '<S2>/Subscribe'
  // Terminate for MATLABSystem: '<S8>/SourceBlock'
  if (!localDW->obj_o.matlabCodegenIsDeleted) {
    localDW->obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/SourceBlock'
  // End of Terminate for SubSystem: '<S2>/Subscribe'
}

//
// File trailer for generated code.
//
// [EOF]
//
